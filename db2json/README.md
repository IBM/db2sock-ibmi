#db2sock/db2json

==Experimental==

Apache REST json interface to new async libdb400.a driver. 

# compile (makedb2json not work in chroot)

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
> export SQL_HOST400="http://ut28p63/db2/db2json.pgm"
> export SQL_DB400=*LOCAL
> export SQL_UID400=MYUID
> export SQL_PWD400=MYPWD

== php test
php query.php 

```


# json
```
experimental see tests
```


