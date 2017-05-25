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
  int expect_hdbc = 0;
  int actual_hdbc = 0;
  int expect_hstmt = 0;
  int actual_hstmt = 0;
  SQLHANDLE hdbc = 0;
/*
 * -- types --
 * "5a"    char(5)         char a[5]
 * "5av2"  varchar(5:2)    struct varchar{short,a[5]}
 * "5av4"  varchar(5:4)    struct varchar{int,a[5]}
 * "5b"    binary(5)       char a[5]
 * "5bv2"  varbinary(5:2)  struct varbinary{short,a[5]}
 * "5bv4"  varbinary(5:4)  struct varbinary{int,a[5]}
 * "3i0"   int(3)          int8, char
 * "5i0"   int(5)          int16, short
 * "10i0"  int(10)         int32, int, long
 * "20i0"  int(20)         int64, long long
 * "3u0"   uns(3)          uint8, uchar, char
 * "5u0"   uns(5)          uint16, ushort, unsigned short
 * "10u0"  uns(10)         uint32, uint, unsigned long
 * "20u0"  uns(20)         uint64, ulonglong, unsigned long long
 * "4f"    float           float
 * "8f"    double          double
 * "12p2"  packed(12:2)    (no c equiv)
 * "12s2"  zoned(12:2)     (no c equiv)
 * "8h"    hole            hole
*/
  char * injson = "{\
  \"pgm\":[\"FAKENAME\",\"FAKELIB\",\"FakeFunc\"]\",\
  \"dcl-s\":[\"int8\",\"3i0\",3],\
  \"dcl-s\":[\"int16\",\"5i0\",55],\
  \"dcl-s\":[\"int32\",\"10i0\",101010],\
  \"dcl-s\":[\"int64\",\"20i0\",20202020],\
  \"dcl-s\":[\"float\",\"4f2\",1234.56],\
  \"dcl-s\":[\"double\",\"8f3\",123456.78],\
  \"dcl-s\":[\"packed\",\"12p2\",123456.78],\
  \"dcl-s\":[\"zoned\",\"12s2\",123456.78],\
  \"dcl-s\":[\"char\",\"32a\",\"Hi there\"],\
  \"dcl-s\":[\"varchar2\",\"32av2\",\"Hi there\"],\
  \"dcl-s\":[\"varchar4\",\"32av4\",\"Hi there\"],\
  \"dcl-s\":[\"binary\",\"3b\",\"313233343536\"],\
  \"end-pgm\":\"FAKENAME\"\
  }";
  int inlen = strlen(injson);
  char * outjson = NULL;
  int outlen = 0;

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


