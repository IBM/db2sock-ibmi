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
SQLINTEGER yes = SQL_TRUE;
SQL400AttrStruct pophenv[3];
SQL400AttrStruct pophdbc[3];
SQLINTEGER sqlcode;

SQLINTEGER myccsid = 819;
char db_utf16[22];
char uid_utf16[22];
char pwd_utf16[22];

int main(int argc, char * argv[]) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  /* profile db2 */
  db  = getenv(SQL_DB400);
  uid = getenv(SQL_UID400);
  pwd = getenv(SQL_PWD400);
  /* environment db2 */
  sqlrc = SQLOverrideCCSID400( 1200 );
  lang_check_sqlrc(SQL_HANDLE_ENV, henv, sqlrc, 1, &sqlcode);
  sqlrc = SQL400AddAttr(SQL_HANDLE_ENV, SQL_ATTR_SERVER_MODE, &yes, 0, SQL400_ONERR_CONT, SQL400_FLAG_IMMED, (SQLPOINTER)&pophenv);
  sqlrc = SQL400Environment( &henv, (SQLPOINTER)&pophenv );
  lang_check_sqlrc(SQL_HANDLE_ENV, henv, sqlrc, 1, &sqlcode);
  /* normal db2 connect (no async) */
  sqlrc = SQL400ToUtf16(henv,  (SQLPOINTER) db, (SQLINTEGER)  strlen(db), (SQLPOINTER)  &db_utf16, (SQLINTEGER)  sizeof(db_utf16), myccsid);
  sqlrc = SQL400ToUtf16(henv, (SQLPOINTER) uid, (SQLINTEGER) strlen(uid), (SQLPOINTER) &uid_utf16, (SQLINTEGER) sizeof(uid_utf16), myccsid);
  sqlrc = SQL400ToUtf16(henv, (SQLPOINTER) pwd, (SQLINTEGER) strlen(pwd), (SQLPOINTER) &pwd_utf16, (SQLINTEGER) sizeof(pwd_utf16), myccsid);
  sqlrc = SQL400ConnectW(henv, (SQLWCHAR *) &db_utf16, (SQLWCHAR *) &uid_utf16, (SQLWCHAR *) &pwd_utf16, &hdbc, (SQLPOINTER)&pophdbc);
  lang_check_sqlrc(SQL_HANDLE_DBC, hdbc, sqlrc, 1, &sqlcode);
  printf("SQL400ConnectW: complete\n");
  sqlrc = SQLDisconnect(hdbc);
  sqlrc = SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
  return sqlrc;
}
