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
  int i = 0, j = 0, c1 = 0, c2 = 0, c3 = 0, t = 0;
  int fatal = 0, expect = 0;
  SQLRETURN sqlrc = 0;
  SQLHANDLE henv = 0;
  SQLHANDLE hdbc = 0;
  SQLHANDLE hstmt = 0;
  SQLINTEGER yes = SQL_TRUE;
  SQL400AttrStruct pophenv[3];
  SQL400AttrStruct pophdbc[3];
  char * db = (char *) NULL;
  char * uid = (char *) NULL;
  char * pwd = (char *) NULL;
  char * qual = (char *) NULL;
  char * parm = (char *) NULL;
  char * parmval = (char *) NULL;
  char * sql = (char *) NULL;
  SQLINTEGER start_row = 0;
  SQL400DescStruct desc_parms[100];
  SQL400ParamStruct call_parms[100];
  SQLINTEGER indPtr[100];
  SQLSMALLINT pccol = 0;
  SQL400ParamStruct call_cols[100];
  SQL400DescStruct desc_cols[100];
  SQLPOINTER data_cols[100];
  static char * run_main_keys[] = {"sql", (char *) NULL};
  static char * run_sql_keys[] = {"connect","prepare","execute","fetch", (char *) NULL};
  static char * run_sql_connect_keys[] = {"database","user","password","qualify",(char *) NULL};
  char * run_sql_connect_error[] = {"invalid connection",(char *) NULL};
  char * run_sql_prepare_error[] = {"invalid prepare",(char *) NULL};
  char * run_sql_execute_error[] = {"invalid execute",(char *) NULL};
  char * run_sql_fetch_row[] = {"row",(char *) NULL};
  char * run_sql_fetch_assoc[] = {(char *) NULL,(char *) NULL,(char *) NULL};

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
        /* ==========================
         * sql prepare
         * ========================== */
        case 1: /* prepare */
          run_output(RUN_COMMA,outrun,outlen,NULL,rf);
          run_output(RUN_START_NAME,outrun,outlen,&name[i],rf);
          if (hdbc < 2) {
            run_output(RUN_ERROR,outrun,outlen,run_sql_connect_error,rf);
            fatal = 1;
          }
          if (!fatal) {
            sqlrc = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
            sql = value[i];
            t = strlen(sql);
            sqlrc = SQLPrepare(hstmt, sql , t);
            if (sqlrc == SQL_ERROR) {
              run_output(RUN_ERROR,outrun,outlen,run_sql_prepare_error,rf);
              fatal = 1;
            } else {
              run_output(RUN_OK,outrun,outlen,NULL,rf);
            }
          }
          run_output(RUN_END,outrun,outlen,NULL,rf);
          break;
        /* ==========================
         * sql execute
         * ========================== */
        case 2: /* execute */
          run_output(RUN_COMMA,outrun,outlen,NULL,rf);
          run_output(RUN_START_NAME,outrun,outlen,&name[i],rf);
          if (hdbc < 2) {
            run_output(RUN_ERROR,outrun,outlen,run_sql_connect_error,rf);
            fatal = 1;
          }
          if (!fatal && hstmt < 2) {
            run_output(RUN_ERROR,outrun,outlen,run_sql_prepare_error,rf);
            fatal = 1;
          }
          if (!fatal) {
            memset(desc_parms,0,sizeof(desc_parms));
            memset(call_parms,0,sizeof(call_parms));
            memset(indPtr,0,sizeof(indPtr));
            t = 0;
            parm = value[i];
            c3 = strlen(parm);
            for (c1=-1, c2=0; c2 <= c3; c2++) {
              if (c1 < 0) {
                if (*parm == '"' || *parm == ',' || *parm == '\0' || *parm == ' ') {
                  /* not start parm */
                } else {
                  c1 = c2;
                  parmval = parm;
                }
              } else {
                if (*parm == '"' || *parm == ',' || *parm == '\0') {
                  *parm = '\0';
                  if (strcmp(parmval,"null")) {
                    indPtr[t] = c2 - c1;
                    sqlrc = SQL400AddDesc(hstmt, t + 1, SQL400_DESC_PARM, (SQLPOINTER)&desc_parms);
                    sqlrc = SQL400AddCVar(t + 1, SQL_PARAM_INPUT, SQL_C_CHAR, (SQLPOINTER) parmval, &indPtr[t], (SQLPOINTER) &call_parms);
                    t++;
                  }
                  c1 = -1;
                }
              }
              parm += 1;
            }
            sqlrc = SQL400Execute(hstmt, (SQLPOINTER)&call_parms, (SQLPOINTER)&desc_parms);
            if (sqlrc == SQL_ERROR) {
              run_output(RUN_ERROR,outrun,outlen,run_sql_execute_error,rf);
              fatal = 1;
            } else {
              run_output(RUN_OK,outrun,outlen,NULL,rf);
            }
          }
          run_output(RUN_END,outrun,outlen,NULL,rf);
          break;
        /* ==========================
         * sql fetch
         * ========================== */
        case 3: /* fetch */
          run_output(RUN_COMMA,outrun,outlen,NULL,rf);
          run_output(RUN_START_NAME,outrun,outlen,&name[i],rf);
          if (hdbc < 2) {
            run_output(RUN_ERROR,outrun,outlen,run_sql_connect_error,rf);
            fatal = 1;
          }
          if (!fatal && hstmt < 2) {
            run_output(RUN_ERROR,outrun,outlen,run_sql_prepare_error,rf);
            fatal = 1;
          }
          if (!fatal) {
            memset(desc_cols,0,sizeof(desc_cols));
            memset(call_cols,0,sizeof(call_cols));
            memset(data_cols,0,sizeof(data_cols));
            sqlrc = SQLNumResultCols(hstmt, (SQLSMALLINT *)&pccol );
            for (t=0; t < pccol; t++) {
              sqlrc = SQL400AddDesc(hstmt, t + 1, SQL400_DESC_COL, (SQLPOINTER)&desc_cols);
              data_cols[t] = (SQLPOINTER) malloc(1024);
              indPtr[t] = 1024;
              sqlrc = SQL400AddCVar(t + 1, 0, SQL_C_CHAR, (SQLPOINTER)data_cols[t], &indPtr[t], (SQLPOINTER) &call_cols);
            }
            sqlrc == SQL_SUCCESS;
            c1 = 0;
            while (sqlrc == SQL_SUCCESS) {
              for (t=0; t < pccol; t++) {
                memset(data_cols[t],0,1024);
              }
              sqlrc = SQL400Fetch(hstmt, start_row, (SQLPOINTER)&call_cols, (SQLPOINTER)&desc_cols);
              if (sqlrc == SQL_SUCCESS) {
                if (!c1) {
                  run_output(RUN_START_ARRAY_NAME,outrun,outlen,run_sql_fetch_row,rf);
                  c1 = 1;
                } else {
                  run_output(RUN_COMMA,outrun,outlen,NULL,rf);
                }
                run_output(RUN_START,outrun,outlen,NULL,rf);
                for (t=0; t < pccol; t++) {
                  run_sql_fetch_assoc[0] = desc_cols[t].szColName;
                  run_sql_fetch_assoc[1] = data_cols[t];
                  run_output(RUN_NAME_VALUE_STRING,outrun,outlen,run_sql_fetch_assoc,rf);
                  if (t < pccol - 1) {
                    run_output(RUN_COMMA,outrun,outlen,NULL,rf);
                  }
                }
                run_output(RUN_END,outrun,outlen,NULL,rf);
              }
            }
            if (c1) {
              run_output(RUN_END_ARRAY,outrun,outlen,NULL,rf);
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

/*
 * Invalid utf-8 bytes 0xC0, 0xC1, and 0xF5..0xFF
 */
static int valid_utf8(char * j) 
{
  while (j[0]) {
    switch(j[0]) {
    case 0xC0:
    case 0xC1:
    case 0xF5:
    case 0xF6:
    case 0xF7:
    case 0xF8:
    case 0xF9:
    case 0xFA:
    case 0xFB:
    case 0xFC:
    case 0xFD:
    case 0xFE:
    case 0xFF:
      return 0;
      break;
    default:
      break;
    }
    j += 1;
  }
  return 1;
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
  SQLRETURN sqlrc = 0;
  SQLHANDLE henv = 0;

  /* debug only */
  /* run_spin_me(); */

  /* copy in for parse */
  memset(outrun,0,outlen);
  if (valid_utf8(inrun)) {
    run_input = malloc(inlen + 1);
    strcpy(run_input,inrun);
  } else {
    run_input = malloc(inlen * 3 + 1);
    sqlrc = SQL400ToUtf8(henv, (SQLPOINTER) inrun, (SQLINTEGER) inlen, (SQLPOINTER) run_input, (SQLINTEGER) (inlen * 3 + 1), 819);
  }

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

