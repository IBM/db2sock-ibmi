#ifndef _PASECLIJSON_H
#define _PASECLIJSON_H
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

int json_parse_hash(script_map_t * script);

#endif /* _PASECLIJSON_H */

