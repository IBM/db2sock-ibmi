#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iconv.h>
#include <stdarg.h>
#include "../PaseTool.h"
#include "PaseJson.h"
#ifdef __IBMC__
#else
#include "../db2/PaseCliPrintf.h"
#endif


/* ==========================
 * trace
 * ==========================
 */
#ifdef __IBMC__
void json_dump_key(char *mykey, int lvl, int key, char * val){}
void json_dump_mykey(char * akey, char *func){}
void json_dump_val(char * mykey, char * aval, int alen, char * val){}
void json_dump_lvl_key_val(char * mykey, int lvl, int key, char * val){}
void json_graph(char *func, int *ikey, char **ival, int *ilvl){}
void json_dump_one(char *func, int lvl, int key, char * val){}
void json_dump_null(char *func, char * val){}
#else
void json_dump_key(char *mykey, int lvl, int key, char * val) {
  switch (key) {

    case JSON400_END:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "JSON400_END", val);
      break;
    case JSON400_KEY:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "JSON400_KEY", val);
      break;
    case JSON400_AT_BEG:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "JSON400_AT_BEG", val);
      break;
    case JSON400_OBJ_BEG:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "JSON400_OBJ_BEG", val);
      break;
    case JSON400_ARY_BEG:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "JSON400_ARY_BEG", val);
      break;
    case JSON400_COMMA:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "JSON400_COMMA", val);
      break;
    case JSON400_COLON:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "JSON400_COLON", val);
      break;
    case JSON400_AT_VAL:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "JSON400_AT_VAL", val);
      break;
    case JSON400_VAL_STR:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "JSON400_VAL_STR", val);
      break;
    case JSON400_VAL_NBR:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "JSON400_VAL_NBR", val);
      break;
    case JSON400_VAL_BOL:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "JSON400_VAL_BOL", val);
      break;
    case JSON400_VAL_NUL:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "JSON400_VAL_NUL", val);
      break;
    case JSON400_AT_END:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "JSON400_AT_END", val);
      break;
    case JSON400_OBJ_END:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "JSON400_OBJ_END", val);
      break;
    case JSON400_ARY_END:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "JSON400_ARY_END", val);
      break;

    case TOOL400_KEY_CONN:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "TOOL400_KEY_CONN", val);
      break;
    case TOOL400_CONN_DB:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "TOOL400_CONN_DB", val);
      break;
    case TOOL400_CONN_UID:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "TOOL400_CONN_UID", val);
      break;
    case TOOL400_CONN_PWD:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "TOOL400_CONN_PWD", val);
      break;
    case TOOL400_CONN_LIBL:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "TOOL400_CONN_LIBL", val);
      break;
    case TOOL400_CONN_CURLIB:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "TOOL400_CONN_CURLIB", val);
      break;
    case TOOL400_CONN_QUAL:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "TOOL400_CONN_QUAL", val);
      break;
    case TOOL400_CONN_ISOLATION:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "TOOL400_CONN_ISOLATION", val);
      break;
    case TOOL400_KEY_END_CONN:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "TOOL400_KEY_END_CONN", val);
      break;

    case TOOL400_KEY_QUERY:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "TOOL400_KEY_QUERY", val);
      break;
    case TOOL400_QUERY_STMT:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "TOOL400_QUERY_STMT", val);
      break;
    case TOOL400_QUERY_HNDL:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "TOOL400_QUERY_HNDL", val);
      break;
    case TOOL400_KEY_END_QUERY:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "TOOL400_KEY_END_QUERY", val);
      break;

    case TOOL400_KEY_CLOSE:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "TOOL400_KEY_CLOSE", val);
      break;
    case TOOL400_CLOSE_HNDL:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "TOOL400_CLOSE_HNDL", val);
      break;
    case TOOL400_KEY_END_CLOSE:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "TOOL400_KEY_END_CLOSE", val);
      break;


    case TOOL400_KEY_PARM:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "TOOL400_KEY_PARM", val);
      break;
    case TOOL400_PARM_VALUE:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "TOOL400_PARM_VALUE", val);
      break;
    case TOOL400_KEY_END_PARM:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "TOOL400_KEY_END_PARM", val);
      break;


    case TOOL400_KEY_FETCH:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "TOOL400_KEY_FETCH", val);
      break;
    case TOOL400_FETCH_REC:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "TOOL400_FETCH_REC", val);
      break;
    case TOOL400_KEY_END_FETCH:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "TOOL400_KEY_END_FETCH", val);
      break;


    case TOOL400_KEY_CMD:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "TOOL400_KEY_CMD", val);
      break;
    case TOOL400_CMD_EXEC:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "TOOL400_CMD_EXEC", val);
      break;
    case TOOL400_KEY_END_CMD:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "TOOL400_KEY_END_CMD", val);
      break;

    case TOOL400_KEY_PGM:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "TOOL400_KEY_PGM", val);
      break;
    case TOOL400_PGM_NAME:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "TOOL400_PGM_NAME", val);
      break;
    case TOOL400_PGM_LIB:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "TOOL400_PGM_LIB", val);
      break;
    case TOOL400_PGM_FUNC:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "TOOL400_PGM_FUNC", val);
      break;
    case TOOL400_KEY_END_PGM:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "TOOL400_KEY_END_PGM", val);
      break;

    case TOOL400_KEY_DCL_DS:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "TOOL400_KEY_DCL_DS", val);
      break;
    case TOOL400_DS_NAME:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "TOOL400_DS_NAME", val);
      break;
    case TOOL400_DS_DIM:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "TOOL400_DS_DIM", val);
      break;
    case TOOL400_DS_BY:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "TOOL400_DS_BY", val);
      break;
    case TOOL400_DS_DOU:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "TOOL400_DS_DOU", val);
      break;
    case TOOL400_DS_DOB:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "TOOL400_DS_DOB", val);
      break;
    case TOOL400_DS_DOS:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "TOOL400_DS_DOS", val);
      break;
    case TOOL400_KEY_END_DS:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "TOOL400_KEY_END_DS", val);
      break;

    case TOOL400_KEY_DCL_S:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "TOOL400_KEY_DCL_S", val);
      break;
    case TOOL400_S_NAME:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "TOOL400_S_NAME", val);
      break;
    case TOOL400_S_DIM:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "TOOL400_S_DIM", val);
      break;
    case TOOL400_S_TYPE:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "TOOL400_S_TYPE", val);
      break;
    case TOOL400_S_BY:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "TOOL400_S_BY", val);
      break;
    case TOOL400_S_NOCONV:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "TOOL400_S_NOCONV", val);
      break;
    case TOOL400_S_DOU:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "TOOL400_S_DOU", val);
      break;
    case TOOL400_S_DOB:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "TOOL400_S_DOB", val);
      break;
    case TOOL400_S_VALUE:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "TOOL400_S_VALUE", val);
      break;
    case TOOL400_KEY_END_S:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "TOOL400_KEY_END_S", val);
      break;

    case TOOL400_KEY_ARY_BEG:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "TOOL400_KEY_ARY_BEG", val);
      break;
    case TOOL400_KEY_ARY_SEP:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "TOOL400_KEY_ARY_SEP", val);
      break;
    case TOOL400_KEY_ARY_END:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "TOOL400_KEY_ARY_END", val);
      break;

    case TOOL400_KEY_ATTR_KIT_BEG:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "TOOL400_KEY_ATTR_KIT_BEG", val);
      break;

    case TOOL400_KEY_SPEC_BEG:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "TOOL400_KEY_SPEC_BEG", val);
      break;

    case TOOL400_KEY_HIGH:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "TOOL400_KEY_HIGH", val);
      break;

    default:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "TOOL400_KEY_?", val);
      break;
  }
}
void json_dump_mykey(char * akey, char *func) {
  char funckey[256];
  sprintf(funckey,"tkbase_%s",func);
  printf_key(akey,funckey);
}
void json_dump_val(char * mykey, char * aval, int alen, char * val) {
  int vlen = 0;
  memset(aval,0,alen);
  if (val) {
    vlen = strlen(val);
    if (vlen) {
      if (vlen < alen - 1) {
        strcpy(aval,val);
      } else {
        strncpy(aval,val,alen - 1);
      }
    }
  }
}
void json_dump_lvl_key_val(char * mykey, int lvl, int key, char * val) {
  char myval[80];
  json_dump_val(mykey, myval, sizeof(myval), val);
  json_dump_key(mykey, lvl, key, val);
}

void json_graph(char *func, int *ikey, char **ival, int *ilvl) {
  char mykey[256];
  int i = 0;
  int key = 0;
  char * val = NULL;
  int lvl = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (dev_go(sqlrc,"sql400json")) {
    json_dump_mykey(mykey,func);
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    /* printf_stack(mykey); */
    printf_sqlrc_status((char *)&mykey, sqlrc);
    dev_dump();
    for (i = 0; sqlrc == SQL_SUCCESS; i++) {
      key = ikey[i];
      val = ival[i];
      lvl = ilvl[i];
      /* no key */
      if (!key) {
        break;
      }
      json_dump_lvl_key_val(mykey, lvl, key, val);
      dev_dump();
    }
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    if (sqlrc < SQL_SUCCESS) {
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}

void json_dump_one(char *func, int lvl, int key, char * val) {
  char mykey[256];
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (dev_go(sqlrc,"sql400json")) {
    json_dump_mykey(mykey,func);
    json_dump_lvl_key_val(mykey, lvl, key, val);
    dev_dump();
  }
}

void json_dump_null(char *func, char * val) {
  char mykey[256];
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (dev_go(sqlrc,"sql400json")) {
    json_dump_mykey(mykey,func);
    if (val) {
      printf_format("%s.node (%p)\n",mykey, val);
    } else {
      printf_format("%s.node (NULL)\n",mykey);
    }
    dev_dump();
  }
}
#endif


