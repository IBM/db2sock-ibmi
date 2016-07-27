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

static int run_key(char * str, char **val, char *keys[]) 
{
  int i = 0;
  for (i=0; keys[i]; i++) {
    /* key found */
    if (!strcmp(str, keys[i])) {
      /* check json "value":null */
      if (!strcmp(*val,"null")) {
        *val = (char *)NULL;
      }
      return i;
    }
  }
  /* special final name:value */
  if (!strcmp(str,"junk")) {
    return -2;
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
  int i = 0, j = 0, t = 0, sz = 0;
  int fatal = 0, expect = 0;
  SQLRETURN sqlrc = 0;
  SQLHANDLE henv = 0;
  SQLHANDLE hdbc = 0;
  SQLHANDLE hstmt = 0;
  SQLINTEGER yes = SQL_TRUE;
  SQL400AttrStruct pophenv[3];
  SQL400AttrStruct pophdbc[3];

  char * conn_db = (char *) NULL;
  char * conn_uid = (char *) NULL;
  char * conn_pwd = (char *) NULL;
  char * conn_qual = (char *) NULL;

  char * prep_sql = (char *) NULL;

  char * exec_parm = (char *) NULL;
  char * exec_parmval = (char *) NULL;
  SQL400DescStruct exec_desc_parms[1024];
  SQL400ParamStruct exec_call_parms[1024];
  SQLINTEGER exec_ind[1024];

  char * meta_schema = (char *) NULL;
  char * meta_name = (char *) NULL;
  char * meta_type = (char *) NULL;

  SQLINTEGER fetch_start_row = 0; 
  SQLINTEGER fetch_max_rows = 9999; 
  SQLINTEGER fetch_cnt_rows = 0;
  SQLINTEGER fetch_more_rows = 0; 
  SQLINTEGER fetch_cnt_cols = 0; 
  SQLPOINTER fetch_out_rows = (SQLPOINTER) NULL;
  SQLPOINTER fetch_out_decs = (SQLPOINTER) NULL;
  SQLINTEGER fetch_all_char = 1; 
  SQLINTEGER fetch_expand_factor = 0;
  SQL400DescStruct * fetch_opts = (SQL400DescStruct *) NULL;
  SQL400DescStruct * fetch_opt = (SQL400DescStruct *) NULL;
  SQL400ParamStruct * fetch_prms = (SQL400ParamStruct *) NULL;
  SQL400ParamStruct * fetch_prm = (SQL400ParamStruct *) NULL;
  char ** fetch_ptr = (char **) NULL;

  static char * run_main_keys[] = {"sql", (char *) NULL};
  static char * run_sql_keys[] = {"connect","prepare","execute","fetch", "tables", (char *) NULL};
  static char * run_sql_connect_keys[] = {"database","user","password","qualify", (char *) NULL};
  static char * run_sql_parm_keys[] = {"parm", "junk", (char *) NULL};
  static char * run_sql_tables_keys[] = {"schema","name","type", (char *) NULL};

  char * run_sql_connect_error[] = {"invalid connection",(char *) NULL};
  char * run_sql_prepare_error[] = {"invalid prepare",(char *) NULL};
  char * run_sql_execute_error[] = {"invalid execute",(char *) NULL};
  char * run_sql_tables_error[] = {"invalid tables",(char *) NULL};
  char * run_sql_fetch_error[] = {"invalid fetch",(char *) NULL};
  char * run_sql_fetch_nodata[] = {"no data",(char *) NULL};
  char * run_sql_fetch_row[] = {"row",(char *) NULL};
  char * run_sql_fetch_assoc[] = {(char *) NULL,(char *) NULL,(char *) NULL};

  /* ==========================
   * json operation {sql, ...}
   * ========================== */
  run_output(RUN_START,outrun,outlen,NULL,rf);
  for (i=0; i < argc && !fatal; i++) {
    j = run_key(name[i], &value[i], run_main_keys);
    if (j < 0) {
      if (j < -1) {
        expect = 1;
      }
      if (!expect) {
        run_output_invalid(RUN_ERROR,outrun,outlen,name[i],run_main_keys,rf);
        expect = 1;
      }
      i--;
      break;
    }
    switch (j) {
    /* ==========================
     * sql operations { connect, ...}
     * ========================== */
    case 0: /* sql */
      run_output(RUN_START_NAME,outrun,outlen,&name[i],rf);
      memset(pophenv,0,sizeof(pophenv));
      sqlrc = SQLOverrideCCSID400( 1208 );
      sqlrc = SQL400AddAttr(SQL_HANDLE_ENV, SQL_ATTR_SERVER_MODE, &yes, 0, SQL400_ONERR_CONT, SQL400_FLAG_IMMED, (SQLPOINTER)&pophenv);
      sqlrc = SQL400Environment( &henv, (SQLPOINTER)&pophenv);
      for (i++; i < argc && !fatal; i++) {
        j = run_key(name[i], &value[i], run_sql_keys);
        if (j < 0) {
          if (j < -1) {
            expect = 1;
          }
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
          conn_db = (char *) NULL;
          conn_uid = (char *) NULL;
          conn_pwd = (char *) NULL;
          conn_qual = (char *) NULL;
          run_output(RUN_START_NAME,outrun,outlen,&name[i],rf);
          memset(pophdbc,0,sizeof(pophdbc));
          for (i++; i < argc && !fatal; i++) {
            j = run_key(name[i], &value[i], run_sql_connect_keys);
            if (j < 0) {
              sqlrc = SQL400pConnect(henv, (SQLCHAR *) conn_db, (SQLCHAR *) conn_uid, (SQLCHAR *) conn_pwd, (SQLCHAR *) conn_qual, (SQLINTEGER *)&hdbc, (SQLPOINTER)&pophdbc);
              if (sqlrc == SQL_ERROR) {
                run_output(RUN_ERROR,outrun,outlen,run_sql_connect_error,rf);
                fatal = 1;
              } else {
                run_output(RUN_OK,outrun,outlen,NULL,rf);
              }
              i--;
              break;
            }
            switch (j) {
            case 0: /* database */
              conn_db = value[i];
              break;
            case 1: /* user */
              conn_uid = value[i];
              break;
            case 2: /* password */
              conn_pwd = value[i];
              break;
            case 3: /* qualify */
              conn_qual = value[i];
              break;
            default:
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
            prep_sql = value[i];
            t = strlen(prep_sql);
            sqlrc = SQLPrepare(hstmt, prep_sql , t);
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
            memset(exec_desc_parms,0,sizeof(exec_desc_parms));
            memset(exec_call_parms,0,sizeof(exec_call_parms));
            memset(exec_ind,0,sizeof(exec_ind));
            t = 0;
            for (i++; i < argc && !fatal; i++) {
              j = run_key(name[i], &value[i], run_sql_parm_keys);
              if (j < 0) {
                sqlrc = SQL400Execute(hstmt, (SQLPOINTER)&exec_call_parms, (SQLPOINTER)&exec_desc_parms);
                if (sqlrc == SQL_ERROR) {
                  run_output(RUN_ERROR,outrun,outlen,run_sql_execute_error,rf);
                  fatal = 1;
                } else {
                  run_output(RUN_OK,outrun,outlen,NULL,rf);
                }
                i--;
                break;
              }
              switch (j) {
              case 0: /* parm */
                exec_ind[t] = strlen(value[i]);
                sqlrc = SQL400AddDesc(hstmt, t + 1, SQL400_DESC_PARM, (SQLPOINTER)&exec_desc_parms);
                sqlrc = SQL400AddCVar(t + 1, SQL_PARAM_INPUT, SQL_C_CHAR, (SQLPOINTER) value[i], &exec_ind[t], (SQLPOINTER) &exec_call_parms);
                t++;
                break;
              default:
                break;
              }
            }
          }
          run_output(RUN_END,outrun,outlen,NULL,rf);
          if (fatal && hstmt > 0) {
            sqlrc = SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
            hstmt = 0;
          }
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
            sqlrc = SQL400FetchArray(hstmt, 
              fetch_start_row, 
              fetch_max_rows, 
              (SQLINTEGER *) &fetch_cnt_rows, 
              (SQLINTEGER *) &fetch_more_rows, 
              (SQLINTEGER *) &fetch_cnt_cols, 
              (SQLPOINTER *) &fetch_out_rows, 
              (SQLPOINTER *) &fetch_out_decs, 
              fetch_all_char, 
              fetch_expand_factor);
            if (sqlrc == SQL_ERROR) {
              run_output(RUN_ERROR,outrun,outlen,run_sql_fetch_error,rf);
              fatal = 1;
            }
          }
          if (!fatal) {
            sqlrc == SQL_SUCCESS;
            fetch_ptr = (char **) fetch_out_rows;
            fetch_opts = (SQL400DescStruct *) fetch_out_decs;
            for (t=0; t < fetch_cnt_rows; t++) {
              fetch_prms = (SQL400ParamStruct *) fetch_ptr[t];
              if (!t) {
                run_output(RUN_START_ARRAY_NAME,outrun,outlen,run_sql_fetch_row,rf);
                run_output(RUN_START,outrun,outlen,NULL,rf);
              } else {
                run_output(RUN_COMMA,outrun,outlen,NULL,rf);
                run_output(RUN_START,outrun,outlen,NULL,rf);
              }
              for (j=0; j < fetch_cnt_cols; j++) {
                fetch_opt = (SQL400DescStruct *)&fetch_opts[j];
                fetch_prm = (SQL400ParamStruct *)&fetch_prms[j];
                run_sql_fetch_assoc[0] = fetch_opt->szColName;
                run_sql_fetch_assoc[1] = fetch_prm->pfSqlCValue;
                run_output(RUN_NAME_VALUE_STRING,outrun,outlen,run_sql_fetch_assoc,rf);
                if (j < fetch_cnt_cols - 1) {
                  run_output(RUN_COMMA,outrun,outlen,NULL,rf);
                } /* for j */
              }
              run_output(RUN_END,outrun,outlen,NULL,rf);
            } /* for t */
            if (fetch_cnt_rows > 0) {
              run_output(RUN_END_ARRAY,outrun,outlen,NULL,rf);
            } else {
              run_output(RUN_ERROR,outrun,outlen,run_sql_fetch_nodata,rf);
            }
            sqlrc = SQL400FetchArrayFree(fetch_cnt_cols, fetch_out_rows, fetch_out_decs);
          }
          run_output(RUN_END,outrun,outlen,NULL,rf);
          if (hstmt > 0) {
            sqlrc = SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
          }
          break;
        /* ==========================
         * sql tables
         * ========================== */
        case 4: /* tables */
          meta_schema = (char *) NULL;
          meta_name = (char *) NULL;
          meta_type = (char *) NULL;
          run_output(RUN_COMMA,outrun,outlen,NULL,rf);
          run_output(RUN_START_NAME,outrun,outlen,&name[i],rf);
          if (hdbc < 2) {
            run_output(RUN_ERROR,outrun,outlen,run_sql_connect_error,rf);
            fatal = 1;
          }
          if (!fatal) {
            sqlrc = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
            if (!fatal && hstmt < 2) {
              run_output(RUN_ERROR,outrun,outlen,run_sql_tables_error,rf);
              fatal = 1;
            }
          }
          if (!fatal) {
            for (i++; i < argc && !fatal; i++) {
              j = run_key(name[i], &value[i], run_sql_tables_keys);
              if (j < 0) {
                sqlrc = SQLTables(hstmt, NULL, 0, meta_schema, SQL_NTS, meta_name, SQL_NTS, meta_type, SQL_NTS);
                if (sqlrc == SQL_ERROR) {
                  run_output(RUN_ERROR,outrun,outlen,run_sql_tables_error,rf);
                  fatal = 1;
                } else {
                  run_output(RUN_OK,outrun,outlen,NULL,rf);
                }
                i--;
                break;
              }
              switch (j) {
              case 0: /* schema */
                meta_schema = value[i];
                break;
              case 1: /* name (table) */
                meta_name = value[i];
                break;
              case 2: /* type */
                meta_type = value[i];
                break;
              default:
                break;
              }
            }
          }
          if (fatal && hstmt > 0) {
            sqlrc = SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
            hstmt = 0;
          }
          run_output(RUN_END,outrun,outlen,NULL,rf);
          break;
        /* ==========================
         * sql op default (nothing)
         * ========================== */
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
 SQLINTEGER rf)
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

