#ifndef _TEST_H
#define _TEST_H

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sqlcli1.h>


#define SQL_HOST400 "SQL_HOST400"
#define SQL_DB400 "SQL_DB400"
#define SQL_UID400 "SQL_UID400"
#define SQL_PWD400 "SQL_PWD400"
#define SQL_LIBL400 "SQL_LIBL400"
#define SQL_CURLIB400 "SQL_CURLIB400"
#define SQL_TRACE "TRACE"


void test_replace_quote(char * c) {
  for (; *c; c++) {
    if (*c == 0x27) *c = '"';
  }
}

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


#endif /* _TEST_H */

