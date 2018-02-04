"use strict";

function createFragment(iLen, bSel) {
	this.len = iLen;		//integer
	this.sel = bSel;		//true/false
}

function getInstance() {
    let name = "Mozilla"; 
    // name 是一个被init创建的局部变量
    function displayName() { 
    // displayName() 是一个内部函数,
        console.log(`name = ${name}`); 
        //  一个闭包使用在父函数中声明的变量
    } 
    displayName();
}