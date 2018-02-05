"use strict";

let cutting_list = new Array();

$( document ).ready(function() {
 
    $( "#add_cutting_len" ).click(function( event ) {
		let  ele = $("<input/>");
		ele.attr("type", "checkbox");
		let tips = $("#cutting_len").val();
    	$("#cutting_list_title").append("<br/>", ele, tips);
    	let cut_ele = {};
    	cut_ele.value = $("#cutting_len").val();
    	cut_ele.selected = true;
    	cutting_list.push(cut_ele);
    	
    	alert(cutting_list[cutting_list.length - 1]);
    });
});
