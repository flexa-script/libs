// MIT License
// Copyright (c) 2023 Carlos Eduardo de Borba Machado

using cp.std.testing;
using cp.std.collections.dictionary;

as namespace cp;

var default_dict: Dictionary = create_dictionary();
emplace(default_dict, "one", 1);
emplace(default_dict, "two", 2);
emplace(default_dict, "three", 3);
emplace(default_dict, "four", 4);
emplace(default_dict, "five", 5);
emplace(default_dict, "six", 6);

fun _arr_pair_comparator(rval[]: Pair, lval[]: Pair) {
	if (len(rval) != len(lval)) {
		return false;
	}
	for (var i = 0; i < len(rval); i++) {
		if (lval[i] == null or rval[i] == null) {
			if (lval[i] == rval[i]) {
				continue;
			}
			return false;
		}
		if (rval[i].key != lval[i].key) {
			return false;
		}
	}
	return true;
}

fun _pair_comparator(rval: Pair, lval: Pair) {
	return rval.key == lval.key;
}

fun dict_emplace() {
	// arrange
	var dict: Dictionary = create_dictionary();
	
	// act
	emplace(dict, "one", 1);
	emplace(dict, "two", 2);
	emplace(dict, "three", 3);
	
	// assert
	assert_equals(this + "[size]", 3, size(dict));
	assert_equals(this + "[content]", {Pair{key="one", value=1}, Pair{key="two", value=2}, Pair{key="three", value=3}}, to_array(dict), _arr_pair_comparator);
}

fun dict_erase() {
	// arrange
	var dict: Dictionary = copy(default_dict);
	
	// act
	erase(dict, "two");
	erase(dict, "four");
	erase(dict, "six");
	
	// assert
	assert_equals(this + "[size]", 3, size(dict));
	assert_equals(this + "[content]", {Pair{key="one", value=1}, Pair{key="three", value=3}, Pair{key="five", value=5}}, to_array(dict), _arr_pair_comparator);
}

fun dict_find() {
	// arrange
	
	// act
	var val: int = find(default_dict, "four");
	
	// assert
	assert_equals(this, 4, val);
}

fun dict_stringfy() {
	// arrange
	struct Foo {
		var bar: int;
		var qux: string;
	};

	var dict: Dictionary = create_dictionary();
	emplace(dict, "bool_true", true);
	emplace(dict, "bool_false", false);
	emplace(dict, "int", 1);
	emplace(dict, "float", 10.5);
	emplace(dict, "char", "this is a char");
	emplace(dict, "string", "this is a string");
	emplace(dict, "array", {1, '2', "3", Foo{bar=5,qux="5"}, true});
	emplace(dict, "multi_dim_array", {{1, 2, 3}, {1, 2, 3}, {1, 2, 3}});
	emplace(dict, "struct", Foo{bar=10,qux="str"});
	emplace(dict, "sub_dict", default_dict);
	
	// act
	var valx: string = stringfy(dict);
	
	// assert
	assert_equals(this,
		"{\"bool_true\":true,\"int\":1,\"float\":10.500000,\"char\":\"this is a char\",\"array\":[1,\"2\",\"3\",{\"bar\":5,\"qux\":\"5\"},true],\"string\":\"this is a string\",\"struct\":{\"bar\":10,\"qux\":\"str\"},\"sub_dict\":{\"one\":1,\"two\":2,\"six\":6,\"three\":3,\"four\":4,\"five\":5},\"bool_false\":false,\"multi_dim_array\":[[1,2,3],[1,2,3],[1,2,3]]}",
		valx);
}

fun dictionary_test_suite() {
	dict_emplace();
	dict_erase();
	dict_find();
	dict_stringfy();
}
