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
  {'pgm':[{'name':'RAINBOW',  'lib':'DB2JSON'},\
          {'s':[{'name':'aint8',      'type':'3i0',   'value':1},\
                {'name':'aint16',     'type':'5i0',   'value':2},\
                {'name':'aint32',     'type':'10i0',  'value':3},\
                {'name':'aint64',     'type':'20i0',  'value':4},\
                {'name':'auint8',     'type':'3u0',   'value':5},\
                {'name':'auint16',    'type':'5u0',   'value':6},\
                {'name':'auint32',    'type':'10u0',  'value':7},\
                {'name':'auint64',    'type':'20u0',  'value':8},\
                {'name':'afloat',     'type':'4f2',   'value':5.55},\
                {'name':'adouble',    'type':'8f3',   'value':6.666},\
                {'name':'apacked',    'type':'12p2',  'value':7.77},\
                {'name':'azoned',     'type':'12s2',  'value':8.88},\
                {'name':'achar',      'type':'32a',   'value':'A'},\
                {'name':'avarchar2',  'type':'32av2', 'value':'B'},\
                {'name':'avarchar4',  'type':'32av4', 'value':'C'},\
                {'name':'abin4',      'type':'5i0',   'value':4},\
                {'name':'abin9',      'type':'10i0',  'value':2},\
                {'name':'ahex1',      'type':'2b',    'value':'0001'},\
                {'name':'ahex2',      'type':'2b',    'value':'0002'},\
                {'name':'ahex3',      'type':'2b',    'value':'0003'},\
                {'name':'ahex4',      'type':'2b',    'value':'0004'},\
                {'name':'ahex5',      'type':'4b',    'value':'00000005'},\
                {'name':'ahex6',      'type':'4b',    'value':'00000006'},\
                {'name':'ahex7',      'type':'4b',    'value':'00000007'},\
                {'name':'ahex8',      'type':'4b',    'value':'00000008'},\
                {'name':'ahex9',      'type':'4b',    'value':'00000009'}\
               ]}\
         ]}";
  char injson[4096];
  int inlen = sizeof(injson);
  char outjson[4096];
  int outlen = sizeof(outjson);
  int i = 0;
  char * ptr = NULL;
  char * expect[] = {"\"aint8\":2","\"aint16\":3","\"aint32\":4","\"aint64\":5","\"auint8\":6",
                     "\"auint16\":7","\"auint32\":8","\"auint64\":9","\"afloat\":6.66",
                     "\"adouble\":7.777","\"apacked\":8.88","\"azoned\":9.99",
                     "\"achar\":\"A+1\"","\"avarchar2\":\"B+1\"","\"avarchar4\":\"C+1\"",
                     "\"abin4\":5","\"abin9\":3",
                     "\"ahex1\":\"0002\"","\"ahex2\":\"0003\"","\"ahex3\":\"0004\"",
                     "\"ahex4\":\"0005\"","\"ahex5\":\"00000006\"","\"ahex6\":\"00000007\"",
                     "\"ahex7\":\"00000008\"","\"ahex8\":\"00000009\"","\"ahex9\":\"0000000A\"",
                     NULL};

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


