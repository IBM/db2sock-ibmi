#------IMPORTANT WARNING -------
This project is under construction. APIs are changing daily, therefore, you should not use for ANY production purpose. 
When this warning disappears, APIs will be considered stable.

#db2sock/toolkit - libtkit400.a (generic toolkit IBM i calls)

This module provides generic toolkit service to call IBM i CMD, PGM, SRVPGM, QSH, DB2, etc. 
The toolkit binary (libtkit400.a), provides a callback constructor allowing any parser to control protocol syntax.
The toolkit binary receives an array of input generic 'ordinals' as defined by PaseTool.h,
Any parser can can use toolkit (xml, json, cvs, etc.). However, default parsers provided under toolkit directory (parser-protocol).

# transports (configurations)

Various json transports remote and local have been tested (included).
The driver options are listed in performance order, memory fastest
through REST slowest. 


## memory (compile) - call direct script language requires c extension compile

Local call only. 

Any scripting language may call directly to ILE via the in memory option. 
Simply add {"connect":[{"qual":"*memory"}, ... ]} to your normal json call.
However, your language provider need create a c extension
to call SQL400Json(Async).

Warning: Many security and functional exposes using in memory call option for web languages. 
See db2sock issues 'fast, may not be best' (you have been warned).

Example (tests/c):
```
bash-4.3$ ./test3000_sql400json_memory32 ../json/j0101_srvpgm_hello
input(5000000):
{"connect":[{"qual":"*memory"},{"pgm":[{"name":"HELLOSRV", "lib":"DB2JSON", "func":"HELLO"},
        {"s":{"name":"char", "type":"128a", "value":"Hi there"}}
       ]}

]}
output(74):
{"script":[{"pgm":["HELLOSRV","DB2JSON","HELLO",{"char":"Hello World"}]}]}

result:
success (0)
```

## New db2 advanced  API (compile) - call direct new advanced API

Local call only. 

Any scripting language may call directly to new CLI API SQL400Json(Async).
The new API intended to add toolkit capabilities to your existing
language db2 driver (php ibm_db2, etc.). All new CLI APIs include
an Async version to change game of your interpreted language driver.
However, your language provider need create a c extension
to call SQL400Json(Async). 

Example (tests/c):
```
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

## db2 stored procedure (no compile) - call via language db2 driver

Local or remote call.

Any scripting language may use current db2 (*DRDA) or odbc (*DDM) drivers to call included toolkit stored procedures.

- db2json.db2jsonj - single input/output parameter clob(15MB). Whereby, db2 i/ohandles all json ccsid conversion.

- db2json.db2jsonjr - single input parameter clob(15MB). Returns result set 3000 characters per record. Whereby, db2 fetch handles all json ccsid conversion.

- db2json.db2jsonb - single input/output parameter blob(15MB). Whereby, client code must handle ascii/ebcdic csid conversion.

- db2json.db2jsonbr - single input parameter blob(15MB). Returns result set 3000 bytes per record. Whereby, db2 fetch returns hex char representation of ebcdic. client code must handle ascii/ebcdic csid conversion.

Examples (tests/c):
```
test4000_sql400json_procj32
test5000_sql400json_procjr32
test6000_sql400json_procb32
test7000_sql400json_procbr32
```

Examples (tests/c):
```
bash-4.3$ ./test5000_sql400json_procjr32 ../json/j0101_srvpgm_hello
input(5000000):
{"pgm":[{"name":"HELLOSRV", "lib":"DB2JSON", "func":"HELLO"},
        {"s":{"name":"char", "type":"128a", "value":"Hi there"}}
       ]}


output(74):
{"script":[{"pgm":["HELLOSRV","DB2JSON","HELLO",{"char":"Hello World"}]}]}

result:
success (0)
```


## REST web server (no compile) - web server REST API (Apache, nginx, etc.)

Local or remote call.

Any scripting language may use standard REST json calls to toolkit hoisted on IBM i.
The REST API json interface was tested with Apache (cgi, fastcgi), and nginx (fastcgi).
The configurations are many, so please check README subdirectories /fastcgi, /cgi.

# Technical (add your own 'json parser')

## interface PaseTool.h (see toolkit/parser-json default)

A protocol parser maps any chosen syntax to generic toolkit ordinals found in PaseTool.h. 
The module header (PaseTool.h), defines parser callback constructor (tool_ctor), destructor (tool_dtor), and run (tool_run).
The module header (PaseTool.h), defines ordinals for generic toolkit actions (TOOL400_KEY_CMD, TOOL400_KEY_PGM. etc.), 
and generic toolkit attributes for actions (TOOL400_PGM_NAME, TOOL400_PGM_LIB, TOOL400_PGM_FUNC, etc.).
The parser must build the generic ordinal nodes by calling toolkit provided node add interfaces (tool_node_beg, tool_node_sep, tool_node_end, tool_node_attr).
All protocol input/output syntax operations are controlled by the parser. Aka, toolkit simply uses 'callback' for desired output formating (anything you like).

## run toolkit

DB2 db2sock driver libdb400.a CLI new toolkit API SQL400Json(injson, outjson) dynamically loads json parser responsible for input/output (below).
The same simple toolkit API will be true for any other protocol we decide to implement, SQL400Xml(inxml, outxml), SQL400Cvs(incvs, outcvs), etc.

```
json parser (see toolkit/parser-json)
> export DB2JSONPARSER32 libjson400.a(shr.o)
> export DB2JSONPARSER64 libjson400.a(shr_64.o)
* Note: Default is libjson400.a, env vars are not required.
```

