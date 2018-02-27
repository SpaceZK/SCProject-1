'use strict';

alert('Loading script Utils_UI.js');

let socket = io.connect();

$(document).ready(function() {
	let cuttingData = new CuttingData(socket);
	
});