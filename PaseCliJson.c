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

#define SQL400_MAX_KEY 65000
#define SQL400_KEY_CONN 1
#define SQL400_KEY_QUERY 2
#define SQL400_KEY_PARM 3
#define SQL400_KEY_FETCH 4
#define SQL400_MAX_ARGS 32
#define SQL400_MAX_COLS 1024

#define SQL400_MAX_ERR_MSG_LEN (SQL_MAX_MESSAGE_LENGTH + SQL_SQLSTATE_SIZE + 10)

#define SQL400_EXPAND_CHAR 3
#define SQL400_EXPAND_BINARY 2
#define SQL400_EXPAND_OTHER 64
#define SQL400_EXPAND_COL_NAME 128

#define SQL400_UNKNOWN -1

#define SQL400_CMD_HELP 1
#define SQL400_CMD_QUERY 2

#define SQL400_OUT_COMMA 11
#define SQL400_OUT_JSON 12
#define SQL400_OUT_SPACE 13
#define SQL400_OUT_COMMA_BUFF 21
#define SQL400_OUT_JSON_BUFF 22
#define SQL400_OUT_SPACE_BUFF 23


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
  case SQL400_OUT_JSON:
    printf("{\"records\":[");
    break;
  case SQL400_OUT_JSON_BUFF:
    custom_output_printf(out_caller, "{\"records\":[");
    break;
  case SQL400_OUT_SPACE:
    break;
  case SQL400_OUT_SPACE_BUFF:
    break;
  case SQL400_OUT_COMMA:
    break;
  case SQL400_OUT_COMMA_BUFF:
    break;
  default:
    break;
  }
}
void custom_output_record_row_beg(int fmt, int flag, char *out_caller) {
  switch (fmt) {
  case SQL400_OUT_JSON:
    if (flag) {
      printf(",\n{");
    } else {
      printf("\n{");
    }
    break;
  case SQL400_OUT_JSON_BUFF:
    if (flag) {
      custom_output_printf(out_caller, ",\n{");
    } else {
      custom_output_printf(out_caller, "\n{");
    }
    break;
  case SQL400_OUT_SPACE:
    break;
  case SQL400_OUT_SPACE_BUFF:
    break;
  case SQL400_OUT_COMMA:
    break;
  case SQL400_OUT_COMMA_BUFF:
    break;
  default:
    break;
  }
}
void custom_output_record_name_value(int fmt, int flag, char *name, char *value, char *out_caller) {
  switch (fmt) {
  case SQL400_OUT_JSON:
    if (flag) {
      printf(",");
    }
    printf("\"%s\":\"%s\"",name,value);
    break;
  case SQL400_OUT_JSON_BUFF:
    if (flag) {
      custom_output_printf(out_caller, ",");
    }
    custom_output_printf(out_caller, "\"%s\":\"%s\"",name,value);
    break;
  case SQL400_OUT_SPACE:
    if (flag) {
      printf(" ");
    }
    printf("\"%s\"",value);
    break;
  case SQL400_OUT_SPACE_BUFF:
    if (flag) {
      custom_output_printf(out_caller, " ");
    }
    custom_output_printf(out_caller, "\"%s\"",value);
    break;
  case SQL400_OUT_COMMA:
    if (flag) {
      printf(",");
    }
    printf("\"%s\"",value);
    break;
  case SQL400_OUT_COMMA_BUFF:
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
  case SQL400_OUT_JSON:
    printf("}");
    break;
  case SQL400_OUT_JSON_BUFF:
    custom_output_printf(out_caller, "}");
    break;
  case SQL400_OUT_SPACE:
    printf("\n");
    break;
  case SQL400_OUT_SPACE_BUFF:
    custom_output_printf(out_caller, "\n");
    break;
  case SQL400_OUT_COMMA:
    printf("\n");
    break;
  case SQL400_OUT_COMMA_BUFF:
    custom_output_printf(out_caller, "\n");
    break;
  default:
    break;
  }
}
void custom_output_record_array_end(int fmt, char *out_caller) {
  switch (fmt) {
  case SQL400_OUT_JSON:
    printf("\n]}\n");
    break;
  case SQL400_OUT_JSON_BUFF:
    custom_output_printf(out_caller, "\n]}\n");
    break;
  case SQL400_OUT_SPACE:
    printf("\n");
    break;
  case SQL400_OUT_SPACE_BUFF:
    custom_output_printf(out_caller, "\n");
    break;
  case SQL400_OUT_COMMA:
    printf("\n");
    break;
  case SQL400_OUT_COMMA_BUFF:
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
  SQLCHAR errMsg[SQL400_MAX_ERR_MSG_LEN];
  SQLINTEGER sqlcode = 0;
  SQLSMALLINT length = 0;
  SQLCHAR *p = NULL;
  SQLSMALLINT recno = 1;
  if (rc == SQL_ERROR) {
    memset(msg, '\0', SQL_MAX_MESSAGE_LENGTH + 1);
    memset(sqlstate, '\0', SQL_SQLSTATE_SIZE + 1);
    memset(errMsg, '\0', SQL400_MAX_ERR_MSG_LEN);
    if ( SQLGetDiagRec(hType, handle, recno, sqlstate, &sqlcode, msg, SQL_MAX_MESSAGE_LENGTH + 1, &length)  == SQL_SUCCESS ) {
      if (msg[length-1] == '\n') {
        p = &msg[length-1];
        *p = '\0';
      }
      switch (fmt) {
      case SQL400_OUT_JSON:
        printf("{\"ok\":false,\"reason\":\"error %s SQLCODE=%d\"}",msg, sqlcode);
        break;
      case SQL400_OUT_JSON_BUFF:
        custom_output_printf(out_caller, "{\"ok\":false,\"reason\":\"error %s SQLCODE=%d\"}",msg, sqlcode);
        break;
      case SQL400_OUT_SPACE:
        printf("\"error=%s SQLCODE=%d\"\n",msg, sqlcode);
        break;
      case SQL400_OUT_SPACE_BUFF:
        custom_output_printf(out_caller, "\"error=%s SQLCODE=%d\"\n",msg, sqlcode);
        break;
      case SQL400_OUT_COMMA:
        printf("\"error %s, SQLCODE=%d\"\n",msg, sqlcode);
        break;
      case SQL400_OUT_COMMA_BUFF:
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
  char * arv[SQL400_MAX_KEY];
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
  SQLCHAR *buff_name[SQL400_MAX_COLS];
  SQLCHAR *buff_value[SQL400_MAX_COLS];
  SQLINTEGER buff_len[SQL400_MAX_COLS];
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
    case SQL400_KEY_CONN:
      if (arr[i]) {
        nbr_arv = custom_json_parse_array_values(val[i], arv);
        switch (nbr_arv) {
        case 3:
          sqlrc = custom_SQL400Connect( val[0], val[1], val[2], &hdbc, attr_isolation, NULL, NULL );
          break;
        case 2:
          sqlrc = custom_SQL400Connect( NULL, val[1], val[2], &hdbc, attr_isolation, NULL, NULL );
          break;
        default:
          sqlrc = custom_SQL400Connect( NULL, NULL, NULL, &hdbc, attr_isolation, NULL, NULL );
          break;
        }
      }
      break;
    case SQL400_KEY_QUERY:
      if (!hdbc) {
        sqlrc = custom_SQL400Connect( NULL, NULL, NULL, &hdbc, SQL_TXN_NO_COMMIT, NULL, NULL );
      }
      /* statement */
      sqlrc = SQLAllocHandle(SQL_HANDLE_STMT, (SQLHDBC) hdbc, &hstmt);
      /* prepare */
      sqlrc = SQLPrepare((SQLHSTMT)hstmt, (SQLCHAR*)val[i], (SQLINTEGER)SQL_NTS);
      /* execute */
      if (key[i+1] != SQL400_KEY_PARM) {
        sqlrc = SQLExecute((SQLHSTMT)hstmt);
      }
      break;
    case SQL400_KEY_PARM:
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
      /* internal handle */
      if (key[i+1] != SQL400_KEY_FETCH) {
        sqlrc = SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
      }
      break;
    case SQL400_KEY_FETCH:
      /* result set */
      sqlrc = SQLNumResultCols((SQLHSTMT)hstmt, &nResultCols);
      if (nResultCols > 0) {
        for (i = 0 ; i < nResultCols; i++) {
          size = SQL400_EXPAND_COL_NAME;
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
            size = size * SQL400_EXPAND_CHAR;
            buff_value[i] = custom_json_new(size);
            sqlrc = SQLBindCol((SQLHSTMT)hstmt, (i + 1), SQL_CHAR, buff_value[i], size, &fStrLen);
            break;
          case SQL_BINARY:
          case SQL_VARBINARY:
          case SQL_BLOB:
            size = size * SQL400_EXPAND_BINARY;
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
            size = SQL400_EXPAND_OTHER;
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
      /* internal handle */
      sqlrc = SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
      /* hdbc external (caller?) */
      if (!hdbc_external && hdbc) {
        sqlrc = SQLDisconnect((SQLHDBC)hdbc);
        sqlrc = SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
      }
      break;
    }
  }
}

char * custom_json_parse_value(char * c, int idx, char **v, int *a) {
  int i = 0;
  char * f = c;
  char * g = c;
  char * w = c;
  char * x = c;
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
          return &c[i];
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
          return &c[i];
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

/* json
 * {"query":"select * from bobdata","fetch":"*ALL"}
 * {"query":"call proc(?,?,?)","parm":[1,2,"bob"]}
 * {"connect":["*LOCAL","UID","PWD"],"query":"call proc(?,?,?)","parm":[1,2,"bob"],"fetch":"*ALL"}
 */
SQLRETURN custom_SQL400Json(SQLHDBC hdbc,
 SQLCHAR * injson,
 SQLINTEGER inlen, 
 SQLCHAR * outjson,
 SQLINTEGER outlen) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  int i = 0;
  int j = 0;
  char * c = NULL;
  char * f = NULL;
  char * g = NULL;
  char * copyin = NULL;
  int fmt = SQL400_OUT_JSON;
  char * val[SQL400_MAX_KEY];
  int arr[SQL400_MAX_KEY];
  int key[SQL400_MAX_KEY];
  char * conn_key = "\"connect\":";
  char * query_key = "\"query\":";
  char * parm_key = "\"parm\":";
  char * fetch_key = "\"fetch\":";
  int conn_look = 1;
  int query_look = 1;
  int parm_look = 1;
  int fetch_look = 1;
  int conn_len = strlen(conn_key);
  int query_len = strlen(query_key);
  int parm_len = strlen(parm_key);
  int fetch_len = strlen(fetch_key);
  /* output format */
  if (outjson && outlen) {
    fmt = SQL400_OUT_JSON_BUFF;
  } else {
    fmt = SQL400_OUT_JSON;
  }
  /* copy in */
  copyin = custom_json_new(inlen + 1);
  strcpy(copyin,injson);
  /* parse json */
  for (i=0, f=copyin, c=copyin; i+1<SQL400_MAX_KEY && f; i++) {
    val[i] = NULL;
    arr[i] = NULL;
    key[i] = 0;
    val[i+1] = NULL;
    arr[i+1] = NULL;
    key[i+1] = 0;
    for (j=0, c = f; f && c[j]; j++) {
      /* "connect":["*LOCAL","UID","PWD"]
       * "query":"select * ..."
       * "parm":[1,2,"bob"]
       * "fetch":"*ALL"
       * x
       */
      if (c[j] == '"') {
        f = NULL;
        g = &c[j];
        /* "connect":["*LOCAL","UID","PWD"]
         * x
         */
        if (conn_look) {
          f = strstr(g,conn_key);
          if (f) {
            f[0] = ' ';
            key[i] = SQL400_KEY_CONN;
            f += conn_len;
            f = custom_json_parse_value(f,i,val,arr);
            break;
          } else {
            conn_look = 0;
          }
        }
        /* "query":"select * ..."
         * x
         */
        if (query_look) {
          f = strstr(g,query_key);
          if (f) {
            f[0] = ' ';
            key[i] = SQL400_KEY_QUERY;
            f += query_len;
            f = custom_json_parse_value(f,i,val,arr);
            break;
          } else {
            query_look = 0;
          }
        }
        /* "parm":[1,2,"bob"]
         * x
         */
        if (parm_look) {
          f = strstr(g,parm_key);
          if (f) {
            f[0] = ' ';
            key[i] = SQL400_KEY_PARM;
            f += parm_len;
            f = custom_json_parse_value(f,i,val,arr);
            break;
          } else {
            parm_look = 0;
          }
        }
        /* "fetch":"*ALL"
         * x
         */
        if (fetch_look) {
          f = strstr(g,fetch_key);
          if (f) {
            f[0] = ' ';
            key[i] = SQL400_KEY_FETCH;
            f += fetch_len;
            f = custom_json_parse_value(f,i,val,arr);
            break;
          } else {
            fetch_look = 0;
          }
        }
        /* done */
        break;
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


