#easyjson

Easy RPG CGI to process a bit of JSON. 

## build
```
download zip
ftp to location below (binary)

call qp2term os ssh myibmi
> cd /QOpenSys/QIBM/ProdData/OPS/EasyJson
> ./makeeasyjson.sh
```

## configuration (optional Basic Authorization)
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

ScriptAlias /json/ /QSYS.LIB/EASYJSON.LIB/
<Directory /QSYS.LIB/EASYJSON.LIB/>
  AllowOverride None
  order allow,deny
  allow from all
  SetHandler cgi-script
  Options +ExecCGI
</Directory>
```

#Contributors
- Tony Cairns, IBM

#License
BSD

