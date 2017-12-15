#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <sqlcli1.h>
#include "test.h"
#include "PaseCliAsync.h"

#define MAX_TEST_BUFFER 5000000

int main(int argc, char * argv[]) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  char injson[MAX_TEST_BUFFER];
  int inlen = sizeof(injson);
  char outjson[MAX_TEST_BUFFER];
  int outlen = sizeof(outjson);
  char * ptr = NULL;
  int len = 0;
  char fp_buf[1024];
  char fp_file_json[1024];
  FILE *fp_json = NULL;
  char fp_file_exp[1024];
  FILE *fp_exp = NULL;
  char * fp_prefix = argv[1];
  char * bad = "_bad.";

  /* bad */
  if (argc < 2) {
    printf("%s j0000_parm_required (none specified)\n",argv[0]);
    printf("success (%d)\n",sqlrc);
    return;
  }

  /* json test file */
  sprintf(fp_file_json,"%s.json",fp_prefix);
  fp_json = fopen(fp_file_json,"r");
  if (!fp_json) {
    printf("file '%s' not found\n",fp_file_json);
    sqlrc = SQL_ERROR;
  }
  memset(injson,0,sizeof(injson));
  while (sqlrc == SQL_SUCCESS && (fgets(fp_buf, sizeof(fp_buf), fp_json) != NULL)) {
    strcat(injson,fp_buf);
  } 

  /* exp test file */
  sprintf(fp_file_exp,"%s.exp",fp_prefix);
  fp_exp = fopen(fp_file_exp,"r");
  if (!fp_exp) {
    printf("file '%s' not found\n",fp_file_exp);
    sqlrc = SQL_ERROR;
  }

  /* test */
  printf("input(%d):\n%s\n",inlen,injson);

  /* sqlrc = SQLOverrideCCSID400( 1208 ); */

  /* json call (hdbc=0 - json handles connection) */
  sqlrc = SQL400Json(0, injson, inlen, outjson, outlen);
  printf("output(%d):\n%s\n\n",strlen(outjson),outjson);

  /* output */
  printf("result:\n");
  /* bad expected ? */
  if (sqlrc == SQL_ERROR) {
    ptr = strstr(fp_file_json,bad);
    if (ptr) {
      printf("expected bad (%d)\n",sqlrc);
      sqlrc = SQL_SUCCESS;
    }
  }
  while (sqlrc == SQL_SUCCESS && (fgets(fp_buf, sizeof(fp_buf), fp_exp) != NULL)) {
    len = strlen(fp_buf);
    if (!len) continue;
    fp_buf[len-1] = '\0';
    ptr = strstr(outjson,fp_buf);
    if (!ptr) {
      printf("fail missing (%s)\n",fp_buf);
      sqlrc = SQL_ERROR;
    }
  } 
  if (sqlrc == SQL_SUCCESS) {
    printf("success (%d)\n",sqlrc);
  } else {
    printf("fail (%d)\n",sqlrc);
  }

  return sqlrc;
}


