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

SQLINTEGER myccsid = 819;
char db_utf8[11];
char uid_utf8[11];
char pwd_utf8[11];

int main(int argc, char * argv[]) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  pthread_t tid = 0;
  SQL400ConnectStruct *myptr = (SQL400ConnectStruct *) NULL;
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
  sqlrc = SQL400ToUtf8(henv,  (SQLPOINTER) db, (SQLINTEGER)  strlen(db), (SQLPOINTER)  &db_utf8, (SQLINTEGER)  sizeof(db_utf8), myccsid);
  sqlrc = SQL400ToUtf8(henv, (SQLPOINTER) uid, (SQLINTEGER) strlen(uid), (SQLPOINTER) &uid_utf8, (SQLINTEGER) sizeof(uid_utf8), myccsid);
  sqlrc = SQL400ToUtf8(henv, (SQLPOINTER) pwd, (SQLINTEGER) strlen(pwd), (SQLPOINTER) &pwd_utf8, (SQLINTEGER) sizeof(pwd_utf8), myccsid);
  tid = SQL400ConnectAsync(henv, (SQLCHAR *) &db_utf8, (SQLCHAR *) &uid_utf8, (SQLCHAR *) &pwd_utf8, &hdbc, (SQLPOINTER)&pophdbc, (void *)NULL);
  printf("SQL400ConnectAsync (thread %d): connect running\n", tid);
  myptr = SQL400ConnectJoin (tid, SQL400_FLAG_JOIN_NO_WAIT);
  if (!myptr) {
    printf("SQL400ConnectAsync (thread %d): connect still running\n", tid);
    myptr = SQL400ConnectJoin (tid, SQL400_FLAG_JOIN_WAIT);
  }
  /* join return SQL400ConnectStruct (PaseCliAsync.h) */
  printf("SQL400ConnectJoin (thread %d): complete: sqlrc=%d, henv=%d, db=%s uid=%s pwd=xxxx *ohnd=%d options=%p callback=%p\n",
    tid, myptr->sqlrc, myptr->henv, myptr->db, myptr->uid, *(myptr->ohnd), myptr->options, myptr->callback);
  lang_check_sqlrc(SQL_HANDLE_DBC, *(myptr->ohnd), myptr->sqlrc, 1, &sqlcode);
  free(myptr);
  sqlrc = SQLDisconnect(hdbc);
  sqlrc = SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
  return sqlrc;
}
