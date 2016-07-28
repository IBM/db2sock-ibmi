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
#include "PaseCliRun.h"
#include "PaseCliJson.h"

int json_parse_hash(script_map_t * script) {
  char *ip = script->in;
  int rc = 0;
  int go = 0;
  char *lp = NULL;
  char *np = NULL;
  node_map_t prev = node_cur(script);
  while (*ip) {
    switch(*ip) {
    case '{':
      node_add(script,RUN_NODE_TYPE_MARK_ELEM1,ip,ip);
      break;
    case '}':
      node_add(script,RUN_NODE_TYPE_MARK_ELEM2,ip,ip);
      break;
    case '[':
      node_add(script,RUN_NODE_TYPE_MARK_ARRAY1,ip,ip);
      break;
    case ']':
      node_add(script,RUN_NODE_TYPE_MARK_ARRAY2,ip,ip);
      break;
    case ':':
      node_add(script,RUN_NODE_TYPE_MARK_VAL,ip,ip);
      break;
    /* "name":"value" */
    case '"':
      prev = node_prev_peek(script);
      lp = ip + 1;
      ip = lp;
      while (*ip) {
        if (*ip == '"') {
          /* "name":"value"
           *       | xxxxx
           *       |<-prev.id??
           */
          if (prev.id == RUN_NODE_TYPE_MARK_VAL) {
            node_add(script,RUN_NODE_TYPE_VALUE,lp,ip-1);
          } else {
            /* "name":"value"   -- elem
             * "_attr":"value"  -- attribute
             * "__text":"value" -- data
             *  xxxxxx
             */
            if (*lp == '_') {
              np = lp + 1;
              /* "__text":"value" -- data
               *  xx
               */
              if (*np == '_') {
                node_add(script,RUN_NODE_TYPE_DATA,lp,ip-1);
              /* "_attr":"value"  -- attribute
               *  x
               */
              } else {
                node_add(script,RUN_NODE_TYPE_ATTR,lp,ip-1);
              }
            /* "name":"value"   -- elem
             *  xxxx
             */
            } else {
              node_add(script,RUN_NODE_TYPE_ELEM,lp,ip-1);
            }
          } /* end else name, _attr, __test */
          break;
        } /* end if (*ip == '"') */
        ip+=1;
      } /* end while (*ip) */
      break;
    default:
      break;
    }
    ip+=1;
  } /* end while (*ip) */
  return rc;
}


