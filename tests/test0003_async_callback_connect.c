#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sqlcli1.h>
#include "test.h"
#include "PaseCliAsync.h"
#include "liblang400.h"

char *db  = NULL;
char *uid = NULL;
char *pwd = NULL;
SQL400SetAttrStruct options[100];
SQLHANDLE henv;
SQLHANDLE hdbc;
SQLINTEGER ccsid = SQL_CCSID;
SQLINTEGER yes = SQL_TRUE;
SQL400AttrStruct pophenv[3];
SQL400AttrStruct pophdbc[3];
SQLINTEGER sqlcode;

/* callback sends SQL400ConnectStruct (PaseCliAsync.h) */
void SQL400ConnectCallback(SQL400ConnectStruct* myptr) {
  pthread_t ptid = pthread_self();
  printf("SQL400ConnectCallback (thread %d): hi there from callback thread\n",ptid);
  printf("SQL400ConnectCallback (thread %d): complete: sqlrc=%d, henv=%d, db=%s uid=%s pwd=xxxx *ohnd=%d options=%p callback=%p\n",
    ptid, myptr->sqlrc, myptr->henv, myptr->db, myptr->uid, *(myptr->ohnd), myptr->options, myptr->callback);
  lang_check_sqlrc(SQL_HANDLE_DBC, *(myptr->ohnd), myptr->sqlrc, 1, &sqlcode);
  free(myptr);
}

int main(int argc, char * argv[]) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  pthread_t tid = 0;
  SQL400ConnectStruct *myptr = (SQL400ConnectStruct *) NULL;
  pthread_t ptid = pthread_self();
  /* profile db2 */
  db  = getenv(SQL_DB400);
  uid = getenv(SQL_UID400);
  pwd = getenv(SQL_PWD400);
  /* environment db2 */
  sqlrc = SQL400AddAttr(SQL_HANDLE_ENV, SQL400_ATTR_PASE_CCSID, &ccsid, 0, SQL400_ONERR_CONT, SQL400_FLAG_IMMED, (SQLPOINTER)&pophenv);
  if (ccsid == 1208) {
    sqlrc = SQL400AddAttr(SQL_HANDLE_ENV, SQL_ATTR_UTF8, &yes, 0, SQL400_ONERR_CONT, SQL400_FLAG_IMMED, (SQLPOINTER)&pophenv);
  }
  sqlrc = SQL400AddAttr(SQL_HANDLE_ENV, SQL_ATTR_SERVER_MODE, &yes, 0, SQL400_ONERR_CONT, SQL400_FLAG_IMMED, (SQLPOINTER)&pophenv);
  sqlrc = SQL400Environment( &henv, (SQLPOINTER)&pophenv );
  lang_check_sqlrc(SQL_HANDLE_ENV, henv, sqlrc, 1, &sqlcode);
  /* async connection */
  tid = SQL400ConnectAsync(henv, db, uid, pwd, &hdbc, (SQLPOINTER)&pophdbc, (void *)SQL400ConnectCallback);
  printf("SQL400ConnectAsync (thread %d): connect running\n", tid);
  printf("SQL400ConnectAsync (thread %d): hi there from main thread\n",ptid);
  sleep(5);
  sqlrc = SQLDisconnect(hdbc);
  sqlrc = SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
  return sqlrc;
}
