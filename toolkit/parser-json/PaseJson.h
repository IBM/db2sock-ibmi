#ifndef _PASEJSON_H
#define _PASEJSON_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iconv.h>
#include <stdarg.h>
#ifdef __IBMC__
#include <sqlcli.h>
#include "../PaseType.h"
#endif


/*
 * == WARNING ==
 * The json format is changing.
 * When project warnings are removed, you may
 * rely on json format.
 */

/* ==========================
 * json output control
 * ==========================
 */
#define JSON400_OUT_MAX_STDOUT 1000000

#define JSON400_ADJUST_NDA 0
#define JSON400_ADJUST_ADD_COMMA 1
#define JSON400_ADJUST_ADD_SPACE 2
#define JSON400_ADJUST_RMV_COMMA 3

/* ==========================
 * json raw parse ordinals
 * ==========================
 */
#define JSON400_KEY_BLOCK 4096
typedef struct json_key_struct {
  int count;
  int max;
  int * key;
  char ** val;
  int * lvl;
} json_key_t;
#define JSON400_END 0
#define JSON400_KEY 9001
#define JSON400_AT_BEG 9101
#define JSON400_OBJ_BEG 9102
#define JSON400_ARY_BEG 9103
#define JSON400_COMMA 9501
#define JSON400_COLON 9502
#define JSON400_AT_VAL 9601
#define JSON400_VAL_STR 9602
#define JSON400_VAL_NBR 9603
#define JSON400_VAL_BOL 9604
#define JSON400_VAL_NUL 9605
#define JSON400_AT_END 9700
#define JSON400_OBJ_END 9701
#define JSON400_ARY_END 9702

SQLRETURN custom_SQL400Json(SQLHDBC hdbc,
 SQLCHAR * injson,
 SQLINTEGER inlen, 
 SQLCHAR * outjson,
 SQLINTEGER outlen);

#endif /* _PASEJSON_H */

