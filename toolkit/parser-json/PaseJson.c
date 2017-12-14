#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iconv.h>
#include <stdarg.h>
#include "../PaseTool.h"
#include "PaseJsDmp.h"
#include "PaseJson.h"

static char sbang;
static char spound;
static char sdollar;
static char sat;
static char sbackslash;
static char sopen_brace;
static char sclose_brace;
static char scaret;
static char sbacktick;
static char sopen_bracket;
static char sclose_bracket;
static char sbar;
static char stilde;

/* ==========================
 * json <map> toolkit keys
 * ==========================
 */

/* == toolkit db2 == */

/* {"connect":{"db":"DB","uid":"UID","pwd":"PWD","qual":"QUAL","iso":"nc|uc|cs|rr|rs","libl":"mylib yourlib","curlib":"mylib"}}
 * Note: connection is provided toolkit services (if missing). Aka, connect(null, null, null)
 */
char * json_conn_attr [] = {"db","uid","pwd","qual","iso","libl","curlib", NULL};
int json_conn_tool [] = {TOOL400_CONN_DB,TOOL400_CONN_UID,TOOL400_CONN_PWD,TOOL400_CONN_QUAL,TOOL400_CONN_ISOLATION,TOOL400_CONN_LIBL, TOOL400_CONN_CURLIB};
/* {"query":[{"stmt":"select * from QIWS/QCUSTCDT where LSTNAM=? or LSTNAM=?"},
        {"parm":[{"value":"Jones"},{"value":"Vine"}]},
        {"fetch":[{"rec":"all"}]}
       ]} 
*/
char * json_query_attr [] = {"stmt",NULL};
int json_query_tool [] = {TOOL400_QUERY_STMT};
char * json_parm_attr [] = {"value",NULL};
int json_parm_tool [] = {TOOL400_PARM_VALUE};
char * json_fetch_attr [] = {"rec",NULL};
int json_fetch_tool [] = {TOOL400_FETCH_REC};


/* == toolkit cmd == */

/* 
 * {"cmd":{"exec":"addlible mylib"}}
 * {"cmd":{"rexx":"RTVJOBA CCSID(?N) USRLIBL(?) SYSLIBL(?)"}}
 * {"cmd":{"qsh":"ls -1 /home/adc"}}
 */
char * json_cmd_attr [] = {"exec","rexx","qsh", NULL};
int json_cmd_tool [] = {TOOL400_CMD_EXEC, TOOL400_CMD_REXX, TOOL400_CMD_QSH};


/* == toolkit pgm, srvpgm == */

/* {"pgm":{"name":"MYPGM","lib":"MYLIB","func":"MyFunc","debugpgm":"stopped in qsysopr"}} */
char * json_pgm_attr [] = {"name","lib","func","debugpgm", NULL};
int json_pgm_tool [] = {TOOL400_PGM_NAME,TOOL400_PGM_LIB,TOOL400_PGM_FUNC,TOOL400_PGM_DEBUG};
/* {"ds":{"name":"MYDS","dim":1,"by":"in|out|both|value|const|return","dou":"name","dos":"-+","dob":"name"}} */
char * json_ds_attr [] = {"name","dim","by","dou","dos","dob", NULL};
int json_ds_tool [] = {TOOL400_DS_NAME,TOOL400_DS_DIM,TOOL400_DS_BY,TOOL400_DS_DOU,TOOL400_DS_DOS,TOOL400_DS_DOB};
/* {"s":{"name":"MYDATA","dim":1,"type":"5av2","by":"in|out|both|val|const|return","value":"MYVALUE","setlen":"name"}} */
char * json_s_attr [] = {"name","dim","type","value","by", "setlen", NULL};
int json_s_tool [] = {TOOL400_S_NAME,TOOL400_S_DIM,TOOL400_S_TYPE,TOOL400_S_VALUE,TOOL400_S_BY,TOOL400_S_SETLEN};

/* == internal map == */

/* primary elements */
char * json_elem_key [] = {"connect","query","parm","fetch","cmd","pgm","ds", "s", NULL};
int json_elem_tool_beg [] = {
TOOL400_KEY_CONN,
TOOL400_KEY_QUERY,
TOOL400_KEY_PARM,
TOOL400_KEY_FETCH,
TOOL400_KEY_CMD,
TOOL400_KEY_PGM,
TOOL400_KEY_DCL_DS,
TOOL400_KEY_DCL_S};
int json_elem_tool_end [] = {
TOOL400_KEY_END_CONN,
TOOL400_KEY_END_QUERY,
TOOL400_KEY_END_PARM,
TOOL400_KEY_END_FETCH,
TOOL400_KEY_END_CMD,
TOOL400_KEY_END_PGM,
TOOL400_KEY_END_DS,
TOOL400_KEY_END_S};
char ** json_elem_attr_key[] = {
json_conn_attr,
json_query_attr,
json_parm_attr,
json_fetch_attr,
json_cmd_attr,
json_pgm_attr,
json_ds_attr,
json_s_attr
};
int * json_elem_attr_tool [] = {
json_conn_tool,
json_query_tool,
json_parm_tool,
json_fetch_tool,
json_cmd_tool,
json_pgm_tool,
json_ds_tool,
json_s_tool
};


/* ==========================
 * malloc/free
 * ==========================
 */
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

/* ==========================
 * output
 * ==========================
 */
int json_output_printf(int adjust, char *out_caller, int outLen, const char * format, ...) {
  int retLen = outLen;
  char *p = (char *) NULL; 
  char *q = (char *) NULL; 
  int l = 0;
  int w = 0;
  int printLen = 0;
  va_list args;
  if(retLen == 0){
    retLen = strlen(out_caller);
  }
  l = retLen;
  p = out_caller + l;
  if (l) {
    w = l - 1;
    q = out_caller + w;
  } else {
    q = p;
  }
  switch (adjust) {
  case JSON400_ADJUST_ADD_COMMA:
    /* if (q[0] == '{' || q[0] == '[' || q[0] == ':') { */
    if (q[0] == sopen_bracket || q[0] == sopen_brace || q[0] == ':') {
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
  va_start(args, format);
  printLen = vsprintf(p, format, args);
  va_end(args);
  retLen = l + printLen;
  return retLen;
}

int json_output_script_beg(tool_node_t *tool, char *out_caller, int outLen) {
  int retLen = outLen;
  retLen = json_output_printf(JSON400_ADJUST_NDA, out_caller, retLen, 
    "%c\"script\":%c",sopen_bracket,sopen_brace);
  return retLen;
}
int json_output_script_end(tool_node_t *tool, char *out_caller, int outLen) {
  int retLen = outLen;
  retLen = json_output_printf(JSON400_ADJUST_RMV_COMMA, out_caller, retLen, 
    "%c%c",sclose_brace,sclose_bracket);
  return retLen;
}

int json_output_query_beg(tool_node_t *tool, char *out_caller, int outLen, char * query) {
  int retLen = outLen;
  retLen = json_output_printf(JSON400_ADJUST_ADD_COMMA, out_caller, retLen, 
      "%c\"query\":%c\"%s\"",sopen_bracket,sopen_brace, query);
  return retLen;
}
int json_output_query_end(tool_node_t *tool, char *out_caller, int outLen) {
  int retLen = outLen;
  retLen = json_output_printf(JSON400_ADJUST_RMV_COMMA, out_caller, retLen, 
    "%c%c",sclose_brace,sclose_bracket);
  return retLen;
}
int json_output_record_array_beg(tool_node_t *tool, char *out_caller, int outLen) {
  int retLen = outLen;
  retLen = json_output_printf(JSON400_ADJUST_ADD_COMMA, out_caller, retLen, 
    "%c\"records\":%c",sopen_bracket,sopen_brace);
  return retLen;
}
int json_output_record_array_end(tool_node_t *tool, char *out_caller, int outLen) {
  int retLen = outLen;
  retLen = json_output_printf(JSON400_ADJUST_RMV_COMMA, out_caller, retLen, 
    "%c%c",sclose_brace,sclose_bracket);
  return retLen;
}

int json_output_record_no_data_found(tool_node_t *tool, char *out_caller, int outLen) {
  int retLen = outLen;
  retLen = json_output_printf(JSON400_ADJUST_NDA, out_caller, retLen, 
    "\"SQL_NO_DATA_FOUND\"");
  return retLen;
}


int json_output_record_row_beg(tool_node_t *tool, char *out_caller, int outLen) {
  int retLen = outLen;
  retLen = json_output_printf(JSON400_ADJUST_ADD_COMMA, out_caller, retLen, 
    "%c",sopen_bracket);
  return retLen;
}
int json_output_record_name_value(tool_node_t *tool, char *out_caller, int outLen, char *name, char *value, int type, int fStrLen) {
  int retLen = outLen;
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
  if (fStrLen == TOOL400_DATA_IS_NULL) {
    value = fmt_json_null;
    fmt_val = fmt_val_dec;
    fmt_key_val = fmt_key_val_dec;
  } else {
    switch (type) {
    case TOOL400_DATA_TYPE_NBR:
      if (value[0] == '.') {
        fmt_val = fmt_val_zero_dec;
        fmt_key_val = fmt_key_val_zero_dec;
      } else {
        fmt_val = fmt_val_dec;
        fmt_key_val = fmt_key_val_dec;
      }
      break;
    case TOOL400_DATA_TYPE_CHAR:
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
  retLen = json_output_printf(JSON400_ADJUST_ADD_COMMA, out_caller, retLen, fmt_key_val, name, value);
  return retLen;
}
int json_output_record_row_end(tool_node_t *tool, char *out_caller, int outLen) {
  int retLen = outLen;
  retLen = json_output_printf(JSON400_ADJUST_RMV_COMMA, out_caller, retLen, 
    "%c",sclose_bracket);
  return retLen;
}

int json_output_sql_errors(tool_node_t *tool, char *out_caller, int outLen, int rc, int sqlCode, char * sqlState, char *sqlMsg)
{
  int retLen = outLen;
  if (rc == SQL_ERROR) {
    retLen = json_output_printf(JSON400_ADJUST_ADD_COMMA, out_caller, retLen, 
        "\n%c\"ok\":false,\"sqlcode\":\"%d\",\"sqlstate\":\"%s\",\"sqlmsg\":\"%s\"%c", sopen_bracket, sqlCode, sqlState, sqlMsg, sclose_bracket);
  }
  return retLen;
}

/* pgm call */
int json_output_pgm_beg(tool_node_t *tool, char *out_caller, int outLen, char * name, char * lib, char * func) {
  int retLen = outLen;
  if (!lib) {
    lib = "*LIBL";
  }
  if (!func) {
    retLen = json_output_printf(JSON400_ADJUST_ADD_COMMA, out_caller, retLen, 
      "%c\"pgm\":%c\"%s\",\"%s\"",sopen_bracket,sopen_brace, name, lib);
  } else {
    retLen = json_output_printf(JSON400_ADJUST_ADD_COMMA, out_caller, retLen, 
      "%c\"pgm\":%c\"%s\",\"%s\",\"%s\"",sopen_bracket,sopen_brace, name, lib, func);
  }
  return retLen;
}
int json_output_pgm_end(tool_node_t *tool, char *out_caller, int outLen) {
  int retLen = outLen;
  retLen = json_output_printf(JSON400_ADJUST_RMV_COMMA, out_caller, retLen, 
    "%c%c",sclose_brace,sclose_bracket);
  return retLen;
}

int json_output_pgm_dcl_ds_beg(tool_node_t *tool, char *out_caller, int outLen, char * name, int tdim) {
  int retLen = outLen;
  if (tdim > 1) {
    retLen = json_output_printf(JSON400_ADJUST_ADD_COMMA, out_caller, retLen, 
      "%c\"%s\":%c",sopen_bracket,name,sopen_brace);
  } else {
    retLen = json_output_printf(JSON400_ADJUST_ADD_COMMA, out_caller, retLen, 
      "%c\"%s\":",sopen_bracket, name);
  }
  return retLen;
}
int json_output_pgm_dcl_ds_rec_beg(tool_node_t *tool, char *out_caller, int outLen) {
  int retLen = outLen;
  retLen = json_output_printf(JSON400_ADJUST_ADD_COMMA, out_caller, retLen, 
      "%c",sopen_brace);
  return retLen;
}
int json_output_pgm_dcl_ds_rec_end(tool_node_t *tool, char *out_caller, int outLen) {
  int retLen = outLen;
  retLen = json_output_printf(JSON400_ADJUST_RMV_COMMA, out_caller, retLen,
      "%c",sclose_brace);
  return retLen;
}
int json_output_pgm_dcl_ds_end(tool_node_t *tool, char *out_caller, int outLen, int tdim) {
  int retLen = outLen;
  if (tdim > 1) {
    retLen = json_output_printf(JSON400_ADJUST_RMV_COMMA, out_caller, retLen,
      "%c%c",sclose_brace,sclose_bracket);
  } else {
    retLen = json_output_printf(JSON400_ADJUST_RMV_COMMA, out_caller, retLen, 
      "%c",sclose_bracket);
  }
  return retLen;
}

int json_output_pgm_dcl_s_beg(tool_node_t *tool, char *out_caller, int outLen, char * name, int tdim) {
  int retLen = outLen;
  if (tdim > 1) {
    retLen = json_output_printf(JSON400_ADJUST_ADD_COMMA, out_caller, retLen, 
      "%c\"%s\":%c",sopen_bracket,name,sopen_brace);
  } else {
    retLen = json_output_printf(JSON400_ADJUST_ADD_COMMA, out_caller, retLen, 
      "%c\"%s\":",sopen_bracket, name);
  }
  return retLen;
}
int json_output_pgm_dcl_s_data(tool_node_t *tool, char *out_caller, int outLen, char *value, int numFlag) {
  int retLen = outLen;
  if (numFlag == 1) {
    retLen = json_output_printf(JSON400_ADJUST_ADD_COMMA, out_caller, retLen, 
      "%s", value);
  } else {
    retLen = json_output_printf(JSON400_ADJUST_ADD_COMMA, out_caller, retLen, 
      "\"%s\"", value);
  }
  return retLen;
}
int json_output_pgm_dcl_s_end(tool_node_t *tool, char *out_caller, int outLen, int tdim) {
  int retLen = outLen;
  if (tdim > 1) {
    retLen = json_output_printf(JSON400_ADJUST_RMV_COMMA, out_caller, retLen,
      "%c%c",sclose_brace,sclose_bracket);
  } else {
    retLen = json_output_printf(JSON400_ADJUST_RMV_COMMA, out_caller, retLen, 
      "%c",sclose_bracket);
  }
  return retLen;
}

/* cmd call */
int json_output_cmd_beg(tool_node_t *tool, char *out_caller, int outLen, char * cmd) {
  int retLen = outLen;
  retLen = json_output_printf(JSON400_ADJUST_ADD_COMMA, out_caller, retLen, 
      "%c\"cmd\":%c\"%s\"",sopen_bracket,sopen_brace, cmd);
  return retLen;
}
int json_output_cmd_end(tool_node_t *tool, char *out_caller, int outLen) {
  int retLen = outLen;
  retLen = json_output_printf(JSON400_ADJUST_RMV_COMMA, out_caller, retLen, 
    "%c%c",sclose_brace,sclose_bracket);
  return retLen;
}

/* joblog */
int json_output_joblog_beg(tool_node_t *tool, char *out_caller, int outLen) {
  int retLen = outLen;
  retLen = json_output_printf(JSON400_ADJUST_ADD_COMMA, out_caller, retLen, 
      "%c\"joblog\":%c",sopen_bracket,sopen_brace);
  return retLen;
}
int json_output_joblog_rec(tool_node_t *tool, char *out_caller, int outLen, char * msgid, char * msgtype, char * msgsub, char * msgsev, char * msgstamp, char * msgtolib, char * msgtopgm, char * msgtomod, char * msgtoproc, char * msgtoinst, char * msgtxt) 
{
  int retLen = outLen;
  retLen = json_output_printf(JSON400_ADJUST_ADD_COMMA, out_caller, retLen, 
      "%c",sopen_bracket);
  retLen = json_output_printf(JSON400_ADJUST_ADD_COMMA, out_caller, retLen, 
      "\"msgid\":\"%s\"",msgid);
  retLen = json_output_printf(JSON400_ADJUST_ADD_COMMA, out_caller, retLen, 
      "\"msgtype\":\"%s\"",msgtype);
  if (strlen(msgsub)) {
    retLen = json_output_printf(JSON400_ADJUST_ADD_COMMA, out_caller, retLen, 
      "\"msgsub\":\"na\"");
  } else {
    retLen = json_output_printf(JSON400_ADJUST_ADD_COMMA, out_caller, retLen, 
      "\"msgsub\":\"%s\"",msgsub);
  }
  retLen = json_output_printf(JSON400_ADJUST_ADD_COMMA, out_caller, retLen, 
      "\"msgsev\":\"%s\"",msgsev);
  retLen = json_output_printf(JSON400_ADJUST_ADD_COMMA, out_caller, retLen, 
      "\"msgstamp\":\"%s\"",msgstamp);
  retLen = json_output_printf(JSON400_ADJUST_ADD_COMMA, out_caller, retLen, 
      "\"msgtolib\":\"%s\"",msgtolib);
  retLen = json_output_printf(JSON400_ADJUST_ADD_COMMA, out_caller, retLen, 
      "\"msgtopgm\":\"%s\"",msgtopgm);
  retLen = json_output_printf(JSON400_ADJUST_ADD_COMMA, out_caller, retLen, 
      "\"msgtomod\":\"%s\"",msgtomod);
  retLen = json_output_printf(JSON400_ADJUST_ADD_COMMA, out_caller, retLen, 
      "\"msgtoproc\":\"%s\"",msgtoproc);
  retLen = json_output_printf(JSON400_ADJUST_ADD_COMMA, out_caller, retLen, 
      "\"msgtoinst\":\"%s\"",msgtoinst);
  retLen = json_output_printf(JSON400_ADJUST_ADD_COMMA, out_caller, retLen, 
      "\"msgtxt\":\"%s\"",msgtxt);
  retLen = json_output_printf(JSON400_ADJUST_RMV_COMMA, out_caller, retLen, 
      "%c",sclose_bracket);
  return retLen;
}
int json_output_joblog_end(tool_node_t *tool, char *out_caller, int outLen) {
  int retLen = outLen;
  retLen = json_output_printf(JSON400_ADJUST_RMV_COMMA, out_caller, retLen, 
    "%c%c",sclose_brace,sclose_bracket);
  return retLen;
}

/* ==========================
 * input
 * ==========================
 */
json_key_t * json_ctor_key() {
  json_key_t * k = json_new(sizeof(json_key_t));
  k->count = 0;
  k->max = 0;
  k->key = NULL;
  k->val = NULL;
  k->lvl = NULL;
  return k;
}
void json_grow_key(json_key_t * k, int i) {
  int g = 0;
  char * old_key = (char *) k->key;
  char * old_val = (char *) k->val;
  char * old_lvl = (char *) k->lvl;
  char * new_key = NULL;
  char * new_val = NULL;
  char * new_lvl = NULL;
  /* already big enough (add grow amount i to count) */
  if (k->max > k->count + i + 1) {
    k->count += i; /* hamela found bug */
    return;
  }
  /* grow by blocks */
  for (g = k->max; k->max < g + i + 1; k->max += JSON400_KEY_BLOCK);
  /* realloc */
  new_key = json_new(k->max * sizeof(int));
  new_val = json_new(k->max * sizeof(char *));
  new_lvl = json_new(k->max * sizeof(int));
  memcpy(new_key,old_key,(k->count * sizeof(int)));
  memcpy(new_val,old_val,(k->count * sizeof(char *)));
  memcpy(new_lvl,old_lvl,(k->count * sizeof(int)));
  k->key = (int *) new_key;
  k->val = (char **) new_val;
  k->lvl = (int *) new_lvl;
  json_free(old_key);
  json_free(old_val);
  json_free(old_lvl);
}
void json_dtor_key(json_key_t * k) {
  char * old_key = (char *) k->key;
  char * old_val = (char *) k->val;
  char * old_lvl = (char *) k->lvl;
  if (old_key) json_free(old_key);
  if (old_val) json_free(old_val);
  if (old_lvl) json_free(old_lvl);
  json_free((char *)k);
}

/* parse transform */
void json_xform(int max, json_key_t * bigkey) {
  int i = 0;
  int j = 0;
  int k = 0;
  int l = 0;
  int level = 0;
  int minlevel = 0;
  int maxlevel = 0;
  int arylevel = 0;
  int arycnt = 0;
  char * ckey = NULL;
  char ** elem_key = json_elem_key;
  int * elem_val = json_elem_tool_beg;
  int * elem_end = json_elem_tool_end;
  char * akey = NULL;
  char ** attr_key = NULL;
  int * attr_val = NULL;
  int * key = bigkey->key;
  char ** val = bigkey->val;
  int * lvl = bigkey->lvl;
  /* loop through raw parse keys */
  for (i=0; i<max; i++) {
    /* see val (debug) */
    ckey = val[i];
    /* "key":... */
    if (key[i] == JSON400_KEY) {
      /* check primary key like "connect", "pgm", ... */
      for (j=0; ckey && *ckey && elem_key[j]; j++) {
        if (!strcmp(elem_key[j],ckey)) {
          key[i] = elem_val[j];
          attr_key = json_elem_attr_key[j];
          attr_val = json_elem_attr_tool[j];
          /* handle attr(s) */
          for (k = i+1, minlevel = lvl[i], level = lvl[i], maxlevel = 0, arylevel = 0, arycnt = 0; k<max; k++) {
            /* see val (debug) */
            akey = val[k];
            level = lvl[k];
            if (!maxlevel) {
              switch(key[k]) {
              case JSON400_COLON:
                continue;
                break;
              case JSON400_ARY_BEG:
                arylevel = level;
                key[k] = TOOL400_KEY_ARY_BEG;
                arycnt = 0;
                continue;
                break;
              case JSON400_OBJ_BEG:
                continue;
                break;
              default:
                maxlevel = level;
                break;
              }
            } /* maxlevel */
            /* ignore children beyond max level */
            if (level > maxlevel) {
              continue;
            }
            /* end of element in array (normalize toolkit nodes) */
            if (level == arylevel && key[k] == JSON400_COMMA) {
              key[k] = TOOL400_KEY_ARY_SEP;
              arycnt++;
            }
            /* end of array */
            if (level == arylevel && key[k] == JSON400_ARY_END) {
              key[k] = TOOL400_KEY_ARY_END;
            }
            /* at end end-pgm, end-cmd, etc.*/
            if (level == minlevel) {
              key[k] = elem_end[j];
              break; /* break attr loop (k) */
            }
            /* normal attr ok? */
            for (l=0; akey && *akey && attr_key[l]; l++) {
              if (!strcmp(attr_key[l],akey)) {
                key[k] = attr_val[l];
                break;
              }
            }
          } /* attr loop (k) */
          break; /* break loop (j) */
        } /* found valid primary key "connect", "pgm", ... */
      } /* loop primary key (j) */
    } /* found "key": ... */
  } /* loop i (raw parse) */
}

/* parse compress */
void json_tkit(tool_struct_t *tool, int max, json_key_t * bigkey) {
  int i = 0;
  int j = 0;
  int k = 0;
  int * key = bigkey->key;
  char ** val = bigkey->val;
  int * lvl = bigkey->lvl;
  int key1 = 0;
  char * val1 = NULL;
  int lvl1 = 0;
  tool_node_t * node = NULL;
  int range = 0;
  /* condense array */
  for (i=0, k=0; i<max; i++) {
    if (key[i] < TOOL400_KEY_HIGH) {
      key1 = key[k++] = key[i];
      if (i+2 < max && key[i+1] == JSON400_COLON && key[i+2] > JSON400_AT_VAL && key[i+2] < JSON400_AT_END) {
        val1 = val[k-1] = val[i+2];
      } else {
        val1 = val[k-1] = val[i];
      }
      lvl1 = lvl[k-1] = lvl[i];
      json_dump_null("json_tkit(1)", (char *) node);
      json_dump_one("json_tkit(1)", lvl1, key1, val1);
      range = tool_key_range(key1);
      switch (range) {
      case TOOL400_RANGE_ELEM_KIT_BEG:
      case TOOL400_RANGE_ELEM_DB2_BEG:
        json_dump_one("json_tkit(2)", lvl1, key1, val1);
        node = tool_node_beg(tool, key1, lvl1);
        break;
      case TOOL400_RANGE_ELEM_KIT_END:
      case TOOL400_RANGE_ELEM_DB2_END:
        node = tool_node_end(tool, node, key1, lvl1);
        break;
      case TOOL400_RANGE_ATTR_KIT:
      case TOOL400_RANGE_ATTR_DB2:
        node = tool_node_attr(tool, node, key1, val1, lvl1);
        break;
      case TOOL400_RANGE_KEY_SPEC:
        switch(key1) {
        case TOOL400_KEY_ARY_SEP:
          json_dump_one("json_tkit(3)", lvl1, key1, val1);
          node = tool_node_sep(tool, node, key1, lvl1);
          break;
        default:
          break;
        }
        break;
      case TOOL400_RANGE_HIGH:
      default:
        break;
      }
    }
  }
  for (i=k; i<max; i++) {
    key[i] = 0;
    val[i] = NULL;
    lvl[i] = 0;
  }
}


/* parse json */
int json_parse(char * json, json_key_t * bigkey) {
  int i = 0;
  int j = 0;
  int k = 0;
  int isColon = 0;
  int nest = 0;
  char * c = NULL;
  int * key = NULL;
  char ** val = NULL;
  int * lvl = NULL;

  /* parse json */
  for (c=json; *c; c++) {
    json_grow_key(bigkey, 1);
    key = bigkey->key;
    val = bigkey->val;
    lvl = bigkey->lvl;
    /* ILE variant chars (argh) */
    if (*c == sopen_bracket) { /* '{' */
      isColon = 0;
      key[k++] = JSON400_OBJ_BEG;
      lvl[k-1] = ++nest;
      *c = '\0';
    } else if (*c == sclose_bracket) { /* '}' */
      isColon = 0;
      key[k++] = JSON400_OBJ_END;
      lvl[k-1] = nest--;
      *c = '\0';
    } else if (*c == sopen_brace) { /* '[' */
      isColon = 0;
      key[k++] = JSON400_ARY_BEG;
      lvl[k-1] = ++nest;
      *c = '\0';
    } else if (*c == sclose_brace) { /* ']' */
      isColon = 0;
      key[k++] = JSON400_ARY_END;
      lvl[k-1] = nest--;
      *c = '\0';
    } else {
    switch(*c) {
    case ',':
      isColon = 0;
      key[k++] = JSON400_COMMA;
      lvl[k-1] = nest;
      *c = '\0';
      break;
    case ':':
      isColon = 1;
      key[k++] = JSON400_COLON;
      lvl[k-1] = nest;
      *c = '\0';
      break;
    case '"':
      if (isColon) {
        key[k++] = JSON400_VAL_STR;
      } else {
        key[k++] = JSON400_KEY;
      }
      lvl[k-1] = nest;
      c++;
      val[k-1] = c;
      for (; *c; c++) {
        if (*c == '"') {
          *c = '\0';
          break;
        }
      }
      break;
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    case '.':
      key[k++] = JSON400_VAL_NBR;
      lvl[k-1] = nest;
      val[k-1] = c;
      for (; *c; c++) {
        if (*c == '0' || *c == '1' || *c == '2' || *c == '3' || *c == '4' || *c == '5' 
         || *c == '6' || *c == '7' || *c == '8' || *c == '9' || *c == '0' || *c == '.') {
          continue;
        } else {
          c--;
          break;
        }
      }
      break;
    case 'f':
      key[k++] = JSON400_VAL_BOL;
      lvl[k-1] = nest;
      val[k-1] = c;
      for (; *c; c++) {
        if (*c == 'f' || *c == 'a' || *c == 'l' || *c == 's' || *c == 'e') {
          continue;
        } else {
          c--;
          break;
        }
      }
      break;
    case 't':
      key[k++] = JSON400_VAL_BOL;
      lvl[k-1] = nest;
      val[k-1] = c;
      for (; *c; c++) {
        if (*c == 't' || *c == 'r' || *c == 'u' || *c == 'e') {
          continue;
        } else {
          c--;
          break;
        }
      }
      break;
    case 'n':
      key[k++] = JSON400_VAL_NUL;
      lvl[k-1] = nest;
      val[k-1] = c;
      for (; *c; c++) {
        if (*c == 'n' || *c == 'u' || *c == 'l') {
          continue;
        } else {
          c--;
          break;
        }
      }
      break;
    default:
      break;
    }
    } /* ILE variant chars (argh) */
  } /* loop c */
  /* max nodes */
  return k;
}

/* ==========================
 * SQL400Json interface (dynamic loaded)
 * ==========================
 */
SQLRETURN custom_SQL400Json(SQLHDBC hdbc,
 SQLCHAR * injson,
 SQLINTEGER inlen, 
 SQLCHAR * outjson,
 SQLINTEGER outlen) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  int max = 0;
  char * stdbuf = NULL;
  char * copyin = NULL;
  tool_struct_t *tool = NULL;
  json_key_t * bigkey = NULL;

  /* Variant EBCDIC characters !#$@\[]^`{}|~ */
  sbang = ccsid_variant_bang();
  spound = ccsid_variant_pound();
  sdollar = ccsid_variant_dollar();
  sat = ccsid_variant_at();
  sbackslash = ccsid_variant_backslash();
  sopen_brace = ccsid_variant_open_brace();
  sclose_brace = ccsid_variant_close_brace();
  scaret = ccsid_variant_caret();
  sbacktick = ccsid_variant_backtick();
  sopen_bracket = ccsid_variant_open_bracket();
  sclose_bracket = ccsid_variant_close_bracket();
  sbar = ccsid_variant_bar();
  stilde = ccsid_variant_tilde();

  /* debug me */
  /* sleep(30); */

  /* nothing input */
  if (!inlen) {
    return SQL_ERROR;
  }

  /* output format */
  if (!outjson || !outlen) {
    stdbuf = json_new(JSON400_OUT_MAX_STDOUT);
    outjson = stdbuf;
    outlen = JSON400_OUT_MAX_STDOUT;
  }

  /* copy in (enable parse null terminated strings) */
  copyin = json_new(inlen + 1);
  strcpy(copyin, injson);

  /* ctor toolkit callbacks */
  tool = tool_ctor(
    &json_output_script_beg,
    &json_output_script_end,
    &json_output_query_beg,
    &json_output_query_end,
    &json_output_record_array_beg,
    &json_output_record_array_end,
    &json_output_record_no_data_found,
    &json_output_record_row_beg,
    &json_output_record_name_value,
    &json_output_record_row_end,
    &json_output_sql_errors,
    &json_output_pgm_beg,
    &json_output_pgm_end,
    &json_output_pgm_dcl_ds_beg,
    &json_output_pgm_dcl_ds_end,
    &json_output_pgm_dcl_ds_rec_beg,
    &json_output_pgm_dcl_ds_rec_end,
    &json_output_pgm_dcl_s_beg,
    &json_output_pgm_dcl_s_data,
    &json_output_pgm_dcl_s_end,
    &json_output_cmd_beg,
    &json_output_cmd_end,
    &json_output_joblog_beg,
    &json_output_joblog_rec,
    &json_output_joblog_end
  );

  /* pass 1 - parse raw json */
  bigkey = json_ctor_key();
  max = json_parse(copyin, bigkey);
  json_graph("json_parse", bigkey->key, bigkey->val, bigkey->lvl);
  /* pass 2 - xform toolkit ordinals */
  json_xform(max, bigkey);
  json_graph("json_xform", bigkey->key, bigkey->val, bigkey->lvl);
  /* pass 3 - build toolkit nodes */
  json_tkit(tool, max, bigkey);
  json_graph("json_tkit", bigkey->key, bigkey->val, bigkey->lvl);

  /* run */
  sqlrc = tool_run(hdbc, outjson, outlen, tool);
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

  /* free key val */
  if (bigkey) {
    json_dtor_key(bigkey);
  }

  return sqlrc;
}


