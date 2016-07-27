#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dlfcn.h>
#include <sqlcli1.h>
#include <as400_types.h>
#include <as400_protos.h>
#include "PaseCliInit.h"
#include "PaseCliAsync.h"

  /* gcc compiler
   * as400_types.h  
   * #if defined( __GNUC__ )
   *   long double align __attribute__((aligned(16))); gcc force
   * #else 
   *   long double; Force xlc quadword alignment (with -qldbl128 -qalign=natural)
   * #endif 
   * 
   * Use we also need cast ulong to match size of pointer 32/64 
   *   arglist->ohnd.s.addr = (ulong) ohnd;
   */

#define ROUND_QUAD(x) (((size_t)(x) + 0xf) & ~0xf)

SQLINTEGER SQLAllocConnectLoaded;
SQLCHAR SQLAllocConnectBuf[132];
SQLINTEGER SQLAllocEnvLoaded;
SQLCHAR SQLAllocEnvBuf[132];
SQLINTEGER SQLAllocHandleLoaded;
SQLCHAR SQLAllocHandleBuf[132];
SQLINTEGER SQLAllocStmtLoaded;
SQLCHAR SQLAllocStmtBuf[132];
SQLINTEGER SQLBindColLoaded;
SQLCHAR SQLBindColBuf[132];
SQLINTEGER SQLBindFileToColLoaded;
SQLCHAR SQLBindFileToColBuf[132];
SQLINTEGER SQLBindFileToParamLoaded;
SQLCHAR SQLBindFileToParamBuf[132];
SQLINTEGER SQLBindParamLoaded;
SQLCHAR SQLBindParamBuf[132];
SQLINTEGER SQLBindParameterLoaded;
SQLCHAR SQLBindParameterBuf[132];
SQLINTEGER SQLCancelLoaded;
SQLCHAR SQLCancelBuf[132];
SQLINTEGER SQLCloseCursorLoaded;
SQLCHAR SQLCloseCursorBuf[132];
SQLINTEGER SQLColAttributeLoaded;
SQLCHAR SQLColAttributeBuf[132];
SQLINTEGER SQLColAttributeWLoaded;
SQLCHAR SQLColAttributeWBuf[132];
SQLINTEGER SQLColAttributesLoaded;
SQLCHAR SQLColAttributesBuf[132];
SQLINTEGER SQLColAttributesWLoaded;
SQLCHAR SQLColAttributesWBuf[132];
SQLINTEGER SQLColumnPrivilegesLoaded;
SQLCHAR SQLColumnPrivilegesBuf[132];
SQLINTEGER SQLColumnPrivilegesWLoaded;
SQLCHAR SQLColumnPrivilegesWBuf[132];
SQLINTEGER SQLColumnsLoaded;
SQLCHAR SQLColumnsBuf[132];
SQLINTEGER SQLColumnsWLoaded;
SQLCHAR SQLColumnsWBuf[132];
SQLINTEGER SQLConnectLoaded;
SQLCHAR SQLConnectBuf[132];
SQLINTEGER SQLConnectWLoaded;
SQLCHAR SQLConnectWBuf[132];
SQLINTEGER SQLCopyDescLoaded;
SQLCHAR SQLCopyDescBuf[132];
SQLINTEGER SQLDataSourcesLoaded;
SQLCHAR SQLDataSourcesBuf[132];
SQLINTEGER SQLDataSourcesWLoaded;
SQLCHAR SQLDataSourcesWBuf[132];
SQLINTEGER SQLDescribeColLoaded;
SQLCHAR SQLDescribeColBuf[132];
SQLINTEGER SQLDescribeColWLoaded;
SQLCHAR SQLDescribeColWBuf[132];
SQLINTEGER SQLDescribeParamLoaded;
SQLCHAR SQLDescribeParamBuf[132];
SQLINTEGER SQLDisconnectLoaded;
SQLCHAR SQLDisconnectBuf[132];
SQLINTEGER SQLDriverConnectLoaded;
SQLCHAR SQLDriverConnectBuf[132];
SQLINTEGER SQLDriverConnectWLoaded;
SQLCHAR SQLDriverConnectWBuf[132];
SQLINTEGER SQLEndTranLoaded;
SQLCHAR SQLEndTranBuf[132];
SQLINTEGER SQLErrorLoaded;
SQLCHAR SQLErrorBuf[132];
SQLINTEGER SQLErrorWLoaded;
SQLCHAR SQLErrorWBuf[132];
SQLINTEGER SQLExecDirectLoaded;
SQLCHAR SQLExecDirectBuf[132];
SQLINTEGER SQLExecDirectWLoaded;
SQLCHAR SQLExecDirectWBuf[132];
SQLINTEGER SQLExecuteLoaded;
SQLCHAR SQLExecuteBuf[132];
SQLINTEGER SQLExtendedFetchLoaded;
SQLCHAR SQLExtendedFetchBuf[132];
SQLINTEGER SQLFetchLoaded;
SQLCHAR SQLFetchBuf[132];
SQLINTEGER SQLFetchScrollLoaded;
SQLCHAR SQLFetchScrollBuf[132];
SQLINTEGER SQLForeignKeysLoaded;
SQLCHAR SQLForeignKeysBuf[132];
SQLINTEGER SQLForeignKeysWLoaded;
SQLCHAR SQLForeignKeysWBuf[132];
SQLINTEGER SQLFreeConnectLoaded;
SQLCHAR SQLFreeConnectBuf[132];
SQLINTEGER SQLFreeEnvLoaded;
SQLCHAR SQLFreeEnvBuf[132];
SQLINTEGER SQLFreeStmtLoaded;
SQLCHAR SQLFreeStmtBuf[132];
SQLINTEGER SQLFreeHandleLoaded;
SQLCHAR SQLFreeHandleBuf[132];
SQLINTEGER SQLGetColLoaded;
SQLCHAR SQLGetColBuf[132];
SQLINTEGER SQLGetColWLoaded;
SQLCHAR SQLGetColWBuf[132];
SQLINTEGER SQLGetConnectAttrLoaded;
SQLCHAR SQLGetConnectAttrBuf[132];
SQLINTEGER SQLGetConnectAttrWLoaded;
SQLCHAR SQLGetConnectAttrWBuf[132];
SQLINTEGER SQLGetConnectOptionLoaded;
SQLCHAR SQLGetConnectOptionBuf[132];
SQLINTEGER SQLGetConnectOptionWLoaded;
SQLCHAR SQLGetConnectOptionWBuf[132];
SQLINTEGER SQLGetCursorNameLoaded;
SQLCHAR SQLGetCursorNameBuf[132];
SQLINTEGER SQLGetCursorNameWLoaded;
SQLCHAR SQLGetCursorNameWBuf[132];
SQLINTEGER SQLGetDataLoaded;
SQLCHAR SQLGetDataBuf[132];
SQLINTEGER SQLGetDescFieldLoaded;
SQLCHAR SQLGetDescFieldBuf[132];
SQLINTEGER SQLGetDescFieldWLoaded;
SQLCHAR SQLGetDescFieldWBuf[132];
SQLINTEGER SQLGetDescRecLoaded;
SQLCHAR SQLGetDescRecBuf[132];
SQLINTEGER SQLGetDescRecWLoaded;
SQLCHAR SQLGetDescRecWBuf[132];
SQLINTEGER SQLGetDiagFieldLoaded;
SQLCHAR SQLGetDiagFieldBuf[132];
SQLINTEGER SQLGetDiagFieldWLoaded;
SQLCHAR SQLGetDiagFieldWBuf[132];
SQLINTEGER SQLGetDiagRecLoaded;
SQLCHAR SQLGetDiagRecBuf[132];
SQLINTEGER SQLGetDiagRecWLoaded;
SQLCHAR SQLGetDiagRecWBuf[132];
SQLINTEGER SQLGetEnvAttrLoaded;
SQLCHAR SQLGetEnvAttrBuf[132];
SQLINTEGER SQLGetFunctionsLoaded;
SQLCHAR SQLGetFunctionsBuf[132];
SQLINTEGER SQLGetInfoLoaded;
SQLCHAR SQLGetInfoBuf[132];
SQLINTEGER SQLGetInfoWLoaded;
SQLCHAR SQLGetInfoWBuf[132];
SQLINTEGER SQLGetLengthLoaded;
SQLCHAR SQLGetLengthBuf[132];
SQLINTEGER SQLGetPositionLoaded;
SQLCHAR SQLGetPositionBuf[132];
SQLINTEGER SQLGetPositionWLoaded;
SQLCHAR SQLGetPositionWBuf[132];
SQLINTEGER SQLGetStmtAttrLoaded;
SQLCHAR SQLGetStmtAttrBuf[132];
SQLINTEGER SQLGetStmtAttrWLoaded;
SQLCHAR SQLGetStmtAttrWBuf[132];
SQLINTEGER SQLGetStmtOptionLoaded;
SQLCHAR SQLGetStmtOptionBuf[132];
SQLINTEGER SQLGetStmtOptionWLoaded;
SQLCHAR SQLGetStmtOptionWBuf[132];
SQLINTEGER SQLGetSubStringLoaded;
SQLCHAR SQLGetSubStringBuf[132];
SQLINTEGER SQLGetSubStringWLoaded;
SQLCHAR SQLGetSubStringWBuf[132];
SQLINTEGER SQLGetTypeInfoLoaded;
SQLCHAR SQLGetTypeInfoBuf[132];
SQLINTEGER SQLGetTypeInfoWLoaded;
SQLCHAR SQLGetTypeInfoWBuf[132];
SQLINTEGER SQLLanguagesLoaded;
SQLCHAR SQLLanguagesBuf[132];
SQLINTEGER SQLMoreResultsLoaded;
SQLCHAR SQLMoreResultsBuf[132];
SQLINTEGER SQLNativeSqlLoaded;
SQLCHAR SQLNativeSqlBuf[132];
SQLINTEGER SQLNativeSqlWLoaded;
SQLCHAR SQLNativeSqlWBuf[132];
SQLINTEGER SQLNextResultLoaded;
SQLCHAR SQLNextResultBuf[132];
SQLINTEGER SQLNumParamsLoaded;
SQLCHAR SQLNumParamsBuf[132];
SQLINTEGER SQLNumResultColsLoaded;
SQLCHAR SQLNumResultColsBuf[132];
SQLINTEGER SQLParamDataLoaded;
SQLCHAR SQLParamDataBuf[132];
SQLINTEGER SQLParamOptionsLoaded;
SQLCHAR SQLParamOptionsBuf[132];
SQLINTEGER SQLPrepareLoaded;
SQLCHAR SQLPrepareBuf[132];
SQLINTEGER SQLPrepareWLoaded;
SQLCHAR SQLPrepareWBuf[132];
SQLINTEGER SQLPrimaryKeysLoaded;
SQLCHAR SQLPrimaryKeysBuf[132];
SQLINTEGER SQLPrimaryKeysWLoaded;
SQLCHAR SQLPrimaryKeysWBuf[132];
SQLINTEGER SQLProcedureColumnsLoaded;
SQLCHAR SQLProcedureColumnsBuf[132];
SQLINTEGER SQLProcedureColumnsWLoaded;
SQLCHAR SQLProcedureColumnsWBuf[132];
SQLINTEGER SQLProceduresLoaded;
SQLCHAR SQLProceduresBuf[132];
SQLINTEGER SQLProceduresWLoaded;
SQLCHAR SQLProceduresWBuf[132];
SQLINTEGER SQLPutDataLoaded;
SQLCHAR SQLPutDataBuf[132];
SQLINTEGER SQLReleaseEnvLoaded;
SQLCHAR SQLReleaseEnvBuf[132];
SQLINTEGER SQLRowCountLoaded;
SQLCHAR SQLRowCountBuf[132];
SQLINTEGER SQLSetConnectAttrLoaded;
SQLCHAR SQLSetConnectAttrBuf[132];
SQLINTEGER SQLSetConnectAttrWLoaded;
SQLCHAR SQLSetConnectAttrWBuf[132];
SQLINTEGER SQLSetConnectOptionLoaded;
SQLCHAR SQLSetConnectOptionBuf[132];
SQLINTEGER SQLSetConnectOptionWLoaded;
SQLCHAR SQLSetConnectOptionWBuf[132];
SQLINTEGER SQLSetCursorNameLoaded;
SQLCHAR SQLSetCursorNameBuf[132];
SQLINTEGER SQLSetCursorNameWLoaded;
SQLCHAR SQLSetCursorNameWBuf[132];
SQLINTEGER SQLSetDescFieldLoaded;
SQLCHAR SQLSetDescFieldBuf[132];
SQLINTEGER SQLSetDescFieldWLoaded;
SQLCHAR SQLSetDescFieldWBuf[132];
SQLINTEGER SQLSetDescRecLoaded;
SQLCHAR SQLSetDescRecBuf[132];
SQLINTEGER SQLSetEnvAttrLoaded;
SQLCHAR SQLSetEnvAttrBuf[132];
SQLINTEGER SQLSetParamLoaded;
SQLCHAR SQLSetParamBuf[132];
SQLINTEGER SQLSetStmtAttrLoaded;
SQLCHAR SQLSetStmtAttrBuf[132];
SQLINTEGER SQLSetStmtAttrWLoaded;
SQLCHAR SQLSetStmtAttrWBuf[132];
SQLINTEGER SQLSetStmtOptionLoaded;
SQLCHAR SQLSetStmtOptionBuf[132];
SQLINTEGER SQLSetStmtOptionWLoaded;
SQLCHAR SQLSetStmtOptionWBuf[132];
SQLINTEGER SQLSpecialColumnsLoaded;
SQLCHAR SQLSpecialColumnsBuf[132];
SQLINTEGER SQLSpecialColumnsWLoaded;
SQLCHAR SQLSpecialColumnsWBuf[132];
SQLINTEGER SQLStartTranLoaded;
SQLCHAR SQLStartTranBuf[132];
SQLINTEGER SQLStatisticsLoaded;
SQLCHAR SQLStatisticsBuf[132];
SQLINTEGER SQLStatisticsWLoaded;
SQLCHAR SQLStatisticsWBuf[132];
SQLINTEGER SQLTablePrivilegesLoaded;
SQLCHAR SQLTablePrivilegesBuf[132];
SQLINTEGER SQLTablePrivilegesWLoaded;
SQLCHAR SQLTablePrivilegesWBuf[132];
SQLINTEGER SQLTablesLoaded;
SQLCHAR SQLTablesBuf[132];
SQLINTEGER SQLTablesWLoaded;
SQLCHAR SQLTablesWBuf[132];
SQLINTEGER SQLTransactLoaded;
SQLCHAR SQLTransactBuf[132];

/* ILE call structures               */

typedef struct SQLAllocConnectIleCallStruct {ILEarglist_base base; SQLHENV  henv; ILEpointer phdbc; } SQLAllocConnectIleCallStruct;
typedef struct SQLAllocEnvIleCallStruct {ILEarglist_base base; ILEpointer phenv; } SQLAllocEnvIleCallStruct;
typedef struct SQLAllocHandleIleCallStruct {ILEarglist_base base; SQLSMALLINT  htype; SQLINTEGER  ihnd; ILEpointer ohnd; } SQLAllocHandleIleCallStruct;
typedef struct SQLAllocStmtIleCallStruct {ILEarglist_base base; SQLHDBC  hdbc; ILEpointer phstmt; } SQLAllocStmtIleCallStruct;
typedef struct SQLBindColIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; SQLSMALLINT  icol; SQLSMALLINT  iType; ILEpointer rgbValue; SQLINTEGER  cbValueMax; ILEpointer pcbValue; } SQLBindColIleCallStruct;
typedef struct SQLBindFileToColIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; SQLSMALLINT  icol; ILEpointer fName; ILEpointer fNameLen; ILEpointer fOptions; SQLSMALLINT  fValueMax; ILEpointer sLen; ILEpointer pcbValue; } SQLBindFileToColIleCallStruct;
typedef struct SQLBindFileToParamIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; SQLSMALLINT  ipar; SQLSMALLINT  iType; ILEpointer fName; ILEpointer fNameLen; ILEpointer fOptions; SQLSMALLINT  fValueMax; ILEpointer pcbValue; } SQLBindFileToParamIleCallStruct;
typedef struct SQLBindParamIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; SQLSMALLINT  iparm; SQLSMALLINT  iType; SQLSMALLINT  pType; SQLINTEGER  pLen; SQLSMALLINT  pScale; ILEpointer pData; ILEpointer pcbValue; } SQLBindParamIleCallStruct;
typedef struct SQLBindParameterIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; SQLSMALLINT  ipar; SQLSMALLINT  fParamType; SQLSMALLINT  fCType; SQLSMALLINT  fSQLType; SQLINTEGER  pLen; SQLSMALLINT  pScale; ILEpointer pData; SQLINTEGER  cbValueMax; ILEpointer pcbValue; } SQLBindParameterIleCallStruct;
typedef struct SQLCancelIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; } SQLCancelIleCallStruct;
typedef struct SQLCloseCursorIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; } SQLCloseCursorIleCallStruct;
typedef struct SQLColAttributeIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; SQLSMALLINT  icol; SQLSMALLINT  fDescType; ILEpointer rgbDesc; SQLSMALLINT  cbDescMax; ILEpointer pcbDesc; ILEpointer pfDesc; } SQLColAttributeIleCallStruct;
typedef struct SQLColAttributeWIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; SQLSMALLINT  icol; SQLSMALLINT  fDescType; ILEpointer rgbDesc; SQLSMALLINT  cbDescMax; ILEpointer pcbDesc; ILEpointer pfDesc; } SQLColAttributeWIleCallStruct;
typedef struct SQLColAttributesIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; SQLSMALLINT  icol; SQLSMALLINT  fDescType; ILEpointer rgbDesc; SQLINTEGER  cbDescMax; ILEpointer pcbDesc; ILEpointer pfDesc; } SQLColAttributesIleCallStruct;
typedef struct SQLColAttributesWIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; SQLSMALLINT  icol; SQLSMALLINT  fDescType; ILEpointer rgbDesc; SQLINTEGER  cbDescMax; ILEpointer pcbDesc; ILEpointer pfDesc; } SQLColAttributesWIleCallStruct;
typedef struct SQLColumnPrivilegesIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; ILEpointer szTableQualifier; SQLSMALLINT  cbTableQualifier; ILEpointer szTableOwner; SQLSMALLINT  cbTableOwner; ILEpointer szTableName; SQLSMALLINT  cbTableName; ILEpointer szColumnName; SQLSMALLINT  cbColumnName; } SQLColumnPrivilegesIleCallStruct;
typedef struct SQLColumnPrivilegesWIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; ILEpointer szTableQualifier; SQLSMALLINT  cbTableQualifier; ILEpointer szTableOwner; SQLSMALLINT  cbTableOwner; ILEpointer szTableName; SQLSMALLINT  cbTableName; ILEpointer szColumnName; SQLSMALLINT  cbColumnName; } SQLColumnPrivilegesWIleCallStruct;
typedef struct SQLColumnsIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; ILEpointer szTableQualifier; SQLSMALLINT  cbTableQualifier; ILEpointer szTableOwner; SQLSMALLINT  cbTableOwner; ILEpointer szTableName; SQLSMALLINT  cbTableName; ILEpointer szColumnName; SQLSMALLINT  cbColumnName; } SQLColumnsIleCallStruct;
typedef struct SQLColumnsWIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; ILEpointer szTableQualifier; SQLSMALLINT  cbTableQualifier; ILEpointer szTableOwner; SQLSMALLINT  cbTableOwner; ILEpointer szTableName; SQLSMALLINT  cbTableName; ILEpointer szColumnName; SQLSMALLINT  cbColumnName; } SQLColumnsWIleCallStruct;
typedef struct SQLConnectIleCallStruct {ILEarglist_base base; SQLHDBC  hdbc; ILEpointer szDSN; SQLSMALLINT  cbDSN; ILEpointer szUID; SQLSMALLINT  cbUID; ILEpointer szAuthStr; SQLSMALLINT  cbAuthStr; } SQLConnectIleCallStruct;
typedef struct SQLConnectWIleCallStruct {ILEarglist_base base; SQLHDBC  hdbc; ILEpointer szDSN; SQLSMALLINT  cbDSN; ILEpointer szUID; SQLSMALLINT  cbUID; ILEpointer szAuthStr; SQLSMALLINT  cbAuthStr; } SQLConnectWIleCallStruct;
typedef struct SQLCopyDescIleCallStruct {ILEarglist_base base; SQLHDESC  sDesc; SQLHDESC  tDesc; } SQLCopyDescIleCallStruct;
typedef struct SQLDataSourcesIleCallStruct {ILEarglist_base base; SQLHENV  henv; SQLSMALLINT  fDirection; ILEpointer szDSN; SQLSMALLINT  cbDSNMax; ILEpointer pcbDSN; ILEpointer szDescription; SQLSMALLINT  cbDescriptionMax; ILEpointer pcbDescription; } SQLDataSourcesIleCallStruct;
typedef struct SQLDataSourcesWIleCallStruct {ILEarglist_base base; SQLHENV  henv; SQLSMALLINT  fDirection; ILEpointer szDSN; SQLSMALLINT  cbDSNMax; ILEpointer pcbDSN; ILEpointer szDescription; SQLSMALLINT  cbDescriptionMax; ILEpointer pcbDescription; } SQLDataSourcesWIleCallStruct;
typedef struct SQLDescribeColIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; SQLSMALLINT  icol; ILEpointer szColName; SQLSMALLINT  cbColNameMax; ILEpointer pcbColName; ILEpointer pfSqlType; ILEpointer pcbColDef; ILEpointer pibScale; ILEpointer pfNullable; } SQLDescribeColIleCallStruct;
typedef struct SQLDescribeColWIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; SQLSMALLINT  icol; ILEpointer szColName; SQLSMALLINT  cbColNameMax; ILEpointer pcbColName; ILEpointer pfSqlType; ILEpointer pcbColDef; ILEpointer pibScale; ILEpointer pfNullable; } SQLDescribeColWIleCallStruct;
typedef struct SQLDescribeParamIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; SQLSMALLINT  ipar; ILEpointer pfSqlType; ILEpointer pcbColDef; ILEpointer pibScale; ILEpointer pfNullable; } SQLDescribeParamIleCallStruct;
typedef struct SQLDisconnectIleCallStruct {ILEarglist_base base; SQLHDBC  hdbc; } SQLDisconnectIleCallStruct;
typedef struct SQLDriverConnectIleCallStruct {ILEarglist_base base; SQLHDBC  hdbc; ILEpointer hwnd; ILEpointer szConnStrIn; SQLSMALLINT  cbConnStrin; ILEpointer szConnStrOut; SQLSMALLINT  cbConnStrOutMax; ILEpointer pcbConnStrOut; SQLSMALLINT  fDriverCompletion; } SQLDriverConnectIleCallStruct;
typedef struct SQLDriverConnectWIleCallStruct {ILEarglist_base base; SQLHDBC  hdbc; ILEpointer hwnd; ILEpointer szConnStrIn; SQLSMALLINT  cbConnStrin; ILEpointer szConnStrOut; SQLSMALLINT  cbConnStrOutMax; ILEpointer pcbConnStrOut; SQLSMALLINT  fDriverCompletion; } SQLDriverConnectWIleCallStruct;
typedef struct SQLEndTranIleCallStruct {ILEarglist_base base; SQLSMALLINT  htype; SQLHENV  henv; SQLSMALLINT  ctype; } SQLEndTranIleCallStruct;
typedef struct SQLErrorIleCallStruct {ILEarglist_base base; SQLHENV  henv; SQLHDBC  hdbc; SQLHSTMT  hstmt; ILEpointer szSqlState; ILEpointer pfNativeError; ILEpointer szErrorMsg; SQLSMALLINT  cbErrorMsgMax; ILEpointer pcbErrorMsg; } SQLErrorIleCallStruct;
typedef struct SQLErrorWIleCallStruct {ILEarglist_base base; SQLHENV  henv; SQLHDBC  hdbc; SQLHSTMT  hstmt; ILEpointer szSqlState; ILEpointer pfNativeError; ILEpointer szErrorMsg; SQLSMALLINT  cbErrorMsgMax; ILEpointer pcbErrorMsg; } SQLErrorWIleCallStruct;
typedef struct SQLExecDirectIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; ILEpointer szSqlStr; SQLINTEGER  cbSqlStr; } SQLExecDirectIleCallStruct;
typedef struct SQLExecDirectWIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; ILEpointer szSqlStr; SQLINTEGER  cbSqlStr; } SQLExecDirectWIleCallStruct;
typedef struct SQLExecuteIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; } SQLExecuteIleCallStruct;
typedef struct SQLExtendedFetchIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; SQLSMALLINT  fOrient; SQLINTEGER  fOffset; ILEpointer pcrow; ILEpointer rgfRowStatus; } SQLExtendedFetchIleCallStruct;
typedef struct SQLFetchIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; } SQLFetchIleCallStruct;
typedef struct SQLFetchScrollIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; SQLSMALLINT  fOrient; SQLINTEGER  fOffset; } SQLFetchScrollIleCallStruct;
typedef struct SQLForeignKeysIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; ILEpointer szPkTableQualifier; SQLSMALLINT  cbPkTableQualifier; ILEpointer szPkTableOwner; SQLSMALLINT  cbPkTableOwner; ILEpointer szPkTableName; SQLSMALLINT  cbPkTableName; ILEpointer szFkTableQualifier; SQLSMALLINT  cbFkTableQualifier; ILEpointer szFkTableOwner; SQLSMALLINT  cbFkTableOwner; ILEpointer szFkTableName; SQLSMALLINT  cbFkTableName; } SQLForeignKeysIleCallStruct;
typedef struct SQLForeignKeysWIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; ILEpointer szPkTableQualifier; SQLSMALLINT  cbPkTableQualifier; ILEpointer szPkTableOwner; SQLSMALLINT  cbPkTableOwner; ILEpointer szPkTableName; SQLSMALLINT  cbPkTableName; ILEpointer szFkTableQualifier; SQLSMALLINT  cbFkTableQualifier; ILEpointer szFkTableOwner; SQLSMALLINT  cbFkTableOwner; ILEpointer szFkTableName; SQLSMALLINT  cbFkTableName; } SQLForeignKeysWIleCallStruct;
typedef struct SQLFreeConnectIleCallStruct {ILEarglist_base base; SQLHDBC  hdbc; } SQLFreeConnectIleCallStruct;
typedef struct SQLFreeEnvIleCallStruct {ILEarglist_base base; SQLHENV  henv; } SQLFreeEnvIleCallStruct;
typedef struct SQLFreeStmtIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; SQLSMALLINT  fOption; } SQLFreeStmtIleCallStruct;
typedef struct SQLFreeHandleIleCallStruct {ILEarglist_base base; SQLSMALLINT  htype; SQLINTEGER  hndl; } SQLFreeHandleIleCallStruct;
typedef struct SQLGetColIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; SQLSMALLINT  icol; SQLSMALLINT  itype; ILEpointer tval; SQLINTEGER  blen; ILEpointer olen; } SQLGetColIleCallStruct;
typedef struct SQLGetColWIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; SQLSMALLINT  icol; SQLSMALLINT  itype; ILEpointer tval; SQLINTEGER  blen; ILEpointer olen; } SQLGetColWIleCallStruct;
typedef struct SQLGetConnectAttrIleCallStruct {ILEarglist_base base; SQLHDBC  hdbc; SQLINTEGER  attr; ILEpointer oval; SQLINTEGER  ilen; ILEpointer olen; } SQLGetConnectAttrIleCallStruct;
typedef struct SQLGetConnectAttrWIleCallStruct {ILEarglist_base base; SQLHDBC  hdbc; SQLINTEGER  attr; ILEpointer oval; SQLINTEGER  ilen; ILEpointer olen; } SQLGetConnectAttrWIleCallStruct;
typedef struct SQLGetConnectOptionIleCallStruct {ILEarglist_base base; SQLHDBC  hdbc; SQLSMALLINT  iopt; ILEpointer oval; } SQLGetConnectOptionIleCallStruct;
typedef struct SQLGetConnectOptionWIleCallStruct {ILEarglist_base base; SQLHDBC  hdbc; SQLSMALLINT  iopt; ILEpointer oval; } SQLGetConnectOptionWIleCallStruct;
typedef struct SQLGetCursorNameIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; ILEpointer szCursor; SQLSMALLINT  cbCursorMax; ILEpointer pcbCursor; } SQLGetCursorNameIleCallStruct;
typedef struct SQLGetCursorNameWIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; ILEpointer szCursor; SQLSMALLINT  cbCursorMax; ILEpointer pcbCursor; } SQLGetCursorNameWIleCallStruct;
typedef struct SQLGetDataIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; SQLSMALLINT  icol; SQLSMALLINT  fCType; ILEpointer rgbValue; SQLINTEGER  cbValueMax; ILEpointer pcbValue; } SQLGetDataIleCallStruct;
typedef struct SQLGetDescFieldIleCallStruct {ILEarglist_base base; SQLHDESC  hdesc; SQLSMALLINT  rcdNum; SQLSMALLINT  fieldID; ILEpointer fValue; SQLINTEGER  fLength; ILEpointer stLength; } SQLGetDescFieldIleCallStruct;
typedef struct SQLGetDescFieldWIleCallStruct {ILEarglist_base base; SQLHDESC  hdesc; SQLSMALLINT  rcdNum; SQLSMALLINT  fieldID; ILEpointer fValue; SQLINTEGER  fLength; ILEpointer stLength; } SQLGetDescFieldWIleCallStruct;
typedef struct SQLGetDescRecIleCallStruct {ILEarglist_base base; SQLHDESC  hdesc; SQLSMALLINT  rcdNum; ILEpointer fname; SQLSMALLINT  bufLen; ILEpointer sLength; ILEpointer sType; ILEpointer sbType; ILEpointer fLength; ILEpointer fprec; ILEpointer fscale; ILEpointer fnull; } SQLGetDescRecIleCallStruct;
typedef struct SQLGetDescRecWIleCallStruct {ILEarglist_base base; SQLHDESC  hdesc; SQLSMALLINT  rcdNum; ILEpointer fname; SQLSMALLINT  bufLen; ILEpointer sLength; ILEpointer sType; ILEpointer sbType; ILEpointer fLength; ILEpointer fprec; ILEpointer fscale; ILEpointer fnull; } SQLGetDescRecWIleCallStruct;
typedef struct SQLGetDiagFieldIleCallStruct {ILEarglist_base base; SQLSMALLINT  hType; SQLINTEGER  hndl; SQLSMALLINT  rcdNum; SQLSMALLINT  diagID; ILEpointer dValue; SQLSMALLINT  bLength; ILEpointer sLength; } SQLGetDiagFieldIleCallStruct;
typedef struct SQLGetDiagFieldWIleCallStruct {ILEarglist_base base; SQLSMALLINT  hType; SQLINTEGER  hndl; SQLSMALLINT  rcdNum; SQLSMALLINT  diagID; ILEpointer dValue; SQLSMALLINT  bLength; ILEpointer sLength; } SQLGetDiagFieldWIleCallStruct;
typedef struct SQLGetDiagRecIleCallStruct {ILEarglist_base base; SQLSMALLINT  hType; SQLINTEGER  hndl; SQLSMALLINT  rcdNum; ILEpointer SQLstate; ILEpointer SQLcode; ILEpointer msgText; SQLSMALLINT  bLength; ILEpointer SLength; } SQLGetDiagRecIleCallStruct;
typedef struct SQLGetDiagRecWIleCallStruct {ILEarglist_base base; SQLSMALLINT  hType; SQLINTEGER  hndl; SQLSMALLINT  rcdNum; ILEpointer SQLstate; ILEpointer SQLcode; ILEpointer msgText; SQLSMALLINT  bLength; ILEpointer SLength; } SQLGetDiagRecWIleCallStruct;
typedef struct SQLGetEnvAttrIleCallStruct {ILEarglist_base base; SQLHENV  hEnv; SQLINTEGER  fAttribute; ILEpointer pParam; SQLINTEGER  cbParamMax; ILEpointer pcbParam; } SQLGetEnvAttrIleCallStruct;
typedef struct SQLGetFunctionsIleCallStruct {ILEarglist_base base; SQLHDBC  hdbc; SQLSMALLINT  fFunction; ILEpointer pfExists; } SQLGetFunctionsIleCallStruct;
typedef struct SQLGetInfoIleCallStruct {ILEarglist_base base; SQLHDBC  hdbc; SQLSMALLINT  fInfoType; ILEpointer rgbInfoValue; SQLSMALLINT  cbInfoValueMax; ILEpointer pcbInfoValue; } SQLGetInfoIleCallStruct;
typedef struct SQLGetInfoWIleCallStruct {ILEarglist_base base; SQLHDBC  hdbc; SQLSMALLINT  fInfoType; ILEpointer rgbInfoValue; SQLSMALLINT  cbInfoValueMax; ILEpointer pcbInfoValue; } SQLGetInfoWIleCallStruct;
typedef struct SQLGetLengthIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; SQLSMALLINT  locType; SQLINTEGER  locator; ILEpointer sLength; ILEpointer ind; } SQLGetLengthIleCallStruct;
typedef struct SQLGetPositionIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; SQLSMALLINT  locType; SQLINTEGER  srceLocator; SQLINTEGER  srchLocator; ILEpointer srchLiteral; SQLINTEGER  srchLiteralLen; SQLINTEGER  fPosition; ILEpointer located; ILEpointer ind; } SQLGetPositionIleCallStruct;
typedef struct SQLGetPositionWIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; SQLSMALLINT  locType; SQLINTEGER  srceLocator; SQLINTEGER  srchLocator; ILEpointer srchLiteral; SQLINTEGER  srchLiteralLen; SQLINTEGER  fPosition; ILEpointer located; ILEpointer ind; } SQLGetPositionWIleCallStruct;
typedef struct SQLGetStmtAttrIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; SQLINTEGER  fAttr; ILEpointer pvParam; SQLINTEGER  bLength; ILEpointer SLength; } SQLGetStmtAttrIleCallStruct;
typedef struct SQLGetStmtAttrWIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; SQLINTEGER  fAttr; ILEpointer pvParam; SQLINTEGER  bLength; ILEpointer SLength; } SQLGetStmtAttrWIleCallStruct;
typedef struct SQLGetStmtOptionIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; SQLSMALLINT  fOption; ILEpointer pvParam; } SQLGetStmtOptionIleCallStruct;
typedef struct SQLGetStmtOptionWIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; SQLSMALLINT  fOption; ILEpointer pvParam; } SQLGetStmtOptionWIleCallStruct;
typedef struct SQLGetSubStringIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; SQLSMALLINT  locType; SQLINTEGER  srceLocator; SQLINTEGER  fPosition; SQLINTEGER  length; SQLSMALLINT  tType; ILEpointer rgbValue; SQLINTEGER  cbValueMax; ILEpointer StringLength; ILEpointer ind; } SQLGetSubStringIleCallStruct;
typedef struct SQLGetSubStringWIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; SQLSMALLINT  locType; SQLINTEGER  srceLocator; SQLINTEGER  fPosition; SQLINTEGER  length; SQLSMALLINT  tType; ILEpointer rgbValue; SQLINTEGER  cbValueMax; ILEpointer StringLength; ILEpointer ind; } SQLGetSubStringWIleCallStruct;
typedef struct SQLGetTypeInfoIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; SQLSMALLINT  fSqlType; } SQLGetTypeInfoIleCallStruct;
typedef struct SQLGetTypeInfoWIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; SQLSMALLINT  fSqlType; } SQLGetTypeInfoWIleCallStruct;
typedef struct SQLLanguagesIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; } SQLLanguagesIleCallStruct;
typedef struct SQLMoreResultsIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; } SQLMoreResultsIleCallStruct;
typedef struct SQLNativeSqlIleCallStruct {ILEarglist_base base; SQLHDBC  hdbc; ILEpointer szSqlStrIn; SQLINTEGER  cbSqlStrIn; ILEpointer szSqlStr; SQLINTEGER  cbSqlStrMax; ILEpointer pcbSqlStr; } SQLNativeSqlIleCallStruct;
typedef struct SQLNativeSqlWIleCallStruct {ILEarglist_base base; SQLHDBC  hdbc; ILEpointer szSqlStrIn; SQLINTEGER  cbSqlStrIn; ILEpointer szSqlStr; SQLINTEGER  cbSqlStrMax; ILEpointer pcbSqlStr; } SQLNativeSqlWIleCallStruct;
typedef struct SQLNextResultIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; SQLHSTMT  hstmt2; } SQLNextResultIleCallStruct;
typedef struct SQLNumParamsIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; ILEpointer pcpar; } SQLNumParamsIleCallStruct;
typedef struct SQLNumResultColsIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; ILEpointer pccol; } SQLNumResultColsIleCallStruct;
typedef struct SQLParamDataIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; ILEpointer Value; } SQLParamDataIleCallStruct;
typedef struct SQLParamOptionsIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; SQLINTEGER  crow; ILEpointer pirow; } SQLParamOptionsIleCallStruct;
typedef struct SQLPrepareIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; ILEpointer szSqlStr; SQLINTEGER  cbSqlStr; } SQLPrepareIleCallStruct;
typedef struct SQLPrepareWIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; ILEpointer szSqlStr; SQLINTEGER  cbSqlStr; } SQLPrepareWIleCallStruct;
typedef struct SQLPrimaryKeysIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; ILEpointer szTableQualifier; SQLSMALLINT  cbTableQualifier; ILEpointer szTableOwner; SQLSMALLINT  cbTableOwner; ILEpointer szTableName; SQLSMALLINT  cbTableName; } SQLPrimaryKeysIleCallStruct;
typedef struct SQLPrimaryKeysWIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; ILEpointer szTableQualifier; SQLSMALLINT  cbTableQualifier; ILEpointer szTableOwner; SQLSMALLINT  cbTableOwner; ILEpointer szTableName; SQLSMALLINT  cbTableName; } SQLPrimaryKeysWIleCallStruct;
typedef struct SQLProcedureColumnsIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; ILEpointer szProcQualifier; SQLSMALLINT  cbProcQualifier; ILEpointer szProcOwner; SQLSMALLINT  cbProcOwner; ILEpointer szProcName; SQLSMALLINT  cbProcName; ILEpointer szColumnName; SQLSMALLINT  cbColumnName; } SQLProcedureColumnsIleCallStruct;
typedef struct SQLProcedureColumnsWIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; ILEpointer szProcQualifier; SQLSMALLINT  cbProcQualifier; ILEpointer szProcOwner; SQLSMALLINT  cbProcOwner; ILEpointer szProcName; SQLSMALLINT  cbProcName; ILEpointer szColumnName; SQLSMALLINT  cbColumnName; } SQLProcedureColumnsWIleCallStruct;
typedef struct SQLProceduresIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; ILEpointer szProcQualifier; SQLSMALLINT  cbProcQualifier; ILEpointer szProcOwner; SQLSMALLINT  cbProcOwner; ILEpointer szProcName; SQLSMALLINT  cbProcName; } SQLProceduresIleCallStruct;
typedef struct SQLProceduresWIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; ILEpointer szProcQualifier; SQLSMALLINT  cbProcQualifier; ILEpointer szProcOwner; SQLSMALLINT  cbProcOwner; ILEpointer szProcName; SQLSMALLINT  cbProcName; } SQLProceduresWIleCallStruct;
typedef struct SQLPutDataIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; ILEpointer Data; SQLINTEGER  SLen; } SQLPutDataIleCallStruct;
typedef struct SQLReleaseEnvIleCallStruct {ILEarglist_base base; SQLHENV  henv; } SQLReleaseEnvIleCallStruct;
typedef struct SQLRowCountIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; ILEpointer pcrow; } SQLRowCountIleCallStruct;
typedef struct SQLSetConnectAttrIleCallStruct {ILEarglist_base base; SQLHDBC  hdbc; SQLINTEGER  attrib; ILEpointer vParam; SQLINTEGER  inlen; } SQLSetConnectAttrIleCallStruct;
typedef struct SQLSetConnectAttrWIleCallStruct {ILEarglist_base base; SQLHDBC  hdbc; SQLINTEGER  attrib; ILEpointer vParam; SQLINTEGER  inlen; } SQLSetConnectAttrWIleCallStruct;
typedef struct SQLSetConnectOptionIleCallStruct {ILEarglist_base base; SQLHDBC  hdbc; SQLSMALLINT  fOption; ILEpointer vParam; } SQLSetConnectOptionIleCallStruct;
typedef struct SQLSetConnectOptionWIleCallStruct {ILEarglist_base base; SQLHDBC  hdbc; SQLSMALLINT  fOption; ILEpointer vParam; } SQLSetConnectOptionWIleCallStruct;
typedef struct SQLSetCursorNameIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; ILEpointer szCursor; SQLSMALLINT  cbCursor; } SQLSetCursorNameIleCallStruct;
typedef struct SQLSetCursorNameWIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; ILEpointer szCursor; SQLSMALLINT  cbCursor; } SQLSetCursorNameWIleCallStruct;
typedef struct SQLSetDescFieldIleCallStruct {ILEarglist_base base; SQLHDESC  hdesc; SQLSMALLINT  rcdNum; SQLSMALLINT  fID; ILEpointer Value; SQLINTEGER  buffLen; } SQLSetDescFieldIleCallStruct;
typedef struct SQLSetDescFieldWIleCallStruct {ILEarglist_base base; SQLHDESC  hdesc; SQLSMALLINT  rcdNum; SQLSMALLINT  fID; ILEpointer Value; SQLINTEGER  buffLen; } SQLSetDescFieldWIleCallStruct;
typedef struct SQLSetDescRecIleCallStruct {ILEarglist_base base; SQLHDESC  hdesc; SQLSMALLINT  rcdNum; SQLSMALLINT  Type; SQLSMALLINT  subType; SQLINTEGER  fLength; SQLSMALLINT  fPrec; SQLSMALLINT  fScale; ILEpointer Value; ILEpointer sLength; ILEpointer indic; } SQLSetDescRecIleCallStruct;
typedef struct SQLSetEnvAttrIleCallStruct {ILEarglist_base base; SQLHENV  hEnv; SQLINTEGER  fAttribute; ILEpointer pParam; SQLINTEGER  cbParam; } SQLSetEnvAttrIleCallStruct;
typedef struct SQLSetParamIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; SQLSMALLINT  ipar; SQLSMALLINT  fCType; SQLSMALLINT  fSqlType; SQLINTEGER  cbColDef; SQLSMALLINT  ibScale; ILEpointer rgbValue; ILEpointer pcbValue; } SQLSetParamIleCallStruct;
typedef struct SQLSetStmtAttrIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; SQLINTEGER  fAttr; ILEpointer pParam; SQLINTEGER  vParam; } SQLSetStmtAttrIleCallStruct;
typedef struct SQLSetStmtAttrWIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; SQLINTEGER  fAttr; ILEpointer pParam; SQLINTEGER  vParam; } SQLSetStmtAttrWIleCallStruct;
typedef struct SQLSetStmtOptionIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; SQLSMALLINT  fOption; ILEpointer vParam; } SQLSetStmtOptionIleCallStruct;
typedef struct SQLSetStmtOptionWIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; SQLSMALLINT  fOption; ILEpointer vParam; } SQLSetStmtOptionWIleCallStruct;
typedef struct SQLSpecialColumnsIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; SQLSMALLINT  fColType; ILEpointer szTableQual; SQLSMALLINT  cbTableQual; ILEpointer szTableOwner; SQLSMALLINT  cbTableOwner; ILEpointer szTableName; SQLSMALLINT  cbTableName; SQLSMALLINT  fScope; SQLSMALLINT  fNullable; } SQLSpecialColumnsIleCallStruct;
typedef struct SQLSpecialColumnsWIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; SQLSMALLINT  fColType; ILEpointer szTableQual; SQLSMALLINT  cbTableQual; ILEpointer szTableOwner; SQLSMALLINT  cbTableOwner; ILEpointer szTableName; SQLSMALLINT  cbTableName; SQLSMALLINT  fScope; SQLSMALLINT  fNullable; } SQLSpecialColumnsWIleCallStruct;
typedef struct SQLStartTranIleCallStruct {ILEarglist_base base; SQLSMALLINT  htype; SQLHENV  henv; SQLINTEGER  mode; SQLINTEGER  clevel; } SQLStartTranIleCallStruct;
typedef struct SQLStatisticsIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; ILEpointer szTableQualifier; SQLSMALLINT  cbTableQualifier; ILEpointer szTableOwner; SQLSMALLINT  cbTableOwner; ILEpointer szTableName; SQLSMALLINT  cbTableName; SQLSMALLINT  fUnique; SQLSMALLINT  fres; } SQLStatisticsIleCallStruct;
typedef struct SQLStatisticsWIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; ILEpointer szTableQualifier; SQLSMALLINT  cbTableQualifier; ILEpointer szTableOwner; SQLSMALLINT  cbTableOwner; ILEpointer szTableName; SQLSMALLINT  cbTableName; SQLSMALLINT  fUnique; SQLSMALLINT  fres; } SQLStatisticsWIleCallStruct;
typedef struct SQLTablePrivilegesIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; ILEpointer szTableQualifier; SQLSMALLINT  cbTableQualifier; ILEpointer szTableOwner; SQLSMALLINT  cbTableOwner; ILEpointer szTableName; SQLSMALLINT  cbTableName; } SQLTablePrivilegesIleCallStruct;
typedef struct SQLTablePrivilegesWIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; ILEpointer szTableQualifier; SQLSMALLINT  cbTableQualifier; ILEpointer szTableOwner; SQLSMALLINT  cbTableOwner; ILEpointer szTableName; SQLSMALLINT  cbTableName; } SQLTablePrivilegesWIleCallStruct;
typedef struct SQLTablesIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; ILEpointer szTableQualifier; SQLSMALLINT  cbTableQualifier; ILEpointer szTableOwner; SQLSMALLINT  cbTableOwner; ILEpointer szTableName; SQLSMALLINT  cbTableName; ILEpointer szTableType; SQLSMALLINT  cbTableType; } SQLTablesIleCallStruct;
typedef struct SQLTablesWIleCallStruct {ILEarglist_base base; SQLHSTMT  hstmt; ILEpointer szTableQualifier; SQLSMALLINT  cbTableQualifier; ILEpointer szTableOwner; SQLSMALLINT  cbTableOwner; ILEpointer szTableName; SQLSMALLINT  cbTableName; ILEpointer szTableType; SQLSMALLINT  cbTableType; } SQLTablesWIleCallStruct;
typedef struct SQLTransactIleCallStruct {ILEarglist_base base; SQLHENV  henv; SQLHDBC  hdbc; SQLSMALLINT  fType; } SQLTransactIleCallStruct;


SQLRETURN ILE_SQLAllocConnect( SQLHENV  henv, SQLHDBC * phdbc )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLAllocConnectIleCallStruct * arglist = (SQLAllocConnectIleCallStruct *) NULL;
  char buffer[ sizeof(SQLAllocConnectIleCallStruct) + 16 ];
  static arg_type_t SQLAllocConnectIleSigStruct[] = { ARG_INT32, ARG_MEMPTR, ARG_END };
  arglist = (SQLAllocConnectIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLAllocConnectBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLAllocConnectLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLAllocConnect");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLAllocConnectLoaded = 1;
  }
  arglist->henv = (SQLHENV) henv;
  arglist->phdbc.s.addr = (ulong) phdbc;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLAllocConnectIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLAllocEnv( SQLHENV * phenv )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLAllocEnvIleCallStruct * arglist = (SQLAllocEnvIleCallStruct *) NULL;
  char buffer[ sizeof(SQLAllocEnvIleCallStruct) + 16 ];
  static arg_type_t SQLAllocEnvIleSigStruct[] = { ARG_MEMPTR, ARG_END };
  arglist = (SQLAllocEnvIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLAllocEnvBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLAllocEnvLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLAllocEnv");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLAllocEnvLoaded = 1;
  }
  arglist->phenv.s.addr = (ulong) phenv;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLAllocEnvIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLAllocHandle( SQLSMALLINT  htype, SQLINTEGER  ihnd, SQLINTEGER * ohnd )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLAllocHandleIleCallStruct * arglist = (SQLAllocHandleIleCallStruct *) NULL;
  char buffer[ sizeof(SQLAllocHandleIleCallStruct) + 16 ];
  static arg_type_t SQLAllocHandleIleSigStruct[] = { ARG_INT16, ARG_INT32, ARG_MEMPTR, ARG_END };
  arglist = (SQLAllocHandleIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLAllocHandleBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLAllocHandleLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLAllocHandle");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLAllocHandleLoaded = 1;
  }
  arglist->htype = (SQLSMALLINT) htype;
  arglist->ihnd = (SQLINTEGER) ihnd;
  arglist->ohnd.s.addr = (ulong) ohnd;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLAllocHandleIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLAllocStmt( SQLHDBC  hdbc, SQLHSTMT * phstmt )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLAllocStmtIleCallStruct * arglist = (SQLAllocStmtIleCallStruct *) NULL;
  char buffer[ sizeof(SQLAllocStmtIleCallStruct) + 16 ];
  static arg_type_t SQLAllocStmtIleSigStruct[] = { ARG_INT32, ARG_MEMPTR, ARG_END };
  arglist = (SQLAllocStmtIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLAllocStmtBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLAllocStmtLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLAllocStmt");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLAllocStmtLoaded = 1;
  }
  arglist->hdbc = (SQLHDBC) hdbc;
  arglist->phstmt.s.addr = (ulong) phstmt;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLAllocStmtIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLBindCol( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  iType, SQLPOINTER  rgbValue, SQLINTEGER  cbValueMax, SQLINTEGER * pcbValue )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLBindColIleCallStruct * arglist = (SQLBindColIleCallStruct *) NULL;
  char buffer[ sizeof(SQLBindColIleCallStruct) + 16 ];
  static arg_type_t SQLBindColIleSigStruct[] = { ARG_INT32, ARG_INT16, ARG_INT16, ARG_MEMPTR, ARG_INT32, ARG_MEMPTR, ARG_END };
  arglist = (SQLBindColIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLBindColBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLBindColLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLBindCol");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLBindColLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->icol = (SQLSMALLINT) icol;
  arglist->iType = (SQLSMALLINT) iType;
  arglist->rgbValue.s.addr = (ulong) rgbValue;
  arglist->cbValueMax = (SQLINTEGER) cbValueMax;
  arglist->pcbValue.s.addr = (ulong) pcbValue;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLBindColIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLBindFileToCol( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLCHAR * fName, SQLSMALLINT * fNameLen, SQLINTEGER * fOptions, SQLSMALLINT  fValueMax, SQLINTEGER * sLen, SQLINTEGER * pcbValue )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLBindFileToColIleCallStruct * arglist = (SQLBindFileToColIleCallStruct *) NULL;
  char buffer[ sizeof(SQLBindFileToColIleCallStruct) + 16 ];
  static arg_type_t SQLBindFileToColIleSigStruct[] = { ARG_INT32, ARG_INT16, ARG_MEMPTR, ARG_MEMPTR, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_MEMPTR, ARG_END };
  arglist = (SQLBindFileToColIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLBindFileToColBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLBindFileToColLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLBindFileToCol");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLBindFileToColLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->icol = (SQLSMALLINT) icol;
  arglist->fName.s.addr = (ulong) fName;
  arglist->fNameLen.s.addr = (ulong) fNameLen;
  arglist->fOptions.s.addr = (ulong) fOptions;
  arglist->fValueMax = (SQLSMALLINT) fValueMax;
  arglist->sLen.s.addr = (ulong) sLen;
  arglist->pcbValue.s.addr = (ulong) pcbValue;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLBindFileToColIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLBindFileToParam( SQLHSTMT  hstmt, SQLSMALLINT  ipar, SQLSMALLINT  iType, SQLCHAR * fName, SQLSMALLINT * fNameLen, SQLINTEGER * fOptions, SQLSMALLINT  fValueMax, SQLINTEGER * pcbValue )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLBindFileToParamIleCallStruct * arglist = (SQLBindFileToParamIleCallStruct *) NULL;
  char buffer[ sizeof(SQLBindFileToParamIleCallStruct) + 16 ];
  static arg_type_t SQLBindFileToParamIleSigStruct[] = { ARG_INT32, ARG_INT16, ARG_INT16, ARG_MEMPTR, ARG_MEMPTR, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_END };
  arglist = (SQLBindFileToParamIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLBindFileToParamBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLBindFileToParamLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLBindFileToParam");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLBindFileToParamLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->ipar = (SQLSMALLINT) ipar;
  arglist->iType = (SQLSMALLINT) iType;
  arglist->fName.s.addr = (ulong) fName;
  arglist->fNameLen.s.addr = (ulong) fNameLen;
  arglist->fOptions.s.addr = (ulong) fOptions;
  arglist->fValueMax = (SQLSMALLINT) fValueMax;
  arglist->pcbValue.s.addr = (ulong) pcbValue;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLBindFileToParamIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLBindParam( SQLHSTMT  hstmt, SQLSMALLINT  iparm, SQLSMALLINT  iType, SQLSMALLINT  pType, SQLINTEGER  pLen, SQLSMALLINT  pScale, SQLPOINTER  pData, SQLINTEGER * pcbValue )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLBindParamIleCallStruct * arglist = (SQLBindParamIleCallStruct *) NULL;
  char buffer[ sizeof(SQLBindParamIleCallStruct) + 16 ];
  static arg_type_t SQLBindParamIleSigStruct[] = { ARG_INT32, ARG_INT16, ARG_INT16, ARG_INT16, ARG_INT32, ARG_INT16, ARG_MEMPTR, ARG_MEMPTR, ARG_END };
  arglist = (SQLBindParamIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLBindParamBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLBindParamLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLBindParam");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLBindParamLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->iparm = (SQLSMALLINT) iparm;
  arglist->iType = (SQLSMALLINT) iType;
  arglist->pType = (SQLSMALLINT) pType;
  arglist->pLen = (SQLINTEGER) pLen;
  arglist->pScale = (SQLSMALLINT) pScale;
  arglist->pData.s.addr = (ulong) pData;
  arglist->pcbValue.s.addr = (ulong) pcbValue;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLBindParamIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLBindParameter( SQLHSTMT  hstmt, SQLSMALLINT  ipar, SQLSMALLINT  fParamType, SQLSMALLINT  fCType, SQLSMALLINT  fSQLType, SQLINTEGER  pLen, SQLSMALLINT  pScale, SQLPOINTER  pData, SQLINTEGER  cbValueMax, SQLINTEGER * pcbValue )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLBindParameterIleCallStruct * arglist = (SQLBindParameterIleCallStruct *) NULL;
  char buffer[ sizeof(SQLBindParameterIleCallStruct) + 16 ];
  static arg_type_t SQLBindParameterIleSigStruct[] = { ARG_INT32, ARG_INT16, ARG_INT16, ARG_INT16, ARG_INT16, ARG_INT32, ARG_INT16, ARG_MEMPTR, ARG_INT32, ARG_MEMPTR, ARG_END };
  arglist = (SQLBindParameterIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLBindParameterBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLBindParameterLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLBindParameter");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLBindParameterLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->ipar = (SQLSMALLINT) ipar;
  arglist->fParamType = (SQLSMALLINT) fParamType;
  arglist->fCType = (SQLSMALLINT) fCType;
  arglist->fSQLType = (SQLSMALLINT) fSQLType;
  arglist->pLen = (SQLINTEGER) pLen;
  arglist->pScale = (SQLSMALLINT) pScale;
  arglist->pData.s.addr = (ulong) pData;
  arglist->cbValueMax = (SQLINTEGER) cbValueMax;
  arglist->pcbValue.s.addr = (ulong) pcbValue;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLBindParameterIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLCancel( SQLHSTMT  hstmt )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLCancelIleCallStruct * arglist = (SQLCancelIleCallStruct *) NULL;
  char buffer[ sizeof(SQLCancelIleCallStruct) + 16 ];
  static arg_type_t SQLCancelIleSigStruct[] = { ARG_INT32, ARG_END };
  arglist = (SQLCancelIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLCancelBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLCancelLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLCancel");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLCancelLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLCancelIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLCloseCursor( SQLHSTMT  hstmt )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLCloseCursorIleCallStruct * arglist = (SQLCloseCursorIleCallStruct *) NULL;
  char buffer[ sizeof(SQLCloseCursorIleCallStruct) + 16 ];
  static arg_type_t SQLCloseCursorIleSigStruct[] = { ARG_INT32, ARG_END };
  arglist = (SQLCloseCursorIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLCloseCursorBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLCloseCursorLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLCloseCursor");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLCloseCursorLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLCloseCursorIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLColAttribute( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fDescType, SQLPOINTER  rgbDesc, SQLSMALLINT  cbDescMax, SQLSMALLINT * pcbDesc, SQLPOINTER  pfDesc )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLColAttributeIleCallStruct * arglist = (SQLColAttributeIleCallStruct *) NULL;
  char buffer[ sizeof(SQLColAttributeIleCallStruct) + 16 ];
  static arg_type_t SQLColAttributeIleSigStruct[] = { ARG_INT32, ARG_INT16, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_MEMPTR, ARG_END };
  arglist = (SQLColAttributeIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLColAttributeBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLColAttributeLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLColAttribute");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLColAttributeLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->icol = (SQLSMALLINT) icol;
  arglist->fDescType = (SQLSMALLINT) fDescType;
  arglist->rgbDesc.s.addr = (ulong) rgbDesc;
  arglist->cbDescMax = (SQLSMALLINT) cbDescMax;
  arglist->pcbDesc.s.addr = (ulong) pcbDesc;
  arglist->pfDesc.s.addr = (ulong) pfDesc;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLColAttributeIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLColAttributeW( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fDescType, SQLPOINTER  rgbDesc, SQLSMALLINT  cbDescMax, SQLSMALLINT * pcbDesc, SQLPOINTER  pfDesc )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLColAttributeWIleCallStruct * arglist = (SQLColAttributeWIleCallStruct *) NULL;
  char buffer[ sizeof(SQLColAttributeWIleCallStruct) + 16 ];
  static arg_type_t SQLColAttributeWIleSigStruct[] = { ARG_INT32, ARG_INT16, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_MEMPTR, ARG_END };
  arglist = (SQLColAttributeWIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLColAttributeWBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLColAttributeWLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLColAttributeW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLColAttributeWLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->icol = (SQLSMALLINT) icol;
  arglist->fDescType = (SQLSMALLINT) fDescType;
  arglist->rgbDesc.s.addr = (ulong) rgbDesc;
  arglist->cbDescMax = (SQLSMALLINT) cbDescMax;
  arglist->pcbDesc.s.addr = (ulong) pcbDesc;
  arglist->pfDesc.s.addr = (ulong) pfDesc;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLColAttributeWIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLColAttributes( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fDescType, SQLCHAR * rgbDesc, SQLINTEGER  cbDescMax, SQLINTEGER * pcbDesc, SQLINTEGER * pfDesc )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLColAttributesIleCallStruct * arglist = (SQLColAttributesIleCallStruct *) NULL;
  char buffer[ sizeof(SQLColAttributesIleCallStruct) + 16 ];
  static arg_type_t SQLColAttributesIleSigStruct[] = { ARG_INT32, ARG_INT16, ARG_INT16, ARG_MEMPTR, ARG_INT32, ARG_MEMPTR, ARG_MEMPTR, ARG_END };
  arglist = (SQLColAttributesIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLColAttributesBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLColAttributesLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLColAttributes");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLColAttributesLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->icol = (SQLSMALLINT) icol;
  arglist->fDescType = (SQLSMALLINT) fDescType;
  arglist->rgbDesc.s.addr = (ulong) rgbDesc;
  arglist->cbDescMax = (SQLINTEGER) cbDescMax;
  arglist->pcbDesc.s.addr = (ulong) pcbDesc;
  arglist->pfDesc.s.addr = (ulong) pfDesc;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLColAttributesIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLColAttributesW( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fDescType, SQLWCHAR * rgbDesc, SQLINTEGER  cbDescMax, SQLINTEGER * pcbDesc, SQLINTEGER * pfDesc )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLColAttributesWIleCallStruct * arglist = (SQLColAttributesWIleCallStruct *) NULL;
  char buffer[ sizeof(SQLColAttributesWIleCallStruct) + 16 ];
  static arg_type_t SQLColAttributesWIleSigStruct[] = { ARG_INT32, ARG_INT16, ARG_INT16, ARG_MEMPTR, ARG_INT32, ARG_MEMPTR, ARG_MEMPTR, ARG_END };
  arglist = (SQLColAttributesWIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLColAttributesWBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLColAttributesWLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLColAttributesW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLColAttributesWLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->icol = (SQLSMALLINT) icol;
  arglist->fDescType = (SQLSMALLINT) fDescType;
  arglist->rgbDesc.s.addr = (ulong) rgbDesc;
  arglist->cbDescMax = (SQLINTEGER) cbDescMax;
  arglist->pcbDesc.s.addr = (ulong) pcbDesc;
  arglist->pfDesc.s.addr = (ulong) pfDesc;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLColAttributesWIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLColumnPrivileges( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLCHAR * szColumnName, SQLSMALLINT  cbColumnName )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLColumnPrivilegesIleCallStruct * arglist = (SQLColumnPrivilegesIleCallStruct *) NULL;
  char buffer[ sizeof(SQLColumnPrivilegesIleCallStruct) + 16 ];
  static arg_type_t SQLColumnPrivilegesIleSigStruct[] = { ARG_INT32, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_END };
  arglist = (SQLColumnPrivilegesIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLColumnPrivilegesBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLColumnPrivilegesLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLColumnPrivileges");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLColumnPrivilegesLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->szTableQualifier.s.addr = (ulong) szTableQualifier;
  arglist->cbTableQualifier = (SQLSMALLINT) cbTableQualifier;
  arglist->szTableOwner.s.addr = (ulong) szTableOwner;
  arglist->cbTableOwner = (SQLSMALLINT) cbTableOwner;
  arglist->szTableName.s.addr = (ulong) szTableName;
  arglist->cbTableName = (SQLSMALLINT) cbTableName;
  arglist->szColumnName.s.addr = (ulong) szColumnName;
  arglist->cbColumnName = (SQLSMALLINT) cbColumnName;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLColumnPrivilegesIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLColumnPrivilegesW( SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName, SQLWCHAR * szColumnName, SQLSMALLINT  cbColumnName )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLColumnPrivilegesWIleCallStruct * arglist = (SQLColumnPrivilegesWIleCallStruct *) NULL;
  char buffer[ sizeof(SQLColumnPrivilegesWIleCallStruct) + 16 ];
  static arg_type_t SQLColumnPrivilegesWIleSigStruct[] = { ARG_INT32, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_END };
  arglist = (SQLColumnPrivilegesWIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLColumnPrivilegesWBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLColumnPrivilegesWLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLColumnPrivilegesW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLColumnPrivilegesWLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->szTableQualifier.s.addr = (ulong) szTableQualifier;
  arglist->cbTableQualifier = (SQLSMALLINT) cbTableQualifier;
  arglist->szTableOwner.s.addr = (ulong) szTableOwner;
  arglist->cbTableOwner = (SQLSMALLINT) cbTableOwner;
  arglist->szTableName.s.addr = (ulong) szTableName;
  arglist->cbTableName = (SQLSMALLINT) cbTableName;
  arglist->szColumnName.s.addr = (ulong) szColumnName;
  arglist->cbColumnName = (SQLSMALLINT) cbColumnName;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLColumnPrivilegesWIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLColumns( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLCHAR * szColumnName, SQLSMALLINT  cbColumnName )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLColumnsIleCallStruct * arglist = (SQLColumnsIleCallStruct *) NULL;
  char buffer[ sizeof(SQLColumnsIleCallStruct) + 16 ];
  static arg_type_t SQLColumnsIleSigStruct[] = { ARG_INT32, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_END };
  arglist = (SQLColumnsIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLColumnsBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLColumnsLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLColumns");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLColumnsLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->szTableQualifier.s.addr = (ulong) szTableQualifier;
  arglist->cbTableQualifier = (SQLSMALLINT) cbTableQualifier;
  arglist->szTableOwner.s.addr = (ulong) szTableOwner;
  arglist->cbTableOwner = (SQLSMALLINT) cbTableOwner;
  arglist->szTableName.s.addr = (ulong) szTableName;
  arglist->cbTableName = (SQLSMALLINT) cbTableName;
  arglist->szColumnName.s.addr = (ulong) szColumnName;
  arglist->cbColumnName = (SQLSMALLINT) cbColumnName;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLColumnsIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLColumnsW( SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName, SQLWCHAR * szColumnName, SQLSMALLINT  cbColumnName )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLColumnsWIleCallStruct * arglist = (SQLColumnsWIleCallStruct *) NULL;
  char buffer[ sizeof(SQLColumnsWIleCallStruct) + 16 ];
  static arg_type_t SQLColumnsWIleSigStruct[] = { ARG_INT32, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_END };
  arglist = (SQLColumnsWIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLColumnsWBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLColumnsWLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLColumnsW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLColumnsWLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->szTableQualifier.s.addr = (ulong) szTableQualifier;
  arglist->cbTableQualifier = (SQLSMALLINT) cbTableQualifier;
  arglist->szTableOwner.s.addr = (ulong) szTableOwner;
  arglist->cbTableOwner = (SQLSMALLINT) cbTableOwner;
  arglist->szTableName.s.addr = (ulong) szTableName;
  arglist->cbTableName = (SQLSMALLINT) cbTableName;
  arglist->szColumnName.s.addr = (ulong) szColumnName;
  arglist->cbColumnName = (SQLSMALLINT) cbColumnName;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLColumnsWIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLConnect( SQLHDBC  hdbc, SQLCHAR * szDSN, SQLSMALLINT  cbDSN, SQLCHAR * szUID, SQLSMALLINT  cbUID, SQLCHAR * szAuthStr, SQLSMALLINT  cbAuthStr )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLConnectIleCallStruct * arglist = (SQLConnectIleCallStruct *) NULL;
  char buffer[ sizeof(SQLConnectIleCallStruct) + 16 ];
  static arg_type_t SQLConnectIleSigStruct[] = { ARG_INT32, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_END };
  arglist = (SQLConnectIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLConnectBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLConnectLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLConnect");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLConnectLoaded = 1;
  }
  arglist->hdbc = (SQLHDBC) hdbc;
  arglist->szDSN.s.addr = (ulong) szDSN;
  arglist->cbDSN = (SQLSMALLINT) cbDSN;
  arglist->szUID.s.addr = (ulong) szUID;
  arglist->cbUID = (SQLSMALLINT) cbUID;
  arglist->szAuthStr.s.addr = (ulong) szAuthStr;
  arglist->cbAuthStr = (SQLSMALLINT) cbAuthStr;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLConnectIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLConnectW( SQLHDBC  hdbc, SQLWCHAR * szDSN, SQLSMALLINT  cbDSN, SQLWCHAR * szUID, SQLSMALLINT  cbUID, SQLWCHAR * szAuthStr, SQLSMALLINT  cbAuthStr )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLConnectWIleCallStruct * arglist = (SQLConnectWIleCallStruct *) NULL;
  char buffer[ sizeof(SQLConnectWIleCallStruct) + 16 ];
  static arg_type_t SQLConnectWIleSigStruct[] = { ARG_INT32, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_END };
  arglist = (SQLConnectWIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLConnectWBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLConnectWLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLConnectW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLConnectWLoaded = 1;
  }
  arglist->hdbc = (SQLHDBC) hdbc;
  arglist->szDSN.s.addr = (ulong) szDSN;
  arglist->cbDSN = (SQLSMALLINT) cbDSN;
  arglist->szUID.s.addr = (ulong) szUID;
  arglist->cbUID = (SQLSMALLINT) cbUID;
  arglist->szAuthStr.s.addr = (ulong) szAuthStr;
  arglist->cbAuthStr = (SQLSMALLINT) cbAuthStr;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLConnectWIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLCopyDesc( SQLHDESC  sDesc, SQLHDESC  tDesc )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLCopyDescIleCallStruct * arglist = (SQLCopyDescIleCallStruct *) NULL;
  char buffer[ sizeof(SQLCopyDescIleCallStruct) + 16 ];
  static arg_type_t SQLCopyDescIleSigStruct[] = { ARG_INT32, ARG_INT32, ARG_END };
  arglist = (SQLCopyDescIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLCopyDescBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLCopyDescLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLCopyDesc");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLCopyDescLoaded = 1;
  }
  arglist->sDesc = (SQLHDESC) sDesc;
  arglist->tDesc = (SQLHDESC) tDesc;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLCopyDescIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLDataSources( SQLHENV  henv, SQLSMALLINT  fDirection, SQLCHAR * szDSN, SQLSMALLINT  cbDSNMax, SQLSMALLINT * pcbDSN, SQLCHAR * szDescription, SQLSMALLINT  cbDescriptionMax, SQLSMALLINT * pcbDescription )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLDataSourcesIleCallStruct * arglist = (SQLDataSourcesIleCallStruct *) NULL;
  char buffer[ sizeof(SQLDataSourcesIleCallStruct) + 16 ];
  static arg_type_t SQLDataSourcesIleSigStruct[] = { ARG_INT32, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_END };
  arglist = (SQLDataSourcesIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLDataSourcesBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLDataSourcesLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLDataSources");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLDataSourcesLoaded = 1;
  }
  arglist->henv = (SQLHENV) henv;
  arglist->fDirection = (SQLSMALLINT) fDirection;
  arglist->szDSN.s.addr = (ulong) szDSN;
  arglist->cbDSNMax = (SQLSMALLINT) cbDSNMax;
  arglist->pcbDSN.s.addr = (ulong) pcbDSN;
  arglist->szDescription.s.addr = (ulong) szDescription;
  arglist->cbDescriptionMax = (SQLSMALLINT) cbDescriptionMax;
  arglist->pcbDescription.s.addr = (ulong) pcbDescription;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLDataSourcesIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLDataSourcesW( SQLHENV  henv, SQLSMALLINT  fDirection, SQLWCHAR * szDSN, SQLSMALLINT  cbDSNMax, SQLSMALLINT * pcbDSN, SQLWCHAR * szDescription, SQLSMALLINT  cbDescriptionMax, SQLSMALLINT * pcbDescription )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLDataSourcesWIleCallStruct * arglist = (SQLDataSourcesWIleCallStruct *) NULL;
  char buffer[ sizeof(SQLDataSourcesWIleCallStruct) + 16 ];
  static arg_type_t SQLDataSourcesWIleSigStruct[] = { ARG_INT32, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_END };
  arglist = (SQLDataSourcesWIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLDataSourcesWBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLDataSourcesWLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLDataSourcesW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLDataSourcesWLoaded = 1;
  }
  arglist->henv = (SQLHENV) henv;
  arglist->fDirection = (SQLSMALLINT) fDirection;
  arglist->szDSN.s.addr = (ulong) szDSN;
  arglist->cbDSNMax = (SQLSMALLINT) cbDSNMax;
  arglist->pcbDSN.s.addr = (ulong) pcbDSN;
  arglist->szDescription.s.addr = (ulong) szDescription;
  arglist->cbDescriptionMax = (SQLSMALLINT) cbDescriptionMax;
  arglist->pcbDescription.s.addr = (ulong) pcbDescription;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLDataSourcesWIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLDescribeCol( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLCHAR * szColName, SQLSMALLINT  cbColNameMax, SQLSMALLINT * pcbColName, SQLSMALLINT * pfSqlType, SQLINTEGER * pcbColDef, SQLSMALLINT * pibScale, SQLSMALLINT * pfNullable )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLDescribeColIleCallStruct * arglist = (SQLDescribeColIleCallStruct *) NULL;
  char buffer[ sizeof(SQLDescribeColIleCallStruct) + 16 ];
  static arg_type_t SQLDescribeColIleSigStruct[] = { ARG_INT32, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_MEMPTR, ARG_MEMPTR, ARG_MEMPTR, ARG_MEMPTR, ARG_END };
  arglist = (SQLDescribeColIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLDescribeColBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLDescribeColLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLDescribeCol");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLDescribeColLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->icol = (SQLSMALLINT) icol;
  arglist->szColName.s.addr = (ulong) szColName;
  arglist->cbColNameMax = (SQLSMALLINT) cbColNameMax;
  arglist->pcbColName.s.addr = (ulong) pcbColName;
  arglist->pfSqlType.s.addr = (ulong) pfSqlType;
  arglist->pcbColDef.s.addr = (ulong) pcbColDef;
  arglist->pibScale.s.addr = (ulong) pibScale;
  arglist->pfNullable.s.addr = (ulong) pfNullable;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLDescribeColIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLDescribeColW( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLWCHAR * szColName, SQLSMALLINT  cbColNameMax, SQLSMALLINT * pcbColName, SQLSMALLINT * pfSqlType, SQLINTEGER * pcbColDef, SQLSMALLINT * pibScale, SQLSMALLINT * pfNullable )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLDescribeColWIleCallStruct * arglist = (SQLDescribeColWIleCallStruct *) NULL;
  char buffer[ sizeof(SQLDescribeColWIleCallStruct) + 16 ];
  static arg_type_t SQLDescribeColWIleSigStruct[] = { ARG_INT32, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_MEMPTR, ARG_MEMPTR, ARG_MEMPTR, ARG_MEMPTR, ARG_END };
  arglist = (SQLDescribeColWIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLDescribeColWBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLDescribeColWLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLDescribeColW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLDescribeColWLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->icol = (SQLSMALLINT) icol;
  arglist->szColName.s.addr = (ulong) szColName;
  arglist->cbColNameMax = (SQLSMALLINT) cbColNameMax;
  arglist->pcbColName.s.addr = (ulong) pcbColName;
  arglist->pfSqlType.s.addr = (ulong) pfSqlType;
  arglist->pcbColDef.s.addr = (ulong) pcbColDef;
  arglist->pibScale.s.addr = (ulong) pibScale;
  arglist->pfNullable.s.addr = (ulong) pfNullable;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLDescribeColWIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLDescribeParam( SQLHSTMT  hstmt, SQLSMALLINT  ipar, SQLSMALLINT * pfSqlType, SQLINTEGER * pcbColDef, SQLSMALLINT * pibScale, SQLSMALLINT * pfNullable )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLDescribeParamIleCallStruct * arglist = (SQLDescribeParamIleCallStruct *) NULL;
  char buffer[ sizeof(SQLDescribeParamIleCallStruct) + 16 ];
  static arg_type_t SQLDescribeParamIleSigStruct[] = { ARG_INT32, ARG_INT16, ARG_MEMPTR, ARG_MEMPTR, ARG_MEMPTR, ARG_MEMPTR, ARG_END };
  arglist = (SQLDescribeParamIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLDescribeParamBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLDescribeParamLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLDescribeParam");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLDescribeParamLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->ipar = (SQLSMALLINT) ipar;
  arglist->pfSqlType.s.addr = (ulong) pfSqlType;
  arglist->pcbColDef.s.addr = (ulong) pcbColDef;
  arglist->pibScale.s.addr = (ulong) pibScale;
  arglist->pfNullable.s.addr = (ulong) pfNullable;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLDescribeParamIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLDisconnect( SQLHDBC  hdbc )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLDisconnectIleCallStruct * arglist = (SQLDisconnectIleCallStruct *) NULL;
  char buffer[ sizeof(SQLDisconnectIleCallStruct) + 16 ];
  static arg_type_t SQLDisconnectIleSigStruct[] = { ARG_INT32, ARG_END };
  arglist = (SQLDisconnectIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLDisconnectBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLDisconnectLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLDisconnect");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLDisconnectLoaded = 1;
  }
  arglist->hdbc = (SQLHDBC) hdbc;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLDisconnectIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLDriverConnect( SQLHDBC  hdbc, SQLPOINTER  hwnd, SQLCHAR * szConnStrIn, SQLSMALLINT  cbConnStrin, SQLCHAR * szConnStrOut, SQLSMALLINT  cbConnStrOutMax, SQLSMALLINT * pcbConnStrOut, SQLSMALLINT  fDriverCompletion )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLDriverConnectIleCallStruct * arglist = (SQLDriverConnectIleCallStruct *) NULL;
  char buffer[ sizeof(SQLDriverConnectIleCallStruct) + 16 ];
  static arg_type_t SQLDriverConnectIleSigStruct[] = { ARG_INT32, ARG_MEMPTR, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_END };
  arglist = (SQLDriverConnectIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLDriverConnectBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLDriverConnectLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLDriverConnect");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLDriverConnectLoaded = 1;
  }
  arglist->hdbc = (SQLHDBC) hdbc;
  arglist->hwnd.s.addr = (ulong) hwnd;
  arglist->szConnStrIn.s.addr = (ulong) szConnStrIn;
  arglist->cbConnStrin = (SQLSMALLINT) cbConnStrin;
  arglist->szConnStrOut.s.addr = (ulong) szConnStrOut;
  arglist->cbConnStrOutMax = (SQLSMALLINT) cbConnStrOutMax;
  arglist->pcbConnStrOut.s.addr = (ulong) pcbConnStrOut;
  arglist->fDriverCompletion = (SQLSMALLINT) fDriverCompletion;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLDriverConnectIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLDriverConnectW( SQLHDBC  hdbc, SQLPOINTER  hwnd, SQLWCHAR * szConnStrIn, SQLSMALLINT  cbConnStrin, SQLWCHAR * szConnStrOut, SQLSMALLINT  cbConnStrOutMax, SQLSMALLINT * pcbConnStrOut, SQLSMALLINT  fDriverCompletion )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLDriverConnectWIleCallStruct * arglist = (SQLDriverConnectWIleCallStruct *) NULL;
  char buffer[ sizeof(SQLDriverConnectWIleCallStruct) + 16 ];
  static arg_type_t SQLDriverConnectWIleSigStruct[] = { ARG_INT32, ARG_MEMPTR, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_END };
  arglist = (SQLDriverConnectWIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLDriverConnectWBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLDriverConnectWLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLDriverConnectW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLDriverConnectWLoaded = 1;
  }
  arglist->hdbc = (SQLHDBC) hdbc;
  arglist->hwnd.s.addr = (ulong) hwnd;
  arglist->szConnStrIn.s.addr = (ulong) szConnStrIn;
  arglist->cbConnStrin = (SQLSMALLINT) cbConnStrin;
  arglist->szConnStrOut.s.addr = (ulong) szConnStrOut;
  arglist->cbConnStrOutMax = (SQLSMALLINT) cbConnStrOutMax;
  arglist->pcbConnStrOut.s.addr = (ulong) pcbConnStrOut;
  arglist->fDriverCompletion = (SQLSMALLINT) fDriverCompletion;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLDriverConnectWIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLEndTran( SQLSMALLINT  htype, SQLHENV  henv, SQLSMALLINT  ctype )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLEndTranIleCallStruct * arglist = (SQLEndTranIleCallStruct *) NULL;
  char buffer[ sizeof(SQLEndTranIleCallStruct) + 16 ];
  static arg_type_t SQLEndTranIleSigStruct[] = { ARG_INT16, ARG_INT32, ARG_INT16, ARG_END };
  arglist = (SQLEndTranIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLEndTranBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLEndTranLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLEndTran");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLEndTranLoaded = 1;
  }
  arglist->htype = (SQLSMALLINT) htype;
  arglist->henv = (SQLHENV) henv;
  arglist->ctype = (SQLSMALLINT) ctype;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLEndTranIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLError( SQLHENV  henv, SQLHDBC  hdbc, SQLHSTMT  hstmt, SQLCHAR * szSqlState, SQLINTEGER * pfNativeError, SQLCHAR * szErrorMsg, SQLSMALLINT  cbErrorMsgMax, SQLSMALLINT * pcbErrorMsg )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLErrorIleCallStruct * arglist = (SQLErrorIleCallStruct *) NULL;
  char buffer[ sizeof(SQLErrorIleCallStruct) + 16 ];
  static arg_type_t SQLErrorIleSigStruct[] = { ARG_INT32, ARG_INT32, ARG_INT32, ARG_MEMPTR, ARG_MEMPTR, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_END };
  arglist = (SQLErrorIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLErrorBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLErrorLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLError");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLErrorLoaded = 1;
  }
  arglist->henv = (SQLHENV) henv;
  arglist->hdbc = (SQLHDBC) hdbc;
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->szSqlState.s.addr = (ulong) szSqlState;
  arglist->pfNativeError.s.addr = (ulong) pfNativeError;
  arglist->szErrorMsg.s.addr = (ulong) szErrorMsg;
  arglist->cbErrorMsgMax = (SQLSMALLINT) cbErrorMsgMax;
  arglist->pcbErrorMsg.s.addr = (ulong) pcbErrorMsg;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLErrorIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLErrorW( SQLHENV  henv, SQLHDBC  hdbc, SQLHSTMT  hstmt, SQLWCHAR * szSqlState, SQLINTEGER * pfNativeError, SQLWCHAR * szErrorMsg, SQLSMALLINT  cbErrorMsgMax, SQLSMALLINT * pcbErrorMsg )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLErrorWIleCallStruct * arglist = (SQLErrorWIleCallStruct *) NULL;
  char buffer[ sizeof(SQLErrorWIleCallStruct) + 16 ];
  static arg_type_t SQLErrorWIleSigStruct[] = { ARG_INT32, ARG_INT32, ARG_INT32, ARG_MEMPTR, ARG_MEMPTR, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_END };
  arglist = (SQLErrorWIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLErrorWBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLErrorWLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLErrorW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLErrorWLoaded = 1;
  }
  arglist->henv = (SQLHENV) henv;
  arglist->hdbc = (SQLHDBC) hdbc;
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->szSqlState.s.addr = (ulong) szSqlState;
  arglist->pfNativeError.s.addr = (ulong) pfNativeError;
  arglist->szErrorMsg.s.addr = (ulong) szErrorMsg;
  arglist->cbErrorMsgMax = (SQLSMALLINT) cbErrorMsgMax;
  arglist->pcbErrorMsg.s.addr = (ulong) pcbErrorMsg;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLErrorWIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLExecDirect( SQLHSTMT  hstmt, SQLCHAR * szSqlStr, SQLINTEGER  cbSqlStr )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLExecDirectIleCallStruct * arglist = (SQLExecDirectIleCallStruct *) NULL;
  char buffer[ sizeof(SQLExecDirectIleCallStruct) + 16 ];
  static arg_type_t SQLExecDirectIleSigStruct[] = { ARG_INT32, ARG_MEMPTR, ARG_INT32, ARG_END };
  arglist = (SQLExecDirectIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLExecDirectBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLExecDirectLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLExecDirect");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLExecDirectLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->szSqlStr.s.addr = (ulong) szSqlStr;
  arglist->cbSqlStr = (SQLINTEGER) cbSqlStr;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLExecDirectIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLExecDirectW( SQLHSTMT  hstmt, SQLWCHAR * szSqlStr, SQLINTEGER  cbSqlStr )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLExecDirectWIleCallStruct * arglist = (SQLExecDirectWIleCallStruct *) NULL;
  char buffer[ sizeof(SQLExecDirectWIleCallStruct) + 16 ];
  static arg_type_t SQLExecDirectWIleSigStruct[] = { ARG_INT32, ARG_MEMPTR, ARG_INT32, ARG_END };
  arglist = (SQLExecDirectWIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLExecDirectWBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLExecDirectWLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLExecDirectW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLExecDirectWLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->szSqlStr.s.addr = (ulong) szSqlStr;
  arglist->cbSqlStr = (SQLINTEGER) cbSqlStr;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLExecDirectWIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLExecute( SQLHSTMT  hstmt )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLExecuteIleCallStruct * arglist = (SQLExecuteIleCallStruct *) NULL;
  char buffer[ sizeof(SQLExecuteIleCallStruct) + 16 ];
  static arg_type_t SQLExecuteIleSigStruct[] = { ARG_INT32, ARG_END };
  arglist = (SQLExecuteIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLExecuteBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLExecuteLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLExecute");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLExecuteLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLExecuteIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLExtendedFetch( SQLHSTMT  hstmt, SQLSMALLINT  fOrient, SQLINTEGER  fOffset, SQLINTEGER * pcrow, SQLSMALLINT * rgfRowStatus )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLExtendedFetchIleCallStruct * arglist = (SQLExtendedFetchIleCallStruct *) NULL;
  char buffer[ sizeof(SQLExtendedFetchIleCallStruct) + 16 ];
  static arg_type_t SQLExtendedFetchIleSigStruct[] = { ARG_INT32, ARG_INT16, ARG_INT32, ARG_MEMPTR, ARG_MEMPTR, ARG_END };
  arglist = (SQLExtendedFetchIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLExtendedFetchBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLExtendedFetchLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLExtendedFetch");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLExtendedFetchLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->fOrient = (SQLSMALLINT) fOrient;
  arglist->fOffset = (SQLINTEGER) fOffset;
  arglist->pcrow.s.addr = (ulong) pcrow;
  arglist->rgfRowStatus.s.addr = (ulong) rgfRowStatus;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLExtendedFetchIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLFetch( SQLHSTMT  hstmt )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLFetchIleCallStruct * arglist = (SQLFetchIleCallStruct *) NULL;
  char buffer[ sizeof(SQLFetchIleCallStruct) + 16 ];
  static arg_type_t SQLFetchIleSigStruct[] = { ARG_INT32, ARG_END };
  arglist = (SQLFetchIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLFetchBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLFetchLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLFetch");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLFetchLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLFetchIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLFetchScroll( SQLHSTMT  hstmt, SQLSMALLINT  fOrient, SQLINTEGER  fOffset )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLFetchScrollIleCallStruct * arglist = (SQLFetchScrollIleCallStruct *) NULL;
  char buffer[ sizeof(SQLFetchScrollIleCallStruct) + 16 ];
  static arg_type_t SQLFetchScrollIleSigStruct[] = { ARG_INT32, ARG_INT16, ARG_INT32, ARG_END };
  arglist = (SQLFetchScrollIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLFetchScrollBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLFetchScrollLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLFetchScroll");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLFetchScrollLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->fOrient = (SQLSMALLINT) fOrient;
  arglist->fOffset = (SQLINTEGER) fOffset;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLFetchScrollIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLForeignKeys( SQLHSTMT  hstmt, SQLCHAR * szPkTableQualifier, SQLSMALLINT  cbPkTableQualifier, SQLCHAR * szPkTableOwner, SQLSMALLINT  cbPkTableOwner, SQLCHAR * szPkTableName, SQLSMALLINT  cbPkTableName, SQLCHAR * szFkTableQualifier, SQLSMALLINT  cbFkTableQualifier, SQLCHAR * szFkTableOwner, SQLSMALLINT  cbFkTableOwner, SQLCHAR * szFkTableName, SQLSMALLINT  cbFkTableName )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLForeignKeysIleCallStruct * arglist = (SQLForeignKeysIleCallStruct *) NULL;
  char buffer[ sizeof(SQLForeignKeysIleCallStruct) + 16 ];
  static arg_type_t SQLForeignKeysIleSigStruct[] = { ARG_INT32, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_END };
  arglist = (SQLForeignKeysIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLForeignKeysBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLForeignKeysLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLForeignKeys");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLForeignKeysLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->szPkTableQualifier.s.addr = (ulong) szPkTableQualifier;
  arglist->cbPkTableQualifier = (SQLSMALLINT) cbPkTableQualifier;
  arglist->szPkTableOwner.s.addr = (ulong) szPkTableOwner;
  arglist->cbPkTableOwner = (SQLSMALLINT) cbPkTableOwner;
  arglist->szPkTableName.s.addr = (ulong) szPkTableName;
  arglist->cbPkTableName = (SQLSMALLINT) cbPkTableName;
  arglist->szFkTableQualifier.s.addr = (ulong) szFkTableQualifier;
  arglist->cbFkTableQualifier = (SQLSMALLINT) cbFkTableQualifier;
  arglist->szFkTableOwner.s.addr = (ulong) szFkTableOwner;
  arglist->cbFkTableOwner = (SQLSMALLINT) cbFkTableOwner;
  arglist->szFkTableName.s.addr = (ulong) szFkTableName;
  arglist->cbFkTableName = (SQLSMALLINT) cbFkTableName;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLForeignKeysIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLForeignKeysW( SQLHSTMT  hstmt, SQLWCHAR * szPkTableQualifier, SQLSMALLINT  cbPkTableQualifier, SQLWCHAR * szPkTableOwner, SQLSMALLINT  cbPkTableOwner, SQLWCHAR * szPkTableName, SQLSMALLINT  cbPkTableName, SQLWCHAR * szFkTableQualifier, SQLSMALLINT  cbFkTableQualifier, SQLWCHAR * szFkTableOwner, SQLSMALLINT  cbFkTableOwner, SQLWCHAR * szFkTableName, SQLSMALLINT  cbFkTableName )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLForeignKeysWIleCallStruct * arglist = (SQLForeignKeysWIleCallStruct *) NULL;
  char buffer[ sizeof(SQLForeignKeysWIleCallStruct) + 16 ];
  static arg_type_t SQLForeignKeysWIleSigStruct[] = { ARG_INT32, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_END };
  arglist = (SQLForeignKeysWIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLForeignKeysWBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLForeignKeysWLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLForeignKeysW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLForeignKeysWLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->szPkTableQualifier.s.addr = (ulong) szPkTableQualifier;
  arglist->cbPkTableQualifier = (SQLSMALLINT) cbPkTableQualifier;
  arglist->szPkTableOwner.s.addr = (ulong) szPkTableOwner;
  arglist->cbPkTableOwner = (SQLSMALLINT) cbPkTableOwner;
  arglist->szPkTableName.s.addr = (ulong) szPkTableName;
  arglist->cbPkTableName = (SQLSMALLINT) cbPkTableName;
  arglist->szFkTableQualifier.s.addr = (ulong) szFkTableQualifier;
  arglist->cbFkTableQualifier = (SQLSMALLINT) cbFkTableQualifier;
  arglist->szFkTableOwner.s.addr = (ulong) szFkTableOwner;
  arglist->cbFkTableOwner = (SQLSMALLINT) cbFkTableOwner;
  arglist->szFkTableName.s.addr = (ulong) szFkTableName;
  arglist->cbFkTableName = (SQLSMALLINT) cbFkTableName;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLForeignKeysWIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLFreeConnect( SQLHDBC  hdbc )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLFreeConnectIleCallStruct * arglist = (SQLFreeConnectIleCallStruct *) NULL;
  char buffer[ sizeof(SQLFreeConnectIleCallStruct) + 16 ];
  static arg_type_t SQLFreeConnectIleSigStruct[] = { ARG_INT32, ARG_END };
  arglist = (SQLFreeConnectIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLFreeConnectBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLFreeConnectLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLFreeConnect");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLFreeConnectLoaded = 1;
  }
  arglist->hdbc = (SQLHDBC) hdbc;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLFreeConnectIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLFreeEnv( SQLHENV  henv )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLFreeEnvIleCallStruct * arglist = (SQLFreeEnvIleCallStruct *) NULL;
  char buffer[ sizeof(SQLFreeEnvIleCallStruct) + 16 ];
  static arg_type_t SQLFreeEnvIleSigStruct[] = { ARG_INT32, ARG_END };
  arglist = (SQLFreeEnvIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLFreeEnvBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLFreeEnvLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLFreeEnv");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLFreeEnvLoaded = 1;
  }
  arglist->henv = (SQLHENV) henv;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLFreeEnvIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLFreeStmt( SQLHSTMT  hstmt, SQLSMALLINT  fOption )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLFreeStmtIleCallStruct * arglist = (SQLFreeStmtIleCallStruct *) NULL;
  char buffer[ sizeof(SQLFreeStmtIleCallStruct) + 16 ];
  static arg_type_t SQLFreeStmtIleSigStruct[] = { ARG_INT32, ARG_INT16, ARG_END };
  arglist = (SQLFreeStmtIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLFreeStmtBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLFreeStmtLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLFreeStmt");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLFreeStmtLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->fOption = (SQLSMALLINT) fOption;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLFreeStmtIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLFreeHandle( SQLSMALLINT  htype, SQLINTEGER  hndl )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLFreeHandleIleCallStruct * arglist = (SQLFreeHandleIleCallStruct *) NULL;
  char buffer[ sizeof(SQLFreeHandleIleCallStruct) + 16 ];
  static arg_type_t SQLFreeHandleIleSigStruct[] = { ARG_INT16, ARG_INT32, ARG_END };
  arglist = (SQLFreeHandleIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLFreeHandleBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLFreeHandleLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLFreeHandle");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLFreeHandleLoaded = 1;
  }
  arglist->htype = (SQLSMALLINT) htype;
  arglist->hndl = (SQLINTEGER) hndl;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLFreeHandleIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLGetCol( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  itype, SQLPOINTER  tval, SQLINTEGER  blen, SQLINTEGER * olen )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLGetColIleCallStruct * arglist = (SQLGetColIleCallStruct *) NULL;
  char buffer[ sizeof(SQLGetColIleCallStruct) + 16 ];
  static arg_type_t SQLGetColIleSigStruct[] = { ARG_INT32, ARG_INT16, ARG_INT16, ARG_MEMPTR, ARG_INT32, ARG_MEMPTR, ARG_END };
  arglist = (SQLGetColIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLGetColBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLGetColLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLGetCol");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetColLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->icol = (SQLSMALLINT) icol;
  arglist->itype = (SQLSMALLINT) itype;
  arglist->tval.s.addr = (ulong) tval;
  arglist->blen = (SQLINTEGER) blen;
  arglist->olen.s.addr = (ulong) olen;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLGetColIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLGetColW( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  itype, SQLPOINTER  tval, SQLINTEGER  blen, SQLINTEGER * olen )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLGetColWIleCallStruct * arglist = (SQLGetColWIleCallStruct *) NULL;
  char buffer[ sizeof(SQLGetColWIleCallStruct) + 16 ];
  static arg_type_t SQLGetColWIleSigStruct[] = { ARG_INT32, ARG_INT16, ARG_INT16, ARG_MEMPTR, ARG_INT32, ARG_MEMPTR, ARG_END };
  arglist = (SQLGetColWIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLGetColWBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLGetColWLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLGetColW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetColWLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->icol = (SQLSMALLINT) icol;
  arglist->itype = (SQLSMALLINT) itype;
  arglist->tval.s.addr = (ulong) tval;
  arglist->blen = (SQLINTEGER) blen;
  arglist->olen.s.addr = (ulong) olen;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLGetColWIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLGetConnectAttr( SQLHDBC  hdbc, SQLINTEGER  attr, SQLPOINTER  oval, SQLINTEGER  ilen, SQLINTEGER * olen )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLGetConnectAttrIleCallStruct * arglist = (SQLGetConnectAttrIleCallStruct *) NULL;
  char buffer[ sizeof(SQLGetConnectAttrIleCallStruct) + 16 ];
  static arg_type_t SQLGetConnectAttrIleSigStruct[] = { ARG_INT32, ARG_INT32, ARG_MEMPTR, ARG_INT32, ARG_MEMPTR, ARG_END };
  arglist = (SQLGetConnectAttrIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLGetConnectAttrBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLGetConnectAttrLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLGetConnectAttr");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetConnectAttrLoaded = 1;
  }
  arglist->hdbc = (SQLHDBC) hdbc;
  arglist->attr = (SQLINTEGER) attr;
  arglist->oval.s.addr = (ulong) oval;
  arglist->ilen = (SQLINTEGER) ilen;
  arglist->olen.s.addr = (ulong) olen;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLGetConnectAttrIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLGetConnectAttrW( SQLHDBC  hdbc, SQLINTEGER  attr, SQLPOINTER  oval, SQLINTEGER  ilen, SQLINTEGER * olen )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLGetConnectAttrWIleCallStruct * arglist = (SQLGetConnectAttrWIleCallStruct *) NULL;
  char buffer[ sizeof(SQLGetConnectAttrWIleCallStruct) + 16 ];
  static arg_type_t SQLGetConnectAttrWIleSigStruct[] = { ARG_INT32, ARG_INT32, ARG_MEMPTR, ARG_INT32, ARG_MEMPTR, ARG_END };
  arglist = (SQLGetConnectAttrWIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLGetConnectAttrWBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLGetConnectAttrWLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLGetConnectAttrW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetConnectAttrWLoaded = 1;
  }
  arglist->hdbc = (SQLHDBC) hdbc;
  arglist->attr = (SQLINTEGER) attr;
  arglist->oval.s.addr = (ulong) oval;
  arglist->ilen = (SQLINTEGER) ilen;
  arglist->olen.s.addr = (ulong) olen;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLGetConnectAttrWIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLGetConnectOption( SQLHDBC  hdbc, SQLSMALLINT  iopt, SQLPOINTER  oval )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLGetConnectOptionIleCallStruct * arglist = (SQLGetConnectOptionIleCallStruct *) NULL;
  char buffer[ sizeof(SQLGetConnectOptionIleCallStruct) + 16 ];
  static arg_type_t SQLGetConnectOptionIleSigStruct[] = { ARG_INT32, ARG_INT16, ARG_MEMPTR, ARG_END };
  arglist = (SQLGetConnectOptionIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLGetConnectOptionBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLGetConnectOptionLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLGetConnectOption");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetConnectOptionLoaded = 1;
  }
  arglist->hdbc = (SQLHDBC) hdbc;
  arglist->iopt = (SQLSMALLINT) iopt;
  arglist->oval.s.addr = (ulong) oval;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLGetConnectOptionIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLGetConnectOptionW( SQLHDBC  hdbc, SQLSMALLINT  iopt, SQLPOINTER  oval )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLGetConnectOptionWIleCallStruct * arglist = (SQLGetConnectOptionWIleCallStruct *) NULL;
  char buffer[ sizeof(SQLGetConnectOptionWIleCallStruct) + 16 ];
  static arg_type_t SQLGetConnectOptionWIleSigStruct[] = { ARG_INT32, ARG_INT16, ARG_MEMPTR, ARG_END };
  arglist = (SQLGetConnectOptionWIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLGetConnectOptionWBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLGetConnectOptionWLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLGetConnectOptionW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetConnectOptionWLoaded = 1;
  }
  arglist->hdbc = (SQLHDBC) hdbc;
  arglist->iopt = (SQLSMALLINT) iopt;
  arglist->oval.s.addr = (ulong) oval;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLGetConnectOptionWIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLGetCursorName( SQLHSTMT  hstmt, SQLCHAR * szCursor, SQLSMALLINT  cbCursorMax, SQLSMALLINT * pcbCursor )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLGetCursorNameIleCallStruct * arglist = (SQLGetCursorNameIleCallStruct *) NULL;
  char buffer[ sizeof(SQLGetCursorNameIleCallStruct) + 16 ];
  static arg_type_t SQLGetCursorNameIleSigStruct[] = { ARG_INT32, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_END };
  arglist = (SQLGetCursorNameIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLGetCursorNameBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLGetCursorNameLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLGetCursorName");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetCursorNameLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->szCursor.s.addr = (ulong) szCursor;
  arglist->cbCursorMax = (SQLSMALLINT) cbCursorMax;
  arglist->pcbCursor.s.addr = (ulong) pcbCursor;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLGetCursorNameIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLGetCursorNameW( SQLHSTMT  hstmt, SQLWCHAR * szCursor, SQLSMALLINT  cbCursorMax, SQLSMALLINT * pcbCursor )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLGetCursorNameWIleCallStruct * arglist = (SQLGetCursorNameWIleCallStruct *) NULL;
  char buffer[ sizeof(SQLGetCursorNameWIleCallStruct) + 16 ];
  static arg_type_t SQLGetCursorNameWIleSigStruct[] = { ARG_INT32, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_END };
  arglist = (SQLGetCursorNameWIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLGetCursorNameWBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLGetCursorNameWLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLGetCursorNameW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetCursorNameWLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->szCursor.s.addr = (ulong) szCursor;
  arglist->cbCursorMax = (SQLSMALLINT) cbCursorMax;
  arglist->pcbCursor.s.addr = (ulong) pcbCursor;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLGetCursorNameWIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLGetData( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fCType, SQLPOINTER  rgbValue, SQLINTEGER  cbValueMax, SQLINTEGER * pcbValue )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLGetDataIleCallStruct * arglist = (SQLGetDataIleCallStruct *) NULL;
  char buffer[ sizeof(SQLGetDataIleCallStruct) + 16 ];
  static arg_type_t SQLGetDataIleSigStruct[] = { ARG_INT32, ARG_INT16, ARG_INT16, ARG_MEMPTR, ARG_INT32, ARG_MEMPTR, ARG_END };
  arglist = (SQLGetDataIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLGetDataBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLGetDataLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLGetData");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetDataLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->icol = (SQLSMALLINT) icol;
  arglist->fCType = (SQLSMALLINT) fCType;
  arglist->rgbValue.s.addr = (ulong) rgbValue;
  arglist->cbValueMax = (SQLINTEGER) cbValueMax;
  arglist->pcbValue.s.addr = (ulong) pcbValue;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLGetDataIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLGetDescField( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  fieldID, SQLPOINTER  fValue, SQLINTEGER  fLength, SQLINTEGER * stLength )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLGetDescFieldIleCallStruct * arglist = (SQLGetDescFieldIleCallStruct *) NULL;
  char buffer[ sizeof(SQLGetDescFieldIleCallStruct) + 16 ];
  static arg_type_t SQLGetDescFieldIleSigStruct[] = { ARG_INT32, ARG_INT16, ARG_INT16, ARG_MEMPTR, ARG_INT32, ARG_MEMPTR, ARG_END };
  arglist = (SQLGetDescFieldIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLGetDescFieldBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLGetDescFieldLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLGetDescField");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetDescFieldLoaded = 1;
  }
  arglist->hdesc = (SQLHDESC) hdesc;
  arglist->rcdNum = (SQLSMALLINT) rcdNum;
  arglist->fieldID = (SQLSMALLINT) fieldID;
  arglist->fValue.s.addr = (ulong) fValue;
  arglist->fLength = (SQLINTEGER) fLength;
  arglist->stLength.s.addr = (ulong) stLength;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLGetDescFieldIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLGetDescFieldW( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  fieldID, SQLPOINTER  fValue, SQLINTEGER  fLength, SQLINTEGER * stLength )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLGetDescFieldWIleCallStruct * arglist = (SQLGetDescFieldWIleCallStruct *) NULL;
  char buffer[ sizeof(SQLGetDescFieldWIleCallStruct) + 16 ];
  static arg_type_t SQLGetDescFieldWIleSigStruct[] = { ARG_INT32, ARG_INT16, ARG_INT16, ARG_MEMPTR, ARG_INT32, ARG_MEMPTR, ARG_END };
  arglist = (SQLGetDescFieldWIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLGetDescFieldWBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLGetDescFieldWLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLGetDescFieldW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetDescFieldWLoaded = 1;
  }
  arglist->hdesc = (SQLHDESC) hdesc;
  arglist->rcdNum = (SQLSMALLINT) rcdNum;
  arglist->fieldID = (SQLSMALLINT) fieldID;
  arglist->fValue.s.addr = (ulong) fValue;
  arglist->fLength = (SQLINTEGER) fLength;
  arglist->stLength.s.addr = (ulong) stLength;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLGetDescFieldWIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLGetDescRec( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLCHAR * fname, SQLSMALLINT  bufLen, SQLSMALLINT * sLength, SQLSMALLINT * sType, SQLSMALLINT * sbType, SQLINTEGER * fLength, SQLSMALLINT * fprec, SQLSMALLINT * fscale, SQLSMALLINT * fnull )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLGetDescRecIleCallStruct * arglist = (SQLGetDescRecIleCallStruct *) NULL;
  char buffer[ sizeof(SQLGetDescRecIleCallStruct) + 16 ];
  static arg_type_t SQLGetDescRecIleSigStruct[] = { ARG_INT32, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_MEMPTR, ARG_MEMPTR, ARG_MEMPTR, ARG_MEMPTR, ARG_MEMPTR, ARG_MEMPTR, ARG_END };
  arglist = (SQLGetDescRecIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLGetDescRecBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLGetDescRecLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLGetDescRec");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetDescRecLoaded = 1;
  }
  arglist->hdesc = (SQLHDESC) hdesc;
  arglist->rcdNum = (SQLSMALLINT) rcdNum;
  arglist->fname.s.addr = (ulong) fname;
  arglist->bufLen = (SQLSMALLINT) bufLen;
  arglist->sLength.s.addr = (ulong) sLength;
  arglist->sType.s.addr = (ulong) sType;
  arglist->sbType.s.addr = (ulong) sbType;
  arglist->fLength.s.addr = (ulong) fLength;
  arglist->fprec.s.addr = (ulong) fprec;
  arglist->fscale.s.addr = (ulong) fscale;
  arglist->fnull.s.addr = (ulong) fnull;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLGetDescRecIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLGetDescRecW( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLWCHAR * fname, SQLSMALLINT  bufLen, SQLSMALLINT * sLength, SQLSMALLINT * sType, SQLSMALLINT * sbType, SQLINTEGER * fLength, SQLSMALLINT * fprec, SQLSMALLINT * fscale, SQLSMALLINT * fnull )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLGetDescRecWIleCallStruct * arglist = (SQLGetDescRecWIleCallStruct *) NULL;
  char buffer[ sizeof(SQLGetDescRecWIleCallStruct) + 16 ];
  static arg_type_t SQLGetDescRecWIleSigStruct[] = { ARG_INT32, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_MEMPTR, ARG_MEMPTR, ARG_MEMPTR, ARG_MEMPTR, ARG_MEMPTR, ARG_MEMPTR, ARG_END };
  arglist = (SQLGetDescRecWIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLGetDescRecWBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLGetDescRecWLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLGetDescRecW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetDescRecWLoaded = 1;
  }
  arglist->hdesc = (SQLHDESC) hdesc;
  arglist->rcdNum = (SQLSMALLINT) rcdNum;
  arglist->fname.s.addr = (ulong) fname;
  arglist->bufLen = (SQLSMALLINT) bufLen;
  arglist->sLength.s.addr = (ulong) sLength;
  arglist->sType.s.addr = (ulong) sType;
  arglist->sbType.s.addr = (ulong) sbType;
  arglist->fLength.s.addr = (ulong) fLength;
  arglist->fprec.s.addr = (ulong) fprec;
  arglist->fscale.s.addr = (ulong) fscale;
  arglist->fnull.s.addr = (ulong) fnull;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLGetDescRecWIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLGetDiagField( SQLSMALLINT  hType, SQLINTEGER  hndl, SQLSMALLINT  rcdNum, SQLSMALLINT  diagID, SQLPOINTER  dValue, SQLSMALLINT  bLength, SQLSMALLINT * sLength )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLGetDiagFieldIleCallStruct * arglist = (SQLGetDiagFieldIleCallStruct *) NULL;
  char buffer[ sizeof(SQLGetDiagFieldIleCallStruct) + 16 ];
  static arg_type_t SQLGetDiagFieldIleSigStruct[] = { ARG_INT16, ARG_INT32, ARG_INT16, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_END };
  arglist = (SQLGetDiagFieldIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLGetDiagFieldBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLGetDiagFieldLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLGetDiagField");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetDiagFieldLoaded = 1;
  }
  arglist->hType = (SQLSMALLINT) hType;
  arglist->hndl = (SQLINTEGER) hndl;
  arglist->rcdNum = (SQLSMALLINT) rcdNum;
  arglist->diagID = (SQLSMALLINT) diagID;
  arglist->dValue.s.addr = (ulong) dValue;
  arglist->bLength = (SQLSMALLINT) bLength;
  arglist->sLength.s.addr = (ulong) sLength;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLGetDiagFieldIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLGetDiagFieldW( SQLSMALLINT  hType, SQLINTEGER  hndl, SQLSMALLINT  rcdNum, SQLSMALLINT  diagID, SQLPOINTER  dValue, SQLSMALLINT  bLength, SQLSMALLINT * sLength )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLGetDiagFieldWIleCallStruct * arglist = (SQLGetDiagFieldWIleCallStruct *) NULL;
  char buffer[ sizeof(SQLGetDiagFieldWIleCallStruct) + 16 ];
  static arg_type_t SQLGetDiagFieldWIleSigStruct[] = { ARG_INT16, ARG_INT32, ARG_INT16, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_END };
  arglist = (SQLGetDiagFieldWIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLGetDiagFieldWBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLGetDiagFieldWLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLGetDiagFieldW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetDiagFieldWLoaded = 1;
  }
  arglist->hType = (SQLSMALLINT) hType;
  arglist->hndl = (SQLINTEGER) hndl;
  arglist->rcdNum = (SQLSMALLINT) rcdNum;
  arglist->diagID = (SQLSMALLINT) diagID;
  arglist->dValue.s.addr = (ulong) dValue;
  arglist->bLength = (SQLSMALLINT) bLength;
  arglist->sLength.s.addr = (ulong) sLength;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLGetDiagFieldWIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLGetDiagRec( SQLSMALLINT  hType, SQLINTEGER  hndl, SQLSMALLINT  rcdNum, SQLCHAR * SQLstate, SQLINTEGER * SQLcode, SQLCHAR * msgText, SQLSMALLINT  bLength, SQLSMALLINT * SLength )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLGetDiagRecIleCallStruct * arglist = (SQLGetDiagRecIleCallStruct *) NULL;
  char buffer[ sizeof(SQLGetDiagRecIleCallStruct) + 16 ];
  static arg_type_t SQLGetDiagRecIleSigStruct[] = { ARG_INT16, ARG_INT32, ARG_INT16, ARG_MEMPTR, ARG_MEMPTR, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_END };
  arglist = (SQLGetDiagRecIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLGetDiagRecBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLGetDiagRecLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLGetDiagRec");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetDiagRecLoaded = 1;
  }
  arglist->hType = (SQLSMALLINT) hType;
  arglist->hndl = (SQLINTEGER) hndl;
  arglist->rcdNum = (SQLSMALLINT) rcdNum;
  arglist->SQLstate.s.addr = (ulong) SQLstate;
  arglist->SQLcode.s.addr = (ulong) SQLcode;
  arglist->msgText.s.addr = (ulong) msgText;
  arglist->bLength = (SQLSMALLINT) bLength;
  arglist->SLength.s.addr = (ulong) SLength;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLGetDiagRecIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLGetDiagRecW( SQLSMALLINT  hType, SQLINTEGER  hndl, SQLSMALLINT  rcdNum, SQLWCHAR * SQLstate, SQLINTEGER * SQLcode, SQLWCHAR * msgText, SQLSMALLINT  bLength, SQLSMALLINT * SLength )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLGetDiagRecWIleCallStruct * arglist = (SQLGetDiagRecWIleCallStruct *) NULL;
  char buffer[ sizeof(SQLGetDiagRecWIleCallStruct) + 16 ];
  static arg_type_t SQLGetDiagRecWIleSigStruct[] = { ARG_INT16, ARG_INT32, ARG_INT16, ARG_MEMPTR, ARG_MEMPTR, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_END };
  arglist = (SQLGetDiagRecWIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLGetDiagRecWBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLGetDiagRecWLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLGetDiagRecW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetDiagRecWLoaded = 1;
  }
  arglist->hType = (SQLSMALLINT) hType;
  arglist->hndl = (SQLINTEGER) hndl;
  arglist->rcdNum = (SQLSMALLINT) rcdNum;
  arglist->SQLstate.s.addr = (ulong) SQLstate;
  arglist->SQLcode.s.addr = (ulong) SQLcode;
  arglist->msgText.s.addr = (ulong) msgText;
  arglist->bLength = (SQLSMALLINT) bLength;
  arglist->SLength.s.addr = (ulong) SLength;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLGetDiagRecWIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLGetEnvAttr( SQLHENV  hEnv, SQLINTEGER  fAttribute, SQLPOINTER  pParam, SQLINTEGER  cbParamMax, SQLINTEGER * pcbParam )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLGetEnvAttrIleCallStruct * arglist = (SQLGetEnvAttrIleCallStruct *) NULL;
  char buffer[ sizeof(SQLGetEnvAttrIleCallStruct) + 16 ];
  static arg_type_t SQLGetEnvAttrIleSigStruct[] = { ARG_INT32, ARG_INT32, ARG_MEMPTR, ARG_INT32, ARG_MEMPTR, ARG_END };
  arglist = (SQLGetEnvAttrIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLGetEnvAttrBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLGetEnvAttrLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLGetEnvAttr");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetEnvAttrLoaded = 1;
  }
  arglist->hEnv = (SQLHENV) hEnv;
  arglist->fAttribute = (SQLINTEGER) fAttribute;
  arglist->pParam.s.addr = (ulong) pParam;
  arglist->cbParamMax = (SQLINTEGER) cbParamMax;
  arglist->pcbParam.s.addr = (ulong) pcbParam;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLGetEnvAttrIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLGetFunctions( SQLHDBC  hdbc, SQLSMALLINT  fFunction, SQLSMALLINT * pfExists )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLGetFunctionsIleCallStruct * arglist = (SQLGetFunctionsIleCallStruct *) NULL;
  char buffer[ sizeof(SQLGetFunctionsIleCallStruct) + 16 ];
  static arg_type_t SQLGetFunctionsIleSigStruct[] = { ARG_INT32, ARG_INT16, ARG_MEMPTR, ARG_END };
  arglist = (SQLGetFunctionsIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLGetFunctionsBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLGetFunctionsLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLGetFunctions");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetFunctionsLoaded = 1;
  }
  arglist->hdbc = (SQLHDBC) hdbc;
  arglist->fFunction = (SQLSMALLINT) fFunction;
  arglist->pfExists.s.addr = (ulong) pfExists;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLGetFunctionsIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLGetInfo( SQLHDBC  hdbc, SQLSMALLINT  fInfoType, SQLPOINTER  rgbInfoValue, SQLSMALLINT  cbInfoValueMax, SQLSMALLINT * pcbInfoValue )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLGetInfoIleCallStruct * arglist = (SQLGetInfoIleCallStruct *) NULL;
  char buffer[ sizeof(SQLGetInfoIleCallStruct) + 16 ];
  static arg_type_t SQLGetInfoIleSigStruct[] = { ARG_INT32, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_END };
  arglist = (SQLGetInfoIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLGetInfoBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLGetInfoLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLGetInfo");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetInfoLoaded = 1;
  }
  arglist->hdbc = (SQLHDBC) hdbc;
  arglist->fInfoType = (SQLSMALLINT) fInfoType;
  arglist->rgbInfoValue.s.addr = (ulong) rgbInfoValue;
  arglist->cbInfoValueMax = (SQLSMALLINT) cbInfoValueMax;
  arglist->pcbInfoValue.s.addr = (ulong) pcbInfoValue;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLGetInfoIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLGetInfoW( SQLHDBC  hdbc, SQLSMALLINT  fInfoType, SQLPOINTER  rgbInfoValue, SQLSMALLINT  cbInfoValueMax, SQLSMALLINT * pcbInfoValue )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLGetInfoWIleCallStruct * arglist = (SQLGetInfoWIleCallStruct *) NULL;
  char buffer[ sizeof(SQLGetInfoWIleCallStruct) + 16 ];
  static arg_type_t SQLGetInfoWIleSigStruct[] = { ARG_INT32, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_END };
  arglist = (SQLGetInfoWIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLGetInfoWBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLGetInfoWLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLGetInfoW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetInfoWLoaded = 1;
  }
  arglist->hdbc = (SQLHDBC) hdbc;
  arglist->fInfoType = (SQLSMALLINT) fInfoType;
  arglist->rgbInfoValue.s.addr = (ulong) rgbInfoValue;
  arglist->cbInfoValueMax = (SQLSMALLINT) cbInfoValueMax;
  arglist->pcbInfoValue.s.addr = (ulong) pcbInfoValue;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLGetInfoWIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLGetLength( SQLHSTMT  hstmt, SQLSMALLINT  locType, SQLINTEGER  locator, SQLINTEGER * sLength, SQLINTEGER * ind )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLGetLengthIleCallStruct * arglist = (SQLGetLengthIleCallStruct *) NULL;
  char buffer[ sizeof(SQLGetLengthIleCallStruct) + 16 ];
  static arg_type_t SQLGetLengthIleSigStruct[] = { ARG_INT32, ARG_INT16, ARG_INT32, ARG_MEMPTR, ARG_MEMPTR, ARG_END };
  arglist = (SQLGetLengthIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLGetLengthBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLGetLengthLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLGetLength");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetLengthLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->locType = (SQLSMALLINT) locType;
  arglist->locator = (SQLINTEGER) locator;
  arglist->sLength.s.addr = (ulong) sLength;
  arglist->ind.s.addr = (ulong) ind;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLGetLengthIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLGetPosition( SQLHSTMT  hstmt, SQLSMALLINT  locType, SQLINTEGER  srceLocator, SQLINTEGER  srchLocator, SQLCHAR * srchLiteral, SQLINTEGER  srchLiteralLen, SQLINTEGER  fPosition, SQLINTEGER * located, SQLINTEGER * ind )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLGetPositionIleCallStruct * arglist = (SQLGetPositionIleCallStruct *) NULL;
  char buffer[ sizeof(SQLGetPositionIleCallStruct) + 16 ];
  static arg_type_t SQLGetPositionIleSigStruct[] = { ARG_INT32, ARG_INT16, ARG_INT32, ARG_INT32, ARG_MEMPTR, ARG_INT32, ARG_INT32, ARG_MEMPTR, ARG_MEMPTR, ARG_END };
  arglist = (SQLGetPositionIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLGetPositionBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLGetPositionLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLGetPosition");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetPositionLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->locType = (SQLSMALLINT) locType;
  arglist->srceLocator = (SQLINTEGER) srceLocator;
  arglist->srchLocator = (SQLINTEGER) srchLocator;
  arglist->srchLiteral.s.addr = (ulong) srchLiteral;
  arglist->srchLiteralLen = (SQLINTEGER) srchLiteralLen;
  arglist->fPosition = (SQLINTEGER) fPosition;
  arglist->located.s.addr = (ulong) located;
  arglist->ind.s.addr = (ulong) ind;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLGetPositionIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLGetPositionW( SQLHSTMT  hstmt, SQLSMALLINT  locType, SQLINTEGER  srceLocator, SQLINTEGER  srchLocator, SQLWCHAR * srchLiteral, SQLINTEGER  srchLiteralLen, SQLINTEGER  fPosition, SQLINTEGER * located, SQLINTEGER * ind )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLGetPositionWIleCallStruct * arglist = (SQLGetPositionWIleCallStruct *) NULL;
  char buffer[ sizeof(SQLGetPositionWIleCallStruct) + 16 ];
  static arg_type_t SQLGetPositionWIleSigStruct[] = { ARG_INT32, ARG_INT16, ARG_INT32, ARG_INT32, ARG_MEMPTR, ARG_INT32, ARG_INT32, ARG_MEMPTR, ARG_MEMPTR, ARG_END };
  arglist = (SQLGetPositionWIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLGetPositionWBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLGetPositionWLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLGetPositionW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetPositionWLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->locType = (SQLSMALLINT) locType;
  arglist->srceLocator = (SQLINTEGER) srceLocator;
  arglist->srchLocator = (SQLINTEGER) srchLocator;
  arglist->srchLiteral.s.addr = (ulong) srchLiteral;
  arglist->srchLiteralLen = (SQLINTEGER) srchLiteralLen;
  arglist->fPosition = (SQLINTEGER) fPosition;
  arglist->located.s.addr = (ulong) located;
  arglist->ind.s.addr = (ulong) ind;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLGetPositionWIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLGetStmtAttr( SQLHSTMT  hstmt, SQLINTEGER  fAttr, SQLPOINTER  pvParam, SQLINTEGER  bLength, SQLINTEGER * SLength )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLGetStmtAttrIleCallStruct * arglist = (SQLGetStmtAttrIleCallStruct *) NULL;
  char buffer[ sizeof(SQLGetStmtAttrIleCallStruct) + 16 ];
  static arg_type_t SQLGetStmtAttrIleSigStruct[] = { ARG_INT32, ARG_INT32, ARG_MEMPTR, ARG_INT32, ARG_MEMPTR, ARG_END };
  arglist = (SQLGetStmtAttrIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLGetStmtAttrBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLGetStmtAttrLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLGetStmtAttr");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetStmtAttrLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->fAttr = (SQLINTEGER) fAttr;
  arglist->pvParam.s.addr = (ulong) pvParam;
  arglist->bLength = (SQLINTEGER) bLength;
  arglist->SLength.s.addr = (ulong) SLength;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLGetStmtAttrIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLGetStmtAttrW( SQLHSTMT  hstmt, SQLINTEGER  fAttr, SQLPOINTER  pvParam, SQLINTEGER  bLength, SQLINTEGER * SLength )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLGetStmtAttrWIleCallStruct * arglist = (SQLGetStmtAttrWIleCallStruct *) NULL;
  char buffer[ sizeof(SQLGetStmtAttrWIleCallStruct) + 16 ];
  static arg_type_t SQLGetStmtAttrWIleSigStruct[] = { ARG_INT32, ARG_INT32, ARG_MEMPTR, ARG_INT32, ARG_MEMPTR, ARG_END };
  arglist = (SQLGetStmtAttrWIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLGetStmtAttrWBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLGetStmtAttrWLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLGetStmtAttrW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetStmtAttrWLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->fAttr = (SQLINTEGER) fAttr;
  arglist->pvParam.s.addr = (ulong) pvParam;
  arglist->bLength = (SQLINTEGER) bLength;
  arglist->SLength.s.addr = (ulong) SLength;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLGetStmtAttrWIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLGetStmtOption( SQLHSTMT  hstmt, SQLSMALLINT  fOption, SQLPOINTER  pvParam )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLGetStmtOptionIleCallStruct * arglist = (SQLGetStmtOptionIleCallStruct *) NULL;
  char buffer[ sizeof(SQLGetStmtOptionIleCallStruct) + 16 ];
  static arg_type_t SQLGetStmtOptionIleSigStruct[] = { ARG_INT32, ARG_INT16, ARG_MEMPTR, ARG_END };
  arglist = (SQLGetStmtOptionIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLGetStmtOptionBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLGetStmtOptionLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLGetStmtOption");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetStmtOptionLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->fOption = (SQLSMALLINT) fOption;
  arglist->pvParam.s.addr = (ulong) pvParam;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLGetStmtOptionIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLGetStmtOptionW( SQLHSTMT  hstmt, SQLSMALLINT  fOption, SQLPOINTER  pvParam )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLGetStmtOptionWIleCallStruct * arglist = (SQLGetStmtOptionWIleCallStruct *) NULL;
  char buffer[ sizeof(SQLGetStmtOptionWIleCallStruct) + 16 ];
  static arg_type_t SQLGetStmtOptionWIleSigStruct[] = { ARG_INT32, ARG_INT16, ARG_MEMPTR, ARG_END };
  arglist = (SQLGetStmtOptionWIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLGetStmtOptionWBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLGetStmtOptionWLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLGetStmtOptionW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetStmtOptionWLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->fOption = (SQLSMALLINT) fOption;
  arglist->pvParam.s.addr = (ulong) pvParam;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLGetStmtOptionWIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLGetSubString( SQLHSTMT  hstmt, SQLSMALLINT  locType, SQLINTEGER  srceLocator, SQLINTEGER  fPosition, SQLINTEGER  length, SQLSMALLINT  tType, SQLPOINTER  rgbValue, SQLINTEGER  cbValueMax, SQLINTEGER * StringLength, SQLINTEGER * ind )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLGetSubStringIleCallStruct * arglist = (SQLGetSubStringIleCallStruct *) NULL;
  char buffer[ sizeof(SQLGetSubStringIleCallStruct) + 16 ];
  static arg_type_t SQLGetSubStringIleSigStruct[] = { ARG_INT32, ARG_INT16, ARG_INT32, ARG_INT32, ARG_INT32, ARG_INT16, ARG_MEMPTR, ARG_INT32, ARG_MEMPTR, ARG_MEMPTR, ARG_END };
  arglist = (SQLGetSubStringIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLGetSubStringBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLGetSubStringLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLGetSubString");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetSubStringLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->locType = (SQLSMALLINT) locType;
  arglist->srceLocator = (SQLINTEGER) srceLocator;
  arglist->fPosition = (SQLINTEGER) fPosition;
  arglist->length = (SQLINTEGER) length;
  arglist->tType = (SQLSMALLINT) tType;
  arglist->rgbValue.s.addr = (ulong) rgbValue;
  arglist->cbValueMax = (SQLINTEGER) cbValueMax;
  arglist->StringLength.s.addr = (ulong) StringLength;
  arglist->ind.s.addr = (ulong) ind;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLGetSubStringIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLGetSubStringW( SQLHSTMT  hstmt, SQLSMALLINT  locType, SQLINTEGER  srceLocator, SQLINTEGER  fPosition, SQLINTEGER  length, SQLSMALLINT  tType, SQLPOINTER  rgbValue, SQLINTEGER  cbValueMax, SQLINTEGER * StringLength, SQLINTEGER * ind )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLGetSubStringWIleCallStruct * arglist = (SQLGetSubStringWIleCallStruct *) NULL;
  char buffer[ sizeof(SQLGetSubStringWIleCallStruct) + 16 ];
  static arg_type_t SQLGetSubStringWIleSigStruct[] = { ARG_INT32, ARG_INT16, ARG_INT32, ARG_INT32, ARG_INT32, ARG_INT16, ARG_MEMPTR, ARG_INT32, ARG_MEMPTR, ARG_MEMPTR, ARG_END };
  arglist = (SQLGetSubStringWIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLGetSubStringWBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLGetSubStringWLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLGetSubStringW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetSubStringWLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->locType = (SQLSMALLINT) locType;
  arglist->srceLocator = (SQLINTEGER) srceLocator;
  arglist->fPosition = (SQLINTEGER) fPosition;
  arglist->length = (SQLINTEGER) length;
  arglist->tType = (SQLSMALLINT) tType;
  arglist->rgbValue.s.addr = (ulong) rgbValue;
  arglist->cbValueMax = (SQLINTEGER) cbValueMax;
  arglist->StringLength.s.addr = (ulong) StringLength;
  arglist->ind.s.addr = (ulong) ind;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLGetSubStringWIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLGetTypeInfo( SQLHSTMT  hstmt, SQLSMALLINT  fSqlType )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLGetTypeInfoIleCallStruct * arglist = (SQLGetTypeInfoIleCallStruct *) NULL;
  char buffer[ sizeof(SQLGetTypeInfoIleCallStruct) + 16 ];
  static arg_type_t SQLGetTypeInfoIleSigStruct[] = { ARG_INT32, ARG_INT16, ARG_END };
  arglist = (SQLGetTypeInfoIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLGetTypeInfoBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLGetTypeInfoLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLGetTypeInfo");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetTypeInfoLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->fSqlType = (SQLSMALLINT) fSqlType;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLGetTypeInfoIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLGetTypeInfoW( SQLHSTMT  hstmt, SQLSMALLINT  fSqlType )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLGetTypeInfoWIleCallStruct * arglist = (SQLGetTypeInfoWIleCallStruct *) NULL;
  char buffer[ sizeof(SQLGetTypeInfoWIleCallStruct) + 16 ];
  static arg_type_t SQLGetTypeInfoWIleSigStruct[] = { ARG_INT32, ARG_INT16, ARG_END };
  arglist = (SQLGetTypeInfoWIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLGetTypeInfoWBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLGetTypeInfoWLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLGetTypeInfoW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetTypeInfoWLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->fSqlType = (SQLSMALLINT) fSqlType;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLGetTypeInfoWIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLLanguages( SQLHSTMT  hstmt )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLLanguagesIleCallStruct * arglist = (SQLLanguagesIleCallStruct *) NULL;
  char buffer[ sizeof(SQLLanguagesIleCallStruct) + 16 ];
  static arg_type_t SQLLanguagesIleSigStruct[] = { ARG_INT32, ARG_END };
  arglist = (SQLLanguagesIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLLanguagesBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLLanguagesLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLLanguages");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLLanguagesLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLLanguagesIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLMoreResults( SQLHSTMT  hstmt )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLMoreResultsIleCallStruct * arglist = (SQLMoreResultsIleCallStruct *) NULL;
  char buffer[ sizeof(SQLMoreResultsIleCallStruct) + 16 ];
  static arg_type_t SQLMoreResultsIleSigStruct[] = { ARG_INT32, ARG_END };
  arglist = (SQLMoreResultsIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLMoreResultsBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLMoreResultsLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLMoreResults");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLMoreResultsLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLMoreResultsIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLNativeSql( SQLHDBC  hdbc, SQLCHAR * szSqlStrIn, SQLINTEGER  cbSqlStrIn, SQLCHAR * szSqlStr, SQLINTEGER  cbSqlStrMax, SQLINTEGER * pcbSqlStr )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLNativeSqlIleCallStruct * arglist = (SQLNativeSqlIleCallStruct *) NULL;
  char buffer[ sizeof(SQLNativeSqlIleCallStruct) + 16 ];
  static arg_type_t SQLNativeSqlIleSigStruct[] = { ARG_INT32, ARG_MEMPTR, ARG_INT32, ARG_MEMPTR, ARG_INT32, ARG_MEMPTR, ARG_END };
  arglist = (SQLNativeSqlIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLNativeSqlBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLNativeSqlLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLNativeSql");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLNativeSqlLoaded = 1;
  }
  arglist->hdbc = (SQLHDBC) hdbc;
  arglist->szSqlStrIn.s.addr = (ulong) szSqlStrIn;
  arglist->cbSqlStrIn = (SQLINTEGER) cbSqlStrIn;
  arglist->szSqlStr.s.addr = (ulong) szSqlStr;
  arglist->cbSqlStrMax = (SQLINTEGER) cbSqlStrMax;
  arglist->pcbSqlStr.s.addr = (ulong) pcbSqlStr;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLNativeSqlIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLNativeSqlW( SQLHDBC  hdbc, SQLWCHAR * szSqlStrIn, SQLINTEGER  cbSqlStrIn, SQLWCHAR * szSqlStr, SQLINTEGER  cbSqlStrMax, SQLINTEGER * pcbSqlStr )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLNativeSqlWIleCallStruct * arglist = (SQLNativeSqlWIleCallStruct *) NULL;
  char buffer[ sizeof(SQLNativeSqlWIleCallStruct) + 16 ];
  static arg_type_t SQLNativeSqlWIleSigStruct[] = { ARG_INT32, ARG_MEMPTR, ARG_INT32, ARG_MEMPTR, ARG_INT32, ARG_MEMPTR, ARG_END };
  arglist = (SQLNativeSqlWIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLNativeSqlWBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLNativeSqlWLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLNativeSqlW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLNativeSqlWLoaded = 1;
  }
  arglist->hdbc = (SQLHDBC) hdbc;
  arglist->szSqlStrIn.s.addr = (ulong) szSqlStrIn;
  arglist->cbSqlStrIn = (SQLINTEGER) cbSqlStrIn;
  arglist->szSqlStr.s.addr = (ulong) szSqlStr;
  arglist->cbSqlStrMax = (SQLINTEGER) cbSqlStrMax;
  arglist->pcbSqlStr.s.addr = (ulong) pcbSqlStr;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLNativeSqlWIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLNextResult( SQLHSTMT  hstmt, SQLHSTMT  hstmt2 )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLNextResultIleCallStruct * arglist = (SQLNextResultIleCallStruct *) NULL;
  char buffer[ sizeof(SQLNextResultIleCallStruct) + 16 ];
  static arg_type_t SQLNextResultIleSigStruct[] = { ARG_INT32, ARG_INT32, ARG_END };
  arglist = (SQLNextResultIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLNextResultBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLNextResultLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLNextResult");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLNextResultLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->hstmt2 = (SQLHSTMT) hstmt2;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLNextResultIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLNumParams( SQLHSTMT  hstmt, SQLSMALLINT * pcpar )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLNumParamsIleCallStruct * arglist = (SQLNumParamsIleCallStruct *) NULL;
  char buffer[ sizeof(SQLNumParamsIleCallStruct) + 16 ];
  static arg_type_t SQLNumParamsIleSigStruct[] = { ARG_INT32, ARG_MEMPTR, ARG_END };
  arglist = (SQLNumParamsIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLNumParamsBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLNumParamsLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLNumParams");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLNumParamsLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->pcpar.s.addr = (ulong) pcpar;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLNumParamsIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLNumResultCols( SQLHSTMT  hstmt, SQLSMALLINT * pccol )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLNumResultColsIleCallStruct * arglist = (SQLNumResultColsIleCallStruct *) NULL;
  char buffer[ sizeof(SQLNumResultColsIleCallStruct) + 16 ];
  static arg_type_t SQLNumResultColsIleSigStruct[] = { ARG_INT32, ARG_MEMPTR, ARG_END };
  arglist = (SQLNumResultColsIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLNumResultColsBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLNumResultColsLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLNumResultCols");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLNumResultColsLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->pccol.s.addr = (ulong) pccol;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLNumResultColsIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLParamData( SQLHSTMT  hstmt, SQLPOINTER * Value )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLParamDataIleCallStruct * arglist = (SQLParamDataIleCallStruct *) NULL;
  char buffer[ sizeof(SQLParamDataIleCallStruct) + 16 ];
  static arg_type_t SQLParamDataIleSigStruct[] = { ARG_INT32, ARG_MEMPTR, ARG_END };
  arglist = (SQLParamDataIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLParamDataBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLParamDataLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLParamData");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLParamDataLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->Value.s.addr = (ulong) Value;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLParamDataIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLParamOptions( SQLHSTMT  hstmt, SQLINTEGER  crow, SQLINTEGER * pirow )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLParamOptionsIleCallStruct * arglist = (SQLParamOptionsIleCallStruct *) NULL;
  char buffer[ sizeof(SQLParamOptionsIleCallStruct) + 16 ];
  static arg_type_t SQLParamOptionsIleSigStruct[] = { ARG_INT32, ARG_INT32, ARG_MEMPTR, ARG_END };
  arglist = (SQLParamOptionsIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLParamOptionsBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLParamOptionsLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLParamOptions");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLParamOptionsLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->crow = (SQLINTEGER) crow;
  arglist->pirow.s.addr = (ulong) pirow;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLParamOptionsIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLPrepare( SQLHSTMT  hstmt, SQLCHAR * szSqlStr, SQLINTEGER  cbSqlStr )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLPrepareIleCallStruct * arglist = (SQLPrepareIleCallStruct *) NULL;
  char buffer[ sizeof(SQLPrepareIleCallStruct) + 16 ];
  static arg_type_t SQLPrepareIleSigStruct[] = { ARG_INT32, ARG_MEMPTR, ARG_INT32, ARG_END };
  arglist = (SQLPrepareIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLPrepareBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLPrepareLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLPrepare");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLPrepareLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->szSqlStr.s.addr = (ulong) szSqlStr;
  arglist->cbSqlStr = (SQLINTEGER) cbSqlStr;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLPrepareIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLPrepareW( SQLHSTMT  hstmt, SQLWCHAR * szSqlStr, SQLINTEGER  cbSqlStr )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLPrepareWIleCallStruct * arglist = (SQLPrepareWIleCallStruct *) NULL;
  char buffer[ sizeof(SQLPrepareWIleCallStruct) + 16 ];
  static arg_type_t SQLPrepareWIleSigStruct[] = { ARG_INT32, ARG_MEMPTR, ARG_INT32, ARG_END };
  arglist = (SQLPrepareWIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLPrepareWBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLPrepareWLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLPrepareW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLPrepareWLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->szSqlStr.s.addr = (ulong) szSqlStr;
  arglist->cbSqlStr = (SQLINTEGER) cbSqlStr;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLPrepareWIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLPrimaryKeys( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLPrimaryKeysIleCallStruct * arglist = (SQLPrimaryKeysIleCallStruct *) NULL;
  char buffer[ sizeof(SQLPrimaryKeysIleCallStruct) + 16 ];
  static arg_type_t SQLPrimaryKeysIleSigStruct[] = { ARG_INT32, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_END };
  arglist = (SQLPrimaryKeysIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLPrimaryKeysBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLPrimaryKeysLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLPrimaryKeys");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLPrimaryKeysLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->szTableQualifier.s.addr = (ulong) szTableQualifier;
  arglist->cbTableQualifier = (SQLSMALLINT) cbTableQualifier;
  arglist->szTableOwner.s.addr = (ulong) szTableOwner;
  arglist->cbTableOwner = (SQLSMALLINT) cbTableOwner;
  arglist->szTableName.s.addr = (ulong) szTableName;
  arglist->cbTableName = (SQLSMALLINT) cbTableName;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLPrimaryKeysIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLPrimaryKeysW( SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLPrimaryKeysWIleCallStruct * arglist = (SQLPrimaryKeysWIleCallStruct *) NULL;
  char buffer[ sizeof(SQLPrimaryKeysWIleCallStruct) + 16 ];
  static arg_type_t SQLPrimaryKeysWIleSigStruct[] = { ARG_INT32, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_END };
  arglist = (SQLPrimaryKeysWIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLPrimaryKeysWBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLPrimaryKeysWLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLPrimaryKeysW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLPrimaryKeysWLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->szTableQualifier.s.addr = (ulong) szTableQualifier;
  arglist->cbTableQualifier = (SQLSMALLINT) cbTableQualifier;
  arglist->szTableOwner.s.addr = (ulong) szTableOwner;
  arglist->cbTableOwner = (SQLSMALLINT) cbTableOwner;
  arglist->szTableName.s.addr = (ulong) szTableName;
  arglist->cbTableName = (SQLSMALLINT) cbTableName;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLPrimaryKeysWIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLProcedureColumns( SQLHSTMT  hstmt, SQLCHAR * szProcQualifier, SQLSMALLINT  cbProcQualifier, SQLCHAR * szProcOwner, SQLSMALLINT  cbProcOwner, SQLCHAR * szProcName, SQLSMALLINT  cbProcName, SQLCHAR * szColumnName, SQLSMALLINT  cbColumnName )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLProcedureColumnsIleCallStruct * arglist = (SQLProcedureColumnsIleCallStruct *) NULL;
  char buffer[ sizeof(SQLProcedureColumnsIleCallStruct) + 16 ];
  static arg_type_t SQLProcedureColumnsIleSigStruct[] = { ARG_INT32, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_END };
  arglist = (SQLProcedureColumnsIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLProcedureColumnsBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLProcedureColumnsLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLProcedureColumns");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLProcedureColumnsLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->szProcQualifier.s.addr = (ulong) szProcQualifier;
  arglist->cbProcQualifier = (SQLSMALLINT) cbProcQualifier;
  arglist->szProcOwner.s.addr = (ulong) szProcOwner;
  arglist->cbProcOwner = (SQLSMALLINT) cbProcOwner;
  arglist->szProcName.s.addr = (ulong) szProcName;
  arglist->cbProcName = (SQLSMALLINT) cbProcName;
  arglist->szColumnName.s.addr = (ulong) szColumnName;
  arglist->cbColumnName = (SQLSMALLINT) cbColumnName;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLProcedureColumnsIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLProcedureColumnsW( SQLHSTMT  hstmt, SQLWCHAR * szProcQualifier, SQLSMALLINT  cbProcQualifier, SQLWCHAR * szProcOwner, SQLSMALLINT  cbProcOwner, SQLWCHAR * szProcName, SQLSMALLINT  cbProcName, SQLWCHAR * szColumnName, SQLSMALLINT  cbColumnName )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLProcedureColumnsWIleCallStruct * arglist = (SQLProcedureColumnsWIleCallStruct *) NULL;
  char buffer[ sizeof(SQLProcedureColumnsWIleCallStruct) + 16 ];
  static arg_type_t SQLProcedureColumnsWIleSigStruct[] = { ARG_INT32, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_END };
  arglist = (SQLProcedureColumnsWIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLProcedureColumnsWBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLProcedureColumnsWLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLProcedureColumnsW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLProcedureColumnsWLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->szProcQualifier.s.addr = (ulong) szProcQualifier;
  arglist->cbProcQualifier = (SQLSMALLINT) cbProcQualifier;
  arglist->szProcOwner.s.addr = (ulong) szProcOwner;
  arglist->cbProcOwner = (SQLSMALLINT) cbProcOwner;
  arglist->szProcName.s.addr = (ulong) szProcName;
  arglist->cbProcName = (SQLSMALLINT) cbProcName;
  arglist->szColumnName.s.addr = (ulong) szColumnName;
  arglist->cbColumnName = (SQLSMALLINT) cbColumnName;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLProcedureColumnsWIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLProcedures( SQLHSTMT  hstmt, SQLCHAR * szProcQualifier, SQLSMALLINT  cbProcQualifier, SQLCHAR * szProcOwner, SQLSMALLINT  cbProcOwner, SQLCHAR * szProcName, SQLSMALLINT  cbProcName )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLProceduresIleCallStruct * arglist = (SQLProceduresIleCallStruct *) NULL;
  char buffer[ sizeof(SQLProceduresIleCallStruct) + 16 ];
  static arg_type_t SQLProceduresIleSigStruct[] = { ARG_INT32, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_END };
  arglist = (SQLProceduresIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLProceduresBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLProceduresLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLProcedures");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLProceduresLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->szProcQualifier.s.addr = (ulong) szProcQualifier;
  arglist->cbProcQualifier = (SQLSMALLINT) cbProcQualifier;
  arglist->szProcOwner.s.addr = (ulong) szProcOwner;
  arglist->cbProcOwner = (SQLSMALLINT) cbProcOwner;
  arglist->szProcName.s.addr = (ulong) szProcName;
  arglist->cbProcName = (SQLSMALLINT) cbProcName;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLProceduresIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLProceduresW( SQLHSTMT  hstmt, SQLWCHAR * szProcQualifier, SQLSMALLINT  cbProcQualifier, SQLWCHAR * szProcOwner, SQLSMALLINT  cbProcOwner, SQLWCHAR * szProcName, SQLSMALLINT  cbProcName )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLProceduresWIleCallStruct * arglist = (SQLProceduresWIleCallStruct *) NULL;
  char buffer[ sizeof(SQLProceduresWIleCallStruct) + 16 ];
  static arg_type_t SQLProceduresWIleSigStruct[] = { ARG_INT32, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_END };
  arglist = (SQLProceduresWIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLProceduresWBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLProceduresWLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLProceduresW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLProceduresWLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->szProcQualifier.s.addr = (ulong) szProcQualifier;
  arglist->cbProcQualifier = (SQLSMALLINT) cbProcQualifier;
  arglist->szProcOwner.s.addr = (ulong) szProcOwner;
  arglist->cbProcOwner = (SQLSMALLINT) cbProcOwner;
  arglist->szProcName.s.addr = (ulong) szProcName;
  arglist->cbProcName = (SQLSMALLINT) cbProcName;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLProceduresWIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLPutData( SQLHSTMT  hstmt, SQLPOINTER  Data, SQLINTEGER  SLen )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLPutDataIleCallStruct * arglist = (SQLPutDataIleCallStruct *) NULL;
  char buffer[ sizeof(SQLPutDataIleCallStruct) + 16 ];
  static arg_type_t SQLPutDataIleSigStruct[] = { ARG_INT32, ARG_MEMPTR, ARG_INT32, ARG_END };
  arglist = (SQLPutDataIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLPutDataBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLPutDataLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLPutData");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLPutDataLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->Data.s.addr = (ulong) Data;
  arglist->SLen = (SQLINTEGER) SLen;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLPutDataIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLReleaseEnv( SQLHENV  henv )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLReleaseEnvIleCallStruct * arglist = (SQLReleaseEnvIleCallStruct *) NULL;
  char buffer[ sizeof(SQLReleaseEnvIleCallStruct) + 16 ];
  static arg_type_t SQLReleaseEnvIleSigStruct[] = { ARG_INT32, ARG_END };
  arglist = (SQLReleaseEnvIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLReleaseEnvBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLReleaseEnvLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLReleaseEnv");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLReleaseEnvLoaded = 1;
  }
  arglist->henv = (SQLHENV) henv;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLReleaseEnvIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLRowCount( SQLHSTMT  hstmt, SQLINTEGER * pcrow )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLRowCountIleCallStruct * arglist = (SQLRowCountIleCallStruct *) NULL;
  char buffer[ sizeof(SQLRowCountIleCallStruct) + 16 ];
  static arg_type_t SQLRowCountIleSigStruct[] = { ARG_INT32, ARG_MEMPTR, ARG_END };
  arglist = (SQLRowCountIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLRowCountBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLRowCountLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLRowCount");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLRowCountLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->pcrow.s.addr = (ulong) pcrow;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLRowCountIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLSetConnectAttr( SQLHDBC  hdbc, SQLINTEGER  attrib, SQLPOINTER  vParam, SQLINTEGER  inlen )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLSetConnectAttrIleCallStruct * arglist = (SQLSetConnectAttrIleCallStruct *) NULL;
  char buffer[ sizeof(SQLSetConnectAttrIleCallStruct) + 16 ];
  static arg_type_t SQLSetConnectAttrIleSigStruct[] = { ARG_INT32, ARG_INT32, ARG_MEMPTR, ARG_INT32, ARG_END };
  arglist = (SQLSetConnectAttrIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLSetConnectAttrBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLSetConnectAttrLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLSetConnectAttr");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLSetConnectAttrLoaded = 1;
  }
  arglist->hdbc = (SQLHDBC) hdbc;
  arglist->attrib = (SQLINTEGER) attrib;
  arglist->vParam.s.addr = (ulong) vParam;
  arglist->inlen = (SQLINTEGER) inlen;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLSetConnectAttrIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLSetConnectAttrW( SQLHDBC  hdbc, SQLINTEGER  attrib, SQLPOINTER  vParam, SQLINTEGER  inlen )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLSetConnectAttrWIleCallStruct * arglist = (SQLSetConnectAttrWIleCallStruct *) NULL;
  char buffer[ sizeof(SQLSetConnectAttrWIleCallStruct) + 16 ];
  static arg_type_t SQLSetConnectAttrWIleSigStruct[] = { ARG_INT32, ARG_INT32, ARG_MEMPTR, ARG_INT32, ARG_END };
  arglist = (SQLSetConnectAttrWIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLSetConnectAttrWBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLSetConnectAttrWLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLSetConnectAttrW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLSetConnectAttrWLoaded = 1;
  }
  arglist->hdbc = (SQLHDBC) hdbc;
  arglist->attrib = (SQLINTEGER) attrib;
  arglist->vParam.s.addr = (ulong) vParam;
  arglist->inlen = (SQLINTEGER) inlen;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLSetConnectAttrWIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLSetConnectOption( SQLHDBC  hdbc, SQLSMALLINT  fOption, SQLPOINTER  vParam )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLSetConnectOptionIleCallStruct * arglist = (SQLSetConnectOptionIleCallStruct *) NULL;
  char buffer[ sizeof(SQLSetConnectOptionIleCallStruct) + 16 ];
  static arg_type_t SQLSetConnectOptionIleSigStruct[] = { ARG_INT32, ARG_INT16, ARG_MEMPTR, ARG_END };
  arglist = (SQLSetConnectOptionIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLSetConnectOptionBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLSetConnectOptionLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLSetConnectOption");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLSetConnectOptionLoaded = 1;
  }
  arglist->hdbc = (SQLHDBC) hdbc;
  arglist->fOption = (SQLSMALLINT) fOption;
  arglist->vParam.s.addr = (ulong) vParam;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLSetConnectOptionIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLSetConnectOptionW( SQLHDBC  hdbc, SQLSMALLINT  fOption, SQLPOINTER  vParam )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLSetConnectOptionWIleCallStruct * arglist = (SQLSetConnectOptionWIleCallStruct *) NULL;
  char buffer[ sizeof(SQLSetConnectOptionWIleCallStruct) + 16 ];
  static arg_type_t SQLSetConnectOptionWIleSigStruct[] = { ARG_INT32, ARG_INT16, ARG_MEMPTR, ARG_END };
  arglist = (SQLSetConnectOptionWIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLSetConnectOptionWBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLSetConnectOptionWLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLSetConnectOptionW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLSetConnectOptionWLoaded = 1;
  }
  arglist->hdbc = (SQLHDBC) hdbc;
  arglist->fOption = (SQLSMALLINT) fOption;
  arglist->vParam.s.addr = (ulong) vParam;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLSetConnectOptionWIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLSetCursorName( SQLHSTMT  hstmt, SQLCHAR * szCursor, SQLSMALLINT  cbCursor )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLSetCursorNameIleCallStruct * arglist = (SQLSetCursorNameIleCallStruct *) NULL;
  char buffer[ sizeof(SQLSetCursorNameIleCallStruct) + 16 ];
  static arg_type_t SQLSetCursorNameIleSigStruct[] = { ARG_INT32, ARG_MEMPTR, ARG_INT16, ARG_END };
  arglist = (SQLSetCursorNameIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLSetCursorNameBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLSetCursorNameLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLSetCursorName");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLSetCursorNameLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->szCursor.s.addr = (ulong) szCursor;
  arglist->cbCursor = (SQLSMALLINT) cbCursor;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLSetCursorNameIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLSetCursorNameW( SQLHSTMT  hstmt, SQLWCHAR * szCursor, SQLSMALLINT  cbCursor )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLSetCursorNameWIleCallStruct * arglist = (SQLSetCursorNameWIleCallStruct *) NULL;
  char buffer[ sizeof(SQLSetCursorNameWIleCallStruct) + 16 ];
  static arg_type_t SQLSetCursorNameWIleSigStruct[] = { ARG_INT32, ARG_MEMPTR, ARG_INT16, ARG_END };
  arglist = (SQLSetCursorNameWIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLSetCursorNameWBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLSetCursorNameWLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLSetCursorNameW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLSetCursorNameWLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->szCursor.s.addr = (ulong) szCursor;
  arglist->cbCursor = (SQLSMALLINT) cbCursor;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLSetCursorNameWIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLSetDescField( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  fID, SQLPOINTER  Value, SQLINTEGER  buffLen )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLSetDescFieldIleCallStruct * arglist = (SQLSetDescFieldIleCallStruct *) NULL;
  char buffer[ sizeof(SQLSetDescFieldIleCallStruct) + 16 ];
  static arg_type_t SQLSetDescFieldIleSigStruct[] = { ARG_INT32, ARG_INT16, ARG_INT16, ARG_MEMPTR, ARG_INT32, ARG_END };
  arglist = (SQLSetDescFieldIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLSetDescFieldBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLSetDescFieldLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLSetDescField");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLSetDescFieldLoaded = 1;
  }
  arglist->hdesc = (SQLHDESC) hdesc;
  arglist->rcdNum = (SQLSMALLINT) rcdNum;
  arglist->fID = (SQLSMALLINT) fID;
  arglist->Value.s.addr = (ulong) Value;
  arglist->buffLen = (SQLINTEGER) buffLen;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLSetDescFieldIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLSetDescFieldW( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  fID, SQLPOINTER  Value, SQLINTEGER  buffLen )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLSetDescFieldWIleCallStruct * arglist = (SQLSetDescFieldWIleCallStruct *) NULL;
  char buffer[ sizeof(SQLSetDescFieldWIleCallStruct) + 16 ];
  static arg_type_t SQLSetDescFieldWIleSigStruct[] = { ARG_INT32, ARG_INT16, ARG_INT16, ARG_MEMPTR, ARG_INT32, ARG_END };
  arglist = (SQLSetDescFieldWIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLSetDescFieldWBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLSetDescFieldWLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLSetDescFieldW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLSetDescFieldWLoaded = 1;
  }
  arglist->hdesc = (SQLHDESC) hdesc;
  arglist->rcdNum = (SQLSMALLINT) rcdNum;
  arglist->fID = (SQLSMALLINT) fID;
  arglist->Value.s.addr = (ulong) Value;
  arglist->buffLen = (SQLINTEGER) buffLen;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLSetDescFieldWIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLSetDescRec( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  Type, SQLSMALLINT  subType, SQLINTEGER  fLength, SQLSMALLINT  fPrec, SQLSMALLINT  fScale, SQLPOINTER  Value, SQLINTEGER * sLength, SQLINTEGER * indic )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLSetDescRecIleCallStruct * arglist = (SQLSetDescRecIleCallStruct *) NULL;
  char buffer[ sizeof(SQLSetDescRecIleCallStruct) + 16 ];
  static arg_type_t SQLSetDescRecIleSigStruct[] = { ARG_INT32, ARG_INT16, ARG_INT16, ARG_INT16, ARG_INT32, ARG_INT16, ARG_INT16, ARG_MEMPTR, ARG_MEMPTR, ARG_MEMPTR, ARG_END };
  arglist = (SQLSetDescRecIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLSetDescRecBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLSetDescRecLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLSetDescRec");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLSetDescRecLoaded = 1;
  }
  arglist->hdesc = (SQLHDESC) hdesc;
  arglist->rcdNum = (SQLSMALLINT) rcdNum;
  arglist->Type = (SQLSMALLINT) Type;
  arglist->subType = (SQLSMALLINT) subType;
  arglist->fLength = (SQLINTEGER) fLength;
  arglist->fPrec = (SQLSMALLINT) fPrec;
  arglist->fScale = (SQLSMALLINT) fScale;
  arglist->Value.s.addr = (ulong) Value;
  arglist->sLength.s.addr = (ulong) sLength;
  arglist->indic.s.addr = (ulong) indic;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLSetDescRecIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLSetEnvAttr( SQLHENV  hEnv, SQLINTEGER  fAttribute, SQLPOINTER  pParam, SQLINTEGER  cbParam )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLSetEnvAttrIleCallStruct * arglist = (SQLSetEnvAttrIleCallStruct *) NULL;
  char buffer[ sizeof(SQLSetEnvAttrIleCallStruct) + 16 ];
  static arg_type_t SQLSetEnvAttrIleSigStruct[] = { ARG_INT32, ARG_INT32, ARG_MEMPTR, ARG_INT32, ARG_END };
  arglist = (SQLSetEnvAttrIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLSetEnvAttrBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLSetEnvAttrLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLSetEnvAttr");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLSetEnvAttrLoaded = 1;
  }
  arglist->hEnv = (SQLHENV) hEnv;
  arglist->fAttribute = (SQLINTEGER) fAttribute;
  arglist->pParam.s.addr = (ulong) pParam;
  arglist->cbParam = (SQLINTEGER) cbParam;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLSetEnvAttrIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLSetParam( SQLHSTMT  hstmt, SQLSMALLINT  ipar, SQLSMALLINT  fCType, SQLSMALLINT  fSqlType, SQLINTEGER  cbColDef, SQLSMALLINT  ibScale, SQLPOINTER  rgbValue, SQLINTEGER * pcbValue )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLSetParamIleCallStruct * arglist = (SQLSetParamIleCallStruct *) NULL;
  char buffer[ sizeof(SQLSetParamIleCallStruct) + 16 ];
  static arg_type_t SQLSetParamIleSigStruct[] = { ARG_INT32, ARG_INT16, ARG_INT16, ARG_INT16, ARG_INT32, ARG_INT16, ARG_MEMPTR, ARG_MEMPTR, ARG_END };
  arglist = (SQLSetParamIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLSetParamBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLSetParamLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLSetParam");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLSetParamLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->ipar = (SQLSMALLINT) ipar;
  arglist->fCType = (SQLSMALLINT) fCType;
  arglist->fSqlType = (SQLSMALLINT) fSqlType;
  arglist->cbColDef = (SQLINTEGER) cbColDef;
  arglist->ibScale = (SQLSMALLINT) ibScale;
  arglist->rgbValue.s.addr = (ulong) rgbValue;
  arglist->pcbValue.s.addr = (ulong) pcbValue;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLSetParamIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLSetStmtAttr( SQLHSTMT  hstmt, SQLINTEGER  fAttr, SQLPOINTER  pParam, SQLINTEGER  vParam )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLSetStmtAttrIleCallStruct * arglist = (SQLSetStmtAttrIleCallStruct *) NULL;
  char buffer[ sizeof(SQLSetStmtAttrIleCallStruct) + 16 ];
  static arg_type_t SQLSetStmtAttrIleSigStruct[] = { ARG_INT32, ARG_INT32, ARG_MEMPTR, ARG_INT32, ARG_END };
  arglist = (SQLSetStmtAttrIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLSetStmtAttrBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLSetStmtAttrLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLSetStmtAttr");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLSetStmtAttrLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->fAttr = (SQLINTEGER) fAttr;
  arglist->pParam.s.addr = (ulong) pParam;
  arglist->vParam = (SQLINTEGER) vParam;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLSetStmtAttrIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLSetStmtAttrW( SQLHSTMT  hstmt, SQLINTEGER  fAttr, SQLPOINTER  pParam, SQLINTEGER  vParam )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLSetStmtAttrWIleCallStruct * arglist = (SQLSetStmtAttrWIleCallStruct *) NULL;
  char buffer[ sizeof(SQLSetStmtAttrWIleCallStruct) + 16 ];
  static arg_type_t SQLSetStmtAttrWIleSigStruct[] = { ARG_INT32, ARG_INT32, ARG_MEMPTR, ARG_INT32, ARG_END };
  arglist = (SQLSetStmtAttrWIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLSetStmtAttrWBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLSetStmtAttrWLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLSetStmtAttrW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLSetStmtAttrWLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->fAttr = (SQLINTEGER) fAttr;
  arglist->pParam.s.addr = (ulong) pParam;
  arglist->vParam = (SQLINTEGER) vParam;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLSetStmtAttrWIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLSetStmtOption( SQLHSTMT  hstmt, SQLSMALLINT  fOption, SQLPOINTER  vParam )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLSetStmtOptionIleCallStruct * arglist = (SQLSetStmtOptionIleCallStruct *) NULL;
  char buffer[ sizeof(SQLSetStmtOptionIleCallStruct) + 16 ];
  static arg_type_t SQLSetStmtOptionIleSigStruct[] = { ARG_INT32, ARG_INT16, ARG_MEMPTR, ARG_END };
  arglist = (SQLSetStmtOptionIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLSetStmtOptionBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLSetStmtOptionLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLSetStmtOption");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLSetStmtOptionLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->fOption = (SQLSMALLINT) fOption;
  arglist->vParam.s.addr = (ulong) vParam;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLSetStmtOptionIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLSetStmtOptionW( SQLHSTMT  hstmt, SQLSMALLINT  fOption, SQLPOINTER  vParam )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLSetStmtOptionWIleCallStruct * arglist = (SQLSetStmtOptionWIleCallStruct *) NULL;
  char buffer[ sizeof(SQLSetStmtOptionWIleCallStruct) + 16 ];
  static arg_type_t SQLSetStmtOptionWIleSigStruct[] = { ARG_INT32, ARG_INT16, ARG_MEMPTR, ARG_END };
  arglist = (SQLSetStmtOptionWIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLSetStmtOptionWBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLSetStmtOptionWLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLSetStmtOptionW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLSetStmtOptionWLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->fOption = (SQLSMALLINT) fOption;
  arglist->vParam.s.addr = (ulong) vParam;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLSetStmtOptionWIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLSpecialColumns( SQLHSTMT  hstmt, SQLSMALLINT  fColType, SQLCHAR * szTableQual, SQLSMALLINT  cbTableQual, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLSMALLINT  fScope, SQLSMALLINT  fNullable )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLSpecialColumnsIleCallStruct * arglist = (SQLSpecialColumnsIleCallStruct *) NULL;
  char buffer[ sizeof(SQLSpecialColumnsIleCallStruct) + 16 ];
  static arg_type_t SQLSpecialColumnsIleSigStruct[] = { ARG_INT32, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_INT16, ARG_INT16, ARG_END };
  arglist = (SQLSpecialColumnsIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLSpecialColumnsBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLSpecialColumnsLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLSpecialColumns");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLSpecialColumnsLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->fColType = (SQLSMALLINT) fColType;
  arglist->szTableQual.s.addr = (ulong) szTableQual;
  arglist->cbTableQual = (SQLSMALLINT) cbTableQual;
  arglist->szTableOwner.s.addr = (ulong) szTableOwner;
  arglist->cbTableOwner = (SQLSMALLINT) cbTableOwner;
  arglist->szTableName.s.addr = (ulong) szTableName;
  arglist->cbTableName = (SQLSMALLINT) cbTableName;
  arglist->fScope = (SQLSMALLINT) fScope;
  arglist->fNullable = (SQLSMALLINT) fNullable;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLSpecialColumnsIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLSpecialColumnsW( SQLHSTMT  hstmt, SQLSMALLINT  fColType, SQLWCHAR * szTableQual, SQLSMALLINT  cbTableQual, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName, SQLSMALLINT  fScope, SQLSMALLINT  fNullable )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLSpecialColumnsWIleCallStruct * arglist = (SQLSpecialColumnsWIleCallStruct *) NULL;
  char buffer[ sizeof(SQLSpecialColumnsWIleCallStruct) + 16 ];
  static arg_type_t SQLSpecialColumnsWIleSigStruct[] = { ARG_INT32, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_INT16, ARG_INT16, ARG_END };
  arglist = (SQLSpecialColumnsWIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLSpecialColumnsWBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLSpecialColumnsWLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLSpecialColumnsW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLSpecialColumnsWLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->fColType = (SQLSMALLINT) fColType;
  arglist->szTableQual.s.addr = (ulong) szTableQual;
  arglist->cbTableQual = (SQLSMALLINT) cbTableQual;
  arglist->szTableOwner.s.addr = (ulong) szTableOwner;
  arglist->cbTableOwner = (SQLSMALLINT) cbTableOwner;
  arglist->szTableName.s.addr = (ulong) szTableName;
  arglist->cbTableName = (SQLSMALLINT) cbTableName;
  arglist->fScope = (SQLSMALLINT) fScope;
  arglist->fNullable = (SQLSMALLINT) fNullable;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLSpecialColumnsWIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLStartTran( SQLSMALLINT  htype, SQLHENV  henv, SQLINTEGER  mode, SQLINTEGER  clevel )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLStartTranIleCallStruct * arglist = (SQLStartTranIleCallStruct *) NULL;
  char buffer[ sizeof(SQLStartTranIleCallStruct) + 16 ];
  static arg_type_t SQLStartTranIleSigStruct[] = { ARG_INT16, ARG_INT32, ARG_INT32, ARG_INT32, ARG_END };
  arglist = (SQLStartTranIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLStartTranBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLStartTranLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLStartTran");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLStartTranLoaded = 1;
  }
  arglist->htype = (SQLSMALLINT) htype;
  arglist->henv = (SQLHENV) henv;
  arglist->mode = (SQLINTEGER) mode;
  arglist->clevel = (SQLINTEGER) clevel;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLStartTranIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLStatistics( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLSMALLINT  fUnique, SQLSMALLINT  fres )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLStatisticsIleCallStruct * arglist = (SQLStatisticsIleCallStruct *) NULL;
  char buffer[ sizeof(SQLStatisticsIleCallStruct) + 16 ];
  static arg_type_t SQLStatisticsIleSigStruct[] = { ARG_INT32, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_INT16, ARG_INT16, ARG_END };
  arglist = (SQLStatisticsIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLStatisticsBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLStatisticsLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLStatistics");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLStatisticsLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->szTableQualifier.s.addr = (ulong) szTableQualifier;
  arglist->cbTableQualifier = (SQLSMALLINT) cbTableQualifier;
  arglist->szTableOwner.s.addr = (ulong) szTableOwner;
  arglist->cbTableOwner = (SQLSMALLINT) cbTableOwner;
  arglist->szTableName.s.addr = (ulong) szTableName;
  arglist->cbTableName = (SQLSMALLINT) cbTableName;
  arglist->fUnique = (SQLSMALLINT) fUnique;
  arglist->fres = (SQLSMALLINT) fres;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLStatisticsIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLStatisticsW( SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName, SQLSMALLINT  fUnique, SQLSMALLINT  fres )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLStatisticsWIleCallStruct * arglist = (SQLStatisticsWIleCallStruct *) NULL;
  char buffer[ sizeof(SQLStatisticsWIleCallStruct) + 16 ];
  static arg_type_t SQLStatisticsWIleSigStruct[] = { ARG_INT32, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_INT16, ARG_INT16, ARG_END };
  arglist = (SQLStatisticsWIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLStatisticsWBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLStatisticsWLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLStatisticsW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLStatisticsWLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->szTableQualifier.s.addr = (ulong) szTableQualifier;
  arglist->cbTableQualifier = (SQLSMALLINT) cbTableQualifier;
  arglist->szTableOwner.s.addr = (ulong) szTableOwner;
  arglist->cbTableOwner = (SQLSMALLINT) cbTableOwner;
  arglist->szTableName.s.addr = (ulong) szTableName;
  arglist->cbTableName = (SQLSMALLINT) cbTableName;
  arglist->fUnique = (SQLSMALLINT) fUnique;
  arglist->fres = (SQLSMALLINT) fres;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLStatisticsWIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLTablePrivileges( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLTablePrivilegesIleCallStruct * arglist = (SQLTablePrivilegesIleCallStruct *) NULL;
  char buffer[ sizeof(SQLTablePrivilegesIleCallStruct) + 16 ];
  static arg_type_t SQLTablePrivilegesIleSigStruct[] = { ARG_INT32, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_END };
  arglist = (SQLTablePrivilegesIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLTablePrivilegesBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLTablePrivilegesLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLTablePrivileges");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLTablePrivilegesLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->szTableQualifier.s.addr = (ulong) szTableQualifier;
  arglist->cbTableQualifier = (SQLSMALLINT) cbTableQualifier;
  arglist->szTableOwner.s.addr = (ulong) szTableOwner;
  arglist->cbTableOwner = (SQLSMALLINT) cbTableOwner;
  arglist->szTableName.s.addr = (ulong) szTableName;
  arglist->cbTableName = (SQLSMALLINT) cbTableName;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLTablePrivilegesIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLTablePrivilegesW( SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLTablePrivilegesWIleCallStruct * arglist = (SQLTablePrivilegesWIleCallStruct *) NULL;
  char buffer[ sizeof(SQLTablePrivilegesWIleCallStruct) + 16 ];
  static arg_type_t SQLTablePrivilegesWIleSigStruct[] = { ARG_INT32, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_END };
  arglist = (SQLTablePrivilegesWIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLTablePrivilegesWBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLTablePrivilegesWLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLTablePrivilegesW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLTablePrivilegesWLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->szTableQualifier.s.addr = (ulong) szTableQualifier;
  arglist->cbTableQualifier = (SQLSMALLINT) cbTableQualifier;
  arglist->szTableOwner.s.addr = (ulong) szTableOwner;
  arglist->cbTableOwner = (SQLSMALLINT) cbTableOwner;
  arglist->szTableName.s.addr = (ulong) szTableName;
  arglist->cbTableName = (SQLSMALLINT) cbTableName;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLTablePrivilegesWIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLTables( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLCHAR * szTableType, SQLSMALLINT  cbTableType )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLTablesIleCallStruct * arglist = (SQLTablesIleCallStruct *) NULL;
  char buffer[ sizeof(SQLTablesIleCallStruct) + 16 ];
  static arg_type_t SQLTablesIleSigStruct[] = { ARG_INT32, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_END };
  arglist = (SQLTablesIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLTablesBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLTablesLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLTables");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLTablesLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->szTableQualifier.s.addr = (ulong) szTableQualifier;
  arglist->cbTableQualifier = (SQLSMALLINT) cbTableQualifier;
  arglist->szTableOwner.s.addr = (ulong) szTableOwner;
  arglist->cbTableOwner = (SQLSMALLINT) cbTableOwner;
  arglist->szTableName.s.addr = (ulong) szTableName;
  arglist->cbTableName = (SQLSMALLINT) cbTableName;
  arglist->szTableType.s.addr = (ulong) szTableType;
  arglist->cbTableType = (SQLSMALLINT) cbTableType;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLTablesIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLTablesW( SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName, SQLWCHAR * szTableType, SQLSMALLINT  cbTableType )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLTablesWIleCallStruct * arglist = (SQLTablesWIleCallStruct *) NULL;
  char buffer[ sizeof(SQLTablesWIleCallStruct) + 16 ];
  static arg_type_t SQLTablesWIleSigStruct[] = { ARG_INT32, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_MEMPTR, ARG_INT16, ARG_END };
  arglist = (SQLTablesWIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLTablesWBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLTablesWLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLTablesW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLTablesWLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->szTableQualifier.s.addr = (ulong) szTableQualifier;
  arglist->cbTableQualifier = (SQLSMALLINT) cbTableQualifier;
  arglist->szTableOwner.s.addr = (ulong) szTableOwner;
  arglist->cbTableOwner = (SQLSMALLINT) cbTableOwner;
  arglist->szTableName.s.addr = (ulong) szTableName;
  arglist->cbTableName = (SQLSMALLINT) cbTableName;
  arglist->szTableType.s.addr = (ulong) szTableType;
  arglist->cbTableType = (SQLSMALLINT) cbTableType;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLTablesWIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}
SQLRETURN ILE_SQLTransact( SQLHENV  henv, SQLHDBC  hdbc, SQLSMALLINT  fType )
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  SQLTransactIleCallStruct * arglist = (SQLTransactIleCallStruct *) NULL;
  char buffer[ sizeof(SQLTransactIleCallStruct) + 16 ];
  static arg_type_t SQLTransactIleSigStruct[] = { ARG_INT32, ARG_INT32, ARG_INT16, ARG_END };
  arglist = (SQLTransactIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&SQLTransactBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = init_cli_srvpgm();
  if (!SQLTransactLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "SQLTransact");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLTransactLoaded = 1;
  }
  arglist->henv = (SQLHENV) henv;
  arglist->hdbc = (SQLHDBC) hdbc;
  arglist->fType = (SQLSMALLINT) fType;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, SQLTransactIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}

