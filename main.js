'use strict';

const http = require('http');
const fs = require('fs');

function serveStaticFile(res, path, contentType, responseCode) {
  if(!responseCode) responseCode = 200;
  fs.readFile(__dirname + path, function(err, data) {
    if(err) {
      res.writeHead(500, {'Content-Type': 'text/plain'});
      res.end('500 - Internal Error');
    } else {
      res.writeHead(responseCode, {'Content-Type': contentType});
      res.end(data);
    }
  });
}

http.createServer(function(req,res){
  // 规范化url，去掉查询字符串、可选的反斜杠，并把它变成小写
    var path = req.url.replace(/\/?(?:\?.*)?$/, '').toLowerCase();
    switch(path) {
      default:
        serveStaticFile(res, '/public/index.html', 'text/html');
        break;
  }}).listen(3000);
console.log('Server started on localhost:3000; press Ctrl-C to terminate....');