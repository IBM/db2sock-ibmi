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
assumes basic authorization (httpd.conf)

<Directory />       
   AuthType Basic
   AuthName "IBMi OS User Profile"
   Require valid-user
   PasswdFile %%SYSTEM%%
   Order Deny,Allow 
   Deny From all     
</Directory>
ScriptAlias /db2/ /QSYS.LIB/DB2JSON.LIB/
<Directory /QSYS.LIB/DB2JSON.LIB/>
  AllowOverride None
  order allow,deny
  allow from all
  SetHandler cgi-script
  Options +ExecCGI
  CGIConvMode BINARY
</Directory>


Note: Must use CGIConvMode BINARY for directory.
```

# run

```
set test authorization (shell)
> export SQL_HOST400=myibmi
> export SQL_DB400=*LOCAL
> export SQL_UID400=MYUID
> export SQL_PWD400=MYPWD

== node test db2 json 
> node tests/nodejsrest.js

== curl test db2 json
> tests/curltest.sh
> tests/curltestnull.sh
```


# json
```
Query:
{
"connect":{"database":"*LOCAL","user":"DB2","password":"XXXXX", "qualify":"myconn"},
"prepare":"select * from qiws.qcustcdt where lstnam like ?",
"execute":"Hen%",
"fetch":"*"
}
```


