'use strict';

const socketio = require('socket.io');
const redis = require('redis');

let io;

exports.listen = function(server) {
	io = socketio.listen(server);
	io.set('log level', 1);

	io.sockets.on('connection', function(socket) {
		console.log('a data client connection');

		//handle data client messages
		handleClientMessages(socket);
	});
};

function handleClientMessages(socket) {
	socket.on('clear', function() {
		//clear the data in redis db
	});

	socket.on('pullData', function() {
		//push the data in server to the client
		console.log('client request pullData');
		//load dat from redis
		//socket.emit('updateDataList', {dataList: dat});
	});

	socket.on('pushData', function() {
		//update data in db from client pushing
	});
}

function clearCuttingData() {
	
}