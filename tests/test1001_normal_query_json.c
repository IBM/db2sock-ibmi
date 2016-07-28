#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sqlcli1.h>
#include "test.h"
#include "PaseCliAsync.h"
#include "liblang400.h"

char * injson0 = " \
{ \
 \"sql\": { \
   \"prepare\": \"select * from qiws.qcustcdt where LSTNAM like ?\", \
   \"execute\": {\"parm\":\"J%\"}, \
   \"fetch\": \"*\" \
 } \
} \
";
char outjson0[4096];


/* ====================
 * main
 * ====================
 */
int main(int argc, char * argv[]) {
  pthread_t ptid = pthread_self();
  pthread_t tid = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLCHAR * injson = injson0;
  SQLINTEGER  inlen = strlen(injson0);
  SQLCHAR * outjson = (SQLCHAR *) &outjson0;
  SQLINTEGER  outlen = sizeof(outjson0);
  int expect = SQL_SUCCESS;
  sqlrc = SQL400Json(injson, inlen, outjson, outlen);
  lang_expect_count("operation complete", expect, sqlrc);
  return 1;
}
