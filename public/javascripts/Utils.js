'use strict';

let DataUnit = function(len, sel) {
	this.length = len;
	this.selected = sel;
}

let CuttingData = function(socket, data) {
	this.socket = socket;
	this.dataList = new Array();
	if(data) {
		for(let i = 0; i < data.length(); i++) {
			this.dataList.push(data[i]);	//copy the data
		}
	}

}

CuttingData.prototype.AddCuttingUnit = function (unit) {
	for(let i = 0; i < this.dataList.length(); i++) {
		if(this.dataList[i].length === unit.length) {
			return false;
		}
	}
	this.dataList.push(unit);
	return true;
}

CuttingData.prototype.RemoveCuttingUnit = function (unit) {
	for(let i = 0; i < this.dataList.length(); i++) {
		if(this.dataList[i].length === unit.length) {
			delete this.dataList[i];
			return true;
		}
	}
	return false;
}

CuttingData.prototype.processCommand = function(command) {
	switch(command) {
		default:
			return false;

		case 'clear':
			this.dataList.splice(0, this.dataList.length());
			break;

		case 'pullData':
			this.socket.emit('pullData');
			break;

		case 'pushData':
			this.socket.emit('pushData');
			break;
	}

	return true;
}