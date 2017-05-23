#db2sock/ILE-CGI

==Experimental==

Apache REST json interface to new async libdb400.a driver. 

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
- db2json.c (CGI) path to libdb400.a (INITARGET)
compiles ...
1) compile from chroot
  > export INICHROOT=/QOpenSys/db2sock
  > export INILIB=DB2JSON
  > export INITARGET=/QOpenSys/usr/lib
  > ./make_libdb400.sh ile
2) compile from root
  > export INILIB=DB2JSON
  > export INITARGET=/QOpenSys/usr/lib
  > ./make_libdb400.sh ile

make_libdb400.sh generates iconf.h
with 'hard code' location of libdb400.a
(see YIPs test below)
```

# binary
[YIPS test version binary](http://yips.idevcloud.com/wiki/index.php/Databases/SuperDriver)
```
  if you want to experiment with CGI (above), 
  create/copy new libdb400.a test directory
  /QOpenSys/db2sock/QOpenSys/usr/lib/libdb400.a
  
```
Note: 
I am using a chroot for my development therefore /QOpenSys/db2sock.
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
> cd tests
> export PATH=/usr/local/zendphp7/bin:/usr/bin
> export LIBPATH=/usr/local/zendphp7/bin:/usr/lib
> php query.php

```


# json
```
experimental see php tests
```


