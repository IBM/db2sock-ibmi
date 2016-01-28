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
  int i = 0, j = 0;
  /* profile db2 */
  db  = getenv(SQL_DB400);
  uid = getenv(SQL_UID400);
  pwd = getenv(SQL_PWD400);
  /* environment db2 */
  sqlrc = SQLOverrideCCSID400( 1208 );
  lang_check_sqlrc(SQL_HANDLE_ENV, henv, sqlrc, 1, &sqlcode);
  sqlrc = SQL400AddAttr(SQL_HANDLE_ENV, SQL_ATTR_SERVER_MODE, &yes, 0, SQL400_ONERR_CONT, SQL400_FLAG_IMMED, (SQLPOINTER)&pophenv);
  sqlrc = SQL400Environment( &henv, (SQLPOINTER)&pophenv );
  lang_check_sqlrc(SQL_HANDLE_ENV, henv, sqlrc, 1, &sqlcode);
  /* normal db2 connect (no async) */
  sqlrc = SQL400ToUtf8(henv,  (SQLPOINTER) db, (SQLINTEGER)  strlen(db), (SQLPOINTER)  &db_utf8, (SQLINTEGER)  sizeof(db_utf8), myccsid);
  sqlrc = SQL400ToUtf8(henv, (SQLPOINTER) uid, (SQLINTEGER) strlen(uid), (SQLPOINTER) &uid_utf8, (SQLINTEGER) sizeof(uid_utf8), myccsid);
  sqlrc = SQL400ToUtf8(henv, (SQLPOINTER) pwd, (SQLINTEGER) strlen(pwd), (SQLPOINTER) &pwd_utf8, (SQLINTEGER) sizeof(pwd_utf8), myccsid);
  for (i=0;i<10; i++) {
    sqlrc = SQL400Connect(henv, (SQLCHAR *) &db_utf8, (SQLCHAR *) &uid_utf8, (SQLCHAR *) &pwd_utf8, &hdbc[i], (SQLPOINTER)&pophdbc);
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
