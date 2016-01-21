#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dlfcn.h>
#include <sqlcli1.h>
#include "PaseCliInit.h"
#include "PaseCliAsync.h"

/* special SQL400 aggregate functions */
/* do common work for language driver */
/* composite calls to CLI also async  */

SQLRETURN custom_SQL400AddAttr( SQLINTEGER  scope, SQLINTEGER  attrib, SQLPOINTER  vParam, SQLINTEGER  inlen, SQLINTEGER  onerr, SQLINTEGER  flag, SQLPOINTER  options );
SQLRETURN custom_SQL400SetAttr( SQLINTEGER  scope, SQLHANDLE  hndl, SQLINTEGER  flag, SQLPOINTER  options );
SQLRETURN custom_SQL400Environment( SQLINTEGER * ohnd, SQLPOINTER  options );
SQLRETURN custom_SQL400Connect( SQLHENV  henv, SQLCHAR * db, SQLCHAR * uid, SQLCHAR * pwd, SQLINTEGER * ohnd, SQLPOINTER  options );
SQLRETURN custom_SQL400AddCParam( SQLSMALLINT  icol, SQLSMALLINT  inOutType, SQLSMALLINT  pfSqlCType, SQLPOINTER  pfSqlCValue, SQLINTEGER * indPtr, SQLPOINTER  parms );
SQLRETURN custom_SQL400AddDesc( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  flag, SQLPOINTER  descs );
SQLRETURN custom_SQL400Execute( SQLHSTMT  hstmt, SQLPOINTER  parms, SQLPOINTER  desc_parms );
SQLRETURN custom_SQL400Fetch( SQLHSTMT  hstmt, SQLINTEGER  start_row, SQLPOINTER  cols, SQLPOINTER  desc_cols );
SQLRETURN custom_SQL400Stmt2Hdbc( SQLHSTMT  hstmt, SQLINTEGER * ohnd );

static SQLRETURN (*libdb400_SQLOverrideCCSID400)( int );
static SQLRETURN (*libdb400_SQLAllocEnv)( SQLHENV* );
static SQLRETURN (*libdb400_SQLAllocConnect)( SQLHENV, SQLHDBC* );
static SQLRETURN (*libdb400_SQLAllocHandle)( SQLSMALLINT, SQLINTEGER, SQLINTEGER* );
static SQLRETURN (*libdb400_SQLAllocStmt)( SQLHDBC, SQLHSTMT* );
static SQLRETURN (*libdb400_SQLBindCol)( SQLHSTMT, SQLSMALLINT, SQLSMALLINT, SQLPOINTER, SQLINTEGER, SQLINTEGER* );
static SQLRETURN (*libdb400_SQLBindFileToCol)( SQLHSTMT, SQLSMALLINT, SQLCHAR*, SQLSMALLINT*, SQLINTEGER*, SQLSMALLINT, SQLINTEGER*, SQLINTEGER* );
static SQLRETURN (*libdb400_SQLBindFileToParam)( SQLHSTMT, SQLSMALLINT, SQLSMALLINT, SQLCHAR*, SQLSMALLINT*, SQLINTEGER*, SQLSMALLINT, SQLINTEGER* );
static SQLRETURN (*libdb400_SQLBindParam)( SQLHSTMT, SQLSMALLINT, SQLSMALLINT, SQLSMALLINT, SQLINTEGER, SQLSMALLINT, SQLPOINTER, SQLINTEGER* );
static SQLRETURN (*libdb400_SQLBindParameter)( SQLHSTMT, SQLSMALLINT, SQLSMALLINT, SQLSMALLINT, SQLSMALLINT, SQLINTEGER, SQLSMALLINT, SQLPOINTER, SQLINTEGER, SQLINTEGER* );
static SQLRETURN (*libdb400_SQLCancel)( SQLHSTMT );
static SQLRETURN (*libdb400_SQLCloseCursor)( SQLHSTMT );
static SQLRETURN (*libdb400_SQLColAttributes)( SQLHSTMT, SQLSMALLINT, SQLSMALLINT, SQLCHAR*, SQLINTEGER, SQLINTEGER*, SQLINTEGER* );
static SQLRETURN (*libdb400_SQLColumnPrivileges)( SQLHSTMT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT );
static SQLRETURN (*libdb400_SQLColumns)( SQLHSTMT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT );
static SQLRETURN (*libdb400_SQLConnect)( SQLHDBC, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT );
static SQLRETURN (*libdb400_SQLCopyDesc)( SQLHDESC, SQLHDESC );
static SQLRETURN (*libdb400_SQLDataSources)( SQLHENV, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLSMALLINT*, SQLCHAR*, SQLSMALLINT, SQLSMALLINT* );
static SQLRETURN (*libdb400_SQLDescribeCol)( SQLHSTMT, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLSMALLINT*, SQLSMALLINT*, SQLINTEGER*, SQLSMALLINT*, SQLSMALLINT* );
static SQLRETURN (*libdb400_SQLDescribeParam)( SQLHSTMT, SQLSMALLINT, SQLSMALLINT*, SQLINTEGER*, SQLSMALLINT*, SQLSMALLINT* );
static SQLRETURN (*libdb400_SQLDisconnect)( SQLHDBC );
static SQLRETURN (*libdb400_SQLDriverConnect)( SQLHDBC, SQLPOINTER, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLSMALLINT*, SQLSMALLINT );
static SQLRETURN (*libdb400_SQLEndTran)( SQLSMALLINT, SQLHENV, SQLSMALLINT );
static SQLRETURN (*libdb400_SQLError)( SQLHENV, SQLHDBC, SQLHSTMT, SQLCHAR*, SQLINTEGER*, SQLCHAR*, SQLSMALLINT, SQLSMALLINT* );
static SQLRETURN (*libdb400_SQLExecDirect)( SQLHSTMT, SQLCHAR*, SQLINTEGER );
static SQLRETURN (*libdb400_SQLExecute)( SQLHSTMT );
static SQLRETURN (*libdb400_SQLExtendedFetch)( SQLHSTMT, SQLSMALLINT, SQLINTEGER, SQLINTEGER*, SQLSMALLINT* );
static SQLRETURN (*libdb400_SQLFetch)( SQLHSTMT );
static SQLRETURN (*libdb400_SQLFetchScroll)( SQLHSTMT, SQLSMALLINT, SQLINTEGER );
static SQLRETURN (*libdb400_SQLForeignKeys)( SQLHSTMT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT );
static SQLRETURN (*libdb400_SQLFreeConnect)( SQLHDBC );
static SQLRETURN (*libdb400_SQLFreeEnv)( SQLHENV );
static SQLRETURN (*libdb400_SQLFreeHandle)( SQLSMALLINT, SQLINTEGER );
static SQLRETURN (*libdb400_SQLFreeStmt)( SQLHSTMT, SQLSMALLINT );
static SQLRETURN (*libdb400_SQLGetCol)( SQLHSTMT, SQLSMALLINT, SQLSMALLINT, SQLPOINTER, SQLINTEGER, SQLINTEGER* );
static SQLRETURN (*libdb400_SQLGetConnectAttr)( SQLHDBC, SQLINTEGER, SQLPOINTER, SQLINTEGER, SQLINTEGER* );
static SQLRETURN (*libdb400_SQLGetConnectOption)( SQLHDBC, SQLSMALLINT, SQLPOINTER );
static SQLRETURN (*libdb400_SQLGetCursorName)( SQLHSTMT, SQLCHAR*, SQLSMALLINT, SQLSMALLINT* );
static SQLRETURN (*libdb400_SQLGetData)( SQLHSTMT, SQLSMALLINT, SQLSMALLINT, SQLPOINTER, SQLINTEGER, SQLINTEGER* );
static SQLRETURN (*libdb400_SQLGetDescField)( SQLHDESC, SQLSMALLINT, SQLSMALLINT, SQLPOINTER, SQLINTEGER, SQLINTEGER* );
static SQLRETURN (*libdb400_SQLGetDescRec)( SQLHDESC, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLSMALLINT*, SQLSMALLINT*, SQLSMALLINT*, SQLINTEGER*, SQLSMALLINT*, SQLSMALLINT*, SQLSMALLINT* );
static SQLRETURN (*libdb400_SQLGetDiagField)( SQLSMALLINT, SQLINTEGER, SQLSMALLINT, SQLSMALLINT, SQLPOINTER, SQLSMALLINT, SQLSMALLINT* );
static SQLRETURN (*libdb400_SQLGetDiagRec)( SQLSMALLINT, SQLINTEGER, SQLSMALLINT, SQLCHAR*, SQLINTEGER*, SQLCHAR*, SQLSMALLINT, SQLSMALLINT* );
static SQLRETURN (*libdb400_SQLGetEnvAttr)( SQLHENV, SQLINTEGER, SQLPOINTER, SQLINTEGER, SQLINTEGER* );
static SQLRETURN (*libdb400_SQLGetFunctions)( SQLHDBC, SQLSMALLINT, SQLSMALLINT* );
static SQLRETURN (*libdb400_SQLGetInfo)( SQLHDBC, SQLSMALLINT, SQLPOINTER, SQLSMALLINT, SQLSMALLINT* );
static SQLRETURN (*libdb400_SQLGetLength)( SQLHSTMT, SQLSMALLINT, SQLINTEGER, SQLINTEGER*, SQLINTEGER* );
static SQLRETURN (*libdb400_SQLGetPosition)( SQLHSTMT, SQLSMALLINT, SQLINTEGER, SQLINTEGER, SQLCHAR*, SQLINTEGER, SQLINTEGER, SQLINTEGER*, SQLINTEGER* );
static SQLRETURN (*libdb400_SQLGetStmtAttr)( SQLHSTMT, SQLINTEGER, SQLPOINTER, SQLINTEGER, SQLINTEGER* );
static SQLRETURN (*libdb400_SQLGetStmtOption)( SQLHSTMT, SQLSMALLINT, SQLPOINTER );
static SQLRETURN (*libdb400_SQLGetSubString)( SQLHSTMT, SQLSMALLINT, SQLINTEGER, SQLINTEGER, SQLINTEGER, SQLSMALLINT, SQLPOINTER, SQLINTEGER, SQLINTEGER*, SQLINTEGER* );
static SQLRETURN (*libdb400_SQLGetTypeInfo)( SQLHSTMT, SQLSMALLINT );
static SQLRETURN (*libdb400_SQLLanguages)( SQLHSTMT );
static SQLRETURN (*libdb400_SQLMoreResults)( SQLHSTMT );
static SQLRETURN (*libdb400_SQLNativeSql)( SQLHDBC, SQLCHAR*, SQLINTEGER, SQLCHAR*, SQLINTEGER, SQLINTEGER* );
static SQLRETURN (*libdb400_SQLNextResult)( SQLHSTMT, SQLHSTMT );
static SQLRETURN (*libdb400_SQLNumParams)( SQLHSTMT, SQLSMALLINT* );
static SQLRETURN (*libdb400_SQLNumResultCols)( SQLHSTMT, SQLSMALLINT* );
static SQLRETURN (*libdb400_SQLParamData)( SQLHSTMT, SQLPOINTER* );
static SQLRETURN (*libdb400_SQLParamOptions)( SQLHSTMT, SQLINTEGER, SQLINTEGER* );
static SQLRETURN (*libdb400_SQLPrepare)( SQLHSTMT, SQLCHAR*, SQLINTEGER );
static SQLRETURN (*libdb400_SQLPrimaryKeys)( SQLHSTMT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT );
static SQLRETURN (*libdb400_SQLProcedureColumns)( SQLHSTMT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT );
static SQLRETURN (*libdb400_SQLProcedures)( SQLHSTMT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT );
static SQLRETURN (*libdb400_SQLPutData)( SQLHSTMT, SQLPOINTER, SQLINTEGER );
static SQLRETURN (*libdb400_SQLReleaseEnv)( SQLHENV );
static SQLRETURN (*libdb400_SQLRowCount)( SQLHSTMT, SQLINTEGER* );
static SQLRETURN (*libdb400_SQLSetConnectAttr)( SQLHDBC, SQLINTEGER, SQLPOINTER, SQLINTEGER );
static SQLRETURN (*libdb400_SQLSetConnectOption)( SQLHDBC, SQLSMALLINT, SQLPOINTER );
static SQLRETURN (*libdb400_SQLSetCursorName)( SQLHSTMT, SQLCHAR*, SQLSMALLINT );
static SQLRETURN (*libdb400_SQLSetDescField)( SQLHDESC, SQLSMALLINT, SQLSMALLINT, SQLPOINTER, SQLINTEGER );
static SQLRETURN (*libdb400_SQLSetDescRec)( SQLHDESC, SQLSMALLINT, SQLSMALLINT, SQLSMALLINT, SQLINTEGER, SQLSMALLINT, SQLSMALLINT, SQLPOINTER, SQLINTEGER*, SQLINTEGER* );
static SQLRETURN (*libdb400_SQLSetEnvAttr)( SQLHENV, SQLINTEGER, SQLPOINTER, SQLINTEGER );
static SQLRETURN (*libdb400_SQLSetParam)( SQLHSTMT, SQLSMALLINT, SQLSMALLINT, SQLSMALLINT, SQLINTEGER, SQLSMALLINT, SQLPOINTER, SQLINTEGER* );
static SQLRETURN (*libdb400_SQLSetStmtAttr)( SQLHSTMT, SQLINTEGER, SQLPOINTER, SQLINTEGER );
static SQLRETURN (*libdb400_SQLSetStmtOption)( SQLHSTMT, SQLSMALLINT, SQLPOINTER );
static SQLRETURN (*libdb400_SQLSpecialColumns)( SQLHSTMT, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLSMALLINT, SQLSMALLINT );
static SQLRETURN (*libdb400_SQLStartTran)( SQLSMALLINT, SQLHENV, SQLINTEGER, SQLINTEGER );
static SQLRETURN (*libdb400_SQLStatistics)( SQLHSTMT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLSMALLINT, SQLSMALLINT );
static SQLRETURN (*libdb400_SQLTablePrivileges)( SQLHSTMT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT );
static SQLRETURN (*libdb400_SQLTables)( SQLHSTMT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT );
static SQLRETURN (*libdb400_SQLTransact)( SQLHENV, SQLHDBC, SQLSMALLINT );


void load_dlsym() {
  libdb400_SQLOverrideCCSID400 = dlsym(dlhandle, "SQLOverrideCCSID400");
  libdb400_SQLAllocEnv = dlsym(dlhandle, "SQLAllocEnv");
  libdb400_SQLAllocConnect = dlsym(dlhandle, "SQLAllocConnect");
  libdb400_SQLAllocHandle = dlsym(dlhandle, "SQLAllocHandle");
  libdb400_SQLAllocStmt = dlsym(dlhandle, "SQLAllocStmt");
  libdb400_SQLBindCol = dlsym(dlhandle, "SQLBindCol");
  libdb400_SQLBindFileToCol = dlsym(dlhandle, "SQLBindFileToCol");
  libdb400_SQLBindFileToParam = dlsym(dlhandle, "SQLBindFileToParam");
  libdb400_SQLBindParam = dlsym(dlhandle, "SQLBindParam");
  libdb400_SQLBindParameter = dlsym(dlhandle, "SQLBindParameter");
  libdb400_SQLCancel = dlsym(dlhandle, "SQLCancel");
  libdb400_SQLCloseCursor = dlsym(dlhandle, "SQLCloseCursor");
  libdb400_SQLColAttributes = dlsym(dlhandle, "SQLColAttributes");
  libdb400_SQLColumnPrivileges = dlsym(dlhandle, "SQLColumnPrivileges");
  libdb400_SQLColumns = dlsym(dlhandle, "SQLColumns");
  libdb400_SQLConnect = dlsym(dlhandle, "SQLConnect");
  libdb400_SQLCopyDesc = dlsym(dlhandle, "SQLCopyDesc");
  libdb400_SQLDataSources = dlsym(dlhandle, "SQLDataSources");
  libdb400_SQLDescribeCol = dlsym(dlhandle, "SQLDescribeCol");
  libdb400_SQLDescribeParam = dlsym(dlhandle, "SQLDescribeParam");
  libdb400_SQLDisconnect = dlsym(dlhandle, "SQLDisconnect");
  libdb400_SQLDriverConnect = dlsym(dlhandle, "SQLDriverConnect");
  libdb400_SQLEndTran = dlsym(dlhandle, "SQLEndTran");
  libdb400_SQLError = dlsym(dlhandle, "SQLError");
  libdb400_SQLExecDirect = dlsym(dlhandle, "SQLExecDirect");
  libdb400_SQLExecute = dlsym(dlhandle, "SQLExecute");
  libdb400_SQLExtendedFetch = dlsym(dlhandle, "SQLExtendedFetch");
  libdb400_SQLFetch = dlsym(dlhandle, "SQLFetch");
  libdb400_SQLFetchScroll = dlsym(dlhandle, "SQLFetchScroll");
  libdb400_SQLForeignKeys = dlsym(dlhandle, "SQLForeignKeys");
  libdb400_SQLFreeConnect = dlsym(dlhandle, "SQLFreeConnect");
  libdb400_SQLFreeEnv = dlsym(dlhandle, "SQLFreeEnv");
  libdb400_SQLFreeHandle = dlsym(dlhandle, "SQLFreeHandle");
  libdb400_SQLFreeStmt = dlsym(dlhandle, "SQLFreeStmt");
  libdb400_SQLGetCol = dlsym(dlhandle, "SQLGetCol");
  libdb400_SQLGetConnectAttr = dlsym(dlhandle, "SQLGetConnectAttr");
  libdb400_SQLGetConnectOption = dlsym(dlhandle, "SQLGetConnectOption");
  libdb400_SQLGetCursorName = dlsym(dlhandle, "SQLGetCursorName");
  libdb400_SQLGetData = dlsym(dlhandle, "SQLGetData");
  libdb400_SQLGetDescField = dlsym(dlhandle, "SQLGetDescField");
  libdb400_SQLGetDescRec = dlsym(dlhandle, "SQLGetDescRec");
  libdb400_SQLGetDiagField = dlsym(dlhandle, "SQLGetDiagField");
  libdb400_SQLGetDiagRec = dlsym(dlhandle, "SQLGetDiagRec");
  libdb400_SQLGetEnvAttr = dlsym(dlhandle, "SQLGetEnvAttr");
  libdb400_SQLGetFunctions = dlsym(dlhandle, "SQLGetFunctions");
  libdb400_SQLGetInfo = dlsym(dlhandle, "SQLGetInfo");
  libdb400_SQLGetLength = dlsym(dlhandle, "SQLGetLength");
  libdb400_SQLGetPosition = dlsym(dlhandle, "SQLGetPosition");
  libdb400_SQLGetStmtAttr = dlsym(dlhandle, "SQLGetStmtAttr");
  libdb400_SQLGetStmtOption = dlsym(dlhandle, "SQLGetStmtOption");
  libdb400_SQLGetSubString = dlsym(dlhandle, "SQLGetSubString");
  libdb400_SQLGetTypeInfo = dlsym(dlhandle, "SQLGetTypeInfo");
  libdb400_SQLLanguages = dlsym(dlhandle, "SQLLanguages");
  libdb400_SQLMoreResults = dlsym(dlhandle, "SQLMoreResults");
  libdb400_SQLNativeSql = dlsym(dlhandle, "SQLNativeSql");
  libdb400_SQLNextResult = dlsym(dlhandle, "SQLNextResult");
  libdb400_SQLNumParams = dlsym(dlhandle, "SQLNumParams");
  libdb400_SQLNumResultCols = dlsym(dlhandle, "SQLNumResultCols");
  libdb400_SQLParamData = dlsym(dlhandle, "SQLParamData");
  libdb400_SQLParamOptions = dlsym(dlhandle, "SQLParamOptions");
  libdb400_SQLPrepare = dlsym(dlhandle, "SQLPrepare");
  libdb400_SQLPrimaryKeys = dlsym(dlhandle, "SQLPrimaryKeys");
  libdb400_SQLProcedureColumns = dlsym(dlhandle, "SQLProcedureColumns");
  libdb400_SQLProcedures = dlsym(dlhandle, "SQLProcedures");
  libdb400_SQLPutData = dlsym(dlhandle, "SQLPutData");
  libdb400_SQLReleaseEnv = dlsym(dlhandle, "SQLReleaseEnv");
  libdb400_SQLRowCount = dlsym(dlhandle, "SQLRowCount");
  libdb400_SQLSetConnectAttr = dlsym(dlhandle, "SQLSetConnectAttr");
  libdb400_SQLSetConnectOption = dlsym(dlhandle, "SQLSetConnectOption");
  libdb400_SQLSetCursorName = dlsym(dlhandle, "SQLSetCursorName");
  libdb400_SQLSetDescField = dlsym(dlhandle, "SQLSetDescField");
  libdb400_SQLSetDescRec = dlsym(dlhandle, "SQLSetDescRec");
  libdb400_SQLSetEnvAttr = dlsym(dlhandle, "SQLSetEnvAttr");
  libdb400_SQLSetParam = dlsym(dlhandle, "SQLSetParam");
  libdb400_SQLSetStmtAttr = dlsym(dlhandle, "SQLSetStmtAttr");
  libdb400_SQLSetStmtOption = dlsym(dlhandle, "SQLSetStmtOption");
  libdb400_SQLSpecialColumns = dlsym(dlhandle, "SQLSpecialColumns");
  libdb400_SQLStartTran = dlsym(dlhandle, "SQLStartTran");
  libdb400_SQLStatistics = dlsym(dlhandle, "SQLStatistics");
  libdb400_SQLTablePrivileges = dlsym(dlhandle, "SQLTablePrivileges");
  libdb400_SQLTables = dlsym(dlhandle, "SQLTables");
  libdb400_SQLTransact = dlsym(dlhandle, "SQLTransact");

}

int SQLOverrideCCSID400( int  newCCSID )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  sqlrc = libdb400_SQLOverrideCCSID400( newCCSID );
  return sqlrc;
}
SQLRETURN SQLAllocEnv( SQLHENV * phenv )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_lock();
  sqlrc = libdb400_SQLAllocEnv( phenv );
  if (sqlrc == SQL_SUCCESS) {
    init_table_ctor(*phenv, *phenv);
  }
  init_unlock();
  return sqlrc;
}
SQLRETURN SQLAllocConnect( SQLHENV  henv, SQLHDBC * phdbc )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_lock();
  sqlrc = libdb400_SQLAllocConnect( henv, phdbc );
  if (sqlrc == SQL_SUCCESS) {
    init_table_ctor(*phdbc, *phdbc);
  }
  init_unlock();
  return sqlrc;
}
SQLRETURN SQLAllocHandle( SQLSMALLINT  htype, SQLINTEGER  ihnd, SQLINTEGER * ohnd )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  switch (htype) {
  case SQL_HANDLE_ENV:
    init_lock();
    sqlrc = libdb400_SQLAllocHandle( htype, ihnd, ohnd );
    if (sqlrc == SQL_SUCCESS) {
      init_table_ctor(*ohnd, *ohnd);
    }
    init_unlock();
    break;
  case SQL_HANDLE_DBC:
    init_lock();
    sqlrc = libdb400_SQLAllocHandle( htype, ihnd, ohnd );
    if (sqlrc == SQL_SUCCESS) {
      init_table_ctor(*ohnd, *ohnd);
    }
    init_unlock();
    break;
  case SQL_HANDLE_STMT:
    init_lock();
    sqlrc = libdb400_SQLAllocHandle( htype, ihnd, ohnd );
    if (sqlrc == SQL_SUCCESS) {
      init_table_ctor(*ohnd, ihnd);
    }
    init_unlock();
    break;
  case SQL_HANDLE_DESC:
    init_lock();
    sqlrc = libdb400_SQLAllocHandle( htype, ihnd, ohnd );
    if (sqlrc == SQL_SUCCESS) {
      init_table_ctor(*ohnd, ihnd);
    }
    init_unlock();
    break;
  }
  return sqlrc;
}
SQLRETURN SQLAllocStmt( SQLHDBC  hdbc, SQLHSTMT * phstmt )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_lock();
  sqlrc = libdb400_SQLAllocStmt( hdbc, phstmt );
  if (sqlrc == SQL_SUCCESS) {
    init_table_ctor(*phstmt, hdbc);
  }
  init_unlock();
  return sqlrc;
}
SQLRETURN SQLBindCol( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fCType, SQLPOINTER  rgbValue, SQLINTEGER  cbValueMax, SQLINTEGER * pcbValue )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hstmt, 1);
  sqlrc = libdb400_SQLBindCol( hstmt, icol, fCType, rgbValue, cbValueMax, pcbValue );
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLBindFileToCol( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLCHAR * fName, SQLSMALLINT * fNameLen, SQLINTEGER * fOptions, SQLSMALLINT  fValueMax, SQLINTEGER * sLen, SQLINTEGER * pcbValue )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hstmt, 1);
  sqlrc = libdb400_SQLBindFileToCol( hstmt, icol, fName, fNameLen, fOptions, fValueMax, sLen, pcbValue );
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLBindFileToParam( SQLHSTMT  hstmt, SQLSMALLINT  ipar, SQLSMALLINT  iType, SQLCHAR * fName, SQLSMALLINT * fNameLen, SQLINTEGER * fOptions, SQLSMALLINT  fValueMax, SQLINTEGER * pcbValue )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hstmt, 1);
  sqlrc = libdb400_SQLBindFileToParam( hstmt, ipar, iType, fName, fNameLen, fOptions, fValueMax, pcbValue );
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLBindParam( SQLHSTMT  hstmt, SQLSMALLINT  iparm, SQLSMALLINT  iType, SQLSMALLINT  pType, SQLINTEGER  pLen, SQLSMALLINT  pScale, SQLPOINTER  pData, SQLINTEGER * pcbValue )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hstmt, 1);
  sqlrc = libdb400_SQLBindParam( hstmt, iparm, iType, pType, pLen, pScale, pData, pcbValue );
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLBindParameter( SQLHSTMT  hstmt, SQLSMALLINT  ipar, SQLSMALLINT  fParamType, SQLSMALLINT  fCType, SQLSMALLINT  fSQLType, SQLINTEGER  pLen, SQLSMALLINT  pScale, SQLPOINTER  pData, SQLINTEGER  cbValueMax, SQLINTEGER * pcbValue )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hstmt, 1);
  sqlrc = libdb400_SQLBindParameter( hstmt, ipar, fParamType, fCType, fSQLType, pLen, pScale, pData, cbValueMax, pcbValue );
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLCancel( SQLHSTMT  hstmt )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hstmt, 1);
  sqlrc = libdb400_SQLCancel( hstmt );
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLCloseCursor( SQLHSTMT  hstmt )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hstmt, 1);
  sqlrc = libdb400_SQLCloseCursor( hstmt );
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLColAttributes( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fDescType, SQLCHAR * rgbDesc, SQLINTEGER  cbDescMax, SQLINTEGER * pcbDesc, SQLINTEGER * pfDesc )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hstmt, 1);
  sqlrc = libdb400_SQLColAttributes( hstmt, icol, fDescType, rgbDesc, cbDescMax, pcbDesc, pfDesc );
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLColumnPrivileges( SQLHSTMT  hstmt, SQLCHAR * szCatalogName, SQLSMALLINT  cbCatalogName, SQLCHAR * szSchemaName, SQLSMALLINT  cbSchemaName, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLCHAR * szColumnName, SQLSMALLINT  cbColumnName )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hstmt, 1);
  sqlrc = libdb400_SQLColumnPrivileges( hstmt, szCatalogName, cbCatalogName, szSchemaName, cbSchemaName, szTableName, cbTableName, szColumnName, cbColumnName );
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLColumns( SQLHSTMT  hstmt, SQLCHAR * szCatalogName, SQLSMALLINT  cbCatalogName, SQLCHAR * szSchemaName, SQLSMALLINT  cbSchemaName, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLCHAR * szColumnName, SQLSMALLINT  cbColumnName )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hstmt, 1);
  sqlrc = libdb400_SQLColumns( hstmt, szCatalogName, cbCatalogName, szSchemaName, cbSchemaName, szTableName, cbTableName, szColumnName, cbColumnName );
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLConnect( SQLHDBC  hdbc, SQLCHAR * szDSN, SQLSMALLINT  cbDSN, SQLCHAR * szUID, SQLSMALLINT  cbUID, SQLCHAR * szAuthStr, SQLSMALLINT  cbAuthStr )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hdbc, 0);
  sqlrc = libdb400_SQLConnect( hdbc, szDSN, cbDSN, szUID, cbUID, szAuthStr, cbAuthStr );
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
SQLRETURN SQLCopyDesc( SQLHDESC  sDesc, SQLHDESC  tDesc )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(sDesc, 1);
  sqlrc = libdb400_SQLCopyDesc( sDesc, tDesc );
  init_table_unlock(sDesc, 1);
  return sqlrc;
}
SQLRETURN SQLDataSources( SQLHENV  henv, SQLSMALLINT  fDirection, SQLCHAR * szDSN, SQLSMALLINT  cbDSNMax, SQLSMALLINT * pcbDSN, SQLCHAR * szDescription, SQLSMALLINT  cbDescriptionMax, SQLSMALLINT * pcbDescription )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  sqlrc = libdb400_SQLDataSources( henv, fDirection, szDSN, cbDSNMax, pcbDSN, szDescription, cbDescriptionMax, pcbDescription );
  return sqlrc;
}
SQLRETURN SQLDescribeCol( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLCHAR * szColName, SQLSMALLINT  cbColNameMax, SQLSMALLINT * pcbColName, SQLSMALLINT * pfSqlType, SQLINTEGER * pcbColDef, SQLSMALLINT * pibScale, SQLSMALLINT * pfNullable )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hstmt, 1);
  sqlrc = libdb400_SQLDescribeCol( hstmt, icol, szColName, cbColNameMax, pcbColName, pfSqlType, pcbColDef, pibScale, pfNullable );
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLDescribeParam( SQLHSTMT  hstmt, SQLSMALLINT  ipar, SQLSMALLINT * pfSqlType, SQLINTEGER * pcbColDef, SQLSMALLINT * pibScale, SQLSMALLINT * pfNullable )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hstmt, 1);
  sqlrc = libdb400_SQLDescribeParam( hstmt, ipar, pfSqlType, pcbColDef, pibScale, pfNullable );
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLDisconnect( SQLHDBC  hdbc )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hdbc, 0);
  sqlrc = libdb400_SQLDisconnect( hdbc );
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
SQLRETURN SQLDriverConnect( SQLHDBC  hdbc, SQLPOINTER  hwnd, SQLCHAR * szConnStrIn, SQLSMALLINT  cbConnStrin, SQLCHAR * szConnStrOut, SQLSMALLINT  cbConnStrOutMax, SQLSMALLINT * pcbConnStrOut, SQLSMALLINT  fDriverCompletion )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hdbc, 0);
  sqlrc = libdb400_SQLDriverConnect( hdbc, hwnd, szConnStrIn, cbConnStrin, szConnStrOut, cbConnStrOutMax, pcbConnStrOut, fDriverCompletion );
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
SQLRETURN SQLEndTran( SQLSMALLINT  htype, SQLHENV  henv, SQLSMALLINT  ctype )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  sqlrc = libdb400_SQLEndTran( htype, henv, ctype );
  return sqlrc;
}
SQLRETURN SQLError( SQLHENV  henv, SQLHDBC  hdbc, SQLHSTMT  hstmt, SQLCHAR * szSqlState, SQLINTEGER * pfNativeError, SQLCHAR * szErrorMsg, SQLSMALLINT  cbErrorMsgMax, SQLSMALLINT * pcbErrorMsg )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  sqlrc = libdb400_SQLError( henv, hdbc, hstmt, szSqlState, pfNativeError, szErrorMsg, cbErrorMsgMax, pcbErrorMsg );
  return sqlrc;
}
SQLRETURN SQLExecDirect( SQLHSTMT  hstmt, SQLCHAR * szSqlStr, SQLINTEGER  cbSqlStr )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hstmt, 1);
  sqlrc = libdb400_SQLExecDirect( hstmt, szSqlStr, cbSqlStr );
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLExecute( SQLHSTMT  hstmt )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hstmt, 1);
  sqlrc = libdb400_SQLExecute( hstmt );
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLExtendedFetch( SQLHSTMT  hstmt, SQLSMALLINT  fOrient, SQLINTEGER  fOffset, SQLINTEGER * pcrow, SQLSMALLINT * rgfRowStatus )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hstmt, 1);
  sqlrc = libdb400_SQLExtendedFetch( hstmt, fOrient, fOffset, pcrow, rgfRowStatus );
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLFetch( SQLHSTMT  hstmt )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hstmt, 1);
  sqlrc = libdb400_SQLFetch( hstmt );
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLFetchScroll( SQLHSTMT  hstmt, SQLSMALLINT  fOrient, SQLINTEGER  fOffset )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hstmt, 1);
  sqlrc = libdb400_SQLFetchScroll( hstmt, fOrient, fOffset );
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLForeignKeys( SQLHSTMT  hstmt, SQLCHAR * szPkTableQualifier, SQLSMALLINT  cbPkTableQualifier, SQLCHAR * szPkTableOwner, SQLSMALLINT  cbPkTableOwner, SQLCHAR * szPkTableName, SQLSMALLINT  cbPkTableName, SQLCHAR * szFkTableQualifier, SQLSMALLINT  cbFkTableQualifier, SQLCHAR * szFkTableOwner, SQLSMALLINT  cbFkTableOwner, SQLCHAR * szFkTableName, SQLSMALLINT  cbFkTableName )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hstmt, 1);
  sqlrc = libdb400_SQLForeignKeys( hstmt, szPkTableQualifier, cbPkTableQualifier, szPkTableOwner, cbPkTableOwner, szPkTableName, cbPkTableName, szFkTableQualifier, cbFkTableQualifier, szFkTableOwner, cbFkTableOwner, szFkTableName, cbFkTableName );
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLFreeConnect( SQLHDBC  hdbc )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_lock();
  sqlrc = libdb400_SQLFreeConnect( hdbc );
  if (sqlrc == SQL_SUCCESS) {
    init_table_dtor(hdbc);
  }
  init_unlock();
  return sqlrc;
}
SQLRETURN SQLFreeEnv( SQLHENV  henv )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_lock();
  sqlrc = libdb400_SQLFreeEnv( henv );
  init_unlock();
  return sqlrc;
}
SQLRETURN SQLFreeHandle( SQLSMALLINT  htype, SQLINTEGER  hndl )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  switch (htype) {
  case SQL_HANDLE_ENV:
    init_lock();
    sqlrc = libdb400_SQLFreeHandle( htype, hndl );
    init_unlock();
    break;
  case SQL_HANDLE_DBC:
    init_lock();
    sqlrc = libdb400_SQLFreeHandle( htype, hndl );
    if (sqlrc == SQL_SUCCESS) {
      init_table_dtor(hndl);
    }
    init_unlock();
    break;
  case SQL_HANDLE_STMT:
    init_lock();
    sqlrc = libdb400_SQLFreeHandle( htype, hndl );
    if (sqlrc == SQL_SUCCESS) {
      init_table_dtor(hndl);
    }
    init_unlock();
    break;
  case SQL_HANDLE_DESC:
    init_lock();
    sqlrc = libdb400_SQLFreeHandle( htype, hndl );
    if (sqlrc == SQL_SUCCESS) {
      init_table_dtor(hndl);
    }
    init_unlock();
    break;
  }
  return sqlrc;
}
SQLRETURN SQLFreeStmt( SQLHSTMT  hstmt, SQLSMALLINT  fOption )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_lock();
  sqlrc = libdb400_SQLFreeStmt( hstmt, fOption );
  if (sqlrc == SQL_SUCCESS) {
    init_table_dtor(hstmt);
  }
  init_unlock();
  return sqlrc;
}
SQLRETURN SQLGetCol( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  itype, SQLPOINTER  tval, SQLINTEGER  blen, SQLINTEGER * olen )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hstmt, 1);
  sqlrc = libdb400_SQLGetCol( hstmt, icol, itype, tval, blen, olen );
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLGetConnectAttr( SQLHDBC  hdbc, SQLINTEGER  attr, SQLPOINTER  oval, SQLINTEGER  ilen, SQLINTEGER * olen )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hdbc, 0);
  sqlrc = libdb400_SQLGetConnectAttr( hdbc, attr, oval, ilen, olen );
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
SQLRETURN SQLGetConnectOption( SQLHDBC  hdbc, SQLSMALLINT  fOption, SQLPOINTER  pvParam )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hdbc, 0);
  sqlrc = libdb400_SQLGetConnectOption( hdbc, fOption, pvParam );
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
SQLRETURN SQLGetCursorName( SQLHSTMT  hstmt, SQLCHAR * szCursor, SQLSMALLINT  cbCursorMax, SQLSMALLINT * pcbCursor )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hstmt, 1);
  sqlrc = libdb400_SQLGetCursorName( hstmt, szCursor, cbCursorMax, pcbCursor );
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLGetData( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fCType, SQLPOINTER  rgbValue, SQLINTEGER  cbValueMax, SQLINTEGER * pcbValue )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hstmt, 1);
  sqlrc = libdb400_SQLGetData( hstmt, icol, fCType, rgbValue, cbValueMax, pcbValue );
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLGetDescField( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  fieldID, SQLPOINTER  fValue, SQLINTEGER  fLength, SQLINTEGER * stLength )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hdesc, 1);
  sqlrc = libdb400_SQLGetDescField( hdesc, rcdNum, fieldID, fValue, fLength, stLength );
  init_table_unlock(hdesc, 1);
  return sqlrc;
}
SQLRETURN SQLGetDescRec( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLCHAR * fname, SQLSMALLINT  bufLen, SQLSMALLINT * sLength, SQLSMALLINT * sType, SQLSMALLINT * sbType, SQLINTEGER * fLength, SQLSMALLINT * fprec, SQLSMALLINT * fscale, SQLSMALLINT * fnull )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hdesc, 1);
  sqlrc = libdb400_SQLGetDescRec( hdesc, rcdNum, fname, bufLen, sLength, sType, sbType, fLength, fprec, fscale, fnull );
  init_table_unlock(hdesc, 1);
  return sqlrc;
}
SQLRETURN SQLGetDiagField( SQLSMALLINT  hType, SQLINTEGER  hndl, SQLSMALLINT  rcdNum, SQLSMALLINT  diagID, SQLPOINTER  dValue, SQLSMALLINT  bLength, SQLSMALLINT * sLength )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  sqlrc = libdb400_SQLGetDiagField( hType, hndl, rcdNum, diagID, dValue, bLength, sLength );
  return sqlrc;
}
SQLRETURN SQLGetDiagRec( SQLSMALLINT  hType, SQLINTEGER  hndl, SQLSMALLINT  rcdNum, SQLCHAR * SQLstate, SQLINTEGER * SQLcode, SQLCHAR * msgText, SQLSMALLINT  bLength, SQLSMALLINT * sLength )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  sqlrc = libdb400_SQLGetDiagRec( hType, hndl, rcdNum, SQLstate, SQLcode, msgText, bLength, sLength );
  return sqlrc;
}
SQLRETURN SQLGetEnvAttr( SQLHENV  henv, SQLINTEGER  Attribute, SQLPOINTER  Value, SQLINTEGER  BufferLength, SQLINTEGER * StringLength )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  sqlrc = libdb400_SQLGetEnvAttr( henv, Attribute, Value, BufferLength, StringLength );
  return sqlrc;
}
SQLRETURN SQLGetFunctions( SQLHDBC  hdbc, SQLSMALLINT  fFunction, SQLSMALLINT * pfExists )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hdbc, 0);
  sqlrc = libdb400_SQLGetFunctions( hdbc, fFunction, pfExists );
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
SQLRETURN SQLGetInfo( SQLHDBC  hdbc, SQLSMALLINT  fInfoType, SQLPOINTER  rgbInfoValue, SQLSMALLINT  cbInfoValueMax, SQLSMALLINT * pcbInfoValue )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hdbc, 0);
  sqlrc = libdb400_SQLGetInfo( hdbc, fInfoType, rgbInfoValue, cbInfoValueMax, pcbInfoValue );
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
SQLRETURN SQLGetLength( SQLHSTMT  hstmt, SQLSMALLINT  locType, SQLINTEGER  locator, SQLINTEGER * sLength, SQLINTEGER * ind )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hstmt, 1);
  sqlrc = libdb400_SQLGetLength( hstmt, locType, locator, sLength, ind );
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLGetPosition( SQLHSTMT  hstmt, SQLSMALLINT  locType, SQLINTEGER  srceLocator, SQLINTEGER  srchLocator, SQLCHAR * srchLiteral, SQLINTEGER  srchLiteralLen, SQLINTEGER  fPosition, SQLINTEGER * located, SQLINTEGER * ind )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hstmt, 1);
  sqlrc = libdb400_SQLGetPosition( hstmt, locType, srceLocator, srchLocator, srchLiteral, srchLiteralLen, fPosition, located, ind );
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLGetStmtAttr( SQLHSTMT  hstmt, SQLINTEGER  fAttr, SQLPOINTER  pvParam, SQLINTEGER  bLength, SQLINTEGER * SLength )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hstmt, 1);
  sqlrc = libdb400_SQLGetStmtAttr( hstmt, fAttr, pvParam, bLength, SLength );
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLGetStmtOption( SQLHSTMT  hstmt, SQLSMALLINT  fOption, SQLPOINTER  pvParam )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hstmt, 1);
  sqlrc = libdb400_SQLGetStmtOption( hstmt, fOption, pvParam );
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLGetSubString( SQLHSTMT  hstmt, SQLSMALLINT  locType, SQLINTEGER  srceLocator, SQLINTEGER  fPosition, SQLINTEGER  length, SQLSMALLINT  tType, SQLPOINTER  rgbValue, SQLINTEGER  cbValueMax, SQLINTEGER * StringLength, SQLINTEGER * ind )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hstmt, 1);
  sqlrc = libdb400_SQLGetSubString( hstmt, locType, srceLocator, fPosition, length, tType, rgbValue, cbValueMax, StringLength, ind );
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLGetTypeInfo( SQLHSTMT  hstmt, SQLSMALLINT  fSqlType )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hstmt, 1);
  sqlrc = libdb400_SQLGetTypeInfo( hstmt, fSqlType );
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLLanguages( SQLHSTMT  hstmt )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hstmt, 1);
  sqlrc = libdb400_SQLLanguages( hstmt );
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLMoreResults( SQLHSTMT  hstmt )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hstmt, 1);
  sqlrc = libdb400_SQLMoreResults( hstmt );
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLNativeSql( SQLHDBC  hdbc, SQLCHAR * szSqlStrIn, SQLINTEGER  cbSqlStrIn, SQLCHAR * szSqlStr, SQLINTEGER  cbSqlStrMax, SQLINTEGER * pcbSqlStr )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hdbc, 0);
  sqlrc = libdb400_SQLNativeSql( hdbc, szSqlStrIn, cbSqlStrIn, szSqlStr, cbSqlStrMax, pcbSqlStr );
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
SQLRETURN SQLNextResult( SQLHSTMT  hstmt, SQLHSTMT  hstmt2 )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hstmt, 1);
  sqlrc = libdb400_SQLNextResult( hstmt, hstmt2 );
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLNumParams( SQLHSTMT  hstmt, SQLSMALLINT * pcpar )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hstmt, 1);
  sqlrc = libdb400_SQLNumParams( hstmt, pcpar );
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLNumResultCols( SQLHSTMT  hstmt, SQLSMALLINT * pccol )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hstmt, 1);
  sqlrc = libdb400_SQLNumResultCols( hstmt, pccol );
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLParamData( SQLHSTMT  hstmt, SQLPOINTER * prgbValue )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hstmt, 1);
  sqlrc = libdb400_SQLParamData( hstmt, prgbValue );
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLParamOptions( SQLHSTMT  hstmt, SQLINTEGER  crow, SQLINTEGER * pirow )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hstmt, 1);
  sqlrc = libdb400_SQLParamOptions( hstmt, crow, pirow );
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLPrepare( SQLHSTMT  hstmt, SQLCHAR * szSqlStr, SQLINTEGER  cbSqlStr )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hstmt, 1);
  sqlrc = libdb400_SQLPrepare( hstmt, szSqlStr, cbSqlStr );
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLPrimaryKeys( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hstmt, 1);
  sqlrc = libdb400_SQLPrimaryKeys( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName );
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLProcedureColumns( SQLHSTMT  hstmt, SQLCHAR * szProcQualifier, SQLSMALLINT  cbProcQualifier, SQLCHAR * szProcOwner, SQLSMALLINT  cbProcOwner, SQLCHAR * szProcName, SQLSMALLINT  cbProcName, SQLCHAR * szColumnName, SQLSMALLINT  cbColumnName )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hstmt, 1);
  sqlrc = libdb400_SQLProcedureColumns( hstmt, szProcQualifier, cbProcQualifier, szProcOwner, cbProcOwner, szProcName, cbProcName, szColumnName, cbColumnName );
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLProcedures( SQLHSTMT  hstmt, SQLCHAR * szProcQualifier, SQLSMALLINT  cbProcQualifier, SQLCHAR * szProcOwner, SQLSMALLINT  cbProcOwner, SQLCHAR * szProcName, SQLSMALLINT  cbProcName )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hstmt, 1);
  sqlrc = libdb400_SQLProcedures( hstmt, szProcQualifier, cbProcQualifier, szProcOwner, cbProcOwner, szProcName, cbProcName );
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLPutData( SQLHSTMT  hstmt, SQLPOINTER  rgbValue, SQLINTEGER  cbValue )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hstmt, 1);
  sqlrc = libdb400_SQLPutData( hstmt, rgbValue, cbValue );
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLReleaseEnv( SQLHENV  henv )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  sqlrc = libdb400_SQLReleaseEnv( henv );
  return sqlrc;
}
SQLRETURN SQLRowCount( SQLHSTMT  hstmt, SQLINTEGER * pcrow )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hstmt, 1);
  sqlrc = libdb400_SQLRowCount( hstmt, pcrow );
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLSetConnectAttr( SQLHDBC  hdbc, SQLINTEGER  attrib, SQLPOINTER  vParam, SQLINTEGER  inlen )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hdbc, 0);
  sqlrc = libdb400_SQLSetConnectAttr( hdbc, attrib, vParam, inlen );
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
SQLRETURN SQLSetConnectOption( SQLHDBC  hdbc, SQLSMALLINT  fOption, SQLPOINTER  vParam )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hdbc, 0);
  sqlrc = libdb400_SQLSetConnectOption( hdbc, fOption, vParam );
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
SQLRETURN SQLSetCursorName( SQLHSTMT  hstmt, SQLCHAR * szCursor, SQLSMALLINT  cbCursor )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hstmt, 1);
  sqlrc = libdb400_SQLSetCursorName( hstmt, szCursor, cbCursor );
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLSetDescField( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  fID, SQLPOINTER  Value, SQLINTEGER  buffLen )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hdesc, 1);
  sqlrc = libdb400_SQLSetDescField( hdesc, rcdNum, fID, Value, buffLen );
  init_table_unlock(hdesc, 1);
  return sqlrc;
}
SQLRETURN SQLSetDescRec( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  Type, SQLSMALLINT  subType, SQLINTEGER  fLength, SQLSMALLINT  fPrec, SQLSMALLINT  fScale, SQLPOINTER  Value, SQLINTEGER * sLength, SQLINTEGER * indic )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hdesc, 1);
  sqlrc = libdb400_SQLSetDescRec( hdesc, rcdNum, Type, subType, fLength, fPrec, fScale, Value, sLength, indic );
  init_table_unlock(hdesc, 1);
  return sqlrc;
}
SQLRETURN SQLSetEnvAttr( SQLHENV  henv, SQLINTEGER  Attribute, SQLPOINTER  Value, SQLINTEGER  StringLength )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  sqlrc = libdb400_SQLSetEnvAttr( henv, Attribute, Value, StringLength );
  return sqlrc;
}
SQLRETURN SQLSetParam( SQLHSTMT  hstmt, SQLSMALLINT  ipar, SQLSMALLINT  fCType, SQLSMALLINT  fSqlType, SQLINTEGER  cbParamDef, SQLSMALLINT  ibScale, SQLPOINTER  rgbValue, SQLINTEGER * pcbValue )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hstmt, 1);
  sqlrc = libdb400_SQLSetParam( hstmt, ipar, fCType, fSqlType, cbParamDef, ibScale, rgbValue, pcbValue );
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLSetStmtAttr( SQLHSTMT  hstmt, SQLINTEGER  fAttr, SQLPOINTER  pParam, SQLINTEGER  vParam )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hstmt, 1);
  sqlrc = libdb400_SQLSetStmtAttr( hstmt, fAttr, pParam, vParam );
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLSetStmtOption( SQLHSTMT  hstmt, SQLSMALLINT  fOption, SQLPOINTER  vParam )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hstmt, 1);
  sqlrc = libdb400_SQLSetStmtOption( hstmt, fOption, vParam );
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLSpecialColumns( SQLHSTMT  hstmt, SQLSMALLINT  fColType, SQLCHAR * szCatalogName, SQLSMALLINT  cbCatalogName, SQLCHAR * szSchemaName, SQLSMALLINT  cbSchemaName, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLSMALLINT  fScope, SQLSMALLINT  fNullable )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hstmt, 1);
  sqlrc = libdb400_SQLSpecialColumns( hstmt, fColType, szCatalogName, cbCatalogName, szSchemaName, cbSchemaName, szTableName, cbTableName, fScope, fNullable );
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLStartTran( SQLSMALLINT  htype, SQLHENV  henv, SQLINTEGER  mode, SQLINTEGER  clevel )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  sqlrc = libdb400_SQLStartTran( htype, henv, mode, clevel );
  return sqlrc;
}
SQLRETURN SQLStatistics( SQLHSTMT  hstmt, SQLCHAR * szCatalogName, SQLSMALLINT  cbCatalogName, SQLCHAR * szSchemaName, SQLSMALLINT  cbSchemaName, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLSMALLINT  fUnique, SQLSMALLINT  fAccuracy )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hstmt, 1);
  sqlrc = libdb400_SQLStatistics( hstmt, szCatalogName, cbCatalogName, szSchemaName, cbSchemaName, szTableName, cbTableName, fUnique, fAccuracy );
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLTablePrivileges( SQLHSTMT  hstmt, SQLCHAR * szCatalogName, SQLSMALLINT  cbCatalogName, SQLCHAR * szSchemaName, SQLSMALLINT  cbSchemaName, SQLCHAR * szTableName, SQLSMALLINT  cbTableName )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hstmt, 1);
  sqlrc = libdb400_SQLTablePrivileges( hstmt, szCatalogName, cbCatalogName, szSchemaName, cbSchemaName, szTableName, cbTableName );
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLTables( SQLHSTMT  hstmt, SQLCHAR * szCatalogName, SQLSMALLINT  cbCatalogName, SQLCHAR * szSchemaName, SQLSMALLINT  cbSchemaName, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLCHAR * szTableType, SQLSMALLINT  cbTableType )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hstmt, 1);
  sqlrc = libdb400_SQLTables( hstmt, szCatalogName, cbCatalogName, szSchemaName, cbSchemaName, szTableName, cbTableName, szTableType, cbTableType );
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLTransact( SQLHENV  henv, SQLHDBC  hdbc, SQLSMALLINT  fType )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  sqlrc = libdb400_SQLTransact( henv, hdbc, fType );
  return sqlrc;
}
SQLRETURN SQL400AddAttr( SQLINTEGER  scope, SQLINTEGER  attrib, SQLPOINTER  vParam, SQLINTEGER  inlen, SQLINTEGER  onerr, SQLINTEGER  flag, SQLPOINTER  options )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  sqlrc = custom_SQL400AddAttr( scope, attrib, vParam, inlen, onerr, flag, options );
  return sqlrc;
}
SQLRETURN SQL400SetAttr( SQLINTEGER  scope, SQLHANDLE  hndl, SQLINTEGER  flag, SQLPOINTER  options )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  sqlrc = custom_SQL400SetAttr( scope, hndl, flag, options );
  return sqlrc;
}
SQLRETURN SQL400Environment( SQLINTEGER * ohnd, SQLPOINTER  options )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  sqlrc = custom_SQL400Environment( ohnd, options );
  return sqlrc;
}
SQLRETURN SQL400Connect( SQLHENV  henv, SQLCHAR * db, SQLCHAR * uid, SQLCHAR * pwd, SQLINTEGER * ohnd, SQLPOINTER  options )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  sqlrc = custom_SQL400Connect( henv, db, uid, pwd, ohnd, options );
  return sqlrc;
}
SQLRETURN SQL400AddCParam( SQLSMALLINT  icol, SQLSMALLINT  inOutType, SQLSMALLINT  pfSqlCType, SQLPOINTER  pfSqlCValue, SQLINTEGER * indPtr, SQLPOINTER  parms )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  sqlrc = custom_SQL400AddCParam( icol, inOutType, pfSqlCType, pfSqlCValue, indPtr, parms );
  return sqlrc;
}
SQLRETURN SQL400AddDesc( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  flag, SQLPOINTER  descs )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hstmt, 1);
  sqlrc = custom_SQL400AddDesc( hstmt, icol, flag, descs );
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQL400Execute( SQLHSTMT  hstmt, SQLPOINTER  parms, SQLPOINTER  desc_parms )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hstmt, 1);
  sqlrc = custom_SQL400Execute( hstmt, parms, desc_parms );
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQL400Fetch( SQLHSTMT  hstmt, SQLINTEGER  start_row, SQLPOINTER  cols, SQLPOINTER  desc_cols )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hstmt, 1);
  sqlrc = custom_SQL400Fetch( hstmt, start_row, cols, desc_cols );
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQL400Stmt2Hdbc( SQLHSTMT  hstmt, SQLINTEGER * ohnd )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_dlsym();
  init_table_lock(hstmt, 1);
  sqlrc = custom_SQL400Stmt2Hdbc( hstmt, ohnd );
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLOverrideCCSID400Thread (void *ptr)
{
  SQLOverrideCCSID400Struct * myptr = (SQLOverrideCCSID400Struct *) ptr;
  myptr->sqlrc = libdb400_SQLOverrideCCSID400( myptr->newCCSID );
  /* void SQLOverrideCCSID400Callback(SQLOverrideCCSID400Struct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLOverrideCCSID400Struct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLOverrideCCSID400Async ( int  newCCSID, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLOverrideCCSID400Struct * myptr = (SQLOverrideCCSID400Struct *) malloc(sizeof(SQLOverrideCCSID400Struct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->newCCSID = newCCSID;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLOverrideCCSID400Thread, (void *)myptr);
  return tid;
}
SQLOverrideCCSID400Struct * SQLOverrideCCSID400Join (pthread_t tid, SQLINTEGER flag)
{
  SQLOverrideCCSID400Struct * myptr = (SQLOverrideCCSID400Struct *) NULL;
  int active = 0;
  init_dlsym();
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLOverrideCCSID400Struct *) NULL;
  }
  return myptr;
}
void * SQLBindColThread (void *ptr)
{
  SQLBindColStruct * myptr = (SQLBindColStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  myptr->sqlrc = libdb400_SQLBindCol( myptr->hstmt, myptr->icol, myptr->fCType, myptr->rgbValue, myptr->cbValueMax, myptr->pcbValue );
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLBindColCallback(SQLBindColStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLBindColStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLBindColAsync ( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fCType, SQLPOINTER  rgbValue, SQLINTEGER  cbValueMax, SQLINTEGER * pcbValue, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLBindColStruct * myptr = (SQLBindColStruct *) malloc(sizeof(SQLBindColStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->icol = icol;
  myptr->fCType = fCType;
  myptr->rgbValue = rgbValue;
  myptr->cbValueMax = cbValueMax;
  myptr->pcbValue = pcbValue;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLBindColThread, (void *)myptr);
  return tid;
}
SQLBindColStruct * SQLBindColJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLBindColStruct * myptr = (SQLBindColStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLBindColStruct *) NULL;
  }
  return myptr;
}
void * SQLBindFileToColThread (void *ptr)
{
  SQLBindFileToColStruct * myptr = (SQLBindFileToColStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  myptr->sqlrc = libdb400_SQLBindFileToCol( myptr->hstmt, myptr->icol, myptr->fName, myptr->fNameLen, myptr->fOptions, myptr->fValueMax, myptr->sLen, myptr->pcbValue );
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLBindFileToColCallback(SQLBindFileToColStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLBindFileToColStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLBindFileToColAsync ( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLCHAR * fName, SQLSMALLINT * fNameLen, SQLINTEGER * fOptions, SQLSMALLINT  fValueMax, SQLINTEGER * sLen, SQLINTEGER * pcbValue, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLBindFileToColStruct * myptr = (SQLBindFileToColStruct *) malloc(sizeof(SQLBindFileToColStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->icol = icol;
  myptr->fName = fName;
  myptr->fNameLen = fNameLen;
  myptr->fOptions = fOptions;
  myptr->fValueMax = fValueMax;
  myptr->sLen = sLen;
  myptr->pcbValue = pcbValue;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLBindFileToColThread, (void *)myptr);
  return tid;
}
SQLBindFileToColStruct * SQLBindFileToColJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLBindFileToColStruct * myptr = (SQLBindFileToColStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLBindFileToColStruct *) NULL;
  }
  return myptr;
}
void * SQLBindFileToParamThread (void *ptr)
{
  SQLBindFileToParamStruct * myptr = (SQLBindFileToParamStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  myptr->sqlrc = libdb400_SQLBindFileToParam( myptr->hstmt, myptr->ipar, myptr->iType, myptr->fName, myptr->fNameLen, myptr->fOptions, myptr->fValueMax, myptr->pcbValue );
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLBindFileToParamCallback(SQLBindFileToParamStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLBindFileToParamStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLBindFileToParamAsync ( SQLHSTMT  hstmt, SQLSMALLINT  ipar, SQLSMALLINT  iType, SQLCHAR * fName, SQLSMALLINT * fNameLen, SQLINTEGER * fOptions, SQLSMALLINT  fValueMax, SQLINTEGER * pcbValue, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLBindFileToParamStruct * myptr = (SQLBindFileToParamStruct *) malloc(sizeof(SQLBindFileToParamStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->ipar = ipar;
  myptr->iType = iType;
  myptr->fName = fName;
  myptr->fNameLen = fNameLen;
  myptr->fOptions = fOptions;
  myptr->fValueMax = fValueMax;
  myptr->pcbValue = pcbValue;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLBindFileToParamThread, (void *)myptr);
  return tid;
}
SQLBindFileToParamStruct * SQLBindFileToParamJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLBindFileToParamStruct * myptr = (SQLBindFileToParamStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLBindFileToParamStruct *) NULL;
  }
  return myptr;
}
void * SQLBindParamThread (void *ptr)
{
  SQLBindParamStruct * myptr = (SQLBindParamStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  myptr->sqlrc = libdb400_SQLBindParam( myptr->hstmt, myptr->iparm, myptr->iType, myptr->pType, myptr->pLen, myptr->pScale, myptr->pData, myptr->pcbValue );
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLBindParamCallback(SQLBindParamStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLBindParamStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLBindParamAsync ( SQLHSTMT  hstmt, SQLSMALLINT  iparm, SQLSMALLINT  iType, SQLSMALLINT  pType, SQLINTEGER  pLen, SQLSMALLINT  pScale, SQLPOINTER  pData, SQLINTEGER * pcbValue, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLBindParamStruct * myptr = (SQLBindParamStruct *) malloc(sizeof(SQLBindParamStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->iparm = iparm;
  myptr->iType = iType;
  myptr->pType = pType;
  myptr->pLen = pLen;
  myptr->pScale = pScale;
  myptr->pData = pData;
  myptr->pcbValue = pcbValue;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLBindParamThread, (void *)myptr);
  return tid;
}
SQLBindParamStruct * SQLBindParamJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLBindParamStruct * myptr = (SQLBindParamStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLBindParamStruct *) NULL;
  }
  return myptr;
}
void * SQLBindParameterThread (void *ptr)
{
  SQLBindParameterStruct * myptr = (SQLBindParameterStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  myptr->sqlrc = libdb400_SQLBindParameter( myptr->hstmt, myptr->ipar, myptr->fParamType, myptr->fCType, myptr->fSQLType, myptr->pLen, myptr->pScale, myptr->pData, myptr->cbValueMax, myptr->pcbValue );
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLBindParameterCallback(SQLBindParameterStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLBindParameterStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLBindParameterAsync ( SQLHSTMT  hstmt, SQLSMALLINT  ipar, SQLSMALLINT  fParamType, SQLSMALLINT  fCType, SQLSMALLINT  fSQLType, SQLINTEGER  pLen, SQLSMALLINT  pScale, SQLPOINTER  pData, SQLINTEGER  cbValueMax, SQLINTEGER * pcbValue, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLBindParameterStruct * myptr = (SQLBindParameterStruct *) malloc(sizeof(SQLBindParameterStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->ipar = ipar;
  myptr->fParamType = fParamType;
  myptr->fCType = fCType;
  myptr->fSQLType = fSQLType;
  myptr->pLen = pLen;
  myptr->pScale = pScale;
  myptr->pData = pData;
  myptr->cbValueMax = cbValueMax;
  myptr->pcbValue = pcbValue;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLBindParameterThread, (void *)myptr);
  return tid;
}
SQLBindParameterStruct * SQLBindParameterJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLBindParameterStruct * myptr = (SQLBindParameterStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLBindParameterStruct *) NULL;
  }
  return myptr;
}
void * SQLCancelThread (void *ptr)
{
  SQLCancelStruct * myptr = (SQLCancelStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  myptr->sqlrc = libdb400_SQLCancel( myptr->hstmt );
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLCancelCallback(SQLCancelStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLCancelStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLCancelAsync ( SQLHSTMT  hstmt, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLCancelStruct * myptr = (SQLCancelStruct *) malloc(sizeof(SQLCancelStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLCancelThread, (void *)myptr);
  return tid;
}
SQLCancelStruct * SQLCancelJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLCancelStruct * myptr = (SQLCancelStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLCancelStruct *) NULL;
  }
  return myptr;
}
void * SQLCloseCursorThread (void *ptr)
{
  SQLCloseCursorStruct * myptr = (SQLCloseCursorStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  myptr->sqlrc = libdb400_SQLCloseCursor( myptr->hstmt );
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLCloseCursorCallback(SQLCloseCursorStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLCloseCursorStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLCloseCursorAsync ( SQLHSTMT  hstmt, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLCloseCursorStruct * myptr = (SQLCloseCursorStruct *) malloc(sizeof(SQLCloseCursorStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLCloseCursorThread, (void *)myptr);
  return tid;
}
SQLCloseCursorStruct * SQLCloseCursorJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLCloseCursorStruct * myptr = (SQLCloseCursorStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLCloseCursorStruct *) NULL;
  }
  return myptr;
}
void * SQLColAttributesThread (void *ptr)
{
  SQLColAttributesStruct * myptr = (SQLColAttributesStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  myptr->sqlrc = libdb400_SQLColAttributes( myptr->hstmt, myptr->icol, myptr->fDescType, myptr->rgbDesc, myptr->cbDescMax, myptr->pcbDesc, myptr->pfDesc );
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLColAttributesCallback(SQLColAttributesStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLColAttributesStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLColAttributesAsync ( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fDescType, SQLCHAR * rgbDesc, SQLINTEGER  cbDescMax, SQLINTEGER * pcbDesc, SQLINTEGER * pfDesc, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLColAttributesStruct * myptr = (SQLColAttributesStruct *) malloc(sizeof(SQLColAttributesStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->icol = icol;
  myptr->fDescType = fDescType;
  myptr->rgbDesc = rgbDesc;
  myptr->cbDescMax = cbDescMax;
  myptr->pcbDesc = pcbDesc;
  myptr->pfDesc = pfDesc;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLColAttributesThread, (void *)myptr);
  return tid;
}
SQLColAttributesStruct * SQLColAttributesJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLColAttributesStruct * myptr = (SQLColAttributesStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLColAttributesStruct *) NULL;
  }
  return myptr;
}
void * SQLColumnPrivilegesThread (void *ptr)
{
  SQLColumnPrivilegesStruct * myptr = (SQLColumnPrivilegesStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  myptr->sqlrc = libdb400_SQLColumnPrivileges( myptr->hstmt, myptr->szCatalogName, myptr->cbCatalogName, myptr->szSchemaName, myptr->cbSchemaName, myptr->szTableName, myptr->cbTableName, myptr->szColumnName, myptr->cbColumnName );
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLColumnPrivilegesCallback(SQLColumnPrivilegesStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLColumnPrivilegesStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLColumnPrivilegesAsync ( SQLHSTMT  hstmt, SQLCHAR * szCatalogName, SQLSMALLINT  cbCatalogName, SQLCHAR * szSchemaName, SQLSMALLINT  cbSchemaName, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLCHAR * szColumnName, SQLSMALLINT  cbColumnName, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLColumnPrivilegesStruct * myptr = (SQLColumnPrivilegesStruct *) malloc(sizeof(SQLColumnPrivilegesStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->szCatalogName = szCatalogName;
  myptr->cbCatalogName = cbCatalogName;
  myptr->szSchemaName = szSchemaName;
  myptr->cbSchemaName = cbSchemaName;
  myptr->szTableName = szTableName;
  myptr->cbTableName = cbTableName;
  myptr->szColumnName = szColumnName;
  myptr->cbColumnName = cbColumnName;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLColumnPrivilegesThread, (void *)myptr);
  return tid;
}
SQLColumnPrivilegesStruct * SQLColumnPrivilegesJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLColumnPrivilegesStruct * myptr = (SQLColumnPrivilegesStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLColumnPrivilegesStruct *) NULL;
  }
  return myptr;
}
void * SQLColumnsThread (void *ptr)
{
  SQLColumnsStruct * myptr = (SQLColumnsStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  myptr->sqlrc = libdb400_SQLColumns( myptr->hstmt, myptr->szCatalogName, myptr->cbCatalogName, myptr->szSchemaName, myptr->cbSchemaName, myptr->szTableName, myptr->cbTableName, myptr->szColumnName, myptr->cbColumnName );
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLColumnsCallback(SQLColumnsStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLColumnsStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLColumnsAsync ( SQLHSTMT  hstmt, SQLCHAR * szCatalogName, SQLSMALLINT  cbCatalogName, SQLCHAR * szSchemaName, SQLSMALLINT  cbSchemaName, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLCHAR * szColumnName, SQLSMALLINT  cbColumnName, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLColumnsStruct * myptr = (SQLColumnsStruct *) malloc(sizeof(SQLColumnsStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->szCatalogName = szCatalogName;
  myptr->cbCatalogName = cbCatalogName;
  myptr->szSchemaName = szSchemaName;
  myptr->cbSchemaName = cbSchemaName;
  myptr->szTableName = szTableName;
  myptr->cbTableName = cbTableName;
  myptr->szColumnName = szColumnName;
  myptr->cbColumnName = cbColumnName;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLColumnsThread, (void *)myptr);
  return tid;
}
SQLColumnsStruct * SQLColumnsJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLColumnsStruct * myptr = (SQLColumnsStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLColumnsStruct *) NULL;
  }
  return myptr;
}
void * SQLConnectThread (void *ptr)
{
  SQLConnectStruct * myptr = (SQLConnectStruct *) ptr;
  init_table_lock(myptr->hdbc, 0);
  myptr->sqlrc = libdb400_SQLConnect( myptr->hdbc, myptr->szDSN, myptr->cbDSN, myptr->szUID, myptr->cbUID, myptr->szAuthStr, myptr->cbAuthStr );
  init_table_unlock(myptr->hdbc, 0);
  /* void SQLConnectCallback(SQLConnectStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLConnectStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLConnectAsync ( SQLHDBC  hdbc, SQLCHAR * szDSN, SQLSMALLINT  cbDSN, SQLCHAR * szUID, SQLSMALLINT  cbUID, SQLCHAR * szAuthStr, SQLSMALLINT  cbAuthStr, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLConnectStruct * myptr = (SQLConnectStruct *) malloc(sizeof(SQLConnectStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdbc = hdbc;
  myptr->szDSN = szDSN;
  myptr->cbDSN = cbDSN;
  myptr->szUID = szUID;
  myptr->cbUID = cbUID;
  myptr->szAuthStr = szAuthStr;
  myptr->cbAuthStr = cbAuthStr;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLConnectThread, (void *)myptr);
  return tid;
}
SQLConnectStruct * SQLConnectJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLConnectStruct * myptr = (SQLConnectStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hdbc, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLConnectStruct *) NULL;
  }
  return myptr;
}
void * SQLCopyDescThread (void *ptr)
{
  SQLCopyDescStruct * myptr = (SQLCopyDescStruct *) ptr;
  init_table_lock(myptr->sDesc, 1);
  myptr->sqlrc = libdb400_SQLCopyDesc( myptr->sDesc, myptr->tDesc );
  init_table_unlock(myptr->sDesc, 1);
  /* void SQLCopyDescCallback(SQLCopyDescStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLCopyDescStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLCopyDescAsync ( SQLHDESC  sDesc, SQLHDESC  tDesc, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLCopyDescStruct * myptr = (SQLCopyDescStruct *) malloc(sizeof(SQLCopyDescStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->sDesc = sDesc;
  myptr->tDesc = tDesc;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLCopyDescThread, (void *)myptr);
  return tid;
}
SQLCopyDescStruct * SQLCopyDescJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLCopyDescStruct * myptr = (SQLCopyDescStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->sDesc, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLCopyDescStruct *) NULL;
  }
  return myptr;
}
void * SQLDataSourcesThread (void *ptr)
{
  SQLDataSourcesStruct * myptr = (SQLDataSourcesStruct *) ptr;
  /* not lock */
  myptr->sqlrc = libdb400_SQLDataSources( myptr->henv, myptr->fDirection, myptr->szDSN, myptr->cbDSNMax, myptr->pcbDSN, myptr->szDescription, myptr->cbDescriptionMax, myptr->pcbDescription );
  /* not lock */
  /* void SQLDataSourcesCallback(SQLDataSourcesStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLDataSourcesStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLDataSourcesAsync ( SQLHENV  henv, SQLSMALLINT  fDirection, SQLCHAR * szDSN, SQLSMALLINT  cbDSNMax, SQLSMALLINT * pcbDSN, SQLCHAR * szDescription, SQLSMALLINT  cbDescriptionMax, SQLSMALLINT * pcbDescription, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLDataSourcesStruct * myptr = (SQLDataSourcesStruct *) malloc(sizeof(SQLDataSourcesStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->henv = henv;
  myptr->fDirection = fDirection;
  myptr->szDSN = szDSN;
  myptr->cbDSNMax = cbDSNMax;
  myptr->pcbDSN = pcbDSN;
  myptr->szDescription = szDescription;
  myptr->cbDescriptionMax = cbDescriptionMax;
  myptr->pcbDescription = pcbDescription;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLDataSourcesThread, (void *)myptr);
  return tid;
}
SQLDataSourcesStruct * SQLDataSourcesJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLDataSourcesStruct * myptr = (SQLDataSourcesStruct *) NULL;
  int active = 0;
  init_dlsym();
  /* not lock */
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLDataSourcesStruct *) NULL;
  }
  return myptr;
}
void * SQLDescribeColThread (void *ptr)
{
  SQLDescribeColStruct * myptr = (SQLDescribeColStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  myptr->sqlrc = libdb400_SQLDescribeCol( myptr->hstmt, myptr->icol, myptr->szColName, myptr->cbColNameMax, myptr->pcbColName, myptr->pfSqlType, myptr->pcbColDef, myptr->pibScale, myptr->pfNullable );
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLDescribeColCallback(SQLDescribeColStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLDescribeColStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLDescribeColAsync ( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLCHAR * szColName, SQLSMALLINT  cbColNameMax, SQLSMALLINT * pcbColName, SQLSMALLINT * pfSqlType, SQLINTEGER * pcbColDef, SQLSMALLINT * pibScale, SQLSMALLINT * pfNullable, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLDescribeColStruct * myptr = (SQLDescribeColStruct *) malloc(sizeof(SQLDescribeColStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->icol = icol;
  myptr->szColName = szColName;
  myptr->cbColNameMax = cbColNameMax;
  myptr->pcbColName = pcbColName;
  myptr->pfSqlType = pfSqlType;
  myptr->pcbColDef = pcbColDef;
  myptr->pibScale = pibScale;
  myptr->pfNullable = pfNullable;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLDescribeColThread, (void *)myptr);
  return tid;
}
SQLDescribeColStruct * SQLDescribeColJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLDescribeColStruct * myptr = (SQLDescribeColStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLDescribeColStruct *) NULL;
  }
  return myptr;
}
void * SQLDescribeParamThread (void *ptr)
{
  SQLDescribeParamStruct * myptr = (SQLDescribeParamStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  myptr->sqlrc = libdb400_SQLDescribeParam( myptr->hstmt, myptr->ipar, myptr->pfSqlType, myptr->pcbColDef, myptr->pibScale, myptr->pfNullable );
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLDescribeParamCallback(SQLDescribeParamStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLDescribeParamStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLDescribeParamAsync ( SQLHSTMT  hstmt, SQLSMALLINT  ipar, SQLSMALLINT * pfSqlType, SQLINTEGER * pcbColDef, SQLSMALLINT * pibScale, SQLSMALLINT * pfNullable, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLDescribeParamStruct * myptr = (SQLDescribeParamStruct *) malloc(sizeof(SQLDescribeParamStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->ipar = ipar;
  myptr->pfSqlType = pfSqlType;
  myptr->pcbColDef = pcbColDef;
  myptr->pibScale = pibScale;
  myptr->pfNullable = pfNullable;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLDescribeParamThread, (void *)myptr);
  return tid;
}
SQLDescribeParamStruct * SQLDescribeParamJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLDescribeParamStruct * myptr = (SQLDescribeParamStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLDescribeParamStruct *) NULL;
  }
  return myptr;
}
void * SQLDisconnectThread (void *ptr)
{
  SQLDisconnectStruct * myptr = (SQLDisconnectStruct *) ptr;
  init_table_lock(myptr->hdbc, 0);
  myptr->sqlrc = libdb400_SQLDisconnect( myptr->hdbc );
  init_table_unlock(myptr->hdbc, 0);
  /* void SQLDisconnectCallback(SQLDisconnectStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLDisconnectStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLDisconnectAsync ( SQLHDBC  hdbc, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLDisconnectStruct * myptr = (SQLDisconnectStruct *) malloc(sizeof(SQLDisconnectStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdbc = hdbc;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLDisconnectThread, (void *)myptr);
  return tid;
}
SQLDisconnectStruct * SQLDisconnectJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLDisconnectStruct * myptr = (SQLDisconnectStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hdbc, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLDisconnectStruct *) NULL;
  }
  return myptr;
}
void * SQLDriverConnectThread (void *ptr)
{
  SQLDriverConnectStruct * myptr = (SQLDriverConnectStruct *) ptr;
  init_table_lock(myptr->hdbc, 0);
  myptr->sqlrc = libdb400_SQLDriverConnect( myptr->hdbc, myptr->hwnd, myptr->szConnStrIn, myptr->cbConnStrin, myptr->szConnStrOut, myptr->cbConnStrOutMax, myptr->pcbConnStrOut, myptr->fDriverCompletion );
  init_table_unlock(myptr->hdbc, 0);
  /* void SQLDriverConnectCallback(SQLDriverConnectStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLDriverConnectStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLDriverConnectAsync ( SQLHDBC  hdbc, SQLPOINTER  hwnd, SQLCHAR * szConnStrIn, SQLSMALLINT  cbConnStrin, SQLCHAR * szConnStrOut, SQLSMALLINT  cbConnStrOutMax, SQLSMALLINT * pcbConnStrOut, SQLSMALLINT  fDriverCompletion, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLDriverConnectStruct * myptr = (SQLDriverConnectStruct *) malloc(sizeof(SQLDriverConnectStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdbc = hdbc;
  myptr->hwnd = hwnd;
  myptr->szConnStrIn = szConnStrIn;
  myptr->cbConnStrin = cbConnStrin;
  myptr->szConnStrOut = szConnStrOut;
  myptr->cbConnStrOutMax = cbConnStrOutMax;
  myptr->pcbConnStrOut = pcbConnStrOut;
  myptr->fDriverCompletion = fDriverCompletion;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLDriverConnectThread, (void *)myptr);
  return tid;
}
SQLDriverConnectStruct * SQLDriverConnectJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLDriverConnectStruct * myptr = (SQLDriverConnectStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hdbc, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLDriverConnectStruct *) NULL;
  }
  return myptr;
}
void * SQLEndTranThread (void *ptr)
{
  SQLEndTranStruct * myptr = (SQLEndTranStruct *) ptr;
  myptr->sqlrc = libdb400_SQLEndTran( myptr->htype, myptr->henv, myptr->ctype );
  /* void SQLEndTranCallback(SQLEndTranStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLEndTranStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLEndTranAsync ( SQLSMALLINT  htype, SQLHENV  henv, SQLSMALLINT  ctype, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLEndTranStruct * myptr = (SQLEndTranStruct *) malloc(sizeof(SQLEndTranStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->htype = htype;
  myptr->henv = henv;
  myptr->ctype = ctype;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLEndTranThread, (void *)myptr);
  return tid;
}
SQLEndTranStruct * SQLEndTranJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLEndTranStruct * myptr = (SQLEndTranStruct *) NULL;
  int active = 0;
  init_dlsym();
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLEndTranStruct *) NULL;
  }
  return myptr;
}
void * SQLErrorThread (void *ptr)
{
  SQLErrorStruct * myptr = (SQLErrorStruct *) ptr;
  /* not lock */
  myptr->sqlrc = libdb400_SQLError( myptr->henv, myptr->hdbc, myptr->hstmt, myptr->szSqlState, myptr->pfNativeError, myptr->szErrorMsg, myptr->cbErrorMsgMax, myptr->pcbErrorMsg );
  /* not lock */
  /* void SQLErrorCallback(SQLErrorStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLErrorStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLErrorAsync ( SQLHENV  henv, SQLHDBC  hdbc, SQLHSTMT  hstmt, SQLCHAR * szSqlState, SQLINTEGER * pfNativeError, SQLCHAR * szErrorMsg, SQLSMALLINT  cbErrorMsgMax, SQLSMALLINT * pcbErrorMsg, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLErrorStruct * myptr = (SQLErrorStruct *) malloc(sizeof(SQLErrorStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->henv = henv;
  myptr->hdbc = hdbc;
  myptr->hstmt = hstmt;
  myptr->szSqlState = szSqlState;
  myptr->pfNativeError = pfNativeError;
  myptr->szErrorMsg = szErrorMsg;
  myptr->cbErrorMsgMax = cbErrorMsgMax;
  myptr->pcbErrorMsg = pcbErrorMsg;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLErrorThread, (void *)myptr);
  return tid;
}
SQLErrorStruct * SQLErrorJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLErrorStruct * myptr = (SQLErrorStruct *) NULL;
  int active = 0;
  init_dlsym();
  /* not lock */
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLErrorStruct *) NULL;
  }
  return myptr;
}
void * SQLExecDirectThread (void *ptr)
{
  SQLExecDirectStruct * myptr = (SQLExecDirectStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  myptr->sqlrc = libdb400_SQLExecDirect( myptr->hstmt, myptr->szSqlStr, myptr->cbSqlStr );
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLExecDirectCallback(SQLExecDirectStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLExecDirectStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLExecDirectAsync ( SQLHSTMT  hstmt, SQLCHAR * szSqlStr, SQLINTEGER  cbSqlStr, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLExecDirectStruct * myptr = (SQLExecDirectStruct *) malloc(sizeof(SQLExecDirectStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->szSqlStr = szSqlStr;
  myptr->cbSqlStr = cbSqlStr;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLExecDirectThread, (void *)myptr);
  return tid;
}
SQLExecDirectStruct * SQLExecDirectJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLExecDirectStruct * myptr = (SQLExecDirectStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLExecDirectStruct *) NULL;
  }
  return myptr;
}
void * SQLExecuteThread (void *ptr)
{
  SQLExecuteStruct * myptr = (SQLExecuteStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  myptr->sqlrc = libdb400_SQLExecute( myptr->hstmt );
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLExecuteCallback(SQLExecuteStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLExecuteStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLExecuteAsync ( SQLHSTMT  hstmt, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLExecuteStruct * myptr = (SQLExecuteStruct *) malloc(sizeof(SQLExecuteStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLExecuteThread, (void *)myptr);
  return tid;
}
SQLExecuteStruct * SQLExecuteJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLExecuteStruct * myptr = (SQLExecuteStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLExecuteStruct *) NULL;
  }
  return myptr;
}
void * SQLExtendedFetchThread (void *ptr)
{
  SQLExtendedFetchStruct * myptr = (SQLExtendedFetchStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  myptr->sqlrc = libdb400_SQLExtendedFetch( myptr->hstmt, myptr->fOrient, myptr->fOffset, myptr->pcrow, myptr->rgfRowStatus );
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLExtendedFetchCallback(SQLExtendedFetchStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLExtendedFetchStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLExtendedFetchAsync ( SQLHSTMT  hstmt, SQLSMALLINT  fOrient, SQLINTEGER  fOffset, SQLINTEGER * pcrow, SQLSMALLINT * rgfRowStatus, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLExtendedFetchStruct * myptr = (SQLExtendedFetchStruct *) malloc(sizeof(SQLExtendedFetchStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->fOrient = fOrient;
  myptr->fOffset = fOffset;
  myptr->pcrow = pcrow;
  myptr->rgfRowStatus = rgfRowStatus;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLExtendedFetchThread, (void *)myptr);
  return tid;
}
SQLExtendedFetchStruct * SQLExtendedFetchJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLExtendedFetchStruct * myptr = (SQLExtendedFetchStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLExtendedFetchStruct *) NULL;
  }
  return myptr;
}
void * SQLFetchThread (void *ptr)
{
  SQLFetchStruct * myptr = (SQLFetchStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  myptr->sqlrc = libdb400_SQLFetch( myptr->hstmt );
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLFetchCallback(SQLFetchStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLFetchStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLFetchAsync ( SQLHSTMT  hstmt, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLFetchStruct * myptr = (SQLFetchStruct *) malloc(sizeof(SQLFetchStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLFetchThread, (void *)myptr);
  return tid;
}
SQLFetchStruct * SQLFetchJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLFetchStruct * myptr = (SQLFetchStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLFetchStruct *) NULL;
  }
  return myptr;
}
void * SQLFetchScrollThread (void *ptr)
{
  SQLFetchScrollStruct * myptr = (SQLFetchScrollStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  myptr->sqlrc = libdb400_SQLFetchScroll( myptr->hstmt, myptr->fOrient, myptr->fOffset );
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLFetchScrollCallback(SQLFetchScrollStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLFetchScrollStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLFetchScrollAsync ( SQLHSTMT  hstmt, SQLSMALLINT  fOrient, SQLINTEGER  fOffset, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLFetchScrollStruct * myptr = (SQLFetchScrollStruct *) malloc(sizeof(SQLFetchScrollStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->fOrient = fOrient;
  myptr->fOffset = fOffset;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLFetchScrollThread, (void *)myptr);
  return tid;
}
SQLFetchScrollStruct * SQLFetchScrollJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLFetchScrollStruct * myptr = (SQLFetchScrollStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLFetchScrollStruct *) NULL;
  }
  return myptr;
}
void * SQLForeignKeysThread (void *ptr)
{
  SQLForeignKeysStruct * myptr = (SQLForeignKeysStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  myptr->sqlrc = libdb400_SQLForeignKeys( myptr->hstmt, myptr->szPkTableQualifier, myptr->cbPkTableQualifier, myptr->szPkTableOwner, myptr->cbPkTableOwner, myptr->szPkTableName, myptr->cbPkTableName, myptr->szFkTableQualifier, myptr->cbFkTableQualifier, myptr->szFkTableOwner, myptr->cbFkTableOwner, myptr->szFkTableName, myptr->cbFkTableName );
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLForeignKeysCallback(SQLForeignKeysStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLForeignKeysStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLForeignKeysAsync ( SQLHSTMT  hstmt, SQLCHAR * szPkTableQualifier, SQLSMALLINT  cbPkTableQualifier, SQLCHAR * szPkTableOwner, SQLSMALLINT  cbPkTableOwner, SQLCHAR * szPkTableName, SQLSMALLINT  cbPkTableName, SQLCHAR * szFkTableQualifier, SQLSMALLINT  cbFkTableQualifier, SQLCHAR * szFkTableOwner, SQLSMALLINT  cbFkTableOwner, SQLCHAR * szFkTableName, SQLSMALLINT  cbFkTableName, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLForeignKeysStruct * myptr = (SQLForeignKeysStruct *) malloc(sizeof(SQLForeignKeysStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->szPkTableQualifier = szPkTableQualifier;
  myptr->cbPkTableQualifier = cbPkTableQualifier;
  myptr->szPkTableOwner = szPkTableOwner;
  myptr->cbPkTableOwner = cbPkTableOwner;
  myptr->szPkTableName = szPkTableName;
  myptr->cbPkTableName = cbPkTableName;
  myptr->szFkTableQualifier = szFkTableQualifier;
  myptr->cbFkTableQualifier = cbFkTableQualifier;
  myptr->szFkTableOwner = szFkTableOwner;
  myptr->cbFkTableOwner = cbFkTableOwner;
  myptr->szFkTableName = szFkTableName;
  myptr->cbFkTableName = cbFkTableName;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLForeignKeysThread, (void *)myptr);
  return tid;
}
SQLForeignKeysStruct * SQLForeignKeysJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLForeignKeysStruct * myptr = (SQLForeignKeysStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLForeignKeysStruct *) NULL;
  }
  return myptr;
}
void * SQLGetColThread (void *ptr)
{
  SQLGetColStruct * myptr = (SQLGetColStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  myptr->sqlrc = libdb400_SQLGetCol( myptr->hstmt, myptr->icol, myptr->itype, myptr->tval, myptr->blen, myptr->olen );
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLGetColCallback(SQLGetColStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetColStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetColAsync ( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  itype, SQLPOINTER  tval, SQLINTEGER  blen, SQLINTEGER * olen, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetColStruct * myptr = (SQLGetColStruct *) malloc(sizeof(SQLGetColStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->icol = icol;
  myptr->itype = itype;
  myptr->tval = tval;
  myptr->blen = blen;
  myptr->olen = olen;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetColThread, (void *)myptr);
  return tid;
}
SQLGetColStruct * SQLGetColJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetColStruct * myptr = (SQLGetColStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetColStruct *) NULL;
  }
  return myptr;
}
void * SQLGetConnectAttrThread (void *ptr)
{
  SQLGetConnectAttrStruct * myptr = (SQLGetConnectAttrStruct *) ptr;
  init_table_lock(myptr->hdbc, 0);
  myptr->sqlrc = libdb400_SQLGetConnectAttr( myptr->hdbc, myptr->attr, myptr->oval, myptr->ilen, myptr->olen );
  init_table_unlock(myptr->hdbc, 0);
  /* void SQLGetConnectAttrCallback(SQLGetConnectAttrStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetConnectAttrStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetConnectAttrAsync ( SQLHDBC  hdbc, SQLINTEGER  attr, SQLPOINTER  oval, SQLINTEGER  ilen, SQLINTEGER * olen, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetConnectAttrStruct * myptr = (SQLGetConnectAttrStruct *) malloc(sizeof(SQLGetConnectAttrStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdbc = hdbc;
  myptr->attr = attr;
  myptr->oval = oval;
  myptr->ilen = ilen;
  myptr->olen = olen;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetConnectAttrThread, (void *)myptr);
  return tid;
}
SQLGetConnectAttrStruct * SQLGetConnectAttrJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetConnectAttrStruct * myptr = (SQLGetConnectAttrStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hdbc, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetConnectAttrStruct *) NULL;
  }
  return myptr;
}
void * SQLGetConnectOptionThread (void *ptr)
{
  SQLGetConnectOptionStruct * myptr = (SQLGetConnectOptionStruct *) ptr;
  init_table_lock(myptr->hdbc, 0);
  myptr->sqlrc = libdb400_SQLGetConnectOption( myptr->hdbc, myptr->fOption, myptr->pvParam );
  init_table_unlock(myptr->hdbc, 0);
  /* void SQLGetConnectOptionCallback(SQLGetConnectOptionStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetConnectOptionStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetConnectOptionAsync ( SQLHDBC  hdbc, SQLSMALLINT  fOption, SQLPOINTER  pvParam, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetConnectOptionStruct * myptr = (SQLGetConnectOptionStruct *) malloc(sizeof(SQLGetConnectOptionStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdbc = hdbc;
  myptr->fOption = fOption;
  myptr->pvParam = pvParam;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetConnectOptionThread, (void *)myptr);
  return tid;
}
SQLGetConnectOptionStruct * SQLGetConnectOptionJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetConnectOptionStruct * myptr = (SQLGetConnectOptionStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hdbc, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetConnectOptionStruct *) NULL;
  }
  return myptr;
}
void * SQLGetCursorNameThread (void *ptr)
{
  SQLGetCursorNameStruct * myptr = (SQLGetCursorNameStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  myptr->sqlrc = libdb400_SQLGetCursorName( myptr->hstmt, myptr->szCursor, myptr->cbCursorMax, myptr->pcbCursor );
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLGetCursorNameCallback(SQLGetCursorNameStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetCursorNameStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetCursorNameAsync ( SQLHSTMT  hstmt, SQLCHAR * szCursor, SQLSMALLINT  cbCursorMax, SQLSMALLINT * pcbCursor, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetCursorNameStruct * myptr = (SQLGetCursorNameStruct *) malloc(sizeof(SQLGetCursorNameStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->szCursor = szCursor;
  myptr->cbCursorMax = cbCursorMax;
  myptr->pcbCursor = pcbCursor;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetCursorNameThread, (void *)myptr);
  return tid;
}
SQLGetCursorNameStruct * SQLGetCursorNameJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetCursorNameStruct * myptr = (SQLGetCursorNameStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetCursorNameStruct *) NULL;
  }
  return myptr;
}
void * SQLGetDataThread (void *ptr)
{
  SQLGetDataStruct * myptr = (SQLGetDataStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  myptr->sqlrc = libdb400_SQLGetData( myptr->hstmt, myptr->icol, myptr->fCType, myptr->rgbValue, myptr->cbValueMax, myptr->pcbValue );
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLGetDataCallback(SQLGetDataStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetDataStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetDataAsync ( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fCType, SQLPOINTER  rgbValue, SQLINTEGER  cbValueMax, SQLINTEGER * pcbValue, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetDataStruct * myptr = (SQLGetDataStruct *) malloc(sizeof(SQLGetDataStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->icol = icol;
  myptr->fCType = fCType;
  myptr->rgbValue = rgbValue;
  myptr->cbValueMax = cbValueMax;
  myptr->pcbValue = pcbValue;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetDataThread, (void *)myptr);
  return tid;
}
SQLGetDataStruct * SQLGetDataJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetDataStruct * myptr = (SQLGetDataStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetDataStruct *) NULL;
  }
  return myptr;
}
void * SQLGetDescFieldThread (void *ptr)
{
  SQLGetDescFieldStruct * myptr = (SQLGetDescFieldStruct *) ptr;
  init_table_lock(myptr->hdesc, 1);
  myptr->sqlrc = libdb400_SQLGetDescField( myptr->hdesc, myptr->rcdNum, myptr->fieldID, myptr->fValue, myptr->fLength, myptr->stLength );
  init_table_unlock(myptr->hdesc, 1);
  /* void SQLGetDescFieldCallback(SQLGetDescFieldStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetDescFieldStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetDescFieldAsync ( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  fieldID, SQLPOINTER  fValue, SQLINTEGER  fLength, SQLINTEGER * stLength, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetDescFieldStruct * myptr = (SQLGetDescFieldStruct *) malloc(sizeof(SQLGetDescFieldStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdesc = hdesc;
  myptr->rcdNum = rcdNum;
  myptr->fieldID = fieldID;
  myptr->fValue = fValue;
  myptr->fLength = fLength;
  myptr->stLength = stLength;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetDescFieldThread, (void *)myptr);
  return tid;
}
SQLGetDescFieldStruct * SQLGetDescFieldJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetDescFieldStruct * myptr = (SQLGetDescFieldStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hdesc, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetDescFieldStruct *) NULL;
  }
  return myptr;
}
void * SQLGetDescRecThread (void *ptr)
{
  SQLGetDescRecStruct * myptr = (SQLGetDescRecStruct *) ptr;
  init_table_lock(myptr->hdesc, 1);
  myptr->sqlrc = libdb400_SQLGetDescRec( myptr->hdesc, myptr->rcdNum, myptr->fname, myptr->bufLen, myptr->sLength, myptr->sType, myptr->sbType, myptr->fLength, myptr->fprec, myptr->fscale, myptr->fnull );
  init_table_unlock(myptr->hdesc, 1);
  /* void SQLGetDescRecCallback(SQLGetDescRecStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetDescRecStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetDescRecAsync ( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLCHAR * fname, SQLSMALLINT  bufLen, SQLSMALLINT * sLength, SQLSMALLINT * sType, SQLSMALLINT * sbType, SQLINTEGER * fLength, SQLSMALLINT * fprec, SQLSMALLINT * fscale, SQLSMALLINT * fnull, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetDescRecStruct * myptr = (SQLGetDescRecStruct *) malloc(sizeof(SQLGetDescRecStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdesc = hdesc;
  myptr->rcdNum = rcdNum;
  myptr->fname = fname;
  myptr->bufLen = bufLen;
  myptr->sLength = sLength;
  myptr->sType = sType;
  myptr->sbType = sbType;
  myptr->fLength = fLength;
  myptr->fprec = fprec;
  myptr->fscale = fscale;
  myptr->fnull = fnull;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetDescRecThread, (void *)myptr);
  return tid;
}
SQLGetDescRecStruct * SQLGetDescRecJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetDescRecStruct * myptr = (SQLGetDescRecStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hdesc, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetDescRecStruct *) NULL;
  }
  return myptr;
}
void * SQLGetDiagFieldThread (void *ptr)
{
  SQLGetDiagFieldStruct * myptr = (SQLGetDiagFieldStruct *) ptr;
  myptr->sqlrc = libdb400_SQLGetDiagField( myptr->hType, myptr->hndl, myptr->rcdNum, myptr->diagID, myptr->dValue, myptr->bLength, myptr->sLength );
  /* void SQLGetDiagFieldCallback(SQLGetDiagFieldStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetDiagFieldStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetDiagFieldAsync ( SQLSMALLINT  hType, SQLINTEGER  hndl, SQLSMALLINT  rcdNum, SQLSMALLINT  diagID, SQLPOINTER  dValue, SQLSMALLINT  bLength, SQLSMALLINT * sLength, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetDiagFieldStruct * myptr = (SQLGetDiagFieldStruct *) malloc(sizeof(SQLGetDiagFieldStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hType = hType;
  myptr->hndl = hndl;
  myptr->rcdNum = rcdNum;
  myptr->diagID = diagID;
  myptr->dValue = dValue;
  myptr->bLength = bLength;
  myptr->sLength = sLength;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetDiagFieldThread, (void *)myptr);
  return tid;
}
SQLGetDiagFieldStruct * SQLGetDiagFieldJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetDiagFieldStruct * myptr = (SQLGetDiagFieldStruct *) NULL;
  int active = 0;
  init_dlsym();
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetDiagFieldStruct *) NULL;
  }
  return myptr;
}
void * SQLGetDiagRecThread (void *ptr)
{
  SQLGetDiagRecStruct * myptr = (SQLGetDiagRecStruct *) ptr;
  myptr->sqlrc = libdb400_SQLGetDiagRec( myptr->hType, myptr->hndl, myptr->rcdNum, myptr->SQLstate, myptr->SQLcode, myptr->msgText, myptr->bLength, myptr->sLength );
  /* void SQLGetDiagRecCallback(SQLGetDiagRecStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetDiagRecStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetDiagRecAsync ( SQLSMALLINT  hType, SQLINTEGER  hndl, SQLSMALLINT  rcdNum, SQLCHAR * SQLstate, SQLINTEGER * SQLcode, SQLCHAR * msgText, SQLSMALLINT  bLength, SQLSMALLINT * sLength, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetDiagRecStruct * myptr = (SQLGetDiagRecStruct *) malloc(sizeof(SQLGetDiagRecStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hType = hType;
  myptr->hndl = hndl;
  myptr->rcdNum = rcdNum;
  myptr->SQLstate = SQLstate;
  myptr->SQLcode = SQLcode;
  myptr->msgText = msgText;
  myptr->bLength = bLength;
  myptr->sLength = sLength;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetDiagRecThread, (void *)myptr);
  return tid;
}
SQLGetDiagRecStruct * SQLGetDiagRecJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetDiagRecStruct * myptr = (SQLGetDiagRecStruct *) NULL;
  int active = 0;
  init_dlsym();
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetDiagRecStruct *) NULL;
  }
  return myptr;
}
void * SQLGetEnvAttrThread (void *ptr)
{
  SQLGetEnvAttrStruct * myptr = (SQLGetEnvAttrStruct *) ptr;
  /* not lock */
  myptr->sqlrc = libdb400_SQLGetEnvAttr( myptr->henv, myptr->Attribute, myptr->Value, myptr->BufferLength, myptr->StringLength );
  /* not lock */
  /* void SQLGetEnvAttrCallback(SQLGetEnvAttrStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetEnvAttrStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetEnvAttrAsync ( SQLHENV  henv, SQLINTEGER  Attribute, SQLPOINTER  Value, SQLINTEGER  BufferLength, SQLINTEGER * StringLength, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetEnvAttrStruct * myptr = (SQLGetEnvAttrStruct *) malloc(sizeof(SQLGetEnvAttrStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->henv = henv;
  myptr->Attribute = Attribute;
  myptr->Value = Value;
  myptr->BufferLength = BufferLength;
  myptr->StringLength = StringLength;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetEnvAttrThread, (void *)myptr);
  return tid;
}
SQLGetEnvAttrStruct * SQLGetEnvAttrJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetEnvAttrStruct * myptr = (SQLGetEnvAttrStruct *) NULL;
  int active = 0;
  init_dlsym();
  /* not lock */
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetEnvAttrStruct *) NULL;
  }
  return myptr;
}
void * SQLGetFunctionsThread (void *ptr)
{
  SQLGetFunctionsStruct * myptr = (SQLGetFunctionsStruct *) ptr;
  init_table_lock(myptr->hdbc, 0);
  myptr->sqlrc = libdb400_SQLGetFunctions( myptr->hdbc, myptr->fFunction, myptr->pfExists );
  init_table_unlock(myptr->hdbc, 0);
  /* void SQLGetFunctionsCallback(SQLGetFunctionsStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetFunctionsStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetFunctionsAsync ( SQLHDBC  hdbc, SQLSMALLINT  fFunction, SQLSMALLINT * pfExists, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetFunctionsStruct * myptr = (SQLGetFunctionsStruct *) malloc(sizeof(SQLGetFunctionsStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdbc = hdbc;
  myptr->fFunction = fFunction;
  myptr->pfExists = pfExists;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetFunctionsThread, (void *)myptr);
  return tid;
}
SQLGetFunctionsStruct * SQLGetFunctionsJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetFunctionsStruct * myptr = (SQLGetFunctionsStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hdbc, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetFunctionsStruct *) NULL;
  }
  return myptr;
}
void * SQLGetInfoThread (void *ptr)
{
  SQLGetInfoStruct * myptr = (SQLGetInfoStruct *) ptr;
  init_table_lock(myptr->hdbc, 0);
  myptr->sqlrc = libdb400_SQLGetInfo( myptr->hdbc, myptr->fInfoType, myptr->rgbInfoValue, myptr->cbInfoValueMax, myptr->pcbInfoValue );
  init_table_unlock(myptr->hdbc, 0);
  /* void SQLGetInfoCallback(SQLGetInfoStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetInfoStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetInfoAsync ( SQLHDBC  hdbc, SQLSMALLINT  fInfoType, SQLPOINTER  rgbInfoValue, SQLSMALLINT  cbInfoValueMax, SQLSMALLINT * pcbInfoValue, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetInfoStruct * myptr = (SQLGetInfoStruct *) malloc(sizeof(SQLGetInfoStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdbc = hdbc;
  myptr->fInfoType = fInfoType;
  myptr->rgbInfoValue = rgbInfoValue;
  myptr->cbInfoValueMax = cbInfoValueMax;
  myptr->pcbInfoValue = pcbInfoValue;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetInfoThread, (void *)myptr);
  return tid;
}
SQLGetInfoStruct * SQLGetInfoJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetInfoStruct * myptr = (SQLGetInfoStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hdbc, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetInfoStruct *) NULL;
  }
  return myptr;
}
void * SQLGetLengthThread (void *ptr)
{
  SQLGetLengthStruct * myptr = (SQLGetLengthStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  myptr->sqlrc = libdb400_SQLGetLength( myptr->hstmt, myptr->locType, myptr->locator, myptr->sLength, myptr->ind );
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLGetLengthCallback(SQLGetLengthStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetLengthStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetLengthAsync ( SQLHSTMT  hstmt, SQLSMALLINT  locType, SQLINTEGER  locator, SQLINTEGER * sLength, SQLINTEGER * ind, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetLengthStruct * myptr = (SQLGetLengthStruct *) malloc(sizeof(SQLGetLengthStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->locType = locType;
  myptr->locator = locator;
  myptr->sLength = sLength;
  myptr->ind = ind;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetLengthThread, (void *)myptr);
  return tid;
}
SQLGetLengthStruct * SQLGetLengthJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetLengthStruct * myptr = (SQLGetLengthStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetLengthStruct *) NULL;
  }
  return myptr;
}
void * SQLGetPositionThread (void *ptr)
{
  SQLGetPositionStruct * myptr = (SQLGetPositionStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  myptr->sqlrc = libdb400_SQLGetPosition( myptr->hstmt, myptr->locType, myptr->srceLocator, myptr->srchLocator, myptr->srchLiteral, myptr->srchLiteralLen, myptr->fPosition, myptr->located, myptr->ind );
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLGetPositionCallback(SQLGetPositionStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetPositionStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetPositionAsync ( SQLHSTMT  hstmt, SQLSMALLINT  locType, SQLINTEGER  srceLocator, SQLINTEGER  srchLocator, SQLCHAR * srchLiteral, SQLINTEGER  srchLiteralLen, SQLINTEGER  fPosition, SQLINTEGER * located, SQLINTEGER * ind, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetPositionStruct * myptr = (SQLGetPositionStruct *) malloc(sizeof(SQLGetPositionStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->locType = locType;
  myptr->srceLocator = srceLocator;
  myptr->srchLocator = srchLocator;
  myptr->srchLiteral = srchLiteral;
  myptr->srchLiteralLen = srchLiteralLen;
  myptr->fPosition = fPosition;
  myptr->located = located;
  myptr->ind = ind;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetPositionThread, (void *)myptr);
  return tid;
}
SQLGetPositionStruct * SQLGetPositionJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetPositionStruct * myptr = (SQLGetPositionStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetPositionStruct *) NULL;
  }
  return myptr;
}
void * SQLGetStmtAttrThread (void *ptr)
{
  SQLGetStmtAttrStruct * myptr = (SQLGetStmtAttrStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  myptr->sqlrc = libdb400_SQLGetStmtAttr( myptr->hstmt, myptr->fAttr, myptr->pvParam, myptr->bLength, myptr->SLength );
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLGetStmtAttrCallback(SQLGetStmtAttrStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetStmtAttrStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetStmtAttrAsync ( SQLHSTMT  hstmt, SQLINTEGER  fAttr, SQLPOINTER  pvParam, SQLINTEGER  bLength, SQLINTEGER * SLength, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetStmtAttrStruct * myptr = (SQLGetStmtAttrStruct *) malloc(sizeof(SQLGetStmtAttrStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->fAttr = fAttr;
  myptr->pvParam = pvParam;
  myptr->bLength = bLength;
  myptr->SLength = SLength;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetStmtAttrThread, (void *)myptr);
  return tid;
}
SQLGetStmtAttrStruct * SQLGetStmtAttrJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetStmtAttrStruct * myptr = (SQLGetStmtAttrStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetStmtAttrStruct *) NULL;
  }
  return myptr;
}
void * SQLGetStmtOptionThread (void *ptr)
{
  SQLGetStmtOptionStruct * myptr = (SQLGetStmtOptionStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  myptr->sqlrc = libdb400_SQLGetStmtOption( myptr->hstmt, myptr->fOption, myptr->pvParam );
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLGetStmtOptionCallback(SQLGetStmtOptionStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetStmtOptionStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetStmtOptionAsync ( SQLHSTMT  hstmt, SQLSMALLINT  fOption, SQLPOINTER  pvParam, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetStmtOptionStruct * myptr = (SQLGetStmtOptionStruct *) malloc(sizeof(SQLGetStmtOptionStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->fOption = fOption;
  myptr->pvParam = pvParam;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetStmtOptionThread, (void *)myptr);
  return tid;
}
SQLGetStmtOptionStruct * SQLGetStmtOptionJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetStmtOptionStruct * myptr = (SQLGetStmtOptionStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetStmtOptionStruct *) NULL;
  }
  return myptr;
}
void * SQLGetSubStringThread (void *ptr)
{
  SQLGetSubStringStruct * myptr = (SQLGetSubStringStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  myptr->sqlrc = libdb400_SQLGetSubString( myptr->hstmt, myptr->locType, myptr->srceLocator, myptr->fPosition, myptr->length, myptr->tType, myptr->rgbValue, myptr->cbValueMax, myptr->StringLength, myptr->ind );
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLGetSubStringCallback(SQLGetSubStringStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetSubStringStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetSubStringAsync ( SQLHSTMT  hstmt, SQLSMALLINT  locType, SQLINTEGER  srceLocator, SQLINTEGER  fPosition, SQLINTEGER  length, SQLSMALLINT  tType, SQLPOINTER  rgbValue, SQLINTEGER  cbValueMax, SQLINTEGER * StringLength, SQLINTEGER * ind, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetSubStringStruct * myptr = (SQLGetSubStringStruct *) malloc(sizeof(SQLGetSubStringStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->locType = locType;
  myptr->srceLocator = srceLocator;
  myptr->fPosition = fPosition;
  myptr->length = length;
  myptr->tType = tType;
  myptr->rgbValue = rgbValue;
  myptr->cbValueMax = cbValueMax;
  myptr->StringLength = StringLength;
  myptr->ind = ind;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetSubStringThread, (void *)myptr);
  return tid;
}
SQLGetSubStringStruct * SQLGetSubStringJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetSubStringStruct * myptr = (SQLGetSubStringStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetSubStringStruct *) NULL;
  }
  return myptr;
}
void * SQLGetTypeInfoThread (void *ptr)
{
  SQLGetTypeInfoStruct * myptr = (SQLGetTypeInfoStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  myptr->sqlrc = libdb400_SQLGetTypeInfo( myptr->hstmt, myptr->fSqlType );
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLGetTypeInfoCallback(SQLGetTypeInfoStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetTypeInfoStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetTypeInfoAsync ( SQLHSTMT  hstmt, SQLSMALLINT  fSqlType, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetTypeInfoStruct * myptr = (SQLGetTypeInfoStruct *) malloc(sizeof(SQLGetTypeInfoStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->fSqlType = fSqlType;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetTypeInfoThread, (void *)myptr);
  return tid;
}
SQLGetTypeInfoStruct * SQLGetTypeInfoJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetTypeInfoStruct * myptr = (SQLGetTypeInfoStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetTypeInfoStruct *) NULL;
  }
  return myptr;
}
void * SQLLanguagesThread (void *ptr)
{
  SQLLanguagesStruct * myptr = (SQLLanguagesStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  myptr->sqlrc = libdb400_SQLLanguages( myptr->hstmt );
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLLanguagesCallback(SQLLanguagesStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLLanguagesStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLLanguagesAsync ( SQLHSTMT  hstmt, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLLanguagesStruct * myptr = (SQLLanguagesStruct *) malloc(sizeof(SQLLanguagesStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLLanguagesThread, (void *)myptr);
  return tid;
}
SQLLanguagesStruct * SQLLanguagesJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLLanguagesStruct * myptr = (SQLLanguagesStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLLanguagesStruct *) NULL;
  }
  return myptr;
}
void * SQLMoreResultsThread (void *ptr)
{
  SQLMoreResultsStruct * myptr = (SQLMoreResultsStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  myptr->sqlrc = libdb400_SQLMoreResults( myptr->hstmt );
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLMoreResultsCallback(SQLMoreResultsStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLMoreResultsStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLMoreResultsAsync ( SQLHSTMT  hstmt, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLMoreResultsStruct * myptr = (SQLMoreResultsStruct *) malloc(sizeof(SQLMoreResultsStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLMoreResultsThread, (void *)myptr);
  return tid;
}
SQLMoreResultsStruct * SQLMoreResultsJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLMoreResultsStruct * myptr = (SQLMoreResultsStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLMoreResultsStruct *) NULL;
  }
  return myptr;
}
void * SQLNativeSqlThread (void *ptr)
{
  SQLNativeSqlStruct * myptr = (SQLNativeSqlStruct *) ptr;
  init_table_lock(myptr->hdbc, 0);
  myptr->sqlrc = libdb400_SQLNativeSql( myptr->hdbc, myptr->szSqlStrIn, myptr->cbSqlStrIn, myptr->szSqlStr, myptr->cbSqlStrMax, myptr->pcbSqlStr );
  init_table_unlock(myptr->hdbc, 0);
  /* void SQLNativeSqlCallback(SQLNativeSqlStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLNativeSqlStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLNativeSqlAsync ( SQLHDBC  hdbc, SQLCHAR * szSqlStrIn, SQLINTEGER  cbSqlStrIn, SQLCHAR * szSqlStr, SQLINTEGER  cbSqlStrMax, SQLINTEGER * pcbSqlStr, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLNativeSqlStruct * myptr = (SQLNativeSqlStruct *) malloc(sizeof(SQLNativeSqlStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdbc = hdbc;
  myptr->szSqlStrIn = szSqlStrIn;
  myptr->cbSqlStrIn = cbSqlStrIn;
  myptr->szSqlStr = szSqlStr;
  myptr->cbSqlStrMax = cbSqlStrMax;
  myptr->pcbSqlStr = pcbSqlStr;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLNativeSqlThread, (void *)myptr);
  return tid;
}
SQLNativeSqlStruct * SQLNativeSqlJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLNativeSqlStruct * myptr = (SQLNativeSqlStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hdbc, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLNativeSqlStruct *) NULL;
  }
  return myptr;
}
void * SQLNextResultThread (void *ptr)
{
  SQLNextResultStruct * myptr = (SQLNextResultStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  myptr->sqlrc = libdb400_SQLNextResult( myptr->hstmt, myptr->hstmt2 );
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLNextResultCallback(SQLNextResultStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLNextResultStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLNextResultAsync ( SQLHSTMT  hstmt, SQLHSTMT  hstmt2, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLNextResultStruct * myptr = (SQLNextResultStruct *) malloc(sizeof(SQLNextResultStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->hstmt2 = hstmt2;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLNextResultThread, (void *)myptr);
  return tid;
}
SQLNextResultStruct * SQLNextResultJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLNextResultStruct * myptr = (SQLNextResultStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLNextResultStruct *) NULL;
  }
  return myptr;
}
void * SQLNumParamsThread (void *ptr)
{
  SQLNumParamsStruct * myptr = (SQLNumParamsStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  myptr->sqlrc = libdb400_SQLNumParams( myptr->hstmt, myptr->pcpar );
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLNumParamsCallback(SQLNumParamsStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLNumParamsStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLNumParamsAsync ( SQLHSTMT  hstmt, SQLSMALLINT * pcpar, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLNumParamsStruct * myptr = (SQLNumParamsStruct *) malloc(sizeof(SQLNumParamsStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->pcpar = pcpar;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLNumParamsThread, (void *)myptr);
  return tid;
}
SQLNumParamsStruct * SQLNumParamsJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLNumParamsStruct * myptr = (SQLNumParamsStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLNumParamsStruct *) NULL;
  }
  return myptr;
}
void * SQLNumResultColsThread (void *ptr)
{
  SQLNumResultColsStruct * myptr = (SQLNumResultColsStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  myptr->sqlrc = libdb400_SQLNumResultCols( myptr->hstmt, myptr->pccol );
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLNumResultColsCallback(SQLNumResultColsStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLNumResultColsStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLNumResultColsAsync ( SQLHSTMT  hstmt, SQLSMALLINT * pccol, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLNumResultColsStruct * myptr = (SQLNumResultColsStruct *) malloc(sizeof(SQLNumResultColsStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->pccol = pccol;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLNumResultColsThread, (void *)myptr);
  return tid;
}
SQLNumResultColsStruct * SQLNumResultColsJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLNumResultColsStruct * myptr = (SQLNumResultColsStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLNumResultColsStruct *) NULL;
  }
  return myptr;
}
void * SQLParamDataThread (void *ptr)
{
  SQLParamDataStruct * myptr = (SQLParamDataStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  myptr->sqlrc = libdb400_SQLParamData( myptr->hstmt, myptr->prgbValue );
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLParamDataCallback(SQLParamDataStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLParamDataStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLParamDataAsync ( SQLHSTMT  hstmt, SQLPOINTER * prgbValue, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLParamDataStruct * myptr = (SQLParamDataStruct *) malloc(sizeof(SQLParamDataStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->prgbValue = prgbValue;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLParamDataThread, (void *)myptr);
  return tid;
}
SQLParamDataStruct * SQLParamDataJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLParamDataStruct * myptr = (SQLParamDataStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLParamDataStruct *) NULL;
  }
  return myptr;
}
void * SQLParamOptionsThread (void *ptr)
{
  SQLParamOptionsStruct * myptr = (SQLParamOptionsStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  myptr->sqlrc = libdb400_SQLParamOptions( myptr->hstmt, myptr->crow, myptr->pirow );
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLParamOptionsCallback(SQLParamOptionsStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLParamOptionsStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLParamOptionsAsync ( SQLHSTMT  hstmt, SQLINTEGER  crow, SQLINTEGER * pirow, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLParamOptionsStruct * myptr = (SQLParamOptionsStruct *) malloc(sizeof(SQLParamOptionsStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->crow = crow;
  myptr->pirow = pirow;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLParamOptionsThread, (void *)myptr);
  return tid;
}
SQLParamOptionsStruct * SQLParamOptionsJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLParamOptionsStruct * myptr = (SQLParamOptionsStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLParamOptionsStruct *) NULL;
  }
  return myptr;
}
void * SQLPrepareThread (void *ptr)
{
  SQLPrepareStruct * myptr = (SQLPrepareStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  myptr->sqlrc = libdb400_SQLPrepare( myptr->hstmt, myptr->szSqlStr, myptr->cbSqlStr );
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLPrepareCallback(SQLPrepareStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLPrepareStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLPrepareAsync ( SQLHSTMT  hstmt, SQLCHAR * szSqlStr, SQLINTEGER  cbSqlStr, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLPrepareStruct * myptr = (SQLPrepareStruct *) malloc(sizeof(SQLPrepareStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->szSqlStr = szSqlStr;
  myptr->cbSqlStr = cbSqlStr;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLPrepareThread, (void *)myptr);
  return tid;
}
SQLPrepareStruct * SQLPrepareJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLPrepareStruct * myptr = (SQLPrepareStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLPrepareStruct *) NULL;
  }
  return myptr;
}
void * SQLPrimaryKeysThread (void *ptr)
{
  SQLPrimaryKeysStruct * myptr = (SQLPrimaryKeysStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  myptr->sqlrc = libdb400_SQLPrimaryKeys( myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName );
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLPrimaryKeysCallback(SQLPrimaryKeysStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLPrimaryKeysStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLPrimaryKeysAsync ( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLPrimaryKeysStruct * myptr = (SQLPrimaryKeysStruct *) malloc(sizeof(SQLPrimaryKeysStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->szTableQualifier = szTableQualifier;
  myptr->cbTableQualifier = cbTableQualifier;
  myptr->szTableOwner = szTableOwner;
  myptr->cbTableOwner = cbTableOwner;
  myptr->szTableName = szTableName;
  myptr->cbTableName = cbTableName;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLPrimaryKeysThread, (void *)myptr);
  return tid;
}
SQLPrimaryKeysStruct * SQLPrimaryKeysJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLPrimaryKeysStruct * myptr = (SQLPrimaryKeysStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLPrimaryKeysStruct *) NULL;
  }
  return myptr;
}
void * SQLProcedureColumnsThread (void *ptr)
{
  SQLProcedureColumnsStruct * myptr = (SQLProcedureColumnsStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  myptr->sqlrc = libdb400_SQLProcedureColumns( myptr->hstmt, myptr->szProcQualifier, myptr->cbProcQualifier, myptr->szProcOwner, myptr->cbProcOwner, myptr->szProcName, myptr->cbProcName, myptr->szColumnName, myptr->cbColumnName );
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLProcedureColumnsCallback(SQLProcedureColumnsStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLProcedureColumnsStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLProcedureColumnsAsync ( SQLHSTMT  hstmt, SQLCHAR * szProcQualifier, SQLSMALLINT  cbProcQualifier, SQLCHAR * szProcOwner, SQLSMALLINT  cbProcOwner, SQLCHAR * szProcName, SQLSMALLINT  cbProcName, SQLCHAR * szColumnName, SQLSMALLINT  cbColumnName, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLProcedureColumnsStruct * myptr = (SQLProcedureColumnsStruct *) malloc(sizeof(SQLProcedureColumnsStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->szProcQualifier = szProcQualifier;
  myptr->cbProcQualifier = cbProcQualifier;
  myptr->szProcOwner = szProcOwner;
  myptr->cbProcOwner = cbProcOwner;
  myptr->szProcName = szProcName;
  myptr->cbProcName = cbProcName;
  myptr->szColumnName = szColumnName;
  myptr->cbColumnName = cbColumnName;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLProcedureColumnsThread, (void *)myptr);
  return tid;
}
SQLProcedureColumnsStruct * SQLProcedureColumnsJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLProcedureColumnsStruct * myptr = (SQLProcedureColumnsStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLProcedureColumnsStruct *) NULL;
  }
  return myptr;
}
void * SQLProceduresThread (void *ptr)
{
  SQLProceduresStruct * myptr = (SQLProceduresStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  myptr->sqlrc = libdb400_SQLProcedures( myptr->hstmt, myptr->szProcQualifier, myptr->cbProcQualifier, myptr->szProcOwner, myptr->cbProcOwner, myptr->szProcName, myptr->cbProcName );
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLProceduresCallback(SQLProceduresStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLProceduresStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLProceduresAsync ( SQLHSTMT  hstmt, SQLCHAR * szProcQualifier, SQLSMALLINT  cbProcQualifier, SQLCHAR * szProcOwner, SQLSMALLINT  cbProcOwner, SQLCHAR * szProcName, SQLSMALLINT  cbProcName, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLProceduresStruct * myptr = (SQLProceduresStruct *) malloc(sizeof(SQLProceduresStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->szProcQualifier = szProcQualifier;
  myptr->cbProcQualifier = cbProcQualifier;
  myptr->szProcOwner = szProcOwner;
  myptr->cbProcOwner = cbProcOwner;
  myptr->szProcName = szProcName;
  myptr->cbProcName = cbProcName;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLProceduresThread, (void *)myptr);
  return tid;
}
SQLProceduresStruct * SQLProceduresJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLProceduresStruct * myptr = (SQLProceduresStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLProceduresStruct *) NULL;
  }
  return myptr;
}
void * SQLPutDataThread (void *ptr)
{
  SQLPutDataStruct * myptr = (SQLPutDataStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  myptr->sqlrc = libdb400_SQLPutData( myptr->hstmt, myptr->rgbValue, myptr->cbValue );
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLPutDataCallback(SQLPutDataStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLPutDataStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLPutDataAsync ( SQLHSTMT  hstmt, SQLPOINTER  rgbValue, SQLINTEGER  cbValue, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLPutDataStruct * myptr = (SQLPutDataStruct *) malloc(sizeof(SQLPutDataStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->rgbValue = rgbValue;
  myptr->cbValue = cbValue;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLPutDataThread, (void *)myptr);
  return tid;
}
SQLPutDataStruct * SQLPutDataJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLPutDataStruct * myptr = (SQLPutDataStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLPutDataStruct *) NULL;
  }
  return myptr;
}
void * SQLReleaseEnvThread (void *ptr)
{
  SQLReleaseEnvStruct * myptr = (SQLReleaseEnvStruct *) ptr;
  /* not lock */
  myptr->sqlrc = libdb400_SQLReleaseEnv( myptr->henv );
  /* not lock */
  /* void SQLReleaseEnvCallback(SQLReleaseEnvStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLReleaseEnvStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLReleaseEnvAsync ( SQLHENV  henv, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLReleaseEnvStruct * myptr = (SQLReleaseEnvStruct *) malloc(sizeof(SQLReleaseEnvStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->henv = henv;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLReleaseEnvThread, (void *)myptr);
  return tid;
}
SQLReleaseEnvStruct * SQLReleaseEnvJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLReleaseEnvStruct * myptr = (SQLReleaseEnvStruct *) NULL;
  int active = 0;
  init_dlsym();
  /* not lock */
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLReleaseEnvStruct *) NULL;
  }
  return myptr;
}
void * SQLRowCountThread (void *ptr)
{
  SQLRowCountStruct * myptr = (SQLRowCountStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  myptr->sqlrc = libdb400_SQLRowCount( myptr->hstmt, myptr->pcrow );
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLRowCountCallback(SQLRowCountStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLRowCountStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLRowCountAsync ( SQLHSTMT  hstmt, SQLINTEGER * pcrow, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLRowCountStruct * myptr = (SQLRowCountStruct *) malloc(sizeof(SQLRowCountStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->pcrow = pcrow;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLRowCountThread, (void *)myptr);
  return tid;
}
SQLRowCountStruct * SQLRowCountJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLRowCountStruct * myptr = (SQLRowCountStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLRowCountStruct *) NULL;
  }
  return myptr;
}
void * SQLSetConnectAttrThread (void *ptr)
{
  SQLSetConnectAttrStruct * myptr = (SQLSetConnectAttrStruct *) ptr;
  init_table_lock(myptr->hdbc, 0);
  myptr->sqlrc = libdb400_SQLSetConnectAttr( myptr->hdbc, myptr->attrib, myptr->vParam, myptr->inlen );
  init_table_unlock(myptr->hdbc, 0);
  /* void SQLSetConnectAttrCallback(SQLSetConnectAttrStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLSetConnectAttrStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLSetConnectAttrAsync ( SQLHDBC  hdbc, SQLINTEGER  attrib, SQLPOINTER  vParam, SQLINTEGER  inlen, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLSetConnectAttrStruct * myptr = (SQLSetConnectAttrStruct *) malloc(sizeof(SQLSetConnectAttrStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdbc = hdbc;
  myptr->attrib = attrib;
  myptr->vParam = vParam;
  myptr->inlen = inlen;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLSetConnectAttrThread, (void *)myptr);
  return tid;
}
SQLSetConnectAttrStruct * SQLSetConnectAttrJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLSetConnectAttrStruct * myptr = (SQLSetConnectAttrStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hdbc, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLSetConnectAttrStruct *) NULL;
  }
  return myptr;
}
void * SQLSetConnectOptionThread (void *ptr)
{
  SQLSetConnectOptionStruct * myptr = (SQLSetConnectOptionStruct *) ptr;
  init_table_lock(myptr->hdbc, 0);
  myptr->sqlrc = libdb400_SQLSetConnectOption( myptr->hdbc, myptr->fOption, myptr->vParam );
  init_table_unlock(myptr->hdbc, 0);
  /* void SQLSetConnectOptionCallback(SQLSetConnectOptionStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLSetConnectOptionStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLSetConnectOptionAsync ( SQLHDBC  hdbc, SQLSMALLINT  fOption, SQLPOINTER  vParam, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLSetConnectOptionStruct * myptr = (SQLSetConnectOptionStruct *) malloc(sizeof(SQLSetConnectOptionStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdbc = hdbc;
  myptr->fOption = fOption;
  myptr->vParam = vParam;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLSetConnectOptionThread, (void *)myptr);
  return tid;
}
SQLSetConnectOptionStruct * SQLSetConnectOptionJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLSetConnectOptionStruct * myptr = (SQLSetConnectOptionStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hdbc, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLSetConnectOptionStruct *) NULL;
  }
  return myptr;
}
void * SQLSetCursorNameThread (void *ptr)
{
  SQLSetCursorNameStruct * myptr = (SQLSetCursorNameStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  myptr->sqlrc = libdb400_SQLSetCursorName( myptr->hstmt, myptr->szCursor, myptr->cbCursor );
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLSetCursorNameCallback(SQLSetCursorNameStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLSetCursorNameStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLSetCursorNameAsync ( SQLHSTMT  hstmt, SQLCHAR * szCursor, SQLSMALLINT  cbCursor, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLSetCursorNameStruct * myptr = (SQLSetCursorNameStruct *) malloc(sizeof(SQLSetCursorNameStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->szCursor = szCursor;
  myptr->cbCursor = cbCursor;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLSetCursorNameThread, (void *)myptr);
  return tid;
}
SQLSetCursorNameStruct * SQLSetCursorNameJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLSetCursorNameStruct * myptr = (SQLSetCursorNameStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLSetCursorNameStruct *) NULL;
  }
  return myptr;
}
void * SQLSetDescFieldThread (void *ptr)
{
  SQLSetDescFieldStruct * myptr = (SQLSetDescFieldStruct *) ptr;
  init_table_lock(myptr->hdesc, 1);
  myptr->sqlrc = libdb400_SQLSetDescField( myptr->hdesc, myptr->rcdNum, myptr->fID, myptr->Value, myptr->buffLen );
  init_table_unlock(myptr->hdesc, 1);
  /* void SQLSetDescFieldCallback(SQLSetDescFieldStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLSetDescFieldStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLSetDescFieldAsync ( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  fID, SQLPOINTER  Value, SQLINTEGER  buffLen, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLSetDescFieldStruct * myptr = (SQLSetDescFieldStruct *) malloc(sizeof(SQLSetDescFieldStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdesc = hdesc;
  myptr->rcdNum = rcdNum;
  myptr->fID = fID;
  myptr->Value = Value;
  myptr->buffLen = buffLen;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLSetDescFieldThread, (void *)myptr);
  return tid;
}
SQLSetDescFieldStruct * SQLSetDescFieldJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLSetDescFieldStruct * myptr = (SQLSetDescFieldStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hdesc, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLSetDescFieldStruct *) NULL;
  }
  return myptr;
}
void * SQLSetDescRecThread (void *ptr)
{
  SQLSetDescRecStruct * myptr = (SQLSetDescRecStruct *) ptr;
  init_table_lock(myptr->hdesc, 1);
  myptr->sqlrc = libdb400_SQLSetDescRec( myptr->hdesc, myptr->rcdNum, myptr->Type, myptr->subType, myptr->fLength, myptr->fPrec, myptr->fScale, myptr->Value, myptr->sLength, myptr->indic );
  init_table_unlock(myptr->hdesc, 1);
  /* void SQLSetDescRecCallback(SQLSetDescRecStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLSetDescRecStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLSetDescRecAsync ( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  Type, SQLSMALLINT  subType, SQLINTEGER  fLength, SQLSMALLINT  fPrec, SQLSMALLINT  fScale, SQLPOINTER  Value, SQLINTEGER * sLength, SQLINTEGER * indic, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLSetDescRecStruct * myptr = (SQLSetDescRecStruct *) malloc(sizeof(SQLSetDescRecStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdesc = hdesc;
  myptr->rcdNum = rcdNum;
  myptr->Type = Type;
  myptr->subType = subType;
  myptr->fLength = fLength;
  myptr->fPrec = fPrec;
  myptr->fScale = fScale;
  myptr->Value = Value;
  myptr->sLength = sLength;
  myptr->indic = indic;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLSetDescRecThread, (void *)myptr);
  return tid;
}
SQLSetDescRecStruct * SQLSetDescRecJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLSetDescRecStruct * myptr = (SQLSetDescRecStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hdesc, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLSetDescRecStruct *) NULL;
  }
  return myptr;
}
void * SQLSetEnvAttrThread (void *ptr)
{
  SQLSetEnvAttrStruct * myptr = (SQLSetEnvAttrStruct *) ptr;
  /* not lock */
  myptr->sqlrc = libdb400_SQLSetEnvAttr( myptr->henv, myptr->Attribute, myptr->Value, myptr->StringLength );
  /* not lock */
  /* void SQLSetEnvAttrCallback(SQLSetEnvAttrStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLSetEnvAttrStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLSetEnvAttrAsync ( SQLHENV  henv, SQLINTEGER  Attribute, SQLPOINTER  Value, SQLINTEGER  StringLength, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLSetEnvAttrStruct * myptr = (SQLSetEnvAttrStruct *) malloc(sizeof(SQLSetEnvAttrStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->henv = henv;
  myptr->Attribute = Attribute;
  myptr->Value = Value;
  myptr->StringLength = StringLength;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLSetEnvAttrThread, (void *)myptr);
  return tid;
}
SQLSetEnvAttrStruct * SQLSetEnvAttrJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLSetEnvAttrStruct * myptr = (SQLSetEnvAttrStruct *) NULL;
  int active = 0;
  init_dlsym();
  /* not lock */
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLSetEnvAttrStruct *) NULL;
  }
  return myptr;
}
void * SQLSetParamThread (void *ptr)
{
  SQLSetParamStruct * myptr = (SQLSetParamStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  myptr->sqlrc = libdb400_SQLSetParam( myptr->hstmt, myptr->ipar, myptr->fCType, myptr->fSqlType, myptr->cbParamDef, myptr->ibScale, myptr->rgbValue, myptr->pcbValue );
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLSetParamCallback(SQLSetParamStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLSetParamStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLSetParamAsync ( SQLHSTMT  hstmt, SQLSMALLINT  ipar, SQLSMALLINT  fCType, SQLSMALLINT  fSqlType, SQLINTEGER  cbParamDef, SQLSMALLINT  ibScale, SQLPOINTER  rgbValue, SQLINTEGER * pcbValue, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLSetParamStruct * myptr = (SQLSetParamStruct *) malloc(sizeof(SQLSetParamStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->ipar = ipar;
  myptr->fCType = fCType;
  myptr->fSqlType = fSqlType;
  myptr->cbParamDef = cbParamDef;
  myptr->ibScale = ibScale;
  myptr->rgbValue = rgbValue;
  myptr->pcbValue = pcbValue;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLSetParamThread, (void *)myptr);
  return tid;
}
SQLSetParamStruct * SQLSetParamJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLSetParamStruct * myptr = (SQLSetParamStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLSetParamStruct *) NULL;
  }
  return myptr;
}
void * SQLSetStmtAttrThread (void *ptr)
{
  SQLSetStmtAttrStruct * myptr = (SQLSetStmtAttrStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  myptr->sqlrc = libdb400_SQLSetStmtAttr( myptr->hstmt, myptr->fAttr, myptr->pParam, myptr->vParam );
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLSetStmtAttrCallback(SQLSetStmtAttrStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLSetStmtAttrStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLSetStmtAttrAsync ( SQLHSTMT  hstmt, SQLINTEGER  fAttr, SQLPOINTER  pParam, SQLINTEGER  vParam, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLSetStmtAttrStruct * myptr = (SQLSetStmtAttrStruct *) malloc(sizeof(SQLSetStmtAttrStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->fAttr = fAttr;
  myptr->pParam = pParam;
  myptr->vParam = vParam;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLSetStmtAttrThread, (void *)myptr);
  return tid;
}
SQLSetStmtAttrStruct * SQLSetStmtAttrJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLSetStmtAttrStruct * myptr = (SQLSetStmtAttrStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLSetStmtAttrStruct *) NULL;
  }
  return myptr;
}
void * SQLSetStmtOptionThread (void *ptr)
{
  SQLSetStmtOptionStruct * myptr = (SQLSetStmtOptionStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  myptr->sqlrc = libdb400_SQLSetStmtOption( myptr->hstmt, myptr->fOption, myptr->vParam );
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLSetStmtOptionCallback(SQLSetStmtOptionStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLSetStmtOptionStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLSetStmtOptionAsync ( SQLHSTMT  hstmt, SQLSMALLINT  fOption, SQLPOINTER  vParam, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLSetStmtOptionStruct * myptr = (SQLSetStmtOptionStruct *) malloc(sizeof(SQLSetStmtOptionStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->fOption = fOption;
  myptr->vParam = vParam;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLSetStmtOptionThread, (void *)myptr);
  return tid;
}
SQLSetStmtOptionStruct * SQLSetStmtOptionJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLSetStmtOptionStruct * myptr = (SQLSetStmtOptionStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLSetStmtOptionStruct *) NULL;
  }
  return myptr;
}
void * SQLSpecialColumnsThread (void *ptr)
{
  SQLSpecialColumnsStruct * myptr = (SQLSpecialColumnsStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  myptr->sqlrc = libdb400_SQLSpecialColumns( myptr->hstmt, myptr->fColType, myptr->szCatalogName, myptr->cbCatalogName, myptr->szSchemaName, myptr->cbSchemaName, myptr->szTableName, myptr->cbTableName, myptr->fScope, myptr->fNullable );
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLSpecialColumnsCallback(SQLSpecialColumnsStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLSpecialColumnsStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLSpecialColumnsAsync ( SQLHSTMT  hstmt, SQLSMALLINT  fColType, SQLCHAR * szCatalogName, SQLSMALLINT  cbCatalogName, SQLCHAR * szSchemaName, SQLSMALLINT  cbSchemaName, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLSMALLINT  fScope, SQLSMALLINT  fNullable, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLSpecialColumnsStruct * myptr = (SQLSpecialColumnsStruct *) malloc(sizeof(SQLSpecialColumnsStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->fColType = fColType;
  myptr->szCatalogName = szCatalogName;
  myptr->cbCatalogName = cbCatalogName;
  myptr->szSchemaName = szSchemaName;
  myptr->cbSchemaName = cbSchemaName;
  myptr->szTableName = szTableName;
  myptr->cbTableName = cbTableName;
  myptr->fScope = fScope;
  myptr->fNullable = fNullable;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLSpecialColumnsThread, (void *)myptr);
  return tid;
}
SQLSpecialColumnsStruct * SQLSpecialColumnsJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLSpecialColumnsStruct * myptr = (SQLSpecialColumnsStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLSpecialColumnsStruct *) NULL;
  }
  return myptr;
}
void * SQLStartTranThread (void *ptr)
{
  SQLStartTranStruct * myptr = (SQLStartTranStruct *) ptr;
  myptr->sqlrc = libdb400_SQLStartTran( myptr->htype, myptr->henv, myptr->mode, myptr->clevel );
  /* void SQLStartTranCallback(SQLStartTranStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLStartTranStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLStartTranAsync ( SQLSMALLINT  htype, SQLHENV  henv, SQLINTEGER  mode, SQLINTEGER  clevel, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLStartTranStruct * myptr = (SQLStartTranStruct *) malloc(sizeof(SQLStartTranStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->htype = htype;
  myptr->henv = henv;
  myptr->mode = mode;
  myptr->clevel = clevel;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLStartTranThread, (void *)myptr);
  return tid;
}
SQLStartTranStruct * SQLStartTranJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLStartTranStruct * myptr = (SQLStartTranStruct *) NULL;
  int active = 0;
  init_dlsym();
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLStartTranStruct *) NULL;
  }
  return myptr;
}
void * SQLStatisticsThread (void *ptr)
{
  SQLStatisticsStruct * myptr = (SQLStatisticsStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  myptr->sqlrc = libdb400_SQLStatistics( myptr->hstmt, myptr->szCatalogName, myptr->cbCatalogName, myptr->szSchemaName, myptr->cbSchemaName, myptr->szTableName, myptr->cbTableName, myptr->fUnique, myptr->fAccuracy );
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLStatisticsCallback(SQLStatisticsStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLStatisticsStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLStatisticsAsync ( SQLHSTMT  hstmt, SQLCHAR * szCatalogName, SQLSMALLINT  cbCatalogName, SQLCHAR * szSchemaName, SQLSMALLINT  cbSchemaName, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLSMALLINT  fUnique, SQLSMALLINT  fAccuracy, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLStatisticsStruct * myptr = (SQLStatisticsStruct *) malloc(sizeof(SQLStatisticsStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->szCatalogName = szCatalogName;
  myptr->cbCatalogName = cbCatalogName;
  myptr->szSchemaName = szSchemaName;
  myptr->cbSchemaName = cbSchemaName;
  myptr->szTableName = szTableName;
  myptr->cbTableName = cbTableName;
  myptr->fUnique = fUnique;
  myptr->fAccuracy = fAccuracy;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLStatisticsThread, (void *)myptr);
  return tid;
}
SQLStatisticsStruct * SQLStatisticsJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLStatisticsStruct * myptr = (SQLStatisticsStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLStatisticsStruct *) NULL;
  }
  return myptr;
}
void * SQLTablePrivilegesThread (void *ptr)
{
  SQLTablePrivilegesStruct * myptr = (SQLTablePrivilegesStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  myptr->sqlrc = libdb400_SQLTablePrivileges( myptr->hstmt, myptr->szCatalogName, myptr->cbCatalogName, myptr->szSchemaName, myptr->cbSchemaName, myptr->szTableName, myptr->cbTableName );
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLTablePrivilegesCallback(SQLTablePrivilegesStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLTablePrivilegesStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLTablePrivilegesAsync ( SQLHSTMT  hstmt, SQLCHAR * szCatalogName, SQLSMALLINT  cbCatalogName, SQLCHAR * szSchemaName, SQLSMALLINT  cbSchemaName, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLTablePrivilegesStruct * myptr = (SQLTablePrivilegesStruct *) malloc(sizeof(SQLTablePrivilegesStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->szCatalogName = szCatalogName;
  myptr->cbCatalogName = cbCatalogName;
  myptr->szSchemaName = szSchemaName;
  myptr->cbSchemaName = cbSchemaName;
  myptr->szTableName = szTableName;
  myptr->cbTableName = cbTableName;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLTablePrivilegesThread, (void *)myptr);
  return tid;
}
SQLTablePrivilegesStruct * SQLTablePrivilegesJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLTablePrivilegesStruct * myptr = (SQLTablePrivilegesStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLTablePrivilegesStruct *) NULL;
  }
  return myptr;
}
void * SQLTablesThread (void *ptr)
{
  SQLTablesStruct * myptr = (SQLTablesStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  myptr->sqlrc = libdb400_SQLTables( myptr->hstmt, myptr->szCatalogName, myptr->cbCatalogName, myptr->szSchemaName, myptr->cbSchemaName, myptr->szTableName, myptr->cbTableName, myptr->szTableType, myptr->cbTableType );
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLTablesCallback(SQLTablesStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLTablesStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLTablesAsync ( SQLHSTMT  hstmt, SQLCHAR * szCatalogName, SQLSMALLINT  cbCatalogName, SQLCHAR * szSchemaName, SQLSMALLINT  cbSchemaName, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLCHAR * szTableType, SQLSMALLINT  cbTableType, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLTablesStruct * myptr = (SQLTablesStruct *) malloc(sizeof(SQLTablesStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->szCatalogName = szCatalogName;
  myptr->cbCatalogName = cbCatalogName;
  myptr->szSchemaName = szSchemaName;
  myptr->cbSchemaName = cbSchemaName;
  myptr->szTableName = szTableName;
  myptr->cbTableName = cbTableName;
  myptr->szTableType = szTableType;
  myptr->cbTableType = cbTableType;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLTablesThread, (void *)myptr);
  return tid;
}
SQLTablesStruct * SQLTablesJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLTablesStruct * myptr = (SQLTablesStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLTablesStruct *) NULL;
  }
  return myptr;
}
void * SQLTransactThread (void *ptr)
{
  SQLTransactStruct * myptr = (SQLTransactStruct *) ptr;
  /* not lock */
  myptr->sqlrc = libdb400_SQLTransact( myptr->henv, myptr->hdbc, myptr->fType );
  /* not lock */
  /* void SQLTransactCallback(SQLTransactStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLTransactStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLTransactAsync ( SQLHENV  henv, SQLHDBC  hdbc, SQLSMALLINT  fType, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLTransactStruct * myptr = (SQLTransactStruct *) malloc(sizeof(SQLTransactStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->henv = henv;
  myptr->hdbc = hdbc;
  myptr->fType = fType;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLTransactThread, (void *)myptr);
  return tid;
}
SQLTransactStruct * SQLTransactJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLTransactStruct * myptr = (SQLTransactStruct *) NULL;
  int active = 0;
  init_dlsym();
  /* not lock */
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLTransactStruct *) NULL;
  }
  return myptr;
}
void * SQL400AddAttrThread (void *ptr)
{
  SQL400AddAttrStruct * myptr = (SQL400AddAttrStruct *) ptr;
  myptr->sqlrc = custom_SQL400AddAttr( myptr->scope, myptr->attrib, myptr->vParam, myptr->inlen, myptr->onerr, myptr->flag, myptr->options );
  /* void SQL400AddAttrCallback(SQL400AddAttrStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQL400AddAttrStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQL400AddAttrAsync ( SQLINTEGER  scope, SQLINTEGER  attrib, SQLPOINTER  vParam, SQLINTEGER  inlen, SQLINTEGER  onerr, SQLINTEGER  flag, SQLPOINTER  options, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQL400AddAttrStruct * myptr = (SQL400AddAttrStruct *) malloc(sizeof(SQL400AddAttrStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->scope = scope;
  myptr->attrib = attrib;
  myptr->vParam = vParam;
  myptr->inlen = inlen;
  myptr->onerr = onerr;
  myptr->flag = flag;
  myptr->options = options;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQL400AddAttrThread, (void *)myptr);
  return tid;
}
SQL400AddAttrStruct * SQL400AddAttrJoin (pthread_t tid, SQLINTEGER flag)
{
  SQL400AddAttrStruct * myptr = (SQL400AddAttrStruct *) NULL;
  int active = 0;
  init_dlsym();
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQL400AddAttrStruct *) NULL;
  }
  return myptr;
}
void * SQL400SetAttrThread (void *ptr)
{
  SQL400SetAttrStruct * myptr = (SQL400SetAttrStruct *) ptr;
  myptr->sqlrc = custom_SQL400SetAttr( myptr->scope, myptr->hndl, myptr->flag, myptr->options );
  /* void SQL400SetAttrCallback(SQL400SetAttrStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQL400SetAttrStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQL400SetAttrAsync ( SQLINTEGER  scope, SQLHANDLE  hndl, SQLINTEGER  flag, SQLPOINTER  options, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQL400SetAttrStruct * myptr = (SQL400SetAttrStruct *) malloc(sizeof(SQL400SetAttrStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->scope = scope;
  myptr->hndl = hndl;
  myptr->flag = flag;
  myptr->options = options;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQL400SetAttrThread, (void *)myptr);
  return tid;
}
SQL400SetAttrStruct * SQL400SetAttrJoin (pthread_t tid, SQLINTEGER flag)
{
  SQL400SetAttrStruct * myptr = (SQL400SetAttrStruct *) NULL;
  int active = 0;
  init_dlsym();
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQL400SetAttrStruct *) NULL;
  }
  return myptr;
}
void * SQL400EnvironmentThread (void *ptr)
{
  SQL400EnvironmentStruct * myptr = (SQL400EnvironmentStruct *) ptr;
  myptr->sqlrc = custom_SQL400Environment( myptr->ohnd, myptr->options );
  /* void SQL400EnvironmentCallback(SQL400EnvironmentStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQL400EnvironmentStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQL400EnvironmentAsync ( SQLINTEGER * ohnd, SQLPOINTER  options, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQL400EnvironmentStruct * myptr = (SQL400EnvironmentStruct *) malloc(sizeof(SQL400EnvironmentStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->ohnd = ohnd;
  myptr->options = options;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQL400EnvironmentThread, (void *)myptr);
  return tid;
}
SQL400EnvironmentStruct * SQL400EnvironmentJoin (pthread_t tid, SQLINTEGER flag)
{
  SQL400EnvironmentStruct * myptr = (SQL400EnvironmentStruct *) NULL;
  int active = 0;
  init_dlsym();
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQL400EnvironmentStruct *) NULL;
  }
  return myptr;
}
void * SQL400ConnectThread (void *ptr)
{
  SQL400ConnectStruct * myptr = (SQL400ConnectStruct *) ptr;
  /* not lock */
  myptr->sqlrc = custom_SQL400Connect( myptr->henv, myptr->db, myptr->uid, myptr->pwd, myptr->ohnd, myptr->options );
  /* not lock */
  /* void SQL400ConnectCallback(SQL400ConnectStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQL400ConnectStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQL400ConnectAsync ( SQLHENV  henv, SQLCHAR * db, SQLCHAR * uid, SQLCHAR * pwd, SQLINTEGER * ohnd, SQLPOINTER  options, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQL400ConnectStruct * myptr = (SQL400ConnectStruct *) malloc(sizeof(SQL400ConnectStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->henv = henv;
  myptr->db = db;
  myptr->uid = uid;
  myptr->pwd = pwd;
  myptr->ohnd = ohnd;
  myptr->options = options;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQL400ConnectThread, (void *)myptr);
  return tid;
}
SQL400ConnectStruct * SQL400ConnectJoin (pthread_t tid, SQLINTEGER flag)
{
  SQL400ConnectStruct * myptr = (SQL400ConnectStruct *) NULL;
  int active = 0;
  init_dlsym();
  /* not lock */
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQL400ConnectStruct *) NULL;
  }
  return myptr;
}
void * SQL400AddCParamThread (void *ptr)
{
  SQL400AddCParamStruct * myptr = (SQL400AddCParamStruct *) ptr;
  myptr->sqlrc = custom_SQL400AddCParam( myptr->icol, myptr->inOutType, myptr->pfSqlCType, myptr->pfSqlCValue, myptr->indPtr, myptr->parms );
  /* void SQL400AddCParamCallback(SQL400AddCParamStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQL400AddCParamStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQL400AddCParamAsync ( SQLSMALLINT  icol, SQLSMALLINT  inOutType, SQLSMALLINT  pfSqlCType, SQLPOINTER  pfSqlCValue, SQLINTEGER * indPtr, SQLPOINTER  parms, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQL400AddCParamStruct * myptr = (SQL400AddCParamStruct *) malloc(sizeof(SQL400AddCParamStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->icol = icol;
  myptr->inOutType = inOutType;
  myptr->pfSqlCType = pfSqlCType;
  myptr->pfSqlCValue = pfSqlCValue;
  myptr->indPtr = indPtr;
  myptr->parms = parms;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQL400AddCParamThread, (void *)myptr);
  return tid;
}
SQL400AddCParamStruct * SQL400AddCParamJoin (pthread_t tid, SQLINTEGER flag)
{
  SQL400AddCParamStruct * myptr = (SQL400AddCParamStruct *) NULL;
  int active = 0;
  init_dlsym();
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQL400AddCParamStruct *) NULL;
  }
  return myptr;
}
void * SQL400AddDescThread (void *ptr)
{
  SQL400AddDescStruct * myptr = (SQL400AddDescStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  myptr->sqlrc = custom_SQL400AddDesc( myptr->hstmt, myptr->icol, myptr->flag, myptr->descs );
  init_table_unlock(myptr->hstmt, 1);
  /* void SQL400AddDescCallback(SQL400AddDescStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQL400AddDescStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQL400AddDescAsync ( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  flag, SQLPOINTER  descs, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQL400AddDescStruct * myptr = (SQL400AddDescStruct *) malloc(sizeof(SQL400AddDescStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->icol = icol;
  myptr->flag = flag;
  myptr->descs = descs;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQL400AddDescThread, (void *)myptr);
  return tid;
}
SQL400AddDescStruct * SQL400AddDescJoin (pthread_t tid, SQLINTEGER flag)
{
  SQL400AddDescStruct * myptr = (SQL400AddDescStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQL400AddDescStruct *) NULL;
  }
  return myptr;
}
void * SQL400ExecuteThread (void *ptr)
{
  SQL400ExecuteStruct * myptr = (SQL400ExecuteStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  myptr->sqlrc = custom_SQL400Execute( myptr->hstmt, myptr->parms, myptr->desc_parms );
  init_table_unlock(myptr->hstmt, 1);
  /* void SQL400ExecuteCallback(SQL400ExecuteStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQL400ExecuteStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQL400ExecuteAsync ( SQLHSTMT  hstmt, SQLPOINTER  parms, SQLPOINTER  desc_parms, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQL400ExecuteStruct * myptr = (SQL400ExecuteStruct *) malloc(sizeof(SQL400ExecuteStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->parms = parms;
  myptr->desc_parms = desc_parms;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQL400ExecuteThread, (void *)myptr);
  return tid;
}
SQL400ExecuteStruct * SQL400ExecuteJoin (pthread_t tid, SQLINTEGER flag)
{
  SQL400ExecuteStruct * myptr = (SQL400ExecuteStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQL400ExecuteStruct *) NULL;
  }
  return myptr;
}
void * SQL400FetchThread (void *ptr)
{
  SQL400FetchStruct * myptr = (SQL400FetchStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  myptr->sqlrc = custom_SQL400Fetch( myptr->hstmt, myptr->start_row, myptr->cols, myptr->desc_cols );
  init_table_unlock(myptr->hstmt, 1);
  /* void SQL400FetchCallback(SQL400FetchStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQL400FetchStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQL400FetchAsync ( SQLHSTMT  hstmt, SQLINTEGER  start_row, SQLPOINTER  cols, SQLPOINTER  desc_cols, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQL400FetchStruct * myptr = (SQL400FetchStruct *) malloc(sizeof(SQL400FetchStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->start_row = start_row;
  myptr->cols = cols;
  myptr->desc_cols = desc_cols;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQL400FetchThread, (void *)myptr);
  return tid;
}
SQL400FetchStruct * SQL400FetchJoin (pthread_t tid, SQLINTEGER flag)
{
  SQL400FetchStruct * myptr = (SQL400FetchStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQL400FetchStruct *) NULL;
  }
  return myptr;
}
void * SQL400Stmt2HdbcThread (void *ptr)
{
  SQL400Stmt2HdbcStruct * myptr = (SQL400Stmt2HdbcStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  myptr->sqlrc = custom_SQL400Stmt2Hdbc( myptr->hstmt, myptr->ohnd );
  init_table_unlock(myptr->hstmt, 1);
  /* void SQL400Stmt2HdbcCallback(SQL400Stmt2HdbcStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQL400Stmt2HdbcStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQL400Stmt2HdbcAsync ( SQLHSTMT  hstmt, SQLINTEGER * ohnd, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQL400Stmt2HdbcStruct * myptr = (SQL400Stmt2HdbcStruct *) malloc(sizeof(SQL400Stmt2HdbcStruct));
  init_dlsym();
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->ohnd = ohnd;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQL400Stmt2HdbcThread, (void *)myptr);
  return tid;
}
SQL400Stmt2HdbcStruct * SQL400Stmt2HdbcJoin (pthread_t tid, SQLINTEGER flag)
{
  SQL400Stmt2HdbcStruct * myptr = (SQL400Stmt2HdbcStruct *) NULL;
  int active = 0;
  init_dlsym();
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQL400Stmt2HdbcStruct *) NULL;
  }
  return myptr;
}
