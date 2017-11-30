#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dlfcn.h>
#include <iconv.h>
#include <sqlcli1.h>
#include "PaseCliInit.h"
#include "PaseCliAsync.h"

SQLINTEGER custom_json_parser_flag;
SQLRETURN (*custom_json_parser_symbol)( SQLHDBC, SQLCHAR *, SQLINTEGER, SQLCHAR *, SQLINTEGER );

SQLRETURN custom_SQL400Json(SQLHDBC hdbc,
 SQLCHAR * injson,
 SQLINTEGER inlen, 
 SQLCHAR * outjson,
 SQLINTEGER outlen) 
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!custom_json_parser_flag) {
    dlhandle = init_json_dlsym();
    custom_json_parser_symbol = dlsym(dlhandle, "custom_SQL400Json");
    custom_json_parser_flag = 1;
  }
  sqlrc = custom_json_parser_symbol( hdbc, injson, inlen, outjson, outlen );
  // dynamic load of parser
  return sqlrc;
}


