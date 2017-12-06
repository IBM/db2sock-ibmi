#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iconv.h>
#include <stdarg.h>
#include "proc/iconf.h" /* see proc/Makefile */
#include "PaseToIle.h"
#include "PaseToDmp.h"
#include "PaseTool.h"
#ifdef __IBMC__
#else
#include "PaseCliPrintf.h"
#endif


/*=================================================
 * toolkit trace
 */
#ifdef __IBMC__
void tool_dump_key(char *mykey, int idx, int lvl, int key, char * val){}
void tool_dump_mykey(char * akey, char *func){}
void tool_dump_val(char * mykey, char * aval, int alen, char * val){}
void tool_dump_lvl_key_val(char * mykey, int idx, int lvl, int key, char * val){}
void tool_graph(int sqlrc, char *func, tool_struct_t * tool){}
void tool_dump(int flag, int sqlrc, char *func, int idx, int lvl, int key,  char * val){}
void tool_dump_attr(int sqlrc, char *func, int idx, int lvl, int key,  char * val){}
void tool_dump_beg(int sqlrc, char *func, int idx, int lvl, int key,  char * val){}
void tool_dump_end(int sqlrc, char *func, int idx, int lvl, int key,  char * val){}
void tool_dump_hex_chunks(char * mykey, char *start, int size){}
void tool_pgm_dump(int sqlrc, char *func, int step, tool_key_pgm_struct_t * tpgm){}
#else
void tool_dump_key(char *mykey, int idx, int lvl, int key, char * val) {
  char widekey[256];
  sprintf(widekey,"%s.node",mykey);
  switch (key) {

    case TOOL400_KEY_CONN:
      printf_format("%-50s %6d %6d %6d %25s (%s)\n",widekey, idx, lvl, key, "TOOL400_KEY_CONN", val);
      break;
    case TOOL400_CONN_DB:
      printf_format("%-50s %6d %6d %6d %25s (%s)\n",widekey, idx, lvl, key, "TOOL400_CONN_DB", val);
      break;
    case TOOL400_CONN_UID:
      printf_format("%-50s %6d %6d %6d %25s (%s)\n",widekey, idx, lvl, key, "TOOL400_CONN_UID", val);
      break;
    case TOOL400_CONN_PWD:
      printf_format("%-50s %6d %6d %6d %25s (%s)\n",widekey, idx, lvl, key, "TOOL400_CONN_PWD", val);
      break;
    case TOOL400_CONN_LIBL:
      printf_format("%-50s %6d %6d %6d %25s (%s)\n",widekey, idx, lvl, key, "TOOL400_CONN_LIBL", val);
      break;
    case TOOL400_CONN_CURLIB:
      printf_format("%-50s %6d %6d %6d %25s (%s)\n",widekey, idx, lvl, key, "TOOL400_CONN_CURLIB", val);
      break;
    case TOOL400_CONN_QUAL:
      printf_format("%-50s %6d %6d %6d %25s (%s)\n",widekey, idx, lvl, key, "TOOL400_CONN_QUAL", val);
      break;
    case TOOL400_CONN_ISOLATION:
      printf_format("%-50s %6d %6d %6d %25s (%s)\n",widekey, idx, lvl, key, "TOOL400_CONN_ISOLATION", val);
      break;
    case TOOL400_KEY_END_CONN:
      printf_format("%-50s %6d %6d %6d %25s (%s)\n",widekey, idx, lvl, key, "TOOL400_KEY_END_CONN", val);
      break;

    case TOOL400_KEY_QUERY:
      printf_format("%-50s %6d %6d %6d %25s (%s)\n",widekey, idx, lvl, key, "TOOL400_KEY_QUERY", val);
      break;
    case TOOL400_QUERY_STMT:
      printf_format("%-50s %6d %6d %6d %25s (%s)\n",widekey, idx, lvl, key, "TOOL400_QUERY_STMT", val);
      break;
    case TOOL400_KEY_END_QUERY:
      printf_format("%-50s %6d %6d %6d %25s (%s)\n",widekey, idx, lvl, key, "TOOL400_KEY_END_QUERY", val);
      break;

    case TOOL400_KEY_PARM:
      printf_format("%-50s %6d %6d %6d %25s (%s)\n",widekey, idx, lvl, key, "TOOL400_KEY_PARM", val);
      break;
    case TOOL400_PARM_VALUE:
      printf_format("%-50s %6d %6d %6d %25s (%s)\n",widekey, idx, lvl, key, "TOOL400_PARM_VALUE", val);
      break;
    case TOOL400_KEY_END_PARM:
      printf_format("%-50s %6d %6d %6d %25s (%s)\n",widekey, idx, lvl, key, "TOOL400_KEY_END_PARM", val);
      break;

    case TOOL400_KEY_FETCH:
      printf_format("%-50s %6d %6d %6d %25s (%s)\n",widekey, idx, lvl, key, "TOOL400_KEY_FETCH", val);
      break;
    case TOOL400_FETCH_REC:
      printf_format("%-50s %6d %6d %6d %25s (%s)\n",widekey, idx, lvl, key, "TOOL400_FETCH_REC", val);
      break;
    case TOOL400_KEY_END_FETCH:
      printf_format("%-50s %6d %6d %6d %25s (%s)\n",widekey, idx, lvl, key, "TOOL400_KEY_END_FETCH", val);
      break;

    case TOOL400_KEY_CMD:
      printf_format("%-50s %6d %6d %6d %25s (%s)\n",widekey, idx, lvl, key, "TOOL400_KEY_CMD", val);
      break;
    case TOOL400_CMD_EXEC:
      printf_format("%s.node %6d %6d %25s (%s)\n",mykey, lvl, key, "TOOL400_CMD_EXEC", val);
      break;
    case TOOL400_KEY_END_CMD:
      printf_format("%-50s %6d %6d %6d %25s (%s)\n",widekey, idx, lvl, key, "TOOL400_KEY_END_CMD", val);
      break;

    case TOOL400_KEY_PGM:
      printf_format("%-50s %6d %6d %6d %25s (%s)\n",widekey, idx, lvl, key, "TOOL400_KEY_PGM", val);
      break;
    case TOOL400_PGM_NAME:
      printf_format("%-50s %6d %6d %6d %25s (%s)\n",widekey, idx, lvl, key, "TOOL400_PGM_NAME", val);
      break;
    case TOOL400_PGM_LIB:
      printf_format("%-50s %6d %6d %6d %25s (%s)\n",widekey, idx, lvl, key, "TOOL400_PGM_LIB", val);
      break;
    case TOOL400_PGM_FUNC:
      printf_format("%-50s %6d %6d %6d %25s (%s)\n",widekey, idx, lvl, key, "TOOL400_PGM_FUNC", val);
      break;
    case TOOL400_KEY_END_PGM:
      printf_format("%-50s %6d %6d %6d %25s (%s)\n",widekey, idx, lvl, key, "TOOL400_KEY_END_PGM", val);
      break;

    case TOOL400_KEY_DCL_DS:
      printf_format("%-50s %6d %6d %6d %25s (%s)\n",widekey, idx, lvl, key, "TOOL400_KEY_DCL_DS", val);
      break;
    case TOOL400_DS_NAME:
      printf_format("%-50s %6d %6d %6d %25s (%s)\n",widekey, idx, lvl, key, "TOOL400_DS_NAME", val);
      break;
    case TOOL400_DS_DIM:
      printf_format("%-50s %6d %6d %6d %25s (%s)\n",widekey, idx, lvl, key, "TOOL400_DS_DIM", val);
      break;
    case TOOL400_DS_BY:
      printf_format("%-50s %6d %6d %6d %25s (%s)\n",widekey, idx, lvl, key, "TOOL400_DS_BY", val);
      break;
    case TOOL400_KEY_END_DS:
      printf_format("%-50s %6d %6d %6d %25s (%s)\n",widekey, idx, lvl, key, "TOOL400_KEY_END_DS", val);
      break;

    case TOOL400_KEY_DCL_S:
      printf_format("%-50s %6d %6d %6d %25s (%s)\n",widekey, idx, lvl, key, "TOOL400_KEY_DCL_S", val);
      break;
    case TOOL400_S_NAME:
      printf_format("%-50s %6d %6d %6d %25s (%s)\n",widekey, idx, lvl, key, "TOOL400_S_NAME", val);
      break;
    case TOOL400_S_DIM:
      printf_format("%-50s %6d %6d %6d %25s (%s)\n",widekey, idx, lvl, key, "TOOL400_S_DIM", val);
      break;
    case TOOL400_S_TYPE:
      printf_format("%-50s %6d %6d %6d %25s (%s)\n",widekey, idx, lvl, key, "TOOL400_S_TYPE", val);
      break;
    case TOOL400_S_BY:
      printf_format("%-50s %6d %6d %6d %25s (%s)\n",widekey, idx, lvl, key, "TOOL400_S_BY", val);
      break;
    case TOOL400_S_VALUE:
      printf_format("%-50s %6d %6d %6d %25s (%s)\n",widekey, idx, lvl, key, "TOOL400_S_VALUE", val);
      break;
    case TOOL400_KEY_END_S:
      printf_format("%-50s %6d %6d %6d %25s (%s)\n",widekey, idx, lvl, key, "TOOL400_KEY_END_S", val);
      break;

    case TOOL400_KEY_ARY_BEG:
      printf_format("%-50s %6d %6d %6d %25s (%s)\n",widekey, idx, lvl, key, "TOOL400_KEY_ARY_BEG", val);
      break;
    case TOOL400_KEY_ARY_SEP:
      printf_format("%-50s %6d %6d %6d %25s (%s)\n",widekey, idx, lvl, key, "TOOL400_KEY_ARY_SEP", val);
      break;
    case TOOL400_KEY_ARY_END:
      printf_format("%-50s %6d %6d %6d %25s (%s)\n",widekey, idx, lvl, key, "TOOL400_KEY_ARY_END", val);
      break;

    case TOOL400_KEY_ATTR_KIT_BEG:
      printf_format("%-50s %6d %6d %6d %25s (%s)\n",widekey, idx, lvl, key, "TOOL400_KEY_ATTR_KIT_BEG", val);
      break;

    case TOOL400_KEY_SPEC_BEG:
      printf_format("%-50s %6d %6d %6d %25s (%s)\n",widekey, idx, lvl, key, "TOOL400_KEY_SPEC_BEG", val);
      break;

    case TOOL400_KEY_HIGH:
      printf_format("%-50s %6d %6d %6d %25s (%s)\n",widekey, idx, lvl, key, "TOOL400_KEY_HIGH", val);
      break;

    default:
      printf_format("%-50s %6d %6d %6d %25s (%s)\n",widekey, idx, lvl, key, "TOOL400_KEY_?", val);
      break;
  }
}
void tool_dump_mykey(char * akey, char *func) {
  char funckey[256];
  sprintf(funckey,"tkbase_%s",func);
  printf_key(akey,funckey);
}
void tool_dump_val(char * mykey, char * aval, int alen, char * val) {
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
void tool_dump_lvl_key_val(char * mykey, int idx, int lvl, int key, char * val) {
  char myval[80];
  tool_dump_val(mykey, myval, sizeof(myval), val);
  tool_dump_key(mykey, idx, lvl, key, val);
}

void tool_graph(int sqlrc, char *func, tool_struct_t * tool) {
  char mykey[256];
  int i = 0;
  int j = 0;
  int key = 0;
  char * val = NULL;
  int lvl = 0;
  tool_node_t * node = NULL;
  if (dev_go(sqlrc,"sql400json")) {
    tool_dump_mykey(mykey,func);
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    /* printf_stack(mykey); */
    printf_sqlrc_status((char *)&mykey, sqlrc);
    dev_dump();
    for (i=0, node = tool->first; node; node = node->next, i++) {
      tool_dump_lvl_key_val(mykey, i, node->ord, node->key, node->val);
      dev_dump();
      for (j=0; j < TOOL400_ATTR_MAX && node->akey[j]; j++) {
        key = node->akey[j];
        val = node->aval[j];
        lvl = node->ord;
        tool_dump_lvl_key_val(mykey, i, lvl, key, val);
        dev_dump();
      }
    }
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    if (sqlrc < 0) {
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}

void tool_dump(int flag, int sqlrc, char *func, int idx, int lvl, int key,  char * val) {
  char mykey[256];
  if (dev_go(sqlrc,"sql400json")) {
    tool_dump_mykey(mykey,func);
    printf_clear();
    if (flag > 99) printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    /* printf_stack(mykey); */
    if (flag > 1 && sqlrc != 0) printf_sqlrc_status((char *)&mykey, sqlrc);
    tool_dump_lvl_key_val(mykey, idx, lvl, key, val);
    if (flag > 99) printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < 0) {
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void tool_dump_attr(int sqlrc, char *func, int idx, int lvl, int key,  char * val) {
  tool_dump(0, sqlrc, func, idx, lvl, key, val);
}
void tool_dump_beg(int sqlrc, char *func, int idx, int lvl, int key,  char * val) {
  tool_dump(1, sqlrc, func, idx, lvl, key, val);
}
void tool_dump_end(int sqlrc, char *func, int idx, int lvl, int key,  char * val) {
  tool_dump(2, sqlrc, func, idx, lvl, key, val);
}
void tool_dump_hex_chunks(char * mykey, char *start, int size) {
  int max = 0;
  char * here = NULL;
  int chunk = 80;
  int partial_chunk = 0;
  for (max = 0; max < size; max += chunk) {
    here = start + max;
    if (max + chunk < size) {
      partial_chunk = chunk;
    } else {
      partial_chunk = size - max;
    }
    printf_hexdump(mykey, here, partial_chunk);
  }
}
void tool_pgm_dump(int sqlrc, char *func, int step, tool_key_pgm_struct_t * tpgm) {
  char mykey[256];
  ile_pgm_call_t * layout = NULL;
  char * argv_area = NULL;
  int argv_len = 0;
  char * spill_area = NULL;
  int spill_len = 0;
  if (dev_go(sqlrc,"sql400json")) {
    tool_dump_mykey(mykey,func);
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    /* printf_stack(mykey); */
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %d\n",mykey,"step",step);
    if (tpgm) {
      layout = tpgm->layout;
      printf_format("%s.parm %s %s\n",mykey,"pgm_ile_name",tpgm->pgm_ile_name);
      printf_format("%s.parm %s %s\n",mykey,"pgm_ile_lib",tpgm->pgm_ile_lib);
      printf_format("%s.parm %s %s\n",mykey,"pgm_ile_func",tpgm->pgm_ile_func);
    }
    dev_dump();
    if (layout) {
      printf_format("%s.parm %s %d\n",mykey,"argc",layout->argc);
      printf_format("%s.parm %s %d\n",mykey,"parmc",layout->parmc);
      printf_format("%s.parm %s %d\n",mykey,"vpos",layout->vpos);
      printf_format("%s.parm %s %d\n",mykey,"pos",layout->pos);
      printf_format("%s.parm %s %d\n",mykey,"step",layout->step);
      printf_format("%s.parm %s %d\n",mykey,"max",layout->max);
      argv_area = ile_pgm_argv_top_buf(layout);
      argv_len = ile_pgm_argv_length(layout);
      printf_format("%s.parm %s 0x%p - 0x%p (0x%p)\n",mykey,"argv_area", argv_area, argv_area + argv_len, argv_len);
      tool_dump_hex_chunks(mykey, argv_area, argv_len);
      spill_area = ile_pgm_spill_top_buf(layout);
      spill_len = ile_pgm_spill_length(layout);
      printf_format("%s.parm %s 0x%p - 0x%p (0x%p)\n",mykey,"spill_area", spill_area, spill_area + spill_len, spill_len);
      dev_dump();
      tool_dump_hex_chunks(mykey, spill_area, spill_len);
    }
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < 0) {
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
#endif /* __IBMC__ */

