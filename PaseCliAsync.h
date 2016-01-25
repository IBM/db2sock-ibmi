#ifndef _PASECLIASYNC_H
#define _PASECLIASYNC_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dlfcn.h>
#include <sqlcli1.h>


/* special SQL400 aggregate functions */
/* do common work for language driver */
/* composite calls to CLI also async  */

#define SQL400_FLAG_JOIN_WAIT 0
#define SQL400_FLAG_JOIN_NO_WAIT 1

/* Use:
 * SQL400Environment
 */
#define SQL400_ATTR_CCSID 4242
/* Use:
 *   SQL400Environment ( ..., SQLPOINTER  options )
 *   SQL400Connect ( ..., SQLPOINTER  options )
 *   SQL400SetAttr ( ..., SQLPOINTER  options )
 * CTOR:
 *   SQL400AddAttr
 * Struct:
 *   SQL400AttrStruct
 *     e - EnvAttr
 *     c - ConnectAttr
 *     s - StmtAttr
 *     o - StmtOption
 */
#define SQL400_ONERR_CONT 1
#define SQL400_ONERR_STOP 2
#define SQL400_FLAG_IMMED 0
#define SQL400_FLAG_PRE_CONNECT 1
#define SQL400_FLAG_POST_CONNECT 2
typedef struct SQL400AttrStruct {
 SQLINTEGER scope;   /*      - scope  - SQL_HANDLE_ENV|DBC|SRTMT|DESC */
 SQLHANDLE  hndl;    /* ecso - hndl   - CLI handle                    */
 SQLINTEGER attrib;  /* ecso - attrib - CLI attribute                 */
 SQLPOINTER vParam;  /* ecso - vParam - ptr to CLI value              */
 SQLINTEGER inlen;   /* ecs  - inlen  - len CLI value (string)        */
 SQLINTEGER sqlrc;   /*      - sqlrc  - sql return code               */
 SQLINTEGER onerr;   /*      - onerr  - SQL400_ONERR_xxx              */
 SQLINTEGER flag;    /*      - flag   - SQL400_FLAG_xxx               */
} SQL400AttrStruct;
/* Use:
 *   SQL400Execute( ..., SQLPOINTER parms, SQLPOINTER desc_parms)
 *   SQL400Fetch (..., SQLPOINTER desc_cols)
 * CTOR:
 *   SQL400Describe
 *   SQL400AddCVar
 * Struct:
 *   SQL400ParamStruct
 *   SQL400DescribeStruct
 *     p - SQLDescribeParam
 *     c - SQLDescribeCol
 */
#define SQL400_DESC_PARM 0
#define SQL400_DESC_COL  1
#define SQL400_PARM_IO_FILE 42
typedef struct SQL400ParamStruct {
 SQLSMALLINT icol;            /* icol         - param number      (in)  */
 SQLSMALLINT inOutType;       /* inOutType    - sql C in/out flag (in)  */
 SQLSMALLINT pfSqlCType;      /* pfSqlCType   - sql C data type   (in)  */
 SQLPOINTER  pfSqlCValue;     /* pfSqlCValue  - sql C ptr to data (out) */
 SQLINTEGER * indPtr;         /* indPtr       - sql strlen/ind    (out) */
} SQL400ParamStruct;

typedef struct SQL400DescStruct {
 SQLSMALLINT itype;           /*    - itype        - descr col/parm  (out) */
 SQLSMALLINT icol;            /* pc - icol         - column number   (in)  */
 SQLCHAR *   szColName;       /*  c - szColName    - column name ptr (out) */
 SQLSMALLINT cbColNameMax;    /*  c - cbColNameMax - name max len    (in)  */
 SQLSMALLINT pcbColName;      /*  c - pcbColName   - name size len   (out) */
 SQLSMALLINT pfSqlType;       /* pc - pfSqlType    - sql data type   (out) */
 SQLINTEGER  pcbColDef;       /* pc - pcbColDef    - sql size column (out) */
 SQLSMALLINT pibScale;        /* pc - pibScale     - decimal digits  (out) */
 SQLSMALLINT pfNullable;      /* pc - pfNullable   - null allowed    (out) */
 SQLCHAR     bfColName[1024]; /*  c - bfColName    - column name buf (out) */
} SQL400DescStruct;

SQLRETURN SQL400AddAttr( SQLINTEGER  scope, SQLINTEGER  attrib, SQLPOINTER  vParam, SQLINTEGER  inlen, SQLINTEGER  onerr, SQLINTEGER  flag, SQLPOINTER  options );
SQLRETURN SQL400SetAttr( SQLINTEGER  scope, SQLHANDLE  hndl, SQLINTEGER  flag, SQLPOINTER  options );
SQLRETURN SQL400Environment( SQLINTEGER * ohnd, SQLPOINTER  options );
SQLRETURN SQL400Connect( SQLHENV  henv, SQLCHAR * db, SQLCHAR * uid, SQLCHAR * pwd, SQLINTEGER * ohnd, SQLPOINTER  options );
SQLRETURN SQL400AddCVar( SQLSMALLINT  icol, SQLSMALLINT  inOutType, SQLSMALLINT  pfSqlCType, SQLPOINTER  pfSqlCValue, SQLINTEGER * indPtr, SQLPOINTER  parms );
SQLRETURN SQL400AddDesc( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  flag, SQLPOINTER  descs );
SQLRETURN SQL400Execute( SQLHSTMT  hstmt, SQLPOINTER  parms, SQLPOINTER  desc_parms );
SQLRETURN SQL400Fetch( SQLHSTMT  hstmt, SQLINTEGER  start_row, SQLPOINTER  cols, SQLPOINTER  desc_cols );
SQLRETURN SQL400Stmt2Hdbc( SQLHSTMT  hstmt, SQLINTEGER * ohnd );

/* choose either callback or join    */
/* following structures returned     */
/* caller must free return structure */

typedef struct SQLOverrideCCSID400Struct { SQLRETURN sqlrc; int  newCCSID; void * callback; } SQLOverrideCCSID400Struct;
typedef struct SQLBindColStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLSMALLINT  icol; SQLSMALLINT  fCType; SQLPOINTER  rgbValue; SQLINTEGER  cbValueMax; SQLINTEGER * pcbValue; void * callback; } SQLBindColStruct;
typedef struct SQLBindFileToColStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLSMALLINT  icol; SQLCHAR * fName; SQLSMALLINT * fNameLen; SQLINTEGER * fOptions; SQLSMALLINT  fValueMax; SQLINTEGER * sLen; SQLINTEGER * pcbValue; void * callback; } SQLBindFileToColStruct;
typedef struct SQLBindFileToParamStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLSMALLINT  ipar; SQLSMALLINT  iType; SQLCHAR * fName; SQLSMALLINT * fNameLen; SQLINTEGER * fOptions; SQLSMALLINT  fValueMax; SQLINTEGER * pcbValue; void * callback; } SQLBindFileToParamStruct;
typedef struct SQLBindParamStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLSMALLINT  iparm; SQLSMALLINT  iType; SQLSMALLINT  pType; SQLINTEGER  pLen; SQLSMALLINT  pScale; SQLPOINTER  pData; SQLINTEGER * pcbValue; void * callback; } SQLBindParamStruct;
typedef struct SQLBindParameterStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLSMALLINT  ipar; SQLSMALLINT  fParamType; SQLSMALLINT  fCType; SQLSMALLINT  fSQLType; SQLINTEGER  pLen; SQLSMALLINT  pScale; SQLPOINTER  pData; SQLINTEGER  cbValueMax; SQLINTEGER * pcbValue; void * callback; } SQLBindParameterStruct;
typedef struct SQLCancelStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; void * callback; } SQLCancelStruct;
typedef struct SQLCloseCursorStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; void * callback; } SQLCloseCursorStruct;
typedef struct SQLColAttributesStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLSMALLINT  icol; SQLSMALLINT  fDescType; SQLCHAR * rgbDesc; SQLINTEGER  cbDescMax; SQLINTEGER * pcbDesc; SQLINTEGER * pfDesc; void * callback; } SQLColAttributesStruct;
typedef struct SQLColumnPrivilegesStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLCHAR * szCatalogName; SQLSMALLINT  cbCatalogName; SQLCHAR * szSchemaName; SQLSMALLINT  cbSchemaName; SQLCHAR * szTableName; SQLSMALLINT  cbTableName; SQLCHAR * szColumnName; SQLSMALLINT  cbColumnName; void * callback; } SQLColumnPrivilegesStruct;
typedef struct SQLColumnsStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLCHAR * szCatalogName; SQLSMALLINT  cbCatalogName; SQLCHAR * szSchemaName; SQLSMALLINT  cbSchemaName; SQLCHAR * szTableName; SQLSMALLINT  cbTableName; SQLCHAR * szColumnName; SQLSMALLINT  cbColumnName; void * callback; } SQLColumnsStruct;
typedef struct SQLConnectStruct { SQLRETURN sqlrc; SQLHDBC  hdbc; SQLCHAR * szDSN; SQLSMALLINT  cbDSN; SQLCHAR * szUID; SQLSMALLINT  cbUID; SQLCHAR * szAuthStr; SQLSMALLINT  cbAuthStr; void * callback; } SQLConnectStruct;
typedef struct SQLCopyDescStruct { SQLRETURN sqlrc; SQLHDESC  sDesc; SQLHDESC  tDesc; void * callback; } SQLCopyDescStruct;
typedef struct SQLDataSourcesStruct { SQLRETURN sqlrc; SQLHENV  henv; SQLSMALLINT  fDirection; SQLCHAR * szDSN; SQLSMALLINT  cbDSNMax; SQLSMALLINT * pcbDSN; SQLCHAR * szDescription; SQLSMALLINT  cbDescriptionMax; SQLSMALLINT * pcbDescription; void * callback; } SQLDataSourcesStruct;
typedef struct SQLDescribeColStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLSMALLINT  icol; SQLCHAR * szColName; SQLSMALLINT  cbColNameMax; SQLSMALLINT * pcbColName; SQLSMALLINT * pfSqlType; SQLINTEGER * pcbColDef; SQLSMALLINT * pibScale; SQLSMALLINT * pfNullable; void * callback; } SQLDescribeColStruct;
typedef struct SQLDescribeParamStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLSMALLINT  ipar; SQLSMALLINT * pfSqlType; SQLINTEGER * pcbColDef; SQLSMALLINT * pibScale; SQLSMALLINT * pfNullable; void * callback; } SQLDescribeParamStruct;
typedef struct SQLDisconnectStruct { SQLRETURN sqlrc; SQLHDBC  hdbc; void * callback; } SQLDisconnectStruct;
typedef struct SQLDriverConnectStruct { SQLRETURN sqlrc; SQLHDBC  hdbc; SQLPOINTER  hwnd; SQLCHAR * szConnStrIn; SQLSMALLINT  cbConnStrin; SQLCHAR * szConnStrOut; SQLSMALLINT  cbConnStrOutMax; SQLSMALLINT * pcbConnStrOut; SQLSMALLINT  fDriverCompletion; void * callback; } SQLDriverConnectStruct;
typedef struct SQLEndTranStruct { SQLRETURN sqlrc; SQLSMALLINT  htype; SQLHENV  henv; SQLSMALLINT  ctype; void * callback; } SQLEndTranStruct;
typedef struct SQLErrorStruct { SQLRETURN sqlrc; SQLHENV  henv; SQLHDBC  hdbc; SQLHSTMT  hstmt; SQLCHAR * szSqlState; SQLINTEGER * pfNativeError; SQLCHAR * szErrorMsg; SQLSMALLINT  cbErrorMsgMax; SQLSMALLINT * pcbErrorMsg; void * callback; } SQLErrorStruct;
typedef struct SQLExecDirectStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLCHAR * szSqlStr; SQLINTEGER  cbSqlStr; void * callback; } SQLExecDirectStruct;
typedef struct SQLExecuteStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; void * callback; } SQLExecuteStruct;
typedef struct SQLExtendedFetchStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLSMALLINT  fOrient; SQLINTEGER  fOffset; SQLINTEGER * pcrow; SQLSMALLINT * rgfRowStatus; void * callback; } SQLExtendedFetchStruct;
typedef struct SQLFetchStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; void * callback; } SQLFetchStruct;
typedef struct SQLFetchScrollStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLSMALLINT  fOrient; SQLINTEGER  fOffset; void * callback; } SQLFetchScrollStruct;
typedef struct SQLForeignKeysStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLCHAR * szPkTableQualifier; SQLSMALLINT  cbPkTableQualifier; SQLCHAR * szPkTableOwner; SQLSMALLINT  cbPkTableOwner; SQLCHAR * szPkTableName; SQLSMALLINT  cbPkTableName; SQLCHAR * szFkTableQualifier; SQLSMALLINT  cbFkTableQualifier; SQLCHAR * szFkTableOwner; SQLSMALLINT  cbFkTableOwner; SQLCHAR * szFkTableName; SQLSMALLINT  cbFkTableName; void * callback; } SQLForeignKeysStruct;
typedef struct SQLGetColStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLSMALLINT  icol; SQLSMALLINT  itype; SQLPOINTER  tval; SQLINTEGER  blen; SQLINTEGER * olen; void * callback; } SQLGetColStruct;
typedef struct SQLGetConnectAttrStruct { SQLRETURN sqlrc; SQLHDBC  hdbc; SQLINTEGER  attr; SQLPOINTER  oval; SQLINTEGER  ilen; SQLINTEGER * olen; void * callback; } SQLGetConnectAttrStruct;
typedef struct SQLGetConnectOptionStruct { SQLRETURN sqlrc; SQLHDBC  hdbc; SQLSMALLINT  fOption; SQLPOINTER  pvParam; void * callback; } SQLGetConnectOptionStruct;
typedef struct SQLGetCursorNameStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLCHAR * szCursor; SQLSMALLINT  cbCursorMax; SQLSMALLINT * pcbCursor; void * callback; } SQLGetCursorNameStruct;
typedef struct SQLGetDataStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLSMALLINT  icol; SQLSMALLINT  fCType; SQLPOINTER  rgbValue; SQLINTEGER  cbValueMax; SQLINTEGER * pcbValue; void * callback; } SQLGetDataStruct;
typedef struct SQLGetDescFieldStruct { SQLRETURN sqlrc; SQLHDESC  hdesc; SQLSMALLINT  rcdNum; SQLSMALLINT  fieldID; SQLPOINTER  fValue; SQLINTEGER  fLength; SQLINTEGER * stLength; void * callback; } SQLGetDescFieldStruct;
typedef struct SQLGetDescRecStruct { SQLRETURN sqlrc; SQLHDESC  hdesc; SQLSMALLINT  rcdNum; SQLCHAR * fname; SQLSMALLINT  bufLen; SQLSMALLINT * sLength; SQLSMALLINT * sType; SQLSMALLINT * sbType; SQLINTEGER * fLength; SQLSMALLINT * fprec; SQLSMALLINT * fscale; SQLSMALLINT * fnull; void * callback; } SQLGetDescRecStruct;
typedef struct SQLGetDiagFieldStruct { SQLRETURN sqlrc; SQLSMALLINT  hType; SQLINTEGER  hndl; SQLSMALLINT  rcdNum; SQLSMALLINT  diagID; SQLPOINTER  dValue; SQLSMALLINT  bLength; SQLSMALLINT * sLength; void * callback; } SQLGetDiagFieldStruct;
typedef struct SQLGetDiagRecStruct { SQLRETURN sqlrc; SQLSMALLINT  hType; SQLINTEGER  hndl; SQLSMALLINT  rcdNum; SQLCHAR * SQLstate; SQLINTEGER * SQLcode; SQLCHAR * msgText; SQLSMALLINT  bLength; SQLSMALLINT * sLength; void * callback; } SQLGetDiagRecStruct;
typedef struct SQLGetEnvAttrStruct { SQLRETURN sqlrc; SQLHENV  henv; SQLINTEGER  Attribute; SQLPOINTER  Value; SQLINTEGER  BufferLength; SQLINTEGER * StringLength; void * callback; } SQLGetEnvAttrStruct;
typedef struct SQLGetFunctionsStruct { SQLRETURN sqlrc; SQLHDBC  hdbc; SQLSMALLINT  fFunction; SQLSMALLINT * pfExists; void * callback; } SQLGetFunctionsStruct;
typedef struct SQLGetInfoStruct { SQLRETURN sqlrc; SQLHDBC  hdbc; SQLSMALLINT  fInfoType; SQLPOINTER  rgbInfoValue; SQLSMALLINT  cbInfoValueMax; SQLSMALLINT * pcbInfoValue; void * callback; } SQLGetInfoStruct;
typedef struct SQLGetLengthStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLSMALLINT  locType; SQLINTEGER  locator; SQLINTEGER * sLength; SQLINTEGER * ind; void * callback; } SQLGetLengthStruct;
typedef struct SQLGetPositionStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLSMALLINT  locType; SQLINTEGER  srceLocator; SQLINTEGER  srchLocator; SQLCHAR * srchLiteral; SQLINTEGER  srchLiteralLen; SQLINTEGER  fPosition; SQLINTEGER * located; SQLINTEGER * ind; void * callback; } SQLGetPositionStruct;
typedef struct SQLGetStmtAttrStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLINTEGER  fAttr; SQLPOINTER  pvParam; SQLINTEGER  bLength; SQLINTEGER * SLength; void * callback; } SQLGetStmtAttrStruct;
typedef struct SQLGetStmtOptionStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLSMALLINT  fOption; SQLPOINTER  pvParam; void * callback; } SQLGetStmtOptionStruct;
typedef struct SQLGetSubStringStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLSMALLINT  locType; SQLINTEGER  srceLocator; SQLINTEGER  fPosition; SQLINTEGER  length; SQLSMALLINT  tType; SQLPOINTER  rgbValue; SQLINTEGER  cbValueMax; SQLINTEGER * StringLength; SQLINTEGER * ind; void * callback; } SQLGetSubStringStruct;
typedef struct SQLGetTypeInfoStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLSMALLINT  fSqlType; void * callback; } SQLGetTypeInfoStruct;
typedef struct SQLLanguagesStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; void * callback; } SQLLanguagesStruct;
typedef struct SQLMoreResultsStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; void * callback; } SQLMoreResultsStruct;
typedef struct SQLNativeSqlStruct { SQLRETURN sqlrc; SQLHDBC  hdbc; SQLCHAR * szSqlStrIn; SQLINTEGER  cbSqlStrIn; SQLCHAR * szSqlStr; SQLINTEGER  cbSqlStrMax; SQLINTEGER * pcbSqlStr; void * callback; } SQLNativeSqlStruct;
typedef struct SQLNextResultStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLHSTMT  hstmt2; void * callback; } SQLNextResultStruct;
typedef struct SQLNumParamsStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLSMALLINT * pcpar; void * callback; } SQLNumParamsStruct;
typedef struct SQLNumResultColsStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLSMALLINT * pccol; void * callback; } SQLNumResultColsStruct;
typedef struct SQLParamDataStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLPOINTER * prgbValue; void * callback; } SQLParamDataStruct;
typedef struct SQLParamOptionsStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLINTEGER  crow; SQLINTEGER * pirow; void * callback; } SQLParamOptionsStruct;
typedef struct SQLPrepareStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLCHAR * szSqlStr; SQLINTEGER  cbSqlStr; void * callback; } SQLPrepareStruct;
typedef struct SQLPrimaryKeysStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLCHAR * szTableQualifier; SQLSMALLINT  cbTableQualifier; SQLCHAR * szTableOwner; SQLSMALLINT  cbTableOwner; SQLCHAR * szTableName; SQLSMALLINT  cbTableName; void * callback; } SQLPrimaryKeysStruct;
typedef struct SQLProcedureColumnsStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLCHAR * szProcQualifier; SQLSMALLINT  cbProcQualifier; SQLCHAR * szProcOwner; SQLSMALLINT  cbProcOwner; SQLCHAR * szProcName; SQLSMALLINT  cbProcName; SQLCHAR * szColumnName; SQLSMALLINT  cbColumnName; void * callback; } SQLProcedureColumnsStruct;
typedef struct SQLProceduresStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLCHAR * szProcQualifier; SQLSMALLINT  cbProcQualifier; SQLCHAR * szProcOwner; SQLSMALLINT  cbProcOwner; SQLCHAR * szProcName; SQLSMALLINT  cbProcName; void * callback; } SQLProceduresStruct;
typedef struct SQLPutDataStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLPOINTER  rgbValue; SQLINTEGER  cbValue; void * callback; } SQLPutDataStruct;
typedef struct SQLReleaseEnvStruct { SQLRETURN sqlrc; SQLHENV  henv; void * callback; } SQLReleaseEnvStruct;
typedef struct SQLRowCountStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLINTEGER * pcrow; void * callback; } SQLRowCountStruct;
typedef struct SQLSetConnectAttrStruct { SQLRETURN sqlrc; SQLHDBC  hdbc; SQLINTEGER  attrib; SQLPOINTER  vParam; SQLINTEGER  inlen; void * callback; } SQLSetConnectAttrStruct;
typedef struct SQLSetConnectOptionStruct { SQLRETURN sqlrc; SQLHDBC  hdbc; SQLSMALLINT  fOption; SQLPOINTER  vParam; void * callback; } SQLSetConnectOptionStruct;
typedef struct SQLSetCursorNameStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLCHAR * szCursor; SQLSMALLINT  cbCursor; void * callback; } SQLSetCursorNameStruct;
typedef struct SQLSetDescFieldStruct { SQLRETURN sqlrc; SQLHDESC  hdesc; SQLSMALLINT  rcdNum; SQLSMALLINT  fID; SQLPOINTER  Value; SQLINTEGER  buffLen; void * callback; } SQLSetDescFieldStruct;
typedef struct SQLSetDescRecStruct { SQLRETURN sqlrc; SQLHDESC  hdesc; SQLSMALLINT  rcdNum; SQLSMALLINT  Type; SQLSMALLINT  subType; SQLINTEGER  fLength; SQLSMALLINT  fPrec; SQLSMALLINT  fScale; SQLPOINTER  Value; SQLINTEGER * sLength; SQLINTEGER * indic; void * callback; } SQLSetDescRecStruct;
typedef struct SQLSetEnvAttrStruct { SQLRETURN sqlrc; SQLHENV  henv; SQLINTEGER  Attribute; SQLPOINTER  Value; SQLINTEGER  StringLength; void * callback; } SQLSetEnvAttrStruct;
typedef struct SQLSetParamStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLSMALLINT  ipar; SQLSMALLINT  fCType; SQLSMALLINT  fSqlType; SQLINTEGER  cbParamDef; SQLSMALLINT  ibScale; SQLPOINTER  rgbValue; SQLINTEGER * pcbValue; void * callback; } SQLSetParamStruct;
typedef struct SQLSetStmtAttrStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLINTEGER  fAttr; SQLPOINTER  pParam; SQLINTEGER  vParam; void * callback; } SQLSetStmtAttrStruct;
typedef struct SQLSetStmtOptionStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLSMALLINT  fOption; SQLPOINTER  vParam; void * callback; } SQLSetStmtOptionStruct;
typedef struct SQLSpecialColumnsStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLSMALLINT  fColType; SQLCHAR * szCatalogName; SQLSMALLINT  cbCatalogName; SQLCHAR * szSchemaName; SQLSMALLINT  cbSchemaName; SQLCHAR * szTableName; SQLSMALLINT  cbTableName; SQLSMALLINT  fScope; SQLSMALLINT  fNullable; void * callback; } SQLSpecialColumnsStruct;
typedef struct SQLStartTranStruct { SQLRETURN sqlrc; SQLSMALLINT  htype; SQLHENV  henv; SQLINTEGER  mode; SQLINTEGER  clevel; void * callback; } SQLStartTranStruct;
typedef struct SQLStatisticsStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLCHAR * szCatalogName; SQLSMALLINT  cbCatalogName; SQLCHAR * szSchemaName; SQLSMALLINT  cbSchemaName; SQLCHAR * szTableName; SQLSMALLINT  cbTableName; SQLSMALLINT  fUnique; SQLSMALLINT  fAccuracy; void * callback; } SQLStatisticsStruct;
typedef struct SQLTablePrivilegesStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLCHAR * szCatalogName; SQLSMALLINT  cbCatalogName; SQLCHAR * szSchemaName; SQLSMALLINT  cbSchemaName; SQLCHAR * szTableName; SQLSMALLINT  cbTableName; void * callback; } SQLTablePrivilegesStruct;
typedef struct SQLTablesStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLCHAR * szCatalogName; SQLSMALLINT  cbCatalogName; SQLCHAR * szSchemaName; SQLSMALLINT  cbSchemaName; SQLCHAR * szTableName; SQLSMALLINT  cbTableName; SQLCHAR * szTableType; SQLSMALLINT  cbTableType; void * callback; } SQLTablesStruct;
typedef struct SQLTransactStruct { SQLRETURN sqlrc; SQLHENV  henv; SQLHDBC  hdbc; SQLSMALLINT  fType; void * callback; } SQLTransactStruct;
typedef struct SQL400AddAttrStruct { SQLRETURN sqlrc; SQLINTEGER  scope; SQLINTEGER  attrib; SQLPOINTER  vParam; SQLINTEGER  inlen; SQLINTEGER  onerr; SQLINTEGER  flag; SQLPOINTER  options; void * callback; } SQL400AddAttrStruct;
typedef struct SQL400SetAttrStruct { SQLRETURN sqlrc; SQLINTEGER  scope; SQLHANDLE  hndl; SQLINTEGER  flag; SQLPOINTER  options; void * callback; } SQL400SetAttrStruct;
typedef struct SQL400EnvironmentStruct { SQLRETURN sqlrc; SQLINTEGER * ohnd; SQLPOINTER  options; void * callback; } SQL400EnvironmentStruct;
typedef struct SQL400ConnectStruct { SQLRETURN sqlrc; SQLHENV  henv; SQLCHAR * db; SQLCHAR * uid; SQLCHAR * pwd; SQLINTEGER * ohnd; SQLPOINTER  options; void * callback; } SQL400ConnectStruct;
typedef struct SQL400AddCVarStruct { SQLRETURN sqlrc; SQLSMALLINT  icol; SQLSMALLINT  inOutType; SQLSMALLINT  pfSqlCType; SQLPOINTER  pfSqlCValue; SQLINTEGER * indPtr; SQLPOINTER  parms; void * callback; } SQL400AddCVarStruct;
typedef struct SQL400AddDescStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLSMALLINT  icol; SQLSMALLINT  flag; SQLPOINTER  descs; void * callback; } SQL400AddDescStruct;
typedef struct SQL400ExecuteStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLPOINTER  parms; SQLPOINTER  desc_parms; void * callback; } SQL400ExecuteStruct;
typedef struct SQL400FetchStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLINTEGER  start_row; SQLPOINTER  cols; SQLPOINTER  desc_cols; void * callback; } SQL400FetchStruct;
typedef struct SQL400Stmt2HdbcStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLINTEGER * ohnd; void * callback; } SQL400Stmt2HdbcStruct;


/* join async thread                    */
/* flag:                                */
/*   SQL400_FLAG_JOIN_WAIT              */
/*     - block until complete           */
/*   SQL400_FLAG_JOIN_NO_WAIT           */
/*     - no block, NULL still executing */

/* void SQLOverrideCCSID400Callback(SQLOverrideCCSID400Struct* ); */
SQLOverrideCCSID400Struct * SQLOverrideCCSID400Join (pthread_t tid, SQLINTEGER flag);
/* void SQLBindColCallback(SQLBindColStruct* ); */
SQLBindColStruct * SQLBindColJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLBindFileToColCallback(SQLBindFileToColStruct* ); */
SQLBindFileToColStruct * SQLBindFileToColJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLBindFileToParamCallback(SQLBindFileToParamStruct* ); */
SQLBindFileToParamStruct * SQLBindFileToParamJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLBindParamCallback(SQLBindParamStruct* ); */
SQLBindParamStruct * SQLBindParamJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLBindParameterCallback(SQLBindParameterStruct* ); */
SQLBindParameterStruct * SQLBindParameterJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLCancelCallback(SQLCancelStruct* ); */
SQLCancelStruct * SQLCancelJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLCloseCursorCallback(SQLCloseCursorStruct* ); */
SQLCloseCursorStruct * SQLCloseCursorJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLColAttributesCallback(SQLColAttributesStruct* ); */
SQLColAttributesStruct * SQLColAttributesJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLColumnPrivilegesCallback(SQLColumnPrivilegesStruct* ); */
SQLColumnPrivilegesStruct * SQLColumnPrivilegesJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLColumnsCallback(SQLColumnsStruct* ); */
SQLColumnsStruct * SQLColumnsJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLConnectCallback(SQLConnectStruct* ); */
SQLConnectStruct * SQLConnectJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLCopyDescCallback(SQLCopyDescStruct* ); */
SQLCopyDescStruct * SQLCopyDescJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLDataSourcesCallback(SQLDataSourcesStruct* ); */
SQLDataSourcesStruct * SQLDataSourcesJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLDescribeColCallback(SQLDescribeColStruct* ); */
SQLDescribeColStruct * SQLDescribeColJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLDescribeParamCallback(SQLDescribeParamStruct* ); */
SQLDescribeParamStruct * SQLDescribeParamJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLDisconnectCallback(SQLDisconnectStruct* ); */
SQLDisconnectStruct * SQLDisconnectJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLDriverConnectCallback(SQLDriverConnectStruct* ); */
SQLDriverConnectStruct * SQLDriverConnectJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLEndTranCallback(SQLEndTranStruct* ); */
SQLEndTranStruct * SQLEndTranJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLErrorCallback(SQLErrorStruct* ); */
SQLErrorStruct * SQLErrorJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLExecDirectCallback(SQLExecDirectStruct* ); */
SQLExecDirectStruct * SQLExecDirectJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLExecuteCallback(SQLExecuteStruct* ); */
SQLExecuteStruct * SQLExecuteJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLExtendedFetchCallback(SQLExtendedFetchStruct* ); */
SQLExtendedFetchStruct * SQLExtendedFetchJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLFetchCallback(SQLFetchStruct* ); */
SQLFetchStruct * SQLFetchJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLFetchScrollCallback(SQLFetchScrollStruct* ); */
SQLFetchScrollStruct * SQLFetchScrollJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLForeignKeysCallback(SQLForeignKeysStruct* ); */
SQLForeignKeysStruct * SQLForeignKeysJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLGetColCallback(SQLGetColStruct* ); */
SQLGetColStruct * SQLGetColJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLGetConnectAttrCallback(SQLGetConnectAttrStruct* ); */
SQLGetConnectAttrStruct * SQLGetConnectAttrJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLGetConnectOptionCallback(SQLGetConnectOptionStruct* ); */
SQLGetConnectOptionStruct * SQLGetConnectOptionJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLGetCursorNameCallback(SQLGetCursorNameStruct* ); */
SQLGetCursorNameStruct * SQLGetCursorNameJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLGetDataCallback(SQLGetDataStruct* ); */
SQLGetDataStruct * SQLGetDataJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLGetDescFieldCallback(SQLGetDescFieldStruct* ); */
SQLGetDescFieldStruct * SQLGetDescFieldJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLGetDescRecCallback(SQLGetDescRecStruct* ); */
SQLGetDescRecStruct * SQLGetDescRecJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLGetDiagFieldCallback(SQLGetDiagFieldStruct* ); */
SQLGetDiagFieldStruct * SQLGetDiagFieldJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLGetDiagRecCallback(SQLGetDiagRecStruct* ); */
SQLGetDiagRecStruct * SQLGetDiagRecJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLGetEnvAttrCallback(SQLGetEnvAttrStruct* ); */
SQLGetEnvAttrStruct * SQLGetEnvAttrJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLGetFunctionsCallback(SQLGetFunctionsStruct* ); */
SQLGetFunctionsStruct * SQLGetFunctionsJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLGetInfoCallback(SQLGetInfoStruct* ); */
SQLGetInfoStruct * SQLGetInfoJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLGetLengthCallback(SQLGetLengthStruct* ); */
SQLGetLengthStruct * SQLGetLengthJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLGetPositionCallback(SQLGetPositionStruct* ); */
SQLGetPositionStruct * SQLGetPositionJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLGetStmtAttrCallback(SQLGetStmtAttrStruct* ); */
SQLGetStmtAttrStruct * SQLGetStmtAttrJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLGetStmtOptionCallback(SQLGetStmtOptionStruct* ); */
SQLGetStmtOptionStruct * SQLGetStmtOptionJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLGetSubStringCallback(SQLGetSubStringStruct* ); */
SQLGetSubStringStruct * SQLGetSubStringJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLGetTypeInfoCallback(SQLGetTypeInfoStruct* ); */
SQLGetTypeInfoStruct * SQLGetTypeInfoJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLLanguagesCallback(SQLLanguagesStruct* ); */
SQLLanguagesStruct * SQLLanguagesJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLMoreResultsCallback(SQLMoreResultsStruct* ); */
SQLMoreResultsStruct * SQLMoreResultsJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLNativeSqlCallback(SQLNativeSqlStruct* ); */
SQLNativeSqlStruct * SQLNativeSqlJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLNextResultCallback(SQLNextResultStruct* ); */
SQLNextResultStruct * SQLNextResultJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLNumParamsCallback(SQLNumParamsStruct* ); */
SQLNumParamsStruct * SQLNumParamsJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLNumResultColsCallback(SQLNumResultColsStruct* ); */
SQLNumResultColsStruct * SQLNumResultColsJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLParamDataCallback(SQLParamDataStruct* ); */
SQLParamDataStruct * SQLParamDataJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLParamOptionsCallback(SQLParamOptionsStruct* ); */
SQLParamOptionsStruct * SQLParamOptionsJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLPrepareCallback(SQLPrepareStruct* ); */
SQLPrepareStruct * SQLPrepareJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLPrimaryKeysCallback(SQLPrimaryKeysStruct* ); */
SQLPrimaryKeysStruct * SQLPrimaryKeysJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLProcedureColumnsCallback(SQLProcedureColumnsStruct* ); */
SQLProcedureColumnsStruct * SQLProcedureColumnsJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLProceduresCallback(SQLProceduresStruct* ); */
SQLProceduresStruct * SQLProceduresJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLPutDataCallback(SQLPutDataStruct* ); */
SQLPutDataStruct * SQLPutDataJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLReleaseEnvCallback(SQLReleaseEnvStruct* ); */
SQLReleaseEnvStruct * SQLReleaseEnvJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLRowCountCallback(SQLRowCountStruct* ); */
SQLRowCountStruct * SQLRowCountJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLSetConnectAttrCallback(SQLSetConnectAttrStruct* ); */
SQLSetConnectAttrStruct * SQLSetConnectAttrJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLSetConnectOptionCallback(SQLSetConnectOptionStruct* ); */
SQLSetConnectOptionStruct * SQLSetConnectOptionJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLSetCursorNameCallback(SQLSetCursorNameStruct* ); */
SQLSetCursorNameStruct * SQLSetCursorNameJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLSetDescFieldCallback(SQLSetDescFieldStruct* ); */
SQLSetDescFieldStruct * SQLSetDescFieldJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLSetDescRecCallback(SQLSetDescRecStruct* ); */
SQLSetDescRecStruct * SQLSetDescRecJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLSetEnvAttrCallback(SQLSetEnvAttrStruct* ); */
SQLSetEnvAttrStruct * SQLSetEnvAttrJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLSetParamCallback(SQLSetParamStruct* ); */
SQLSetParamStruct * SQLSetParamJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLSetStmtAttrCallback(SQLSetStmtAttrStruct* ); */
SQLSetStmtAttrStruct * SQLSetStmtAttrJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLSetStmtOptionCallback(SQLSetStmtOptionStruct* ); */
SQLSetStmtOptionStruct * SQLSetStmtOptionJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLSpecialColumnsCallback(SQLSpecialColumnsStruct* ); */
SQLSpecialColumnsStruct * SQLSpecialColumnsJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLStartTranCallback(SQLStartTranStruct* ); */
SQLStartTranStruct * SQLStartTranJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLStatisticsCallback(SQLStatisticsStruct* ); */
SQLStatisticsStruct * SQLStatisticsJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLTablePrivilegesCallback(SQLTablePrivilegesStruct* ); */
SQLTablePrivilegesStruct * SQLTablePrivilegesJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLTablesCallback(SQLTablesStruct* ); */
SQLTablesStruct * SQLTablesJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLTransactCallback(SQLTransactStruct* ); */
SQLTransactStruct * SQLTransactJoin (pthread_t tid, SQLINTEGER flag);
/* void SQL400AddAttrCallback(SQL400AddAttrStruct* ); */
SQL400AddAttrStruct * SQL400AddAttrJoin (pthread_t tid, SQLINTEGER flag);
/* void SQL400SetAttrCallback(SQL400SetAttrStruct* ); */
SQL400SetAttrStruct * SQL400SetAttrJoin (pthread_t tid, SQLINTEGER flag);
/* void SQL400EnvironmentCallback(SQL400EnvironmentStruct* ); */
SQL400EnvironmentStruct * SQL400EnvironmentJoin (pthread_t tid, SQLINTEGER flag);
/* void SQL400ConnectCallback(SQL400ConnectStruct* ); */
SQL400ConnectStruct * SQL400ConnectJoin (pthread_t tid, SQLINTEGER flag);
/* void SQL400AddCVarCallback(SQL400AddCVarStruct* ); */
SQL400AddCVarStruct * SQL400AddCVarJoin (pthread_t tid, SQLINTEGER flag);
/* void SQL400AddDescCallback(SQL400AddDescStruct* ); */
SQL400AddDescStruct * SQL400AddDescJoin (pthread_t tid, SQLINTEGER flag);
/* void SQL400ExecuteCallback(SQL400ExecuteStruct* ); */
SQL400ExecuteStruct * SQL400ExecuteJoin (pthread_t tid, SQLINTEGER flag);
/* void SQL400FetchCallback(SQL400FetchStruct* ); */
SQL400FetchStruct * SQL400FetchJoin (pthread_t tid, SQLINTEGER flag);
/* void SQL400Stmt2HdbcCallback(SQL400Stmt2HdbcStruct* ); */
SQL400Stmt2HdbcStruct * SQL400Stmt2HdbcJoin (pthread_t tid, SQLINTEGER flag);


/* start an async call to DB2 CLI */
/* choose either callback or join */
/* for results returned.          */
/* sqlrc returned in structure.   */

pthread_t SQLOverrideCCSID400Async ( int  newCCSID, void * callback );
pthread_t SQLBindColAsync ( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fCType, SQLPOINTER  rgbValue, SQLINTEGER  cbValueMax, SQLINTEGER * pcbValue, void * callback );
pthread_t SQLBindFileToColAsync ( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLCHAR * fName, SQLSMALLINT * fNameLen, SQLINTEGER * fOptions, SQLSMALLINT  fValueMax, SQLINTEGER * sLen, SQLINTEGER * pcbValue, void * callback );
pthread_t SQLBindFileToParamAsync ( SQLHSTMT  hstmt, SQLSMALLINT  ipar, SQLSMALLINT  iType, SQLCHAR * fName, SQLSMALLINT * fNameLen, SQLINTEGER * fOptions, SQLSMALLINT  fValueMax, SQLINTEGER * pcbValue, void * callback );
pthread_t SQLBindParamAsync ( SQLHSTMT  hstmt, SQLSMALLINT  iparm, SQLSMALLINT  iType, SQLSMALLINT  pType, SQLINTEGER  pLen, SQLSMALLINT  pScale, SQLPOINTER  pData, SQLINTEGER * pcbValue, void * callback );
pthread_t SQLBindParameterAsync ( SQLHSTMT  hstmt, SQLSMALLINT  ipar, SQLSMALLINT  fParamType, SQLSMALLINT  fCType, SQLSMALLINT  fSQLType, SQLINTEGER  pLen, SQLSMALLINT  pScale, SQLPOINTER  pData, SQLINTEGER  cbValueMax, SQLINTEGER * pcbValue, void * callback );
pthread_t SQLCancelAsync ( SQLHSTMT  hstmt, void * callback );
pthread_t SQLCloseCursorAsync ( SQLHSTMT  hstmt, void * callback );
pthread_t SQLColAttributesAsync ( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fDescType, SQLCHAR * rgbDesc, SQLINTEGER  cbDescMax, SQLINTEGER * pcbDesc, SQLINTEGER * pfDesc, void * callback );
pthread_t SQLColumnPrivilegesAsync ( SQLHSTMT  hstmt, SQLCHAR * szCatalogName, SQLSMALLINT  cbCatalogName, SQLCHAR * szSchemaName, SQLSMALLINT  cbSchemaName, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLCHAR * szColumnName, SQLSMALLINT  cbColumnName, void * callback );
pthread_t SQLColumnsAsync ( SQLHSTMT  hstmt, SQLCHAR * szCatalogName, SQLSMALLINT  cbCatalogName, SQLCHAR * szSchemaName, SQLSMALLINT  cbSchemaName, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLCHAR * szColumnName, SQLSMALLINT  cbColumnName, void * callback );
pthread_t SQLConnectAsync ( SQLHDBC  hdbc, SQLCHAR * szDSN, SQLSMALLINT  cbDSN, SQLCHAR * szUID, SQLSMALLINT  cbUID, SQLCHAR * szAuthStr, SQLSMALLINT  cbAuthStr, void * callback );
pthread_t SQLCopyDescAsync ( SQLHDESC  sDesc, SQLHDESC  tDesc, void * callback );
pthread_t SQLDataSourcesAsync ( SQLHENV  henv, SQLSMALLINT  fDirection, SQLCHAR * szDSN, SQLSMALLINT  cbDSNMax, SQLSMALLINT * pcbDSN, SQLCHAR * szDescription, SQLSMALLINT  cbDescriptionMax, SQLSMALLINT * pcbDescription, void * callback );
pthread_t SQLDescribeColAsync ( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLCHAR * szColName, SQLSMALLINT  cbColNameMax, SQLSMALLINT * pcbColName, SQLSMALLINT * pfSqlType, SQLINTEGER * pcbColDef, SQLSMALLINT * pibScale, SQLSMALLINT * pfNullable, void * callback );
pthread_t SQLDescribeParamAsync ( SQLHSTMT  hstmt, SQLSMALLINT  ipar, SQLSMALLINT * pfSqlType, SQLINTEGER * pcbColDef, SQLSMALLINT * pibScale, SQLSMALLINT * pfNullable, void * callback );
pthread_t SQLDisconnectAsync ( SQLHDBC  hdbc, void * callback );
pthread_t SQLDriverConnectAsync ( SQLHDBC  hdbc, SQLPOINTER  hwnd, SQLCHAR * szConnStrIn, SQLSMALLINT  cbConnStrin, SQLCHAR * szConnStrOut, SQLSMALLINT  cbConnStrOutMax, SQLSMALLINT * pcbConnStrOut, SQLSMALLINT  fDriverCompletion, void * callback );
pthread_t SQLEndTranAsync ( SQLSMALLINT  htype, SQLHENV  henv, SQLSMALLINT  ctype, void * callback );
pthread_t SQLErrorAsync ( SQLHENV  henv, SQLHDBC  hdbc, SQLHSTMT  hstmt, SQLCHAR * szSqlState, SQLINTEGER * pfNativeError, SQLCHAR * szErrorMsg, SQLSMALLINT  cbErrorMsgMax, SQLSMALLINT * pcbErrorMsg, void * callback );
pthread_t SQLExecDirectAsync ( SQLHSTMT  hstmt, SQLCHAR * szSqlStr, SQLINTEGER  cbSqlStr, void * callback );
pthread_t SQLExecuteAsync ( SQLHSTMT  hstmt, void * callback );
pthread_t SQLExtendedFetchAsync ( SQLHSTMT  hstmt, SQLSMALLINT  fOrient, SQLINTEGER  fOffset, SQLINTEGER * pcrow, SQLSMALLINT * rgfRowStatus, void * callback );
pthread_t SQLFetchAsync ( SQLHSTMT  hstmt, void * callback );
pthread_t SQLFetchScrollAsync ( SQLHSTMT  hstmt, SQLSMALLINT  fOrient, SQLINTEGER  fOffset, void * callback );
pthread_t SQLForeignKeysAsync ( SQLHSTMT  hstmt, SQLCHAR * szPkTableQualifier, SQLSMALLINT  cbPkTableQualifier, SQLCHAR * szPkTableOwner, SQLSMALLINT  cbPkTableOwner, SQLCHAR * szPkTableName, SQLSMALLINT  cbPkTableName, SQLCHAR * szFkTableQualifier, SQLSMALLINT  cbFkTableQualifier, SQLCHAR * szFkTableOwner, SQLSMALLINT  cbFkTableOwner, SQLCHAR * szFkTableName, SQLSMALLINT  cbFkTableName, void * callback );
pthread_t SQLGetColAsync ( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  itype, SQLPOINTER  tval, SQLINTEGER  blen, SQLINTEGER * olen, void * callback );
pthread_t SQLGetConnectAttrAsync ( SQLHDBC  hdbc, SQLINTEGER  attr, SQLPOINTER  oval, SQLINTEGER  ilen, SQLINTEGER * olen, void * callback );
pthread_t SQLGetConnectOptionAsync ( SQLHDBC  hdbc, SQLSMALLINT  fOption, SQLPOINTER  pvParam, void * callback );
pthread_t SQLGetCursorNameAsync ( SQLHSTMT  hstmt, SQLCHAR * szCursor, SQLSMALLINT  cbCursorMax, SQLSMALLINT * pcbCursor, void * callback );
pthread_t SQLGetDataAsync ( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fCType, SQLPOINTER  rgbValue, SQLINTEGER  cbValueMax, SQLINTEGER * pcbValue, void * callback );
pthread_t SQLGetDescFieldAsync ( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  fieldID, SQLPOINTER  fValue, SQLINTEGER  fLength, SQLINTEGER * stLength, void * callback );
pthread_t SQLGetDescRecAsync ( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLCHAR * fname, SQLSMALLINT  bufLen, SQLSMALLINT * sLength, SQLSMALLINT * sType, SQLSMALLINT * sbType, SQLINTEGER * fLength, SQLSMALLINT * fprec, SQLSMALLINT * fscale, SQLSMALLINT * fnull, void * callback );
pthread_t SQLGetDiagFieldAsync ( SQLSMALLINT  hType, SQLINTEGER  hndl, SQLSMALLINT  rcdNum, SQLSMALLINT  diagID, SQLPOINTER  dValue, SQLSMALLINT  bLength, SQLSMALLINT * sLength, void * callback );
pthread_t SQLGetDiagRecAsync ( SQLSMALLINT  hType, SQLINTEGER  hndl, SQLSMALLINT  rcdNum, SQLCHAR * SQLstate, SQLINTEGER * SQLcode, SQLCHAR * msgText, SQLSMALLINT  bLength, SQLSMALLINT * sLength, void * callback );
pthread_t SQLGetEnvAttrAsync ( SQLHENV  henv, SQLINTEGER  Attribute, SQLPOINTER  Value, SQLINTEGER  BufferLength, SQLINTEGER * StringLength, void * callback );
pthread_t SQLGetFunctionsAsync ( SQLHDBC  hdbc, SQLSMALLINT  fFunction, SQLSMALLINT * pfExists, void * callback );
pthread_t SQLGetInfoAsync ( SQLHDBC  hdbc, SQLSMALLINT  fInfoType, SQLPOINTER  rgbInfoValue, SQLSMALLINT  cbInfoValueMax, SQLSMALLINT * pcbInfoValue, void * callback );
pthread_t SQLGetLengthAsync ( SQLHSTMT  hstmt, SQLSMALLINT  locType, SQLINTEGER  locator, SQLINTEGER * sLength, SQLINTEGER * ind, void * callback );
pthread_t SQLGetPositionAsync ( SQLHSTMT  hstmt, SQLSMALLINT  locType, SQLINTEGER  srceLocator, SQLINTEGER  srchLocator, SQLCHAR * srchLiteral, SQLINTEGER  srchLiteralLen, SQLINTEGER  fPosition, SQLINTEGER * located, SQLINTEGER * ind, void * callback );
pthread_t SQLGetStmtAttrAsync ( SQLHSTMT  hstmt, SQLINTEGER  fAttr, SQLPOINTER  pvParam, SQLINTEGER  bLength, SQLINTEGER * SLength, void * callback );
pthread_t SQLGetStmtOptionAsync ( SQLHSTMT  hstmt, SQLSMALLINT  fOption, SQLPOINTER  pvParam, void * callback );
pthread_t SQLGetSubStringAsync ( SQLHSTMT  hstmt, SQLSMALLINT  locType, SQLINTEGER  srceLocator, SQLINTEGER  fPosition, SQLINTEGER  length, SQLSMALLINT  tType, SQLPOINTER  rgbValue, SQLINTEGER  cbValueMax, SQLINTEGER * StringLength, SQLINTEGER * ind, void * callback );
pthread_t SQLGetTypeInfoAsync ( SQLHSTMT  hstmt, SQLSMALLINT  fSqlType, void * callback );
pthread_t SQLLanguagesAsync ( SQLHSTMT  hstmt, void * callback );
pthread_t SQLMoreResultsAsync ( SQLHSTMT  hstmt, void * callback );
pthread_t SQLNativeSqlAsync ( SQLHDBC  hdbc, SQLCHAR * szSqlStrIn, SQLINTEGER  cbSqlStrIn, SQLCHAR * szSqlStr, SQLINTEGER  cbSqlStrMax, SQLINTEGER * pcbSqlStr, void * callback );
pthread_t SQLNextResultAsync ( SQLHSTMT  hstmt, SQLHSTMT  hstmt2, void * callback );
pthread_t SQLNumParamsAsync ( SQLHSTMT  hstmt, SQLSMALLINT * pcpar, void * callback );
pthread_t SQLNumResultColsAsync ( SQLHSTMT  hstmt, SQLSMALLINT * pccol, void * callback );
pthread_t SQLParamDataAsync ( SQLHSTMT  hstmt, SQLPOINTER * prgbValue, void * callback );
pthread_t SQLParamOptionsAsync ( SQLHSTMT  hstmt, SQLINTEGER  crow, SQLINTEGER * pirow, void * callback );
pthread_t SQLPrepareAsync ( SQLHSTMT  hstmt, SQLCHAR * szSqlStr, SQLINTEGER  cbSqlStr, void * callback );
pthread_t SQLPrimaryKeysAsync ( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, void * callback );
pthread_t SQLProcedureColumnsAsync ( SQLHSTMT  hstmt, SQLCHAR * szProcQualifier, SQLSMALLINT  cbProcQualifier, SQLCHAR * szProcOwner, SQLSMALLINT  cbProcOwner, SQLCHAR * szProcName, SQLSMALLINT  cbProcName, SQLCHAR * szColumnName, SQLSMALLINT  cbColumnName, void * callback );
pthread_t SQLProceduresAsync ( SQLHSTMT  hstmt, SQLCHAR * szProcQualifier, SQLSMALLINT  cbProcQualifier, SQLCHAR * szProcOwner, SQLSMALLINT  cbProcOwner, SQLCHAR * szProcName, SQLSMALLINT  cbProcName, void * callback );
pthread_t SQLPutDataAsync ( SQLHSTMT  hstmt, SQLPOINTER  rgbValue, SQLINTEGER  cbValue, void * callback );
pthread_t SQLReleaseEnvAsync ( SQLHENV  henv, void * callback );
pthread_t SQLRowCountAsync ( SQLHSTMT  hstmt, SQLINTEGER * pcrow, void * callback );
pthread_t SQLSetConnectAttrAsync ( SQLHDBC  hdbc, SQLINTEGER  attrib, SQLPOINTER  vParam, SQLINTEGER  inlen, void * callback );
pthread_t SQLSetConnectOptionAsync ( SQLHDBC  hdbc, SQLSMALLINT  fOption, SQLPOINTER  vParam, void * callback );
pthread_t SQLSetCursorNameAsync ( SQLHSTMT  hstmt, SQLCHAR * szCursor, SQLSMALLINT  cbCursor, void * callback );
pthread_t SQLSetDescFieldAsync ( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  fID, SQLPOINTER  Value, SQLINTEGER  buffLen, void * callback );
pthread_t SQLSetDescRecAsync ( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  Type, SQLSMALLINT  subType, SQLINTEGER  fLength, SQLSMALLINT  fPrec, SQLSMALLINT  fScale, SQLPOINTER  Value, SQLINTEGER * sLength, SQLINTEGER * indic, void * callback );
pthread_t SQLSetEnvAttrAsync ( SQLHENV  henv, SQLINTEGER  Attribute, SQLPOINTER  Value, SQLINTEGER  StringLength, void * callback );
pthread_t SQLSetParamAsync ( SQLHSTMT  hstmt, SQLSMALLINT  ipar, SQLSMALLINT  fCType, SQLSMALLINT  fSqlType, SQLINTEGER  cbParamDef, SQLSMALLINT  ibScale, SQLPOINTER  rgbValue, SQLINTEGER * pcbValue, void * callback );
pthread_t SQLSetStmtAttrAsync ( SQLHSTMT  hstmt, SQLINTEGER  fAttr, SQLPOINTER  pParam, SQLINTEGER  vParam, void * callback );
pthread_t SQLSetStmtOptionAsync ( SQLHSTMT  hstmt, SQLSMALLINT  fOption, SQLPOINTER  vParam, void * callback );
pthread_t SQLSpecialColumnsAsync ( SQLHSTMT  hstmt, SQLSMALLINT  fColType, SQLCHAR * szCatalogName, SQLSMALLINT  cbCatalogName, SQLCHAR * szSchemaName, SQLSMALLINT  cbSchemaName, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLSMALLINT  fScope, SQLSMALLINT  fNullable, void * callback );
pthread_t SQLStartTranAsync ( SQLSMALLINT  htype, SQLHENV  henv, SQLINTEGER  mode, SQLINTEGER  clevel, void * callback );
pthread_t SQLStatisticsAsync ( SQLHSTMT  hstmt, SQLCHAR * szCatalogName, SQLSMALLINT  cbCatalogName, SQLCHAR * szSchemaName, SQLSMALLINT  cbSchemaName, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLSMALLINT  fUnique, SQLSMALLINT  fAccuracy, void * callback );
pthread_t SQLTablePrivilegesAsync ( SQLHSTMT  hstmt, SQLCHAR * szCatalogName, SQLSMALLINT  cbCatalogName, SQLCHAR * szSchemaName, SQLSMALLINT  cbSchemaName, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, void * callback );
pthread_t SQLTablesAsync ( SQLHSTMT  hstmt, SQLCHAR * szCatalogName, SQLSMALLINT  cbCatalogName, SQLCHAR * szSchemaName, SQLSMALLINT  cbSchemaName, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLCHAR * szTableType, SQLSMALLINT  cbTableType, void * callback );
pthread_t SQLTransactAsync ( SQLHENV  henv, SQLHDBC  hdbc, SQLSMALLINT  fType, void * callback );
pthread_t SQL400AddAttrAsync ( SQLINTEGER  scope, SQLINTEGER  attrib, SQLPOINTER  vParam, SQLINTEGER  inlen, SQLINTEGER  onerr, SQLINTEGER  flag, SQLPOINTER  options, void * callback );
pthread_t SQL400SetAttrAsync ( SQLINTEGER  scope, SQLHANDLE  hndl, SQLINTEGER  flag, SQLPOINTER  options, void * callback );
pthread_t SQL400EnvironmentAsync ( SQLINTEGER * ohnd, SQLPOINTER  options, void * callback );
pthread_t SQL400ConnectAsync ( SQLHENV  henv, SQLCHAR * db, SQLCHAR * uid, SQLCHAR * pwd, SQLINTEGER * ohnd, SQLPOINTER  options, void * callback );
pthread_t SQL400AddCVarAsync ( SQLSMALLINT  icol, SQLSMALLINT  inOutType, SQLSMALLINT  pfSqlCType, SQLPOINTER  pfSqlCValue, SQLINTEGER * indPtr, SQLPOINTER  parms, void * callback );
pthread_t SQL400AddDescAsync ( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  flag, SQLPOINTER  descs, void * callback );
pthread_t SQL400ExecuteAsync ( SQLHSTMT  hstmt, SQLPOINTER  parms, SQLPOINTER  desc_parms, void * callback );
pthread_t SQL400FetchAsync ( SQLHSTMT  hstmt, SQLINTEGER  start_row, SQLPOINTER  cols, SQLPOINTER  desc_cols, void * callback );
pthread_t SQL400Stmt2HdbcAsync ( SQLHSTMT  hstmt, SQLINTEGER * ohnd, void * callback );

#endif /* _PASECLIASYNC_H */
