#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dlfcn.h>
#include <sqlcli1.h>
#include <as400_types.h>
#include <as400_protos.h>
#include "PaseCliInit.h"
#include "PaseCliAsync.h"

int i_am_big_chicken_flag;
int db2_cli_srvpgm_mark;
#define DB2CLISRVPGM "QSYS/QSQCLI"
#define ROUND_QUAD(x) (((size_t)(x) + 0xf) & ~0xf)

/* ILE call                          */

SQLRETURN ILE_SQLAllocConnect( SQLHENV  henv, SQLHDBC * phdbc );
SQLRETURN ILE_SQLAllocEnv( SQLHENV * phenv );
SQLRETURN ILE_SQLAllocHandle( SQLSMALLINT  htype, SQLINTEGER  ihnd, SQLINTEGER * ohnd );
SQLRETURN ILE_SQLAllocStmt( SQLHDBC  hdbc, SQLHSTMT * phstmt );
SQLRETURN ILE_SQLBindCol( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  iType, SQLPOINTER  rgbValue, SQLINTEGER  cbValueMax, SQLINTEGER * pcbValue );
SQLRETURN ILE_SQLBindFileToCol( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLCHAR * fName, SQLSMALLINT * fNameLen, SQLINTEGER * fOptions, SQLSMALLINT  fValueMax, SQLINTEGER * sLen, SQLINTEGER * pcbValue );
SQLRETURN ILE_SQLBindFileToParam( SQLHSTMT  hstmt, SQLSMALLINT  ipar, SQLSMALLINT  iType, SQLCHAR * fName, SQLSMALLINT * fNameLen, SQLINTEGER * fOptions, SQLSMALLINT  fValueMax, SQLINTEGER * pcbValue );
SQLRETURN ILE_SQLBindParam( SQLHSTMT  hstmt, SQLSMALLINT  iparm, SQLSMALLINT  iType, SQLSMALLINT  pType, SQLINTEGER  pLen, SQLSMALLINT  pScale, SQLPOINTER  pData, SQLINTEGER * pcbValue );
SQLRETURN ILE_SQLBindParameter( SQLHSTMT  hstmt, SQLSMALLINT  ipar, SQLSMALLINT  fParamType, SQLSMALLINT  fCType, SQLSMALLINT  fSQLType, SQLINTEGER  pLen, SQLSMALLINT  pScale, SQLPOINTER  pData, SQLINTEGER  cbValueMax, SQLINTEGER * pcbValue );
SQLRETURN ILE_SQLCancel( SQLHSTMT  hstmt );
SQLRETURN ILE_SQLCloseCursor( SQLHSTMT  hstmt );
SQLRETURN ILE_SQLColAttribute( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fDescType, SQLPOINTER  rgbDesc, SQLSMALLINT  cbDescMax, SQLSMALLINT * pcbDesc, SQLPOINTER  pfDesc );
SQLRETURN ILE_SQLColAttributeW( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fDescType, SQLPOINTER  rgbDesc, SQLSMALLINT  cbDescMax, SQLSMALLINT * pcbDesc, SQLPOINTER  pfDesc );
SQLRETURN ILE_SQLColAttributes( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fDescType, SQLCHAR * rgbDesc, SQLINTEGER  cbDescMax, SQLINTEGER * pcbDesc, SQLINTEGER * pfDesc );
SQLRETURN ILE_SQLColAttributesW( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fDescType, SQLWCHAR * rgbDesc, SQLINTEGER  cbDescMax, SQLINTEGER * pcbDesc, SQLINTEGER * pfDesc );
SQLRETURN ILE_SQLColumnPrivileges( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLCHAR * szColumnName, SQLSMALLINT  cbColumnName );
SQLRETURN ILE_SQLColumnPrivilegesW( SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName, SQLWCHAR * szColumnName, SQLSMALLINT  cbColumnName );
SQLRETURN ILE_SQLColumns( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLCHAR * szColumnName, SQLSMALLINT  cbColumnName );
SQLRETURN ILE_SQLColumnsW( SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName, SQLWCHAR * szColumnName, SQLSMALLINT  cbColumnName );
SQLRETURN ILE_SQLConnect( SQLHDBC  hdbc, SQLCHAR * szDSN, SQLSMALLINT  cbDSN, SQLCHAR * szUID, SQLSMALLINT  cbUID, SQLCHAR * szAuthStr, SQLSMALLINT  cbAuthStr );
SQLRETURN ILE_SQLConnectW( SQLHDBC  hdbc, SQLWCHAR * szDSN, SQLSMALLINT  cbDSN, SQLWCHAR * szUID, SQLSMALLINT  cbUID, SQLWCHAR * szAuthStr, SQLSMALLINT  cbAuthStr );
SQLRETURN ILE_SQLCopyDesc( SQLHDESC  sDesc, SQLHDESC  tDesc );
SQLRETURN ILE_SQLDataSources( SQLHENV  henv, SQLSMALLINT  fDirection, SQLCHAR * szDSN, SQLSMALLINT  cbDSNMax, SQLSMALLINT * pcbDSN, SQLCHAR * szDescription, SQLSMALLINT  cbDescriptionMax, SQLSMALLINT * pcbDescription );
SQLRETURN ILE_SQLDataSourcesW( SQLHENV  henv, SQLSMALLINT  fDirection, SQLWCHAR * szDSN, SQLSMALLINT  cbDSNMax, SQLSMALLINT * pcbDSN, SQLWCHAR * szDescription, SQLSMALLINT  cbDescriptionMax, SQLSMALLINT * pcbDescription );
SQLRETURN ILE_SQLDescribeCol( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLCHAR * szColName, SQLSMALLINT  cbColNameMax, SQLSMALLINT * pcbColName, SQLSMALLINT * pfSqlType, SQLINTEGER * pcbColDef, SQLSMALLINT * pibScale, SQLSMALLINT * pfNullable );
SQLRETURN ILE_SQLDescribeColW( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLWCHAR * szColName, SQLSMALLINT  cbColNameMax, SQLSMALLINT * pcbColName, SQLSMALLINT * pfSqlType, SQLINTEGER * pcbColDef, SQLSMALLINT * pibScale, SQLSMALLINT * pfNullable );
SQLRETURN ILE_SQLDescribeParam( SQLHSTMT  hstmt, SQLSMALLINT  ipar, SQLSMALLINT * pfSqlType, SQLINTEGER * pcbColDef, SQLSMALLINT * pibScale, SQLSMALLINT * pfNullable );
SQLRETURN ILE_SQLDisconnect( SQLHDBC  hdbc );
SQLRETURN ILE_SQLDriverConnect( SQLHDBC  hdbc, SQLPOINTER  hwnd, SQLCHAR * szConnStrIn, SQLSMALLINT  cbConnStrin, SQLCHAR * szConnStrOut, SQLSMALLINT  cbConnStrOutMax, SQLSMALLINT * pcbConnStrOut, SQLSMALLINT  fDriverCompletion );
SQLRETURN ILE_SQLDriverConnectW( SQLHDBC  hdbc, SQLPOINTER  hwnd, SQLWCHAR * szConnStrIn, SQLSMALLINT  cbConnStrin, SQLWCHAR * szConnStrOut, SQLSMALLINT  cbConnStrOutMax, SQLSMALLINT * pcbConnStrOut, SQLSMALLINT  fDriverCompletion );
SQLRETURN ILE_SQLEndTran( SQLSMALLINT  htype, SQLHENV  henv, SQLSMALLINT  ctype );
SQLRETURN ILE_SQLError( SQLHENV  henv, SQLHDBC  hdbc, SQLHSTMT  hstmt, SQLCHAR * szSqlState, SQLINTEGER * pfNativeError, SQLCHAR * szErrorMsg, SQLSMALLINT  cbErrorMsgMax, SQLSMALLINT * pcbErrorMsg );
SQLRETURN ILE_SQLErrorW( SQLHENV  henv, SQLHDBC  hdbc, SQLHSTMT  hstmt, SQLWCHAR * szSqlState, SQLINTEGER * pfNativeError, SQLWCHAR * szErrorMsg, SQLSMALLINT  cbErrorMsgMax, SQLSMALLINT * pcbErrorMsg );
SQLRETURN ILE_SQLExecDirect( SQLHSTMT  hstmt, SQLCHAR * szSqlStr, SQLINTEGER  cbSqlStr );
SQLRETURN ILE_SQLExecDirectW( SQLHSTMT  hstmt, SQLWCHAR * szSqlStr, SQLINTEGER  cbSqlStr );
SQLRETURN ILE_SQLExecute( SQLHSTMT  hstmt );
SQLRETURN ILE_SQLExtendedFetch( SQLHSTMT  hstmt, SQLSMALLINT  fOrient, SQLINTEGER  fOffset, SQLINTEGER * pcrow, SQLSMALLINT * rgfRowStatus );
SQLRETURN ILE_SQLFetch( SQLHSTMT  hstmt );
SQLRETURN ILE_SQLFetchScroll( SQLHSTMT  hstmt, SQLSMALLINT  fOrient, SQLINTEGER  fOffset );
SQLRETURN ILE_SQLForeignKeys( SQLHSTMT  hstmt, SQLCHAR * szPkTableQualifier, SQLSMALLINT  cbPkTableQualifier, SQLCHAR * szPkTableOwner, SQLSMALLINT  cbPkTableOwner, SQLCHAR * szPkTableName, SQLSMALLINT  cbPkTableName, SQLCHAR * szFkTableQualifier, SQLSMALLINT  cbFkTableQualifier, SQLCHAR * szFkTableOwner, SQLSMALLINT  cbFkTableOwner, SQLCHAR * szFkTableName, SQLSMALLINT  cbFkTableName );
SQLRETURN ILE_SQLForeignKeysW( SQLHSTMT  hstmt, SQLWCHAR * szPkTableQualifier, SQLSMALLINT  cbPkTableQualifier, SQLWCHAR * szPkTableOwner, SQLSMALLINT  cbPkTableOwner, SQLWCHAR * szPkTableName, SQLSMALLINT  cbPkTableName, SQLWCHAR * szFkTableQualifier, SQLSMALLINT  cbFkTableQualifier, SQLWCHAR * szFkTableOwner, SQLSMALLINT  cbFkTableOwner, SQLWCHAR * szFkTableName, SQLSMALLINT  cbFkTableName );
SQLRETURN ILE_SQLFreeConnect( SQLHDBC  hdbc );
SQLRETURN ILE_SQLFreeEnv( SQLHENV  henv );
SQLRETURN ILE_SQLFreeStmt( SQLHSTMT  hstmt, SQLSMALLINT  fOption );
SQLRETURN ILE_SQLFreeHandle( SQLSMALLINT  htype, SQLINTEGER  hndl );
SQLRETURN ILE_SQLGetCol( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  itype, SQLPOINTER  tval, SQLINTEGER  blen, SQLINTEGER * olen );
SQLRETURN ILE_SQLGetColW( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  itype, SQLPOINTER  tval, SQLINTEGER  blen, SQLINTEGER * olen );
SQLRETURN ILE_SQLGetConnectAttr( SQLHDBC  hdbc, SQLINTEGER  attr, SQLPOINTER  oval, SQLINTEGER  ilen, SQLINTEGER * olen );
SQLRETURN ILE_SQLGetConnectAttrW( SQLHDBC  hdbc, SQLINTEGER  attr, SQLPOINTER  oval, SQLINTEGER  ilen, SQLINTEGER * olen );
SQLRETURN ILE_SQLGetConnectOption( SQLHDBC  hdbc, SQLSMALLINT  iopt, SQLPOINTER  oval );
SQLRETURN ILE_SQLGetConnectOptionW( SQLHDBC  hdbc, SQLSMALLINT  iopt, SQLPOINTER  oval );
SQLRETURN ILE_SQLGetCursorName( SQLHSTMT  hstmt, SQLCHAR * szCursor, SQLSMALLINT  cbCursorMax, SQLSMALLINT * pcbCursor );
SQLRETURN ILE_SQLGetCursorNameW( SQLHSTMT  hstmt, SQLWCHAR * szCursor, SQLSMALLINT  cbCursorMax, SQLSMALLINT * pcbCursor );
SQLRETURN ILE_SQLGetData( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fCType, SQLPOINTER  rgbValue, SQLINTEGER  cbValueMax, SQLINTEGER * pcbValue );
SQLRETURN ILE_SQLGetDescField( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  fieldID, SQLPOINTER  fValue, SQLINTEGER  fLength, SQLINTEGER * stLength );
SQLRETURN ILE_SQLGetDescFieldW( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  fieldID, SQLPOINTER  fValue, SQLINTEGER  fLength, SQLINTEGER * stLength );
SQLRETURN ILE_SQLGetDescRec( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLCHAR * fname, SQLSMALLINT  bufLen, SQLSMALLINT * sLength, SQLSMALLINT * sType, SQLSMALLINT * sbType, SQLINTEGER * fLength, SQLSMALLINT * fprec, SQLSMALLINT * fscale, SQLSMALLINT * fnull );
SQLRETURN ILE_SQLGetDescRecW( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLWCHAR * fname, SQLSMALLINT  bufLen, SQLSMALLINT * sLength, SQLSMALLINT * sType, SQLSMALLINT * sbType, SQLINTEGER * fLength, SQLSMALLINT * fprec, SQLSMALLINT * fscale, SQLSMALLINT * fnull );
SQLRETURN ILE_SQLGetDiagField( SQLSMALLINT  hType, SQLINTEGER  hndl, SQLSMALLINT  rcdNum, SQLSMALLINT  diagID, SQLPOINTER  dValue, SQLSMALLINT  bLength, SQLSMALLINT * sLength );
SQLRETURN ILE_SQLGetDiagFieldW( SQLSMALLINT  hType, SQLINTEGER  hndl, SQLSMALLINT  rcdNum, SQLSMALLINT  diagID, SQLPOINTER  dValue, SQLSMALLINT  bLength, SQLSMALLINT * sLength );
SQLRETURN ILE_SQLGetDiagRec( SQLSMALLINT  hType, SQLINTEGER  hndl, SQLSMALLINT  rcdNum, SQLCHAR * SQLstate, SQLINTEGER * SQLcode, SQLCHAR * msgText, SQLSMALLINT  bLength, SQLSMALLINT * SLength );
SQLRETURN ILE_SQLGetDiagRecW( SQLSMALLINT  hType, SQLINTEGER  hndl, SQLSMALLINT  rcdNum, SQLWCHAR * SQLstate, SQLINTEGER * SQLcode, SQLWCHAR * msgText, SQLSMALLINT  bLength, SQLSMALLINT * SLength );
SQLRETURN ILE_SQLGetEnvAttr( SQLHENV  hEnv, SQLINTEGER  fAttribute, SQLPOINTER  pParam, SQLINTEGER  cbParamMax, SQLINTEGER * pcbParam );
SQLRETURN ILE_SQLGetFunctions( SQLHDBC  hdbc, SQLSMALLINT  fFunction, SQLSMALLINT * pfExists );
SQLRETURN ILE_SQLGetInfo( SQLHDBC  hdbc, SQLSMALLINT  fInfoType, SQLPOINTER  rgbInfoValue, SQLSMALLINT  cbInfoValueMax, SQLSMALLINT * pcbInfoValue );
SQLRETURN ILE_SQLGetInfoW( SQLHDBC  hdbc, SQLSMALLINT  fInfoType, SQLPOINTER  rgbInfoValue, SQLSMALLINT  cbInfoValueMax, SQLSMALLINT * pcbInfoValue );
SQLRETURN ILE_SQLGetLength( SQLHSTMT  hstmt, SQLSMALLINT  locType, SQLINTEGER  locator, SQLINTEGER * sLength, SQLINTEGER * ind );
SQLRETURN ILE_SQLGetPosition( SQLHSTMT  hstmt, SQLSMALLINT  locType, SQLINTEGER  srceLocator, SQLINTEGER  srchLocator, SQLCHAR * srchLiteral, SQLINTEGER  srchLiteralLen, SQLINTEGER  fPosition, SQLINTEGER * located, SQLINTEGER * ind );
SQLRETURN ILE_SQLGetPositionW( SQLHSTMT  hstmt, SQLSMALLINT  locType, SQLINTEGER  srceLocator, SQLINTEGER  srchLocator, SQLWCHAR * srchLiteral, SQLINTEGER  srchLiteralLen, SQLINTEGER  fPosition, SQLINTEGER * located, SQLINTEGER * ind );
SQLRETURN ILE_SQLGetStmtAttr( SQLHSTMT  hstmt, SQLINTEGER  fAttr, SQLPOINTER  pvParam, SQLINTEGER  bLength, SQLINTEGER * SLength );
SQLRETURN ILE_SQLGetStmtAttrW( SQLHSTMT  hstmt, SQLINTEGER  fAttr, SQLPOINTER  pvParam, SQLINTEGER  bLength, SQLINTEGER * SLength );
SQLRETURN ILE_SQLGetStmtOption( SQLHSTMT  hstmt, SQLSMALLINT  fOption, SQLPOINTER  pvParam );
SQLRETURN ILE_SQLGetStmtOptionW( SQLHSTMT  hstmt, SQLSMALLINT  fOption, SQLPOINTER  pvParam );
SQLRETURN ILE_SQLGetSubString( SQLHSTMT  hstmt, SQLSMALLINT  locType, SQLINTEGER  srceLocator, SQLINTEGER  fPosition, SQLINTEGER  length, SQLSMALLINT  tType, SQLPOINTER  rgbValue, SQLINTEGER  cbValueMax, SQLINTEGER * StringLength, SQLINTEGER * ind );
SQLRETURN ILE_SQLGetSubStringW( SQLHSTMT  hstmt, SQLSMALLINT  locType, SQLINTEGER  srceLocator, SQLINTEGER  fPosition, SQLINTEGER  length, SQLSMALLINT  tType, SQLPOINTER  rgbValue, SQLINTEGER  cbValueMax, SQLINTEGER * StringLength, SQLINTEGER * ind );
SQLRETURN ILE_SQLGetTypeInfo( SQLHSTMT  hstmt, SQLSMALLINT  fSqlType );
SQLRETURN ILE_SQLGetTypeInfoW( SQLHSTMT  hstmt, SQLSMALLINT  fSqlType );
SQLRETURN ILE_SQLLanguages( SQLHSTMT  hstmt );
SQLRETURN ILE_SQLMoreResults( SQLHSTMT  hstmt );
SQLRETURN ILE_SQLNativeSql( SQLHDBC  hdbc, SQLCHAR * szSqlStrIn, SQLINTEGER  cbSqlStrIn, SQLCHAR * szSqlStr, SQLINTEGER  cbSqlStrMax, SQLINTEGER * pcbSqlStr );
SQLRETURN ILE_SQLNativeSqlW( SQLHDBC  hdbc, SQLWCHAR * szSqlStrIn, SQLINTEGER  cbSqlStrIn, SQLWCHAR * szSqlStr, SQLINTEGER  cbSqlStrMax, SQLINTEGER * pcbSqlStr );
SQLRETURN ILE_SQLNextResult( SQLHSTMT  hstmt, SQLHSTMT  hstmt2 );
SQLRETURN ILE_SQLNumParams( SQLHSTMT  hstmt, SQLSMALLINT * pcpar );
SQLRETURN ILE_SQLNumResultCols( SQLHSTMT  hstmt, SQLSMALLINT * pccol );
SQLRETURN ILE_SQLParamData( SQLHSTMT  hstmt, SQLPOINTER * Value );
SQLRETURN ILE_SQLParamOptions( SQLHSTMT  hstmt, SQLINTEGER  crow, SQLINTEGER * pirow );
SQLRETURN ILE_SQLPrepare( SQLHSTMT  hstmt, SQLCHAR * szSqlStr, SQLINTEGER  cbSqlStr );
SQLRETURN ILE_SQLPrepareW( SQLHSTMT  hstmt, SQLWCHAR * szSqlStr, SQLINTEGER  cbSqlStr );
SQLRETURN ILE_SQLPrimaryKeys( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName );
SQLRETURN ILE_SQLPrimaryKeysW( SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName );
SQLRETURN ILE_SQLProcedureColumns( SQLHSTMT  hstmt, SQLCHAR * szProcQualifier, SQLSMALLINT  cbProcQualifier, SQLCHAR * szProcOwner, SQLSMALLINT  cbProcOwner, SQLCHAR * szProcName, SQLSMALLINT  cbProcName, SQLCHAR * szColumnName, SQLSMALLINT  cbColumnName );
SQLRETURN ILE_SQLProcedureColumnsW( SQLHSTMT  hstmt, SQLWCHAR * szProcQualifier, SQLSMALLINT  cbProcQualifier, SQLWCHAR * szProcOwner, SQLSMALLINT  cbProcOwner, SQLWCHAR * szProcName, SQLSMALLINT  cbProcName, SQLWCHAR * szColumnName, SQLSMALLINT  cbColumnName );
SQLRETURN ILE_SQLProcedures( SQLHSTMT  hstmt, SQLCHAR * szProcQualifier, SQLSMALLINT  cbProcQualifier, SQLCHAR * szProcOwner, SQLSMALLINT  cbProcOwner, SQLCHAR * szProcName, SQLSMALLINT  cbProcName );
SQLRETURN ILE_SQLProceduresW( SQLHSTMT  hstmt, SQLWCHAR * szProcQualifier, SQLSMALLINT  cbProcQualifier, SQLWCHAR * szProcOwner, SQLSMALLINT  cbProcOwner, SQLWCHAR * szProcName, SQLSMALLINT  cbProcName );
SQLRETURN ILE_SQLPutData( SQLHSTMT  hstmt, SQLPOINTER  Data, SQLINTEGER  SLen );
SQLRETURN ILE_SQLReleaseEnv( SQLHENV  henv );
SQLRETURN ILE_SQLRowCount( SQLHSTMT  hstmt, SQLINTEGER * pcrow );
SQLRETURN ILE_SQLSetConnectAttr( SQLHDBC  hdbc, SQLINTEGER  attrib, SQLPOINTER  vParam, SQLINTEGER  inlen );
SQLRETURN ILE_SQLSetConnectAttrW( SQLHDBC  hdbc, SQLINTEGER  attrib, SQLPOINTER  vParam, SQLINTEGER  inlen );
SQLRETURN ILE_SQLSetConnectOption( SQLHDBC  hdbc, SQLSMALLINT  fOption, SQLPOINTER  vParam );
SQLRETURN ILE_SQLSetConnectOptionW( SQLHDBC  hdbc, SQLSMALLINT  fOption, SQLPOINTER  vParam );
SQLRETURN ILE_SQLSetCursorName( SQLHSTMT  hstmt, SQLCHAR * szCursor, SQLSMALLINT  cbCursor );
SQLRETURN ILE_SQLSetCursorNameW( SQLHSTMT  hstmt, SQLWCHAR * szCursor, SQLSMALLINT  cbCursor );
SQLRETURN ILE_SQLSetDescField( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  fID, SQLPOINTER  Value, SQLINTEGER  buffLen );
SQLRETURN ILE_SQLSetDescFieldW( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  fID, SQLPOINTER  Value, SQLINTEGER  buffLen );
SQLRETURN ILE_SQLSetDescRec( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  Type, SQLSMALLINT  subType, SQLINTEGER  fLength, SQLSMALLINT  fPrec, SQLSMALLINT  fScale, SQLPOINTER  Value, SQLINTEGER * sLength, SQLINTEGER * indic );
SQLRETURN ILE_SQLSetEnvAttr( SQLHENV  hEnv, SQLINTEGER  fAttribute, SQLPOINTER  pParam, SQLINTEGER  cbParam );
SQLRETURN ILE_SQLSetParam( SQLHSTMT  hstmt, SQLSMALLINT  ipar, SQLSMALLINT  fCType, SQLSMALLINT  fSqlType, SQLINTEGER  cbColDef, SQLSMALLINT  ibScale, SQLPOINTER  rgbValue, SQLINTEGER * pcbValue );
SQLRETURN ILE_SQLSetStmtAttr( SQLHSTMT  hstmt, SQLINTEGER  fAttr, SQLPOINTER  pParam, SQLINTEGER  vParam );
SQLRETURN ILE_SQLSetStmtAttrW( SQLHSTMT  hstmt, SQLINTEGER  fAttr, SQLPOINTER  pParam, SQLINTEGER  vParam );
SQLRETURN ILE_SQLSetStmtOption( SQLHSTMT  hstmt, SQLSMALLINT  fOption, SQLPOINTER  vParam );
SQLRETURN ILE_SQLSetStmtOptionW( SQLHSTMT  hstmt, SQLSMALLINT  fOption, SQLPOINTER  vParam );
SQLRETURN ILE_SQLSpecialColumns( SQLHSTMT  hstmt, SQLSMALLINT  fColType, SQLCHAR * szTableQual, SQLSMALLINT  cbTableQual, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLSMALLINT  fScope, SQLSMALLINT  fNullable );
SQLRETURN ILE_SQLSpecialColumnsW( SQLHSTMT  hstmt, SQLSMALLINT  fColType, SQLWCHAR * szTableQual, SQLSMALLINT  cbTableQual, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName, SQLSMALLINT  fScope, SQLSMALLINT  fNullable );
SQLRETURN ILE_SQLStartTran( SQLSMALLINT  htype, SQLHENV  henv, SQLINTEGER  mode, SQLINTEGER  clevel );
SQLRETURN ILE_SQLStatistics( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLSMALLINT  fUnique, SQLSMALLINT  fres );
SQLRETURN ILE_SQLStatisticsW( SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName, SQLSMALLINT  fUnique, SQLSMALLINT  fres );
SQLRETURN ILE_SQLTablePrivileges( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName );
SQLRETURN ILE_SQLTablePrivilegesW( SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName );
SQLRETURN ILE_SQLTables( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLCHAR * szTableType, SQLSMALLINT  cbTableType );
SQLRETURN ILE_SQLTablesW( SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName, SQLWCHAR * szTableType, SQLSMALLINT  cbTableType );
SQLRETURN ILE_SQLTransact( SQLHENV  henv, SQLHDBC  hdbc, SQLSMALLINT  fType );

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


/* special SQL400 aggregate functions */
/* do common work for language driver */
/* composite calls to CLI also async  */

SQLRETURN custom_SQL400ToUtf8( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  inccsid );
SQLRETURN custom_SQL400FromUtf8( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  outccsid );
SQLRETURN custom_SQL400ToUtf16( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  inccsid );
SQLRETURN custom_SQL400FromUtf16( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  outccsid );
SQLRETURN custom_SQL400AddAttr( SQLINTEGER  scope, SQLINTEGER  attrib, SQLPOINTER  vParam, SQLINTEGER  inlen, SQLINTEGER  onerr, SQLINTEGER  flag, SQLPOINTER  options );
SQLRETURN custom_SQL400SetAttr( SQLINTEGER  scope, SQLHANDLE  hndl, SQLINTEGER  flag, SQLPOINTER  options );
SQLRETURN custom_SQL400Environment( SQLINTEGER * ohnd, SQLPOINTER  options );
SQLRETURN custom_SQL400Connect( SQLHENV  henv, SQLCHAR * db, SQLCHAR * uid, SQLCHAR * pwd, SQLINTEGER * ohnd, SQLPOINTER  options );
SQLRETURN custom_SQL400AddCVar( SQLSMALLINT  icol, SQLSMALLINT  inOutType, SQLSMALLINT  pfSqlCType, SQLPOINTER  pfSqlCValue, SQLINTEGER * indPtr, SQLPOINTER  parms );
SQLRETURN custom_SQL400AddDesc( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  flag, SQLPOINTER  descs );
SQLRETURN custom_SQL400Execute( SQLHSTMT  hstmt, SQLPOINTER  parms, SQLPOINTER  desc_parms );
SQLRETURN custom_SQL400Fetch( SQLHSTMT  hstmt, SQLINTEGER  start_row, SQLPOINTER  cols, SQLPOINTER  desc_cols );
SQLRETURN custom_SQL400Stmt2Hdbc( SQLHSTMT  hstmt, SQLINTEGER * ohnd );

static SQLRETURN (*libdb400_SQLAllocConnect)( SQLHENV, SQLHDBC* );
static SQLRETURN (*libdb400_SQLAllocEnv)( SQLHENV* );
static SQLRETURN (*libdb400_SQLAllocHandle)( SQLSMALLINT, SQLINTEGER, SQLINTEGER* );
static SQLRETURN (*libdb400_SQLAllocStmt)( SQLHDBC, SQLHSTMT* );
static SQLRETURN (*libdb400_SQLBindCol)( SQLHSTMT, SQLSMALLINT, SQLSMALLINT, SQLPOINTER, SQLINTEGER, SQLINTEGER* );
static SQLRETURN (*libdb400_SQLBindFileToCol)( SQLHSTMT, SQLSMALLINT, SQLCHAR*, SQLSMALLINT*, SQLINTEGER*, SQLSMALLINT, SQLINTEGER*, SQLINTEGER* );
static SQLRETURN (*libdb400_SQLBindFileToParam)( SQLHSTMT, SQLSMALLINT, SQLSMALLINT, SQLCHAR*, SQLSMALLINT*, SQLINTEGER*, SQLSMALLINT, SQLINTEGER* );
static SQLRETURN (*libdb400_SQLBindParam)( SQLHSTMT, SQLSMALLINT, SQLSMALLINT, SQLSMALLINT, SQLINTEGER, SQLSMALLINT, SQLPOINTER, SQLINTEGER* );
static SQLRETURN (*libdb400_SQLBindParameter)( SQLHSTMT, SQLSMALLINT, SQLSMALLINT, SQLSMALLINT, SQLSMALLINT, SQLINTEGER, SQLSMALLINT, SQLPOINTER, SQLINTEGER, SQLINTEGER* );
static SQLRETURN (*libdb400_SQLCancel)( SQLHSTMT );
static SQLRETURN (*libdb400_SQLCloseCursor)( SQLHSTMT );
static SQLRETURN (*libdb400_SQLColAttribute)( SQLHSTMT, SQLSMALLINT, SQLSMALLINT, SQLPOINTER, SQLSMALLINT, SQLSMALLINT*, SQLPOINTER );
static SQLRETURN (*libdb400_SQLColAttributeW)( SQLHSTMT, SQLSMALLINT, SQLSMALLINT, SQLPOINTER, SQLSMALLINT, SQLSMALLINT*, SQLPOINTER );
static SQLRETURN (*libdb400_SQLColAttributes)( SQLHSTMT, SQLSMALLINT, SQLSMALLINT, SQLCHAR*, SQLINTEGER, SQLINTEGER*, SQLINTEGER* );
static SQLRETURN (*libdb400_SQLColAttributesW)( SQLHSTMT, SQLSMALLINT, SQLSMALLINT, SQLWCHAR*, SQLINTEGER, SQLINTEGER*, SQLINTEGER* );
static SQLRETURN (*libdb400_SQLColumnPrivileges)( SQLHSTMT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT );
static SQLRETURN (*libdb400_SQLColumnPrivilegesW)( SQLHSTMT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT );
static SQLRETURN (*libdb400_SQLColumns)( SQLHSTMT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT );
static SQLRETURN (*libdb400_SQLColumnsW)( SQLHSTMT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT );
static SQLRETURN (*libdb400_SQLConnect)( SQLHDBC, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT );
static SQLRETURN (*libdb400_SQLConnectW)( SQLHDBC, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT );
static SQLRETURN (*libdb400_SQLCopyDesc)( SQLHDESC, SQLHDESC );
static SQLRETURN (*libdb400_SQLDataSources)( SQLHENV, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLSMALLINT*, SQLCHAR*, SQLSMALLINT, SQLSMALLINT* );
static SQLRETURN (*libdb400_SQLDataSourcesW)( SQLHENV, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLSMALLINT*, SQLWCHAR*, SQLSMALLINT, SQLSMALLINT* );
static SQLRETURN (*libdb400_SQLDescribeCol)( SQLHSTMT, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLSMALLINT*, SQLSMALLINT*, SQLINTEGER*, SQLSMALLINT*, SQLSMALLINT* );
static SQLRETURN (*libdb400_SQLDescribeColW)( SQLHSTMT, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLSMALLINT*, SQLSMALLINT*, SQLINTEGER*, SQLSMALLINT*, SQLSMALLINT* );
static SQLRETURN (*libdb400_SQLDescribeParam)( SQLHSTMT, SQLSMALLINT, SQLSMALLINT*, SQLINTEGER*, SQLSMALLINT*, SQLSMALLINT* );
static SQLRETURN (*libdb400_SQLDisconnect)( SQLHDBC );
static SQLRETURN (*libdb400_SQLDriverConnect)( SQLHDBC, SQLPOINTER, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLSMALLINT*, SQLSMALLINT );
static SQLRETURN (*libdb400_SQLDriverConnectW)( SQLHDBC, SQLPOINTER, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLSMALLINT*, SQLSMALLINT );
static SQLRETURN (*libdb400_SQLEndTran)( SQLSMALLINT, SQLHENV, SQLSMALLINT );
static SQLRETURN (*libdb400_SQLError)( SQLHENV, SQLHDBC, SQLHSTMT, SQLCHAR*, SQLINTEGER*, SQLCHAR*, SQLSMALLINT, SQLSMALLINT* );
static SQLRETURN (*libdb400_SQLErrorW)( SQLHENV, SQLHDBC, SQLHSTMT, SQLWCHAR*, SQLINTEGER*, SQLWCHAR*, SQLSMALLINT, SQLSMALLINT* );
static SQLRETURN (*libdb400_SQLExecDirect)( SQLHSTMT, SQLCHAR*, SQLINTEGER );
static SQLRETURN (*libdb400_SQLExecDirectW)( SQLHSTMT, SQLWCHAR*, SQLINTEGER );
static SQLRETURN (*libdb400_SQLExecute)( SQLHSTMT );
static SQLRETURN (*libdb400_SQLExtendedFetch)( SQLHSTMT, SQLSMALLINT, SQLINTEGER, SQLINTEGER*, SQLSMALLINT* );
static SQLRETURN (*libdb400_SQLFetch)( SQLHSTMT );
static SQLRETURN (*libdb400_SQLFetchScroll)( SQLHSTMT, SQLSMALLINT, SQLINTEGER );
static SQLRETURN (*libdb400_SQLForeignKeys)( SQLHSTMT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT );
static SQLRETURN (*libdb400_SQLForeignKeysW)( SQLHSTMT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT );
static SQLRETURN (*libdb400_SQLFreeConnect)( SQLHDBC );
static SQLRETURN (*libdb400_SQLFreeEnv)( SQLHENV );
static SQLRETURN (*libdb400_SQLFreeStmt)( SQLHSTMT, SQLSMALLINT );
static SQLRETURN (*libdb400_SQLFreeHandle)( SQLSMALLINT, SQLINTEGER );
static SQLRETURN (*libdb400_SQLGetCol)( SQLHSTMT, SQLSMALLINT, SQLSMALLINT, SQLPOINTER, SQLINTEGER, SQLINTEGER* );
static SQLRETURN (*libdb400_SQLGetColW)( SQLHSTMT, SQLSMALLINT, SQLSMALLINT, SQLPOINTER, SQLINTEGER, SQLINTEGER* );
static SQLRETURN (*libdb400_SQLGetConnectAttr)( SQLHDBC, SQLINTEGER, SQLPOINTER, SQLINTEGER, SQLINTEGER* );
static SQLRETURN (*libdb400_SQLGetConnectAttrW)( SQLHDBC, SQLINTEGER, SQLPOINTER, SQLINTEGER, SQLINTEGER* );
static SQLRETURN (*libdb400_SQLGetConnectOption)( SQLHDBC, SQLSMALLINT, SQLPOINTER );
static SQLRETURN (*libdb400_SQLGetConnectOptionW)( SQLHDBC, SQLSMALLINT, SQLPOINTER );
static SQLRETURN (*libdb400_SQLGetCursorName)( SQLHSTMT, SQLCHAR*, SQLSMALLINT, SQLSMALLINT* );
static SQLRETURN (*libdb400_SQLGetCursorNameW)( SQLHSTMT, SQLWCHAR*, SQLSMALLINT, SQLSMALLINT* );
static SQLRETURN (*libdb400_SQLGetData)( SQLHSTMT, SQLSMALLINT, SQLSMALLINT, SQLPOINTER, SQLINTEGER, SQLINTEGER* );
static SQLRETURN (*libdb400_SQLGetDescField)( SQLHDESC, SQLSMALLINT, SQLSMALLINT, SQLPOINTER, SQLINTEGER, SQLINTEGER* );
static SQLRETURN (*libdb400_SQLGetDescFieldW)( SQLHDESC, SQLSMALLINT, SQLSMALLINT, SQLPOINTER, SQLINTEGER, SQLINTEGER* );
static SQLRETURN (*libdb400_SQLGetDescRec)( SQLHDESC, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLSMALLINT*, SQLSMALLINT*, SQLSMALLINT*, SQLINTEGER*, SQLSMALLINT*, SQLSMALLINT*, SQLSMALLINT* );
static SQLRETURN (*libdb400_SQLGetDescRecW)( SQLHDESC, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLSMALLINT*, SQLSMALLINT*, SQLSMALLINT*, SQLINTEGER*, SQLSMALLINT*, SQLSMALLINT*, SQLSMALLINT* );
static SQLRETURN (*libdb400_SQLGetDiagField)( SQLSMALLINT, SQLINTEGER, SQLSMALLINT, SQLSMALLINT, SQLPOINTER, SQLSMALLINT, SQLSMALLINT* );
static SQLRETURN (*libdb400_SQLGetDiagFieldW)( SQLSMALLINT, SQLINTEGER, SQLSMALLINT, SQLSMALLINT, SQLPOINTER, SQLSMALLINT, SQLSMALLINT* );
static SQLRETURN (*libdb400_SQLGetDiagRec)( SQLSMALLINT, SQLINTEGER, SQLSMALLINT, SQLCHAR*, SQLINTEGER*, SQLCHAR*, SQLSMALLINT, SQLSMALLINT* );
static SQLRETURN (*libdb400_SQLGetDiagRecW)( SQLSMALLINT, SQLINTEGER, SQLSMALLINT, SQLWCHAR*, SQLINTEGER*, SQLWCHAR*, SQLSMALLINT, SQLSMALLINT* );
static SQLRETURN (*libdb400_SQLGetEnvAttr)( SQLHENV, SQLINTEGER, SQLPOINTER, SQLINTEGER, SQLINTEGER* );
static SQLRETURN (*libdb400_SQLGetFunctions)( SQLHDBC, SQLSMALLINT, SQLSMALLINT* );
static SQLRETURN (*libdb400_SQLGetInfo)( SQLHDBC, SQLSMALLINT, SQLPOINTER, SQLSMALLINT, SQLSMALLINT* );
static SQLRETURN (*libdb400_SQLGetInfoW)( SQLHDBC, SQLSMALLINT, SQLPOINTER, SQLSMALLINT, SQLSMALLINT* );
static SQLRETURN (*libdb400_SQLGetLength)( SQLHSTMT, SQLSMALLINT, SQLINTEGER, SQLINTEGER*, SQLINTEGER* );
static SQLRETURN (*libdb400_SQLGetPosition)( SQLHSTMT, SQLSMALLINT, SQLINTEGER, SQLINTEGER, SQLCHAR*, SQLINTEGER, SQLINTEGER, SQLINTEGER*, SQLINTEGER* );
static SQLRETURN (*libdb400_SQLGetPositionW)( SQLHSTMT, SQLSMALLINT, SQLINTEGER, SQLINTEGER, SQLWCHAR*, SQLINTEGER, SQLINTEGER, SQLINTEGER*, SQLINTEGER* );
static SQLRETURN (*libdb400_SQLGetStmtAttr)( SQLHSTMT, SQLINTEGER, SQLPOINTER, SQLINTEGER, SQLINTEGER* );
static SQLRETURN (*libdb400_SQLGetStmtAttrW)( SQLHSTMT, SQLINTEGER, SQLPOINTER, SQLINTEGER, SQLINTEGER* );
static SQLRETURN (*libdb400_SQLGetStmtOption)( SQLHSTMT, SQLSMALLINT, SQLPOINTER );
static SQLRETURN (*libdb400_SQLGetStmtOptionW)( SQLHSTMT, SQLSMALLINT, SQLPOINTER );
static SQLRETURN (*libdb400_SQLGetSubString)( SQLHSTMT, SQLSMALLINT, SQLINTEGER, SQLINTEGER, SQLINTEGER, SQLSMALLINT, SQLPOINTER, SQLINTEGER, SQLINTEGER*, SQLINTEGER* );
static SQLRETURN (*libdb400_SQLGetSubStringW)( SQLHSTMT, SQLSMALLINT, SQLINTEGER, SQLINTEGER, SQLINTEGER, SQLSMALLINT, SQLPOINTER, SQLINTEGER, SQLINTEGER*, SQLINTEGER* );
static SQLRETURN (*libdb400_SQLGetTypeInfo)( SQLHSTMT, SQLSMALLINT );
static SQLRETURN (*libdb400_SQLGetTypeInfoW)( SQLHSTMT, SQLSMALLINT );
static SQLRETURN (*libdb400_SQLLanguages)( SQLHSTMT );
static SQLRETURN (*libdb400_SQLMoreResults)( SQLHSTMT );
static SQLRETURN (*libdb400_SQLNativeSql)( SQLHDBC, SQLCHAR*, SQLINTEGER, SQLCHAR*, SQLINTEGER, SQLINTEGER* );
static SQLRETURN (*libdb400_SQLNativeSqlW)( SQLHDBC, SQLWCHAR*, SQLINTEGER, SQLWCHAR*, SQLINTEGER, SQLINTEGER* );
static SQLRETURN (*libdb400_SQLNextResult)( SQLHSTMT, SQLHSTMT );
static SQLRETURN (*libdb400_SQLNumParams)( SQLHSTMT, SQLSMALLINT* );
static SQLRETURN (*libdb400_SQLNumResultCols)( SQLHSTMT, SQLSMALLINT* );
static SQLRETURN (*libdb400_SQLParamData)( SQLHSTMT, SQLPOINTER* );
static SQLRETURN (*libdb400_SQLParamOptions)( SQLHSTMT, SQLINTEGER, SQLINTEGER* );
static SQLRETURN (*libdb400_SQLPrepare)( SQLHSTMT, SQLCHAR*, SQLINTEGER );
static SQLRETURN (*libdb400_SQLPrepareW)( SQLHSTMT, SQLWCHAR*, SQLINTEGER );
static SQLRETURN (*libdb400_SQLPrimaryKeys)( SQLHSTMT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT );
static SQLRETURN (*libdb400_SQLPrimaryKeysW)( SQLHSTMT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT );
static SQLRETURN (*libdb400_SQLProcedureColumns)( SQLHSTMT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT );
static SQLRETURN (*libdb400_SQLProcedureColumnsW)( SQLHSTMT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT );
static SQLRETURN (*libdb400_SQLProcedures)( SQLHSTMT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT );
static SQLRETURN (*libdb400_SQLProceduresW)( SQLHSTMT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT );
static SQLRETURN (*libdb400_SQLPutData)( SQLHSTMT, SQLPOINTER, SQLINTEGER );
static SQLRETURN (*libdb400_SQLReleaseEnv)( SQLHENV );
static SQLRETURN (*libdb400_SQLRowCount)( SQLHSTMT, SQLINTEGER* );
static SQLRETURN (*libdb400_SQLSetConnectAttr)( SQLHDBC, SQLINTEGER, SQLPOINTER, SQLINTEGER );
static SQLRETURN (*libdb400_SQLSetConnectAttrW)( SQLHDBC, SQLINTEGER, SQLPOINTER, SQLINTEGER );
static SQLRETURN (*libdb400_SQLSetConnectOption)( SQLHDBC, SQLSMALLINT, SQLPOINTER );
static SQLRETURN (*libdb400_SQLSetConnectOptionW)( SQLHDBC, SQLSMALLINT, SQLPOINTER );
static SQLRETURN (*libdb400_SQLSetCursorName)( SQLHSTMT, SQLCHAR*, SQLSMALLINT );
static SQLRETURN (*libdb400_SQLSetCursorNameW)( SQLHSTMT, SQLWCHAR*, SQLSMALLINT );
static SQLRETURN (*libdb400_SQLSetDescField)( SQLHDESC, SQLSMALLINT, SQLSMALLINT, SQLPOINTER, SQLINTEGER );
static SQLRETURN (*libdb400_SQLSetDescFieldW)( SQLHDESC, SQLSMALLINT, SQLSMALLINT, SQLPOINTER, SQLINTEGER );
static SQLRETURN (*libdb400_SQLSetDescRec)( SQLHDESC, SQLSMALLINT, SQLSMALLINT, SQLSMALLINT, SQLINTEGER, SQLSMALLINT, SQLSMALLINT, SQLPOINTER, SQLINTEGER*, SQLINTEGER* );
static SQLRETURN (*libdb400_SQLSetEnvAttr)( SQLHENV, SQLINTEGER, SQLPOINTER, SQLINTEGER );
static SQLRETURN (*libdb400_SQLSetParam)( SQLHSTMT, SQLSMALLINT, SQLSMALLINT, SQLSMALLINT, SQLINTEGER, SQLSMALLINT, SQLPOINTER, SQLINTEGER* );
static SQLRETURN (*libdb400_SQLSetStmtAttr)( SQLHSTMT, SQLINTEGER, SQLPOINTER, SQLINTEGER );
static SQLRETURN (*libdb400_SQLSetStmtAttrW)( SQLHSTMT, SQLINTEGER, SQLPOINTER, SQLINTEGER );
static SQLRETURN (*libdb400_SQLSetStmtOption)( SQLHSTMT, SQLSMALLINT, SQLPOINTER );
static SQLRETURN (*libdb400_SQLSetStmtOptionW)( SQLHSTMT, SQLSMALLINT, SQLPOINTER );
static SQLRETURN (*libdb400_SQLSpecialColumns)( SQLHSTMT, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLSMALLINT, SQLSMALLINT );
static SQLRETURN (*libdb400_SQLSpecialColumnsW)( SQLHSTMT, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLSMALLINT, SQLSMALLINT );
static SQLRETURN (*libdb400_SQLStartTran)( SQLSMALLINT, SQLHENV, SQLINTEGER, SQLINTEGER );
static SQLRETURN (*libdb400_SQLStatistics)( SQLHSTMT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLSMALLINT, SQLSMALLINT );
static SQLRETURN (*libdb400_SQLStatisticsW)( SQLHSTMT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLSMALLINT, SQLSMALLINT );
static SQLRETURN (*libdb400_SQLTablePrivileges)( SQLHSTMT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT );
static SQLRETURN (*libdb400_SQLTablePrivilegesW)( SQLHSTMT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT );
static SQLRETURN (*libdb400_SQLTables)( SQLHSTMT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT );
static SQLRETURN (*libdb400_SQLTablesW)( SQLHSTMT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT );
static SQLRETURN (*libdb400_SQLTransact)( SQLHENV, SQLHDBC, SQLSMALLINT );


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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLAllocConnectLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLAllocConnect");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLAllocConnectLoaded = 1;
  }
  arglist->henv = (SQLHENV) henv;
  arglist->phdbc.s.addr = (address64_t) phdbc;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLAllocConnectIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLAllocEnvLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLAllocEnv");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLAllocEnvLoaded = 1;
  }
  arglist->phenv.s.addr = (address64_t) phenv;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLAllocEnvIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLAllocHandleLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLAllocHandle");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLAllocHandleLoaded = 1;
  }
  arglist->htype = (SQLSMALLINT) htype;
  arglist->ihnd = (SQLINTEGER) ihnd;
  arglist->ohnd.s.addr = (address64_t) ohnd;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLAllocHandleIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLAllocStmtLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLAllocStmt");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLAllocStmtLoaded = 1;
  }
  arglist->hdbc = (SQLHDBC) hdbc;
  arglist->phstmt.s.addr = (address64_t) phstmt;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLAllocStmtIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLBindColLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLBindCol");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLBindColLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->icol = (SQLSMALLINT) icol;
  arglist->iType = (SQLSMALLINT) iType;
  arglist->rgbValue.s.addr = (address64_t) rgbValue;
  arglist->cbValueMax = (SQLINTEGER) cbValueMax;
  arglist->pcbValue.s.addr = (address64_t) pcbValue;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLBindColIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLBindFileToColLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLBindFileToCol");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLBindFileToColLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->icol = (SQLSMALLINT) icol;
  arglist->fName.s.addr = (address64_t) fName;
  arglist->fNameLen.s.addr = (address64_t) fNameLen;
  arglist->fOptions.s.addr = (address64_t) fOptions;
  arglist->fValueMax = (SQLSMALLINT) fValueMax;
  arglist->sLen.s.addr = (address64_t) sLen;
  arglist->pcbValue.s.addr = (address64_t) pcbValue;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLBindFileToColIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLBindFileToParamLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLBindFileToParam");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLBindFileToParamLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->ipar = (SQLSMALLINT) ipar;
  arglist->iType = (SQLSMALLINT) iType;
  arglist->fName.s.addr = (address64_t) fName;
  arglist->fNameLen.s.addr = (address64_t) fNameLen;
  arglist->fOptions.s.addr = (address64_t) fOptions;
  arglist->fValueMax = (SQLSMALLINT) fValueMax;
  arglist->pcbValue.s.addr = (address64_t) pcbValue;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLBindFileToParamIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLBindParamLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLBindParam");
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
  arglist->pData.s.addr = (address64_t) pData;
  arglist->pcbValue.s.addr = (address64_t) pcbValue;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLBindParamIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLBindParameterLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLBindParameter");
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
  arglist->pData.s.addr = (address64_t) pData;
  arglist->cbValueMax = (SQLINTEGER) cbValueMax;
  arglist->pcbValue.s.addr = (address64_t) pcbValue;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLBindParameterIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLCancelLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLCancel");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLCancelLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLCancelIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLCloseCursorLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLCloseCursor");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLCloseCursorLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLCloseCursorIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLColAttributeLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLColAttribute");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLColAttributeLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->icol = (SQLSMALLINT) icol;
  arglist->fDescType = (SQLSMALLINT) fDescType;
  arglist->rgbDesc.s.addr = (address64_t) rgbDesc;
  arglist->cbDescMax = (SQLSMALLINT) cbDescMax;
  arglist->pcbDesc.s.addr = (address64_t) pcbDesc;
  arglist->pfDesc.s.addr = (address64_t) pfDesc;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLColAttributeIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLColAttributeWLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLColAttributeW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLColAttributeWLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->icol = (SQLSMALLINT) icol;
  arglist->fDescType = (SQLSMALLINT) fDescType;
  arglist->rgbDesc.s.addr = (address64_t) rgbDesc;
  arglist->cbDescMax = (SQLSMALLINT) cbDescMax;
  arglist->pcbDesc.s.addr = (address64_t) pcbDesc;
  arglist->pfDesc.s.addr = (address64_t) pfDesc;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLColAttributeWIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLColAttributesLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLColAttributes");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLColAttributesLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->icol = (SQLSMALLINT) icol;
  arglist->fDescType = (SQLSMALLINT) fDescType;
  arglist->rgbDesc.s.addr = (address64_t) rgbDesc;
  arglist->cbDescMax = (SQLINTEGER) cbDescMax;
  arglist->pcbDesc.s.addr = (address64_t) pcbDesc;
  arglist->pfDesc.s.addr = (address64_t) pfDesc;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLColAttributesIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLColAttributesWLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLColAttributesW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLColAttributesWLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->icol = (SQLSMALLINT) icol;
  arglist->fDescType = (SQLSMALLINT) fDescType;
  arglist->rgbDesc.s.addr = (address64_t) rgbDesc;
  arglist->cbDescMax = (SQLINTEGER) cbDescMax;
  arglist->pcbDesc.s.addr = (address64_t) pcbDesc;
  arglist->pfDesc.s.addr = (address64_t) pfDesc;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLColAttributesWIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLColumnPrivilegesLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLColumnPrivileges");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLColumnPrivilegesLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->szTableQualifier.s.addr = (address64_t) szTableQualifier;
  arglist->cbTableQualifier = (SQLSMALLINT) cbTableQualifier;
  arglist->szTableOwner.s.addr = (address64_t) szTableOwner;
  arglist->cbTableOwner = (SQLSMALLINT) cbTableOwner;
  arglist->szTableName.s.addr = (address64_t) szTableName;
  arglist->cbTableName = (SQLSMALLINT) cbTableName;
  arglist->szColumnName.s.addr = (address64_t) szColumnName;
  arglist->cbColumnName = (SQLSMALLINT) cbColumnName;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLColumnPrivilegesIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLColumnPrivilegesWLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLColumnPrivilegesW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLColumnPrivilegesWLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->szTableQualifier.s.addr = (address64_t) szTableQualifier;
  arglist->cbTableQualifier = (SQLSMALLINT) cbTableQualifier;
  arglist->szTableOwner.s.addr = (address64_t) szTableOwner;
  arglist->cbTableOwner = (SQLSMALLINT) cbTableOwner;
  arglist->szTableName.s.addr = (address64_t) szTableName;
  arglist->cbTableName = (SQLSMALLINT) cbTableName;
  arglist->szColumnName.s.addr = (address64_t) szColumnName;
  arglist->cbColumnName = (SQLSMALLINT) cbColumnName;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLColumnPrivilegesWIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLColumnsLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLColumns");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLColumnsLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->szTableQualifier.s.addr = (address64_t) szTableQualifier;
  arglist->cbTableQualifier = (SQLSMALLINT) cbTableQualifier;
  arglist->szTableOwner.s.addr = (address64_t) szTableOwner;
  arglist->cbTableOwner = (SQLSMALLINT) cbTableOwner;
  arglist->szTableName.s.addr = (address64_t) szTableName;
  arglist->cbTableName = (SQLSMALLINT) cbTableName;
  arglist->szColumnName.s.addr = (address64_t) szColumnName;
  arglist->cbColumnName = (SQLSMALLINT) cbColumnName;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLColumnsIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLColumnsWLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLColumnsW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLColumnsWLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->szTableQualifier.s.addr = (address64_t) szTableQualifier;
  arglist->cbTableQualifier = (SQLSMALLINT) cbTableQualifier;
  arglist->szTableOwner.s.addr = (address64_t) szTableOwner;
  arglist->cbTableOwner = (SQLSMALLINT) cbTableOwner;
  arglist->szTableName.s.addr = (address64_t) szTableName;
  arglist->cbTableName = (SQLSMALLINT) cbTableName;
  arglist->szColumnName.s.addr = (address64_t) szColumnName;
  arglist->cbColumnName = (SQLSMALLINT) cbColumnName;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLColumnsWIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLConnectLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLConnect");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLConnectLoaded = 1;
  }
  arglist->hdbc = (SQLHDBC) hdbc;
  arglist->szDSN.s.addr = (address64_t) szDSN;
  arglist->cbDSN = (SQLSMALLINT) cbDSN;
  arglist->szUID.s.addr = (address64_t) szUID;
  arglist->cbUID = (SQLSMALLINT) cbUID;
  arglist->szAuthStr.s.addr = (address64_t) szAuthStr;
  arglist->cbAuthStr = (SQLSMALLINT) cbAuthStr;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLConnectIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLConnectWLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLConnectW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLConnectWLoaded = 1;
  }
  arglist->hdbc = (SQLHDBC) hdbc;
  arglist->szDSN.s.addr = (address64_t) szDSN;
  arglist->cbDSN = (SQLSMALLINT) cbDSN;
  arglist->szUID.s.addr = (address64_t) szUID;
  arglist->cbUID = (SQLSMALLINT) cbUID;
  arglist->szAuthStr.s.addr = (address64_t) szAuthStr;
  arglist->cbAuthStr = (SQLSMALLINT) cbAuthStr;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLConnectWIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLCopyDescLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLCopyDesc");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLCopyDescLoaded = 1;
  }
  arglist->sDesc = (SQLHDESC) sDesc;
  arglist->tDesc = (SQLHDESC) tDesc;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLCopyDescIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLDataSourcesLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLDataSources");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLDataSourcesLoaded = 1;
  }
  arglist->henv = (SQLHENV) henv;
  arglist->fDirection = (SQLSMALLINT) fDirection;
  arglist->szDSN.s.addr = (address64_t) szDSN;
  arglist->cbDSNMax = (SQLSMALLINT) cbDSNMax;
  arglist->pcbDSN.s.addr = (address64_t) pcbDSN;
  arglist->szDescription.s.addr = (address64_t) szDescription;
  arglist->cbDescriptionMax = (SQLSMALLINT) cbDescriptionMax;
  arglist->pcbDescription.s.addr = (address64_t) pcbDescription;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLDataSourcesIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLDataSourcesWLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLDataSourcesW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLDataSourcesWLoaded = 1;
  }
  arglist->henv = (SQLHENV) henv;
  arglist->fDirection = (SQLSMALLINT) fDirection;
  arglist->szDSN.s.addr = (address64_t) szDSN;
  arglist->cbDSNMax = (SQLSMALLINT) cbDSNMax;
  arglist->pcbDSN.s.addr = (address64_t) pcbDSN;
  arglist->szDescription.s.addr = (address64_t) szDescription;
  arglist->cbDescriptionMax = (SQLSMALLINT) cbDescriptionMax;
  arglist->pcbDescription.s.addr = (address64_t) pcbDescription;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLDataSourcesWIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLDescribeColLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLDescribeCol");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLDescribeColLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->icol = (SQLSMALLINT) icol;
  arglist->szColName.s.addr = (address64_t) szColName;
  arglist->cbColNameMax = (SQLSMALLINT) cbColNameMax;
  arglist->pcbColName.s.addr = (address64_t) pcbColName;
  arglist->pfSqlType.s.addr = (address64_t) pfSqlType;
  arglist->pcbColDef.s.addr = (address64_t) pcbColDef;
  arglist->pibScale.s.addr = (address64_t) pibScale;
  arglist->pfNullable.s.addr = (address64_t) pfNullable;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLDescribeColIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLDescribeColWLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLDescribeColW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLDescribeColWLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->icol = (SQLSMALLINT) icol;
  arglist->szColName.s.addr = (address64_t) szColName;
  arglist->cbColNameMax = (SQLSMALLINT) cbColNameMax;
  arglist->pcbColName.s.addr = (address64_t) pcbColName;
  arglist->pfSqlType.s.addr = (address64_t) pfSqlType;
  arglist->pcbColDef.s.addr = (address64_t) pcbColDef;
  arglist->pibScale.s.addr = (address64_t) pibScale;
  arglist->pfNullable.s.addr = (address64_t) pfNullable;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLDescribeColWIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLDescribeParamLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLDescribeParam");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLDescribeParamLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->ipar = (SQLSMALLINT) ipar;
  arglist->pfSqlType.s.addr = (address64_t) pfSqlType;
  arglist->pcbColDef.s.addr = (address64_t) pcbColDef;
  arglist->pibScale.s.addr = (address64_t) pibScale;
  arglist->pfNullable.s.addr = (address64_t) pfNullable;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLDescribeParamIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLDisconnectLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLDisconnect");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLDisconnectLoaded = 1;
  }
  arglist->hdbc = (SQLHDBC) hdbc;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLDisconnectIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLDriverConnectLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLDriverConnect");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLDriverConnectLoaded = 1;
  }
  arglist->hdbc = (SQLHDBC) hdbc;
  arglist->hwnd.s.addr = (address64_t) hwnd;
  arglist->szConnStrIn.s.addr = (address64_t) szConnStrIn;
  arglist->cbConnStrin = (SQLSMALLINT) cbConnStrin;
  arglist->szConnStrOut.s.addr = (address64_t) szConnStrOut;
  arglist->cbConnStrOutMax = (SQLSMALLINT) cbConnStrOutMax;
  arglist->pcbConnStrOut.s.addr = (address64_t) pcbConnStrOut;
  arglist->fDriverCompletion = (SQLSMALLINT) fDriverCompletion;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLDriverConnectIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLDriverConnectWLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLDriverConnectW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLDriverConnectWLoaded = 1;
  }
  arglist->hdbc = (SQLHDBC) hdbc;
  arglist->hwnd.s.addr = (address64_t) hwnd;
  arglist->szConnStrIn.s.addr = (address64_t) szConnStrIn;
  arglist->cbConnStrin = (SQLSMALLINT) cbConnStrin;
  arglist->szConnStrOut.s.addr = (address64_t) szConnStrOut;
  arglist->cbConnStrOutMax = (SQLSMALLINT) cbConnStrOutMax;
  arglist->pcbConnStrOut.s.addr = (address64_t) pcbConnStrOut;
  arglist->fDriverCompletion = (SQLSMALLINT) fDriverCompletion;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLDriverConnectWIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLEndTranLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLEndTran");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLEndTranLoaded = 1;
  }
  arglist->htype = (SQLSMALLINT) htype;
  arglist->henv = (SQLHENV) henv;
  arglist->ctype = (SQLSMALLINT) ctype;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLEndTranIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLErrorLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLError");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLErrorLoaded = 1;
  }
  arglist->henv = (SQLHENV) henv;
  arglist->hdbc = (SQLHDBC) hdbc;
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->szSqlState.s.addr = (address64_t) szSqlState;
  arglist->pfNativeError.s.addr = (address64_t) pfNativeError;
  arglist->szErrorMsg.s.addr = (address64_t) szErrorMsg;
  arglist->cbErrorMsgMax = (SQLSMALLINT) cbErrorMsgMax;
  arglist->pcbErrorMsg.s.addr = (address64_t) pcbErrorMsg;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLErrorIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLErrorWLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLErrorW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLErrorWLoaded = 1;
  }
  arglist->henv = (SQLHENV) henv;
  arglist->hdbc = (SQLHDBC) hdbc;
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->szSqlState.s.addr = (address64_t) szSqlState;
  arglist->pfNativeError.s.addr = (address64_t) pfNativeError;
  arglist->szErrorMsg.s.addr = (address64_t) szErrorMsg;
  arglist->cbErrorMsgMax = (SQLSMALLINT) cbErrorMsgMax;
  arglist->pcbErrorMsg.s.addr = (address64_t) pcbErrorMsg;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLErrorWIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLExecDirectLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLExecDirect");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLExecDirectLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->szSqlStr.s.addr = (address64_t) szSqlStr;
  arglist->cbSqlStr = (SQLINTEGER) cbSqlStr;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLExecDirectIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLExecDirectWLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLExecDirectW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLExecDirectWLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->szSqlStr.s.addr = (address64_t) szSqlStr;
  arglist->cbSqlStr = (SQLINTEGER) cbSqlStr;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLExecDirectWIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLExecuteLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLExecute");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLExecuteLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLExecuteIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLExtendedFetchLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLExtendedFetch");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLExtendedFetchLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->fOrient = (SQLSMALLINT) fOrient;
  arglist->fOffset = (SQLINTEGER) fOffset;
  arglist->pcrow.s.addr = (address64_t) pcrow;
  arglist->rgfRowStatus.s.addr = (address64_t) rgfRowStatus;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLExtendedFetchIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLFetchLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLFetch");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLFetchLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLFetchIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLFetchScrollLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLFetchScroll");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLFetchScrollLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->fOrient = (SQLSMALLINT) fOrient;
  arglist->fOffset = (SQLINTEGER) fOffset;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLFetchScrollIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLForeignKeysLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLForeignKeys");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLForeignKeysLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->szPkTableQualifier.s.addr = (address64_t) szPkTableQualifier;
  arglist->cbPkTableQualifier = (SQLSMALLINT) cbPkTableQualifier;
  arglist->szPkTableOwner.s.addr = (address64_t) szPkTableOwner;
  arglist->cbPkTableOwner = (SQLSMALLINT) cbPkTableOwner;
  arglist->szPkTableName.s.addr = (address64_t) szPkTableName;
  arglist->cbPkTableName = (SQLSMALLINT) cbPkTableName;
  arglist->szFkTableQualifier.s.addr = (address64_t) szFkTableQualifier;
  arglist->cbFkTableQualifier = (SQLSMALLINT) cbFkTableQualifier;
  arglist->szFkTableOwner.s.addr = (address64_t) szFkTableOwner;
  arglist->cbFkTableOwner = (SQLSMALLINT) cbFkTableOwner;
  arglist->szFkTableName.s.addr = (address64_t) szFkTableName;
  arglist->cbFkTableName = (SQLSMALLINT) cbFkTableName;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLForeignKeysIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLForeignKeysWLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLForeignKeysW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLForeignKeysWLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->szPkTableQualifier.s.addr = (address64_t) szPkTableQualifier;
  arglist->cbPkTableQualifier = (SQLSMALLINT) cbPkTableQualifier;
  arglist->szPkTableOwner.s.addr = (address64_t) szPkTableOwner;
  arglist->cbPkTableOwner = (SQLSMALLINT) cbPkTableOwner;
  arglist->szPkTableName.s.addr = (address64_t) szPkTableName;
  arglist->cbPkTableName = (SQLSMALLINT) cbPkTableName;
  arglist->szFkTableQualifier.s.addr = (address64_t) szFkTableQualifier;
  arglist->cbFkTableQualifier = (SQLSMALLINT) cbFkTableQualifier;
  arglist->szFkTableOwner.s.addr = (address64_t) szFkTableOwner;
  arglist->cbFkTableOwner = (SQLSMALLINT) cbFkTableOwner;
  arglist->szFkTableName.s.addr = (address64_t) szFkTableName;
  arglist->cbFkTableName = (SQLSMALLINT) cbFkTableName;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLForeignKeysWIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLFreeConnectLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLFreeConnect");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLFreeConnectLoaded = 1;
  }
  arglist->hdbc = (SQLHDBC) hdbc;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLFreeConnectIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLFreeEnvLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLFreeEnv");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLFreeEnvLoaded = 1;
  }
  arglist->henv = (SQLHENV) henv;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLFreeEnvIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLFreeStmtLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLFreeStmt");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLFreeStmtLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->fOption = (SQLSMALLINT) fOption;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLFreeStmtIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLFreeHandleLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLFreeHandle");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLFreeHandleLoaded = 1;
  }
  arglist->htype = (SQLSMALLINT) htype;
  arglist->hndl = (SQLINTEGER) hndl;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLFreeHandleIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLGetColLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLGetCol");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetColLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->icol = (SQLSMALLINT) icol;
  arglist->itype = (SQLSMALLINT) itype;
  arglist->tval.s.addr = (address64_t) tval;
  arglist->blen = (SQLINTEGER) blen;
  arglist->olen.s.addr = (address64_t) olen;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLGetColIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLGetColWLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLGetColW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetColWLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->icol = (SQLSMALLINT) icol;
  arglist->itype = (SQLSMALLINT) itype;
  arglist->tval.s.addr = (address64_t) tval;
  arglist->blen = (SQLINTEGER) blen;
  arglist->olen.s.addr = (address64_t) olen;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLGetColWIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLGetConnectAttrLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLGetConnectAttr");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetConnectAttrLoaded = 1;
  }
  arglist->hdbc = (SQLHDBC) hdbc;
  arglist->attr = (SQLINTEGER) attr;
  arglist->oval.s.addr = (address64_t) oval;
  arglist->ilen = (SQLINTEGER) ilen;
  arglist->olen.s.addr = (address64_t) olen;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLGetConnectAttrIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLGetConnectAttrWLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLGetConnectAttrW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetConnectAttrWLoaded = 1;
  }
  arglist->hdbc = (SQLHDBC) hdbc;
  arglist->attr = (SQLINTEGER) attr;
  arglist->oval.s.addr = (address64_t) oval;
  arglist->ilen = (SQLINTEGER) ilen;
  arglist->olen.s.addr = (address64_t) olen;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLGetConnectAttrWIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLGetConnectOptionLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLGetConnectOption");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetConnectOptionLoaded = 1;
  }
  arglist->hdbc = (SQLHDBC) hdbc;
  arglist->iopt = (SQLSMALLINT) iopt;
  arglist->oval.s.addr = (address64_t) oval;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLGetConnectOptionIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLGetConnectOptionWLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLGetConnectOptionW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetConnectOptionWLoaded = 1;
  }
  arglist->hdbc = (SQLHDBC) hdbc;
  arglist->iopt = (SQLSMALLINT) iopt;
  arglist->oval.s.addr = (address64_t) oval;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLGetConnectOptionWIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLGetCursorNameLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLGetCursorName");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetCursorNameLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->szCursor.s.addr = (address64_t) szCursor;
  arglist->cbCursorMax = (SQLSMALLINT) cbCursorMax;
  arglist->pcbCursor.s.addr = (address64_t) pcbCursor;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLGetCursorNameIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLGetCursorNameWLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLGetCursorNameW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetCursorNameWLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->szCursor.s.addr = (address64_t) szCursor;
  arglist->cbCursorMax = (SQLSMALLINT) cbCursorMax;
  arglist->pcbCursor.s.addr = (address64_t) pcbCursor;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLGetCursorNameWIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLGetDataLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLGetData");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetDataLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->icol = (SQLSMALLINT) icol;
  arglist->fCType = (SQLSMALLINT) fCType;
  arglist->rgbValue.s.addr = (address64_t) rgbValue;
  arglist->cbValueMax = (SQLINTEGER) cbValueMax;
  arglist->pcbValue.s.addr = (address64_t) pcbValue;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLGetDataIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLGetDescFieldLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLGetDescField");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetDescFieldLoaded = 1;
  }
  arglist->hdesc = (SQLHDESC) hdesc;
  arglist->rcdNum = (SQLSMALLINT) rcdNum;
  arglist->fieldID = (SQLSMALLINT) fieldID;
  arglist->fValue.s.addr = (address64_t) fValue;
  arglist->fLength = (SQLINTEGER) fLength;
  arglist->stLength.s.addr = (address64_t) stLength;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLGetDescFieldIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLGetDescFieldWLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLGetDescFieldW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetDescFieldWLoaded = 1;
  }
  arglist->hdesc = (SQLHDESC) hdesc;
  arglist->rcdNum = (SQLSMALLINT) rcdNum;
  arglist->fieldID = (SQLSMALLINT) fieldID;
  arglist->fValue.s.addr = (address64_t) fValue;
  arglist->fLength = (SQLINTEGER) fLength;
  arglist->stLength.s.addr = (address64_t) stLength;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLGetDescFieldWIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLGetDescRecLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLGetDescRec");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetDescRecLoaded = 1;
  }
  arglist->hdesc = (SQLHDESC) hdesc;
  arglist->rcdNum = (SQLSMALLINT) rcdNum;
  arglist->fname.s.addr = (address64_t) fname;
  arglist->bufLen = (SQLSMALLINT) bufLen;
  arglist->sLength.s.addr = (address64_t) sLength;
  arglist->sType.s.addr = (address64_t) sType;
  arglist->sbType.s.addr = (address64_t) sbType;
  arglist->fLength.s.addr = (address64_t) fLength;
  arglist->fprec.s.addr = (address64_t) fprec;
  arglist->fscale.s.addr = (address64_t) fscale;
  arglist->fnull.s.addr = (address64_t) fnull;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLGetDescRecIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLGetDescRecWLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLGetDescRecW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetDescRecWLoaded = 1;
  }
  arglist->hdesc = (SQLHDESC) hdesc;
  arglist->rcdNum = (SQLSMALLINT) rcdNum;
  arglist->fname.s.addr = (address64_t) fname;
  arglist->bufLen = (SQLSMALLINT) bufLen;
  arglist->sLength.s.addr = (address64_t) sLength;
  arglist->sType.s.addr = (address64_t) sType;
  arglist->sbType.s.addr = (address64_t) sbType;
  arglist->fLength.s.addr = (address64_t) fLength;
  arglist->fprec.s.addr = (address64_t) fprec;
  arglist->fscale.s.addr = (address64_t) fscale;
  arglist->fnull.s.addr = (address64_t) fnull;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLGetDescRecWIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLGetDiagFieldLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLGetDiagField");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetDiagFieldLoaded = 1;
  }
  arglist->hType = (SQLSMALLINT) hType;
  arglist->hndl = (SQLINTEGER) hndl;
  arglist->rcdNum = (SQLSMALLINT) rcdNum;
  arglist->diagID = (SQLSMALLINT) diagID;
  arglist->dValue.s.addr = (address64_t) dValue;
  arglist->bLength = (SQLSMALLINT) bLength;
  arglist->sLength.s.addr = (address64_t) sLength;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLGetDiagFieldIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLGetDiagFieldWLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLGetDiagFieldW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetDiagFieldWLoaded = 1;
  }
  arglist->hType = (SQLSMALLINT) hType;
  arglist->hndl = (SQLINTEGER) hndl;
  arglist->rcdNum = (SQLSMALLINT) rcdNum;
  arglist->diagID = (SQLSMALLINT) diagID;
  arglist->dValue.s.addr = (address64_t) dValue;
  arglist->bLength = (SQLSMALLINT) bLength;
  arglist->sLength.s.addr = (address64_t) sLength;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLGetDiagFieldWIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLGetDiagRecLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLGetDiagRec");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetDiagRecLoaded = 1;
  }
  arglist->hType = (SQLSMALLINT) hType;
  arglist->hndl = (SQLINTEGER) hndl;
  arglist->rcdNum = (SQLSMALLINT) rcdNum;
  arglist->SQLstate.s.addr = (address64_t) SQLstate;
  arglist->SQLcode.s.addr = (address64_t) SQLcode;
  arglist->msgText.s.addr = (address64_t) msgText;
  arglist->bLength = (SQLSMALLINT) bLength;
  arglist->SLength.s.addr = (address64_t) SLength;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLGetDiagRecIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLGetDiagRecWLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLGetDiagRecW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetDiagRecWLoaded = 1;
  }
  arglist->hType = (SQLSMALLINT) hType;
  arglist->hndl = (SQLINTEGER) hndl;
  arglist->rcdNum = (SQLSMALLINT) rcdNum;
  arglist->SQLstate.s.addr = (address64_t) SQLstate;
  arglist->SQLcode.s.addr = (address64_t) SQLcode;
  arglist->msgText.s.addr = (address64_t) msgText;
  arglist->bLength = (SQLSMALLINT) bLength;
  arglist->SLength.s.addr = (address64_t) SLength;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLGetDiagRecWIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLGetEnvAttrLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLGetEnvAttr");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetEnvAttrLoaded = 1;
  }
  arglist->hEnv = (SQLHENV) hEnv;
  arglist->fAttribute = (SQLINTEGER) fAttribute;
  arglist->pParam.s.addr = (address64_t) pParam;
  arglist->cbParamMax = (SQLINTEGER) cbParamMax;
  arglist->pcbParam.s.addr = (address64_t) pcbParam;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLGetEnvAttrIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLGetFunctionsLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLGetFunctions");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetFunctionsLoaded = 1;
  }
  arglist->hdbc = (SQLHDBC) hdbc;
  arglist->fFunction = (SQLSMALLINT) fFunction;
  arglist->pfExists.s.addr = (address64_t) pfExists;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLGetFunctionsIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLGetInfoLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLGetInfo");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetInfoLoaded = 1;
  }
  arglist->hdbc = (SQLHDBC) hdbc;
  arglist->fInfoType = (SQLSMALLINT) fInfoType;
  arglist->rgbInfoValue.s.addr = (address64_t) rgbInfoValue;
  arglist->cbInfoValueMax = (SQLSMALLINT) cbInfoValueMax;
  arglist->pcbInfoValue.s.addr = (address64_t) pcbInfoValue;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLGetInfoIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLGetInfoWLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLGetInfoW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetInfoWLoaded = 1;
  }
  arglist->hdbc = (SQLHDBC) hdbc;
  arglist->fInfoType = (SQLSMALLINT) fInfoType;
  arglist->rgbInfoValue.s.addr = (address64_t) rgbInfoValue;
  arglist->cbInfoValueMax = (SQLSMALLINT) cbInfoValueMax;
  arglist->pcbInfoValue.s.addr = (address64_t) pcbInfoValue;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLGetInfoWIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLGetLengthLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLGetLength");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetLengthLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->locType = (SQLSMALLINT) locType;
  arglist->locator = (SQLINTEGER) locator;
  arglist->sLength.s.addr = (address64_t) sLength;
  arglist->ind.s.addr = (address64_t) ind;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLGetLengthIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLGetPositionLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLGetPosition");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetPositionLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->locType = (SQLSMALLINT) locType;
  arglist->srceLocator = (SQLINTEGER) srceLocator;
  arglist->srchLocator = (SQLINTEGER) srchLocator;
  arglist->srchLiteral.s.addr = (address64_t) srchLiteral;
  arglist->srchLiteralLen = (SQLINTEGER) srchLiteralLen;
  arglist->fPosition = (SQLINTEGER) fPosition;
  arglist->located.s.addr = (address64_t) located;
  arglist->ind.s.addr = (address64_t) ind;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLGetPositionIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLGetPositionWLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLGetPositionW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetPositionWLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->locType = (SQLSMALLINT) locType;
  arglist->srceLocator = (SQLINTEGER) srceLocator;
  arglist->srchLocator = (SQLINTEGER) srchLocator;
  arglist->srchLiteral.s.addr = (address64_t) srchLiteral;
  arglist->srchLiteralLen = (SQLINTEGER) srchLiteralLen;
  arglist->fPosition = (SQLINTEGER) fPosition;
  arglist->located.s.addr = (address64_t) located;
  arglist->ind.s.addr = (address64_t) ind;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLGetPositionWIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLGetStmtAttrLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLGetStmtAttr");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetStmtAttrLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->fAttr = (SQLINTEGER) fAttr;
  arglist->pvParam.s.addr = (address64_t) pvParam;
  arglist->bLength = (SQLINTEGER) bLength;
  arglist->SLength.s.addr = (address64_t) SLength;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLGetStmtAttrIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLGetStmtAttrWLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLGetStmtAttrW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetStmtAttrWLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->fAttr = (SQLINTEGER) fAttr;
  arglist->pvParam.s.addr = (address64_t) pvParam;
  arglist->bLength = (SQLINTEGER) bLength;
  arglist->SLength.s.addr = (address64_t) SLength;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLGetStmtAttrWIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLGetStmtOptionLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLGetStmtOption");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetStmtOptionLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->fOption = (SQLSMALLINT) fOption;
  arglist->pvParam.s.addr = (address64_t) pvParam;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLGetStmtOptionIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLGetStmtOptionWLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLGetStmtOptionW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetStmtOptionWLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->fOption = (SQLSMALLINT) fOption;
  arglist->pvParam.s.addr = (address64_t) pvParam;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLGetStmtOptionWIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLGetSubStringLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLGetSubString");
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
  arglist->rgbValue.s.addr = (address64_t) rgbValue;
  arglist->cbValueMax = (SQLINTEGER) cbValueMax;
  arglist->StringLength.s.addr = (address64_t) StringLength;
  arglist->ind.s.addr = (address64_t) ind;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLGetSubStringIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLGetSubStringWLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLGetSubStringW");
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
  arglist->rgbValue.s.addr = (address64_t) rgbValue;
  arglist->cbValueMax = (SQLINTEGER) cbValueMax;
  arglist->StringLength.s.addr = (address64_t) StringLength;
  arglist->ind.s.addr = (address64_t) ind;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLGetSubStringWIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLGetTypeInfoLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLGetTypeInfo");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetTypeInfoLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->fSqlType = (SQLSMALLINT) fSqlType;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLGetTypeInfoIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLGetTypeInfoWLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLGetTypeInfoW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLGetTypeInfoWLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->fSqlType = (SQLSMALLINT) fSqlType;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLGetTypeInfoWIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLLanguagesLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLLanguages");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLLanguagesLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLLanguagesIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLMoreResultsLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLMoreResults");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLMoreResultsLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLMoreResultsIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLNativeSqlLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLNativeSql");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLNativeSqlLoaded = 1;
  }
  arglist->hdbc = (SQLHDBC) hdbc;
  arglist->szSqlStrIn.s.addr = (address64_t) szSqlStrIn;
  arglist->cbSqlStrIn = (SQLINTEGER) cbSqlStrIn;
  arglist->szSqlStr.s.addr = (address64_t) szSqlStr;
  arglist->cbSqlStrMax = (SQLINTEGER) cbSqlStrMax;
  arglist->pcbSqlStr.s.addr = (address64_t) pcbSqlStr;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLNativeSqlIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLNativeSqlWLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLNativeSqlW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLNativeSqlWLoaded = 1;
  }
  arglist->hdbc = (SQLHDBC) hdbc;
  arglist->szSqlStrIn.s.addr = (address64_t) szSqlStrIn;
  arglist->cbSqlStrIn = (SQLINTEGER) cbSqlStrIn;
  arglist->szSqlStr.s.addr = (address64_t) szSqlStr;
  arglist->cbSqlStrMax = (SQLINTEGER) cbSqlStrMax;
  arglist->pcbSqlStr.s.addr = (address64_t) pcbSqlStr;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLNativeSqlWIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLNextResultLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLNextResult");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLNextResultLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->hstmt2 = (SQLHSTMT) hstmt2;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLNextResultIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLNumParamsLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLNumParams");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLNumParamsLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->pcpar.s.addr = (address64_t) pcpar;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLNumParamsIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLNumResultColsLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLNumResultCols");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLNumResultColsLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->pccol.s.addr = (address64_t) pccol;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLNumResultColsIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLParamDataLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLParamData");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLParamDataLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->Value.s.addr = (address64_t) Value;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLParamDataIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLParamOptionsLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLParamOptions");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLParamOptionsLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->crow = (SQLINTEGER) crow;
  arglist->pirow.s.addr = (address64_t) pirow;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLParamOptionsIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLPrepareLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLPrepare");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLPrepareLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->szSqlStr.s.addr = (address64_t) szSqlStr;
  arglist->cbSqlStr = (SQLINTEGER) cbSqlStr;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLPrepareIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLPrepareWLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLPrepareW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLPrepareWLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->szSqlStr.s.addr = (address64_t) szSqlStr;
  arglist->cbSqlStr = (SQLINTEGER) cbSqlStr;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLPrepareWIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLPrimaryKeysLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLPrimaryKeys");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLPrimaryKeysLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->szTableQualifier.s.addr = (address64_t) szTableQualifier;
  arglist->cbTableQualifier = (SQLSMALLINT) cbTableQualifier;
  arglist->szTableOwner.s.addr = (address64_t) szTableOwner;
  arglist->cbTableOwner = (SQLSMALLINT) cbTableOwner;
  arglist->szTableName.s.addr = (address64_t) szTableName;
  arglist->cbTableName = (SQLSMALLINT) cbTableName;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLPrimaryKeysIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLPrimaryKeysWLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLPrimaryKeysW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLPrimaryKeysWLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->szTableQualifier.s.addr = (address64_t) szTableQualifier;
  arglist->cbTableQualifier = (SQLSMALLINT) cbTableQualifier;
  arglist->szTableOwner.s.addr = (address64_t) szTableOwner;
  arglist->cbTableOwner = (SQLSMALLINT) cbTableOwner;
  arglist->szTableName.s.addr = (address64_t) szTableName;
  arglist->cbTableName = (SQLSMALLINT) cbTableName;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLPrimaryKeysWIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLProcedureColumnsLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLProcedureColumns");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLProcedureColumnsLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->szProcQualifier.s.addr = (address64_t) szProcQualifier;
  arglist->cbProcQualifier = (SQLSMALLINT) cbProcQualifier;
  arglist->szProcOwner.s.addr = (address64_t) szProcOwner;
  arglist->cbProcOwner = (SQLSMALLINT) cbProcOwner;
  arglist->szProcName.s.addr = (address64_t) szProcName;
  arglist->cbProcName = (SQLSMALLINT) cbProcName;
  arglist->szColumnName.s.addr = (address64_t) szColumnName;
  arglist->cbColumnName = (SQLSMALLINT) cbColumnName;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLProcedureColumnsIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLProcedureColumnsWLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLProcedureColumnsW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLProcedureColumnsWLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->szProcQualifier.s.addr = (address64_t) szProcQualifier;
  arglist->cbProcQualifier = (SQLSMALLINT) cbProcQualifier;
  arglist->szProcOwner.s.addr = (address64_t) szProcOwner;
  arglist->cbProcOwner = (SQLSMALLINT) cbProcOwner;
  arglist->szProcName.s.addr = (address64_t) szProcName;
  arglist->cbProcName = (SQLSMALLINT) cbProcName;
  arglist->szColumnName.s.addr = (address64_t) szColumnName;
  arglist->cbColumnName = (SQLSMALLINT) cbColumnName;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLProcedureColumnsWIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLProceduresLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLProcedures");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLProceduresLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->szProcQualifier.s.addr = (address64_t) szProcQualifier;
  arglist->cbProcQualifier = (SQLSMALLINT) cbProcQualifier;
  arglist->szProcOwner.s.addr = (address64_t) szProcOwner;
  arglist->cbProcOwner = (SQLSMALLINT) cbProcOwner;
  arglist->szProcName.s.addr = (address64_t) szProcName;
  arglist->cbProcName = (SQLSMALLINT) cbProcName;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLProceduresIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLProceduresWLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLProceduresW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLProceduresWLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->szProcQualifier.s.addr = (address64_t) szProcQualifier;
  arglist->cbProcQualifier = (SQLSMALLINT) cbProcQualifier;
  arglist->szProcOwner.s.addr = (address64_t) szProcOwner;
  arglist->cbProcOwner = (SQLSMALLINT) cbProcOwner;
  arglist->szProcName.s.addr = (address64_t) szProcName;
  arglist->cbProcName = (SQLSMALLINT) cbProcName;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLProceduresWIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLPutDataLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLPutData");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLPutDataLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->Data.s.addr = (address64_t) Data;
  arglist->SLen = (SQLINTEGER) SLen;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLPutDataIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLReleaseEnvLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLReleaseEnv");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLReleaseEnvLoaded = 1;
  }
  arglist->henv = (SQLHENV) henv;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLReleaseEnvIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLRowCountLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLRowCount");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLRowCountLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->pcrow.s.addr = (address64_t) pcrow;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLRowCountIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLSetConnectAttrLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLSetConnectAttr");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLSetConnectAttrLoaded = 1;
  }
  arglist->hdbc = (SQLHDBC) hdbc;
  arglist->attrib = (SQLINTEGER) attrib;
  arglist->vParam.s.addr = (address64_t) vParam;
  arglist->inlen = (SQLINTEGER) inlen;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLSetConnectAttrIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLSetConnectAttrWLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLSetConnectAttrW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLSetConnectAttrWLoaded = 1;
  }
  arglist->hdbc = (SQLHDBC) hdbc;
  arglist->attrib = (SQLINTEGER) attrib;
  arglist->vParam.s.addr = (address64_t) vParam;
  arglist->inlen = (SQLINTEGER) inlen;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLSetConnectAttrWIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLSetConnectOptionLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLSetConnectOption");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLSetConnectOptionLoaded = 1;
  }
  arglist->hdbc = (SQLHDBC) hdbc;
  arglist->fOption = (SQLSMALLINT) fOption;
  arglist->vParam.s.addr = (address64_t) vParam;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLSetConnectOptionIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLSetConnectOptionWLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLSetConnectOptionW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLSetConnectOptionWLoaded = 1;
  }
  arglist->hdbc = (SQLHDBC) hdbc;
  arglist->fOption = (SQLSMALLINT) fOption;
  arglist->vParam.s.addr = (address64_t) vParam;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLSetConnectOptionWIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLSetCursorNameLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLSetCursorName");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLSetCursorNameLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->szCursor.s.addr = (address64_t) szCursor;
  arglist->cbCursor = (SQLSMALLINT) cbCursor;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLSetCursorNameIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLSetCursorNameWLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLSetCursorNameW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLSetCursorNameWLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->szCursor.s.addr = (address64_t) szCursor;
  arglist->cbCursor = (SQLSMALLINT) cbCursor;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLSetCursorNameWIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLSetDescFieldLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLSetDescField");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLSetDescFieldLoaded = 1;
  }
  arglist->hdesc = (SQLHDESC) hdesc;
  arglist->rcdNum = (SQLSMALLINT) rcdNum;
  arglist->fID = (SQLSMALLINT) fID;
  arglist->Value.s.addr = (address64_t) Value;
  arglist->buffLen = (SQLINTEGER) buffLen;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLSetDescFieldIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLSetDescFieldWLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLSetDescFieldW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLSetDescFieldWLoaded = 1;
  }
  arglist->hdesc = (SQLHDESC) hdesc;
  arglist->rcdNum = (SQLSMALLINT) rcdNum;
  arglist->fID = (SQLSMALLINT) fID;
  arglist->Value.s.addr = (address64_t) Value;
  arglist->buffLen = (SQLINTEGER) buffLen;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLSetDescFieldWIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLSetDescRecLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLSetDescRec");
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
  arglist->Value.s.addr = (address64_t) Value;
  arglist->sLength.s.addr = (address64_t) sLength;
  arglist->indic.s.addr = (address64_t) indic;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLSetDescRecIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLSetEnvAttrLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLSetEnvAttr");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLSetEnvAttrLoaded = 1;
  }
  arglist->hEnv = (SQLHENV) hEnv;
  arglist->fAttribute = (SQLINTEGER) fAttribute;
  arglist->pParam.s.addr = (address64_t) pParam;
  arglist->cbParam = (SQLINTEGER) cbParam;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLSetEnvAttrIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLSetParamLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLSetParam");
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
  arglist->rgbValue.s.addr = (address64_t) rgbValue;
  arglist->pcbValue.s.addr = (address64_t) pcbValue;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLSetParamIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLSetStmtAttrLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLSetStmtAttr");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLSetStmtAttrLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->fAttr = (SQLINTEGER) fAttr;
  arglist->pParam.s.addr = (address64_t) pParam;
  arglist->vParam = (SQLINTEGER) vParam;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLSetStmtAttrIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLSetStmtAttrWLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLSetStmtAttrW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLSetStmtAttrWLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->fAttr = (SQLINTEGER) fAttr;
  arglist->pParam.s.addr = (address64_t) pParam;
  arglist->vParam = (SQLINTEGER) vParam;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLSetStmtAttrWIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLSetStmtOptionLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLSetStmtOption");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLSetStmtOptionLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->fOption = (SQLSMALLINT) fOption;
  arglist->vParam.s.addr = (address64_t) vParam;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLSetStmtOptionIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLSetStmtOptionWLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLSetStmtOptionW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLSetStmtOptionWLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->fOption = (SQLSMALLINT) fOption;
  arglist->vParam.s.addr = (address64_t) vParam;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLSetStmtOptionWIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLSpecialColumnsLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLSpecialColumns");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLSpecialColumnsLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->fColType = (SQLSMALLINT) fColType;
  arglist->szTableQual.s.addr = (address64_t) szTableQual;
  arglist->cbTableQual = (SQLSMALLINT) cbTableQual;
  arglist->szTableOwner.s.addr = (address64_t) szTableOwner;
  arglist->cbTableOwner = (SQLSMALLINT) cbTableOwner;
  arglist->szTableName.s.addr = (address64_t) szTableName;
  arglist->cbTableName = (SQLSMALLINT) cbTableName;
  arglist->fScope = (SQLSMALLINT) fScope;
  arglist->fNullable = (SQLSMALLINT) fNullable;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLSpecialColumnsIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLSpecialColumnsWLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLSpecialColumnsW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLSpecialColumnsWLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->fColType = (SQLSMALLINT) fColType;
  arglist->szTableQual.s.addr = (address64_t) szTableQual;
  arglist->cbTableQual = (SQLSMALLINT) cbTableQual;
  arglist->szTableOwner.s.addr = (address64_t) szTableOwner;
  arglist->cbTableOwner = (SQLSMALLINT) cbTableOwner;
  arglist->szTableName.s.addr = (address64_t) szTableName;
  arglist->cbTableName = (SQLSMALLINT) cbTableName;
  arglist->fScope = (SQLSMALLINT) fScope;
  arglist->fNullable = (SQLSMALLINT) fNullable;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLSpecialColumnsWIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLStartTranLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLStartTran");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLStartTranLoaded = 1;
  }
  arglist->htype = (SQLSMALLINT) htype;
  arglist->henv = (SQLHENV) henv;
  arglist->mode = (SQLINTEGER) mode;
  arglist->clevel = (SQLINTEGER) clevel;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLStartTranIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLStatisticsLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLStatistics");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLStatisticsLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->szTableQualifier.s.addr = (address64_t) szTableQualifier;
  arglist->cbTableQualifier = (SQLSMALLINT) cbTableQualifier;
  arglist->szTableOwner.s.addr = (address64_t) szTableOwner;
  arglist->cbTableOwner = (SQLSMALLINT) cbTableOwner;
  arglist->szTableName.s.addr = (address64_t) szTableName;
  arglist->cbTableName = (SQLSMALLINT) cbTableName;
  arglist->fUnique = (SQLSMALLINT) fUnique;
  arglist->fres = (SQLSMALLINT) fres;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLStatisticsIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLStatisticsWLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLStatisticsW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLStatisticsWLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->szTableQualifier.s.addr = (address64_t) szTableQualifier;
  arglist->cbTableQualifier = (SQLSMALLINT) cbTableQualifier;
  arglist->szTableOwner.s.addr = (address64_t) szTableOwner;
  arglist->cbTableOwner = (SQLSMALLINT) cbTableOwner;
  arglist->szTableName.s.addr = (address64_t) szTableName;
  arglist->cbTableName = (SQLSMALLINT) cbTableName;
  arglist->fUnique = (SQLSMALLINT) fUnique;
  arglist->fres = (SQLSMALLINT) fres;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLStatisticsWIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLTablePrivilegesLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLTablePrivileges");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLTablePrivilegesLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->szTableQualifier.s.addr = (address64_t) szTableQualifier;
  arglist->cbTableQualifier = (SQLSMALLINT) cbTableQualifier;
  arglist->szTableOwner.s.addr = (address64_t) szTableOwner;
  arglist->cbTableOwner = (SQLSMALLINT) cbTableOwner;
  arglist->szTableName.s.addr = (address64_t) szTableName;
  arglist->cbTableName = (SQLSMALLINT) cbTableName;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLTablePrivilegesIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLTablePrivilegesWLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLTablePrivilegesW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLTablePrivilegesWLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->szTableQualifier.s.addr = (address64_t) szTableQualifier;
  arglist->cbTableQualifier = (SQLSMALLINT) cbTableQualifier;
  arglist->szTableOwner.s.addr = (address64_t) szTableOwner;
  arglist->cbTableOwner = (SQLSMALLINT) cbTableOwner;
  arglist->szTableName.s.addr = (address64_t) szTableName;
  arglist->cbTableName = (SQLSMALLINT) cbTableName;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLTablePrivilegesWIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLTablesLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLTables");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLTablesLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->szTableQualifier.s.addr = (address64_t) szTableQualifier;
  arglist->cbTableQualifier = (SQLSMALLINT) cbTableQualifier;
  arglist->szTableOwner.s.addr = (address64_t) szTableOwner;
  arglist->cbTableOwner = (SQLSMALLINT) cbTableOwner;
  arglist->szTableName.s.addr = (address64_t) szTableName;
  arglist->cbTableName = (SQLSMALLINT) cbTableName;
  arglist->szTableType.s.addr = (address64_t) szTableType;
  arglist->cbTableType = (SQLSMALLINT) cbTableType;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLTablesIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLTablesWLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLTablesW");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLTablesWLoaded = 1;
  }
  arglist->hstmt = (SQLHSTMT) hstmt;
  arglist->szTableQualifier.s.addr = (address64_t) szTableQualifier;
  arglist->cbTableQualifier = (SQLSMALLINT) cbTableQualifier;
  arglist->szTableOwner.s.addr = (address64_t) szTableOwner;
  arglist->cbTableOwner = (SQLSMALLINT) cbTableOwner;
  arglist->szTableName.s.addr = (address64_t) szTableName;
  arglist->cbTableName = (SQLSMALLINT) cbTableName;
  arglist->szTableType.s.addr = (address64_t) szTableType;
  arglist->cbTableType = (SQLSMALLINT) cbTableType;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLTablesWIleSigStruct, RESULT_INT32);
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
  if (!db2_cli_srvpgm_mark) {
    actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
    if (actMark < 0) {
      return SQL_ERROR;
    }
    db2_cli_srvpgm_mark = actMark;
  }
  if (!SQLTransactLoaded) {
    rc = _ILESYM(ileSymPtr, db2_cli_srvpgm_mark, "SQLTransact");
    if (rc < 0) {
      return SQL_ERROR;
    }
    SQLTransactLoaded = 1;
  }
  arglist->henv = (SQLHENV) henv;
  arglist->hdbc = (SQLHDBC) hdbc;
  arglist->fType = (SQLSMALLINT) fType;
  rc = _ILECALL(ileSymPtr, &arglist->base, SQLTransactIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return arglist->base.result.s_int32.r_int32;
}

void load_dlsym() {
  libdb400_SQLAllocConnect = dlsym(dlhandle, "SQLAllocConnect");
  libdb400_SQLAllocEnv = dlsym(dlhandle, "SQLAllocEnv");
  libdb400_SQLAllocHandle = dlsym(dlhandle, "SQLAllocHandle");
  libdb400_SQLAllocStmt = dlsym(dlhandle, "SQLAllocStmt");
  libdb400_SQLBindCol = dlsym(dlhandle, "SQLBindCol");
  libdb400_SQLBindFileToCol = dlsym(dlhandle, "SQLBindFileToCol");
  libdb400_SQLBindFileToParam = dlsym(dlhandle, "SQLBindFileToParam");
  libdb400_SQLBindParam = dlsym(dlhandle, "SQLBindParam");
  libdb400_SQLBindParameter = dlsym(dlhandle, "SQLBindParameter");
  libdb400_SQLCancel = dlsym(dlhandle, "SQLCancel");
  libdb400_SQLCloseCursor = dlsym(dlhandle, "SQLCloseCursor");
  libdb400_SQLColAttribute = dlsym(dlhandle, "SQLColAttribute");
  libdb400_SQLColAttributeW = dlsym(dlhandle, "SQLColAttributeW");
  libdb400_SQLColAttributes = dlsym(dlhandle, "SQLColAttributes");
  libdb400_SQLColAttributesW = dlsym(dlhandle, "SQLColAttributesW");
  libdb400_SQLColumnPrivileges = dlsym(dlhandle, "SQLColumnPrivileges");
  libdb400_SQLColumnPrivilegesW = dlsym(dlhandle, "SQLColumnPrivilegesW");
  libdb400_SQLColumns = dlsym(dlhandle, "SQLColumns");
  libdb400_SQLColumnsW = dlsym(dlhandle, "SQLColumnsW");
  libdb400_SQLConnect = dlsym(dlhandle, "SQLConnect");
  libdb400_SQLConnectW = dlsym(dlhandle, "SQLConnectW");
  libdb400_SQLCopyDesc = dlsym(dlhandle, "SQLCopyDesc");
  libdb400_SQLDataSources = dlsym(dlhandle, "SQLDataSources");
  libdb400_SQLDataSourcesW = dlsym(dlhandle, "SQLDataSourcesW");
  libdb400_SQLDescribeCol = dlsym(dlhandle, "SQLDescribeCol");
  libdb400_SQLDescribeColW = dlsym(dlhandle, "SQLDescribeColW");
  libdb400_SQLDescribeParam = dlsym(dlhandle, "SQLDescribeParam");
  libdb400_SQLDisconnect = dlsym(dlhandle, "SQLDisconnect");
  libdb400_SQLDriverConnect = dlsym(dlhandle, "SQLDriverConnect");
  libdb400_SQLDriverConnectW = dlsym(dlhandle, "SQLDriverConnectW");
  libdb400_SQLEndTran = dlsym(dlhandle, "SQLEndTran");
  libdb400_SQLError = dlsym(dlhandle, "SQLError");
  libdb400_SQLErrorW = dlsym(dlhandle, "SQLErrorW");
  libdb400_SQLExecDirect = dlsym(dlhandle, "SQLExecDirect");
  libdb400_SQLExecDirectW = dlsym(dlhandle, "SQLExecDirectW");
  libdb400_SQLExecute = dlsym(dlhandle, "SQLExecute");
  libdb400_SQLExtendedFetch = dlsym(dlhandle, "SQLExtendedFetch");
  libdb400_SQLFetch = dlsym(dlhandle, "SQLFetch");
  libdb400_SQLFetchScroll = dlsym(dlhandle, "SQLFetchScroll");
  libdb400_SQLForeignKeys = dlsym(dlhandle, "SQLForeignKeys");
  libdb400_SQLForeignKeysW = dlsym(dlhandle, "SQLForeignKeysW");
  libdb400_SQLFreeConnect = dlsym(dlhandle, "SQLFreeConnect");
  libdb400_SQLFreeEnv = dlsym(dlhandle, "SQLFreeEnv");
  libdb400_SQLFreeStmt = dlsym(dlhandle, "SQLFreeStmt");
  libdb400_SQLFreeHandle = dlsym(dlhandle, "SQLFreeHandle");
  libdb400_SQLGetCol = dlsym(dlhandle, "SQLGetCol");
  libdb400_SQLGetColW = dlsym(dlhandle, "SQLGetColW");
  libdb400_SQLGetConnectAttr = dlsym(dlhandle, "SQLGetConnectAttr");
  libdb400_SQLGetConnectAttrW = dlsym(dlhandle, "SQLGetConnectAttrW");
  libdb400_SQLGetConnectOption = dlsym(dlhandle, "SQLGetConnectOption");
  libdb400_SQLGetConnectOptionW = dlsym(dlhandle, "SQLGetConnectOptionW");
  libdb400_SQLGetCursorName = dlsym(dlhandle, "SQLGetCursorName");
  libdb400_SQLGetCursorNameW = dlsym(dlhandle, "SQLGetCursorNameW");
  libdb400_SQLGetData = dlsym(dlhandle, "SQLGetData");
  libdb400_SQLGetDescField = dlsym(dlhandle, "SQLGetDescField");
  libdb400_SQLGetDescFieldW = dlsym(dlhandle, "SQLGetDescFieldW");
  libdb400_SQLGetDescRec = dlsym(dlhandle, "SQLGetDescRec");
  libdb400_SQLGetDescRecW = dlsym(dlhandle, "SQLGetDescRecW");
  libdb400_SQLGetDiagField = dlsym(dlhandle, "SQLGetDiagField");
  libdb400_SQLGetDiagFieldW = dlsym(dlhandle, "SQLGetDiagFieldW");
  libdb400_SQLGetDiagRec = dlsym(dlhandle, "SQLGetDiagRec");
  libdb400_SQLGetDiagRecW = dlsym(dlhandle, "SQLGetDiagRecW");
  libdb400_SQLGetEnvAttr = dlsym(dlhandle, "SQLGetEnvAttr");
  libdb400_SQLGetFunctions = dlsym(dlhandle, "SQLGetFunctions");
  libdb400_SQLGetInfo = dlsym(dlhandle, "SQLGetInfo");
  libdb400_SQLGetInfoW = dlsym(dlhandle, "SQLGetInfoW");
  libdb400_SQLGetLength = dlsym(dlhandle, "SQLGetLength");
  libdb400_SQLGetPosition = dlsym(dlhandle, "SQLGetPosition");
  libdb400_SQLGetPositionW = dlsym(dlhandle, "SQLGetPositionW");
  libdb400_SQLGetStmtAttr = dlsym(dlhandle, "SQLGetStmtAttr");
  libdb400_SQLGetStmtAttrW = dlsym(dlhandle, "SQLGetStmtAttrW");
  libdb400_SQLGetStmtOption = dlsym(dlhandle, "SQLGetStmtOption");
  libdb400_SQLGetStmtOptionW = dlsym(dlhandle, "SQLGetStmtOptionW");
  libdb400_SQLGetSubString = dlsym(dlhandle, "SQLGetSubString");
  libdb400_SQLGetSubStringW = dlsym(dlhandle, "SQLGetSubStringW");
  libdb400_SQLGetTypeInfo = dlsym(dlhandle, "SQLGetTypeInfo");
  libdb400_SQLGetTypeInfoW = dlsym(dlhandle, "SQLGetTypeInfoW");
  libdb400_SQLLanguages = dlsym(dlhandle, "SQLLanguages");
  libdb400_SQLMoreResults = dlsym(dlhandle, "SQLMoreResults");
  libdb400_SQLNativeSql = dlsym(dlhandle, "SQLNativeSql");
  libdb400_SQLNativeSqlW = dlsym(dlhandle, "SQLNativeSqlW");
  libdb400_SQLNextResult = dlsym(dlhandle, "SQLNextResult");
  libdb400_SQLNumParams = dlsym(dlhandle, "SQLNumParams");
  libdb400_SQLNumResultCols = dlsym(dlhandle, "SQLNumResultCols");
  libdb400_SQLParamData = dlsym(dlhandle, "SQLParamData");
  libdb400_SQLParamOptions = dlsym(dlhandle, "SQLParamOptions");
  libdb400_SQLPrepare = dlsym(dlhandle, "SQLPrepare");
  libdb400_SQLPrepareW = dlsym(dlhandle, "SQLPrepareW");
  libdb400_SQLPrimaryKeys = dlsym(dlhandle, "SQLPrimaryKeys");
  libdb400_SQLPrimaryKeysW = dlsym(dlhandle, "SQLPrimaryKeysW");
  libdb400_SQLProcedureColumns = dlsym(dlhandle, "SQLProcedureColumns");
  libdb400_SQLProcedureColumnsW = dlsym(dlhandle, "SQLProcedureColumnsW");
  libdb400_SQLProcedures = dlsym(dlhandle, "SQLProcedures");
  libdb400_SQLProceduresW = dlsym(dlhandle, "SQLProceduresW");
  libdb400_SQLPutData = dlsym(dlhandle, "SQLPutData");
  libdb400_SQLReleaseEnv = dlsym(dlhandle, "SQLReleaseEnv");
  libdb400_SQLRowCount = dlsym(dlhandle, "SQLRowCount");
  libdb400_SQLSetConnectAttr = dlsym(dlhandle, "SQLSetConnectAttr");
  libdb400_SQLSetConnectAttrW = dlsym(dlhandle, "SQLSetConnectAttrW");
  libdb400_SQLSetConnectOption = dlsym(dlhandle, "SQLSetConnectOption");
  libdb400_SQLSetConnectOptionW = dlsym(dlhandle, "SQLSetConnectOptionW");
  libdb400_SQLSetCursorName = dlsym(dlhandle, "SQLSetCursorName");
  libdb400_SQLSetCursorNameW = dlsym(dlhandle, "SQLSetCursorNameW");
  libdb400_SQLSetDescField = dlsym(dlhandle, "SQLSetDescField");
  libdb400_SQLSetDescFieldW = dlsym(dlhandle, "SQLSetDescFieldW");
  libdb400_SQLSetDescRec = dlsym(dlhandle, "SQLSetDescRec");
  libdb400_SQLSetEnvAttr = dlsym(dlhandle, "SQLSetEnvAttr");
  libdb400_SQLSetParam = dlsym(dlhandle, "SQLSetParam");
  libdb400_SQLSetStmtAttr = dlsym(dlhandle, "SQLSetStmtAttr");
  libdb400_SQLSetStmtAttrW = dlsym(dlhandle, "SQLSetStmtAttrW");
  libdb400_SQLSetStmtOption = dlsym(dlhandle, "SQLSetStmtOption");
  libdb400_SQLSetStmtOptionW = dlsym(dlhandle, "SQLSetStmtOptionW");
  libdb400_SQLSpecialColumns = dlsym(dlhandle, "SQLSpecialColumns");
  libdb400_SQLSpecialColumnsW = dlsym(dlhandle, "SQLSpecialColumnsW");
  libdb400_SQLStartTran = dlsym(dlhandle, "SQLStartTran");
  libdb400_SQLStatistics = dlsym(dlhandle, "SQLStatistics");
  libdb400_SQLStatisticsW = dlsym(dlhandle, "SQLStatisticsW");
  libdb400_SQLTablePrivileges = dlsym(dlhandle, "SQLTablePrivileges");
  libdb400_SQLTablePrivilegesW = dlsym(dlhandle, "SQLTablePrivilegesW");
  libdb400_SQLTables = dlsym(dlhandle, "SQLTables");
  libdb400_SQLTablesW = dlsym(dlhandle, "SQLTablesW");
  libdb400_SQLTransact = dlsym(dlhandle, "SQLTransact");

}

SQLRETURN SQLAllocConnect( SQLHENV  henv, SQLHDBC * phdbc )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_lock();
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLAllocConnect( henv, phdbc );
  } else {
    sqlrc = ILE_SQLAllocConnect( henv, phdbc );
  }
  if (sqlrc == SQL_SUCCESS) {
    init_table_ctor(*phdbc, *phdbc);
  }
  init_unlock();
  return sqlrc;
}
SQLRETURN SQLAllocEnv( SQLHENV * phenv )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_lock();
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLAllocEnv( phenv );
  } else {
    sqlrc = ILE_SQLAllocEnv( phenv );
  }
  if (sqlrc == SQL_SUCCESS) {
    init_table_ctor(*phenv, *phenv);
  }
  init_unlock();
  return sqlrc;
}
SQLRETURN SQLAllocHandle( SQLSMALLINT  htype, SQLINTEGER  ihnd, SQLINTEGER * ohnd )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  switch (htype) {
  case SQL_HANDLE_ENV:
    init_lock();
    if (i_am_big_chicken_flag) {
      sqlrc = libdb400_SQLAllocHandle( htype, ihnd, ohnd );
    } else {
      sqlrc = ILE_SQLAllocHandle( htype, ihnd, ohnd );
    }
    if (sqlrc == SQL_SUCCESS) {
      init_table_ctor(*ohnd, *ohnd);
    }
    init_unlock();
    break;
  case SQL_HANDLE_DBC:
    init_lock();
    if (i_am_big_chicken_flag) {
      sqlrc = libdb400_SQLAllocHandle( htype, ihnd, ohnd );
    } else {
      sqlrc = ILE_SQLAllocHandle( htype, ihnd, ohnd );
    }
    if (sqlrc == SQL_SUCCESS) {
      init_table_ctor(*ohnd, *ohnd);
    }
    init_unlock();
    break;
  case SQL_HANDLE_STMT:
    init_lock();
    if (i_am_big_chicken_flag) {
      sqlrc = libdb400_SQLAllocHandle( htype, ihnd, ohnd );
    } else {
      sqlrc = ILE_SQLAllocHandle( htype, ihnd, ohnd );
    }
    if (sqlrc == SQL_SUCCESS) {
      init_table_ctor(*ohnd, ihnd);
    }
    init_unlock();
    break;
  case SQL_HANDLE_DESC:
    init_lock();
    if (i_am_big_chicken_flag) {
      sqlrc = libdb400_SQLAllocHandle( htype, ihnd, ohnd );
    } else {
      sqlrc = ILE_SQLAllocHandle( htype, ihnd, ohnd );
    }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_lock();
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLAllocStmt( hdbc, phstmt );
  } else {
    sqlrc = ILE_SQLAllocStmt( hdbc, phstmt );
  }
  if (sqlrc == SQL_SUCCESS) {
    init_table_ctor(*phstmt, hdbc);
  }
  init_unlock();
  return sqlrc;
}
SQLRETURN SQLBindCol( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  iType, SQLPOINTER  rgbValue, SQLINTEGER  cbValueMax, SQLINTEGER * pcbValue )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLBindCol( hstmt, icol, iType, rgbValue, cbValueMax, pcbValue );
  } else {
    sqlrc = ILE_SQLBindCol( hstmt, icol, iType, rgbValue, cbValueMax, pcbValue );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLBindFileToCol( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLCHAR * fName, SQLSMALLINT * fNameLen, SQLINTEGER * fOptions, SQLSMALLINT  fValueMax, SQLINTEGER * sLen, SQLINTEGER * pcbValue )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLBindFileToCol( hstmt, icol, fName, fNameLen, fOptions, fValueMax, sLen, pcbValue );
  } else {
    sqlrc = ILE_SQLBindFileToCol( hstmt, icol, fName, fNameLen, fOptions, fValueMax, sLen, pcbValue );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLBindFileToParam( SQLHSTMT  hstmt, SQLSMALLINT  ipar, SQLSMALLINT  iType, SQLCHAR * fName, SQLSMALLINT * fNameLen, SQLINTEGER * fOptions, SQLSMALLINT  fValueMax, SQLINTEGER * pcbValue )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLBindFileToParam( hstmt, ipar, iType, fName, fNameLen, fOptions, fValueMax, pcbValue );
  } else {
    sqlrc = ILE_SQLBindFileToParam( hstmt, ipar, iType, fName, fNameLen, fOptions, fValueMax, pcbValue );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLBindParam( SQLHSTMT  hstmt, SQLSMALLINT  iparm, SQLSMALLINT  iType, SQLSMALLINT  pType, SQLINTEGER  pLen, SQLSMALLINT  pScale, SQLPOINTER  pData, SQLINTEGER * pcbValue )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLBindParam( hstmt, iparm, iType, pType, pLen, pScale, pData, pcbValue );
  } else {
    sqlrc = ILE_SQLBindParam( hstmt, iparm, iType, pType, pLen, pScale, pData, pcbValue );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLBindParameter( SQLHSTMT  hstmt, SQLSMALLINT  ipar, SQLSMALLINT  fParamType, SQLSMALLINT  fCType, SQLSMALLINT  fSQLType, SQLINTEGER  pLen, SQLSMALLINT  pScale, SQLPOINTER  pData, SQLINTEGER  cbValueMax, SQLINTEGER * pcbValue )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLBindParameter( hstmt, ipar, fParamType, fCType, fSQLType, pLen, pScale, pData, cbValueMax, pcbValue );
  } else {
    sqlrc = ILE_SQLBindParameter( hstmt, ipar, fParamType, fCType, fSQLType, pLen, pScale, pData, cbValueMax, pcbValue );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLCancel( SQLHSTMT  hstmt )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLCancel( hstmt );
  } else {
    sqlrc = ILE_SQLCancel( hstmt );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLCloseCursor( SQLHSTMT  hstmt )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLCloseCursor( hstmt );
  } else {
    sqlrc = ILE_SQLCloseCursor( hstmt );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLColAttribute( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fDescType, SQLPOINTER  rgbDesc, SQLSMALLINT  cbDescMax, SQLSMALLINT * pcbDesc, SQLPOINTER  pfDesc )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLColAttribute( hstmt, icol, fDescType, rgbDesc, cbDescMax, pcbDesc, pfDesc );
  } else {
    sqlrc = ILE_SQLColAttribute( hstmt, icol, fDescType, rgbDesc, cbDescMax, pcbDesc, pfDesc );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLColAttributeW( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fDescType, SQLPOINTER  rgbDesc, SQLSMALLINT  cbDescMax, SQLSMALLINT * pcbDesc, SQLPOINTER  pfDesc )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLColAttributeW( hstmt, icol, fDescType, rgbDesc, cbDescMax, pcbDesc, pfDesc );
  } else {
    sqlrc = ILE_SQLColAttributeW( hstmt, icol, fDescType, rgbDesc, cbDescMax, pcbDesc, pfDesc );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLColAttributes( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fDescType, SQLCHAR * rgbDesc, SQLINTEGER  cbDescMax, SQLINTEGER * pcbDesc, SQLINTEGER * pfDesc )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLColAttributes( hstmt, icol, fDescType, rgbDesc, cbDescMax, pcbDesc, pfDesc );
  } else {
    sqlrc = ILE_SQLColAttributes( hstmt, icol, fDescType, rgbDesc, cbDescMax, pcbDesc, pfDesc );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLColAttributesW( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fDescType, SQLWCHAR * rgbDesc, SQLINTEGER  cbDescMax, SQLINTEGER * pcbDesc, SQLINTEGER * pfDesc )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLColAttributesW( hstmt, icol, fDescType, rgbDesc, cbDescMax, pcbDesc, pfDesc );
  } else {
    sqlrc = ILE_SQLColAttributesW( hstmt, icol, fDescType, rgbDesc, cbDescMax, pcbDesc, pfDesc );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLColumnPrivileges( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLCHAR * szColumnName, SQLSMALLINT  cbColumnName )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLColumnPrivileges( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName, szColumnName, cbColumnName );
  } else {
    sqlrc = ILE_SQLColumnPrivileges( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName, szColumnName, cbColumnName );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLColumnPrivilegesW( SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName, SQLWCHAR * szColumnName, SQLSMALLINT  cbColumnName )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLColumnPrivilegesW( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName, szColumnName, cbColumnName );
  } else {
    sqlrc = ILE_SQLColumnPrivilegesW( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName, szColumnName, cbColumnName );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLColumns( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLCHAR * szColumnName, SQLSMALLINT  cbColumnName )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLColumns( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName, szColumnName, cbColumnName );
  } else {
    sqlrc = ILE_SQLColumns( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName, szColumnName, cbColumnName );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLColumnsW( SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName, SQLWCHAR * szColumnName, SQLSMALLINT  cbColumnName )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLColumnsW( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName, szColumnName, cbColumnName );
  } else {
    sqlrc = ILE_SQLColumnsW( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName, szColumnName, cbColumnName );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLConnect( SQLHDBC  hdbc, SQLCHAR * szDSN, SQLSMALLINT  cbDSN, SQLCHAR * szUID, SQLSMALLINT  cbUID, SQLCHAR * szAuthStr, SQLSMALLINT  cbAuthStr )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hdbc, 0);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLConnect( hdbc, szDSN, cbDSN, szUID, cbUID, szAuthStr, cbAuthStr );
  } else {
    sqlrc = ILE_SQLConnect( hdbc, szDSN, cbDSN, szUID, cbUID, szAuthStr, cbAuthStr );
  }
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
SQLRETURN SQLConnectW( SQLHDBC  hdbc, SQLWCHAR * szDSN, SQLSMALLINT  cbDSN, SQLWCHAR * szUID, SQLSMALLINT  cbUID, SQLWCHAR * szAuthStr, SQLSMALLINT  cbAuthStr )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hdbc, 0);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLConnectW( hdbc, szDSN, cbDSN, szUID, cbUID, szAuthStr, cbAuthStr );
  } else {
    sqlrc = ILE_SQLConnectW( hdbc, szDSN, cbDSN, szUID, cbUID, szAuthStr, cbAuthStr );
  }
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
SQLRETURN SQLCopyDesc( SQLHDESC  sDesc, SQLHDESC  tDesc )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(sDesc, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLCopyDesc( sDesc, tDesc );
  } else {
    sqlrc = ILE_SQLCopyDesc( sDesc, tDesc );
  }
  init_table_unlock(sDesc, 1);
  return sqlrc;
}
SQLRETURN SQLDataSources( SQLHENV  henv, SQLSMALLINT  fDirection, SQLCHAR * szDSN, SQLSMALLINT  cbDSNMax, SQLSMALLINT * pcbDSN, SQLCHAR * szDescription, SQLSMALLINT  cbDescriptionMax, SQLSMALLINT * pcbDescription )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLDataSources( henv, fDirection, szDSN, cbDSNMax, pcbDSN, szDescription, cbDescriptionMax, pcbDescription );
  } else {
    sqlrc = ILE_SQLDataSources( henv, fDirection, szDSN, cbDSNMax, pcbDSN, szDescription, cbDescriptionMax, pcbDescription );
  }
  return sqlrc;
}
SQLRETURN SQLDataSourcesW( SQLHENV  henv, SQLSMALLINT  fDirection, SQLWCHAR * szDSN, SQLSMALLINT  cbDSNMax, SQLSMALLINT * pcbDSN, SQLWCHAR * szDescription, SQLSMALLINT  cbDescriptionMax, SQLSMALLINT * pcbDescription )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLDataSourcesW( henv, fDirection, szDSN, cbDSNMax, pcbDSN, szDescription, cbDescriptionMax, pcbDescription );
  } else {
    sqlrc = ILE_SQLDataSourcesW( henv, fDirection, szDSN, cbDSNMax, pcbDSN, szDescription, cbDescriptionMax, pcbDescription );
  }
  return sqlrc;
}
SQLRETURN SQLDescribeCol( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLCHAR * szColName, SQLSMALLINT  cbColNameMax, SQLSMALLINT * pcbColName, SQLSMALLINT * pfSqlType, SQLINTEGER * pcbColDef, SQLSMALLINT * pibScale, SQLSMALLINT * pfNullable )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLDescribeCol( hstmt, icol, szColName, cbColNameMax, pcbColName, pfSqlType, pcbColDef, pibScale, pfNullable );
  } else {
    sqlrc = ILE_SQLDescribeCol( hstmt, icol, szColName, cbColNameMax, pcbColName, pfSqlType, pcbColDef, pibScale, pfNullable );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLDescribeColW( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLWCHAR * szColName, SQLSMALLINT  cbColNameMax, SQLSMALLINT * pcbColName, SQLSMALLINT * pfSqlType, SQLINTEGER * pcbColDef, SQLSMALLINT * pibScale, SQLSMALLINT * pfNullable )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLDescribeColW( hstmt, icol, szColName, cbColNameMax, pcbColName, pfSqlType, pcbColDef, pibScale, pfNullable );
  } else {
    sqlrc = ILE_SQLDescribeColW( hstmt, icol, szColName, cbColNameMax, pcbColName, pfSqlType, pcbColDef, pibScale, pfNullable );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLDescribeParam( SQLHSTMT  hstmt, SQLSMALLINT  ipar, SQLSMALLINT * pfSqlType, SQLINTEGER * pcbColDef, SQLSMALLINT * pibScale, SQLSMALLINT * pfNullable )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLDescribeParam( hstmt, ipar, pfSqlType, pcbColDef, pibScale, pfNullable );
  } else {
    sqlrc = ILE_SQLDescribeParam( hstmt, ipar, pfSqlType, pcbColDef, pibScale, pfNullable );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLDisconnect( SQLHDBC  hdbc )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hdbc, 0);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLDisconnect( hdbc );
  } else {
    sqlrc = ILE_SQLDisconnect( hdbc );
  }
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
SQLRETURN SQLDriverConnect( SQLHDBC  hdbc, SQLPOINTER  hwnd, SQLCHAR * szConnStrIn, SQLSMALLINT  cbConnStrin, SQLCHAR * szConnStrOut, SQLSMALLINT  cbConnStrOutMax, SQLSMALLINT * pcbConnStrOut, SQLSMALLINT  fDriverCompletion )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hdbc, 0);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLDriverConnect( hdbc, hwnd, szConnStrIn, cbConnStrin, szConnStrOut, cbConnStrOutMax, pcbConnStrOut, fDriverCompletion );
  } else {
    sqlrc = ILE_SQLDriverConnect( hdbc, hwnd, szConnStrIn, cbConnStrin, szConnStrOut, cbConnStrOutMax, pcbConnStrOut, fDriverCompletion );
  }
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
SQLRETURN SQLDriverConnectW( SQLHDBC  hdbc, SQLPOINTER  hwnd, SQLWCHAR * szConnStrIn, SQLSMALLINT  cbConnStrin, SQLWCHAR * szConnStrOut, SQLSMALLINT  cbConnStrOutMax, SQLSMALLINT * pcbConnStrOut, SQLSMALLINT  fDriverCompletion )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hdbc, 0);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLDriverConnectW( hdbc, hwnd, szConnStrIn, cbConnStrin, szConnStrOut, cbConnStrOutMax, pcbConnStrOut, fDriverCompletion );
  } else {
    sqlrc = ILE_SQLDriverConnectW( hdbc, hwnd, szConnStrIn, cbConnStrin, szConnStrOut, cbConnStrOutMax, pcbConnStrOut, fDriverCompletion );
  }
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
SQLRETURN SQLEndTran( SQLSMALLINT  htype, SQLHENV  henv, SQLSMALLINT  ctype )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLEndTran( htype, henv, ctype );
  } else {
    sqlrc = ILE_SQLEndTran( htype, henv, ctype );
  }
  return sqlrc;
}
SQLRETURN SQLError( SQLHENV  henv, SQLHDBC  hdbc, SQLHSTMT  hstmt, SQLCHAR * szSqlState, SQLINTEGER * pfNativeError, SQLCHAR * szErrorMsg, SQLSMALLINT  cbErrorMsgMax, SQLSMALLINT * pcbErrorMsg )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLError( henv, hdbc, hstmt, szSqlState, pfNativeError, szErrorMsg, cbErrorMsgMax, pcbErrorMsg );
  } else {
    sqlrc = ILE_SQLError( henv, hdbc, hstmt, szSqlState, pfNativeError, szErrorMsg, cbErrorMsgMax, pcbErrorMsg );
  }
  return sqlrc;
}
SQLRETURN SQLErrorW( SQLHENV  henv, SQLHDBC  hdbc, SQLHSTMT  hstmt, SQLWCHAR * szSqlState, SQLINTEGER * pfNativeError, SQLWCHAR * szErrorMsg, SQLSMALLINT  cbErrorMsgMax, SQLSMALLINT * pcbErrorMsg )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLErrorW( henv, hdbc, hstmt, szSqlState, pfNativeError, szErrorMsg, cbErrorMsgMax, pcbErrorMsg );
  } else {
    sqlrc = ILE_SQLErrorW( henv, hdbc, hstmt, szSqlState, pfNativeError, szErrorMsg, cbErrorMsgMax, pcbErrorMsg );
  }
  return sqlrc;
}
SQLRETURN SQLExecDirect( SQLHSTMT  hstmt, SQLCHAR * szSqlStr, SQLINTEGER  cbSqlStr )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLExecDirect( hstmt, szSqlStr, cbSqlStr );
  } else {
    sqlrc = ILE_SQLExecDirect( hstmt, szSqlStr, cbSqlStr );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLExecDirectW( SQLHSTMT  hstmt, SQLWCHAR * szSqlStr, SQLINTEGER  cbSqlStr )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLExecDirectW( hstmt, szSqlStr, cbSqlStr );
  } else {
    sqlrc = ILE_SQLExecDirectW( hstmt, szSqlStr, cbSqlStr );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLExecute( SQLHSTMT  hstmt )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLExecute( hstmt );
  } else {
    sqlrc = ILE_SQLExecute( hstmt );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLExtendedFetch( SQLHSTMT  hstmt, SQLSMALLINT  fOrient, SQLINTEGER  fOffset, SQLINTEGER * pcrow, SQLSMALLINT * rgfRowStatus )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLExtendedFetch( hstmt, fOrient, fOffset, pcrow, rgfRowStatus );
  } else {
    sqlrc = ILE_SQLExtendedFetch( hstmt, fOrient, fOffset, pcrow, rgfRowStatus );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLFetch( SQLHSTMT  hstmt )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLFetch( hstmt );
  } else {
    sqlrc = ILE_SQLFetch( hstmt );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLFetchScroll( SQLHSTMT  hstmt, SQLSMALLINT  fOrient, SQLINTEGER  fOffset )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLFetchScroll( hstmt, fOrient, fOffset );
  } else {
    sqlrc = ILE_SQLFetchScroll( hstmt, fOrient, fOffset );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLForeignKeys( SQLHSTMT  hstmt, SQLCHAR * szPkTableQualifier, SQLSMALLINT  cbPkTableQualifier, SQLCHAR * szPkTableOwner, SQLSMALLINT  cbPkTableOwner, SQLCHAR * szPkTableName, SQLSMALLINT  cbPkTableName, SQLCHAR * szFkTableQualifier, SQLSMALLINT  cbFkTableQualifier, SQLCHAR * szFkTableOwner, SQLSMALLINT  cbFkTableOwner, SQLCHAR * szFkTableName, SQLSMALLINT  cbFkTableName )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLForeignKeys( hstmt, szPkTableQualifier, cbPkTableQualifier, szPkTableOwner, cbPkTableOwner, szPkTableName, cbPkTableName, szFkTableQualifier, cbFkTableQualifier, szFkTableOwner, cbFkTableOwner, szFkTableName, cbFkTableName );
  } else {
    sqlrc = ILE_SQLForeignKeys( hstmt, szPkTableQualifier, cbPkTableQualifier, szPkTableOwner, cbPkTableOwner, szPkTableName, cbPkTableName, szFkTableQualifier, cbFkTableQualifier, szFkTableOwner, cbFkTableOwner, szFkTableName, cbFkTableName );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLForeignKeysW( SQLHSTMT  hstmt, SQLWCHAR * szPkTableQualifier, SQLSMALLINT  cbPkTableQualifier, SQLWCHAR * szPkTableOwner, SQLSMALLINT  cbPkTableOwner, SQLWCHAR * szPkTableName, SQLSMALLINT  cbPkTableName, SQLWCHAR * szFkTableQualifier, SQLSMALLINT  cbFkTableQualifier, SQLWCHAR * szFkTableOwner, SQLSMALLINT  cbFkTableOwner, SQLWCHAR * szFkTableName, SQLSMALLINT  cbFkTableName )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLForeignKeysW( hstmt, szPkTableQualifier, cbPkTableQualifier, szPkTableOwner, cbPkTableOwner, szPkTableName, cbPkTableName, szFkTableQualifier, cbFkTableQualifier, szFkTableOwner, cbFkTableOwner, szFkTableName, cbFkTableName );
  } else {
    sqlrc = ILE_SQLForeignKeysW( hstmt, szPkTableQualifier, cbPkTableQualifier, szPkTableOwner, cbPkTableOwner, szPkTableName, cbPkTableName, szFkTableQualifier, cbFkTableQualifier, szFkTableOwner, cbFkTableOwner, szFkTableName, cbFkTableName );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLFreeConnect( SQLHDBC  hdbc )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_lock();
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLFreeConnect( hdbc );
  } else {
    sqlrc = ILE_SQLFreeConnect( hdbc );
  }
  if (sqlrc == SQL_SUCCESS) {
    init_table_dtor(hdbc);
  }
  init_unlock();
  return sqlrc;
}
SQLRETURN SQLFreeEnv( SQLHENV  henv )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_lock();
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLFreeEnv( henv );
  } else {
    sqlrc = ILE_SQLFreeEnv( henv );
  }
  init_unlock();
  return sqlrc;
}
SQLRETURN SQLFreeStmt( SQLHSTMT  hstmt, SQLSMALLINT  fOption )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_lock();
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLFreeStmt( hstmt, fOption );
  } else {
    sqlrc = ILE_SQLFreeStmt( hstmt, fOption );
  }
  if (sqlrc == SQL_SUCCESS) {
    init_table_dtor(hstmt);
  }
  init_unlock();
  return sqlrc;
}
SQLRETURN SQLFreeHandle( SQLSMALLINT  htype, SQLINTEGER  hndl )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  switch (htype) {
  case SQL_HANDLE_ENV:
    init_lock();
    if (i_am_big_chicken_flag) {
      sqlrc = libdb400_SQLFreeHandle( htype, hndl );
    } else {
      sqlrc = ILE_SQLFreeHandle( htype, hndl );
    }
    init_unlock();
    break;
  case SQL_HANDLE_DBC:
    init_lock();
    if (i_am_big_chicken_flag) {
      sqlrc = libdb400_SQLFreeHandle( htype, hndl );
    } else {
      sqlrc = ILE_SQLFreeHandle( htype, hndl );
    }
    if (sqlrc == SQL_SUCCESS) {
      init_table_dtor(hndl);
    }
    init_unlock();
    break;
  case SQL_HANDLE_STMT:
    init_lock();
    if (i_am_big_chicken_flag) {
      sqlrc = libdb400_SQLFreeHandle( htype, hndl );
    } else {
      sqlrc = ILE_SQLFreeHandle( htype, hndl );
    }
    if (sqlrc == SQL_SUCCESS) {
      init_table_dtor(hndl);
    }
    init_unlock();
    break;
  case SQL_HANDLE_DESC:
    init_lock();
    if (i_am_big_chicken_flag) {
      sqlrc = libdb400_SQLFreeHandle( htype, hndl );
    } else {
      sqlrc = ILE_SQLFreeHandle( htype, hndl );
    }
    if (sqlrc == SQL_SUCCESS) {
      init_table_dtor(hndl);
    }
    init_unlock();
    break;
  }
  return sqlrc;
}
SQLRETURN SQLGetCol( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  itype, SQLPOINTER  tval, SQLINTEGER  blen, SQLINTEGER * olen )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLGetCol( hstmt, icol, itype, tval, blen, olen );
  } else {
    sqlrc = ILE_SQLGetCol( hstmt, icol, itype, tval, blen, olen );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLGetColW( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  itype, SQLPOINTER  tval, SQLINTEGER  blen, SQLINTEGER * olen )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLGetColW( hstmt, icol, itype, tval, blen, olen );
  } else {
    sqlrc = ILE_SQLGetColW( hstmt, icol, itype, tval, blen, olen );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLGetConnectAttr( SQLHDBC  hdbc, SQLINTEGER  attr, SQLPOINTER  oval, SQLINTEGER  ilen, SQLINTEGER * olen )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hdbc, 0);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLGetConnectAttr( hdbc, attr, oval, ilen, olen );
  } else {
    sqlrc = ILE_SQLGetConnectAttr( hdbc, attr, oval, ilen, olen );
  }
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
SQLRETURN SQLGetConnectAttrW( SQLHDBC  hdbc, SQLINTEGER  attr, SQLPOINTER  oval, SQLINTEGER  ilen, SQLINTEGER * olen )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hdbc, 0);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLGetConnectAttrW( hdbc, attr, oval, ilen, olen );
  } else {
    sqlrc = ILE_SQLGetConnectAttrW( hdbc, attr, oval, ilen, olen );
  }
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
SQLRETURN SQLGetConnectOption( SQLHDBC  hdbc, SQLSMALLINT  iopt, SQLPOINTER  oval )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hdbc, 0);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLGetConnectOption( hdbc, iopt, oval );
  } else {
    sqlrc = ILE_SQLGetConnectOption( hdbc, iopt, oval );
  }
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
SQLRETURN SQLGetConnectOptionW( SQLHDBC  hdbc, SQLSMALLINT  iopt, SQLPOINTER  oval )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hdbc, 0);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLGetConnectOptionW( hdbc, iopt, oval );
  } else {
    sqlrc = ILE_SQLGetConnectOptionW( hdbc, iopt, oval );
  }
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
SQLRETURN SQLGetCursorName( SQLHSTMT  hstmt, SQLCHAR * szCursor, SQLSMALLINT  cbCursorMax, SQLSMALLINT * pcbCursor )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLGetCursorName( hstmt, szCursor, cbCursorMax, pcbCursor );
  } else {
    sqlrc = ILE_SQLGetCursorName( hstmt, szCursor, cbCursorMax, pcbCursor );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLGetCursorNameW( SQLHSTMT  hstmt, SQLWCHAR * szCursor, SQLSMALLINT  cbCursorMax, SQLSMALLINT * pcbCursor )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLGetCursorNameW( hstmt, szCursor, cbCursorMax, pcbCursor );
  } else {
    sqlrc = ILE_SQLGetCursorNameW( hstmt, szCursor, cbCursorMax, pcbCursor );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLGetData( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fCType, SQLPOINTER  rgbValue, SQLINTEGER  cbValueMax, SQLINTEGER * pcbValue )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLGetData( hstmt, icol, fCType, rgbValue, cbValueMax, pcbValue );
  } else {
    sqlrc = ILE_SQLGetData( hstmt, icol, fCType, rgbValue, cbValueMax, pcbValue );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLGetDescField( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  fieldID, SQLPOINTER  fValue, SQLINTEGER  fLength, SQLINTEGER * stLength )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hdesc, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLGetDescField( hdesc, rcdNum, fieldID, fValue, fLength, stLength );
  } else {
    sqlrc = ILE_SQLGetDescField( hdesc, rcdNum, fieldID, fValue, fLength, stLength );
  }
  init_table_unlock(hdesc, 1);
  return sqlrc;
}
SQLRETURN SQLGetDescFieldW( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  fieldID, SQLPOINTER  fValue, SQLINTEGER  fLength, SQLINTEGER * stLength )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hdesc, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLGetDescFieldW( hdesc, rcdNum, fieldID, fValue, fLength, stLength );
  } else {
    sqlrc = ILE_SQLGetDescFieldW( hdesc, rcdNum, fieldID, fValue, fLength, stLength );
  }
  init_table_unlock(hdesc, 1);
  return sqlrc;
}
SQLRETURN SQLGetDescRec( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLCHAR * fname, SQLSMALLINT  bufLen, SQLSMALLINT * sLength, SQLSMALLINT * sType, SQLSMALLINT * sbType, SQLINTEGER * fLength, SQLSMALLINT * fprec, SQLSMALLINT * fscale, SQLSMALLINT * fnull )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hdesc, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLGetDescRec( hdesc, rcdNum, fname, bufLen, sLength, sType, sbType, fLength, fprec, fscale, fnull );
  } else {
    sqlrc = ILE_SQLGetDescRec( hdesc, rcdNum, fname, bufLen, sLength, sType, sbType, fLength, fprec, fscale, fnull );
  }
  init_table_unlock(hdesc, 1);
  return sqlrc;
}
SQLRETURN SQLGetDescRecW( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLWCHAR * fname, SQLSMALLINT  bufLen, SQLSMALLINT * sLength, SQLSMALLINT * sType, SQLSMALLINT * sbType, SQLINTEGER * fLength, SQLSMALLINT * fprec, SQLSMALLINT * fscale, SQLSMALLINT * fnull )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hdesc, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLGetDescRecW( hdesc, rcdNum, fname, bufLen, sLength, sType, sbType, fLength, fprec, fscale, fnull );
  } else {
    sqlrc = ILE_SQLGetDescRecW( hdesc, rcdNum, fname, bufLen, sLength, sType, sbType, fLength, fprec, fscale, fnull );
  }
  init_table_unlock(hdesc, 1);
  return sqlrc;
}
SQLRETURN SQLGetDiagField( SQLSMALLINT  hType, SQLINTEGER  hndl, SQLSMALLINT  rcdNum, SQLSMALLINT  diagID, SQLPOINTER  dValue, SQLSMALLINT  bLength, SQLSMALLINT * sLength )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLGetDiagField( hType, hndl, rcdNum, diagID, dValue, bLength, sLength );
  } else {
    sqlrc = ILE_SQLGetDiagField( hType, hndl, rcdNum, diagID, dValue, bLength, sLength );
  }
  return sqlrc;
}
SQLRETURN SQLGetDiagFieldW( SQLSMALLINT  hType, SQLINTEGER  hndl, SQLSMALLINT  rcdNum, SQLSMALLINT  diagID, SQLPOINTER  dValue, SQLSMALLINT  bLength, SQLSMALLINT * sLength )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLGetDiagFieldW( hType, hndl, rcdNum, diagID, dValue, bLength, sLength );
  } else {
    sqlrc = ILE_SQLGetDiagFieldW( hType, hndl, rcdNum, diagID, dValue, bLength, sLength );
  }
  return sqlrc;
}
SQLRETURN SQLGetDiagRec( SQLSMALLINT  hType, SQLINTEGER  hndl, SQLSMALLINT  rcdNum, SQLCHAR * SQLstate, SQLINTEGER * SQLcode, SQLCHAR * msgText, SQLSMALLINT  bLength, SQLSMALLINT * SLength )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLGetDiagRec( hType, hndl, rcdNum, SQLstate, SQLcode, msgText, bLength, SLength );
  } else {
    sqlrc = ILE_SQLGetDiagRec( hType, hndl, rcdNum, SQLstate, SQLcode, msgText, bLength, SLength );
  }
  return sqlrc;
}
SQLRETURN SQLGetDiagRecW( SQLSMALLINT  hType, SQLINTEGER  hndl, SQLSMALLINT  rcdNum, SQLWCHAR * SQLstate, SQLINTEGER * SQLcode, SQLWCHAR * msgText, SQLSMALLINT  bLength, SQLSMALLINT * SLength )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLGetDiagRecW( hType, hndl, rcdNum, SQLstate, SQLcode, msgText, bLength, SLength );
  } else {
    sqlrc = ILE_SQLGetDiagRecW( hType, hndl, rcdNum, SQLstate, SQLcode, msgText, bLength, SLength );
  }
  return sqlrc;
}
SQLRETURN SQLGetEnvAttr( SQLHENV  hEnv, SQLINTEGER  fAttribute, SQLPOINTER  pParam, SQLINTEGER  cbParamMax, SQLINTEGER * pcbParam )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLGetEnvAttr( hEnv, fAttribute, pParam, cbParamMax, pcbParam );
  } else {
    sqlrc = ILE_SQLGetEnvAttr( hEnv, fAttribute, pParam, cbParamMax, pcbParam );
  }
  return sqlrc;
}
SQLRETURN SQLGetFunctions( SQLHDBC  hdbc, SQLSMALLINT  fFunction, SQLSMALLINT * pfExists )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hdbc, 0);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLGetFunctions( hdbc, fFunction, pfExists );
  } else {
    sqlrc = ILE_SQLGetFunctions( hdbc, fFunction, pfExists );
  }
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
SQLRETURN SQLGetInfo( SQLHDBC  hdbc, SQLSMALLINT  fInfoType, SQLPOINTER  rgbInfoValue, SQLSMALLINT  cbInfoValueMax, SQLSMALLINT * pcbInfoValue )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hdbc, 0);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLGetInfo( hdbc, fInfoType, rgbInfoValue, cbInfoValueMax, pcbInfoValue );
  } else {
    sqlrc = ILE_SQLGetInfo( hdbc, fInfoType, rgbInfoValue, cbInfoValueMax, pcbInfoValue );
  }
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
SQLRETURN SQLGetInfoW( SQLHDBC  hdbc, SQLSMALLINT  fInfoType, SQLPOINTER  rgbInfoValue, SQLSMALLINT  cbInfoValueMax, SQLSMALLINT * pcbInfoValue )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hdbc, 0);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLGetInfoW( hdbc, fInfoType, rgbInfoValue, cbInfoValueMax, pcbInfoValue );
  } else {
    sqlrc = ILE_SQLGetInfoW( hdbc, fInfoType, rgbInfoValue, cbInfoValueMax, pcbInfoValue );
  }
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
SQLRETURN SQLGetLength( SQLHSTMT  hstmt, SQLSMALLINT  locType, SQLINTEGER  locator, SQLINTEGER * sLength, SQLINTEGER * ind )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLGetLength( hstmt, locType, locator, sLength, ind );
  } else {
    sqlrc = ILE_SQLGetLength( hstmt, locType, locator, sLength, ind );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLGetPosition( SQLHSTMT  hstmt, SQLSMALLINT  locType, SQLINTEGER  srceLocator, SQLINTEGER  srchLocator, SQLCHAR * srchLiteral, SQLINTEGER  srchLiteralLen, SQLINTEGER  fPosition, SQLINTEGER * located, SQLINTEGER * ind )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLGetPosition( hstmt, locType, srceLocator, srchLocator, srchLiteral, srchLiteralLen, fPosition, located, ind );
  } else {
    sqlrc = ILE_SQLGetPosition( hstmt, locType, srceLocator, srchLocator, srchLiteral, srchLiteralLen, fPosition, located, ind );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLGetPositionW( SQLHSTMT  hstmt, SQLSMALLINT  locType, SQLINTEGER  srceLocator, SQLINTEGER  srchLocator, SQLWCHAR * srchLiteral, SQLINTEGER  srchLiteralLen, SQLINTEGER  fPosition, SQLINTEGER * located, SQLINTEGER * ind )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLGetPositionW( hstmt, locType, srceLocator, srchLocator, srchLiteral, srchLiteralLen, fPosition, located, ind );
  } else {
    sqlrc = ILE_SQLGetPositionW( hstmt, locType, srceLocator, srchLocator, srchLiteral, srchLiteralLen, fPosition, located, ind );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLGetStmtAttr( SQLHSTMT  hstmt, SQLINTEGER  fAttr, SQLPOINTER  pvParam, SQLINTEGER  bLength, SQLINTEGER * SLength )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLGetStmtAttr( hstmt, fAttr, pvParam, bLength, SLength );
  } else {
    sqlrc = ILE_SQLGetStmtAttr( hstmt, fAttr, pvParam, bLength, SLength );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLGetStmtAttrW( SQLHSTMT  hstmt, SQLINTEGER  fAttr, SQLPOINTER  pvParam, SQLINTEGER  bLength, SQLINTEGER * SLength )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLGetStmtAttrW( hstmt, fAttr, pvParam, bLength, SLength );
  } else {
    sqlrc = ILE_SQLGetStmtAttrW( hstmt, fAttr, pvParam, bLength, SLength );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLGetStmtOption( SQLHSTMT  hstmt, SQLSMALLINT  fOption, SQLPOINTER  pvParam )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLGetStmtOption( hstmt, fOption, pvParam );
  } else {
    sqlrc = ILE_SQLGetStmtOption( hstmt, fOption, pvParam );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLGetStmtOptionW( SQLHSTMT  hstmt, SQLSMALLINT  fOption, SQLPOINTER  pvParam )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLGetStmtOptionW( hstmt, fOption, pvParam );
  } else {
    sqlrc = ILE_SQLGetStmtOptionW( hstmt, fOption, pvParam );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLGetSubString( SQLHSTMT  hstmt, SQLSMALLINT  locType, SQLINTEGER  srceLocator, SQLINTEGER  fPosition, SQLINTEGER  length, SQLSMALLINT  tType, SQLPOINTER  rgbValue, SQLINTEGER  cbValueMax, SQLINTEGER * StringLength, SQLINTEGER * ind )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLGetSubString( hstmt, locType, srceLocator, fPosition, length, tType, rgbValue, cbValueMax, StringLength, ind );
  } else {
    sqlrc = ILE_SQLGetSubString( hstmt, locType, srceLocator, fPosition, length, tType, rgbValue, cbValueMax, StringLength, ind );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLGetSubStringW( SQLHSTMT  hstmt, SQLSMALLINT  locType, SQLINTEGER  srceLocator, SQLINTEGER  fPosition, SQLINTEGER  length, SQLSMALLINT  tType, SQLPOINTER  rgbValue, SQLINTEGER  cbValueMax, SQLINTEGER * StringLength, SQLINTEGER * ind )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLGetSubStringW( hstmt, locType, srceLocator, fPosition, length, tType, rgbValue, cbValueMax, StringLength, ind );
  } else {
    sqlrc = ILE_SQLGetSubStringW( hstmt, locType, srceLocator, fPosition, length, tType, rgbValue, cbValueMax, StringLength, ind );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLGetTypeInfo( SQLHSTMT  hstmt, SQLSMALLINT  fSqlType )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLGetTypeInfo( hstmt, fSqlType );
  } else {
    sqlrc = ILE_SQLGetTypeInfo( hstmt, fSqlType );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLGetTypeInfoW( SQLHSTMT  hstmt, SQLSMALLINT  fSqlType )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLGetTypeInfoW( hstmt, fSqlType );
  } else {
    sqlrc = ILE_SQLGetTypeInfoW( hstmt, fSqlType );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLLanguages( SQLHSTMT  hstmt )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLLanguages( hstmt );
  } else {
    sqlrc = ILE_SQLLanguages( hstmt );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLMoreResults( SQLHSTMT  hstmt )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLMoreResults( hstmt );
  } else {
    sqlrc = ILE_SQLMoreResults( hstmt );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLNativeSql( SQLHDBC  hdbc, SQLCHAR * szSqlStrIn, SQLINTEGER  cbSqlStrIn, SQLCHAR * szSqlStr, SQLINTEGER  cbSqlStrMax, SQLINTEGER * pcbSqlStr )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hdbc, 0);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLNativeSql( hdbc, szSqlStrIn, cbSqlStrIn, szSqlStr, cbSqlStrMax, pcbSqlStr );
  } else {
    sqlrc = ILE_SQLNativeSql( hdbc, szSqlStrIn, cbSqlStrIn, szSqlStr, cbSqlStrMax, pcbSqlStr );
  }
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
SQLRETURN SQLNativeSqlW( SQLHDBC  hdbc, SQLWCHAR * szSqlStrIn, SQLINTEGER  cbSqlStrIn, SQLWCHAR * szSqlStr, SQLINTEGER  cbSqlStrMax, SQLINTEGER * pcbSqlStr )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hdbc, 0);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLNativeSqlW( hdbc, szSqlStrIn, cbSqlStrIn, szSqlStr, cbSqlStrMax, pcbSqlStr );
  } else {
    sqlrc = ILE_SQLNativeSqlW( hdbc, szSqlStrIn, cbSqlStrIn, szSqlStr, cbSqlStrMax, pcbSqlStr );
  }
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
SQLRETURN SQLNextResult( SQLHSTMT  hstmt, SQLHSTMT  hstmt2 )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLNextResult( hstmt, hstmt2 );
  } else {
    sqlrc = ILE_SQLNextResult( hstmt, hstmt2 );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLNumParams( SQLHSTMT  hstmt, SQLSMALLINT * pcpar )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLNumParams( hstmt, pcpar );
  } else {
    sqlrc = ILE_SQLNumParams( hstmt, pcpar );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLNumResultCols( SQLHSTMT  hstmt, SQLSMALLINT * pccol )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLNumResultCols( hstmt, pccol );
  } else {
    sqlrc = ILE_SQLNumResultCols( hstmt, pccol );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLParamData( SQLHSTMT  hstmt, SQLPOINTER * Value )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLParamData( hstmt, Value );
  } else {
    sqlrc = ILE_SQLParamData( hstmt, Value );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLParamOptions( SQLHSTMT  hstmt, SQLINTEGER  crow, SQLINTEGER * pirow )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLParamOptions( hstmt, crow, pirow );
  } else {
    sqlrc = ILE_SQLParamOptions( hstmt, crow, pirow );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLPrepare( SQLHSTMT  hstmt, SQLCHAR * szSqlStr, SQLINTEGER  cbSqlStr )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLPrepare( hstmt, szSqlStr, cbSqlStr );
  } else {
    sqlrc = ILE_SQLPrepare( hstmt, szSqlStr, cbSqlStr );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLPrepareW( SQLHSTMT  hstmt, SQLWCHAR * szSqlStr, SQLINTEGER  cbSqlStr )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLPrepareW( hstmt, szSqlStr, cbSqlStr );
  } else {
    sqlrc = ILE_SQLPrepareW( hstmt, szSqlStr, cbSqlStr );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLPrimaryKeys( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLPrimaryKeys( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName );
  } else {
    sqlrc = ILE_SQLPrimaryKeys( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLPrimaryKeysW( SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLPrimaryKeysW( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName );
  } else {
    sqlrc = ILE_SQLPrimaryKeysW( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLProcedureColumns( SQLHSTMT  hstmt, SQLCHAR * szProcQualifier, SQLSMALLINT  cbProcQualifier, SQLCHAR * szProcOwner, SQLSMALLINT  cbProcOwner, SQLCHAR * szProcName, SQLSMALLINT  cbProcName, SQLCHAR * szColumnName, SQLSMALLINT  cbColumnName )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLProcedureColumns( hstmt, szProcQualifier, cbProcQualifier, szProcOwner, cbProcOwner, szProcName, cbProcName, szColumnName, cbColumnName );
  } else {
    sqlrc = ILE_SQLProcedureColumns( hstmt, szProcQualifier, cbProcQualifier, szProcOwner, cbProcOwner, szProcName, cbProcName, szColumnName, cbColumnName );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLProcedureColumnsW( SQLHSTMT  hstmt, SQLWCHAR * szProcQualifier, SQLSMALLINT  cbProcQualifier, SQLWCHAR * szProcOwner, SQLSMALLINT  cbProcOwner, SQLWCHAR * szProcName, SQLSMALLINT  cbProcName, SQLWCHAR * szColumnName, SQLSMALLINT  cbColumnName )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLProcedureColumnsW( hstmt, szProcQualifier, cbProcQualifier, szProcOwner, cbProcOwner, szProcName, cbProcName, szColumnName, cbColumnName );
  } else {
    sqlrc = ILE_SQLProcedureColumnsW( hstmt, szProcQualifier, cbProcQualifier, szProcOwner, cbProcOwner, szProcName, cbProcName, szColumnName, cbColumnName );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLProcedures( SQLHSTMT  hstmt, SQLCHAR * szProcQualifier, SQLSMALLINT  cbProcQualifier, SQLCHAR * szProcOwner, SQLSMALLINT  cbProcOwner, SQLCHAR * szProcName, SQLSMALLINT  cbProcName )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLProcedures( hstmt, szProcQualifier, cbProcQualifier, szProcOwner, cbProcOwner, szProcName, cbProcName );
  } else {
    sqlrc = ILE_SQLProcedures( hstmt, szProcQualifier, cbProcQualifier, szProcOwner, cbProcOwner, szProcName, cbProcName );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLProceduresW( SQLHSTMT  hstmt, SQLWCHAR * szProcQualifier, SQLSMALLINT  cbProcQualifier, SQLWCHAR * szProcOwner, SQLSMALLINT  cbProcOwner, SQLWCHAR * szProcName, SQLSMALLINT  cbProcName )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLProceduresW( hstmt, szProcQualifier, cbProcQualifier, szProcOwner, cbProcOwner, szProcName, cbProcName );
  } else {
    sqlrc = ILE_SQLProceduresW( hstmt, szProcQualifier, cbProcQualifier, szProcOwner, cbProcOwner, szProcName, cbProcName );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLPutData( SQLHSTMT  hstmt, SQLPOINTER  Data, SQLINTEGER  SLen )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLPutData( hstmt, Data, SLen );
  } else {
    sqlrc = ILE_SQLPutData( hstmt, Data, SLen );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLReleaseEnv( SQLHENV  henv )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLReleaseEnv( henv );
  } else {
    sqlrc = ILE_SQLReleaseEnv( henv );
  }
  return sqlrc;
}
SQLRETURN SQLRowCount( SQLHSTMT  hstmt, SQLINTEGER * pcrow )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLRowCount( hstmt, pcrow );
  } else {
    sqlrc = ILE_SQLRowCount( hstmt, pcrow );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLSetConnectAttr( SQLHDBC  hdbc, SQLINTEGER  attrib, SQLPOINTER  vParam, SQLINTEGER  inlen )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hdbc, 0);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLSetConnectAttr( hdbc, attrib, vParam, inlen );
  } else {
    sqlrc = ILE_SQLSetConnectAttr( hdbc, attrib, vParam, inlen );
  }
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
SQLRETURN SQLSetConnectAttrW( SQLHDBC  hdbc, SQLINTEGER  attrib, SQLPOINTER  vParam, SQLINTEGER  inlen )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hdbc, 0);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLSetConnectAttrW( hdbc, attrib, vParam, inlen );
  } else {
    sqlrc = ILE_SQLSetConnectAttrW( hdbc, attrib, vParam, inlen );
  }
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
SQLRETURN SQLSetConnectOption( SQLHDBC  hdbc, SQLSMALLINT  fOption, SQLPOINTER  vParam )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hdbc, 0);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLSetConnectOption( hdbc, fOption, vParam );
  } else {
    sqlrc = ILE_SQLSetConnectOption( hdbc, fOption, vParam );
  }
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
SQLRETURN SQLSetConnectOptionW( SQLHDBC  hdbc, SQLSMALLINT  fOption, SQLPOINTER  vParam )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hdbc, 0);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLSetConnectOptionW( hdbc, fOption, vParam );
  } else {
    sqlrc = ILE_SQLSetConnectOptionW( hdbc, fOption, vParam );
  }
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
SQLRETURN SQLSetCursorName( SQLHSTMT  hstmt, SQLCHAR * szCursor, SQLSMALLINT  cbCursor )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLSetCursorName( hstmt, szCursor, cbCursor );
  } else {
    sqlrc = ILE_SQLSetCursorName( hstmt, szCursor, cbCursor );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLSetCursorNameW( SQLHSTMT  hstmt, SQLWCHAR * szCursor, SQLSMALLINT  cbCursor )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLSetCursorNameW( hstmt, szCursor, cbCursor );
  } else {
    sqlrc = ILE_SQLSetCursorNameW( hstmt, szCursor, cbCursor );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLSetDescField( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  fID, SQLPOINTER  Value, SQLINTEGER  buffLen )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hdesc, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLSetDescField( hdesc, rcdNum, fID, Value, buffLen );
  } else {
    sqlrc = ILE_SQLSetDescField( hdesc, rcdNum, fID, Value, buffLen );
  }
  init_table_unlock(hdesc, 1);
  return sqlrc;
}
SQLRETURN SQLSetDescFieldW( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  fID, SQLPOINTER  Value, SQLINTEGER  buffLen )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hdesc, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLSetDescFieldW( hdesc, rcdNum, fID, Value, buffLen );
  } else {
    sqlrc = ILE_SQLSetDescFieldW( hdesc, rcdNum, fID, Value, buffLen );
  }
  init_table_unlock(hdesc, 1);
  return sqlrc;
}
SQLRETURN SQLSetDescRec( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  Type, SQLSMALLINT  subType, SQLINTEGER  fLength, SQLSMALLINT  fPrec, SQLSMALLINT  fScale, SQLPOINTER  Value, SQLINTEGER * sLength, SQLINTEGER * indic )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hdesc, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLSetDescRec( hdesc, rcdNum, Type, subType, fLength, fPrec, fScale, Value, sLength, indic );
  } else {
    sqlrc = ILE_SQLSetDescRec( hdesc, rcdNum, Type, subType, fLength, fPrec, fScale, Value, sLength, indic );
  }
  init_table_unlock(hdesc, 1);
  return sqlrc;
}
SQLRETURN SQLSetEnvAttr( SQLHENV  hEnv, SQLINTEGER  fAttribute, SQLPOINTER  pParam, SQLINTEGER  cbParam )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLSetEnvAttr( hEnv, fAttribute, pParam, cbParam );
  } else {
    sqlrc = ILE_SQLSetEnvAttr( hEnv, fAttribute, pParam, cbParam );
  }
  return sqlrc;
}
SQLRETURN SQLSetParam( SQLHSTMT  hstmt, SQLSMALLINT  ipar, SQLSMALLINT  fCType, SQLSMALLINT  fSqlType, SQLINTEGER  cbColDef, SQLSMALLINT  ibScale, SQLPOINTER  rgbValue, SQLINTEGER * pcbValue )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLSetParam( hstmt, ipar, fCType, fSqlType, cbColDef, ibScale, rgbValue, pcbValue );
  } else {
    sqlrc = ILE_SQLSetParam( hstmt, ipar, fCType, fSqlType, cbColDef, ibScale, rgbValue, pcbValue );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLSetStmtAttr( SQLHSTMT  hstmt, SQLINTEGER  fAttr, SQLPOINTER  pParam, SQLINTEGER  vParam )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLSetStmtAttr( hstmt, fAttr, pParam, vParam );
  } else {
    sqlrc = ILE_SQLSetStmtAttr( hstmt, fAttr, pParam, vParam );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLSetStmtAttrW( SQLHSTMT  hstmt, SQLINTEGER  fAttr, SQLPOINTER  pParam, SQLINTEGER  vParam )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLSetStmtAttrW( hstmt, fAttr, pParam, vParam );
  } else {
    sqlrc = ILE_SQLSetStmtAttrW( hstmt, fAttr, pParam, vParam );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLSetStmtOption( SQLHSTMT  hstmt, SQLSMALLINT  fOption, SQLPOINTER  vParam )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLSetStmtOption( hstmt, fOption, vParam );
  } else {
    sqlrc = ILE_SQLSetStmtOption( hstmt, fOption, vParam );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLSetStmtOptionW( SQLHSTMT  hstmt, SQLSMALLINT  fOption, SQLPOINTER  vParam )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLSetStmtOptionW( hstmt, fOption, vParam );
  } else {
    sqlrc = ILE_SQLSetStmtOptionW( hstmt, fOption, vParam );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLSpecialColumns( SQLHSTMT  hstmt, SQLSMALLINT  fColType, SQLCHAR * szTableQual, SQLSMALLINT  cbTableQual, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLSMALLINT  fScope, SQLSMALLINT  fNullable )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLSpecialColumns( hstmt, fColType, szTableQual, cbTableQual, szTableOwner, cbTableOwner, szTableName, cbTableName, fScope, fNullable );
  } else {
    sqlrc = ILE_SQLSpecialColumns( hstmt, fColType, szTableQual, cbTableQual, szTableOwner, cbTableOwner, szTableName, cbTableName, fScope, fNullable );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLSpecialColumnsW( SQLHSTMT  hstmt, SQLSMALLINT  fColType, SQLWCHAR * szTableQual, SQLSMALLINT  cbTableQual, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName, SQLSMALLINT  fScope, SQLSMALLINT  fNullable )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLSpecialColumnsW( hstmt, fColType, szTableQual, cbTableQual, szTableOwner, cbTableOwner, szTableName, cbTableName, fScope, fNullable );
  } else {
    sqlrc = ILE_SQLSpecialColumnsW( hstmt, fColType, szTableQual, cbTableQual, szTableOwner, cbTableOwner, szTableName, cbTableName, fScope, fNullable );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLStartTran( SQLSMALLINT  htype, SQLHENV  henv, SQLINTEGER  mode, SQLINTEGER  clevel )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLStartTran( htype, henv, mode, clevel );
  } else {
    sqlrc = ILE_SQLStartTran( htype, henv, mode, clevel );
  }
  return sqlrc;
}
SQLRETURN SQLStatistics( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLSMALLINT  fUnique, SQLSMALLINT  fres )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLStatistics( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName, fUnique, fres );
  } else {
    sqlrc = ILE_SQLStatistics( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName, fUnique, fres );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLStatisticsW( SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName, SQLSMALLINT  fUnique, SQLSMALLINT  fres )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLStatisticsW( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName, fUnique, fres );
  } else {
    sqlrc = ILE_SQLStatisticsW( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName, fUnique, fres );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLTablePrivileges( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLTablePrivileges( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName );
  } else {
    sqlrc = ILE_SQLTablePrivileges( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLTablePrivilegesW( SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLTablePrivilegesW( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName );
  } else {
    sqlrc = ILE_SQLTablePrivilegesW( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLTables( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLCHAR * szTableType, SQLSMALLINT  cbTableType )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLTables( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName, szTableType, cbTableType );
  } else {
    sqlrc = ILE_SQLTables( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName, szTableType, cbTableType );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLTablesW( SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName, SQLWCHAR * szTableType, SQLSMALLINT  cbTableType )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLTablesW( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName, szTableType, cbTableType );
  } else {
    sqlrc = ILE_SQLTablesW( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName, szTableType, cbTableType );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQLTransact( SQLHENV  henv, SQLHDBC  hdbc, SQLSMALLINT  fType )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  if (i_am_big_chicken_flag) {
    sqlrc = libdb400_SQLTransact( henv, hdbc, fType );
  } else {
    sqlrc = ILE_SQLTransact( henv, hdbc, fType );
  }
  return sqlrc;
}
SQLRETURN SQL400ToUtf8( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  inccsid )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hdbc, 0);
  sqlrc = custom_SQL400ToUtf8( hdbc, inparm, inlen, outparm, outlen, inccsid );
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
SQLRETURN SQL400FromUtf8( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  outccsid )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hdbc, 0);
  sqlrc = custom_SQL400FromUtf8( hdbc, inparm, inlen, outparm, outlen, outccsid );
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
SQLRETURN SQL400ToUtf16( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  inccsid )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hdbc, 0);
  sqlrc = custom_SQL400ToUtf16( hdbc, inparm, inlen, outparm, outlen, inccsid );
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
SQLRETURN SQL400FromUtf16( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  outccsid )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hdbc, 0);
  sqlrc = custom_SQL400FromUtf16( hdbc, inparm, inlen, outparm, outlen, outccsid );
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
SQLRETURN SQL400AddAttr( SQLINTEGER  scope, SQLINTEGER  attrib, SQLPOINTER  vParam, SQLINTEGER  inlen, SQLINTEGER  onerr, SQLINTEGER  flag, SQLPOINTER  options )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  sqlrc = custom_SQL400AddAttr( scope, attrib, vParam, inlen, onerr, flag, options );
  return sqlrc;
}
SQLRETURN SQL400SetAttr( SQLINTEGER  scope, SQLHANDLE  hndl, SQLINTEGER  flag, SQLPOINTER  options )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  sqlrc = custom_SQL400SetAttr( scope, hndl, flag, options );
  return sqlrc;
}
SQLRETURN SQL400Environment( SQLINTEGER * ohnd, SQLPOINTER  options )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  sqlrc = custom_SQL400Environment( ohnd, options );
  return sqlrc;
}
SQLRETURN SQL400Connect( SQLHENV  henv, SQLCHAR * db, SQLCHAR * uid, SQLCHAR * pwd, SQLINTEGER * ohnd, SQLPOINTER  options )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  sqlrc = custom_SQL400Connect( henv, db, uid, pwd, ohnd, options );
  return sqlrc;
}
SQLRETURN SQL400AddCVar( SQLSMALLINT  icol, SQLSMALLINT  inOutType, SQLSMALLINT  pfSqlCType, SQLPOINTER  pfSqlCValue, SQLINTEGER * indPtr, SQLPOINTER  parms )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  sqlrc = custom_SQL400AddCVar( icol, inOutType, pfSqlCType, pfSqlCValue, indPtr, parms );
  return sqlrc;
}
SQLRETURN SQL400AddDesc( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  flag, SQLPOINTER  descs )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  sqlrc = custom_SQL400AddDesc( hstmt, icol, flag, descs );
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQL400Execute( SQLHSTMT  hstmt, SQLPOINTER  parms, SQLPOINTER  desc_parms )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  sqlrc = custom_SQL400Execute( hstmt, parms, desc_parms );
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQL400Fetch( SQLHSTMT  hstmt, SQLINTEGER  start_row, SQLPOINTER  cols, SQLPOINTER  desc_cols )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  sqlrc = custom_SQL400Fetch( hstmt, start_row, cols, desc_cols );
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
SQLRETURN SQL400Stmt2Hdbc( SQLHSTMT  hstmt, SQLINTEGER * ohnd )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  init_table_lock(hstmt, 1);
  sqlrc = custom_SQL400Stmt2Hdbc( hstmt, ohnd );
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLBindColThread (void *ptr)
{
  SQLBindColStruct * myptr = (SQLBindColStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLBindCol( myptr->hstmt, myptr->icol, myptr->iType, myptr->rgbValue, myptr->cbValueMax, myptr->pcbValue );
  } else {
    myptr->sqlrc = ILE_SQLBindCol( myptr->hstmt, myptr->icol, myptr->iType, myptr->rgbValue, myptr->cbValueMax, myptr->pcbValue );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLBindColCallback(SQLBindColStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLBindColStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLBindColAsync ( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  iType, SQLPOINTER  rgbValue, SQLINTEGER  cbValueMax, SQLINTEGER * pcbValue, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLBindColStruct * myptr = (SQLBindColStruct *) malloc(sizeof(SQLBindColStruct));
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->icol = icol;
  myptr->iType = iType;
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLBindFileToCol( myptr->hstmt, myptr->icol, myptr->fName, myptr->fNameLen, myptr->fOptions, myptr->fValueMax, myptr->sLen, myptr->pcbValue );
  } else {
    myptr->sqlrc = ILE_SQLBindFileToCol( myptr->hstmt, myptr->icol, myptr->fName, myptr->fNameLen, myptr->fOptions, myptr->fValueMax, myptr->sLen, myptr->pcbValue );
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLBindFileToParam( myptr->hstmt, myptr->ipar, myptr->iType, myptr->fName, myptr->fNameLen, myptr->fOptions, myptr->fValueMax, myptr->pcbValue );
  } else {
    myptr->sqlrc = ILE_SQLBindFileToParam( myptr->hstmt, myptr->ipar, myptr->iType, myptr->fName, myptr->fNameLen, myptr->fOptions, myptr->fValueMax, myptr->pcbValue );
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLBindParam( myptr->hstmt, myptr->iparm, myptr->iType, myptr->pType, myptr->pLen, myptr->pScale, myptr->pData, myptr->pcbValue );
  } else {
    myptr->sqlrc = ILE_SQLBindParam( myptr->hstmt, myptr->iparm, myptr->iType, myptr->pType, myptr->pLen, myptr->pScale, myptr->pData, myptr->pcbValue );
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLBindParameter( myptr->hstmt, myptr->ipar, myptr->fParamType, myptr->fCType, myptr->fSQLType, myptr->pLen, myptr->pScale, myptr->pData, myptr->cbValueMax, myptr->pcbValue );
  } else {
    myptr->sqlrc = ILE_SQLBindParameter( myptr->hstmt, myptr->ipar, myptr->fParamType, myptr->fCType, myptr->fSQLType, myptr->pLen, myptr->pScale, myptr->pData, myptr->cbValueMax, myptr->pcbValue );
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLCancel( myptr->hstmt );
  } else {
    myptr->sqlrc = ILE_SQLCancel( myptr->hstmt );
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLCloseCursor( myptr->hstmt );
  } else {
    myptr->sqlrc = ILE_SQLCloseCursor( myptr->hstmt );
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLCloseCursorStruct *) NULL;
  }
  return myptr;
}
void * SQLColAttributeThread (void *ptr)
{
  SQLColAttributeStruct * myptr = (SQLColAttributeStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLColAttribute( myptr->hstmt, myptr->icol, myptr->fDescType, myptr->rgbDesc, myptr->cbDescMax, myptr->pcbDesc, myptr->pfDesc );
  } else {
    myptr->sqlrc = ILE_SQLColAttribute( myptr->hstmt, myptr->icol, myptr->fDescType, myptr->rgbDesc, myptr->cbDescMax, myptr->pcbDesc, myptr->pfDesc );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLColAttributeCallback(SQLColAttributeStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLColAttributeStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLColAttributeAsync ( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fDescType, SQLPOINTER  rgbDesc, SQLSMALLINT  cbDescMax, SQLSMALLINT * pcbDesc, SQLPOINTER  pfDesc, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLColAttributeStruct * myptr = (SQLColAttributeStruct *) malloc(sizeof(SQLColAttributeStruct));
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->icol = icol;
  myptr->fDescType = fDescType;
  myptr->rgbDesc = rgbDesc;
  myptr->cbDescMax = cbDescMax;
  myptr->pcbDesc = pcbDesc;
  myptr->pfDesc = pfDesc;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLColAttributeThread, (void *)myptr);
  return tid;
}
SQLColAttributeStruct * SQLColAttributeJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLColAttributeStruct * myptr = (SQLColAttributeStruct *) NULL;
  int active = 0;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLColAttributeStruct *) NULL;
  }
  return myptr;
}
void * SQLColAttributeWThread (void *ptr)
{
  SQLColAttributeWStruct * myptr = (SQLColAttributeWStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLColAttributeW( myptr->hstmt, myptr->icol, myptr->fDescType, myptr->rgbDesc, myptr->cbDescMax, myptr->pcbDesc, myptr->pfDesc );
  } else {
    myptr->sqlrc = ILE_SQLColAttributeW( myptr->hstmt, myptr->icol, myptr->fDescType, myptr->rgbDesc, myptr->cbDescMax, myptr->pcbDesc, myptr->pfDesc );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLColAttributeWCallback(SQLColAttributeWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLColAttributeWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLColAttributeWAsync ( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fDescType, SQLPOINTER  rgbDesc, SQLSMALLINT  cbDescMax, SQLSMALLINT * pcbDesc, SQLPOINTER  pfDesc, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLColAttributeWStruct * myptr = (SQLColAttributeWStruct *) malloc(sizeof(SQLColAttributeWStruct));
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->icol = icol;
  myptr->fDescType = fDescType;
  myptr->rgbDesc = rgbDesc;
  myptr->cbDescMax = cbDescMax;
  myptr->pcbDesc = pcbDesc;
  myptr->pfDesc = pfDesc;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLColAttributeWThread, (void *)myptr);
  return tid;
}
SQLColAttributeWStruct * SQLColAttributeWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLColAttributeWStruct * myptr = (SQLColAttributeWStruct *) NULL;
  int active = 0;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLColAttributeWStruct *) NULL;
  }
  return myptr;
}
void * SQLColAttributesThread (void *ptr)
{
  SQLColAttributesStruct * myptr = (SQLColAttributesStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLColAttributes( myptr->hstmt, myptr->icol, myptr->fDescType, myptr->rgbDesc, myptr->cbDescMax, myptr->pcbDesc, myptr->pfDesc );
  } else {
    myptr->sqlrc = ILE_SQLColAttributes( myptr->hstmt, myptr->icol, myptr->fDescType, myptr->rgbDesc, myptr->cbDescMax, myptr->pcbDesc, myptr->pfDesc );
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLColAttributesStruct *) NULL;
  }
  return myptr;
}
void * SQLColAttributesWThread (void *ptr)
{
  SQLColAttributesWStruct * myptr = (SQLColAttributesWStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLColAttributesW( myptr->hstmt, myptr->icol, myptr->fDescType, myptr->rgbDesc, myptr->cbDescMax, myptr->pcbDesc, myptr->pfDesc );
  } else {
    myptr->sqlrc = ILE_SQLColAttributesW( myptr->hstmt, myptr->icol, myptr->fDescType, myptr->rgbDesc, myptr->cbDescMax, myptr->pcbDesc, myptr->pfDesc );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLColAttributesWCallback(SQLColAttributesWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLColAttributesWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLColAttributesWAsync ( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fDescType, SQLWCHAR * rgbDesc, SQLINTEGER  cbDescMax, SQLINTEGER * pcbDesc, SQLINTEGER * pfDesc, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLColAttributesWStruct * myptr = (SQLColAttributesWStruct *) malloc(sizeof(SQLColAttributesWStruct));
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->icol = icol;
  myptr->fDescType = fDescType;
  myptr->rgbDesc = rgbDesc;
  myptr->cbDescMax = cbDescMax;
  myptr->pcbDesc = pcbDesc;
  myptr->pfDesc = pfDesc;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLColAttributesWThread, (void *)myptr);
  return tid;
}
SQLColAttributesWStruct * SQLColAttributesWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLColAttributesWStruct * myptr = (SQLColAttributesWStruct *) NULL;
  int active = 0;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLColAttributesWStruct *) NULL;
  }
  return myptr;
}
void * SQLColumnPrivilegesThread (void *ptr)
{
  SQLColumnPrivilegesStruct * myptr = (SQLColumnPrivilegesStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLColumnPrivileges( myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName, myptr->szColumnName, myptr->cbColumnName );
  } else {
    myptr->sqlrc = ILE_SQLColumnPrivileges( myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName, myptr->szColumnName, myptr->cbColumnName );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLColumnPrivilegesCallback(SQLColumnPrivilegesStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLColumnPrivilegesStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLColumnPrivilegesAsync ( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLCHAR * szColumnName, SQLSMALLINT  cbColumnName, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLColumnPrivilegesStruct * myptr = (SQLColumnPrivilegesStruct *) malloc(sizeof(SQLColumnPrivilegesStruct));
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->szTableQualifier = szTableQualifier;
  myptr->cbTableQualifier = cbTableQualifier;
  myptr->szTableOwner = szTableOwner;
  myptr->cbTableOwner = cbTableOwner;
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLColumnPrivilegesStruct *) NULL;
  }
  return myptr;
}
void * SQLColumnPrivilegesWThread (void *ptr)
{
  SQLColumnPrivilegesWStruct * myptr = (SQLColumnPrivilegesWStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLColumnPrivilegesW( myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName, myptr->szColumnName, myptr->cbColumnName );
  } else {
    myptr->sqlrc = ILE_SQLColumnPrivilegesW( myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName, myptr->szColumnName, myptr->cbColumnName );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLColumnPrivilegesWCallback(SQLColumnPrivilegesWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLColumnPrivilegesWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLColumnPrivilegesWAsync ( SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName, SQLWCHAR * szColumnName, SQLSMALLINT  cbColumnName, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLColumnPrivilegesWStruct * myptr = (SQLColumnPrivilegesWStruct *) malloc(sizeof(SQLColumnPrivilegesWStruct));
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->szTableQualifier = szTableQualifier;
  myptr->cbTableQualifier = cbTableQualifier;
  myptr->szTableOwner = szTableOwner;
  myptr->cbTableOwner = cbTableOwner;
  myptr->szTableName = szTableName;
  myptr->cbTableName = cbTableName;
  myptr->szColumnName = szColumnName;
  myptr->cbColumnName = cbColumnName;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLColumnPrivilegesWThread, (void *)myptr);
  return tid;
}
SQLColumnPrivilegesWStruct * SQLColumnPrivilegesWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLColumnPrivilegesWStruct * myptr = (SQLColumnPrivilegesWStruct *) NULL;
  int active = 0;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLColumnPrivilegesWStruct *) NULL;
  }
  return myptr;
}
void * SQLColumnsThread (void *ptr)
{
  SQLColumnsStruct * myptr = (SQLColumnsStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLColumns( myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName, myptr->szColumnName, myptr->cbColumnName );
  } else {
    myptr->sqlrc = ILE_SQLColumns( myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName, myptr->szColumnName, myptr->cbColumnName );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLColumnsCallback(SQLColumnsStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLColumnsStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLColumnsAsync ( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLCHAR * szColumnName, SQLSMALLINT  cbColumnName, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLColumnsStruct * myptr = (SQLColumnsStruct *) malloc(sizeof(SQLColumnsStruct));
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->szTableQualifier = szTableQualifier;
  myptr->cbTableQualifier = cbTableQualifier;
  myptr->szTableOwner = szTableOwner;
  myptr->cbTableOwner = cbTableOwner;
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLColumnsStruct *) NULL;
  }
  return myptr;
}
void * SQLColumnsWThread (void *ptr)
{
  SQLColumnsWStruct * myptr = (SQLColumnsWStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLColumnsW( myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName, myptr->szColumnName, myptr->cbColumnName );
  } else {
    myptr->sqlrc = ILE_SQLColumnsW( myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName, myptr->szColumnName, myptr->cbColumnName );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLColumnsWCallback(SQLColumnsWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLColumnsWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLColumnsWAsync ( SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName, SQLWCHAR * szColumnName, SQLSMALLINT  cbColumnName, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLColumnsWStruct * myptr = (SQLColumnsWStruct *) malloc(sizeof(SQLColumnsWStruct));
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->szTableQualifier = szTableQualifier;
  myptr->cbTableQualifier = cbTableQualifier;
  myptr->szTableOwner = szTableOwner;
  myptr->cbTableOwner = cbTableOwner;
  myptr->szTableName = szTableName;
  myptr->cbTableName = cbTableName;
  myptr->szColumnName = szColumnName;
  myptr->cbColumnName = cbColumnName;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLColumnsWThread, (void *)myptr);
  return tid;
}
SQLColumnsWStruct * SQLColumnsWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLColumnsWStruct * myptr = (SQLColumnsWStruct *) NULL;
  int active = 0;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLColumnsWStruct *) NULL;
  }
  return myptr;
}
void * SQLConnectThread (void *ptr)
{
  SQLConnectStruct * myptr = (SQLConnectStruct *) ptr;
  init_table_lock(myptr->hdbc, 0);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLConnect( myptr->hdbc, myptr->szDSN, myptr->cbDSN, myptr->szUID, myptr->cbUID, myptr->szAuthStr, myptr->cbAuthStr );
  } else {
    myptr->sqlrc = ILE_SQLConnect( myptr->hdbc, myptr->szDSN, myptr->cbDSN, myptr->szUID, myptr->cbUID, myptr->szAuthStr, myptr->cbAuthStr );
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hdbc, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLConnectStruct *) NULL;
  }
  return myptr;
}
void * SQLConnectWThread (void *ptr)
{
  SQLConnectWStruct * myptr = (SQLConnectWStruct *) ptr;
  init_table_lock(myptr->hdbc, 0);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLConnectW( myptr->hdbc, myptr->szDSN, myptr->cbDSN, myptr->szUID, myptr->cbUID, myptr->szAuthStr, myptr->cbAuthStr );
  } else {
    myptr->sqlrc = ILE_SQLConnectW( myptr->hdbc, myptr->szDSN, myptr->cbDSN, myptr->szUID, myptr->cbUID, myptr->szAuthStr, myptr->cbAuthStr );
  }
  init_table_unlock(myptr->hdbc, 0);
  /* void SQLConnectWCallback(SQLConnectWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLConnectWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLConnectWAsync ( SQLHDBC  hdbc, SQLWCHAR * szDSN, SQLSMALLINT  cbDSN, SQLWCHAR * szUID, SQLSMALLINT  cbUID, SQLWCHAR * szAuthStr, SQLSMALLINT  cbAuthStr, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLConnectWStruct * myptr = (SQLConnectWStruct *) malloc(sizeof(SQLConnectWStruct));
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdbc = hdbc;
  myptr->szDSN = szDSN;
  myptr->cbDSN = cbDSN;
  myptr->szUID = szUID;
  myptr->cbUID = cbUID;
  myptr->szAuthStr = szAuthStr;
  myptr->cbAuthStr = cbAuthStr;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLConnectWThread, (void *)myptr);
  return tid;
}
SQLConnectWStruct * SQLConnectWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLConnectWStruct * myptr = (SQLConnectWStruct *) NULL;
  int active = 0;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hdbc, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLConnectWStruct *) NULL;
  }
  return myptr;
}
void * SQLCopyDescThread (void *ptr)
{
  SQLCopyDescStruct * myptr = (SQLCopyDescStruct *) ptr;
  init_table_lock(myptr->sDesc, 1);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLCopyDesc( myptr->sDesc, myptr->tDesc );
  } else {
    myptr->sqlrc = ILE_SQLCopyDesc( myptr->sDesc, myptr->tDesc );
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLDataSources( myptr->henv, myptr->fDirection, myptr->szDSN, myptr->cbDSNMax, myptr->pcbDSN, myptr->szDescription, myptr->cbDescriptionMax, myptr->pcbDescription );
  } else {
    myptr->sqlrc = ILE_SQLDataSources( myptr->henv, myptr->fDirection, myptr->szDSN, myptr->cbDSNMax, myptr->pcbDSN, myptr->szDescription, myptr->cbDescriptionMax, myptr->pcbDescription );
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  /* not lock */
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLDataSourcesStruct *) NULL;
  }
  return myptr;
}
void * SQLDataSourcesWThread (void *ptr)
{
  SQLDataSourcesWStruct * myptr = (SQLDataSourcesWStruct *) ptr;
  /* not lock */
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLDataSourcesW( myptr->henv, myptr->fDirection, myptr->szDSN, myptr->cbDSNMax, myptr->pcbDSN, myptr->szDescription, myptr->cbDescriptionMax, myptr->pcbDescription );
  } else {
    myptr->sqlrc = ILE_SQLDataSourcesW( myptr->henv, myptr->fDirection, myptr->szDSN, myptr->cbDSNMax, myptr->pcbDSN, myptr->szDescription, myptr->cbDescriptionMax, myptr->pcbDescription );
  }
  /* not lock */
  /* void SQLDataSourcesWCallback(SQLDataSourcesWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLDataSourcesWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLDataSourcesWAsync ( SQLHENV  henv, SQLSMALLINT  fDirection, SQLWCHAR * szDSN, SQLSMALLINT  cbDSNMax, SQLSMALLINT * pcbDSN, SQLWCHAR * szDescription, SQLSMALLINT  cbDescriptionMax, SQLSMALLINT * pcbDescription, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLDataSourcesWStruct * myptr = (SQLDataSourcesWStruct *) malloc(sizeof(SQLDataSourcesWStruct));
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  rc = pthread_create(&tid, NULL, SQLDataSourcesWThread, (void *)myptr);
  return tid;
}
SQLDataSourcesWStruct * SQLDataSourcesWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLDataSourcesWStruct * myptr = (SQLDataSourcesWStruct *) NULL;
  int active = 0;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  /* not lock */
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLDataSourcesWStruct *) NULL;
  }
  return myptr;
}
void * SQLDescribeColThread (void *ptr)
{
  SQLDescribeColStruct * myptr = (SQLDescribeColStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLDescribeCol( myptr->hstmt, myptr->icol, myptr->szColName, myptr->cbColNameMax, myptr->pcbColName, myptr->pfSqlType, myptr->pcbColDef, myptr->pibScale, myptr->pfNullable );
  } else {
    myptr->sqlrc = ILE_SQLDescribeCol( myptr->hstmt, myptr->icol, myptr->szColName, myptr->cbColNameMax, myptr->pcbColName, myptr->pfSqlType, myptr->pcbColDef, myptr->pibScale, myptr->pfNullable );
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLDescribeColStruct *) NULL;
  }
  return myptr;
}
void * SQLDescribeColWThread (void *ptr)
{
  SQLDescribeColWStruct * myptr = (SQLDescribeColWStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLDescribeColW( myptr->hstmt, myptr->icol, myptr->szColName, myptr->cbColNameMax, myptr->pcbColName, myptr->pfSqlType, myptr->pcbColDef, myptr->pibScale, myptr->pfNullable );
  } else {
    myptr->sqlrc = ILE_SQLDescribeColW( myptr->hstmt, myptr->icol, myptr->szColName, myptr->cbColNameMax, myptr->pcbColName, myptr->pfSqlType, myptr->pcbColDef, myptr->pibScale, myptr->pfNullable );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLDescribeColWCallback(SQLDescribeColWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLDescribeColWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLDescribeColWAsync ( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLWCHAR * szColName, SQLSMALLINT  cbColNameMax, SQLSMALLINT * pcbColName, SQLSMALLINT * pfSqlType, SQLINTEGER * pcbColDef, SQLSMALLINT * pibScale, SQLSMALLINT * pfNullable, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLDescribeColWStruct * myptr = (SQLDescribeColWStruct *) malloc(sizeof(SQLDescribeColWStruct));
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  rc = pthread_create(&tid, NULL, SQLDescribeColWThread, (void *)myptr);
  return tid;
}
SQLDescribeColWStruct * SQLDescribeColWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLDescribeColWStruct * myptr = (SQLDescribeColWStruct *) NULL;
  int active = 0;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLDescribeColWStruct *) NULL;
  }
  return myptr;
}
void * SQLDescribeParamThread (void *ptr)
{
  SQLDescribeParamStruct * myptr = (SQLDescribeParamStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLDescribeParam( myptr->hstmt, myptr->ipar, myptr->pfSqlType, myptr->pcbColDef, myptr->pibScale, myptr->pfNullable );
  } else {
    myptr->sqlrc = ILE_SQLDescribeParam( myptr->hstmt, myptr->ipar, myptr->pfSqlType, myptr->pcbColDef, myptr->pibScale, myptr->pfNullable );
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLDisconnect( myptr->hdbc );
  } else {
    myptr->sqlrc = ILE_SQLDisconnect( myptr->hdbc );
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLDriverConnect( myptr->hdbc, myptr->hwnd, myptr->szConnStrIn, myptr->cbConnStrin, myptr->szConnStrOut, myptr->cbConnStrOutMax, myptr->pcbConnStrOut, myptr->fDriverCompletion );
  } else {
    myptr->sqlrc = ILE_SQLDriverConnect( myptr->hdbc, myptr->hwnd, myptr->szConnStrIn, myptr->cbConnStrin, myptr->szConnStrOut, myptr->cbConnStrOutMax, myptr->pcbConnStrOut, myptr->fDriverCompletion );
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hdbc, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLDriverConnectStruct *) NULL;
  }
  return myptr;
}
void * SQLDriverConnectWThread (void *ptr)
{
  SQLDriverConnectWStruct * myptr = (SQLDriverConnectWStruct *) ptr;
  init_table_lock(myptr->hdbc, 0);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLDriverConnectW( myptr->hdbc, myptr->hwnd, myptr->szConnStrIn, myptr->cbConnStrin, myptr->szConnStrOut, myptr->cbConnStrOutMax, myptr->pcbConnStrOut, myptr->fDriverCompletion );
  } else {
    myptr->sqlrc = ILE_SQLDriverConnectW( myptr->hdbc, myptr->hwnd, myptr->szConnStrIn, myptr->cbConnStrin, myptr->szConnStrOut, myptr->cbConnStrOutMax, myptr->pcbConnStrOut, myptr->fDriverCompletion );
  }
  init_table_unlock(myptr->hdbc, 0);
  /* void SQLDriverConnectWCallback(SQLDriverConnectWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLDriverConnectWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLDriverConnectWAsync ( SQLHDBC  hdbc, SQLPOINTER  hwnd, SQLWCHAR * szConnStrIn, SQLSMALLINT  cbConnStrin, SQLWCHAR * szConnStrOut, SQLSMALLINT  cbConnStrOutMax, SQLSMALLINT * pcbConnStrOut, SQLSMALLINT  fDriverCompletion, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLDriverConnectWStruct * myptr = (SQLDriverConnectWStruct *) malloc(sizeof(SQLDriverConnectWStruct));
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  rc = pthread_create(&tid, NULL, SQLDriverConnectWThread, (void *)myptr);
  return tid;
}
SQLDriverConnectWStruct * SQLDriverConnectWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLDriverConnectWStruct * myptr = (SQLDriverConnectWStruct *) NULL;
  int active = 0;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hdbc, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLDriverConnectWStruct *) NULL;
  }
  return myptr;
}
void * SQLEndTranThread (void *ptr)
{
  SQLEndTranStruct * myptr = (SQLEndTranStruct *) ptr;
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLEndTran( myptr->htype, myptr->henv, myptr->ctype );
  } else {
    myptr->sqlrc = ILE_SQLEndTran( myptr->htype, myptr->henv, myptr->ctype );
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLError( myptr->henv, myptr->hdbc, myptr->hstmt, myptr->szSqlState, myptr->pfNativeError, myptr->szErrorMsg, myptr->cbErrorMsgMax, myptr->pcbErrorMsg );
  } else {
    myptr->sqlrc = ILE_SQLError( myptr->henv, myptr->hdbc, myptr->hstmt, myptr->szSqlState, myptr->pfNativeError, myptr->szErrorMsg, myptr->cbErrorMsgMax, myptr->pcbErrorMsg );
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  /* not lock */
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLErrorStruct *) NULL;
  }
  return myptr;
}
void * SQLErrorWThread (void *ptr)
{
  SQLErrorWStruct * myptr = (SQLErrorWStruct *) ptr;
  /* not lock */
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLErrorW( myptr->henv, myptr->hdbc, myptr->hstmt, myptr->szSqlState, myptr->pfNativeError, myptr->szErrorMsg, myptr->cbErrorMsgMax, myptr->pcbErrorMsg );
  } else {
    myptr->sqlrc = ILE_SQLErrorW( myptr->henv, myptr->hdbc, myptr->hstmt, myptr->szSqlState, myptr->pfNativeError, myptr->szErrorMsg, myptr->cbErrorMsgMax, myptr->pcbErrorMsg );
  }
  /* not lock */
  /* void SQLErrorWCallback(SQLErrorWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLErrorWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLErrorWAsync ( SQLHENV  henv, SQLHDBC  hdbc, SQLHSTMT  hstmt, SQLWCHAR * szSqlState, SQLINTEGER * pfNativeError, SQLWCHAR * szErrorMsg, SQLSMALLINT  cbErrorMsgMax, SQLSMALLINT * pcbErrorMsg, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLErrorWStruct * myptr = (SQLErrorWStruct *) malloc(sizeof(SQLErrorWStruct));
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  rc = pthread_create(&tid, NULL, SQLErrorWThread, (void *)myptr);
  return tid;
}
SQLErrorWStruct * SQLErrorWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLErrorWStruct * myptr = (SQLErrorWStruct *) NULL;
  int active = 0;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  /* not lock */
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLErrorWStruct *) NULL;
  }
  return myptr;
}
void * SQLExecDirectThread (void *ptr)
{
  SQLExecDirectStruct * myptr = (SQLExecDirectStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLExecDirect( myptr->hstmt, myptr->szSqlStr, myptr->cbSqlStr );
  } else {
    myptr->sqlrc = ILE_SQLExecDirect( myptr->hstmt, myptr->szSqlStr, myptr->cbSqlStr );
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLExecDirectStruct *) NULL;
  }
  return myptr;
}
void * SQLExecDirectWThread (void *ptr)
{
  SQLExecDirectWStruct * myptr = (SQLExecDirectWStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLExecDirectW( myptr->hstmt, myptr->szSqlStr, myptr->cbSqlStr );
  } else {
    myptr->sqlrc = ILE_SQLExecDirectW( myptr->hstmt, myptr->szSqlStr, myptr->cbSqlStr );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLExecDirectWCallback(SQLExecDirectWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLExecDirectWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLExecDirectWAsync ( SQLHSTMT  hstmt, SQLWCHAR * szSqlStr, SQLINTEGER  cbSqlStr, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLExecDirectWStruct * myptr = (SQLExecDirectWStruct *) malloc(sizeof(SQLExecDirectWStruct));
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->szSqlStr = szSqlStr;
  myptr->cbSqlStr = cbSqlStr;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLExecDirectWThread, (void *)myptr);
  return tid;
}
SQLExecDirectWStruct * SQLExecDirectWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLExecDirectWStruct * myptr = (SQLExecDirectWStruct *) NULL;
  int active = 0;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLExecDirectWStruct *) NULL;
  }
  return myptr;
}
void * SQLExecuteThread (void *ptr)
{
  SQLExecuteStruct * myptr = (SQLExecuteStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLExecute( myptr->hstmt );
  } else {
    myptr->sqlrc = ILE_SQLExecute( myptr->hstmt );
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLExtendedFetch( myptr->hstmt, myptr->fOrient, myptr->fOffset, myptr->pcrow, myptr->rgfRowStatus );
  } else {
    myptr->sqlrc = ILE_SQLExtendedFetch( myptr->hstmt, myptr->fOrient, myptr->fOffset, myptr->pcrow, myptr->rgfRowStatus );
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLFetch( myptr->hstmt );
  } else {
    myptr->sqlrc = ILE_SQLFetch( myptr->hstmt );
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLFetchScroll( myptr->hstmt, myptr->fOrient, myptr->fOffset );
  } else {
    myptr->sqlrc = ILE_SQLFetchScroll( myptr->hstmt, myptr->fOrient, myptr->fOffset );
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLForeignKeys( myptr->hstmt, myptr->szPkTableQualifier, myptr->cbPkTableQualifier, myptr->szPkTableOwner, myptr->cbPkTableOwner, myptr->szPkTableName, myptr->cbPkTableName, myptr->szFkTableQualifier, myptr->cbFkTableQualifier, myptr->szFkTableOwner, myptr->cbFkTableOwner, myptr->szFkTableName, myptr->cbFkTableName );
  } else {
    myptr->sqlrc = ILE_SQLForeignKeys( myptr->hstmt, myptr->szPkTableQualifier, myptr->cbPkTableQualifier, myptr->szPkTableOwner, myptr->cbPkTableOwner, myptr->szPkTableName, myptr->cbPkTableName, myptr->szFkTableQualifier, myptr->cbFkTableQualifier, myptr->szFkTableOwner, myptr->cbFkTableOwner, myptr->szFkTableName, myptr->cbFkTableName );
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLForeignKeysStruct *) NULL;
  }
  return myptr;
}
void * SQLForeignKeysWThread (void *ptr)
{
  SQLForeignKeysWStruct * myptr = (SQLForeignKeysWStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLForeignKeysW( myptr->hstmt, myptr->szPkTableQualifier, myptr->cbPkTableQualifier, myptr->szPkTableOwner, myptr->cbPkTableOwner, myptr->szPkTableName, myptr->cbPkTableName, myptr->szFkTableQualifier, myptr->cbFkTableQualifier, myptr->szFkTableOwner, myptr->cbFkTableOwner, myptr->szFkTableName, myptr->cbFkTableName );
  } else {
    myptr->sqlrc = ILE_SQLForeignKeysW( myptr->hstmt, myptr->szPkTableQualifier, myptr->cbPkTableQualifier, myptr->szPkTableOwner, myptr->cbPkTableOwner, myptr->szPkTableName, myptr->cbPkTableName, myptr->szFkTableQualifier, myptr->cbFkTableQualifier, myptr->szFkTableOwner, myptr->cbFkTableOwner, myptr->szFkTableName, myptr->cbFkTableName );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLForeignKeysWCallback(SQLForeignKeysWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLForeignKeysWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLForeignKeysWAsync ( SQLHSTMT  hstmt, SQLWCHAR * szPkTableQualifier, SQLSMALLINT  cbPkTableQualifier, SQLWCHAR * szPkTableOwner, SQLSMALLINT  cbPkTableOwner, SQLWCHAR * szPkTableName, SQLSMALLINT  cbPkTableName, SQLWCHAR * szFkTableQualifier, SQLSMALLINT  cbFkTableQualifier, SQLWCHAR * szFkTableOwner, SQLSMALLINT  cbFkTableOwner, SQLWCHAR * szFkTableName, SQLSMALLINT  cbFkTableName, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLForeignKeysWStruct * myptr = (SQLForeignKeysWStruct *) malloc(sizeof(SQLForeignKeysWStruct));
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  rc = pthread_create(&tid, NULL, SQLForeignKeysWThread, (void *)myptr);
  return tid;
}
SQLForeignKeysWStruct * SQLForeignKeysWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLForeignKeysWStruct * myptr = (SQLForeignKeysWStruct *) NULL;
  int active = 0;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLForeignKeysWStruct *) NULL;
  }
  return myptr;
}
void * SQLGetColThread (void *ptr)
{
  SQLGetColStruct * myptr = (SQLGetColStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLGetCol( myptr->hstmt, myptr->icol, myptr->itype, myptr->tval, myptr->blen, myptr->olen );
  } else {
    myptr->sqlrc = ILE_SQLGetCol( myptr->hstmt, myptr->icol, myptr->itype, myptr->tval, myptr->blen, myptr->olen );
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetColStruct *) NULL;
  }
  return myptr;
}
void * SQLGetColWThread (void *ptr)
{
  SQLGetColWStruct * myptr = (SQLGetColWStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLGetColW( myptr->hstmt, myptr->icol, myptr->itype, myptr->tval, myptr->blen, myptr->olen );
  } else {
    myptr->sqlrc = ILE_SQLGetColW( myptr->hstmt, myptr->icol, myptr->itype, myptr->tval, myptr->blen, myptr->olen );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLGetColWCallback(SQLGetColWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetColWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetColWAsync ( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  itype, SQLPOINTER  tval, SQLINTEGER  blen, SQLINTEGER * olen, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetColWStruct * myptr = (SQLGetColWStruct *) malloc(sizeof(SQLGetColWStruct));
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->icol = icol;
  myptr->itype = itype;
  myptr->tval = tval;
  myptr->blen = blen;
  myptr->olen = olen;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetColWThread, (void *)myptr);
  return tid;
}
SQLGetColWStruct * SQLGetColWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetColWStruct * myptr = (SQLGetColWStruct *) NULL;
  int active = 0;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetColWStruct *) NULL;
  }
  return myptr;
}
void * SQLGetConnectAttrThread (void *ptr)
{
  SQLGetConnectAttrStruct * myptr = (SQLGetConnectAttrStruct *) ptr;
  init_table_lock(myptr->hdbc, 0);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLGetConnectAttr( myptr->hdbc, myptr->attr, myptr->oval, myptr->ilen, myptr->olen );
  } else {
    myptr->sqlrc = ILE_SQLGetConnectAttr( myptr->hdbc, myptr->attr, myptr->oval, myptr->ilen, myptr->olen );
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hdbc, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetConnectAttrStruct *) NULL;
  }
  return myptr;
}
void * SQLGetConnectAttrWThread (void *ptr)
{
  SQLGetConnectAttrWStruct * myptr = (SQLGetConnectAttrWStruct *) ptr;
  init_table_lock(myptr->hdbc, 0);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLGetConnectAttrW( myptr->hdbc, myptr->attr, myptr->oval, myptr->ilen, myptr->olen );
  } else {
    myptr->sqlrc = ILE_SQLGetConnectAttrW( myptr->hdbc, myptr->attr, myptr->oval, myptr->ilen, myptr->olen );
  }
  init_table_unlock(myptr->hdbc, 0);
  /* void SQLGetConnectAttrWCallback(SQLGetConnectAttrWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetConnectAttrWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetConnectAttrWAsync ( SQLHDBC  hdbc, SQLINTEGER  attr, SQLPOINTER  oval, SQLINTEGER  ilen, SQLINTEGER * olen, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetConnectAttrWStruct * myptr = (SQLGetConnectAttrWStruct *) malloc(sizeof(SQLGetConnectAttrWStruct));
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdbc = hdbc;
  myptr->attr = attr;
  myptr->oval = oval;
  myptr->ilen = ilen;
  myptr->olen = olen;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetConnectAttrWThread, (void *)myptr);
  return tid;
}
SQLGetConnectAttrWStruct * SQLGetConnectAttrWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetConnectAttrWStruct * myptr = (SQLGetConnectAttrWStruct *) NULL;
  int active = 0;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hdbc, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetConnectAttrWStruct *) NULL;
  }
  return myptr;
}
void * SQLGetConnectOptionThread (void *ptr)
{
  SQLGetConnectOptionStruct * myptr = (SQLGetConnectOptionStruct *) ptr;
  init_table_lock(myptr->hdbc, 0);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLGetConnectOption( myptr->hdbc, myptr->iopt, myptr->oval );
  } else {
    myptr->sqlrc = ILE_SQLGetConnectOption( myptr->hdbc, myptr->iopt, myptr->oval );
  }
  init_table_unlock(myptr->hdbc, 0);
  /* void SQLGetConnectOptionCallback(SQLGetConnectOptionStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetConnectOptionStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetConnectOptionAsync ( SQLHDBC  hdbc, SQLSMALLINT  iopt, SQLPOINTER  oval, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetConnectOptionStruct * myptr = (SQLGetConnectOptionStruct *) malloc(sizeof(SQLGetConnectOptionStruct));
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdbc = hdbc;
  myptr->iopt = iopt;
  myptr->oval = oval;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetConnectOptionThread, (void *)myptr);
  return tid;
}
SQLGetConnectOptionStruct * SQLGetConnectOptionJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetConnectOptionStruct * myptr = (SQLGetConnectOptionStruct *) NULL;
  int active = 0;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hdbc, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetConnectOptionStruct *) NULL;
  }
  return myptr;
}
void * SQLGetConnectOptionWThread (void *ptr)
{
  SQLGetConnectOptionWStruct * myptr = (SQLGetConnectOptionWStruct *) ptr;
  init_table_lock(myptr->hdbc, 0);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLGetConnectOptionW( myptr->hdbc, myptr->iopt, myptr->oval );
  } else {
    myptr->sqlrc = ILE_SQLGetConnectOptionW( myptr->hdbc, myptr->iopt, myptr->oval );
  }
  init_table_unlock(myptr->hdbc, 0);
  /* void SQLGetConnectOptionWCallback(SQLGetConnectOptionWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetConnectOptionWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetConnectOptionWAsync ( SQLHDBC  hdbc, SQLSMALLINT  iopt, SQLPOINTER  oval, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetConnectOptionWStruct * myptr = (SQLGetConnectOptionWStruct *) malloc(sizeof(SQLGetConnectOptionWStruct));
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdbc = hdbc;
  myptr->iopt = iopt;
  myptr->oval = oval;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetConnectOptionWThread, (void *)myptr);
  return tid;
}
SQLGetConnectOptionWStruct * SQLGetConnectOptionWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetConnectOptionWStruct * myptr = (SQLGetConnectOptionWStruct *) NULL;
  int active = 0;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hdbc, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetConnectOptionWStruct *) NULL;
  }
  return myptr;
}
void * SQLGetCursorNameThread (void *ptr)
{
  SQLGetCursorNameStruct * myptr = (SQLGetCursorNameStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLGetCursorName( myptr->hstmt, myptr->szCursor, myptr->cbCursorMax, myptr->pcbCursor );
  } else {
    myptr->sqlrc = ILE_SQLGetCursorName( myptr->hstmt, myptr->szCursor, myptr->cbCursorMax, myptr->pcbCursor );
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetCursorNameStruct *) NULL;
  }
  return myptr;
}
void * SQLGetCursorNameWThread (void *ptr)
{
  SQLGetCursorNameWStruct * myptr = (SQLGetCursorNameWStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLGetCursorNameW( myptr->hstmt, myptr->szCursor, myptr->cbCursorMax, myptr->pcbCursor );
  } else {
    myptr->sqlrc = ILE_SQLGetCursorNameW( myptr->hstmt, myptr->szCursor, myptr->cbCursorMax, myptr->pcbCursor );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLGetCursorNameWCallback(SQLGetCursorNameWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetCursorNameWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetCursorNameWAsync ( SQLHSTMT  hstmt, SQLWCHAR * szCursor, SQLSMALLINT  cbCursorMax, SQLSMALLINT * pcbCursor, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetCursorNameWStruct * myptr = (SQLGetCursorNameWStruct *) malloc(sizeof(SQLGetCursorNameWStruct));
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->szCursor = szCursor;
  myptr->cbCursorMax = cbCursorMax;
  myptr->pcbCursor = pcbCursor;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetCursorNameWThread, (void *)myptr);
  return tid;
}
SQLGetCursorNameWStruct * SQLGetCursorNameWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetCursorNameWStruct * myptr = (SQLGetCursorNameWStruct *) NULL;
  int active = 0;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetCursorNameWStruct *) NULL;
  }
  return myptr;
}
void * SQLGetDataThread (void *ptr)
{
  SQLGetDataStruct * myptr = (SQLGetDataStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLGetData( myptr->hstmt, myptr->icol, myptr->fCType, myptr->rgbValue, myptr->cbValueMax, myptr->pcbValue );
  } else {
    myptr->sqlrc = ILE_SQLGetData( myptr->hstmt, myptr->icol, myptr->fCType, myptr->rgbValue, myptr->cbValueMax, myptr->pcbValue );
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLGetDescField( myptr->hdesc, myptr->rcdNum, myptr->fieldID, myptr->fValue, myptr->fLength, myptr->stLength );
  } else {
    myptr->sqlrc = ILE_SQLGetDescField( myptr->hdesc, myptr->rcdNum, myptr->fieldID, myptr->fValue, myptr->fLength, myptr->stLength );
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hdesc, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetDescFieldStruct *) NULL;
  }
  return myptr;
}
void * SQLGetDescFieldWThread (void *ptr)
{
  SQLGetDescFieldWStruct * myptr = (SQLGetDescFieldWStruct *) ptr;
  init_table_lock(myptr->hdesc, 1);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLGetDescFieldW( myptr->hdesc, myptr->rcdNum, myptr->fieldID, myptr->fValue, myptr->fLength, myptr->stLength );
  } else {
    myptr->sqlrc = ILE_SQLGetDescFieldW( myptr->hdesc, myptr->rcdNum, myptr->fieldID, myptr->fValue, myptr->fLength, myptr->stLength );
  }
  init_table_unlock(myptr->hdesc, 1);
  /* void SQLGetDescFieldWCallback(SQLGetDescFieldWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetDescFieldWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetDescFieldWAsync ( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  fieldID, SQLPOINTER  fValue, SQLINTEGER  fLength, SQLINTEGER * stLength, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetDescFieldWStruct * myptr = (SQLGetDescFieldWStruct *) malloc(sizeof(SQLGetDescFieldWStruct));
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdesc = hdesc;
  myptr->rcdNum = rcdNum;
  myptr->fieldID = fieldID;
  myptr->fValue = fValue;
  myptr->fLength = fLength;
  myptr->stLength = stLength;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetDescFieldWThread, (void *)myptr);
  return tid;
}
SQLGetDescFieldWStruct * SQLGetDescFieldWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetDescFieldWStruct * myptr = (SQLGetDescFieldWStruct *) NULL;
  int active = 0;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hdesc, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetDescFieldWStruct *) NULL;
  }
  return myptr;
}
void * SQLGetDescRecThread (void *ptr)
{
  SQLGetDescRecStruct * myptr = (SQLGetDescRecStruct *) ptr;
  init_table_lock(myptr->hdesc, 1);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLGetDescRec( myptr->hdesc, myptr->rcdNum, myptr->fname, myptr->bufLen, myptr->sLength, myptr->sType, myptr->sbType, myptr->fLength, myptr->fprec, myptr->fscale, myptr->fnull );
  } else {
    myptr->sqlrc = ILE_SQLGetDescRec( myptr->hdesc, myptr->rcdNum, myptr->fname, myptr->bufLen, myptr->sLength, myptr->sType, myptr->sbType, myptr->fLength, myptr->fprec, myptr->fscale, myptr->fnull );
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hdesc, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetDescRecStruct *) NULL;
  }
  return myptr;
}
void * SQLGetDescRecWThread (void *ptr)
{
  SQLGetDescRecWStruct * myptr = (SQLGetDescRecWStruct *) ptr;
  init_table_lock(myptr->hdesc, 1);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLGetDescRecW( myptr->hdesc, myptr->rcdNum, myptr->fname, myptr->bufLen, myptr->sLength, myptr->sType, myptr->sbType, myptr->fLength, myptr->fprec, myptr->fscale, myptr->fnull );
  } else {
    myptr->sqlrc = ILE_SQLGetDescRecW( myptr->hdesc, myptr->rcdNum, myptr->fname, myptr->bufLen, myptr->sLength, myptr->sType, myptr->sbType, myptr->fLength, myptr->fprec, myptr->fscale, myptr->fnull );
  }
  init_table_unlock(myptr->hdesc, 1);
  /* void SQLGetDescRecWCallback(SQLGetDescRecWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetDescRecWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetDescRecWAsync ( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLWCHAR * fname, SQLSMALLINT  bufLen, SQLSMALLINT * sLength, SQLSMALLINT * sType, SQLSMALLINT * sbType, SQLINTEGER * fLength, SQLSMALLINT * fprec, SQLSMALLINT * fscale, SQLSMALLINT * fnull, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetDescRecWStruct * myptr = (SQLGetDescRecWStruct *) malloc(sizeof(SQLGetDescRecWStruct));
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  rc = pthread_create(&tid, NULL, SQLGetDescRecWThread, (void *)myptr);
  return tid;
}
SQLGetDescRecWStruct * SQLGetDescRecWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetDescRecWStruct * myptr = (SQLGetDescRecWStruct *) NULL;
  int active = 0;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hdesc, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetDescRecWStruct *) NULL;
  }
  return myptr;
}
void * SQLGetDiagFieldThread (void *ptr)
{
  SQLGetDiagFieldStruct * myptr = (SQLGetDiagFieldStruct *) ptr;
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLGetDiagField( myptr->hType, myptr->hndl, myptr->rcdNum, myptr->diagID, myptr->dValue, myptr->bLength, myptr->sLength );
  } else {
    myptr->sqlrc = ILE_SQLGetDiagField( myptr->hType, myptr->hndl, myptr->rcdNum, myptr->diagID, myptr->dValue, myptr->bLength, myptr->sLength );
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetDiagFieldStruct *) NULL;
  }
  return myptr;
}
void * SQLGetDiagFieldWThread (void *ptr)
{
  SQLGetDiagFieldWStruct * myptr = (SQLGetDiagFieldWStruct *) ptr;
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLGetDiagFieldW( myptr->hType, myptr->hndl, myptr->rcdNum, myptr->diagID, myptr->dValue, myptr->bLength, myptr->sLength );
  } else {
    myptr->sqlrc = ILE_SQLGetDiagFieldW( myptr->hType, myptr->hndl, myptr->rcdNum, myptr->diagID, myptr->dValue, myptr->bLength, myptr->sLength );
  }
  /* void SQLGetDiagFieldWCallback(SQLGetDiagFieldWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetDiagFieldWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetDiagFieldWAsync ( SQLSMALLINT  hType, SQLINTEGER  hndl, SQLSMALLINT  rcdNum, SQLSMALLINT  diagID, SQLPOINTER  dValue, SQLSMALLINT  bLength, SQLSMALLINT * sLength, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetDiagFieldWStruct * myptr = (SQLGetDiagFieldWStruct *) malloc(sizeof(SQLGetDiagFieldWStruct));
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hType = hType;
  myptr->hndl = hndl;
  myptr->rcdNum = rcdNum;
  myptr->diagID = diagID;
  myptr->dValue = dValue;
  myptr->bLength = bLength;
  myptr->sLength = sLength;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetDiagFieldWThread, (void *)myptr);
  return tid;
}
SQLGetDiagFieldWStruct * SQLGetDiagFieldWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetDiagFieldWStruct * myptr = (SQLGetDiagFieldWStruct *) NULL;
  int active = 0;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetDiagFieldWStruct *) NULL;
  }
  return myptr;
}
void * SQLGetDiagRecThread (void *ptr)
{
  SQLGetDiagRecStruct * myptr = (SQLGetDiagRecStruct *) ptr;
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLGetDiagRec( myptr->hType, myptr->hndl, myptr->rcdNum, myptr->SQLstate, myptr->SQLcode, myptr->msgText, myptr->bLength, myptr->SLength );
  } else {
    myptr->sqlrc = ILE_SQLGetDiagRec( myptr->hType, myptr->hndl, myptr->rcdNum, myptr->SQLstate, myptr->SQLcode, myptr->msgText, myptr->bLength, myptr->SLength );
  }
  /* void SQLGetDiagRecCallback(SQLGetDiagRecStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetDiagRecStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetDiagRecAsync ( SQLSMALLINT  hType, SQLINTEGER  hndl, SQLSMALLINT  rcdNum, SQLCHAR * SQLstate, SQLINTEGER * SQLcode, SQLCHAR * msgText, SQLSMALLINT  bLength, SQLSMALLINT * SLength, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetDiagRecStruct * myptr = (SQLGetDiagRecStruct *) malloc(sizeof(SQLGetDiagRecStruct));
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hType = hType;
  myptr->hndl = hndl;
  myptr->rcdNum = rcdNum;
  myptr->SQLstate = SQLstate;
  myptr->SQLcode = SQLcode;
  myptr->msgText = msgText;
  myptr->bLength = bLength;
  myptr->SLength = SLength;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetDiagRecThread, (void *)myptr);
  return tid;
}
SQLGetDiagRecStruct * SQLGetDiagRecJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetDiagRecStruct * myptr = (SQLGetDiagRecStruct *) NULL;
  int active = 0;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetDiagRecStruct *) NULL;
  }
  return myptr;
}
void * SQLGetDiagRecWThread (void *ptr)
{
  SQLGetDiagRecWStruct * myptr = (SQLGetDiagRecWStruct *) ptr;
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLGetDiagRecW( myptr->hType, myptr->hndl, myptr->rcdNum, myptr->SQLstate, myptr->SQLcode, myptr->msgText, myptr->bLength, myptr->SLength );
  } else {
    myptr->sqlrc = ILE_SQLGetDiagRecW( myptr->hType, myptr->hndl, myptr->rcdNum, myptr->SQLstate, myptr->SQLcode, myptr->msgText, myptr->bLength, myptr->SLength );
  }
  /* void SQLGetDiagRecWCallback(SQLGetDiagRecWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetDiagRecWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetDiagRecWAsync ( SQLSMALLINT  hType, SQLINTEGER  hndl, SQLSMALLINT  rcdNum, SQLWCHAR * SQLstate, SQLINTEGER * SQLcode, SQLWCHAR * msgText, SQLSMALLINT  bLength, SQLSMALLINT * SLength, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetDiagRecWStruct * myptr = (SQLGetDiagRecWStruct *) malloc(sizeof(SQLGetDiagRecWStruct));
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hType = hType;
  myptr->hndl = hndl;
  myptr->rcdNum = rcdNum;
  myptr->SQLstate = SQLstate;
  myptr->SQLcode = SQLcode;
  myptr->msgText = msgText;
  myptr->bLength = bLength;
  myptr->SLength = SLength;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetDiagRecWThread, (void *)myptr);
  return tid;
}
SQLGetDiagRecWStruct * SQLGetDiagRecWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetDiagRecWStruct * myptr = (SQLGetDiagRecWStruct *) NULL;
  int active = 0;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetDiagRecWStruct *) NULL;
  }
  return myptr;
}
void * SQLGetEnvAttrThread (void *ptr)
{
  SQLGetEnvAttrStruct * myptr = (SQLGetEnvAttrStruct *) ptr;
  /* not lock */
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLGetEnvAttr( myptr->hEnv, myptr->fAttribute, myptr->pParam, myptr->cbParamMax, myptr->pcbParam );
  } else {
    myptr->sqlrc = ILE_SQLGetEnvAttr( myptr->hEnv, myptr->fAttribute, myptr->pParam, myptr->cbParamMax, myptr->pcbParam );
  }
  /* not lock */
  /* void SQLGetEnvAttrCallback(SQLGetEnvAttrStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetEnvAttrStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetEnvAttrAsync ( SQLHENV  hEnv, SQLINTEGER  fAttribute, SQLPOINTER  pParam, SQLINTEGER  cbParamMax, SQLINTEGER * pcbParam, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetEnvAttrStruct * myptr = (SQLGetEnvAttrStruct *) malloc(sizeof(SQLGetEnvAttrStruct));
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hEnv = hEnv;
  myptr->fAttribute = fAttribute;
  myptr->pParam = pParam;
  myptr->cbParamMax = cbParamMax;
  myptr->pcbParam = pcbParam;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetEnvAttrThread, (void *)myptr);
  return tid;
}
SQLGetEnvAttrStruct * SQLGetEnvAttrJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetEnvAttrStruct * myptr = (SQLGetEnvAttrStruct *) NULL;
  int active = 0;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLGetFunctions( myptr->hdbc, myptr->fFunction, myptr->pfExists );
  } else {
    myptr->sqlrc = ILE_SQLGetFunctions( myptr->hdbc, myptr->fFunction, myptr->pfExists );
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLGetInfo( myptr->hdbc, myptr->fInfoType, myptr->rgbInfoValue, myptr->cbInfoValueMax, myptr->pcbInfoValue );
  } else {
    myptr->sqlrc = ILE_SQLGetInfo( myptr->hdbc, myptr->fInfoType, myptr->rgbInfoValue, myptr->cbInfoValueMax, myptr->pcbInfoValue );
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hdbc, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetInfoStruct *) NULL;
  }
  return myptr;
}
void * SQLGetInfoWThread (void *ptr)
{
  SQLGetInfoWStruct * myptr = (SQLGetInfoWStruct *) ptr;
  init_table_lock(myptr->hdbc, 0);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLGetInfoW( myptr->hdbc, myptr->fInfoType, myptr->rgbInfoValue, myptr->cbInfoValueMax, myptr->pcbInfoValue );
  } else {
    myptr->sqlrc = ILE_SQLGetInfoW( myptr->hdbc, myptr->fInfoType, myptr->rgbInfoValue, myptr->cbInfoValueMax, myptr->pcbInfoValue );
  }
  init_table_unlock(myptr->hdbc, 0);
  /* void SQLGetInfoWCallback(SQLGetInfoWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetInfoWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetInfoWAsync ( SQLHDBC  hdbc, SQLSMALLINT  fInfoType, SQLPOINTER  rgbInfoValue, SQLSMALLINT  cbInfoValueMax, SQLSMALLINT * pcbInfoValue, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetInfoWStruct * myptr = (SQLGetInfoWStruct *) malloc(sizeof(SQLGetInfoWStruct));
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdbc = hdbc;
  myptr->fInfoType = fInfoType;
  myptr->rgbInfoValue = rgbInfoValue;
  myptr->cbInfoValueMax = cbInfoValueMax;
  myptr->pcbInfoValue = pcbInfoValue;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetInfoWThread, (void *)myptr);
  return tid;
}
SQLGetInfoWStruct * SQLGetInfoWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetInfoWStruct * myptr = (SQLGetInfoWStruct *) NULL;
  int active = 0;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hdbc, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetInfoWStruct *) NULL;
  }
  return myptr;
}
void * SQLGetLengthThread (void *ptr)
{
  SQLGetLengthStruct * myptr = (SQLGetLengthStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLGetLength( myptr->hstmt, myptr->locType, myptr->locator, myptr->sLength, myptr->ind );
  } else {
    myptr->sqlrc = ILE_SQLGetLength( myptr->hstmt, myptr->locType, myptr->locator, myptr->sLength, myptr->ind );
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLGetPosition( myptr->hstmt, myptr->locType, myptr->srceLocator, myptr->srchLocator, myptr->srchLiteral, myptr->srchLiteralLen, myptr->fPosition, myptr->located, myptr->ind );
  } else {
    myptr->sqlrc = ILE_SQLGetPosition( myptr->hstmt, myptr->locType, myptr->srceLocator, myptr->srchLocator, myptr->srchLiteral, myptr->srchLiteralLen, myptr->fPosition, myptr->located, myptr->ind );
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetPositionStruct *) NULL;
  }
  return myptr;
}
void * SQLGetPositionWThread (void *ptr)
{
  SQLGetPositionWStruct * myptr = (SQLGetPositionWStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLGetPositionW( myptr->hstmt, myptr->locType, myptr->srceLocator, myptr->srchLocator, myptr->srchLiteral, myptr->srchLiteralLen, myptr->fPosition, myptr->located, myptr->ind );
  } else {
    myptr->sqlrc = ILE_SQLGetPositionW( myptr->hstmt, myptr->locType, myptr->srceLocator, myptr->srchLocator, myptr->srchLiteral, myptr->srchLiteralLen, myptr->fPosition, myptr->located, myptr->ind );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLGetPositionWCallback(SQLGetPositionWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetPositionWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetPositionWAsync ( SQLHSTMT  hstmt, SQLSMALLINT  locType, SQLINTEGER  srceLocator, SQLINTEGER  srchLocator, SQLWCHAR * srchLiteral, SQLINTEGER  srchLiteralLen, SQLINTEGER  fPosition, SQLINTEGER * located, SQLINTEGER * ind, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetPositionWStruct * myptr = (SQLGetPositionWStruct *) malloc(sizeof(SQLGetPositionWStruct));
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  rc = pthread_create(&tid, NULL, SQLGetPositionWThread, (void *)myptr);
  return tid;
}
SQLGetPositionWStruct * SQLGetPositionWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetPositionWStruct * myptr = (SQLGetPositionWStruct *) NULL;
  int active = 0;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetPositionWStruct *) NULL;
  }
  return myptr;
}
void * SQLGetStmtAttrThread (void *ptr)
{
  SQLGetStmtAttrStruct * myptr = (SQLGetStmtAttrStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLGetStmtAttr( myptr->hstmt, myptr->fAttr, myptr->pvParam, myptr->bLength, myptr->SLength );
  } else {
    myptr->sqlrc = ILE_SQLGetStmtAttr( myptr->hstmt, myptr->fAttr, myptr->pvParam, myptr->bLength, myptr->SLength );
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetStmtAttrStruct *) NULL;
  }
  return myptr;
}
void * SQLGetStmtAttrWThread (void *ptr)
{
  SQLGetStmtAttrWStruct * myptr = (SQLGetStmtAttrWStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLGetStmtAttrW( myptr->hstmt, myptr->fAttr, myptr->pvParam, myptr->bLength, myptr->SLength );
  } else {
    myptr->sqlrc = ILE_SQLGetStmtAttrW( myptr->hstmt, myptr->fAttr, myptr->pvParam, myptr->bLength, myptr->SLength );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLGetStmtAttrWCallback(SQLGetStmtAttrWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetStmtAttrWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetStmtAttrWAsync ( SQLHSTMT  hstmt, SQLINTEGER  fAttr, SQLPOINTER  pvParam, SQLINTEGER  bLength, SQLINTEGER * SLength, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetStmtAttrWStruct * myptr = (SQLGetStmtAttrWStruct *) malloc(sizeof(SQLGetStmtAttrWStruct));
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->fAttr = fAttr;
  myptr->pvParam = pvParam;
  myptr->bLength = bLength;
  myptr->SLength = SLength;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetStmtAttrWThread, (void *)myptr);
  return tid;
}
SQLGetStmtAttrWStruct * SQLGetStmtAttrWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetStmtAttrWStruct * myptr = (SQLGetStmtAttrWStruct *) NULL;
  int active = 0;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetStmtAttrWStruct *) NULL;
  }
  return myptr;
}
void * SQLGetStmtOptionThread (void *ptr)
{
  SQLGetStmtOptionStruct * myptr = (SQLGetStmtOptionStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLGetStmtOption( myptr->hstmt, myptr->fOption, myptr->pvParam );
  } else {
    myptr->sqlrc = ILE_SQLGetStmtOption( myptr->hstmt, myptr->fOption, myptr->pvParam );
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetStmtOptionStruct *) NULL;
  }
  return myptr;
}
void * SQLGetStmtOptionWThread (void *ptr)
{
  SQLGetStmtOptionWStruct * myptr = (SQLGetStmtOptionWStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLGetStmtOptionW( myptr->hstmt, myptr->fOption, myptr->pvParam );
  } else {
    myptr->sqlrc = ILE_SQLGetStmtOptionW( myptr->hstmt, myptr->fOption, myptr->pvParam );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLGetStmtOptionWCallback(SQLGetStmtOptionWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetStmtOptionWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetStmtOptionWAsync ( SQLHSTMT  hstmt, SQLSMALLINT  fOption, SQLPOINTER  pvParam, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetStmtOptionWStruct * myptr = (SQLGetStmtOptionWStruct *) malloc(sizeof(SQLGetStmtOptionWStruct));
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->fOption = fOption;
  myptr->pvParam = pvParam;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetStmtOptionWThread, (void *)myptr);
  return tid;
}
SQLGetStmtOptionWStruct * SQLGetStmtOptionWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetStmtOptionWStruct * myptr = (SQLGetStmtOptionWStruct *) NULL;
  int active = 0;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetStmtOptionWStruct *) NULL;
  }
  return myptr;
}
void * SQLGetSubStringThread (void *ptr)
{
  SQLGetSubStringStruct * myptr = (SQLGetSubStringStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLGetSubString( myptr->hstmt, myptr->locType, myptr->srceLocator, myptr->fPosition, myptr->length, myptr->tType, myptr->rgbValue, myptr->cbValueMax, myptr->StringLength, myptr->ind );
  } else {
    myptr->sqlrc = ILE_SQLGetSubString( myptr->hstmt, myptr->locType, myptr->srceLocator, myptr->fPosition, myptr->length, myptr->tType, myptr->rgbValue, myptr->cbValueMax, myptr->StringLength, myptr->ind );
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetSubStringStruct *) NULL;
  }
  return myptr;
}
void * SQLGetSubStringWThread (void *ptr)
{
  SQLGetSubStringWStruct * myptr = (SQLGetSubStringWStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLGetSubStringW( myptr->hstmt, myptr->locType, myptr->srceLocator, myptr->fPosition, myptr->length, myptr->tType, myptr->rgbValue, myptr->cbValueMax, myptr->StringLength, myptr->ind );
  } else {
    myptr->sqlrc = ILE_SQLGetSubStringW( myptr->hstmt, myptr->locType, myptr->srceLocator, myptr->fPosition, myptr->length, myptr->tType, myptr->rgbValue, myptr->cbValueMax, myptr->StringLength, myptr->ind );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLGetSubStringWCallback(SQLGetSubStringWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetSubStringWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetSubStringWAsync ( SQLHSTMT  hstmt, SQLSMALLINT  locType, SQLINTEGER  srceLocator, SQLINTEGER  fPosition, SQLINTEGER  length, SQLSMALLINT  tType, SQLPOINTER  rgbValue, SQLINTEGER  cbValueMax, SQLINTEGER * StringLength, SQLINTEGER * ind, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetSubStringWStruct * myptr = (SQLGetSubStringWStruct *) malloc(sizeof(SQLGetSubStringWStruct));
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  rc = pthread_create(&tid, NULL, SQLGetSubStringWThread, (void *)myptr);
  return tid;
}
SQLGetSubStringWStruct * SQLGetSubStringWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetSubStringWStruct * myptr = (SQLGetSubStringWStruct *) NULL;
  int active = 0;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetSubStringWStruct *) NULL;
  }
  return myptr;
}
void * SQLGetTypeInfoThread (void *ptr)
{
  SQLGetTypeInfoStruct * myptr = (SQLGetTypeInfoStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLGetTypeInfo( myptr->hstmt, myptr->fSqlType );
  } else {
    myptr->sqlrc = ILE_SQLGetTypeInfo( myptr->hstmt, myptr->fSqlType );
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetTypeInfoStruct *) NULL;
  }
  return myptr;
}
void * SQLGetTypeInfoWThread (void *ptr)
{
  SQLGetTypeInfoWStruct * myptr = (SQLGetTypeInfoWStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLGetTypeInfoW( myptr->hstmt, myptr->fSqlType );
  } else {
    myptr->sqlrc = ILE_SQLGetTypeInfoW( myptr->hstmt, myptr->fSqlType );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLGetTypeInfoWCallback(SQLGetTypeInfoWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetTypeInfoWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetTypeInfoWAsync ( SQLHSTMT  hstmt, SQLSMALLINT  fSqlType, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetTypeInfoWStruct * myptr = (SQLGetTypeInfoWStruct *) malloc(sizeof(SQLGetTypeInfoWStruct));
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->fSqlType = fSqlType;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetTypeInfoWThread, (void *)myptr);
  return tid;
}
SQLGetTypeInfoWStruct * SQLGetTypeInfoWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetTypeInfoWStruct * myptr = (SQLGetTypeInfoWStruct *) NULL;
  int active = 0;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetTypeInfoWStruct *) NULL;
  }
  return myptr;
}
void * SQLLanguagesThread (void *ptr)
{
  SQLLanguagesStruct * myptr = (SQLLanguagesStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLLanguages( myptr->hstmt );
  } else {
    myptr->sqlrc = ILE_SQLLanguages( myptr->hstmt );
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLMoreResults( myptr->hstmt );
  } else {
    myptr->sqlrc = ILE_SQLMoreResults( myptr->hstmt );
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLNativeSql( myptr->hdbc, myptr->szSqlStrIn, myptr->cbSqlStrIn, myptr->szSqlStr, myptr->cbSqlStrMax, myptr->pcbSqlStr );
  } else {
    myptr->sqlrc = ILE_SQLNativeSql( myptr->hdbc, myptr->szSqlStrIn, myptr->cbSqlStrIn, myptr->szSqlStr, myptr->cbSqlStrMax, myptr->pcbSqlStr );
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hdbc, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLNativeSqlStruct *) NULL;
  }
  return myptr;
}
void * SQLNativeSqlWThread (void *ptr)
{
  SQLNativeSqlWStruct * myptr = (SQLNativeSqlWStruct *) ptr;
  init_table_lock(myptr->hdbc, 0);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLNativeSqlW( myptr->hdbc, myptr->szSqlStrIn, myptr->cbSqlStrIn, myptr->szSqlStr, myptr->cbSqlStrMax, myptr->pcbSqlStr );
  } else {
    myptr->sqlrc = ILE_SQLNativeSqlW( myptr->hdbc, myptr->szSqlStrIn, myptr->cbSqlStrIn, myptr->szSqlStr, myptr->cbSqlStrMax, myptr->pcbSqlStr );
  }
  init_table_unlock(myptr->hdbc, 0);
  /* void SQLNativeSqlWCallback(SQLNativeSqlWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLNativeSqlWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLNativeSqlWAsync ( SQLHDBC  hdbc, SQLWCHAR * szSqlStrIn, SQLINTEGER  cbSqlStrIn, SQLWCHAR * szSqlStr, SQLINTEGER  cbSqlStrMax, SQLINTEGER * pcbSqlStr, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLNativeSqlWStruct * myptr = (SQLNativeSqlWStruct *) malloc(sizeof(SQLNativeSqlWStruct));
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdbc = hdbc;
  myptr->szSqlStrIn = szSqlStrIn;
  myptr->cbSqlStrIn = cbSqlStrIn;
  myptr->szSqlStr = szSqlStr;
  myptr->cbSqlStrMax = cbSqlStrMax;
  myptr->pcbSqlStr = pcbSqlStr;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLNativeSqlWThread, (void *)myptr);
  return tid;
}
SQLNativeSqlWStruct * SQLNativeSqlWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLNativeSqlWStruct * myptr = (SQLNativeSqlWStruct *) NULL;
  int active = 0;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hdbc, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLNativeSqlWStruct *) NULL;
  }
  return myptr;
}
void * SQLNextResultThread (void *ptr)
{
  SQLNextResultStruct * myptr = (SQLNextResultStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLNextResult( myptr->hstmt, myptr->hstmt2 );
  } else {
    myptr->sqlrc = ILE_SQLNextResult( myptr->hstmt, myptr->hstmt2 );
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLNumParams( myptr->hstmt, myptr->pcpar );
  } else {
    myptr->sqlrc = ILE_SQLNumParams( myptr->hstmt, myptr->pcpar );
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLNumResultCols( myptr->hstmt, myptr->pccol );
  } else {
    myptr->sqlrc = ILE_SQLNumResultCols( myptr->hstmt, myptr->pccol );
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLParamData( myptr->hstmt, myptr->Value );
  } else {
    myptr->sqlrc = ILE_SQLParamData( myptr->hstmt, myptr->Value );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLParamDataCallback(SQLParamDataStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLParamDataStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLParamDataAsync ( SQLHSTMT  hstmt, SQLPOINTER * Value, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLParamDataStruct * myptr = (SQLParamDataStruct *) malloc(sizeof(SQLParamDataStruct));
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->Value = Value;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLParamDataThread, (void *)myptr);
  return tid;
}
SQLParamDataStruct * SQLParamDataJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLParamDataStruct * myptr = (SQLParamDataStruct *) NULL;
  int active = 0;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLParamOptions( myptr->hstmt, myptr->crow, myptr->pirow );
  } else {
    myptr->sqlrc = ILE_SQLParamOptions( myptr->hstmt, myptr->crow, myptr->pirow );
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLPrepare( myptr->hstmt, myptr->szSqlStr, myptr->cbSqlStr );
  } else {
    myptr->sqlrc = ILE_SQLPrepare( myptr->hstmt, myptr->szSqlStr, myptr->cbSqlStr );
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLPrepareStruct *) NULL;
  }
  return myptr;
}
void * SQLPrepareWThread (void *ptr)
{
  SQLPrepareWStruct * myptr = (SQLPrepareWStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLPrepareW( myptr->hstmt, myptr->szSqlStr, myptr->cbSqlStr );
  } else {
    myptr->sqlrc = ILE_SQLPrepareW( myptr->hstmt, myptr->szSqlStr, myptr->cbSqlStr );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLPrepareWCallback(SQLPrepareWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLPrepareWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLPrepareWAsync ( SQLHSTMT  hstmt, SQLWCHAR * szSqlStr, SQLINTEGER  cbSqlStr, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLPrepareWStruct * myptr = (SQLPrepareWStruct *) malloc(sizeof(SQLPrepareWStruct));
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->szSqlStr = szSqlStr;
  myptr->cbSqlStr = cbSqlStr;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLPrepareWThread, (void *)myptr);
  return tid;
}
SQLPrepareWStruct * SQLPrepareWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLPrepareWStruct * myptr = (SQLPrepareWStruct *) NULL;
  int active = 0;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLPrepareWStruct *) NULL;
  }
  return myptr;
}
void * SQLPrimaryKeysThread (void *ptr)
{
  SQLPrimaryKeysStruct * myptr = (SQLPrimaryKeysStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLPrimaryKeys( myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName );
  } else {
    myptr->sqlrc = ILE_SQLPrimaryKeys( myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName );
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLPrimaryKeysStruct *) NULL;
  }
  return myptr;
}
void * SQLPrimaryKeysWThread (void *ptr)
{
  SQLPrimaryKeysWStruct * myptr = (SQLPrimaryKeysWStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLPrimaryKeysW( myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName );
  } else {
    myptr->sqlrc = ILE_SQLPrimaryKeysW( myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLPrimaryKeysWCallback(SQLPrimaryKeysWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLPrimaryKeysWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLPrimaryKeysWAsync ( SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLPrimaryKeysWStruct * myptr = (SQLPrimaryKeysWStruct *) malloc(sizeof(SQLPrimaryKeysWStruct));
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->szTableQualifier = szTableQualifier;
  myptr->cbTableQualifier = cbTableQualifier;
  myptr->szTableOwner = szTableOwner;
  myptr->cbTableOwner = cbTableOwner;
  myptr->szTableName = szTableName;
  myptr->cbTableName = cbTableName;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLPrimaryKeysWThread, (void *)myptr);
  return tid;
}
SQLPrimaryKeysWStruct * SQLPrimaryKeysWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLPrimaryKeysWStruct * myptr = (SQLPrimaryKeysWStruct *) NULL;
  int active = 0;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLPrimaryKeysWStruct *) NULL;
  }
  return myptr;
}
void * SQLProcedureColumnsThread (void *ptr)
{
  SQLProcedureColumnsStruct * myptr = (SQLProcedureColumnsStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLProcedureColumns( myptr->hstmt, myptr->szProcQualifier, myptr->cbProcQualifier, myptr->szProcOwner, myptr->cbProcOwner, myptr->szProcName, myptr->cbProcName, myptr->szColumnName, myptr->cbColumnName );
  } else {
    myptr->sqlrc = ILE_SQLProcedureColumns( myptr->hstmt, myptr->szProcQualifier, myptr->cbProcQualifier, myptr->szProcOwner, myptr->cbProcOwner, myptr->szProcName, myptr->cbProcName, myptr->szColumnName, myptr->cbColumnName );
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLProcedureColumnsStruct *) NULL;
  }
  return myptr;
}
void * SQLProcedureColumnsWThread (void *ptr)
{
  SQLProcedureColumnsWStruct * myptr = (SQLProcedureColumnsWStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLProcedureColumnsW( myptr->hstmt, myptr->szProcQualifier, myptr->cbProcQualifier, myptr->szProcOwner, myptr->cbProcOwner, myptr->szProcName, myptr->cbProcName, myptr->szColumnName, myptr->cbColumnName );
  } else {
    myptr->sqlrc = ILE_SQLProcedureColumnsW( myptr->hstmt, myptr->szProcQualifier, myptr->cbProcQualifier, myptr->szProcOwner, myptr->cbProcOwner, myptr->szProcName, myptr->cbProcName, myptr->szColumnName, myptr->cbColumnName );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLProcedureColumnsWCallback(SQLProcedureColumnsWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLProcedureColumnsWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLProcedureColumnsWAsync ( SQLHSTMT  hstmt, SQLWCHAR * szProcQualifier, SQLSMALLINT  cbProcQualifier, SQLWCHAR * szProcOwner, SQLSMALLINT  cbProcOwner, SQLWCHAR * szProcName, SQLSMALLINT  cbProcName, SQLWCHAR * szColumnName, SQLSMALLINT  cbColumnName, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLProcedureColumnsWStruct * myptr = (SQLProcedureColumnsWStruct *) malloc(sizeof(SQLProcedureColumnsWStruct));
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  rc = pthread_create(&tid, NULL, SQLProcedureColumnsWThread, (void *)myptr);
  return tid;
}
SQLProcedureColumnsWStruct * SQLProcedureColumnsWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLProcedureColumnsWStruct * myptr = (SQLProcedureColumnsWStruct *) NULL;
  int active = 0;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLProcedureColumnsWStruct *) NULL;
  }
  return myptr;
}
void * SQLProceduresThread (void *ptr)
{
  SQLProceduresStruct * myptr = (SQLProceduresStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLProcedures( myptr->hstmt, myptr->szProcQualifier, myptr->cbProcQualifier, myptr->szProcOwner, myptr->cbProcOwner, myptr->szProcName, myptr->cbProcName );
  } else {
    myptr->sqlrc = ILE_SQLProcedures( myptr->hstmt, myptr->szProcQualifier, myptr->cbProcQualifier, myptr->szProcOwner, myptr->cbProcOwner, myptr->szProcName, myptr->cbProcName );
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLProceduresStruct *) NULL;
  }
  return myptr;
}
void * SQLProceduresWThread (void *ptr)
{
  SQLProceduresWStruct * myptr = (SQLProceduresWStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLProceduresW( myptr->hstmt, myptr->szProcQualifier, myptr->cbProcQualifier, myptr->szProcOwner, myptr->cbProcOwner, myptr->szProcName, myptr->cbProcName );
  } else {
    myptr->sqlrc = ILE_SQLProceduresW( myptr->hstmt, myptr->szProcQualifier, myptr->cbProcQualifier, myptr->szProcOwner, myptr->cbProcOwner, myptr->szProcName, myptr->cbProcName );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLProceduresWCallback(SQLProceduresWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLProceduresWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLProceduresWAsync ( SQLHSTMT  hstmt, SQLWCHAR * szProcQualifier, SQLSMALLINT  cbProcQualifier, SQLWCHAR * szProcOwner, SQLSMALLINT  cbProcOwner, SQLWCHAR * szProcName, SQLSMALLINT  cbProcName, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLProceduresWStruct * myptr = (SQLProceduresWStruct *) malloc(sizeof(SQLProceduresWStruct));
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->szProcQualifier = szProcQualifier;
  myptr->cbProcQualifier = cbProcQualifier;
  myptr->szProcOwner = szProcOwner;
  myptr->cbProcOwner = cbProcOwner;
  myptr->szProcName = szProcName;
  myptr->cbProcName = cbProcName;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLProceduresWThread, (void *)myptr);
  return tid;
}
SQLProceduresWStruct * SQLProceduresWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLProceduresWStruct * myptr = (SQLProceduresWStruct *) NULL;
  int active = 0;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLProceduresWStruct *) NULL;
  }
  return myptr;
}
void * SQLPutDataThread (void *ptr)
{
  SQLPutDataStruct * myptr = (SQLPutDataStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLPutData( myptr->hstmt, myptr->Data, myptr->SLen );
  } else {
    myptr->sqlrc = ILE_SQLPutData( myptr->hstmt, myptr->Data, myptr->SLen );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLPutDataCallback(SQLPutDataStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLPutDataStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLPutDataAsync ( SQLHSTMT  hstmt, SQLPOINTER  Data, SQLINTEGER  SLen, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLPutDataStruct * myptr = (SQLPutDataStruct *) malloc(sizeof(SQLPutDataStruct));
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->Data = Data;
  myptr->SLen = SLen;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLPutDataThread, (void *)myptr);
  return tid;
}
SQLPutDataStruct * SQLPutDataJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLPutDataStruct * myptr = (SQLPutDataStruct *) NULL;
  int active = 0;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLReleaseEnv( myptr->henv );
  } else {
    myptr->sqlrc = ILE_SQLReleaseEnv( myptr->henv );
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLRowCount( myptr->hstmt, myptr->pcrow );
  } else {
    myptr->sqlrc = ILE_SQLRowCount( myptr->hstmt, myptr->pcrow );
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLSetConnectAttr( myptr->hdbc, myptr->attrib, myptr->vParam, myptr->inlen );
  } else {
    myptr->sqlrc = ILE_SQLSetConnectAttr( myptr->hdbc, myptr->attrib, myptr->vParam, myptr->inlen );
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hdbc, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLSetConnectAttrStruct *) NULL;
  }
  return myptr;
}
void * SQLSetConnectAttrWThread (void *ptr)
{
  SQLSetConnectAttrWStruct * myptr = (SQLSetConnectAttrWStruct *) ptr;
  init_table_lock(myptr->hdbc, 0);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLSetConnectAttrW( myptr->hdbc, myptr->attrib, myptr->vParam, myptr->inlen );
  } else {
    myptr->sqlrc = ILE_SQLSetConnectAttrW( myptr->hdbc, myptr->attrib, myptr->vParam, myptr->inlen );
  }
  init_table_unlock(myptr->hdbc, 0);
  /* void SQLSetConnectAttrWCallback(SQLSetConnectAttrWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLSetConnectAttrWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLSetConnectAttrWAsync ( SQLHDBC  hdbc, SQLINTEGER  attrib, SQLPOINTER  vParam, SQLINTEGER  inlen, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLSetConnectAttrWStruct * myptr = (SQLSetConnectAttrWStruct *) malloc(sizeof(SQLSetConnectAttrWStruct));
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdbc = hdbc;
  myptr->attrib = attrib;
  myptr->vParam = vParam;
  myptr->inlen = inlen;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLSetConnectAttrWThread, (void *)myptr);
  return tid;
}
SQLSetConnectAttrWStruct * SQLSetConnectAttrWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLSetConnectAttrWStruct * myptr = (SQLSetConnectAttrWStruct *) NULL;
  int active = 0;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hdbc, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLSetConnectAttrWStruct *) NULL;
  }
  return myptr;
}
void * SQLSetConnectOptionThread (void *ptr)
{
  SQLSetConnectOptionStruct * myptr = (SQLSetConnectOptionStruct *) ptr;
  init_table_lock(myptr->hdbc, 0);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLSetConnectOption( myptr->hdbc, myptr->fOption, myptr->vParam );
  } else {
    myptr->sqlrc = ILE_SQLSetConnectOption( myptr->hdbc, myptr->fOption, myptr->vParam );
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hdbc, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLSetConnectOptionStruct *) NULL;
  }
  return myptr;
}
void * SQLSetConnectOptionWThread (void *ptr)
{
  SQLSetConnectOptionWStruct * myptr = (SQLSetConnectOptionWStruct *) ptr;
  init_table_lock(myptr->hdbc, 0);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLSetConnectOptionW( myptr->hdbc, myptr->fOption, myptr->vParam );
  } else {
    myptr->sqlrc = ILE_SQLSetConnectOptionW( myptr->hdbc, myptr->fOption, myptr->vParam );
  }
  init_table_unlock(myptr->hdbc, 0);
  /* void SQLSetConnectOptionWCallback(SQLSetConnectOptionWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLSetConnectOptionWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLSetConnectOptionWAsync ( SQLHDBC  hdbc, SQLSMALLINT  fOption, SQLPOINTER  vParam, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLSetConnectOptionWStruct * myptr = (SQLSetConnectOptionWStruct *) malloc(sizeof(SQLSetConnectOptionWStruct));
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdbc = hdbc;
  myptr->fOption = fOption;
  myptr->vParam = vParam;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLSetConnectOptionWThread, (void *)myptr);
  return tid;
}
SQLSetConnectOptionWStruct * SQLSetConnectOptionWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLSetConnectOptionWStruct * myptr = (SQLSetConnectOptionWStruct *) NULL;
  int active = 0;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hdbc, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLSetConnectOptionWStruct *) NULL;
  }
  return myptr;
}
void * SQLSetCursorNameThread (void *ptr)
{
  SQLSetCursorNameStruct * myptr = (SQLSetCursorNameStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLSetCursorName( myptr->hstmt, myptr->szCursor, myptr->cbCursor );
  } else {
    myptr->sqlrc = ILE_SQLSetCursorName( myptr->hstmt, myptr->szCursor, myptr->cbCursor );
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLSetCursorNameStruct *) NULL;
  }
  return myptr;
}
void * SQLSetCursorNameWThread (void *ptr)
{
  SQLSetCursorNameWStruct * myptr = (SQLSetCursorNameWStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLSetCursorNameW( myptr->hstmt, myptr->szCursor, myptr->cbCursor );
  } else {
    myptr->sqlrc = ILE_SQLSetCursorNameW( myptr->hstmt, myptr->szCursor, myptr->cbCursor );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLSetCursorNameWCallback(SQLSetCursorNameWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLSetCursorNameWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLSetCursorNameWAsync ( SQLHSTMT  hstmt, SQLWCHAR * szCursor, SQLSMALLINT  cbCursor, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLSetCursorNameWStruct * myptr = (SQLSetCursorNameWStruct *) malloc(sizeof(SQLSetCursorNameWStruct));
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->szCursor = szCursor;
  myptr->cbCursor = cbCursor;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLSetCursorNameWThread, (void *)myptr);
  return tid;
}
SQLSetCursorNameWStruct * SQLSetCursorNameWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLSetCursorNameWStruct * myptr = (SQLSetCursorNameWStruct *) NULL;
  int active = 0;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLSetCursorNameWStruct *) NULL;
  }
  return myptr;
}
void * SQLSetDescFieldThread (void *ptr)
{
  SQLSetDescFieldStruct * myptr = (SQLSetDescFieldStruct *) ptr;
  init_table_lock(myptr->hdesc, 1);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLSetDescField( myptr->hdesc, myptr->rcdNum, myptr->fID, myptr->Value, myptr->buffLen );
  } else {
    myptr->sqlrc = ILE_SQLSetDescField( myptr->hdesc, myptr->rcdNum, myptr->fID, myptr->Value, myptr->buffLen );
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hdesc, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLSetDescFieldStruct *) NULL;
  }
  return myptr;
}
void * SQLSetDescFieldWThread (void *ptr)
{
  SQLSetDescFieldWStruct * myptr = (SQLSetDescFieldWStruct *) ptr;
  init_table_lock(myptr->hdesc, 1);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLSetDescFieldW( myptr->hdesc, myptr->rcdNum, myptr->fID, myptr->Value, myptr->buffLen );
  } else {
    myptr->sqlrc = ILE_SQLSetDescFieldW( myptr->hdesc, myptr->rcdNum, myptr->fID, myptr->Value, myptr->buffLen );
  }
  init_table_unlock(myptr->hdesc, 1);
  /* void SQLSetDescFieldWCallback(SQLSetDescFieldWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLSetDescFieldWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLSetDescFieldWAsync ( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  fID, SQLPOINTER  Value, SQLINTEGER  buffLen, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLSetDescFieldWStruct * myptr = (SQLSetDescFieldWStruct *) malloc(sizeof(SQLSetDescFieldWStruct));
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdesc = hdesc;
  myptr->rcdNum = rcdNum;
  myptr->fID = fID;
  myptr->Value = Value;
  myptr->buffLen = buffLen;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLSetDescFieldWThread, (void *)myptr);
  return tid;
}
SQLSetDescFieldWStruct * SQLSetDescFieldWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLSetDescFieldWStruct * myptr = (SQLSetDescFieldWStruct *) NULL;
  int active = 0;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hdesc, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLSetDescFieldWStruct *) NULL;
  }
  return myptr;
}
void * SQLSetDescRecThread (void *ptr)
{
  SQLSetDescRecStruct * myptr = (SQLSetDescRecStruct *) ptr;
  init_table_lock(myptr->hdesc, 1);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLSetDescRec( myptr->hdesc, myptr->rcdNum, myptr->Type, myptr->subType, myptr->fLength, myptr->fPrec, myptr->fScale, myptr->Value, myptr->sLength, myptr->indic );
  } else {
    myptr->sqlrc = ILE_SQLSetDescRec( myptr->hdesc, myptr->rcdNum, myptr->Type, myptr->subType, myptr->fLength, myptr->fPrec, myptr->fScale, myptr->Value, myptr->sLength, myptr->indic );
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLSetEnvAttr( myptr->hEnv, myptr->fAttribute, myptr->pParam, myptr->cbParam );
  } else {
    myptr->sqlrc = ILE_SQLSetEnvAttr( myptr->hEnv, myptr->fAttribute, myptr->pParam, myptr->cbParam );
  }
  /* not lock */
  /* void SQLSetEnvAttrCallback(SQLSetEnvAttrStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLSetEnvAttrStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLSetEnvAttrAsync ( SQLHENV  hEnv, SQLINTEGER  fAttribute, SQLPOINTER  pParam, SQLINTEGER  cbParam, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLSetEnvAttrStruct * myptr = (SQLSetEnvAttrStruct *) malloc(sizeof(SQLSetEnvAttrStruct));
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hEnv = hEnv;
  myptr->fAttribute = fAttribute;
  myptr->pParam = pParam;
  myptr->cbParam = cbParam;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLSetEnvAttrThread, (void *)myptr);
  return tid;
}
SQLSetEnvAttrStruct * SQLSetEnvAttrJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLSetEnvAttrStruct * myptr = (SQLSetEnvAttrStruct *) NULL;
  int active = 0;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLSetParam( myptr->hstmt, myptr->ipar, myptr->fCType, myptr->fSqlType, myptr->cbColDef, myptr->ibScale, myptr->rgbValue, myptr->pcbValue );
  } else {
    myptr->sqlrc = ILE_SQLSetParam( myptr->hstmt, myptr->ipar, myptr->fCType, myptr->fSqlType, myptr->cbColDef, myptr->ibScale, myptr->rgbValue, myptr->pcbValue );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLSetParamCallback(SQLSetParamStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLSetParamStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLSetParamAsync ( SQLHSTMT  hstmt, SQLSMALLINT  ipar, SQLSMALLINT  fCType, SQLSMALLINT  fSqlType, SQLINTEGER  cbColDef, SQLSMALLINT  ibScale, SQLPOINTER  rgbValue, SQLINTEGER * pcbValue, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLSetParamStruct * myptr = (SQLSetParamStruct *) malloc(sizeof(SQLSetParamStruct));
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->ipar = ipar;
  myptr->fCType = fCType;
  myptr->fSqlType = fSqlType;
  myptr->cbColDef = cbColDef;
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLSetStmtAttr( myptr->hstmt, myptr->fAttr, myptr->pParam, myptr->vParam );
  } else {
    myptr->sqlrc = ILE_SQLSetStmtAttr( myptr->hstmt, myptr->fAttr, myptr->pParam, myptr->vParam );
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLSetStmtAttrStruct *) NULL;
  }
  return myptr;
}
void * SQLSetStmtAttrWThread (void *ptr)
{
  SQLSetStmtAttrWStruct * myptr = (SQLSetStmtAttrWStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLSetStmtAttrW( myptr->hstmt, myptr->fAttr, myptr->pParam, myptr->vParam );
  } else {
    myptr->sqlrc = ILE_SQLSetStmtAttrW( myptr->hstmt, myptr->fAttr, myptr->pParam, myptr->vParam );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLSetStmtAttrWCallback(SQLSetStmtAttrWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLSetStmtAttrWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLSetStmtAttrWAsync ( SQLHSTMT  hstmt, SQLINTEGER  fAttr, SQLPOINTER  pParam, SQLINTEGER  vParam, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLSetStmtAttrWStruct * myptr = (SQLSetStmtAttrWStruct *) malloc(sizeof(SQLSetStmtAttrWStruct));
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->fAttr = fAttr;
  myptr->pParam = pParam;
  myptr->vParam = vParam;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLSetStmtAttrWThread, (void *)myptr);
  return tid;
}
SQLSetStmtAttrWStruct * SQLSetStmtAttrWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLSetStmtAttrWStruct * myptr = (SQLSetStmtAttrWStruct *) NULL;
  int active = 0;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLSetStmtAttrWStruct *) NULL;
  }
  return myptr;
}
void * SQLSetStmtOptionThread (void *ptr)
{
  SQLSetStmtOptionStruct * myptr = (SQLSetStmtOptionStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLSetStmtOption( myptr->hstmt, myptr->fOption, myptr->vParam );
  } else {
    myptr->sqlrc = ILE_SQLSetStmtOption( myptr->hstmt, myptr->fOption, myptr->vParam );
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLSetStmtOptionStruct *) NULL;
  }
  return myptr;
}
void * SQLSetStmtOptionWThread (void *ptr)
{
  SQLSetStmtOptionWStruct * myptr = (SQLSetStmtOptionWStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLSetStmtOptionW( myptr->hstmt, myptr->fOption, myptr->vParam );
  } else {
    myptr->sqlrc = ILE_SQLSetStmtOptionW( myptr->hstmt, myptr->fOption, myptr->vParam );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLSetStmtOptionWCallback(SQLSetStmtOptionWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLSetStmtOptionWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLSetStmtOptionWAsync ( SQLHSTMT  hstmt, SQLSMALLINT  fOption, SQLPOINTER  vParam, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLSetStmtOptionWStruct * myptr = (SQLSetStmtOptionWStruct *) malloc(sizeof(SQLSetStmtOptionWStruct));
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->fOption = fOption;
  myptr->vParam = vParam;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLSetStmtOptionWThread, (void *)myptr);
  return tid;
}
SQLSetStmtOptionWStruct * SQLSetStmtOptionWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLSetStmtOptionWStruct * myptr = (SQLSetStmtOptionWStruct *) NULL;
  int active = 0;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLSetStmtOptionWStruct *) NULL;
  }
  return myptr;
}
void * SQLSpecialColumnsThread (void *ptr)
{
  SQLSpecialColumnsStruct * myptr = (SQLSpecialColumnsStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLSpecialColumns( myptr->hstmt, myptr->fColType, myptr->szTableQual, myptr->cbTableQual, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName, myptr->fScope, myptr->fNullable );
  } else {
    myptr->sqlrc = ILE_SQLSpecialColumns( myptr->hstmt, myptr->fColType, myptr->szTableQual, myptr->cbTableQual, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName, myptr->fScope, myptr->fNullable );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLSpecialColumnsCallback(SQLSpecialColumnsStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLSpecialColumnsStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLSpecialColumnsAsync ( SQLHSTMT  hstmt, SQLSMALLINT  fColType, SQLCHAR * szTableQual, SQLSMALLINT  cbTableQual, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLSMALLINT  fScope, SQLSMALLINT  fNullable, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLSpecialColumnsStruct * myptr = (SQLSpecialColumnsStruct *) malloc(sizeof(SQLSpecialColumnsStruct));
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->fColType = fColType;
  myptr->szTableQual = szTableQual;
  myptr->cbTableQual = cbTableQual;
  myptr->szTableOwner = szTableOwner;
  myptr->cbTableOwner = cbTableOwner;
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLSpecialColumnsStruct *) NULL;
  }
  return myptr;
}
void * SQLSpecialColumnsWThread (void *ptr)
{
  SQLSpecialColumnsWStruct * myptr = (SQLSpecialColumnsWStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLSpecialColumnsW( myptr->hstmt, myptr->fColType, myptr->szTableQual, myptr->cbTableQual, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName, myptr->fScope, myptr->fNullable );
  } else {
    myptr->sqlrc = ILE_SQLSpecialColumnsW( myptr->hstmt, myptr->fColType, myptr->szTableQual, myptr->cbTableQual, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName, myptr->fScope, myptr->fNullable );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLSpecialColumnsWCallback(SQLSpecialColumnsWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLSpecialColumnsWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLSpecialColumnsWAsync ( SQLHSTMT  hstmt, SQLSMALLINT  fColType, SQLWCHAR * szTableQual, SQLSMALLINT  cbTableQual, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName, SQLSMALLINT  fScope, SQLSMALLINT  fNullable, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLSpecialColumnsWStruct * myptr = (SQLSpecialColumnsWStruct *) malloc(sizeof(SQLSpecialColumnsWStruct));
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->fColType = fColType;
  myptr->szTableQual = szTableQual;
  myptr->cbTableQual = cbTableQual;
  myptr->szTableOwner = szTableOwner;
  myptr->cbTableOwner = cbTableOwner;
  myptr->szTableName = szTableName;
  myptr->cbTableName = cbTableName;
  myptr->fScope = fScope;
  myptr->fNullable = fNullable;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLSpecialColumnsWThread, (void *)myptr);
  return tid;
}
SQLSpecialColumnsWStruct * SQLSpecialColumnsWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLSpecialColumnsWStruct * myptr = (SQLSpecialColumnsWStruct *) NULL;
  int active = 0;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLSpecialColumnsWStruct *) NULL;
  }
  return myptr;
}
void * SQLStartTranThread (void *ptr)
{
  SQLStartTranStruct * myptr = (SQLStartTranStruct *) ptr;
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLStartTran( myptr->htype, myptr->henv, myptr->mode, myptr->clevel );
  } else {
    myptr->sqlrc = ILE_SQLStartTran( myptr->htype, myptr->henv, myptr->mode, myptr->clevel );
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLStatistics( myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName, myptr->fUnique, myptr->fres );
  } else {
    myptr->sqlrc = ILE_SQLStatistics( myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName, myptr->fUnique, myptr->fres );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLStatisticsCallback(SQLStatisticsStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLStatisticsStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLStatisticsAsync ( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLSMALLINT  fUnique, SQLSMALLINT  fres, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLStatisticsStruct * myptr = (SQLStatisticsStruct *) malloc(sizeof(SQLStatisticsStruct));
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->szTableQualifier = szTableQualifier;
  myptr->cbTableQualifier = cbTableQualifier;
  myptr->szTableOwner = szTableOwner;
  myptr->cbTableOwner = cbTableOwner;
  myptr->szTableName = szTableName;
  myptr->cbTableName = cbTableName;
  myptr->fUnique = fUnique;
  myptr->fres = fres;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLStatisticsThread, (void *)myptr);
  return tid;
}
SQLStatisticsStruct * SQLStatisticsJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLStatisticsStruct * myptr = (SQLStatisticsStruct *) NULL;
  int active = 0;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLStatisticsStruct *) NULL;
  }
  return myptr;
}
void * SQLStatisticsWThread (void *ptr)
{
  SQLStatisticsWStruct * myptr = (SQLStatisticsWStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLStatisticsW( myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName, myptr->fUnique, myptr->fres );
  } else {
    myptr->sqlrc = ILE_SQLStatisticsW( myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName, myptr->fUnique, myptr->fres );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLStatisticsWCallback(SQLStatisticsWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLStatisticsWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLStatisticsWAsync ( SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName, SQLSMALLINT  fUnique, SQLSMALLINT  fres, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLStatisticsWStruct * myptr = (SQLStatisticsWStruct *) malloc(sizeof(SQLStatisticsWStruct));
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->szTableQualifier = szTableQualifier;
  myptr->cbTableQualifier = cbTableQualifier;
  myptr->szTableOwner = szTableOwner;
  myptr->cbTableOwner = cbTableOwner;
  myptr->szTableName = szTableName;
  myptr->cbTableName = cbTableName;
  myptr->fUnique = fUnique;
  myptr->fres = fres;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLStatisticsWThread, (void *)myptr);
  return tid;
}
SQLStatisticsWStruct * SQLStatisticsWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLStatisticsWStruct * myptr = (SQLStatisticsWStruct *) NULL;
  int active = 0;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLStatisticsWStruct *) NULL;
  }
  return myptr;
}
void * SQLTablePrivilegesThread (void *ptr)
{
  SQLTablePrivilegesStruct * myptr = (SQLTablePrivilegesStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLTablePrivileges( myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName );
  } else {
    myptr->sqlrc = ILE_SQLTablePrivileges( myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLTablePrivilegesCallback(SQLTablePrivilegesStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLTablePrivilegesStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLTablePrivilegesAsync ( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLTablePrivilegesStruct * myptr = (SQLTablePrivilegesStruct *) malloc(sizeof(SQLTablePrivilegesStruct));
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->szTableQualifier = szTableQualifier;
  myptr->cbTableQualifier = cbTableQualifier;
  myptr->szTableOwner = szTableOwner;
  myptr->cbTableOwner = cbTableOwner;
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLTablePrivilegesStruct *) NULL;
  }
  return myptr;
}
void * SQLTablePrivilegesWThread (void *ptr)
{
  SQLTablePrivilegesWStruct * myptr = (SQLTablePrivilegesWStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLTablePrivilegesW( myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName );
  } else {
    myptr->sqlrc = ILE_SQLTablePrivilegesW( myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLTablePrivilegesWCallback(SQLTablePrivilegesWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLTablePrivilegesWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLTablePrivilegesWAsync ( SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLTablePrivilegesWStruct * myptr = (SQLTablePrivilegesWStruct *) malloc(sizeof(SQLTablePrivilegesWStruct));
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->szTableQualifier = szTableQualifier;
  myptr->cbTableQualifier = cbTableQualifier;
  myptr->szTableOwner = szTableOwner;
  myptr->cbTableOwner = cbTableOwner;
  myptr->szTableName = szTableName;
  myptr->cbTableName = cbTableName;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLTablePrivilegesWThread, (void *)myptr);
  return tid;
}
SQLTablePrivilegesWStruct * SQLTablePrivilegesWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLTablePrivilegesWStruct * myptr = (SQLTablePrivilegesWStruct *) NULL;
  int active = 0;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLTablePrivilegesWStruct *) NULL;
  }
  return myptr;
}
void * SQLTablesThread (void *ptr)
{
  SQLTablesStruct * myptr = (SQLTablesStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLTables( myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName, myptr->szTableType, myptr->cbTableType );
  } else {
    myptr->sqlrc = ILE_SQLTables( myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName, myptr->szTableType, myptr->cbTableType );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLTablesCallback(SQLTablesStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLTablesStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLTablesAsync ( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLCHAR * szTableType, SQLSMALLINT  cbTableType, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLTablesStruct * myptr = (SQLTablesStruct *) malloc(sizeof(SQLTablesStruct));
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->szTableQualifier = szTableQualifier;
  myptr->cbTableQualifier = cbTableQualifier;
  myptr->szTableOwner = szTableOwner;
  myptr->cbTableOwner = cbTableOwner;
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLTablesStruct *) NULL;
  }
  return myptr;
}
void * SQLTablesWThread (void *ptr)
{
  SQLTablesWStruct * myptr = (SQLTablesWStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLTablesW( myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName, myptr->szTableType, myptr->cbTableType );
  } else {
    myptr->sqlrc = ILE_SQLTablesW( myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName, myptr->szTableType, myptr->cbTableType );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLTablesWCallback(SQLTablesWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLTablesWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLTablesWAsync ( SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName, SQLWCHAR * szTableType, SQLSMALLINT  cbTableType, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLTablesWStruct * myptr = (SQLTablesWStruct *) malloc(sizeof(SQLTablesWStruct));
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->szTableQualifier = szTableQualifier;
  myptr->cbTableQualifier = cbTableQualifier;
  myptr->szTableOwner = szTableOwner;
  myptr->cbTableOwner = cbTableOwner;
  myptr->szTableName = szTableName;
  myptr->cbTableName = cbTableName;
  myptr->szTableType = szTableType;
  myptr->cbTableType = cbTableType;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLTablesWThread, (void *)myptr);
  return tid;
}
SQLTablesWStruct * SQLTablesWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLTablesWStruct * myptr = (SQLTablesWStruct *) NULL;
  int active = 0;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLTablesWStruct *) NULL;
  }
  return myptr;
}
void * SQLTransactThread (void *ptr)
{
  SQLTransactStruct * myptr = (SQLTransactStruct *) ptr;
  /* not lock */
  if (i_am_big_chicken_flag) {
    myptr->sqlrc = libdb400_SQLTransact( myptr->henv, myptr->hdbc, myptr->fType );
  } else {
    myptr->sqlrc = ILE_SQLTransact( myptr->henv, myptr->hdbc, myptr->fType );
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  /* not lock */
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLTransactStruct *) NULL;
  }
  return myptr;
}
void * SQL400ToUtf8Thread (void *ptr)
{
  SQL400ToUtf8Struct * myptr = (SQL400ToUtf8Struct *) ptr;
  init_table_lock(myptr->hdbc, 0);
  myptr->sqlrc = custom_SQL400ToUtf8( myptr->hdbc, myptr->inparm, myptr->inlen, myptr->outparm, myptr->outlen, myptr->inccsid );
  init_table_unlock(myptr->hdbc, 0);
  /* void SQL400ToUtf8Callback(SQL400ToUtf8Struct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQL400ToUtf8Struct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQL400ToUtf8Async ( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  inccsid, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQL400ToUtf8Struct * myptr = (SQL400ToUtf8Struct *) malloc(sizeof(SQL400ToUtf8Struct));
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdbc = hdbc;
  myptr->inparm = inparm;
  myptr->inlen = inlen;
  myptr->outparm = outparm;
  myptr->outlen = outlen;
  myptr->inccsid = inccsid;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQL400ToUtf8Thread, (void *)myptr);
  return tid;
}
SQL400ToUtf8Struct * SQL400ToUtf8Join (pthread_t tid, SQLINTEGER flag)
{
  SQL400ToUtf8Struct * myptr = (SQL400ToUtf8Struct *) NULL;
  int active = 0;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hdbc, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQL400ToUtf8Struct *) NULL;
  }
  return myptr;
}
void * SQL400FromUtf8Thread (void *ptr)
{
  SQL400FromUtf8Struct * myptr = (SQL400FromUtf8Struct *) ptr;
  init_table_lock(myptr->hdbc, 0);
  myptr->sqlrc = custom_SQL400FromUtf8( myptr->hdbc, myptr->inparm, myptr->inlen, myptr->outparm, myptr->outlen, myptr->outccsid );
  init_table_unlock(myptr->hdbc, 0);
  /* void SQL400FromUtf8Callback(SQL400FromUtf8Struct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQL400FromUtf8Struct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQL400FromUtf8Async ( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  outccsid, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQL400FromUtf8Struct * myptr = (SQL400FromUtf8Struct *) malloc(sizeof(SQL400FromUtf8Struct));
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdbc = hdbc;
  myptr->inparm = inparm;
  myptr->inlen = inlen;
  myptr->outparm = outparm;
  myptr->outlen = outlen;
  myptr->outccsid = outccsid;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQL400FromUtf8Thread, (void *)myptr);
  return tid;
}
SQL400FromUtf8Struct * SQL400FromUtf8Join (pthread_t tid, SQLINTEGER flag)
{
  SQL400FromUtf8Struct * myptr = (SQL400FromUtf8Struct *) NULL;
  int active = 0;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hdbc, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQL400FromUtf8Struct *) NULL;
  }
  return myptr;
}
void * SQL400ToUtf16Thread (void *ptr)
{
  SQL400ToUtf16Struct * myptr = (SQL400ToUtf16Struct *) ptr;
  init_table_lock(myptr->hdbc, 0);
  myptr->sqlrc = custom_SQL400ToUtf16( myptr->hdbc, myptr->inparm, myptr->inlen, myptr->outparm, myptr->outlen, myptr->inccsid );
  init_table_unlock(myptr->hdbc, 0);
  /* void SQL400ToUtf16Callback(SQL400ToUtf16Struct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQL400ToUtf16Struct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQL400ToUtf16Async ( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  inccsid, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQL400ToUtf16Struct * myptr = (SQL400ToUtf16Struct *) malloc(sizeof(SQL400ToUtf16Struct));
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdbc = hdbc;
  myptr->inparm = inparm;
  myptr->inlen = inlen;
  myptr->outparm = outparm;
  myptr->outlen = outlen;
  myptr->inccsid = inccsid;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQL400ToUtf16Thread, (void *)myptr);
  return tid;
}
SQL400ToUtf16Struct * SQL400ToUtf16Join (pthread_t tid, SQLINTEGER flag)
{
  SQL400ToUtf16Struct * myptr = (SQL400ToUtf16Struct *) NULL;
  int active = 0;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hdbc, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQL400ToUtf16Struct *) NULL;
  }
  return myptr;
}
void * SQL400FromUtf16Thread (void *ptr)
{
  SQL400FromUtf16Struct * myptr = (SQL400FromUtf16Struct *) ptr;
  init_table_lock(myptr->hdbc, 0);
  myptr->sqlrc = custom_SQL400FromUtf16( myptr->hdbc, myptr->inparm, myptr->inlen, myptr->outparm, myptr->outlen, myptr->outccsid );
  init_table_unlock(myptr->hdbc, 0);
  /* void SQL400FromUtf16Callback(SQL400FromUtf16Struct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQL400FromUtf16Struct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQL400FromUtf16Async ( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  outccsid, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQL400FromUtf16Struct * myptr = (SQL400FromUtf16Struct *) malloc(sizeof(SQL400FromUtf16Struct));
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdbc = hdbc;
  myptr->inparm = inparm;
  myptr->inlen = inlen;
  myptr->outparm = outparm;
  myptr->outlen = outlen;
  myptr->outccsid = outccsid;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQL400FromUtf16Thread, (void *)myptr);
  return tid;
}
SQL400FromUtf16Struct * SQL400FromUtf16Join (pthread_t tid, SQLINTEGER flag)
{
  SQL400FromUtf16Struct * myptr = (SQL400FromUtf16Struct *) NULL;
  int active = 0;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hdbc, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQL400FromUtf16Struct *) NULL;
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  /* not lock */
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQL400ConnectStruct *) NULL;
  }
  return myptr;
}
void * SQL400AddCVarThread (void *ptr)
{
  SQL400AddCVarStruct * myptr = (SQL400AddCVarStruct *) ptr;
  myptr->sqlrc = custom_SQL400AddCVar( myptr->icol, myptr->inOutType, myptr->pfSqlCType, myptr->pfSqlCValue, myptr->indPtr, myptr->parms );
  /* void SQL400AddCVarCallback(SQL400AddCVarStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQL400AddCVarStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQL400AddCVarAsync ( SQLSMALLINT  icol, SQLSMALLINT  inOutType, SQLSMALLINT  pfSqlCType, SQLPOINTER  pfSqlCValue, SQLINTEGER * indPtr, SQLPOINTER  parms, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQL400AddCVarStruct * myptr = (SQL400AddCVarStruct *) malloc(sizeof(SQL400AddCVarStruct));
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  myptr->sqlrc = SQL_SUCCESS;
  myptr->icol = icol;
  myptr->inOutType = inOutType;
  myptr->pfSqlCType = pfSqlCType;
  myptr->pfSqlCValue = pfSqlCValue;
  myptr->indPtr = indPtr;
  myptr->parms = parms;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQL400AddCVarThread, (void *)myptr);
  return tid;
}
SQL400AddCVarStruct * SQL400AddCVarJoin (pthread_t tid, SQLINTEGER flag)
{
  SQL400AddCVarStruct * myptr = (SQL400AddCVarStruct *) NULL;
  int active = 0;
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQL400AddCVarStruct *) NULL;
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
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
  if (i_am_big_chicken_flag) {
    init_dlsym();
  }
  active = init_table_in_progress(myptr->hstmt, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQL400Stmt2HdbcStruct *) NULL;
  }
  return myptr;
}
