#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sqlcli1.h>
#include "PaseCliAsync.h"
#include "liblang400.h"

/*
 * hType - SQL_HANDLE_ENV|DBC|SRTMT|DESC
 */
void lang_check_sqlrc(SQLSMALLINT hType, SQLHANDLE handle, SQLINTEGER sqlrc, SQLSMALLINT recno, SQLINTEGER * sqlcode) {
  SQLCHAR msg[SQL_MAX_MESSAGE_LENGTH + 1];
  SQLCHAR state[SQL_SQLSTATE_SIZE + 1];
  SQLINTEGER code = 0;
  SQLSMALLINT len = 0;
  SQLCHAR *p = NULL;
  SQLINTEGER sqlrc2 = SQL_SUCCESS;
  SQLHANDLE handle2 = 0;
  if (sqlcode) {
    *sqlcode = code;
  }
  if (sqlrc != SQL_SUCCESS) {
    memset(msg, '\0', SQL_MAX_MESSAGE_LENGTH + 1);
    memset(state, '\0', SQL_SQLSTATE_SIZE + 1);
    sqlrc2 = SQLGetDiagRec(hType, handle, recno, state, &code, msg, SQL_MAX_MESSAGE_LENGTH + 1, &len);
    if (sqlrc2 == SQL_SUCCESS ) {
      if (msg[len-1] == '\n') {
        p = &msg[len-1];
       *p = '\0';
      }
    }
    printf("ERROR: sqlrc=%d SQLCODE=%d state=%s %s (diag_sqlrc=%d)\n", sqlrc, (int)code, state, msg, sqlrc2);
    switch (hType) {
    case SQL_HANDLE_ENV:
      break;
    case SQL_HANDLE_DBC:
      sqlrc2 = SQLDisconnect(handle);
      sqlrc2 = SQLFreeHandle(SQL_HANDLE_DBC, handle);
      break;
    default:
      sqlrc2 = SQL400Stmt2Hdbc(handle, &handle2);
      if (sqlrc2 == SQL_SUCCESS ) {
        sqlrc2 = SQLDisconnect(handle2);
        sqlrc2 = SQLFreeHandle(SQL_HANDLE_DBC, handle2);
      }
      break;
    }
    exit(-1);
  }
  if (sqlcode) {
    *sqlcode = code;
  }
}


