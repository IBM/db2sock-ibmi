#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sqlcli1.h>
#include "PaseCliAsync.h"
#include "liblang400.h"


int lang_strlen_utf16(unsigned int * src) {
  int len = 0;
  char *tgt = (char *) src;
  while (*(unsigned short *)tgt) { 
    len++;
    tgt += 2;
  }
  return len;
}

void lang_expect_count(char * msg, int expect, int actual) 
{
  if (expect > actual) {
    printf("ERROR: %s) expect=%d actual=%d\n", msg, expect, actual);
    exit(-1);
  } else {
    printf("SUCCESS: %s) expect=%d actual=%d\n", msg, expect, actual);
  }
}


/*
 * count process data
 */
void lang_expect_count_jobs(int expect, char * uid) 
{
  int actual = 0;
  FILE *fp = (FILE *) NULL;
  int status = 0;
  char cmd[4096];
  char big[4096];
  char buf[1024];

  memset(cmd,0,sizeof(cmd));
  memset(buf,0,sizeof(buf));
  memset(big,0,sizeof(big));
  strcat(cmd,"system wrkactjob | grep -i QSQSRVR | grep -i -c ");
  strcat(cmd,uid);
  fp = popen(cmd,"r");
  while (fgets(buf, sizeof(buf), fp) != NULL) {
    strcat(big,buf);
    memset(buf,0,sizeof(buf));
  }
  status = pclose(fp);
  actual = atoi(big);
  if (expect > actual) {
    printf("ERROR: %s) expect=%d actual=%d\n", uid, expect, actual);
    exit(-1);
  } else {
    printf("SUCCESS: %s) expect=%d actual=%d\n", uid, expect, actual);
  }
}

void lang_out_jobs(char * uid) 
{
  FILE *fp = (FILE *) NULL;
  int status = 0;
  char cmd[4096];
  char buf[1024];
  int actual = 0;

  memset(cmd,0,sizeof(cmd));
  memset(buf,0,sizeof(buf));
  strcat(cmd,"system wrkactjob | grep -i QSQSRVR | grep -i ");
  strcat(cmd,uid);
  fp = popen(cmd,"r");
  while (fgets(buf, sizeof(buf), fp) != NULL) {
    actual++;
    printf("%5d) %s", actual, buf);
    memset(buf,0,sizeof(buf));
  }
  status = pclose(fp);
}

/*
 * hType - SQL_HANDLE_ENV|DBC|STMT|DESC
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


/*
 * hType - SQL_HANDLE_ENV|DBC|STMT|DESC
 */
void lang_check_sqlrcW(SQLSMALLINT hType, SQLHANDLE handle, SQLINTEGER sqlrc, SQLSMALLINT recno, SQLINTEGER * sqlcode) {
  SQLWCHAR msg[SQL_MAX_MESSAGE_LENGTH + 1];
  SQLWCHAR state[SQL_SQLSTATE_SIZE + 1];
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
    sqlrc2 = SQLGetDiagRecW(hType, handle, recno, state, &code, msg, SQL_MAX_MESSAGE_LENGTH + 1, &len);
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


