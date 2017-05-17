#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <sqlcli1.h>
#include "test.h"
#include "PaseCliAsync.h"

pthread_once_t threadInitObject = PTHREAD_ONCE_INIT;
static pthread_mutex_t testMutexLock = PTHREAD_MUTEX_INITIALIZER;

#define LOOP 10

int hdbc_count = -1;
SQLHANDLE hdbc[LOOP];
SQLHANDLE hstmt[LOOP][LOOP];


/* (PaseCliAsync.h)
   void SQL400ConnectUtf16Callback(SQL400ConnectUtf16Struct* );
   typedef struct SQL400ConnectUtf16Struct { SQLRETURN sqlrc; 
     SQLINTEGER  accsid; 
     SQLCHAR * db; 
     SQLCHAR * uid; 
     SQLCHAR * pwd; 
     SQLINTEGER * ohnd; 
     SQLINTEGER  acommit; 
     SQLCHAR * alibl; 
     SQLCHAR * acurlib; 
     void * callback; } SQL400ConnectUtf16Struct;
*/
void SQL400ConnectUtf16Callback(SQL400ConnectUtf16Struct* cb) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  int j = 0;
  int hdbc_idx = 0;
  pthread_t ptid = pthread_self();
  if (cb->sqlrc == SQL_SUCCESS) {
    pthread_mutex_lock(&testMutexLock);
    hdbc_count++;
    hdbc_idx = hdbc_count;
    hdbc[hdbc_idx] = *cb->ohnd;
    pthread_mutex_unlock(&testMutexLock);
    printf("SQL400ConnectUtf16Callback (thread %d) hdbc = %d sqlrc = %d\n", ptid, hdbc[hdbc_idx], cb->sqlrc);
    for (j=0;j<LOOP; j++) {
      sqlrc = SQLAllocHandle(SQL_HANDLE_STMT, hdbc[hdbc_idx], &hstmt[hdbc_idx][j]);
      if (sqlrc < SQL_SUCCESS || hstmt[hdbc_idx][j] < 2) {
        printf("fail: SQL400ConnectUtf16Callback (thread %d) hdbc=%d hstmt=%d sqlrc=%d\n", ptid, hdbc[hdbc_idx], hstmt[hdbc_idx][j], cb->sqlrc);
      } else {
        printf("ok: SQL400ConnectUtf16Callback (thread %d) hdbc=%d hstmt=%d sqlrc=%d\n", ptid, hdbc[hdbc_idx], hstmt[hdbc_idx][j], cb->sqlrc);
      }
    }
  } else {
    printf("fail: SQL400ConnectUtf16Callback (thread %d) connect sqlrc = %d\n", ptid, cb->sqlrc);
  }
}
/* SQL400 aggregate API -- convert db, uid, pwd to UTF8, set-up env, sys naming, server mode, etc. */
pthread_t db2_async_connect(int myccsid, SQLCHAR * db, SQLCHAR * uid, SQLCHAR * pwd, SQLHANDLE *handle, int iso, SQLCHAR * libl, SQLCHAR * curlib) {
  return SQL400ConnectUtf16Async(myccsid, db, uid, pwd, handle, iso, libl, curlib, SQL400ConnectUtf16Callback);
}

int main(int argc, char * argv[]) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  int i = 0, j = 0;
  char *db  = NULL;
  char *uid = NULL;
  char *pwd = NULL;
  char *libl  = NULL;
  char *curlib = NULL;
  char *trace  = NULL;
  int expect_hdbc = 0;
  int actual_hdbc = 0;
  int expect_hstmt = 0;
  int actual_hstmt = 0;
  pthread_t tid[LOOP];
  SQLHANDLE handle[LOOP];

  /* profile db2 */
  db  = getenv(SQL_DB400);
  uid = getenv(SQL_UID400);
  pwd = getenv(SQL_PWD400);
  trace = getenv(SQL_TRACE);
  printf("run (trace=%s)\n",trace);
  /* environment db2 */
  sqlrc = SQLOverrideCCSID400( 1200 );
  /* connection(s) db2 */
  for (i=0;i<LOOP; i++) {
    printf("main submit async connect for array handle[%d]\n",i);
    tid[i] = db2_async_connect(819, (SQLCHAR *) db, (SQLCHAR *) uid, (SQLCHAR *) pwd, &handle[i], SQL_TXN_NO_COMMIT, libl, curlib);
  }
  /* wait threads finish (false hold to avoid end) */
  for (i=0;i<LOOP; i++) {
    printf("final join (thread %d)\n", tid[i]);
    pthread_join(tid[i],NULL);
  }
  /* free connection(s) db2 */
  printf("final delete resources\n");
  for (i=0;i<LOOP; i++) {
    if (hdbc[i]) actual_hdbc++;
    for (j=0;j<LOOP; j++) {
      if (hstmt[i][j]) actual_hstmt++;
      printf("final free hdbc=%d hstmt=%d\n", hdbc[i], hstmt[i][j]);
      sqlrc = SQLFreeHandle(SQL_HANDLE_STMT, hstmt[i][j]);
    }
    sqlrc = SQLDisconnect(hdbc[i]);
    printf("final disconnect hdbc=%d sqlrc=%d\n", hdbc[i], sqlrc);
    sqlrc = SQLFreeHandle(SQL_HANDLE_DBC, hdbc[i]);
    printf("final conn free hdbc=%d sqlrc=%d\n", hdbc[i], sqlrc);
  }
  expect_hdbc = LOOP;
  expect_hstmt = expect_hdbc * LOOP;
  printf("final expected hdbc=%d total hdbc=%d\n", expect_hdbc, actual_hdbc);
  printf("final expected hstmt=%d total hstmt=%d\n", expect_hstmt, actual_hstmt);
  printf("success (trace=%s)\n",trace);
  return sqlrc;
}


