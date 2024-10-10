// MIT License
// Copyright (c) 2023 Carlos Eduardo de Borba Machado

using cp.std.testing;
using cp.std.DSL.XML;

include namespace cp;

fun xml_parse_full() {
	// arrange
	var xml = "";

	// act
	var val: Dictionary = xml_parse(xml);
	
	// assert
	assert_equals(this, null, val);
}

fun xml_stringify_full() {
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
	var val: string = xml_stringify(dict);
	
	// assert
	assert_equals(this,
		"<root><bool_true>true</bool_true><int>1</int><float>10.500000</float><char>X</char><array><item>1</item><item>2</item><item>3</item><item><bar>5</bar><qux>5</qux></item><item>true</item></array><string>this is a string</string><struct><bar>10</bar><qux>str</qux></struct><sub_dict><one>1</one><two>2</two><three>3</three></sub_dict><bool_false>false</bool_false><multi_dim_array><array><item>1</item><item>2</item><item>3</item></array><array><item>1</item><item>2</item><item>3</item></array><array><item>1</item><item>2</item><item>3</item></array></multi_dim_array></root>",
		val);
}

fun xml_test_suite() {
	xml_parse_full();
	xml_stringify_full();
}
