#------IMPORTANT WARNING -------
This project is under construction. APIs are changing daily, therefore, you should not use for ANY production purpose. 
When this warning disappears, APIs will be considered stable.

#db2sock - libtkit400.a

Welcome to db2sock project. This 'toolkit' is a dynamically loaded toolkit interface. 
Any JSON/XML parser can be used to call this interface.
The parser simply includes PaseTool.h, compile with -ltkit400, calls toolkit APIs.
Warning - current version in project is only a test. This is not formal interface.

```
tool_ctor - callbacks for output formating
tool_run - parsed name, value pairs
tool_dtor - clean-up memory
```

The parsers are dynamically loaded via SQL400Json or SQL400Xml interfaces. 
Default parser is provided (toolkit-parser-json, toolkit-parser-xml).
An environment variable allows any override fo a parser your own.

```
> export DB2JSONPARSER32 libjson400.a(shr.o)
> export DB2JSONPARSER64 libjson400.a(shr_64.o)
> export DB2XMLPARSER32 libxml400.a(shr.o)
> export DB2XMLPARSER64 libxml400.a(shr_64.o)
```

Formal interface to tool_run is simple key, value pairs (not complete yet).

```
key[n]                                  val[n] - "names" parser dependent (anything)
--------------------------------        --------------------------------
#define TOOL400_KEY_CONN       1        "connect"
#define TOOL400_KEY_PCONN      2        "pconnect"
#define TOOL400_CONN_DB     1001        "*LOCAL"
#define TOOL400_CONN_NAME   1002        "MYUSER"
#define TOOL400_CONN_PWD    1003        "MYPWD"
#define TOOL400_CONN_LIBL   1004        "MYLIB YOURLIB"
#define TOOL400_CONN_CURLIB 1005        "MYLIB"

#define TOOL400_KEY_QUERY     10        "query"
#define TOOL400_QRY_SQL     1011        "select * from animals where breed=?"

#define TOOL400_KEY_PARM      20
#define TOOL400_PARM_VALUE  1021        "fox"

#define TOOL400_KEY_FETCH     30        "fetch"
#define TOOL400_FETCH_ALL   1031        "all"

#define TOOL400_KEY_CMD       40        "cmd"
#define TOOL400_ATTR_CMD    1041        "CHGLIBL LIBL(DB2JSON QTEMP) CURLIB(DB2JSON)"

#define TOOL400_KEY_PGM       50        "pgm"
#define TOOL400_PGM_NAME    1051        "MYPGM"
#define TOOL400_PGM_LIB     1052        "*LIBL"
#define TOOL400_PGM_NAME    1053        "MYFUNC" (SRVPGM function)
#define TOOL400_KEY_END_PGM   59        "end-pgm

#define TOOL400_KEY_DCL_DS    60        "dcl-ds"
#define TOOL400_DS_NAME     1061        "my_ds_t"
#define TOOL400_DS_DIM      1062        "4"
#define TOOL400_KEY_END_DS    69        "end-ds"

#define TOOL400_KEY_DCL_S     70        "dcl-s"
#define TOOL400_S_NAME      1071        "myvar"
#define TOOL400_S_DIM       1072        "4"
#define TOOL400_S_TYPE      1073        "5av2"

...
parser may add type in range 9000+
...
#define USER_CONN_KEY       9001       "bobkey"


...
types
...
/* -- types --
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
 * "4f2"   float           float
 * "8f2"   double          double
 * "12p2"  packed(12:2)    (no c equiv)
 * "12s2"  zoned(12:2)     (no c equiv)
 * "8h"    hole            hole
 */
```


