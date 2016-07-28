#ifndef _PASECLIRUN_H
#define _PASECLIRUN_H

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dlfcn.h>
#include <iconv.h>
#include <sqlcli1.h>
#include <as400_types.h>
#include <as400_protos.h>

#define RUN_NODE_MAX 1000000
#define RUN_NODE_TYPE_END -1
#define RUN_NODE_TYPE_ELEM 1
#define RUN_NODE_TYPE_ATTR 2
#define RUN_NODE_TYPE_DATA 3
#define RUN_NODE_TYPE_VALUE 4
#define RUN_NODE_TYPE_MARK_ELEM1 10
#define RUN_NODE_TYPE_MARK_ELEM2 11
#define RUN_NODE_TYPE_MARK_ARRAY1 20
#define RUN_NODE_TYPE_MARK_ARRAY2 21
#define RUN_NODE_TYPE_MARK_VAL 40

typedef struct run_node_map {
  short id;
  int off;
  int len; 
} node_map_t;

typedef struct run_script {
  char * in;
  char * out;
  int inlen; 
  int outlen; 
  SQLHDBC hdbc;
  int idx; 
  int max; 
  node_map_t map[RUN_NODE_MAX];
} script_map_t;

__inline__ node_map_t node_first(script_map_t * x) {
  x->idx = 0;
  return x->map[x->idx];
}
__inline__ node_map_t node_prev(script_map_t * x) {
  x->idx--;
  return x->map[x->idx];
}
__inline__ node_map_t node_prev_peek(script_map_t * x) {
  if (!x->idx) return x->map[x->idx];
  else return x->map[x->idx - 1];
}
__inline__ node_map_t node_next(script_map_t * x) {
  x->idx++;
  return x->map[x->idx];
}
__inline__ node_map_t node_next_peek(script_map_t * x) {
  if (x->idx == x->max) return x->map[x->idx];
  else return x->map[x->idx + 1];
}
__inline__ node_map_t node_cur(script_map_t * x) {
  return x->map[x->idx];
}
__inline__ node_map_t node_last(script_map_t * x) {
  x->idx = x->max - 1;
  return x->map[x->idx];
}


__inline__ void node_init(script_map_t * x) {
  x->idx = 0;
  x->max = 0;
  x->map[x->max].id = RUN_NODE_TYPE_END;
  x->map[x->max].off = 0;
  x->map[x->max].len = 0;
  x->idx = x->max;
  x->max++;
}
__inline__ void node_add(script_map_t * x, short id, char *lp, char *ip) {
  x->map[x->max].id = id;
  x->map[x->max].off = lp - x->in;
  x->map[x->max].len = ip - lp + 1;
  x->idx = x->max;
  x->max++;
  x->map[x->max].id = RUN_NODE_TYPE_END;
  x->map[x->max].off = 0;
  x->map[x->max].len = 0;
}

SQLRETURN run_main(
 SQLHDBC  hdbc,
 SQLCHAR * injson,
 SQLINTEGER inlen,
 SQLCHAR * outjson,
 SQLINTEGER outlen,
 SQLINTEGER rf);

#endif /* _PASECLIRUN_H */

