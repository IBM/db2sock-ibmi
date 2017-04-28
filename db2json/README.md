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
test assumes basic authorization (httpd.conf)
also work for SSL, kerberos, %%client%%, EIM, etc.

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


Note: 
- Must use CGIConvMode BINARY for directory.
- db2json.rpgle (CGI) hard coded to my test chroot directory for libdb400.a
       // test chroot (test)
       DCL-C DB2_PATH_LIBDB400 CONST('/QOpenSys/zend7+
       /QOpenSys/usr/lib/');
       // actual lib (production)
       // DCL-C DB2_PATH_LIBDB400 CONST('/QOpenSys/usr/lib/');
```

# binary
[YIPS test version binary](http://yips.idevcloud.com/wiki/index.php/Databases/SuperDriver)
```
  if you want to experiment with CGI (above), 
  create/copy new libdb400.a test directory
  /QOpenSys/zend7/QOpenSys/usr/lib/libdb400.a
  
```
Note: 
I am using a chroot for my development therefore /QOpenSys/zend7.
You will have to replicate if you want to play around (please).
When project is closer to finshed the final target dir will be choosen.

# run

```
set test authorization (shell)
> export SQL_HOST400="http://ut28p63/db2/db2json.pgm"
> export SQL_DB400=*LOCAL
> export SQL_UID400=MYUID
> export SQL_PWD400=MYPWD

== php test
> cd db2json/tests
> export PATH=/usr/local/zendphp7/bin:/usr/bin
> export LIBPATH=/usr/local/zendphp7/bin:/usr/li
> php query.php

```


# json
```
experimental see php tests
```


