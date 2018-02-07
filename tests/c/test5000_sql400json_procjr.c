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
  char * ptr1 = NULL;
  char * ptr2 = NULL;
  int len = 0;
  char fp_buf[1024];
  char fp_file_json[1024];
  FILE *fp_json = NULL;
  char fp_file_exp[1024];
  FILE *fp_exp = NULL;
  char * fp_prefix = argv[1];
  char * bad = "_bad.";
  char * fixup = NULL;
  int fixlen = 0;
  SQLHDBC  hdbc = 0;
  SQLHSTMT  hstmt = 0;
  SQLSMALLINT parm_scale = 0;
  SQLINTEGER parm_precision = 0;
  SQLSMALLINT parm_data_type = 0;
  SQLSMALLINT parm_nullable = 0;
  SQLCHAR * injsonutf8 = NULL;
  SQLINTEGER inlenutf8 = 0;
  SQLCHAR * outjsonutf8 = NULL;
  SQLINTEGER outlenutf8 = 0;
  SQLSMALLINT nResultCols = 0;
  SQLCHAR buff_name[128];
  SQLSMALLINT name_length = 0;
  SQLSMALLINT type = 0;
  SQLINTEGER size = 0;
  SQLSMALLINT scale = 0;
  SQLSMALLINT nullable = 0;

  /* bad */
  if (argc < 2) {
    printf("%s j0000_parm_required (none specified)\n",argv[0]);
    printf("success (%d)\n",sqlrc);
    return;
  }
  /* fix up */
  fixup = strrchr(fp_prefix,'.');
  if (fixup && (!strcmp(fixup,".json") || !strcmp(fixup,".exp"))) {
    fixlen = strlen(fixup);
    memset(fixup,0,fixlen);
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

  sqlrc = SQL400ConnectUtf8(819, NULL, NULL, NULL, &hdbc, 0, NULL, NULL);
  sqlrc = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
  sqlrc = SQLPrepare(hstmt, "call DB2JSON.DB2PROCJR(?)", SQL_NTS);
  sqlrc = SQLDescribeParam(hstmt, 1, &parm_data_type, &parm_precision, &parm_scale, &parm_nullable);
  inlenutf8 = parm_precision;
  injsonutf8 = ptr1 = malloc(inlenutf8);
  memset(injsonutf8,0,inlenutf8);
  inlen = strlen(injson);
  sqlrc = SQL400ToUtf8(hdbc, injson, inlen, injsonutf8, inlenutf8, 0);
  inlenutf8 = SQL_NTS;
  sqlrc = SQLBindParameter(hstmt, 1, SQL_PARAM_INPUT, SQL_C_CHAR, parm_data_type, parm_precision, parm_scale, injsonutf8, 0, &inlenutf8);
  sqlrc = SQLExecute(hstmt);
  /* get your own errors (remote not have SQL400Json) */
  if (sqlrc == SQL_ERROR) {
    memset(injson,0,sizeof(injson));
    strcat(injson,"{\"query\":[{\"stmt\":\"joblog\"}]}");
    inlen = strlen(injson);
    memset(injsonutf8,0,inlenutf8);
    sqlrc = SQL400ToUtf8(hdbc, injson, inlen, injsonutf8, inlenutf8, 0);
    inlenutf8 = SQL_NTS;
    sqlrc = SQLBindParameter(hstmt, 1, SQL_PARAM_INPUT, SQL_C_CHAR, parm_data_type, parm_precision, parm_scale, injsonutf8, 0, &inlenutf8);
    sqlrc = SQLExecute(hstmt);
  }
  sqlrc = SQLNumResultCols(hstmt, &nResultCols);
  if (nResultCols == 1) {
    size = sizeof(buff_name);
    sqlrc = SQLDescribeCol(hstmt, 1, (SQLCHAR *)&buff_name, size, &name_length, &type, &size, &scale, &nullable);
    outlenutf8 = parm_precision;
    outjsonutf8 = ptr2 = malloc(outlenutf8);
    memset(outjsonutf8,0,outlenutf8);
    for (sqlrc = SQL_SUCCESS; sqlrc == SQL_SUCCESS;) {
      outjsonutf8 += strlen(outjsonutf8);
      outlenutf8 = parm_precision - strlen(outjsonutf8);
      outlenutf8 = SQL_NTS;
      sqlrc = SQLBindCol(hstmt,1,SQL_C_CHAR,outjsonutf8,size,&outlenutf8);
      sqlrc = SQLFetch(hstmt);
    }
    outlenutf8 = strlen(ptr2);
    if (outlenutf8 && sqlrc == SQL_NO_DATA_FOUND) {
      sqlrc = SQL_SUCCESS;
    }
    strncpy(outjson,ptr2,sizeof(outjson));
    free(ptr1);
    free(ptr2);
  }
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


