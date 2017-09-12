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
  int i = 0, j = 0;
  char *db  = NULL;
  char *uid = NULL;
  char *pwd = NULL;
  char *libl  = NULL;
  char *curlib = NULL;
  char *trace  = NULL;
  SQLHANDLE hdbc = 0;
  char * injson_easy_c = "\
  {'pgm':[{'name':'RAINBOW',  'lib':'DB2JSON'},\
          {'s':[{'name':'aint8',      'type':'3i0',   'value':3},\
                {'name':'aint16',     'type':'5i0',   'value':55},\
                {'name':'aint32',     'type':'10i0',  'value':101010},\
                {'name':'aint64',     'type':'20i0',  'value':20202020},\
                {'name':'afloat',     'type':'4f2',   'value':1234.56},\
                {'name':'adouble',    'type':'8f3',   'value':123456.78},\
                {'name':'apacked',    'type':'12p2',  'value':123456.78},\
                {'name':'azoned',     'type':'12s2',  'value':123456.78},\
                {'name':'achar',      'type':'32a',   'value':'Hi there'},\
                {'name':'avarchar2',  'type':'32av2', 'value':'Hi there'},\
                {'name':'avarchar4',  'type':'32av4', 'value':'Hi there'},\
                {'name':'abinary',    'type':'3b',    'value':'313233'}\
               ]}\
         ]}";
  char injson[4096];
  int inlen = 0;
  char * outjson = NULL;
  int outlen = 0;

  /* quote to double quote */
  memset(injson,0,sizeof(injson));
  strcpy(injson,injson_easy_c);
  inlen = strlen(injson);
  test_replace_quote(injson);
  printf("input: %s\n",injson);

  /* profile db2 */
  db  = getenv(SQL_DB400);
  uid = getenv(SQL_UID400);
  pwd = getenv(SQL_PWD400);
  libl = getenv(SQL_LIBL400);
  curlib = getenv(SQL_CURLIB400);
  trace = getenv(SQL_TRACE);
  printf("run (trace=%s)\n",trace);
  /* environment db2 */
  sqlrc = SQLOverrideCCSID400( 1208 );
  /* connection(s) db2 */
  sqlrc = SQL400ConnectUtf8(819, db, uid, pwd, &hdbc, SQL_TXN_NO_COMMIT, libl, curlib);
  /* json call */
  sqlrc = SQL400Json(hdbc, injson, inlen, outjson, outlen);
  /* clean up */
  sqlrc = SQLDisconnect((SQLHDBC)hdbc);
  sqlrc = SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
  /* output */
  printf("success (trace=%s)\n",trace);
  return sqlrc;
}


