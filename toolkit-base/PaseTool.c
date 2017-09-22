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
#include "PaseCliDev.h"
#include "PaseCliPrintf.h"
#include "../ILE-PROC/iconf.h" /* see ILE-PROC/Makefile */
#include "PaseTool.h"

typedef struct tool_key_conn_struct {
  tool_struct_t node;
  int presistent;
  int conn_type;
  SQLHANDLE hdbc;
  SQLCHAR * conn_db;
  SQLCHAR * conn_uid;
  SQLCHAR * conn_pwd;
  SQLCHAR * conn_qual;
  SQLINTEGER conn_commit;
  SQLCHAR * conn_libl;
  SQLCHAR * conn_curlib;
} tool_key_conn_struct_t;

typedef struct tool_key_query_struct {
  tool_struct_t node;
  SQLHANDLE hstmt;
} tool_key_query_struct_t;

typedef struct tool_key_cmd_struct {
  tool_struct_t node;
  SQLHANDLE hstmt;
  SQLINTEGER cmd_len;
  SQLCHAR cmd_buff[TOOL400_MAX_CMD_BUFF];
} tool_key_cmd_struct_t;

typedef struct tool_key_pgm_struct {
  tool_struct_t node;
  SQLHANDLE hstmt;
  ile_pgm_call_t * layout;
  char * pgm_proc_lib;
  char * pgm_ile_name;
  char * pgm_ile_lib;
  char * pgm_ile_func;
  SQLINTEGER pgm_len;
  SQLCHAR pgm_buff[TOOL400_MAX_CMD_BUFF];
} tool_key_pgm_struct_t;

typedef struct tool_key_struct {
  int hdbc;
  tool_key_conn_struct_t * tconn;
  char * outarea;
  int outlen;
  tool_struct_t *tool;
} tool_key_t;

/*=================================================
 * toolkit prototypes
 */
SQLRETURN tool_key_pgm_data_run(tool_key_t * tk, tool_key_pgm_struct_t * tpgm, int * isDs, int isOut, tool_node_t ** curr_node);
SQLRETURN tool_key_pgm_ds_run(tool_key_t * tk, tool_key_pgm_struct_t * tpgm, int * isDs, int isOut, tool_node_t ** curr_node);

char * ile_pgm_spill_top_buf(ile_pgm_call_t * layout);
int ile_pgm_spill_top_offset(ile_pgm_call_t * layout);
int ile_pgm_spill_length(ile_pgm_call_t * layout);
char * ile_pgm_argv_top_buf(ile_pgm_call_t * layout);
int ile_pgm_argv_top_offset(ile_pgm_call_t * layout);
int ile_pgm_argv_length(ile_pgm_call_t * layout);

/*=================================================
 * toolkit malloc
 */


void * tool_new(int size) {
  void * buffer = malloc(size + 1);
  memset(buffer,0,size + 1);
  return buffer;
}
void tool_free(char *buffer) {
  if (buffer) {
    free(buffer);
  }
}


/*=================================================
 * toolkit node class
 */
tool_node_t * tool_node_ctor(int key, int ord, char * val, int size)
{
  tool_node_t *node = tool_new(size);
  node->ctor = node;
  node->ord = ord;
  node->key = key;
  node->val = val;
  return node; 
}

void tool_node_attr_add(tool_node_t *node, int key, char * val)
{
  int i = 0;
  for (i=0; i<TOOL400_ATTR_MAX; i++) {
    if (!node->akey[i]) {
      node->akey[i] = key;
      node->aval[i] = val;
      break;
    }
  }
}


/*=================================================
 * toolkit class
 */
tool_struct_t * tool_ctor(
  output_script_beg_t output_script_beg,
  output_script_end_t output_script_end,
  output_query_beg_t output_query_beg,
  output_query_end_t output_query_end,
  output_record_array_beg_t output_record_array_beg,
  output_record_array_end_t output_record_array_end,
  output_record_no_data_found_t output_record_no_data_found,
  output_record_row_beg_t output_record_row_beg,
  output_record_name_value_t output_record_name_value,
  output_record_row_end_t output_record_row_end,
  output_sql_errors_t output_sql_errors,
  output_pgm_beg_t output_pgm_beg,
  output_pgm_end_t output_pgm_end,
  output_pgm_dcl_ds_beg_t output_pgm_dcl_ds_beg,
  output_pgm_dcl_ds_end_t output_pgm_dcl_ds_end,
  output_pgm_dcl_s_beg_t output_pgm_dcl_s_beg,
  output_pgm_dcl_s_data_t output_pgm_dcl_s_data,
  output_pgm_dcl_s_end_t output_pgm_dcl_s_end,
  output_cmd_beg_t output_cmd_beg,
  output_cmd_end_t output_cmd_end,
  output_joblog_beg_t output_joblog_beg,
  output_joblog_rec_t output_joblog_rec,
  output_joblog_end_t output_joblog_end
) 
{
  tool_struct_t *tool = tool_new(sizeof(tool_struct_t));
  tool->output_script_beg = output_script_beg;
  tool->output_script_end = output_script_end;
  tool->output_query_beg = output_query_beg;
  tool->output_query_end = output_query_end;
  tool->output_record_array_beg = output_record_array_beg;
  tool->output_record_array_end = output_record_array_end;
  tool->output_record_no_data_found = output_record_no_data_found;
  tool->output_record_row_beg = output_record_row_beg;
  tool->output_record_name_value = output_record_name_value;
  tool->output_record_row_end = output_record_row_end;
  tool->output_sql_errors = output_sql_errors;
  tool->output_pgm_beg = output_pgm_beg;
  tool->output_pgm_end = output_pgm_end;
  tool->output_pgm_dcl_ds_beg = output_pgm_dcl_ds_beg;
  tool->output_pgm_dcl_ds_end = output_pgm_dcl_ds_end;
  tool->output_pgm_dcl_s_beg = output_pgm_dcl_s_beg;
  tool->output_pgm_dcl_s_data = output_pgm_dcl_s_data;
  tool->output_pgm_dcl_s_end = output_pgm_dcl_s_end;
  tool->output_cmd_beg = output_cmd_beg;
  tool->output_cmd_end = output_cmd_end;
  tool->output_joblog_beg = output_joblog_beg;
  tool->output_joblog_rec = output_joblog_rec;
  tool->output_joblog_end = output_joblog_end;
  tool->first = NULL;
  tool->curr = NULL;
  return tool;
}

void tool_dtor(tool_struct_t *tool){
  tool_free((char *)tool);
}

tool_node_t * tool_node_first(tool_struct_t * tool) {
  return tool->first;
}
tool_node_t * tool_node_curr(tool_struct_t * tool) {
  return tool->curr;
}

tool_node_t * tool_node_find_ord_not_fin(tool_struct_t * tool, tool_node_t * curr_node, int ord) {
  tool_node_t * node = NULL;
  for (node = curr_node; node; node = node->prev) {
    if (node->ord == ord && !node->fin) {
      break;
    }
  }
  return node;
}
tool_node_t * tool_node_find_key_ord_not_fin(tool_struct_t * tool, tool_node_t * curr_node, int key, int ord) {
  tool_node_t * node = NULL;
  for (node = curr_node; node; node = node->prev) {
    if (node->key == key && node->ord == ord && !node->fin) {
      break;
    }
  }
  return node;
}

tool_node_t * tool_node_elem_push(tool_struct_t * tool, int key, char * val, int size, int ord) {
  tool_node_t * prev_node = NULL;
  tool_node_t * conn_node = NULL;
  tool_node_t * node = tool_node_ctor(key, ord, val, size);
  if (!tool->first) {
    /* must have a connection node */
    if (node->key == TOOL400_KEY_CONN) {
      tool->first = node;
      tool->curr = node;
      tool->last = node;
      return node;
    } else {
      conn_node = tool_node_ctor(TOOL400_KEY_CONN, ord, NULL, sizeof(tool_key_conn_struct_t));
      tool->first = conn_node;
      tool->curr = conn_node;
      tool->last = node;
    }
  }
  prev_node = tool->curr;
  tool->curr = node;
  tool->last = node;
  prev_node->next = node;
  node->prev = prev_node;
  return node;
}

int tool_key_range(int key) {
  int match = 0;
  /*  toolkit node begin */
  if ( (key >= TOOL400_KEY_ELEM_RSV_BEG && key <= TOOL400_KEY_ELEM_RSV_BEG2) ) {
    match = TOOL400_RANGE_ELEM_RSV_BEG;
  /*  toolkit node end */
  } else if ( (key >= TOOL400_KEY_ELEM_RSV_END && key <= TOOL400_KEY_ELEM_RSV_END2) ) {
    match = TOOL400_RANGE_ELEM_RSV_END;
  /*  user node begin */
  } else if ( (key >= TOOL400_KEY_ELEM_USR_BEG && key <= TOOL400_KEY_ELEM_USR_BEG2) ) {
    match = TOOL400_RANGE_ELEM_USR_BEG;
  /*  user node end */
  } else if ( (key >= TOOL400_KEY_ELEM_USR_END && key <= TOOL400_KEY_ELEM_USR_END2) ) {
    match = TOOL400_RANGE_ELEM_USR_END;
  /* toolkit attribute */
  } else  if ( (key >= TOOL400_KEY_ATTR_RSV_BEG && key <= TOOL400_KEY_ATTR_RSV_END) ) {
    match = TOOL400_RANGE_ATTR_RSV;
  /* user attribute */
  } else  if ( (key >= TOOL400_KEY_ATTR_USR_BEG && key <= TOOL400_KEY_ATTR_USR_END) ) {
    match = TOOL400_RANGE_ATTR_USR;
  /* special attr */
  } else  if ( (key >= TOOL400_KEY_SPEC_BEG && key <= TOOL400_KEY_SEPC_END) ) {
    match = TOOL400_RANGE_KEY_SPEC;
  /* parser only (not toolkit) */
  } else  if ( key >= TOOL400_KEY_HIGH ) {
    match = TOOL400_RANGE_HIGH;
  }
  return match;
}


tool_node_t * tool_node_add(tool_struct_t * tool, int key, char *val, int ord) {
  tool_node_t * node = NULL;
  int size = sizeof(tool_node_t);
  int range = 0;

  switch (key) {
  case TOOL400_KEY_CONN:
    size = sizeof(tool_key_conn_struct_t);
    break;
  case TOOL400_KEY_END_CONN:
    break;

  case TOOL400_KEY_QUERY:
    size = sizeof(tool_key_query_struct_t);
    break;
  case TOOL400_KEY_END_QUERY:
    break;

  case TOOL400_KEY_PARM:
    break;
  case TOOL400_KEY_END_PARM:
    break;

  case TOOL400_KEY_FETCH:
    break;
  case TOOL400_KEY_END_FETCH:
    break;

  case TOOL400_KEY_CMD:
    size = sizeof(tool_key_cmd_struct_t);
    break;
  case TOOL400_KEY_END_CMD:
    break;

  case TOOL400_KEY_PGM:
    size = sizeof(tool_key_pgm_struct_t);
    break;
  case TOOL400_KEY_END_PGM:
    break;

  case TOOL400_KEY_DCL_DS:
    break;
  case TOOL400_KEY_END_DS:
    break;

  case TOOL400_KEY_DCL_S:
    break;
  case TOOL400_KEY_END_S:
    break;

  default:
    break;
  }

  range = tool_key_range(key);
  switch (range) {
  case TOOL400_RANGE_ELEM_RSV_BEG:
  case TOOL400_RANGE_ELEM_USR_BEG:
  case TOOL400_RANGE_ELEM_RSV_END:
  case TOOL400_RANGE_ELEM_USR_END:
    node = tool_node_elem_push(tool, key, val, size, ord);
    break;
  case TOOL400_RANGE_ATTR_RSV:
  case TOOL400_RANGE_ATTR_USR:
  case TOOL400_RANGE_KEY_SPEC:
  case TOOL400_RANGE_HIGH:
  default:
    break;
  }

  return node;
}

int tool_key_match_beg_2_end(int key) {
  int match = 0;
  int range = 0;
  range = tool_key_range(key);
  switch (range) {
  case TOOL400_RANGE_ELEM_RSV_BEG:
    match = key + (TOOL400_KEY_ELEM_RSV_END - TOOL400_KEY_ELEM_RSV_BEG);
    break;
  case TOOL400_RANGE_ELEM_USR_BEG:
    match = key + (TOOL400_KEY_ELEM_USR_END - TOOL400_KEY_ELEM_USR_BEG);
    break;
  case TOOL400_RANGE_ELEM_RSV_END:
  case TOOL400_RANGE_ELEM_USR_END:
  case TOOL400_RANGE_ATTR_RSV:
  case TOOL400_RANGE_ATTR_USR:
  case TOOL400_RANGE_KEY_SPEC:
  case TOOL400_RANGE_HIGH:
  default:
    break;
  }
  return match;
}

int tool_key_match_end_2_beg(int key) {
  int match = 0;
  int range = 0;
  range = tool_key_range(key);
  switch (range) {
  case TOOL400_RANGE_ELEM_RSV_BEG:
  case TOOL400_RANGE_ELEM_USR_BEG:
    break;
  case TOOL400_RANGE_ELEM_RSV_END:
    match = key - (TOOL400_KEY_ELEM_RSV_END - TOOL400_KEY_ELEM_RSV_BEG);
    break;
  case TOOL400_RANGE_ELEM_USR_END:
    match = key - (TOOL400_KEY_ELEM_USR_END - TOOL400_KEY_ELEM_USR_BEG);
    break;
  case TOOL400_RANGE_ATTR_RSV:
  case TOOL400_RANGE_ATTR_USR:
  case TOOL400_RANGE_KEY_SPEC:
  case TOOL400_RANGE_HIGH:
  default:
    break;
  }
  return match;
}

int tool_key_match_attr_2_beg(int key) {
  int match = 0;
  int range = 0;
  int tmp = 0;
  range = tool_key_range(key);
  switch (range) {
  case TOOL400_RANGE_ELEM_RSV_BEG:
  case TOOL400_RANGE_ELEM_USR_BEG:
  case TOOL400_RANGE_ELEM_RSV_END:
  case TOOL400_RANGE_ELEM_USR_END:
    break;
  case TOOL400_RANGE_ATTR_RSV:
    tmp = (key - (TOOL400_KEY_ATTR_RSV_BEG - TOOL400_KEY_ELEM_RSV_BEG));
    tmp -= tmp % 10;
    match = tmp;
    break;
  case TOOL400_RANGE_ATTR_USR:
    tmp = (key - (TOOL400_KEY_ATTR_USR_BEG - TOOL400_KEY_ELEM_USR_BEG));
    tmp -= tmp % 10;
    match = tmp;
    break;
  case TOOL400_RANGE_KEY_SPEC:
  case TOOL400_RANGE_HIGH:
  default:
    break;
  }
  return match;
}


tool_node_t * tool_node_beg(tool_struct_t * tool, int key, int ord) {
  return tool_node_add(tool, key, NULL, ord);
}
tool_node_t * tool_node_end(tool_struct_t * tool, tool_node_t *node, int key, int ord) {
  int i = 0;
  int match = 0;
  tool_node_t *node_cur = NULL;
  tool_node_t *node_beg = NULL;
  /* find working begin node */
  match = tool_key_match_end_2_beg(key);
  for (i = ord; i > -1; i--) {
    node_beg = tool_node_find_key_ord_not_fin(tool, node, match, i);
    if (node_beg) {
      break;
    }
  }
  if (node_beg) {
    node_beg->fin = node->ord;
    node_cur = tool_node_add(tool, key, NULL, node->ord);
    return node_cur;
  /* not found (replication of last?) */
  } else {
    /* i dunno */
  }
  return node;
}
tool_node_t * tool_node_sep(tool_struct_t * tool, tool_node_t *node, int key, int ord) {
  int i = 0;
  int match = 0;
  int add = 0;
  tool_node_t *node_cur = NULL;
  tool_node_t *node_beg = NULL;
  /* find working begin node */
  for (i = ord; i > -1; i--) {
    node_beg = tool_node_find_ord_not_fin(tool, node, i);
    if (node_beg) {
      break;
    }
  }
  if (node_beg) {
    /* add new one */
    switch (node_beg->key) {
    case TOOL400_KEY_DCL_S:
    case TOOL400_KEY_PARM:
      add = 1;
      break;
    default:
      add = 0;
      break;
    }
    if (add) {
      node_beg->fin = node->ord;
      match = tool_key_match_beg_2_end(node_beg->key);
      node_cur = tool_node_add(tool, match, NULL, node_beg->ord);
      node_cur = tool_node_add(tool, node_beg->key, NULL, node_beg->ord);
      return node_cur;
    }
  /* not found (replication of last?) */
  } else {
    /* i dunno */
  }
  return node;
}
tool_node_t * tool_node_attr(tool_struct_t * tool, tool_node_t * node, int key, char *val, int ord) {
  int i = 0;
  int match = 0;
  tool_node_t *node_cur = NULL;
  tool_node_t *node_beg = NULL;
  /* find working begin node */
  match = tool_key_match_attr_2_beg(key);
  for (i = ord; i > -1; i--) {
    node_beg = tool_node_find_key_ord_not_fin(tool, node, match, i);
    if (node_beg) {
      break;
    }
  }
  /* found working begin node */
  if (node_beg) {
    tool_node_attr_add(node_beg, key, val);
  /* not found (replication of last?) */
  } else {
    /* i dunno */
  }
  return node;
}

/*=================================================
 * toolkit trace
 */

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

    case TOOL400_KEY_ATTR_RSV_BEG:
      printf_format("%-50s %6d %6d %6d %25s (%s)\n",widekey, idx, lvl, key, "TOOL400_KEY_ATTR_RSV_BEG", val);
      break;
    case TOOL400_KEY_ATTR_RSV_END:
      printf_format("%-50s %6d %6d %6d %25s (%s)\n",widekey, idx, lvl, key, "TOOL400_KEY_ATTR_RSV_END", val);
      break;
    case TOOL400_KEY_SPEC_BEG:
      printf_format("%-50s %6d %6d %6d %25s (%s)\n",widekey, idx, lvl, key, "TOOL400_KEY_SPEC_BEG", val);
      break;
    case TOOL400_KEY_SEPC_END:
      printf_format("%-50s %6d %6d %6d %25s (%s)\n",widekey, idx, lvl, key, "TOOL400_KEY_SEPC_END", val);
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

void tool_graph(SQLRETURN sqlrc, char *func, tool_key_t * tk) {
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
    for (i=0, node = tk->tool->first; node; node = node->next, i++) {
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
    if (sqlrc < SQL_SUCCESS) {
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}

void tool_dump(int flag, SQLRETURN sqlrc, char *func, int idx, int lvl, int key,  char * val) {
  char mykey[256];
  if (dev_go(sqlrc,"sql400json")) {
    tool_dump_mykey(mykey,func);
    printf_clear();
    if (flag > 99) printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    /* printf_stack(mykey); */
    if (flag > 1 && sqlrc != SQL_SUCCESS) printf_sqlrc_status((char *)&mykey, sqlrc);
    tool_dump_lvl_key_val(mykey, idx, lvl, key, val);
    if (flag > 99) printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void tool_dump_attr(SQLRETURN sqlrc, char *func, int idx, int lvl, int key,  char * val) {
  tool_dump(0, sqlrc, func, idx, lvl, key, val);
}
void tool_dump_beg(SQLRETURN sqlrc, char *func, int idx, int lvl, int key,  char * val) {
  tool_dump(1, sqlrc, func, idx, lvl, key, val);
}
void tool_dump_end(SQLRETURN sqlrc, char *func, int idx, int lvl, int key,  char * val) {
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
void tool_pgm_dump(SQLRETURN sqlrc, char *func, int step, tool_key_pgm_struct_t * tpgm) {
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
      tool_dump_hex_chunks(mykey, spill_area, spill_len);
    }
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}


/*=================================================
 * toolkit callback output format
 */

void tool_output_script_beg(tool_struct_t *tool, char *out_caller) {
  tool->output_script_beg(out_caller);
}
void tool_output_script_end(tool_struct_t *tool, char *out_caller) {
  tool->output_script_end(out_caller);
}
void tool_output_query_beg(tool_struct_t *tool, char *out_caller, char *query) {
  tool->output_query_beg(out_caller, query);
}
void tool_output_query_end(tool_struct_t *tool, char *out_caller) {
  tool->output_query_end(out_caller);
}
void tool_output_record_array_beg(tool_struct_t *tool, char *out_caller) {
  tool->output_record_array_beg(out_caller);
}
void tool_output_record_array_end(tool_struct_t *tool, char *out_caller) {
  tool->output_record_array_end(out_caller);
}
void tool_output_record_no_data_found(tool_struct_t *tool, char *out_caller) {
  tool->output_record_no_data_found(out_caller);
}
void tool_output_record_row_beg(tool_struct_t *tool, char *out_caller) {
  tool->output_record_row_beg(out_caller);
}
void tool_output_record_name_value(tool_struct_t *tool, char *name, char *value, int type, int fStrLen, char *out_caller) {
  tool->output_record_name_value(name, value, type, fStrLen, out_caller);
}
void tool_output_record_row_end(tool_struct_t *tool, char *out_caller) {
  tool->output_record_row_end(out_caller);
}
int tool_output_sql_errors(tool_struct_t *tool, SQLHANDLE handle, SQLSMALLINT hType, int rc, char *out_caller)
{
  return tool->output_sql_errors(handle, hType, rc, out_caller);
}
void tool_output_pgm_beg(tool_struct_t *tool, char *out_caller, char * name, char * lib, char * func) {
  tool->output_pgm_beg(out_caller, name, lib, func);
}
void tool_output_pgm_end(tool_struct_t *tool, char *out_caller) {
  tool->output_pgm_end(out_caller);
}
void tool_output_pgm_dcl_s_beg(tool_struct_t *tool, char *out_caller, char * name, int tdim) {
  tool->output_pgm_dcl_s_beg(out_caller, name, tdim);
}
void tool_output_pgm_dcl_s_data(tool_struct_t *tool, char *out_caller, char *value, int numFlag) {
  tool->output_pgm_dcl_s_data(out_caller, value, numFlag);
}
void tool_output_pgm_dcl_s_end(tool_struct_t *tool, char *out_caller, int tdim) {
  tool->output_pgm_dcl_s_end(out_caller, tdim);
}
void tool_output_pgm_dcl_ds_beg(tool_struct_t *tool, char *out_caller, char * name, int tdim) {
  tool->output_pgm_dcl_ds_beg(out_caller, name, tdim);
}
void tool_output_pgm_dcl_ds_end(tool_struct_t *tool, char *out_caller, int tdim) {
  tool->output_pgm_dcl_ds_end(out_caller, tdim);
}
void tool_output_cmd_beg(tool_struct_t *tool, char *out_caller, char * cmd) {
  tool->output_cmd_beg(out_caller, cmd);
}
void tool_output_cmd_end(tool_struct_t *tool, char *out_caller) {
  tool->output_cmd_end(out_caller);
}

void tool_output_joblog_beg(tool_struct_t *tool, char *out_caller) {
  tool->output_joblog_beg(out_caller);
}
void tool_output_joblog_rec(tool_struct_t *tool, char *out_caller, char * msgid, char * msgtype, char * msgsub, char * msgsev, char * msgstamp, char * msgtolib, char * msgtopgm, char * msgtomod, char * msgtoproc, char * msgtoinst, char * msgtxt) {
  tool->output_joblog_rec(out_caller,msgid,msgtype,msgsub,msgsev,msgstamp,msgtolib,msgtopgm,msgtomod,msgtoproc,msgtoinst,msgtxt);
}
void tool_output_joblog_end(tool_struct_t *tool, char *out_caller) {
  tool->output_joblog_end(out_caller);
}


/*=================================================
 * toolkit copy in/out ILE parm layout
 */
char * ile_pgm_spill_top_buf(ile_pgm_call_t * layout) {
  return (char *)&layout->buf;
}
int ile_pgm_spill_top_offset(ile_pgm_call_t * layout) {
  int delta = 0;
  delta = (char *)&layout->buf - (char *)layout;
  return delta;
}
int ile_pgm_spill_length(ile_pgm_call_t * layout) {
  int delta = 0;
  delta = (char *)&layout->buf - (char *)layout;
  return layout->pos - delta;
}
char * ile_pgm_argv_top_buf(ile_pgm_call_t * layout) {
  return (char *)&layout->argv[0];
}
int ile_pgm_argv_top_offset(ile_pgm_call_t * layout) {
  int delta = 0;
  delta = (char *)&layout->argv[0] - (char *)layout;
  return delta;
}
int ile_pgm_argv_length(ile_pgm_call_t * layout) {
  int delta = 0;
  delta = (char *)&layout->argv[0] - (char *)layout;
  return layout->vpos - delta;
}


/* by ref area */
void ile_pgm_reset_spill_pos(ile_pgm_call_t * layout) {
  layout->pos = ile_pgm_spill_top_offset(layout);
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
  layout->vpos = ile_pgm_argv_top_offset(layout);
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

void ile_pgm_reset_pos(ile_pgm_call_t * layout) {
  ile_pgm_reset_argv_pos(layout);
  ile_pgm_reset_spill_pos(layout);
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
  tmp = tool_new(new_len);
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
    ile_pgm_reset_pos(layout);
  }
  /* old layout free */
  tmp = (char *)(*playout);
  if (tmp) {
    tool_free(tmp);
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

SQLRETURN ile_pgm_str_2_int8(char * where, const char *str, int tdim) {
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
SQLRETURN ile_pgm_int8_2_output(tool_struct_t *tool, char *out_caller, char * where, int tdim) {
  int i = 0;
  int8 * wherev = (int8 *) where;
  int8 value = 0;
  char str[128];
  for (i=0; i < tdim; i++, wherev++) {
    value = *wherev;
    memset(str,0,sizeof(str));
    sprintf(str,"%d",value);
    tool_output_pgm_dcl_s_data(tool, out_caller, str, 1);
  }
  return SQL_SUCCESS;
}

SQLRETURN ile_pgm_str_2_int16(char * where, const char *str, int tdim) {
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
SQLRETURN ile_pgm_int16_2_output(tool_struct_t *tool, char *out_caller, char * where, int tdim) {
  int i = 0;
  int16 * wherev = (int16 *) where;
  int16 value = 0;
  char str[128];
  for (i=0; i < tdim; i++, wherev++) {
    value = *wherev;
    memset(str,0,sizeof(str));
    sprintf(str,"%d",value);
    tool_output_pgm_dcl_s_data(tool, out_caller, str, 1);
  }
  return SQL_SUCCESS;
}

SQLRETURN ile_pgm_str_2_int32(char * where, const char *str, int tdim) {
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
SQLRETURN ile_pgm_int32_2_output(tool_struct_t *tool, char *out_caller, char * where, int tdim) {
  int i = 0;
  int32 * wherev = (int32 *) where;
  int32 value = 0;
  char str[128];
  for (i=0; i < tdim; i++, wherev++) {
    value = *wherev;
    memset(str,0,sizeof(str));
    sprintf(str,"%d",value);
    tool_output_pgm_dcl_s_data(tool, out_caller, str, 1);
  }
  return SQL_SUCCESS;
}

SQLRETURN ile_pgm_str_2_int64(char * where, const char *str, int tdim) {
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
SQLRETURN ile_pgm_int64_2_output(tool_struct_t *tool, char *out_caller, char * where, int tdim) {
  int i = 0;
  int64 * wherev = (int64 *) where;
  int64 value = 0;
  char str[128];
  for (i=0; i < tdim; i++, wherev++) {
    value = *wherev;
    memset(str,0,sizeof(str));
    sprintf(str,"%lld",value);
    tool_output_pgm_dcl_s_data(tool, out_caller, str, 1);
  }
  return SQL_SUCCESS;
}

SQLRETURN ile_pgm_str_2_uint8(char * where, const char *str, int tdim) {
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
SQLRETURN ile_pgm_uint8_2_output(tool_struct_t *tool, char *out_caller, char * where, int tdim) {
  int i = 0;
  uint8 * wherev = (uint8 *) where;
  uint8 value = 0;
  char str[128];
  for (i=0; i < tdim; i++, wherev++) {
    value = *wherev;
    memset(str,0,sizeof(str));
    sprintf(str,"%u",value);
    tool_output_pgm_dcl_s_data(tool, out_caller, str, 1);
  }
  return SQL_SUCCESS;
}

SQLRETURN ile_pgm_str_2_uint16(char * where, const char *str, int tdim) {
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
SQLRETURN ile_pgm_uint16_2_output(tool_struct_t *tool, char *out_caller, char * where, int tdim) {
  int i = 0;
  uint16 * wherev = (uint16 *) where;
  uint16 value = 0;
  char str[128];
  for (i=0; i < tdim; i++, wherev++) {
    value = *wherev;
    memset(str,0,sizeof(str));
    sprintf(str,"%u",value);
    tool_output_pgm_dcl_s_data(tool, out_caller, str, 1);
  }
  return SQL_SUCCESS;
}

SQLRETURN ile_pgm_str_2_uint32(char * where, const char *str, int tdim) {
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
SQLRETURN ile_pgm_uint32_2_output(tool_struct_t *tool, char *out_caller, char * where, int tdim) {
  int i = 0;
  uint32 * wherev = (uint32 *) where;
  uint32 value = 0;
  char str[128];
  for (i=0; i < tdim; i++, wherev++) {
    value = *wherev;
    memset(str,0,sizeof(str));
    sprintf(str,"%u",value);
    tool_output_pgm_dcl_s_data(tool, out_caller, str, 1);
  }
  return SQL_SUCCESS;
}

SQLRETURN ile_pgm_str_2_uint64(char * where, const char *str, int tdim) {
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
SQLRETURN ile_pgm_uint64_2_output(tool_struct_t *tool, char *out_caller, char * where, int tdim) {
  int i = 0;
  uint64 * wherev = (uint64 *) where;
  uint64 value = 0;
  char str[128];
  for (i=0; i < tdim; i++, wherev++) {
    value = *wherev;
    memset(str,0,sizeof(str));
    sprintf(str,"%llu",value);
    tool_output_pgm_dcl_s_data(tool, out_caller, str, 1);
  }
  return SQL_SUCCESS;
}

SQLRETURN ile_pgm_str_2_float(char * where, const char *str, int tdim) {
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
SQLRETURN ile_pgm_float_2_output(tool_struct_t *tool, char *out_caller, char * where, int tscale, int tdim) {
  int i = 0;
  float * wherev = (float *) where;
  float value = 0;
  char str[128];
  char outfmt[128];
  for (i=0; i < tdim; i++, wherev++) {
    value = *wherev;
    memset(str,0,sizeof(str));
    if (tscale) {
      memset(outfmt,0,sizeof(outfmt));
      sprintf(outfmt,"%%.%df",tscale);
      sprintf(str,outfmt,value);
    } else {
      sprintf(str,"%f",value);
    }
    tool_output_pgm_dcl_s_data(tool, out_caller, str, 1);
  }
  return SQL_SUCCESS;
}

SQLRETURN ile_pgm_str_2_double(char * where, const char *str, int tdim) {
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
SQLRETURN ile_pgm_double_2_output(tool_struct_t *tool, char *out_caller, char * where, int tscale, int tdim) {
  int i = 0;
  double * wherev = (double *) where;
  double value = 0;
  char str[128];
  char outfmt[128];
  for (i=0; i < tdim; i++, wherev++) {
    value = *wherev;
    memset(str,0,sizeof(str));
    if (tscale) {
      memset(outfmt,0,sizeof(outfmt));
      sprintf(outfmt,"%%.%df",tscale);
      sprintf(str,outfmt,value);
    } else {
      sprintf(str,"%f",value);
    }
    tool_output_pgm_dcl_s_data(tool, out_caller, str, 1);
  }
  return SQL_SUCCESS;
}

SQLRETURN ile_pgm_str_2_hole(char * where, int tlen, int tdim) {
  int i = 0;
  char * wherev = where;
  /* copy in */
  for (i=0; i < tdim; i++, wherev += tlen) {
    memset(wherev,0,tlen);
  }
  return SQL_SUCCESS;
}


SQLRETURN ile_pgm_str_2_packed(char * where, char *str, int tdim, int tlen, int tscale) {
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
SQLRETURN ile_pgm_packed_2_output(tool_struct_t *tool, char *out_caller, char * where, int tlen, int tscale, int tdim) {
  int i = 0;
  int j = 0;
  int k = 0;
  int l = 0;
  int isOk = 0;
  int isDot = 0;
  int isScale = 0;
  char * wherev = (char *) where;
  int outDigits = tlen;
  int outLength = outDigits/2+1;
  int leftDigitValue = 0;
  int rightDigitValue = 0;
  char * c = NULL;
  char str[128];
  for (i=0; i < tdim; i++, wherev += outLength) {
    memset(str,0,sizeof(str));
    /* sign negative */
    c = wherev;
    rightDigitValue = (char)(c[outLength-1] & 0x0F);
    if (rightDigitValue == 0x0D) {
      str[j++] = '-';
    }
    for (j=0, k=0, l=0, isOk=0, isDot=0, isScale=0; k < outLength; k++) {
      /* decimal point */
      l++;
      if (!isDot && tscale && l >= tlen) {
        if (!isOk) {
          str[j++] = (char) 0x30;
        }
        str[j++] = '.';
        isDot = 1;
        isOk = 1;
      }
      /* digits */
      leftDigitValue = (char)((c[k] >> 4) & 0x0F);
      if (isOk || leftDigitValue > 0) {
        str[j++] = (char)(0x30 + leftDigitValue);
        isOk = 1;
        if (isDot) {
          isScale++;
        }
      }
      /* decimal point */
      l++;
      if (!isDot && tscale && l >= tlen) {
        if (!isOk) {
          str[j++] = (char) 0x30;
        }
        str[j++] = '.';
        isDot = 1;
        isOk = 1;
      }
      /* digits */
      rightDigitValue = (char)(c[k] & 0x0F);
      if (k < outLength-1 && (isOk || rightDigitValue > 0)) {
        str[j++] = (char)(0x30 + rightDigitValue);
        isOk = 1;
        if (isDot) {
          isScale++;
        }
      }
    }
    /* zero */
    if (!isOk) {
      str[j++] = (char) 0x30;
      str[j++] = '.';
      isOk = 1;
      isDot = 1;
      isScale = 0;
    }
    /* one significant decimal */
    if (isDot && !isScale) {
      str[j++] = (char) 0x30;
    }
    tool_output_pgm_dcl_s_data(tool, out_caller, str, 1);
  }
  return SQL_SUCCESS;
}

SQLRETURN ile_pgm_str_2_zoned(char * where, char *str, int tdim, int tlen, int tscale) {
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
  for (i=0; i < outDigits-inLength; i++) {
    dec[j++] = (char)0xF0;
  }
  /* place all the digits except the last one */
  while (j < outLength-1) {
    dec[j++] = (char)((c[k++] & 0x000F) | 0x00F0);
  }
  /* place the sign and last digit */
  if (!sign) {
    dec[j++] = (char)((c[k++] & 0x000F) | 0x00F0);
  } else {
    dec[j++] = (char)((c[k++] & 0x000F) | 0x00D0);
  }
  /* copy in */
  for (i=0; i < tdim; i++, wherev += outLength) {
    memcpy(wherev, dec, outLength);
  }
  return SQL_SUCCESS;
}
SQLRETURN ile_pgm_zoned_2_output(tool_struct_t *tool, char *out_caller, char * where, int tlen, int tscale, int tdim) {
  int i = 0;
  int j = 0;
  int k = 0;
  int l = 0;
  int isOk = 0;
  int isDot = 0;
  int isScale = 0;
  char * wherev = (char *) where;
  int outDigits = tlen;
  int outLength = outDigits;
  int leftDigitValue = 0;
  int rightDigitValue = 0;
  char * c = NULL;
  char str[128];
  for (i=0; i < tdim; i++, wherev += outLength) {
    memset(str,0,sizeof(str));
    /* sign negative */
    c = wherev;
    leftDigitValue = (char)((c[outLength-1] >> 4) & 0x0F);
    if (leftDigitValue == 0x0D) {
      str[j++] = '-';
    }
    for (j=0, k=0, l=0, isOk=0, isDot=0, isScale=0; k < outLength; k++) {
      /* digits */
      leftDigitValue = (char)((c[k] >> 4) & 0x0F);
      /* decimal point */
      if (!isDot && tscale && l >= tlen - tscale) {
        if (!isOk) {
          str[j++] = (char) 0x30;
        }
        str[j++] = '.';
        isDot = 1;
        isOk = 1;
      }
      l++;
      /* digits */
      rightDigitValue = (char)(c[k] & 0x0F);
      if (isOk || rightDigitValue > 0) {
        str[j++] = (char)(0x30 + rightDigitValue);
        isOk = 1;
        if (isDot) {
          isScale++;
        }
      }
    }
    /* zero */
    if (!isOk) {
      str[j++] = (char) 0x30;
      str[j++] = '.';
      isOk = 1;
      isDot = 1;
      isScale = 0;
    }
    /* one significant decimal */
    if (isDot && !isScale) {
      str[j++] = (char) 0x30;
    }
    tool_output_pgm_dcl_s_data(tool, out_caller, str, 1);
  }
  return SQL_SUCCESS;
}



SQLRETURN ile_pgm_str_2_char(char * where, char *str, int tdim, int tlen, int tvary, int tccsid) {
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
  /* truncate user overflow field area */
  len = strlen(str);
  if (len > tlen) {
    len = tlen;
  }
  /* ebcdic ccsid? */
  if (!tccsid) {
    tccsid = Qp2jobCCSID();
  }
  /* convert ccsid */
  if (len) {
    ebcdic = tool_new(len*4);
    rc = SQL400FromUtf8(0, str, len, ebcdic, len*4, tccsid);
    c = ebcdic;
    j = 0;
    for (i = len*4 - 1; i>-1; i--) {
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
    tool_free(ebcdic);
  }
  return SQL_SUCCESS;
}
SQLRETURN ile_pgm_char_2_output(tool_struct_t *tool, char *out_caller, char * where, int tlen, int tvary, int tccsid, int tdim) {
  int rc = 0;
  int i = 0;
  int j = 0;
  char * wherev = where;
  int len = 0;
  char * utf8 = NULL;
  char * c = NULL;
  char * str_empty = "";
  char * str_tool_empty = "{}";
  /* ebcdic ccsid? */
  if (!tccsid) {
    tccsid = Qp2jobCCSID();
  }
  /* copy in ebcdic 2 utf8 */
  len = tlen;
  utf8 = tool_new(len*4);
  for (i=0; i < tdim; i++, wherev += tlen) {
    /* vary */
    if (tvary == 4) {
      len = *(int *) wherev;
      wherev += 4;
    } else if (tvary) {
      len = *(short *) wherev;
      wherev += 2;
    } else {
      len = tlen;
    }
    if (len) {
      /* convert ebcdic to utf8 */
      memset(utf8,0,len*4);
      rc = SQL400ToUtf8(0, wherev, len, utf8, len*4, tccsid);
      /* trim */
      len = strlen(utf8);
      for (c = utf8, j = len - 1; j >= 0; j--) {
        if (!c[j] || c[j] == 0x20) {
          c[j] = 0x00;
          len = j;
        } else {
          break;
        }
      }
    } /* j loop (trim) */
    /* output processing */
    if (len) {
      tool_output_pgm_dcl_s_data(tool, out_caller, utf8, 0);
    } else {
      tool_output_pgm_dcl_s_data(tool, out_caller, str_tool_empty, 1);
    }
  } /* i loop (tdim) */
  /* free temp storage */
  if (utf8) {
    tool_free(utf8);
  }
  return SQL_SUCCESS;
}

SQLRETURN ile_pgm_str_2_bin(char * where, char *str, int tdim, int tlen, int tvary) {
  int i = 0;
  int j = 0;
  int k = 0;
  int outDigits = tlen;
  int outLength = outDigits;
  int inLength = 0;
  short * short_value = NULL;
  int * int_value = NULL;
  char * dec = NULL;
  char * c = NULL;
  char * wherev = where;
  char bytex = ' ';
  int hnbr = 0;
  int lnbr = 0;
  /* length of char hex binary input */
  if (str) {
    inLength = strlen(str);
  }
  /* truncate user overflow field area */
  if (inLength > tlen * 2) {
    inLength = tlen * 2;
  }
  /* copy in */
  for (i=0; i < tdim; i++, wherev += outLength) {
    /* vary */
    if (tvary == 4) {
      int_value = (int *) wherev;
      *int_value = inLength/2;
      wherev += 4;
    } else if (tvary) {
      short_value = (short *) wherev;
      *short_value = inLength/2;
      wherev += 2;
    }
    /* digits */
    memset(wherev, 0, outLength);
    dec = wherev;
    c = str;
    for (j=0, k=0; j < outDigits && k < inLength; k += 2) {
      bytex = str[k];
      if (bytex=='F' || bytex=='f') {
          hnbr = 15;
      } else if (bytex=='E' || bytex=='e') {
          hnbr = 14;
      } else if (bytex=='D' || bytex=='d') {
          hnbr = 13;
      } else if (bytex=='C' || bytex=='c') {
          hnbr = 12;
      } else if (bytex=='B' || bytex=='b') {
          hnbr = 11;
      } else if (bytex=='A' || bytex=='a') {
          hnbr = 10;
      } else if (bytex=='9') {
          hnbr = 9;
      } else if (bytex=='8') {
          hnbr = 8;
      } else if (bytex=='7') {
          hnbr = 7;
      } else if (bytex=='6') {
          hnbr = 6;
      } else if (bytex=='5') {
          hnbr = 5;
      } else if (bytex=='4') {
          hnbr = 4;
      } else if (bytex=='3') {
          hnbr = 3;
      } else if (bytex=='2') {
          hnbr = 2;
      } else if (bytex=='1') {
          hnbr = 1;
      } else {
          hnbr = 0;
      }
      bytex = str[k + 1];
      if (bytex=='F' || bytex=='f') {
          lnbr = 15;
      } else if (bytex=='E' || bytex=='e') {
          lnbr = 14;
      } else if (bytex=='D' || bytex=='d') {
          lnbr = 13;
      } else if (bytex=='C' || bytex=='c') {
          lnbr = 12;
      } else if (bytex=='B' || bytex=='b') {
          lnbr = 11;
      } else if (bytex=='A' || bytex=='a') {
          lnbr = 10;
      } else if (bytex=='9') {
          lnbr = 9;
      } else if (bytex=='8') {
          lnbr = 8;
      } else if (bytex=='7') {
          lnbr = 7;
      } else if (bytex=='6') {
          lnbr = 6;
      } else if (bytex=='5') {
          lnbr = 5;
      } else if (bytex=='4') {
          lnbr = 4;
      } else if (bytex=='3') {
          lnbr = 3;
      } else if (bytex=='2') {
          lnbr = 2;
      } else if (bytex=='1') {
          lnbr = 1;
      } else {
          lnbr = 0;
      }
      dec[j++] = (char)(hnbr*16 + lnbr);
    }
  }
  return SQL_SUCCESS;
}
SQLRETURN ile_pgm_bin_2_output(tool_struct_t *tool, char *out_caller, char * where, int tlen, int tvary, int tdim) {
  int i = 0;
  int j = 0;
  int k = 0;
  int l = 0;
  int len = 0;
  char * wherev = (char *) where;
  int outDigits = tlen;
  int outLength = outDigits*2+1;
  char * c = NULL;
  char * str = NULL;
  int hnbr = 0;
  int lnbr = 0;
  str = tool_new(outLength);
  for (i=0; i < tdim; i++, wherev += outDigits) {
    /* vary */
    if (tvary == 4) {
      len = *(int *) wherev;
      wherev += 4;
    } else if (tvary) {
      len = *(short *) wherev;
      wherev += 2;
    } else {
      len = tlen;
    }
    /* digits */
    memset(str,0,outLength);
    for (k=0, c = wherev; k < len; k++) {
      hnbr = (int)c[k];
      if (hnbr>=240) { /* x'FO' */
          str[j++] = 'F';
          lnbr = hnbr - 240;
      } else if (hnbr>=224 && hnbr<240) { /* x'E0' */
          str[j++] = 'E';
          lnbr = hnbr - 224;
      } else if (hnbr>=208 && hnbr<224) { /* x'D0' */
          str[j++] = 'D';
          lnbr = hnbr - 208;
      } else if (hnbr>=192 && hnbr<208) { /* x'C0' */
          str[j++] = 'C';
          lnbr = hnbr - 192;
      } else if (hnbr>=176 && hnbr<192) { /* x'B0' */
          str[j++] = 'B';
          lnbr = hnbr - 176;
      } else if (hnbr>=160 && hnbr<176) { /* x'A0' */
          str[j++] = 'A';
          lnbr = hnbr - 160;
      } else if (hnbr>=144 && hnbr<160) { /* x'90' */
          str[j++] = '9';
          lnbr = hnbr - 144;
      } else if (hnbr>=128 && hnbr<144) { /* x'80' */
          str[j++] = '8';
          lnbr = hnbr - 128;
      } else if (hnbr>=112 && hnbr<128) { /* x'70' */
          str[j++] = '7';
          lnbr = hnbr - 112;
      } else if (hnbr>=96 && hnbr<112) { /* x'60' */
          str[j++] = '6';
          lnbr = hnbr - 96;
      } else if (hnbr>=80 && hnbr<96) { /* x'50' */
          str[j++] = '5';
          lnbr = hnbr - 80;
      } else if (hnbr>=64 && hnbr<80) { /* x'40' */
          str[j++] = '4';
          lnbr = hnbr - 64;
      } else if (hnbr>=48 && hnbr<64) { /* x'30' */
          str[j++] = '3';
          lnbr = hnbr - 48;
      } else if (hnbr>=32 && hnbr<48) { /* x'20' */
          str[j++] = '2';
          lnbr = hnbr - 32;
      } else if (hnbr>=16 && hnbr<32) { /* x'10' */
          str[j++] = '1';
          lnbr = hnbr - 16;
      } else {
          str[j++] = '0';
          lnbr = hnbr;
      }
      if (lnbr>=15) { /* x'0F' */
          str[j++] = 'F';
      } else if (lnbr>=14 && lnbr<15) { /* x'0E' */
          str[j++] = 'E';
      } else if (lnbr>=13 && lnbr<14) { /* x'0D' */
          str[j++] = 'D';
      } else if (lnbr>=12 && lnbr<13) { /* x'0C' */
          str[j++] = 'C';
      } else if (lnbr>=11 && lnbr<12) { /* x'0B' */
          str[j++] = 'B';
      } else if (lnbr>=10 && lnbr<11) { /* x'0A' */
          str[j++] = 'A';
      } else if (lnbr>=9 && lnbr<10) { /* x'09' */
          str[j++] = '9';
      } else if (lnbr>=8 && lnbr<9) { /* x'08' */
          str[j++] = '8';
      } else if (lnbr>=7 && lnbr<8) { /* x'07' */
          str[j++] = '7';
      } else if (lnbr>=6 && lnbr<7) { /* x'06' */
          str[j++] = '6';
      } else if (lnbr>=5 && lnbr<6) { /* x'05' */
          str[j++] = '5';
      } else if (lnbr>=4 && lnbr<5) { /* x'04' */
          str[j++] = '4';
      } else if (lnbr>=3 && lnbr<4) { /* x'03' */
          str[j++] = '3';
      } else if (lnbr>=2 && lnbr<3) { /* x'02' */
          str[j++] = '2';
      } else if (lnbr>=1 && lnbr<2) { /* x'01' */
          str[j++] = '1';
      } else {
          str[j++] = '0';
      }
    } /* k loop (outLength) */
    tool_output_pgm_dcl_s_data(tool, out_caller, str, 0);
  } /* i loop (tdim) */
  /* free temp storage */
  if (str) {
    tool_free(str);
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
    rc = ile_pgm_str_2_int32((char *)tlen, clen, 1);
  }
  /* scale */
  if (k) {
    rc = ile_pgm_str_2_int32((char *)tscale, cscale, 1);
  }
  /* varying 2 or 4 */
  if (v1 != ' ') {
    if (l) {
      rc = ile_pgm_str_2_int32((char *)tvary, cvary, 1);
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
  /* pass by ref/val or isDs (val) */
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
      layout->argv_parm[layout->argc] = -1;
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
    /* start return position */
    if (!layout->return_start) {
      layout->return_start = layout->pos;
    }
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

void ile_pgm_trim_ebcdic(char *str, int len) {
  int j = 0;
  char * c = NULL;
  for (c = str, j = len - 1; j >= 0; j--) {
    if (!c[j] || c[j] == 0x40) {
      c[j] = 0x00;
      len = j;
    } else {
      break;
    }
  }
}

/* "pgm":["NAME","LIB","procedure"], */
SQLRETURN tool_pgm(char *pgm, char *lib, char * func, ile_pgm_call_t **playout) {
  ile_pgm_call_t * layout = *playout;
  int rc = 0;

  /* grow template (if need) */
  layout = ile_pgm_grow(playout, sizeof(ile_pgm_call_t));

  /* copy ebcdic */
  rc = ile_pgm_str_2_char((char *)&layout->pgm, pgm, 1, sizeof(layout->pgm), 0, 0);
  ile_pgm_trim_ebcdic((char *)&layout->pgm, sizeof(layout->pgm));
  rc = ile_pgm_str_2_char((char *)&layout->lib, lib, 1, sizeof(layout->lib), 0, 0);
  ile_pgm_trim_ebcdic((char *)&layout->lib, sizeof(layout->lib));
  rc = ile_pgm_str_2_char((char *)&layout->func, func, 1, sizeof(layout->func), 0, 0);
  ile_pgm_trim_ebcdic((char *)&layout->func, sizeof(layout->func));

  /* layout return */
  *playout = layout;
}

/* "dcl-s":["name","type", value, dimension, "in|out|both|value|const|return"], */
SQLRETURN tool_dcl_s(tool_struct_t *tool, 
char *out_caller, int isOut, 
char * in_name,
char * in_type,
char * in_value,
char * in_dim,
char * in_by,
char * in_ccsid,
int isDs,
ile_pgm_call_t **playout) {

  ile_pgm_call_t * layout = *playout;

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

  /* parse "12p2", "5a", "5av2", ... */
  typ = ile_pgm_type(in_type, &tlen, &tscale, &tvary);
  if (tlen < 1) {
    return SQL_ERROR;
  }

  /* parse dimension */
  rc = ile_pgm_str_2_int32((char *)&tdim, in_dim, 1);
  if (tdim < 1) {
    tdim = 1;
  }

  /* parse ccsid */
  rc = ile_pgm_str_2_int32((char *)&tccsid, in_ccsid, 1);
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

  /* output processing */
  if (isOut) {
    tool_output_pgm_dcl_s_beg(tool, out_caller, in_name, tdim);
  }

  /* dcl-s type */
  switch (typ) {
  case 'i':
    switch (tlen) {
    case 3:
      if (isOut) {
        rc = ile_pgm_int8_2_output(tool, out_caller, where, tdim);
      } else {
        rc = ile_pgm_str_2_int8(where, in_value, tdim);
      }
      break;
    case 5:
      if (isOut) {
        rc = ile_pgm_int16_2_output(tool, out_caller, where, tdim);
      } else {
        rc = ile_pgm_str_2_int16(where, in_value, tdim);
      }
      break;
    case 10:
      if (isOut) {
        rc = ile_pgm_int32_2_output(tool, out_caller, where, tdim);
      } else {
        rc = ile_pgm_str_2_int32(where, in_value, tdim);
      }
      break;
    case 20:
      if (isOut) {
        rc = ile_pgm_int64_2_output(tool, out_caller, where, tdim);
      } else {
        rc = ile_pgm_str_2_int64(where, in_value, tdim);
      }
      break;
    default:
      rc = SQL_ERROR;
      break;
    }
    break;
  case 'u':
    switch (tlen) {
    case 3:
      if (isOut) {
        rc = ile_pgm_uint8_2_output(tool, out_caller, where, tdim);
      } else {
        rc = ile_pgm_str_2_uint8(where, in_value, tdim);
      }
      break;
    case 5:
      if (isOut) {
        rc = ile_pgm_uint16_2_output(tool, out_caller, where, tdim);
      } else {
        rc = ile_pgm_str_2_uint16(where, in_value, tdim);
      }
      break;
    case 10:
      if (isOut) {
        rc = ile_pgm_uint32_2_output(tool, out_caller, where, tdim);
      } else {
        rc = ile_pgm_str_2_uint32(where, in_value, tdim);
      }
      break;
    case 20:
      if (isOut) {
        rc = ile_pgm_uint64_2_output(tool, out_caller, where, tdim);
      } else {
        rc = ile_pgm_str_2_uint64(where, in_value, tdim);
      }
      break;
    default:
      rc = SQL_ERROR;
      break;
    }
    break;
  case 'f':
    switch (tlen) {
    case 4:
      if (isOut) {
        rc = ile_pgm_float_2_output(tool, out_caller, where, tscale, tdim);
      } else {
        rc = ile_pgm_str_2_float(where, in_value, tdim);
      }
      break;
    case 8:
      if (isOut) {
        rc = ile_pgm_double_2_output(tool, out_caller, where, tscale, tdim);
      } else {
        rc = ile_pgm_str_2_double(where, in_value, tdim);
      }
      break;
    default:
      rc = SQL_ERROR;
      break;
    }
    break;
  case 'p':
    if (isOut) {
      ile_pgm_packed_2_output(tool, out_caller, where, tlen, tscale, tdim);
    } else {
      rc = ile_pgm_str_2_packed(where, in_value, tdim, tlen, tscale);
    }
    break;
  case 's':
    if (isOut) {
      ile_pgm_zoned_2_output(tool, out_caller, where, tlen, tscale, tdim);
    } else {
      rc = ile_pgm_str_2_zoned(where, in_value, tdim, tlen, tscale);
    }
    break;
  case 'a':
    if (isOut) {
      ile_pgm_char_2_output(tool, out_caller, where, tlen, tvary, tccsid, tdim);
    } else {
      rc = ile_pgm_str_2_char(where, in_value, tdim, tlen, tvary, tccsid);
    }
    break;
  case 'b':
    if (isOut) {
      ile_pgm_bin_2_output(tool, out_caller, where, tlen, tvary, tdim);
    } else {
      rc = ile_pgm_str_2_bin(where, in_value, tdim, tlen, tvary);
    }
    break;
  case 'h':
    if (!isOut) {
      rc = ile_pgm_str_2_hole(where, tdim, tlen);
    }
    break;
  default:
    rc = SQL_ERROR;
    break;
  }
  /* output processing */
  if (isOut) {
    tool_output_pgm_dcl_s_end(tool, out_caller, tdim);
  }
  return rc;
}

/* "dcl-ds":["name",dimension, "in|out|both|value|const|return"] */
SQLRETURN tool_dcl_ds(
char * in_name,
char * in_dim,
char * in_by,
int * ds_dim, 
int * ds_by, 
char ** ds_where,
ile_pgm_call_t **playout) {

  ile_pgm_call_t * layout = *playout;

  char typ = ' ';
  int tlen = 0;
  int tscale = 0;
  int tvary = 0;
  int tdim = 0;

  int spill_len = 0;
  int rc = 0;
  int by = 0;
  char * where = NULL;

  /* parse dimension */
  rc = ile_pgm_str_2_int32((char *)&tdim, in_dim, 1);
  if (tdim < 1) {
    tdim = 1;
  }

  /* parse in|out|both|value|const|return */
  by = ile_pgm_by(in_by, typ, tlen, tdim, tvary, 0, &spill_len);
  if (spill_len) {
    /* grow template (if need) */
    layout = ile_pgm_grow(playout, spill_len);
  }

  /* location of parm or ds data */
  where = ile_pgm_parm_location(0, by, spill_len, layout);
  if (!where) {
    return SQL_ERROR;
  }

  /* parse data */
  *ds_dim = tdim;
  *ds_by = by;
  *ds_where = where;

  /* layout return */
  *playout = layout;

  return rc;
}

SQLRETURN ile_pgm_copy_ds(char *ds_where, int ds_dim, int ds_by, ile_pgm_call_t **playout) {

  ile_pgm_call_t * layout = *playout;

  int j = 0;
  int ds_spill_len = 0;
  char * where = NULL;

  /* multiple dim DS */
  if (ds_dim > 1) {
    where = ile_pgm_parm_location(0, ds_by, 0, layout);
    ds_spill_len = where - ds_where;
    for (j = 1; j < ds_dim; j++) {
      /* where now */
      where = ile_pgm_parm_location(0, ds_by, 0, layout);
      /* grow template (if need) */
      layout = ile_pgm_grow(playout, ds_spill_len);
      /* copy additional ds */
      memcpy(where,ds_where,ds_spill_len);
    }
  }

  /* layout return */
  *playout = layout;

  return SQL_SUCCESS;
}

/*=================================================
 * toolkit run parsed key, val, lvl
 */

/* program */
SQLRETURN tool_key_pgm_data_run(tool_key_t * tk, tool_key_pgm_struct_t * tpgm, int * isDs, int isOut, tool_node_t ** curr_node) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  int i = 0;
  int key = 0;
  char * val = NULL;
  int lvl = 0;
  int max = 0;
  int go = 1;
  char * pgm_s_name = NULL;
  char * pgm_s_type = NULL;
  char * pgm_s_val = NULL;
  char * pgm_s_dim = NULL;
  char * pgm_s_by = NULL;
  char * pgm_s_ccsid = NULL;
  tool_key_conn_struct_t * tconn = tk->tconn;
  tool_node_t * node = *curr_node;
  /* pgm data attributes (parser order 1st) */
  for (i=0; i < TOOL400_ATTR_MAX && node->akey[i]; i++) {
    key = node->akey[i];
    val = node->aval[i];
    lvl = node->ord;
    tool_dump_attr(sqlrc, "pgm_data_run(a)", i, lvl, key, val);
    switch (key) {
    case TOOL400_S_NAME:
      pgm_s_name = val;
      break;
    case TOOL400_S_DIM:
      pgm_s_dim = val;
      break;
    case TOOL400_S_TYPE:
      pgm_s_type = val;
      break;
    case TOOL400_S_VALUE:
      pgm_s_val = val;
      break;
    case TOOL400_S_BY:
      pgm_s_by = val;
      break;
    default:
      break;
    }
  }
  /* write or read data */
  sqlrc = tool_dcl_s(tk->tool, tk->outarea, isOut, pgm_s_name, pgm_s_type, pgm_s_val, pgm_s_dim, pgm_s_by, pgm_s_ccsid, *isDs, &tpgm->layout);
  return sqlrc;
}

SQLRETURN tool_key_pgm_ds_run(tool_key_t * tk, tool_key_pgm_struct_t * tpgm, int * isDs, int isOut, tool_node_t ** curr_node) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  int i = 0;
  int key = 0;
  char * val = NULL;
  int lvl = 0;
  int max = 0;
  int go = 1;
  int pgm_is_ds = 1;
  char * pgm_ds_name = NULL;
  char * pgm_ds_dim = NULL;
  char * pgm_ds_by = NULL;
  int pgm_ds_dim_cnt = 0;
  int pgm_ds_dim_max = 0;
  int pgm_ds_by_flag = 0;
  char * pgm_ds_where_start = NULL;
  tool_key_conn_struct_t * tconn = tk->tconn;
  tool_node_t * node = *curr_node;
  tool_node_t * pgm_ds_idx = node;
  /* pgm ds attributes (parser order 1st) */
  for (i=0; i < TOOL400_ATTR_MAX && node->akey[i]; i++) {
    key = node->akey[i];
    val = node->aval[i];
    lvl = node->ord;
    tool_dump_attr(sqlrc, "pgm_ds_run(a)", i, lvl, key, val);
    switch (key) {
    case TOOL400_DS_NAME:
      pgm_ds_name = val;
      break;
    case TOOL400_DS_DIM:
      pgm_ds_dim = val;
      break;
    case TOOL400_DS_BY:
      pgm_ds_by = val;
      break;
    default:
      break;
    }
  }
  /* where start here */
  sqlrc = tool_dcl_ds(pgm_ds_name, pgm_ds_by, pgm_ds_dim, &pgm_ds_dim_cnt, &pgm_ds_by_flag, &pgm_ds_where_start, &tpgm->layout);
  if (isOut) {
    tool_output_pgm_dcl_ds_beg(tk->tool, tk->outarea, pgm_ds_name, pgm_ds_dim_cnt);
  }
  /* pgm ds children (parser order next) */
  for (i=0, go = 1, node = node->next; node && sqlrc == SQL_SUCCESS && go; node = node->next, i++) {
    key = node->key;
    val = node->val;
    lvl = node->ord;
    if (!max) {
      max = node->ord;
    }
    if (lvl > max) {
      continue;
    }
    *curr_node = node;
    /* ds */
    tool_dump_beg(sqlrc, "pgm_ds_run", i, lvl, key, val);
    switch (key) {
    case TOOL400_KEY_DCL_S:
      sqlrc = tool_key_pgm_data_run(tk, tpgm, isDs, isOut, &node);
      *isDs = 1; /* if pass by ref, was the first argv->data element */
      break;
    case TOOL400_KEY_DCL_DS:
      sqlrc = tool_key_pgm_ds_run(tk, tpgm, isDs, isOut, &node);
      break;
    case TOOL400_KEY_END_DS:
      if (!isOut) {
        sqlrc = ile_pgm_copy_ds(pgm_ds_where_start, pgm_ds_dim_cnt, pgm_ds_by_flag, &tpgm->layout);
        go = 0;
      } else {
        /* dim replay ds (from pgm_ds_idx) */
        if (!pgm_ds_dim_max) {
          pgm_ds_dim_max = pgm_ds_dim_cnt;
        }
        pgm_ds_dim_cnt--;
        if (pgm_ds_dim_cnt > 0) {
          node = pgm_ds_idx;
        } else {
          tool_output_pgm_dcl_ds_end(tk->tool, tk->outarea, pgm_ds_dim_max);
          pgm_ds_dim_max = 0;
          go = 0;
        }
      } /* isOut */
      break;
    default:
      break;
    }
    tool_dump_end(sqlrc, "pgm_ds_run2", i, lvl, key, val);
  }
  return sqlrc;
}


SQLRETURN tool_key_pgm_params_run(tool_key_t * tk, tool_key_pgm_struct_t * tpgm, int isOut, tool_node_t ** curr_node) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  int i = 0;
  int i_end = 0;
  int key = 0;
  char * val = NULL;
  int lvl = 0;
  int max = 0;
  int go = 1;
  int isDs = 0;
  tool_key_conn_struct_t * tconn = tk->tconn;
  tool_node_t * node = *curr_node;
  for (i=0, go = 1, node = node->next; node && sqlrc == SQL_SUCCESS && go; node = node->next, i++) {
    key = node->key;
    val = node->val;
    lvl = node->ord;
    if (!max) {
      max = node->ord;
    }
    if (lvl > max) {
      continue;
    }
    *curr_node = node;
    tool_dump_beg(sqlrc, "pgm_params_run", i, lvl, key, val);
    switch (key) {
    case TOOL400_KEY_DCL_S:
      isDs = 0;
      sqlrc = tool_key_pgm_data_run(tk, tpgm, &isDs, isOut, &node);
      break;
    case TOOL400_KEY_DCL_DS:
      isDs = 0;
      sqlrc = tool_key_pgm_ds_run(tk, tpgm, &isDs, isOut, &node);
      break;
    case TOOL400_KEY_END_PGM:
      go = 0;
    default:
      break;
    }
    tool_dump_end(sqlrc, "pgm_params_run2", i, lvl, key, val);
  }
  return sqlrc;
}

SQLRETURN tool_key_pgm_call_run(tool_key_t * tk, tool_key_pgm_struct_t * tpgm) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  char * pgm_shift_ile = NULL;
  char * pgm_shift_pase = NULL;
  int pgm_shift_len = 0;
  SQLINTEGER pgm_shift_sql_max = 0;
  /* how far? */
  tpgm->layout->step = 0;
  /* last return position */
  if (tpgm->layout->return_start) {
    tpgm->layout->return_end = tpgm->layout->pos;
  }
  /* shift to blob alignment
   * pase -        |pad[0]|pad[1]|pad[2]|pad[3]|...argv...|
   *                                           .
   *                                    ........
   *                                    .
   * blob - |len   |pad[0]|pad[1]|pad[2]|...argv...| 
   */
  tpgm->layout->blob_pad[0] = -1;
  tpgm->layout->blob_pad[1] = -1;
  tpgm->layout->blob_pad[2] = -1;
  pgm_shift_ile = (char *)&tpgm->layout->blob_pad[3];
  pgm_shift_pase = pgm_shift_ile + 4;
  pgm_shift_len = tpgm->layout->max - (pgm_shift_pase - (char *)tpgm->layout);
  memcpy(pgm_shift_ile,pgm_shift_pase,pgm_shift_len);
  /* bind parm */
  pgm_shift_sql_max = tpgm->layout->max;
  sqlrc = SQLBindParameter((SQLHSTMT)tpgm->hstmt,
                           (SQLUSMALLINT) 1,
                           SQL_PARAM_INPUT_OUTPUT,
                           SQL_C_BINARY,
                           SQL_BLOB,
                           tpgm->layout->max,
                           0,
                           (SQLPOINTER)tpgm->layout,
                           0,
                           &pgm_shift_sql_max);
  /* execute */
  if (sqlrc == SQL_SUCCESS) {
    sqlrc = SQLExecute((SQLHSTMT)tpgm->hstmt);
  }
  sqlrc = tool_output_sql_errors(tk->tool, tpgm->hstmt, SQL_HANDLE_STMT, sqlrc, tk->outarea);
  /* shift to pase alignment
   * pase -        |pad[0]|pad[1]|pad[2]|pad[3]|...argv...|
   *                                           .
   *                                    ........
   *                                    .
   * blob - |len   |pad[0]|pad[1]|pad[2]|...argv...| 
   */
  memcpy(pgm_shift_pase,pgm_shift_ile,pgm_shift_len);
  return sqlrc;
}

SQLRETURN tool_key_pgm_run(tool_key_t * tk, tool_node_t ** curr_node) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLRETURN sqlrc1 = SQL_SUCCESS;
  int i = 0;
  int key = 0;
  char * val = NULL;
  int lvl = 0;
  int max = 0;
  int go = 1;
  int step = 0;
  tool_key_conn_struct_t * tconn = tk->tconn;
  tool_node_t * node = *curr_node;
  tool_key_pgm_struct_t * tpgm = (tool_key_pgm_struct_t *) node;
  tool_node_t * pgm_out_idx = node;
  /* ctor */
  tpgm->hstmt = 0;
  tpgm->layout = NULL;
  tpgm->pgm_proc_lib = NULL;
  /* make sp call to ILE blob call wrapper
   * (sp is simple load, activate, call, return)
   * > export TOOLLIB=DB2JSON
   */
  tpgm->pgm_proc_lib = getenv(TOOLLIB);
  if (!tpgm->pgm_proc_lib) {
    tpgm->pgm_proc_lib = ILELIB; /* see ILE_PROC Makefile (iconf.h) */
  }
  tpgm->pgm_ile_name = NULL;
  tpgm->pgm_ile_lib = NULL;
  tpgm->pgm_ile_func = NULL;
  tpgm->pgm_len = 0;
  memset(tpgm->pgm_buff,0,TOOL400_MAX_CMD_BUFF);
  sprintf(tpgm->pgm_buff,"CALL %s.DB2PROC(?)", tpgm->pgm_proc_lib);
  /* pgm name attributes (parser order 1st) */
  for (i=0; i < TOOL400_ATTR_MAX && node->akey[i]; i++) {
    key = node->akey[i];
    val = node->aval[i];
    lvl = node->ord;
    tool_dump_attr(sqlrc, "pgm_run(a)", i, lvl, key, val);
    switch (key) {
    case TOOL400_PGM_NAME:
      tpgm->pgm_ile_name = val;
      break;
    case TOOL400_PGM_LIB:
      tpgm->pgm_ile_lib = val;
      break;
    case TOOL400_PGM_FUNC:
      tpgm->pgm_ile_func = val;
      break;
    default:
      break;
    }
  }
  /* init pgm layout (ebcdic, etc) */
  tool_pgm(tpgm->pgm_ile_name, tpgm->pgm_ile_lib, tpgm->pgm_ile_func, &tpgm->layout);
  /* statement */
  sqlrc = SQLAllocHandle(SQL_HANDLE_STMT, (SQLHDBC) tconn->hdbc, &tpgm->hstmt);
  /* prepare */
  if (sqlrc == SQL_SUCCESS) {
    sqlrc = SQLPrepare((SQLHSTMT)tpgm->hstmt, (SQLCHAR*)tpgm->pgm_buff, (SQLINTEGER)SQL_NTS);
  }
  sqlrc = tool_output_sql_errors(tk->tool, tpgm->hstmt, SQL_HANDLE_STMT, sqlrc, tk->outarea);
  /* call program (step 1-input, step 2-output)*/
  for (step=1; step < 4 && sqlrc == SQL_SUCCESS; step++) {
    node = pgm_out_idx;
    tool_pgm_dump(sqlrc, "pgm_run", step, tpgm);
    switch(step) {
    case 1:
      if (tpgm->pgm_ile_name) {
        tool_output_pgm_beg(tk->tool, tk->outarea, tpgm->pgm_ile_name, tpgm->pgm_ile_lib, tpgm->pgm_ile_func);
      }
      sqlrc = tool_key_pgm_params_run(tk, tpgm, 0, &node);
      break;
    case 2:
      sqlrc = tool_key_pgm_call_run(tk, tpgm);
      break;
    case 3:
      /* reset top of parms */
      ile_pgm_reset_pos(tpgm->layout);
      sqlrc = tool_key_pgm_params_run(tk, tpgm, 1, &node);
      if (tpgm->pgm_ile_name) {
        tool_output_pgm_end(tk->tool, tk->outarea);
      }
      break;
    default:
      break;
    }
    tool_pgm_dump(sqlrc, "pgm_run", step, tpgm);
  }
  if (tpgm->pgm_ile_name && sqlrc != SQL_SUCCESS) {
    tool_output_pgm_end(tk->tool, tk->outarea);
  }
  /* close */
  if (tpgm->hstmt) {
    sqlrc1 = SQLFreeHandle(SQL_HANDLE_STMT, tpgm->hstmt);
  }
  tpgm->hstmt = 0;
  return sqlrc;
}

/* cmd */
SQLRETURN tool_key_cmd_run(tool_key_t * tk, tool_node_t ** curr_node) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLRETURN sqlrc1 = SQL_SUCCESS;
  int i = 0;
  int key = 0;
  char * val = NULL;
  int lvl = 0;
  int max = 0;
  int go = 1;
  char * cmd = NULL;
  tool_key_conn_struct_t * tconn = tk->tconn;
  tool_node_t * node = *curr_node;
  tool_key_cmd_struct_t * tcmd = (tool_key_cmd_struct_t *) node;

  /* ctor */
  tcmd->hstmt = 0;
  tcmd->cmd_len = 0;
  memset(tcmd->cmd_buff,0,sizeof(tcmd->cmd_buff));

  /* cmd attributes (parser order 1st) */
  for (i=0; i < TOOL400_ATTR_MAX && node->akey[i]; i++) {
    key = node->akey[i];
    val = node->aval[i];
    lvl = node->ord;
    tool_dump_attr(sqlrc, "cmd_run(a)", i, lvl, key, val);
    switch (key) {
    case TOOL400_CMD_EXEC:
      cmd = val;
      break;
      break;
    default:
      break;
    }
  }
  /* output */
  tool_output_cmd_beg(tk->tool, tk->outarea, cmd);
  /* sql */
  tcmd->cmd_len = strlen(cmd);
  memset(tcmd->cmd_buff,0,TOOL400_MAX_CMD_BUFF);
  sprintf(tcmd->cmd_buff,"CALL QSYS2.QCMDEXC('%s',%d)", cmd, tcmd->cmd_len);
  /* statement */
  sqlrc = SQLAllocHandle(SQL_HANDLE_STMT, (SQLHDBC) tconn->hdbc, &tcmd->hstmt);
  /* prepare */
  if (sqlrc == SQL_SUCCESS) {
    sqlrc = SQLPrepare((SQLHSTMT)tcmd->hstmt, (SQLCHAR*)tcmd->cmd_buff, (SQLINTEGER)SQL_NTS);
  }
  sqlrc = tool_output_sql_errors(tk->tool, tcmd->hstmt, SQL_HANDLE_STMT, sqlrc, tk->outarea);
  /* execute */
  if (sqlrc == SQL_SUCCESS) {
    sqlrc = SQLExecute((SQLHSTMT)tcmd->hstmt);
  }
  sqlrc = tool_output_sql_errors(tk->tool, tcmd->hstmt, SQL_HANDLE_STMT, sqlrc, tk->outarea);
  /* output */
  tool_output_cmd_end(tk->tool, tk->outarea);
  /* close */
  if (tcmd->hstmt) {
    sqlrc1 = SQLFreeHandle(SQL_HANDLE_STMT, tcmd->hstmt);
  }
  tcmd->hstmt = 0;
  return sqlrc;
}

/* query */
SQLRETURN tool_key_fetch_run(tool_key_t * tk, tool_key_query_struct_t * tqry) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  tool_key_conn_struct_t * tconn = tk->tconn;
  int i = 0;
  /* fetch */
  int fetch_recs = 0;
  SQLSMALLINT fetch_cols = 0;
  SQLSMALLINT fetch_col_name_len = 0;
  SQLCHAR *fetch_col_name[TOOL400_MAX_COLS];
  SQLCHAR *fetch_col_value[TOOL400_MAX_COLS];
  SQLSMALLINT fetch_col_sql_type[TOOL400_MAX_COLS];
  SQLUINTEGER fetch_col_size = 0;
  SQLSMALLINT fetch_col_scale = 0;
  SQLSMALLINT fetch_nullable = 0;
  SQLINTEGER fetch_col_len[TOOL400_MAX_COLS];

  /* result set */
  memset(fetch_col_name, 0, sizeof(fetch_col_name));
  memset(fetch_col_value,0,sizeof(fetch_col_value));
  memset(fetch_col_sql_type,0, sizeof(fetch_col_sql_type));
  memset(fetch_col_len, 0, sizeof(fetch_col_len));
  sqlrc = SQLNumResultCols((SQLHSTMT)tqry->hstmt, 
                           &fetch_cols);
  sqlrc = tool_output_sql_errors(tk->tool, tqry->hstmt, SQL_HANDLE_STMT, sqlrc, tk->outarea);
  /* no records */
  if (fetch_cols < 1) {
    tool_output_record_array_beg(tk->tool, tk->outarea);
    tool_output_record_no_data_found(tk->tool, tk->outarea);
    tool_output_record_array_end(tk->tool, tk->outarea);
    return sqlrc;
  }
  /* SQLDescribeCol */
  for (i = 0 ; i < fetch_cols; i++) {
    fetch_col_size = TOOL400_EXPAND_COL_NAME;
    fetch_col_name[i] = tool_new(fetch_col_size);
    fetch_col_value[i] = NULL;
    fetch_col_sql_type[i] = 0;
    fetch_col_len[i] = SQL_NTS;
    sqlrc = SQLDescribeCol((SQLHSTMT)tqry->hstmt, 
                           (SQLSMALLINT)(i + 1), 
                           (SQLCHAR *)fetch_col_name[i],
                           fetch_col_size,
                           &fetch_col_name_len, 
                           &fetch_col_sql_type[i],
                           &fetch_col_size,
                           &fetch_col_scale,
                           &fetch_nullable);
    /* dbcs expansion */
    switch (fetch_col_sql_type[i]) {
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
      fetch_col_size = fetch_col_size * TOOL400_EXPAND_CHAR;
      fetch_col_value[i] = tool_new(fetch_col_size);
      sqlrc = SQLBindCol((SQLHSTMT)tqry->hstmt,
                         (i + 1),
                         SQL_CHAR, 
                         fetch_col_value[i],
                         fetch_col_size,
                         &fetch_col_len[i]);
      break;
    case SQL_BINARY:
    case SQL_VARBINARY:
    case SQL_BLOB:
      fetch_col_size = fetch_col_size * TOOL400_EXPAND_BINARY;
      fetch_col_value[i] = tool_new(fetch_col_size);
      sqlrc = SQLBindCol((SQLHSTMT)tqry->hstmt,
                         (i + 1),
                         SQL_CHAR, 
                         fetch_col_value[i],
                         fetch_col_size,
                         &fetch_col_len[i]);
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
      fetch_col_size = TOOL400_EXPAND_OTHER;
      fetch_col_value[i] = tool_new(fetch_col_size);
      sqlrc = SQLBindCol((SQLHSTMT)tqry->hstmt,
                         (i + 1),
                         SQL_CHAR, 
                         fetch_col_value[i],
                         fetch_col_size,
                         &fetch_col_len[i]);
      break;
    }
  } /* SQLDescribeCol loop */
  /* fetch */
  sqlrc = SQL_SUCCESS;
  tool_output_record_array_beg(tk->tool, tk->outarea);
  while (sqlrc == SQL_SUCCESS) {
    sqlrc = SQLFetch(tqry->hstmt);
    if (sqlrc == SQL_NO_DATA_FOUND || sqlrc < SQL_SUCCESS ) {
      if (!fetch_recs) {
        tool_output_record_no_data_found(tk->tool, tk->outarea);
      } else {
        sqlrc = SQL_SUCCESS;
      }
      break;
    }
    tool_output_record_row_beg(tk->tool, tk->outarea);
    fetch_recs += 1;
    for (i = 0 ; i < fetch_cols; i++) {
      if (fetch_col_value[i]) {
        tool_output_record_name_value(tk->tool, fetch_col_name[i], fetch_col_value[i], fetch_col_sql_type[i], fetch_col_len[i], tk->outarea);
      }
    }
    tool_output_record_row_end(tk->tool, tk->outarea);
  } /* fetch loop */
  tool_output_record_array_end(tk->tool, tk->outarea);
  /* clean up col names */
  for (i = 0 ; i < fetch_cols; i++) {
    if (fetch_col_value[i]) {
      tool_free(fetch_col_name[i]);
      fetch_col_name[i] = NULL;
    }
    if (fetch_col_name[i]) {
      tool_free(fetch_col_name[i]);
      fetch_col_name[i] = NULL;
    }
  } /* name dtor loop */
  return sqlrc;
}

SQLRETURN tool_key_query_run(tool_key_t * tk, tool_node_t ** curr_node) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLRETURN sqlrc1 = SQL_SUCCESS;
  int i = 0;
  int j = 0;
  int key = 0;
  char * val = NULL;
  int lvl = 0;
  int max = 0;
  int go = 1;
  tool_key_conn_struct_t * tconn = tk->tconn;
  tool_node_t * node = *curr_node;
  tool_key_query_struct_t * tqry = (tool_key_query_struct_t *) node;
  tool_node_t * node_next = NULL;
  /* query */
  SQLCHAR * query = NULL;
  SQLCHAR * query_val = NULL;
  SQLCHAR * query_fetch = NULL;
  SQLSMALLINT parm_max = 0;
  SQLSMALLINT parm_cnt = 0;
  SQLINTEGER parm_len[TOOL400_MAX_COLS];
  SQLSMALLINT parm_scale = 0;
  SQLUINTEGER parm_precision = 0;
  SQLSMALLINT parm_data_type = 0;
  SQLSMALLINT parm_nullable = 0;

  /* query attributes (parser order 1st) */
  for (i=0; i < TOOL400_ATTR_MAX && node->akey[i]; i++) {
    key = node->akey[i];
    val = node->aval[i];
    lvl = node->ord;
    tool_dump_beg(sqlrc, "query_run(a)", i, lvl, key, val);
    switch (key) {
    case TOOL400_QUERY_STMT:
      query = val;
      break;
    default:
      break;
    }
    tool_dump_end(sqlrc, "query_run2(a)", i, lvl, key, val);
  }
  /* no query */
  if (!query) {
    return sqlrc;
  }
  /* output */
  tool_output_query_beg(tk->tool, tk->outarea, query);  
  /* statement */
  sqlrc = SQLAllocHandle(SQL_HANDLE_STMT, (SQLHDBC) tconn->hdbc, &tqry->hstmt);
  /* prepare */
  if (sqlrc == SQL_SUCCESS) {
    sqlrc = SQLPrepare((SQLHSTMT)tqry->hstmt, (SQLCHAR*)query, (SQLINTEGER)SQL_NTS);
  }
  sqlrc = tool_output_sql_errors(tk->tool, tqry->hstmt, SQL_HANDLE_STMT, sqlrc, tk->outarea);

  /* parms? */
  memset(parm_len, 0, sizeof(parm_len));
  if (tqry->hstmt) {
    sqlrc = SQLNumParams((SQLHSTMT)tqry->hstmt, (SQLSMALLINT*)&parm_max);
  }
  sqlrc = tool_output_sql_errors(tk->tool, tqry->hstmt, SQL_HANDLE_STMT, sqlrc, tk->outarea);
  /* query parms */
  if (!node_next) {
    node_next = node->next;
  }
  for (i=0, go = 1, node = node_next, node_next = NULL; node && sqlrc == SQL_SUCCESS && go; node = node->next, i++) {
    key = node->key;
    val = node->val;
    lvl = node->ord;
    if (!max) {
      max = node->ord;
    }
    if (lvl > max) {
      continue;
    }
    *curr_node = node;
    tool_dump_beg(sqlrc, "query_parm", i, lvl, key, val);
    switch (key) {
    case TOOL400_KEY_PARM:
      /* query parm attributes (parser order 1st) */
      for (j=0, query_val = NULL; j < TOOL400_ATTR_MAX && node->akey[j]; j++) {
        key = node->akey[j];
        val = node->aval[j];
        lvl = node->ord;
        tool_dump_beg(sqlrc, "query_parm(a)", j, lvl, key, val);
        switch (key) {
        case TOOL400_PARM_VALUE:
          query_val = val;
          break;
        default:
          break;
        }
        tool_dump_end(sqlrc, "query_parm2(a)", j, lvl, key, val);
      }
      if (query_val && parm_cnt <= parm_max) {
        sqlrc = SQLDescribeParam((SQLHSTMT)tqry->hstmt, 
                (SQLUSMALLINT)parm_cnt + 1, /* running count */
                &parm_data_type, 
                &parm_precision,
                &parm_scale,
                &parm_nullable);
        parm_len[parm_cnt] = SQL_NTS;
        sqlrc = SQLBindParameter((SQLHSTMT)tqry->hstmt,
                (SQLUSMALLINT)parm_cnt + 1,
                SQL_PARAM_INPUT,
                SQL_CHAR,
                parm_data_type,
                parm_precision,
                parm_scale,
                query_val, /* input value */
                0,
                &parm_len[parm_cnt] /* in/out length (above) */
                );
        parm_cnt++;
      }
      break;
    case TOOL400_KEY_END_PARM:
      node_next = (tool_node_t *)node->next;
      if (!node_next || node_next->key != TOOL400_KEY_PARM) {
        go = 0;
      }
      break;
    default:
      break;
    }
    tool_dump_end(sqlrc, "query_parm_end", i, lvl, key, val);
  }
  /* parms error */
  if (sqlrc == SQL_ERROR) {
    /* output */
    tool_output_query_end(tk->tool, tk->outarea);  
    return sqlrc;
  }

  /* execute */
  if (sqlrc == SQL_SUCCESS) {
    sqlrc = SQLExecute((SQLHSTMT)tqry->hstmt);
  }
  sqlrc = tool_output_sql_errors(tk->tool, tqry->hstmt, SQL_HANDLE_STMT, sqlrc, tk->outarea);
  /* execute error */
  if (sqlrc == SQL_ERROR) {
    /* output */
    tool_output_query_end(tk->tool, tk->outarea);  
    return sqlrc;
  }

  /* query children (parser order next) */
  if (!node_next) {
    node_next = node->next;
  }
  for (i=0, go = 1, node = node_next, node_next = NULL; node && sqlrc == SQL_SUCCESS && go; node = node->next, i++) {
    key = node->key;
    val = node->val;
    lvl = node->ord;
    if (!max) {
      max = node->ord;
    }
    if (lvl > max) {
      continue;
    }
    *curr_node = node;
    tool_dump_beg(sqlrc, "query_fetch", i, lvl, key, val);
    switch (key) {
    case TOOL400_KEY_FETCH:
      /* query parm attributes (parser order 1st) */
      for (j=0, query_fetch = NULL; j < TOOL400_ATTR_MAX && node->akey[j]; j++) {
        key = node->akey[j];
        val = node->aval[j];
        lvl = node->ord;
        tool_dump_beg(sqlrc, "query_fetch(a)", j, lvl, key, val);
        switch (key) {
        case TOOL400_FETCH_REC:
          query_fetch = val;
          break;
        default:
          break;
        }
        tool_dump_end(sqlrc, "query_fetch(a)", j, lvl, key, val);
      }
      /* fetch not complete */
      if (query_fetch) {
        sqlrc = tool_key_fetch_run(tk, tqry);
      }
      break;
    case TOOL400_KEY_END_FETCH:
      node_next = (tool_node_t *)node->next;
      if (!node_next || node_next->key != TOOL400_KEY_FETCH) {
        go = 0;
      }
      break;
    default:
      break;
    }
    tool_dump_end(sqlrc, "query_fetch_end", i, lvl, key, val);
  }
  /* output */
  tool_output_query_end(tk->tool, tk->outarea);  
  /* close */
  if (tqry->hstmt) {
    sqlrc1 = SQLFreeHandle(SQL_HANDLE_STMT, tqry->hstmt);
    tqry->hstmt = 0;
  }
  return sqlrc;
}

/* connection */
SQLRETURN tool_key_conn_joblog(tool_key_t * tk, SQLHANDLE hdbc) {
  /*
  *sort time descend (new entries first)
  */
  char * hostSql = "select\
  message_id as msgid,\
  message_type as msgtype,\
  message_subtype as msgsub,\
  severity as msgsev,\
  cast(message_timestamp as varchar(26)) as msgstamp,\
  to_library as msgtolib,\
  to_program as msgtopgm,\
  to_module as msgtomod,\
  cast(to_procedure as varchar(128)) as msgtoproc,\
  to_instruction as msgtoinst,\
  cast(message_text as varchar(200) ccsid 37) as msgtxt\
  from table(qsys2.joblog_info('*')) a\
  where severity >= 20 order by msgstamp DESC";
  int j = 0;
  int rec = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLRETURN sql_exec_rc = SQL_SUCCESS;
  SQLHANDLE hstmt = 0;
  SQLSMALLINT nResultCols = 0;
  SQLCHAR buff_name[TOOL400_JOBLOG_MAX_COLS][TOOL400_JOBLOG_MAX_SIZE];
  SQLCHAR buff_value[TOOL400_JOBLOG_MAX_COLS][TOOL400_JOBLOG_MAX_SIZE];
  SQLINTEGER buff_len[TOOL400_JOBLOG_MAX_COLS];
  SQLSMALLINT buff_type[TOOL400_JOBLOG_MAX_COLS];
  SQLINTEGER fStrLen[TOOL400_JOBLOG_MAX_COLS];
  SQLSMALLINT name_length = 0;
  SQLSMALLINT type = 0;
  SQLINTEGER size = 0;
  SQLSMALLINT scale = 0;
  SQLSMALLINT nullable = 0;

  /* output */
  tool_output_joblog_beg(tk->tool, tk->outarea);
  /* statement */
  sqlrc = SQLAllocHandle(SQL_HANDLE_STMT, (SQLHDBC) hdbc, &hstmt);
  /* prepare */
  sqlrc = SQLPrepare((SQLHSTMT)hstmt, (SQLPOINTER)hostSql, (SQLINTEGER)SQL_NTS);
  /* execute */
  sqlrc = SQLExecute((SQLHSTMT)hstmt);
  sql_exec_rc = sqlrc;
  /* result set */
  sqlrc = SQLNumResultCols((SQLHSTMT)hstmt, &nResultCols);
  if (nResultCols > 0) {
    for (j = 0 ; j < nResultCols; j++) {
      size = TOOL400_JOBLOG_MAX_SIZE;
      memset(buff_name[j],0,TOOL400_JOBLOG_MAX_SIZE);
      memset(buff_value[j],0,TOOL400_JOBLOG_MAX_SIZE);
      buff_type[j] = 0;
      fStrLen[j] = SQL_NTS;
      sqlrc = SQLDescribeCol((SQLHSTMT)hstmt, (SQLSMALLINT)(j + 1), (SQLCHAR *)buff_name[j], size, &name_length, &buff_type[j], &size, &scale, &nullable);
      sqlrc = SQLBindCol((SQLHSTMT)hstmt, (j + 1), SQL_CHAR, buff_value[j], size, &fStrLen[j]);
    }
    sqlrc = SQL_SUCCESS;
    while (sqlrc == SQL_SUCCESS) {
      sqlrc = SQLFetch(hstmt);
      if ( sqlrc == SQL_NO_DATA_FOUND || sqlrc < SQL_SUCCESS ) {
        break;
      }
      tool_output_joblog_rec(tk->tool, tk->outarea,
        buff_value[0],
        buff_value[1],
        buff_value[2],
        buff_value[3],
        buff_value[4],
        buff_value[5],
        buff_value[6],
        buff_value[7],
        buff_value[8],
        buff_value[9],
        buff_value[10]);
      rec++;
      if (rec > TOOL400_JOBLOG_MAX_REC) {
        break;
      }
    }
  } else {
    sql_exec_rc = -1;
  }
  /* close */
  sqlrc = SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
  /* output */
  tool_output_joblog_end(tk->tool, tk->outarea);

 return sql_exec_rc;
}

SQLRETURN tool_key_conn_run(tool_key_t * tk, tool_node_t ** curr_node) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  int i = 0;
  int key = 0;
  char * val = NULL;
  int lvl = 0;
  int max = 0;
  int go = 1;
  tool_node_t * node = *curr_node;
  tool_key_conn_struct_t * tconn = (tool_key_conn_struct_t *) node;
  /* ctor */
  if (!tconn->conn_type) {
    tconn->hdbc = tk->hdbc;
    if (tconn->hdbc) {
      tconn->presistent = 1;
    } else {
      tconn->presistent = 0;
    }
    key = node->key;
    switch (key) {
    case TOOL400_KEY_CONN:
      tconn->conn_type = 1;
      break;
    default:
      tconn->conn_type = 3;
      break;
    }
    tconn->conn_db = NULL;
    tconn->conn_uid = NULL;
    tconn->conn_pwd = NULL;
    tconn->conn_qual = NULL;
    tconn->conn_commit = SQL_TXN_NO_COMMIT;
    tconn->conn_libl = NULL;
    tconn->conn_curlib = NULL;
  }
  /* connection in toolkit */
  tk->tconn = tconn;
  /* user request connection? */
  if (!tconn->hdbc) {
    /* connect attributes (parser order 1st) */
    for (i=0; i < TOOL400_ATTR_MAX && node->akey[i]; i++) {
      key = node->akey[i];
      val = node->aval[i];
      lvl = node->ord;
      tool_dump_attr(sqlrc, "conn_run(a)", i, lvl, key, val);
      switch (key) {
      case TOOL400_CONN_DB:
        tconn->conn_db = val;
        break;
      case TOOL400_CONN_UID:
        tconn->conn_uid = val;
        break;
      case TOOL400_CONN_PWD:
        tconn->conn_pwd = val;
        break;
      case TOOL400_CONN_LIBL:
        tconn->conn_libl = val;
        break;
      case TOOL400_CONN_CURLIB:
        tconn->conn_curlib = val;
        break;
      case TOOL400_CONN_QUAL:
        tconn->conn_qual = val;
        tconn->conn_type = 2;
        tconn->presistent = 1;
        break;
      case TOOL400_CONN_ISOLATION:
        if (strcmp(val,"nc")) {
          tconn->conn_commit = SQL_TXN_NO_COMMIT;
        } else
        if (strcmp(val,"uc")) {
          tconn->conn_commit = SQL_TXN_READ_UNCOMMITTED;
        } else
        if (strcmp(val,"cs")) {
          tconn->conn_commit = SQL_TXN_READ_COMMITTED;
        } else
        if (strcmp(val,"rr")) {
          tconn->conn_commit = SQL_TXN_REPEATABLE_READ;
        } else
        if (strcmp(val,"rs")) {
          tconn->conn_commit = SQL_TXN_SERIALIZABLE;
        } else {
          tconn->conn_commit = SQL_TXN_NO_COMMIT;
        }
        break;
      default:
        go = 0;
        *curr_node = node;
        break;
      }
    }
    /* connect */
    if (tconn->presistent) {
      sqlrc = SQL400pConnect( tconn->conn_db, tconn->conn_uid, tconn->conn_pwd, tconn->conn_qual, &tconn->hdbc, tconn->conn_commit, tconn->conn_libl, tconn->conn_curlib );
    } else {
      sqlrc = SQL400Connect( tconn->conn_db, tconn->conn_uid, tconn->conn_pwd, &tconn->hdbc, tconn->conn_commit, tconn->conn_libl, tconn->conn_curlib );
    }
    sqlrc = tool_output_sql_errors(tk->tool, tconn->hdbc, SQL_HANDLE_DBC, sqlrc, tk->outarea);
  } /* !tconn->hdbc */
  /* connect children (parser order next) */
  for (i=0, go = 1, node = node->next; node && sqlrc == SQL_SUCCESS && go; node = node->next, i++) {
    key = node->key;
    val = node->val;
    lvl = node->ord;
    if (!max) {
      max = node->ord;
    }
    if (lvl > max) {
      continue;
    }
    *curr_node = node;
    /* top level */
    tool_dump_beg(sqlrc, "conn_run", i, lvl, key, val);
    switch (key) {
    case TOOL400_KEY_QUERY:
      sqlrc = tool_key_query_run(tk, &node);
      break;
    case TOOL400_KEY_CMD:
      sqlrc = tool_key_cmd_run(tk, &node);
      break;
    case TOOL400_KEY_PGM:
      sqlrc = tool_key_pgm_run(tk, &node);
      break;
    case TOOL400_KEY_END_CONN:
      go = 0;
      break;
    default:
      break;
    }
    tool_dump_end(sqlrc, "conn_run2", i, lvl, key, val);
    /* joblog info */
    if (sqlrc == SQL_ERROR) {
      tool_key_conn_joblog(tk, tconn->hdbc);
    }
  }
  /* hdbc external (caller?) or pool (pConnect) */
  if (tconn->hdbc && !tconn->presistent) {
    sqlrc = SQL400Close(tconn->hdbc);
  }
  return sqlrc;
}

/* toolkit */
tool_key_t * tk_ctor(int hdbc, char * outarea, int outlen, tool_struct_t *tool) {
  tool_key_t * tk = (tool_key_t *) tool_new(sizeof(tool_key_t));
  tk->hdbc = hdbc;
  tk->outarea = outarea;
  tk->outlen = outlen;
  tk->tool = tool;
  tk->tconn = (tool_key_conn_struct_t *) tool_node_first(tool);
  return tk;
} 
void tk_dtor(tool_key_t * tk) {
  tool_free((char *)tk);
}
int tool_run(int hdbc, char * outarea, int outlen, tool_struct_t *tool) 
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int i = 0;
  int key = 0;
  char * val = NULL;
  int lvl = 0;
  int max = 0;
  tool_key_t * tk = NULL;
  tool_node_t * node = NULL;
  /* ctor */
  tk = tk_ctor(hdbc, outarea, outlen, tool);
  tool_graph(sqlrc, "tool_graph", tk);
  /* output start script */
  tool_output_script_beg(tk->tool, tk->outarea);
  /* top level */
  for (i=0, node = tool->first; node && sqlrc == SQL_SUCCESS; node = node->next, i++) {
    key = node->key;
    val = node->val;
    lvl = node->ord;
    tool_dump_beg(sqlrc, "tool_run", i, lvl, key, val);
    switch (key) {
    case TOOL400_KEY_CONN:
      sqlrc = tool_key_conn_run(tk, &node);
      break;
    default:
      break;
    }
    tool_dump_end(sqlrc, "tool_run2", i, lvl, key, val);
  }
  /* output end script */
  tool_output_script_end(tk->tool, tk->outarea);
  /* dtor */
  tk_dtor(tk);
  return sqlrc;
}

