#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <sqlcli1.h>
#include "test.h"
#include "PaseCliAsync.h"

/*
export MALLOCDEBUG=report_allocations 
*/

#define MAX_TEST_BUFFER 5000000

int main(int argc, char * argv[]) {
  int i = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  char injson[MAX_TEST_BUFFER];
  int inlen = sizeof(injson);
  char outjson[MAX_TEST_BUFFER];
  int outlen = sizeof(outjson);
  char * lowwater = NULL;
  char * highwater = NULL;
  char * input = "{\"pgm\":[{\"name\":\"HELLOSRV\", \"lib\":\"DB2JSON\", \"func\":\"HELLO\"},{\"s\":{\"name\":\"char\", \"type\":\"128a\", \"value\":\"Hi there\"}}]}";

  /* test */
  strcpy(injson,input);
  printf("input(%d):\n%s\n",inlen,injson);

  /* sqlrc = SQLOverrideCCSID400( 1208 ); */

  printf("\noutput:\n");

  /* json call (hdbc=0 - json handles connection) */
  for (i = 0, sqlrc = SQL_SUCCESS; i < 500 && sqlrc == SQL_SUCCESS; i++) {
    memset(outjson, 0, outlen);
    sqlrc = SQL400Json(0, injson, inlen, outjson, outlen);
    highwater = sbrk(0);
    if (!lowwater) {
      lowwater = highwater;
    }
    if (!(i % 100)) {
      printf("lowwater(%p) == highwater(%p) - loop count (%d)\n", lowwater, highwater, i);
    }
  }
  printf("lowwater(%p) == highwater(%p) - loop count last (%d)\n", lowwater, highwater, i);
  if (sqlrc == SQL_SUCCESS && lowwater != highwater) {
    sqlrc = SQL_ERROR;
  }
  if (sqlrc == SQL_SUCCESS) {
    printf("success (%d)\n",sqlrc);
  } else {
    printf("fail (%d)\n",sqlrc);
  }

  return sqlrc;
}


