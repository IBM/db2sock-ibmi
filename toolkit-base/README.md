#------IMPORTANT WARNING -------
This project is under construction. APIs are changing daily, therefore, you should not use for ANY production purpose. 
When this warning disappears, APIs will be considered stable.

#db2sock - libtkit400.a

Welcome to db2sock project. This 'toolkit' is a dynamically loaded toolkit interface. 
Any JSON/XML parser can be used to call this interface.
The parser simply includes PaseTool.h, compile with -ltkit400, calls toolkit APIs.
Warning - current version in project is only a test. This is not formal interface.

The toolkit constructor requires callbacks to output 'callback' result data into any form the parser desires (xml, json, csv, etc.)
The toolkit requires a protocol independent fixed array set of key[], value[], level[], arguments to perform toolkit functions.
Any parser may used to map 'any' format to key[], value[], level[]. Parse can be XML, JSON, CSV, anything protocol imaginable. 
 
There are three functions exported from toolkit library (libtkit400.a).
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
#define TOOL400_KEY_ELEM_BEG 0          /* key 'action' elem range */
#define TOOL400_KEY_ELEM_BEG 999        /* key 'action' elem range */

#define TOOL400_KEY_ATTR_BEG 1000       /* attribute range */
#define TOOL400_KEY_ATTR_SEP 1998       /* attribute reserved (internal use only) */
#define TOOL400_KEY_ATTR_END 1999       /* attribute range */

#define TOOL400_KEY_SPEC_BEG 2000       /* special attribute range */
#define TOOL400_KEY_ARY_BEG 2071        /*"["*/
#define TOOL400_KEY_ARY_SEP 2072        /*","*/
#define TOOL400_KEY_ARY_END 2073        /*"]"*/
#define TOOL400_KEY_SEPC_END 2999       /* special attribute range */

#define TOOL400_KEY_HIGH    9000        /* everything above parser only range (remove before call) */

/*
Order input array:
  key begin (TOOL400_KEY_CONN)
    key attr (TOOL400_CONN_DB) <- attributes before child nodes (json sort, xml natural)
      key children (TOOL400_KEY_PGM)

key[n]                                  val[n] - "names" parser dependent (anything)
--------------------------------        --------------------------------
*/
#define TOOL400_KEY_CONN       1        /*"connect":*/
#define TOOL400_KEY_PCONN      2        /*"pconnect":*/
#define TOOL400_CONN_DB     1001        /*"database":"*LOCAL"*/
#define TOOL400_CONN_UID    1002        /*"name":"MYUSER"*/
#define TOOL400_CONN_PWD    1003        /*"password":"MYPWD"*/
#define TOOL400_CONN_LIBL   1004        /*"libl":"MYLIB YOURLIB"*/
#define TOOL400_CONN_CURLIB 1005        /*"curlib":"MYLIB"*/
#define TOOL400_CONN_QUAL   1006        /*"qual":"myprivate1"*/
#define TOOL400_CONN_ISOLATION 1007     /*"isolation":
                                         *  "nc" - SQL_TXN_NO_COMMIT (No Commit)
                                         *  "uc" - SQL_TXN_READ_UNCOMMITTED (Uncommitted Read)
                                         *  "cs" - SQL_TXN_READ_COMMITTED (Cursor Stability)
                                         *  "rr" - SQL_TXN_REPEATABLE_READ (Repeatable Read )
                                         *  "rs" - SQL_TXN_SERIALIZABLE (Read Stability)
                                         */
#define TOOL400_KEY_END_CONN   9        /*"end"*/

#define TOOL400_KEY_QUERY     10        /*"query":"select * from animals where breed=?"*/
#define TOOL400_KEY_END_QUERY 19        /*"end"*/

#define TOOL400_KEY_PARM      20        /*"parm":"fox"*/
#define TOOL400_KEY_END_PARM  29        /*"end"*/

#define TOOL400_KEY_FETCH     30        /*"fetch":"all"*/
#define TOOL400_KEY_END_FETCH 39        /*"end"*/

#define TOOL400_KEY_CMD       40        /*"cmd":"CHGLIBL LIBL(DB2JSON QTEMP) CURLIB(DB2JSON)"*/
#define TOOL400_KEY_END_CMD   49        /*"end"*/

#define TOOL400_KEY_PGM       50        /*"pgm"*/
#define TOOL400_PGM_NAME    1051        /*"name":"MYPGM"*/
#define TOOL400_PGM_LIB     1052        /*"lib":"*LIBL"*/
#define TOOL400_PGM_FUNC    1053        /*"func":"MYFUNC" (SRVPGM function)*/
#define TOOL400_KEY_END_PGM   59        /*"end"*/

#define TOOL400_KEY_DCL_DS    60        /*"ds"*/
#define TOOL400_DS_NAME     1061        /*"name":"my_ds_t"*/
#define TOOL400_DS_DIM      1062        /*"dim":"4"*/
#define TOOL400_DS_BY       1063        /*"by":"in|out|both|value|const|return"*/
#define TOOL400_KEY_END_DS    69        /*"end"*/

#define TOOL400_KEY_DCL_S     70        /*"s"*/
#define TOOL400_S_NAME      1071        /*"name":"myvar"*/
#define TOOL400_S_DIM       1072        /*"dim":"4"*/
#define TOOL400_S_TYPE      1073        /*"type":"5av2" (see below)*/
#define TOOL400_S_BY        1074        /*"by":"in|out|both|value|const|return"*/
#define TOOL400_S_VALUE     1075        /*"value":"42" */
#define TOOL400_KEY_END_S     79        /*"end"*/
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


