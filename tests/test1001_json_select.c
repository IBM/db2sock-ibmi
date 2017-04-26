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

/* SQL400 aggregate API -- convert db, uid, pwd to UTF8, set-up env, sys naming, server mode, etc. */
pthread_t db2_async_connect(int myccsid, SQLCHAR * db, SQLCHAR * uid, SQLCHAR * pwd, SQLHANDLE *handle, int iso, SQLCHAR * libl, SQLCHAR * curlib) {
  return SQL400ConnectUtf16Async(myccsid, db, uid, pwd, handle, iso, libl, curlib, NULL);
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
  SQLHANDLE hdbc = 0;
  char * injson = "{\"query\":\"select * from QIWS/QCUSTCDT where LSTNAM='Jones' or LSTNAM='Vine'\",\"fetch\":\"*ALL\"}";
  int inlen = strlen(injson);
  char * outjson = NULL;
  int outlen = 0;
  char * injson2 = "{\"query\":\"select * from QIWS/QCUSTCDT where LSTNAM=? or LSTNAM=?\",\"parm\":[\"Jones\",\"Vine\"],\"fetch\":\"*ALL\"}";
  int inlen2 = strlen(injson2);
  char outjson2[32000];
  int outlen2 = 32000;

  /* profile db2 */
  db  = getenv(SQL_DB400);
  uid = getenv(SQL_UID400);
  pwd = getenv(SQL_PWD400);
  libl = getenv(SQL_LIBL400);
  curlib = getenv(SQL_CURLIB400);
  trace = getenv(SQL_TRACE);
  printf("run (trace=%s)\n",trace);
  /* environment db2 */
  sqlrc = SQLOverrideCCSID400( 1208 );
  /* connection(s) db2 */
  sqlrc = SQL400ConnectUtf8(819, db, uid, pwd, &hdbc, SQL_TXN_NO_COMMIT, libl, curlib);
  /* json call */
  sqlrc = SQL400Json(hdbc, injson, inlen, outjson, outlen);
  /* json call */
  memset(outjson2,0,sizeof(outjson2));
  sqlrc = SQL400Json(hdbc, injson2, inlen2, outjson2, outlen2);
  printf("buffer:\n%s\n",outjson2);
  /* output */
  printf("success (trace=%s)\n",trace);
  return sqlrc;
}


