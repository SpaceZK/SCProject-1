const socketio = require('socket.io');
const redis = require('redis');

const redisConfig = {
	'host': '127.0.0.1',
	'port': 6379
};
const redisDBNum = '0';
const hkCuttingList = 'cutting list';
const listNum = '1';
var redisClient = redis.createClient(redisConfig);
redisClient.on('error', function (err) {
	console.log('create client error: ' + err);
});

redisClient.select(redisDBNum, function(err) {
	if(err) {
		console.log('select redis database error');
	} else {
		console.log('select database successfully');
	}
});

var io;

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
        redisClient.hgetall(hkCuttingList, function(err, data){
            if(err) {
                console.log(err);
            } else {
                console.log(JSON.stringify(data));
                socket.emit('updateDataList', {dataList: data});
            }
		});
	});

	socket.on('pushData', function(data) {
		//update data in db from client pushing
		//redisClient.hmset
		console.log(JSON.stringify(data));

		//client.set("hashtest 1", "some value", redis.print);
	});
}

function clearCuttingData() {

}