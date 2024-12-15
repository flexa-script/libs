// MIT License
// Copyright (c) 2023 Carlos Eduardo de Borba Machado

using bsl.std.testing;
using bsl.std.collections.hashtable;

include namespace bsl;

var default_hashtable: Hashtable = create_hashtable();
put(default_hashtable, "one", 1);
put(default_hashtable, "two", 2);
put(default_hashtable, "three", 3);
put(default_hashtable, "four", 4);
put(default_hashtable, "five", 5);
put(default_hashtable, "six", 6);

fun _ht_arr_pair_comparator(rval[]: Pair, lval[]: Pair) {
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

fun hashtable_get() {
	// arrange
	
	// act
	var val: int = get(default_hashtable, "four");
	
	// assert
	assert_equals(this, 4, val);
}

fun hashtable_put() {
	// arrange
	var hashtable: Hashtable = create_hashtable();
	
	// act
	put(hashtable, "one", 1);
	put(hashtable, "two", 2);
	put(hashtable, "three", 3);
	
	// assert
	assert_equals(this + "[size]", 3, size(hashtable));
	assert_equals(this + "[content]", {Pair{key="one", value=1}, Pair{key="two", value=2}, Pair{key="three", value=3}}, to_array(hashtable), _ht_arr_pair_comparator);
}

fun hashtable_delete() {
	// arrange
	var hashtable: Hashtable = copy(default_hashtable);
	
	// act
	delete(hashtable, "two");
	delete(hashtable, "four");
	delete(hashtable, "six");
	
	// assert
	assert_equals(this + "[size]", 3, size(hashtable));
	assert_equals(this + "[content]", {Pair{key="one", value=1}, Pair{key="three", value=3}, Pair{key="five", value=5}}, to_array(hashtable), _ht_arr_pair_comparator);
}

fun hashtable_test_suite() {
	hashtable_get();
	hashtable_put();
	hashtable_delete();
}
