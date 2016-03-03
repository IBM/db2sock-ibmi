/* 
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

set test authorization (shell)
> export SQL_HOST400=lp0364d
> export SQL_DB400=*LOCAL
> export SQL_UID400=MYUID
> export SQL_PWD400=MYPWD
> node nodejsrest.js
*/  

var http = require('http');
var querystring = require('querystring');

var hostn = process.env.SQL_HOST400;
var datab = process.env.SQL_DB400;
var usern = process.env.SQL_UID400;
var passw = process.env.SQL_PWD400;
var hostp = '/db2/db2json.pgm';
var auth = "Basic " + new Buffer(usern + ":" + passw).toString("base64");
var myreq = 
{
 "sql": {
   "connect": {
     "database": datab,
     "user": usern,
     "password": passw,
     "qualify": "myconn"
   },
   "prepare": "select * from qiws.qcustcdt",
   "execute": null,
   "fetch": "*"
 }
};
var myjson = JSON.stringify(myreq);
console.log(myjson);

function performRequest(endpoint, method, data, success) {
  var dataString = JSON.stringify(data);
  var headers = {};
  
  if (method == 'GET') {
    headers = {
      "Authorization" : auth,
    };
    endpoint += '?' + querystring.escape(dataString);
  }
  else {
    headers = {
      "Authorization" : auth,
      'Content-Type': 'application/json',
      'Content-Length': dataString.length
    };
  }
  var options = {
    host: hostn,
    path: endpoint,
    method: method,
    headers: headers,
  };

  var req = http.request(options, function(res) {
    res.setEncoding('utf-8');

    var responseString = '';

    res.on('data', function(data) {
      responseString += data;
    });

    res.on('end', function() {
      // console.log(responseString);
      var responseObject = JSON.parse(responseString);
      success(responseObject);
    });
  });

  req.write(dataString);
  req.end();
}

function getReq(myjson) {
  performRequest(hostp, 'POST', myjson, function(data) {
    console.log(JSON.stringify(data));
  });
}

getReq(myreq);

