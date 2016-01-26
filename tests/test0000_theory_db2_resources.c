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
SQLHANDLE henv; /* always 1, only one env on IBM i db2 */
SQLHANDLE hdbc[10];
SQLHANDLE hstmt[10][10];
SQLINTEGER ccsid = SQL_CCSID;
SQLINTEGER yes = SQL_TRUE;
SQL400AttrStruct pophenv[3];
SQL400AttrStruct pophdbc[3];
SQLINTEGER sqlcode;

int main(int argc, char * argv[]) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  int i = 0, j = 0;
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
  /* normal db2 connect (no async) */
  for (i=0;i<10; i++) {
    sqlrc = SQL400Connect(henv, db, uid, pwd, &hdbc[i], (SQLPOINTER)&pophdbc);
    printf("SQL400Connect: hdbc[%d]=%d\n",i,hdbc[i]);
    lang_check_sqlrc(SQL_HANDLE_DBC, hdbc[i], sqlrc, 1, &sqlcode);
    for (j=0;j<10; j++) {
      sqlrc = SQLAllocHandle(SQL_HANDLE_STMT, hdbc[i], &hstmt[i][j]);
      printf("SQLAllocHandle: hstmt[%d][%d]=%d\n",i,j,hstmt[i][j]);
      lang_check_sqlrc(SQL_HANDLE_STMT, hstmt[i][j], sqlrc, 1, &sqlcode);
    }
  }
  printf("sleeping few seconds, allow you check for QSQ server jobs\n");
  sleep(10);
  for (i=0;i<10; i++) {
    for (j=0;j<10; j++) {
      sqlrc = SQLFreeHandle(SQL_HANDLE_STMT, hstmt[i][j]);
      printf("SQLFreeHandle: hstmt[%d][%d]=%d\n",i,j,hstmt[i][j]);
      lang_check_sqlrc(SQL_HANDLE_STMT, hstmt[i][j], sqlrc, 1, &sqlcode);
    }
    sqlrc = SQLDisconnect(hdbc[i]);
    printf("SQLDisconnect: hdbc[%d]=%d\n",i,hdbc[i]);
    sqlrc = SQLFreeHandle(SQL_HANDLE_DBC, hdbc[i]);
    printf("SQLFreeHandle: hdbc[%d]=%d\n",i,hdbc[i]);
  }
  return sqlrc;
}
