var http = require('http');

http.createServer()
.on('request', function (req, res) {
    res.writeHead(200, {'Content-Type': "text/plain; charset=utf-8"});
    res.write("Hello World");
    res.end();
})
.listen(8080, '0.0.0.0');
console.log('Server running at http://0.0.0.0:8080/');

