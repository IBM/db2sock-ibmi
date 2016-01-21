
int SQLOverrideCCSID400(int newCCSID)

SQLRETURN SQLAllocEnv(SQLHENV *	phenv)

SQLRETURN SQLAllocConnect(SQLHENV		henv,
			  SQLHDBC *	phdbc)
		     
SQLRETURN SQLAllocHandle(SQLSMALLINT	htype,
		       SQLINTEGER	ihnd,
		       SQLINTEGER *	ohnd)

SQLRETURN SQLAllocStmt(SQLHDBC		hdbc,
		      SQLHSTMT *	phstmt)

SQLRETURN SQLBindCol(SQLHSTMT		hstmt,
		     SQLSMALLINT	icol,
		     SQLSMALLINT	fCType,
		     SQLPOINTER		rgbValue,
		     SQLINTEGER		cbValueMax,
		     SQLINTEGER *	pcbValue)

SQLRETURN SQLBindFileToCol(SQLHSTMT	hstmt,
		        SQLSMALLINT	icol,
			SQLCHAR *	fName,
			SQLSMALLINT *	fNameLen,
			SQLINTEGER *	fOptions,
		        SQLSMALLINT	fValueMax,
		        SQLINTEGER *	sLen,
		        SQLINTEGER *	pcbValue)

SQLRETURN SQLBindFileToParam(SQLHSTMT	hstmt,
		        SQLSMALLINT	ipar,
			SQLSMALLINT	iType,
			SQLCHAR *	fName,
			SQLSMALLINT *	fNameLen,
			SQLINTEGER *	fOptions,
		        SQLSMALLINT	fValueMax,
		        SQLINTEGER *	pcbValue)

SQLRETURN SQLBindParam(SQLHSTMT		hstmt,
		      SQLSMALLINT       iparm,
		      SQLSMALLINT	iType,
		      SQLSMALLINT	pType,
		      SQLINTEGER        pLen,
		      SQLSMALLINT       pScale,
		      SQLPOINTER        pData,
		      SQLINTEGER *	pcbValue)

SQLRETURN SQLBindParameter(SQLHSTMT	hstmt,
			SQLSMALLINT	ipar,
			SQLSMALLINT	fParamType,
			SQLSMALLINT	fCType,
			SQLSMALLINT	fSQLType,
			SQLINTEGER	pLen,
			SQLSMALLINT	pScale,
			SQLPOINTER	pData,
			SQLINTEGER	cbValueMax,
			SQLINTEGER *	pcbValue)

SQLRETURN SQLCancel(SQLHSTMT	hstmt)

SQLRETURN SQLCloseCursor(SQLHSTMT	   hstmt)

SQLRETURN SQLColAttributes(SQLHSTMT	hstmt,
			SQLSMALLINT	icol,
			SQLSMALLINT	fDescType,
			SQLCHAR *	rgbDesc,
			SQLINTEGER	cbDescMax,
			SQLINTEGER *	pcbDesc,
			SQLINTEGER *	pfDesc)

SQLRETURN SQLColumnPrivileges(SQLHSTMT hstmt,
      SQLCHAR * szCatalogName,
      SQLSMALLINT cbCatalogName,
      SQLCHAR * szSchemaName,
                    SQLSMALLINT cbSchemaName,
      SQLCHAR * szTableName,
                    SQLSMALLINT cbTableName,
      SQLCHAR * szColumnName,
                    SQLSMALLINT cbColumnName)

SQLRETURN SQLColumns(SQLHSTMT	hstmt,
		    SQLCHAR *	szCatalogName,
		    SQLSMALLINT	cbCatalogName,
		    SQLCHAR *	szSchemaName,
                    SQLSMALLINT cbSchemaName,
		    SQLCHAR *	szTableName,
                    SQLSMALLINT cbTableName,
		    SQLCHAR *	szColumnName,
                    SQLSMALLINT cbColumnName)

SQLRETURN SQLConnect(SQLHDBC	hdbc,
		    SQLCHAR *	szDSN,
		    SQLSMALLINT	cbDSN,
		    SQLCHAR *	szUID,
		    SQLSMALLINT	cbUID,
		    SQLCHAR *	szAuthStr,
                    SQLSMALLINT cbAuthStr)

SQLRETURN SQLCopyDesc(SQLHDESC	sDesc,
		    SQLHDESC	tDesc)

SQLRETURN SQLDataSources(SQLHENV       henv,
                      SQLSMALLINT  fDirection,
                      SQLCHAR      *szDSN,
                      SQLSMALLINT   cbDSNMax,
                      SQLSMALLINT  *pcbDSN,
                      SQLCHAR      *szDescription,
                      SQLSMALLINT   cbDescriptionMax,
                      SQLSMALLINT  *pcbDescription)

SQLRETURN SQLDescribeCol(SQLHSTMT          hstmt,
                        SQLSMALLINT     icol,
			SQLCHAR *	szColName,
			SQLSMALLINT	cbColNameMax,
			SQLSMALLINT *	pcbColName,
			SQLSMALLINT *	pfSqlType,
			SQLINTEGER *	pcbColDef,
			SQLSMALLINT *	pibScale,
			SQLSMALLINT *	pfNullable)

SQLRETURN SQLDescribeParam(SQLHSTMT        hstmt,
			SQLSMALLINT	ipar,
			SQLSMALLINT *	pfSqlType,
			SQLINTEGER *	pcbColDef,
			SQLSMALLINT *	pibScale,
			SQLSMALLINT *	pfNullable)

SQLRETURN SQLDisconnect(SQLHDBC	hdbc)

SQLRETURN SQLDriverConnect(SQLHDBC		hdbc,
			SQLPOINTER	hwnd,
			SQLCHAR *	szConnStrIn,
			SQLSMALLINT	cbConnStrin,
			SQLCHAR *	szConnStrOut,
			SQLSMALLINT	cbConnStrOutMax,
			SQLSMALLINT *	pcbConnStrOut,
			SQLSMALLINT	fDriverCompletion)

SQLRETURN SQLEndTran(SQLSMALLINT		htype,
		    SQLHENV		henv,
		    SQLSMALLINT         ctype)

SQLRETURN SQLError(SQLHENV	henv,
		   SQLHDBC	hdbc,
                   SQLHSTMT     hstmt,
		   SQLCHAR *	szSqlState,
		   SQLINTEGER *	pfNativeError,
		   SQLCHAR *	szErrorMsg,
		   SQLSMALLINT	cbErrorMsgMax,
		   SQLSMALLINT *pcbErrorMsg)


SQLRETURN SQLExecDirect(SQLHSTMT		hstmt,
		      SQLCHAR *		szSqlStr,
		      SQLINTEGER	cbSqlStr)

SQLRETURN SQLExecute(SQLHSTMT	hstmt)

SQLRETURN SQLExtendedFetch(SQLHSTMT	hstmt,
			SQLSMALLINT     fOrient,
			SQLINTEGER      fOffset,
			SQLINTEGER *	pcrow,
			SQLSMALLINT *	rgfRowStatus)

SQLRETURN SQLFetch(SQLHSTMT	hstmt)

SQLRETURN SQLFetchScroll(SQLHSTMT		hstmt,
                      SQLSMALLINT      fOrient,
                      SQLINTEGER       fOffset)

SQLRETURN SQLForeignKeys(SQLHSTMT		hstmt,
		       SQLCHAR *	szPkTableQualifier,
		       SQLSMALLINT	cbPkTableQualifier,
		       SQLCHAR *	szPkTableOwner,
		       SQLSMALLINT      cbPkTableOwner,
		       SQLCHAR *	szPkTableName,
		       SQLSMALLINT      cbPkTableName,
		       SQLCHAR *	szFkTableQualifier,
		       SQLSMALLINT      cbFkTableQualifier,
		       SQLCHAR *	szFkTableOwner,
		       SQLSMALLINT      cbFkTableOwner,
		       SQLCHAR *	szFkTableName,
		       SQLSMALLINT      cbFkTableName)

SQLRETURN SQLFreeConnect(SQLHDBC	hdbc)

SQLRETURN SQLFreeEnv(SQLHENV	henv)

SQLRETURN SQLFreeHandle(SQLSMALLINT	htype,
		      SQLINTEGER        hndl)

SQLRETURN SQLFreeStmt(SQLHSTMT		hstmt,
		     SQLSMALLINT	fOption)

SQLRETURN SQLGetCol(SQLHSTMT		hstmt,
		   SQLSMALLINT          icol,
		   SQLSMALLINT		itype,
		   SQLPOINTER		tval,
		   SQLINTEGER		blen,
		   SQLINTEGER *		olen)

SQLRETURN SQLGetConnectAttr(SQLHDBC	hdbc,
			 SQLINTEGER	attr,
			 SQLPOINTER     oval,
			 SQLINTEGER     ilen,
			 SQLINTEGER *	olen)

SQLRETURN SQLGetConnectOption (SQLHDBC	hdbc,
			   SQLSMALLINT	fOption,
			   SQLPOINTER	pvParam)

SQLRETURN SQLGetCursorName(SQLHSTMT       hstmt,
			SQLCHAR *	szCursor,
			SQLSMALLINT	cbCursorMax,
			SQLSMALLINT *	pcbCursor)

SQLRETURN SQLGetData(SQLHSTMT		hstmt,
		     SQLSMALLINT	icol,
		     SQLSMALLINT	fCType,
		     SQLPOINTER		rgbValue,
		     SQLINTEGER		cbValueMax,
		     SQLINTEGER *	pcbValue)

SQLRETURN SQLGetDescField(SQLHDESC        hdesc,
		       SQLSMALLINT      rcdNum,
		       SQLSMALLINT      fieldID,
		       SQLPOINTER       fValue,
		       SQLINTEGER       fLength,
		       SQLINTEGER *	stLength)

SQLRETURN SQLGetDescRec(SQLHDESC		hdesc,
		       SQLSMALLINT	rcdNum,
		       SQLCHAR *	fname,
		       SQLSMALLINT	bufLen,
		       SQLSMALLINT *	sLength,
		       SQLSMALLINT *	sType,
		       SQLSMALLINT *	sbType,
		       SQLINTEGER  *	fLength,
		       SQLSMALLINT *	fprec,
		       SQLSMALLINT *	fscale,
		       SQLSMALLINT *	fnull)

SQLRETURN SQLGetDiagField(SQLSMALLINT	hType,
		      SQLINTEGER        hndl,
		      SQLSMALLINT       rcdNum,
		      SQLSMALLINT       diagID,
		      SQLPOINTER        dValue,
		      SQLSMALLINT       bLength,
		      SQLSMALLINT *	sLength)

SQLRETURN SQLGetDiagRec(SQLSMALLINT	hType,
		       SQLINTEGER       hndl,
		       SQLSMALLINT      rcdNum,
		       SQLCHAR *	SQLstate,
		       SQLINTEGER *	SQLcode,
		       SQLCHAR *	msgText,
		       SQLSMALLINT	bLength,
		       SQLSMALLINT *	sLength)

SQLRETURN SQLGetEnvAttr(SQLHENV		henv,
                     SQLINTEGER        Attribute,
                     SQLPOINTER        Value,
		     SQLINTEGER        BufferLength,
		     SQLINTEGER *	StringLength)

SQLRETURN SQLGetFunctions(SQLHDBC		hdbc,
			  SQLSMALLINT     fFunction,
			  SQLSMALLINT *	pfExists)

SQLRETURN SQLGetInfo(SQLHDBC		hdbc,
		    SQLSMALLINT		fInfoType,
		    SQLPOINTER		rgbInfoValue,
		    SQLSMALLINT		cbInfoValueMax,
		    SQLSMALLINT *	pcbInfoValue)

SQLRETURN SQLGetLength(SQLHSTMT		hstmt,
		     SQLSMALLINT	locType,
		     SQLINTEGER		locator,
		     SQLINTEGER *	sLength,
		     SQLINTEGER *	ind)

SQLRETURN SQLGetPosition(SQLHSTMT		hstmt,
		       SQLSMALLINT	locType,
		       SQLINTEGER	srceLocator,
		       SQLINTEGER	srchLocator,
		       SQLCHAR *	srchLiteral,
		       SQLINTEGER	srchLiteralLen,
		       SQLINTEGER	fPosition,
		       SQLINTEGER *	located,
		       SQLINTEGER *	ind)

SQLRETURN SQLGetStmtAttr(SQLHSTMT       hstmt,
		       SQLINTEGER     fAttr,
		       SQLPOINTER     pvParam,
		       SQLINTEGER     bLength,
		       SQLINTEGER *   SLength)

SQLRETURN SQLGetStmtOption(SQLHSTMT	hstmt,
			 SQLSMALLINT	fOption,
			 SQLPOINTER	pvParam)

SQLRETURN SQLGetSubString(SQLHSTMT	hstmt,
			SQLSMALLINT	locType,
			SQLINTEGER	srceLocator,
			SQLINTEGER	fPosition,
			SQLINTEGER	length,
			SQLSMALLINT	tType,
			SQLPOINTER	rgbValue,
			SQLINTEGER	cbValueMax,
			SQLINTEGER *	StringLength,
			SQLINTEGER *	ind)

SQLRETURN SQLGetTypeInfo(SQLHSTMT          hstmt,
                    SQLSMALLINT       fSqlType)

SQLRETURN SQLLanguages(SQLHSTMT	hstmt)

SQLRETURN SQLMoreResults(SQLHSTMT		hstmt)

SQLRETURN SQLNativeSql(SQLHDBC		hdbc,
		      SQLCHAR *		szSqlStrIn,
		      SQLINTEGER	cbSqlStrIn,
		      SQLCHAR *		szSqlStr,
                      SQLINTEGER        cbSqlStrMax,
		      SQLINTEGER *	pcbSqlStr)

SQLRETURN SQLNextResult(SQLHSTMT	hstmt,
		    SQLHSTMT    hstmt2)

SQLRETURN SQLNumParams(SQLHSTMT          hstmt,
		   SQLSMALLINT *	pcpar)

SQLRETURN SQLNumResultCols(SQLHSTMT	hstmt,
		SQLSMALLINT *	pccol)

SQLRETURN SQLParamData(SQLHSTMT	hstmt,
		   SQLPOINTER *	prgbValue)

SQLRETURN SQLParamOptions(SQLHSTMT		hstmt,
		      SQLINTEGER 	crow,
		      SQLINTEGER *	pirow)

SQLRETURN SQLPrepare(SQLHSTMT       hstmt,
		 SQLCHAR *	szSqlStr,
                 SQLINTEGER     cbSqlStr)

SQLRETURN SQLPrimaryKeys(SQLHSTMT	    hstmt,
		     SQLCHAR *	    szTableQualifier,
		     SQLSMALLINT    cbTableQualifier,
		     SQLCHAR *	    szTableOwner,
		     SQLSMALLINT    cbTableOwner,
		     SQLCHAR *	    szTableName,
		     SQLSMALLINT    cbTableName)

SQLRETURN SQLProcedureColumns(SQLHSTMT     hstmt,
	                   SQLCHAR *	szProcQualifier,
			   SQLSMALLINT  cbProcQualifier,
			   SQLCHAR *	szProcOwner,
			   SQLSMALLINT  cbProcOwner,
			   SQLCHAR *	szProcName,
			   SQLSMALLINT  cbProcName,
			   SQLCHAR *	szColumnName,
			   SQLSMALLINT  cbColumnName)

SQLRETURN SQLProcedures(SQLHSTMT    hstmt,
		    SQLCHAR *	szProcQualifier,
		    SQLSMALLINT cbProcQualifier,
		    SQLCHAR *	szProcOwner,
		    SQLSMALLINT cbProcOwner,
		    SQLCHAR *	szProcName,
		    SQLSMALLINT cbProcName)

SQLRETURN SQLPutData(SQLHSTMT          hstmt,
                  SQLPOINTER        rgbValue,
                  SQLINTEGER        cbValue)

SQLRETURN SQLReleaseEnv(SQLHENV   henv)

SQLRETURN SQLRowCount(SQLHSTMT      hstmt,
		  SQLINTEGER *	pcrow)

SQLRETURN SQLSetConnectAttr(SQLHDBC        hdbc,
			SQLINTEGER     attrib,
			SQLPOINTER     vParam,
			SQLINTEGER     inlen)

SQLRETURN SQLSetConnectOption(SQLHDBC         hdbc,
			  SQLSMALLINT	   fOption,
			  SQLPOINTER       vParam)

SQLRETURN SQLSetCursorName(SQLHSTMT		hstmt,
		       SQLCHAR *	szCursor,
                       SQLSMALLINT      cbCursor)

SQLRETURN SQLSetDescField(SQLHDESC		hdesc,
		        SQLSMALLINT     rcdNum,
			SQLSMALLINT     fID,
			SQLPOINTER      Value,
			SQLINTEGER      buffLen)

SQLRETURN SQLSetDescRec(SQLHDESC	      hdesc,
		    SQLSMALLINT       rcdNum,
		    SQLSMALLINT       Type,
		    SQLSMALLINT       subType,
		    SQLINTEGER        fLength,
		    SQLSMALLINT       fPrec,
		    SQLSMALLINT       fScale,
		    SQLPOINTER        Value,
		    SQLINTEGER *      sLength,
		    SQLINTEGER *     indic)

SQLRETURN SQLSetEnvAttr(SQLHENV           henv,
                    SQLINTEGER        Attribute,
                    SQLPOINTER        Value,
                    SQLINTEGER        StringLength)

SQLRETURN SQLSetParam(SQLHSTMT      hstmt,
                  SQLSMALLINT   ipar,
                  SQLSMALLINT   fCType,
                  SQLSMALLINT   fSqlType,
                  SQLINTEGER    cbParamDef,
                  SQLSMALLINT   ibScale,
                  SQLPOINTER    rgbValue,
		  SQLINTEGER *	pcbValue)

SQLRETURN SQLSetStmtAttr(SQLHSTMT	    hstmt,
		     SQLINTEGER     fAttr,
		     SQLPOINTER     pParam,
		     SQLINTEGER     vParam)

SQLRETURN SQLSetStmtOption(SQLHSTMT		hstmt,
		       SQLSMALLINT	fOption,
		       SQLPOINTER	vParam)

SQLRETURN SQLSpecialColumns(SQLHSTMT	hstmt,
			SQLSMALLINT	fColType,
			SQLCHAR *	szCatalogName,
                        SQLSMALLINT     cbCatalogName,
			SQLCHAR *	szSchemaName,
                        SQLSMALLINT     cbSchemaName,
			SQLCHAR	*	szTableName,
                        SQLSMALLINT     cbTableName,
			SQLSMALLINT	fScope,
			SQLSMALLINT	fNullable)

SQLRETURN SQLStartTran(SQLSMALLINT          htype,
                   SQLHENV              henv,
		   SQLINTEGER           mode,	
                   SQLINTEGER           clevel)

SQLRETURN SQLStatistics(SQLHSTMT	hstmt,
		    SQLCHAR *	szCatalogName,
		    SQLSMALLINT	cbCatalogName,
		    SQLCHAR *	szSchemaName,
		    SQLSMALLINT	cbSchemaName,
		    SQLCHAR *	szTableName,
		    SQLSMALLINT	cbTableName,
		    SQLSMALLINT	fUnique,
		    SQLSMALLINT	fAccuracy)

SQLRETURN SQLTablePrivileges(SQLHSTMT    hstmt,
			     SQLCHAR *   szCatalogName,
			     SQLSMALLINT cbCatalogName,
			     SQLCHAR *   szSchemaName,
			     SQLSMALLINT cbSchemaName,
			     SQLCHAR *   szTableName,
			     SQLSMALLINT cbTableName)

SQLRETURN SQLTables(SQLHSTMT    hstmt,
		SQLCHAR *   szCatalogName,
                SQLSMALLINT cbCatalogName,
		SQLCHAR *   szSchemaName,
                SQLSMALLINT cbSchemaName,
                SQLCHAR *   szTableName,
                SQLSMALLINT cbTableName,
                SQLCHAR *   szTableType,
                SQLSMALLINT cbTableType)

SQLRETURN SQLTransact(SQLHENV	henv,
		  SQLHDBC	hdbc,
		  SQLSMALLINT	fType)

# ------------------
# custom interfaces, not CLI libdb400.a
# ------------------

# custom interfaces, connect attributes

SQLRETURN SQL400AddAttr( SQLINTEGER scope,
 SQLINTEGER  attrib,
 SQLPOINTER  vParam,
 SQLINTEGER  inlen,
 SQLINTEGER  onerr,
 SQLINTEGER  flag,
 SQLPOINTER  options )

SQLRETURN SQL400SetAttr(SQLINTEGER  scope,
 SQLHANDLE  hndl,
 SQLINTEGER  flag,
 SQLPOINTER  options)

SQLRETURN SQL400Environment(SQLINTEGER *	ohnd,
 SQLPOINTER options)

SQLRETURN SQL400Connect(SQLHENV henv, 
 SQLCHAR * db, 
 SQLCHAR * uid, 
 SQLCHAR * pwd, 
 SQLINTEGER *	ohnd,
 SQLPOINTER options)

# custom interfaces, execute fetch

SQLRETURN SQL400AddCParam(SQLSMALLINT icol, 
 SQLSMALLINT inOutType, 
 SQLSMALLINT pfSqlCType, 
 SQLPOINTER pfSqlCValue, 
 SQLINTEGER * indPtr, 
 SQLPOINTER parms) 

SQLRETURN SQL400AddDesc(SQLHSTMT hstmt,
 SQLSMALLINT icol,
 SQLSMALLINT flag, 
 SQLPOINTER descs)

SQLRETURN SQL400Execute(SQLHSTMT hstmt, 
 SQLPOINTER parms, 
 SQLPOINTER desc_parms)

SQLRETURN SQL400Fetch(SQLHSTMT hstmt, 
 SQLINTEGER start_row, 
 SQLPOINTER cols, 
 SQLPOINTER desc_cols) 

SQLRETURN SQL400Stmt2Hdbc(SQLHSTMT hstmt,
  SQLINTEGER *	ohnd)



