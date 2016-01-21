#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dlfcn.h>
#include <sqlcli1.h>
#include "PaseCliInit.h"
#include "PaseCliAsync.h"

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
        /* SQLRETURN SQLOverrideCCSID400 ( int  newCCSID ) */
        case SQL400_ATTR_CCSID:
          opt->sqlrc = SQLOverrideCCSID400((int)opt->vParam);
          if (opt->onerr == SQL400_ONERR_STOP) {
            return opt->sqlrc;
          }
          break;
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
  SQLSMALLINT db_len = strlen(db);
  SQLSMALLINT uid_len = strlen(uid);
  SQLSMALLINT pwd_len = strlen(pwd);
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
  sqlrc = SQLConnect( (SQLHDBC)*ohnd, (SQLCHAR *)db, (SQLSMALLINT)db_len, (SQLCHAR *)uid, (SQLSMALLINT)uid_len, (SQLCHAR *)pwd, (SQLSMALLINT)pwd_len );
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

SQLRETURN custom_SQL400AddCParam(SQLSMALLINT icol, SQLSMALLINT inOutType, SQLSMALLINT pfSqlCType, SQLPOINTER pfSqlCValue, SQLINTEGER * indPtr, SQLPOINTER parms )  { 
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
  if (start_row) {
    sqlrc = SQLFetchScroll((SQLHSTMT)hstmt, SQL_FETCH_ABSOLUTE, start_row);
  } else {
    sqlrc = SQLFetch((SQLHSTMT)hstmt);
  }

  return sqlrc;
}




/* need data
  SQLParamData() returns SQL_NEED_DATA if there is at least one 
  SQL_DATA_AT_EXEC parameter for which data still has not been assigned.
  The application calls SQLPutData() after calling SQLParamData() on a 
  statement in the SQL_NEED_DATA state to supply the data values 
  for an SQL_DATA_AT_EXEC parameter. 
  */
  /*
	if ( rc == SQL_NEED_DATA ) {
    while ( (rc = (SQLParamData((SQLHSTMT)hstmt, (SQLPOINTER *)&valuePtr))) == SQL_NEED_DATA ) {
      rc = SQLPutData((SQLHSTMT)hstmt, (SQLPOINTER)valuePtr, );
    }
  }
*/


/* fetch

rc = SQLNumResultCols((SQLHSTMT)stmt_res->hstmt, &nResultCols);

	for (i = 0 ; i < nResultCols; i++) {
		stmt_res->column_info[i].lob_loc = 0;
		stmt_res->column_info[i].loc_ind = 0;
		stmt_res->column_info[i].loc_type = 0;

		rc = SQLDescribeCol((SQLHSTMT)stmt_res->hstmt, (SQLSMALLINT)(i + 1 ),
			(SQLCHAR *)&tmp_name, BUFSIZ, &name_length, &stmt_res->column_info[i].type,
			&stmt_res->column_info[i].size, &stmt_res->column_info[i].scale,
			&stmt_res->column_info[i].nullable);

				rc = SQLBindCol((SQLHSTMT)stmt_res->hstmt, (SQLUSMALLINT)(i + 1),
					target_type, row_data->str_val, in_length,
					(SQLINTEGER *)(&stmt_res->row_data[i].out_length));

rc = SQLFetchScroll((SQLHSTMT)stmt_res->hstmt, SQL_FETCH_ABSOLUTE, row_number);

SQLRETURN   SQLExtendedFetch (SQLHSTMT          StatementHandle,
                              SQLSMALLINT       FetchOrientation,
                              SQLINTEGER        FetchOffset,
                              SQLINTEGER        *RowCountPtr,
                              SQLSMALLINT       *RowStatusArray);

rc = SQLFetch((SQLHSTMT)stmt_res->hstmt);

  rc = SQLGetData((SQLHSTMT)stmt_res->hstmt, col_num, ctype, buff, in_length, out_length);


  lobs:
	rc = SQLGetLength((SQLHSTMT)new_hstmt, stmt_res->column_info[col_num-1].loc_type,
				stmt_res->column_info[col_num-1].lob_loc, sLength,
				&stmt_res->column_info[col_num-1].loc_ind);
	rc = SQLGetSubString((SQLHSTMT)new_hstmt, stmt_res->column_info[col_num-1].loc_type,
				stmt_res->column_info[col_num-1].lob_loc, 1, read_length, targetCType,
				buff, buff_length, out_length, &stmt_res->column_info[col_num-1].loc_ind);

*/

