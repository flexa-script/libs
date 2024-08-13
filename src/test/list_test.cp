// MIT License
// Copyright (c) 2023 Carlos Eduardo de Borba Machado

using cp.std.testing;
using cp.std.collections.list;

as namespace cp;

fun list_add() {
  // arrange
  var list: List = create_list();
  
  // act
  add(list, 1);
  add(list, 2);
  add(list, 3);
  
  // assert
  assert_equals(this + "[size]", 3, list.size);
  assert_equals(this + "[content]", {1, 2, 3}, to_array(list));
}

fun list_add_position() {
  // arrange
  var list: List = create_list();
  
  // act
  add(list, 1);
  add(list, 3);
  add(list, 5);
  add(list, 2, 1);
  add(list, 4, 3);
  add(list, 0, 0);
  add(list, 6, 6);
  
  // assert
  assert_equals(this + "[size]", 7, list.size);
  assert_equals(this + "[content]", {0, 1, 2, 3, 4, 5, 6, 7}, to_array(list));
}

fun list_test_suite() {
  list_add();
  list_add_position();
}
