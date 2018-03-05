const http = require('http');
const fs = require('fs');
const path = require('path');
const mime = require('mime');
const port = 9877;
var cache = {};

function send404(response) {
	response.writeHead(404, {'Content-Type': 'text/plain'});
	response.write('Error 404: resource not found.');
	response.end();
}

function sendFile(response, filePath, fileContents) {
	response.writeHead(200, {'Content-Type': mime.getType(path.basename(filePath))});
	response.end(fileContents);
}

function serveStatic(response, cache, absPath) {
	if(cache[absPath]) {
		sendFile(response, absPath, cache[absPath]);
	} else {
		fs.exists(absPath, function(exists) {
			if(exists) {
				fs.readFile(absPath, function(err, data) {
					if(err) {
						send404(response);
					} else {
						cache[absPath] = data;
						sendFile(response, absPath, data);
					}
				});
			} else {
				send404(response);
			}
		});
	}
}

var server = http.createServer(function(request, response) {
	var filePath = false;
	if(request.url == '/') {
		filePath = 'public/index.html';
	} else {
		filePath = 'public' + request.url;
	}

	var absPath = './' + filePath;
	serveStatic(response, cache, absPath);
});

server.listen(port, function() {
	console.log('Server listening on port ' + port);
});

var dataServer = require('./lib/data_server.js');
dataServer.listen(server);