// MIT License
// Copyright (c) 2023 Carlos Eduardo de Borba Machado

using cp.std.testing;
using cp.std.DSL.BPS;

include namespace cp;

fun bps_parse_full() {
	// arrange
	var bps = "";
	
	// act
	var val: Dictionary = bps_parse(bps);
	
	// assert
	assert_equals(this, null, val);
}

fun bps_stringify_full() {
	// arrange
	struct Foo {
		var bar: int;
		var qux: string;
	};

	var sub_dict: Dictionary = create_dictionary();
	emplace(sub_dict, "one", 1);
	emplace(sub_dict, "two", 2);
	emplace(sub_dict, "three", 3);
	var dict: Dictionary = create_dictionary();
	emplace(dict, "bool_true", true);
	emplace(dict, "bool_false", false);
	emplace(dict, "int", 1);
	emplace(dict, "float", 10.5);
	emplace(dict, "char", 'X');
	emplace(dict, "string", "this is a string");
	emplace(dict, "array", {1, '2', "3", Foo{bar=5,qux="5"}, true});
	emplace(dict, "multi_dim_array", {{1, 2, 3}, {1, 2, 3}, {1, 2, 3}});
	emplace(dict, "struct", Foo{bar=10,qux="str"});
	emplace(dict, "sub_dict", sub_dict);
	
	// act
	var val: string = bps_stringify(dict);
	
	// assert
	assert_equals(this,
		"bool_true:true;int:1;float:10.500000;char:'X';array:[1,'2',\"3\",bar:5;qux:\"5\";,true];string:\"this is a string\";struct:bar:10;qux:\"str\";;sub_dict:one:1;two:2;three:3;;bool_false:false;multi_dim_array:[[1,2,3],[1,2,3],[1,2,3]];",
		val);
}

fun bps_test_suite() {
	bps_parse_full();
	bps_stringify_full();
}
