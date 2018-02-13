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

void hex_2_bin(char * where, char *str, int tdim, int tlen, int tvary) {
  int i = 0;
  int j = 0;
  int k = 0;
  int outDigits = tlen;
  int outLength = outDigits;
  int inLength = 0;
  short * short_value = NULL;
  int * int_value = NULL;
  char * dec = NULL;
  char * c = NULL;
  char * wherev = where;
  char bytex = ' ';
  int hnbr = 0;
  int lnbr = 0;
  /* length of char hex binary input */
  if (str) {
    inLength = strlen(str);
  }
  /* truncate user overflow field area */
  if (inLength > tlen * 2) {
    inLength = tlen * 2;
  }
  /* copy in */
  for (i=0; i < tdim; i++, wherev += outLength) {
    /* vary */
    if (tvary == 4) {
      int_value = (int *) wherev;
      *int_value = inLength/2;
      wherev += 4;
    } else if (tvary) {
      short_value = (short *) wherev;
      *short_value = inLength/2;
      wherev += 2;
    }
    /* digits */
    memset(wherev, 0, outLength);
    dec = wherev;
    c = str;
    for (j=0, k=0; j < outDigits && k < inLength; k += 2) {
      bytex = str[k];
      if (bytex=='F' || bytex=='f') {
          hnbr = 15;
      } else if (bytex=='E' || bytex=='e') {
          hnbr = 14;
      } else if (bytex=='D' || bytex=='d') {
          hnbr = 13;
      } else if (bytex=='C' || bytex=='c') {
          hnbr = 12;
      } else if (bytex=='B' || bytex=='b') {
          hnbr = 11;
      } else if (bytex=='A' || bytex=='a') {
          hnbr = 10;
      } else if (bytex=='9') {
          hnbr = 9;
      } else if (bytex=='8') {
          hnbr = 8;
      } else if (bytex=='7') {
          hnbr = 7;
      } else if (bytex=='6') {
          hnbr = 6;
      } else if (bytex=='5') {
          hnbr = 5;
      } else if (bytex=='4') {
          hnbr = 4;
      } else if (bytex=='3') {
          hnbr = 3;
      } else if (bytex=='2') {
          hnbr = 2;
      } else if (bytex=='1') {
          hnbr = 1;
      } else {
          hnbr = 0;
      }
      bytex = str[k + 1];
      if (bytex=='F' || bytex=='f') {
          lnbr = 15;
      } else if (bytex=='E' || bytex=='e') {
          lnbr = 14;
      } else if (bytex=='D' || bytex=='d') {
          lnbr = 13;
      } else if (bytex=='C' || bytex=='c') {
          lnbr = 12;
      } else if (bytex=='B' || bytex=='b') {
          lnbr = 11;
      } else if (bytex=='A' || bytex=='a') {
          lnbr = 10;
      } else if (bytex=='9') {
          lnbr = 9;
      } else if (bytex=='8') {
          lnbr = 8;
      } else if (bytex=='7') {
          lnbr = 7;
      } else if (bytex=='6') {
          lnbr = 6;
      } else if (bytex=='5') {
          lnbr = 5;
      } else if (bytex=='4') {
          lnbr = 4;
      } else if (bytex=='3') {
          lnbr = 3;
      } else if (bytex=='2') {
          lnbr = 2;
      } else if (bytex=='1') {
          lnbr = 1;
      } else {
          lnbr = 0;
      }
      dec[j++] = (char)(hnbr*16 + lnbr);
    }
  }
}

int main(int argc, char * argv[]) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLRETURN sqlrc1 = SQL_SUCCESS;
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
  int eccsid = Qp2jobCCSID(); /* ebcdic job ccsid */

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
  sqlrc = SQLPrepare(hstmt, "call DB2JSON.DB2PROCBR(?)", SQL_NTS);
  sqlrc = SQLDescribeParam(hstmt, 1, &parm_data_type, &parm_precision, &parm_scale, &parm_nullable);
  inlenutf8 = parm_precision;
  injsonutf8 = ptr1 = malloc(inlenutf8);
  memset(injsonutf8,0,inlenutf8);
  inlen = strlen(injson);
  sqlrc = SQL400FromUtf8(hdbc, injson, inlen, injsonutf8, inlenutf8, eccsid);
  inlenutf8 = outlen;
  sqlrc = SQLBindParameter(hstmt, 1, SQL_PARAM_INPUT, SQL_C_DEFAULT, parm_data_type, parm_precision, parm_scale, injsonutf8, 0, &inlenutf8);
  sqlrc = SQLExecute(hstmt);
  /* get your own errors (remote not have SQL400Json) */
  if (sqlrc == SQL_ERROR) {
    memset(injson,0,sizeof(injson));
    strcat(injson,"{\"query\":[{\"stmt\":\"joblog\"}]}");
    inlen = strlen(injson);
    memset(injsonutf8,0,inlenutf8);
    sqlrc = SQL400FromUtf8(hdbc, injson, inlen, injsonutf8, inlenutf8, eccsid);
    inlenutf8 = outlen;
    sqlrc = SQLBindParameter(hstmt, 1, SQL_PARAM_INPUT, SQL_C_DEFAULT, parm_data_type, parm_precision, parm_scale, injsonutf8, 0, &inlenutf8);
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
      inlenutf8 = sizeof(injsonutf8);
      memset(injsonutf8,0,inlenutf8);
      sqlrc = SQLBindCol(hstmt,1,SQL_C_DEFAULT,injsonutf8,size,&inlenutf8);
      sqlrc = SQLFetch(hstmt);
      inlen = strlen(injsonutf8);
      memset(outjson,0,sizeof(outjson));
      hex_2_bin(outjsonutf8, injsonutf8, 1, inlen, 0);
    }
    outjsonutf8 = ptr2;
    outlenutf8 = strlen(outjsonutf8);
    if (outlenutf8 && sqlrc == SQL_NO_DATA_FOUND) {
      sqlrc = SQL_SUCCESS;
    }
    outlen = sizeof(outjson);
    memset(outjson,0,outlen);
    sqlrc1 = SQL400ToUtf8(hdbc, outjsonutf8, outlenutf8, outjson, outlen, eccsid);
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


