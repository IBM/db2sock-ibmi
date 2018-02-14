#------IMPORTANT WARNING -------
This project is under construction. APIs are changing daily, therefore, you should not use for ANY production purpose. 
When this warning disappears, APIs will be considered stable.

#db2sock/toolkit/parser-json - libjson400.a (default)

Welcome to db2sock project. This 'toolkit' is a dynamically loaded toolkit interface. 
Any JSON/XML parser can be used to call this interface.
The parser simply includes PaseTool.h, compile with -ltkit400, calls toolkit APIs.
See db2sock/toolkit/README.md for generic toolkit interface details.

The parsers are dynamically loaded via SQL400Json or SQL400JsonAsync interfaces. 
Default parser is provided (toolkit-parser-json, toolkit-parser-xml).
An environment variable allows any override any parser of your own (json, xml, csv, etc.).

```
> export DB2JSONPARSER32 libjson400.a(shr.o)
> export DB2JSONPARSER64 libjson400.a(shr_64.o)
```

# transports

This section does not discuss transports. See parent directory /toolkit demonstration of calling IBM i via memory, db2, rest json calls.

# syntax

This is default json parser syntax provided with db2sock. You may create your own json parser with any syntax desired.

## connect ("connect")

Toolkit connect is relative to the transport. As such, not all connect attributes are  applicable to every connection.
Most transports provide default connection using current profile without specified connection. 

```
{"connect":{
"db":"DB",
"uid":"UID",
"pwd":"PWD",
"qual":"label",
"iso":"nc|uc|cs|rr|rs",
"libl":"mylib yourlib",
"curlib":"mylib"
}}
```

Element "connect" (optional):

- "db" (optional) - db2 database as viewed by WRKRDBDIRE. Most common use "db":"*LOCAL".

- "uid" (optional) - IBM i user profile id.

- "pwd" (optional) - IBM i user profile id password.

- "qual" (optional) - Qualifier identifier for 'persistent connection'. This connection will not be closed by toolkit.
Special "qual":"*memory" performs calls in job (aka, php job memory, etc.). 
The "*memory" option has significant security and functional risks (see db2sock issue 'faster, not always better').  

- "iso" (optional) - Isolation setting for connection. Where, 
"nc" - no commit (CRTLIB no journal), "uc" - read uncommitted (db2 default), "cs" - cursor stability, 
"rr" - repeatable read, "rs" - read synchronized. Each step up isolation implies higher locking,
therefore balanced web site performance is recommended.

- "libl" (optional) - Command CHGLIBL executed on connect.

- "curlib" (optional) - Command CHGCURLIB executed on connect.


## command ("cmd")

Toolkit enables variety of commands including exec standard commands, rexx commands with I/O parameters, qsh for shell utilities.
Please note performance of rexx and qsh is significantly slower over standard exec commands. 


```
{"cmd":{"exec":"addlible mylib"}}
{"cmd":{"rexx":"RTVJOBA CCSID(?N) USRLIBL(?) SYSLIBL(?)"}}
{"cmd":{"qsh":"ls -1 /home/adc"}}
```

Element "cmd":

- "exec" - Enables standard command within current connection job.

- "rexx" - Enables commands with parameter I/O. This option is slow using QTEMP files.

- "qsh" - Enables qsh utility calls, aka, shell calls. This option is slow, involving multiple process, and using QTEMP files.


## program ("pgm"):

Toolkit enables calls of programs (*PGM) and service programs (*SRVPGM). 
Parameters are described by "ds" (data structure) and/or "s" (simple data).
Data structures can be complex, nested, arrays, etc. 
IBM i specific convince attributes are offered to limit returned records.
IBM i specific convince attributes are offered for complex length bytes MI templates.

```
Program:
{"pgm":{
"name":"MYPGM",
"lib":"MYLIB",
"func":"MyFunc",
"debugpgm":"stopped in qsysopr"
}}

Data structure:
{"ds":{
"name":"MYDS",
"dim":1,
"by":"in|out|both|value|const|return",
"dou":"name",
"dos":"-+",
"dob":"name"
}}

Simple data:
{"s":{
"name":"MYDATA",
"dim":1,
"type":"5av2",
"by":"in|out|both|val|const|return",
"value":"MYVALUE",
"setlen":"name",
"noconv":"in|out|both",
"dou":"name",
"dob":"on"
}}
```

Element "pgm":

- "name" - Program or service program name name.

- "lib" (optional) - Library name.

"func":"MyFunc" (optional) - Service program procedure name.

- "debugpgm" (optional) - stop before executing program with message in QSYSOPR. Used for ILE debugging. 


Element "ds":

- "name" - Name of data structure. Expected appear in parser output.

- "dim" (optional) - Array dimension of data structure. Aka, number of records.

- "by" (optional) - Qualifier of data. 

```
- "in" - parameter input only (removed output)
- "out" - parameter output only
- "both" - parameter input/output
- "value" - by value
- "const" - const value
- "return" - return value
```
- "dou" (optional)  - Do until stop value "s":"name" to limit return "dim" records. IBM i convenience to limit records returned blank or unneeded output. RPG programs fills value at call time.

- "dob"  (optional) - Do until blank or zero stop value "s":"name" to limit return "dim" records. IBM i convenience to limit records returned blank or unneeded output. RPG programs fills value at call time.

- "dos" (optional) - Default search for "dou" or "dob" 



Element "s":

- "name" - Name of variable. Expected appear in parser output.

- "dim" (optional) - Array dimension of element. 

- "type" - IBM i type of data. Syntax similar to traditional RPG.

```
- "5a"    char(5)         char a[5]
- "5av2"  varchar(5:2)    struct varchar{short,a[5]}
- "5av4"  varchar(5:4)    struct varchar{int,a[5]}
- "5b"    binary(5)       char a[5]
- "5bv2"  varbinary(5:2)  struct varbinary{short,a[5]}
- "5bv4"  varbinary(5:4)  struct varbinary{int,a[5]}
- "3i0"   int(3)          int8, char
- "5i0"   int(5)          int16, short
- "10i0"  int(10)         int32, int, long
- "20i0"  int(20)         int64, long long
- "3u0"   uns(3)          uint8, uchar, char
- "5u0"   uns(5)          uint16, ushort, unsigned short
- "10u0"  uns(10)         uint32, uint, unsigned long
- "20u0"  uns(20)         uint64, ulonglong, unsigned long long
- "4f2"   float           float
- "8f2"   double          double
- "12p2"  packed(12:2)    (no c equiv)
- "12s2"  zoned(12:2)     (no c equiv)
- "8h"    hole            hole
```

- "by" (optional) - Qualifier of data. 

```
- "in" - parameter input only (removed output)
- "out" - parameter output only
- "both" - parameter input/output
- "value" - by value
- "const" - const value
- "return" - return value
```

- "value" - Data value to be copied into call. Normal json data value mapped.

- "setlen" (optional)  - Set calculated length of "ds" structure in this location. IBM i convenience for various system APIs needing bytes or size.

- "noconv" (optional)  - Do not convert ASCII <> EBCDIC data. Progressive RPG programs using ASCII UTF-8 data commonly.

- "dou" (optional)  - Do until stop value for "ds":"name" with many "dim" records. IBM i convenience to limit records returned blank or unneeded output. RPG programs fills value at call time.

- "dob"  (optional) - Do until blank or zero in this field stop value for "ds":"name" with many "dim" records. IBM i convenience to limit records returned blank or unneeded output. RPG programs fills value at call time.


## db2 ("query"):

Toolkit enables db2 calls similar to a language driver. This section is incomplete (many functions not yet written).


```
{"query":[{
"stmt":"select * from QIWS/QCUSTCDT where LSTNAM=? or LSTNAM=?"},
{"parm":[{"value":"Jones"},{"value":"Vine"}]},
{"fetch":[{"rec":"all"}]}
]} 
```

Element "query":

- "stmt" - SQL statement for prepare/execute. Parameter markers '?' are enabled.

- "parm" - Parameters for '?' markers. Specified as  normal json "value":"data" (string) or "value":1 (numeric).

- "fetch" - Fetch all or number. Refer to fetch pagination discussion below.



## examples (best source sytax)

For json examples see db2sock/tests/json.

Run json samples using small PASE c test program (./test1000_sql400json32).

```
bash-4.3$ cd db2sock/tests/c

bash-4.3$ ./test1000_sql400json32 ../json/j0101_srvpgm_hello                      
input(5000000):
{"pgm":[{"name":"HELLOSRV", "lib":"DB2JSON", "func":"HELLO"},
        {"s":{"name":"char", "type":"128a", "value":"Hi there"}}
       ]}


output(74):
{"script":[{"pgm":["HELLOSRV","DB2JSON","HELLO",{"char":"Hello World"}]}]}

result:
success (0)
```

## FAQ

1) Need a db2 connection? No. A default 'stateless' connection is implicit (current profile).
```
$ cat json/j0101_srvpgm_hello.json 
{"pgm":[{"name":"HELLOSRV", "lib":"DB2JSON", "func":"HELLO"},
        {"s":{"name":"char", "type":"128a", "value":"Hi there"}}
       ]}

```

2) How do i paginate records? Use qualified 'state full' connection like "qual":"fred" (current profile).
```
{"connect":[
  {"qual":"fred"},
  {"query":[{"stmt":"select * from QIWS/QCUSTCDT"}, 
            {"fetch":[{"rec":2}]},
            {"fetch":[{"rec":2}]},
           ]}
]}
Note: A statement handle is returned in output of a "query".
"{"script":[{"query":[{"handle":3},

fetch "rec":"all" will close statement last record.
{"connect":[
  {"qual":"fred"},
  {"query":[{"handle":'.$handle.'},
            {"fetch":[{"rec":"all"}]}
           ]}
]}

```


3) How do i close result set early? Use qualified close.
```
{"connect":[
  {"qual":"fred"},
  {"query":[{"stmt":"select * from QIWS/QCUSTCDT"}, 
            {"fetch":[{"rec":2}]},
            {"fetch":[{"rec":2}]}
           ]}
]}
Note: A statement handle is returned in output of a "query".
"{"script":[{"query":[{"handle":3},

close "handle":3 will close statement.
{"connect":[
  {"qual":"fred"},
  {"close":[{"handle":'.$handle.'}]}
]}
```
