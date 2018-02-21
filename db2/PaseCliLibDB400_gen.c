#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dlfcn.h>
#include <sqlcli1.h>
#include <as400_types.h>
#include <as400_protos.h>
#include "PaseCliInit.h"
#include "PaseCliAsync.h"

#define DFTCOLSIZE 18
#define SQL_MAXINTVAL_REASONABLE 131072


int non_utf_copy_in_hdbc(SQLHDBC	hdbc, SQLCHAR **tmp, SQLCHAR **src, SQLINTEGER srclen, SQLINTEGER maxlen) {
  SQLRETURN sqlrc1 = SQL_SUCCESS;
  int inccsid = init_CCSID400(0);
  int outccsid = init_job_CCSID400();
  SQLCHAR * inparm = *src;
  SQLINTEGER inlen = srclen;
  SQLCHAR * outparm = (SQLCHAR *) NULL;
  SQLINTEGER outlen = 0;
  if (inparm) {
    if (srclen == SQL_NTS) {
      inlen = strlen(inparm);
    }
    outlen = maxlen;
    outparm = (SQLCHAR *) malloc(outlen);
    memset(outparm,0,outlen);
    sqlrc1 = SQL400IgnoreNullAnyToAny(hdbc, inparm, inlen,  outparm, outlen, inccsid, outccsid);
    outlen = strlen(outparm);
  }
  *tmp = *src;
  if (*src) {
    *src = outparm;
  }
  return outlen;
}
int non_utf_copy_in_hstmt(SQLHSTMT hstmt, SQLCHAR **tmp, SQLCHAR **src, SQLINTEGER srclen, SQLINTEGER maxlen) {
  SQLHDBC hdbc = init_table_stmt_2_conn(hstmt);
  return non_utf_copy_in_hdbc(hdbc, tmp, src, srclen, maxlen);
}
void non_utf_copy_in_free(SQLCHAR **tmp, SQLCHAR **src) {
  char * trash = *src;
  *src = *tmp;
  if (trash) {
    free(trash);
    *tmp = NULL;
  }
}
int non_utf_copy_out_hdbc(SQLHDBC	hdbc, SQLRETURN sqlrc, SQLCHAR *src, SQLINTEGER srclen) {
  SQLRETURN sqlrc1 = SQL_SUCCESS;
  int inccsid = init_CCSID400(0);
  int outccsid = init_job_CCSID400();
  SQLCHAR * inparm = src;
  SQLINTEGER inlen = srclen;
  SQLCHAR * outparm = (SQLCHAR *) NULL;
  SQLINTEGER outlen = 0;
  if (inparm && (inlen != SQL_NULL_DATA) && (sqlrc == SQL_SUCCESS || sqlrc == SQL_SUCCESS_WITH_INFO)) {
    outlen = inlen + 1;
    outparm = (SQLCHAR *) malloc(outlen);
    memset(outparm,0,outlen);
    sqlrc1 = SQL400IgnoreNullAnyFromAny(hdbc, inparm, inlen,  outparm, outlen, inccsid, outccsid);
    outlen = strlen(outparm);
    memcpy(inparm,outparm,inlen);
    free(outparm);
  }
  return outlen;
}
int non_utf_copy_out_hstmt(SQLHSTMT hstmt, SQLRETURN sqlrc, SQLCHAR *src, SQLINTEGER srclen) {
  SQLHDBC hdbc = init_table_stmt_2_conn(hstmt);
  return non_utf_copy_out_hdbc(hdbc, sqlrc, src, srclen);
}

SQLRETURN libdb400_SQLAllocConnect( SQLHENV  henv, SQLHDBC * phdbc ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLAllocConnect( henv, phdbc );
  return sqlrc;
}
SQLRETURN libdb400_SQLAllocEnv( SQLHENV * phenv ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLAllocEnv( phenv );
  return sqlrc;
}
SQLRETURN libdb400_SQLAllocHandle( SQLSMALLINT  htype, SQLINTEGER  ihnd, SQLINTEGER * ohnd ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLAllocHandle( htype, ihnd, ohnd );
  return sqlrc;
}
SQLRETURN libdb400_SQLAllocStmt( SQLHDBC  hdbc, SQLHSTMT * phstmt ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLAllocStmt( hdbc, phstmt );
  return sqlrc;
}
SQLRETURN libdb400_SQLBindCol( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  iType, SQLPOINTER  rgbValue, SQLINTEGER  cbValueMax, SQLINTEGER * pcbValue ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLBindCol( hstmt, icol, iType, rgbValue, cbValueMax, pcbValue );
  return sqlrc;
}
SQLRETURN libdb400_SQLBindFileToCol( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLCHAR * fName, SQLSMALLINT * fNameLen, SQLINTEGER * fOptions, SQLSMALLINT  fValueMax, SQLINTEGER * sLen, SQLINTEGER * pcbValue ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLBindFileToCol( hstmt, icol, fName, fNameLen, fOptions, fValueMax, sLen, pcbValue );
  return sqlrc;
}
SQLRETURN libdb400_SQLBindFileToParam( SQLHSTMT  hstmt, SQLSMALLINT  ipar, SQLSMALLINT  iType, SQLCHAR * fName, SQLSMALLINT * fNameLen, SQLINTEGER * fOptions, SQLSMALLINT  fValueMax, SQLINTEGER * pcbValue ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLBindFileToParam( hstmt, ipar, iType, fName, fNameLen, fOptions, fValueMax, pcbValue );
  return sqlrc;
}
SQLRETURN libdb400_SQLBindParam( SQLHSTMT  hstmt, SQLSMALLINT  iparm, SQLSMALLINT  iType, SQLSMALLINT  pType, SQLINTEGER  pLen, SQLSMALLINT  pScale, SQLPOINTER  pData, SQLINTEGER * pcbValue ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLBindParam( hstmt, iparm, iType, pType, pLen, pScale, pData, pcbValue );
  return sqlrc;
}
SQLRETURN libdb400_SQLBindParameter( SQLHSTMT  hstmt, SQLSMALLINT  ipar, SQLSMALLINT  fParamType, SQLSMALLINT  fCType, SQLSMALLINT  fSQLType, SQLINTEGER  pLen, SQLSMALLINT  pScale, SQLPOINTER  pData, SQLINTEGER  cbValueMax, SQLINTEGER * pcbValue ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLBindParameter( hstmt, ipar, fParamType, fCType, fSQLType, pLen, pScale, pData, cbValueMax, pcbValue );
  return sqlrc;
}
SQLRETURN libdb400_SQLCancel( SQLHSTMT  hstmt ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLCancel( hstmt );
  return sqlrc;
}
SQLRETURN libdb400_SQLCloseCursor( SQLHSTMT  hstmt ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLCloseCursor( hstmt );
  return sqlrc;
}
SQLRETURN libdb400_SQLColAttribute( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fDescType, SQLPOINTER  rgbDesc, SQLSMALLINT  cbDescMax, SQLSMALLINT * pcbDesc, SQLPOINTER  pfDesc ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLColAttribute( hstmt, icol, fDescType, rgbDesc, cbDescMax, pcbDesc, pfDesc );
  return sqlrc;
}
SQLRETURN libdb400_SQLColAttributeW( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fDescType, SQLPOINTER  rgbDesc, SQLSMALLINT  cbDescMax, SQLSMALLINT * pcbDesc, SQLPOINTER  pfDesc ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLColAttributeW( hstmt, icol, fDescType, rgbDesc, cbDescMax, pcbDesc, pfDesc );
  return sqlrc;
}
SQLRETURN libdb400_SQLColAttributes( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fDescType, SQLCHAR * rgbDesc, SQLINTEGER  cbDescMax, SQLINTEGER * pcbDesc, SQLINTEGER * pfDesc ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLINTEGER outsz = 0;
  sqlrc = ILE_SQLColAttributes( hstmt, icol, fDescType, rgbDesc, cbDescMax, pcbDesc, pfDesc );
  if (fDescType == SQL_DESC_NAME) {
    outsz = non_utf_copy_out_hstmt(hstmt, sqlrc, (SQLCHAR *)rgbDesc, (SQLINTEGER)cbDescMax);
    if (pcbDesc) *pcbDesc = outsz;
  }
  return sqlrc;
}
SQLRETURN libdb400_SQLColAttributesW( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fDescType, SQLWCHAR * rgbDesc, SQLINTEGER  cbDescMax, SQLINTEGER * pcbDesc, SQLINTEGER * pfDesc ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLColAttributesW( hstmt, icol, fDescType, rgbDesc, cbDescMax, pcbDesc, pfDesc );
  return sqlrc;
}
SQLRETURN libdb400_SQLColumnPrivileges( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLCHAR * szColumnName, SQLSMALLINT  cbColumnName ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLINTEGER maxsz = SQL_MAXSMALLVAL;
  SQLCHAR * tmp1 = NULL;
  SQLCHAR * tmp2 = NULL;
  SQLCHAR * tmp3 = NULL;
  SQLCHAR * tmp4 = NULL;
  cbTableQualifier = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp1, (SQLCHAR **)&szTableQualifier, (SQLINTEGER)cbTableQualifier, (SQLINTEGER)maxsz);
  cbTableOwner = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp2, (SQLCHAR **)&szTableOwner, (SQLINTEGER)cbTableOwner, (SQLINTEGER)maxsz);
  cbTableName = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp3, (SQLCHAR **)&szTableName, (SQLINTEGER)cbTableName, (SQLINTEGER)maxsz);
  cbColumnName = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp4, (SQLCHAR **)&szColumnName, (SQLINTEGER)cbColumnName, (SQLINTEGER)maxsz);
  sqlrc = ILE_SQLColumnPrivileges( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName, szColumnName, cbColumnName );
  non_utf_copy_in_free((SQLCHAR **)&tmp1, (SQLCHAR **)&szTableQualifier);
  non_utf_copy_in_free((SQLCHAR **)&tmp2, (SQLCHAR **)&szTableOwner);
  non_utf_copy_in_free((SQLCHAR **)&tmp3, (SQLCHAR **)&szTableName);
  non_utf_copy_in_free((SQLCHAR **)&tmp4, (SQLCHAR **)&szColumnName);
  return sqlrc;
}
SQLRETURN libdb400_SQLColumnPrivilegesW( SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName, SQLWCHAR * szColumnName, SQLSMALLINT  cbColumnName ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLColumnPrivilegesW( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName, szColumnName, cbColumnName );
  return sqlrc;
}
SQLRETURN libdb400_SQLColumns( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLCHAR * szColumnName, SQLSMALLINT  cbColumnName ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLINTEGER maxsz = SQL_MAXSMALLVAL;
  SQLCHAR * tmp1 = NULL;
  SQLCHAR * tmp2 = NULL;
  SQLCHAR * tmp3 = NULL;
  SQLCHAR * tmp4 = NULL;
  cbTableQualifier = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp1, (SQLCHAR **)&szTableQualifier, (SQLINTEGER)cbTableQualifier, (SQLINTEGER)maxsz);
  cbTableOwner = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp2, (SQLCHAR **)&szTableOwner, (SQLINTEGER)cbTableOwner, (SQLINTEGER)maxsz);
  cbTableName = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp3, (SQLCHAR **)&szTableName, (SQLINTEGER)cbTableName, (SQLINTEGER)maxsz);
  cbColumnName = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp4, (SQLCHAR **)&szColumnName, (SQLINTEGER)cbColumnName, (SQLINTEGER)maxsz);
  sqlrc = ILE_SQLColumns( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName, szColumnName, cbColumnName );
  non_utf_copy_in_free((SQLCHAR **)&tmp1, (SQLCHAR **)&szTableQualifier);
  non_utf_copy_in_free((SQLCHAR **)&tmp2, (SQLCHAR **)&szTableOwner);
  non_utf_copy_in_free((SQLCHAR **)&tmp3, (SQLCHAR **)&szTableName);
  non_utf_copy_in_free((SQLCHAR **)&tmp4, (SQLCHAR **)&szColumnName);
  return sqlrc;
}
SQLRETURN libdb400_SQLColumnsW( SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName, SQLWCHAR * szColumnName, SQLSMALLINT  cbColumnName ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLColumnsW( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName, szColumnName, cbColumnName );
  return sqlrc;
}
SQLRETURN libdb400_SQLConnect( SQLHDBC  hdbc, SQLCHAR * szDSN, SQLSMALLINT  cbDSN, SQLCHAR * szUID, SQLSMALLINT  cbUID, SQLCHAR * szAuthStr, SQLSMALLINT  cbAuthStr ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLINTEGER maxsz = SQL_MAXSMALLVAL;
  SQLCHAR * tmp1 = NULL;
  SQLCHAR * tmp2 = NULL;
  SQLCHAR * tmp3 = NULL;
  cbDSN = non_utf_copy_in_hdbc(hdbc, (SQLCHAR **)&tmp1, (SQLCHAR **)&szDSN, (SQLINTEGER)cbDSN, (SQLINTEGER)maxsz);
  cbUID = non_utf_copy_in_hdbc(hdbc, (SQLCHAR **)&tmp2, (SQLCHAR **)&szUID, (SQLINTEGER)cbUID, (SQLINTEGER)maxsz);
  cbAuthStr = non_utf_copy_in_hdbc(hdbc, (SQLCHAR **)&tmp3, (SQLCHAR **)&szAuthStr, (SQLINTEGER)cbAuthStr, (SQLINTEGER)maxsz);
  sqlrc = ILE_SQLConnect( hdbc, szDSN, cbDSN, szUID, cbUID, szAuthStr, cbAuthStr );
  non_utf_copy_in_free((SQLCHAR **)&tmp1, (SQLCHAR **)&szDSN);
  non_utf_copy_in_free((SQLCHAR **)&tmp2, (SQLCHAR **)&szUID);
  non_utf_copy_in_free((SQLCHAR **)&tmp3, (SQLCHAR **)&szAuthStr);
  return sqlrc;
}
SQLRETURN libdb400_SQLConnectW( SQLHDBC  hdbc, SQLWCHAR * szDSN, SQLSMALLINT  cbDSN, SQLWCHAR * szUID, SQLSMALLINT  cbUID, SQLWCHAR * szAuthStr, SQLSMALLINT  cbAuthStr ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLConnectW( hdbc, szDSN, cbDSN, szUID, cbUID, szAuthStr, cbAuthStr );
  return sqlrc;
}
SQLRETURN libdb400_SQLCopyDesc( SQLHDESC  sDesc, SQLHDESC  tDesc ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLCopyDesc( sDesc, tDesc );
  return sqlrc;
}
SQLRETURN libdb400_SQLDataSources( SQLHENV  henv, SQLSMALLINT  fDirection, SQLCHAR * szDSN, SQLSMALLINT  cbDSNMax, SQLSMALLINT * pcbDSN, SQLCHAR * szDescription, SQLSMALLINT  cbDescriptionMax, SQLSMALLINT * pcbDescription ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLINTEGER tmpsz = 0;
  sqlrc = ILE_SQLDataSources( henv, fDirection, szDSN, cbDSNMax, pcbDSN, szDescription, cbDescriptionMax, pcbDescription );
  tmpsz = non_utf_copy_out_hdbc(0, sqlrc, (SQLCHAR *)szDSN, (SQLINTEGER)cbDSNMax);
  tmpsz = non_utf_copy_out_hdbc(0, sqlrc, (SQLCHAR *)szDescription, (SQLINTEGER)cbDescriptionMax);
  return sqlrc;
}
SQLRETURN libdb400_SQLDataSourcesW( SQLHENV  henv, SQLSMALLINT  fDirection, SQLWCHAR * szDSN, SQLSMALLINT  cbDSNMax, SQLSMALLINT * pcbDSN, SQLWCHAR * szDescription, SQLSMALLINT  cbDescriptionMax, SQLSMALLINT * pcbDescription ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLDataSourcesW( henv, fDirection, szDSN, cbDSNMax, pcbDSN, szDescription, cbDescriptionMax, pcbDescription );
  return sqlrc;
}
SQLRETURN libdb400_SQLDescribeCol( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLCHAR * szColName, SQLSMALLINT  cbColNameMax, SQLSMALLINT * pcbColName, SQLSMALLINT * pfSqlType, SQLINTEGER * pcbColDef, SQLSMALLINT * pibScale, SQLSMALLINT * pfNullable ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLINTEGER outsz = 0;
  sqlrc = ILE_SQLDescribeCol( hstmt, icol, szColName, cbColNameMax, pcbColName, pfSqlType, pcbColDef, pibScale, pfNullable );
  outsz = non_utf_copy_out_hdbc(0, sqlrc, (SQLCHAR *)szColName, (SQLINTEGER)cbColNameMax);
  if (pcbColName) *pcbColName = outsz;
  return sqlrc;
}
SQLRETURN libdb400_SQLDescribeColW( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLWCHAR * szColName, SQLSMALLINT  cbColNameMax, SQLSMALLINT * pcbColName, SQLSMALLINT * pfSqlType, SQLINTEGER * pcbColDef, SQLSMALLINT * pibScale, SQLSMALLINT * pfNullable ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLDescribeColW( hstmt, icol, szColName, cbColNameMax, pcbColName, pfSqlType, pcbColDef, pibScale, pfNullable );
  return sqlrc;
}
SQLRETURN libdb400_SQLDescribeParam( SQLHSTMT  hstmt, SQLSMALLINT  ipar, SQLSMALLINT * pfSqlType, SQLINTEGER * pcbColDef, SQLSMALLINT * pibScale, SQLSMALLINT * pfNullable ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLDescribeParam( hstmt, ipar, pfSqlType, pcbColDef, pibScale, pfNullable );
  return sqlrc;
}
SQLRETURN libdb400_SQLDisconnect( SQLHDBC  hdbc ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLDisconnect( hdbc );
  return sqlrc;
}
SQLRETURN libdb400_SQLDriverConnect( SQLHDBC  hdbc, SQLPOINTER  hwnd, SQLCHAR * szConnStrIn, SQLSMALLINT  cbConnStrin, SQLCHAR * szConnStrOut, SQLSMALLINT  cbConnStrOutMax, SQLSMALLINT * pcbConnStrOut, SQLSMALLINT  fDriverCompletion ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLINTEGER outsz = 0;
  SQLINTEGER maxsz = SQL_MAXSMALLVAL;
  SQLCHAR * tmp1 = NULL;
  cbConnStrin = non_utf_copy_in_hdbc(hdbc, (SQLCHAR **)&tmp1, (SQLCHAR **)&szConnStrIn, (SQLINTEGER)cbConnStrin, (SQLINTEGER)maxsz);
  sqlrc = ILE_SQLDriverConnect( hdbc, hwnd, szConnStrIn, cbConnStrin, szConnStrOut, cbConnStrOutMax, pcbConnStrOut, fDriverCompletion );
  non_utf_copy_in_free((SQLCHAR **)&tmp1, (SQLCHAR **)&szConnStrIn);
  outsz = non_utf_copy_out_hdbc(0, sqlrc, (SQLCHAR *)szConnStrOut, (SQLINTEGER)cbConnStrOutMax);
  if (pcbConnStrOut) *pcbConnStrOut = outsz;
  return sqlrc;
}
SQLRETURN libdb400_SQLDriverConnectW( SQLHDBC  hdbc, SQLPOINTER  hwnd, SQLWCHAR * szConnStrIn, SQLSMALLINT  cbConnStrin, SQLWCHAR * szConnStrOut, SQLSMALLINT  cbConnStrOutMax, SQLSMALLINT * pcbConnStrOut, SQLSMALLINT  fDriverCompletion ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLDriverConnectW( hdbc, hwnd, szConnStrIn, cbConnStrin, szConnStrOut, cbConnStrOutMax, pcbConnStrOut, fDriverCompletion );
  return sqlrc;
}
SQLRETURN libdb400_SQLEndTran( SQLSMALLINT  htype, SQLHENV  henv, SQLSMALLINT  ctype ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLEndTran( htype, henv, ctype );
  return sqlrc;
}
SQLRETURN libdb400_SQLError( SQLHENV  henv, SQLHDBC  hdbc, SQLHSTMT  hstmt, SQLCHAR * szSqlState, SQLINTEGER * pfNativeError, SQLCHAR * szErrorMsg, SQLSMALLINT  cbErrorMsgMax, SQLSMALLINT * pcbErrorMsg ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLINTEGER outsz = 0;
  SQLINTEGER maxsz = SQL_SQLSTATE_SIZE + 1;
  SQLINTEGER tmpsz = 0;
  sqlrc = ILE_SQLError( henv, hdbc, hstmt, szSqlState, pfNativeError, szErrorMsg, cbErrorMsgMax, pcbErrorMsg );
  tmpsz = non_utf_copy_out_hdbc(0, sqlrc, (SQLCHAR *)szSqlState, (SQLINTEGER)maxsz);
  outsz = non_utf_copy_out_hdbc(0, sqlrc, (SQLCHAR *)szErrorMsg, (SQLINTEGER)cbErrorMsgMax);
  if (pcbErrorMsg) *pcbErrorMsg = outsz;
  return sqlrc;
}
SQLRETURN libdb400_SQLErrorW( SQLHENV  henv, SQLHDBC  hdbc, SQLHSTMT  hstmt, SQLWCHAR * szSqlState, SQLINTEGER * pfNativeError, SQLWCHAR * szErrorMsg, SQLSMALLINT  cbErrorMsgMax, SQLSMALLINT * pcbErrorMsg ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLErrorW( henv, hdbc, hstmt, szSqlState, pfNativeError, szErrorMsg, cbErrorMsgMax, pcbErrorMsg );
  return sqlrc;
}
SQLRETURN libdb400_SQLExecDirect( SQLHSTMT  hstmt, SQLCHAR * szSqlStr, SQLINTEGER  cbSqlStr ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLINTEGER maxsz = SQL_MAXINTVAL_REASONABLE;
  SQLCHAR * tmp1 = NULL;
  cbSqlStr = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp1, (SQLCHAR **)&szSqlStr, (SQLINTEGER)cbSqlStr, (SQLINTEGER)maxsz);
  sqlrc = ILE_SQLExecDirect( hstmt, szSqlStr, cbSqlStr );
  non_utf_copy_in_free((SQLCHAR **)&tmp1, (SQLCHAR **)&szSqlStr);
  return sqlrc;
}
SQLRETURN libdb400_SQLExecDirectW( SQLHSTMT  hstmt, SQLWCHAR * szSqlStr, SQLINTEGER  cbSqlStr ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLExecDirectW( hstmt, szSqlStr, cbSqlStr );
  return sqlrc;
}
SQLRETURN libdb400_SQLExecute( SQLHSTMT  hstmt ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLExecute( hstmt );
  return sqlrc;
}
SQLRETURN libdb400_SQLExtendedFetch( SQLHSTMT  hstmt, SQLSMALLINT  fOrient, SQLINTEGER  fOffset, SQLINTEGER * pcrow, SQLSMALLINT * rgfRowStatus ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLExtendedFetch( hstmt, fOrient, fOffset, pcrow, rgfRowStatus );
  return sqlrc;
}
SQLRETURN libdb400_SQLFetch( SQLHSTMT  hstmt ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLFetch( hstmt );
  return sqlrc;
}
SQLRETURN libdb400_SQLFetchScroll( SQLHSTMT  hstmt, SQLSMALLINT  fOrient, SQLINTEGER  fOffset ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLFetchScroll( hstmt, fOrient, fOffset );
  return sqlrc;
}
SQLRETURN libdb400_SQLForeignKeys( SQLHSTMT  hstmt, SQLCHAR * szPkTableQualifier, SQLSMALLINT  cbPkTableQualifier, SQLCHAR * szPkTableOwner, SQLSMALLINT  cbPkTableOwner, SQLCHAR * szPkTableName, SQLSMALLINT  cbPkTableName, SQLCHAR * szFkTableQualifier, SQLSMALLINT  cbFkTableQualifier, SQLCHAR * szFkTableOwner, SQLSMALLINT  cbFkTableOwner, SQLCHAR * szFkTableName, SQLSMALLINT  cbFkTableName ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLINTEGER maxsz = SQL_MAXSMALLVAL;
  SQLCHAR * tmp1 = NULL;
  SQLCHAR * tmp2 = NULL;
  SQLCHAR * tmp3 = NULL;
  SQLCHAR * tmp4 = NULL;
  SQLCHAR * tmp5 = NULL;
  SQLCHAR * tmp6 = NULL;
  cbPkTableQualifier = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp1, (SQLCHAR **)&szPkTableQualifier, (SQLINTEGER)cbPkTableQualifier, (SQLINTEGER)maxsz);
  cbPkTableOwner = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp2, (SQLCHAR **)&szPkTableOwner, (SQLINTEGER)cbPkTableOwner, (SQLINTEGER)maxsz);
  cbPkTableName = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp3, (SQLCHAR **)&szPkTableName, (SQLINTEGER)cbPkTableName, (SQLINTEGER)maxsz);
  cbFkTableQualifier = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp4, (SQLCHAR **)&szFkTableQualifier, (SQLINTEGER)cbFkTableQualifier, (SQLINTEGER)maxsz);
  cbFkTableOwner = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp5, (SQLCHAR **)&szFkTableOwner, (SQLINTEGER)cbFkTableOwner, (SQLINTEGER)maxsz);
  cbFkTableName = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp6, (SQLCHAR **)&szFkTableName, (SQLINTEGER)cbFkTableName, (SQLINTEGER)maxsz);
  sqlrc = ILE_SQLForeignKeys( hstmt, szPkTableQualifier, cbPkTableQualifier, szPkTableOwner, cbPkTableOwner, szPkTableName, cbPkTableName, szFkTableQualifier, cbFkTableQualifier, szFkTableOwner, cbFkTableOwner, szFkTableName, cbFkTableName );
  non_utf_copy_in_free((SQLCHAR **)&tmp1, (SQLCHAR **)&szPkTableQualifier);
  non_utf_copy_in_free((SQLCHAR **)&tmp2, (SQLCHAR **)&szPkTableOwner);
  non_utf_copy_in_free((SQLCHAR **)&tmp3, (SQLCHAR **)&szPkTableName);
  non_utf_copy_in_free((SQLCHAR **)&tmp4, (SQLCHAR **)&szFkTableQualifier);
  non_utf_copy_in_free((SQLCHAR **)&tmp5, (SQLCHAR **)&szFkTableOwner);
  non_utf_copy_in_free((SQLCHAR **)&tmp6, (SQLCHAR **)&szFkTableName);
  return sqlrc;
}
SQLRETURN libdb400_SQLForeignKeysW( SQLHSTMT  hstmt, SQLWCHAR * szPkTableQualifier, SQLSMALLINT  cbPkTableQualifier, SQLWCHAR * szPkTableOwner, SQLSMALLINT  cbPkTableOwner, SQLWCHAR * szPkTableName, SQLSMALLINT  cbPkTableName, SQLWCHAR * szFkTableQualifier, SQLSMALLINT  cbFkTableQualifier, SQLWCHAR * szFkTableOwner, SQLSMALLINT  cbFkTableOwner, SQLWCHAR * szFkTableName, SQLSMALLINT  cbFkTableName ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLForeignKeysW( hstmt, szPkTableQualifier, cbPkTableQualifier, szPkTableOwner, cbPkTableOwner, szPkTableName, cbPkTableName, szFkTableQualifier, cbFkTableQualifier, szFkTableOwner, cbFkTableOwner, szFkTableName, cbFkTableName );
  return sqlrc;
}
SQLRETURN libdb400_SQLFreeConnect( SQLHDBC  hdbc ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLFreeConnect( hdbc );
  return sqlrc;
}
SQLRETURN libdb400_SQLFreeEnv( SQLHENV  henv ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLFreeEnv( henv );
  return sqlrc;
}
SQLRETURN libdb400_SQLFreeStmt( SQLHSTMT  hstmt, SQLSMALLINT  fOption ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLFreeStmt( hstmt, fOption );
  return sqlrc;
}
SQLRETURN libdb400_SQLFreeHandle( SQLSMALLINT  htype, SQLINTEGER  hndl ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLFreeHandle( htype, hndl );
  return sqlrc;
}
SQLRETURN libdb400_SQLGetCol( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  itype, SQLPOINTER  tval, SQLINTEGER  blen, SQLINTEGER * olen ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLGetCol( hstmt, icol, itype, tval, blen, olen );
  return sqlrc;
}
SQLRETURN libdb400_SQLGetColW( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  itype, SQLPOINTER  tval, SQLINTEGER  blen, SQLINTEGER * olen ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLGetColW( hstmt, icol, itype, tval, blen, olen );
  return sqlrc;
}
SQLRETURN libdb400_SQLGetConnectAttr( SQLHDBC  hdbc, SQLINTEGER  attr, SQLPOINTER  oval, SQLINTEGER  ilen, SQLINTEGER * olen ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLINTEGER outsz = 0;
  sqlrc = ILE_SQLGetConnectAttr( hdbc, attr, oval, ilen, olen );
  if (attr == SQL_ATTR_DBC_DEFAULT_LIB || attr == SQL_ATTR_SAVEPOINT_NAME) {
    outsz = non_utf_copy_out_hdbc(hdbc, sqlrc, (SQLCHAR *)oval, (SQLINTEGER)ilen);
    if (olen) *olen = outsz;
  }
  return sqlrc;
}
SQLRETURN libdb400_SQLGetConnectAttrW( SQLHDBC  hdbc, SQLINTEGER  attr, SQLPOINTER  oval, SQLINTEGER  ilen, SQLINTEGER * olen ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLGetConnectAttrW( hdbc, attr, oval, ilen, olen );
  return sqlrc;
}
SQLRETURN libdb400_SQLGetConnectOption( SQLHDBC  hdbc, SQLSMALLINT  iopt, SQLPOINTER  oval ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLINTEGER maxsz = DFTCOLSIZE;
  SQLINTEGER tmpsz = 0;
  sqlrc = ILE_SQLGetConnectOption( hdbc, iopt, oval );
  if (iopt == SQL_ATTR_DBC_DEFAULT_LIB) {
    tmpsz = non_utf_copy_out_hdbc(hdbc, sqlrc, (SQLCHAR *)oval, (SQLINTEGER)maxsz);
  }
  return sqlrc;
}
SQLRETURN libdb400_SQLGetConnectOptionW( SQLHDBC  hdbc, SQLSMALLINT  iopt, SQLPOINTER  oval ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLGetConnectOptionW( hdbc, iopt, oval );
  return sqlrc;
}
SQLRETURN libdb400_SQLGetCursorName( SQLHSTMT  hstmt, SQLCHAR * szCursor, SQLSMALLINT  cbCursorMax, SQLSMALLINT * pcbCursor ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLINTEGER outsz = 0;
  sqlrc = ILE_SQLGetCursorName( hstmt, szCursor, cbCursorMax, pcbCursor );
  outsz = non_utf_copy_out_hdbc(0, sqlrc, (SQLCHAR *)szCursor, (SQLINTEGER)cbCursorMax);
  if (pcbCursor) *pcbCursor = outsz;
  return sqlrc;
}
SQLRETURN libdb400_SQLGetCursorNameW( SQLHSTMT  hstmt, SQLWCHAR * szCursor, SQLSMALLINT  cbCursorMax, SQLSMALLINT * pcbCursor ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLGetCursorNameW( hstmt, szCursor, cbCursorMax, pcbCursor );
  return sqlrc;
}
SQLRETURN libdb400_SQLGetData( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fCType, SQLPOINTER  rgbValue, SQLINTEGER  cbValueMax, SQLINTEGER * pcbValue ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLGetData( hstmt, icol, fCType, rgbValue, cbValueMax, pcbValue );
  return sqlrc;
}
SQLRETURN libdb400_SQLGetDescField( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  fieldID, SQLPOINTER  fValue, SQLINTEGER  fLength, SQLINTEGER * stLength ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLINTEGER outsz = 0;
  sqlrc = ILE_SQLGetDescField( hdesc, rcdNum, fieldID, fValue, fLength, stLength );
  if (fieldID == SQL_DESC_NAME) {
  outsz = non_utf_copy_out_hdbc(0, sqlrc, (SQLCHAR *)fValue, (SQLINTEGER)fLength);
  if (stLength) *stLength = outsz;
  }
  return sqlrc;
}
SQLRETURN libdb400_SQLGetDescFieldW( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  fieldID, SQLPOINTER  fValue, SQLINTEGER  fLength, SQLINTEGER * stLength ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLGetDescFieldW( hdesc, rcdNum, fieldID, fValue, fLength, stLength );
  return sqlrc;
}
SQLRETURN libdb400_SQLGetDescRec( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLCHAR * fname, SQLSMALLINT  bufLen, SQLSMALLINT * sLength, SQLSMALLINT * sType, SQLSMALLINT * sbType, SQLINTEGER * fLength, SQLSMALLINT * fprec, SQLSMALLINT * fscale, SQLSMALLINT * fnull ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLINTEGER outsz = 0;
  sqlrc = ILE_SQLGetDescRec( hdesc, rcdNum, fname, bufLen, sLength, sType, sbType, fLength, fprec, fscale, fnull );
  outsz = non_utf_copy_out_hdbc(0, sqlrc, (SQLCHAR *)fname, (SQLINTEGER)bufLen);
  if (sLength) *sLength = outsz;
  return sqlrc;
}
SQLRETURN libdb400_SQLGetDescRecW( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLWCHAR * fname, SQLSMALLINT  bufLen, SQLSMALLINT * sLength, SQLSMALLINT * sType, SQLSMALLINT * sbType, SQLINTEGER * fLength, SQLSMALLINT * fprec, SQLSMALLINT * fscale, SQLSMALLINT * fnull ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLGetDescRecW( hdesc, rcdNum, fname, bufLen, sLength, sType, sbType, fLength, fprec, fscale, fnull );
  return sqlrc;
}
SQLRETURN libdb400_SQLGetDiagField( SQLSMALLINT  hType, SQLINTEGER  hndl, SQLSMALLINT  rcdNum, SQLSMALLINT  diagID, SQLPOINTER  dValue, SQLSMALLINT  bLength, SQLSMALLINT * sLength ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLINTEGER outsz = 0;
  sqlrc = ILE_SQLGetDiagField( hType, hndl, rcdNum, diagID, dValue, bLength, sLength );
  if (diagID == SQL_DIAG_SQLSTATE || diagID == SQL_DIAG_MESSAGE_TEXT || diagID == SQL_DIAG_SERVER_NAME) {
    if (hType == SQL_HANDLE_DBC) {
      outsz = non_utf_copy_out_hdbc(hndl, sqlrc, (SQLCHAR *)dValue, (SQLINTEGER)bLength);
    } else {
      outsz = non_utf_copy_out_hstmt(hndl, sqlrc, (SQLCHAR *)dValue, (SQLINTEGER)bLength);
    }
    if (sLength) *sLength = outsz;
  }
  return sqlrc;
}
SQLRETURN libdb400_SQLGetDiagFieldW( SQLSMALLINT  hType, SQLINTEGER  hndl, SQLSMALLINT  rcdNum, SQLSMALLINT  diagID, SQLPOINTER  dValue, SQLSMALLINT  bLength, SQLSMALLINT * sLength ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLGetDiagFieldW( hType, hndl, rcdNum, diagID, dValue, bLength, sLength );
  return sqlrc;
}
SQLRETURN libdb400_SQLGetDiagRec( SQLSMALLINT  hType, SQLINTEGER  hndl, SQLSMALLINT  rcdNum, SQLCHAR * SQLstate, SQLINTEGER * SQLcode, SQLCHAR * msgText, SQLSMALLINT  bLength, SQLSMALLINT * SLength ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLINTEGER outsz = 0;
  SQLINTEGER maxsz = SQL_SQLSTATE_SIZE + 1;
  SQLINTEGER tmpsz = 0;
  sqlrc = ILE_SQLGetDiagRec( hType, hndl, rcdNum, SQLstate, SQLcode, msgText, bLength, SLength );
  if (hType == SQL_HANDLE_DBC) {
    tmpsz = non_utf_copy_out_hdbc(hndl, sqlrc, (SQLCHAR *)SQLstate, (SQLINTEGER)maxsz);
    outsz = non_utf_copy_out_hdbc(hndl, sqlrc, (SQLCHAR *)msgText, (SQLINTEGER)bLength);
  } else {
    tmpsz = non_utf_copy_out_hstmt(hndl, sqlrc, (SQLCHAR *)SQLstate, (SQLINTEGER)maxsz);
    outsz = non_utf_copy_out_hstmt(hndl, sqlrc, (SQLCHAR *)msgText, (SQLINTEGER)bLength);
  }
  if (SLength) *SLength = outsz;
  return sqlrc;
}
SQLRETURN libdb400_SQLGetDiagRecW( SQLSMALLINT  hType, SQLINTEGER  hndl, SQLSMALLINT  rcdNum, SQLWCHAR * SQLstate, SQLINTEGER * SQLcode, SQLWCHAR * msgText, SQLSMALLINT  bLength, SQLSMALLINT * SLength ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLGetDiagRecW( hType, hndl, rcdNum, SQLstate, SQLcode, msgText, bLength, SLength );
  return sqlrc;
}
SQLRETURN libdb400_SQLGetEnvAttr( SQLHENV  hEnv, SQLINTEGER  fAttribute, SQLPOINTER  pParam, SQLINTEGER  cbParamMax, SQLINTEGER * pcbParam ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLINTEGER outsz = 0;
  sqlrc = ILE_SQLGetEnvAttr( hEnv, fAttribute, pParam, cbParamMax, pcbParam );
  if (fAttribute == SQL_ATTR_DEFAULT_LIB || fAttribute == SQL_ATTR_ESCAPE_CHAR) {
    outsz = non_utf_copy_out_hdbc(0, sqlrc, (SQLCHAR *)pParam, (SQLINTEGER)cbParamMax);
  }
  if (pcbParam) *pcbParam = outsz;
  return sqlrc;
}
SQLRETURN libdb400_SQLGetFunctions( SQLHDBC  hdbc, SQLSMALLINT  fFunction, SQLSMALLINT * pfExists ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLGetFunctions( hdbc, fFunction, pfExists );
  return sqlrc;
}
SQLRETURN libdb400_SQLGetInfo( SQLHDBC  hdbc, SQLSMALLINT  fInfoType, SQLPOINTER  rgbInfoValue, SQLSMALLINT  cbInfoValueMax, SQLSMALLINT * pcbInfoValue ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLINTEGER outsz = 0;
  sqlrc = ILE_SQLGetInfo( hdbc, fInfoType, rgbInfoValue, cbInfoValueMax, pcbInfoValue );
  if (fInfoType == SQL_DBMS_NAME
   || fInfoType == SQL_DBMS_VER
   || fInfoType == SQL_PROCEDURES
   || fInfoType == SQL_DATA_SOURCE_NAME
   || fInfoType == SQL_COLUMN_ALIAS
   || fInfoType == SQL_DATA_SOURCE_READ_ONLY
   || fInfoType == SQL_MULTIPLE_ACTIVE_TXN
   || fInfoType == SQL_DRIVER_NAME
   || fInfoType == SQL_IDENTIFIER_QUOTE_CHAR
   || fInfoType == SQL_PROCEDURE_TERM
   || fInfoType == SQL_QUALIFIER_TERM
   || fInfoType == SQL_QUALIFIER_NAME_SEPARATOR
   || fInfoType == SQL_OWNER_TERM
   || fInfoType == SQL_DRIVER_ODBC_VER
   || fInfoType == SQL_ORDER_BY_COLUMNS_IN_SELECT
   || fInfoType == SQL_SEARCH_PATTERN_ESCAPE
   || fInfoType == SQL_OUTER_JOINS
   || fInfoType == SQL_LIKE_ESCAPE_CLAUSE
   || fInfoType == SQL_CATALOG_NAME
   || fInfoType == SQL_DESCRIBE_PARAMETER
  ) {
    outsz = non_utf_copy_out_hdbc(hdbc, sqlrc, (SQLCHAR *)rgbInfoValue, (SQLINTEGER)cbInfoValueMax);
    if (pcbInfoValue) *pcbInfoValue = outsz;
  }
  return sqlrc;
}
SQLRETURN libdb400_SQLGetInfoW( SQLHDBC  hdbc, SQLSMALLINT  fInfoType, SQLPOINTER  rgbInfoValue, SQLSMALLINT  cbInfoValueMax, SQLSMALLINT * pcbInfoValue ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLGetInfoW( hdbc, fInfoType, rgbInfoValue, cbInfoValueMax, pcbInfoValue );
  return sqlrc;
}
SQLRETURN libdb400_SQLGetLength( SQLHSTMT  hstmt, SQLSMALLINT  locType, SQLINTEGER  locator, SQLINTEGER * sLength, SQLINTEGER * ind ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLGetLength( hstmt, locType, locator, sLength, ind );
  return sqlrc;
}
SQLRETURN libdb400_SQLGetPosition( SQLHSTMT  hstmt, SQLSMALLINT  locType, SQLINTEGER  srceLocator, SQLINTEGER  srchLocator, SQLCHAR * srchLiteral, SQLINTEGER  srchLiteralLen, SQLINTEGER  fPosition, SQLINTEGER * located, SQLINTEGER * ind ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLINTEGER maxsz = SQL_MAXINTVAL_REASONABLE;
  SQLCHAR * tmp1 = NULL;
  srchLiteralLen = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp1, (SQLCHAR **)&srchLiteral, (SQLINTEGER)srchLiteralLen, (SQLINTEGER)maxsz);
  sqlrc = ILE_SQLGetPosition( hstmt, locType, srceLocator, srchLocator, srchLiteral, srchLiteralLen, fPosition, located, ind );
  non_utf_copy_in_free((SQLCHAR **)&tmp1, (SQLCHAR **)&srchLiteral);
  return sqlrc;
}
SQLRETURN libdb400_SQLGetPositionW( SQLHSTMT  hstmt, SQLSMALLINT  locType, SQLINTEGER  srceLocator, SQLINTEGER  srchLocator, SQLWCHAR * srchLiteral, SQLINTEGER  srchLiteralLen, SQLINTEGER  fPosition, SQLINTEGER * located, SQLINTEGER * ind ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLGetPositionW( hstmt, locType, srceLocator, srchLocator, srchLiteral, srchLiteralLen, fPosition, located, ind );
  return sqlrc;
}
SQLRETURN libdb400_SQLGetStmtAttr( SQLHSTMT  hstmt, SQLINTEGER  fAttr, SQLPOINTER  pvParam, SQLINTEGER  bLength, SQLINTEGER * SLength ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLGetStmtAttr( hstmt, fAttr, pvParam, bLength, SLength );
  return sqlrc;
}
SQLRETURN libdb400_SQLGetStmtAttrW( SQLHSTMT  hstmt, SQLINTEGER  fAttr, SQLPOINTER  pvParam, SQLINTEGER  bLength, SQLINTEGER * SLength ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLGetStmtAttrW( hstmt, fAttr, pvParam, bLength, SLength );
  return sqlrc;
}
SQLRETURN libdb400_SQLGetStmtOption( SQLHSTMT  hstmt, SQLSMALLINT  fOption, SQLPOINTER  pvParam ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLGetStmtOption( hstmt, fOption, pvParam );
  return sqlrc;
}
SQLRETURN libdb400_SQLGetStmtOptionW( SQLHSTMT  hstmt, SQLSMALLINT  fOption, SQLPOINTER  pvParam ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLGetStmtOptionW( hstmt, fOption, pvParam );
  return sqlrc;
}
SQLRETURN libdb400_SQLGetSubString( SQLHSTMT  hstmt, SQLSMALLINT  locType, SQLINTEGER  srceLocator, SQLINTEGER  fPosition, SQLINTEGER  length, SQLSMALLINT  tType, SQLPOINTER  rgbValue, SQLINTEGER  cbValueMax, SQLINTEGER * StringLength, SQLINTEGER * ind ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLGetSubString( hstmt, locType, srceLocator, fPosition, length, tType, rgbValue, cbValueMax, StringLength, ind );
  return sqlrc;
}
SQLRETURN libdb400_SQLGetSubStringW( SQLHSTMT  hstmt, SQLSMALLINT  locType, SQLINTEGER  srceLocator, SQLINTEGER  fPosition, SQLINTEGER  length, SQLSMALLINT  tType, SQLPOINTER  rgbValue, SQLINTEGER  cbValueMax, SQLINTEGER * StringLength, SQLINTEGER * ind ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLGetSubStringW( hstmt, locType, srceLocator, fPosition, length, tType, rgbValue, cbValueMax, StringLength, ind );
  return sqlrc;
}
SQLRETURN libdb400_SQLGetTypeInfo( SQLHSTMT  hstmt, SQLSMALLINT  fSqlType ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLGetTypeInfo( hstmt, fSqlType );
  return sqlrc;
}
SQLRETURN libdb400_SQLGetTypeInfoW( SQLHSTMT  hstmt, SQLSMALLINT  fSqlType ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLGetTypeInfoW( hstmt, fSqlType );
  return sqlrc;
}
SQLRETURN libdb400_SQLLanguages( SQLHSTMT  hstmt ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLLanguages( hstmt );
  return sqlrc;
}
SQLRETURN libdb400_SQLMoreResults( SQLHSTMT  hstmt ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLMoreResults( hstmt );
  return sqlrc;
}
SQLRETURN libdb400_SQLNativeSql( SQLHDBC  hdbc, SQLCHAR * szSqlStrIn, SQLINTEGER  cbSqlStrIn, SQLCHAR * szSqlStr, SQLINTEGER  cbSqlStrMax, SQLINTEGER * pcbSqlStr ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLINTEGER outsz = 0;
  SQLINTEGER maxsz = SQL_MAXINTVAL_REASONABLE;
  SQLCHAR * tmp1 = NULL;
  cbSqlStrIn = non_utf_copy_in_hdbc(hdbc, (SQLCHAR **)&tmp1, (SQLCHAR **)&szSqlStrIn, (SQLINTEGER)cbSqlStrIn, (SQLINTEGER)maxsz);
  sqlrc = ILE_SQLNativeSql( hdbc, szSqlStrIn, cbSqlStrIn, szSqlStr, cbSqlStrMax, pcbSqlStr );
  non_utf_copy_in_free((SQLCHAR **)&tmp1, (SQLCHAR **)&szSqlStrIn);
  outsz = non_utf_copy_out_hdbc(hdbc, sqlrc, (SQLCHAR *)szSqlStr, (SQLINTEGER)cbSqlStrMax);
  if (pcbSqlStr) *pcbSqlStr = outsz;
  return sqlrc;
}
SQLRETURN libdb400_SQLNativeSqlW( SQLHDBC  hdbc, SQLWCHAR * szSqlStrIn, SQLINTEGER  cbSqlStrIn, SQLWCHAR * szSqlStr, SQLINTEGER  cbSqlStrMax, SQLINTEGER * pcbSqlStr ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLNativeSqlW( hdbc, szSqlStrIn, cbSqlStrIn, szSqlStr, cbSqlStrMax, pcbSqlStr );
  return sqlrc;
}
SQLRETURN libdb400_SQLNextResult( SQLHSTMT  hstmt, SQLHSTMT  hstmt2 ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLNextResult( hstmt, hstmt2 );
  return sqlrc;
}
SQLRETURN libdb400_SQLNumParams( SQLHSTMT  hstmt, SQLSMALLINT * pcpar ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLNumParams( hstmt, pcpar );
  return sqlrc;
}
SQLRETURN libdb400_SQLNumResultCols( SQLHSTMT  hstmt, SQLSMALLINT * pccol ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLNumResultCols( hstmt, pccol );
  return sqlrc;
}
SQLRETURN libdb400_SQLParamData( SQLHSTMT  hstmt, SQLPOINTER * Value ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLParamData( hstmt, Value );
  return sqlrc;
}
SQLRETURN libdb400_SQLParamOptions( SQLHSTMT  hstmt, SQLINTEGER  crow, SQLINTEGER * pirow ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLParamOptions( hstmt, crow, pirow );
  return sqlrc;
}
SQLRETURN libdb400_SQLPrepare( SQLHSTMT  hstmt, SQLCHAR * szSqlStr, SQLINTEGER  cbSqlStr ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLINTEGER maxsz = SQL_MAXINTVAL_REASONABLE;
  SQLCHAR * tmp1 = NULL;
  cbSqlStr = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp1, (SQLCHAR **)&szSqlStr, (SQLINTEGER)cbSqlStr, (SQLINTEGER)maxsz);
  sqlrc = ILE_SQLPrepare( hstmt, szSqlStr, cbSqlStr );
  non_utf_copy_in_free((SQLCHAR **)&tmp1, (SQLCHAR **)&szSqlStr);
  return sqlrc;
}
SQLRETURN libdb400_SQLPrepareW( SQLHSTMT  hstmt, SQLWCHAR * szSqlStr, SQLINTEGER  cbSqlStr ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLPrepareW( hstmt, szSqlStr, cbSqlStr );
  return sqlrc;
}
SQLRETURN libdb400_SQLPrimaryKeys( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLINTEGER maxsz = SQL_MAXSMALLVAL;
  SQLCHAR * tmp1 = NULL;
  SQLCHAR * tmp2 = NULL;
  SQLCHAR * tmp3 = NULL;
  cbTableQualifier = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp1, (SQLCHAR **)&szTableQualifier, (SQLINTEGER)cbTableQualifier, (SQLINTEGER)maxsz);
  cbTableOwner = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp2, (SQLCHAR **)&szTableOwner, (SQLINTEGER)cbTableOwner, (SQLINTEGER)maxsz);
  cbTableName = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp3, (SQLCHAR **)&szTableName, (SQLINTEGER)cbTableName, (SQLINTEGER)maxsz);
  sqlrc = ILE_SQLPrimaryKeys( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName );
  non_utf_copy_in_free((SQLCHAR **)&tmp1, (SQLCHAR **)&szTableQualifier);
  non_utf_copy_in_free((SQLCHAR **)&tmp2, (SQLCHAR **)&szTableOwner);
  non_utf_copy_in_free((SQLCHAR **)&tmp3, (SQLCHAR **)&szTableName);
  return sqlrc;
}
SQLRETURN libdb400_SQLPrimaryKeysW( SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLPrimaryKeysW( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName );
  return sqlrc;
}
SQLRETURN libdb400_SQLProcedureColumns( SQLHSTMT  hstmt, SQLCHAR * szProcQualifier, SQLSMALLINT  cbProcQualifier, SQLCHAR * szProcOwner, SQLSMALLINT  cbProcOwner, SQLCHAR * szProcName, SQLSMALLINT  cbProcName, SQLCHAR * szColumnName, SQLSMALLINT  cbColumnName ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLINTEGER maxsz = SQL_MAXSMALLVAL;
  SQLCHAR * tmp1 = NULL;
  SQLCHAR * tmp2 = NULL;
  SQLCHAR * tmp3 = NULL;
  SQLCHAR * tmp4 = NULL;
  cbProcQualifier = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp1, (SQLCHAR **)&szProcQualifier, (SQLINTEGER)cbProcQualifier, (SQLINTEGER)maxsz);
  cbProcOwner = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp2, (SQLCHAR **)&szProcOwner, (SQLINTEGER)cbProcOwner, (SQLINTEGER)maxsz);
  cbProcName = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp3, (SQLCHAR **)&szProcName, (SQLINTEGER)cbProcName, (SQLINTEGER)maxsz);
  cbColumnName = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp4, (SQLCHAR **)&szColumnName, (SQLINTEGER)cbColumnName, (SQLINTEGER)maxsz);
  sqlrc = ILE_SQLProcedureColumns( hstmt, szProcQualifier, cbProcQualifier, szProcOwner, cbProcOwner, szProcName, cbProcName, szColumnName, cbColumnName );
  non_utf_copy_in_free((SQLCHAR **)&tmp1, (SQLCHAR **)&szProcQualifier);
  non_utf_copy_in_free((SQLCHAR **)&tmp2, (SQLCHAR **)&szProcOwner);
  non_utf_copy_in_free((SQLCHAR **)&tmp3, (SQLCHAR **)&szProcName);
  non_utf_copy_in_free((SQLCHAR **)&tmp4, (SQLCHAR **)&szColumnName);
  return sqlrc;
}
SQLRETURN libdb400_SQLProcedureColumnsW( SQLHSTMT  hstmt, SQLWCHAR * szProcQualifier, SQLSMALLINT  cbProcQualifier, SQLWCHAR * szProcOwner, SQLSMALLINT  cbProcOwner, SQLWCHAR * szProcName, SQLSMALLINT  cbProcName, SQLWCHAR * szColumnName, SQLSMALLINT  cbColumnName ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLProcedureColumnsW( hstmt, szProcQualifier, cbProcQualifier, szProcOwner, cbProcOwner, szProcName, cbProcName, szColumnName, cbColumnName );
  return sqlrc;
}
SQLRETURN libdb400_SQLProcedures( SQLHSTMT  hstmt, SQLCHAR * szProcQualifier, SQLSMALLINT  cbProcQualifier, SQLCHAR * szProcOwner, SQLSMALLINT  cbProcOwner, SQLCHAR * szProcName, SQLSMALLINT  cbProcName ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLINTEGER maxsz = SQL_MAXSMALLVAL;
  SQLCHAR * tmp1 = NULL;
  SQLCHAR * tmp2 = NULL;
  SQLCHAR * tmp3 = NULL;
  cbProcQualifier = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp1, (SQLCHAR **)&szProcQualifier, (SQLINTEGER)cbProcQualifier, (SQLINTEGER)maxsz);
  cbProcOwner = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp2, (SQLCHAR **)&szProcOwner, (SQLINTEGER)cbProcOwner, (SQLINTEGER)maxsz);
  cbProcName = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp3, (SQLCHAR **)&szProcName, (SQLINTEGER)cbProcName, (SQLINTEGER)maxsz);
  sqlrc = ILE_SQLProcedures( hstmt, szProcQualifier, cbProcQualifier, szProcOwner, cbProcOwner, szProcName, cbProcName );
  non_utf_copy_in_free((SQLCHAR **)&tmp1, (SQLCHAR **)&szProcQualifier);
  non_utf_copy_in_free((SQLCHAR **)&tmp2, (SQLCHAR **)&szProcOwner);
  non_utf_copy_in_free((SQLCHAR **)&tmp3, (SQLCHAR **)&szProcName);
  return sqlrc;
}
SQLRETURN libdb400_SQLProceduresW( SQLHSTMT  hstmt, SQLWCHAR * szProcQualifier, SQLSMALLINT  cbProcQualifier, SQLWCHAR * szProcOwner, SQLSMALLINT  cbProcOwner, SQLWCHAR * szProcName, SQLSMALLINT  cbProcName ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLProceduresW( hstmt, szProcQualifier, cbProcQualifier, szProcOwner, cbProcOwner, szProcName, cbProcName );
  return sqlrc;
}
SQLRETURN libdb400_SQLPutData( SQLHSTMT  hstmt, SQLPOINTER  Data, SQLINTEGER  SLen ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLPutData( hstmt, Data, SLen );
  return sqlrc;
}
SQLRETURN libdb400_SQLReleaseEnv( SQLHENV  henv ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLReleaseEnv( henv );
  return sqlrc;
}
SQLRETURN libdb400_SQLRowCount( SQLHSTMT  hstmt, SQLINTEGER * pcrow ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLRowCount( hstmt, pcrow );
  return sqlrc;
}
SQLRETURN libdb400_SQLSetConnectAttr( SQLHDBC  hdbc, SQLINTEGER  attrib, SQLPOINTER  vParam, SQLINTEGER  inlen ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLINTEGER maxsz = SQL_MAXINTVAL_REASONABLE;
  SQLCHAR * tmp1 = NULL;
  if (attrib == SQL_ATTR_DBC_DEFAULT_LIB || attrib == SQL_ATTR_SAVEPOINT_NAME) {
    inlen = non_utf_copy_in_hdbc(hdbc, (SQLCHAR **)&tmp1, (SQLCHAR **)&vParam, (SQLINTEGER)inlen, (SQLINTEGER)maxsz);
  }
  sqlrc = ILE_SQLSetConnectAttr( hdbc, attrib, vParam, inlen );
  if (attrib == SQL_ATTR_DBC_DEFAULT_LIB || attrib == SQL_ATTR_SAVEPOINT_NAME) {
    non_utf_copy_in_free((SQLCHAR **)&tmp1, (SQLCHAR **)&vParam);
  }
  return sqlrc;
}
SQLRETURN libdb400_SQLSetConnectAttrW( SQLHDBC  hdbc, SQLINTEGER  attrib, SQLPOINTER  vParam, SQLINTEGER  inlen ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLSetConnectAttrW( hdbc, attrib, vParam, inlen );
  return sqlrc;
}
SQLRETURN libdb400_SQLSetConnectOption( SQLHDBC  hdbc, SQLSMALLINT  fOption, SQLPOINTER  vParam ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLINTEGER maxsz = SQL_MAXSMALLVAL;
  SQLINTEGER tmpsz = 0;
  SQLCHAR * tmp1 = NULL;
  if (fOption == SQL_ATTR_DBC_DEFAULT_LIB || fOption == SQL_ATTR_SAVEPOINT_NAME) {
    tmpsz = non_utf_copy_in_hdbc(hdbc, (SQLCHAR **)&tmp1, (SQLCHAR **)&vParam, (SQLINTEGER)SQL_NTS, (SQLINTEGER)maxsz);
  }
  sqlrc = ILE_SQLSetConnectOption( hdbc, fOption, vParam );
  if (fOption == SQL_ATTR_DBC_DEFAULT_LIB || fOption == SQL_ATTR_SAVEPOINT_NAME) {
    non_utf_copy_in_free((SQLCHAR **)&tmp1, (SQLCHAR **)&vParam);
  }
  return sqlrc;
}
SQLRETURN libdb400_SQLSetConnectOptionW( SQLHDBC  hdbc, SQLSMALLINT  fOption, SQLPOINTER  vParam ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLSetConnectOptionW( hdbc, fOption, vParam );
  return sqlrc;
}
SQLRETURN libdb400_SQLSetCursorName( SQLHSTMT  hstmt, SQLCHAR * szCursor, SQLSMALLINT  cbCursor ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLINTEGER maxsz = SQL_MAXSMALLVAL;
  SQLCHAR * tmp1 = NULL;
  cbCursor = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp1, (SQLCHAR **)&szCursor, (SQLINTEGER)cbCursor, (SQLINTEGER)maxsz);
  sqlrc = ILE_SQLSetCursorName( hstmt, szCursor, cbCursor );
  non_utf_copy_in_free((SQLCHAR **)&tmp1, (SQLCHAR **)&szCursor);
  return sqlrc;
}
SQLRETURN libdb400_SQLSetCursorNameW( SQLHSTMT  hstmt, SQLWCHAR * szCursor, SQLSMALLINT  cbCursor ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLSetCursorNameW( hstmt, szCursor, cbCursor );
  return sqlrc;
}
SQLRETURN libdb400_SQLSetDescField( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  fID, SQLPOINTER  Value, SQLINTEGER  buffLen ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLSetDescField( hdesc, rcdNum, fID, Value, buffLen );
  return sqlrc;
}
SQLRETURN libdb400_SQLSetDescFieldW( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  fID, SQLPOINTER  Value, SQLINTEGER  buffLen ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLSetDescFieldW( hdesc, rcdNum, fID, Value, buffLen );
  return sqlrc;
}
SQLRETURN libdb400_SQLSetDescRec( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  Type, SQLSMALLINT  subType, SQLINTEGER  fLength, SQLSMALLINT  fPrec, SQLSMALLINT  fScale, SQLPOINTER  Value, SQLINTEGER * sLength, SQLINTEGER * indic ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLSetDescRec( hdesc, rcdNum, Type, subType, fLength, fPrec, fScale, Value, sLength, indic );
  return sqlrc;
}
SQLRETURN libdb400_SQLSetEnvAttr( SQLHENV  hEnv, SQLINTEGER  fAttribute, SQLPOINTER  pParam, SQLINTEGER  cbParam ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLINTEGER maxsz = SQL_MAXINTVAL_REASONABLE;
  SQLCHAR * tmp1 = NULL;
  if (fAttribute == SQL_ATTR_DBC_DEFAULT_LIB || fAttribute == SQL_ATTR_SAVEPOINT_NAME) {
    cbParam = non_utf_copy_in_hdbc(0, (SQLCHAR **)&tmp1, (SQLCHAR **)&pParam, (SQLINTEGER)maxsz, (SQLINTEGER)maxsz);
  }
  sqlrc = ILE_SQLSetEnvAttr( hEnv, fAttribute, pParam, cbParam );
  if (fAttribute == SQL_ATTR_DBC_DEFAULT_LIB || fAttribute == SQL_ATTR_SAVEPOINT_NAME) {
    non_utf_copy_in_free((SQLCHAR **)&tmp1, (SQLCHAR **)&pParam);
  }
  return sqlrc;
}
SQLRETURN libdb400_SQLSetParam( SQLHSTMT  hstmt, SQLSMALLINT  ipar, SQLSMALLINT  fCType, SQLSMALLINT  fSqlType, SQLINTEGER  cbColDef, SQLSMALLINT  ibScale, SQLPOINTER  rgbValue, SQLINTEGER * pcbValue ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLSetParam( hstmt, ipar, fCType, fSqlType, cbColDef, ibScale, rgbValue, pcbValue );
  return sqlrc;
}
SQLRETURN libdb400_SQLSetStmtAttr( SQLHSTMT  hstmt, SQLINTEGER  fAttr, SQLPOINTER  pParam, SQLINTEGER  vParam ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLSetStmtAttr( hstmt, fAttr, pParam, vParam );
  return sqlrc;
}
SQLRETURN libdb400_SQLSetStmtAttrW( SQLHSTMT  hstmt, SQLINTEGER  fAttr, SQLPOINTER  pParam, SQLINTEGER  vParam ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLSetStmtAttrW( hstmt, fAttr, pParam, vParam );
  return sqlrc;
}
SQLRETURN libdb400_SQLSetStmtOption( SQLHSTMT  hstmt, SQLSMALLINT  fOption, SQLPOINTER  vParam ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLSetStmtOption( hstmt, fOption, vParam );
  return sqlrc;
}
SQLRETURN libdb400_SQLSetStmtOptionW( SQLHSTMT  hstmt, SQLSMALLINT  fOption, SQLPOINTER  vParam ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLSetStmtOptionW( hstmt, fOption, vParam );
  return sqlrc;
}
SQLRETURN libdb400_SQLSpecialColumns( SQLHSTMT  hstmt, SQLSMALLINT  fColType, SQLCHAR * szTableQual, SQLSMALLINT  cbTableQual, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLSMALLINT  fScope, SQLSMALLINT  fNullable ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLINTEGER maxsz = SQL_MAXSMALLVAL;
  SQLCHAR * tmp1 = NULL;
  SQLCHAR * tmp2 = NULL;
  SQLCHAR * tmp3 = NULL;
  cbTableQual = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp1, (SQLCHAR **)&szTableQual, (SQLINTEGER)cbTableQual, (SQLINTEGER)maxsz);
  cbTableOwner = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp2, (SQLCHAR **)&szTableOwner, (SQLINTEGER)cbTableOwner, (SQLINTEGER)maxsz);
  cbTableName = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp3, (SQLCHAR **)&szTableName, (SQLINTEGER)cbTableName, (SQLINTEGER)maxsz);
  sqlrc = ILE_SQLSpecialColumns( hstmt, fColType, szTableQual, cbTableQual, szTableOwner, cbTableOwner, szTableName, cbTableName, fScope, fNullable );
  non_utf_copy_in_free((SQLCHAR **)&tmp1, (SQLCHAR **)&szTableQual);
  non_utf_copy_in_free((SQLCHAR **)&tmp2, (SQLCHAR **)&szTableOwner);
  non_utf_copy_in_free((SQLCHAR **)&tmp3, (SQLCHAR **)&szTableName);
  return sqlrc;
}
SQLRETURN libdb400_SQLSpecialColumnsW( SQLHSTMT  hstmt, SQLSMALLINT  fColType, SQLWCHAR * szTableQual, SQLSMALLINT  cbTableQual, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName, SQLSMALLINT  fScope, SQLSMALLINT  fNullable ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLSpecialColumnsW( hstmt, fColType, szTableQual, cbTableQual, szTableOwner, cbTableOwner, szTableName, cbTableName, fScope, fNullable );
  return sqlrc;
}
SQLRETURN libdb400_SQLStartTran( SQLSMALLINT  htype, SQLHENV  henv, SQLINTEGER  mode, SQLINTEGER  clevel ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLStartTran( htype, henv, mode, clevel );
  return sqlrc;
}
SQLRETURN libdb400_SQLStatistics( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLSMALLINT  fUnique, SQLSMALLINT  fres ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLINTEGER maxsz = SQL_MAXSMALLVAL;
  SQLCHAR * tmp1 = NULL;
  SQLCHAR * tmp2 = NULL;
  SQLCHAR * tmp3 = NULL;
  cbTableQualifier = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp1, (SQLCHAR **)&szTableQualifier, (SQLINTEGER)cbTableQualifier, (SQLINTEGER)maxsz);
  cbTableOwner = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp2, (SQLCHAR **)&szTableOwner, (SQLINTEGER)cbTableOwner, (SQLINTEGER)maxsz);
  cbTableName = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp3, (SQLCHAR **)&szTableName, (SQLINTEGER)cbTableName, (SQLINTEGER)maxsz);
  sqlrc = ILE_SQLStatistics( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName, fUnique, fres );
  non_utf_copy_in_free((SQLCHAR **)&tmp1, (SQLCHAR **)&szTableQualifier);
  non_utf_copy_in_free((SQLCHAR **)&tmp2, (SQLCHAR **)&szTableOwner);
  non_utf_copy_in_free((SQLCHAR **)&tmp3, (SQLCHAR **)&szTableName);
}
SQLRETURN libdb400_SQLStatisticsW( SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName, SQLSMALLINT  fUnique, SQLSMALLINT  fres ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLStatisticsW( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName, fUnique, fres );
  return sqlrc;
}
SQLRETURN libdb400_SQLTablePrivileges( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLINTEGER maxsz = SQL_MAXSMALLVAL;
  SQLCHAR * tmp1 = NULL;
  SQLCHAR * tmp2 = NULL;
  SQLCHAR * tmp3 = NULL;
  cbTableQualifier = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp1, (SQLCHAR **)&szTableQualifier, (SQLINTEGER)maxsz, (SQLINTEGER)maxsz);
  cbTableOwner = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp2, (SQLCHAR **)&szTableOwner, (SQLINTEGER)maxsz, (SQLINTEGER)maxsz);
  cbTableName = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp3, (SQLCHAR **)&szTableName, (SQLINTEGER)maxsz, (SQLINTEGER)maxsz);
  sqlrc = ILE_SQLTablePrivileges( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName );
  non_utf_copy_in_free((SQLCHAR **)&tmp1, (SQLCHAR **)&szTableQualifier);
  non_utf_copy_in_free((SQLCHAR **)&tmp2, (SQLCHAR **)&szTableOwner);
  non_utf_copy_in_free((SQLCHAR **)&tmp3, (SQLCHAR **)&szTableName);
  return sqlrc;
}
SQLRETURN libdb400_SQLTablePrivilegesW( SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLTablePrivilegesW( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName );
  return sqlrc;
}
SQLRETURN libdb400_SQLTables( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLCHAR * szTableType, SQLSMALLINT  cbTableType ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLINTEGER maxsz = SQL_MAXSMALLVAL;
  SQLCHAR * tmp1 = NULL;
  SQLCHAR * tmp2 = NULL;
  SQLCHAR * tmp3 = NULL;
  SQLCHAR * tmp4 = NULL;
  cbTableQualifier = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp1, (SQLCHAR **)&szTableQualifier, (SQLINTEGER)maxsz, (SQLINTEGER)maxsz);
  cbTableOwner = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp2, (SQLCHAR **)&szTableOwner, (SQLINTEGER)maxsz, (SQLINTEGER)maxsz);
  cbTableName = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp3, (SQLCHAR **)&szTableName, (SQLINTEGER)maxsz, (SQLINTEGER)maxsz);
  cbTableType = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp4, (SQLCHAR **)&szTableType, (SQLINTEGER)maxsz, (SQLINTEGER)maxsz);
  sqlrc = ILE_SQLTables( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName, szTableType, cbTableType );
  non_utf_copy_in_free((SQLCHAR **)&tmp1, (SQLCHAR **)&szTableQualifier);
  non_utf_copy_in_free((SQLCHAR **)&tmp2, (SQLCHAR **)&szTableOwner);
  non_utf_copy_in_free((SQLCHAR **)&tmp3, (SQLCHAR **)&szTableName);
  non_utf_copy_in_free((SQLCHAR **)&tmp4, (SQLCHAR **)&szTableType);
  return sqlrc;
}
SQLRETURN libdb400_SQLTablesW( SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName, SQLWCHAR * szTableType, SQLSMALLINT  cbTableType ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLTablesW( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName, szTableType, cbTableType );
  return sqlrc;
}
SQLRETURN libdb400_SQLTransact( SQLHENV  henv, SQLHDBC  hdbc, SQLSMALLINT  fType ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = ILE_SQLTransact( henv, hdbc, fType );
  return sqlrc;
}

