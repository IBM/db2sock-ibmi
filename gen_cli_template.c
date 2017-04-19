
SQLRETURN SQLAllocConnect(SQLHENV henv, 
 SQLHDBC * phdbc); 

SQLRETURN SQLAllocEnv(SQLHENV * phenv); 
 
SQLRETURN SQLAllocHandle(SQLSMALLINT htype, 
 SQLINTEGER ihnd, 
 SQLINTEGER * ohnd); 
 
SQLRETURN SQLAllocStmt(SQLHDBC hdbc, 
 SQLHSTMT * phstmt); 
 
SQLRETURN SQLBindCol(SQLHSTMT hstmt, 
 SQLSMALLINT icol, 
 SQLSMALLINT iType, 
 SQLPOINTER rgbValue, 
 SQLINTEGER cbValueMax, 
 SQLINTEGER * pcbValue); 
 
SQLRETURN SQLBindFileToCol(SQLHSTMT hstmt, 
 SQLSMALLINT icol, 
 SQLCHAR * fName, 
 SQLSMALLINT * fNameLen, 
 SQLINTEGER * fOptions, 
 SQLSMALLINT fValueMax, 
 SQLINTEGER * sLen, 
 SQLINTEGER * pcbValue); 
 
SQLRETURN SQLBindFileToParam(SQLHSTMT hstmt, 
 SQLSMALLINT ipar, 
 SQLSMALLINT iType, 
 SQLCHAR * fName, 
 SQLSMALLINT * fNameLen, 
 SQLINTEGER * fOptions, 
 SQLSMALLINT fValueMax, 
 SQLINTEGER * pcbValue); 
 
SQLRETURN SQLBindParam(SQLHSTMT hstmt, 
 SQLSMALLINT iparm, 
 SQLSMALLINT iType, 
 SQLSMALLINT pType, 
 SQLINTEGER pLen, 
 SQLSMALLINT pScale, 
 SQLPOINTER pData, 
 SQLINTEGER * pcbValue); 
 
SQLRETURN SQLBindParameter(SQLHSTMT hstmt, 
 SQLSMALLINT ipar, 
 SQLSMALLINT fParamType, 
 SQLSMALLINT fCType, 
 SQLSMALLINT fSQLType, 
 SQLINTEGER pLen, 
 SQLSMALLINT pScale, 
 SQLPOINTER pData, 
 SQLINTEGER cbValueMax, 
 SQLINTEGER * pcbValue); 
 
SQLRETURN SQLCancel(SQLHSTMT hstmt); 
 
SQLRETURN SQLCloseCursor(SQLHSTMT hstmt); 
 
SQLRETURN SQLColAttribute(SQLHSTMT hstmt, 
 SQLSMALLINT icol, 
 SQLSMALLINT fDescType, 
 SQLPOINTER rgbDesc, 
 SQLSMALLINT cbDescMax, 
 SQLSMALLINT * pcbDesc, 
 SQLPOINTER pfDesc); 
 
SQLRETURN SQLColAttributeW(SQLHSTMT hstmt, 
 SQLSMALLINT icol, 
 SQLSMALLINT fDescType, 
 SQLPOINTER rgbDesc, 
 SQLSMALLINT cbDescMax, 
 SQLSMALLINT * pcbDesc, 
 SQLPOINTER pfDesc); 
 
SQLRETURN SQLColAttributes(SQLHSTMT hstmt, 
 SQLSMALLINT icol, 
 SQLSMALLINT fDescType, 
 SQLCHAR * rgbDesc, 
 SQLINTEGER cbDescMax, 
 SQLINTEGER * pcbDesc, 
 SQLINTEGER * pfDesc); 
 
SQLRETURN SQLColAttributesW(SQLHSTMT hstmt, 
 SQLSMALLINT icol, 
 SQLSMALLINT fDescType, 
 SQLWCHAR * rgbDesc, 
 SQLINTEGER cbDescMax, 
 SQLINTEGER * pcbDesc, 
 SQLINTEGER * pfDesc); 
 
SQLRETURN SQLColumnPrivileges(SQLHSTMT hstmt, 
 SQLCHAR * szTableQualifier, 
 SQLSMALLINT cbTableQualifier, 
 SQLCHAR * szTableOwner, 
 SQLSMALLINT cbTableOwner, 
 SQLCHAR * szTableName, 
 SQLSMALLINT cbTableName, 
 SQLCHAR * szColumnName, 
 SQLSMALLINT cbColumnName); 
 
SQLRETURN SQLColumnPrivilegesW(SQLHSTMT hstmt, 
 SQLWCHAR * szTableQualifier, 
 SQLSMALLINT cbTableQualifier, 
 SQLWCHAR * szTableOwner, 
 SQLSMALLINT cbTableOwner, 
 SQLWCHAR * szTableName, 
 SQLSMALLINT cbTableName, 
 SQLWCHAR * szColumnName, 
 SQLSMALLINT cbColumnName); 
 
SQLRETURN SQLColumns(SQLHSTMT hstmt, 
 SQLCHAR * szTableQualifier, 
 SQLSMALLINT cbTableQualifier, 
 SQLCHAR * szTableOwner, 
 SQLSMALLINT cbTableOwner, 
 SQLCHAR * szTableName, 
 SQLSMALLINT cbTableName, 
 SQLCHAR * szColumnName, 
 SQLSMALLINT cbColumnName); 
 
SQLRETURN SQLColumnsW(SQLHSTMT hstmt, 
 SQLWCHAR * szTableQualifier, 
 SQLSMALLINT cbTableQualifier, 
 SQLWCHAR * szTableOwner, 
 SQLSMALLINT cbTableOwner, 
 SQLWCHAR * szTableName, 
 SQLSMALLINT cbTableName, 
 SQLWCHAR * szColumnName, 
 SQLSMALLINT cbColumnName); 
 
SQLRETURN SQLConnect(SQLHDBC hdbc, 
 SQLCHAR * szDSN, 
 SQLSMALLINT cbDSN, 
 SQLCHAR * szUID, 
 SQLSMALLINT cbUID, 
 SQLCHAR * szAuthStr, 
 SQLSMALLINT cbAuthStr); 
 
SQLRETURN SQLConnectW(SQLHDBC hdbc, 
 SQLWCHAR * szDSN, 
 SQLSMALLINT cbDSN, 
 SQLWCHAR * szUID, 
 SQLSMALLINT cbUID, 
 SQLWCHAR * szAuthStr, 
 SQLSMALLINT cbAuthStr); 
 
 
SQLRETURN SQLCopyDesc(SQLHDESC sDesc, 
 SQLHDESC tDesc); 
 
SQLRETURN SQLDataSources(SQLHENV henv, 
 SQLSMALLINT fDirection, 
 SQLCHAR * szDSN, 
 SQLSMALLINT cbDSNMax, 
 SQLSMALLINT * pcbDSN, 
 SQLCHAR * szDescription, 
 SQLSMALLINT cbDescriptionMax, 
 SQLSMALLINT * pcbDescription); 
 
SQLRETURN SQLDataSourcesW(SQLHENV henv, 
 SQLSMALLINT fDirection, 
 SQLWCHAR * szDSN, 
 SQLSMALLINT cbDSNMax, 
 SQLSMALLINT * pcbDSN, 
 SQLWCHAR * szDescription, 
 SQLSMALLINT cbDescriptionMax, 
 SQLSMALLINT * pcbDescription); 
 
SQLRETURN SQLDescribeCol(SQLHSTMT hstmt, 
 SQLSMALLINT icol, 
 SQLCHAR * szColName, 
 SQLSMALLINT cbColNameMax, 
 SQLSMALLINT * pcbColName, 
 SQLSMALLINT * pfSqlType, 
 SQLINTEGER * pcbColDef, 
 SQLSMALLINT * pibScale, 
 SQLSMALLINT * pfNullable); 
 
SQLRETURN SQLDescribeColW(SQLHSTMT hstmt, 
 SQLSMALLINT icol, 
 SQLWCHAR * szColName, 
 SQLSMALLINT cbColNameMax, 
 SQLSMALLINT * pcbColName, 
 SQLSMALLINT * pfSqlType, 
 SQLINTEGER * pcbColDef, 
 SQLSMALLINT * pibScale, 
 SQLSMALLINT * pfNullable); 
 
SQLRETURN SQLDescribeParam(SQLHSTMT hstmt, 
 SQLSMALLINT ipar, 
 SQLSMALLINT * pfSqlType, 
 SQLINTEGER * pcbColDef, 
 SQLSMALLINT * pibScale, 
 SQLSMALLINT * pfNullable); 
 
SQLRETURN SQLDisconnect(SQLHDBC hdbc); 
 
SQLRETURN SQLDriverConnect(SQLHDBC hdbc, 
 SQLPOINTER hwnd, 
 SQLCHAR * szConnStrIn, 
 SQLSMALLINT cbConnStrin, 
 SQLCHAR * szConnStrOut, 
 SQLSMALLINT cbConnStrOutMax, 
 SQLSMALLINT * pcbConnStrOut, 
 SQLSMALLINT fDriverCompletion); 
 
SQLRETURN SQLDriverConnectW(SQLHDBC hdbc, 
 SQLPOINTER hwnd, 
 SQLWCHAR * szConnStrIn, 
 SQLSMALLINT cbConnStrin, 
 SQLWCHAR * szConnStrOut, 
 SQLSMALLINT cbConnStrOutMax, 
 SQLSMALLINT * pcbConnStrOut, 
 SQLSMALLINT fDriverCompletion); 
 
SQLRETURN SQLEndTran(SQLSMALLINT htype, 
 SQLHENV henv, 
 SQLSMALLINT ctype); 
 
SQLRETURN SQLError(SQLHENV henv, 
 SQLHDBC hdbc, 
 SQLHSTMT hstmt, 
 SQLCHAR * szSqlState, 
 SQLINTEGER * pfNativeError, 
 SQLCHAR * szErrorMsg, 
 SQLSMALLINT cbErrorMsgMax, 
 SQLSMALLINT * pcbErrorMsg); 
 
SQLRETURN SQLErrorW(SQLHENV henv, 
 SQLHDBC hdbc, 
 SQLHSTMT hstmt, 
 SQLWCHAR * szSqlState, 
 SQLINTEGER * pfNativeError, 
 SQLWCHAR * szErrorMsg, 
 SQLSMALLINT cbErrorMsgMax, 
 SQLSMALLINT * pcbErrorMsg); 
 
 
SQLRETURN SQLExecDirect(SQLHSTMT hstmt, 
 SQLCHAR * szSqlStr, 
 SQLINTEGER cbSqlStr); 
 
SQLRETURN SQLExecDirectW(SQLHSTMT hstmt, 
 SQLWCHAR * szSqlStr, 
 SQLINTEGER cbSqlStr); 
 
SQLRETURN SQLExecute(SQLHSTMT hstmt); 
 
SQLRETURN SQLExtendedFetch(SQLHSTMT hstmt, 
 SQLSMALLINT fOrient, 
 SQLINTEGER fOffset, 
 SQLINTEGER * pcrow, 
 SQLSMALLINT * rgfRowStatus); 
 
SQLRETURN SQLFetch(SQLHSTMT hstmt); 
 
SQLRETURN SQLFetchScroll(SQLHSTMT hstmt, 
 SQLSMALLINT fOrient, 
 SQLINTEGER fOffset); 
 
SQLRETURN SQLForeignKeys(SQLHSTMT hstmt, 
 SQLCHAR * szPkTableQualifier, 
 SQLSMALLINT cbPkTableQualifier, 
 SQLCHAR * szPkTableOwner, 
 SQLSMALLINT cbPkTableOwner, 
 SQLCHAR * szPkTableName, 
 SQLSMALLINT cbPkTableName, 
 SQLCHAR * szFkTableQualifier, 
 SQLSMALLINT cbFkTableQualifier, 
 SQLCHAR * szFkTableOwner, 
 SQLSMALLINT cbFkTableOwner, 
 SQLCHAR * szFkTableName, 
 SQLSMALLINT cbFkTableName); 
 
SQLRETURN SQLForeignKeysW(SQLHSTMT hstmt, 
 SQLWCHAR * szPkTableQualifier, 
 SQLSMALLINT cbPkTableQualifier, 
 SQLWCHAR * szPkTableOwner, 
 SQLSMALLINT cbPkTableOwner, 
 SQLWCHAR * szPkTableName, 
 SQLSMALLINT cbPkTableName, 
 SQLWCHAR * szFkTableQualifier, 
 SQLSMALLINT cbFkTableQualifier, 
 SQLWCHAR * szFkTableOwner, 
 SQLSMALLINT cbFkTableOwner, 
 SQLWCHAR * szFkTableName, 
 SQLSMALLINT cbFkTableName); 
 
SQLRETURN SQLFreeConnect(SQLHDBC hdbc); 
 
SQLRETURN SQLFreeEnv(SQLHENV henv); 
 
SQLRETURN SQLFreeStmt(SQLHSTMT hstmt, 
 SQLSMALLINT fOption); 
 
SQLRETURN SQLFreeHandle(SQLSMALLINT htype, 
 SQLINTEGER hndl); 
 
SQLRETURN SQLGetCol(SQLHSTMT hstmt, 
 SQLSMALLINT icol, 
 SQLSMALLINT itype, 
 SQLPOINTER tval, 
 SQLINTEGER blen, 
 SQLINTEGER * olen); 
 
SQLRETURN SQLGetColW(SQLHSTMT hstmt, 
 SQLSMALLINT icol, 
 SQLSMALLINT itype, 
 SQLPOINTER tval, 
 SQLINTEGER blen, 
 SQLINTEGER * olen); 
 
SQLRETURN SQLGetConnectAttr(SQLHDBC hdbc, 
 SQLINTEGER attr, 
 SQLPOINTER oval, 
 SQLINTEGER ilen, 
 SQLINTEGER * olen); 
 
SQLRETURN SQLGetConnectAttrW(SQLHDBC hdbc, 
 SQLINTEGER attr, 
 SQLPOINTER oval, 
 SQLINTEGER ilen, 
 SQLINTEGER * olen); 
 
SQLRETURN SQLGetConnectOption(SQLHDBC hdbc, 
 SQLSMALLINT iopt, 
 SQLPOINTER oval); 
 
SQLRETURN SQLGetConnectOptionW(SQLHDBC hdbc, 
 SQLSMALLINT iopt, 
 SQLPOINTER oval); 
 
SQLRETURN SQLGetCursorName(SQLHSTMT hstmt, 
 SQLCHAR * szCursor, 
 SQLSMALLINT cbCursorMax, 
 SQLSMALLINT * pcbCursor); 
 
SQLRETURN SQLGetCursorNameW(SQLHSTMT hstmt, 
 SQLWCHAR * szCursor, 
 SQLSMALLINT cbCursorMax, 
 SQLSMALLINT * pcbCursor); 
 
SQLRETURN SQLGetData(SQLHSTMT hstmt, 
 SQLSMALLINT icol, 
 SQLSMALLINT fCType, 
 SQLPOINTER rgbValue, 
 SQLINTEGER cbValueMax, 
 SQLINTEGER * pcbValue); 
 
SQLRETURN SQLGetDescField(SQLHDESC hdesc, 
 SQLSMALLINT rcdNum, 
 SQLSMALLINT fieldID, 
 SQLPOINTER fValue, 
 SQLINTEGER fLength, 
 SQLINTEGER * stLength); 
 
SQLRETURN SQLGetDescFieldW(SQLHDESC hdesc, 
 SQLSMALLINT rcdNum, 
 SQLSMALLINT fieldID, 
 SQLPOINTER fValue, 
 SQLINTEGER fLength, 
 SQLINTEGER * stLength); 
 
SQLRETURN SQLGetDescRec(SQLHDESC hdesc, 
 SQLSMALLINT rcdNum, 
 SQLCHAR * fname, 
 SQLSMALLINT bufLen, 
 SQLSMALLINT * sLength, 
 SQLSMALLINT * sType, 
 SQLSMALLINT * sbType, 
 SQLINTEGER * fLength, 
 SQLSMALLINT * fprec, 
 SQLSMALLINT * fscale, 
 SQLSMALLINT * fnull); 
 
SQLRETURN SQLGetDescRecW(SQLHDESC hdesc, 
 SQLSMALLINT rcdNum, 
 SQLWCHAR * fname, 
 SQLSMALLINT bufLen, 
 SQLSMALLINT * sLength, 
 SQLSMALLINT * sType, 
 SQLSMALLINT * sbType, 
 SQLINTEGER * fLength, 
 SQLSMALLINT * fprec, 
 SQLSMALLINT * fscale, 
 SQLSMALLINT * fnull); 
 
SQLRETURN SQLGetDiagField(SQLSMALLINT hType, 
 SQLINTEGER hndl, 
 SQLSMALLINT rcdNum, 
 SQLSMALLINT diagID, 
 SQLPOINTER dValue, 
 SQLSMALLINT bLength, 
 SQLSMALLINT * sLength); 
 
SQLRETURN SQLGetDiagFieldW(SQLSMALLINT hType, 
 SQLINTEGER hndl, 
 SQLSMALLINT rcdNum, 
 SQLSMALLINT diagID, 
 SQLPOINTER dValue, 
 SQLSMALLINT bLength, 
 SQLSMALLINT * sLength); 
 
SQLRETURN SQLGetDiagRec(SQLSMALLINT hType, 
 SQLINTEGER hndl, 
 SQLSMALLINT rcdNum, 
 SQLCHAR * SQLstate, 
 SQLINTEGER * SQLcode, 
 SQLCHAR * msgText, 
 SQLSMALLINT bLength, 
 SQLSMALLINT * SLength); 
 
SQLRETURN SQLGetDiagRecW(SQLSMALLINT hType, 
 SQLINTEGER hndl, 
 SQLSMALLINT rcdNum, 
 SQLWCHAR * SQLstate, 
 SQLINTEGER * SQLcode, 
 SQLWCHAR * msgText, 
 SQLSMALLINT bLength, 
 SQLSMALLINT * SLength); 
 
SQLRETURN SQLGetEnvAttr(SQLHENV hEnv, 
 SQLINTEGER fAttribute, 
 SQLPOINTER pParam, 
 SQLINTEGER cbParamMax, 
 SQLINTEGER * pcbParam); 
 
SQLRETURN SQLGetFunctions(SQLHDBC hdbc, 
 SQLSMALLINT fFunction, 
 SQLSMALLINT * pfExists); 
 
SQLRETURN SQLGetInfo(SQLHDBC hdbc, 
 SQLSMALLINT fInfoType, 
 SQLPOINTER rgbInfoValue, 
 SQLSMALLINT cbInfoValueMax, 
 SQLSMALLINT * pcbInfoValue); 
 
SQLRETURN SQLGetInfoW(SQLHDBC hdbc, 
 SQLSMALLINT fInfoType, 
 SQLPOINTER rgbInfoValue, 
 SQLSMALLINT cbInfoValueMax, 
 SQLSMALLINT * pcbInfoValue); 
 
SQLRETURN SQLGetLength(SQLHSTMT hstmt, 
 SQLSMALLINT locType, 
 SQLINTEGER locator, 
 SQLINTEGER * sLength, 
 SQLINTEGER * ind); 
 
SQLRETURN SQLGetPosition(SQLHSTMT hstmt, 
 SQLSMALLINT locType, 
 SQLINTEGER srceLocator, 
 SQLINTEGER srchLocator, 
 SQLCHAR * srchLiteral, 
 SQLINTEGER srchLiteralLen, 
 SQLINTEGER fPosition, 
 SQLINTEGER * located, 
 SQLINTEGER * ind); 
 
SQLRETURN SQLGetPositionW(SQLHSTMT hstmt, 
 SQLSMALLINT locType, 
 SQLINTEGER srceLocator, 
 SQLINTEGER srchLocator, 
 SQLWCHAR * srchLiteral, 
 SQLINTEGER srchLiteralLen, 
 SQLINTEGER fPosition, 
 SQLINTEGER * located, 
 SQLINTEGER * ind); 
 
SQLRETURN SQLGetStmtAttr(SQLHSTMT hstmt, 
 SQLINTEGER fAttr, 
 SQLPOINTER pvParam, 
 SQLINTEGER bLength, 
 SQLINTEGER * SLength); 
 
SQLRETURN SQLGetStmtAttrW(SQLHSTMT hstmt, 
 SQLINTEGER fAttr, 
 SQLPOINTER pvParam, 
 SQLINTEGER bLength, 
 SQLINTEGER * SLength); 
 
SQLRETURN SQLGetStmtOption(SQLHSTMT hstmt, 
 SQLSMALLINT fOption, 
 SQLPOINTER pvParam); 
 
SQLRETURN SQLGetStmtOptionW(SQLHSTMT hstmt, 
 SQLSMALLINT fOption, 
 SQLPOINTER pvParam); 
 
SQLRETURN SQLGetSubString(SQLHSTMT hstmt, 
 SQLSMALLINT locType, 
 SQLINTEGER srceLocator, 
 SQLINTEGER fPosition, 
 SQLINTEGER length, 
 SQLSMALLINT tType, 
 SQLPOINTER rgbValue, 
 SQLINTEGER cbValueMax, 
 SQLINTEGER * StringLength, 
 SQLINTEGER * ind); 
 
SQLRETURN SQLGetSubStringW(SQLHSTMT hstmt, 
 SQLSMALLINT locType, 
 SQLINTEGER srceLocator, 
 SQLINTEGER fPosition, 
 SQLINTEGER length, 
 SQLSMALLINT tType, 
 SQLPOINTER rgbValue, 
 SQLINTEGER cbValueMax, 
 SQLINTEGER * StringLength, 
 SQLINTEGER * ind); 
 
SQLRETURN SQLGetTypeInfo(SQLHSTMT hstmt, 
 SQLSMALLINT fSqlType); 
 
SQLRETURN SQLGetTypeInfoW(SQLHSTMT hstmt, 
 SQLSMALLINT fSqlType); 
 
SQLRETURN SQLLanguages(SQLHSTMT hstmt); 
 
SQLRETURN SQLMoreResults(SQLHSTMT hstmt); 
 
SQLRETURN SQLNativeSql(SQLHDBC hdbc, 
 SQLCHAR * szSqlStrIn, 
 SQLINTEGER cbSqlStrIn, 
 SQLCHAR * szSqlStr, 
 SQLINTEGER cbSqlStrMax, 
 SQLINTEGER * pcbSqlStr); 
 
SQLRETURN SQLNativeSqlW(SQLHDBC hdbc, 
 SQLWCHAR * szSqlStrIn, 
 SQLINTEGER cbSqlStrIn, 
 SQLWCHAR * szSqlStr, 
 SQLINTEGER cbSqlStrMax, 
 SQLINTEGER * pcbSqlStr); 
 
SQLRETURN SQLNextResult(SQLHSTMT hstmt, 
		SQLHSTMT hstmt2); 
 
SQLRETURN SQLNumParams(SQLHSTMT hstmt, 
 SQLSMALLINT * pcpar); 
 
SQLRETURN SQLNumResultCols(SQLHSTMT hstmt, 
 SQLSMALLINT * pccol); 
 
SQLRETURN SQLParamData(SQLHSTMT hstmt, 
 SQLPOINTER * Value); 
 
SQLRETURN SQLParamOptions(SQLHSTMT hstmt, 
 SQLINTEGER crow, 
 SQLINTEGER * pirow); 
 
SQLRETURN SQLPrepare(SQLHSTMT hstmt, 
 SQLCHAR * szSqlStr, 
 SQLINTEGER cbSqlStr); 
 
SQLRETURN SQLPrepareW(SQLHSTMT hstmt, 
 SQLWCHAR * szSqlStr, 
 SQLINTEGER cbSqlStr); 
 
SQLRETURN SQLPrimaryKeys(SQLHSTMT hstmt, 
 SQLCHAR * szTableQualifier, 
 SQLSMALLINT cbTableQualifier, 
 SQLCHAR * szTableOwner, 
 SQLSMALLINT cbTableOwner, 
 SQLCHAR * szTableName, 
 SQLSMALLINT cbTableName); 
 
SQLRETURN SQLPrimaryKeysW(SQLHSTMT hstmt, 
 SQLWCHAR * szTableQualifier, 
 SQLSMALLINT cbTableQualifier, 
 SQLWCHAR * szTableOwner, 
 SQLSMALLINT cbTableOwner, 
 SQLWCHAR * szTableName, 
 SQLSMALLINT cbTableName); 
 
SQLRETURN SQLProcedureColumns(SQLHSTMT hstmt, 
 SQLCHAR * szProcQualifier, 
 SQLSMALLINT cbProcQualifier, 
 SQLCHAR * szProcOwner, 
 SQLSMALLINT cbProcOwner, 
 SQLCHAR * szProcName, 
 SQLSMALLINT cbProcName, 
 SQLCHAR * szColumnName, 
 SQLSMALLINT cbColumnName); 
 
SQLRETURN SQLProcedureColumnsW(SQLHSTMT hstmt, 
 SQLWCHAR * szProcQualifier, 
 SQLSMALLINT cbProcQualifier, 
 SQLWCHAR * szProcOwner, 
 SQLSMALLINT cbProcOwner, 
 SQLWCHAR * szProcName, 
 SQLSMALLINT cbProcName, 
 SQLWCHAR * szColumnName, 
 SQLSMALLINT cbColumnName); 
 
SQLRETURN SQLProcedures(SQLHSTMT hstmt, 
 SQLCHAR * szProcQualifier, 
 SQLSMALLINT cbProcQualifier, 
 SQLCHAR * szProcOwner, 
 SQLSMALLINT cbProcOwner, 
 SQLCHAR * szProcName, 
 SQLSMALLINT cbProcName); 
 
SQLRETURN SQLProceduresW(SQLHSTMT hstmt, 
 SQLWCHAR * szProcQualifier, 
 SQLSMALLINT cbProcQualifier, 
 SQLWCHAR * szProcOwner, 
 SQLSMALLINT cbProcOwner, 
 SQLWCHAR * szProcName, 
 SQLSMALLINT cbProcName); 
 
SQLRETURN SQLPutData(SQLHSTMT hstmt, 
 SQLPOINTER Data, 
 SQLINTEGER SLen); 
 
SQLRETURN SQLReleaseEnv(SQLHENV henv); 
 
SQLRETURN SQLRowCount(SQLHSTMT hstmt, 
 SQLINTEGER * pcrow); 
 
SQLRETURN SQLSetConnectAttr(SQLHDBC hdbc, 
 SQLINTEGER attrib, 
 SQLPOINTER vParam, 
 SQLINTEGER inlen); 
 
SQLRETURN SQLSetConnectAttrW(SQLHDBC hdbc, 
 SQLINTEGER attrib, 
 SQLPOINTER vParam, 
 SQLINTEGER inlen); 
 
SQLRETURN SQLSetConnectOption(SQLHDBC hdbc, 
 SQLSMALLINT fOption, 
 SQLPOINTER vParam); 
 
SQLRETURN SQLSetConnectOptionW(SQLHDBC hdbc, 
 SQLSMALLINT fOption, 
 SQLPOINTER vParam); 
 
SQLRETURN SQLSetCursorName(SQLHSTMT hstmt, 
 SQLCHAR * szCursor, 
 SQLSMALLINT cbCursor); 
 
SQLRETURN SQLSetCursorNameW(SQLHSTMT hstmt, 
 SQLWCHAR * szCursor, 
 SQLSMALLINT cbCursor); 
 
SQLRETURN SQLSetDescField(SQLHDESC hdesc, 
 SQLSMALLINT rcdNum, 
 SQLSMALLINT fID, 
 SQLPOINTER Value, 
 SQLINTEGER buffLen); 
 
SQLRETURN SQLSetDescFieldW(SQLHDESC hdesc, 
 SQLSMALLINT rcdNum, 
 SQLSMALLINT fID, 
 SQLPOINTER Value, 
 SQLINTEGER buffLen); 
 
SQLRETURN SQLSetDescRec(SQLHDESC hdesc, 
 SQLSMALLINT rcdNum, 
 SQLSMALLINT Type, 
 SQLSMALLINT subType, 
 SQLINTEGER fLength, 
 SQLSMALLINT fPrec, 
 SQLSMALLINT fScale, 
 SQLPOINTER Value, 
 SQLINTEGER * sLength, 
 SQLINTEGER * indic); 
 
SQLRETURN SQLSetEnvAttr( SQLHENV hEnv, 
 SQLINTEGER fAttribute, 
 SQLPOINTER pParam, 
 SQLINTEGER cbParam); 
 
SQLRETURN SQLSetParam(SQLHSTMT hstmt, 
 SQLSMALLINT ipar, 
 SQLSMALLINT fCType, 
 SQLSMALLINT fSqlType, 
 SQLINTEGER cbColDef, 
 SQLSMALLINT ibScale, 
 SQLPOINTER rgbValue, 
 SQLINTEGER * pcbValue); 
 
SQLRETURN SQLSetStmtAttr(SQLHSTMT hstmt, 
 SQLINTEGER fAttr, 
 SQLPOINTER pParam, 
 SQLINTEGER vParam); 
 
SQLRETURN SQLSetStmtAttrW(SQLHSTMT hstmt, 
 SQLINTEGER fAttr, 
 SQLPOINTER pParam, 
 SQLINTEGER vParam); 
 
SQLRETURN SQLSetStmtOption(SQLHSTMT hstmt, 
 SQLSMALLINT fOption, 
 SQLPOINTER vParam); 
 
SQLRETURN SQLSetStmtOptionW(SQLHSTMT hstmt, 
 SQLSMALLINT fOption, 
 SQLPOINTER vParam); 
 
SQLRETURN SQLSpecialColumns(SQLHSTMT hstmt, 
 SQLSMALLINT fColType, 
 SQLCHAR * szTableQual, 
 SQLSMALLINT cbTableQual, 
 SQLCHAR * szTableOwner, 
 SQLSMALLINT cbTableOwner, 
 SQLCHAR * szTableName, 
 SQLSMALLINT cbTableName, 
 SQLSMALLINT fScope, 
 SQLSMALLINT fNullable); 
 
SQLRETURN SQLSpecialColumnsW(SQLHSTMT hstmt, 
 SQLSMALLINT fColType, 
 SQLWCHAR * szTableQual, 
 SQLSMALLINT cbTableQual, 
 SQLWCHAR * szTableOwner, 
 SQLSMALLINT cbTableOwner, 
 SQLWCHAR * szTableName, 
 SQLSMALLINT cbTableName, 
 SQLSMALLINT fScope, 
 SQLSMALLINT fNullable); 
 
SQLRETURN SQLStartTran(SQLSMALLINT htype, 
		SQLHENV henv, 
		SQLINTEGER mode, 
		SQLINTEGER clevel); 
 
SQLRETURN SQLStatistics(SQLHSTMT hstmt, 
 SQLCHAR * szTableQualifier, 
 SQLSMALLINT cbTableQualifier, 
 SQLCHAR * szTableOwner, 
 SQLSMALLINT cbTableOwner, 
 SQLCHAR * szTableName, 
 SQLSMALLINT cbTableName, 
 SQLSMALLINT fUnique, 
 SQLSMALLINT fres); 
 
SQLRETURN SQLStatisticsW(SQLHSTMT hstmt, 
 SQLWCHAR * szTableQualifier, 
 SQLSMALLINT cbTableQualifier, 
 SQLWCHAR * szTableOwner, 
 SQLSMALLINT cbTableOwner, 
 SQLWCHAR * szTableName, 
 SQLSMALLINT cbTableName, 
 SQLSMALLINT fUnique, 
 SQLSMALLINT fres); 
 
SQLRETURN SQLTablePrivileges(SQLHSTMT hstmt, 
 SQLCHAR * szTableQualifier, 
 SQLSMALLINT cbTableQualifier, 
 SQLCHAR * szTableOwner, 
 SQLSMALLINT cbTableOwner, 
 SQLCHAR * szTableName, 
 SQLSMALLINT cbTableName); 
 
SQLRETURN SQLTablePrivilegesW(SQLHSTMT hstmt, 
 SQLWCHAR * szTableQualifier, 
 SQLSMALLINT cbTableQualifier, 
 SQLWCHAR * szTableOwner, 
 SQLSMALLINT cbTableOwner, 
 SQLWCHAR * szTableName, 
 SQLSMALLINT cbTableName); 
 
SQLRETURN SQLTables(SQLHSTMT hstmt, 
 SQLCHAR * szTableQualifier, 
 SQLSMALLINT cbTableQualifier, 
 SQLCHAR * szTableOwner, 
 SQLSMALLINT cbTableOwner, 
 SQLCHAR * szTableName, 
 SQLSMALLINT cbTableName, 
 SQLCHAR * szTableType, 
 SQLSMALLINT cbTableType); 
 
SQLRETURN SQLTablesW(SQLHSTMT hstmt, 
 SQLWCHAR * szTableQualifier, 
 SQLSMALLINT cbTableQualifier, 
 SQLWCHAR * szTableOwner, 
 SQLSMALLINT cbTableOwner, 
 SQLWCHAR * szTableName, 
 SQLSMALLINT cbTableName, 
 SQLWCHAR * szTableType, 
 SQLSMALLINT cbTableType); 
 
SQLRETURN SQLTransact(SQLHENV henv, 
 SQLHDBC hdbc, 
 SQLSMALLINT fType); 


# ------------------
# custom interfaces, not CLI libdb400.a
# ------------------

# custom mode set driver by ccsid

SQLRETURN SQLOverrideCCSID400(SQLINTEGER newCCSID)

# custom resource table map

SQLRETURN SQL400Stmt2Hdbc(SQLHSTMT hstmt,
 SQLINTEGER * ohnd)

# custom connection

SQLRETURN SQL400Connect(SQLCHAR * db, 
 SQLCHAR * uid, 
 SQLCHAR * pwd, 
 SQLINTEGER * ohnd,
 SQLINTEGER  acommit, 
 SQLCHAR * alibl, 
 SQLCHAR * acurlib)

SQLRETURN SQL400ConnectW(SQLWCHAR * db, 
 SQLWCHAR * uid, 
 SQLWCHAR * pwd, 
 SQLINTEGER * ohnd,
 SQLINTEGER  acommit, 
 SQLCHAR * alibl, 
 SQLCHAR * acurlib)

SQLRETURN SQL400pConnect(SQLCHAR * db, 
 SQLCHAR * uid, 
 SQLCHAR * pwd,
 SQLCHAR * qual,
 SQLINTEGER * ohnd,
 SQLINTEGER  acommit, 
 SQLCHAR * alibl, 
 SQLCHAR * acurlib)

SQLRETURN SQL400pConnectW(SQLWCHAR * db, 
 SQLWCHAR * uid, 
 SQLWCHAR * pwd,
 SQLCHAR * qual,
 SQLINTEGER * ohnd,
 SQLINTEGER  acommit, 
 SQLCHAR * alibl, 
 SQLCHAR * acurlib)

# custom connection with convert

SQLRETURN SQL400ConnectUtf8(SQLINTEGER accsid,
 SQLCHAR * db, 
 SQLCHAR * uid, 
 SQLCHAR * pwd,
 SQLINTEGER * ohnd,
 SQLINTEGER  acommit, 
 SQLCHAR * alibl, 
 SQLCHAR * acurlib)

SQLRETURN SQL400pConnectUtf8(SQLINTEGER accsid,
 SQLCHAR * db, 
 SQLCHAR * uid, 
 SQLCHAR * pwd,
 SQLCHAR * qual,
 SQLINTEGER * ohnd,
 SQLINTEGER  acommit, 
 SQLCHAR * alibl, 
 SQLCHAR * acurlib)

SQLRETURN SQL400ConnectUtf16(SQLINTEGER accsid,
 SQLCHAR * db, 
 SQLCHAR * uid, 
 SQLCHAR * pwd,
 SQLINTEGER * ohnd,
 SQLINTEGER  acommit, 
 SQLCHAR * alibl, 
 SQLCHAR * acurlib)

SQLRETURN SQL400pConnectUtf16(SQLINTEGER accsid,
 SQLCHAR * db, 
 SQLCHAR * uid, 
 SQLCHAR * pwd,
 SQLCHAR * qual,
 SQLINTEGER * ohnd,
 SQLINTEGER  acommit, 
 SQLCHAR * alibl, 
 SQLCHAR * acurlib)

# custom close 

SQLRETURN SQL400Close(SQLHDBC hdbc)

SQLRETURN SQL400pClose(SQLHDBC hdbc)

# custom utilitites 

SQLRETURN SQL400Cmd(SQLHDBC hdbc,
 SQLCHAR * cmd)

SQLRETURN SQL400ChgLibl(SQLHDBC hdbc,
 SQLCHAR * libl)

SQLRETURN SQL400ChgCurLib(SQLHDBC hdbc,
 SQLCHAR * curlib)

# custom convert

SQLRETURN SQL400ToUtf8(SQLHDBC hdbc,
 SQLPOINTER inparm,
 SQLINTEGER inlen, 
 SQLPOINTER outparm,
 SQLINTEGER outlen,
 SQLINTEGER inccsid)

SQLRETURN SQL400FromUtf8(SQLHDBC hdbc,
 SQLPOINTER inparm,
 SQLINTEGER inlen, 
 SQLPOINTER outparm,
 SQLINTEGER outlen,
 SQLINTEGER outccsid)

SQLRETURN SQL400ToUtf16(SQLHDBC hdbc,
 SQLPOINTER inparm,
 SQLINTEGER inlen, 
 SQLPOINTER outparm,
 SQLINTEGER outlen,
 SQLINTEGER inccsid)

SQLRETURN SQL400FromUtf16(SQLHDBC hdbc,
 SQLPOINTER inparm,
 SQLINTEGER inlen, 
 SQLPOINTER outparm,
 SQLINTEGER outlen,
 SQLINTEGER outccsid)


