#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <sqlcli1.h>
#include "test.h"
#include "PaseCliAsync.h"

int main(int argc, char * argv[]) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  char * injson_easy_c = "\
  {'pgm':[{'name':'HELLO',  'lib':'DB2JSON'},\
          {'s':{'name':'char', 'type':'128a', 'value':'Hi there'}}\
         ]}";
  char injson[4096];
  int inlen = sizeof(injson);
  char outjson[4096];
  int outlen = sizeof(outjson);
  int i = 0;
  char * ptr = NULL;
  char * expect[] = {"\"char\":\"Hello World\"", NULL};

  /* quote to double quote */
  test_single_double(injson_easy_c, injson, &inlen);
  printf("input(%d): %s\n",inlen,injson);

  /* json call (hdbc=0 - json handles connection) */
  sqlrc = SQL400Json(0, injson, inlen, outjson, outlen);
  printf("output(%d): %s\n",strlen(outjson),outjson);

  /* output */
  for (i=0; sqlrc == SQL_SUCCESS && expect[i]; i++) {
    ptr = strstr(outjson,expect[i]);
    if (!ptr) {
      printf("fail missing (%s)\n",expect[i]);
      sqlrc == SQL_ERROR;
    }
  } 
  if (sqlrc == SQL_SUCCESS) {
    printf("success (%d)\n",sqlrc);
  } else {
    printf("fail (%d)\n",sqlrc);
  }

  return sqlrc;
}


