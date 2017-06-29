#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dlfcn.h>
#include <iconv.h>
#include <stdarg.h>
#include <sqlcli1.h>
#include <as400_types.h>
#include <as400_protos.h>
#include "PaseCliInit.h"
#include "PaseCliAsync.h"
#include "PaseTool.h"

/*
 * == WARNING ==
 * The json format is changing. The 'temp format'
 * below was only used to checkout some basic
 * toolkit callback functions (db2sock/toolkit-base).
 * When project warnings are removed, you may
 * rely on json format.
 */


/* json
 * request {
 * -- toolkit database --
 * "query":"select * from bobdata",
 *   "fetch":"*ALL",
 * "query":"call proc(?,?,?)",
 *   "parm":[1,2,"bob"],
 * "connect":["*LOCAL","UID","PWD"],
 *   "query":"call proc(?,?,?)",
 *   "parm":[1,2,"bob"],
 *   "fetch":"*ALL",
 * "pconnect":["id"],
 *   "query":"select * from davedata where name=? and level=? and reports=?",
 *   "parm":[1,2,"bob"],
 *   "fetch":"*ALL",
 * -- toolkit commmand --
 * "cmd":"ADDLIBLE LIB(DB2JSON)",
 * -- toolkit program --
 * "pgm":["NAME","LIB","procedure"],
 *   "dcl-ds":["name",dimension, "in|out|both|value|const|return", "dou-name"],
 *   "end-ds":"name",
 *   "dcl-s":["name","type", value, dimension, "in|out|both|value|const|return",ccsid],
 * "end-pgm":"NAME",
 * -- complex parm (example)               -- temp_t[] RegionTemps(regions_t,int,int)
 * "pgm":["CLIMATE","MYLIB","RegionTemps"],-- *SRVPGM MYLIB/CLIMATE
 *   "dcl-ds":["regions_t"],               -- ds parm assumed "both"
 *     "dcl-s":["region","5a","TX"],       -- region[0] = "TX"
 *     "dcl-s":["region","5a","MN"],       -- region[1] = "MN"
 *     "dcl-s":["region","5a","", 20],     -- region[2-21] = ""
 *     "dcl-ds":["people_t",20],           -- ds[20] nested
 *       "dcl-s":["first","32a"],
 *       "dcl-s":["last","32a"],
 *     "end-ds":"people_t",
 *   "end-ds":"regions_t",
 * -- single parm --
 *   "dcl-s":["countout","10i0",0,"both"],
 *   "dcl-s":["available","10i0"],         -- assumed "both" (not inside ds) --
 * -- complex return value --
 *   "dcl-ds":["temp_t",999, "return","countout"],
 *     "dcl-s":["region","5a"],
 *     "dcl-s":["min","12p2"],
 *     "dcl-s":["max","12p2"],
 *   "end-ds":"temp_t",
 * "end-pgm":"CLIMATE",
 * }
 * -- types --
 * "5a"    char(5)         char a[5]
 * "5av2"  varchar(5:2)    struct varchar{short,a[5]}
 * "5av4"  varchar(5:4)    struct varchar{int,a[5]}
 * "5b"    binary(5)       char a[5]
 * "5bv2"  varbinary(5:2)  struct varbinary{short,a[5]}
 * "5bv4"  varbinary(5:4)  struct varbinary{int,a[5]}
 * "3i0"   int(3)          int8, char
 * "5i0"   int(5)          int16, short
 * "10i0"  int(10)         int32, int, long
 * "20i0"  int(20)         int64, long long
 * "3u0"   uns(3)          uint8, uchar, char
 * "5u0"   uns(5)          uint16, ushort, unsigned short
 * "10u0"  uns(10)         uint32, uint, unsigned long
 * "20u0"  uns(20)         uint64, ulonglong, unsigned long long
 * "4f2"   float           float
 * "8f2"   double          double
 * "12p2"  packed(12:2)    (no c equiv)
 * "12s2"  zoned(12:2)     (no c equiv)
 * "8h"    hole            hole
 */


#define JSON400_ADJUST_NDA 0
#define JSON400_ADJUST_ADD_COMMA 1
#define JSON400_ADJUST_ADD_SPACE 2
#define JSON400_ADJUST_RMV_COMMA 3

char * JSON400_KEYS[TOOL400_NBR_KEYS] = {
  "\"pconnect\":",
  "\"connect\":",
  "\"query\":",
  "\"parm\":",
  "\"fetch\":",
  "\"cmd\":",
  "\"pgm\":",
  "\"dcl-s\":",
  "\"dcl-ds\":",
  "\"end-ds\":",
  "\"end-pgm\":"
};

int JSON400_ORDS[TOOL400_NBR_KEYS] = {
  TOOL400_KEY_PCONN,
  TOOL400_KEY_CONN,
  TOOL400_KEY_QUERY,
  TOOL400_KEY_PARM,
  TOOL400_KEY_FETCH,
  TOOL400_KEY_CMD,
  TOOL400_KEY_PGM,
  TOOL400_KEY_DCL_S,
  TOOL400_KEY_DCL_DS,
  TOOL400_KEY_END_DS,
  TOOL400_KEY_END_PGM
};

void * json_new(int size) {
  void * buffer = malloc(size + 1);
  memset(buffer,0,size + 1);
  return buffer;
}
void json_free(char *buffer) {
  if (buffer) {
    free(buffer);
  }
}

void json_output_printf(int adjust, char *out_caller, const char * format, ...) {
  char *p = (char *) NULL; 
  char *q = (char *) NULL; 
  int l = 0;
  int w = 0;
  l = strlen(out_caller);
  p = out_caller + l;
  if (l) {
    w = l - 1;
    q = out_caller + w;
  } else {
    q = p;
  }
  switch (adjust) {
  case JSON400_ADJUST_ADD_COMMA:
    if (q[0] == '{' || q[0] == '[' || q[0] == ':') {
      /* do nothing */
    } else  if (q[0] != ',') {
      p[0] = ',';
      l++;
      p = out_caller + l;
    }
    break;
  case JSON400_ADJUST_ADD_SPACE:
    if (q[0] != ' ') {
      p[0] = ' ';
      l++;
      p = out_caller + l;
    }
    break;
  case JSON400_ADJUST_RMV_COMMA:
    if (q[0] == ',') {
      q[0] = 0x00;
      l--;
      p = out_caller + l;
    }
    break;
  default:
    break;
  }
  va_list args;
  va_start(args, format);
  vsprintf(p, format, args);
  va_end(args);
}

void json_output_script_beg(char *out_caller) {
  json_output_printf(JSON400_ADJUST_NDA, out_caller, 
    "{\"script\":[");
}
void json_output_script_end(char *out_caller) {
  json_output_printf(JSON400_ADJUST_RMV_COMMA, out_caller, 
    "]}");
}

void json_output_record_array_beg(char *out_caller) {
  json_output_printf(JSON400_ADJUST_ADD_COMMA, out_caller, 
    "{\"records\":[");
}
void json_output_record_array_end(char *out_caller) {
  json_output_printf(JSON400_ADJUST_RMV_COMMA, out_caller, 
    "]}");
}

void json_output_record_no_data_found(char *out_caller) {
  json_output_printf(JSON400_ADJUST_NDA, out_caller, 
    "\"SQL_NO_DATA_FOUND\"");
}


void json_output_record_row_beg(char *out_caller) {
  json_output_printf(JSON400_ADJUST_ADD_COMMA, out_caller, 
    "{");
}
void json_output_record_name_value(char *name, char *value, int type, int fStrLen, char *out_caller) {
  int i = 0;
  int len = 0;
  char * fmt_val_char = "\"%s\"";
  char * fmt_key_val_char = "\"%s\":\"%s\"";
  char * fmt_val_zero_dec = "0%s";
  char * fmt_key_val_zero_dec = "\"%s\":0%s";
  char * fmt_val_dec = "%s";
  char * fmt_key_val_dec = "\"%s\":%s";
  char * fmt_val = NULL;
  char * fmt_key_val = NULL;
  char * fmt_json_null = "null";
  if (fStrLen == SQL_NULL_DATA) {
    value = fmt_json_null;
    fmt_val = fmt_val_dec;
    fmt_key_val = fmt_key_val_dec;
  } else {
    switch (type) {
    case SQL_BIGINT:
    case SQL_DECFLOAT:
    case SQL_SMALLINT:
    case SQL_INTEGER:
    case SQL_REAL:
    case SQL_FLOAT:
    case SQL_DOUBLE:
    case SQL_DECIMAL:
    case SQL_NUMERIC:
      if (value[0] == '.') {
        fmt_val = fmt_val_zero_dec;
        fmt_key_val = fmt_key_val_zero_dec;
      } else {
        fmt_val = fmt_val_dec;
        fmt_key_val = fmt_key_val_dec;
      }
      break;
    default:
      fmt_val = fmt_val_char;
      fmt_key_val = fmt_key_val_char;
      /* trim */
      len = strlen(value);
      for (i=len; i>0; i--) {
        if (!value[i] || value[i] == ' ') {
          value[i] = 0x00;
        } else {
          break;
        }
      }
      break;
    }
  }
  json_output_printf(JSON400_ADJUST_ADD_COMMA, out_caller, fmt_key_val, name, value);
}
void json_output_record_row_end(char *out_caller) {
  json_output_printf(JSON400_ADJUST_RMV_COMMA, out_caller, 
    "}");
}

/*
  json_output_sql_errors(fmt, henv, SQL_HANDLE_ENV,   rc);
  json_output_sql_errors(fmt, hdbc, SQL_HANDLE_DBC,   rc);
  json_output_sql_errors(fmt, hstmt, SQL_HANDLE_STMT, rc);
*/
int json_output_sql_errors(SQLHANDLE handle, SQLSMALLINT hType, int rc, char *out_caller)
{
  SQLCHAR msg[SQL_MAX_MESSAGE_LENGTH + 1];
  SQLCHAR sqlstate[SQL_SQLSTATE_SIZE + 1];
  SQLCHAR errMsg[TOOL400_MAX_ERR_MSG_LEN];
  SQLINTEGER sqlcode = 0;
  SQLSMALLINT length = 0;
  SQLCHAR *p = NULL;
  SQLSMALLINT recno = 1;
  if (rc == SQL_ERROR) {
    memset(msg, '\0', SQL_MAX_MESSAGE_LENGTH + 1);
    memset(sqlstate, '\0', SQL_SQLSTATE_SIZE + 1);
    memset(errMsg, '\0', TOOL400_MAX_ERR_MSG_LEN);
    if ( SQLGetDiagRec(hType, handle, recno, sqlstate, &sqlcode, msg, SQL_MAX_MESSAGE_LENGTH + 1, &length)  == SQL_SUCCESS ) {
      if (msg[length-1] == '\n') {
        p = &msg[length-1];
        *p = '\0';
      }
      json_output_printf(JSON400_ADJUST_ADD_COMMA, out_caller, 
        "\n{\"ok\":false,\"reason\":\"error %s SQLCODE=%d\"}",msg, sqlcode);
      return SQL_ERROR;
    }
  }
  return SQL_SUCCESS;
}

/* pgm call */
void json_output_pgm_beg(char *out_caller, char * name, char * lib, char * func) {
  if (!lib) {
    lib = "*LIBL";
  }
  if (!func) {
    func = "";
  }
  json_output_printf(JSON400_ADJUST_ADD_COMMA, out_caller, 
    "{\"pgm\":[\"%s\",\"%s\",\"%s\"", name, lib, func);
}
void json_output_pgm_end(char *out_caller) {
  json_output_printf(JSON400_ADJUST_RMV_COMMA, out_caller, 
    "]}");
}

void json_output_pgm_dcl_s_beg(char *out_caller, char * name, int tdim) {
  if (tdim > 1) {
    json_output_printf(JSON400_ADJUST_ADD_COMMA, out_caller, 
      "{\"%s\":[", name);
  } else {
    json_output_printf(JSON400_ADJUST_ADD_COMMA, out_caller, 
      "{\"%s\":", name);
  }
}
void json_output_pgm_dcl_s_data(char *out_caller, char *value, int numFlag) {
  if (numFlag == 1) {
    json_output_printf(JSON400_ADJUST_ADD_COMMA, out_caller, 
      "%s", value);
  } else {
    json_output_printf(JSON400_ADJUST_ADD_COMMA, out_caller, 
      "\"%s\"", value);
  }
}
void json_output_pgm_dcl_s_end(char *out_caller, int tdim) {
  if (tdim > 1) {
    json_output_printf(JSON400_ADJUST_RMV_COMMA, out_caller,
      "]}");
  } else {
    json_output_printf(JSON400_ADJUST_RMV_COMMA, out_caller, 
      "}");
  }
}

char * json_parse_key_value(char * c, int find, char **find_key, int *find_ord, int *find_look, int idx, int *k, char **v, int *a) {
  int i = 0;
  char * f = NULL;
  char * w = NULL;
  char * x = NULL;
  char * key = NULL;
  /* key will never be found 
   * -- or --
   * key already found at idx
   */
  if (!find_look[find] || k[idx]) {
    return c;
  }
  /* find "key": */
  key = find_key[find];
  f = strstr(c,key);
  /* found */
  if (f) {
    /* found in start position */
    if ((void *)f == (void *)c) {
      f[0] = ' ';
      k[idx] = find_ord[find];
      f += strlen(key);
      c = f;
    /* found, but not start position */
    } else {
      return c;
    }
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


int json_isnum_decorated(char c) {
  if (c >= '0' && c <= '9') {
    return 1;
  }
  switch(c){
  case '-':
  case '.':
    return 1;
  default:
    break;
  }
  return 0;
}
int json_isnum_digit(char c) {
  if (c >= '0' && c <= '9') {
    return 1;
  }
  return 0;
}


int json_parse_array_values(char *c, char **v) {
  int i = 0;
  int idx = 0;
  char * f = c;
  char * g = c;
  int max = strlen(c);
  /* "parm":[1,2,"bob"]
   *         x
   */
  for (i=0; c[i] && i < max; i++) {
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
      if (json_isnum_decorated(c[i])) {
        f = &c[i];
        for (i++; ;i++) {
          if (json_isnum_decorated(c[i])) {
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
  char * stdbuf = NULL;
  int key[TOOL400_MAX_KEY];
  char * val[TOOL400_MAX_KEY];
  int arr[TOOL400_MAX_KEY];
  int find_look[TOOL400_NBR_KEYS];
  tool_struct_t *tool = NULL;
  /* output format */
  if (!outjson || !outlen) {
    stdbuf = json_new(TOOL400_OUT_MAX_STDOUT);
    outjson = stdbuf;
    outlen = TOOL400_OUT_MAX_STDOUT;
  }
  /* copy in */
  copyin = json_new(inlen + 1);
  strcpy(copyin,injson);
  /* fast look loop */
  for (i=0; i<TOOL400_NBR_KEYS; i++) {
    find_look[i] = 1;
  }
  /* parse json */
  for (i=0, f=copyin, c=copyin; i+1<TOOL400_MAX_KEY && f; i++) {
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
        for (k=0; !key[i] && k < TOOL400_NBR_KEYS; k++) {
          f = json_parse_key_value(&c[j], k, JSON400_KEYS, JSON400_ORDS, find_look, i, key, val, arr);
        }
      }
    }
  }   
  /* run */
  tool = tool_ctor(
    &json_parse_array_values,
    &json_output_script_beg,
    &json_output_script_end,
    &json_output_record_array_beg,
    &json_output_record_array_end,
    &json_output_record_no_data_found,
    &json_output_record_row_beg,
    &json_output_record_name_value,
    &json_output_record_row_end,
    &json_output_sql_errors,
    &json_output_pgm_beg,
    &json_output_pgm_end,
    &json_output_pgm_dcl_s_beg,
    &json_output_pgm_dcl_s_data,
    &json_output_pgm_dcl_s_end
  );
  sqlrc = tool_run(hdbc, outjson, outlen, tool, key, val, arr);
  tool_dtor(tool);
  /* free copyin */
  if (copyin) {
    json_free(copyin);
  }
  /* free stdbuf */
  if (stdbuf) {
    printf(stdbuf);
    printf("\n");
    fflush(stdout);
    json_free(stdbuf);
  }
  return sqlrc;
}


