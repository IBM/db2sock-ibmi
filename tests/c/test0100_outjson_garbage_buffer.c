#include <stdio.h>
#include <string.h>
#include <sqlcli1.h>

#define MAX_TEST_BUFFER 512

int main(int argc, char * argv[]) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  char *injson = "{\"pgm\":[{\"name\":\"HELLO\",\"lib\":\"DB2JSON\"},{\"s\":{\"name\":\"char\",\"type\":\"128a\",\"value\":\"Hi there\"}}]}";
  int inlen = strlen(injson);
  char outjson[MAX_TEST_BUFFER];
  memset(outjson, (int)'X', MAX_TEST_BUFFER);
  int outlen = sizeof(outjson);

  printf("input(%d):\n%s\n",inlen,injson);

  sqlrc = SQL400Json(0, injson, inlen, outjson, outlen);
  printf("output(%d):\n%s\n\n",strlen(outjson),outjson);

  printf("result:\n");

  char *exp="\"char\":\"Hello World\"";
  char *ptr = strstr(outjson,exp);
  if (!ptr) {
    printf("fail missing(%s)\n",exp);
    sqlrc = SQL_ERROR;
  }
  exp="X";
  ptr = strstr(outjson,exp);
  if (ptr) {
    printf("fail found(%s)\n",exp);
    sqlrc = SQL_ERROR;
  }

  if (sqlrc == SQL_SUCCESS) {
    printf("success (%d)\n",sqlrc);
  } else {
    printf("fail (%d)\n",sqlrc);
  }

  return sqlrc;
}


