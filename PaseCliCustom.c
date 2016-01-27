#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dlfcn.h>
#include <iconv.h>
#include <sqlcli1.h>
#include "PaseCliInit.h"
#include "PaseCliAsync.h"


static int utf8_charset_flag;
static char *utf8_charset_Ascii, *utf8_charset_Utf;
static iconv_t utf8_AsciiToUtf, utf8_UtfToAscii;

static int utf16_charset_flag;
static char *utf16_charset_Ascii, *utf16_charset_Utf;
static iconv_t utf16_AsciiToUtf, utf16_UtfToAscii;


/*
 * resource table
 */

SQLRETURN custom_SQL400Stmt2Hdbc( SQLHSTMT  hstmt, SQLINTEGER * ohnd ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  *ohnd = init_table_stmt_2_conn(hstmt);
  if (*ohnd < 2) {
    sqlrc = SQL_ERROR;
  }
  return sqlrc;
}

/*
 * options
 */

SQLRETURN custom_SQL400SetAttr( SQLINTEGER  scope, SQLHANDLE hndl, SQLINTEGER  flag, SQLPOINTER  options ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  int i = 0;
  SQL400AttrStruct * opts = (SQL400AttrStruct *) options;
  SQL400AttrStruct * opt = (SQL400AttrStruct *) NULL;
  if (opts == NULL) {
    return sqlrc;
  }
  for (i=0; opts[i].scope; i++) {
    opt = &opts[i];
    switch (opt->scope) {
    case SQL_HANDLE_ENV:
      if (scope == SQL_HANDLE_ENV ) {
        switch (opt->attrib) {
        /* SQLRETURN SQLOverrideCCSID400 ( int  newCCSID )
        case SQL400_ATTR_CCSID:
          opt->sqlrc = SQLOverrideCCSID400((int)opt->vParam);
          if (opt->onerr == SQL400_ONERR_STOP) {
            return opt->sqlrc;
          }
          break;
        */
        default:
          /* SQLRETURN SQLSetEnvAttr ( SQLHENV  henv; SQLINTEGER  Attribute; SQLPOINTER  Value; SQLINTEGER StringLength ) */
          opt->sqlrc = SQLSetEnvAttr((SQLHENV)hndl, (SQLINTEGER)opt->attrib, (SQLPOINTER)opt->vParam, (SQLINTEGER) opt->inlen);
          if (opt->onerr == SQL400_ONERR_STOP) {
            return opt->sqlrc;
          }
          break;
        }
      }
      break;
    case SQL_HANDLE_DBC:
      if (scope == SQL_HANDLE_DBC ) {
        switch (opt->attrib) {
        default:
          /* SQLRETURN SQLSetConnectAttr ( SQLHDBC  hdbc, SQLINTEGER  attrib, SQLPOINTER  vParam, SQLINTEGER  inlen ) */
          opt->sqlrc = SQLSetConnectAttr((SQLHDBC)hndl, (SQLINTEGER)opt->attrib, (SQLPOINTER)opt->vParam, (SQLINTEGER) opt->inlen);
          if (opt->onerr == SQL400_ONERR_STOP) {
            return opt->sqlrc;
          }
          break;
        }
      }
      break;
    case SQL_HANDLE_STMT:
      if (scope == SQL_HANDLE_STMT ) {
        switch (opt->attrib) {
        default:
          /* SQLRETURN SQLSetStmtAttr ( SQLHSTMT  hstmt, SQLINTEGER  fAttr, SQLPOINTER  pParam, SQLINTEGER  vParam ) */
          opt->sqlrc = SQLSetStmtAttr((SQLHSTMT)hndl, (SQLINTEGER)opt->attrib, (SQLPOINTER)opt->vParam, (SQLINTEGER) opt->inlen);
          if (opt->onerr == SQL400_ONERR_STOP) {
            return opt->sqlrc;
          }
          break;
        }
      }
      break;
    case SQL_HANDLE_DESC:
      if (scope == SQL_HANDLE_DESC ) {
        switch (opt->attrib) {
        default:
          /* SQLRETURN SQLSetStmtOption( SQLHSTMT hstmt, SQLSMALLINT fOption, SQLPOINTER vParam ) */
          opt->sqlrc = SQLSetStmtOption((SQLHSTMT)hndl, (SQLINTEGER)opt->attrib, (SQLPOINTER)opt->vParam );
          if (opt->onerr == SQL400_ONERR_STOP) {
            return opt->sqlrc;
          }
          break;
        }
      }
      break;
    default:
      break;
    }
  }
  return sqlrc;
}
SQLRETURN custom_SQL400AddAttr( SQLINTEGER scope, SQLINTEGER  attrib, SQLPOINTER  vParam, SQLINTEGER  inlen, SQLINTEGER  onerr, SQLINTEGER  flag, SQLPOINTER  options ){
  SQLRETURN sqlrc = SQL_SUCCESS;
  int i = 0;
  SQL400AttrStruct * opts = (SQL400AttrStruct *) options;
  SQL400AttrStruct * opt = (SQL400AttrStruct *) NULL;
  if (opts == NULL) {
    return sqlrc;
  }
  for (i=0; opts[i].scope; i++) {}
  opt = &opts[i];
  opt->scope = scope;
  opt->hndl = 0;
  opt->attrib = attrib;
  opt->vParam = vParam;
  opt->inlen = inlen;
  opt->sqlrc = SQL_SUCCESS;
  opt->onerr = onerr;
  opt->flag = flag;
  return sqlrc;
}

/*
 * connect
 */

SQLRETURN custom_SQL400Environment( SQLINTEGER * ohnd, SQLPOINTER  options ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  /* henv -- IBM i only one env (always 1) */
  sqlrc = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, ohnd);
  if (sqlrc != SQL_SUCCESS) {
    return sqlrc;
  }
  sqlrc = SQL400SetAttr(SQL_HANDLE_ENV, *ohnd, SQL400_FLAG_IMMED, options);
  if (sqlrc != SQL_SUCCESS) {
    return sqlrc;
  }
  return sqlrc;
}

SQLRETURN custom_SQL400Connect( SQLHENV  henv, SQLCHAR * db, SQLCHAR * uid, SQLCHAR * pwd, SQLINTEGER * ohnd, SQLPOINTER  options ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  int i = 0;
  SQLHDBC hdbc = 0;
  SQLWCHAR * db_str = (SQLWCHAR *) db;
  SQLWCHAR * uid_str = (SQLWCHAR *) uid;
  SQLWCHAR * pwd_str = (SQLWCHAR *) pwd;
  SQLSMALLINT db_len = SQL_NTS;
  SQLSMALLINT uid_len = SQL_NTS;
  SQLSMALLINT pwd_len = SQL_NTS;
  /* null input */
  if (db == NULL || *(unsigned short *)db == 0) {
    db_str = (SQLWCHAR *) NULL;
    db_len = 0;
  }
  if (uid == NULL || *(unsigned short *)uid == 0) {
    uid_str = (SQLWCHAR *) NULL;
    uid_len = 0;
  }
  if (pwd == NULL || *(unsigned short *)pwd == 0) {
    pwd_str = (SQLWCHAR *) NULL;
    pwd_len = 0;
  }
  /* hdbc -- connection */
  sqlrc = SQLAllocHandle(SQL_HANDLE_DBC, henv, ohnd);
  if (sqlrc != SQL_SUCCESS) {
    return sqlrc;
  }
  hdbc = *ohnd;
  init_table_lock(hdbc, 0);
  sqlrc = SQL400SetAttr(SQL_HANDLE_DBC, *ohnd, SQL400_FLAG_PRE_CONNECT, options);
  if (sqlrc != SQL_SUCCESS) {
    init_table_unlock(hdbc, 0);
    return sqlrc;
  }
  /* connect */
  sqlrc = SQLConnect( (SQLHDBC)*ohnd, (SQLCHAR *)db_str, (SQLSMALLINT)db_len, (SQLCHAR *)uid_str, (SQLSMALLINT)uid_len, (SQLCHAR *)pwd_str, (SQLSMALLINT)pwd_len );
  if (sqlrc != SQL_SUCCESS) {
    init_table_unlock(hdbc, 0);
    return sqlrc;
  }
  sqlrc = SQL400SetAttr(SQL_HANDLE_DBC, *ohnd, SQL400_FLAG_POST_CONNECT, options);
  if (sqlrc != SQL_SUCCESS) {
    init_table_unlock(hdbc, 0);
    return sqlrc;
  }
  init_table_unlock(hdbc, 0);
  return sqlrc;
}

SQLRETURN custom_SQL400ConnectW( SQLHENV  henv, SQLWCHAR * db, SQLWCHAR * uid, SQLWCHAR * pwd, SQLINTEGER * ohnd, SQLPOINTER  options ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  int i = 0;
  SQLHDBC hdbc = 0;
  SQLWCHAR * db_str = (SQLWCHAR *) db;
  SQLWCHAR * uid_str = (SQLWCHAR *) uid;
  SQLWCHAR * pwd_str = (SQLWCHAR *) pwd;
  SQLSMALLINT db_len = SQL_NTS;  /* wcslen(db);  - not work 64 bit due to header wchar_t changed __64__ */
  SQLSMALLINT uid_len = SQL_NTS; /* wcslen(uid); - not work 64 bit due to header wchar_t changed __64__  */
  SQLSMALLINT pwd_len = SQL_NTS; /* wcslen(pwd); - not work 64 bit due to header wchar_t changed __64__  */
  /* null input */
  if (db == NULL || *(unsigned short *)db == 0) {
    db_str = (SQLWCHAR *) NULL;
    db_len = 0;
  }
  if (uid == NULL || *(unsigned short *)uid == 0) {
    uid_str = (SQLWCHAR *) NULL;
    uid_len = 0;
  }
  if (pwd == NULL || *(unsigned short *)pwd == 0) {
    pwd_str = (SQLWCHAR *) NULL;
    pwd_len = 0;
  }
  /* hdbc -- connection */
  sqlrc = SQLAllocHandle(SQL_HANDLE_DBC, henv, ohnd);
  if (sqlrc != SQL_SUCCESS) {
    return sqlrc;
  }
  hdbc = *ohnd;
  init_table_lock(hdbc, 0);
  sqlrc = SQL400SetAttr(SQL_HANDLE_DBC, *ohnd, SQL400_FLAG_PRE_CONNECT, options);
  if (sqlrc != SQL_SUCCESS) {
    init_table_unlock(hdbc, 0);
    return sqlrc;
  }
  /* connect */
  sqlrc = SQLConnectW( (SQLHDBC)*ohnd, (SQLWCHAR *)db_str, (SQLSMALLINT)db_len, (SQLWCHAR *)uid_str, (SQLSMALLINT)uid_len, (SQLWCHAR *)pwd_str, (SQLSMALLINT)pwd_len );
  if (sqlrc != SQL_SUCCESS) {
    init_table_unlock(hdbc, 0);
    return sqlrc;
  }
  sqlrc = SQL400SetAttr(SQL_HANDLE_DBC, *ohnd, SQL400_FLAG_POST_CONNECT, options);
  if (sqlrc != SQL_SUCCESS) {
    init_table_unlock(hdbc, 0);
    return sqlrc;
  }
  init_table_unlock(hdbc, 0);
  return sqlrc;
}


/*
 * excute fetch
 */

SQLRETURN custom_SQL400AddCVar(SQLSMALLINT icol, SQLSMALLINT inOutType, SQLSMALLINT pfSqlCType, SQLPOINTER pfSqlCValue, SQLINTEGER * indPtr, SQLPOINTER parms )  { 
  SQLRETURN sqlrc = SQL_SUCCESS;
  int i = 0;
  SQL400ParamStruct * opts = (SQL400ParamStruct *) parms;
  SQL400ParamStruct * opt = (SQL400ParamStruct *) NULL;
  if (opts == NULL) {
    return sqlrc;
  }
  for (i=0; opts[i].icol; i++) {}
  opt = &opts[i];
  opt->icol = icol; 
  opt->inOutType = inOutType; 
  opt->pfSqlCType = pfSqlCType; 
  opt->pfSqlCValue = pfSqlCValue;
  opt->indPtr = indPtr;
  return sqlrc;
}

SQLRETURN custom_SQL400AddDesc(SQLHSTMT hstmt, SQLSMALLINT icol, SQLSMALLINT flag, SQLPOINTER descs) { 
  SQLRETURN sqlrc = SQL_SUCCESS;
  int i = 0;
  SQL400DescStruct * opts = (SQL400DescStruct *) descs;
  SQL400DescStruct * opt = (SQL400DescStruct *) NULL;
  for (i=0; opts[i].icol; i++) {}
  opt = &opts[i];
  opt->itype= flag;
  opt->icol = icol;
  opt->szColName = (SQLCHAR *)&opt->bfColName;
  opt->cbColNameMax = 1024;
  opt->pcbColName = -1;
  switch (flag) {
  case SQL400_DESC_PARM:
    sqlrc = SQLDescribeParam((SQLHSTMT)hstmt, 
              opt->icol,
              &opt->pfSqlType, 
              &opt->pcbColDef, 
              &opt->pibScale, 
              &opt->pfNullable);
    break;
  case SQL400_DESC_COL:
    sqlrc = SQLDescribeCol((SQLHSTMT)hstmt, 
              opt->icol, 
              opt->szColName, 
              opt->cbColNameMax, 
              &opt->pcbColName, 
              &opt->pfSqlType, 
              &opt->pcbColDef, 
              &opt->pibScale, 
              &opt->pfNullable);
    break;
  }
  return sqlrc;
}


SQLRETURN custom_SQL400Execute( SQLHSTMT hstmt, SQLPOINTER parms, SQLPOINTER desc_parms ) { 
  SQLRETURN sqlrc = SQL_SUCCESS;
  int i = 0, j = 0;
  SQLSMALLINT np = 0;
  SQL400DescStruct * opts = (SQL400DescStruct *) desc_parms;
  SQL400DescStruct * opt = (SQL400DescStruct *) NULL;
  SQL400ParamStruct * prms = (SQL400ParamStruct *) parms;
  SQL400ParamStruct * prm = (SQL400ParamStruct *) NULL;
  SQLINTEGER bufferLength = 0;
  SQLSMALLINT maxFileNameLength = 0;
  SQLSMALLINT fileNameLength = 0; 
  SQLSMALLINT * fileNameLengths = (SQLSMALLINT *) &fileNameLength;
  SQLINTEGER fileOption = SQL_FILE_READ;
  SQLINTEGER * fileOptions = (SQLINTEGER *) &fileOption;

  /* bind params */
  for (i=0; opts[i].icol; i++) {
    opt = &opts[i];
    for (j=0; opt->icol != prms[j].icol; j++) {}
    prm = (SQL400ParamStruct *) &prms[j];
    switch (prm->inOutType) {
    case SQL400_PARM_IO_FILE:
      *prm->indPtr = 0;
      maxFileNameLength = fileNameLength = strlen(prm->pfSqlCValue);
      sqlrc = SQLBindFileToParam((SQLHSTMT)hstmt, 
                (SQLSMALLINT)   opt->icol, 
                (SQLSMALLINT)   prm->pfSqlCType, /* SQL_BLOB, SQL_CLOB, SQL_DBCLOB*/
                (SQLCHAR *)     prm->pfSqlCValue, 
                (SQLSMALLINT *) fileNameLengths, 
                (SQLINTEGER *)  fileOptions,
                (SQLSMALLINT)   maxFileNameLength, 
                (SQLINTEGER *)  prm->indPtr);
      break;
    default:
      sqlrc = SQLBindParameter((SQLHSTMT)hstmt, 
                (SQLSMALLINT)  opt->icol, 
                (SQLSMALLINT)  prm->inOutType,
                (SQLSMALLINT)  prm->pfSqlCType, 
                (SQLSMALLINT)  opt->pfSqlType, 
                (SQLINTEGER)   opt->pcbColDef, 
                (SQLSMALLINT)  opt->pibScale, 
                (SQLPOINTER)   prm->pfSqlCValue, 
                (SQLINTEGER)   bufferLength, 
                (SQLINTEGER *) prm->indPtr);
      break;
    }
    if (sqlrc != SQL_SUCCESS) {
      return sqlrc;
    }
  }

  /* execute */
  sqlrc = SQLExecute((SQLHSTMT) hstmt);

  return sqlrc;
}

SQLRETURN custom_SQL400Fetch( SQLHSTMT hstmt, 
 SQLINTEGER start_row, 
 SQLPOINTER cols, 
 SQLPOINTER desc_cols ) 
{ 
  SQLRETURN sqlrc = SQL_SUCCESS;
  int i = 0, j = 0;
  SQL400DescStruct * opts = (SQL400DescStruct *) desc_cols;
  SQL400DescStruct * opt = (SQL400DescStruct *) NULL;
  SQL400ParamStruct * prms = (SQL400ParamStruct *) cols;
  SQL400ParamStruct * prm = (SQL400ParamStruct *) NULL;

  /* bind columns */
  for (i=0; opts[i].icol; i++) {
    opt = &opts[i];
    for (j=0; opt->icol != prms[j].icol; j++) {}
    prm = (SQL400ParamStruct *) &prms[j];
    sqlrc = SQLBindCol((SQLHSTMT)hstmt,
              (SQLSMALLINT)   opt->icol,
              (SQLSMALLINT)   prm->pfSqlCType, 
              (SQLPOINTER)    prm->pfSqlCValue, 
              (SQLINTEGER)    opt->pcbColDef, 
              (SQLINTEGER *)  prm->indPtr);    
      if (sqlrc != SQL_SUCCESS) {
        return sqlrc;
      }
  }
  /* fetch */
  switch (start_row) {
  case 0:
    sqlrc = SQLFetch((SQLHSTMT)hstmt);
    break;
  default:
    sqlrc = SQLFetchScroll((SQLHSTMT)hstmt, SQL_FETCH_ABSOLUTE, start_row);
    break;
  }

  return sqlrc;
}


/*
 * NOT tested advanced funtion
 * (cool if it works, and async)
 */
SQLRETURN custom_SQL400Fetch_Array( SQLHSTMT hstmt, 
 SQLINTEGER start_row, 
 SQLINTEGER max_rows, 
 SQLINTEGER *cnt_rows, 
 SQLINTEGER *more_rows, 
 SQLINTEGER *cnt_cols, 
 SQLINTEGER exp_col, 
 SQLPOINTER output) 
{ 
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQL400DescStruct * opts = (SQL400DescStruct *) NULL;
  SQL400DescStruct * opt = (SQL400DescStruct *) NULL;
  SQL400ParamStruct * prms = (SQL400ParamStruct *) NULL;
  SQL400ParamStruct * prm = (SQL400ParamStruct *) NULL;
  SQLSMALLINT pccol = 0;
  SQLPOINTER pfSqlCValue = (SQLPOINTER) NULL;
  SQLINTEGER * indPtr = (SQLINTEGER *) NULL;
  SQLINTEGER expCol = 1;
  SQLHANDLE hdbc = 0;
  SQLHANDLE hstmt2 = 0, hstmt3 = 0;
  SQLINTEGER pcbColDef2 = 0, pcbColDef3 = 0;
  SQLINTEGER indPtr2 = 0, indPtr3 = 0;
  SQLINTEGER lobLoc = 0;
  SQLSMALLINT targetCType = SQL_C_CHAR;
  int c = 0, i = 0, j = 0;
  int szPtrs = 0, szOpts = 0, szPrms = 0;
  void * outPtr = (void *)NULL;
  int argc = 0;
  char ** argv = (char **)NULL;
  short iAmShort = 0;
  int iAmInt = 0;
  float iAmFloat = 0.0;
  double iAmDouble = 0.0;
  int ib = 0;
  char * ibc = (char *) NULL;
  /* number of columns in result */
  sqlrc = SQLNumResultCols(hstmt, (SQLSMALLINT *)&pccol );
  if (sqlrc != SQL_SUCCESS) {
    return sqlrc;
  }
  /* statement hdbc */
  SQL400Stmt2Hdbc(hstmt, (SQLINTEGER *)&hdbc);
  /* description of columns */
  szOpts = (pccol + 1) * sizeof(SQL400DescStruct);
  opts = (SQL400DescStruct *) malloc(szOpts);
  memset(opts,0,szOpts);
  /* loop each column */
  for (i=0; i < pccol; i++) {
    opt = (SQL400DescStruct *)&opts[i];
    sqlrc = SQL400AddDesc(hstmt, i + 1, SQL400_DESC_COL, (SQLPOINTER)opts);
    if (sqlrc != SQL_SUCCESS) {
      return sqlrc;
    }
  }
  /* output */
  if (exp_col > 0) {
    expCol = exp_col;
  }
  szPtrs = (max_rows +1) * sizeof(char *);
  outPtr = (void *)malloc(szPtrs);
  memset(outPtr,0,szOpts);
  argv = (char **) outPtr;
  /* fetch each row */
  szPrms = (pccol + 1) * sizeof(SQL400ParamStruct);
  for (c=0; c < max_rows; c++) {
    /* each row, all columns */
    prms = (SQL400ParamStruct *) malloc(szPrms);
    memset(prms,0,szPrms);
    argv[c] = (char *) prms;
    /* each column */
    for (i=0; i < pccol; i++) {
      opt = (SQL400DescStruct *)&opts[i];
      switch (opt->pfSqlType) {
      case SQL_CHAR:
      case SQL_VARCHAR:
      case SQL_UTF8_CHAR:
      case SQL_WCHAR:
      case SQL_WVARCHAR:
      /* case SQL_LONGVARCHAR: */
      /* case SQL_WLONGVARCHAR: */
        indPtr = (SQLINTEGER *)malloc(sizeof(SQLINTEGER));
        *indPtr = opt->pcbColDef * expCol + 1;
        pfSqlCValue = (SQLPOINTER) malloc(*indPtr);
        sqlrc = SQL400AddCVar(i + 1, 0, SQL_C_CHAR, (SQLPOINTER)pfSqlCValue, indPtr, (SQLPOINTER)prms);
        break;
      case SQL_GRAPHIC:
      case SQL_VARGRAPHIC:
      /* case SQL_LONGVARGRAPHIC: */
        indPtr = (SQLINTEGER *)malloc(sizeof(SQLINTEGER));
        *indPtr = (opt->pcbColDef * expCol + 1) * 2;
        pfSqlCValue = (SQLPOINTER) malloc(*indPtr);
        sqlrc = SQL400AddCVar(i + 1, 0, SQL_C_CHAR, (SQLPOINTER)pfSqlCValue, indPtr, (SQLPOINTER)prms);
        break;
      case SQL_BINARY:
      case SQL_VARBINARY:
      /* case SQL_LONGVARBINARY: */
        indPtr = (SQLINTEGER *)malloc(sizeof(SQLINTEGER));
        *indPtr = opt->pcbColDef + 1;
        pfSqlCValue = (SQLPOINTER) malloc(*indPtr);
        sqlrc = SQL400AddCVar(i + 1, 0, SQL_C_BINARY, (SQLPOINTER)pfSqlCValue, indPtr, (SQLPOINTER)prms);
        break;
      case SQL_TYPE_DATE:
      case SQL_TYPE_TIME:
      case SQL_TYPE_TIMESTAMP:
      case SQL_DATETIME:
      case SQL_DECFLOAT:
        indPtr = (SQLINTEGER *)malloc(sizeof(SQLINTEGER));
        *indPtr = opt->pcbColDef + 2;
        pfSqlCValue = (SQLPOINTER) malloc(*indPtr);
        sqlrc = SQL400AddCVar(i + 1, 0, SQL_C_CHAR, (SQLPOINTER)pfSqlCValue, indPtr, (SQLPOINTER)prms);
        break;
      case SQL_SMALLINT:
        indPtr = (SQLINTEGER *)malloc(sizeof(SQLINTEGER));
        *indPtr = sizeof(iAmFloat);
        pfSqlCValue = (SQLPOINTER) malloc(*indPtr);
        sqlrc = SQL400AddCVar(i + 1, 0, SQL_C_DEFAULT, (SQLPOINTER)pfSqlCValue, indPtr, (SQLPOINTER)prms);
        break;
      case SQL_INTEGER:
        indPtr = (SQLINTEGER *)malloc(sizeof(SQLINTEGER));
        *indPtr = sizeof(iAmInt);
        pfSqlCValue = (SQLPOINTER) malloc(*indPtr);
        sqlrc = SQL400AddCVar(i + 1, 0, SQL_C_DEFAULT, (SQLPOINTER)pfSqlCValue, indPtr, (SQLPOINTER)prms);
        break;
      case SQL_BIGINT:
        /* 9,223,372,036,854,775,807 */
        indPtr = (SQLINTEGER *)malloc(sizeof(SQLINTEGER));
        *indPtr = 20;
        pfSqlCValue = (SQLPOINTER) malloc(*indPtr);
        sqlrc = SQL400AddCVar(i + 1, 0, SQL_C_CHAR, (SQLPOINTER)pfSqlCValue, indPtr, (SQLPOINTER)prms);
        break;
      case SQL_FLOAT:
        indPtr = (SQLINTEGER *)malloc(sizeof(SQLINTEGER));
        *indPtr = sizeof(iAmFloat);
        pfSqlCValue = (SQLPOINTER) malloc(*indPtr);
        sqlrc = SQL400AddCVar(i + 1, 0, SQL_C_DEFAULT, (SQLPOINTER)pfSqlCValue, indPtr, (SQLPOINTER)prms);
        break;
      case SQL_DOUBLE:
        indPtr = (SQLINTEGER *)malloc(sizeof(SQLINTEGER));
        *indPtr = sizeof(iAmDouble);
        pfSqlCValue = (SQLPOINTER) malloc(*indPtr);
        sqlrc = SQL400AddCVar(i + 1, 0, SQL_C_DEFAULT, (SQLPOINTER)pfSqlCValue, indPtr, (SQLPOINTER)prms);
        break;
      case SQL_DECIMAL:
      case SQL_NUMERIC:
        indPtr = (SQLINTEGER *)malloc(sizeof(SQLINTEGER));
        *indPtr = opt->pcbColDef + opt->pibScale + 3;
        pfSqlCValue = (SQLPOINTER) malloc(*indPtr);
        sqlrc = SQL400AddCVar(i + 1, 0, SQL_C_CHAR, (SQLPOINTER)pfSqlCValue, indPtr, (SQLPOINTER)prms);
        break;
      case SQL_CLOB:
        indPtr = (SQLINTEGER *)malloc(sizeof(SQLINTEGER));
        *indPtr = SQL_DATA_AT_EXEC;
        pfSqlCValue = (SQLPOINTER) malloc(sizeof(iAmInt));
        sqlrc = SQL400AddCVar(i + 1, 0, SQL_CLOB_LOCATOR, (SQLPOINTER)pfSqlCValue, indPtr, (SQLPOINTER)prms);
        break;
      case SQL_DBCLOB:
        indPtr = (SQLINTEGER *)malloc(sizeof(SQLINTEGER));
        *indPtr = SQL_DATA_AT_EXEC;
        pfSqlCValue = (SQLPOINTER) malloc(sizeof(iAmInt));
        sqlrc = SQL400AddCVar(i + 1, 0, SQL_DBCLOB_LOCATOR, (SQLPOINTER)pfSqlCValue, indPtr, (SQLPOINTER)prms);
        break;
      case SQL_BLOB:
        indPtr = (SQLINTEGER *)malloc(sizeof(SQLINTEGER));
        *indPtr = SQL_DATA_AT_EXEC;
        pfSqlCValue = (SQLPOINTER) malloc(sizeof(iAmInt));
        sqlrc = SQL400AddCVar(i + 1, 0, SQL_BLOB_LOCATOR, (SQLPOINTER)pfSqlCValue, indPtr, (SQLPOINTER)prms);
        break;
      default:
        indPtr = (SQLINTEGER *)malloc(sizeof(SQLINTEGER));
        *indPtr = opt->pcbColDef * expCol + 1;
        pfSqlCValue = (SQLPOINTER) malloc(*indPtr);
        sqlrc = SQL400AddCVar(i + 1, 0, SQL_C_CHAR, (SQLPOINTER)pfSqlCValue, indPtr, (SQLPOINTER)prms);
        break;
      }
    }
    switch (start_row) {
    case 0:
      sqlrc = SQL400Fetch(hstmt, start_row, prms, opts );
      break;
    default:
      sqlrc = SQL400Fetch(hstmt, start_row + (c - 1), prms, opts );
      break;
    }
    /* SQL_DATA_AT_EXEC */
    for (i=0; i < pccol; i++) {
      opt = (SQL400DescStruct *)&opts[i];
      prms = (SQL400ParamStruct *)&prms[i];
      targetCType = SQL_C_CHAR;
      switch (opt->pfSqlType) {
      case SQL_BLOB:
        targetCType = SQL_C_BINARY;
      case SQL_CLOB:
      case SQL_DBCLOB:
        /* sizeof LOB */
        sqlrc = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt2);
        pcbColDef2 = opt->pcbColDef + 1;
        indPtr2 = 0;
        lobLoc = *(SQLINTEGER *)(prm->pfSqlCValue);
        free(prm->pfSqlCValue);
        sqlrc = SQLGetLength(hstmt2, prm->pfSqlCType, lobLoc, &pcbColDef2, &indPtr2);
        prm->pfSqlCValue = (SQLPOINTER) malloc(pcbColDef2 + 1);
        SQLFreeHandle(SQL_HANDLE_STMT, hstmt2);
        /* get LOB data */
        pcbColDef3 = -10;
        indPtr3 = 0;
        sqlrc = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt3);
        sqlrc = SQLGetSubString(hstmt3, prm->pfSqlCType, lobLoc, 1, pcbColDef2, targetCType, prm->pfSqlCValue, pcbColDef2, &pcbColDef3, &indPtr3);
        SQLFreeHandle(SQL_HANDLE_STMT, hstmt3);
        /* trim DBCLOB */
        ib = pcbColDef3;
        if (pcbColDef3 > 0 && lobLoc == SQL_DBCLOB_LOCATOR) {
          ib = pcbColDef3 - 1;
          ibc = (char *) prm->pfSqlCValue;
          for (; ib && (ibc[ib] == 0x00 || ibc[ib] == 0x20); ib--) ibc[ib] = '\0';
        }
        *(prm->indPtr) = ib;
        break;
      default:
       break;
      }
    }
  } /* end c (rows) */
  return sqlrc;
}


void utf8_iconv_open(int myccsid, int utfccsid) {
  if (!utf8_charset_flag) {
    utf8_charset_Ascii = ccsidtocs(myccsid);
    utf8_charset_Utf = ccsidtocs(utfccsid);
    utf8_AsciiToUtf = iconv_open(utf8_charset_Utf, utf8_charset_Ascii);
    utf8_UtfToAscii = iconv_open(utf8_charset_Ascii, utf8_charset_Utf);
    utf8_charset_flag = 1;
  }
}
SQLRETURN utf8_iconv(int isInput, char *fromBuffer, char *toBuffer, size_t sourceLen, size_t bufSize) {
 int rc = 0;
 char *source = fromBuffer;
 char *target = toBuffer;
 size_t sourceBytesLeft = sourceLen;
 size_t targetBytesLeft = bufSize;

 if (isInput) {
  rc = iconv(utf8_AsciiToUtf, (char**)(&source), &sourceBytesLeft, &target, &targetBytesLeft);
 } else {
  rc = iconv(utf8_UtfToAscii, (char**)(&source), &sourceBytesLeft, &target, &targetBytesLeft);
 }
 return rc;
}
void utf8_iconv_close() {
  if (utf8_charset_flag) {
    (void)iconv_close(utf8_AsciiToUtf);
    (void)iconv_close(utf8_UtfToAscii);
    utf8_charset_flag = 0;
  }
}

void utf16_iconv_open(int myccsid, int utfccsid) {
  if (!utf16_charset_flag) {
    utf16_charset_Ascii = ccsidtocs(myccsid);
    utf16_charset_Utf = ccsidtocs(utfccsid);
    utf16_AsciiToUtf = iconv_open(utf16_charset_Utf, utf16_charset_Ascii);
    utf16_UtfToAscii = iconv_open(utf16_charset_Ascii, utf16_charset_Utf);
    utf16_charset_flag = 1;
  }
}
SQLRETURN utf16_iconv(int isInput, char *fromBuffer, char *toBuffer, size_t sourceLen, size_t bufSize) {
 int rc = 0;
 char *source = fromBuffer;
 char *target = toBuffer;
 size_t sourceBytesLeft = sourceLen;
 size_t targetBytesLeft = bufSize;

 memset(toBuffer,0,bufSize);
 if (isInput) {
  rc = iconv(utf16_AsciiToUtf, (char**)(&source), &sourceBytesLeft, &target, &targetBytesLeft);
 } else {
  rc = iconv(utf16_UtfToAscii, (char**)(&source), &sourceBytesLeft, &target, &targetBytesLeft);
 }
 return rc;
}
void utf16_iconv_close() {
  if (utf16_charset_flag) {
    (void)iconv_close(utf16_AsciiToUtf);
    (void)iconv_close(utf16_UtfToAscii);
    utf16_charset_flag = 0;
  }
}


SQLRETURN custom_SQL400ToUtf8( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  inccsid ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  utf8_iconv_open(inccsid, 1208);
  sqlrc = utf8_iconv(1, inparm, outparm, inlen, outlen);
  return sqlrc;
}
SQLRETURN custom_SQL400FromUtf8( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  outccsid ){
  SQLRETURN sqlrc = SQL_SUCCESS;
  utf8_iconv_open(outccsid, 1208);
  sqlrc = utf8_iconv(0, inparm, outparm, inlen, outlen);
  return sqlrc;
}
SQLRETURN custom_SQL400ToUtf16( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  inccsid ){
  SQLRETURN sqlrc = SQL_SUCCESS;
  utf16_iconv_open(inccsid, 1200);
  sqlrc = utf16_iconv(1, inparm, outparm, inlen, outlen);
  return sqlrc;
}
SQLRETURN custom_SQL400FromUtf16( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  outccsid ){
  SQLRETURN sqlrc = SQL_SUCCESS;
  utf16_iconv_open(outccsid, 1200);
  sqlrc = utf16_iconv(0, inparm, outparm, inlen, outlen);
  return sqlrc;
}


