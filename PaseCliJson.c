#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dlfcn.h>
#include <iconv.h>
#include <stdarg.h>
#include <sqlcli1.h>
#include "PaseCliInit.h"
#include "PaseCliAsync.h"

/* === experimental (not finished) ===
 * This module has fancy 'big helper' APIs.
 *
 * Goal enable many operatins in one async call. Similar to
 * scripting APIs, one new SQL400xxx API (not CLI), many CLI calls
 * set attributes, bind columns, etc.
 *
 * Warning: 
 * Many bugs still here. Development is trial and error,
 * so don't exepct these APIs to be solid until this
 * warning is removed.
 */

#define JSON400_MAX_KEY 65000
#define JSON400_KEY_CONN 1
#define JSON400_KEY_PCONN 2
#define JSON400_KEY_QUERY 10
#define JSON400_KEY_PARM 20
#define JSON400_KEY_FETCH 30
#define JSON400_MAX_ARGS 32
#define JSON400_MAX_COLS 1024

#define JSON400_MAX_ERR_MSG_LEN (SQL_MAX_MESSAGE_LENGTH + SQL_SQLSTATE_SIZE + 10)

#define JSON400_EXPAND_CHAR 3
#define JSON400_EXPAND_BINARY 2
#define JSON400_EXPAND_OTHER 64
#define JSON400_EXPAND_COL_NAME 128

#define JSON400_UNKNOWN -1

#define JSON400_CMD_HELP 1
#define JSON400_CMD_QUERY 2

#define JSON400_OUT_COMMA_STDOUT 11
#define JSON400_OUT_JSON_STDOUT 12
#define JSON400_OUT_SPACE_STDOUT 13
#define JSON400_OUT_COMMA_BUFF 21
#define JSON400_OUT_JSON_BUFF 22
#define JSON400_OUT_SPACE_BUFF 23

#define JSON400_NBR_KEYS 5
char * JSON400_KEYS[JSON400_NBR_KEYS] = {
  "\"pconnect\":",
  "\"connect\":",
  "\"query\":",
  "\"parm\":",
  "\"fetch\":"
};
int JSON400_ORDS[JSON400_NBR_KEYS] = {
  JSON400_KEY_PCONN,
  JSON400_KEY_CONN,
  JSON400_KEY_QUERY,
  JSON400_KEY_PARM,
  JSON400_KEY_FETCH
};


char * custom_json_parse_key_value(char * c, int find, char **find_key, int *find_ord, int *find_look, int idx, int *k, char **v, int *a);
int custom_json_parse_array_values(char *c, char **v);

void * custom_json_new(int size) {
  void * buffer = malloc(size + 1);
  memset(buffer,0,size + 1);
  return buffer;
}
void custom_json_free(char *buffer) {
  if (buffer) {
    free(buffer);
  }
}

void custom_output_printf(char *out_caller, const char * format, ...) {
  char *p = (char *) NULL; 

  p = out_caller + strlen(out_caller);
  va_list args;
  va_start(args, format);
  vsprintf(p, format, args);
  va_end(args);
}

void custom_output_record_array_beg(int fmt, char *out_caller) {
  switch (fmt) {
  case JSON400_OUT_JSON_STDOUT:
    printf("{\"records\":[");
    break;
  case JSON400_OUT_JSON_BUFF:
    custom_output_printf(out_caller, "{\"records\":[");
    break;
  case JSON400_OUT_SPACE_STDOUT:
    break;
  case JSON400_OUT_SPACE_BUFF:
    break;
  case JSON400_OUT_COMMA_STDOUT:
    break;
  case JSON400_OUT_COMMA_BUFF:
    break;
  default:
    break;
  }
}
void custom_output_record_row_beg(int fmt, int flag, char *out_caller) {
  switch (fmt) {
  case JSON400_OUT_JSON_STDOUT:
    if (flag) {
      printf(",\n{");
    } else {
      printf("\n{");
    }
    break;
  case JSON400_OUT_JSON_BUFF:
    if (flag) {
      custom_output_printf(out_caller, ",\n{");
    } else {
      custom_output_printf(out_caller, "\n{");
    }
    break;
  case JSON400_OUT_SPACE_STDOUT:
    break;
  case JSON400_OUT_SPACE_BUFF:
    break;
  case JSON400_OUT_COMMA_STDOUT:
    break;
  case JSON400_OUT_COMMA_BUFF:
    break;
  default:
    break;
  }
}
void custom_output_record_name_value(int fmt, int flag, char *name, char *value, char *out_caller) {
  switch (fmt) {
  case JSON400_OUT_JSON_STDOUT:
    if (flag) {
      printf(",");
    }
    printf("\"%s\":\"%s\"",name,value);
    break;
  case JSON400_OUT_JSON_BUFF:
    if (flag) {
      custom_output_printf(out_caller, ",");
    }
    custom_output_printf(out_caller, "\"%s\":\"%s\"",name,value);
    break;
  case JSON400_OUT_SPACE_STDOUT:
    if (flag) {
      printf(" ");
    }
    printf("\"%s\"",value);
    break;
  case JSON400_OUT_SPACE_BUFF:
    if (flag) {
      custom_output_printf(out_caller, " ");
    }
    custom_output_printf(out_caller, "\"%s\"",value);
    break;
  case JSON400_OUT_COMMA_STDOUT:
    if (flag) {
      printf(",");
    }
    printf("\"%s\"",value);
    break;
  case JSON400_OUT_COMMA_BUFF:
    if (flag) {
      custom_output_printf(out_caller, ",");
    }
    custom_output_printf(out_caller, "\"%s\"",value);
    break;
  default:
    break;
  }
}
void custom_output_record_row_end(int fmt, char *out_caller) {
  switch (fmt) {
  case JSON400_OUT_JSON_STDOUT:
    printf("}");
    break;
  case JSON400_OUT_JSON_BUFF:
    custom_output_printf(out_caller, "}");
    break;
  case JSON400_OUT_SPACE_STDOUT:
    printf("\n");
    break;
  case JSON400_OUT_SPACE_BUFF:
    custom_output_printf(out_caller, "\n");
    break;
  case JSON400_OUT_COMMA_STDOUT:
    printf("\n");
    break;
  case JSON400_OUT_COMMA_BUFF:
    custom_output_printf(out_caller, "\n");
    break;
  default:
    break;
  }
}
void custom_output_record_array_end(int fmt, char *out_caller) {
  switch (fmt) {
  case JSON400_OUT_JSON_STDOUT:
    printf("\n]}\n");
    break;
  case JSON400_OUT_JSON_BUFF:
    custom_output_printf(out_caller, "\n]}\n");
    break;
  case JSON400_OUT_SPACE_STDOUT:
    printf("\n");
    break;
  case JSON400_OUT_SPACE_BUFF:
    custom_output_printf(out_caller, "\n");
    break;
  case JSON400_OUT_COMMA_STDOUT:
    printf("\n");
    break;
  case JSON400_OUT_COMMA_BUFF:
    custom_output_printf(out_caller, "\n");
    break;
  default:
    break;
  }
}

/*
  custom_output_sql_errors(fmt, henv, SQL_HANDLE_ENV,   rc);
  custom_output_sql_errors(fmt, hdbc, SQL_HANDLE_DBC,   rc);
  custom_output_sql_errors(fmt, hstmt, SQL_HANDLE_STMT, rc);
*/
int custom_output_sql_errors(int fmt, SQLHANDLE handle, SQLSMALLINT hType, int rc, char *out_caller)
{
  SQLCHAR msg[SQL_MAX_MESSAGE_LENGTH + 1];
  SQLCHAR sqlstate[SQL_SQLSTATE_SIZE + 1];
  SQLCHAR errMsg[JSON400_MAX_ERR_MSG_LEN];
  SQLINTEGER sqlcode = 0;
  SQLSMALLINT length = 0;
  SQLCHAR *p = NULL;
  SQLSMALLINT recno = 1;
  if (rc == SQL_ERROR) {
    memset(msg, '\0', SQL_MAX_MESSAGE_LENGTH + 1);
    memset(sqlstate, '\0', SQL_SQLSTATE_SIZE + 1);
    memset(errMsg, '\0', JSON400_MAX_ERR_MSG_LEN);
    if ( SQLGetDiagRec(hType, handle, recno, sqlstate, &sqlcode, msg, SQL_MAX_MESSAGE_LENGTH + 1, &length)  == SQL_SUCCESS ) {
      if (msg[length-1] == '\n') {
        p = &msg[length-1];
        *p = '\0';
      }
      switch (fmt) {
      case JSON400_OUT_JSON_STDOUT:
        printf("{\"ok\":false,\"reason\":\"error %s SQLCODE=%d\"}",msg, sqlcode);
        break;
      case JSON400_OUT_JSON_BUFF:
        custom_output_printf(out_caller, "{\"ok\":false,\"reason\":\"error %s SQLCODE=%d\"}",msg, sqlcode);
        break;
      case JSON400_OUT_SPACE_STDOUT:
        printf("\"error=%s SQLCODE=%d\"\n",msg, sqlcode);
        break;
      case JSON400_OUT_SPACE_BUFF:
        custom_output_printf(out_caller, "\"error=%s SQLCODE=%d\"\n",msg, sqlcode);
        break;
      case JSON400_OUT_COMMA_STDOUT:
        printf("\"error %s, SQLCODE=%d\"\n",msg, sqlcode);
        break;
      case JSON400_OUT_COMMA_BUFF:
        custom_output_printf(out_caller, "\"error=%s, SQLCODE=%d\"\n",msg, sqlcode);
        break;
      default:
        break;
      }
      return SQL_ERROR;
    }
  }
  return SQL_SUCCESS;
}

SQLRETURN custom_run(SQLHDBC ihdbc, SQLCHAR * outjson, SQLINTEGER outlen,
 int fmt, int *key, char **val, int *arr) 
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int i = 0;
  int j = 0;
  int nbr_arv = 0;
  char * arv[JSON400_MAX_KEY];
  int recs = 0;
  int hdbc_external = 0;
  SQLHENV henv = 0;
  SQLHANDLE hdbc = ihdbc;
  SQLHANDLE hstmt = 0;
  SQLINTEGER attr = SQL_TRUE;
  SQLINTEGER attr_isolation = SQL_TXN_NO_COMMIT;
  SQLSMALLINT nParms = 0;
  SQLSMALLINT nResultCols = 0;
  SQLSMALLINT name_length = 0;
  SQLCHAR *buff_name[JSON400_MAX_COLS];
  SQLCHAR *buff_value[JSON400_MAX_COLS];
  SQLINTEGER buff_len[JSON400_MAX_COLS];
  SQLSMALLINT type = 0;
  SQLUINTEGER size = 0;
  SQLSMALLINT scale = 0;
  SQLSMALLINT nullable = 0;
  SQLINTEGER lob_loc = 0;
  SQLINTEGER loc_ind = 0;
  SQLSMALLINT loc_type = 0;
  SQLINTEGER fStrLen = SQL_NTS;
  SQLSMALLINT sql_data_type = 0;
  SQLUINTEGER sql_precision = 0;
  SQLSMALLINT sql_scale = 0;
  SQLSMALLINT sql_nullable = SQL_NO_NULLS;
  /* hdbc external (caller?) */
  if (ihdbc) {
    hdbc_external = 1;
  }
  /* process */
  for (i=0;key[i];i++) {
    switch (key[i]) {
    /* SQLRETURN SQL400pConnect( SQLCHAR * db, SQLCHAR * uid, SQLCHAR * pwd, SQLCHAR * qual, 
     *   SQLINTEGER * ohnd, SQLINTEGER  acommit, SQLCHAR * alibl, SQLCHAR * acurlib );
     */
    case JSON400_KEY_PCONN:
      if (arr[i]) {
        nbr_arv = custom_json_parse_array_values(val[i], arv);
        switch (nbr_arv) {
        case 4:
          sqlrc = SQL400pConnect( arv[0], arv[1], arv[2], arv[3], &hdbc, attr_isolation, NULL, NULL );
          break;
        case 3:
          sqlrc = SQL400pConnect( NULL, arv[0], arv[1], arv[2], &hdbc, attr_isolation, NULL, NULL );
          break;
        case 1:
          sqlrc = SQL400pConnect( NULL, NULL, NULL, arv[0], &hdbc, attr_isolation, NULL, NULL );
        default:
          sqlrc = SQL400pConnect( NULL, NULL, NULL, "ALL", &hdbc, attr_isolation, NULL, NULL );
          break;
        }
      }
      /* do not close (pool connection) */
      if (hdbc) {
        hdbc_external = 1;
      }
      break;
    case JSON400_KEY_CONN:
      if (arr[i]) {
        nbr_arv = custom_json_parse_array_values(val[i], arv);
        switch (nbr_arv) {
        case 3:
          sqlrc = SQL400Connect( arv[0], arv[1], arv[2], &hdbc, attr_isolation, NULL, NULL );
          break;
        case 2:
          sqlrc = SQL400Connect( NULL, arv[0], arv[1], &hdbc, attr_isolation, NULL, NULL );
          break;
        default:
          sqlrc = SQL400Connect( NULL, NULL, NULL, &hdbc, attr_isolation, NULL, NULL );
          break;
        }
      }
      break;
    case JSON400_KEY_QUERY:
      if (!hdbc) {
        sqlrc = SQL400Connect( NULL, NULL, NULL, &hdbc, SQL_TXN_NO_COMMIT, NULL, NULL );
      }
      /* statement */
      sqlrc = SQLAllocHandle(SQL_HANDLE_STMT, (SQLHDBC) hdbc, &hstmt);
      /* prepare */
      sqlrc = SQLPrepare((SQLHSTMT)hstmt, (SQLCHAR*)val[i], (SQLINTEGER)SQL_NTS);
      /* no parm? execute */
      if (key[i+1] != JSON400_KEY_PARM) {
        sqlrc = SQLExecute((SQLHSTMT)hstmt);
      }
      break;
    case JSON400_KEY_PARM:
      if (arr[i]) {
        nbr_arv = custom_json_parse_array_values(val[i], arv);
        /* number of input parms */
        sqlrc = SQLNumParams((SQLHSTMT)hstmt, (SQLSMALLINT*)&nParms);
        if (nParms > 0) {
          for (j = 0; j < nParms; j++) {
            sqlrc = SQLDescribeParam((SQLHSTMT)hstmt, (SQLUSMALLINT)(j + 1), 
                   &sql_data_type, &sql_precision, &sql_scale, &sql_nullable);
            buff_len[j] = SQL_NTS;
            sqlrc = SQLBindParameter((SQLHSTMT)hstmt, (SQLUSMALLINT)(j + 1),
                   SQL_PARAM_INPUT, SQL_CHAR, sql_data_type,
                   sql_precision, sql_scale, arv[j], 0, &buff_len[j]);
          }
        }
      }
      /* execute */
      sqlrc = SQLExecute((SQLHSTMT)hstmt);
      /* no fetch? close */
      if (key[i+1] != JSON400_KEY_FETCH) {
        sqlrc = SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
        /* hdbc external (caller?) or pool (pConnect) */
        if (!hdbc_external) {
          sqlrc = SQL400Close(hdbc);
        }
      }
      break;
    case JSON400_KEY_FETCH:
      /* result set */
      sqlrc = SQLNumResultCols((SQLHSTMT)hstmt, &nResultCols);
      if (nResultCols > 0) {
        for (i = 0 ; i < nResultCols; i++) {
          size = JSON400_EXPAND_COL_NAME;
          buff_name[i] = custom_json_new(size);
          buff_value[i] = NULL;
          sqlrc = SQLDescribeCol((SQLHSTMT)hstmt, (SQLSMALLINT)(i + 1), (SQLCHAR *)buff_name[i], size, &name_length, &type, &size, &scale, &nullable);
          /* dbcs expansion */
          switch (type) {
          case SQL_CHAR:
          case SQL_VARCHAR:
          case SQL_CLOB:
          case SQL_DBCLOB:
          case SQL_UTF8_CHAR:
          case SQL_WCHAR:
          case SQL_WVARCHAR:
          case SQL_GRAPHIC:
          case SQL_VARGRAPHIC:
          case SQL_XML:
            size = size * JSON400_EXPAND_CHAR;
            buff_value[i] = custom_json_new(size);
            sqlrc = SQLBindCol((SQLHSTMT)hstmt, (i + 1), SQL_CHAR, buff_value[i], size, &fStrLen);
            break;
          case SQL_BINARY:
          case SQL_VARBINARY:
          case SQL_BLOB:
            size = size * JSON400_EXPAND_BINARY;
            buff_value[i] = custom_json_new(size);
            sqlrc = SQLBindCol((SQLHSTMT)hstmt, (i + 1), SQL_CHAR, buff_value[i], size, &fStrLen);
            break;
          case SQL_TYPE_DATE:
          case SQL_TYPE_TIME:
          case SQL_TYPE_TIMESTAMP:
          case SQL_DATETIME:
          case SQL_BIGINT:
          case SQL_DECFLOAT:
          case SQL_SMALLINT:
          case SQL_INTEGER:
          case SQL_REAL:
          case SQL_FLOAT:
          case SQL_DOUBLE:
          case SQL_DECIMAL:
          case SQL_NUMERIC:
          default:
            size = JSON400_EXPAND_OTHER;
            buff_value[i] = custom_json_new(size);
            sqlrc = SQLBindCol((SQLHSTMT)hstmt, (i + 1), SQL_CHAR, buff_value[i], size, &fStrLen);
            break;
          }
        }
        sqlrc = SQL_SUCCESS;
        custom_output_record_array_beg(fmt, outjson);
        while (sqlrc == SQL_SUCCESS) {
          sqlrc = SQLFetch(hstmt);
          if (sqlrc == SQL_NO_DATA_FOUND) {
            break;
          }
          custom_output_record_row_beg(fmt, recs, outjson);
          recs += 1;
          for (i = 0 ; i < nResultCols; i++) {
            if (buff_value[i]) {
              custom_output_record_name_value(fmt,i,buff_name[i],buff_value[i], outjson);
            }
          }
          custom_output_record_row_end(fmt, outjson);
        }
        custom_output_record_array_end(fmt, outjson);
        for (i = 0 ; i < nResultCols; i++) {
          if (buff_value[i]) {
            custom_json_free(buff_name[i]);
            buff_name[i] = NULL;
          }
          if (buff_name[i]) {
            custom_json_free(buff_name[i]);
            buff_name[i] = NULL;
          }
        }
      }
      /* close */
      sqlrc = SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
      /* hdbc external (caller?) or pool (pConnect) */
      if (!hdbc_external) {
        sqlrc = SQL400Close(hdbc);
      }
      break;
    }
  } // end for
}

/* json
 * {"query":"select * from bobdata","fetch":"*ALL"}
 * {"query":"call proc(?,?,?)","parm":[1,2,"bob"]}
 * {"connect":["*LOCAL","UID","PWD"],"query":"call proc(?,?,?)","parm":[1,2,"bob"],"fetch":"*ALL"}
 * {"pconnect":["id"],"query":"call proc(?,?,?)","parm":[1,2,"bob"],"fetch":"*ALL"}
 */
SQLRETURN custom_SQL400Json(SQLHDBC hdbc,
 SQLCHAR * injson,
 SQLINTEGER inlen, 
 SQLCHAR * outjson,
 SQLINTEGER outlen) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  int i = 0;
  int j = 0;
  int k = 0;
  char * c = NULL;
  char * f = NULL;
  char * copyin = NULL;
  int fmt = JSON400_OUT_JSON_STDOUT;
  int key[JSON400_MAX_KEY];
  char * val[JSON400_MAX_KEY];
  int arr[JSON400_MAX_KEY];
  int find_look[JSON400_NBR_KEYS];
  /* output format */
  if (outjson && outlen) {
    fmt = JSON400_OUT_JSON_BUFF;
  } else {
    fmt = JSON400_OUT_JSON_STDOUT;
  }
  /* copy in */
  copyin = custom_json_new(inlen + 1);
  strcpy(copyin,injson);
  /* fast look loop */
  for (i=0; i<JSON400_NBR_KEYS; i++) {
    find_look[i] = 1;
  }
  /* parse json */
  for (i=0, f=copyin, c=copyin; i+1<JSON400_MAX_KEY && f; i++) {
    val[i] = NULL;
    arr[i] = NULL;
    key[i] = 0;
    val[i+1] = NULL;
    arr[i+1] = NULL;
    key[i+1] = 0;
    for (j=0, c = f; !key[i] && f && c[j]; j++) {
      /* "key":[value,...]
       * "key":"value"
       * x
       */
      if (c[j] == '"') {
        for (k=0; !key[i] && k < JSON400_NBR_KEYS; k++) {
          f = custom_json_parse_key_value(f, k, JSON400_KEYS, JSON400_ORDS, find_look, i, key, val, arr);
        }
      }
    }
  }   
  /* run */
  sqlrc = custom_run(hdbc, outjson, outlen, fmt, key, val, arr);
  /* free copyin */
  if (copyin) {
    custom_json_free(copyin);
  }
  return sqlrc;
}

char * custom_json_parse_key_value(char * c, int find, char **find_key, int *find_ord, int *find_look, int idx, int *k, char **v, int *a) {
  int i = 0;
  char * f = NULL;
  char * w = NULL;
  char * x = NULL;
  /* key will never be found 
   * -- or --
   * key already found at idx
   */
  if (!find_look[find] || k[idx]) {
    return c;
  }
  /* find "key": */
  f = strstr(c,find_key[find]);
  if (f) {
    f[0] = ' ';
    k[idx] = find_ord[find];
    f += strlen(find_key[find]);
    c = f;
  /* key will never be found */
  } else {
    find_look[find] = 0;
    return c;
  }
  /* find :"value" */
  for (i=0; c[i]; i++) {
    switch(c[i]) {
    /* "query":"select ..."
     *         x
     */
    case '"':
      i++;
      w = &c[i];
      a[idx] = 0;
      for (; c[i]; i++) {
        x = &c[i];
        switch(c[i]) {
        /* "query":"select ..."
         *                    x
         */
        case '"':
          c[i]=0x00;
          v[idx] = w;
          i++;
          return &c[i+1];
          break;
        }
      }
      break;
    /* "parm":[1,2,"bob"]
     *        x
     */
    case '[':
      i++;
      w = &c[i];
      a[idx] = 1;
      for (; c[i]; i++) {
        x = &c[i];
        switch(c[i]) {
        /* "parm":[1,2,"bob"]
         *                  x
         */
        case ']':
          c[i]=0x00;
          v[idx] = w;
          i++;
          return &c[i+1];
          break;
        }
      }
      break;
    default:
      break;
    }
  }
  return NULL;
}


int custom_json_parse_array_values(char *c, char **v) {
  int i = 0;
  int idx = 0;
  char * f = c;
  char * g = c;
  /* "parm":[1,2,"bob"]
   *         x
   */
  for (i=0; c[i]; i++) {
    switch(c[i]) {
    /* "parm":[1,2,"bob"]
     *             x
     */
    case '"':
      i++;
      f = &c[i];
      for (; c[i]; i++) {
        g = &c[i];
        /* "parm":[1,2,"bob"]
         *                 x
         */
        if (c[i] == '"') {
          c[i]=0x00;
          v[idx] = f;
          idx++;
          break;
        }
      }
      break;
    case ' ':
      break;
    default:
      /* "parm":[1,2,"bob"]
       *         x
       */
      if (c[i]>='0' && c[i]<='9') {
        f = &c[i];
        for (i++; ;i++) {
          if (c[i] >= '0' && c[i] <= '9') {
            continue;
          }
          c[i]=0x00;
          v[idx] = f;
          idx++;
          break;
        }
      }
    }
  }
  return idx;
}


