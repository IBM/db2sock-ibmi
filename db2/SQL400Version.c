#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dlfcn.h>
#include <iconv.h>
#include <sqlcli1.h>
#include "PaseCliInit.h"
#include "PaseCliAsync.h"

/*
 * version
 */
SQLRETURN custom_SQL400Version(SQLPOINTER outversion, SQLINTEGER outlen) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  char buf[128];
  int len = 0;

  memset(buf,0,sizeof(buf));
  strcpy(buf,DB2_CLI_VERSION);
  len = strlen(buf);
  if (outlen > len) {
    strcpy(outversion,buf);
  } else {
    sqlrc = SQL_ERROR;
  }
  return sqlrc;
}


