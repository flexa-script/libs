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
			return false;
		}
		if (rval[i].key != lval[i].key) {
			return false;
		}
    }
    return true;
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
	assert_equals(this + "[size]", 3, dict.size);
	assert_equals(this + "[content]", {Pair{key="one", value=1}, Pair{key="three", value=2}, Pair{key="five", value=3}}, to_array(dict), _arr_pair_comparator);
}

// fun dict_peek() {
//   // arrange
  
//   // act
//   var val: int = peek(default_dict);
  
//   // assert
//   assert_equals(this, 6, val);
// }

fun dictionary_test_suite() {
  dict_emplace();
  dict_erase();
  // dict_peek();
}
