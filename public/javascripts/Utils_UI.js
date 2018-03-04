'use strict';

let socket = io.connect();

//let cuttingData = new CuttingData(socket);

handleServerEvents(socket);

$(document).ready(function() {
	$('#add_cutting_len').click(function() {
		//alert('request pullData');
		socket.emit('pullData', {});
	});

	$('#push_data').click(function() {
		//alert('emit pushData');
		socket.emit('pushData', {data: 'test'});
	});
});

function handleServerEvents(sock) {
	sock.on('updateDataList', function(data) {
		alert(JSON.stringify(data));
	});
}