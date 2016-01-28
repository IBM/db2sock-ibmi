#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dlfcn.h>
#include <sqlcli1.h>
#include <as400_types.h>
#include <as400_protos.h>
#include "PaseCliInit.h"
#include "PaseCliAsync.h"

SQLINTEGER libdb400_SQLAllocConnect_flag;
SQLRETURN (*libdb400_SQLAllocConnect_symbol)( SQLHENV, SQLHDBC* );
SQLINTEGER libdb400_SQLAllocEnv_flag;
SQLRETURN (*libdb400_SQLAllocEnv_symbol)( SQLHENV* );
SQLINTEGER libdb400_SQLAllocHandle_flag;
SQLRETURN (*libdb400_SQLAllocHandle_symbol)( SQLSMALLINT, SQLINTEGER, SQLINTEGER* );
SQLINTEGER libdb400_SQLAllocStmt_flag;
SQLRETURN (*libdb400_SQLAllocStmt_symbol)( SQLHDBC, SQLHSTMT* );
SQLINTEGER libdb400_SQLBindCol_flag;
SQLRETURN (*libdb400_SQLBindCol_symbol)( SQLHSTMT, SQLSMALLINT, SQLSMALLINT, SQLPOINTER, SQLINTEGER, SQLINTEGER* );
SQLINTEGER libdb400_SQLBindFileToCol_flag;
SQLRETURN (*libdb400_SQLBindFileToCol_symbol)( SQLHSTMT, SQLSMALLINT, SQLCHAR*, SQLSMALLINT*, SQLINTEGER*, SQLSMALLINT, SQLINTEGER*, SQLINTEGER* );
SQLINTEGER libdb400_SQLBindFileToParam_flag;
SQLRETURN (*libdb400_SQLBindFileToParam_symbol)( SQLHSTMT, SQLSMALLINT, SQLSMALLINT, SQLCHAR*, SQLSMALLINT*, SQLINTEGER*, SQLSMALLINT, SQLINTEGER* );
SQLINTEGER libdb400_SQLBindParam_flag;
SQLRETURN (*libdb400_SQLBindParam_symbol)( SQLHSTMT, SQLSMALLINT, SQLSMALLINT, SQLSMALLINT, SQLINTEGER, SQLSMALLINT, SQLPOINTER, SQLINTEGER* );
SQLINTEGER libdb400_SQLBindParameter_flag;
SQLRETURN (*libdb400_SQLBindParameter_symbol)( SQLHSTMT, SQLSMALLINT, SQLSMALLINT, SQLSMALLINT, SQLSMALLINT, SQLINTEGER, SQLSMALLINT, SQLPOINTER, SQLINTEGER, SQLINTEGER* );
SQLINTEGER libdb400_SQLCancel_flag;
SQLRETURN (*libdb400_SQLCancel_symbol)( SQLHSTMT );
SQLINTEGER libdb400_SQLCloseCursor_flag;
SQLRETURN (*libdb400_SQLCloseCursor_symbol)( SQLHSTMT );
SQLINTEGER libdb400_SQLColAttribute_flag;
SQLRETURN (*libdb400_SQLColAttribute_symbol)( SQLHSTMT, SQLSMALLINT, SQLSMALLINT, SQLPOINTER, SQLSMALLINT, SQLSMALLINT*, SQLPOINTER );
SQLINTEGER libdb400_SQLColAttributeW_flag;
SQLRETURN (*libdb400_SQLColAttributeW_symbol)( SQLHSTMT, SQLSMALLINT, SQLSMALLINT, SQLPOINTER, SQLSMALLINT, SQLSMALLINT*, SQLPOINTER );
SQLINTEGER libdb400_SQLColAttributes_flag;
SQLRETURN (*libdb400_SQLColAttributes_symbol)( SQLHSTMT, SQLSMALLINT, SQLSMALLINT, SQLCHAR*, SQLINTEGER, SQLINTEGER*, SQLINTEGER* );
SQLINTEGER libdb400_SQLColAttributesW_flag;
SQLRETURN (*libdb400_SQLColAttributesW_symbol)( SQLHSTMT, SQLSMALLINT, SQLSMALLINT, SQLWCHAR*, SQLINTEGER, SQLINTEGER*, SQLINTEGER* );
SQLINTEGER libdb400_SQLColumnPrivileges_flag;
SQLRETURN (*libdb400_SQLColumnPrivileges_symbol)( SQLHSTMT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT );
SQLINTEGER libdb400_SQLColumnPrivilegesW_flag;
SQLRETURN (*libdb400_SQLColumnPrivilegesW_symbol)( SQLHSTMT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT );
SQLINTEGER libdb400_SQLColumns_flag;
SQLRETURN (*libdb400_SQLColumns_symbol)( SQLHSTMT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT );
SQLINTEGER libdb400_SQLColumnsW_flag;
SQLRETURN (*libdb400_SQLColumnsW_symbol)( SQLHSTMT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT );
SQLINTEGER libdb400_SQLConnect_flag;
SQLRETURN (*libdb400_SQLConnect_symbol)( SQLHDBC, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT );
SQLINTEGER libdb400_SQLConnectW_flag;
SQLRETURN (*libdb400_SQLConnectW_symbol)( SQLHDBC, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT );
SQLINTEGER libdb400_SQLCopyDesc_flag;
SQLRETURN (*libdb400_SQLCopyDesc_symbol)( SQLHDESC, SQLHDESC );
SQLINTEGER libdb400_SQLDataSources_flag;
SQLRETURN (*libdb400_SQLDataSources_symbol)( SQLHENV, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLSMALLINT*, SQLCHAR*, SQLSMALLINT, SQLSMALLINT* );
SQLINTEGER libdb400_SQLDataSourcesW_flag;
SQLRETURN (*libdb400_SQLDataSourcesW_symbol)( SQLHENV, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLSMALLINT*, SQLWCHAR*, SQLSMALLINT, SQLSMALLINT* );
SQLINTEGER libdb400_SQLDescribeCol_flag;
SQLRETURN (*libdb400_SQLDescribeCol_symbol)( SQLHSTMT, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLSMALLINT*, SQLSMALLINT*, SQLINTEGER*, SQLSMALLINT*, SQLSMALLINT* );
SQLINTEGER libdb400_SQLDescribeColW_flag;
SQLRETURN (*libdb400_SQLDescribeColW_symbol)( SQLHSTMT, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLSMALLINT*, SQLSMALLINT*, SQLINTEGER*, SQLSMALLINT*, SQLSMALLINT* );
SQLINTEGER libdb400_SQLDescribeParam_flag;
SQLRETURN (*libdb400_SQLDescribeParam_symbol)( SQLHSTMT, SQLSMALLINT, SQLSMALLINT*, SQLINTEGER*, SQLSMALLINT*, SQLSMALLINT* );
SQLINTEGER libdb400_SQLDisconnect_flag;
SQLRETURN (*libdb400_SQLDisconnect_symbol)( SQLHDBC );
SQLINTEGER libdb400_SQLDriverConnect_flag;
SQLRETURN (*libdb400_SQLDriverConnect_symbol)( SQLHDBC, SQLPOINTER, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLSMALLINT*, SQLSMALLINT );
SQLINTEGER libdb400_SQLDriverConnectW_flag;
SQLRETURN (*libdb400_SQLDriverConnectW_symbol)( SQLHDBC, SQLPOINTER, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLSMALLINT*, SQLSMALLINT );
SQLINTEGER libdb400_SQLEndTran_flag;
SQLRETURN (*libdb400_SQLEndTran_symbol)( SQLSMALLINT, SQLHENV, SQLSMALLINT );
SQLINTEGER libdb400_SQLError_flag;
SQLRETURN (*libdb400_SQLError_symbol)( SQLHENV, SQLHDBC, SQLHSTMT, SQLCHAR*, SQLINTEGER*, SQLCHAR*, SQLSMALLINT, SQLSMALLINT* );
SQLINTEGER libdb400_SQLErrorW_flag;
SQLRETURN (*libdb400_SQLErrorW_symbol)( SQLHENV, SQLHDBC, SQLHSTMT, SQLWCHAR*, SQLINTEGER*, SQLWCHAR*, SQLSMALLINT, SQLSMALLINT* );
SQLINTEGER libdb400_SQLExecDirect_flag;
SQLRETURN (*libdb400_SQLExecDirect_symbol)( SQLHSTMT, SQLCHAR*, SQLINTEGER );
SQLINTEGER libdb400_SQLExecDirectW_flag;
SQLRETURN (*libdb400_SQLExecDirectW_symbol)( SQLHSTMT, SQLWCHAR*, SQLINTEGER );
SQLINTEGER libdb400_SQLExecute_flag;
SQLRETURN (*libdb400_SQLExecute_symbol)( SQLHSTMT );
SQLINTEGER libdb400_SQLExtendedFetch_flag;
SQLRETURN (*libdb400_SQLExtendedFetch_symbol)( SQLHSTMT, SQLSMALLINT, SQLINTEGER, SQLINTEGER*, SQLSMALLINT* );
SQLINTEGER libdb400_SQLFetch_flag;
SQLRETURN (*libdb400_SQLFetch_symbol)( SQLHSTMT );
SQLINTEGER libdb400_SQLFetchScroll_flag;
SQLRETURN (*libdb400_SQLFetchScroll_symbol)( SQLHSTMT, SQLSMALLINT, SQLINTEGER );
SQLINTEGER libdb400_SQLForeignKeys_flag;
SQLRETURN (*libdb400_SQLForeignKeys_symbol)( SQLHSTMT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT );
SQLINTEGER libdb400_SQLForeignKeysW_flag;
SQLRETURN (*libdb400_SQLForeignKeysW_symbol)( SQLHSTMT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT );
SQLINTEGER libdb400_SQLFreeConnect_flag;
SQLRETURN (*libdb400_SQLFreeConnect_symbol)( SQLHDBC );
SQLINTEGER libdb400_SQLFreeEnv_flag;
SQLRETURN (*libdb400_SQLFreeEnv_symbol)( SQLHENV );
SQLINTEGER libdb400_SQLFreeStmt_flag;
SQLRETURN (*libdb400_SQLFreeStmt_symbol)( SQLHSTMT, SQLSMALLINT );
SQLINTEGER libdb400_SQLFreeHandle_flag;
SQLRETURN (*libdb400_SQLFreeHandle_symbol)( SQLSMALLINT, SQLINTEGER );
SQLINTEGER libdb400_SQLGetCol_flag;
SQLRETURN (*libdb400_SQLGetCol_symbol)( SQLHSTMT, SQLSMALLINT, SQLSMALLINT, SQLPOINTER, SQLINTEGER, SQLINTEGER* );
SQLINTEGER libdb400_SQLGetColW_flag;
SQLRETURN (*libdb400_SQLGetColW_symbol)( SQLHSTMT, SQLSMALLINT, SQLSMALLINT, SQLPOINTER, SQLINTEGER, SQLINTEGER* );
SQLINTEGER libdb400_SQLGetConnectAttr_flag;
SQLRETURN (*libdb400_SQLGetConnectAttr_symbol)( SQLHDBC, SQLINTEGER, SQLPOINTER, SQLINTEGER, SQLINTEGER* );
SQLINTEGER libdb400_SQLGetConnectAttrW_flag;
SQLRETURN (*libdb400_SQLGetConnectAttrW_symbol)( SQLHDBC, SQLINTEGER, SQLPOINTER, SQLINTEGER, SQLINTEGER* );
SQLINTEGER libdb400_SQLGetConnectOption_flag;
SQLRETURN (*libdb400_SQLGetConnectOption_symbol)( SQLHDBC, SQLSMALLINT, SQLPOINTER );
SQLINTEGER libdb400_SQLGetConnectOptionW_flag;
SQLRETURN (*libdb400_SQLGetConnectOptionW_symbol)( SQLHDBC, SQLSMALLINT, SQLPOINTER );
SQLINTEGER libdb400_SQLGetCursorName_flag;
SQLRETURN (*libdb400_SQLGetCursorName_symbol)( SQLHSTMT, SQLCHAR*, SQLSMALLINT, SQLSMALLINT* );
SQLINTEGER libdb400_SQLGetCursorNameW_flag;
SQLRETURN (*libdb400_SQLGetCursorNameW_symbol)( SQLHSTMT, SQLWCHAR*, SQLSMALLINT, SQLSMALLINT* );
SQLINTEGER libdb400_SQLGetData_flag;
SQLRETURN (*libdb400_SQLGetData_symbol)( SQLHSTMT, SQLSMALLINT, SQLSMALLINT, SQLPOINTER, SQLINTEGER, SQLINTEGER* );
SQLINTEGER libdb400_SQLGetDescField_flag;
SQLRETURN (*libdb400_SQLGetDescField_symbol)( SQLHDESC, SQLSMALLINT, SQLSMALLINT, SQLPOINTER, SQLINTEGER, SQLINTEGER* );
SQLINTEGER libdb400_SQLGetDescFieldW_flag;
SQLRETURN (*libdb400_SQLGetDescFieldW_symbol)( SQLHDESC, SQLSMALLINT, SQLSMALLINT, SQLPOINTER, SQLINTEGER, SQLINTEGER* );
SQLINTEGER libdb400_SQLGetDescRec_flag;
SQLRETURN (*libdb400_SQLGetDescRec_symbol)( SQLHDESC, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLSMALLINT*, SQLSMALLINT*, SQLSMALLINT*, SQLINTEGER*, SQLSMALLINT*, SQLSMALLINT*, SQLSMALLINT* );
SQLINTEGER libdb400_SQLGetDescRecW_flag;
SQLRETURN (*libdb400_SQLGetDescRecW_symbol)( SQLHDESC, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLSMALLINT*, SQLSMALLINT*, SQLSMALLINT*, SQLINTEGER*, SQLSMALLINT*, SQLSMALLINT*, SQLSMALLINT* );
SQLINTEGER libdb400_SQLGetDiagField_flag;
SQLRETURN (*libdb400_SQLGetDiagField_symbol)( SQLSMALLINT, SQLINTEGER, SQLSMALLINT, SQLSMALLINT, SQLPOINTER, SQLSMALLINT, SQLSMALLINT* );
SQLINTEGER libdb400_SQLGetDiagFieldW_flag;
SQLRETURN (*libdb400_SQLGetDiagFieldW_symbol)( SQLSMALLINT, SQLINTEGER, SQLSMALLINT, SQLSMALLINT, SQLPOINTER, SQLSMALLINT, SQLSMALLINT* );
SQLINTEGER libdb400_SQLGetDiagRec_flag;
SQLRETURN (*libdb400_SQLGetDiagRec_symbol)( SQLSMALLINT, SQLINTEGER, SQLSMALLINT, SQLCHAR*, SQLINTEGER*, SQLCHAR*, SQLSMALLINT, SQLSMALLINT* );
SQLINTEGER libdb400_SQLGetDiagRecW_flag;
SQLRETURN (*libdb400_SQLGetDiagRecW_symbol)( SQLSMALLINT, SQLINTEGER, SQLSMALLINT, SQLWCHAR*, SQLINTEGER*, SQLWCHAR*, SQLSMALLINT, SQLSMALLINT* );
SQLINTEGER libdb400_SQLGetEnvAttr_flag;
SQLRETURN (*libdb400_SQLGetEnvAttr_symbol)( SQLHENV, SQLINTEGER, SQLPOINTER, SQLINTEGER, SQLINTEGER* );
SQLINTEGER libdb400_SQLGetFunctions_flag;
SQLRETURN (*libdb400_SQLGetFunctions_symbol)( SQLHDBC, SQLSMALLINT, SQLSMALLINT* );
SQLINTEGER libdb400_SQLGetInfo_flag;
SQLRETURN (*libdb400_SQLGetInfo_symbol)( SQLHDBC, SQLSMALLINT, SQLPOINTER, SQLSMALLINT, SQLSMALLINT* );
SQLINTEGER libdb400_SQLGetInfoW_flag;
SQLRETURN (*libdb400_SQLGetInfoW_symbol)( SQLHDBC, SQLSMALLINT, SQLPOINTER, SQLSMALLINT, SQLSMALLINT* );
SQLINTEGER libdb400_SQLGetLength_flag;
SQLRETURN (*libdb400_SQLGetLength_symbol)( SQLHSTMT, SQLSMALLINT, SQLINTEGER, SQLINTEGER*, SQLINTEGER* );
SQLINTEGER libdb400_SQLGetPosition_flag;
SQLRETURN (*libdb400_SQLGetPosition_symbol)( SQLHSTMT, SQLSMALLINT, SQLINTEGER, SQLINTEGER, SQLCHAR*, SQLINTEGER, SQLINTEGER, SQLINTEGER*, SQLINTEGER* );
SQLINTEGER libdb400_SQLGetPositionW_flag;
SQLRETURN (*libdb400_SQLGetPositionW_symbol)( SQLHSTMT, SQLSMALLINT, SQLINTEGER, SQLINTEGER, SQLWCHAR*, SQLINTEGER, SQLINTEGER, SQLINTEGER*, SQLINTEGER* );
SQLINTEGER libdb400_SQLGetStmtAttr_flag;
SQLRETURN (*libdb400_SQLGetStmtAttr_symbol)( SQLHSTMT, SQLINTEGER, SQLPOINTER, SQLINTEGER, SQLINTEGER* );
SQLINTEGER libdb400_SQLGetStmtAttrW_flag;
SQLRETURN (*libdb400_SQLGetStmtAttrW_symbol)( SQLHSTMT, SQLINTEGER, SQLPOINTER, SQLINTEGER, SQLINTEGER* );
SQLINTEGER libdb400_SQLGetStmtOption_flag;
SQLRETURN (*libdb400_SQLGetStmtOption_symbol)( SQLHSTMT, SQLSMALLINT, SQLPOINTER );
SQLINTEGER libdb400_SQLGetStmtOptionW_flag;
SQLRETURN (*libdb400_SQLGetStmtOptionW_symbol)( SQLHSTMT, SQLSMALLINT, SQLPOINTER );
SQLINTEGER libdb400_SQLGetSubString_flag;
SQLRETURN (*libdb400_SQLGetSubString_symbol)( SQLHSTMT, SQLSMALLINT, SQLINTEGER, SQLINTEGER, SQLINTEGER, SQLSMALLINT, SQLPOINTER, SQLINTEGER, SQLINTEGER*, SQLINTEGER* );
SQLINTEGER libdb400_SQLGetSubStringW_flag;
SQLRETURN (*libdb400_SQLGetSubStringW_symbol)( SQLHSTMT, SQLSMALLINT, SQLINTEGER, SQLINTEGER, SQLINTEGER, SQLSMALLINT, SQLPOINTER, SQLINTEGER, SQLINTEGER*, SQLINTEGER* );
SQLINTEGER libdb400_SQLGetTypeInfo_flag;
SQLRETURN (*libdb400_SQLGetTypeInfo_symbol)( SQLHSTMT, SQLSMALLINT );
SQLINTEGER libdb400_SQLGetTypeInfoW_flag;
SQLRETURN (*libdb400_SQLGetTypeInfoW_symbol)( SQLHSTMT, SQLSMALLINT );
SQLINTEGER libdb400_SQLLanguages_flag;
SQLRETURN (*libdb400_SQLLanguages_symbol)( SQLHSTMT );
SQLINTEGER libdb400_SQLMoreResults_flag;
SQLRETURN (*libdb400_SQLMoreResults_symbol)( SQLHSTMT );
SQLINTEGER libdb400_SQLNativeSql_flag;
SQLRETURN (*libdb400_SQLNativeSql_symbol)( SQLHDBC, SQLCHAR*, SQLINTEGER, SQLCHAR*, SQLINTEGER, SQLINTEGER* );
SQLINTEGER libdb400_SQLNativeSqlW_flag;
SQLRETURN (*libdb400_SQLNativeSqlW_symbol)( SQLHDBC, SQLWCHAR*, SQLINTEGER, SQLWCHAR*, SQLINTEGER, SQLINTEGER* );
SQLINTEGER libdb400_SQLNextResult_flag;
SQLRETURN (*libdb400_SQLNextResult_symbol)( SQLHSTMT, SQLHSTMT );
SQLINTEGER libdb400_SQLNumParams_flag;
SQLRETURN (*libdb400_SQLNumParams_symbol)( SQLHSTMT, SQLSMALLINT* );
SQLINTEGER libdb400_SQLNumResultCols_flag;
SQLRETURN (*libdb400_SQLNumResultCols_symbol)( SQLHSTMT, SQLSMALLINT* );
SQLINTEGER libdb400_SQLParamData_flag;
SQLRETURN (*libdb400_SQLParamData_symbol)( SQLHSTMT, SQLPOINTER* );
SQLINTEGER libdb400_SQLParamOptions_flag;
SQLRETURN (*libdb400_SQLParamOptions_symbol)( SQLHSTMT, SQLINTEGER, SQLINTEGER* );
SQLINTEGER libdb400_SQLPrepare_flag;
SQLRETURN (*libdb400_SQLPrepare_symbol)( SQLHSTMT, SQLCHAR*, SQLINTEGER );
SQLINTEGER libdb400_SQLPrepareW_flag;
SQLRETURN (*libdb400_SQLPrepareW_symbol)( SQLHSTMT, SQLWCHAR*, SQLINTEGER );
SQLINTEGER libdb400_SQLPrimaryKeys_flag;
SQLRETURN (*libdb400_SQLPrimaryKeys_symbol)( SQLHSTMT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT );
SQLINTEGER libdb400_SQLPrimaryKeysW_flag;
SQLRETURN (*libdb400_SQLPrimaryKeysW_symbol)( SQLHSTMT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT );
SQLINTEGER libdb400_SQLProcedureColumns_flag;
SQLRETURN (*libdb400_SQLProcedureColumns_symbol)( SQLHSTMT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT );
SQLINTEGER libdb400_SQLProcedureColumnsW_flag;
SQLRETURN (*libdb400_SQLProcedureColumnsW_symbol)( SQLHSTMT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT );
SQLINTEGER libdb400_SQLProcedures_flag;
SQLRETURN (*libdb400_SQLProcedures_symbol)( SQLHSTMT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT );
SQLINTEGER libdb400_SQLProceduresW_flag;
SQLRETURN (*libdb400_SQLProceduresW_symbol)( SQLHSTMT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT );
SQLINTEGER libdb400_SQLPutData_flag;
SQLRETURN (*libdb400_SQLPutData_symbol)( SQLHSTMT, SQLPOINTER, SQLINTEGER );
SQLINTEGER libdb400_SQLReleaseEnv_flag;
SQLRETURN (*libdb400_SQLReleaseEnv_symbol)( SQLHENV );
SQLINTEGER libdb400_SQLRowCount_flag;
SQLRETURN (*libdb400_SQLRowCount_symbol)( SQLHSTMT, SQLINTEGER* );
SQLINTEGER libdb400_SQLSetConnectAttr_flag;
SQLRETURN (*libdb400_SQLSetConnectAttr_symbol)( SQLHDBC, SQLINTEGER, SQLPOINTER, SQLINTEGER );
SQLINTEGER libdb400_SQLSetConnectAttrW_flag;
SQLRETURN (*libdb400_SQLSetConnectAttrW_symbol)( SQLHDBC, SQLINTEGER, SQLPOINTER, SQLINTEGER );
SQLINTEGER libdb400_SQLSetConnectOption_flag;
SQLRETURN (*libdb400_SQLSetConnectOption_symbol)( SQLHDBC, SQLSMALLINT, SQLPOINTER );
SQLINTEGER libdb400_SQLSetConnectOptionW_flag;
SQLRETURN (*libdb400_SQLSetConnectOptionW_symbol)( SQLHDBC, SQLSMALLINT, SQLPOINTER );
SQLINTEGER libdb400_SQLSetCursorName_flag;
SQLRETURN (*libdb400_SQLSetCursorName_symbol)( SQLHSTMT, SQLCHAR*, SQLSMALLINT );
SQLINTEGER libdb400_SQLSetCursorNameW_flag;
SQLRETURN (*libdb400_SQLSetCursorNameW_symbol)( SQLHSTMT, SQLWCHAR*, SQLSMALLINT );
SQLINTEGER libdb400_SQLSetDescField_flag;
SQLRETURN (*libdb400_SQLSetDescField_symbol)( SQLHDESC, SQLSMALLINT, SQLSMALLINT, SQLPOINTER, SQLINTEGER );
SQLINTEGER libdb400_SQLSetDescFieldW_flag;
SQLRETURN (*libdb400_SQLSetDescFieldW_symbol)( SQLHDESC, SQLSMALLINT, SQLSMALLINT, SQLPOINTER, SQLINTEGER );
SQLINTEGER libdb400_SQLSetDescRec_flag;
SQLRETURN (*libdb400_SQLSetDescRec_symbol)( SQLHDESC, SQLSMALLINT, SQLSMALLINT, SQLSMALLINT, SQLINTEGER, SQLSMALLINT, SQLSMALLINT, SQLPOINTER, SQLINTEGER*, SQLINTEGER* );
SQLINTEGER libdb400_SQLSetEnvAttr_flag;
SQLRETURN (*libdb400_SQLSetEnvAttr_symbol)( SQLHENV, SQLINTEGER, SQLPOINTER, SQLINTEGER );
SQLINTEGER libdb400_SQLSetParam_flag;
SQLRETURN (*libdb400_SQLSetParam_symbol)( SQLHSTMT, SQLSMALLINT, SQLSMALLINT, SQLSMALLINT, SQLINTEGER, SQLSMALLINT, SQLPOINTER, SQLINTEGER* );
SQLINTEGER libdb400_SQLSetStmtAttr_flag;
SQLRETURN (*libdb400_SQLSetStmtAttr_symbol)( SQLHSTMT, SQLINTEGER, SQLPOINTER, SQLINTEGER );
SQLINTEGER libdb400_SQLSetStmtAttrW_flag;
SQLRETURN (*libdb400_SQLSetStmtAttrW_symbol)( SQLHSTMT, SQLINTEGER, SQLPOINTER, SQLINTEGER );
SQLINTEGER libdb400_SQLSetStmtOption_flag;
SQLRETURN (*libdb400_SQLSetStmtOption_symbol)( SQLHSTMT, SQLSMALLINT, SQLPOINTER );
SQLINTEGER libdb400_SQLSetStmtOptionW_flag;
SQLRETURN (*libdb400_SQLSetStmtOptionW_symbol)( SQLHSTMT, SQLSMALLINT, SQLPOINTER );
SQLINTEGER libdb400_SQLSpecialColumns_flag;
SQLRETURN (*libdb400_SQLSpecialColumns_symbol)( SQLHSTMT, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLSMALLINT, SQLSMALLINT );
SQLINTEGER libdb400_SQLSpecialColumnsW_flag;
SQLRETURN (*libdb400_SQLSpecialColumnsW_symbol)( SQLHSTMT, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLSMALLINT, SQLSMALLINT );
SQLINTEGER libdb400_SQLStartTran_flag;
SQLRETURN (*libdb400_SQLStartTran_symbol)( SQLSMALLINT, SQLHENV, SQLINTEGER, SQLINTEGER );
SQLINTEGER libdb400_SQLStatistics_flag;
SQLRETURN (*libdb400_SQLStatistics_symbol)( SQLHSTMT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLSMALLINT, SQLSMALLINT );
SQLINTEGER libdb400_SQLStatisticsW_flag;
SQLRETURN (*libdb400_SQLStatisticsW_symbol)( SQLHSTMT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLSMALLINT, SQLSMALLINT );
SQLINTEGER libdb400_SQLTablePrivileges_flag;
SQLRETURN (*libdb400_SQLTablePrivileges_symbol)( SQLHSTMT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT );
SQLINTEGER libdb400_SQLTablePrivilegesW_flag;
SQLRETURN (*libdb400_SQLTablePrivilegesW_symbol)( SQLHSTMT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT );
SQLINTEGER libdb400_SQLTables_flag;
SQLRETURN (*libdb400_SQLTables_symbol)( SQLHSTMT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT );
SQLINTEGER libdb400_SQLTablesW_flag;
SQLRETURN (*libdb400_SQLTablesW_symbol)( SQLHSTMT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT );
SQLINTEGER libdb400_SQLTransact_flag;
SQLRETURN (*libdb400_SQLTransact_symbol)( SQLHENV, SQLHDBC, SQLSMALLINT );
SQLINTEGER libdb400_SQLOverrideCCSID400_flag;
SQLRETURN (*libdb400_SQLOverrideCCSID400_symbol)( SQLINTEGER );

SQLRETURN libdb400_SQLAllocConnect( SQLHENV  henv, SQLHDBC * phdbc ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLAllocConnect_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLAllocConnect_symbol = dlsym(dlhandle, "SQLAllocConnect");
    libdb400_SQLAllocConnect_flag = 1;
  }
  sqlrc = libdb400_SQLAllocConnect_symbol( henv, phdbc );
  return sqlrc;
}
SQLRETURN libdb400_SQLAllocEnv( SQLHENV * phenv ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLAllocEnv_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLAllocEnv_symbol = dlsym(dlhandle, "SQLAllocEnv");
    libdb400_SQLAllocEnv_flag = 1;
  }
  sqlrc = libdb400_SQLAllocEnv_symbol( phenv );
  return sqlrc;
}
SQLRETURN libdb400_SQLAllocHandle( SQLSMALLINT  htype, SQLINTEGER  ihnd, SQLINTEGER * ohnd ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLAllocHandle_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLAllocHandle_symbol = dlsym(dlhandle, "SQLAllocHandle");
    libdb400_SQLAllocHandle_flag = 1;
  }
  sqlrc = libdb400_SQLAllocHandle_symbol( htype, ihnd, ohnd );
  return sqlrc;
}
SQLRETURN libdb400_SQLAllocStmt( SQLHDBC  hdbc, SQLHSTMT * phstmt ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLAllocStmt_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLAllocStmt_symbol = dlsym(dlhandle, "SQLAllocStmt");
    libdb400_SQLAllocStmt_flag = 1;
  }
  sqlrc = libdb400_SQLAllocStmt_symbol( hdbc, phstmt );
  return sqlrc;
}
SQLRETURN libdb400_SQLBindCol( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  iType, SQLPOINTER  rgbValue, SQLINTEGER  cbValueMax, SQLINTEGER * pcbValue ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLBindCol_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLBindCol_symbol = dlsym(dlhandle, "SQLBindCol");
    libdb400_SQLBindCol_flag = 1;
  }
  sqlrc = libdb400_SQLBindCol_symbol( hstmt, icol, iType, rgbValue, cbValueMax, pcbValue );
  return sqlrc;
}
SQLRETURN libdb400_SQLBindFileToCol( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLCHAR * fName, SQLSMALLINT * fNameLen, SQLINTEGER * fOptions, SQLSMALLINT  fValueMax, SQLINTEGER * sLen, SQLINTEGER * pcbValue ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLBindFileToCol_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLBindFileToCol_symbol = dlsym(dlhandle, "SQLBindFileToCol");
    libdb400_SQLBindFileToCol_flag = 1;
  }
  sqlrc = libdb400_SQLBindFileToCol_symbol( hstmt, icol, fName, fNameLen, fOptions, fValueMax, sLen, pcbValue );
  return sqlrc;
}
SQLRETURN libdb400_SQLBindFileToParam( SQLHSTMT  hstmt, SQLSMALLINT  ipar, SQLSMALLINT  iType, SQLCHAR * fName, SQLSMALLINT * fNameLen, SQLINTEGER * fOptions, SQLSMALLINT  fValueMax, SQLINTEGER * pcbValue ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLBindFileToParam_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLBindFileToParam_symbol = dlsym(dlhandle, "SQLBindFileToParam");
    libdb400_SQLBindFileToParam_flag = 1;
  }
  sqlrc = libdb400_SQLBindFileToParam_symbol( hstmt, ipar, iType, fName, fNameLen, fOptions, fValueMax, pcbValue );
  return sqlrc;
}
SQLRETURN libdb400_SQLBindParam( SQLHSTMT  hstmt, SQLSMALLINT  iparm, SQLSMALLINT  iType, SQLSMALLINT  pType, SQLINTEGER  pLen, SQLSMALLINT  pScale, SQLPOINTER  pData, SQLINTEGER * pcbValue ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLBindParam_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLBindParam_symbol = dlsym(dlhandle, "SQLBindParam");
    libdb400_SQLBindParam_flag = 1;
  }
  sqlrc = libdb400_SQLBindParam_symbol( hstmt, iparm, iType, pType, pLen, pScale, pData, pcbValue );
  return sqlrc;
}
SQLRETURN libdb400_SQLBindParameter( SQLHSTMT  hstmt, SQLSMALLINT  ipar, SQLSMALLINT  fParamType, SQLSMALLINT  fCType, SQLSMALLINT  fSQLType, SQLINTEGER  pLen, SQLSMALLINT  pScale, SQLPOINTER  pData, SQLINTEGER  cbValueMax, SQLINTEGER * pcbValue ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLBindParameter_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLBindParameter_symbol = dlsym(dlhandle, "SQLBindParameter");
    libdb400_SQLBindParameter_flag = 1;
  }
  sqlrc = libdb400_SQLBindParameter_symbol( hstmt, ipar, fParamType, fCType, fSQLType, pLen, pScale, pData, cbValueMax, pcbValue );
  return sqlrc;
}
SQLRETURN libdb400_SQLCancel( SQLHSTMT  hstmt ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLCancel_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLCancel_symbol = dlsym(dlhandle, "SQLCancel");
    libdb400_SQLCancel_flag = 1;
  }
  sqlrc = libdb400_SQLCancel_symbol( hstmt );
  return sqlrc;
}
SQLRETURN libdb400_SQLCloseCursor( SQLHSTMT  hstmt ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLCloseCursor_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLCloseCursor_symbol = dlsym(dlhandle, "SQLCloseCursor");
    libdb400_SQLCloseCursor_flag = 1;
  }
  sqlrc = libdb400_SQLCloseCursor_symbol( hstmt );
  return sqlrc;
}
SQLRETURN libdb400_SQLColAttribute( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fDescType, SQLPOINTER  rgbDesc, SQLSMALLINT  cbDescMax, SQLSMALLINT * pcbDesc, SQLPOINTER  pfDesc ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLColAttribute_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLColAttribute_symbol = dlsym(dlhandle, "SQLColAttribute");
    libdb400_SQLColAttribute_flag = 1;
  }
  sqlrc = libdb400_SQLColAttribute_symbol( hstmt, icol, fDescType, rgbDesc, cbDescMax, pcbDesc, pfDesc );
  return sqlrc;
}
SQLRETURN libdb400_SQLColAttributeW( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fDescType, SQLPOINTER  rgbDesc, SQLSMALLINT  cbDescMax, SQLSMALLINT * pcbDesc, SQLPOINTER  pfDesc ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLColAttributeW_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLColAttributeW_symbol = dlsym(dlhandle, "SQLColAttributeW");
    libdb400_SQLColAttributeW_flag = 1;
  }
  sqlrc = libdb400_SQLColAttributeW_symbol( hstmt, icol, fDescType, rgbDesc, cbDescMax, pcbDesc, pfDesc );
  return sqlrc;
}
SQLRETURN libdb400_SQLColAttributes( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fDescType, SQLCHAR * rgbDesc, SQLINTEGER  cbDescMax, SQLINTEGER * pcbDesc, SQLINTEGER * pfDesc ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLColAttributes_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLColAttributes_symbol = dlsym(dlhandle, "SQLColAttributes");
    libdb400_SQLColAttributes_flag = 1;
  }
  sqlrc = libdb400_SQLColAttributes_symbol( hstmt, icol, fDescType, rgbDesc, cbDescMax, pcbDesc, pfDesc );
  return sqlrc;
}
SQLRETURN libdb400_SQLColAttributesW( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fDescType, SQLWCHAR * rgbDesc, SQLINTEGER  cbDescMax, SQLINTEGER * pcbDesc, SQLINTEGER * pfDesc ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLColAttributesW_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLColAttributesW_symbol = dlsym(dlhandle, "SQLColAttributesW");
    libdb400_SQLColAttributesW_flag = 1;
  }
  sqlrc = libdb400_SQLColAttributesW_symbol( hstmt, icol, fDescType, rgbDesc, cbDescMax, pcbDesc, pfDesc );
  return sqlrc;
}
SQLRETURN libdb400_SQLColumnPrivileges( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLCHAR * szColumnName, SQLSMALLINT  cbColumnName ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLColumnPrivileges_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLColumnPrivileges_symbol = dlsym(dlhandle, "SQLColumnPrivileges");
    libdb400_SQLColumnPrivileges_flag = 1;
  }
  sqlrc = libdb400_SQLColumnPrivileges_symbol( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName, szColumnName, cbColumnName );
  return sqlrc;
}
SQLRETURN libdb400_SQLColumnPrivilegesW( SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName, SQLWCHAR * szColumnName, SQLSMALLINT  cbColumnName ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLColumnPrivilegesW_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLColumnPrivilegesW_symbol = dlsym(dlhandle, "SQLColumnPrivilegesW");
    libdb400_SQLColumnPrivilegesW_flag = 1;
  }
  sqlrc = libdb400_SQLColumnPrivilegesW_symbol( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName, szColumnName, cbColumnName );
  return sqlrc;
}
SQLRETURN libdb400_SQLColumns( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLCHAR * szColumnName, SQLSMALLINT  cbColumnName ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLColumns_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLColumns_symbol = dlsym(dlhandle, "SQLColumns");
    libdb400_SQLColumns_flag = 1;
  }
  sqlrc = libdb400_SQLColumns_symbol( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName, szColumnName, cbColumnName );
  return sqlrc;
}
SQLRETURN libdb400_SQLColumnsW( SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName, SQLWCHAR * szColumnName, SQLSMALLINT  cbColumnName ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLColumnsW_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLColumnsW_symbol = dlsym(dlhandle, "SQLColumnsW");
    libdb400_SQLColumnsW_flag = 1;
  }
  sqlrc = libdb400_SQLColumnsW_symbol( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName, szColumnName, cbColumnName );
  return sqlrc;
}
SQLRETURN libdb400_SQLConnect( SQLHDBC  hdbc, SQLCHAR * szDSN, SQLSMALLINT  cbDSN, SQLCHAR * szUID, SQLSMALLINT  cbUID, SQLCHAR * szAuthStr, SQLSMALLINT  cbAuthStr ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLConnect_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLConnect_symbol = dlsym(dlhandle, "SQLConnect");
    libdb400_SQLConnect_flag = 1;
  }
  sqlrc = libdb400_SQLConnect_symbol( hdbc, szDSN, cbDSN, szUID, cbUID, szAuthStr, cbAuthStr );
  return sqlrc;
}
SQLRETURN libdb400_SQLConnectW( SQLHDBC  hdbc, SQLWCHAR * szDSN, SQLSMALLINT  cbDSN, SQLWCHAR * szUID, SQLSMALLINT  cbUID, SQLWCHAR * szAuthStr, SQLSMALLINT  cbAuthStr ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLConnectW_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLConnectW_symbol = dlsym(dlhandle, "SQLConnectW");
    libdb400_SQLConnectW_flag = 1;
  }
  sqlrc = libdb400_SQLConnectW_symbol( hdbc, szDSN, cbDSN, szUID, cbUID, szAuthStr, cbAuthStr );
  return sqlrc;
}
SQLRETURN libdb400_SQLCopyDesc( SQLHDESC  sDesc, SQLHDESC  tDesc ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLCopyDesc_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLCopyDesc_symbol = dlsym(dlhandle, "SQLCopyDesc");
    libdb400_SQLCopyDesc_flag = 1;
  }
  sqlrc = libdb400_SQLCopyDesc_symbol( sDesc, tDesc );
  return sqlrc;
}
SQLRETURN libdb400_SQLDataSources( SQLHENV  henv, SQLSMALLINT  fDirection, SQLCHAR * szDSN, SQLSMALLINT  cbDSNMax, SQLSMALLINT * pcbDSN, SQLCHAR * szDescription, SQLSMALLINT  cbDescriptionMax, SQLSMALLINT * pcbDescription ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLDataSources_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLDataSources_symbol = dlsym(dlhandle, "SQLDataSources");
    libdb400_SQLDataSources_flag = 1;
  }
  sqlrc = libdb400_SQLDataSources_symbol( henv, fDirection, szDSN, cbDSNMax, pcbDSN, szDescription, cbDescriptionMax, pcbDescription );
  return sqlrc;
}
SQLRETURN libdb400_SQLDataSourcesW( SQLHENV  henv, SQLSMALLINT  fDirection, SQLWCHAR * szDSN, SQLSMALLINT  cbDSNMax, SQLSMALLINT * pcbDSN, SQLWCHAR * szDescription, SQLSMALLINT  cbDescriptionMax, SQLSMALLINT * pcbDescription ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLDataSourcesW_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLDataSourcesW_symbol = dlsym(dlhandle, "SQLDataSourcesW");
    libdb400_SQLDataSourcesW_flag = 1;
  }
  sqlrc = libdb400_SQLDataSourcesW_symbol( henv, fDirection, szDSN, cbDSNMax, pcbDSN, szDescription, cbDescriptionMax, pcbDescription );
  return sqlrc;
}
SQLRETURN libdb400_SQLDescribeCol( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLCHAR * szColName, SQLSMALLINT  cbColNameMax, SQLSMALLINT * pcbColName, SQLSMALLINT * pfSqlType, SQLINTEGER * pcbColDef, SQLSMALLINT * pibScale, SQLSMALLINT * pfNullable ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLDescribeCol_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLDescribeCol_symbol = dlsym(dlhandle, "SQLDescribeCol");
    libdb400_SQLDescribeCol_flag = 1;
  }
  sqlrc = libdb400_SQLDescribeCol_symbol( hstmt, icol, szColName, cbColNameMax, pcbColName, pfSqlType, pcbColDef, pibScale, pfNullable );
  return sqlrc;
}
SQLRETURN libdb400_SQLDescribeColW( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLWCHAR * szColName, SQLSMALLINT  cbColNameMax, SQLSMALLINT * pcbColName, SQLSMALLINT * pfSqlType, SQLINTEGER * pcbColDef, SQLSMALLINT * pibScale, SQLSMALLINT * pfNullable ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLDescribeColW_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLDescribeColW_symbol = dlsym(dlhandle, "SQLDescribeColW");
    libdb400_SQLDescribeColW_flag = 1;
  }
  sqlrc = libdb400_SQLDescribeColW_symbol( hstmt, icol, szColName, cbColNameMax, pcbColName, pfSqlType, pcbColDef, pibScale, pfNullable );
  return sqlrc;
}
SQLRETURN libdb400_SQLDescribeParam( SQLHSTMT  hstmt, SQLSMALLINT  ipar, SQLSMALLINT * pfSqlType, SQLINTEGER * pcbColDef, SQLSMALLINT * pibScale, SQLSMALLINT * pfNullable ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLDescribeParam_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLDescribeParam_symbol = dlsym(dlhandle, "SQLDescribeParam");
    libdb400_SQLDescribeParam_flag = 1;
  }
  sqlrc = libdb400_SQLDescribeParam_symbol( hstmt, ipar, pfSqlType, pcbColDef, pibScale, pfNullable );
  return sqlrc;
}
SQLRETURN libdb400_SQLDisconnect( SQLHDBC  hdbc ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLDisconnect_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLDisconnect_symbol = dlsym(dlhandle, "SQLDisconnect");
    libdb400_SQLDisconnect_flag = 1;
  }
  sqlrc = libdb400_SQLDisconnect_symbol( hdbc );
  return sqlrc;
}
SQLRETURN libdb400_SQLDriverConnect( SQLHDBC  hdbc, SQLPOINTER  hwnd, SQLCHAR * szConnStrIn, SQLSMALLINT  cbConnStrin, SQLCHAR * szConnStrOut, SQLSMALLINT  cbConnStrOutMax, SQLSMALLINT * pcbConnStrOut, SQLSMALLINT  fDriverCompletion ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLDriverConnect_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLDriverConnect_symbol = dlsym(dlhandle, "SQLDriverConnect");
    libdb400_SQLDriverConnect_flag = 1;
  }
  sqlrc = libdb400_SQLDriverConnect_symbol( hdbc, hwnd, szConnStrIn, cbConnStrin, szConnStrOut, cbConnStrOutMax, pcbConnStrOut, fDriverCompletion );
  return sqlrc;
}
SQLRETURN libdb400_SQLDriverConnectW( SQLHDBC  hdbc, SQLPOINTER  hwnd, SQLWCHAR * szConnStrIn, SQLSMALLINT  cbConnStrin, SQLWCHAR * szConnStrOut, SQLSMALLINT  cbConnStrOutMax, SQLSMALLINT * pcbConnStrOut, SQLSMALLINT  fDriverCompletion ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLDriverConnectW_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLDriverConnectW_symbol = dlsym(dlhandle, "SQLDriverConnectW");
    libdb400_SQLDriverConnectW_flag = 1;
  }
  sqlrc = libdb400_SQLDriverConnectW_symbol( hdbc, hwnd, szConnStrIn, cbConnStrin, szConnStrOut, cbConnStrOutMax, pcbConnStrOut, fDriverCompletion );
  return sqlrc;
}
SQLRETURN libdb400_SQLEndTran( SQLSMALLINT  htype, SQLHENV  henv, SQLSMALLINT  ctype ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLEndTran_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLEndTran_symbol = dlsym(dlhandle, "SQLEndTran");
    libdb400_SQLEndTran_flag = 1;
  }
  sqlrc = libdb400_SQLEndTran_symbol( htype, henv, ctype );
  return sqlrc;
}
SQLRETURN libdb400_SQLError( SQLHENV  henv, SQLHDBC  hdbc, SQLHSTMT  hstmt, SQLCHAR * szSqlState, SQLINTEGER * pfNativeError, SQLCHAR * szErrorMsg, SQLSMALLINT  cbErrorMsgMax, SQLSMALLINT * pcbErrorMsg ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLError_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLError_symbol = dlsym(dlhandle, "SQLError");
    libdb400_SQLError_flag = 1;
  }
  sqlrc = libdb400_SQLError_symbol( henv, hdbc, hstmt, szSqlState, pfNativeError, szErrorMsg, cbErrorMsgMax, pcbErrorMsg );
  return sqlrc;
}
SQLRETURN libdb400_SQLErrorW( SQLHENV  henv, SQLHDBC  hdbc, SQLHSTMT  hstmt, SQLWCHAR * szSqlState, SQLINTEGER * pfNativeError, SQLWCHAR * szErrorMsg, SQLSMALLINT  cbErrorMsgMax, SQLSMALLINT * pcbErrorMsg ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLErrorW_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLErrorW_symbol = dlsym(dlhandle, "SQLErrorW");
    libdb400_SQLErrorW_flag = 1;
  }
  sqlrc = libdb400_SQLErrorW_symbol( henv, hdbc, hstmt, szSqlState, pfNativeError, szErrorMsg, cbErrorMsgMax, pcbErrorMsg );
  return sqlrc;
}
SQLRETURN libdb400_SQLExecDirect( SQLHSTMT  hstmt, SQLCHAR * szSqlStr, SQLINTEGER  cbSqlStr ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLExecDirect_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLExecDirect_symbol = dlsym(dlhandle, "SQLExecDirect");
    libdb400_SQLExecDirect_flag = 1;
  }
  sqlrc = libdb400_SQLExecDirect_symbol( hstmt, szSqlStr, cbSqlStr );
  return sqlrc;
}
SQLRETURN libdb400_SQLExecDirectW( SQLHSTMT  hstmt, SQLWCHAR * szSqlStr, SQLINTEGER  cbSqlStr ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLExecDirectW_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLExecDirectW_symbol = dlsym(dlhandle, "SQLExecDirectW");
    libdb400_SQLExecDirectW_flag = 1;
  }
  sqlrc = libdb400_SQLExecDirectW_symbol( hstmt, szSqlStr, cbSqlStr );
  return sqlrc;
}
SQLRETURN libdb400_SQLExecute( SQLHSTMT  hstmt ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLExecute_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLExecute_symbol = dlsym(dlhandle, "SQLExecute");
    libdb400_SQLExecute_flag = 1;
  }
  sqlrc = libdb400_SQLExecute_symbol( hstmt );
  return sqlrc;
}
SQLRETURN libdb400_SQLExtendedFetch( SQLHSTMT  hstmt, SQLSMALLINT  fOrient, SQLINTEGER  fOffset, SQLINTEGER * pcrow, SQLSMALLINT * rgfRowStatus ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLExtendedFetch_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLExtendedFetch_symbol = dlsym(dlhandle, "SQLExtendedFetch");
    libdb400_SQLExtendedFetch_flag = 1;
  }
  sqlrc = libdb400_SQLExtendedFetch_symbol( hstmt, fOrient, fOffset, pcrow, rgfRowStatus );
  return sqlrc;
}
SQLRETURN libdb400_SQLFetch( SQLHSTMT  hstmt ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLFetch_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLFetch_symbol = dlsym(dlhandle, "SQLFetch");
    libdb400_SQLFetch_flag = 1;
  }
  sqlrc = libdb400_SQLFetch_symbol( hstmt );
  return sqlrc;
}
SQLRETURN libdb400_SQLFetchScroll( SQLHSTMT  hstmt, SQLSMALLINT  fOrient, SQLINTEGER  fOffset ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLFetchScroll_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLFetchScroll_symbol = dlsym(dlhandle, "SQLFetchScroll");
    libdb400_SQLFetchScroll_flag = 1;
  }
  sqlrc = libdb400_SQLFetchScroll_symbol( hstmt, fOrient, fOffset );
  return sqlrc;
}
SQLRETURN libdb400_SQLForeignKeys( SQLHSTMT  hstmt, SQLCHAR * szPkTableQualifier, SQLSMALLINT  cbPkTableQualifier, SQLCHAR * szPkTableOwner, SQLSMALLINT  cbPkTableOwner, SQLCHAR * szPkTableName, SQLSMALLINT  cbPkTableName, SQLCHAR * szFkTableQualifier, SQLSMALLINT  cbFkTableQualifier, SQLCHAR * szFkTableOwner, SQLSMALLINT  cbFkTableOwner, SQLCHAR * szFkTableName, SQLSMALLINT  cbFkTableName ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLForeignKeys_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLForeignKeys_symbol = dlsym(dlhandle, "SQLForeignKeys");
    libdb400_SQLForeignKeys_flag = 1;
  }
  sqlrc = libdb400_SQLForeignKeys_symbol( hstmt, szPkTableQualifier, cbPkTableQualifier, szPkTableOwner, cbPkTableOwner, szPkTableName, cbPkTableName, szFkTableQualifier, cbFkTableQualifier, szFkTableOwner, cbFkTableOwner, szFkTableName, cbFkTableName );
  return sqlrc;
}
SQLRETURN libdb400_SQLForeignKeysW( SQLHSTMT  hstmt, SQLWCHAR * szPkTableQualifier, SQLSMALLINT  cbPkTableQualifier, SQLWCHAR * szPkTableOwner, SQLSMALLINT  cbPkTableOwner, SQLWCHAR * szPkTableName, SQLSMALLINT  cbPkTableName, SQLWCHAR * szFkTableQualifier, SQLSMALLINT  cbFkTableQualifier, SQLWCHAR * szFkTableOwner, SQLSMALLINT  cbFkTableOwner, SQLWCHAR * szFkTableName, SQLSMALLINT  cbFkTableName ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLForeignKeysW_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLForeignKeysW_symbol = dlsym(dlhandle, "SQLForeignKeysW");
    libdb400_SQLForeignKeysW_flag = 1;
  }
  sqlrc = libdb400_SQLForeignKeysW_symbol( hstmt, szPkTableQualifier, cbPkTableQualifier, szPkTableOwner, cbPkTableOwner, szPkTableName, cbPkTableName, szFkTableQualifier, cbFkTableQualifier, szFkTableOwner, cbFkTableOwner, szFkTableName, cbFkTableName );
  return sqlrc;
}
SQLRETURN libdb400_SQLFreeConnect( SQLHDBC  hdbc ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLFreeConnect_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLFreeConnect_symbol = dlsym(dlhandle, "SQLFreeConnect");
    libdb400_SQLFreeConnect_flag = 1;
  }
  sqlrc = libdb400_SQLFreeConnect_symbol( hdbc );
  return sqlrc;
}
SQLRETURN libdb400_SQLFreeEnv( SQLHENV  henv ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLFreeEnv_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLFreeEnv_symbol = dlsym(dlhandle, "SQLFreeEnv");
    libdb400_SQLFreeEnv_flag = 1;
  }
  sqlrc = libdb400_SQLFreeEnv_symbol( henv );
  return sqlrc;
}
SQLRETURN libdb400_SQLFreeStmt( SQLHSTMT  hstmt, SQLSMALLINT  fOption ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLFreeStmt_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLFreeStmt_symbol = dlsym(dlhandle, "SQLFreeStmt");
    libdb400_SQLFreeStmt_flag = 1;
  }
  sqlrc = libdb400_SQLFreeStmt_symbol( hstmt, fOption );
  return sqlrc;
}
SQLRETURN libdb400_SQLFreeHandle( SQLSMALLINT  htype, SQLINTEGER  hndl ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLFreeHandle_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLFreeHandle_symbol = dlsym(dlhandle, "SQLFreeHandle");
    libdb400_SQLFreeHandle_flag = 1;
  }
  sqlrc = libdb400_SQLFreeHandle_symbol( htype, hndl );
  return sqlrc;
}
SQLRETURN libdb400_SQLGetCol( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  itype, SQLPOINTER  tval, SQLINTEGER  blen, SQLINTEGER * olen ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLGetCol_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLGetCol_symbol = dlsym(dlhandle, "SQLGetCol");
    libdb400_SQLGetCol_flag = 1;
  }
  sqlrc = libdb400_SQLGetCol_symbol( hstmt, icol, itype, tval, blen, olen );
  return sqlrc;
}
SQLRETURN libdb400_SQLGetColW( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  itype, SQLPOINTER  tval, SQLINTEGER  blen, SQLINTEGER * olen ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLGetColW_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLGetColW_symbol = dlsym(dlhandle, "SQLGetColW");
    libdb400_SQLGetColW_flag = 1;
  }
  sqlrc = libdb400_SQLGetColW_symbol( hstmt, icol, itype, tval, blen, olen );
  return sqlrc;
}
SQLRETURN libdb400_SQLGetConnectAttr( SQLHDBC  hdbc, SQLINTEGER  attr, SQLPOINTER  oval, SQLINTEGER  ilen, SQLINTEGER * olen ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLGetConnectAttr_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLGetConnectAttr_symbol = dlsym(dlhandle, "SQLGetConnectAttr");
    libdb400_SQLGetConnectAttr_flag = 1;
  }
  sqlrc = libdb400_SQLGetConnectAttr_symbol( hdbc, attr, oval, ilen, olen );
  return sqlrc;
}
SQLRETURN libdb400_SQLGetConnectAttrW( SQLHDBC  hdbc, SQLINTEGER  attr, SQLPOINTER  oval, SQLINTEGER  ilen, SQLINTEGER * olen ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLGetConnectAttrW_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLGetConnectAttrW_symbol = dlsym(dlhandle, "SQLGetConnectAttrW");
    libdb400_SQLGetConnectAttrW_flag = 1;
  }
  sqlrc = libdb400_SQLGetConnectAttrW_symbol( hdbc, attr, oval, ilen, olen );
  return sqlrc;
}
SQLRETURN libdb400_SQLGetConnectOption( SQLHDBC  hdbc, SQLSMALLINT  iopt, SQLPOINTER  oval ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLGetConnectOption_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLGetConnectOption_symbol = dlsym(dlhandle, "SQLGetConnectOption");
    libdb400_SQLGetConnectOption_flag = 1;
  }
  sqlrc = libdb400_SQLGetConnectOption_symbol( hdbc, iopt, oval );
  return sqlrc;
}
SQLRETURN libdb400_SQLGetConnectOptionW( SQLHDBC  hdbc, SQLSMALLINT  iopt, SQLPOINTER  oval ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLGetConnectOptionW_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLGetConnectOptionW_symbol = dlsym(dlhandle, "SQLGetConnectOptionW");
    libdb400_SQLGetConnectOptionW_flag = 1;
  }
  sqlrc = libdb400_SQLGetConnectOptionW_symbol( hdbc, iopt, oval );
  return sqlrc;
}
SQLRETURN libdb400_SQLGetCursorName( SQLHSTMT  hstmt, SQLCHAR * szCursor, SQLSMALLINT  cbCursorMax, SQLSMALLINT * pcbCursor ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLGetCursorName_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLGetCursorName_symbol = dlsym(dlhandle, "SQLGetCursorName");
    libdb400_SQLGetCursorName_flag = 1;
  }
  sqlrc = libdb400_SQLGetCursorName_symbol( hstmt, szCursor, cbCursorMax, pcbCursor );
  return sqlrc;
}
SQLRETURN libdb400_SQLGetCursorNameW( SQLHSTMT  hstmt, SQLWCHAR * szCursor, SQLSMALLINT  cbCursorMax, SQLSMALLINT * pcbCursor ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLGetCursorNameW_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLGetCursorNameW_symbol = dlsym(dlhandle, "SQLGetCursorNameW");
    libdb400_SQLGetCursorNameW_flag = 1;
  }
  sqlrc = libdb400_SQLGetCursorNameW_symbol( hstmt, szCursor, cbCursorMax, pcbCursor );
  return sqlrc;
}
SQLRETURN libdb400_SQLGetData( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fCType, SQLPOINTER  rgbValue, SQLINTEGER  cbValueMax, SQLINTEGER * pcbValue ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLGetData_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLGetData_symbol = dlsym(dlhandle, "SQLGetData");
    libdb400_SQLGetData_flag = 1;
  }
  sqlrc = libdb400_SQLGetData_symbol( hstmt, icol, fCType, rgbValue, cbValueMax, pcbValue );
  return sqlrc;
}
SQLRETURN libdb400_SQLGetDescField( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  fieldID, SQLPOINTER  fValue, SQLINTEGER  fLength, SQLINTEGER * stLength ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLGetDescField_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLGetDescField_symbol = dlsym(dlhandle, "SQLGetDescField");
    libdb400_SQLGetDescField_flag = 1;
  }
  sqlrc = libdb400_SQLGetDescField_symbol( hdesc, rcdNum, fieldID, fValue, fLength, stLength );
  return sqlrc;
}
SQLRETURN libdb400_SQLGetDescFieldW( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  fieldID, SQLPOINTER  fValue, SQLINTEGER  fLength, SQLINTEGER * stLength ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLGetDescFieldW_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLGetDescFieldW_symbol = dlsym(dlhandle, "SQLGetDescFieldW");
    libdb400_SQLGetDescFieldW_flag = 1;
  }
  sqlrc = libdb400_SQLGetDescFieldW_symbol( hdesc, rcdNum, fieldID, fValue, fLength, stLength );
  return sqlrc;
}
SQLRETURN libdb400_SQLGetDescRec( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLCHAR * fname, SQLSMALLINT  bufLen, SQLSMALLINT * sLength, SQLSMALLINT * sType, SQLSMALLINT * sbType, SQLINTEGER * fLength, SQLSMALLINT * fprec, SQLSMALLINT * fscale, SQLSMALLINT * fnull ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLGetDescRec_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLGetDescRec_symbol = dlsym(dlhandle, "SQLGetDescRec");
    libdb400_SQLGetDescRec_flag = 1;
  }
  sqlrc = libdb400_SQLGetDescRec_symbol( hdesc, rcdNum, fname, bufLen, sLength, sType, sbType, fLength, fprec, fscale, fnull );
  return sqlrc;
}
SQLRETURN libdb400_SQLGetDescRecW( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLWCHAR * fname, SQLSMALLINT  bufLen, SQLSMALLINT * sLength, SQLSMALLINT * sType, SQLSMALLINT * sbType, SQLINTEGER * fLength, SQLSMALLINT * fprec, SQLSMALLINT * fscale, SQLSMALLINT * fnull ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLGetDescRecW_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLGetDescRecW_symbol = dlsym(dlhandle, "SQLGetDescRecW");
    libdb400_SQLGetDescRecW_flag = 1;
  }
  sqlrc = libdb400_SQLGetDescRecW_symbol( hdesc, rcdNum, fname, bufLen, sLength, sType, sbType, fLength, fprec, fscale, fnull );
  return sqlrc;
}
SQLRETURN libdb400_SQLGetDiagField( SQLSMALLINT  hType, SQLINTEGER  hndl, SQLSMALLINT  rcdNum, SQLSMALLINT  diagID, SQLPOINTER  dValue, SQLSMALLINT  bLength, SQLSMALLINT * sLength ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLGetDiagField_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLGetDiagField_symbol = dlsym(dlhandle, "SQLGetDiagField");
    libdb400_SQLGetDiagField_flag = 1;
  }
  sqlrc = libdb400_SQLGetDiagField_symbol( hType, hndl, rcdNum, diagID, dValue, bLength, sLength );
  return sqlrc;
}
SQLRETURN libdb400_SQLGetDiagFieldW( SQLSMALLINT  hType, SQLINTEGER  hndl, SQLSMALLINT  rcdNum, SQLSMALLINT  diagID, SQLPOINTER  dValue, SQLSMALLINT  bLength, SQLSMALLINT * sLength ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLGetDiagFieldW_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLGetDiagFieldW_symbol = dlsym(dlhandle, "SQLGetDiagFieldW");
    libdb400_SQLGetDiagFieldW_flag = 1;
  }
  sqlrc = libdb400_SQLGetDiagFieldW_symbol( hType, hndl, rcdNum, diagID, dValue, bLength, sLength );
  return sqlrc;
}
SQLRETURN libdb400_SQLGetDiagRec( SQLSMALLINT  hType, SQLINTEGER  hndl, SQLSMALLINT  rcdNum, SQLCHAR * SQLstate, SQLINTEGER * SQLcode, SQLCHAR * msgText, SQLSMALLINT  bLength, SQLSMALLINT * SLength ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLGetDiagRec_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLGetDiagRec_symbol = dlsym(dlhandle, "SQLGetDiagRec");
    libdb400_SQLGetDiagRec_flag = 1;
  }
  sqlrc = libdb400_SQLGetDiagRec_symbol( hType, hndl, rcdNum, SQLstate, SQLcode, msgText, bLength, SLength );
  return sqlrc;
}
SQLRETURN libdb400_SQLGetDiagRecW( SQLSMALLINT  hType, SQLINTEGER  hndl, SQLSMALLINT  rcdNum, SQLWCHAR * SQLstate, SQLINTEGER * SQLcode, SQLWCHAR * msgText, SQLSMALLINT  bLength, SQLSMALLINT * SLength ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLGetDiagRecW_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLGetDiagRecW_symbol = dlsym(dlhandle, "SQLGetDiagRecW");
    libdb400_SQLGetDiagRecW_flag = 1;
  }
  sqlrc = libdb400_SQLGetDiagRecW_symbol( hType, hndl, rcdNum, SQLstate, SQLcode, msgText, bLength, SLength );
  return sqlrc;
}
SQLRETURN libdb400_SQLGetEnvAttr( SQLHENV  hEnv, SQLINTEGER  fAttribute, SQLPOINTER  pParam, SQLINTEGER  cbParamMax, SQLINTEGER * pcbParam ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLGetEnvAttr_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLGetEnvAttr_symbol = dlsym(dlhandle, "SQLGetEnvAttr");
    libdb400_SQLGetEnvAttr_flag = 1;
  }
  sqlrc = libdb400_SQLGetEnvAttr_symbol( hEnv, fAttribute, pParam, cbParamMax, pcbParam );
  return sqlrc;
}
SQLRETURN libdb400_SQLGetFunctions( SQLHDBC  hdbc, SQLSMALLINT  fFunction, SQLSMALLINT * pfExists ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLGetFunctions_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLGetFunctions_symbol = dlsym(dlhandle, "SQLGetFunctions");
    libdb400_SQLGetFunctions_flag = 1;
  }
  sqlrc = libdb400_SQLGetFunctions_symbol( hdbc, fFunction, pfExists );
  return sqlrc;
}
SQLRETURN libdb400_SQLGetInfo( SQLHDBC  hdbc, SQLSMALLINT  fInfoType, SQLPOINTER  rgbInfoValue, SQLSMALLINT  cbInfoValueMax, SQLSMALLINT * pcbInfoValue ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLGetInfo_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLGetInfo_symbol = dlsym(dlhandle, "SQLGetInfo");
    libdb400_SQLGetInfo_flag = 1;
  }
  sqlrc = libdb400_SQLGetInfo_symbol( hdbc, fInfoType, rgbInfoValue, cbInfoValueMax, pcbInfoValue );
  return sqlrc;
}
SQLRETURN libdb400_SQLGetInfoW( SQLHDBC  hdbc, SQLSMALLINT  fInfoType, SQLPOINTER  rgbInfoValue, SQLSMALLINT  cbInfoValueMax, SQLSMALLINT * pcbInfoValue ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLGetInfoW_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLGetInfoW_symbol = dlsym(dlhandle, "SQLGetInfoW");
    libdb400_SQLGetInfoW_flag = 1;
  }
  sqlrc = libdb400_SQLGetInfoW_symbol( hdbc, fInfoType, rgbInfoValue, cbInfoValueMax, pcbInfoValue );
  return sqlrc;
}
SQLRETURN libdb400_SQLGetLength( SQLHSTMT  hstmt, SQLSMALLINT  locType, SQLINTEGER  locator, SQLINTEGER * sLength, SQLINTEGER * ind ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLGetLength_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLGetLength_symbol = dlsym(dlhandle, "SQLGetLength");
    libdb400_SQLGetLength_flag = 1;
  }
  sqlrc = libdb400_SQLGetLength_symbol( hstmt, locType, locator, sLength, ind );
  return sqlrc;
}
SQLRETURN libdb400_SQLGetPosition( SQLHSTMT  hstmt, SQLSMALLINT  locType, SQLINTEGER  srceLocator, SQLINTEGER  srchLocator, SQLCHAR * srchLiteral, SQLINTEGER  srchLiteralLen, SQLINTEGER  fPosition, SQLINTEGER * located, SQLINTEGER * ind ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLGetPosition_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLGetPosition_symbol = dlsym(dlhandle, "SQLGetPosition");
    libdb400_SQLGetPosition_flag = 1;
  }
  sqlrc = libdb400_SQLGetPosition_symbol( hstmt, locType, srceLocator, srchLocator, srchLiteral, srchLiteralLen, fPosition, located, ind );
  return sqlrc;
}
SQLRETURN libdb400_SQLGetPositionW( SQLHSTMT  hstmt, SQLSMALLINT  locType, SQLINTEGER  srceLocator, SQLINTEGER  srchLocator, SQLWCHAR * srchLiteral, SQLINTEGER  srchLiteralLen, SQLINTEGER  fPosition, SQLINTEGER * located, SQLINTEGER * ind ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLGetPositionW_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLGetPositionW_symbol = dlsym(dlhandle, "SQLGetPositionW");
    libdb400_SQLGetPositionW_flag = 1;
  }
  sqlrc = libdb400_SQLGetPositionW_symbol( hstmt, locType, srceLocator, srchLocator, srchLiteral, srchLiteralLen, fPosition, located, ind );
  return sqlrc;
}
SQLRETURN libdb400_SQLGetStmtAttr( SQLHSTMT  hstmt, SQLINTEGER  fAttr, SQLPOINTER  pvParam, SQLINTEGER  bLength, SQLINTEGER * SLength ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLGetStmtAttr_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLGetStmtAttr_symbol = dlsym(dlhandle, "SQLGetStmtAttr");
    libdb400_SQLGetStmtAttr_flag = 1;
  }
  sqlrc = libdb400_SQLGetStmtAttr_symbol( hstmt, fAttr, pvParam, bLength, SLength );
  return sqlrc;
}
SQLRETURN libdb400_SQLGetStmtAttrW( SQLHSTMT  hstmt, SQLINTEGER  fAttr, SQLPOINTER  pvParam, SQLINTEGER  bLength, SQLINTEGER * SLength ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLGetStmtAttrW_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLGetStmtAttrW_symbol = dlsym(dlhandle, "SQLGetStmtAttrW");
    libdb400_SQLGetStmtAttrW_flag = 1;
  }
  sqlrc = libdb400_SQLGetStmtAttrW_symbol( hstmt, fAttr, pvParam, bLength, SLength );
  return sqlrc;
}
SQLRETURN libdb400_SQLGetStmtOption( SQLHSTMT  hstmt, SQLSMALLINT  fOption, SQLPOINTER  pvParam ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLGetStmtOption_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLGetStmtOption_symbol = dlsym(dlhandle, "SQLGetStmtOption");
    libdb400_SQLGetStmtOption_flag = 1;
  }
  sqlrc = libdb400_SQLGetStmtOption_symbol( hstmt, fOption, pvParam );
  return sqlrc;
}
SQLRETURN libdb400_SQLGetStmtOptionW( SQLHSTMT  hstmt, SQLSMALLINT  fOption, SQLPOINTER  pvParam ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLGetStmtOptionW_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLGetStmtOptionW_symbol = dlsym(dlhandle, "SQLGetStmtOptionW");
    libdb400_SQLGetStmtOptionW_flag = 1;
  }
  sqlrc = libdb400_SQLGetStmtOptionW_symbol( hstmt, fOption, pvParam );
  return sqlrc;
}
SQLRETURN libdb400_SQLGetSubString( SQLHSTMT  hstmt, SQLSMALLINT  locType, SQLINTEGER  srceLocator, SQLINTEGER  fPosition, SQLINTEGER  length, SQLSMALLINT  tType, SQLPOINTER  rgbValue, SQLINTEGER  cbValueMax, SQLINTEGER * StringLength, SQLINTEGER * ind ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLGetSubString_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLGetSubString_symbol = dlsym(dlhandle, "SQLGetSubString");
    libdb400_SQLGetSubString_flag = 1;
  }
  sqlrc = libdb400_SQLGetSubString_symbol( hstmt, locType, srceLocator, fPosition, length, tType, rgbValue, cbValueMax, StringLength, ind );
  return sqlrc;
}
SQLRETURN libdb400_SQLGetSubStringW( SQLHSTMT  hstmt, SQLSMALLINT  locType, SQLINTEGER  srceLocator, SQLINTEGER  fPosition, SQLINTEGER  length, SQLSMALLINT  tType, SQLPOINTER  rgbValue, SQLINTEGER  cbValueMax, SQLINTEGER * StringLength, SQLINTEGER * ind ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLGetSubStringW_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLGetSubStringW_symbol = dlsym(dlhandle, "SQLGetSubStringW");
    libdb400_SQLGetSubStringW_flag = 1;
  }
  sqlrc = libdb400_SQLGetSubStringW_symbol( hstmt, locType, srceLocator, fPosition, length, tType, rgbValue, cbValueMax, StringLength, ind );
  return sqlrc;
}
SQLRETURN libdb400_SQLGetTypeInfo( SQLHSTMT  hstmt, SQLSMALLINT  fSqlType ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLGetTypeInfo_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLGetTypeInfo_symbol = dlsym(dlhandle, "SQLGetTypeInfo");
    libdb400_SQLGetTypeInfo_flag = 1;
  }
  sqlrc = libdb400_SQLGetTypeInfo_symbol( hstmt, fSqlType );
  return sqlrc;
}
SQLRETURN libdb400_SQLGetTypeInfoW( SQLHSTMT  hstmt, SQLSMALLINT  fSqlType ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLGetTypeInfoW_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLGetTypeInfoW_symbol = dlsym(dlhandle, "SQLGetTypeInfoW");
    libdb400_SQLGetTypeInfoW_flag = 1;
  }
  sqlrc = libdb400_SQLGetTypeInfoW_symbol( hstmt, fSqlType );
  return sqlrc;
}
SQLRETURN libdb400_SQLLanguages( SQLHSTMT  hstmt ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLLanguages_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLLanguages_symbol = dlsym(dlhandle, "SQLLanguages");
    libdb400_SQLLanguages_flag = 1;
  }
  sqlrc = libdb400_SQLLanguages_symbol( hstmt );
  return sqlrc;
}
SQLRETURN libdb400_SQLMoreResults( SQLHSTMT  hstmt ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLMoreResults_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLMoreResults_symbol = dlsym(dlhandle, "SQLMoreResults");
    libdb400_SQLMoreResults_flag = 1;
  }
  sqlrc = libdb400_SQLMoreResults_symbol( hstmt );
  return sqlrc;
}
SQLRETURN libdb400_SQLNativeSql( SQLHDBC  hdbc, SQLCHAR * szSqlStrIn, SQLINTEGER  cbSqlStrIn, SQLCHAR * szSqlStr, SQLINTEGER  cbSqlStrMax, SQLINTEGER * pcbSqlStr ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLNativeSql_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLNativeSql_symbol = dlsym(dlhandle, "SQLNativeSql");
    libdb400_SQLNativeSql_flag = 1;
  }
  sqlrc = libdb400_SQLNativeSql_symbol( hdbc, szSqlStrIn, cbSqlStrIn, szSqlStr, cbSqlStrMax, pcbSqlStr );
  return sqlrc;
}
SQLRETURN libdb400_SQLNativeSqlW( SQLHDBC  hdbc, SQLWCHAR * szSqlStrIn, SQLINTEGER  cbSqlStrIn, SQLWCHAR * szSqlStr, SQLINTEGER  cbSqlStrMax, SQLINTEGER * pcbSqlStr ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLNativeSqlW_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLNativeSqlW_symbol = dlsym(dlhandle, "SQLNativeSqlW");
    libdb400_SQLNativeSqlW_flag = 1;
  }
  sqlrc = libdb400_SQLNativeSqlW_symbol( hdbc, szSqlStrIn, cbSqlStrIn, szSqlStr, cbSqlStrMax, pcbSqlStr );
  return sqlrc;
}
SQLRETURN libdb400_SQLNextResult( SQLHSTMT  hstmt, SQLHSTMT  hstmt2 ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLNextResult_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLNextResult_symbol = dlsym(dlhandle, "SQLNextResult");
    libdb400_SQLNextResult_flag = 1;
  }
  sqlrc = libdb400_SQLNextResult_symbol( hstmt, hstmt2 );
  return sqlrc;
}
SQLRETURN libdb400_SQLNumParams( SQLHSTMT  hstmt, SQLSMALLINT * pcpar ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLNumParams_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLNumParams_symbol = dlsym(dlhandle, "SQLNumParams");
    libdb400_SQLNumParams_flag = 1;
  }
  sqlrc = libdb400_SQLNumParams_symbol( hstmt, pcpar );
  return sqlrc;
}
SQLRETURN libdb400_SQLNumResultCols( SQLHSTMT  hstmt, SQLSMALLINT * pccol ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLNumResultCols_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLNumResultCols_symbol = dlsym(dlhandle, "SQLNumResultCols");
    libdb400_SQLNumResultCols_flag = 1;
  }
  sqlrc = libdb400_SQLNumResultCols_symbol( hstmt, pccol );
  return sqlrc;
}
SQLRETURN libdb400_SQLParamData( SQLHSTMT  hstmt, SQLPOINTER * Value ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLParamData_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLParamData_symbol = dlsym(dlhandle, "SQLParamData");
    libdb400_SQLParamData_flag = 1;
  }
  sqlrc = libdb400_SQLParamData_symbol( hstmt, Value );
  return sqlrc;
}
SQLRETURN libdb400_SQLParamOptions( SQLHSTMT  hstmt, SQLINTEGER  crow, SQLINTEGER * pirow ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLParamOptions_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLParamOptions_symbol = dlsym(dlhandle, "SQLParamOptions");
    libdb400_SQLParamOptions_flag = 1;
  }
  sqlrc = libdb400_SQLParamOptions_symbol( hstmt, crow, pirow );
  return sqlrc;
}
SQLRETURN libdb400_SQLPrepare( SQLHSTMT  hstmt, SQLCHAR * szSqlStr, SQLINTEGER  cbSqlStr ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLPrepare_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLPrepare_symbol = dlsym(dlhandle, "SQLPrepare");
    libdb400_SQLPrepare_flag = 1;
  }
  sqlrc = libdb400_SQLPrepare_symbol( hstmt, szSqlStr, cbSqlStr );
  return sqlrc;
}
SQLRETURN libdb400_SQLPrepareW( SQLHSTMT  hstmt, SQLWCHAR * szSqlStr, SQLINTEGER  cbSqlStr ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLPrepareW_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLPrepareW_symbol = dlsym(dlhandle, "SQLPrepareW");
    libdb400_SQLPrepareW_flag = 1;
  }
  sqlrc = libdb400_SQLPrepareW_symbol( hstmt, szSqlStr, cbSqlStr );
  return sqlrc;
}
SQLRETURN libdb400_SQLPrimaryKeys( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLPrimaryKeys_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLPrimaryKeys_symbol = dlsym(dlhandle, "SQLPrimaryKeys");
    libdb400_SQLPrimaryKeys_flag = 1;
  }
  sqlrc = libdb400_SQLPrimaryKeys_symbol( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName );
  return sqlrc;
}
SQLRETURN libdb400_SQLPrimaryKeysW( SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLPrimaryKeysW_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLPrimaryKeysW_symbol = dlsym(dlhandle, "SQLPrimaryKeysW");
    libdb400_SQLPrimaryKeysW_flag = 1;
  }
  sqlrc = libdb400_SQLPrimaryKeysW_symbol( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName );
  return sqlrc;
}
SQLRETURN libdb400_SQLProcedureColumns( SQLHSTMT  hstmt, SQLCHAR * szProcQualifier, SQLSMALLINT  cbProcQualifier, SQLCHAR * szProcOwner, SQLSMALLINT  cbProcOwner, SQLCHAR * szProcName, SQLSMALLINT  cbProcName, SQLCHAR * szColumnName, SQLSMALLINT  cbColumnName ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLProcedureColumns_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLProcedureColumns_symbol = dlsym(dlhandle, "SQLProcedureColumns");
    libdb400_SQLProcedureColumns_flag = 1;
  }
  sqlrc = libdb400_SQLProcedureColumns_symbol( hstmt, szProcQualifier, cbProcQualifier, szProcOwner, cbProcOwner, szProcName, cbProcName, szColumnName, cbColumnName );
  return sqlrc;
}
SQLRETURN libdb400_SQLProcedureColumnsW( SQLHSTMT  hstmt, SQLWCHAR * szProcQualifier, SQLSMALLINT  cbProcQualifier, SQLWCHAR * szProcOwner, SQLSMALLINT  cbProcOwner, SQLWCHAR * szProcName, SQLSMALLINT  cbProcName, SQLWCHAR * szColumnName, SQLSMALLINT  cbColumnName ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLProcedureColumnsW_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLProcedureColumnsW_symbol = dlsym(dlhandle, "SQLProcedureColumnsW");
    libdb400_SQLProcedureColumnsW_flag = 1;
  }
  sqlrc = libdb400_SQLProcedureColumnsW_symbol( hstmt, szProcQualifier, cbProcQualifier, szProcOwner, cbProcOwner, szProcName, cbProcName, szColumnName, cbColumnName );
  return sqlrc;
}
SQLRETURN libdb400_SQLProcedures( SQLHSTMT  hstmt, SQLCHAR * szProcQualifier, SQLSMALLINT  cbProcQualifier, SQLCHAR * szProcOwner, SQLSMALLINT  cbProcOwner, SQLCHAR * szProcName, SQLSMALLINT  cbProcName ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLProcedures_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLProcedures_symbol = dlsym(dlhandle, "SQLProcedures");
    libdb400_SQLProcedures_flag = 1;
  }
  sqlrc = libdb400_SQLProcedures_symbol( hstmt, szProcQualifier, cbProcQualifier, szProcOwner, cbProcOwner, szProcName, cbProcName );
  return sqlrc;
}
SQLRETURN libdb400_SQLProceduresW( SQLHSTMT  hstmt, SQLWCHAR * szProcQualifier, SQLSMALLINT  cbProcQualifier, SQLWCHAR * szProcOwner, SQLSMALLINT  cbProcOwner, SQLWCHAR * szProcName, SQLSMALLINT  cbProcName ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLProceduresW_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLProceduresW_symbol = dlsym(dlhandle, "SQLProceduresW");
    libdb400_SQLProceduresW_flag = 1;
  }
  sqlrc = libdb400_SQLProceduresW_symbol( hstmt, szProcQualifier, cbProcQualifier, szProcOwner, cbProcOwner, szProcName, cbProcName );
  return sqlrc;
}
SQLRETURN libdb400_SQLPutData( SQLHSTMT  hstmt, SQLPOINTER  Data, SQLINTEGER  SLen ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLPutData_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLPutData_symbol = dlsym(dlhandle, "SQLPutData");
    libdb400_SQLPutData_flag = 1;
  }
  sqlrc = libdb400_SQLPutData_symbol( hstmt, Data, SLen );
  return sqlrc;
}
SQLRETURN libdb400_SQLReleaseEnv( SQLHENV  henv ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLReleaseEnv_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLReleaseEnv_symbol = dlsym(dlhandle, "SQLReleaseEnv");
    libdb400_SQLReleaseEnv_flag = 1;
  }
  sqlrc = libdb400_SQLReleaseEnv_symbol( henv );
  return sqlrc;
}
SQLRETURN libdb400_SQLRowCount( SQLHSTMT  hstmt, SQLINTEGER * pcrow ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLRowCount_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLRowCount_symbol = dlsym(dlhandle, "SQLRowCount");
    libdb400_SQLRowCount_flag = 1;
  }
  sqlrc = libdb400_SQLRowCount_symbol( hstmt, pcrow );
  return sqlrc;
}
SQLRETURN libdb400_SQLSetConnectAttr( SQLHDBC  hdbc, SQLINTEGER  attrib, SQLPOINTER  vParam, SQLINTEGER  inlen ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLSetConnectAttr_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLSetConnectAttr_symbol = dlsym(dlhandle, "SQLSetConnectAttr");
    libdb400_SQLSetConnectAttr_flag = 1;
  }
  sqlrc = libdb400_SQLSetConnectAttr_symbol( hdbc, attrib, vParam, inlen );
  return sqlrc;
}
SQLRETURN libdb400_SQLSetConnectAttrW( SQLHDBC  hdbc, SQLINTEGER  attrib, SQLPOINTER  vParam, SQLINTEGER  inlen ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLSetConnectAttrW_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLSetConnectAttrW_symbol = dlsym(dlhandle, "SQLSetConnectAttrW");
    libdb400_SQLSetConnectAttrW_flag = 1;
  }
  sqlrc = libdb400_SQLSetConnectAttrW_symbol( hdbc, attrib, vParam, inlen );
  return sqlrc;
}
SQLRETURN libdb400_SQLSetConnectOption( SQLHDBC  hdbc, SQLSMALLINT  fOption, SQLPOINTER  vParam ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLSetConnectOption_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLSetConnectOption_symbol = dlsym(dlhandle, "SQLSetConnectOption");
    libdb400_SQLSetConnectOption_flag = 1;
  }
  sqlrc = libdb400_SQLSetConnectOption_symbol( hdbc, fOption, vParam );
  return sqlrc;
}
SQLRETURN libdb400_SQLSetConnectOptionW( SQLHDBC  hdbc, SQLSMALLINT  fOption, SQLPOINTER  vParam ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLSetConnectOptionW_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLSetConnectOptionW_symbol = dlsym(dlhandle, "SQLSetConnectOptionW");
    libdb400_SQLSetConnectOptionW_flag = 1;
  }
  sqlrc = libdb400_SQLSetConnectOptionW_symbol( hdbc, fOption, vParam );
  return sqlrc;
}
SQLRETURN libdb400_SQLSetCursorName( SQLHSTMT  hstmt, SQLCHAR * szCursor, SQLSMALLINT  cbCursor ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLSetCursorName_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLSetCursorName_symbol = dlsym(dlhandle, "SQLSetCursorName");
    libdb400_SQLSetCursorName_flag = 1;
  }
  sqlrc = libdb400_SQLSetCursorName_symbol( hstmt, szCursor, cbCursor );
  return sqlrc;
}
SQLRETURN libdb400_SQLSetCursorNameW( SQLHSTMT  hstmt, SQLWCHAR * szCursor, SQLSMALLINT  cbCursor ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLSetCursorNameW_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLSetCursorNameW_symbol = dlsym(dlhandle, "SQLSetCursorNameW");
    libdb400_SQLSetCursorNameW_flag = 1;
  }
  sqlrc = libdb400_SQLSetCursorNameW_symbol( hstmt, szCursor, cbCursor );
  return sqlrc;
}
SQLRETURN libdb400_SQLSetDescField( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  fID, SQLPOINTER  Value, SQLINTEGER  buffLen ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLSetDescField_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLSetDescField_symbol = dlsym(dlhandle, "SQLSetDescField");
    libdb400_SQLSetDescField_flag = 1;
  }
  sqlrc = libdb400_SQLSetDescField_symbol( hdesc, rcdNum, fID, Value, buffLen );
  return sqlrc;
}
SQLRETURN libdb400_SQLSetDescFieldW( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  fID, SQLPOINTER  Value, SQLINTEGER  buffLen ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLSetDescFieldW_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLSetDescFieldW_symbol = dlsym(dlhandle, "SQLSetDescFieldW");
    libdb400_SQLSetDescFieldW_flag = 1;
  }
  sqlrc = libdb400_SQLSetDescFieldW_symbol( hdesc, rcdNum, fID, Value, buffLen );
  return sqlrc;
}
SQLRETURN libdb400_SQLSetDescRec( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  Type, SQLSMALLINT  subType, SQLINTEGER  fLength, SQLSMALLINT  fPrec, SQLSMALLINT  fScale, SQLPOINTER  Value, SQLINTEGER * sLength, SQLINTEGER * indic ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLSetDescRec_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLSetDescRec_symbol = dlsym(dlhandle, "SQLSetDescRec");
    libdb400_SQLSetDescRec_flag = 1;
  }
  sqlrc = libdb400_SQLSetDescRec_symbol( hdesc, rcdNum, Type, subType, fLength, fPrec, fScale, Value, sLength, indic );
  return sqlrc;
}
SQLRETURN libdb400_SQLSetEnvAttr( SQLHENV  hEnv, SQLINTEGER  fAttribute, SQLPOINTER  pParam, SQLINTEGER  cbParam ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLSetEnvAttr_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLSetEnvAttr_symbol = dlsym(dlhandle, "SQLSetEnvAttr");
    libdb400_SQLSetEnvAttr_flag = 1;
  }
  sqlrc = libdb400_SQLSetEnvAttr_symbol( hEnv, fAttribute, pParam, cbParam );
  return sqlrc;
}
SQLRETURN libdb400_SQLSetParam( SQLHSTMT  hstmt, SQLSMALLINT  ipar, SQLSMALLINT  fCType, SQLSMALLINT  fSqlType, SQLINTEGER  cbColDef, SQLSMALLINT  ibScale, SQLPOINTER  rgbValue, SQLINTEGER * pcbValue ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLSetParam_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLSetParam_symbol = dlsym(dlhandle, "SQLSetParam");
    libdb400_SQLSetParam_flag = 1;
  }
  sqlrc = libdb400_SQLSetParam_symbol( hstmt, ipar, fCType, fSqlType, cbColDef, ibScale, rgbValue, pcbValue );
  return sqlrc;
}
SQLRETURN libdb400_SQLSetStmtAttr( SQLHSTMT  hstmt, SQLINTEGER  fAttr, SQLPOINTER  pParam, SQLINTEGER  vParam ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLSetStmtAttr_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLSetStmtAttr_symbol = dlsym(dlhandle, "SQLSetStmtAttr");
    libdb400_SQLSetStmtAttr_flag = 1;
  }
  sqlrc = libdb400_SQLSetStmtAttr_symbol( hstmt, fAttr, pParam, vParam );
  return sqlrc;
}
SQLRETURN libdb400_SQLSetStmtAttrW( SQLHSTMT  hstmt, SQLINTEGER  fAttr, SQLPOINTER  pParam, SQLINTEGER  vParam ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLSetStmtAttrW_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLSetStmtAttrW_symbol = dlsym(dlhandle, "SQLSetStmtAttrW");
    libdb400_SQLSetStmtAttrW_flag = 1;
  }
  sqlrc = libdb400_SQLSetStmtAttrW_symbol( hstmt, fAttr, pParam, vParam );
  return sqlrc;
}
SQLRETURN libdb400_SQLSetStmtOption( SQLHSTMT  hstmt, SQLSMALLINT  fOption, SQLPOINTER  vParam ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLSetStmtOption_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLSetStmtOption_symbol = dlsym(dlhandle, "SQLSetStmtOption");
    libdb400_SQLSetStmtOption_flag = 1;
  }
  sqlrc = libdb400_SQLSetStmtOption_symbol( hstmt, fOption, vParam );
  return sqlrc;
}
SQLRETURN libdb400_SQLSetStmtOptionW( SQLHSTMT  hstmt, SQLSMALLINT  fOption, SQLPOINTER  vParam ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLSetStmtOptionW_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLSetStmtOptionW_symbol = dlsym(dlhandle, "SQLSetStmtOptionW");
    libdb400_SQLSetStmtOptionW_flag = 1;
  }
  sqlrc = libdb400_SQLSetStmtOptionW_symbol( hstmt, fOption, vParam );
  return sqlrc;
}
SQLRETURN libdb400_SQLSpecialColumns( SQLHSTMT  hstmt, SQLSMALLINT  fColType, SQLCHAR * szTableQual, SQLSMALLINT  cbTableQual, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLSMALLINT  fScope, SQLSMALLINT  fNullable ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLSpecialColumns_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLSpecialColumns_symbol = dlsym(dlhandle, "SQLSpecialColumns");
    libdb400_SQLSpecialColumns_flag = 1;
  }
  sqlrc = libdb400_SQLSpecialColumns_symbol( hstmt, fColType, szTableQual, cbTableQual, szTableOwner, cbTableOwner, szTableName, cbTableName, fScope, fNullable );
  return sqlrc;
}
SQLRETURN libdb400_SQLSpecialColumnsW( SQLHSTMT  hstmt, SQLSMALLINT  fColType, SQLWCHAR * szTableQual, SQLSMALLINT  cbTableQual, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName, SQLSMALLINT  fScope, SQLSMALLINT  fNullable ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLSpecialColumnsW_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLSpecialColumnsW_symbol = dlsym(dlhandle, "SQLSpecialColumnsW");
    libdb400_SQLSpecialColumnsW_flag = 1;
  }
  sqlrc = libdb400_SQLSpecialColumnsW_symbol( hstmt, fColType, szTableQual, cbTableQual, szTableOwner, cbTableOwner, szTableName, cbTableName, fScope, fNullable );
  return sqlrc;
}
SQLRETURN libdb400_SQLStartTran( SQLSMALLINT  htype, SQLHENV  henv, SQLINTEGER  mode, SQLINTEGER  clevel ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLStartTran_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLStartTran_symbol = dlsym(dlhandle, "SQLStartTran");
    libdb400_SQLStartTran_flag = 1;
  }
  sqlrc = libdb400_SQLStartTran_symbol( htype, henv, mode, clevel );
  return sqlrc;
}
SQLRETURN libdb400_SQLStatistics( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLSMALLINT  fUnique, SQLSMALLINT  fres ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLStatistics_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLStatistics_symbol = dlsym(dlhandle, "SQLStatistics");
    libdb400_SQLStatistics_flag = 1;
  }
  sqlrc = libdb400_SQLStatistics_symbol( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName, fUnique, fres );
  return sqlrc;
}
SQLRETURN libdb400_SQLStatisticsW( SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName, SQLSMALLINT  fUnique, SQLSMALLINT  fres ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLStatisticsW_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLStatisticsW_symbol = dlsym(dlhandle, "SQLStatisticsW");
    libdb400_SQLStatisticsW_flag = 1;
  }
  sqlrc = libdb400_SQLStatisticsW_symbol( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName, fUnique, fres );
  return sqlrc;
}
SQLRETURN libdb400_SQLTablePrivileges( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLTablePrivileges_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLTablePrivileges_symbol = dlsym(dlhandle, "SQLTablePrivileges");
    libdb400_SQLTablePrivileges_flag = 1;
  }
  sqlrc = libdb400_SQLTablePrivileges_symbol( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName );
  return sqlrc;
}
SQLRETURN libdb400_SQLTablePrivilegesW( SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLTablePrivilegesW_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLTablePrivilegesW_symbol = dlsym(dlhandle, "SQLTablePrivilegesW");
    libdb400_SQLTablePrivilegesW_flag = 1;
  }
  sqlrc = libdb400_SQLTablePrivilegesW_symbol( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName );
  return sqlrc;
}
SQLRETURN libdb400_SQLTables( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLCHAR * szTableType, SQLSMALLINT  cbTableType ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLTables_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLTables_symbol = dlsym(dlhandle, "SQLTables");
    libdb400_SQLTables_flag = 1;
  }
  sqlrc = libdb400_SQLTables_symbol( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName, szTableType, cbTableType );
  return sqlrc;
}
SQLRETURN libdb400_SQLTablesW( SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName, SQLWCHAR * szTableType, SQLSMALLINT  cbTableType ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLTablesW_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLTablesW_symbol = dlsym(dlhandle, "SQLTablesW");
    libdb400_SQLTablesW_flag = 1;
  }
  sqlrc = libdb400_SQLTablesW_symbol( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName, szTableType, cbTableType );
  return sqlrc;
}
SQLRETURN libdb400_SQLTransact( SQLHENV  henv, SQLHDBC  hdbc, SQLSMALLINT  fType ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLTransact_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLTransact_symbol = dlsym(dlhandle, "SQLTransact");
    libdb400_SQLTransact_flag = 1;
  }
  sqlrc = libdb400_SQLTransact_symbol( henv, hdbc, fType );
  return sqlrc;
}
SQLRETURN libdb400_SQLOverrideCCSID400( SQLINTEGER  newCCSID ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  void *dlhandle = NULL;
  if (!libdb400_SQLOverrideCCSID400_flag) {
    dlhandle = init_cli_dlsym();
    libdb400_SQLOverrideCCSID400_symbol = dlsym(dlhandle, "SQLOverrideCCSID400");
    libdb400_SQLOverrideCCSID400_flag = 1;
  }
  sqlrc = libdb400_SQLOverrideCCSID400_symbol( newCCSID );
  return sqlrc;
}

