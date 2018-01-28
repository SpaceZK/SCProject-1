"use strict";

let count = 0;

$( document ).ready(function() {
 
    $( "#add_cutting_len" ).click(function( event ) {
		let  ele = $("<input/>");
		ele.attr("type", "checkbox");
		let tips = $("#cutting_len").val();
    	$("#cutting_list_title").append("<br/>", ele, tips);
    });
});