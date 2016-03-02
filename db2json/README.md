#db2sock/db2json

==Experimental==

Apache REST json interface to new async libdb400.a driver. 

# compile

```
$ cd db2sock/db2json
$ ./makedb2json.sh
```

# configure

```
ScriptAlias /db2/ /QSYS.LIB/DB2JSON.LIB/
<Directory /QSYS.LIB/DB2JSON.LIB/>
  AllowOverride None
  order allow,deny
  allow from all
  SetHandler cgi-script
  Options +ExecCGI
  CGIConvMode BINARY
</Directory>
```

Note: Must use CGIConvMode BINARY for directory.


# json
```
Query:
{
"connect":{"database":"*LOCAL","user":"DB2","password":"NICE2DB2", "qualify":"myconn"},
"prepare":"select * from qiws.qcustcdt where lstnam like ?",
"execute":"Hen%",
"fetch":"*"
}
Ok:
{
"connect":{"ok":true},
"prepare":{"ok":true},
"execute":{"ok":true},
"fetch":
 {
   "ok":true,
   "row":[
    {"fld1":"frog1","fld2":"toad1"},
    {"fld1":"frog2","fld2":"toad2"}
   ]
 }
}
Error:
{
"connect":{
  "ok":false,
  "reason":"SQL error",
  "sqlcode":"99999",
  "sqlmsg":"sample"
  }
}
```


