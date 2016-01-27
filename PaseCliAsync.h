#ifndef _PASECLIASYNC_H
#define _PASECLIASYNC_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dlfcn.h>
#include <sqlcli1.h>
#include <as400_types.h>
#include <as400_protos.h>

/* special SQL400 aggregate functions */
/* do common work for language driver */
/* composite calls to CLI also async  */

#define SQL400_FLAG_JOIN_WAIT 0
#define SQL400_FLAG_JOIN_NO_WAIT 1

/* Use:
 * SQL400Environment
 * 
 * ok, unicode please ...
 * 
 * UTF8 normal interfaces (default 1208):
 *   int ccsid = 1208;
 *   env attr SQL400_ATTR_PASE_CCSID &ccsid -- set pase ccsid
 *   if ccsid == 1208:
 *     env attr SQL_ATTR_UTF8 &true -- no conversion required by PASE
 *   *NOTE: do not set PASE_CCSID or ATTR_UTF8 in UTF-16 mode (below). 
 * 
 * UTF16 wide interfaces:
 *   So, database exotic ebcdic column and PASE binds c type as WVARCHAR/WCHAR output is UTF16?
 *   Yes, the database will do the conversion from EBCDIC to UTF16 for data bound as WVARCHAR/WCHAR.
 *   not sure about DBCLOB -- I want to guess that is bound as UTF-16, not 100% sure.
 * 
 * IF your data not UTF-8 or UTF-16, use following interfaces to convert.
 *   SQL400ToUtf8    -- use before passing to CLI normal interfaces
 *   SQL400FromUtf8  -- use return output normal CLI (if needed)
 *   SQL400ToUtf16   -- use before passing to CLI wide interfaces
 *   SQL400FromUtf16 -- use return output wide CLI (if needed)
 * 
 */
#define SQL400_ATTR_PASE_CCSID 10011
#define SQL400_ATTR_CONN_JDBC 10201
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

SQLRETURN SQL400ToUtf8( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  inccsid );
SQLRETURN SQL400FromUtf8( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  outccsid );
SQLRETURN SQL400ToUtf16( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  inccsid );
SQLRETURN SQL400FromUtf16( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  outccsid );
SQLRETURN SQL400AddAttr( SQLINTEGER  scope, SQLINTEGER  attrib, SQLPOINTER  vParam, SQLINTEGER  inlen, SQLINTEGER  onerr, SQLINTEGER  flag, SQLPOINTER  options );
SQLRETURN SQL400SetAttr( SQLINTEGER  scope, SQLHANDLE  hndl, SQLINTEGER  flag, SQLPOINTER  options );
SQLRETURN SQL400Environment( SQLINTEGER * ohnd, SQLPOINTER  options );
SQLRETURN SQL400Connect( SQLHENV  henv, SQLCHAR * db, SQLCHAR * uid, SQLCHAR * pwd, SQLINTEGER * ohnd, SQLPOINTER  options );
SQLRETURN SQL400ConnectW( SQLHENV  henv, SQLWCHAR * db, SQLWCHAR * uid, SQLWCHAR * pwd, SQLINTEGER * ohnd, SQLPOINTER  options );
SQLRETURN SQL400AddCVar( SQLSMALLINT  icol, SQLSMALLINT  inOutType, SQLSMALLINT  pfSqlCType, SQLPOINTER  pfSqlCValue, SQLINTEGER * indPtr, SQLPOINTER  parms );
SQLRETURN SQL400AddDesc( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  flag, SQLPOINTER  descs );
SQLRETURN SQL400Execute( SQLHSTMT  hstmt, SQLPOINTER  parms, SQLPOINTER  desc_parms );
SQLRETURN SQL400Fetch( SQLHSTMT  hstmt, SQLINTEGER  start_row, SQLPOINTER  cols, SQLPOINTER  desc_cols );
SQLRETURN SQL400Stmt2Hdbc( SQLHSTMT  hstmt, SQLINTEGER * ohnd );

/* === sqlcli.h === 
 * SQLRETURN SQLAllocConnect( SQLHENV  henv, SQLHDBC * phdbc );
 * SQLRETURN SQLAllocEnv( SQLHENV * phenv );
 * SQLRETURN SQLAllocHandle( SQLSMALLINT  htype, SQLINTEGER  ihnd, SQLINTEGER * ohnd );
 * SQLRETURN SQLAllocStmt( SQLHDBC  hdbc, SQLHSTMT * phstmt );
 * SQLRETURN SQLBindCol( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  iType, SQLPOINTER  rgbValue, SQLINTEGER  cbValueMax, SQLINTEGER * pcbValue );
 * SQLRETURN SQLBindFileToCol( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLCHAR * fName, SQLSMALLINT * fNameLen, SQLINTEGER * fOptions, SQLSMALLINT  fValueMax, SQLINTEGER * sLen, SQLINTEGER * pcbValue );
 * SQLRETURN SQLBindFileToParam( SQLHSTMT  hstmt, SQLSMALLINT  ipar, SQLSMALLINT  iType, SQLCHAR * fName, SQLSMALLINT * fNameLen, SQLINTEGER * fOptions, SQLSMALLINT  fValueMax, SQLINTEGER * pcbValue );
 * SQLRETURN SQLBindParam( SQLHSTMT  hstmt, SQLSMALLINT  iparm, SQLSMALLINT  iType, SQLSMALLINT  pType, SQLINTEGER  pLen, SQLSMALLINT  pScale, SQLPOINTER  pData, SQLINTEGER * pcbValue );
 * SQLRETURN SQLBindParameter( SQLHSTMT  hstmt, SQLSMALLINT  ipar, SQLSMALLINT  fParamType, SQLSMALLINT  fCType, SQLSMALLINT  fSQLType, SQLINTEGER  pLen, SQLSMALLINT  pScale, SQLPOINTER  pData, SQLINTEGER  cbValueMax, SQLINTEGER * pcbValue );
 * SQLRETURN SQLCancel( SQLHSTMT  hstmt );
 * SQLRETURN SQLCloseCursor( SQLHSTMT  hstmt );
 * SQLRETURN SQLColAttribute( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fDescType, SQLPOINTER  rgbDesc, SQLSMALLINT  cbDescMax, SQLSMALLINT * pcbDesc, SQLPOINTER  pfDesc );
 * SQLRETURN SQLColAttributeW( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fDescType, SQLPOINTER  rgbDesc, SQLSMALLINT  cbDescMax, SQLSMALLINT * pcbDesc, SQLPOINTER  pfDesc );
 * SQLRETURN SQLColAttributes( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fDescType, SQLCHAR * rgbDesc, SQLINTEGER  cbDescMax, SQLINTEGER * pcbDesc, SQLINTEGER * pfDesc );
 * SQLRETURN SQLColAttributesW( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fDescType, SQLWCHAR * rgbDesc, SQLINTEGER  cbDescMax, SQLINTEGER * pcbDesc, SQLINTEGER * pfDesc );
 * SQLRETURN SQLColumnPrivileges( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLCHAR * szColumnName, SQLSMALLINT  cbColumnName );
 * SQLRETURN SQLColumnPrivilegesW( SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName, SQLWCHAR * szColumnName, SQLSMALLINT  cbColumnName );
 * SQLRETURN SQLColumns( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLCHAR * szColumnName, SQLSMALLINT  cbColumnName );
 * SQLRETURN SQLColumnsW( SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName, SQLWCHAR * szColumnName, SQLSMALLINT  cbColumnName );
 * SQLRETURN SQLConnect( SQLHDBC  hdbc, SQLCHAR * szDSN, SQLSMALLINT  cbDSN, SQLCHAR * szUID, SQLSMALLINT  cbUID, SQLCHAR * szAuthStr, SQLSMALLINT  cbAuthStr );
 * SQLRETURN SQLConnectW( SQLHDBC  hdbc, SQLWCHAR * szDSN, SQLSMALLINT  cbDSN, SQLWCHAR * szUID, SQLSMALLINT  cbUID, SQLWCHAR * szAuthStr, SQLSMALLINT  cbAuthStr );
 * SQLRETURN SQLCopyDesc( SQLHDESC  sDesc, SQLHDESC  tDesc );
 * SQLRETURN SQLDataSources( SQLHENV  henv, SQLSMALLINT  fDirection, SQLCHAR * szDSN, SQLSMALLINT  cbDSNMax, SQLSMALLINT * pcbDSN, SQLCHAR * szDescription, SQLSMALLINT  cbDescriptionMax, SQLSMALLINT * pcbDescription );
 * SQLRETURN SQLDataSourcesW( SQLHENV  henv, SQLSMALLINT  fDirection, SQLWCHAR * szDSN, SQLSMALLINT  cbDSNMax, SQLSMALLINT * pcbDSN, SQLWCHAR * szDescription, SQLSMALLINT  cbDescriptionMax, SQLSMALLINT * pcbDescription );
 * SQLRETURN SQLDescribeCol( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLCHAR * szColName, SQLSMALLINT  cbColNameMax, SQLSMALLINT * pcbColName, SQLSMALLINT * pfSqlType, SQLINTEGER * pcbColDef, SQLSMALLINT * pibScale, SQLSMALLINT * pfNullable );
 * SQLRETURN SQLDescribeColW( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLWCHAR * szColName, SQLSMALLINT  cbColNameMax, SQLSMALLINT * pcbColName, SQLSMALLINT * pfSqlType, SQLINTEGER * pcbColDef, SQLSMALLINT * pibScale, SQLSMALLINT * pfNullable );
 * SQLRETURN SQLDescribeParam( SQLHSTMT  hstmt, SQLSMALLINT  ipar, SQLSMALLINT * pfSqlType, SQLINTEGER * pcbColDef, SQLSMALLINT * pibScale, SQLSMALLINT * pfNullable );
 * SQLRETURN SQLDisconnect( SQLHDBC  hdbc );
 * SQLRETURN SQLDriverConnect( SQLHDBC  hdbc, SQLPOINTER  hwnd, SQLCHAR * szConnStrIn, SQLSMALLINT  cbConnStrin, SQLCHAR * szConnStrOut, SQLSMALLINT  cbConnStrOutMax, SQLSMALLINT * pcbConnStrOut, SQLSMALLINT  fDriverCompletion );
 * SQLRETURN SQLDriverConnectW( SQLHDBC  hdbc, SQLPOINTER  hwnd, SQLWCHAR * szConnStrIn, SQLSMALLINT  cbConnStrin, SQLWCHAR * szConnStrOut, SQLSMALLINT  cbConnStrOutMax, SQLSMALLINT * pcbConnStrOut, SQLSMALLINT  fDriverCompletion );
 * SQLRETURN SQLEndTran( SQLSMALLINT  htype, SQLHENV  henv, SQLSMALLINT  ctype );
 * SQLRETURN SQLError( SQLHENV  henv, SQLHDBC  hdbc, SQLHSTMT  hstmt, SQLCHAR * szSqlState, SQLINTEGER * pfNativeError, SQLCHAR * szErrorMsg, SQLSMALLINT  cbErrorMsgMax, SQLSMALLINT * pcbErrorMsg );
 * SQLRETURN SQLErrorW( SQLHENV  henv, SQLHDBC  hdbc, SQLHSTMT  hstmt, SQLWCHAR * szSqlState, SQLINTEGER * pfNativeError, SQLWCHAR * szErrorMsg, SQLSMALLINT  cbErrorMsgMax, SQLSMALLINT * pcbErrorMsg );
 * SQLRETURN SQLExecDirect( SQLHSTMT  hstmt, SQLCHAR * szSqlStr, SQLINTEGER  cbSqlStr );
 * SQLRETURN SQLExecDirectW( SQLHSTMT  hstmt, SQLWCHAR * szSqlStr, SQLINTEGER  cbSqlStr );
 * SQLRETURN SQLExecute( SQLHSTMT  hstmt );
 * SQLRETURN SQLExtendedFetch( SQLHSTMT  hstmt, SQLSMALLINT  fOrient, SQLINTEGER  fOffset, SQLINTEGER * pcrow, SQLSMALLINT * rgfRowStatus );
 * SQLRETURN SQLFetch( SQLHSTMT  hstmt );
 * SQLRETURN SQLFetchScroll( SQLHSTMT  hstmt, SQLSMALLINT  fOrient, SQLINTEGER  fOffset );
 * SQLRETURN SQLForeignKeys( SQLHSTMT  hstmt, SQLCHAR * szPkTableQualifier, SQLSMALLINT  cbPkTableQualifier, SQLCHAR * szPkTableOwner, SQLSMALLINT  cbPkTableOwner, SQLCHAR * szPkTableName, SQLSMALLINT  cbPkTableName, SQLCHAR * szFkTableQualifier, SQLSMALLINT  cbFkTableQualifier, SQLCHAR * szFkTableOwner, SQLSMALLINT  cbFkTableOwner, SQLCHAR * szFkTableName, SQLSMALLINT  cbFkTableName );
 * SQLRETURN SQLForeignKeysW( SQLHSTMT  hstmt, SQLWCHAR * szPkTableQualifier, SQLSMALLINT  cbPkTableQualifier, SQLWCHAR * szPkTableOwner, SQLSMALLINT  cbPkTableOwner, SQLWCHAR * szPkTableName, SQLSMALLINT  cbPkTableName, SQLWCHAR * szFkTableQualifier, SQLSMALLINT  cbFkTableQualifier, SQLWCHAR * szFkTableOwner, SQLSMALLINT  cbFkTableOwner, SQLWCHAR * szFkTableName, SQLSMALLINT  cbFkTableName );
 * SQLRETURN SQLFreeConnect( SQLHDBC  hdbc );
 * SQLRETURN SQLFreeEnv( SQLHENV  henv );
 * SQLRETURN SQLFreeStmt( SQLHSTMT  hstmt, SQLSMALLINT  fOption );
 * SQLRETURN SQLFreeHandle( SQLSMALLINT  htype, SQLINTEGER  hndl );
 * SQLRETURN SQLGetCol( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  itype, SQLPOINTER  tval, SQLINTEGER  blen, SQLINTEGER * olen );
 * SQLRETURN SQLGetColW( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  itype, SQLPOINTER  tval, SQLINTEGER  blen, SQLINTEGER * olen );
 * SQLRETURN SQLGetConnectAttr( SQLHDBC  hdbc, SQLINTEGER  attr, SQLPOINTER  oval, SQLINTEGER  ilen, SQLINTEGER * olen );
 * SQLRETURN SQLGetConnectAttrW( SQLHDBC  hdbc, SQLINTEGER  attr, SQLPOINTER  oval, SQLINTEGER  ilen, SQLINTEGER * olen );
 * SQLRETURN SQLGetConnectOption( SQLHDBC  hdbc, SQLSMALLINT  iopt, SQLPOINTER  oval );
 * SQLRETURN SQLGetConnectOptionW( SQLHDBC  hdbc, SQLSMALLINT  iopt, SQLPOINTER  oval );
 * SQLRETURN SQLGetCursorName( SQLHSTMT  hstmt, SQLCHAR * szCursor, SQLSMALLINT  cbCursorMax, SQLSMALLINT * pcbCursor );
 * SQLRETURN SQLGetCursorNameW( SQLHSTMT  hstmt, SQLWCHAR * szCursor, SQLSMALLINT  cbCursorMax, SQLSMALLINT * pcbCursor );
 * SQLRETURN SQLGetData( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fCType, SQLPOINTER  rgbValue, SQLINTEGER  cbValueMax, SQLINTEGER * pcbValue );
 * SQLRETURN SQLGetDescField( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  fieldID, SQLPOINTER  fValue, SQLINTEGER  fLength, SQLINTEGER * stLength );
 * SQLRETURN SQLGetDescFieldW( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  fieldID, SQLPOINTER  fValue, SQLINTEGER  fLength, SQLINTEGER * stLength );
 * SQLRETURN SQLGetDescRec( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLCHAR * fname, SQLSMALLINT  bufLen, SQLSMALLINT * sLength, SQLSMALLINT * sType, SQLSMALLINT * sbType, SQLINTEGER * fLength, SQLSMALLINT * fprec, SQLSMALLINT * fscale, SQLSMALLINT * fnull );
 * SQLRETURN SQLGetDescRecW( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLWCHAR * fname, SQLSMALLINT  bufLen, SQLSMALLINT * sLength, SQLSMALLINT * sType, SQLSMALLINT * sbType, SQLINTEGER * fLength, SQLSMALLINT * fprec, SQLSMALLINT * fscale, SQLSMALLINT * fnull );
 * SQLRETURN SQLGetDiagField( SQLSMALLINT  hType, SQLINTEGER  hndl, SQLSMALLINT  rcdNum, SQLSMALLINT  diagID, SQLPOINTER  dValue, SQLSMALLINT  bLength, SQLSMALLINT * sLength );
 * SQLRETURN SQLGetDiagFieldW( SQLSMALLINT  hType, SQLINTEGER  hndl, SQLSMALLINT  rcdNum, SQLSMALLINT  diagID, SQLPOINTER  dValue, SQLSMALLINT  bLength, SQLSMALLINT * sLength );
 * SQLRETURN SQLGetDiagRec( SQLSMALLINT  hType, SQLINTEGER  hndl, SQLSMALLINT  rcdNum, SQLCHAR * SQLstate, SQLINTEGER * SQLcode, SQLCHAR * msgText, SQLSMALLINT  bLength, SQLSMALLINT * SLength );
 * SQLRETURN SQLGetDiagRecW( SQLSMALLINT  hType, SQLINTEGER  hndl, SQLSMALLINT  rcdNum, SQLWCHAR * SQLstate, SQLINTEGER * SQLcode, SQLWCHAR * msgText, SQLSMALLINT  bLength, SQLSMALLINT * SLength );
 * SQLRETURN SQLGetEnvAttr( SQLHENV  hEnv, SQLINTEGER  fAttribute, SQLPOINTER  pParam, SQLINTEGER  cbParamMax, SQLINTEGER * pcbParam );
 * SQLRETURN SQLGetFunctions( SQLHDBC  hdbc, SQLSMALLINT  fFunction, SQLSMALLINT * pfExists );
 * SQLRETURN SQLGetInfo( SQLHDBC  hdbc, SQLSMALLINT  fInfoType, SQLPOINTER  rgbInfoValue, SQLSMALLINT  cbInfoValueMax, SQLSMALLINT * pcbInfoValue );
 * SQLRETURN SQLGetInfoW( SQLHDBC  hdbc, SQLSMALLINT  fInfoType, SQLPOINTER  rgbInfoValue, SQLSMALLINT  cbInfoValueMax, SQLSMALLINT * pcbInfoValue );
 * SQLRETURN SQLGetLength( SQLHSTMT  hstmt, SQLSMALLINT  locType, SQLINTEGER  locator, SQLINTEGER * sLength, SQLINTEGER * ind );
 * SQLRETURN SQLGetPosition( SQLHSTMT  hstmt, SQLSMALLINT  locType, SQLINTEGER  srceLocator, SQLINTEGER  srchLocator, SQLCHAR * srchLiteral, SQLINTEGER  srchLiteralLen, SQLINTEGER  fPosition, SQLINTEGER * located, SQLINTEGER * ind );
 * SQLRETURN SQLGetPositionW( SQLHSTMT  hstmt, SQLSMALLINT  locType, SQLINTEGER  srceLocator, SQLINTEGER  srchLocator, SQLWCHAR * srchLiteral, SQLINTEGER  srchLiteralLen, SQLINTEGER  fPosition, SQLINTEGER * located, SQLINTEGER * ind );
 * SQLRETURN SQLGetStmtAttr( SQLHSTMT  hstmt, SQLINTEGER  fAttr, SQLPOINTER  pvParam, SQLINTEGER  bLength, SQLINTEGER * SLength );
 * SQLRETURN SQLGetStmtAttrW( SQLHSTMT  hstmt, SQLINTEGER  fAttr, SQLPOINTER  pvParam, SQLINTEGER  bLength, SQLINTEGER * SLength );
 * SQLRETURN SQLGetStmtOption( SQLHSTMT  hstmt, SQLSMALLINT  fOption, SQLPOINTER  pvParam );
 * SQLRETURN SQLGetStmtOptionW( SQLHSTMT  hstmt, SQLSMALLINT  fOption, SQLPOINTER  pvParam );
 * SQLRETURN SQLGetSubString( SQLHSTMT  hstmt, SQLSMALLINT  locType, SQLINTEGER  srceLocator, SQLINTEGER  fPosition, SQLINTEGER  length, SQLSMALLINT  tType, SQLPOINTER  rgbValue, SQLINTEGER  cbValueMax, SQLINTEGER * StringLength, SQLINTEGER * ind );
 * SQLRETURN SQLGetSubStringW( SQLHSTMT  hstmt, SQLSMALLINT  locType, SQLINTEGER  srceLocator, SQLINTEGER  fPosition, SQLINTEGER  length, SQLSMALLINT  tType, SQLPOINTER  rgbValue, SQLINTEGER  cbValueMax, SQLINTEGER * StringLength, SQLINTEGER * ind );
 * SQLRETURN SQLGetTypeInfo( SQLHSTMT  hstmt, SQLSMALLINT  fSqlType );
 * SQLRETURN SQLGetTypeInfoW( SQLHSTMT  hstmt, SQLSMALLINT  fSqlType );
 * SQLRETURN SQLLanguages( SQLHSTMT  hstmt );
 * SQLRETURN SQLMoreResults( SQLHSTMT  hstmt );
 * SQLRETURN SQLNativeSql( SQLHDBC  hdbc, SQLCHAR * szSqlStrIn, SQLINTEGER  cbSqlStrIn, SQLCHAR * szSqlStr, SQLINTEGER  cbSqlStrMax, SQLINTEGER * pcbSqlStr );
 * SQLRETURN SQLNativeSqlW( SQLHDBC  hdbc, SQLWCHAR * szSqlStrIn, SQLINTEGER  cbSqlStrIn, SQLWCHAR * szSqlStr, SQLINTEGER  cbSqlStrMax, SQLINTEGER * pcbSqlStr );
 * SQLRETURN SQLNextResult( SQLHSTMT  hstmt, SQLHSTMT  hstmt2 );
 * SQLRETURN SQLNumParams( SQLHSTMT  hstmt, SQLSMALLINT * pcpar );
 * SQLRETURN SQLNumResultCols( SQLHSTMT  hstmt, SQLSMALLINT * pccol );
 * SQLRETURN SQLParamData( SQLHSTMT  hstmt, SQLPOINTER * Value );
 * SQLRETURN SQLParamOptions( SQLHSTMT  hstmt, SQLINTEGER  crow, SQLINTEGER * pirow );
 * SQLRETURN SQLPrepare( SQLHSTMT  hstmt, SQLCHAR * szSqlStr, SQLINTEGER  cbSqlStr );
 * SQLRETURN SQLPrepareW( SQLHSTMT  hstmt, SQLWCHAR * szSqlStr, SQLINTEGER  cbSqlStr );
 * SQLRETURN SQLPrimaryKeys( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName );
 * SQLRETURN SQLPrimaryKeysW( SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName );
 * SQLRETURN SQLProcedureColumns( SQLHSTMT  hstmt, SQLCHAR * szProcQualifier, SQLSMALLINT  cbProcQualifier, SQLCHAR * szProcOwner, SQLSMALLINT  cbProcOwner, SQLCHAR * szProcName, SQLSMALLINT  cbProcName, SQLCHAR * szColumnName, SQLSMALLINT  cbColumnName );
 * SQLRETURN SQLProcedureColumnsW( SQLHSTMT  hstmt, SQLWCHAR * szProcQualifier, SQLSMALLINT  cbProcQualifier, SQLWCHAR * szProcOwner, SQLSMALLINT  cbProcOwner, SQLWCHAR * szProcName, SQLSMALLINT  cbProcName, SQLWCHAR * szColumnName, SQLSMALLINT  cbColumnName );
 * SQLRETURN SQLProcedures( SQLHSTMT  hstmt, SQLCHAR * szProcQualifier, SQLSMALLINT  cbProcQualifier, SQLCHAR * szProcOwner, SQLSMALLINT  cbProcOwner, SQLCHAR * szProcName, SQLSMALLINT  cbProcName );
 * SQLRETURN SQLProceduresW( SQLHSTMT  hstmt, SQLWCHAR * szProcQualifier, SQLSMALLINT  cbProcQualifier, SQLWCHAR * szProcOwner, SQLSMALLINT  cbProcOwner, SQLWCHAR * szProcName, SQLSMALLINT  cbProcName );
 * SQLRETURN SQLPutData( SQLHSTMT  hstmt, SQLPOINTER  Data, SQLINTEGER  SLen );
 * SQLRETURN SQLReleaseEnv( SQLHENV  henv );
 * SQLRETURN SQLRowCount( SQLHSTMT  hstmt, SQLINTEGER * pcrow );
 * SQLRETURN SQLSetConnectAttr( SQLHDBC  hdbc, SQLINTEGER  attrib, SQLPOINTER  vParam, SQLINTEGER  inlen );
 * SQLRETURN SQLSetConnectAttrW( SQLHDBC  hdbc, SQLINTEGER  attrib, SQLPOINTER  vParam, SQLINTEGER  inlen );
 * SQLRETURN SQLSetConnectOption( SQLHDBC  hdbc, SQLSMALLINT  fOption, SQLPOINTER  vParam );
 * SQLRETURN SQLSetConnectOptionW( SQLHDBC  hdbc, SQLSMALLINT  fOption, SQLPOINTER  vParam );
 * SQLRETURN SQLSetCursorName( SQLHSTMT  hstmt, SQLCHAR * szCursor, SQLSMALLINT  cbCursor );
 * SQLRETURN SQLSetCursorNameW( SQLHSTMT  hstmt, SQLWCHAR * szCursor, SQLSMALLINT  cbCursor );
 * SQLRETURN SQLSetDescField( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  fID, SQLPOINTER  Value, SQLINTEGER  buffLen );
 * SQLRETURN SQLSetDescFieldW( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  fID, SQLPOINTER  Value, SQLINTEGER  buffLen );
 * SQLRETURN SQLSetDescRec( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  Type, SQLSMALLINT  subType, SQLINTEGER  fLength, SQLSMALLINT  fPrec, SQLSMALLINT  fScale, SQLPOINTER  Value, SQLINTEGER * sLength, SQLINTEGER * indic );
 * SQLRETURN SQLSetEnvAttr( SQLHENV  hEnv, SQLINTEGER  fAttribute, SQLPOINTER  pParam, SQLINTEGER  cbParam );
 * SQLRETURN SQLSetParam( SQLHSTMT  hstmt, SQLSMALLINT  ipar, SQLSMALLINT  fCType, SQLSMALLINT  fSqlType, SQLINTEGER  cbColDef, SQLSMALLINT  ibScale, SQLPOINTER  rgbValue, SQLINTEGER * pcbValue );
 * SQLRETURN SQLSetStmtAttr( SQLHSTMT  hstmt, SQLINTEGER  fAttr, SQLPOINTER  pParam, SQLINTEGER  vParam );
 * SQLRETURN SQLSetStmtAttrW( SQLHSTMT  hstmt, SQLINTEGER  fAttr, SQLPOINTER  pParam, SQLINTEGER  vParam );
 * SQLRETURN SQLSetStmtOption( SQLHSTMT  hstmt, SQLSMALLINT  fOption, SQLPOINTER  vParam );
 * SQLRETURN SQLSetStmtOptionW( SQLHSTMT  hstmt, SQLSMALLINT  fOption, SQLPOINTER  vParam );
 * SQLRETURN SQLSpecialColumns( SQLHSTMT  hstmt, SQLSMALLINT  fColType, SQLCHAR * szTableQual, SQLSMALLINT  cbTableQual, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLSMALLINT  fScope, SQLSMALLINT  fNullable );
 * SQLRETURN SQLSpecialColumnsW( SQLHSTMT  hstmt, SQLSMALLINT  fColType, SQLWCHAR * szTableQual, SQLSMALLINT  cbTableQual, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName, SQLSMALLINT  fScope, SQLSMALLINT  fNullable );
 * SQLRETURN SQLStartTran( SQLSMALLINT  htype, SQLHENV  henv, SQLINTEGER  mode, SQLINTEGER  clevel );
 * SQLRETURN SQLStatistics( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLSMALLINT  fUnique, SQLSMALLINT  fres );
 * SQLRETURN SQLStatisticsW( SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName, SQLSMALLINT  fUnique, SQLSMALLINT  fres );
 * SQLRETURN SQLTablePrivileges( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName );
 * SQLRETURN SQLTablePrivilegesW( SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName );
 * SQLRETURN SQLTables( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLCHAR * szTableType, SQLSMALLINT  cbTableType );
 * SQLRETURN SQLTablesW( SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName, SQLWCHAR * szTableType, SQLSMALLINT  cbTableType );
 * SQLRETURN SQLTransact( SQLHENV  henv, SQLHDBC  hdbc, SQLSMALLINT  fType );
 * === sqlcli.h === */

/* choose either callback or join    */
/* following structures returned     */
/* caller must free return structure */

typedef struct SQLBindColStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLSMALLINT  icol; SQLSMALLINT  iType; SQLPOINTER  rgbValue; SQLINTEGER  cbValueMax; SQLINTEGER * pcbValue; void * callback; } SQLBindColStruct;
typedef struct SQLBindFileToColStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLSMALLINT  icol; SQLCHAR * fName; SQLSMALLINT * fNameLen; SQLINTEGER * fOptions; SQLSMALLINT  fValueMax; SQLINTEGER * sLen; SQLINTEGER * pcbValue; void * callback; } SQLBindFileToColStruct;
typedef struct SQLBindFileToParamStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLSMALLINT  ipar; SQLSMALLINT  iType; SQLCHAR * fName; SQLSMALLINT * fNameLen; SQLINTEGER * fOptions; SQLSMALLINT  fValueMax; SQLINTEGER * pcbValue; void * callback; } SQLBindFileToParamStruct;
typedef struct SQLBindParamStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLSMALLINT  iparm; SQLSMALLINT  iType; SQLSMALLINT  pType; SQLINTEGER  pLen; SQLSMALLINT  pScale; SQLPOINTER  pData; SQLINTEGER * pcbValue; void * callback; } SQLBindParamStruct;
typedef struct SQLBindParameterStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLSMALLINT  ipar; SQLSMALLINT  fParamType; SQLSMALLINT  fCType; SQLSMALLINT  fSQLType; SQLINTEGER  pLen; SQLSMALLINT  pScale; SQLPOINTER  pData; SQLINTEGER  cbValueMax; SQLINTEGER * pcbValue; void * callback; } SQLBindParameterStruct;
typedef struct SQLCancelStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; void * callback; } SQLCancelStruct;
typedef struct SQLCloseCursorStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; void * callback; } SQLCloseCursorStruct;
typedef struct SQLColAttributeStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLSMALLINT  icol; SQLSMALLINT  fDescType; SQLPOINTER  rgbDesc; SQLSMALLINT  cbDescMax; SQLSMALLINT * pcbDesc; SQLPOINTER  pfDesc; void * callback; } SQLColAttributeStruct;
typedef struct SQLColAttributeWStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLSMALLINT  icol; SQLSMALLINT  fDescType; SQLPOINTER  rgbDesc; SQLSMALLINT  cbDescMax; SQLSMALLINT * pcbDesc; SQLPOINTER  pfDesc; void * callback; } SQLColAttributeWStruct;
typedef struct SQLColAttributesStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLSMALLINT  icol; SQLSMALLINT  fDescType; SQLCHAR * rgbDesc; SQLINTEGER  cbDescMax; SQLINTEGER * pcbDesc; SQLINTEGER * pfDesc; void * callback; } SQLColAttributesStruct;
typedef struct SQLColAttributesWStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLSMALLINT  icol; SQLSMALLINT  fDescType; SQLWCHAR * rgbDesc; SQLINTEGER  cbDescMax; SQLINTEGER * pcbDesc; SQLINTEGER * pfDesc; void * callback; } SQLColAttributesWStruct;
typedef struct SQLColumnPrivilegesStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLCHAR * szTableQualifier; SQLSMALLINT  cbTableQualifier; SQLCHAR * szTableOwner; SQLSMALLINT  cbTableOwner; SQLCHAR * szTableName; SQLSMALLINT  cbTableName; SQLCHAR * szColumnName; SQLSMALLINT  cbColumnName; void * callback; } SQLColumnPrivilegesStruct;
typedef struct SQLColumnPrivilegesWStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLWCHAR * szTableQualifier; SQLSMALLINT  cbTableQualifier; SQLWCHAR * szTableOwner; SQLSMALLINT  cbTableOwner; SQLWCHAR * szTableName; SQLSMALLINT  cbTableName; SQLWCHAR * szColumnName; SQLSMALLINT  cbColumnName; void * callback; } SQLColumnPrivilegesWStruct;
typedef struct SQLColumnsStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLCHAR * szTableQualifier; SQLSMALLINT  cbTableQualifier; SQLCHAR * szTableOwner; SQLSMALLINT  cbTableOwner; SQLCHAR * szTableName; SQLSMALLINT  cbTableName; SQLCHAR * szColumnName; SQLSMALLINT  cbColumnName; void * callback; } SQLColumnsStruct;
typedef struct SQLColumnsWStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLWCHAR * szTableQualifier; SQLSMALLINT  cbTableQualifier; SQLWCHAR * szTableOwner; SQLSMALLINT  cbTableOwner; SQLWCHAR * szTableName; SQLSMALLINT  cbTableName; SQLWCHAR * szColumnName; SQLSMALLINT  cbColumnName; void * callback; } SQLColumnsWStruct;
typedef struct SQLConnectStruct { SQLRETURN sqlrc; SQLHDBC  hdbc; SQLCHAR * szDSN; SQLSMALLINT  cbDSN; SQLCHAR * szUID; SQLSMALLINT  cbUID; SQLCHAR * szAuthStr; SQLSMALLINT  cbAuthStr; void * callback; } SQLConnectStruct;
typedef struct SQLConnectWStruct { SQLRETURN sqlrc; SQLHDBC  hdbc; SQLWCHAR * szDSN; SQLSMALLINT  cbDSN; SQLWCHAR * szUID; SQLSMALLINT  cbUID; SQLWCHAR * szAuthStr; SQLSMALLINT  cbAuthStr; void * callback; } SQLConnectWStruct;
typedef struct SQLCopyDescStruct { SQLRETURN sqlrc; SQLHDESC  sDesc; SQLHDESC  tDesc; void * callback; } SQLCopyDescStruct;
typedef struct SQLDataSourcesStruct { SQLRETURN sqlrc; SQLHENV  henv; SQLSMALLINT  fDirection; SQLCHAR * szDSN; SQLSMALLINT  cbDSNMax; SQLSMALLINT * pcbDSN; SQLCHAR * szDescription; SQLSMALLINT  cbDescriptionMax; SQLSMALLINT * pcbDescription; void * callback; } SQLDataSourcesStruct;
typedef struct SQLDataSourcesWStruct { SQLRETURN sqlrc; SQLHENV  henv; SQLSMALLINT  fDirection; SQLWCHAR * szDSN; SQLSMALLINT  cbDSNMax; SQLSMALLINT * pcbDSN; SQLWCHAR * szDescription; SQLSMALLINT  cbDescriptionMax; SQLSMALLINT * pcbDescription; void * callback; } SQLDataSourcesWStruct;
typedef struct SQLDescribeColStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLSMALLINT  icol; SQLCHAR * szColName; SQLSMALLINT  cbColNameMax; SQLSMALLINT * pcbColName; SQLSMALLINT * pfSqlType; SQLINTEGER * pcbColDef; SQLSMALLINT * pibScale; SQLSMALLINT * pfNullable; void * callback; } SQLDescribeColStruct;
typedef struct SQLDescribeColWStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLSMALLINT  icol; SQLWCHAR * szColName; SQLSMALLINT  cbColNameMax; SQLSMALLINT * pcbColName; SQLSMALLINT * pfSqlType; SQLINTEGER * pcbColDef; SQLSMALLINT * pibScale; SQLSMALLINT * pfNullable; void * callback; } SQLDescribeColWStruct;
typedef struct SQLDescribeParamStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLSMALLINT  ipar; SQLSMALLINT * pfSqlType; SQLINTEGER * pcbColDef; SQLSMALLINT * pibScale; SQLSMALLINT * pfNullable; void * callback; } SQLDescribeParamStruct;
typedef struct SQLDisconnectStruct { SQLRETURN sqlrc; SQLHDBC  hdbc; void * callback; } SQLDisconnectStruct;
typedef struct SQLDriverConnectStruct { SQLRETURN sqlrc; SQLHDBC  hdbc; SQLPOINTER  hwnd; SQLCHAR * szConnStrIn; SQLSMALLINT  cbConnStrin; SQLCHAR * szConnStrOut; SQLSMALLINT  cbConnStrOutMax; SQLSMALLINT * pcbConnStrOut; SQLSMALLINT  fDriverCompletion; void * callback; } SQLDriverConnectStruct;
typedef struct SQLDriverConnectWStruct { SQLRETURN sqlrc; SQLHDBC  hdbc; SQLPOINTER  hwnd; SQLWCHAR * szConnStrIn; SQLSMALLINT  cbConnStrin; SQLWCHAR * szConnStrOut; SQLSMALLINT  cbConnStrOutMax; SQLSMALLINT * pcbConnStrOut; SQLSMALLINT  fDriverCompletion; void * callback; } SQLDriverConnectWStruct;
typedef struct SQLEndTranStruct { SQLRETURN sqlrc; SQLSMALLINT  htype; SQLHENV  henv; SQLSMALLINT  ctype; void * callback; } SQLEndTranStruct;
typedef struct SQLErrorStruct { SQLRETURN sqlrc; SQLHENV  henv; SQLHDBC  hdbc; SQLHSTMT  hstmt; SQLCHAR * szSqlState; SQLINTEGER * pfNativeError; SQLCHAR * szErrorMsg; SQLSMALLINT  cbErrorMsgMax; SQLSMALLINT * pcbErrorMsg; void * callback; } SQLErrorStruct;
typedef struct SQLErrorWStruct { SQLRETURN sqlrc; SQLHENV  henv; SQLHDBC  hdbc; SQLHSTMT  hstmt; SQLWCHAR * szSqlState; SQLINTEGER * pfNativeError; SQLWCHAR * szErrorMsg; SQLSMALLINT  cbErrorMsgMax; SQLSMALLINT * pcbErrorMsg; void * callback; } SQLErrorWStruct;
typedef struct SQLExecDirectStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLCHAR * szSqlStr; SQLINTEGER  cbSqlStr; void * callback; } SQLExecDirectStruct;
typedef struct SQLExecDirectWStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLWCHAR * szSqlStr; SQLINTEGER  cbSqlStr; void * callback; } SQLExecDirectWStruct;
typedef struct SQLExecuteStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; void * callback; } SQLExecuteStruct;
typedef struct SQLExtendedFetchStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLSMALLINT  fOrient; SQLINTEGER  fOffset; SQLINTEGER * pcrow; SQLSMALLINT * rgfRowStatus; void * callback; } SQLExtendedFetchStruct;
typedef struct SQLFetchStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; void * callback; } SQLFetchStruct;
typedef struct SQLFetchScrollStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLSMALLINT  fOrient; SQLINTEGER  fOffset; void * callback; } SQLFetchScrollStruct;
typedef struct SQLForeignKeysStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLCHAR * szPkTableQualifier; SQLSMALLINT  cbPkTableQualifier; SQLCHAR * szPkTableOwner; SQLSMALLINT  cbPkTableOwner; SQLCHAR * szPkTableName; SQLSMALLINT  cbPkTableName; SQLCHAR * szFkTableQualifier; SQLSMALLINT  cbFkTableQualifier; SQLCHAR * szFkTableOwner; SQLSMALLINT  cbFkTableOwner; SQLCHAR * szFkTableName; SQLSMALLINT  cbFkTableName; void * callback; } SQLForeignKeysStruct;
typedef struct SQLForeignKeysWStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLWCHAR * szPkTableQualifier; SQLSMALLINT  cbPkTableQualifier; SQLWCHAR * szPkTableOwner; SQLSMALLINT  cbPkTableOwner; SQLWCHAR * szPkTableName; SQLSMALLINT  cbPkTableName; SQLWCHAR * szFkTableQualifier; SQLSMALLINT  cbFkTableQualifier; SQLWCHAR * szFkTableOwner; SQLSMALLINT  cbFkTableOwner; SQLWCHAR * szFkTableName; SQLSMALLINT  cbFkTableName; void * callback; } SQLForeignKeysWStruct;
typedef struct SQLGetColStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLSMALLINT  icol; SQLSMALLINT  itype; SQLPOINTER  tval; SQLINTEGER  blen; SQLINTEGER * olen; void * callback; } SQLGetColStruct;
typedef struct SQLGetColWStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLSMALLINT  icol; SQLSMALLINT  itype; SQLPOINTER  tval; SQLINTEGER  blen; SQLINTEGER * olen; void * callback; } SQLGetColWStruct;
typedef struct SQLGetConnectAttrStruct { SQLRETURN sqlrc; SQLHDBC  hdbc; SQLINTEGER  attr; SQLPOINTER  oval; SQLINTEGER  ilen; SQLINTEGER * olen; void * callback; } SQLGetConnectAttrStruct;
typedef struct SQLGetConnectAttrWStruct { SQLRETURN sqlrc; SQLHDBC  hdbc; SQLINTEGER  attr; SQLPOINTER  oval; SQLINTEGER  ilen; SQLINTEGER * olen; void * callback; } SQLGetConnectAttrWStruct;
typedef struct SQLGetConnectOptionStruct { SQLRETURN sqlrc; SQLHDBC  hdbc; SQLSMALLINT  iopt; SQLPOINTER  oval; void * callback; } SQLGetConnectOptionStruct;
typedef struct SQLGetConnectOptionWStruct { SQLRETURN sqlrc; SQLHDBC  hdbc; SQLSMALLINT  iopt; SQLPOINTER  oval; void * callback; } SQLGetConnectOptionWStruct;
typedef struct SQLGetCursorNameStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLCHAR * szCursor; SQLSMALLINT  cbCursorMax; SQLSMALLINT * pcbCursor; void * callback; } SQLGetCursorNameStruct;
typedef struct SQLGetCursorNameWStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLWCHAR * szCursor; SQLSMALLINT  cbCursorMax; SQLSMALLINT * pcbCursor; void * callback; } SQLGetCursorNameWStruct;
typedef struct SQLGetDataStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLSMALLINT  icol; SQLSMALLINT  fCType; SQLPOINTER  rgbValue; SQLINTEGER  cbValueMax; SQLINTEGER * pcbValue; void * callback; } SQLGetDataStruct;
typedef struct SQLGetDescFieldStruct { SQLRETURN sqlrc; SQLHDESC  hdesc; SQLSMALLINT  rcdNum; SQLSMALLINT  fieldID; SQLPOINTER  fValue; SQLINTEGER  fLength; SQLINTEGER * stLength; void * callback; } SQLGetDescFieldStruct;
typedef struct SQLGetDescFieldWStruct { SQLRETURN sqlrc; SQLHDESC  hdesc; SQLSMALLINT  rcdNum; SQLSMALLINT  fieldID; SQLPOINTER  fValue; SQLINTEGER  fLength; SQLINTEGER * stLength; void * callback; } SQLGetDescFieldWStruct;
typedef struct SQLGetDescRecStruct { SQLRETURN sqlrc; SQLHDESC  hdesc; SQLSMALLINT  rcdNum; SQLCHAR * fname; SQLSMALLINT  bufLen; SQLSMALLINT * sLength; SQLSMALLINT * sType; SQLSMALLINT * sbType; SQLINTEGER * fLength; SQLSMALLINT * fprec; SQLSMALLINT * fscale; SQLSMALLINT * fnull; void * callback; } SQLGetDescRecStruct;
typedef struct SQLGetDescRecWStruct { SQLRETURN sqlrc; SQLHDESC  hdesc; SQLSMALLINT  rcdNum; SQLWCHAR * fname; SQLSMALLINT  bufLen; SQLSMALLINT * sLength; SQLSMALLINT * sType; SQLSMALLINT * sbType; SQLINTEGER * fLength; SQLSMALLINT * fprec; SQLSMALLINT * fscale; SQLSMALLINT * fnull; void * callback; } SQLGetDescRecWStruct;
typedef struct SQLGetDiagFieldStruct { SQLRETURN sqlrc; SQLSMALLINT  hType; SQLINTEGER  hndl; SQLSMALLINT  rcdNum; SQLSMALLINT  diagID; SQLPOINTER  dValue; SQLSMALLINT  bLength; SQLSMALLINT * sLength; void * callback; } SQLGetDiagFieldStruct;
typedef struct SQLGetDiagFieldWStruct { SQLRETURN sqlrc; SQLSMALLINT  hType; SQLINTEGER  hndl; SQLSMALLINT  rcdNum; SQLSMALLINT  diagID; SQLPOINTER  dValue; SQLSMALLINT  bLength; SQLSMALLINT * sLength; void * callback; } SQLGetDiagFieldWStruct;
typedef struct SQLGetDiagRecStruct { SQLRETURN sqlrc; SQLSMALLINT  hType; SQLINTEGER  hndl; SQLSMALLINT  rcdNum; SQLCHAR * SQLstate; SQLINTEGER * SQLcode; SQLCHAR * msgText; SQLSMALLINT  bLength; SQLSMALLINT * SLength; void * callback; } SQLGetDiagRecStruct;
typedef struct SQLGetDiagRecWStruct { SQLRETURN sqlrc; SQLSMALLINT  hType; SQLINTEGER  hndl; SQLSMALLINT  rcdNum; SQLWCHAR * SQLstate; SQLINTEGER * SQLcode; SQLWCHAR * msgText; SQLSMALLINT  bLength; SQLSMALLINT * SLength; void * callback; } SQLGetDiagRecWStruct;
typedef struct SQLGetEnvAttrStruct { SQLRETURN sqlrc; SQLHENV  hEnv; SQLINTEGER  fAttribute; SQLPOINTER  pParam; SQLINTEGER  cbParamMax; SQLINTEGER * pcbParam; void * callback; } SQLGetEnvAttrStruct;
typedef struct SQLGetFunctionsStruct { SQLRETURN sqlrc; SQLHDBC  hdbc; SQLSMALLINT  fFunction; SQLSMALLINT * pfExists; void * callback; } SQLGetFunctionsStruct;
typedef struct SQLGetInfoStruct { SQLRETURN sqlrc; SQLHDBC  hdbc; SQLSMALLINT  fInfoType; SQLPOINTER  rgbInfoValue; SQLSMALLINT  cbInfoValueMax; SQLSMALLINT * pcbInfoValue; void * callback; } SQLGetInfoStruct;
typedef struct SQLGetInfoWStruct { SQLRETURN sqlrc; SQLHDBC  hdbc; SQLSMALLINT  fInfoType; SQLPOINTER  rgbInfoValue; SQLSMALLINT  cbInfoValueMax; SQLSMALLINT * pcbInfoValue; void * callback; } SQLGetInfoWStruct;
typedef struct SQLGetLengthStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLSMALLINT  locType; SQLINTEGER  locator; SQLINTEGER * sLength; SQLINTEGER * ind; void * callback; } SQLGetLengthStruct;
typedef struct SQLGetPositionStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLSMALLINT  locType; SQLINTEGER  srceLocator; SQLINTEGER  srchLocator; SQLCHAR * srchLiteral; SQLINTEGER  srchLiteralLen; SQLINTEGER  fPosition; SQLINTEGER * located; SQLINTEGER * ind; void * callback; } SQLGetPositionStruct;
typedef struct SQLGetPositionWStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLSMALLINT  locType; SQLINTEGER  srceLocator; SQLINTEGER  srchLocator; SQLWCHAR * srchLiteral; SQLINTEGER  srchLiteralLen; SQLINTEGER  fPosition; SQLINTEGER * located; SQLINTEGER * ind; void * callback; } SQLGetPositionWStruct;
typedef struct SQLGetStmtAttrStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLINTEGER  fAttr; SQLPOINTER  pvParam; SQLINTEGER  bLength; SQLINTEGER * SLength; void * callback; } SQLGetStmtAttrStruct;
typedef struct SQLGetStmtAttrWStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLINTEGER  fAttr; SQLPOINTER  pvParam; SQLINTEGER  bLength; SQLINTEGER * SLength; void * callback; } SQLGetStmtAttrWStruct;
typedef struct SQLGetStmtOptionStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLSMALLINT  fOption; SQLPOINTER  pvParam; void * callback; } SQLGetStmtOptionStruct;
typedef struct SQLGetStmtOptionWStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLSMALLINT  fOption; SQLPOINTER  pvParam; void * callback; } SQLGetStmtOptionWStruct;
typedef struct SQLGetSubStringStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLSMALLINT  locType; SQLINTEGER  srceLocator; SQLINTEGER  fPosition; SQLINTEGER  length; SQLSMALLINT  tType; SQLPOINTER  rgbValue; SQLINTEGER  cbValueMax; SQLINTEGER * StringLength; SQLINTEGER * ind; void * callback; } SQLGetSubStringStruct;
typedef struct SQLGetSubStringWStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLSMALLINT  locType; SQLINTEGER  srceLocator; SQLINTEGER  fPosition; SQLINTEGER  length; SQLSMALLINT  tType; SQLPOINTER  rgbValue; SQLINTEGER  cbValueMax; SQLINTEGER * StringLength; SQLINTEGER * ind; void * callback; } SQLGetSubStringWStruct;
typedef struct SQLGetTypeInfoStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLSMALLINT  fSqlType; void * callback; } SQLGetTypeInfoStruct;
typedef struct SQLGetTypeInfoWStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLSMALLINT  fSqlType; void * callback; } SQLGetTypeInfoWStruct;
typedef struct SQLLanguagesStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; void * callback; } SQLLanguagesStruct;
typedef struct SQLMoreResultsStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; void * callback; } SQLMoreResultsStruct;
typedef struct SQLNativeSqlStruct { SQLRETURN sqlrc; SQLHDBC  hdbc; SQLCHAR * szSqlStrIn; SQLINTEGER  cbSqlStrIn; SQLCHAR * szSqlStr; SQLINTEGER  cbSqlStrMax; SQLINTEGER * pcbSqlStr; void * callback; } SQLNativeSqlStruct;
typedef struct SQLNativeSqlWStruct { SQLRETURN sqlrc; SQLHDBC  hdbc; SQLWCHAR * szSqlStrIn; SQLINTEGER  cbSqlStrIn; SQLWCHAR * szSqlStr; SQLINTEGER  cbSqlStrMax; SQLINTEGER * pcbSqlStr; void * callback; } SQLNativeSqlWStruct;
typedef struct SQLNextResultStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLHSTMT  hstmt2; void * callback; } SQLNextResultStruct;
typedef struct SQLNumParamsStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLSMALLINT * pcpar; void * callback; } SQLNumParamsStruct;
typedef struct SQLNumResultColsStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLSMALLINT * pccol; void * callback; } SQLNumResultColsStruct;
typedef struct SQLParamDataStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLPOINTER * Value; void * callback; } SQLParamDataStruct;
typedef struct SQLParamOptionsStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLINTEGER  crow; SQLINTEGER * pirow; void * callback; } SQLParamOptionsStruct;
typedef struct SQLPrepareStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLCHAR * szSqlStr; SQLINTEGER  cbSqlStr; void * callback; } SQLPrepareStruct;
typedef struct SQLPrepareWStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLWCHAR * szSqlStr; SQLINTEGER  cbSqlStr; void * callback; } SQLPrepareWStruct;
typedef struct SQLPrimaryKeysStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLCHAR * szTableQualifier; SQLSMALLINT  cbTableQualifier; SQLCHAR * szTableOwner; SQLSMALLINT  cbTableOwner; SQLCHAR * szTableName; SQLSMALLINT  cbTableName; void * callback; } SQLPrimaryKeysStruct;
typedef struct SQLPrimaryKeysWStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLWCHAR * szTableQualifier; SQLSMALLINT  cbTableQualifier; SQLWCHAR * szTableOwner; SQLSMALLINT  cbTableOwner; SQLWCHAR * szTableName; SQLSMALLINT  cbTableName; void * callback; } SQLPrimaryKeysWStruct;
typedef struct SQLProcedureColumnsStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLCHAR * szProcQualifier; SQLSMALLINT  cbProcQualifier; SQLCHAR * szProcOwner; SQLSMALLINT  cbProcOwner; SQLCHAR * szProcName; SQLSMALLINT  cbProcName; SQLCHAR * szColumnName; SQLSMALLINT  cbColumnName; void * callback; } SQLProcedureColumnsStruct;
typedef struct SQLProcedureColumnsWStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLWCHAR * szProcQualifier; SQLSMALLINT  cbProcQualifier; SQLWCHAR * szProcOwner; SQLSMALLINT  cbProcOwner; SQLWCHAR * szProcName; SQLSMALLINT  cbProcName; SQLWCHAR * szColumnName; SQLSMALLINT  cbColumnName; void * callback; } SQLProcedureColumnsWStruct;
typedef struct SQLProceduresStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLCHAR * szProcQualifier; SQLSMALLINT  cbProcQualifier; SQLCHAR * szProcOwner; SQLSMALLINT  cbProcOwner; SQLCHAR * szProcName; SQLSMALLINT  cbProcName; void * callback; } SQLProceduresStruct;
typedef struct SQLProceduresWStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLWCHAR * szProcQualifier; SQLSMALLINT  cbProcQualifier; SQLWCHAR * szProcOwner; SQLSMALLINT  cbProcOwner; SQLWCHAR * szProcName; SQLSMALLINT  cbProcName; void * callback; } SQLProceduresWStruct;
typedef struct SQLPutDataStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLPOINTER  Data; SQLINTEGER  SLen; void * callback; } SQLPutDataStruct;
typedef struct SQLReleaseEnvStruct { SQLRETURN sqlrc; SQLHENV  henv; void * callback; } SQLReleaseEnvStruct;
typedef struct SQLRowCountStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLINTEGER * pcrow; void * callback; } SQLRowCountStruct;
typedef struct SQLSetConnectAttrStruct { SQLRETURN sqlrc; SQLHDBC  hdbc; SQLINTEGER  attrib; SQLPOINTER  vParam; SQLINTEGER  inlen; void * callback; } SQLSetConnectAttrStruct;
typedef struct SQLSetConnectAttrWStruct { SQLRETURN sqlrc; SQLHDBC  hdbc; SQLINTEGER  attrib; SQLPOINTER  vParam; SQLINTEGER  inlen; void * callback; } SQLSetConnectAttrWStruct;
typedef struct SQLSetConnectOptionStruct { SQLRETURN sqlrc; SQLHDBC  hdbc; SQLSMALLINT  fOption; SQLPOINTER  vParam; void * callback; } SQLSetConnectOptionStruct;
typedef struct SQLSetConnectOptionWStruct { SQLRETURN sqlrc; SQLHDBC  hdbc; SQLSMALLINT  fOption; SQLPOINTER  vParam; void * callback; } SQLSetConnectOptionWStruct;
typedef struct SQLSetCursorNameStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLCHAR * szCursor; SQLSMALLINT  cbCursor; void * callback; } SQLSetCursorNameStruct;
typedef struct SQLSetCursorNameWStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLWCHAR * szCursor; SQLSMALLINT  cbCursor; void * callback; } SQLSetCursorNameWStruct;
typedef struct SQLSetDescFieldStruct { SQLRETURN sqlrc; SQLHDESC  hdesc; SQLSMALLINT  rcdNum; SQLSMALLINT  fID; SQLPOINTER  Value; SQLINTEGER  buffLen; void * callback; } SQLSetDescFieldStruct;
typedef struct SQLSetDescFieldWStruct { SQLRETURN sqlrc; SQLHDESC  hdesc; SQLSMALLINT  rcdNum; SQLSMALLINT  fID; SQLPOINTER  Value; SQLINTEGER  buffLen; void * callback; } SQLSetDescFieldWStruct;
typedef struct SQLSetDescRecStruct { SQLRETURN sqlrc; SQLHDESC  hdesc; SQLSMALLINT  rcdNum; SQLSMALLINT  Type; SQLSMALLINT  subType; SQLINTEGER  fLength; SQLSMALLINT  fPrec; SQLSMALLINT  fScale; SQLPOINTER  Value; SQLINTEGER * sLength; SQLINTEGER * indic; void * callback; } SQLSetDescRecStruct;
typedef struct SQLSetEnvAttrStruct { SQLRETURN sqlrc; SQLHENV  hEnv; SQLINTEGER  fAttribute; SQLPOINTER  pParam; SQLINTEGER  cbParam; void * callback; } SQLSetEnvAttrStruct;
typedef struct SQLSetParamStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLSMALLINT  ipar; SQLSMALLINT  fCType; SQLSMALLINT  fSqlType; SQLINTEGER  cbColDef; SQLSMALLINT  ibScale; SQLPOINTER  rgbValue; SQLINTEGER * pcbValue; void * callback; } SQLSetParamStruct;
typedef struct SQLSetStmtAttrStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLINTEGER  fAttr; SQLPOINTER  pParam; SQLINTEGER  vParam; void * callback; } SQLSetStmtAttrStruct;
typedef struct SQLSetStmtAttrWStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLINTEGER  fAttr; SQLPOINTER  pParam; SQLINTEGER  vParam; void * callback; } SQLSetStmtAttrWStruct;
typedef struct SQLSetStmtOptionStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLSMALLINT  fOption; SQLPOINTER  vParam; void * callback; } SQLSetStmtOptionStruct;
typedef struct SQLSetStmtOptionWStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLSMALLINT  fOption; SQLPOINTER  vParam; void * callback; } SQLSetStmtOptionWStruct;
typedef struct SQLSpecialColumnsStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLSMALLINT  fColType; SQLCHAR * szTableQual; SQLSMALLINT  cbTableQual; SQLCHAR * szTableOwner; SQLSMALLINT  cbTableOwner; SQLCHAR * szTableName; SQLSMALLINT  cbTableName; SQLSMALLINT  fScope; SQLSMALLINT  fNullable; void * callback; } SQLSpecialColumnsStruct;
typedef struct SQLSpecialColumnsWStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLSMALLINT  fColType; SQLWCHAR * szTableQual; SQLSMALLINT  cbTableQual; SQLWCHAR * szTableOwner; SQLSMALLINT  cbTableOwner; SQLWCHAR * szTableName; SQLSMALLINT  cbTableName; SQLSMALLINT  fScope; SQLSMALLINT  fNullable; void * callback; } SQLSpecialColumnsWStruct;
typedef struct SQLStartTranStruct { SQLRETURN sqlrc; SQLSMALLINT  htype; SQLHENV  henv; SQLINTEGER  mode; SQLINTEGER  clevel; void * callback; } SQLStartTranStruct;
typedef struct SQLStatisticsStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLCHAR * szTableQualifier; SQLSMALLINT  cbTableQualifier; SQLCHAR * szTableOwner; SQLSMALLINT  cbTableOwner; SQLCHAR * szTableName; SQLSMALLINT  cbTableName; SQLSMALLINT  fUnique; SQLSMALLINT  fres; void * callback; } SQLStatisticsStruct;
typedef struct SQLStatisticsWStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLWCHAR * szTableQualifier; SQLSMALLINT  cbTableQualifier; SQLWCHAR * szTableOwner; SQLSMALLINT  cbTableOwner; SQLWCHAR * szTableName; SQLSMALLINT  cbTableName; SQLSMALLINT  fUnique; SQLSMALLINT  fres; void * callback; } SQLStatisticsWStruct;
typedef struct SQLTablePrivilegesStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLCHAR * szTableQualifier; SQLSMALLINT  cbTableQualifier; SQLCHAR * szTableOwner; SQLSMALLINT  cbTableOwner; SQLCHAR * szTableName; SQLSMALLINT  cbTableName; void * callback; } SQLTablePrivilegesStruct;
typedef struct SQLTablePrivilegesWStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLWCHAR * szTableQualifier; SQLSMALLINT  cbTableQualifier; SQLWCHAR * szTableOwner; SQLSMALLINT  cbTableOwner; SQLWCHAR * szTableName; SQLSMALLINT  cbTableName; void * callback; } SQLTablePrivilegesWStruct;
typedef struct SQLTablesStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLCHAR * szTableQualifier; SQLSMALLINT  cbTableQualifier; SQLCHAR * szTableOwner; SQLSMALLINT  cbTableOwner; SQLCHAR * szTableName; SQLSMALLINT  cbTableName; SQLCHAR * szTableType; SQLSMALLINT  cbTableType; void * callback; } SQLTablesStruct;
typedef struct SQLTablesWStruct { SQLRETURN sqlrc; SQLHSTMT  hstmt; SQLWCHAR * szTableQualifier; SQLSMALLINT  cbTableQualifier; SQLWCHAR * szTableOwner; SQLSMALLINT  cbTableOwner; SQLWCHAR * szTableName; SQLSMALLINT  cbTableName; SQLWCHAR * szTableType; SQLSMALLINT  cbTableType; void * callback; } SQLTablesWStruct;
typedef struct SQLTransactStruct { SQLRETURN sqlrc; SQLHENV  henv; SQLHDBC  hdbc; SQLSMALLINT  fType; void * callback; } SQLTransactStruct;
typedef struct SQL400ToUtf8Struct { SQLRETURN sqlrc; SQLHDBC  hdbc; SQLPOINTER  inparm; SQLINTEGER  inlen; SQLPOINTER  outparm; SQLINTEGER  outlen; SQLINTEGER  inccsid; void * callback; } SQL400ToUtf8Struct;
typedef struct SQL400FromUtf8Struct { SQLRETURN sqlrc; SQLHDBC  hdbc; SQLPOINTER  inparm; SQLINTEGER  inlen; SQLPOINTER  outparm; SQLINTEGER  outlen; SQLINTEGER  outccsid; void * callback; } SQL400FromUtf8Struct;
typedef struct SQL400ToUtf16Struct { SQLRETURN sqlrc; SQLHDBC  hdbc; SQLPOINTER  inparm; SQLINTEGER  inlen; SQLPOINTER  outparm; SQLINTEGER  outlen; SQLINTEGER  inccsid; void * callback; } SQL400ToUtf16Struct;
typedef struct SQL400FromUtf16Struct { SQLRETURN sqlrc; SQLHDBC  hdbc; SQLPOINTER  inparm; SQLINTEGER  inlen; SQLPOINTER  outparm; SQLINTEGER  outlen; SQLINTEGER  outccsid; void * callback; } SQL400FromUtf16Struct;
typedef struct SQL400AddAttrStruct { SQLRETURN sqlrc; SQLINTEGER  scope; SQLINTEGER  attrib; SQLPOINTER  vParam; SQLINTEGER  inlen; SQLINTEGER  onerr; SQLINTEGER  flag; SQLPOINTER  options; void * callback; } SQL400AddAttrStruct;
typedef struct SQL400SetAttrStruct { SQLRETURN sqlrc; SQLINTEGER  scope; SQLHANDLE  hndl; SQLINTEGER  flag; SQLPOINTER  options; void * callback; } SQL400SetAttrStruct;
typedef struct SQL400EnvironmentStruct { SQLRETURN sqlrc; SQLINTEGER * ohnd; SQLPOINTER  options; void * callback; } SQL400EnvironmentStruct;
typedef struct SQL400ConnectStruct { SQLRETURN sqlrc; SQLHENV  henv; SQLCHAR * db; SQLCHAR * uid; SQLCHAR * pwd; SQLINTEGER * ohnd; SQLPOINTER  options; void * callback; } SQL400ConnectStruct;
typedef struct SQL400ConnectWStruct { SQLRETURN sqlrc; SQLHENV  henv; SQLWCHAR * db; SQLWCHAR * uid; SQLWCHAR * pwd; SQLINTEGER * ohnd; SQLPOINTER  options; void * callback; } SQL400ConnectWStruct;
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
/* void SQLColAttributeCallback(SQLColAttributeStruct* ); */
SQLColAttributeStruct * SQLColAttributeJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLColAttributeWCallback(SQLColAttributeWStruct* ); */
SQLColAttributeWStruct * SQLColAttributeWJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLColAttributesCallback(SQLColAttributesStruct* ); */
SQLColAttributesStruct * SQLColAttributesJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLColAttributesWCallback(SQLColAttributesWStruct* ); */
SQLColAttributesWStruct * SQLColAttributesWJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLColumnPrivilegesCallback(SQLColumnPrivilegesStruct* ); */
SQLColumnPrivilegesStruct * SQLColumnPrivilegesJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLColumnPrivilegesWCallback(SQLColumnPrivilegesWStruct* ); */
SQLColumnPrivilegesWStruct * SQLColumnPrivilegesWJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLColumnsCallback(SQLColumnsStruct* ); */
SQLColumnsStruct * SQLColumnsJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLColumnsWCallback(SQLColumnsWStruct* ); */
SQLColumnsWStruct * SQLColumnsWJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLConnectCallback(SQLConnectStruct* ); */
SQLConnectStruct * SQLConnectJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLConnectWCallback(SQLConnectWStruct* ); */
SQLConnectWStruct * SQLConnectWJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLCopyDescCallback(SQLCopyDescStruct* ); */
SQLCopyDescStruct * SQLCopyDescJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLDataSourcesCallback(SQLDataSourcesStruct* ); */
SQLDataSourcesStruct * SQLDataSourcesJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLDataSourcesWCallback(SQLDataSourcesWStruct* ); */
SQLDataSourcesWStruct * SQLDataSourcesWJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLDescribeColCallback(SQLDescribeColStruct* ); */
SQLDescribeColStruct * SQLDescribeColJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLDescribeColWCallback(SQLDescribeColWStruct* ); */
SQLDescribeColWStruct * SQLDescribeColWJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLDescribeParamCallback(SQLDescribeParamStruct* ); */
SQLDescribeParamStruct * SQLDescribeParamJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLDisconnectCallback(SQLDisconnectStruct* ); */
SQLDisconnectStruct * SQLDisconnectJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLDriverConnectCallback(SQLDriverConnectStruct* ); */
SQLDriverConnectStruct * SQLDriverConnectJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLDriverConnectWCallback(SQLDriverConnectWStruct* ); */
SQLDriverConnectWStruct * SQLDriverConnectWJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLEndTranCallback(SQLEndTranStruct* ); */
SQLEndTranStruct * SQLEndTranJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLErrorCallback(SQLErrorStruct* ); */
SQLErrorStruct * SQLErrorJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLErrorWCallback(SQLErrorWStruct* ); */
SQLErrorWStruct * SQLErrorWJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLExecDirectCallback(SQLExecDirectStruct* ); */
SQLExecDirectStruct * SQLExecDirectJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLExecDirectWCallback(SQLExecDirectWStruct* ); */
SQLExecDirectWStruct * SQLExecDirectWJoin (pthread_t tid, SQLINTEGER flag);
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
/* void SQLForeignKeysWCallback(SQLForeignKeysWStruct* ); */
SQLForeignKeysWStruct * SQLForeignKeysWJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLGetColCallback(SQLGetColStruct* ); */
SQLGetColStruct * SQLGetColJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLGetColWCallback(SQLGetColWStruct* ); */
SQLGetColWStruct * SQLGetColWJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLGetConnectAttrCallback(SQLGetConnectAttrStruct* ); */
SQLGetConnectAttrStruct * SQLGetConnectAttrJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLGetConnectAttrWCallback(SQLGetConnectAttrWStruct* ); */
SQLGetConnectAttrWStruct * SQLGetConnectAttrWJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLGetConnectOptionCallback(SQLGetConnectOptionStruct* ); */
SQLGetConnectOptionStruct * SQLGetConnectOptionJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLGetConnectOptionWCallback(SQLGetConnectOptionWStruct* ); */
SQLGetConnectOptionWStruct * SQLGetConnectOptionWJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLGetCursorNameCallback(SQLGetCursorNameStruct* ); */
SQLGetCursorNameStruct * SQLGetCursorNameJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLGetCursorNameWCallback(SQLGetCursorNameWStruct* ); */
SQLGetCursorNameWStruct * SQLGetCursorNameWJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLGetDataCallback(SQLGetDataStruct* ); */
SQLGetDataStruct * SQLGetDataJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLGetDescFieldCallback(SQLGetDescFieldStruct* ); */
SQLGetDescFieldStruct * SQLGetDescFieldJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLGetDescFieldWCallback(SQLGetDescFieldWStruct* ); */
SQLGetDescFieldWStruct * SQLGetDescFieldWJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLGetDescRecCallback(SQLGetDescRecStruct* ); */
SQLGetDescRecStruct * SQLGetDescRecJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLGetDescRecWCallback(SQLGetDescRecWStruct* ); */
SQLGetDescRecWStruct * SQLGetDescRecWJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLGetDiagFieldCallback(SQLGetDiagFieldStruct* ); */
SQLGetDiagFieldStruct * SQLGetDiagFieldJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLGetDiagFieldWCallback(SQLGetDiagFieldWStruct* ); */
SQLGetDiagFieldWStruct * SQLGetDiagFieldWJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLGetDiagRecCallback(SQLGetDiagRecStruct* ); */
SQLGetDiagRecStruct * SQLGetDiagRecJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLGetDiagRecWCallback(SQLGetDiagRecWStruct* ); */
SQLGetDiagRecWStruct * SQLGetDiagRecWJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLGetEnvAttrCallback(SQLGetEnvAttrStruct* ); */
SQLGetEnvAttrStruct * SQLGetEnvAttrJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLGetFunctionsCallback(SQLGetFunctionsStruct* ); */
SQLGetFunctionsStruct * SQLGetFunctionsJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLGetInfoCallback(SQLGetInfoStruct* ); */
SQLGetInfoStruct * SQLGetInfoJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLGetInfoWCallback(SQLGetInfoWStruct* ); */
SQLGetInfoWStruct * SQLGetInfoWJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLGetLengthCallback(SQLGetLengthStruct* ); */
SQLGetLengthStruct * SQLGetLengthJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLGetPositionCallback(SQLGetPositionStruct* ); */
SQLGetPositionStruct * SQLGetPositionJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLGetPositionWCallback(SQLGetPositionWStruct* ); */
SQLGetPositionWStruct * SQLGetPositionWJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLGetStmtAttrCallback(SQLGetStmtAttrStruct* ); */
SQLGetStmtAttrStruct * SQLGetStmtAttrJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLGetStmtAttrWCallback(SQLGetStmtAttrWStruct* ); */
SQLGetStmtAttrWStruct * SQLGetStmtAttrWJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLGetStmtOptionCallback(SQLGetStmtOptionStruct* ); */
SQLGetStmtOptionStruct * SQLGetStmtOptionJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLGetStmtOptionWCallback(SQLGetStmtOptionWStruct* ); */
SQLGetStmtOptionWStruct * SQLGetStmtOptionWJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLGetSubStringCallback(SQLGetSubStringStruct* ); */
SQLGetSubStringStruct * SQLGetSubStringJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLGetSubStringWCallback(SQLGetSubStringWStruct* ); */
SQLGetSubStringWStruct * SQLGetSubStringWJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLGetTypeInfoCallback(SQLGetTypeInfoStruct* ); */
SQLGetTypeInfoStruct * SQLGetTypeInfoJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLGetTypeInfoWCallback(SQLGetTypeInfoWStruct* ); */
SQLGetTypeInfoWStruct * SQLGetTypeInfoWJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLLanguagesCallback(SQLLanguagesStruct* ); */
SQLLanguagesStruct * SQLLanguagesJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLMoreResultsCallback(SQLMoreResultsStruct* ); */
SQLMoreResultsStruct * SQLMoreResultsJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLNativeSqlCallback(SQLNativeSqlStruct* ); */
SQLNativeSqlStruct * SQLNativeSqlJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLNativeSqlWCallback(SQLNativeSqlWStruct* ); */
SQLNativeSqlWStruct * SQLNativeSqlWJoin (pthread_t tid, SQLINTEGER flag);
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
/* void SQLPrepareWCallback(SQLPrepareWStruct* ); */
SQLPrepareWStruct * SQLPrepareWJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLPrimaryKeysCallback(SQLPrimaryKeysStruct* ); */
SQLPrimaryKeysStruct * SQLPrimaryKeysJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLPrimaryKeysWCallback(SQLPrimaryKeysWStruct* ); */
SQLPrimaryKeysWStruct * SQLPrimaryKeysWJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLProcedureColumnsCallback(SQLProcedureColumnsStruct* ); */
SQLProcedureColumnsStruct * SQLProcedureColumnsJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLProcedureColumnsWCallback(SQLProcedureColumnsWStruct* ); */
SQLProcedureColumnsWStruct * SQLProcedureColumnsWJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLProceduresCallback(SQLProceduresStruct* ); */
SQLProceduresStruct * SQLProceduresJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLProceduresWCallback(SQLProceduresWStruct* ); */
SQLProceduresWStruct * SQLProceduresWJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLPutDataCallback(SQLPutDataStruct* ); */
SQLPutDataStruct * SQLPutDataJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLReleaseEnvCallback(SQLReleaseEnvStruct* ); */
SQLReleaseEnvStruct * SQLReleaseEnvJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLRowCountCallback(SQLRowCountStruct* ); */
SQLRowCountStruct * SQLRowCountJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLSetConnectAttrCallback(SQLSetConnectAttrStruct* ); */
SQLSetConnectAttrStruct * SQLSetConnectAttrJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLSetConnectAttrWCallback(SQLSetConnectAttrWStruct* ); */
SQLSetConnectAttrWStruct * SQLSetConnectAttrWJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLSetConnectOptionCallback(SQLSetConnectOptionStruct* ); */
SQLSetConnectOptionStruct * SQLSetConnectOptionJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLSetConnectOptionWCallback(SQLSetConnectOptionWStruct* ); */
SQLSetConnectOptionWStruct * SQLSetConnectOptionWJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLSetCursorNameCallback(SQLSetCursorNameStruct* ); */
SQLSetCursorNameStruct * SQLSetCursorNameJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLSetCursorNameWCallback(SQLSetCursorNameWStruct* ); */
SQLSetCursorNameWStruct * SQLSetCursorNameWJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLSetDescFieldCallback(SQLSetDescFieldStruct* ); */
SQLSetDescFieldStruct * SQLSetDescFieldJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLSetDescFieldWCallback(SQLSetDescFieldWStruct* ); */
SQLSetDescFieldWStruct * SQLSetDescFieldWJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLSetDescRecCallback(SQLSetDescRecStruct* ); */
SQLSetDescRecStruct * SQLSetDescRecJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLSetEnvAttrCallback(SQLSetEnvAttrStruct* ); */
SQLSetEnvAttrStruct * SQLSetEnvAttrJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLSetParamCallback(SQLSetParamStruct* ); */
SQLSetParamStruct * SQLSetParamJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLSetStmtAttrCallback(SQLSetStmtAttrStruct* ); */
SQLSetStmtAttrStruct * SQLSetStmtAttrJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLSetStmtAttrWCallback(SQLSetStmtAttrWStruct* ); */
SQLSetStmtAttrWStruct * SQLSetStmtAttrWJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLSetStmtOptionCallback(SQLSetStmtOptionStruct* ); */
SQLSetStmtOptionStruct * SQLSetStmtOptionJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLSetStmtOptionWCallback(SQLSetStmtOptionWStruct* ); */
SQLSetStmtOptionWStruct * SQLSetStmtOptionWJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLSpecialColumnsCallback(SQLSpecialColumnsStruct* ); */
SQLSpecialColumnsStruct * SQLSpecialColumnsJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLSpecialColumnsWCallback(SQLSpecialColumnsWStruct* ); */
SQLSpecialColumnsWStruct * SQLSpecialColumnsWJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLStartTranCallback(SQLStartTranStruct* ); */
SQLStartTranStruct * SQLStartTranJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLStatisticsCallback(SQLStatisticsStruct* ); */
SQLStatisticsStruct * SQLStatisticsJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLStatisticsWCallback(SQLStatisticsWStruct* ); */
SQLStatisticsWStruct * SQLStatisticsWJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLTablePrivilegesCallback(SQLTablePrivilegesStruct* ); */
SQLTablePrivilegesStruct * SQLTablePrivilegesJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLTablePrivilegesWCallback(SQLTablePrivilegesWStruct* ); */
SQLTablePrivilegesWStruct * SQLTablePrivilegesWJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLTablesCallback(SQLTablesStruct* ); */
SQLTablesStruct * SQLTablesJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLTablesWCallback(SQLTablesWStruct* ); */
SQLTablesWStruct * SQLTablesWJoin (pthread_t tid, SQLINTEGER flag);
/* void SQLTransactCallback(SQLTransactStruct* ); */
SQLTransactStruct * SQLTransactJoin (pthread_t tid, SQLINTEGER flag);
/* void SQL400ToUtf8Callback(SQL400ToUtf8Struct* ); */
SQL400ToUtf8Struct * SQL400ToUtf8Join (pthread_t tid, SQLINTEGER flag);
/* void SQL400FromUtf8Callback(SQL400FromUtf8Struct* ); */
SQL400FromUtf8Struct * SQL400FromUtf8Join (pthread_t tid, SQLINTEGER flag);
/* void SQL400ToUtf16Callback(SQL400ToUtf16Struct* ); */
SQL400ToUtf16Struct * SQL400ToUtf16Join (pthread_t tid, SQLINTEGER flag);
/* void SQL400FromUtf16Callback(SQL400FromUtf16Struct* ); */
SQL400FromUtf16Struct * SQL400FromUtf16Join (pthread_t tid, SQLINTEGER flag);
/* void SQL400AddAttrCallback(SQL400AddAttrStruct* ); */
SQL400AddAttrStruct * SQL400AddAttrJoin (pthread_t tid, SQLINTEGER flag);
/* void SQL400SetAttrCallback(SQL400SetAttrStruct* ); */
SQL400SetAttrStruct * SQL400SetAttrJoin (pthread_t tid, SQLINTEGER flag);
/* void SQL400EnvironmentCallback(SQL400EnvironmentStruct* ); */
SQL400EnvironmentStruct * SQL400EnvironmentJoin (pthread_t tid, SQLINTEGER flag);
/* void SQL400ConnectCallback(SQL400ConnectStruct* ); */
SQL400ConnectStruct * SQL400ConnectJoin (pthread_t tid, SQLINTEGER flag);
/* void SQL400ConnectWCallback(SQL400ConnectWStruct* ); */
SQL400ConnectWStruct * SQL400ConnectWJoin (pthread_t tid, SQLINTEGER flag);
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

pthread_t SQLBindColAsync ( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  iType, SQLPOINTER  rgbValue, SQLINTEGER  cbValueMax, SQLINTEGER * pcbValue, void * callback );
pthread_t SQLBindFileToColAsync ( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLCHAR * fName, SQLSMALLINT * fNameLen, SQLINTEGER * fOptions, SQLSMALLINT  fValueMax, SQLINTEGER * sLen, SQLINTEGER * pcbValue, void * callback );
pthread_t SQLBindFileToParamAsync ( SQLHSTMT  hstmt, SQLSMALLINT  ipar, SQLSMALLINT  iType, SQLCHAR * fName, SQLSMALLINT * fNameLen, SQLINTEGER * fOptions, SQLSMALLINT  fValueMax, SQLINTEGER * pcbValue, void * callback );
pthread_t SQLBindParamAsync ( SQLHSTMT  hstmt, SQLSMALLINT  iparm, SQLSMALLINT  iType, SQLSMALLINT  pType, SQLINTEGER  pLen, SQLSMALLINT  pScale, SQLPOINTER  pData, SQLINTEGER * pcbValue, void * callback );
pthread_t SQLBindParameterAsync ( SQLHSTMT  hstmt, SQLSMALLINT  ipar, SQLSMALLINT  fParamType, SQLSMALLINT  fCType, SQLSMALLINT  fSQLType, SQLINTEGER  pLen, SQLSMALLINT  pScale, SQLPOINTER  pData, SQLINTEGER  cbValueMax, SQLINTEGER * pcbValue, void * callback );
pthread_t SQLCancelAsync ( SQLHSTMT  hstmt, void * callback );
pthread_t SQLCloseCursorAsync ( SQLHSTMT  hstmt, void * callback );
pthread_t SQLColAttributeAsync ( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fDescType, SQLPOINTER  rgbDesc, SQLSMALLINT  cbDescMax, SQLSMALLINT * pcbDesc, SQLPOINTER  pfDesc, void * callback );
pthread_t SQLColAttributeWAsync ( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fDescType, SQLPOINTER  rgbDesc, SQLSMALLINT  cbDescMax, SQLSMALLINT * pcbDesc, SQLPOINTER  pfDesc, void * callback );
pthread_t SQLColAttributesAsync ( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fDescType, SQLCHAR * rgbDesc, SQLINTEGER  cbDescMax, SQLINTEGER * pcbDesc, SQLINTEGER * pfDesc, void * callback );
pthread_t SQLColAttributesWAsync ( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fDescType, SQLWCHAR * rgbDesc, SQLINTEGER  cbDescMax, SQLINTEGER * pcbDesc, SQLINTEGER * pfDesc, void * callback );
pthread_t SQLColumnPrivilegesAsync ( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLCHAR * szColumnName, SQLSMALLINT  cbColumnName, void * callback );
pthread_t SQLColumnPrivilegesWAsync ( SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName, SQLWCHAR * szColumnName, SQLSMALLINT  cbColumnName, void * callback );
pthread_t SQLColumnsAsync ( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLCHAR * szColumnName, SQLSMALLINT  cbColumnName, void * callback );
pthread_t SQLColumnsWAsync ( SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName, SQLWCHAR * szColumnName, SQLSMALLINT  cbColumnName, void * callback );
pthread_t SQLConnectAsync ( SQLHDBC  hdbc, SQLCHAR * szDSN, SQLSMALLINT  cbDSN, SQLCHAR * szUID, SQLSMALLINT  cbUID, SQLCHAR * szAuthStr, SQLSMALLINT  cbAuthStr, void * callback );
pthread_t SQLConnectWAsync ( SQLHDBC  hdbc, SQLWCHAR * szDSN, SQLSMALLINT  cbDSN, SQLWCHAR * szUID, SQLSMALLINT  cbUID, SQLWCHAR * szAuthStr, SQLSMALLINT  cbAuthStr, void * callback );
pthread_t SQLCopyDescAsync ( SQLHDESC  sDesc, SQLHDESC  tDesc, void * callback );
pthread_t SQLDataSourcesAsync ( SQLHENV  henv, SQLSMALLINT  fDirection, SQLCHAR * szDSN, SQLSMALLINT  cbDSNMax, SQLSMALLINT * pcbDSN, SQLCHAR * szDescription, SQLSMALLINT  cbDescriptionMax, SQLSMALLINT * pcbDescription, void * callback );
pthread_t SQLDataSourcesWAsync ( SQLHENV  henv, SQLSMALLINT  fDirection, SQLWCHAR * szDSN, SQLSMALLINT  cbDSNMax, SQLSMALLINT * pcbDSN, SQLWCHAR * szDescription, SQLSMALLINT  cbDescriptionMax, SQLSMALLINT * pcbDescription, void * callback );
pthread_t SQLDescribeColAsync ( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLCHAR * szColName, SQLSMALLINT  cbColNameMax, SQLSMALLINT * pcbColName, SQLSMALLINT * pfSqlType, SQLINTEGER * pcbColDef, SQLSMALLINT * pibScale, SQLSMALLINT * pfNullable, void * callback );
pthread_t SQLDescribeColWAsync ( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLWCHAR * szColName, SQLSMALLINT  cbColNameMax, SQLSMALLINT * pcbColName, SQLSMALLINT * pfSqlType, SQLINTEGER * pcbColDef, SQLSMALLINT * pibScale, SQLSMALLINT * pfNullable, void * callback );
pthread_t SQLDescribeParamAsync ( SQLHSTMT  hstmt, SQLSMALLINT  ipar, SQLSMALLINT * pfSqlType, SQLINTEGER * pcbColDef, SQLSMALLINT * pibScale, SQLSMALLINT * pfNullable, void * callback );
pthread_t SQLDisconnectAsync ( SQLHDBC  hdbc, void * callback );
pthread_t SQLDriverConnectAsync ( SQLHDBC  hdbc, SQLPOINTER  hwnd, SQLCHAR * szConnStrIn, SQLSMALLINT  cbConnStrin, SQLCHAR * szConnStrOut, SQLSMALLINT  cbConnStrOutMax, SQLSMALLINT * pcbConnStrOut, SQLSMALLINT  fDriverCompletion, void * callback );
pthread_t SQLDriverConnectWAsync ( SQLHDBC  hdbc, SQLPOINTER  hwnd, SQLWCHAR * szConnStrIn, SQLSMALLINT  cbConnStrin, SQLWCHAR * szConnStrOut, SQLSMALLINT  cbConnStrOutMax, SQLSMALLINT * pcbConnStrOut, SQLSMALLINT  fDriverCompletion, void * callback );
pthread_t SQLEndTranAsync ( SQLSMALLINT  htype, SQLHENV  henv, SQLSMALLINT  ctype, void * callback );
pthread_t SQLErrorAsync ( SQLHENV  henv, SQLHDBC  hdbc, SQLHSTMT  hstmt, SQLCHAR * szSqlState, SQLINTEGER * pfNativeError, SQLCHAR * szErrorMsg, SQLSMALLINT  cbErrorMsgMax, SQLSMALLINT * pcbErrorMsg, void * callback );
pthread_t SQLErrorWAsync ( SQLHENV  henv, SQLHDBC  hdbc, SQLHSTMT  hstmt, SQLWCHAR * szSqlState, SQLINTEGER * pfNativeError, SQLWCHAR * szErrorMsg, SQLSMALLINT  cbErrorMsgMax, SQLSMALLINT * pcbErrorMsg, void * callback );
pthread_t SQLExecDirectAsync ( SQLHSTMT  hstmt, SQLCHAR * szSqlStr, SQLINTEGER  cbSqlStr, void * callback );
pthread_t SQLExecDirectWAsync ( SQLHSTMT  hstmt, SQLWCHAR * szSqlStr, SQLINTEGER  cbSqlStr, void * callback );
pthread_t SQLExecuteAsync ( SQLHSTMT  hstmt, void * callback );
pthread_t SQLExtendedFetchAsync ( SQLHSTMT  hstmt, SQLSMALLINT  fOrient, SQLINTEGER  fOffset, SQLINTEGER * pcrow, SQLSMALLINT * rgfRowStatus, void * callback );
pthread_t SQLFetchAsync ( SQLHSTMT  hstmt, void * callback );
pthread_t SQLFetchScrollAsync ( SQLHSTMT  hstmt, SQLSMALLINT  fOrient, SQLINTEGER  fOffset, void * callback );
pthread_t SQLForeignKeysAsync ( SQLHSTMT  hstmt, SQLCHAR * szPkTableQualifier, SQLSMALLINT  cbPkTableQualifier, SQLCHAR * szPkTableOwner, SQLSMALLINT  cbPkTableOwner, SQLCHAR * szPkTableName, SQLSMALLINT  cbPkTableName, SQLCHAR * szFkTableQualifier, SQLSMALLINT  cbFkTableQualifier, SQLCHAR * szFkTableOwner, SQLSMALLINT  cbFkTableOwner, SQLCHAR * szFkTableName, SQLSMALLINT  cbFkTableName, void * callback );
pthread_t SQLForeignKeysWAsync ( SQLHSTMT  hstmt, SQLWCHAR * szPkTableQualifier, SQLSMALLINT  cbPkTableQualifier, SQLWCHAR * szPkTableOwner, SQLSMALLINT  cbPkTableOwner, SQLWCHAR * szPkTableName, SQLSMALLINT  cbPkTableName, SQLWCHAR * szFkTableQualifier, SQLSMALLINT  cbFkTableQualifier, SQLWCHAR * szFkTableOwner, SQLSMALLINT  cbFkTableOwner, SQLWCHAR * szFkTableName, SQLSMALLINT  cbFkTableName, void * callback );
pthread_t SQLGetColAsync ( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  itype, SQLPOINTER  tval, SQLINTEGER  blen, SQLINTEGER * olen, void * callback );
pthread_t SQLGetColWAsync ( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  itype, SQLPOINTER  tval, SQLINTEGER  blen, SQLINTEGER * olen, void * callback );
pthread_t SQLGetConnectAttrAsync ( SQLHDBC  hdbc, SQLINTEGER  attr, SQLPOINTER  oval, SQLINTEGER  ilen, SQLINTEGER * olen, void * callback );
pthread_t SQLGetConnectAttrWAsync ( SQLHDBC  hdbc, SQLINTEGER  attr, SQLPOINTER  oval, SQLINTEGER  ilen, SQLINTEGER * olen, void * callback );
pthread_t SQLGetConnectOptionAsync ( SQLHDBC  hdbc, SQLSMALLINT  iopt, SQLPOINTER  oval, void * callback );
pthread_t SQLGetConnectOptionWAsync ( SQLHDBC  hdbc, SQLSMALLINT  iopt, SQLPOINTER  oval, void * callback );
pthread_t SQLGetCursorNameAsync ( SQLHSTMT  hstmt, SQLCHAR * szCursor, SQLSMALLINT  cbCursorMax, SQLSMALLINT * pcbCursor, void * callback );
pthread_t SQLGetCursorNameWAsync ( SQLHSTMT  hstmt, SQLWCHAR * szCursor, SQLSMALLINT  cbCursorMax, SQLSMALLINT * pcbCursor, void * callback );
pthread_t SQLGetDataAsync ( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fCType, SQLPOINTER  rgbValue, SQLINTEGER  cbValueMax, SQLINTEGER * pcbValue, void * callback );
pthread_t SQLGetDescFieldAsync ( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  fieldID, SQLPOINTER  fValue, SQLINTEGER  fLength, SQLINTEGER * stLength, void * callback );
pthread_t SQLGetDescFieldWAsync ( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  fieldID, SQLPOINTER  fValue, SQLINTEGER  fLength, SQLINTEGER * stLength, void * callback );
pthread_t SQLGetDescRecAsync ( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLCHAR * fname, SQLSMALLINT  bufLen, SQLSMALLINT * sLength, SQLSMALLINT * sType, SQLSMALLINT * sbType, SQLINTEGER * fLength, SQLSMALLINT * fprec, SQLSMALLINT * fscale, SQLSMALLINT * fnull, void * callback );
pthread_t SQLGetDescRecWAsync ( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLWCHAR * fname, SQLSMALLINT  bufLen, SQLSMALLINT * sLength, SQLSMALLINT * sType, SQLSMALLINT * sbType, SQLINTEGER * fLength, SQLSMALLINT * fprec, SQLSMALLINT * fscale, SQLSMALLINT * fnull, void * callback );
pthread_t SQLGetDiagFieldAsync ( SQLSMALLINT  hType, SQLINTEGER  hndl, SQLSMALLINT  rcdNum, SQLSMALLINT  diagID, SQLPOINTER  dValue, SQLSMALLINT  bLength, SQLSMALLINT * sLength, void * callback );
pthread_t SQLGetDiagFieldWAsync ( SQLSMALLINT  hType, SQLINTEGER  hndl, SQLSMALLINT  rcdNum, SQLSMALLINT  diagID, SQLPOINTER  dValue, SQLSMALLINT  bLength, SQLSMALLINT * sLength, void * callback );
pthread_t SQLGetDiagRecAsync ( SQLSMALLINT  hType, SQLINTEGER  hndl, SQLSMALLINT  rcdNum, SQLCHAR * SQLstate, SQLINTEGER * SQLcode, SQLCHAR * msgText, SQLSMALLINT  bLength, SQLSMALLINT * SLength, void * callback );
pthread_t SQLGetDiagRecWAsync ( SQLSMALLINT  hType, SQLINTEGER  hndl, SQLSMALLINT  rcdNum, SQLWCHAR * SQLstate, SQLINTEGER * SQLcode, SQLWCHAR * msgText, SQLSMALLINT  bLength, SQLSMALLINT * SLength, void * callback );
pthread_t SQLGetEnvAttrAsync ( SQLHENV  hEnv, SQLINTEGER  fAttribute, SQLPOINTER  pParam, SQLINTEGER  cbParamMax, SQLINTEGER * pcbParam, void * callback );
pthread_t SQLGetFunctionsAsync ( SQLHDBC  hdbc, SQLSMALLINT  fFunction, SQLSMALLINT * pfExists, void * callback );
pthread_t SQLGetInfoAsync ( SQLHDBC  hdbc, SQLSMALLINT  fInfoType, SQLPOINTER  rgbInfoValue, SQLSMALLINT  cbInfoValueMax, SQLSMALLINT * pcbInfoValue, void * callback );
pthread_t SQLGetInfoWAsync ( SQLHDBC  hdbc, SQLSMALLINT  fInfoType, SQLPOINTER  rgbInfoValue, SQLSMALLINT  cbInfoValueMax, SQLSMALLINT * pcbInfoValue, void * callback );
pthread_t SQLGetLengthAsync ( SQLHSTMT  hstmt, SQLSMALLINT  locType, SQLINTEGER  locator, SQLINTEGER * sLength, SQLINTEGER * ind, void * callback );
pthread_t SQLGetPositionAsync ( SQLHSTMT  hstmt, SQLSMALLINT  locType, SQLINTEGER  srceLocator, SQLINTEGER  srchLocator, SQLCHAR * srchLiteral, SQLINTEGER  srchLiteralLen, SQLINTEGER  fPosition, SQLINTEGER * located, SQLINTEGER * ind, void * callback );
pthread_t SQLGetPositionWAsync ( SQLHSTMT  hstmt, SQLSMALLINT  locType, SQLINTEGER  srceLocator, SQLINTEGER  srchLocator, SQLWCHAR * srchLiteral, SQLINTEGER  srchLiteralLen, SQLINTEGER  fPosition, SQLINTEGER * located, SQLINTEGER * ind, void * callback );
pthread_t SQLGetStmtAttrAsync ( SQLHSTMT  hstmt, SQLINTEGER  fAttr, SQLPOINTER  pvParam, SQLINTEGER  bLength, SQLINTEGER * SLength, void * callback );
pthread_t SQLGetStmtAttrWAsync ( SQLHSTMT  hstmt, SQLINTEGER  fAttr, SQLPOINTER  pvParam, SQLINTEGER  bLength, SQLINTEGER * SLength, void * callback );
pthread_t SQLGetStmtOptionAsync ( SQLHSTMT  hstmt, SQLSMALLINT  fOption, SQLPOINTER  pvParam, void * callback );
pthread_t SQLGetStmtOptionWAsync ( SQLHSTMT  hstmt, SQLSMALLINT  fOption, SQLPOINTER  pvParam, void * callback );
pthread_t SQLGetSubStringAsync ( SQLHSTMT  hstmt, SQLSMALLINT  locType, SQLINTEGER  srceLocator, SQLINTEGER  fPosition, SQLINTEGER  length, SQLSMALLINT  tType, SQLPOINTER  rgbValue, SQLINTEGER  cbValueMax, SQLINTEGER * StringLength, SQLINTEGER * ind, void * callback );
pthread_t SQLGetSubStringWAsync ( SQLHSTMT  hstmt, SQLSMALLINT  locType, SQLINTEGER  srceLocator, SQLINTEGER  fPosition, SQLINTEGER  length, SQLSMALLINT  tType, SQLPOINTER  rgbValue, SQLINTEGER  cbValueMax, SQLINTEGER * StringLength, SQLINTEGER * ind, void * callback );
pthread_t SQLGetTypeInfoAsync ( SQLHSTMT  hstmt, SQLSMALLINT  fSqlType, void * callback );
pthread_t SQLGetTypeInfoWAsync ( SQLHSTMT  hstmt, SQLSMALLINT  fSqlType, void * callback );
pthread_t SQLLanguagesAsync ( SQLHSTMT  hstmt, void * callback );
pthread_t SQLMoreResultsAsync ( SQLHSTMT  hstmt, void * callback );
pthread_t SQLNativeSqlAsync ( SQLHDBC  hdbc, SQLCHAR * szSqlStrIn, SQLINTEGER  cbSqlStrIn, SQLCHAR * szSqlStr, SQLINTEGER  cbSqlStrMax, SQLINTEGER * pcbSqlStr, void * callback );
pthread_t SQLNativeSqlWAsync ( SQLHDBC  hdbc, SQLWCHAR * szSqlStrIn, SQLINTEGER  cbSqlStrIn, SQLWCHAR * szSqlStr, SQLINTEGER  cbSqlStrMax, SQLINTEGER * pcbSqlStr, void * callback );
pthread_t SQLNextResultAsync ( SQLHSTMT  hstmt, SQLHSTMT  hstmt2, void * callback );
pthread_t SQLNumParamsAsync ( SQLHSTMT  hstmt, SQLSMALLINT * pcpar, void * callback );
pthread_t SQLNumResultColsAsync ( SQLHSTMT  hstmt, SQLSMALLINT * pccol, void * callback );
pthread_t SQLParamDataAsync ( SQLHSTMT  hstmt, SQLPOINTER * Value, void * callback );
pthread_t SQLParamOptionsAsync ( SQLHSTMT  hstmt, SQLINTEGER  crow, SQLINTEGER * pirow, void * callback );
pthread_t SQLPrepareAsync ( SQLHSTMT  hstmt, SQLCHAR * szSqlStr, SQLINTEGER  cbSqlStr, void * callback );
pthread_t SQLPrepareWAsync ( SQLHSTMT  hstmt, SQLWCHAR * szSqlStr, SQLINTEGER  cbSqlStr, void * callback );
pthread_t SQLPrimaryKeysAsync ( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, void * callback );
pthread_t SQLPrimaryKeysWAsync ( SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName, void * callback );
pthread_t SQLProcedureColumnsAsync ( SQLHSTMT  hstmt, SQLCHAR * szProcQualifier, SQLSMALLINT  cbProcQualifier, SQLCHAR * szProcOwner, SQLSMALLINT  cbProcOwner, SQLCHAR * szProcName, SQLSMALLINT  cbProcName, SQLCHAR * szColumnName, SQLSMALLINT  cbColumnName, void * callback );
pthread_t SQLProcedureColumnsWAsync ( SQLHSTMT  hstmt, SQLWCHAR * szProcQualifier, SQLSMALLINT  cbProcQualifier, SQLWCHAR * szProcOwner, SQLSMALLINT  cbProcOwner, SQLWCHAR * szProcName, SQLSMALLINT  cbProcName, SQLWCHAR * szColumnName, SQLSMALLINT  cbColumnName, void * callback );
pthread_t SQLProceduresAsync ( SQLHSTMT  hstmt, SQLCHAR * szProcQualifier, SQLSMALLINT  cbProcQualifier, SQLCHAR * szProcOwner, SQLSMALLINT  cbProcOwner, SQLCHAR * szProcName, SQLSMALLINT  cbProcName, void * callback );
pthread_t SQLProceduresWAsync ( SQLHSTMT  hstmt, SQLWCHAR * szProcQualifier, SQLSMALLINT  cbProcQualifier, SQLWCHAR * szProcOwner, SQLSMALLINT  cbProcOwner, SQLWCHAR * szProcName, SQLSMALLINT  cbProcName, void * callback );
pthread_t SQLPutDataAsync ( SQLHSTMT  hstmt, SQLPOINTER  Data, SQLINTEGER  SLen, void * callback );
pthread_t SQLReleaseEnvAsync ( SQLHENV  henv, void * callback );
pthread_t SQLRowCountAsync ( SQLHSTMT  hstmt, SQLINTEGER * pcrow, void * callback );
pthread_t SQLSetConnectAttrAsync ( SQLHDBC  hdbc, SQLINTEGER  attrib, SQLPOINTER  vParam, SQLINTEGER  inlen, void * callback );
pthread_t SQLSetConnectAttrWAsync ( SQLHDBC  hdbc, SQLINTEGER  attrib, SQLPOINTER  vParam, SQLINTEGER  inlen, void * callback );
pthread_t SQLSetConnectOptionAsync ( SQLHDBC  hdbc, SQLSMALLINT  fOption, SQLPOINTER  vParam, void * callback );
pthread_t SQLSetConnectOptionWAsync ( SQLHDBC  hdbc, SQLSMALLINT  fOption, SQLPOINTER  vParam, void * callback );
pthread_t SQLSetCursorNameAsync ( SQLHSTMT  hstmt, SQLCHAR * szCursor, SQLSMALLINT  cbCursor, void * callback );
pthread_t SQLSetCursorNameWAsync ( SQLHSTMT  hstmt, SQLWCHAR * szCursor, SQLSMALLINT  cbCursor, void * callback );
pthread_t SQLSetDescFieldAsync ( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  fID, SQLPOINTER  Value, SQLINTEGER  buffLen, void * callback );
pthread_t SQLSetDescFieldWAsync ( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  fID, SQLPOINTER  Value, SQLINTEGER  buffLen, void * callback );
pthread_t SQLSetDescRecAsync ( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  Type, SQLSMALLINT  subType, SQLINTEGER  fLength, SQLSMALLINT  fPrec, SQLSMALLINT  fScale, SQLPOINTER  Value, SQLINTEGER * sLength, SQLINTEGER * indic, void * callback );
pthread_t SQLSetEnvAttrAsync ( SQLHENV  hEnv, SQLINTEGER  fAttribute, SQLPOINTER  pParam, SQLINTEGER  cbParam, void * callback );
pthread_t SQLSetParamAsync ( SQLHSTMT  hstmt, SQLSMALLINT  ipar, SQLSMALLINT  fCType, SQLSMALLINT  fSqlType, SQLINTEGER  cbColDef, SQLSMALLINT  ibScale, SQLPOINTER  rgbValue, SQLINTEGER * pcbValue, void * callback );
pthread_t SQLSetStmtAttrAsync ( SQLHSTMT  hstmt, SQLINTEGER  fAttr, SQLPOINTER  pParam, SQLINTEGER  vParam, void * callback );
pthread_t SQLSetStmtAttrWAsync ( SQLHSTMT  hstmt, SQLINTEGER  fAttr, SQLPOINTER  pParam, SQLINTEGER  vParam, void * callback );
pthread_t SQLSetStmtOptionAsync ( SQLHSTMT  hstmt, SQLSMALLINT  fOption, SQLPOINTER  vParam, void * callback );
pthread_t SQLSetStmtOptionWAsync ( SQLHSTMT  hstmt, SQLSMALLINT  fOption, SQLPOINTER  vParam, void * callback );
pthread_t SQLSpecialColumnsAsync ( SQLHSTMT  hstmt, SQLSMALLINT  fColType, SQLCHAR * szTableQual, SQLSMALLINT  cbTableQual, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLSMALLINT  fScope, SQLSMALLINT  fNullable, void * callback );
pthread_t SQLSpecialColumnsWAsync ( SQLHSTMT  hstmt, SQLSMALLINT  fColType, SQLWCHAR * szTableQual, SQLSMALLINT  cbTableQual, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName, SQLSMALLINT  fScope, SQLSMALLINT  fNullable, void * callback );
pthread_t SQLStartTranAsync ( SQLSMALLINT  htype, SQLHENV  henv, SQLINTEGER  mode, SQLINTEGER  clevel, void * callback );
pthread_t SQLStatisticsAsync ( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLSMALLINT  fUnique, SQLSMALLINT  fres, void * callback );
pthread_t SQLStatisticsWAsync ( SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName, SQLSMALLINT  fUnique, SQLSMALLINT  fres, void * callback );
pthread_t SQLTablePrivilegesAsync ( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, void * callback );
pthread_t SQLTablePrivilegesWAsync ( SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName, void * callback );
pthread_t SQLTablesAsync ( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLCHAR * szTableType, SQLSMALLINT  cbTableType, void * callback );
pthread_t SQLTablesWAsync ( SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName, SQLWCHAR * szTableType, SQLSMALLINT  cbTableType, void * callback );
pthread_t SQLTransactAsync ( SQLHENV  henv, SQLHDBC  hdbc, SQLSMALLINT  fType, void * callback );
pthread_t SQL400ToUtf8Async ( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  inccsid, void * callback );
pthread_t SQL400FromUtf8Async ( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  outccsid, void * callback );
pthread_t SQL400ToUtf16Async ( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  inccsid, void * callback );
pthread_t SQL400FromUtf16Async ( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  outccsid, void * callback );
pthread_t SQL400AddAttrAsync ( SQLINTEGER  scope, SQLINTEGER  attrib, SQLPOINTER  vParam, SQLINTEGER  inlen, SQLINTEGER  onerr, SQLINTEGER  flag, SQLPOINTER  options, void * callback );
pthread_t SQL400SetAttrAsync ( SQLINTEGER  scope, SQLHANDLE  hndl, SQLINTEGER  flag, SQLPOINTER  options, void * callback );
pthread_t SQL400EnvironmentAsync ( SQLINTEGER * ohnd, SQLPOINTER  options, void * callback );
pthread_t SQL400ConnectAsync ( SQLHENV  henv, SQLCHAR * db, SQLCHAR * uid, SQLCHAR * pwd, SQLINTEGER * ohnd, SQLPOINTER  options, void * callback );
pthread_t SQL400ConnectWAsync ( SQLHENV  henv, SQLWCHAR * db, SQLWCHAR * uid, SQLWCHAR * pwd, SQLINTEGER * ohnd, SQLPOINTER  options, void * callback );
pthread_t SQL400AddCVarAsync ( SQLSMALLINT  icol, SQLSMALLINT  inOutType, SQLSMALLINT  pfSqlCType, SQLPOINTER  pfSqlCValue, SQLINTEGER * indPtr, SQLPOINTER  parms, void * callback );
pthread_t SQL400AddDescAsync ( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  flag, SQLPOINTER  descs, void * callback );
pthread_t SQL400ExecuteAsync ( SQLHSTMT  hstmt, SQLPOINTER  parms, SQLPOINTER  desc_parms, void * callback );
pthread_t SQL400FetchAsync ( SQLHSTMT  hstmt, SQLINTEGER  start_row, SQLPOINTER  cols, SQLPOINTER  desc_cols, void * callback );
pthread_t SQL400Stmt2HdbcAsync ( SQLHSTMT  hstmt, SQLINTEGER * ohnd, void * callback );

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

/* === internal use ======            */

extern SQLRETURN (*libdb400_SQLAllocConnect)( SQLHENV, SQLHDBC* );
extern SQLRETURN (*libdb400_SQLAllocEnv)( SQLHENV* );
extern SQLRETURN (*libdb400_SQLAllocHandle)( SQLSMALLINT, SQLINTEGER, SQLINTEGER* );
extern SQLRETURN (*libdb400_SQLAllocStmt)( SQLHDBC, SQLHSTMT* );
extern SQLRETURN (*libdb400_SQLBindCol)( SQLHSTMT, SQLSMALLINT, SQLSMALLINT, SQLPOINTER, SQLINTEGER, SQLINTEGER* );
extern SQLRETURN (*libdb400_SQLBindFileToCol)( SQLHSTMT, SQLSMALLINT, SQLCHAR*, SQLSMALLINT*, SQLINTEGER*, SQLSMALLINT, SQLINTEGER*, SQLINTEGER* );
extern SQLRETURN (*libdb400_SQLBindFileToParam)( SQLHSTMT, SQLSMALLINT, SQLSMALLINT, SQLCHAR*, SQLSMALLINT*, SQLINTEGER*, SQLSMALLINT, SQLINTEGER* );
extern SQLRETURN (*libdb400_SQLBindParam)( SQLHSTMT, SQLSMALLINT, SQLSMALLINT, SQLSMALLINT, SQLINTEGER, SQLSMALLINT, SQLPOINTER, SQLINTEGER* );
extern SQLRETURN (*libdb400_SQLBindParameter)( SQLHSTMT, SQLSMALLINT, SQLSMALLINT, SQLSMALLINT, SQLSMALLINT, SQLINTEGER, SQLSMALLINT, SQLPOINTER, SQLINTEGER, SQLINTEGER* );
extern SQLRETURN (*libdb400_SQLCancel)( SQLHSTMT );
extern SQLRETURN (*libdb400_SQLCloseCursor)( SQLHSTMT );
extern SQLRETURN (*libdb400_SQLColAttribute)( SQLHSTMT, SQLSMALLINT, SQLSMALLINT, SQLPOINTER, SQLSMALLINT, SQLSMALLINT*, SQLPOINTER );
extern SQLRETURN (*libdb400_SQLColAttributeW)( SQLHSTMT, SQLSMALLINT, SQLSMALLINT, SQLPOINTER, SQLSMALLINT, SQLSMALLINT*, SQLPOINTER );
extern SQLRETURN (*libdb400_SQLColAttributes)( SQLHSTMT, SQLSMALLINT, SQLSMALLINT, SQLCHAR*, SQLINTEGER, SQLINTEGER*, SQLINTEGER* );
extern SQLRETURN (*libdb400_SQLColAttributesW)( SQLHSTMT, SQLSMALLINT, SQLSMALLINT, SQLWCHAR*, SQLINTEGER, SQLINTEGER*, SQLINTEGER* );
extern SQLRETURN (*libdb400_SQLColumnPrivileges)( SQLHSTMT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT );
extern SQLRETURN (*libdb400_SQLColumnPrivilegesW)( SQLHSTMT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT );
extern SQLRETURN (*libdb400_SQLColumns)( SQLHSTMT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT );
extern SQLRETURN (*libdb400_SQLColumnsW)( SQLHSTMT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT );
extern SQLRETURN (*libdb400_SQLConnect)( SQLHDBC, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT );
extern SQLRETURN (*libdb400_SQLConnectW)( SQLHDBC, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT );
extern SQLRETURN (*libdb400_SQLCopyDesc)( SQLHDESC, SQLHDESC );
extern SQLRETURN (*libdb400_SQLDataSources)( SQLHENV, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLSMALLINT*, SQLCHAR*, SQLSMALLINT, SQLSMALLINT* );
extern SQLRETURN (*libdb400_SQLDataSourcesW)( SQLHENV, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLSMALLINT*, SQLWCHAR*, SQLSMALLINT, SQLSMALLINT* );
extern SQLRETURN (*libdb400_SQLDescribeCol)( SQLHSTMT, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLSMALLINT*, SQLSMALLINT*, SQLINTEGER*, SQLSMALLINT*, SQLSMALLINT* );
extern SQLRETURN (*libdb400_SQLDescribeColW)( SQLHSTMT, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLSMALLINT*, SQLSMALLINT*, SQLINTEGER*, SQLSMALLINT*, SQLSMALLINT* );
extern SQLRETURN (*libdb400_SQLDescribeParam)( SQLHSTMT, SQLSMALLINT, SQLSMALLINT*, SQLINTEGER*, SQLSMALLINT*, SQLSMALLINT* );
extern SQLRETURN (*libdb400_SQLDisconnect)( SQLHDBC );
extern SQLRETURN (*libdb400_SQLDriverConnect)( SQLHDBC, SQLPOINTER, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLSMALLINT*, SQLSMALLINT );
extern SQLRETURN (*libdb400_SQLDriverConnectW)( SQLHDBC, SQLPOINTER, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLSMALLINT*, SQLSMALLINT );
extern SQLRETURN (*libdb400_SQLEndTran)( SQLSMALLINT, SQLHENV, SQLSMALLINT );
extern SQLRETURN (*libdb400_SQLError)( SQLHENV, SQLHDBC, SQLHSTMT, SQLCHAR*, SQLINTEGER*, SQLCHAR*, SQLSMALLINT, SQLSMALLINT* );
extern SQLRETURN (*libdb400_SQLErrorW)( SQLHENV, SQLHDBC, SQLHSTMT, SQLWCHAR*, SQLINTEGER*, SQLWCHAR*, SQLSMALLINT, SQLSMALLINT* );
extern SQLRETURN (*libdb400_SQLExecDirect)( SQLHSTMT, SQLCHAR*, SQLINTEGER );
extern SQLRETURN (*libdb400_SQLExecDirectW)( SQLHSTMT, SQLWCHAR*, SQLINTEGER );
extern SQLRETURN (*libdb400_SQLExecute)( SQLHSTMT );
extern SQLRETURN (*libdb400_SQLExtendedFetch)( SQLHSTMT, SQLSMALLINT, SQLINTEGER, SQLINTEGER*, SQLSMALLINT* );
extern SQLRETURN (*libdb400_SQLFetch)( SQLHSTMT );
extern SQLRETURN (*libdb400_SQLFetchScroll)( SQLHSTMT, SQLSMALLINT, SQLINTEGER );
extern SQLRETURN (*libdb400_SQLForeignKeys)( SQLHSTMT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT );
extern SQLRETURN (*libdb400_SQLForeignKeysW)( SQLHSTMT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT );
extern SQLRETURN (*libdb400_SQLFreeConnect)( SQLHDBC );
extern SQLRETURN (*libdb400_SQLFreeEnv)( SQLHENV );
extern SQLRETURN (*libdb400_SQLFreeStmt)( SQLHSTMT, SQLSMALLINT );
extern SQLRETURN (*libdb400_SQLFreeHandle)( SQLSMALLINT, SQLINTEGER );
extern SQLRETURN (*libdb400_SQLGetCol)( SQLHSTMT, SQLSMALLINT, SQLSMALLINT, SQLPOINTER, SQLINTEGER, SQLINTEGER* );
extern SQLRETURN (*libdb400_SQLGetColW)( SQLHSTMT, SQLSMALLINT, SQLSMALLINT, SQLPOINTER, SQLINTEGER, SQLINTEGER* );
extern SQLRETURN (*libdb400_SQLGetConnectAttr)( SQLHDBC, SQLINTEGER, SQLPOINTER, SQLINTEGER, SQLINTEGER* );
extern SQLRETURN (*libdb400_SQLGetConnectAttrW)( SQLHDBC, SQLINTEGER, SQLPOINTER, SQLINTEGER, SQLINTEGER* );
extern SQLRETURN (*libdb400_SQLGetConnectOption)( SQLHDBC, SQLSMALLINT, SQLPOINTER );
extern SQLRETURN (*libdb400_SQLGetConnectOptionW)( SQLHDBC, SQLSMALLINT, SQLPOINTER );
extern SQLRETURN (*libdb400_SQLGetCursorName)( SQLHSTMT, SQLCHAR*, SQLSMALLINT, SQLSMALLINT* );
extern SQLRETURN (*libdb400_SQLGetCursorNameW)( SQLHSTMT, SQLWCHAR*, SQLSMALLINT, SQLSMALLINT* );
extern SQLRETURN (*libdb400_SQLGetData)( SQLHSTMT, SQLSMALLINT, SQLSMALLINT, SQLPOINTER, SQLINTEGER, SQLINTEGER* );
extern SQLRETURN (*libdb400_SQLGetDescField)( SQLHDESC, SQLSMALLINT, SQLSMALLINT, SQLPOINTER, SQLINTEGER, SQLINTEGER* );
extern SQLRETURN (*libdb400_SQLGetDescFieldW)( SQLHDESC, SQLSMALLINT, SQLSMALLINT, SQLPOINTER, SQLINTEGER, SQLINTEGER* );
extern SQLRETURN (*libdb400_SQLGetDescRec)( SQLHDESC, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLSMALLINT*, SQLSMALLINT*, SQLSMALLINT*, SQLINTEGER*, SQLSMALLINT*, SQLSMALLINT*, SQLSMALLINT* );
extern SQLRETURN (*libdb400_SQLGetDescRecW)( SQLHDESC, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLSMALLINT*, SQLSMALLINT*, SQLSMALLINT*, SQLINTEGER*, SQLSMALLINT*, SQLSMALLINT*, SQLSMALLINT* );
extern SQLRETURN (*libdb400_SQLGetDiagField)( SQLSMALLINT, SQLINTEGER, SQLSMALLINT, SQLSMALLINT, SQLPOINTER, SQLSMALLINT, SQLSMALLINT* );
extern SQLRETURN (*libdb400_SQLGetDiagFieldW)( SQLSMALLINT, SQLINTEGER, SQLSMALLINT, SQLSMALLINT, SQLPOINTER, SQLSMALLINT, SQLSMALLINT* );
extern SQLRETURN (*libdb400_SQLGetDiagRec)( SQLSMALLINT, SQLINTEGER, SQLSMALLINT, SQLCHAR*, SQLINTEGER*, SQLCHAR*, SQLSMALLINT, SQLSMALLINT* );
extern SQLRETURN (*libdb400_SQLGetDiagRecW)( SQLSMALLINT, SQLINTEGER, SQLSMALLINT, SQLWCHAR*, SQLINTEGER*, SQLWCHAR*, SQLSMALLINT, SQLSMALLINT* );
extern SQLRETURN (*libdb400_SQLGetEnvAttr)( SQLHENV, SQLINTEGER, SQLPOINTER, SQLINTEGER, SQLINTEGER* );
extern SQLRETURN (*libdb400_SQLGetFunctions)( SQLHDBC, SQLSMALLINT, SQLSMALLINT* );
extern SQLRETURN (*libdb400_SQLGetInfo)( SQLHDBC, SQLSMALLINT, SQLPOINTER, SQLSMALLINT, SQLSMALLINT* );
extern SQLRETURN (*libdb400_SQLGetInfoW)( SQLHDBC, SQLSMALLINT, SQLPOINTER, SQLSMALLINT, SQLSMALLINT* );
extern SQLRETURN (*libdb400_SQLGetLength)( SQLHSTMT, SQLSMALLINT, SQLINTEGER, SQLINTEGER*, SQLINTEGER* );
extern SQLRETURN (*libdb400_SQLGetPosition)( SQLHSTMT, SQLSMALLINT, SQLINTEGER, SQLINTEGER, SQLCHAR*, SQLINTEGER, SQLINTEGER, SQLINTEGER*, SQLINTEGER* );
extern SQLRETURN (*libdb400_SQLGetPositionW)( SQLHSTMT, SQLSMALLINT, SQLINTEGER, SQLINTEGER, SQLWCHAR*, SQLINTEGER, SQLINTEGER, SQLINTEGER*, SQLINTEGER* );
extern SQLRETURN (*libdb400_SQLGetStmtAttr)( SQLHSTMT, SQLINTEGER, SQLPOINTER, SQLINTEGER, SQLINTEGER* );
extern SQLRETURN (*libdb400_SQLGetStmtAttrW)( SQLHSTMT, SQLINTEGER, SQLPOINTER, SQLINTEGER, SQLINTEGER* );
extern SQLRETURN (*libdb400_SQLGetStmtOption)( SQLHSTMT, SQLSMALLINT, SQLPOINTER );
extern SQLRETURN (*libdb400_SQLGetStmtOptionW)( SQLHSTMT, SQLSMALLINT, SQLPOINTER );
extern SQLRETURN (*libdb400_SQLGetSubString)( SQLHSTMT, SQLSMALLINT, SQLINTEGER, SQLINTEGER, SQLINTEGER, SQLSMALLINT, SQLPOINTER, SQLINTEGER, SQLINTEGER*, SQLINTEGER* );
extern SQLRETURN (*libdb400_SQLGetSubStringW)( SQLHSTMT, SQLSMALLINT, SQLINTEGER, SQLINTEGER, SQLINTEGER, SQLSMALLINT, SQLPOINTER, SQLINTEGER, SQLINTEGER*, SQLINTEGER* );
extern SQLRETURN (*libdb400_SQLGetTypeInfo)( SQLHSTMT, SQLSMALLINT );
extern SQLRETURN (*libdb400_SQLGetTypeInfoW)( SQLHSTMT, SQLSMALLINT );
extern SQLRETURN (*libdb400_SQLLanguages)( SQLHSTMT );
extern SQLRETURN (*libdb400_SQLMoreResults)( SQLHSTMT );
extern SQLRETURN (*libdb400_SQLNativeSql)( SQLHDBC, SQLCHAR*, SQLINTEGER, SQLCHAR*, SQLINTEGER, SQLINTEGER* );
extern SQLRETURN (*libdb400_SQLNativeSqlW)( SQLHDBC, SQLWCHAR*, SQLINTEGER, SQLWCHAR*, SQLINTEGER, SQLINTEGER* );
extern SQLRETURN (*libdb400_SQLNextResult)( SQLHSTMT, SQLHSTMT );
extern SQLRETURN (*libdb400_SQLNumParams)( SQLHSTMT, SQLSMALLINT* );
extern SQLRETURN (*libdb400_SQLNumResultCols)( SQLHSTMT, SQLSMALLINT* );
extern SQLRETURN (*libdb400_SQLParamData)( SQLHSTMT, SQLPOINTER* );
extern SQLRETURN (*libdb400_SQLParamOptions)( SQLHSTMT, SQLINTEGER, SQLINTEGER* );
extern SQLRETURN (*libdb400_SQLPrepare)( SQLHSTMT, SQLCHAR*, SQLINTEGER );
extern SQLRETURN (*libdb400_SQLPrepareW)( SQLHSTMT, SQLWCHAR*, SQLINTEGER );
extern SQLRETURN (*libdb400_SQLPrimaryKeys)( SQLHSTMT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT );
extern SQLRETURN (*libdb400_SQLPrimaryKeysW)( SQLHSTMT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT );
extern SQLRETURN (*libdb400_SQLProcedureColumns)( SQLHSTMT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT );
extern SQLRETURN (*libdb400_SQLProcedureColumnsW)( SQLHSTMT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT );
extern SQLRETURN (*libdb400_SQLProcedures)( SQLHSTMT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT );
extern SQLRETURN (*libdb400_SQLProceduresW)( SQLHSTMT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT );
extern SQLRETURN (*libdb400_SQLPutData)( SQLHSTMT, SQLPOINTER, SQLINTEGER );
extern SQLRETURN (*libdb400_SQLReleaseEnv)( SQLHENV );
extern SQLRETURN (*libdb400_SQLRowCount)( SQLHSTMT, SQLINTEGER* );
extern SQLRETURN (*libdb400_SQLSetConnectAttr)( SQLHDBC, SQLINTEGER, SQLPOINTER, SQLINTEGER );
extern SQLRETURN (*libdb400_SQLSetConnectAttrW)( SQLHDBC, SQLINTEGER, SQLPOINTER, SQLINTEGER );
extern SQLRETURN (*libdb400_SQLSetConnectOption)( SQLHDBC, SQLSMALLINT, SQLPOINTER );
extern SQLRETURN (*libdb400_SQLSetConnectOptionW)( SQLHDBC, SQLSMALLINT, SQLPOINTER );
extern SQLRETURN (*libdb400_SQLSetCursorName)( SQLHSTMT, SQLCHAR*, SQLSMALLINT );
extern SQLRETURN (*libdb400_SQLSetCursorNameW)( SQLHSTMT, SQLWCHAR*, SQLSMALLINT );
extern SQLRETURN (*libdb400_SQLSetDescField)( SQLHDESC, SQLSMALLINT, SQLSMALLINT, SQLPOINTER, SQLINTEGER );
extern SQLRETURN (*libdb400_SQLSetDescFieldW)( SQLHDESC, SQLSMALLINT, SQLSMALLINT, SQLPOINTER, SQLINTEGER );
extern SQLRETURN (*libdb400_SQLSetDescRec)( SQLHDESC, SQLSMALLINT, SQLSMALLINT, SQLSMALLINT, SQLINTEGER, SQLSMALLINT, SQLSMALLINT, SQLPOINTER, SQLINTEGER*, SQLINTEGER* );
extern SQLRETURN (*libdb400_SQLSetEnvAttr)( SQLHENV, SQLINTEGER, SQLPOINTER, SQLINTEGER );
extern SQLRETURN (*libdb400_SQLSetParam)( SQLHSTMT, SQLSMALLINT, SQLSMALLINT, SQLSMALLINT, SQLINTEGER, SQLSMALLINT, SQLPOINTER, SQLINTEGER* );
extern SQLRETURN (*libdb400_SQLSetStmtAttr)( SQLHSTMT, SQLINTEGER, SQLPOINTER, SQLINTEGER );
extern SQLRETURN (*libdb400_SQLSetStmtAttrW)( SQLHSTMT, SQLINTEGER, SQLPOINTER, SQLINTEGER );
extern SQLRETURN (*libdb400_SQLSetStmtOption)( SQLHSTMT, SQLSMALLINT, SQLPOINTER );
extern SQLRETURN (*libdb400_SQLSetStmtOptionW)( SQLHSTMT, SQLSMALLINT, SQLPOINTER );
extern SQLRETURN (*libdb400_SQLSpecialColumns)( SQLHSTMT, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLSMALLINT, SQLSMALLINT );
extern SQLRETURN (*libdb400_SQLSpecialColumnsW)( SQLHSTMT, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLSMALLINT, SQLSMALLINT );
extern SQLRETURN (*libdb400_SQLStartTran)( SQLSMALLINT, SQLHENV, SQLINTEGER, SQLINTEGER );
extern SQLRETURN (*libdb400_SQLStatistics)( SQLHSTMT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLSMALLINT, SQLSMALLINT );
extern SQLRETURN (*libdb400_SQLStatisticsW)( SQLHSTMT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLSMALLINT, SQLSMALLINT );
extern SQLRETURN (*libdb400_SQLTablePrivileges)( SQLHSTMT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT );
extern SQLRETURN (*libdb400_SQLTablePrivilegesW)( SQLHSTMT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT );
extern SQLRETURN (*libdb400_SQLTables)( SQLHSTMT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT );
extern SQLRETURN (*libdb400_SQLTablesW)( SQLHSTMT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT, SQLWCHAR*, SQLSMALLINT );
extern SQLRETURN (*libdb400_SQLTransact)( SQLHENV, SQLHDBC, SQLSMALLINT );

void libdb400_load_dlsym();

SQLRETURN custom_SQL400ToUtf8( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  inccsid );
SQLRETURN custom_SQL400FromUtf8( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  outccsid );
SQLRETURN custom_SQL400ToUtf16( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  inccsid );
SQLRETURN custom_SQL400FromUtf16( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  outccsid );
SQLRETURN custom_SQL400AddAttr( SQLINTEGER  scope, SQLINTEGER  attrib, SQLPOINTER  vParam, SQLINTEGER  inlen, SQLINTEGER  onerr, SQLINTEGER  flag, SQLPOINTER  options );
SQLRETURN custom_SQL400SetAttr( SQLINTEGER  scope, SQLHANDLE  hndl, SQLINTEGER  flag, SQLPOINTER  options );
SQLRETURN custom_SQL400Environment( SQLINTEGER * ohnd, SQLPOINTER  options );
SQLRETURN custom_SQL400Connect( SQLHENV  henv, SQLCHAR * db, SQLCHAR * uid, SQLCHAR * pwd, SQLINTEGER * ohnd, SQLPOINTER  options );
SQLRETURN custom_SQL400ConnectW( SQLHENV  henv, SQLWCHAR * db, SQLWCHAR * uid, SQLWCHAR * pwd, SQLINTEGER * ohnd, SQLPOINTER  options );
SQLRETURN custom_SQL400AddCVar( SQLSMALLINT  icol, SQLSMALLINT  inOutType, SQLSMALLINT  pfSqlCType, SQLPOINTER  pfSqlCValue, SQLINTEGER * indPtr, SQLPOINTER  parms );
SQLRETURN custom_SQL400AddDesc( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  flag, SQLPOINTER  descs );
SQLRETURN custom_SQL400Execute( SQLHSTMT  hstmt, SQLPOINTER  parms, SQLPOINTER  desc_parms );
SQLRETURN custom_SQL400Fetch( SQLHSTMT  hstmt, SQLINTEGER  start_row, SQLPOINTER  cols, SQLPOINTER  desc_cols );
SQLRETURN custom_SQL400Stmt2Hdbc( SQLHSTMT  hstmt, SQLINTEGER * ohnd );

/* === internal use ======            */

#endif /* _PASECLIASYNC_H */
