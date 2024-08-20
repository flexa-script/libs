// MIT License
// Copyright (c) 2023 Carlos Eduardo de Borba Machado

using cp.std.testing;
using cp.std.collections.dictionary;

as namespace cp;

var default_dict: Dictionary = create_dictionary();
put(default_dict, "one", 1);
put(default_dict, "two", 2);
put(default_dict, "three", 3);
put(default_dict, "four", 4);
put(default_dict, "five", 5);
put(default_dict, "six", 6);

fun dict_put() {
  // arrange
  var dict: Dictionary = create_dictionary();
  
  // act
  put(default_dict, "one", 1);
  put(default_dict, "two", 2);
  put(default_dict, "three", 3);
  
  // assert
  assert_equals(this + "[size]", 3, size(dict));
  assert_equals(this + "[content]", {Pair{key="one", value=1}, Pair{key="two", value=2}, Pair{key="three", value=3}}, to_array(dict));
}

// fun dict_pop() {
//   // arrange
//   var dict: Dictionary = copy(default_dict);
  
//   // act
//   pop(dict);
//   pop(dict);
//   pop(dict);
  
//   // assert
//   assert_equals(this + "[size]", 3, dict.size);
//   assert_equals(this + "[content]", {1, 2, 3}, to_array(dict));
// }

// fun dict_peek() {
//   // arrange
  
//   // act
//   var val: int = peek(default_dict);
  
//   // assert
//   assert_equals(this, 6, val);
// }

fun dict_test_suite() {
  dict_put();
  // dict_pop();
  // dict_peek();
}
