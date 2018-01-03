#------IMPORTANT WARNING -------
This project is under construction. APIs are changing daily, therefore, you should not use for ANY production purpose. 
When this warning disappears, APIs will be considered stable.

#db2sock/toolkit/parser-json - libjson400.a (default)

Welcome to db2sock project. This 'toolkit' is a dynamically loaded toolkit interface. 
Any JSON/XML parser can be used to call this interface.
The parser simply includes PaseTool.h, compile with -ltkit400, calls toolkit APIs.
See db2sock/toolkit/README.md for generic toolkit interface details.

The parsers are dynamically loaded via SQL400Json or SQL400Xml interfaces. 
Default parser is provided (toolkit-parser-json, toolkit-parser-xml).
An environment variable allows any override any parser of your own (json, xml, csv, etc.).

```
> export DB2JSONPARSER32 libjson400.a(shr.o)
> export DB2JSONPARSER64 libjson400.a(shr_64.o)
```

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
