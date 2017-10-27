/*
 * ILE stored procedure interface db2procj(ILE)->libdb400.a->SQL400Json->...
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iconv.h>
#include <stdarg.h>
#include <sqlcli.h>
#include "../toolkit-parser-json/PaseJson.h"

#define OCCURS_CLOB_MAX 15000000

int iJson400(char * clob) {
  /* clob -> |4-byte length|pad|data...| */
  char *clobData = NULL;
  int *clobPassLen = NULL;
  int clobLen = 0;
  char *outData = NULL;
  int outLen = 0;
  int i;
  int sqlrc = 0;
  int nest = 0;
 
  /* debug me */
  /* sleep(30); */
  clobPassLen = (int *) clob;
  clobLen = *clobPassLen;
  clobData = (char *) clob + 4;
  for (i=0; i < clobLen; i++) {
    if (clobData[i] == '{') {
      nest++;
    } else if (clobData[i] == '}') {
      nest--;
      if (!nest) {
        break;
      }
    }
  }
  memset(clobData + i, 0, clobLen - i);
  clobLen = i + 1;

  outLen = OCCURS_CLOB_MAX;
  outData = (char *) malloc(outLen);
  memset(outData,0,outLen);

  sqlrc = custom_SQL400Json(0,
            clobData,
            clobLen, 
            outData,
            outLen);

  /* copy out */
  memset(clobData,0,clobLen);
  strcpy(clobData, outData);
  free(outData);

  return sqlrc;
}



