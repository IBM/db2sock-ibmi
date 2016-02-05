#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dlfcn.h>
#include <iconv.h>
#include <sqlcli1.h>
#include "PaseCliInit.h"
#include "PaseCliAsync.h"

/* === experimental (not finished) ===
 * This module has fancy 'big helper' APIs.
 *
 * Goal enable many operatins in one async call. Similar to
 * scripting APIs, one new SQL400xxx API (not CLI), many CLI calls
 * set attributes, bind columns, etc.
 *
 * Warning: 
 * Many bugs still here. Development is trial and error,
 * so don't exepct these APIs to be solid until this
 * warning is removed.
 */

static SQLHANDLE env_hndl;

/*
 * utilities
 */ 

int custom_trim_CVAR(SQL400ParamStruct * prm) {
  int ib = 0;
  char * ibc = (char *) NULL;

  if (prm->indPtr) {
    ib = *(prm->indPtr);
    if (ib > 0) {
      ib = *(prm->indPtr) - 1;
      ibc = (char *) prm->pfSqlCValue;
      for (; ib && (ibc[ib] == 0x00 || ibc[ib] == 0x20); ib--) ibc[ib] = '\0';
    }
    *(prm->indPtr) = ib;
  }
}


SQLRETURN custom_SQL400ToUtf8( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  inccsid ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = custom_iconv(1, inparm, outparm, inlen, outlen, inccsid, 1208);
  return sqlrc;
}
SQLRETURN custom_SQL400FromUtf8( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  outccsid ){
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = custom_iconv(0, inparm, outparm, inlen, outlen, outccsid, 1208);
  return sqlrc;
}
SQLRETURN custom_SQL400ToUtf16( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  inccsid ){
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = custom_iconv(1, inparm, outparm, inlen, outlen, inccsid, 1200);
  return sqlrc;
}
SQLRETURN custom_SQL400FromUtf16( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  outccsid ){
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = custom_iconv(0, inparm, outparm, inlen, outlen, outccsid, 1200);
  return sqlrc;
}

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

SQLRETURN custom_SQL400Cmd(SQLHDBC hdbc, SQLCHAR * cmd)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLHSTMT hstmt = 0;
  int cmd_len = strlen(cmd);
  char *len_string= (char *) NULL;
  int len_len = 0;
  char *query_string= (char *) NULL;
  int query_len = 0;
  /* setup call to QSYS2/QCMDEXC('cmd',cmdlength) */
  if (!cmd_len) {
    return SQL_ERROR;
  }
  len_string = custom_alloc_zero(40);
  len_len = sprintf(len_string, "%d", cmd_len);
  query_len = 23 + cmd_len + len_len ;
  query_string = custom_alloc_zero(query_len);
  strcpy(query_string, "CALL QSYS2.QCMDEXC('");
  strcat(query_string, cmd);
  strcat(query_string, "',");
  strcat(query_string, len_string);
  strcat(query_string, ")");
  /* make call */
  sqlrc = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
  if ( sqlrc == SQL_SUCCESS ) {
    sqlrc = SQLExecDirect(hstmt, query_string, query_len);
    SQLFreeHandle( SQL_HANDLE_STMT, hstmt );
  }
  free(len_string);
  free(query_string);
  return sqlrc;
}

SQLRETURN custom_SQL400ChgLibl(SQLHDBC hdbc, SQLCHAR * libl)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int in_len = strlen(libl);
  char *cmd_string= (char *) NULL;
  int cmd_len = 0;
  /* setup CHGLIBL LIBL(QGPL QTEMP QDEVELOP QBLDSYS QBLDSYSR) */
  if (!in_len) {
    return SQL_ERROR;
  }
  cmd_len = 15 + in_len;
  cmd_string = custom_alloc_zero(cmd_len);
  strcpy(cmd_string, "CHGLIBL LIBL(");
  strcat(cmd_string, libl);
  strcat(cmd_string, ")");
  /* make call */
  sqlrc = custom_SQL400Cmd(hdbc, cmd_string);
  free(cmd_string);
  return sqlrc;
}
SQLRETURN custom_SQL400ChgCurLib(SQLHDBC hdbc, SQLCHAR * curlib)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int in_len = strlen(curlib);
  char *cmd_string= (char *) NULL;
  int cmd_len = 0;
  /* setup CHGCURLIB CURLIB(FROG) */
  if (!in_len) {
    return SQL_ERROR;
  }
  cmd_len = 19 + in_len;
  cmd_string = custom_alloc_zero(cmd_len);
  strcpy(cmd_string, "CHGCURLIB CURLIB(");
  strcat(cmd_string, curlib);
  strcat(cmd_string, ")");
  /* make call */
  sqlrc = custom_SQL400Cmd(hdbc, cmd_string);
  free(cmd_string);
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

SQLRETURN custom_SQL400SetAttrBoth( SQLINTEGER  scope, SQLHANDLE hndl, SQLINTEGER  flag, SQLPOINTER  options, SQLSMALLINT iswide) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  int i = 0;
  SQL400AttrStruct * opts = (SQL400AttrStruct *) options;
  SQL400AttrStruct * opt = (SQL400AttrStruct *) NULL;
  if (opts == NULL) {
    return sqlrc;
  }
  for (i=0; opts[i].scope; i++) {
    opt = &opts[i];
    /*
     * SQL400_FLAG_IMMED        -- apply now
     * SQL400_FLAG_POST_CONNECT -- after connect
     */
    if (opt->flag != flag) {
      continue;
    }
    switch (opt->scope) {
    case SQL_HANDLE_ENV:
      /* SQLRETURN SQLSetEnvAttr ( SQLHENV  henv; SQLINTEGER  Attribute; SQLPOINTER  Value; SQLINTEGER StringLength ) */
      if (scope == SQL_HANDLE_ENV ) {
        switch (opt->attrib) {
        default:
          opt->sqlrc = SQLSetEnvAttr((SQLHENV)hndl, (SQLINTEGER)opt->attrib, (SQLPOINTER)opt->vParam, (SQLINTEGER) opt->inlen);
          if (opt->sqlrc == SQL_ERROR && opt->onerr == SQL400_ONERR_STOP) {
            return opt->sqlrc;
          }
          break;
        }
      }
      break;
    case SQL_HANDLE_DBC:
      /* SQLRETURN SQLSetConnectAttr ( SQLHDBC  hdbc, SQLINTEGER  attrib, SQLPOINTER  vParam, SQLINTEGER  inlen ) */
      if (scope == SQL_HANDLE_DBC ) {
        switch (opt->attrib) {
        case SQL400_ATTR_CONN_CHGLIBL:
          opt->sqlrc = custom_SQL400ChgLibl((SQLHDBC)hndl, (SQLCHAR *) opt->vParam);
          break;
        case SQL400_ATTR_CONN_CHGCURLIB:
          opt->sqlrc = custom_SQL400ChgCurLib((SQLHDBC)hndl, (SQLCHAR *) opt->vParam);
          break;
        default:
          switch (iswide) {
          case 1:
            opt->sqlrc = SQLSetConnectAttrW((SQLHDBC)hndl, (SQLINTEGER)opt->attrib, (SQLPOINTER)opt->vParam, (SQLINTEGER) opt->inlen);
            break;
          default:
            opt->sqlrc = SQLSetConnectAttr((SQLHDBC)hndl, (SQLINTEGER)opt->attrib, (SQLPOINTER)opt->vParam, (SQLINTEGER) opt->inlen);
            break;
          }
          if (opt->sqlrc == SQL_ERROR && opt->onerr == SQL400_ONERR_STOP) {
            return opt->sqlrc;
          }
        }
      }
      break;
    case SQL_HANDLE_STMT:
      /* SQLRETURN SQLSetStmtAttr ( SQLHSTMT  hstmt, SQLINTEGER  fAttr, SQLPOINTER  pParam, SQLINTEGER  vParam ) */
      if (scope == SQL_HANDLE_STMT ) {
        switch (opt->attrib) {
        default:
          switch (iswide) {
          case 1:
            opt->sqlrc = SQLSetStmtAttr((SQLHSTMT)hndl, (SQLINTEGER)opt->attrib, (SQLPOINTER)opt->vParam, (SQLINTEGER) opt->inlen);
            break;
          default:
            opt->sqlrc = SQLSetStmtAttr((SQLHSTMT)hndl, (SQLINTEGER)opt->attrib, (SQLPOINTER)opt->vParam, (SQLINTEGER) opt->inlen);
            break;
          }
          if (opt->sqlrc == SQL_ERROR && opt->onerr == SQL400_ONERR_STOP) {
            return opt->sqlrc;
          }
          break;
        }
      }
      break;
    case SQL_HANDLE_DESC:
      /* SQLRETURN SQLSetStmtOption( SQLHSTMT hstmt, SQLSMALLINT fOption, SQLPOINTER vParam ) */
      if (scope == SQL_HANDLE_DESC ) {
        switch (opt->attrib) {
        default:
          switch (iswide) {
          case 1:
            opt->sqlrc = SQLSetStmtOptionW((SQLHSTMT)hndl, (SQLINTEGER)opt->attrib, (SQLPOINTER)opt->vParam );
            break;
          default:
            opt->sqlrc = SQLSetStmtOption((SQLHSTMT)hndl, (SQLINTEGER)opt->attrib, (SQLPOINTER)opt->vParam );
            break;
          }
          if (opt->sqlrc == SQL_ERROR && opt->onerr == SQL400_ONERR_STOP) {
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
SQLRETURN custom_SQL400SetAttr( SQLINTEGER  scope, SQLHANDLE hndl, SQLINTEGER  flag, SQLPOINTER  options ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = custom_SQL400SetAttrBoth(scope, hndl, flag, options, 0);
  return sqlrc;
}
SQLRETURN custom_SQL400SetAttrW( SQLINTEGER  scope, SQLHANDLE hndl, SQLINTEGER  flag, SQLPOINTER  options ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = custom_SQL400SetAttrBoth(scope, hndl, flag, options, 1);
  return sqlrc;
}




/*
 * env 
 */
SQLRETURN custom_SQLOverrideCCSID400( SQLINTEGER  newCCSID ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLINTEGER yes = SQL_TRUE;
  int myccsid = 0;
  if (!env_hndl) {
    myccsid = init_CCSID400(newCCSID);
    switch(myccsid) {
    case 1208: /* UTF-8 */
      sqlrc = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env_hndl);
      sqlrc = SQLSetEnvAttr((SQLHENV)env_hndl, (SQLINTEGER)SQL400_ATTR_PASE_CCSID, (SQLPOINTER)&myccsid, (SQLINTEGER) 0);
      sqlrc = SQLSetEnvAttr((SQLHENV)env_hndl, (SQLINTEGER)SQL_ATTR_UTF8, (SQLPOINTER)&yes, (SQLINTEGER) 0);
      break;
    case 1200: /* UTF-16 */
      sqlrc = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env_hndl);
      break;
    default:
      libdb400_SQLOverrideCCSID400( newCCSID );
      sqlrc = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env_hndl);
      break;
    }
  }
  return sqlrc;
}

SQLRETURN custom_SQL400Environment( SQLINTEGER * ohnd, SQLPOINTER  options ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  /* henv -- IBM i only one env (always 1) */
  sqlrc = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, ohnd);
  sqlrc = custom_SQL400SetAttr(SQL_HANDLE_ENV, *ohnd, SQL400_FLAG_IMMED, options);
  if (sqlrc != SQL_SUCCESS) {
    return sqlrc;
  }
  return sqlrc;
}


/*
 * connect
 */

SQLRETURN custom_SQL400ConnectBoth( SQLHENV  henv, SQLCHAR * db, SQLCHAR * uid, SQLCHAR * pwd, SQLCHAR * qual, SQLINTEGER * ohnd, SQLPOINTER  options, SQLSMALLINT iswide, SQLSMALLINT isPersistent) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  int i = 0;
  SQLHDBC hdbc = 0;
  SQLCHAR * db_str = (SQLCHAR *) db;
  SQLCHAR * uid_str = (SQLCHAR *) uid;
  SQLCHAR * pwd_str = (SQLCHAR *) pwd;
  SQLSMALLINT db_len = SQL_NTS;
  SQLSMALLINT uid_len = SQL_NTS;
  SQLSMALLINT pwd_len = SQL_NTS;
  int db_slen = strlen(db);
  int uid_slen = strlen(uid);
  int pwd_slen = strlen(pwd);

  /* nothing open, so far */
  *ohnd = 0;

  switch(iswide) {
  case 1:
    db_slen = custom_strlen_utf16((unsigned int*)db);  /* wcslen(db);  - not work 64 bit due to header wchar_t changed __64__ */
    uid_slen = custom_strlen_utf16((unsigned int*)uid); /* wcslen(uid); - not work 64 bit due to header wchar_t changed __64__  */
    pwd_slen = custom_strlen_utf16((unsigned int*)pwd); /* wcslen(pwd); - not work 64 bit due to header wchar_t changed __64__  */
    break;
  default:
    db_slen = strlen(db);
    uid_slen = strlen(uid);
    pwd_slen = strlen(pwd);
    break;
  }
  /* null input */
  if (db == NULL || !db_slen) {
    db_str = (SQLCHAR *) NULL;
    db_len = 0;
  }
  if (uid == NULL || !uid_slen) {
    uid_str = (SQLCHAR *) NULL;
    uid_len = 0;
  }
  if (pwd == NULL || !pwd_slen) {
    pwd_str = (SQLCHAR *) NULL;
    pwd_len = 0;
  }
  /* possible persistent connection */
  if (isPersistent) {
    switch(iswide) {
    case 1:
      *ohnd = init_table_hash_2_conn_W((unsigned int*)db, (unsigned int*)uid, (unsigned int*)pwd, (unsigned int*)qual);
      break;
    default:
      *ohnd = init_table_hash_2_conn((char *)db, (char *)uid, (char *)pwd, (char *)qual);
      break;
    }
  }
  hdbc = *ohnd;
  /* open a connection */
  if (hdbc < 2) {
    /* hdbc -- connection */
    sqlrc = SQLAllocHandle(SQL_HANDLE_DBC, henv, ohnd);
    if (sqlrc != SQL_SUCCESS) {
      return sqlrc;
    }
    hdbc = *ohnd;
    init_table_lock(hdbc, 0);
    /* pre connection */
    switch(iswide) {
    case 1:
      sqlrc = custom_SQL400SetAttrW(SQL_HANDLE_DBC, *ohnd, SQL400_FLAG_IMMED, options);
      break;
    default:
      sqlrc = custom_SQL400SetAttr(SQL_HANDLE_DBC, *ohnd, SQL400_FLAG_IMMED, options);
      break;
    }
    if (sqlrc != SQL_SUCCESS) {
      init_table_unlock(hdbc, 0);
      return sqlrc;
    }
    /* connect */
    switch(iswide) {
    case 1:
      sqlrc = SQLConnectW( (SQLHDBC)*ohnd, (SQLWCHAR *)db_str, (SQLSMALLINT)db_len, (SQLWCHAR *)uid_str, (SQLSMALLINT)uid_len, (SQLWCHAR *)pwd_str, (SQLSMALLINT)pwd_len );
      break;
    default:
      sqlrc = SQLConnect( (SQLHDBC)*ohnd, (SQLCHAR *)db_str, (SQLSMALLINT)db_len, (SQLCHAR *)uid_str, (SQLSMALLINT)uid_len, (SQLCHAR *)pwd_str, (SQLSMALLINT)pwd_len );
      break;
    }
    if (sqlrc != SQL_SUCCESS) {
      init_table_unlock(hdbc, 0);
      return sqlrc;
    }
    /* possible persistent connection */
    if (isPersistent) {
      switch(iswide) {
      case 1:
        init_table_add_hash_W(hdbc, (unsigned int*)db, (unsigned int*)uid, (unsigned int*)pwd, (unsigned int*)qual, 0);
        break;
      default:
        init_table_add_hash(hdbc, db, uid, pwd, qual, 0);
        break;
      }
    }
  } else {
    init_table_lock(hdbc, 0);
  }
  /* post connection */
  switch(iswide) {
  case 1:
    sqlrc = custom_SQL400SetAttrW(SQL_HANDLE_DBC, *ohnd, SQL400_FLAG_POST_CONNECT, options);
    break;
  default:
    sqlrc = custom_SQL400SetAttr(SQL_HANDLE_DBC, *ohnd, SQL400_FLAG_POST_CONNECT, options);
    break;
  }
  if (sqlrc != SQL_SUCCESS) {
    init_table_unlock(hdbc, 0);
    return sqlrc;
  }
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
SQLRETURN custom_SQL400Connect( SQLHENV  henv, SQLCHAR * db, SQLCHAR * uid, SQLCHAR * pwd, SQLINTEGER * ohnd, SQLPOINTER  options ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = custom_SQL400ConnectBoth( henv, db, uid, pwd, NULL, ohnd, options, 0, 0);
  return sqlrc;
}
SQLRETURN custom_SQL400ConnectW( SQLHENV  henv, SQLWCHAR * db, SQLWCHAR * uid, SQLWCHAR * pwd, SQLINTEGER * ohnd, SQLPOINTER  options ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = custom_SQL400ConnectBoth( henv, (SQLCHAR *)db, (SQLCHAR *)uid, (SQLCHAR *)pwd, NULL, ohnd, options, 1, 0);
  return sqlrc;
}
SQLRETURN custom_SQL400pConnect( SQLHENV  henv, SQLCHAR * db, SQLCHAR * uid, SQLCHAR * pwd, SQLCHAR * qual, SQLINTEGER * ohnd, SQLPOINTER  options ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = custom_SQL400ConnectBoth( henv, db, uid, pwd, qual, ohnd, options, 0, 1);
  return sqlrc;
}
SQLRETURN custom_SQL400pConnectW( SQLHENV  henv, SQLWCHAR * db, SQLWCHAR * uid, SQLWCHAR * pwd, SQLCHAR * qual, SQLINTEGER * ohnd, SQLPOINTER  options ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = custom_SQL400ConnectBoth( henv, (SQLCHAR *)db, (SQLCHAR *)uid, (SQLCHAR *)pwd, qual, ohnd, options, 1, 1);
  return sqlrc;
}


SQLRETURN custom_SQL400CloseBoth(SQLHDBC hdbc) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  int auto_commit = 0;
  init_table_dtor(hdbc);
  sqlrc = SQLGetConnectAttr(hdbc, SQL_ATTR_AUTOCOMMIT, &auto_commit, 0, NULL);
  if (!auto_commit) {
    sqlrc = SQLEndTran(SQL_HANDLE_DBC, hdbc, SQL_ROLLBACK);
  }
  sqlrc = SQLDisconnect(hdbc);
  sqlrc = SQLFreeConnect(hdbc);
  return sqlrc;
}

SQLRETURN custom_SQL400Close(SQLHDBC hdbc) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  int auto_commit = 0;
  int active = init_table_hash_active(hdbc, 0);
  /* persistent connect only close with SQL400pClose */
  if (active) {
    return SQL_ERROR;
  }
  return custom_SQL400CloseBoth(hdbc);
}


SQLRETURN custom_SQL400pClose(SQLHDBC hdbc) {
  return custom_SQL400CloseBoth(hdbc);
}


/*
 * SQL describe descriptions (parm or result)
 */

SQLRETURN custom_SQL400AddDescBoth(SQLHSTMT hstmt, SQLSMALLINT icol, SQLSMALLINT flag, SQLPOINTER descs, SQLSMALLINT iswide) { 
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
    switch (iswide) {
    case 1:
      sqlrc = SQLDescribeColW((SQLHSTMT)hstmt, 
              opt->icol, 
              (SQLWCHAR *)opt->szColName, 
              opt->cbColNameMax, 
              &opt->pcbColName, 
              &opt->pfSqlType, 
              &opt->pcbColDef, 
              &opt->pibScale, 
              &opt->pfNullable);
      break;
    default:
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
    break;
  }
  return sqlrc;
}
SQLRETURN custom_SQL400AddDesc(SQLHSTMT hstmt, SQLSMALLINT icol, SQLSMALLINT flag, SQLPOINTER descs) { 
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = custom_SQL400AddDescBoth(hstmt, icol, flag, descs, 0);
  return sqlrc;
}
SQLRETURN custom_SQL400AddDescW(SQLHSTMT hstmt, SQLSMALLINT icol, SQLSMALLINT flag, SQLPOINTER descs) { 
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = custom_SQL400AddDescBoth(hstmt, icol, flag, descs, 1);
  return sqlrc;
}


/*
 * SQL describe parameter descriptions
 */


SQLRETURN custom_SQL400AddCParmDescBoth(SQLHSTMT hstmt,
 SQLSMALLINT * pccol,
 SQLPOINTER * out_opts,
 SQLSMALLINT iswide) 
{ 
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQL400DescStruct * opts = (SQL400DescStruct *) NULL;
  SQL400DescStruct * opt = (SQL400DescStruct *) NULL;
  int i = 0;
  int szOpts = 0;
  /* number paramters */
  sqlrc = SQLNumParams(hstmt, (SQLSMALLINT *)pccol);
  if (sqlrc != SQL_SUCCESS) {
    return sqlrc;
  }
  /* description of columns */
  szOpts = (*pccol + 1) * sizeof(SQL400DescStruct);
  opts = (SQL400DescStruct *) custom_alloc_zero(szOpts);
  *out_opts = (SQLPOINTER) opts;
  /* loop each column */
  for (i=0; i < *pccol; i++) {
    opt = (SQL400DescStruct *)&opts[i];
    sqlrc = custom_SQL400AddDescBoth(hstmt, i + 1, SQL400_DESC_PARM, (SQLPOINTER)opts, iswide);
    if (sqlrc != SQL_SUCCESS) {
      return sqlrc;
    }
  }
  return sqlrc;
}
SQLRETURN custom_SQL400AddCParmDesc(SQLHSTMT hstmt,
 SQLSMALLINT * pccol,
 SQLPOINTER * out_opts) 
{ 
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = custom_SQL400AddCParmDescBoth(hstmt, pccol, out_opts, 0);
  return sqlrc;
}
SQLRETURN custom_SQL400AddCParmDescW(SQLHSTMT hstmt,
 SQLSMALLINT * pccol,
 SQLPOINTER * out_opts) 
{ 
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = custom_SQL400AddCParmDescBoth(hstmt, pccol, out_opts, 1);
  return sqlrc;
}


/*
 * SQL describe result descriptions
 */

SQLRETURN custom_SQL400AddCResultDescBoth(SQLHSTMT hstmt,
 SQLSMALLINT * pccol,
 SQLPOINTER * out_opts,
 SQLSMALLINT iswide) 
{ 
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQL400DescStruct * opts = (SQL400DescStruct *) NULL;
  SQL400DescStruct * opt = (SQL400DescStruct *) NULL;
  int i = 0;
  int szOpts = 0;
  /* number of columns in result */
  sqlrc = SQLNumResultCols(hstmt, (SQLSMALLINT *)pccol);
  if (sqlrc != SQL_SUCCESS) {
    return sqlrc;
  }
  /* description of columns */
  szOpts = (*pccol + 1) * sizeof(SQL400DescStruct);
  opts = (SQL400DescStruct *) custom_alloc_zero(szOpts);
  *out_opts = (SQLPOINTER) opts;
  /* loop each column */
  for (i=0; i < *pccol; i++) {
    opt = (SQL400DescStruct *)&opts[i];
    sqlrc = custom_SQL400AddDescBoth(hstmt, i + 1, SQL400_DESC_COL, (SQLPOINTER)opts, iswide);
    if (sqlrc != SQL_SUCCESS) {
      return sqlrc;
    }
  }
  return sqlrc;
}
SQLRETURN custom_SQL400AddCResultDesc(SQLHSTMT hstmt,
 SQLSMALLINT * pccol,
 SQLPOINTER * out_opts) 
{ 
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = custom_SQL400AddCResultDescBoth(hstmt, pccol, out_opts, 0);
  return sqlrc;
}
SQLRETURN custom_SQL400AddCResultDescW(SQLHSTMT hstmt,
 SQLSMALLINT * pccol,
 SQLPOINTER * out_opts) 
{ 
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = custom_SQL400AddCResultDescBoth(hstmt, pccol, out_opts, 1);
  return sqlrc;
}

/*
 * C host variables
 */

SQLRETURN custom_SQL400AddCVar(SQLSMALLINT icol, SQLSMALLINT inOutType, SQLSMALLINT pfSqlCType, SQLPOINTER pfSqlCValue, SQLINTEGER * indPtr, SQLPOINTER parms)  { 
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

SQLRETURN custom_SQL400AddCVarAnyBoth(SQLSMALLINT nbrcols,
 SQLPOINTER descs,
 SQLPOINTER cparms,
 SQLINTEGER expand_factor,
 SQLSMALLINT targetCType,
 SQLSMALLINT iswide,
 SQLSMALLINT flag,
 SQLPOINTER * in_parms,
 SQLINTEGER * in_parms_len,
 SQLSMALLINT * in_parms_ctype)
{ 
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLINTEGER * indPtr = (SQLINTEGER *) NULL;
  SQL400DescStruct * opts = (SQL400DescStruct *)descs;
  SQL400ParamStruct * prms = (SQL400ParamStruct *)cparms;
  SQL400DescStruct * opt = (SQL400DescStruct *) NULL;
  SQL400ParamStruct * prm = (SQL400ParamStruct *) NULL;
  SQLPOINTER pfSqlCValue = (SQLPOINTER) NULL;
  SQLSMALLINT defaultCType = SQL_C_CHAR;
  SQLSMALLINT parmCType = SQL_C_DEFAULT;
  int c = 0, i = 0, j = 0;
  short iAmShort = 0;
  int iAmInt = 0;
  float iAmFloat = 0.0;
  double iAmDouble = 0.0;
  long long iAmBigInt = 0.0;
  /* each column */
  switch(iswide) {
  case 1:
    defaultCType = SQL_C_WCHAR;
    break;
  default:
    defaultCType = SQL_C_CHAR;
    break;
  }
  for (i=0; i < nbrcols; i++) {
    opt = (SQL400DescStruct *)&opts[i];
    switch (flag) {
    case SQL400_DESC_PARM:
      indPtr = (SQLINTEGER *)custom_alloc_zero(sizeof(SQLINTEGER));
      *indPtr = in_parms_len[i];
      parmCType = in_parms_ctype[i];
      pfSqlCValue = in_parms[i];
      break;
    default:
      indPtr = (SQLINTEGER *)custom_alloc_zero(sizeof(SQLINTEGER));
      pfSqlCValue = (SQLPOINTER) NULL;
      parmCType = SQL_C_DEFAULT;
      break;
    }
    switch (opt->pfSqlType) {
    case SQL_CHAR:
    case SQL_VARCHAR:
    case SQL_UTF8_CHAR:
    case SQL_WCHAR:
    case SQL_WVARCHAR:
    /* case SQL_LONGVARCHAR: */
    /* case SQL_WLONGVARCHAR: */
      switch (flag) {
      case SQL400_DESC_PARM:
        sqlrc = custom_SQL400AddCVar(i + 1, 0, parmCType, (SQLPOINTER)pfSqlCValue, indPtr, (SQLPOINTER)prms);
        break;
      default:
        switch (targetCType) {
        case SQL_C_WCHAR:
          *indPtr = (opt->pcbColDef * expand_factor + 1) * 2;
          pfSqlCValue = (SQLPOINTER) custom_alloc_zero(*indPtr);
          sqlrc = custom_SQL400AddCVar(i + 1, 0, SQL_C_WCHAR, (SQLPOINTER)pfSqlCValue, indPtr, (SQLPOINTER)prms);
          break;
        default:
          *indPtr = opt->pcbColDef * expand_factor + 1;
          if (defaultCType == SQL_C_WCHAR) {
            *indPtr = *indPtr * 2;
          }
          pfSqlCValue = (SQLPOINTER) custom_alloc_zero(*indPtr);
          sqlrc = custom_SQL400AddCVar(i + 1, 0, defaultCType, (SQLPOINTER)pfSqlCValue, indPtr, (SQLPOINTER)prms);
          break;
        }
        break;
      }
      break;
    case SQL_GRAPHIC:
    case SQL_VARGRAPHIC:
    /* case SQL_LONGVARGRAPHIC: */
      switch (flag) {
      case SQL400_DESC_PARM:
        sqlrc = custom_SQL400AddCVar(i + 1, 0, parmCType, (SQLPOINTER)pfSqlCValue, indPtr, (SQLPOINTER)prms);
        break;
      default:
        switch (targetCType) {
        case SQL_C_WCHAR:
          *indPtr = (opt->pcbColDef * expand_factor + 1) * 2;
          pfSqlCValue = (SQLPOINTER) custom_alloc_zero(*indPtr);
          sqlrc = custom_SQL400AddCVar(i + 1, 0, SQL_C_WCHAR, (SQLPOINTER)pfSqlCValue, indPtr, (SQLPOINTER)prms);
          break;
        default:
          *indPtr = opt->pcbColDef * expand_factor + 1;
          if (defaultCType == SQL_C_WCHAR) {
            *indPtr = *indPtr * 2;
          }
          pfSqlCValue = (SQLPOINTER) custom_alloc_zero(*indPtr);
          sqlrc = custom_SQL400AddCVar(i + 1, 0, defaultCType, (SQLPOINTER)pfSqlCValue, indPtr, (SQLPOINTER)prms);
          break;
        }
        break;
      }
      break;
    case SQL_BINARY:
    case SQL_VARBINARY:
    /* case SQL_LONGVARBINARY: */
      switch (flag) {
      case SQL400_DESC_PARM:
        sqlrc = custom_SQL400AddCVar(i + 1, 0, parmCType, (SQLPOINTER)pfSqlCValue, indPtr, (SQLPOINTER)prms);
        break;
      default:
        switch (targetCType) {
        case SQL_C_WCHAR:
          *indPtr = (opt->pcbColDef + 1) * 4;
          pfSqlCValue = (SQLPOINTER) custom_alloc_zero(*indPtr);
          sqlrc = custom_SQL400AddCVar(i + 1, 0, SQL_C_WCHAR, (SQLPOINTER)pfSqlCValue, indPtr, (SQLPOINTER)prms);
          break;
        case SQL_C_CHAR:
          *indPtr = (opt->pcbColDef + 1) * 2;
          pfSqlCValue = (SQLPOINTER) custom_alloc_zero(*indPtr);
          sqlrc = custom_SQL400AddCVar(i + 1, 0, SQL_C_CHAR, (SQLPOINTER)pfSqlCValue, indPtr, (SQLPOINTER)prms);
        default:
          *indPtr = opt->pcbColDef + 1;
          pfSqlCValue = (SQLPOINTER) custom_alloc_zero(*indPtr);
          sqlrc = custom_SQL400AddCVar(i + 1, 0, SQL_C_BINARY, (SQLPOINTER)pfSqlCValue, indPtr, (SQLPOINTER)prms);
          break;
        }
        break;
      }
      break;
    case SQL_TYPE_DATE:
    case SQL_TYPE_TIME:
    case SQL_TYPE_TIMESTAMP:
    case SQL_DATETIME:
    case SQL_DECFLOAT:
      switch (flag) {
      case SQL400_DESC_PARM:
        sqlrc = custom_SQL400AddCVar(i + 1, 0, parmCType, (SQLPOINTER)pfSqlCValue, indPtr, (SQLPOINTER)prms);
        break;
      default:
        switch (targetCType) {
        case SQL_C_WCHAR:
          *indPtr = (opt->pcbColDef + 1) * 2;
          pfSqlCValue = (SQLPOINTER) custom_alloc_zero(*indPtr);
          sqlrc = custom_SQL400AddCVar(i + 1, 0, SQL_C_WCHAR, (SQLPOINTER)pfSqlCValue, indPtr, (SQLPOINTER)prms);
          break;
        default:
          *indPtr = opt->pcbColDef + 1;
          if (defaultCType == SQL_C_WCHAR) {
            *indPtr = *indPtr * 2;
          }
          pfSqlCValue = (SQLPOINTER) custom_alloc_zero(*indPtr);
          sqlrc = custom_SQL400AddCVar(i + 1, 0, defaultCType, (SQLPOINTER)pfSqlCValue, indPtr, (SQLPOINTER)prms);
          break;
        }
        break;
      }
      break;
    case SQL_SMALLINT:
      /* max 32,767 */
      switch (flag) {
      case SQL400_DESC_PARM:
        sqlrc = custom_SQL400AddCVar(i + 1, 0, parmCType, (SQLPOINTER)pfSqlCValue, indPtr, (SQLPOINTER)prms);
        break;
      default:
        switch (targetCType) {
        case SQL_C_WCHAR:
          *indPtr = 14;
          pfSqlCValue = (SQLPOINTER) custom_alloc_zero(*indPtr);
          sqlrc = custom_SQL400AddCVar(i + 1, 0, SQL_C_WCHAR, (SQLPOINTER)pfSqlCValue, indPtr, (SQLPOINTER)prms);
          break;
        case SQL_C_CHAR:
          *indPtr = 7;
          pfSqlCValue = (SQLPOINTER) custom_alloc_zero(*indPtr);
          sqlrc = custom_SQL400AddCVar(i + 1, 0, SQL_C_CHAR, (SQLPOINTER)pfSqlCValue, indPtr, (SQLPOINTER)prms);
          break;
        default:
          *indPtr = sizeof(iAmFloat);
          pfSqlCValue = (SQLPOINTER) custom_alloc_zero(*indPtr);
          sqlrc = custom_SQL400AddCVar(i + 1, 0, SQL_C_DEFAULT, (SQLPOINTER)pfSqlCValue, indPtr, (SQLPOINTER)prms);
          break;
        }
        break;
      }
      break;
    case SQL_INTEGER:
      /* max 2,147,483,647 */
      switch (flag) {
      case SQL400_DESC_PARM:
        sqlrc = custom_SQL400AddCVar(i + 1, 0, parmCType, (SQLPOINTER)pfSqlCValue, indPtr, (SQLPOINTER)prms);
        break;
      default:
        switch (targetCType) {
        case SQL_C_WCHAR:
          *indPtr = 24;
          pfSqlCValue = (SQLPOINTER) custom_alloc_zero(*indPtr);
          sqlrc = custom_SQL400AddCVar(i + 1, 0, SQL_C_WCHAR, (SQLPOINTER)pfSqlCValue, indPtr, (SQLPOINTER)prms);
          break;
        case SQL_C_CHAR:
          *indPtr = 12;
          pfSqlCValue = (SQLPOINTER) custom_alloc_zero(*indPtr);
          sqlrc = custom_SQL400AddCVar(i + 1, 0, SQL_C_CHAR, (SQLPOINTER)pfSqlCValue, indPtr, (SQLPOINTER)prms);
          break;
        default:
          *indPtr = sizeof(iAmInt);
          pfSqlCValue = (SQLPOINTER) custom_alloc_zero(*indPtr);
          sqlrc = custom_SQL400AddCVar(i + 1, 0, SQL_C_DEFAULT, (SQLPOINTER)pfSqlCValue, indPtr, (SQLPOINTER)prms);
          break;
        }
        break;
      }
      break;
    case SQL_BIGINT:
      /* max 9,223,372,036,854,775,807 */
      switch (flag) {
      case SQL400_DESC_PARM:
        sqlrc = custom_SQL400AddCVar(i + 1, 0, parmCType, (SQLPOINTER)pfSqlCValue, indPtr, (SQLPOINTER)prms);
        break;
      default:
        switch (targetCType) {
        case SQL_C_WCHAR:
          *indPtr = 44;
          pfSqlCValue = (SQLPOINTER) custom_alloc_zero(*indPtr);
          sqlrc = custom_SQL400AddCVar(i + 1, 0, SQL_C_WCHAR, (SQLPOINTER)pfSqlCValue, indPtr, (SQLPOINTER)prms);
          break;
        case SQL_C_CHAR:
          *indPtr = 22;
          pfSqlCValue = (SQLPOINTER) custom_alloc_zero(*indPtr);
          sqlrc = custom_SQL400AddCVar(i + 1, 0, SQL_C_CHAR, (SQLPOINTER)pfSqlCValue, indPtr, (SQLPOINTER)prms);
          break;
        default:
          *indPtr = sizeof(iAmBigInt);
          pfSqlCValue = (SQLPOINTER) custom_alloc_zero(*indPtr);
          sqlrc = custom_SQL400AddCVar(i + 1, 0, SQL_C_DEFAULT, (SQLPOINTER)pfSqlCValue, indPtr, (SQLPOINTER)prms);
          break;
        }
        break;
      }
      break;
    case SQL_FLOAT:
      switch (flag) {
      case SQL400_DESC_PARM:
        sqlrc = custom_SQL400AddCVar(i + 1, 0, parmCType, (SQLPOINTER)pfSqlCValue, indPtr, (SQLPOINTER)prms);
        break;
      default:
        switch (targetCType) {
        case SQL_C_WCHAR:
          *indPtr = (opt->pcbColDef + opt->pibScale + 3) * 2;
          pfSqlCValue = (SQLPOINTER) custom_alloc_zero(*indPtr);
          sqlrc = custom_SQL400AddCVar(i + 1, 0, SQL_C_WCHAR, (SQLPOINTER)pfSqlCValue, indPtr, (SQLPOINTER)prms);
          break;
        case SQL_C_CHAR:
          *indPtr = opt->pcbColDef + opt->pibScale + 3;
          pfSqlCValue = (SQLPOINTER) custom_alloc_zero(*indPtr);
          sqlrc = custom_SQL400AddCVar(i + 1, 0, SQL_C_CHAR, (SQLPOINTER)pfSqlCValue, indPtr, (SQLPOINTER)prms);
          break;
        default:
          *indPtr = sizeof(iAmFloat);
          pfSqlCValue = (SQLPOINTER) custom_alloc_zero(*indPtr);
          sqlrc = custom_SQL400AddCVar(i + 1, 0, SQL_C_DEFAULT, (SQLPOINTER)pfSqlCValue, indPtr, (SQLPOINTER)prms);
          break;
        }
        break;
      }
      break;
    case SQL_DOUBLE:
      switch (flag) {
      case SQL400_DESC_PARM:
        sqlrc = custom_SQL400AddCVar(i + 1, 0, parmCType, (SQLPOINTER)pfSqlCValue, indPtr, (SQLPOINTER)prms);
        break;
      default:
        switch (targetCType) {
        case SQL_C_WCHAR:
          *indPtr = (opt->pcbColDef + opt->pibScale + 3) * 2;
          pfSqlCValue = (SQLPOINTER) custom_alloc_zero(*indPtr);
          sqlrc = custom_SQL400AddCVar(i + 1, 0, SQL_C_WCHAR, (SQLPOINTER)pfSqlCValue, indPtr, (SQLPOINTER)prms);
          break;
        case SQL_C_CHAR:
          *indPtr = opt->pcbColDef + opt->pibScale + 3;
          pfSqlCValue = (SQLPOINTER) custom_alloc_zero(*indPtr);
          sqlrc = custom_SQL400AddCVar(i + 1, 0, SQL_C_CHAR, (SQLPOINTER)pfSqlCValue, indPtr, (SQLPOINTER)prms);
          break;
        default:
          *indPtr = sizeof(iAmDouble);
          pfSqlCValue = (SQLPOINTER) custom_alloc_zero(*indPtr);
          sqlrc = custom_SQL400AddCVar(i + 1, 0, SQL_C_DEFAULT, (SQLPOINTER)pfSqlCValue, indPtr, (SQLPOINTER)prms);
          break;
        }
        break;
      }
      break;
    case SQL_DECIMAL:
    case SQL_NUMERIC:
      switch (flag) {
      case SQL400_DESC_PARM:
        sqlrc = custom_SQL400AddCVar(i + 1, 0, parmCType, (SQLPOINTER)pfSqlCValue, indPtr, (SQLPOINTER)prms);
        break;
      default:
        switch (targetCType) {
        case SQL_C_WCHAR:
          *indPtr = (opt->pcbColDef + opt->pibScale + 3) * 2;
          pfSqlCValue = (SQLPOINTER) custom_alloc_zero(*indPtr);
          sqlrc = custom_SQL400AddCVar(i + 1, 0, SQL_C_WCHAR, (SQLPOINTER)pfSqlCValue, indPtr, (SQLPOINTER)prms);
          break;
        default:
          *indPtr = opt->pcbColDef + opt->pibScale + 3;
          if (defaultCType == SQL_C_WCHAR) {
            *indPtr = *indPtr * 2;
          }
          pfSqlCValue = (SQLPOINTER) custom_alloc_zero(*indPtr);
          sqlrc = custom_SQL400AddCVar(i + 1, 0, defaultCType, (SQLPOINTER)pfSqlCValue, indPtr, (SQLPOINTER)prms);
          break;
        }
        break;
      }
      break;
    case SQL_CLOB:
      switch (flag) {
      case SQL400_DESC_PARM:
        sqlrc = custom_SQL400AddCVar(i + 1, 0, parmCType, (SQLPOINTER)pfSqlCValue, indPtr, (SQLPOINTER)prms);
        break;
      default:
        *indPtr = SQL_DATA_AT_EXEC;
        pfSqlCValue = (SQLPOINTER) custom_alloc_zero(sizeof(iAmInt));
        sqlrc = custom_SQL400AddCVar(i + 1, 0, SQL_CLOB_LOCATOR, (SQLPOINTER)pfSqlCValue, indPtr, (SQLPOINTER)prms);
        break;
      }
      break;
    case SQL_DBCLOB:
      switch (flag) {
      case SQL400_DESC_PARM:
        sqlrc = custom_SQL400AddCVar(i + 1, 0, parmCType, (SQLPOINTER)pfSqlCValue, indPtr, (SQLPOINTER)prms);
      default:
        *indPtr = SQL_DATA_AT_EXEC;
        pfSqlCValue = (SQLPOINTER) custom_alloc_zero(sizeof(iAmInt));
        sqlrc = custom_SQL400AddCVar(i + 1, 0, SQL_DBCLOB_LOCATOR, (SQLPOINTER)pfSqlCValue, indPtr, (SQLPOINTER)prms);
        break;
      }
      break;
    case SQL_BLOB:
      switch (flag) {
      case SQL400_DESC_PARM:
        sqlrc = custom_SQL400AddCVar(i + 1, 0, parmCType, (SQLPOINTER)pfSqlCValue, indPtr, (SQLPOINTER)prms);
        break;
      default:
        *indPtr = SQL_DATA_AT_EXEC;
        pfSqlCValue = (SQLPOINTER) custom_alloc_zero(sizeof(iAmInt));
        sqlrc = custom_SQL400AddCVar(i + 1, 0, SQL_BLOB_LOCATOR, (SQLPOINTER)pfSqlCValue, indPtr, (SQLPOINTER)prms);
        break;
      }
      break;
    default:
      switch (flag) {
      case SQL400_DESC_PARM:
        sqlrc = custom_SQL400AddCVar(i + 1, 0, parmCType, (SQLPOINTER)pfSqlCValue, indPtr, (SQLPOINTER)prms);
        break;
      default:
        switch (targetCType) {
        case SQL_C_WCHAR:
          *indPtr = (opt->pcbColDef * expand_factor + 1) * 2;
          pfSqlCValue = (SQLPOINTER) custom_alloc_zero(*indPtr);
          sqlrc = custom_SQL400AddCVar(i + 1, 0, SQL_C_WCHAR, (SQLPOINTER)pfSqlCValue, indPtr, (SQLPOINTER)prms);
          break;
          break;
        default:
          *indPtr = opt->pcbColDef * expand_factor + 1;
          if (defaultCType == SQL_C_WCHAR) {
            *indPtr = *indPtr * 2;
          }
          pfSqlCValue = (SQLPOINTER) custom_alloc_zero(*indPtr);
          sqlrc = custom_SQL400AddCVar(i + 1, 0, defaultCType, (SQLPOINTER)pfSqlCValue, indPtr, (SQLPOINTER)prms);
          break;
        }
        break;
      }
      break;
    }
  }
  return sqlrc;
}
SQLRETURN custom_SQL400AddCVarRowAsChar(SQLSMALLINT nbrcols,
 SQLPOINTER descs,
 SQLPOINTER cparms,
 SQLINTEGER expand_factor) 
{ 
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc =  custom_SQL400AddCVarAnyBoth(nbrcols, descs, cparms, expand_factor, SQL_C_CHAR, 0, SQL400_DESC_COL, (SQLPOINTER) NULL, (SQLPOINTER) NULL, (SQLPOINTER) NULL);
  return sqlrc;
}
SQLRETURN custom_SQL400AddCVarRowAsCharW(SQLSMALLINT nbrcols,
 SQLPOINTER descs,
 SQLPOINTER cparms,
 SQLINTEGER expand_factor) 
{ 
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc =  custom_SQL400AddCVarAnyBoth(nbrcols, descs, cparms, expand_factor, SQL_C_WCHAR, 1, SQL400_DESC_COL, (SQLPOINTER) NULL, (SQLPOINTER) NULL, (SQLPOINTER) NULL);
  return sqlrc;
}
SQLRETURN custom_SQL400AddCVarRowAsDefault(SQLSMALLINT nbrcols,
 SQLPOINTER descs,
 SQLPOINTER cparms,
 SQLINTEGER expand_factor) 
{ 
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc =  custom_SQL400AddCVarAnyBoth(nbrcols, descs, cparms, expand_factor, SQL_C_DEFAULT, 0, SQL400_DESC_COL, (SQLPOINTER) NULL, (SQLPOINTER) NULL, (SQLPOINTER) NULL);
  return sqlrc;
}
SQLRETURN custom_SQL400AddCVarRowAsDefaultW(SQLSMALLINT nbrcols,
 SQLPOINTER descs,
 SQLPOINTER cparms,
 SQLINTEGER expand_factor) 
{ 
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc =  custom_SQL400AddCVarAnyBoth(nbrcols, descs, cparms, expand_factor, SQL_C_DEFAULT, 1, SQL400_DESC_COL, (SQLPOINTER) NULL, (SQLPOINTER) NULL, (SQLPOINTER) NULL);
  return sqlrc;
}

SQLRETURN custom_SQL400AddCVarMultipleRowsBoth(SQLSMALLINT nbrcols, 
 SQLPOINTER descs,
 SQLINTEGER max_rows, 
 SQLPOINTER *out_rows,
 SQLINTEGER all_char, 
 SQLINTEGER expand_factor,
 SQLSMALLINT iswide) 
{ 
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQL400DescStruct * opts = (SQL400DescStruct *) NULL;
  SQL400DescStruct * opt = (SQL400DescStruct *) NULL;
  SQL400ParamStruct * prms = (SQL400ParamStruct *) NULL;
  SQL400ParamStruct * prm = (SQL400ParamStruct *) NULL;
  SQLSMALLINT defaultCType = SQL_C_CHAR;
  int c = 0;
  int szPtrs = 0, szPrms = 0;
  void * outPtr = (void *)NULL;
  char ** argv = (char **)NULL;

  /* output - initial results */
  *out_rows = (SQLPOINTER) NULL;

  /* alloc expand factor (ccsid conversion) */
  if (expand_factor < 1) {
    expand_factor = 1;
  }
  switch (all_char) {
  case 1:
    defaultCType = SQL_C_CHAR;
    break;
  default:
    defaultCType = SQL_C_DEFAULT;
    break;
  }
  /* out_rows - ptr to rows results
   * out_rows[0]->SQL400ParamStruct[0],..,SQL400ParamStruct[nbrcols]
   * :
   * out_rows[max_rows]->SQL400ParamStruct[0],..,SQL400ParamStruct[nbrcols]
   */
  szPtrs = (max_rows +1) * sizeof(char *);
  outPtr = (void *)custom_alloc_zero(szPtrs);
  argv = (char **) outPtr;
  *out_rows = (SQLPOINTER) outPtr;
  /* fetch location each row */
  szPrms = (nbrcols + 1) * sizeof(SQL400ParamStruct);
  for (c=0; c < max_rows; c++) {
    /* each row, all columns */
    prms = (SQL400ParamStruct *) custom_alloc_zero(szPrms);
    opts = (SQL400DescStruct *) descs;
    argv[c] = (char *) prms;
    sqlrc = custom_SQL400AddCVarAnyBoth(nbrcols, opts, prms, expand_factor, defaultCType, iswide, SQL400_DESC_COL, (SQLPOINTER) NULL, (SQLPOINTER) NULL, (SQLPOINTER) NULL);
  }

  return sqlrc;
}

SQLRETURN custom_SQL400AddCVarMultipleRowsAsChar(SQLSMALLINT nbrcols, 
 SQLPOINTER descs,
 SQLINTEGER max_rows, 
 SQLPOINTER *out_rows,
 SQLINTEGER expand_factor)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLINTEGER all_char = 1;
  SQLSMALLINT iswide = 0;
  sqlrc = custom_SQL400AddCVarMultipleRowsBoth(nbrcols, descs, max_rows, out_rows, all_char, expand_factor, iswide);
  return sqlrc;
}
SQLRETURN custom_SQL400AddCVarMultipleRowsAsCharW(SQLSMALLINT nbrcols, 
 SQLPOINTER descs,
 SQLINTEGER max_rows, 
 SQLPOINTER *out_rows,
 SQLINTEGER expand_factor)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLINTEGER all_char = 1;
  SQLSMALLINT iswide = 1;
  sqlrc = custom_SQL400AddCVarMultipleRowsBoth(nbrcols, descs, max_rows, out_rows, all_char, expand_factor, iswide);
  return sqlrc;
}
SQLRETURN custom_SQL400AddCVarMultipleRowsAsDefault(SQLSMALLINT nbrcols, 
 SQLPOINTER descs,
 SQLINTEGER max_rows, 
 SQLPOINTER *out_rows,
 SQLINTEGER expand_factor)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLINTEGER all_char = 0;
  SQLSMALLINT iswide = 0;
  sqlrc = custom_SQL400AddCVarMultipleRowsBoth(nbrcols, descs, max_rows, out_rows, all_char, expand_factor, iswide);
  return sqlrc;
}
SQLRETURN custom_SQL400AddCVarMultipleRowsAsDefaultW(SQLSMALLINT nbrcols, 
 SQLPOINTER descs,
 SQLINTEGER max_rows, 
 SQLPOINTER *out_rows,
 SQLINTEGER expand_factor)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLINTEGER all_char = 0;
  SQLSMALLINT iswide = 1;
  sqlrc = custom_SQL400AddCVarMultipleRowsBoth(nbrcols, descs, max_rows, out_rows, all_char, expand_factor, iswide);
  return sqlrc;
}

/*
 * C VAR host vars params
 */

SQLRETURN custom_SQL400AddCVarParmsBoth(SQLSMALLINT nbrparms, 
 SQLPOINTER descs,
 SQLPOINTER * in_parms,
 SQLINTEGER * in_parms_len,
 SQLSMALLINT * in_parms_ctype,
 SQLPOINTER * out_parms,
 SQLINTEGER expand_factor,
 SQLSMALLINT targetCType,
 SQLSMALLINT iswide)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  /* alloc expand factor (ccsid conversion) */
  if (expand_factor < 1) {
    expand_factor = 1;
  }
  *out_parms = (SQLPOINTER) custom_alloc_zero((nbrparms + 1) * sizeof(SQL400ParamStruct));
  sqlrc = custom_SQL400AddCVarAnyBoth(nbrparms, descs, *out_parms, expand_factor, targetCType, iswide, SQL400_DESC_PARM, (SQLPOINTER) in_parms, (SQLPOINTER) in_parms_len, (SQLPOINTER) in_parms_ctype);
  return sqlrc;
}
SQLRETURN custom_SQL400AddCVarParms(SQLSMALLINT nbrparms,
 SQLPOINTER descs,
 SQLPOINTER * in_parms,
 SQLINTEGER * in_parms_len,
 SQLSMALLINT * in_parms_ctype,
 SQLPOINTER * out_parms,
 SQLINTEGER expand_factor) 
{ 
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc =  custom_SQL400AddCVarParmsBoth(nbrparms, descs, in_parms, in_parms_len, in_parms_ctype, out_parms, expand_factor, SQL_C_DEFAULT, 0);
  return sqlrc;
}
SQLRETURN custom_SQL400AddCVarParmsW(SQLSMALLINT nbrparms,
 SQLPOINTER descs,
 SQLPOINTER * in_parms,
 SQLINTEGER * in_parms_len,
 SQLSMALLINT * in_parms_ctype,
 SQLPOINTER * out_parms,
 SQLINTEGER expand_factor) 
{ 
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc =  custom_SQL400AddCVarParmsBoth(nbrparms, descs, in_parms, in_parms_len, in_parms_ctype, out_parms, expand_factor, SQL_C_DEFAULT, 1);
  return sqlrc;
}

SQLRETURN custom_SQL400ParmsFree(SQLSMALLINT nbr_parms,
 SQLPOINTER parms,
 SQLPOINTER decs)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQL400DescStruct * opts = (SQL400DescStruct *) NULL;
  SQL400DescStruct * opt = (SQL400DescStruct *) NULL;
  SQL400ParamStruct * prms = (SQL400ParamStruct *) NULL;
  SQL400ParamStruct * prm = (SQL400ParamStruct *) NULL;
  int i=0, j=0;
  char ** argv = (char **)NULL;

  /* parms */
  if (parms) {
    prms = (SQL400ParamStruct *) parms;
    for (j=0; j < nbr_parms; j++) {
      prm = (SQL400ParamStruct *)&prms[j];
      if (prm->indPtr) {
        free(prm->indPtr);
      }
      /* provided by caller
      if (prm->pfSqlCValue) {
        free(prm->pfSqlCValue);
      }
      */
      free(prm);
    }
  }
  /* decs */
  if (decs) {
    opts = (SQL400DescStruct *) decs;
    for (i=0; i < nbr_parms; i++) {
      opt = (SQL400DescStruct *)&opts[i];
      free(opt);
    }
  }
  return sqlrc;
}


/*
 * C var at exec
 */

SQLRETURN custom_SQL400GetAtExecLobBoth(SQLHSTMT hstmt,
 SQLSMALLINT targetCType,
 SQLPOINTER cdesc,
 SQLPOINTER cparm,
 SQLINTEGER expand_factor) 
{ 
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLHANDLE hdbc = 0;
  SQLHANDLE hstmt2 = 0, hstmt3 = 0;
  SQLINTEGER pcbColDef2 = 0, pcbColDef3 = 0;
  SQLINTEGER indPtr2 = 0, indPtr3 = 0;
  SQLINTEGER lobLoc = 0;
  SQL400DescStruct * opt = (SQL400DescStruct *) cdesc;
  SQL400ParamStruct * prm = (SQL400ParamStruct *) cparm;
  SQL400ParamStruct sprm;


  /* SQL_DATA_AT_EXEC (need connection) */
  sqlrc = custom_SQL400Stmt2Hdbc(hstmt, &hdbc);

  /* sizeof LOB */
  sqlrc = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt2);
  pcbColDef2 = opt->pcbColDef + 1;
  indPtr2 = 0;
  lobLoc = *(SQLINTEGER *)(prm->pfSqlCValue);
  free(prm->pfSqlCValue);
  sqlrc = SQLGetLength(hstmt2, prm->pfSqlCType, lobLoc, &pcbColDef2, &indPtr2);
  pcbColDef2 = pcbColDef2 * expand_factor;
  prm->pfSqlCValue = (SQLPOINTER) custom_alloc_zero(pcbColDef2 + 1);
  SQLFreeHandle(SQL_HANDLE_STMT, hstmt2);

  /* get LOB data */
  pcbColDef3 = -10;
  indPtr3 = 0;
  sqlrc = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt3);
  switch (lobLoc) {
  case SQL_CLOB_LOCATOR:
  case SQL_DBCLOB_LOCATOR:
    switch (targetCType) {
    case SQL_C_WCHAR:
      sqlrc = SQLGetSubStringW(hstmt3, prm->pfSqlCType, lobLoc, 1, pcbColDef2, targetCType, prm->pfSqlCValue, pcbColDef2, &pcbColDef3, &indPtr3);
    default:
      sqlrc = SQLGetSubString(hstmt3, prm->pfSqlCType, lobLoc, 1, pcbColDef2, targetCType, prm->pfSqlCValue, pcbColDef2, &pcbColDef3, &indPtr3);
      break;
    }
    /* trim */
    sprm.icol = SQL400_DESC_COL;
    sprm.inOutType = 0;
    sprm.pfSqlCType = SQL_CLOB;
    sprm.pfSqlCValue = prm->pfSqlCValue;
    sprm.indPtr = &pcbColDef2;
    custom_trim_CVAR(&sprm);
    break;
  case SQL_BLOB_LOCATOR:
    sqlrc = SQLGetSubString(hstmt3, prm->pfSqlCType, lobLoc, 1, pcbColDef2, targetCType, prm->pfSqlCValue, pcbColDef2, &pcbColDef3, &indPtr3);
    break;
  }
  SQLFreeHandle(SQL_HANDLE_STMT, hstmt3);
  return sqlrc;
}


SQLRETURN custom_SQL400GetAtExecBoth(SQLHSTMT hstmt,
 SQLSMALLINT nbrcols,
 SQLPOINTER descs,
 SQLPOINTER cparms,
 SQLINTEGER expand_factor,
 SQLSMALLINT targetCType,
 SQLSMALLINT iswide) 
{ 
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQL400DescStruct * opts = (SQL400DescStruct *)descs;
  SQL400ParamStruct * prms = (SQL400ParamStruct *)cparms;
  SQL400DescStruct * opt = (SQL400DescStruct *) NULL;
  SQL400ParamStruct * prm = (SQL400ParamStruct *) NULL;
  SQLSMALLINT defaultCType = SQL_C_CHAR;
  int i = 0;

  /* SQL_DATA_AT_EXEC (delayed data fetch) */
  switch(iswide) {
  case 1:
    defaultCType = SQL_C_WCHAR;
    break;
  default:
    defaultCType = SQL_C_CHAR;
    break;
  }
  for (i=0; i < nbrcols; i++) {
    opt = (SQL400DescStruct *)&opts[i];
    prm = (SQL400ParamStruct *)&prms[i];
    if (prm->pfSqlCType == SQL_C_CHAR || prm->pfSqlCType == SQL_C_WCHAR) {
      custom_trim_CVAR(prm);
    }
    switch (opt->pfSqlType) {
    case SQL_CHAR:
    case SQL_VARCHAR:
    case SQL_UTF8_CHAR:
    case SQL_WCHAR:
    case SQL_WVARCHAR:
    /* case SQL_LONGVARCHAR: */
    /* case SQL_WLONGVARCHAR: */
      break;
    case SQL_GRAPHIC:
    case SQL_VARGRAPHIC:
    /* case SQL_LONGVARGRAPHIC: */
      break;
    case SQL_BINARY:
    case SQL_VARBINARY:
    /* case SQL_LONGVARBINARY: */
      break;
    case SQL_TYPE_DATE:
    case SQL_TYPE_TIME:
    case SQL_TYPE_TIMESTAMP:
    case SQL_DATETIME:
    case SQL_DECFLOAT:
      break;
    case SQL_SMALLINT:
      break;
    case SQL_INTEGER:
      break;
    case SQL_BIGINT:
      break;
    case SQL_FLOAT:
      break;
    case SQL_DOUBLE:
      break;
    case SQL_DECIMAL:
    case SQL_NUMERIC:
      break;
    case SQL_BLOB:
      targetCType = SQL_C_BINARY;
      sqlrc = custom_SQL400GetAtExecLobBoth(hstmt, targetCType, (SQLPOINTER)opt, (SQLPOINTER)prm, expand_factor);
      break;
    case SQL_CLOB:
    case SQL_DBCLOB:
      sqlrc = custom_SQL400GetAtExecLobBoth(hstmt, defaultCType, (SQLPOINTER)opt, (SQLPOINTER)prm, expand_factor);
      break;
    default:
      break;
    }
  }
  return sqlrc;
}


/*
 * bind excute
 */

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


/* 
 * fetch
 */

SQLRETURN custom_SQL400Fetch(SQLHSTMT hstmt, 
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

SQLRETURN custom_SQL400FetchArrayBoth( SQLHSTMT hstmt, 
 SQLINTEGER start_row, 
 SQLINTEGER max_rows, 
 SQLINTEGER *cnt_rows, 
 SQLINTEGER *more_rows, 
 SQLINTEGER *cnt_cols, 
 SQLPOINTER *out_rows, 
 SQLPOINTER *out_decs, 
 SQLINTEGER all_char, 
 SQLINTEGER expand_factor,
 SQLSMALLINT iswide) 
{ 
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQL400DescStruct * opts = (SQL400DescStruct *) NULL;
  SQL400DescStruct * opt = (SQL400DescStruct *) NULL;
  SQL400ParamStruct * prms = (SQL400ParamStruct *) NULL;
  SQL400ParamStruct * prm = (SQL400ParamStruct *) NULL;
  SQLSMALLINT defaultCType = SQL_C_CHAR;
  SQLSMALLINT nbrcols = 0;
  int c = 0;
  char ** argv = (char **)NULL;

  /* output - initial results */
  *cnt_rows = 0;
  *more_rows = 0;
  *cnt_cols = 0;
  *out_rows = (SQLPOINTER) NULL;
  *out_decs = (SQLPOINTER) NULL;
  /* alloc expand factor (ccsid conversion) */
  if (expand_factor < 1) {
    expand_factor = 1;
  }
  switch (all_char) {
  case 1:
    defaultCType = SQL_C_CHAR;
    break;
  default:
    defaultCType = SQL_C_DEFAULT;
    break;
  }
  /* describe columns result set */
  sqlrc = custom_SQL400AddCResultDescBoth(hstmt, &nbrcols, (SQLPOINTER *)&opts, iswide);
  *out_decs = (SQLPOINTER) opts;
  *cnt_cols = (SQLINTEGER) nbrcols;
  /* out_rows - ptr to rows results
   * out_rows[0]->SQL400ParamStruct[0],..,SQL400ParamStruct[nbrcols]
   * :
   * out_rows[max_rows]->SQL400ParamStruct[0],..,SQL400ParamStruct[nbrcols]
   */
  sqlrc = custom_SQL400AddCVarMultipleRowsBoth(nbrcols, opts, max_rows, (SQLPOINTER *)&argv, all_char, expand_factor, iswide);
  *out_rows = (SQLPOINTER *) argv;
  /* fetch each row */
  for (c=0; c < max_rows; c++) {
    prms = (SQL400ParamStruct *) argv[c];
    switch (start_row) {
    case 0:
      sqlrc = custom_SQL400Fetch(hstmt, start_row, prms, opts );
      break;
    default:
      sqlrc = custom_SQL400Fetch(hstmt, start_row + (c - 1), prms, opts );
      break;
    }
    /* finished */
    if (sqlrc != SQL_SUCCESS) {
      /* output -- no more rows */
      *more_rows = 0;
      return sqlrc;
    }
    /* possible SQL_DATA_AT_EXEC */
    sqlrc = custom_SQL400GetAtExecBoth(hstmt, nbrcols, opts, prms, expand_factor, SQL_C_CHAR, iswide);
    /* output - number cols in result set */
    *cnt_rows = c + 1;
  } /* end c (rows) */
  /* output -- MAYBE more rows */
  *more_rows = 1;
  return sqlrc;
}
SQLRETURN custom_SQL400FetchArray( SQLHSTMT hstmt, 
 SQLINTEGER start_row, 
 SQLINTEGER max_rows, 
 SQLINTEGER *cnt_rows, 
 SQLINTEGER *more_rows, 
 SQLINTEGER *cnt_cols, 
 SQLPOINTER *out_rows, 
 SQLPOINTER *out_decs, 
 SQLINTEGER all_char, 
 SQLINTEGER expand_factor) 
{ 
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = custom_SQL400FetchArrayBoth(hstmt, start_row, max_rows, cnt_rows, more_rows, cnt_cols, out_rows, out_decs, all_char, expand_factor, 0);
  return sqlrc;
}
SQLRETURN custom_SQL400FetchArrayW( SQLHSTMT hstmt, 
 SQLINTEGER start_row, 
 SQLINTEGER max_rows, 
 SQLINTEGER *cnt_rows, 
 SQLINTEGER *more_rows, 
 SQLINTEGER *cnt_cols, 
 SQLPOINTER *out_rows, 
 SQLPOINTER *out_decs, 
 SQLINTEGER all_char, 
 SQLINTEGER expand_factor) 
{ 
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = custom_SQL400FetchArrayBoth(hstmt, start_row, max_rows, cnt_rows, more_rows, cnt_cols, out_rows, out_decs, all_char, expand_factor, 1);
  return sqlrc;
}

SQLRETURN custom_SQL400FetchArrayFree(SQLINTEGER cnt_cols,
 SQLPOINTER rows,
 SQLPOINTER decs)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQL400DescStruct * opts = (SQL400DescStruct *) NULL;
  SQL400DescStruct * opt = (SQL400DescStruct *) NULL;
  SQL400ParamStruct * prms = (SQL400ParamStruct *) NULL;
  SQL400ParamStruct * prm = (SQL400ParamStruct *) NULL;
  int i=0, j=0;
  char ** argv = (char **)NULL;

  /* rows */
  if (rows) {
    argv = (char **)rows;
    for (i=0; argv[i]; i++) {
      prms = (SQL400ParamStruct *) argv[i];
      for (j=0; j < cnt_cols; j++) {
        prm = (SQL400ParamStruct *)&prms[j];
        if (prm->indPtr) {
          free(prm->indPtr);
        }
        if (prm->pfSqlCValue) {
          free(prm->pfSqlCValue);
        }
        free(prm);
      }
    }
    free(argv);
  }
  /* decs */
  if (decs) {
    opts = (SQL400DescStruct *) decs;
    for (i=0; i < cnt_cols; i++) {
      opt = (SQL400DescStruct *)&opts[i];
      free(opt);
    }
  }
  return sqlrc;
}


