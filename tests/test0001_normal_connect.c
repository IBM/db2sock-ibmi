#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sqlcli1.h>
#include "test.h"
#include "PaseCliAsync.h"
#include "liblang400.h"

char db[]  = { SQL_DB400 };
char uid[] = { SQL_UID400 };
char pwd[] = { SQL_PWD400 };
SQL400SetAttrStruct options[100];
SQLHANDLE henv;
SQLHANDLE hdbc;
SQLINTEGER ccsid = 819;
SQLINTEGER yes = SQL_TRUE;
SQL400AttrStruct pophenv[3];
SQL400AttrStruct pophdbc[3];
SQLINTEGER sqlcode;

int main(int argc, char * argv[]) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  /* environment db2 */
  sqlrc = SQL400AddAttr(SQL_HANDLE_ENV, SQL400_ATTR_CCSID, &ccsid, 0, SQL400_ONERR_CONT, SQL400_FLAG_IMMED, (SQLPOINTER)&pophenv);
  sqlrc = SQL400AddAttr(SQL_HANDLE_ENV, SQL_ATTR_SERVER_MODE, &yes, 0, SQL400_ONERR_CONT, SQL400_FLAG_IMMED, (SQLPOINTER)&pophenv);
  sqlrc = SQL400Environment( &henv, (SQLPOINTER)&pophenv );
  lang_check_sqlrc(SQL_HANDLE_ENV, henv, sqlrc, 1, &sqlcode);
  /* normal db2 connect (no async) */
  sqlrc = SQL400Connect(henv, (char *)&db, (char *)&uid, (char *)&pwd, &hdbc, (SQLPOINTER)&pophdbc);
  lang_check_sqlrc(SQL_HANDLE_DBC, hdbc, sqlrc, 1, &sqlcode);
  printf("SQL400Connect: complete\n");
  sqlrc = SQLDisconnect(hdbc);
  sqlrc = SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
  return sqlrc;
}
