#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iconv.h>
#include <stdarg.h>
#include <sqlcli.h>
#include "PaseType.h"

/* TBD -- functional place holder (for impatient folk of no name) 
*/


static SQLHANDLE env_hndl;
static int env_server_mode;

/*=================================================
 * custom malloc
 */


void * custom_new(int size) {
  void * buffer = malloc(size + 1);
  memset(buffer,0,size + 1);
  return buffer;
}
void custom_free(char *buffer) {
  if (buffer) {
    free(buffer);
  }
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
  len_string = custom_new(40);
  len_len = sprintf(len_string, "%d", cmd_len);
  query_len = 23 + cmd_len + len_len ;
  query_string = custom_new(query_len);
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
  custom_free(len_string);
  custom_free(query_string);
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
  cmd_string = custom_new(cmd_len);
  strcpy(cmd_string, "CHGLIBL LIBL(");
  strcat(cmd_string, libl);
  strcat(cmd_string, ")");
  /* make call */
  sqlrc = custom_SQL400Cmd(hdbc, cmd_string);
  custom_free(cmd_string);
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
  cmd_string = custom_new(cmd_len);
  strcpy(cmd_string, "CHGCURLIB CURLIB(");
  strcat(cmd_string, curlib);
  strcat(cmd_string, ")");
  /* make call */
  sqlrc = custom_SQL400Cmd(hdbc, cmd_string);
  custom_free(cmd_string);
  return sqlrc;
}

SQLRETURN SQL400ToUtf8( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  inccsid ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  strncpy(outparm,inparm,inlen);
  return sqlrc;
}
SQLRETURN SQL400FromUtf8( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  outccsid ){
  SQLRETURN sqlrc = SQL_SUCCESS;
  strncpy(outparm,inparm,inlen);
  return sqlrc;
}
SQLRETURN SQL400Connect( SQLCHAR * db, SQLCHAR * uid, SQLCHAR * pwd, SQLINTEGER * ohnd, SQLINTEGER  acommit, SQLCHAR * alibl, SQLCHAR * acurlib ) {
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
  int db_slen = 0;
  int uid_slen = 0;
  int pwd_slen = 0;

  SQLINTEGER attr = SQL_TRUE;

  /* nothing open, so far */
  *ohnd = 0;

  /* henv -- IBM i only one env (always 1) */
  if (!env_hndl) {
    sqlrc = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env_hndl);
  }
  henv = env_hndl;
  /* henv -- always server mode */
  if (!env_server_mode) {
    attr = SQL_TRUE;
    sqlrc = SQLSetEnvAttr((SQLHENV)henv, SQL_ATTR_SERVER_MODE, (SQLPOINTER)&attr, (SQLINTEGER) 0);
    /* we are already in a stored proc call (direct calling) */
    if (sqlrc < SQL_SUCCESS) {
      env_server_mode = -1;
    } else {
      env_server_mode = 1;
    }
  }

  /* null input (or NULL terminated string) */
  if (db != NULL) {
    db_slen = strlen(db);
  }
  if (uid != NULL) {
    uid_slen = strlen(uid);
  }
  if (pwd != NULL) {
    pwd_slen = strlen(pwd);
  }
  if (env_server_mode < 1 || db == NULL || !db_slen) {
    db_str = (SQLCHAR *) NULL;
    db_len = 0;
  }
  if (env_server_mode < 1 || uid == NULL || !uid_slen) {
    uid_str = (SQLCHAR *) NULL;
    uid_len = 0;
  }
  if (env_server_mode < 1 || pwd == NULL || !pwd_slen) {
    pwd_str = (SQLCHAR *) NULL;
    pwd_len = 0;
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

  /* connect */
  sqlrc = SQLConnect( (SQLHDBC)*ohnd, (SQLCHAR *)db_str, (SQLSMALLINT)db_len, (SQLCHAR *)uid_str, (SQLSMALLINT)uid_len, (SQLCHAR *)pwd_str, (SQLSMALLINT)pwd_len );

  /* hdbc - commit isolation */
  if (acommit < SQL_TXN_NOCOMMIT || acommit > SQL_TXN_SERIALIZABLE) {
    acommit = SQL_TXN_NOCOMMIT;
  }
  attr = acommit;
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

  return sqlrc;
}
SQLRETURN SQL400pConnect( SQLCHAR * db, SQLCHAR * uid, SQLCHAR * pwd, SQLCHAR * qual, SQLINTEGER * ohnd, SQLINTEGER  acommit, SQLCHAR * alibl, SQLCHAR * acurlib ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = SQL400Connect( db, uid, pwd, ohnd, acommit, alibl, acurlib );
  return sqlrc;
}
SQLRETURN SQL400Close(SQLHDBC hdbc) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  return sqlrc;
}



