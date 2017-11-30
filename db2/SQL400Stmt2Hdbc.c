#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dlfcn.h>
#include <iconv.h>
#include <sqlcli1.h>
#include "PaseCliInit.h"
#include "PaseCliAsync.h"

/*
 * resource table
 */

SQLRETURN custom_SQL400Stmt2Hdbc( SQLHSTMT  hstmt, SQLINTEGER * ohnd ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  *ohnd = init_table_stmt_2_conn(hstmt);
  if (*ohnd < 2) {
    sqlrc = SQL_ERROR;
  }
  return sqlrc;
}



