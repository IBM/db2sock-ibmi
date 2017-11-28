#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sqlcli1.h>
#include "test.h"
#include "PaseCliAsync.h"


int main(int argc, char * argv[]) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  int i = 0, j = 0;
  int loop = 10;
  int expect_hdbc = 0;
  int actual_hdbc = 0;
  int expect_hstmt = 0;
  int actual_hstmt = 0;
  char *db  = NULL;
  char *uid = NULL;
  char *pwd = NULL;
  char *libl  = NULL;
  char *curlib = NULL;
  char *trace  = NULL;
  SQLHANDLE hdbc[10];
  SQLHANDLE hstmt[10][10];
  SQLINTEGER sqlcode;
  /* profile db2 */
  db  = getenv(SQL_DB400);
  uid = getenv(SQL_UID400);
  pwd = getenv(SQL_PWD400);
  trace = getenv(SQL_TRACE);
  printf("run (trace=%s)\n",trace);
  /* environment db2 */
  sqlrc = SQLOverrideCCSID400( 1208 );
  expect_hdbc += 1; /* env = 1 */
  expect_hstmt = expect_hdbc;
  /* connection(s) db2 */
  for (i=0;i<loop; i++) {
    /* SQL400 aggregate API -- convert db, uid, pwd to UTF8, set-up env, sys naming, server mode, etc. */
    sqlrc = SQL400ConnectUtf8(819, (SQLCHAR *) db, (SQLCHAR *) uid, (SQLCHAR *) pwd, &hdbc[i], SQL_TXN_NO_COMMIT, libl, curlib);
    expect_hdbc = expect_hstmt + 1; /* conn = 2, ...*/
    actual_hdbc = hdbc[i];
    if (expect_hdbc != actual_hdbc) {
      printf("fail: expected hdbc=%d actual hdbc=%d\n", expect_hdbc, actual_hdbc);
    }
    expect_hstmt = expect_hdbc;
    for (j=0;j<loop; j++) {
      sqlrc = SQLAllocHandle(SQL_HANDLE_STMT, hdbc[i], &hstmt[i][j]);
      expect_hstmt += 1; /* conn = 2 + (j + 1)*/
      actual_hstmt = hstmt[i][j];
      if (actual_hstmt != expect_hstmt) {
        printf("fail: expected hstmt=%d actual hstmt=%d\n", expect_hstmt, actual_hstmt);
      }
    }
  }
  /* free connection(s) db2 */
  for (i=0;i<loop; i++) {
    for (j=0;j<loop; j++) {
      sqlrc = SQLFreeHandle(SQL_HANDLE_STMT, hstmt[i][j]);
    }
    sqlrc = SQLDisconnect(hdbc[i]);
    sqlrc = SQLFreeHandle(SQL_HANDLE_DBC, hdbc[i]);
  }
  printf("final expected hdbc=%d actual hdbc=%d\n", expect_hdbc, actual_hdbc);
  printf("final expected hstmt=%d actual hstmt=%d\n", expect_hstmt, actual_hstmt);

  /* test passed? */
  if (expect_hdbc == actual_hdbc && expect_hstmt && actual_hstmt) {
    printf("success (%d)\n",sqlrc);
  } else {
    printf("failed (%d)\n",sqlrc);
  }
  return sqlrc;
}
