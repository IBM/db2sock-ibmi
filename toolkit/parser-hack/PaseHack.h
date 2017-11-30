#ifndef _PASEHACK_H
#define _PASEHACK_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iconv.h>
#include <stdarg.h>
#ifdef __IBMC__
#include <sqlcli.h>
#include "../PaseType.h"
#endif

#define DB2_HACK_SQL_ERROR -42
#define DB2_HACK_MAX_JSON 15000000
typedef struct PaseHackResource {
  int inlen;
  char * injson;
  int outlen;
  char * outjson;
  int userlen;
  char * userjson;
} PaseHackResource;

#endif /* _PASEHACK_H */

