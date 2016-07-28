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


SQLRETURN run_main(
 SQLHDBC  hdbc,
 SQLCHAR * inrun,
 SQLINTEGER inlen,
 SQLCHAR * outrun,
 SQLINTEGER outlen,
 SQLINTEGER rf)
{
  int rc = 0;
  script_map_t * script = malloc(sizeof(script_map_t));

  script->in = inrun;
  script->out = outrun;
  script->inlen = inlen;
  script->outlen = outlen;
  script->hdbc = hdbc;
  node_init(script);

  switch(rf) {
  case 0:
    rc = json_parse_hash(script);
    break;
  case 1:
/* 
    rc = xml_parse_hash(script);
    break;
*/
  default:
    break;
  }

/*
  rc = run_script(script);
*/

  free(script);

  return rc;
}

