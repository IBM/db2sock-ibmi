#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dlfcn.h>
#include <iconv.h>
#include <sqlcli1.h>
#include "PaseCliInit.h"
#include "PaseCliAsync.h"
#include "PaseCliJson.h"
#include "PaseCliRun.h"

static char * run_main_keys[] = {"sql", (char *) NULL};
static char * run_sql_keys[] = {"connect","prepare","execute","fetch", (char *) NULL};
static char * run_sql_connect_keys[] = {"database","user","password","qualify",(char *) NULL};
static char * run_sql_connect_error[] = {"invalid connection",(char *) NULL};

static int run_key(char * str, char *keys[]) 
{
  int i = 0;
  for (i=0; keys[i]; i++) {
    if (!strcmp(str, keys[i])) {
      return i;
    }
  }
  return -1;
}

void run_output(int flag, char *outrun, int outlen, char *argv[], int rf)
{
  switch(rf) {
  case 0:
    json_output(flag, outrun, outlen, argv);
    break;
  case 1:
    /* xml_output(flag, outrun, outlen, argv);
    break;
    */
  default:
    break;
  }
}

void run_output_invalid(int flag, char *outrun, int outlen, char *bad, char *argv[], int rf)
{
  int i= 0, j = 0;
  char * errv[1024];
  errv[0] = "invalid keyword '";
  errv[1] = bad;
  errv[2] = "' (";
  for (i=0, j=3; argv[i]; i++, j++) {
    errv[j] = argv[i];
    if (argv[i+1]) {
      j++;
      errv[j] = ",";
    }
  }
  errv[j] = ")";
  errv[j+1] = (char *) NULL;
  run_output(RUN_ERROR,outrun,outlen,errv,rf);
}

static int run_script(int argc, char *name[], char *value[], SQLCHAR * outrun, SQLINTEGER outlen, int rf)
{
  int i = 0, j = 0;
  int fatal = 0, expect = 0;
  SQLRETURN sqlrc = 0;
  SQLHANDLE henv = 0;
  SQLHANDLE hdbc = 0;
  SQLINTEGER yes = SQL_TRUE;
  SQL400AttrStruct pophenv[3];
  SQL400AttrStruct pophdbc[3];
  char * db = (char *) NULL;
  char * uid = (char *) NULL;
  char * pwd = (char *) NULL;
  char * qual = (char *) NULL;

  run_output(RUN_START,outrun,outlen,NULL,rf);
  for (i=0; i < argc && !fatal; i++) {
    j = run_key(name[i], run_main_keys);
    if (j < 0) {
      if (!expect) {
        run_output_invalid(RUN_ERROR,outrun,outlen,name[i],run_main_keys,rf);
        expect = 1;
      }
      i--;
      break;
    }
    switch (j) {
    /* ==========================
     * sql operations
     * ========================== */
    case 0: /* sql */
      run_output(RUN_START_NAME,outrun,outlen,&name[i],rf);
      memset(pophenv,0,sizeof(pophenv));
      sqlrc = SQLOverrideCCSID400( 1208 );
      sqlrc = SQL400AddAttr(SQL_HANDLE_ENV, SQL_ATTR_SERVER_MODE, &yes, 0, SQL400_ONERR_CONT, SQL400_FLAG_IMMED, (SQLPOINTER)&pophenv);
      sqlrc = SQL400Environment( &henv, (SQLPOINTER)&pophenv);
      for (i++; i < argc && !fatal; i++) {
        j = run_key(name[i], run_sql_keys);
        if (j < 0) {
          if (!expect) {
            run_output_invalid(RUN_ERROR,outrun,outlen,name[i],run_sql_keys,rf);
            expect = 1;
          }
          i--;
          break;
        }
        switch (j) {
        /* ==========================
         * sql connect
         * ========================== */
        case 0: /* connect */
          run_output(RUN_START_NAME,outrun,outlen,&name[i],rf);
          memset(pophdbc,0,sizeof(pophdbc));
          for (i++; i < argc && !fatal; i++) {
            j = run_key(name[i], run_sql_connect_keys);
            if (j < 0) {
              if (!expect) {
                run_output_invalid(RUN_ERROR,outrun,outlen,name[i],run_sql_connect_keys,rf);
                expect = 1;
              }
              i--;
              break;
            }
            switch (j) {
            case 0: /* database */
              db = value[i];
              break;
            case 1: /* user */
              uid = value[i];
              break;
            case 2: /* password */
              pwd = value[i];
              break;
            case 3: /* qualify */
              qual = value[i];
              break;
            default:
              break;
            }
            if (db && uid && pwd && qual) {
              sqlrc = SQL400pConnect(henv, (SQLCHAR *) db, (SQLCHAR *) uid, (SQLCHAR *) pwd, (SQLCHAR *) qual, (SQLINTEGER *)&hdbc, (SQLPOINTER)&pophdbc);
              if (sqlrc == SQL_ERROR) {
                run_output(RUN_ERROR,outrun,outlen,run_sql_connect_error,rf);
                fatal = 1;
              } else {
                run_output(RUN_OK,outrun,outlen,NULL,rf);
              }
              break;
            }
          }
          run_output(RUN_END,outrun,outlen,NULL,rf);
          break;
        default:
          break;
        }
      } 
      run_output(RUN_END,outrun,outlen,NULL,rf);
      break;
    default:
      break;
    }
  }
  run_output(RUN_END,outrun,outlen,NULL,rf);

  return SQL_SUCCESS;
}

static void run_spin_me() {
  sleep(30);
}

SQLRETURN run_main(
 SQLCHAR * inrun,
 SQLINTEGER inlen,
 SQLCHAR * outrun,
 SQLINTEGER outlen,
 int rf)
{
  int argc = 0, rc = 0;
  char * run_input = (char *) NULL;
  char ** name = (char **) NULL;
  char ** value = (char **) NULL;

  /* debug only */
  /* run_spin_me(); */

  /* copy in for parse */
  memset(outrun,0,outlen);
  run_input = malloc(inlen) + 1;
  strcpy(run_input,inrun);

  switch(rf) {
  case 0:
    argc = json_parse_hash(run_input, (void **)&name, (void **)&value);
    break;
  case 1:
    /* 
    argc = xml_parse_hash(run_input, (void **)&name, (void **)&value);
    break;
    */
  default:
    break;
  }

  rc = run_script(argc, name, value, outrun, outlen, rf);

  return rc;
}

