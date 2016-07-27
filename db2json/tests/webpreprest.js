var http = require('http');
var querystring = require('querystring');

var hostn = process.env.SQL_HOST400;
var datab = process.env.SQL_DB400;
var usern = process.env.SQL_UID400;
var passw = process.env.SQL_PWD400;
var hostp = '/db2/db2json.pgm';
var auth = "Basic " + new Buffer(usern + ":" + passw).toString("base64");
// already using Basic auth
// no need for DB2 sign-on
var myreq = 
{
 "sql": {
   "connect": {
     "qualify": "myconn"
   },
   "prepare": "select * from qiws.qcustcdt where LSTNAM like ?",
   "execute": {"parm":"J%"},
   "fetch": "*"
 }
};
var mypool = 0;
var mypoolmax = 10;
http.createServer()
.on('request', function (req1, res1) {
  mypool++;
  if (mypool > mypoolmax) {
    mypool = 1;
  }
  var myreq = 
  {
   "sql": {
     "connect": {
       "qualify": "myconn" + (mypool + '')
   },
   "prepare": "select * from qiws.qcustcdt where LSTNAM like ?",
   "execute": {"parm":"J%"},
   "fetch": "*"
   }
  };
  // console.log(myreq);
  var dataString = JSON.stringify(myreq);
  var headers = {
    "Authorization" : auth,
    'Content-Type': 'application/json',
    'Content-Length': dataString.length
  };
  var options = {
    host: hostn,
    path: hostp,
    method: 'POST',
    headers: headers,
  };
  var req2 = http.request(options, function(res2) {
    var responseString = '';
    res2.setEncoding('utf-8');
    res2.on('data', function(data) {
      responseString += data;
    });
    res2.on('end', function() {
      res1.writeHead(200, {'Content-Type': "application/json; charset=utf-8"});
      res1.write(responseString);
      res1.end();
    });
  });
  req2.write(dataString);
  req2.end();
})
.listen(8080, '0.0.0.0');
console.log('Server running at http://0.0.0.0:8080/');

