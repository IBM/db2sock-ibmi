#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dlfcn.h>
#include <iconv.h>
#include <sqlcli1.h>
#include "PaseCliInit.h"
#include "PaseCliAsync.h"

/*
 * proto
 */
SQLINTEGER flag_custom_SQL400HackExecDirect;
SQLRETURN (*symbol_custom_SQL400HackExecDirect)( SQLHSTMT, SQLCHAR *, SQLINTEGER);

SQLINTEGER flag_custom_SQL400HackPrepare;
SQLRETURN (*symbol_custom_SQL400HackPrepare)( SQLHSTMT, SQLCHAR *, SQLINTEGER);

SQLINTEGER flag_custom_SQL400HackExecute;
SQLRETURN (*symbol_custom_SQL400HackExecute)( SQLHSTMT );

SQLINTEGER flag_custom_SQL400HackFetch;
SQLRETURN (*symbol_custom_SQL400HackFetch)( SQLHSTMT );

SQLINTEGER flag_custom_SQL400HackDescribeCol;
SQLRETURN (*symbol_custom_SQL400HackDescribeCol)( SQLHSTMT,
  SQLSMALLINT, SQLCHAR *, SQLSMALLINT, 
  SQLSMALLINT *, SQLSMALLINT *, SQLINTEGER *, 
  SQLSMALLINT *, SQLSMALLINT *);

SQLINTEGER flag_custom_SQL400HackBindCol;
SQLRETURN (*symbol_custom_SQL400HackBindCol)( SQLHSTMT,
  SQLSMALLINT, SQLSMALLINT, SQLPOINTER, 
  SQLINTEGER, SQLINTEGER *);

SQLINTEGER flag_custom_SQL400HackParamData;
SQLRETURN (*symbol_custom_SQL400HackParamData)( SQLHSTMT, SQLPOINTER * );

SQLINTEGER flag_custom_SQL400HackPutData;
SQLRETURN (*symbol_custom_SQL400HackPutData)( SQLHSTMT, SQLPOINTER, SQLINTEGER );

/*
 * code
 */
SQLRETURN custom_SQL400HackExecDirect(SQLHSTMT hstmt, 
 SQLCHAR * szSqlStr, 
 SQLINTEGER cbSqlStr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!flag_custom_SQL400HackExecDirect) {
    dlhandle = init_hack_dlsym();
    symbol_custom_SQL400HackExecDirect = dlsym(dlhandle, "custom_SQL400HackExecDirect");
    flag_custom_SQL400HackExecDirect = 1;
  }
  sqlrc = symbol_custom_SQL400HackExecDirect( hstmt, szSqlStr, cbSqlStr );
  return sqlrc;
}

SQLRETURN custom_SQL400HackPrepare(SQLHSTMT hstmt, 
 SQLCHAR * szSqlStr, 
 SQLINTEGER cbSqlStr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!flag_custom_SQL400HackPrepare) {
    dlhandle = init_hack_dlsym();
    symbol_custom_SQL400HackPrepare = dlsym(dlhandle, "custom_SQL400HackPrepare");
    flag_custom_SQL400HackPrepare = 1;
  }
  sqlrc = symbol_custom_SQL400HackPrepare( hstmt, szSqlStr, cbSqlStr );
  return sqlrc;
}

SQLRETURN custom_SQL400HackExecute(SQLHSTMT hstmt)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!flag_custom_SQL400HackExecute) {
    dlhandle = init_hack_dlsym();
    symbol_custom_SQL400HackExecute = dlsym(dlhandle, "custom_SQL400HackExecute");
    flag_custom_SQL400HackExecute = 1;
  }
  sqlrc = symbol_custom_SQL400HackExecute( hstmt );
  return sqlrc;
}

SQLRETURN custom_SQL400HackFetch(SQLHSTMT hstmt)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!flag_custom_SQL400HackFetch) {
    dlhandle = init_hack_dlsym();
    symbol_custom_SQL400HackFetch = dlsym(dlhandle, "custom_SQL400HackFetch");
    flag_custom_SQL400HackFetch = 1;
  }
  sqlrc = symbol_custom_SQL400HackFetch( hstmt );
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
  void *dlhandle = NULL;
  if (!flag_custom_SQL400HackDescribeCol) {
    dlhandle = init_hack_dlsym();
    symbol_custom_SQL400HackDescribeCol = dlsym(dlhandle, "custom_SQL400HackDescribeCol");
    flag_custom_SQL400HackDescribeCol = 1;
  }
  sqlrc = symbol_custom_SQL400HackDescribeCol( hstmt, icol, szColName, cbColNameMax, pcbColName, pfSqlType, pcbColDef, pibScale, pfNullable );
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
  void *dlhandle = NULL;
  if (!flag_custom_SQL400HackBindCol) {
    dlhandle = init_hack_dlsym();
    symbol_custom_SQL400HackBindCol = dlsym(dlhandle, "custom_SQL400HackBindCol");
    flag_custom_SQL400HackBindCol = 1;
  }
  sqlrc = symbol_custom_SQL400HackBindCol( hstmt, icol, iType, rgbValue, cbValueMax, pcbValue );
  return sqlrc;
}

SQLRETURN custom_SQL400HackParamData(SQLHSTMT hstmt, 
 SQLPOINTER * Value)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!flag_custom_SQL400HackParamData) {
    dlhandle = init_hack_dlsym();
    symbol_custom_SQL400HackParamData = dlsym(dlhandle, "custom_SQL400HackParamData");
    flag_custom_SQL400HackParamData = 1;
  }
  sqlrc = symbol_custom_SQL400HackParamData( hstmt, Value );
  return sqlrc;
}

SQLRETURN custom_SQL400HackPutData(SQLHSTMT hstmt, 
 SQLPOINTER Data, 
 SQLINTEGER SLen)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!flag_custom_SQL400HackPutData) {
    dlhandle = init_hack_dlsym();
    symbol_custom_SQL400HackPutData = dlsym(dlhandle, "custom_SQL400HackPutData");
    flag_custom_SQL400HackPutData = 1;
  }
  sqlrc = symbol_custom_SQL400HackPutData( hstmt, Data, SLen );
  return sqlrc;
}



