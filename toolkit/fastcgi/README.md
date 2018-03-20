#db2sock/toolkit/fastcgi

Apache fastcgi REST json interface to new async libdb400.a driver.

-- or --

Nginx fastcgi REST json interface to new async libdb400.a driver.

# configure Apache (httpd.conf, fastcgi.conf)

```
http (ut28p63 == your machine)
http://ut28p63/db2json.db2

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

# configure nginx (nginx.conf)

```
http (ut28p63 == your machine)
http://ut28p63/db2json.db2

===
start db2jsonfcgi (using db2jsonngix)
===
bash-4.3$ cd /QOpenSys/usr/lib
-- localhost:port (option 1) --
bash-4.3$ ./db2jsonngix -start -connect 127.0.0.1:9002 ./db2jsonfcgi
-- unix domain socket (option 2) --
bash-4.3$ ./db2jsonngix -start -connect /tmp/db3.sock ./db2jsonfcgi


===
start nginx
===
/QOpenSys/QIBM/ProdData/OPS/tools/bin/nginx -c /home/ADC/nginx/conf/nginx.conf

===
config (nginx.conf)
===
bash-4.3$ pwd
/home/ADC/nginx/conf
bash-4.3$ ls
fastcgi_params - /QOpenSys/QIBM/ProdData/OPS/tools/conf
mime.types - /QOpenSys/QIBM/ProdData/OPS/tools/conf
nginx.conf - (see below)


bash-4.3$ cat nginx.conf 

#user  nobody;
worker_processes  1;

#error_log  logs/error.log;
#error_log  logs/error.log  notice;
error_log  logs/error.log  info;

pid        logs/nginx.pid;


events {
    worker_connections  1024;
}


http {
    include       mime.types;
    default_type  application/octet-stream;

    #log_format  main  '$remote_addr - $remote_user [$time_local] "$request" '
    #                  '$status $body_bytes_sent "$http_referer" '
    #                  '"$http_user_agent" "$http_x_forwarded_for"';

    #access_log  logs/access.log  main;

    sendfile        on;
    #tcp_nopush     on;

    #keepalive_timeout  0;
    keepalive_timeout  65;

    #gzip  on;

    server {
        listen       80;
        server_name  localhost;

        #charset koi8-r;

        #access_log  logs/host.access.log  main;

        location / {
            root   htdocs;
            index  index.html index.htm;
        }

        #error_page  404              /404.html;

        # redirect server error pages to the static page /50x.html
        #
        error_page   500 502 503 504  /50x.html;
        location = /50x.html {
            root   html;
        }

        # proxy the PHP scripts to Apache listening on 127.0.0.1:80
        #
        #location ~ \.php$ {
        #    proxy_pass   http://127.0.0.1;
        #}
        # pass db2 json to FastCGI server listening on 127.0.0.1:9002
        # ./db2jsonngix -start -connect 127.0.0.1:9002 ./db2jsonfcgi
        #
        location ~ \.db2$ {
            fastcgi_pass   127.0.0.1:9002;
            fastcgi_param  SCRIPT_FILENAME  /scripts$fastcgi_script_name;
            include        fastcgi_params;
        }
        # pass db3 json to FastCGI server listening on /home/ADC/nginx/logs/db3.soc
        # ./db2jsonngix -start -connect /tmp/db3.sock ./db2jsonfcgi
        # Note: Using chroot /QOpenSys/db2sock for development db2sock,
        #       but running nginx as root /QOpenSys/QIBM/ProdData/OPS/tools/bin/nginx.
        location ~ \.db3$ {
            fastcgi_pass   unix:/QOpenSys/db2sock/tmp/db3.sock;
            fastcgi_param  SCRIPT_FILENAME  /scripts$fastcgi_script_name;
            include        fastcgi_params;
        }
        # pass the PHP scripts to FastCGI server listening on 127.0.0.1:9000
        #
        #location ~ \.php$ {
        #    root           html;
        #    fastcgi_pass   127.0.0.1:9000;
        #    fastcgi_index  index.php;
        #    fastcgi_param  SCRIPT_FILENAME  /scripts$fastcgi_script_name;
        #    include        fastcgi_params;
        #}

        # deny access to .htaccess files, if Apache's document root
        # concurs with nginx's one
        #
        #location ~ /\.ht {
        #    deny  all;
        #}
    }


    # another virtual host using mix of IP-, name-, and port-based configuration
    #
    #server {
    #    listen       8000;
    #    listen       somename:8080;
    #    server_name  somename  alias  another.alias;

    #    location / {
    #        root   html;
    #        index  index.html index.htm;
    #    }
    #}


    # HTTPS server
    #
    #server {
    #    listen       443 ssl;
    #    server_name  localhost;

    #    ssl_certificate      cert.pem;
    #    ssl_certificate_key  cert.key;

    #    ssl_session_cache    shared:SSL:1m;
    #    ssl_session_timeout  5m;

    #    ssl_ciphers  HIGH:!aNULL:!MD5;
    #    ssl_prefer_server_ciphers  on;

    #    location / {
    #        root   html;
    #        index  index.html index.htm;
    #    }
    #}

}
```


