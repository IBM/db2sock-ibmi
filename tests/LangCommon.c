#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sqlcli1.h>
#include "test.h"
#include "PaseCliAsync.h"
#include "liblang400.h"

pthread_once_t threadInitObject = PTHREAD_ONCE_INIT;
static pthread_mutex_t threadMutexLock = PTHREAD_MUTEX_INITIALIZER;
static int lang_waiter = 0;
static int lang_debug = 0;

/* global table lock
 * This lock is 'lock once'.
 * That is, not PTHREAD_MUTEX_RECURSIVE,
 * therefore do not call twice, will hang.
 */
void lang_lock() {
  pthread_mutex_lock(&threadMutexLock);
}

void lang_unlock() {
  pthread_mutex_unlock(&threadMutexLock);
}

int lang_wait_init() {
  int rc = 0;
  char * bug = getenv(SQL_DEBUG400);
  lang_lock();
  if (bug) {
    lang_debug = 1;
  } else {
    lang_debug = 0;
  }
  lang_waiter = 0;
  lang_unlock();
  if (bug) {
    rc = lang_wait_done(1, 1);
  }
}
int lang_wait_read_wait() {
  int rc = 0;
  lang_lock();
  rc = lang_waiter;
  lang_unlock();
  return rc;
}
int lang_wait_read_debug(int secs) {
  int rc = 0;
  lang_lock();
  rc = lang_debug;
  lang_unlock();
  if (rc) {
    rc = 30;
    printf("--DEBUG MODE--\nLong sleep, attach pid %d\n--DEBUG MODE--\n", getpid());
  } else {
    rc = secs;
  }
  return rc;
}
int lang_wait_complete() {
  lang_lock();
  lang_waiter = 1;
  lang_unlock();
}
int lang_wait_done(int loop, int secs) {
  int i = 0;
  int rc = 0;
  int sleepy = secs;
  for (i=0;i < loop; i++) {
    rc = lang_wait_read_wait();
    if (rc) {
      break;
    }
    sleepy = lang_wait_read_debug(secs);
    sleep(sleepy);
  }
  return rc;
}


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
  if (expect != actual) {
    printf("ERROR: %s) expect=%d actual=%d\n", msg, expect, actual);
    exit(-1);
  } else {
    printf("SUCCESS: %s) expect=%d actual=%d\n", msg, expect, actual);
  }
}

void lang_expect_greater(char * msg, int expect, int actual) 
{
  if (expect >= actual) {
    printf("ERROR: %s) expect=%d actual=%d\n", msg, expect, actual);
    exit(-1);
  } else {
    printf("SUCCESS: %s) expect=%d actual=%d\n", msg, expect, actual);
  }
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


