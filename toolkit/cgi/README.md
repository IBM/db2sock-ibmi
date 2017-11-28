#db2sock/toolkit/cgi

==Experimental==

Apache REST json interface to JSON400 driver. 
This fastcgi interface seems to work best (over ILE_CGI).

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
</Directory>


Note: 
- Unsupported CGIConvMode BINARY, EBCDIC_JCD, MIXED.
```

