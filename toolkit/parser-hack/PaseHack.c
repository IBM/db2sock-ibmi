#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iconv.h>
#include <stdarg.h>
#include "../PaseTool.h"
#include "PaseHkDmp.h"
#include "PaseHack.h"

/* ==========================
 * SQL400Hack interface (dynamic loaded)
 * ==========================
 */
SQLRETURN custom_SQL400HackExecDirect(SQLHSTMT hstmt, 
 SQLCHAR * szSqlStr, 
 SQLINTEGER cbSqlStr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  return sqlrc;
}

SQLRETURN custom_SQL400HackPrepare(SQLHSTMT hstmt, 
 SQLCHAR * szSqlStr, 
 SQLINTEGER cbSqlStr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  return sqlrc;
}

SQLRETURN custom_SQL400HackExecute(SQLHSTMT hstmt)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  return sqlrc;
}

SQLRETURN custom_SQL400HackFetch(SQLHSTMT hstmt)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  return sqlrc;
}

SQLRETURN custom_SQL400HackDescribeCol(SQLHSTMT hstmt, 
 SQLSMALLINT icol, 
 SQLCHAR * szColName, 
 SQLSMALLINT cbColNameMax, 
 SQLSMALLINT * pcbColName, 
 SQLSMALLINT * pfSqlType, 
 SQLINTEGER * pcbColDef, 
 SQLSMALLINT * pibScale, 
 SQLSMALLINT * pfNullable)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  return sqlrc;
}

SQLRETURN custom_SQL400HackBindCol(SQLHSTMT hstmt, 
 SQLSMALLINT icol, 
 SQLSMALLINT iType, 
 SQLPOINTER rgbValue, 
 SQLINTEGER cbValueMax, 
 SQLINTEGER * pcbValue)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  return sqlrc;
}


