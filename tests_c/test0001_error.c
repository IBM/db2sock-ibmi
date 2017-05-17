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
  char *db  = NULL;
  char *uid = NULL;
  char *pwd = NULL;
  char *libl  = NULL;
  char *curlib = NULL;
  char *trace  = NULL;
  /* profile db2 */
  db  = getenv(SQL_DB400);
  uid = getenv(SQL_UID400);
  pwd = getenv(SQL_PWD400);
  trace = getenv(SQL_TRACE);
  printf("run (trace=%s)\n",trace);
  /* environment db2 */
  sqlrc = SQLOverrideCCSID400( 1208 );
  /* force error */
  if (trace[0] == 's' && trace[1] == 't') {
    printf("coredump expected -- should not see final message success (trace=%s)\n",trace);
  }
  /* invalid handle number '0' */
  sqlrc = SQLSetConnectAttr((SQLHDBC)0, SQL_ATTR_DEFAULT_LIB, (SQLPOINTER)NULL, 0);
  if (sqlrc < SQL_SUCCESS) {
    printf("final expected sqlrc %d\n",sqlrc);
    printf("success (trace=%s)\n",trace);
  } else {
    printf("fail: sqlrc %d SQL_SUCCESS \n",sqlrc);
  }
  return sqlrc;
}
