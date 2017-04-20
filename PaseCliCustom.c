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

/*
 * conversion
 */
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

SQLRETURN custom_SQL400IgnoreNullToUtf8( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  inccsid ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (inparm != NULL && inlen != 0 && outparm != NULL && outlen != 0) {
    return custom_SQL400ToUtf8( hdbc, inparm, inlen, outparm, outlen, inccsid );
  } else if (outparm != NULL && outlen != 0) {
    memset(outparm,0,outlen);
  }
  return sqlrc;
}
SQLRETURN custom_SQL400IgnoreNullFromUtf8( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  outccsid ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (inparm != NULL && inlen != 0 && outparm != NULL && outlen != 0) {
    return custom_SQL400ToUtf8( hdbc, inparm, inlen, outparm, outlen, outccsid );
  } else if (outparm != NULL && outlen != 0) {
    memset(outparm,0,outlen);
  }
  return sqlrc;
}
SQLRETURN custom_SQL400IgnoreNullToUtf16( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  inccsid ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (inparm != NULL && inlen != 0 && outparm != NULL && outlen != 0) {
    return custom_SQL400ToUtf16( hdbc, inparm, inlen, outparm, outlen, inccsid );
  } else if (outparm != NULL && outlen != 0) {
    memset(outparm,0,outlen);
  }
  return sqlrc;
}
SQLRETURN custom_SQL400IgnoreNullFromUtf16( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  outccsid ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (inparm != NULL && inlen != 0 && outparm != NULL && outlen != 0) {
    return custom_SQL400ToUtf16( hdbc, inparm, inlen, outparm, outlen, outccsid );
  } else if (outparm != NULL && outlen != 0) {
    memset(outparm,0,outlen);
  }
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


/*
 * connect
 */
SQLRETURN custom_SQL400ConnectBoth( 
 SQLCHAR * db,
 SQLCHAR * uid,
 SQLCHAR * pwd,
 SQLCHAR * qual, 
 SQLINTEGER * ohnd, 
 SQLINTEGER  acommit, 
 SQLCHAR * alibl, 
 SQLCHAR * acurlib, 
 SQLSMALLINT iswide, 
 SQLSMALLINT isPersistent) {
  int i = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLHENV henv = 0; 
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

  SQLINTEGER attr = SQL_TRUE;

  /* nothing open, so far */
  *ohnd = 0;

  /* henv -- IBM i only one env (always 1) */
  if (!env_hndl) {
    sqlrc = custom_SQLOverrideCCSID400(0);
    henv = env_hndl;
    /* henv -- always server mode */
    attr = SQL_TRUE;
    sqlrc = SQLSetEnvAttr((SQLHENV)henv, SQL_ATTR_SERVER_MODE, (SQLPOINTER)&attr, (SQLINTEGER) 0);
  }
  henv = env_hndl;

  /* length user profile */
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
  /* re-use connection */
  if (hdbc > 1) {
    return SQL_SUCCESS;
  }
  /* hdbc -- new connection */
  sqlrc = SQLAllocHandle(SQL_HANDLE_DBC, henv, ohnd);
  if (sqlrc != SQL_SUCCESS) {
    return sqlrc;
  }
  hdbc = *ohnd;
  init_table_lock(hdbc, 0);
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
  /* hdbc - commit isolation */
  if (acommit >= 4) attr = SQL_TXN_SERIALIZABLE;
  else if (acommit >= 3) attr = SQL_TXN_REPEATABLE_READ;
  else if (acommit >= 2) attr = SQL_TXN_READ_COMMITTED;
  else if (acommit >= 1) attr = SQL_TXN_READ_UNCOMMITTED;
  else attr = SQL_TXN_NO_COMMIT;
  sqlrc = SQLSetConnectAttr((SQLHDBC)hdbc, SQL_ATTR_TXN_ISOLATION, (SQLPOINTER)&attr, 0);
  /* hdbc - system naming */
  attr = SQL_TRUE;
  sqlrc = SQLSetConnectAttr((SQLHDBC)hdbc, SQL_ATTR_DBC_SYS_NAMING, (SQLPOINTER)&attr, 0);
  /* hdbc - autocommit */
  attr = SQL_TRUE;
  sqlrc = SQLSetConnectAttr((SQLHDBC)hdbc, SQL_ATTR_AUTOCOMMIT, (SQLPOINTER)&attr, 0);
  /* hdbc - libl */
  if (alibl) {
    sqlrc = custom_SQL400ChgLibl((SQLHDBC)hdbc, (SQLCHAR *)alibl);
  }
  /* hdbc - curlib */
  if (acurlib) {
    sqlrc = custom_SQL400ChgCurLib((SQLHDBC)hdbc, (SQLCHAR *)acurlib);
  }
  /* unlock and return */
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
SQLRETURN custom_SQL400Connect( SQLCHAR * db, SQLCHAR * uid, SQLCHAR * pwd, SQLINTEGER * ohnd, SQLINTEGER  acommit, SQLCHAR * alibl, SQLCHAR * acurlib ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = custom_SQL400ConnectBoth( db, uid, pwd, NULL, ohnd, acommit, alibl, acurlib, 0, 0);
  return sqlrc;
}
SQLRETURN custom_SQL400ConnectW( SQLWCHAR * db, SQLWCHAR * uid, SQLWCHAR * pwd, SQLINTEGER * ohnd, SQLINTEGER  acommit, SQLCHAR * alibl, SQLCHAR * acurlib ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = custom_SQL400ConnectBoth( (SQLCHAR *)db, (SQLCHAR *)uid, (SQLCHAR *)pwd, NULL, ohnd, acommit, alibl, acurlib, 1, 0);
  return sqlrc;
}
SQLRETURN custom_SQL400pConnect( SQLCHAR * db, SQLCHAR * uid, SQLCHAR * pwd, SQLCHAR * qual, SQLINTEGER * ohnd, SQLINTEGER  acommit, SQLCHAR * alibl, SQLCHAR * acurlib ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = custom_SQL400ConnectBoth( db, uid, pwd, qual, ohnd, acommit, alibl, acurlib, 0, 1);
  return sqlrc;
}
SQLRETURN custom_SQL400pConnectW( SQLWCHAR * db, SQLWCHAR * uid, SQLWCHAR * pwd, SQLCHAR * qual, SQLINTEGER * ohnd, SQLINTEGER  acommit, SQLCHAR * alibl, SQLCHAR * acurlib ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = custom_SQL400ConnectBoth( (SQLCHAR *)db, (SQLCHAR *)uid, (SQLCHAR *)pwd, qual, ohnd, acommit, alibl, acurlib, 1, 1);
  return sqlrc;
}

SQLRETURN custom_SQL400ConnectUtf8( SQLINTEGER myccsid, SQLCHAR * db, SQLCHAR * uid, SQLCHAR * pwd, SQLINTEGER * ohnd, SQLINTEGER  acommit, SQLCHAR * alibl, SQLCHAR * acurlib ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLHENV henv = env_hndl; 
  SQLCHAR db_utf8[11];
  SQLCHAR uid_utf8[11];
  SQLCHAR pwd_utf8[11];
  sqlrc = custom_SQL400IgnoreNullToUtf8(henv,  (SQLPOINTER) db, (SQLINTEGER)  strlen(db), (SQLPOINTER)  &db_utf8, (SQLINTEGER)  sizeof(db_utf8), myccsid);
  sqlrc = custom_SQL400IgnoreNullToUtf8(henv, (SQLPOINTER) uid, (SQLINTEGER) strlen(uid), (SQLPOINTER) &uid_utf8, (SQLINTEGER) sizeof(uid_utf8), myccsid);
  sqlrc = custom_SQL400IgnoreNullToUtf8(henv, (SQLPOINTER) pwd, (SQLINTEGER) strlen(pwd), (SQLPOINTER) &pwd_utf8, (SQLINTEGER) sizeof(pwd_utf8), myccsid);
  sqlrc = custom_SQL400ConnectBoth( db_utf8, uid_utf8, pwd_utf8, NULL, ohnd, acommit, alibl, acurlib, 0, 0);
  return sqlrc;
}
SQLRETURN custom_SQL400pConnectUtf8( SQLINTEGER myccsid, SQLCHAR * db, SQLCHAR * uid, SQLCHAR * pwd, SQLCHAR * qual, SQLINTEGER * ohnd, SQLINTEGER  acommit, SQLCHAR * alibl, SQLCHAR * acurlib ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLHENV henv = env_hndl; 
  SQLCHAR db_utf8[11];
  SQLCHAR uid_utf8[11];
  SQLCHAR pwd_utf8[11];
  SQLCHAR qual_utf8[11];
  sqlrc = custom_SQL400IgnoreNullToUtf8(henv, (SQLPOINTER)   db, (SQLINTEGER)   strlen(db), (SQLPOINTER)   &db_utf8, (SQLINTEGER)   sizeof(db_utf8), myccsid);
  sqlrc = custom_SQL400IgnoreNullToUtf8(henv, (SQLPOINTER)  uid, (SQLINTEGER)  strlen(uid), (SQLPOINTER)  &uid_utf8, (SQLINTEGER)  sizeof(uid_utf8), myccsid);
  sqlrc = custom_SQL400IgnoreNullToUtf8(henv, (SQLPOINTER)  pwd, (SQLINTEGER)  strlen(pwd), (SQLPOINTER)  &pwd_utf8, (SQLINTEGER)  sizeof(pwd_utf8), myccsid);
  sqlrc = custom_SQL400IgnoreNullToUtf8(henv, (SQLPOINTER) qual, (SQLINTEGER) strlen(qual), (SQLPOINTER) &qual_utf8, (SQLINTEGER) sizeof(qual_utf8), myccsid);
  sqlrc = custom_SQL400ConnectBoth( db_utf8, uid_utf8, pwd_utf8, qual_utf8, ohnd, acommit, alibl, acurlib, 0, 1);
  return sqlrc;
}

SQLRETURN custom_SQL400ConnectUtf16( SQLINTEGER myccsid, SQLCHAR * db, SQLCHAR * uid, SQLCHAR * pwd, SQLINTEGER * ohnd, SQLINTEGER  acommit, SQLCHAR * alibl, SQLCHAR * acurlib ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLHENV henv = env_hndl; 
  SQLCHAR db_utf16[22];
  SQLCHAR uid_utf16[22];
  SQLCHAR pwd_utf16[22];
  sqlrc = custom_SQL400IgnoreNullToUtf16(henv, (SQLPOINTER)  db, (SQLINTEGER)  strlen(db), (SQLPOINTER)  &db_utf16, (SQLINTEGER)  sizeof(db_utf16), myccsid);
  sqlrc = custom_SQL400IgnoreNullToUtf16(henv, (SQLPOINTER) uid, (SQLINTEGER) strlen(uid), (SQLPOINTER) &uid_utf16, (SQLINTEGER) sizeof(uid_utf16), myccsid);
  sqlrc = custom_SQL400IgnoreNullToUtf16(henv, (SQLPOINTER) pwd, (SQLINTEGER) strlen(pwd), (SQLPOINTER) &pwd_utf16, (SQLINTEGER) sizeof(pwd_utf16), myccsid);
  sqlrc = custom_SQL400ConnectBoth( db_utf16, uid_utf16, pwd_utf16, NULL, ohnd, acommit, alibl, acurlib, 0, 0);
  return sqlrc;
}
SQLRETURN custom_SQL400pConnectUtf16( SQLINTEGER myccsid, SQLCHAR * db, SQLCHAR * uid, SQLCHAR * pwd, SQLCHAR * qual, SQLINTEGER * ohnd, SQLINTEGER  acommit, SQLCHAR * alibl, SQLCHAR * acurlib ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLHENV henv = env_hndl; 
  SQLCHAR db_utf16[22];
  SQLCHAR uid_utf16[22];
  SQLCHAR pwd_utf16[22];
  SQLCHAR qual_utf16[22];
  sqlrc = custom_SQL400IgnoreNullToUtf16(henv, (SQLPOINTER)   db, (SQLINTEGER)   strlen(db), (SQLPOINTER)   &db_utf16, (SQLINTEGER)   sizeof(db_utf16), myccsid);
  sqlrc = custom_SQL400IgnoreNullToUtf16(henv, (SQLPOINTER)  uid, (SQLINTEGER)  strlen(uid), (SQLPOINTER)  &uid_utf16, (SQLINTEGER)  sizeof(uid_utf16), myccsid);
  sqlrc = custom_SQL400IgnoreNullToUtf16(henv, (SQLPOINTER)  pwd, (SQLINTEGER)  strlen(pwd), (SQLPOINTER)  &pwd_utf16, (SQLINTEGER)  sizeof(pwd_utf16), myccsid);
  sqlrc = custom_SQL400IgnoreNullToUtf16(henv, (SQLPOINTER) qual, (SQLINTEGER) strlen(qual), (SQLPOINTER) &qual_utf16, (SQLINTEGER)  sizeof(qual_utf16), myccsid);
  sqlrc = custom_SQL400ConnectBoth( db_utf16, uid_utf16, pwd_utf16, qual_utf16, ohnd, acommit, alibl, acurlib, 0, 1);
  return sqlrc;
}

/*
 * close connect
 */
SQLRETURN custom_SQL400CloseBoth(SQLHDBC hdbc) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  init_table_dtor(hdbc);
  sqlrc = SQLDisconnect(hdbc);
  sqlrc = SQLFreeConnect(hdbc);
  return sqlrc;
}

SQLRETURN custom_SQL400RollBackBoth(SQLHDBC hdbc) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  int auto_commit = 0;
  sqlrc = SQLGetConnectAttr(hdbc, SQL_ATTR_AUTOCOMMIT, &auto_commit, 0, NULL);
  if (!auto_commit) {
    sqlrc = SQLEndTran(SQL_HANDLE_DBC, hdbc, SQL_ROLLBACK);
  }
  return sqlrc;
}

SQLRETURN custom_SQL400Close(SQLHDBC hdbc) {
  int active = init_table_hash_active(hdbc, 0);
  /* always rollback (dtor language safe call) */
  SQLRETURN sqlrc = custom_SQL400RollBackBoth(hdbc);
  /* persistent connect only close with SQL400pClose */
  if (active) {
    return SQL_ERROR;
  }
  return custom_SQL400CloseBoth(hdbc);
}

SQLRETURN custom_SQL400pClose(SQLHDBC hdbc) {
  /* always rollback (dtor language safe call) */
  SQLRETURN sqlrc = custom_SQL400RollBackBoth(hdbc);
  return custom_SQL400CloseBoth(hdbc);
}


