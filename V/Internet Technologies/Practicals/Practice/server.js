var http = require('http');

var hostname = 'localhost';
var port = 10_000;

var server = http.createServer((req, res) => {
  res.statusCode = 200; // response status code
  res.setHeader('Content-Type', 'text/plain'); // response header type
  res.end('Hello World!, This is my Nodejs server.'); // end() is used that this is the last thing u can write in response
});

server.listen(port, hostname, () => {
  console.log(`Server running at http://${hostname}:${port}/`);
});