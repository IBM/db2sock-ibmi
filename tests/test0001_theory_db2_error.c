#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sqlcli1.h>
#include "test.h"
#include "PaseCliAsync.h"

char *db  = NULL;
char *uid = NULL;
char *pwd = NULL;
char *libl  = NULL;
char *curlib = NULL;
SQLHANDLE henv; /* always 1, only one env on IBM i db2 */
SQLHANDLE hdbc[10];
SQLHANDLE hstmt[10][10];
SQLINTEGER sqlcode;
SQLINTEGER myccsid = 819;

int main(int argc, char * argv[]) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  int i = 0, j = 0;
  int expect = 10;
  int expect_hstmt = 1 + expect * expect + expect;
  int actual_hstmt = 0;
  /* profile db2 */
  db  = getenv(SQL_DB400);
  uid = getenv(SQL_UID400);
  pwd = getenv(SQL_PWD400);
  /* environment db2 */
  sqlrc = SQLOverrideCCSID400( 1208 );
  /* force error */
  sqlrc = SQLSetConnectAttr((SQLHDBC)0, SQL_ATTR_DEFAULT_LIB, (SQLPOINTER)NULL, 0);
  return sqlrc;
}
