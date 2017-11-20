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
```

# http (ut28p63 == your machine)

http://ut28p63/db2/db2json.pgm


