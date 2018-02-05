"use strict";

const redis = require("redis");
const redis_config = {
    "host": "127.0.0.1",
    "port": 6379
};

let redisClient = redis.createClient(redis_config);

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

function getFragmentList() {
    let frag_list;

    function getDataFromRedis() {
        if(frag_list == undefined) {
            //read frag_list from database
        }
        return frag_list;
    }
}
/**** just for test *****/
redisClient.hkeys("hash key", function(err, replies) {
    console.log(replies.length + " replies: ");
    replies.forEach(function (reply, i) {
        console.log("  " + i + ": " + reply);
    });
    redisClient.quit();
});
/*
*/