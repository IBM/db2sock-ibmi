#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iconv.h>
#include <stdarg.h>
#ifdef __IBMC__
#include <sqlcli.h>
#include "PaseType.h"
#else
#include <sqlcli1.h>
#include <as400_types.h>
#include <as400_protos.h>
#include "PaseCliInit.h"
#include "PaseCliAsync.h"
#include "PaseCliDev.h"
#include "PaseCliPrintf.h"
#endif
#include "../ILE-PROC/iconf.h" /* see ILE-PROC/Makefile */
#include "PaseToIle.h"
#include "PaseToDmp.h"
#include "PaseTool.h"

/*=================================================
 * toolkit prototypes
 */
SQLRETURN tool_key_pgm_data_run(tool_struct_t * tool, tool_key_pgm_struct_t * tpgm, int * isDs, int isOut, tool_node_t ** curr_node);
SQLRETURN tool_key_pgm_ds_run(tool_struct_t * tool, tool_key_pgm_struct_t * tpgm, int * isDs, int isOut, tool_node_t ** curr_node);


/*=================================================
 * ebcdic char ccsid mess
 */
#ifdef __IBMC__
char ccsid_variant_bang() {
  /* '!' */
  return ccsid_bang();
}
char ccsid_variant_pound() {
  /* '#' */
  return ccsid_pound();
}

char ccsid_variant_dollar() {
  /* '$' */
  return ccsid_dollar();
}

char ccsid_variant_at() {
  /* '@' */
  return ccsid_at();
}

char ccsid_variant_backslash() {
  /* '\' */
  return ccsid_backslash();
}

char ccsid_variant_open_brace() {
  /* '[' */
  return ccsid_open_brace();
}

char ccsid_variant_close_brace() {
  /* ']' */
  return ccsid_close_brace();
}

char ccsid_variant_caret() {
  /* '^' */
  return ccsid_caret();
}

char ccsid_variant_backtick() {
  /* '`' */
  return ccsid_backtick();
}

char ccsid_variant_open_bracket() {
  /* '{' */
  return ccsid_open_bracket();
}

char ccsid_variant_close_bracket() {
  /* '}' */
  return ccsid_close_bracket();
}

char ccsid_variant_bar() {
  /* '|' */
  return ccsid_bar();
}

char ccsid_variant_tilde() {
  /* '~' */
  return ccsid_tilde();
}
#else
char ccsid_variant_bang() {
  return '!';
}
char ccsid_variant_pound() {
  return '#';
}

char ccsid_variant_dollar() {
  return '$';
}

char ccsid_variant_at() {
  return '@';
}

char ccsid_variant_backslash() {
  return '\\';
}

char ccsid_variant_open_brace() {
  return '[';
}

char ccsid_variant_close_brace() {
  return ']';
}

char ccsid_variant_caret() {
  return '^';
}

char ccsid_variant_backtick() {
  return '`';
}

char ccsid_variant_open_bracket() {
  return '{';
}

char ccsid_variant_close_bracket() {
  return '}';
}

char ccsid_variant_bar() {
  return '|';
}

char ccsid_variant_tilde() {
  return '~';
}
#endif

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
  output_pgm_dcl_ds_rec_beg_t output_pgm_dcl_ds_rec_beg,
  output_pgm_dcl_ds_rec_end_t output_pgm_dcl_ds_rec_end,
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
  tool->output_pgm_dcl_ds_rec_beg = output_pgm_dcl_ds_rec_beg;
  tool->output_pgm_dcl_ds_rec_end = output_pgm_dcl_ds_rec_end;
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
  tool->last = NULL;
  tool->tconn = NULL;
  tool->outarea = NULL;
  tool->outareaLen = 0;
  tool->outmax = 0;
  tool->outlen = 0;
  tool->hdbc = 0;
  tool->sqlCode = 0;
  return tool;
}

void tool_dtor(tool_struct_t *tool){
  tool_node_t * node = NULL;
  for (node = tool->last; node; node = node->prev) {
    tool_free((char *)node);
  }
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
    size = sizeof(tool_key_data_struct_t);
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
    node_cur = tool_node_add(tool, key, NULL, node_beg->ord); /* was node->ord */
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

tool_node_t * tool_node_find_s_dou_name(tool_struct_t * tool, char * s_dou_name, char * search) {
  char * search_default = "-+";
  int i = 0;
  char * c = NULL;
  tool_node_t * node = NULL;
  /* search pattern */
  if (search) {
    c = search;
  } else {
    c = search_default;
  }
  for (;*c; c++) {
    switch (*c) {
    /* backward search TOOL400_S_NAME */
    case '-':
      for (node = tool->curr; node; node = node->prev) {
        if (node->key == TOOL400_KEY_DCL_S) {
          for (i=0;i<TOOL400_ATTR_MAX;i++) {
            if (node->akey[i] == TOOL400_S_NAME && !strcmp(node->aval[i],s_dou_name)) {
              return node;
            }
          }
        }
      }
      break;
    /* forward search TOOL400_S_NAME */
    case '+':
      for (node = tool->curr; node; node = node->next) {
        if (node->key == TOOL400_KEY_DCL_S) {
          for (i=0;i<TOOL400_ATTR_MAX;i++) {
            if (node->akey[i] == TOOL400_S_NAME && !strcmp(node->aval[i],s_dou_name)) {
              return node;
            }
          }
        }
      }
      break;
    }
  }
  return node;
}


/*=================================================
 * toolkit callback output format
 */

void tool_output_script_beg(tool_struct_t *tool) {
  tool->outareaLen = tool->output_script_beg(tool->curr, tool->outarea, tool->outareaLen);
}
void tool_output_script_end(tool_struct_t *tool) {
  tool->outareaLen = tool->output_script_end(tool->curr, tool->outarea, tool->outareaLen);
}
void tool_output_query_beg(tool_struct_t *tool, char *query) {
  tool->outareaLen = tool->output_query_beg(tool->curr, tool->outarea, tool->outareaLen, query);
}
void tool_output_query_end(tool_struct_t *tool) {
  tool->outareaLen = tool->output_query_end(tool->curr, tool->outarea, tool->outareaLen);
}
void tool_output_record_array_beg(tool_struct_t *tool) {
  tool->outareaLen = tool->output_record_array_beg(tool->curr, tool->outarea, tool->outareaLen);
}
void tool_output_record_array_end(tool_struct_t *tool) {
  tool->outareaLen = tool->output_record_array_end(tool->curr, tool->outarea, tool->outareaLen);
}
void tool_output_record_no_data_found(tool_struct_t *tool) {
  tool->outareaLen = tool->output_record_no_data_found(tool->curr, tool->outarea, tool->outareaLen);
}
void tool_output_record_row_beg(tool_struct_t *tool) {
  tool->outareaLen = tool->output_record_row_beg(tool->curr, tool->outarea, tool->outareaLen);
}
void tool_output_record_name_value(tool_struct_t *tool, char *name, char *value, int type, int fStrLen) {
  if (fStrLen == SQL_NULL_DATA) {
    fStrLen = TOOL400_DATA_IS_NULL;
  }
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
    type = TOOL400_DATA_TYPE_NBR;
    break;
  default:
    type = TOOL400_DATA_TYPE_CHAR;
    break;
  }
  tool->outareaLen = tool->output_record_name_value(tool->curr, tool->outarea, tool->outareaLen, name, value, type, fStrLen);
}
void tool_output_record_row_end(tool_struct_t *tool) {
  tool->outareaLen = tool->output_record_row_end(tool->curr, tool->outarea, tool->outareaLen);
}
void tool_output_sql_errors(tool_struct_t *tool, int rc, int sqlCode, char * sqlState, char *sqlMsg)
{
  tool->outareaLen = tool->output_sql_errors(tool->curr, tool->outarea, tool->outareaLen, rc, sqlCode, sqlState, sqlMsg);
}
void tool_output_pgm_beg(tool_struct_t *tool, char * name, char * lib, char * func) {
  tool->outareaLen = tool->output_pgm_beg(tool->curr, tool->outarea, tool->outareaLen, name, lib, func);
}
void tool_output_pgm_end(tool_struct_t *tool) {
  tool->outareaLen = tool->output_pgm_end(tool->curr, tool->outarea, tool->outareaLen);
}
void tool_output_pgm_dcl_s_beg(tool_struct_t *tool, char * name, int tdim) {
  if (!tool->outhold) {
    tool->outareaLen = tool->output_pgm_dcl_s_beg(tool->curr, tool->outarea, tool->outareaLen, name, tdim);
  }
}
void tool_output_pgm_dcl_s_data(tool_struct_t *tool, char *value, int numFlag) {
  if (!tool->outhold) {
    tool->outareaLen = tool->output_pgm_dcl_s_data(tool->curr, tool->outarea, tool->outareaLen, value, numFlag);
  }
}
void tool_output_pgm_dcl_s_end(tool_struct_t *tool, int tdim) {
  if (!tool->outhold) {
    tool->outareaLen = tool->output_pgm_dcl_s_end(tool->curr, tool->outarea, tool->outareaLen, tdim);
  }
}
void tool_output_pgm_dcl_ds_beg(tool_struct_t *tool, char * name, int tdim) {
  if (!tool->outhold) {
    tool->outareaLen = tool->output_pgm_dcl_ds_beg(tool->curr, tool->outarea, tool->outareaLen, name, tdim);
  }
}
void tool_output_pgm_dcl_ds_rec_beg(tool_struct_t *tool) {
  if (!tool->outhold) {
    tool->outareaLen = tool->output_pgm_dcl_ds_rec_beg(tool->curr, tool->outarea, tool->outareaLen);
  }
}
void tool_output_pgm_dcl_ds_rec_end(tool_struct_t *tool) {
  if (!tool->outhold) {
    tool->outareaLen = tool->output_pgm_dcl_ds_rec_end(tool->curr, tool->outarea, tool->outareaLen);
  }
}
void tool_output_pgm_dcl_ds_end(tool_struct_t *tool, int tdim) {
  if (!tool->outhold) {
    tool->outareaLen = tool->output_pgm_dcl_ds_end(tool->curr, tool->outarea, tool->outareaLen, tdim);
  }
}
void tool_output_cmd_beg(tool_struct_t *tool, char * cmd) {
  tool->outareaLen = tool->output_cmd_beg(tool->curr, tool->outarea, tool->outareaLen, cmd);
}
void tool_output_cmd_end(tool_struct_t *tool) {
  tool->outareaLen = tool->output_cmd_end(tool->curr, tool->outarea, tool->outareaLen);
}

void tool_output_joblog_beg(tool_struct_t *tool) {
  tool->outareaLen = tool->output_joblog_beg(tool->curr, tool->outarea, tool->outareaLen);
}
void tool_output_joblog_rec(tool_struct_t *tool, char * msgid, char * msgtype, char * msgsub, char * msgsev, char * msgstamp, char * msgtolib, char * msgtopgm, char * msgtomod, char * msgtoproc, char * msgtoinst, char * msgtxt) {
  tool->outareaLen = tool->output_joblog_rec(tool->curr, tool->outarea, tool->outareaLen, msgid,msgtype,msgsub, msgsev, msgstamp, msgtolib, msgtopgm, msgtomod, msgtoproc, msgtoinst, msgtxt);
}
void tool_output_joblog_end(tool_struct_t *tool) {
  tool->outareaLen = tool->output_joblog_end(tool->curr, tool->outarea, tool->outareaLen);
}


/* "pgm":["NAME","LIB","procedure"], */
SQLRETURN tool_pgm(char *pgm, char *lib, char * func, char * debug, ile_pgm_call_t **playout) {
  ile_pgm_call_t * layout = *playout;
  int rc = 0;

  /* grow template (if need) */
  layout = ile_pgm_grow(playout, ILE_PGM_ALLOC_BLOCK);

  /* copy ebcdic */
  rc = ile_pgm_str_2_char((char *)&layout->pgm, pgm, 1, sizeof(layout->pgm), 0, 0);
  ile_pgm_trim_ebcdic((char *)&layout->pgm, sizeof(layout->pgm));
  rc = ile_pgm_str_2_char((char *)&layout->lib, lib, 1, sizeof(layout->lib), 0, 0);
  ile_pgm_trim_ebcdic((char *)&layout->lib, sizeof(layout->lib));
  rc = ile_pgm_str_2_char((char *)&layout->func, func, 1, sizeof(layout->func), 0, 0);
  ile_pgm_trim_ebcdic((char *)&layout->func, sizeof(layout->func));
  rc = ile_pgm_str_2_char((char *)&layout->debug, debug, 1, sizeof(layout->debug), 0, 0);
  ile_pgm_trim_ebcdic((char *)&layout->debug, sizeof(layout->debug));

  /* layout return */
  *playout = layout;
}

/* "dcl-s":["name","type", value, dimension, "in|out|both|value|const|return"], */
SQLRETURN tool_dcl_s(tool_struct_t *tool, 
int isOut, 
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

  int pase_sig = 0;
  tool_key_data_struct_t * node = NULL;

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
  by = ile_pgm_by(in_by, typ, tlen, tdim, tvary, isDs, &spill_len, &pase_sig);
  if (!isOut && spill_len) {
    /* grow template (if need) */
    layout = ile_pgm_grow(playout, spill_len);
  }

  /* location of parm or ds data */
  where = ile_pgm_parm_location(isOut, by, pase_sig, spill_len, layout);
  if (!where) {
    return SQL_ERROR;
  }

  /* output processing */
  if (isOut) {
    tool_output_pgm_dcl_s_beg(tool, in_name, tdim);
  }

  /* dcl-s type */
  switch (typ) {
  case 'i':
    switch (tlen) {
    case 3:
      if (isOut) {
        rc = ile_pgm_int8_2_output(tool, where, tdim);
      } else {
        rc = ile_pgm_str_2_int8(where, in_value, tdim);
      }
      break;
    case 5:
      if (isOut) {
        rc = ile_pgm_int16_2_output(tool, where, tdim);
      } else {
        rc = ile_pgm_str_2_int16(where, in_value, tdim);
      }
      break;
    case 10:
      if (isOut) {
        rc = ile_pgm_int32_2_output(tool, where, tdim);
      } else {
        rc = ile_pgm_str_2_int32(where, in_value, tdim);
      }
      break;
    case 20:
      if (isOut) {
        rc = ile_pgm_int64_2_output(tool, where, tdim);
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
        rc = ile_pgm_uint8_2_output(tool, where, tdim);
      } else {
        rc = ile_pgm_str_2_uint8(where, in_value, tdim);
      }
      break;
    case 5:
      if (isOut) {
        rc = ile_pgm_uint16_2_output(tool, where, tdim);
      } else {
        rc = ile_pgm_str_2_uint16(where, in_value, tdim);
      }
      break;
    case 10:
      if (isOut) {
        rc = ile_pgm_uint32_2_output(tool, where, tdim);
      } else {
        rc = ile_pgm_str_2_uint32(where, in_value, tdim);
      }
      break;
    case 20:
      if (isOut) {
        rc = ile_pgm_uint64_2_output(tool, where, tdim);
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
        rc = ile_pgm_float_2_output(tool, where, tscale, tdim);
      } else {
        rc = ile_pgm_str_2_float(where, in_value, tdim);
      }
      break;
    case 8:
      if (isOut) {
        rc = ile_pgm_double_2_output(tool, where, tscale, tdim);
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
      ile_pgm_packed_2_output(tool, where, tlen, tscale, tdim);
    } else {
      rc = ile_pgm_str_2_packed(where, in_value, tdim, tlen, tscale);
    }
    break;
  case 's':
    if (isOut) {
      ile_pgm_zoned_2_output(tool, where, tlen, tscale, tdim);
    } else {
      rc = ile_pgm_str_2_zoned(where, in_value, tdim, tlen, tscale);
    }
    break;
  case 'a':
    if (isOut) {
      ile_pgm_char_2_output(tool, where, tlen, tvary, tccsid, tdim);
    } else {
      rc = ile_pgm_str_2_char(where, in_value, tdim, tlen, tvary, tccsid);
    }
    break;
  case 'b':
    if (isOut) {
      ile_pgm_bin_2_output(tool, where, tlen, tvary, tdim);
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
  if (!isOut) {
    node = (tool_key_data_struct_t *) tool->curr;
    node->typ = typ;
    node->tlen = tlen;
    node->tscale = tscale;
    node->tvary = tvary;
    node->tdim = tdim;
    node->tccsid = tccsid;
    node->spill_len = spill_len;
    node->by = by;
    node->offset = where - (char *)layout;
  /* output processing */
  } else {
    tool_output_pgm_dcl_s_end(tool, tdim);
  }
  return rc;
}

/* int value from 'anything' */
int tool_dcl_s_2_int(
char typ,
int tlen,
int tscale,
int tvary,
char *where
) {
  /* dcl-s type */
  switch (typ) {
  case 'i':
    switch (tlen) {
    case 3:
      return ile_pgm_int8_2_int(where);
    case 5:
      return ile_pgm_int16_2_int(where);
    case 10:
      return ile_pgm_int32_2_int(where);
    case 20:
      return ile_pgm_int64_2_int(where);
    default:
      return ile_pgm_int32_2_int(where);
    }
    break;
  case 'u':
    switch (tlen) {
    case 3:
      return ile_pgm_uint8_2_int(where);
    case 5:
      return ile_pgm_uint16_2_int(where);
    case 10:
      return ile_pgm_uint32_2_int(where);
    case 20:
      return ile_pgm_uint64_2_int(where);
    default:
      return ile_pgm_uint32_2_int(where);
    }
    break;
  case 'f':
    switch (tlen) {
    case 4:
      return ile_pgm_float_2_int(where);
    case 8:
      return ile_pgm_double_2_int(where);
    default:
      return ile_pgm_double_2_int(where);
    }
  case 'p':
    return ile_pgm_packed_2_int(where, tlen, tscale);
  case 's':
    return ile_pgm_zoned_2_int(where, tlen, tscale);
  case 'a':
    return ile_pgm_char_2_int(where, tlen, tvary);
  case 'b':
    return ile_pgm_bin_2_int(where, tlen);
  case 'h':
    return ile_pgm_hole_2_int(where, tlen);
  default:
    break;
  }
  return 0;
}


/* "dcl-ds":["name",dimension, "in|out|both|value|const|return"] */
SQLRETURN tool_dcl_ds(
tool_struct_t * tool,
int isOut,
int isDs,
char * in_name,
char * in_dim,
char * in_by,
char * in_dou,
char * in_dou_search,
int * ds_dim, 
int * ds_by, 
int * ds_dou, 
int * ds_start_offset,
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

  int pase_sig = 0;

  int dou = 0;
  char * where_dou = NULL;
  tool_key_data_struct_t * node = NULL;

  /* parse dimension */
  rc = ile_pgm_str_2_int32((char *)&tdim, in_dim, 1);
  if (tdim < 1) {
    tdim = 1;
  }

  /* parse in|out|both|value|const|return */
  by = ile_pgm_by(in_by, typ, tlen, tdim, tvary, isDs, &spill_len, &pase_sig);
  if (spill_len) {
    /* grow template (if need) */
    layout = ile_pgm_grow(playout, spill_len);
  }

  /* location of parm or ds data */
  where = ile_pgm_parm_location(0, by, pase_sig, spill_len, layout);
  if (!where) {
    return SQL_ERROR;
  }

  /* "dou":? */
  if (isOut && in_dou) {
    /* "dou":4 (literal) */
    dou = ile_pgm_char_2_int_valid(in_dou, strlen(in_dou), 0);
    /* "dou":"TOOL400_S_NAME" */
    if (dou < 0) {
      dou = 0;
      node = (tool_key_data_struct_t *) tool_node_find_s_dou_name(tool, in_dou, in_dou_search);
      if (node && node->tlen) {
        where_dou = (char *)layout + node->offset;
        dou = tool_dcl_s_2_int(node->typ, node->tlen, node->tscale, node->tvary, where_dou);
      }
    }
  }

  /* parse data */
  *ds_dim = tdim;
  *ds_by = by;
  *ds_dou = dou;
  *ds_start_offset = where - (char *)layout;

  /* layout return */
  *playout = layout;

  return rc;
}


/*=================================================
 * toolkit run parsed key, val, lvl
 */

int tool_sql_errors(tool_struct_t * tool, SQLHANDLE handle, SQLSMALLINT hType, int rc)
{
  SQLSMALLINT length = 0;
  SQLCHAR *p = NULL;
  SQLSMALLINT recno = 1;
  tool->sqlCode = 0;
  if (rc == SQL_ERROR) {
    memset(tool->sqlMsg, '\0', SQL_MAX_MESSAGE_LENGTH + 1);
    memset(tool->sqlState, '\0', SQL_SQLSTATE_SIZE + 1);
    if ( SQLGetDiagRec(hType, handle, recno, tool->sqlState, &tool->sqlCode, tool->sqlMsg, SQL_MAX_MESSAGE_LENGTH + 1, &length)  == SQL_SUCCESS ) {
      if (tool->sqlMsg[length-1] == '\n') {
        p = &tool->sqlMsg[length-1];
        *p = '\0';
      }
      tool_output_sql_errors(tool, rc, tool->sqlCode, tool->sqlState, tool->sqlMsg);
      return SQL_ERROR;
    }
  }
  return SQL_SUCCESS;
}


/* program */
SQLRETURN tool_key_pgm_data_run(tool_struct_t * tool, tool_key_pgm_struct_t * tpgm, int * isDs, int isOut, tool_node_t ** curr_node) {
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
  tool_key_conn_struct_t * tconn = (tool_key_conn_struct_t *) tool->tconn;
  tool_node_t * node = *curr_node;
  /* current node (output) */
  tool->curr = node;
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
  sqlrc = tool_dcl_s(tool, isOut, pgm_s_name, pgm_s_type, pgm_s_val, pgm_s_dim, pgm_s_by, pgm_s_ccsid, *isDs, (ile_pgm_call_t **)&tpgm->layout);
  return sqlrc;
}

SQLRETURN tool_key_pgm_ds_run(tool_struct_t * tool, tool_key_pgm_struct_t * tpgm, int * isDs, int isOut, tool_node_t ** curr_node) {
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
  char * pgm_ds_dou = NULL;
  char * pgm_ds_dim_dou_search = NULL;
  int pgm_ds_dim_cnt = 0;
  int pgm_ds_dim_cnt_up = 0;
  int pgm_ds_dim_max = 0;
  int pgm_ds_by_flag = 0;
  int pgm_ds_dim_dou_cnt = 0;
  int ds_start_offset = 0;
  tool_key_conn_struct_t * tconn = (tool_key_conn_struct_t *) tool->tconn;
  tool_node_t * node = *curr_node;
  tool_node_t * pgm_ds_idx = node;
  int j = 0;
  int ds_spill_len = 0;
  char * where = NULL;
  char * where_copy = NULL;
  /* current node (output) */
  tool->curr = node;
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
    case TOOL400_DS_DOU:
      pgm_ds_dou = val;
      break;
    case TOOL400_DS_DOS:
      pgm_ds_dim_dou_search = val;
      break;
    default:
      break;
    }
  }
  /* where start here */
  sqlrc = tool_dcl_ds(tool, isOut, *isDs, pgm_ds_name, pgm_ds_dim, pgm_ds_by, pgm_ds_dou, pgm_ds_dim_dou_search, &pgm_ds_dim_cnt, &pgm_ds_by_flag, &pgm_ds_dim_dou_cnt, &ds_start_offset, (ile_pgm_call_t **)&tpgm->layout);
  *isDs = 1; /* now, we are in a ds structure */
  if (isOut) {
    tool_output_pgm_dcl_ds_beg(tool, pgm_ds_name, pgm_ds_dim_cnt);
    if (pgm_ds_dim_cnt) {
      tool_output_pgm_dcl_ds_rec_beg(tool);
    }
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
    /* current node (output) */
    tool->curr = node;
    /* ds */
    tool_dump_beg(sqlrc, "pgm_ds_run", i, lvl, key, val);
    switch (key) {
    case TOOL400_KEY_DCL_S:
      sqlrc = tool_key_pgm_data_run(tool, tpgm, isDs, isOut, &node);
      break;
    case TOOL400_KEY_DCL_DS:
      sqlrc = tool_key_pgm_ds_run(tool, tpgm, isDs, isOut, &node);
      break;
    case TOOL400_KEY_END_DS:
      if (!isOut) {
        /* multiple dim DS */
        if (pgm_ds_dim_cnt > 1) {
          /* ds_spill_len calculate full size of 'ds' including all fully initialized 
           * nested/arrayed 'ds', 's' children, then use as 1st 'element' pattern
           * to initialize all the remaining array elements with memcpy.
           * This avoids the need to reprocess json in the recursive 'run' functions.
           * (To wit, nature of compiler initialization of 'ds' array 'nested' is simply
           * replicate 1st full initialize element into remain array elements.)
           */
          where_copy = (char *)tpgm->layout + ds_start_offset; /* hamela05 bug - will move on grow */
          where = ile_pgm_parm_location(0, ILE_PGM_BY_IN_DS, 0, 0, (ile_pgm_call_t *)tpgm->layout);
          ds_spill_len = where - where_copy;
          for (j = 1; j < pgm_ds_dim_cnt; j++) {
            /* grow template (if need) */
            tpgm->layout = ile_pgm_grow((ile_pgm_call_t **)&tpgm->layout, ds_spill_len);
            /* where now */
            where = ile_pgm_parm_location(0, ILE_PGM_BY_IN_DS, 0, 0, (ile_pgm_call_t *)tpgm->layout);
            where_copy = (char *)tpgm->layout + ds_start_offset; /* hamela05 bug */
            /* copy additional ds element */
            memcpy(where,where_copy,ds_spill_len);
            ile_pgm_next_spill_pos((ile_pgm_call_t *)tpgm->layout, ds_spill_len);
          }
          where = NULL;
          where_copy = NULL;
        }
        go = 0;
      } else {
        /* dim replay ds (from pgm_ds_idx)
         * Unfortunately, output can not just copy image like input (init above).
         * Instead we must 're-play' the entire parse for each element. The
         * reason is obvious (probably), but to complete the thought, 
         * output data is likely completely different each array element. 
         */
        if (!pgm_ds_dim_max) {
          pgm_ds_dim_max = pgm_ds_dim_cnt;
        }
        pgm_ds_dim_cnt--;
        pgm_ds_dim_cnt_up++;
        if (pgm_ds_dim_cnt > 0) {
          if (pgm_ds_dim_dou_cnt > 0 && pgm_ds_dim_cnt_up >= pgm_ds_dim_dou_cnt) {
             tool->outhold = 1;
          }
          if (pgm_ds_dim_max) {
            tool_output_pgm_dcl_ds_rec_end(tool);
            tool_output_pgm_dcl_ds_rec_beg(tool);
          }
          node = pgm_ds_idx;
        } else {
          tool->outhold = 0;
          if (pgm_ds_dim_max) {
            tool_output_pgm_dcl_ds_rec_end(tool);
          }
          tool_output_pgm_dcl_ds_end(tool, pgm_ds_dim_max);
          pgm_ds_dim_max = 0;
          go = 0;
        }
      } /* isOut */
      break;
    default:
      break;
    }
    if (sqlrc == SQL_ERROR) {
      tool_dump_end(sqlrc, "pgm_ds_error", i, lvl, key, val);
    }
  }
  return sqlrc;
}


SQLRETURN tool_key_pgm_params_run(tool_struct_t * tool, tool_key_pgm_struct_t * tpgm, int isOut, tool_node_t ** curr_node) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  int i = 0;
  int i_end = 0;
  int key = 0;
  char * val = NULL;
  int lvl = 0;
  int max = 0;
  int go = 1;
  int isDs = 0;
  tool_key_conn_struct_t * tconn = (tool_key_conn_struct_t *) tool->tconn;
  tool_node_t * node = *curr_node;
  /* current node (output) */
  tool->curr = node;
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
    /* current node (output) */
    tool->curr = node;
    tool_dump_beg(sqlrc, "pgm_params_run", i, lvl, key, val);
    switch (key) {
    case TOOL400_KEY_DCL_S:
      isDs = 0;
      sqlrc = tool_key_pgm_data_run(tool, tpgm, &isDs, isOut, &node);
      break;
    case TOOL400_KEY_DCL_DS:
      isDs = 0;
      sqlrc = tool_key_pgm_ds_run(tool, tpgm, &isDs, isOut, &node);
      break;
    case TOOL400_KEY_END_PGM:
      go = 0;
    default:
      break;
    }
    if (sqlrc == SQL_ERROR) {
      tool_dump_end(sqlrc, "pgm_params_error", i, lvl, key, val);
    }
  }
  return sqlrc;
}

SQLRETURN tool_key_pgm_call_run(tool_struct_t * tool, tool_key_pgm_struct_t * tpgm) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  char * pgm_shift_ile = NULL;
  char * pgm_shift_pase = NULL;
  int pgm_shift_len = 0;
  SQLINTEGER pgm_shift_sql_max = 0;
  ile_pgm_call_t * layout = (ile_pgm_call_t *)tpgm->layout;
  /* how far? */
  layout->step = 0;
  /* last return position */
  if (layout->return_start) {
    layout->return_end = layout->pos;
  }
#ifdef __IBMC__
  iCall400((char *) tpgm->layout);
  sqlrc = 0;
#else
  /* shift to blob alignment
   * pase -        |pad[0]|pad[1]|pad[2]|pad[3]|...argv...|
   *                                           .
   *                                    ........
   *                                    .
   * blob - |len   |pad[0]|pad[1]|pad[2]|...argv...| 
   */
  layout->blob_pad[0] = -1;
  layout->blob_pad[1] = -1;
  layout->blob_pad[2] = -1;
  pgm_shift_ile = (char *)&layout->blob_pad[3];
  pgm_shift_pase = pgm_shift_ile + 4;
  pgm_shift_len = layout->max - (pgm_shift_pase - (char *)tpgm->layout);
  memcpy(pgm_shift_ile,pgm_shift_pase,pgm_shift_len);
  pgm_shift_sql_max = layout->max;
  /* bind parm */
  sqlrc = SQLBindParameter((SQLHSTMT)tpgm->hstmt,
                           (SQLUSMALLINT) 1,
                           SQL_PARAM_INPUT_OUTPUT,
                           SQL_C_BINARY,
                           SQL_BLOB,
                           layout->max,
                           0,
                           (SQLPOINTER)tpgm->layout,
                           0,
                           &pgm_shift_sql_max);
  /* execute */
  if (sqlrc == SQL_SUCCESS) {
    sqlrc = SQLExecute((SQLHSTMT)tpgm->hstmt);
  }
  sqlrc = tool_sql_errors(tool, tpgm->hstmt, SQL_HANDLE_STMT, sqlrc);
  /* shift to pase alignment
   * pase -        |pad[0]|pad[1]|pad[2]|pad[3]|...argv...|
   *                                           .
   *                                    ........
   *                                    .
   * blob - |len   |pad[0]|pad[1]|pad[2]|...argv...| 
   */
  memcpy(pgm_shift_pase,pgm_shift_ile,pgm_shift_len);
#endif
  return sqlrc;
}

SQLRETURN tool_key_pgm_run(tool_struct_t * tool, tool_node_t ** curr_node) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLRETURN sqlrc1 = SQL_SUCCESS;
  int i = 0;
  int key = 0;
  char * val = NULL;
  int lvl = 0;
  int max = 0;
  int go = 1;
  int step = 0;
  tool_key_conn_struct_t * tconn = (tool_key_conn_struct_t *) tool->tconn;
  tool_node_t * node = *curr_node;
  tool_key_pgm_struct_t * tpgm = (tool_key_pgm_struct_t *) node;
  tool_node_t * pgm_out_idx = node;
  /* current node (output) */
  tool->curr = node;
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
  tpgm->pgm_ile_debug = NULL;
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
    case TOOL400_PGM_DEBUG:
      tpgm->pgm_ile_debug = val;
      break;
    default:
      break;
    }
  }
  /* init pgm layout (ebcdic, etc) */
  tool_pgm(tpgm->pgm_ile_name, tpgm->pgm_ile_lib, tpgm->pgm_ile_func, tpgm->pgm_ile_debug, (ile_pgm_call_t **)&tpgm->layout);
  /* statement */
  sqlrc = SQLAllocHandle(SQL_HANDLE_STMT, (SQLHDBC) tconn->hdbc, &tpgm->hstmt);
  /* prepare */
  if (sqlrc == SQL_SUCCESS) {
    sqlrc = SQLPrepare((SQLHSTMT)tpgm->hstmt, (SQLCHAR*)tpgm->pgm_buff, (SQLINTEGER)SQL_NTS);
  }
  sqlrc = tool_sql_errors(tool, tpgm->hstmt, SQL_HANDLE_STMT, sqlrc);
  /* call program (step 1-input, step 2-output)*/
  for (step=1; step < 4 && sqlrc == SQL_SUCCESS; step++) {
    node = pgm_out_idx;
    /* current node (output) */
    tool->curr = node;
    tool_pgm_dump(sqlrc, "pgm_run", step, tpgm);
    switch(step) {
    case 1:
      if (tpgm->pgm_ile_name) {
        tool_output_pgm_beg(tool, tpgm->pgm_ile_name, tpgm->pgm_ile_lib, tpgm->pgm_ile_func);
      }
      sqlrc = tool_key_pgm_params_run(tool, tpgm, 0, &node);
      break;
    case 2:
      sqlrc = tool_key_pgm_call_run(tool, tpgm);
      break;
    case 3:
      /* reset top of parms */
      ile_pgm_reset_pos(tpgm->layout);
      sqlrc = tool_key_pgm_params_run(tool, tpgm, 1, &node);
      if (tpgm->pgm_ile_name) {
        tool_output_pgm_end(tool);
      }
      break;
    default:
      break;
    }
    if (sqlrc == SQL_ERROR) {
      tool_pgm_dump(sqlrc, "pgm_error", step, tpgm);
    }
  }
  if (tpgm->pgm_ile_name && sqlrc != SQL_SUCCESS) {
    tool_output_pgm_end(tool);
  }
  /* close */
  if (tpgm->hstmt) {
    sqlrc1 = SQLFreeHandle(SQL_HANDLE_STMT, tpgm->hstmt);
  }
  tpgm->hstmt = 0;
  return sqlrc;
}

/* cmd */
SQLRETURN tool_key_cmd_run(tool_struct_t * tool, tool_node_t ** curr_node) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLRETURN sqlrc1 = SQL_SUCCESS;
  int i = 0;
  int key = 0;
  char * val = NULL;
  int lvl = 0;
  int max = 0;
  int go = 1;
  char * cmd = NULL;
  tool_key_conn_struct_t * tconn = (tool_key_conn_struct_t *) tool->tconn;
  tool_node_t * node = *curr_node;
  tool_key_cmd_struct_t * tcmd = (tool_key_cmd_struct_t *) node;
  /* current node (output) */
  tool->curr = node;

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
  tool_output_cmd_beg(tool, cmd);
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
  sqlrc = tool_sql_errors(tool, tcmd->hstmt, SQL_HANDLE_STMT, sqlrc);
  /* execute */
  if (sqlrc == SQL_SUCCESS) {
    sqlrc = SQLExecute((SQLHSTMT)tcmd->hstmt);
  }
  sqlrc = tool_sql_errors(tool, tcmd->hstmt, SQL_HANDLE_STMT, sqlrc);
  /* output */
  tool_output_cmd_end(tool);
  /* close */
  if (tcmd->hstmt) {
    sqlrc1 = SQLFreeHandle(SQL_HANDLE_STMT, tcmd->hstmt);
  }
  tcmd->hstmt = 0;
  return sqlrc;
}

/* query */
SQLRETURN tool_key_fetch_run(tool_struct_t * tool, tool_key_query_struct_t * tqry) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  tool_key_conn_struct_t * tconn = (tool_key_conn_struct_t *) tool->tconn;
  int i = 0;
  /* fetch */
  int fetch_recs = 0;
  SQLSMALLINT fetch_cols = 0;
  SQLSMALLINT fetch_col_name_len = 0;
  SQLCHAR *fetch_col_name[TOOL400_MAX_COLS];
  SQLCHAR *fetch_col_value[TOOL400_MAX_COLS];
  SQLSMALLINT fetch_col_sql_type[TOOL400_MAX_COLS];
  SQLINTEGER fetch_col_size = 0;
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
  sqlrc = tool_sql_errors(tool, tqry->hstmt, SQL_HANDLE_STMT, sqlrc);
  /* no records */
  if (fetch_cols < 1) {
    tool_output_record_array_beg(tool);
    tool_output_record_no_data_found(tool);
    tool_output_record_array_end(tool);
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
  tool_output_record_array_beg(tool);
  while (sqlrc == SQL_SUCCESS) {
    sqlrc = SQLFetch(tqry->hstmt);
    if (sqlrc == SQL_NO_DATA_FOUND || sqlrc < SQL_SUCCESS ) {
      if (!fetch_recs) {
        tool_output_record_no_data_found(tool);
      } else {
        sqlrc = SQL_SUCCESS;
      }
      break;
    }
    tool_output_record_row_beg(tool);
    fetch_recs += 1;
    for (i = 0 ; i < fetch_cols; i++) {
      if (fetch_col_value[i]) {
        tool_output_record_name_value(tool, fetch_col_name[i], fetch_col_value[i], fetch_col_sql_type[i], fetch_col_len[i]);
      }
    }
    tool_output_record_row_end(tool);
  } /* fetch loop */
  tool_output_record_array_end(tool);
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

SQLRETURN tool_key_query_run(tool_struct_t * tool, tool_node_t ** curr_node) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLRETURN sqlrc1 = SQL_SUCCESS;
  int i = 0;
  int j = 0;
  int key = 0;
  char * val = NULL;
  int lvl = 0;
  int max = 0;
  int go = 1;
  tool_key_conn_struct_t * tconn = (tool_key_conn_struct_t *) tool->tconn;
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
  SQLINTEGER parm_precision = 0;
  SQLSMALLINT parm_data_type = 0;
  SQLSMALLINT parm_nullable = 0;

  /* current node (output) */
  tool->curr = node;

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
  }
  /* no query */
  if (!query) {
    return sqlrc;
  }
  /* output */
  tool_output_query_beg(tool, query);  
  /* statement */
  sqlrc = SQLAllocHandle(SQL_HANDLE_STMT, (SQLHDBC) tconn->hdbc, &tqry->hstmt);
  /* prepare */
  if (sqlrc == SQL_SUCCESS) {
    sqlrc = SQLPrepare((SQLHSTMT)tqry->hstmt, (SQLCHAR*)query, (SQLINTEGER)SQL_NTS);
  }
  sqlrc = tool_sql_errors(tool, tqry->hstmt, SQL_HANDLE_STMT, sqlrc);

  /* parms? */
  memset(parm_len, 0, sizeof(parm_len));
  if (tqry->hstmt) {
    sqlrc = SQLNumParams((SQLHSTMT)tqry->hstmt, (SQLSMALLINT*)&parm_max);
  }
  sqlrc = tool_sql_errors(tool, tqry->hstmt, SQL_HANDLE_STMT, sqlrc);
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
    /* current node (output) */
    tool->curr = node;
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
    tool_output_query_end(tool);  
    return sqlrc;
  }

  /* execute */
  if (sqlrc == SQL_SUCCESS) {
    sqlrc = SQLExecute((SQLHSTMT)tqry->hstmt);
  }
  sqlrc = tool_sql_errors(tool, tqry->hstmt, SQL_HANDLE_STMT, sqlrc);
  /* execute error */
  if (sqlrc == SQL_ERROR) {
    /* output */
    tool_output_query_end(tool);  
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
    /* current node (output) */
    tool->curr = node;
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
        sqlrc = tool_key_fetch_run(tool, tqry);
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
  tool_output_query_end(tool);  
  /* close */
  if (tqry->hstmt) {
    sqlrc1 = SQLFreeHandle(SQL_HANDLE_STMT, tqry->hstmt);
    tqry->hstmt = 0;
  }
  return sqlrc;
}

/* connection */
SQLRETURN tool_key_conn_joblog(tool_struct_t * tool, SQLHANDLE hdbc) {
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
  tool_output_joblog_beg(tool);
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
      tool_output_joblog_rec(tool,
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
  tool_output_joblog_end(tool);

 return sql_exec_rc;
}

SQLRETURN tool_key_conn_run(tool_struct_t * tool, tool_node_t ** curr_node) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  int i = 0;
  int key = 0;
  char * val = NULL;
  int lvl = 0;
  int max = 0;
  int go = 1;
  tool_node_t * node = *curr_node;
  tool_key_conn_struct_t * tconn = (tool_key_conn_struct_t *) node;
  /* current node (output) */
  tool->curr = node;
  /* ctor */
  if (!tconn->conn_type) {
    tconn->hdbc = tool->hdbc;
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
  tool->tconn = tconn;
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
        /* current node (output) */
        tool->curr = node;
        break;
      }
    }
    /* connect */
    if (tconn->presistent) {
      sqlrc = SQL400pConnect( tconn->conn_db, tconn->conn_uid, tconn->conn_pwd, tconn->conn_qual, &tconn->hdbc, tconn->conn_commit, tconn->conn_libl, tconn->conn_curlib );
    } else {
      sqlrc = SQL400Connect( tconn->conn_db, tconn->conn_uid, tconn->conn_pwd, &tconn->hdbc, tconn->conn_commit, tconn->conn_libl, tconn->conn_curlib );
    }
    sqlrc = tool_sql_errors(tool, tconn->hdbc, SQL_HANDLE_DBC, sqlrc);
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
    /* current node (output) */
    tool->curr = node;
    /* top level */
    tool_dump_beg(sqlrc, "conn_run", i, lvl, key, val);
    switch (key) {
    case TOOL400_KEY_QUERY:
      sqlrc = tool_key_query_run(tool, &node);
      break;
    case TOOL400_KEY_CMD:
      sqlrc = tool_key_cmd_run(tool, &node);
      break;
    case TOOL400_KEY_PGM:
      sqlrc = tool_key_pgm_run(tool, &node);
      break;
    case TOOL400_KEY_END_CONN:
      go = 0;
      break;
    default:
      break;
    }
    if (sqlrc == SQL_ERROR) {
      tool_dump_end(sqlrc, "conn_error", i, lvl, key, val);
    }
    /* joblog info */
    if (sqlrc == SQL_ERROR) {
      tool_key_conn_joblog(tool, tconn->hdbc);
    }
  }
  /* hdbc external (caller?) or pool (pConnect) */
  if (tconn->hdbc && !tconn->presistent) {
    sqlrc = SQL400Close(tconn->hdbc);
  }
  return sqlrc;
}

int tool_run(int hdbc, char * outarea, int outlen, tool_struct_t *tool) 
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int i = 0;
  int key = 0;
  char * val = NULL;
  int lvl = 0;
  int max = 0;
  tool_node_t * node = NULL;
  /* ctor */
  tool->hdbc = hdbc;
  tool->outarea = outarea;
  tool->outmax = outlen;
  tool->outlen = 0;
  tool->tconn = (tool_key_conn_struct_t *) tool_node_first(tool);
  tool_graph(sqlrc, "tool_graph", tool);
  /* output start script */
  tool_output_script_beg(tool);
  /* top level */
  for (i=0, node = tool->first; node && sqlrc == SQL_SUCCESS; node = node->next, i++) {
    key = node->key;
    val = node->val;
    lvl = node->ord;
    tool_dump_beg(sqlrc, "tool_run", i, lvl, key, val);
    switch (key) {
    case TOOL400_KEY_CONN:
      sqlrc = tool_key_conn_run(tool, &node);
      break;
    default:
      break;
    }
    if (sqlrc == SQL_ERROR) {
      tool_dump_end(sqlrc, "tool_error", i, lvl, key, val);
    }
  }
  /* output end script */
  tool_output_script_end(tool);

  return sqlrc;
}

