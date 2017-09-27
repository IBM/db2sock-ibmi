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
  char ver[128];

  /* profile db2 */
  db  = getenv(SQL_DB400);
  uid = getenv(SQL_UID400);
  pwd = getenv(SQL_PWD400);
  trace = getenv(SQL_TRACE);
  printf("run (trace=%s)\n",trace);

  memset(ver,0,sizeof(ver));
  sqlrc = SQL400Version((SQLPOINTER) &ver, sizeof(ver));

  /* test passed? */
  if (sqlrc == SQL_SUCCESS) {
    printf("version (%s)\n",ver);
    printf("success (%d)\n",sqlrc);
  } else {
    printf("failed (%d)\n",sqlrc);
  }

  return sqlrc;
}
