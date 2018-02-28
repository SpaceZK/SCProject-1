'use strict';

alert('Loading script Utils_UI.js');

let socket = io.connect();

//let cuttingData = new CuttingData(socket);

handleServerEvents(socket);

$(document).ready(function() {
	$('#add_cutting_len').click(function() {
		alert('request pullData');
		socket.emit('pullData', {});
	});
});

function handleServerEvents(sock) {
	sock.on('updateDataList', function(data) {
	});
}