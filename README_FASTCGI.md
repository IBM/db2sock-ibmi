#db2sock/fastcgi

==Experimental==

Apache REST json interface to new async libdb400.a driver. 

# configure

```
httpd.conf:
LoadModule zend_enabler_module /QSYS.LIB/QHTTPSVR.LIB/QZFAST.SRVPGM
# db2jsoncgi fastcgi
AddType application/x-httpd-db2 .db2
AddHandler fastcgi-script .db2
<Directory />       
   AuthType Basic
   AuthName "IBMi OS User Profile"
   Require valid-user
   PasswdFile %%SYSTEM%%
   Order Deny,Allow 
   Deny From all     
</Directory>

fastcgi.conf:
; Static DB2 servers
Server type="application/x-httpd-db2" CommandLine="/QOpenSys/db2sock/QOpenSys/usr/lib/db2jsonfcgi" StartProcesses="1" SetEnv="LIBPATH=/QOpenSys/db2sock/QOpenSys/usr/lib"
; Where to place socket files
IpcDir /www/apachedft/logs


compiles ...
1) compile from chroot
  > export INICHROOT=/QOpenSys/db2sock
  > export INILIB=DB2JSON
  > export INITARGET=/QOpenSys/usr/lib
  > ./make_libdb400.sh fcgi
2) compile from root
  > export INILIB=DB2JSON
  > export INITARGET=/QOpenSys/usr/lib
  > ./make_libdb400.sh fcgi
```

# binary
[YIPS test version binary](http://yips.idevcloud.com/wiki/index.php/Databases/SuperDriver)
```
  if you want to experiment with fastcgi (above), 
  create/copy new libdb400.a test directory
  /QOpenSys/db2sock/QOpenSys/usr/lib/libdb400.a
  also new db2jsonfcgi test directory
  /QOpenSys/db2sock/QOpenSys/usr/lib/db2jsonfcgi
```
# json
```
experimental see php tests
```


