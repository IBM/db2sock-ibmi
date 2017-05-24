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

#define JSON400_OUT_MAX_STDOUT 1000000

#define JSON400_MAX_KEY 65000

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

#define JSON400_MAX_CMD_BUFF 4096

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
 * "4f"    float           float
 * "8f"    double          double
 * "12p2"  packed(12:2)    (no c equiv)
 * "12s2"  zoned(12:2)     (no c equiv)
 * "8h"    hole            hole
 */
#define JSON400_NBR_KEYS 11
#define JSON400_KEY_CONN 1
#define JSON400_KEY_PCONN 2
#define JSON400_KEY_QUERY 10
#define JSON400_KEY_PARM 20
#define JSON400_KEY_FETCH 30
#define JSON400_KEY_CMD 40
#define JSON400_KEY_PGM 50
#define JSON400_KEY_DCL_S 51
#define JSON400_KEY_DCL_DS 52
#define JSON400_KEY_END_DS 53
#define JSON400_KEY_END_PGM 54
char * JSON400_KEYS[JSON400_NBR_KEYS] = {
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
int JSON400_ORDS[JSON400_NBR_KEYS] = {
  JSON400_KEY_PCONN,
  JSON400_KEY_CONN,
  JSON400_KEY_QUERY,
  JSON400_KEY_PARM,
  JSON400_KEY_FETCH,
  JSON400_KEY_CMD,
  JSON400_KEY_PGM,
  JSON400_KEY_DCL_S,
  JSON400_KEY_DCL_DS,
  JSON400_KEY_END_DS,
  JSON400_KEY_END_PGM
};

#define JSON400_ADJUST_NDA 0
#define JSON400_ADJUST_ADD_COMMA 1
#define JSON400_ADJUST_ADD_SPACE 2
#define JSON400_ADJUST_RMV_COMMA 3

#define ILE_PGM_BY_REF_IN 1
#define ILE_PGM_BY_REF_OUT 2
#define ILE_PGM_BY_REF_BOTH 3
#define ILE_PGM_BY_VALUE 4
#define ILE_PGM_BY_RETURN 5
#define ILE_PGM_BY_IN_DS 6


#define ILE_PGM_MAX_ARGS 128
#define ILE_PGM_ALLOC_BLOCK 4096
typedef struct ile_pgm_call_struct {
  ILEpointer argv[ILE_PGM_MAX_ARGS];
  int argv_parm[ILE_PGM_MAX_ARGS];
  int arg_by[ILE_PGM_MAX_ARGS];
  int arg_pos[ILE_PGM_MAX_ARGS];
  int arg_len[ILE_PGM_MAX_ARGS];
  char pgm[16];
  char lib[16];
  char func[128];
  int max;
  int pos;
  int vpos;
  int argc;
  int parmc;
  char * buf;
} ile_pgm_call_t;


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

void custom_output_printf(int adjust, char *out_caller, const char * format, ...) {
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
    if (q[0] == '{' || q[0] == '[') {
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

void custom_output_script_beg(int fmt, char *out_caller) {
  switch (fmt) {
  case JSON400_OUT_JSON_STDOUT:
    custom_output_printf(JSON400_ADJUST_NDA, out_caller, "{\"script\":[");
    break;
  case JSON400_OUT_JSON_BUFF:
    custom_output_printf(JSON400_ADJUST_NDA, out_caller, "{\"script\":[");
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
void custom_output_script_end(int fmt, char *out_caller) {
  switch (fmt) {
  case JSON400_OUT_JSON_STDOUT:
    custom_output_printf(JSON400_ADJUST_RMV_COMMA, out_caller, "]}\n");
    break;
  case JSON400_OUT_JSON_BUFF:
    custom_output_printf(JSON400_ADJUST_RMV_COMMA, out_caller, "]}\n");
    break;
  case JSON400_OUT_SPACE_STDOUT:
    custom_output_printf(JSON400_ADJUST_NDA, out_caller, "\n");
    break;
  case JSON400_OUT_SPACE_BUFF:
    custom_output_printf(JSON400_ADJUST_NDA, out_caller, "\n");
    break;
  case JSON400_OUT_COMMA_STDOUT:
    custom_output_printf(JSON400_ADJUST_NDA, out_caller, "\n");
    break;
  case JSON400_OUT_COMMA_BUFF:
    custom_output_printf(JSON400_ADJUST_NDA, out_caller, "\n");
    break;
  default:
    break;
  }
}

void custom_output_record_array_beg(int fmt, char *out_caller) {
  switch (fmt) {
  case JSON400_OUT_JSON_STDOUT:
    custom_output_printf(JSON400_ADJUST_ADD_COMMA, out_caller, "\n{\"records\":[");
    break;
  case JSON400_OUT_JSON_BUFF:
    custom_output_printf(JSON400_ADJUST_ADD_COMMA, out_caller, "\n{\"records\":[");
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
void custom_output_record_array_end(int fmt, char *out_caller) {
  switch (fmt) {
  case JSON400_OUT_JSON_STDOUT:
    custom_output_printf(JSON400_ADJUST_RMV_COMMA, out_caller, "]}\n");
    break;
  case JSON400_OUT_JSON_BUFF:
    custom_output_printf(JSON400_ADJUST_RMV_COMMA, out_caller, "]}\n");
    break;
  case JSON400_OUT_SPACE_STDOUT:
    custom_output_printf(JSON400_ADJUST_NDA, out_caller, "\n");
    break;
  case JSON400_OUT_SPACE_BUFF:
    custom_output_printf(JSON400_ADJUST_NDA, out_caller, "\n");
    break;
  case JSON400_OUT_COMMA_STDOUT:
    custom_output_printf(JSON400_ADJUST_NDA, out_caller, "\n");
    break;
  case JSON400_OUT_COMMA_BUFF:
    custom_output_printf(JSON400_ADJUST_NDA, out_caller, "\n");
    break;
  default:
    break;
  }
}

void custom_output_record_no_data_found(int fmt, char *out_caller) {
  switch (fmt) {
  case JSON400_OUT_JSON_STDOUT:
    custom_output_printf(JSON400_ADJUST_NDA, out_caller, "\"SQL_NO_DATA_FOUND\"");
    break;
  case JSON400_OUT_JSON_BUFF:
    custom_output_printf(JSON400_ADJUST_NDA, out_caller, "\"SQL_NO_DATA_FOUND\"");
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


void custom_output_record_row_beg(int fmt, char *out_caller) {
  switch (fmt) {
  case JSON400_OUT_JSON_STDOUT:
    custom_output_printf(JSON400_ADJUST_ADD_COMMA, out_caller, "\n{");
    break;
  case JSON400_OUT_JSON_BUFF:
    custom_output_printf(JSON400_ADJUST_ADD_COMMA, out_caller, "\n{");
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
void custom_output_record_name_value(int fmt, char *name, char *value, int type, int fStrLen, char *out_caller) {
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
  switch (fmt) {
  case JSON400_OUT_JSON_STDOUT:
    custom_output_printf(JSON400_ADJUST_ADD_COMMA, out_caller, fmt_key_val, name, value);
    break;
  case JSON400_OUT_JSON_BUFF:
    custom_output_printf(JSON400_ADJUST_ADD_COMMA, out_caller, fmt_key_val, name, value);
    break;
  case JSON400_OUT_SPACE_STDOUT:
    custom_output_printf(JSON400_ADJUST_ADD_SPACE, out_caller, fmt_val, value);
    break;
  case JSON400_OUT_SPACE_BUFF:
    custom_output_printf(JSON400_ADJUST_ADD_SPACE, out_caller, fmt_val, value);
    break;
  case JSON400_OUT_COMMA_STDOUT:
    custom_output_printf(JSON400_ADJUST_ADD_COMMA, out_caller, fmt_val, value);
    break;
  case JSON400_OUT_COMMA_BUFF:
    custom_output_printf(JSON400_ADJUST_ADD_COMMA, out_caller, fmt_val, value);
    break;
  default:
    break;
  }
}
void custom_output_record_row_end(int fmt, char *out_caller) {
  switch (fmt) {
  case JSON400_OUT_JSON_STDOUT:
    custom_output_printf(JSON400_ADJUST_RMV_COMMA, out_caller, "}");
    break;
  case JSON400_OUT_JSON_BUFF:
    custom_output_printf(JSON400_ADJUST_RMV_COMMA, out_caller, "}");
    break;
  case JSON400_OUT_SPACE_STDOUT:
    custom_output_printf(JSON400_ADJUST_NDA, out_caller, "\n");
    break;
  case JSON400_OUT_SPACE_BUFF:
    custom_output_printf(JSON400_ADJUST_NDA, out_caller, "\n");
    break;
  case JSON400_OUT_COMMA_STDOUT:
    custom_output_printf(JSON400_ADJUST_NDA, out_caller, "\n");
    break;
  case JSON400_OUT_COMMA_BUFF:
    custom_output_printf(JSON400_ADJUST_NDA, out_caller, "\n");
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
        custom_output_printf(JSON400_ADJUST_ADD_COMMA, out_caller, "\n{\"ok\":false,\"reason\":\"error %s SQLCODE=%d\"}",msg, sqlcode);
        break;
      case JSON400_OUT_JSON_BUFF:
        custom_output_printf(JSON400_ADJUST_ADD_COMMA, out_caller, "\n{\"ok\":false,\"reason\":\"error %s SQLCODE=%d\"}",msg, sqlcode);
        break;
      case JSON400_OUT_SPACE_STDOUT:
        custom_output_printf(JSON400_ADJUST_ADD_SPACE, out_caller, "\"error=%s SQLCODE=%d\"\n",msg, sqlcode);
        break;
      case JSON400_OUT_SPACE_BUFF:
        custom_output_printf(JSON400_ADJUST_ADD_SPACE, out_caller, "\"error=%s SQLCODE=%d\"\n",msg, sqlcode);
        break;
      case JSON400_OUT_COMMA_STDOUT:
        custom_output_printf(JSON400_ADJUST_ADD_COMMA, out_caller, "\"error %s, SQLCODE=%d\"\n",msg, sqlcode);
        break;
      case JSON400_OUT_COMMA_BUFF:
        custom_output_printf(JSON400_ADJUST_ADD_COMMA, out_caller, "\"error=%s, SQLCODE=%d\"\n",msg, sqlcode);
        break;
      default:
        break;
      }
      return SQL_ERROR;
    }
  }
  return SQL_SUCCESS;
}

/* by ref area */
void ile_pgm_reset_spill_pos(ile_pgm_call_t * layout) {
  int delta = 0;
  delta = (char *)&layout->buf - (char *)layout;
  layout->pos = delta;
}
int ile_pgm_curr_spill_pos(ile_pgm_call_t * layout) {
  return layout->pos;
}
char * ile_pgm_curr_spill_ptr(ile_pgm_call_t * layout) {
  return (char *)layout + layout->pos;
}
void ile_pgm_next_spill_pos(ile_pgm_call_t * layout, int spill_len) {
  layout->pos += spill_len;
}

/* by value area (register area) */
void ile_pgm_reset_argv_pos(ile_pgm_call_t * layout) {
  int delta = 0;
  layout->argc = 0;
  layout->parmc = 0;
  layout->vpos = (char *)&layout->argv[0] - (char *)layout;
}
void ile_pgm_argv_full_reg_available(ile_pgm_call_t * layout) {
  int beg_reg  = (char *)&layout->argv[layout->argc] - (char *)layout;
  /* beyond register (use another register location) */
  if (layout->vpos > beg_reg) {
    layout->argc++;
  }
  /* register used for pass by ref, by value start next register location */
  layout->vpos = (char *)&layout->argv[layout->argc + 1] - (char *)layout; 
}
char * ile_pgm_curr_argv_ptr_align(ile_pgm_call_t * layout, int tlen) {
  int beg_reg  = (char *)&layout->argv[layout->argc] - (char *)layout;
  int end_reg  = beg_reg + sizeof(ILEpointer);
  /* natural alignment (by value) */
  if (tlen == 2) {
    layout->vpos = ile_pgm_round_up(layout->vpos, 2);
  } else if (tlen <= 4) {
    layout->vpos = ile_pgm_round_up(layout->vpos, 4);
  } else if (tlen <= 8) {
    layout->vpos = ile_pgm_round_up(layout->vpos, 8);
  }
  /* beyond register (use another register location) */
  if (layout->vpos + tlen > end_reg) {
    layout->argc++;
  } 
  return (char *)layout + layout->vpos;
}
int ile_pgm_curr_argv_pos(ile_pgm_call_t * layout) {
  return layout->vpos;
}
void ile_pgm_next_argv_pos(ile_pgm_call_t * layout, int tlen) {
  layout->vpos += tlen;
}

ile_pgm_call_t * ile_pgm_grow(ile_pgm_call_t **playout, int size) {
  int i = 0;
  int new_len = 0;
  int orig_len = 0;
  char * tmp = NULL;
  int delta = 0;
  ile_pgm_call_t * layout = *playout;
  /* enough room ? */
  if (layout) {
    /* max length - current position */
    delta = layout->max - layout->pos;
    if (delta > size) {
      return *playout;
    }
    new_len = layout->max;
    orig_len = new_len;
  }
  /* need more space (block size alloc) */
  for (i=0; new_len < size + sizeof(ile_pgm_call_t); i++) {
    new_len += ILE_PGM_ALLOC_BLOCK;
  }
  /* expanded layout template */
  tmp = custom_json_new(new_len);
  /* copy original data */
  if (orig_len) {
    memcpy(tmp, layout, orig_len);
  }
  /* layout to new pointer */
  layout = (ile_pgm_call_t *) tmp;
  /* max template */
  layout->max = new_len;
  /* current spill pos */
  if (!orig_len) {
    ile_pgm_reset_argv_pos(layout);
    ile_pgm_reset_spill_pos(layout);
  }
  /* old layout free */
  tmp = (char *)(*playout);
  if (tmp) {
    custom_json_free(tmp);
  }
  /* rest layout template pointer */
  *playout = layout;
  /* return new location (tmp ptrs) */
  return *playout;
}

int ile_pgm_isnum_decorated(char c) {
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
int ile_pgm_isnum_digit(char c) {
  if (c >= '0' && c <= '9') {
    return 1;
  }
  return 0;
}


int ile_pgm_round_up(int num, int factor) {
  return num + factor - 1 - (num - 1) % factor;
}

SQLRETURN ile_pgm_str2int8(char * where, const char *str, int tdim) {
  char * endptr = NULL;
  int i = 0;
  int8 * wherev = (int8 *) where;
  int8 value = 0;
  if (str) {
    value = (int8) strtol(str, &endptr, 10);
  }
  for (i=0; i < tdim; i++, wherev++) {
    *wherev = value;
  }
  return SQL_SUCCESS;
}
SQLRETURN ile_pgm_str2int16(char * where, const char *str, int tdim) {
  char * endptr = NULL;
  int i = 0;
  int16 * wherev = (int16 *) where;
  int16 value = 0;
  if (str) {
    value = (int16) strtol(str, &endptr, 10);
  }
  for (i=0; i < tdim; i++, wherev++) {
    *wherev = value;
  }
  return SQL_SUCCESS;
}
SQLRETURN ile_pgm_str2int32(char * where, const char *str, int tdim) {
  char * endptr = NULL;
  int i = 0;
  int32 * wherev = (int32 *) where;
  int32 value = 0;
  if (str) {
    value = (int32) strtol(str, &endptr, 10);
  }
  for (i=0; i < tdim; i++, wherev++) {
    *wherev = value;
  }
  return SQL_SUCCESS;
}
SQLRETURN ile_pgm_str2int64(char * where, const char *str, int tdim) {
  char * endptr = NULL;
  int i = 0;
  int64 * wherev = (int64 *) where;
  int64 value = 0;
  if (str) {
    value = (int64) strtoll(str, &endptr, 10);
  }
  for (i=0; i < tdim; i++, wherev++) {
    *wherev = value;
  }
  return SQL_SUCCESS;
}
SQLRETURN ile_pgm_str2uint8(char * where, const char *str, int tdim) {
  char * endptr = NULL;
  int i = 0;
  uint8 * wherev = (uint8 *) where;
  uint8 value = 0;
  if (str) {
    value = (uint8) strtoul(str, &endptr, 10);
  }
  for (i=0; i < tdim; i++, wherev++) {
    *wherev = value;
  }
  return SQL_SUCCESS;
}
SQLRETURN ile_pgm_str2uint16(char * where, const char *str, int tdim) {
  char * endptr = NULL;
  int i = 0;
  uint16 * wherev = (uint16 *) where;
  uint16 value = 0;
  if (str) {
    value = (uint16) strtoul(str, &endptr, 10);
  }
  for (i=0; i < tdim; i++, wherev++) {
    *wherev = value;
  }
  return SQL_SUCCESS;
}
SQLRETURN ile_pgm_str2uint32(char * where, const char *str, int tdim) {
  char * endptr = NULL;
  int i = 0;
  uint32 * wherev = (uint32 *) where;
  uint32 value = 0;
  if (str) {
    value = (uint32) strtoul(str, &endptr, 10);
  }
  for (i=0; i < tdim; i++, wherev++) {
    *wherev = value;
  }
  return SQL_SUCCESS;
}
SQLRETURN ile_pgm_str2uint64(char * where, const char *str, int tdim) {
  char * endptr = NULL;
  int i = 0;
  uint64 * wherev = (uint64 *) where;
  uint64 value = 0;
  if (str) {
    value = (uint64) strtoull(str, &endptr, 10);
  }
  for (i=0; i < tdim; i++, wherev++) {
    *wherev = value;
  }
  return SQL_SUCCESS;
}
SQLRETURN ile_pgm_str2float(char * where, const char *str, int tdim) {
  int i = 0;
  float * wherev = (float *) where;
  float value = 0.0;
  if (str) {
    value = (float) strtof(str,NULL);
  }
  for (i=0; i < tdim; i++, wherev++) {
    *wherev = value;
  }
  return SQL_SUCCESS;
}
SQLRETURN ile_pgm_str2double(char * where, const char *str, int tdim) {
  int i = 0;
  double * wherev = (double *) where;
  double value = 0.0;
  if (str) {
    value = (double) strtod(str,NULL);
  }
  for (i=0; i < tdim; i++, wherev++) {
    *wherev = value;
  }
  return SQL_SUCCESS;
}
SQLRETURN ile_pgm_str2hole(char * where, int tlen, int tdim) {
  int i = 0;
  char * wherev = where;
  /* copy in */
  for (i=0; i < tdim; i++, wherev += tlen) {
    memset(wherev,0,tlen);
  }
  return SQL_SUCCESS;
}
/*
 * general idea -- need test
 */
SQLRETURN ile_pgm_str2packed(char * where, char *str, int tdim, int tlen, int tscale) {
  int i = 0;
  int j = 0;
  int k = 0;
  int outDigits = tlen;
  int outDecimalPlaces = tscale;
  int outLength = outDigits/2+1;
  int inLength = 0;
  int sign = 0;
  char chr[256];
  char dec[256];
  char * c = NULL;
  int leadingZeros = 0;
  int firstNibble = 0;
  int secondNibble = 0;
  char * wherev = where;
  /* fix up input */
  if (!str) {
    str = "0";
  }
  memset(chr,0,sizeof(chr));
  memset(dec,0,sizeof(dec));
  c = str;
  inLength = strlen(c);
  for (i=0, j=0; i < inLength; i++) {
    if (c[i] == '-') {
      sign = i + 1;
    } else {
      if (ile_pgm_isnum_digit(c[i])) {
        chr[j++] = c[i];
      }
    }
  }
  /* convert string to packed */
  c = chr;
  inLength = strlen(c); 
  j = 0;
  if (outDigits % 2 == 0) {
   leadingZeros = outDigits - inLength + 1;
  } else {
   leadingZeros = outDigits - inLength;
  }
  /* write correct number of leading zero's */
  for (i=0; i<leadingZeros-1; i+=2) {
    dec[j++] = 0;
  }
  if (leadingZeros > 0) {
    if (leadingZeros % 2 != 0) {
      dec[j++] = (char)(c[k++] & 0x000F);
    }
  }
  /* place all the digits except last one */
  while (j < outLength-1) {
    firstNibble = (char)(c[k++] & 0x000F) << 4;
    secondNibble = (char)(c[k++] & 0x000F);
    dec[j++] = (char)(firstNibble + secondNibble);
  }
  /* place last digit and sign nibble */
  firstNibble = (char)(c[k++] & 0x000F) << 4;
  if (!sign) {
    dec[j++] = (char)(firstNibble + 0x000F);
  }
  else {
    dec[j++] = (char)(firstNibble + 0x000D);
  }
  /* copy in */
  for (i=0; i < tdim; i++, wherev += outLength) {
    memcpy(wherev, dec, outLength);
  }
  return SQL_SUCCESS;
}
/*
 * general idea -- need test
 */
SQLRETURN ile_pgm_str2zoned(char * where, char *str, int tdim, int tlen, int tscale) {
  int i = 0;
  int j = 0;
  int k = 0;
  int outDigits = tlen;
  int outDecimalPlaces = tscale;
  int outLength = outDigits;
  int inLength = 0;
  int sign = 0;
  char chr[256];
  char dec[256];
  char * c = NULL;
  char * wherev = where;
  /* fix up input */
  if (!str) {
    str = "0";
  }
  memset(chr,0,sizeof(chr));
  memset(dec,0,sizeof(dec));
  c = str;
  inLength = strlen(c);
  for (i=0, j=0; i < inLength; i++) {
    if (c[i] == '-') {
      sign = i + 1;
    } else {
      if (ile_pgm_isnum_digit(c[i])) {
        chr[j++] = c[i];
      }
    }
  }
  /* convert string to zoned */
  c = chr;
  inLength = strlen(c); 
  j = 0;
  /* write correct number of leading zero's */
  for (i=0; i < outDigits-inLength; i++)
  {
    dec[j++] = (char)0xF0;
  }
  /* place all the digits except the last one */
  while (j < outLength-1)
  {
    dec[j++] = (char)((c[k++] & 0x000F) | 0x00F0);
  }
  /* place the sign and last digit */
  if (!sign)
  {
    dec[j++] = (char)((c[k++] & 0x000F) | 0x00F0);
  }
  else
  {
    dec[j++] = (char)((c[k++] & 0x000F) | 0x00D0);
  }
  /* copy in */
  for (i=0; i < tdim; i++, wherev += outLength) {
    memcpy(wherev, dec, outLength);
  }
  return SQL_SUCCESS;
}
/*
 * general idea -- need test
 */
SQLRETURN ile_pgm_str2char(char * where, char *str, int tdim, int tlen, int tvary, int tccsid) {
  int rc = 0;
  int i = 0;
  int j = 0;
  char * wherev = where;
  int len = 0;
  char * value = NULL;
  short * short_value = NULL;
  int * int_value = NULL;
  char * ebcdic = NULL;
  char * c = NULL;
  if (!str) {
    str = "";
  }
  len = strlen(str);
  /* ebcdic ccsid? */
  if (!tccsid) {
    tccsid = Qp2jobCCSID();
  }
  /* convert ccsid */
  if (len) {
    ebcdic = custom_json_new(len*4);
    rc = SQL400FromUtf8(0, str, len, ebcdic, len*4, tccsid);
    c = ebcdic;
    j = 0;
    for (i = len*4 - 1; i; i--) {
      if (c[i]) {
        j = i + 1;
        break;
      } 
    }
    len = j;
  }
  /* truncate */
  if (len > tlen) {
    len = tlen;
  }
  /* copy in ebcdic space pad (0x40) */
  for (i=0; i < tdim; i++, wherev += tlen) {
    /* vary */
    if (tvary == 4) {
      int_value = (int *) wherev;
      *int_value = len;
      wherev += 4;
    } else if (tvary) {
      short_value = (short *) wherev;
      *short_value = len;
      wherev += 2;
    }
    /* ebcdic space pad (0x40) */
    if (len < tlen) {
      memset(wherev,0x40,tlen);
    }
    /* ebcdic chars */
    if (len && ebcdic) {
      memcpy(wherev,ebcdic,len);
    }
  }
  /* free temp storage */
  if (ebcdic) {
    custom_json_free(ebcdic);
  }
  return SQL_SUCCESS;
}
/*
 * general idea -- need test
 */
SQLRETURN ile_pgm_str2bin(char * where, char *str, int tdim, int tlen, int tvary) {
  int i = 0;
  int j = 0;
  int k = 0;
  int outDigits = tlen;
  int outLength = outDigits;
  int inLength = 0;
  int firstNibble = 0;
  int secondNibble = 0;
  char * dec = NULL;
  char * c = NULL;
  char * wherev = where;
  /* length of char hex binary input */
  if (str) {
    inLength = strlen(str);
  }
  /* copy in */
  for (i=0; i < tdim; i++, wherev += outLength) {
    memset(wherev, 0, outLength);
    dec = wherev;
    c = str;
    for (j=0, k=0; j < outDigits && k < inLength; ) {
      firstNibble = (char)(c[k++] & 0x000F) << 4;
      secondNibble = (char)(c[k++] & 0x000F);
      dec[j++] = (char)(firstNibble + secondNibble);
    }
  }
  return SQL_SUCCESS;
}


/* parse "12p2", "5a", "5av2", ... */
char ile_pgm_type(char *str, int * tlen, int * tscale, int * tvary) {
  int rc = 0;
  int i = 0;
  int j = 0;
  int k = 0;
  int l = 0;
  char t = ' ';
  char v1 = ' ';
  int v2 = 0;
  char * c = NULL;
  int cl = 0;
  char clen[32];
  char cscale[32];
  char cvary[32];

  /* no data */
  *tlen = 0;
  *tscale = 0;
  *tvary = 0;
  if (!str) {
    return t;
  }
  /* parse type */
  memset(clen,0,sizeof(clen));
  memset(cscale,0,sizeof(cscale));
  memset(cvary,0,sizeof(cvary));
  c = str;
  cl = strlen(c);
  for (i=0; cl && i < cl; i++) {
    if (ile_pgm_isnum_digit(c[i])) {
      /* len */
      if (t == ' ') {
        clen[j] = c[i];
        j++;
      /* scale */
      } else if (v1 == ' ') {
        cscale[k] = c[i];
        k++;
      /* varying 2 or 4 */
      } else {
        cvary[l] = c[i];
        l++;
      }
    } else {
      if (t == ' ') {
        t = c[i];
      } else if (v1 == ' ') {
        v1 = c[i];
      }
    }
  }
  /* len */
  if (j) {
    rc = ile_pgm_str2int32((char *)tlen, clen, 1);
  }
  /* scale */
  if (k) {
    rc = ile_pgm_str2int32((char *)tscale, cscale, 1);
  }
  /* varying 2 or 4 */
  if (v1 != ' ') {
    if (l) {
      rc = ile_pgm_str2int32((char *)tvary, cvary, 1);
    } else {
      *tvary = 2;
    }
  }
  /* return type */
  return t;
}

/* in|out|both|value|const|return */
int ile_pgm_by(char *str, char typ, int tlen, int tdim, int tvary, int isDs, int * spill_len) {
  int by = ILE_PGM_BY_REF_IN;
  /* default length input */
  switch (typ) {
  case 'i':
    switch (tlen) {
    case 3:
      *spill_len = sizeof(int8) * tdim;
      break;
    case 5:
      *spill_len = sizeof(int16) * tdim;
      break;
    case 10:
      *spill_len = sizeof(int32) * tdim;
      break;
    case 20:
      *spill_len = sizeof(int64) * tdim;
      break;
    default:
      *spill_len = sizeof(int32) * tdim;
      break;
    }
    break;
  case 'u':
    switch (tlen) {
    case 3:
      *spill_len = sizeof(uint8) * tdim;
      break;
    case 5:
      *spill_len = sizeof(uint16) * tdim;
      break;
    case 10:
      *spill_len = sizeof(uint32) * tdim;
      break;
    case 20:
      *spill_len = sizeof(uint64) * tdim;
      break;
    default:
      *spill_len = sizeof(uint32) * tdim;
      break;
    }
    break;
  case 'f':
    switch (tlen) {
    case 4:
      *spill_len = sizeof(float) * tdim;
      break;
    case 8:
      *spill_len = sizeof(double) * tdim;
      break;
    default:
      *spill_len = sizeof(double) * tdim;
      break;
    }
    break;
  case 'p':
    *spill_len = (tlen/2+1) * tdim;
    break;
  case 's':
    *spill_len = tlen * tdim;
    break;
  case 'a':
    switch(tvary){
    case 2:
      *spill_len = (tlen+sizeof(uint16)) * tdim;
      break;
    case 4:
      *spill_len = (tlen+sizeof(uint32)) * tdim;
      break;
    default:
      *spill_len = tlen * tdim;
      break;
    }
    break;
  case 'b':
    *spill_len = tlen * tdim;
    break;
  case 'h':
    *spill_len = tlen * tdim;
    break;
  default:
    *spill_len = tlen * tdim;
    break;
  }
  /* pass by ref/val or isDS (val) */
  if (isDs) {
    by = ILE_PGM_BY_IN_DS;
  } else if (!str) {
    by = ILE_PGM_BY_REF_BOTH;
  } else {
    if (str[0] == 'i') {
      by = ILE_PGM_BY_REF_IN;
    } else if (str[0] == 'o') {
      by = ILE_PGM_BY_REF_OUT;
    } else if (str[0] == 'b') {
      by = ILE_PGM_BY_REF_BOTH;
    } else if (str[0] == 'v' || str[0] == 'c') {
      /* not fit in register (not by value) */
      if (*spill_len > 8) {
        by = ILE_PGM_BY_REF_IN;
      /* ok, fit in register (by value/const) */
      } else {
        by = ILE_PGM_BY_VALUE;
      }
    } else if (str[0] == 'r') {
      by = ILE_PGM_BY_RETURN;
    }
  }
  /* return by */
  return by;
}

/* dcl-s parms */
char * ile_pgm_parm_location(int isOut, int by, int tlen, ile_pgm_call_t * layout) {

  char * where = NULL;

  /* current value assumed by ref buffer (or ds data)*/
  where = ile_pgm_curr_spill_ptr(layout);
  switch (by) {
  /* parm pass by ref (spill area) */
  case ILE_PGM_BY_REF_IN:
  case ILE_PGM_BY_REF_OUT:
  case ILE_PGM_BY_REF_BOTH:
    ile_pgm_argv_full_reg_available(layout);
    if (!isOut) {
      layout->argv_parm[layout->argc] = layout->parmc;
      layout->arg_by[layout->parmc] = by;
      layout->arg_pos[layout->parmc] = ile_pgm_curr_spill_pos(layout);
      layout->arg_len[layout->parmc] = tlen;
    }
    layout->argc++;
    layout->parmc++;
    /* next position */
    ile_pgm_next_spill_pos(layout, tlen);
    break;
  /* parm pass by value */
  case ILE_PGM_BY_VALUE:
    where = ile_pgm_curr_argv_ptr_align(layout, tlen);
    if (!isOut) {
      layout->argv_parm[layout->argc] = 0;
      layout->arg_by[layout->parmc] = by;
      layout->arg_pos[layout->parmc] = ile_pgm_curr_argv_pos(layout);
      layout->arg_len[layout->parmc] = tlen;
    }
    layout->parmc++;
    /* next position */
    ile_pgm_next_argv_pos(layout, tlen);
    break;
  /* return in buffer */
  case ILE_PGM_BY_RETURN:
    /* next position */
    ile_pgm_next_spill_pos(layout, tlen);
    break;
  /* ds data */
  case ILE_PGM_BY_IN_DS:
    /* next position */
    ile_pgm_next_spill_pos(layout, tlen);
    break;
  /* other??? */
  default:
    return NULL;
    break;
  }
  /* location of value */
  return where;
}


/* "dcl-s":["name","type", value, dimension, "in|out|both|value|const|return"], */
SQLRETURN custom_json_dcl_s(int isOut, int argc, char * argv[], int isDs, ile_pgm_call_t **playout) {

  ile_pgm_call_t * layout = *playout;

  char * in_name = NULL;
  char * in_type = NULL;
  char * in_value = NULL;
  char * in_dim = NULL;
  char * in_by = NULL;
  char * in_ccsid = NULL;

  char typ = ' ';
  int tlen = 0;
  int tscale = 0;
  int tvary = 0;
  int tdim = 0;
  int tccsid = 0;

  int spill_len = 0;
  int rc = 0;
  int by = 0;
  char * where = NULL;

  /* manditory - "name", "type" */
  if (argc < 2) {
    return SQL_ERROR;
  }
  /* manitory - name */
  in_name = argv[0];
  /* manitory - type */
  in_type = argv[1];
  /* optional - value */
  if (argc > 2) {
    in_value = argv[2];
  }
  /* optional - dimension */
  if (argc > 3) {
    in_dim = argv[3];
  }
  /* optional - by */
  if (argc > 4) {
    in_by = argv[4];
  }
  /* optional - ccsid */
  if (argc > 5) {
    in_ccsid = argv[5];
  }

  /* parse "12p2", "5a", "5av2", ... */
  typ = ile_pgm_type(in_type, &tlen, &tscale, &tvary);
  if (tlen < 1) {
    return SQL_ERROR;
  }

  /* parse dimension */
  rc = ile_pgm_str2int32((char *)&tdim, in_dim, 1);
  if (tdim < 1) {
    tdim = 1;
  }

  /* parse ccsid */
  rc = ile_pgm_str2int32((char *)&tccsid, in_ccsid, 1);
  if (tccsid < 1) {
    tccsid = 0;
  }

  /* parse in|out|both|value|const|return */
  by = ile_pgm_by(in_by, typ, tlen, tdim, tvary, isDs, &spill_len);
  if (!isOut && spill_len) {
    /* grow template (if need) */
    layout = ile_pgm_grow(playout, spill_len);
  }

  /* location of parm or ds data */
  where = ile_pgm_parm_location(isOut, by, spill_len, layout);
  if (!where) {
    return SQL_ERROR;
  }

  /* dcl-s type */
  switch (typ) {
  case 'i':
    switch (tlen) {
    case 3:
      if (!isOut) {
        rc = ile_pgm_str2int8(where, in_value, tdim);
      }
      break;
    case 5:
      if (!isOut) {
        rc = ile_pgm_str2int16(where, in_value, tdim);
      }
      break;
    case 10:
      if (!isOut) {
        rc = ile_pgm_str2int32(where, in_value, tdim);
      }
      break;
    case 20:
      if (!isOut) {
        rc = ile_pgm_str2int64(where, in_value, tdim);
      }
      break;
    default:
      return SQL_ERROR;
      break;
    }
    break;
  case 'u':
    switch (tlen) {
    case 3:
      if (!isOut) {
        rc = ile_pgm_str2uint8(where, in_value, tdim);
      }
      break;
    case 5:
      if (!isOut) {
        rc = ile_pgm_str2uint16(where, in_value, tdim);
      }
      break;
    case 10:
      if (!isOut) {
        rc = ile_pgm_str2uint32(where, in_value, tdim);
      }
      break;
    case 20:
      if (!isOut) {
        rc = ile_pgm_str2uint64(where, in_value, tdim);
      }
      break;
    default:
      return SQL_ERROR;
      break;
    }
    break;
  case 'f':
    switch (tlen) {
    case 4:
      if (!isOut) {
        rc = ile_pgm_str2float(where, in_value, tdim);
      }
      break;
    case 8:
      if (!isOut) {
        rc = ile_pgm_str2double(where, in_value, tdim);
      }
      break;
    default:
      return SQL_ERROR;
      break;
    }
    break;
  case 'p':
    if (!isOut) {
      rc = ile_pgm_str2packed(where, in_value, tdim, tlen, tscale);
    }
    break;
  case 's':
    if (!isOut) {
      rc = ile_pgm_str2zoned(where, in_value, tdim, tlen, tscale);
    }
    break;
  case 'a':
    if (!isOut) {
      rc = ile_pgm_str2char(where, in_value, tdim, tlen, tvary, tccsid);
    }
    break;
  case 'b':
    if (!isOut) {
      rc = ile_pgm_str2bin(where, in_value, tdim, tlen, tvary);
    }
    break;
  case 'h':
    if (!isOut) {
      rc = ile_pgm_str2hole(where, tdim, tlen);
    }
    break;
  default:
    return SQL_ERROR;
    break;
  }
  return SQL_SUCCESS;
}

/* "dcl-ds":["name",dimension, "in|out|both|value|return", "dou-name"], */
SQLRETURN custom_json_dcl_ds(int isOut, int argc, char * arv[], int isDs, ile_pgm_call_t **playout) {
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
  int isDs = 0;
  int isOut = 0;
  ile_pgm_call_t * layout = NULL;
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
  SQLSMALLINT buff_type[JSON400_MAX_COLS];
  SQLSMALLINT type = 0;
  SQLUINTEGER size = 0;
  SQLSMALLINT scale = 0;
  SQLSMALLINT nullable = 0;
  SQLINTEGER lob_loc = 0;
  SQLINTEGER loc_ind = 0;
  SQLSMALLINT loc_type = 0;
  SQLINTEGER fStrLen[JSON400_MAX_COLS];
  SQLSMALLINT sql_data_type = 0;
  SQLUINTEGER sql_precision = 0;
  SQLSMALLINT sql_scale = 0;
  SQLSMALLINT sql_nullable = SQL_NO_NULLS;
  SQLCHAR cmd_buff[JSON400_MAX_CMD_BUFF];
  SQLINTEGER cmd_len = 0;
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
        sqlrc = custom_output_sql_errors(fmt, hdbc, SQL_HANDLE_DBC, sqlrc, outjson);
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
        sqlrc = custom_output_sql_errors(fmt, hdbc, SQL_HANDLE_DBC, sqlrc, outjson);
      }
      break;
    case JSON400_KEY_QUERY:
      if (!hdbc) {
        sqlrc = SQL400Connect( NULL, NULL, NULL, &hdbc, SQL_TXN_NO_COMMIT, NULL, NULL );
        sqlrc = custom_output_sql_errors(fmt, hdbc, SQL_HANDLE_DBC, sqlrc, outjson);
      }
      /* statement */
      sqlrc = SQLAllocHandle(SQL_HANDLE_STMT, (SQLHDBC) hdbc, &hstmt);
      /* prepare */
      sqlrc = SQLPrepare((SQLHSTMT)hstmt, (SQLCHAR*)val[i], (SQLINTEGER)SQL_NTS);
      sqlrc = custom_output_sql_errors(fmt, hstmt, SQL_HANDLE_STMT, sqlrc, outjson);
      /* no parm? execute */
      if (key[i+1] != JSON400_KEY_PARM) {
        sqlrc = SQLExecute((SQLHSTMT)hstmt);
        sqlrc = custom_output_sql_errors(fmt, hstmt, SQL_HANDLE_STMT, sqlrc, outjson);
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
      sqlrc = custom_output_sql_errors(fmt, hstmt, SQL_HANDLE_STMT, sqlrc, outjson);
      /* no fetch? close */
      if (key[i+1] != JSON400_KEY_FETCH) {
        sqlrc = SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
      }
      break;
    case JSON400_KEY_FETCH:
      /* result set */
      sqlrc = SQLNumResultCols((SQLHSTMT)hstmt, &nResultCols);
      sqlrc = custom_output_sql_errors(fmt, hstmt, SQL_HANDLE_STMT, sqlrc, outjson);
      if (nResultCols > 0) {
        for (j = 0 ; j < nResultCols; j++) {
          size = JSON400_EXPAND_COL_NAME;
          buff_name[j] = custom_json_new(size);
          buff_value[j] = NULL;
          buff_type[j] = 0;
          fStrLen[j] = SQL_NTS;
          sqlrc = SQLDescribeCol((SQLHSTMT)hstmt, (SQLSMALLINT)(j + 1), (SQLCHAR *)buff_name[j], size, &name_length, &buff_type[j], &size, &scale, &nullable);
          /* dbcs expansion */
          switch (buff_type[j]) {
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
            buff_value[j] = custom_json_new(size);
            sqlrc = SQLBindCol((SQLHSTMT)hstmt, (j + 1), SQL_CHAR, buff_value[j], size, &fStrLen[j]);
            break;
          case SQL_BINARY:
          case SQL_VARBINARY:
          case SQL_BLOB:
            size = size * JSON400_EXPAND_BINARY;
            buff_value[j] = custom_json_new(size);
            sqlrc = SQLBindCol((SQLHSTMT)hstmt, (j + 1), SQL_CHAR, buff_value[j], size, &fStrLen[j]);
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
            buff_value[j] = custom_json_new(size);
            sqlrc = SQLBindCol((SQLHSTMT)hstmt, (j + 1), SQL_CHAR, buff_value[j], size, &fStrLen[j]);
            break;
          }
        }
        sqlrc = SQL_SUCCESS;
        custom_output_record_array_beg(fmt, outjson);
        while (sqlrc == SQL_SUCCESS) {
          sqlrc = SQLFetch(hstmt);
          if (sqlrc == SQL_NO_DATA_FOUND || sqlrc < SQL_SUCCESS ) {
            if (!recs) {
              custom_output_record_no_data_found(fmt, outjson);
            }
            break;
          }
          custom_output_record_row_beg(fmt, outjson);
          recs += 1;
          for (j = 0 ; j < nResultCols; j++) {
            if (buff_value[j]) {
              custom_output_record_name_value(fmt, buff_name[j], buff_value[j], buff_type[j], fStrLen[j], outjson);
            }
          }
          custom_output_record_row_end(fmt, outjson);
        }
        custom_output_record_array_end(fmt, outjson);
        for (j = 0 ; j < nResultCols; j++) {
          if (buff_value[j]) {
            custom_json_free(buff_name[j]);
            buff_name[j] = NULL;
          }
          if (buff_name[j]) {
            custom_json_free(buff_name[j]);
            buff_name[j] = NULL;
          }
        }
      } else {
        custom_output_record_array_beg(fmt, outjson);
        custom_output_record_no_data_found(fmt, outjson);
        custom_output_record_array_end(fmt, outjson);
      }
      /* close */
      sqlrc = SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
      break;
    case JSON400_KEY_CMD:
      if (!hdbc) {
        sqlrc = SQL400Connect( NULL, NULL, NULL, &hdbc, SQL_TXN_NO_COMMIT, NULL, NULL );
        sqlrc = custom_output_sql_errors(fmt, hdbc, SQL_HANDLE_DBC, sqlrc, outjson);
      }
      /* statement */
      sqlrc = SQLAllocHandle(SQL_HANDLE_STMT, (SQLHDBC) hdbc, &hstmt);
      /* sql */
      cmd_len = strlen(val[i]);
      memset(cmd_buff,0,JSON400_MAX_CMD_BUFF);
      sprintf(cmd_buff,"CALL QSYS2.QCMDEXC('%s',%d)",val[i],cmd_len);
      /* prepare */
      sqlrc = SQLPrepare((SQLHSTMT)hstmt, cmd_buff, (SQLINTEGER)SQL_NTS);
      sqlrc = custom_output_sql_errors(fmt, hstmt, SQL_HANDLE_STMT, sqlrc, outjson);
      /* execute */
      sqlrc = SQLExecute((SQLHSTMT)hstmt);
      sqlrc = custom_output_sql_errors(fmt, hstmt, SQL_HANDLE_STMT, sqlrc, outjson);
      /* close */
      sqlrc = SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
      break;
    /* don't bother trying ...
     * nothing tested yet with pgm
     * (just saving work until finished)
     */
    case JSON400_KEY_PGM:
      isOut = 0;
      if (!hdbc) {
        sqlrc = SQL400Connect( NULL, NULL, NULL, &hdbc, SQL_TXN_NO_COMMIT, NULL, NULL );
        sqlrc = custom_output_sql_errors(fmt, hdbc, SQL_HANDLE_DBC, sqlrc, outjson);
      }
      /* statement */
      sqlrc = SQLAllocHandle(SQL_HANDLE_STMT, (SQLHDBC) hdbc, &hstmt);
      /* clear parameter area */
      memset(&layout,0,sizeof(layout));
      break;
    /*
     * input copy in any dcl-s, dcl-ds
     */
    case JSON400_KEY_DCL_S:
      nbr_arv = custom_json_parse_array_values(val[i], arv);
      sqlrc = custom_json_dcl_s(isOut, nbr_arv, arv, isDs, &layout);
      break;
    case JSON400_KEY_DCL_DS:
      isDs = 1;
      break;
    case JSON400_KEY_END_DS:
      isDs = 0;
      break;
    /*
     * end-pgm we can run then copy out to json format
     */
    case JSON400_KEY_END_PGM:
      isOut = 1;
      ile_pgm_reset_spill_pos(layout);
      /* close */
      sqlrc = SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
      break;
    default:
      break;
    }
  } /* end for */
  /* hdbc external (caller?) or pool (pConnect) */
  if (!hdbc_external) {
    sqlrc = SQL400Close(hdbc);
  }
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
    stdbuf = custom_json_new(JSON400_OUT_MAX_STDOUT);
    outjson = stdbuf;
    outlen = JSON400_OUT_MAX_STDOUT;
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
          f = custom_json_parse_key_value(&c[j], k, JSON400_KEYS, JSON400_ORDS, find_look, i, key, val, arr);
        }
      }
    }
  }   
  /* run */
  custom_output_script_beg(fmt, outjson);
  sqlrc = custom_run(hdbc, outjson, outlen, fmt, key, val, arr);
  custom_output_script_end(fmt, outjson);
  /* free copyin */
  if (copyin) {
    custom_json_free(copyin);
  }
  /* free stdbuf */
  if (stdbuf) {
    printf("%s\n",stdbuf);
    custom_json_free(stdbuf);
  }
  return sqlrc;
}

char * custom_json_parse_key_value(char * c, int find, char **find_key, int *find_ord, int *find_look, int idx, int *k, char **v, int *a) {
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


int custom_json_parse_array_values(char *c, char **v) {
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
      if (ile_pgm_isnum_decorated(c[i])) {
        f = &c[i];
        for (i++; ;i++) {
          if (ile_pgm_isnum_decorated(c[i])) {
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


