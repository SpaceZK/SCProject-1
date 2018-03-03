'use strict';

let DataUnit = function(len, sel) {
	this.length = len;
	this.selected = sel;
}

let CuttingData = function(socket) {
	this.socket = socket;
	this.dataList = new Array();
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

CuttingData.prototype.LoadDataList = function(datLst) {
	this.dataList.clear();
	for(let i = 0; i < datLst.length(); i++) {
		this.dataList.push(datLst[i]);
	}
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