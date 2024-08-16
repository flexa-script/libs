// MIT License
// Copyright (c) 2023 Carlos Eduardo de Borba Machado

using cp.std.testing;
using cp.std.collections.list;

as namespace cp;

var default_list: Collection = create_collection();
add(default_list, 1);
add(default_list, 2);
add(default_list, 3);
add(default_list, 4);
add(default_list, 5);
add(default_list, 6);

fun list_add() {
  // arrange
  var list: Collection = create_collection();
  
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
  var list: Collection = create_collection();

  // act
  insert(list, 4, 0);
  insert(list, 5, 1);
  insert(list, 1, 0);
  insert(list, 2, 1);
  insert(list, 3, 2);
  insert(list, 6, 5);
  
  // assert
  assert_equals(this + "[size]", 6, list.size);
  assert_equals(this + "[content]", {1, 2, 3, 4, 5, 6}, to_array(list));
}

fun list_add_position_with_existent() {
  // arrange
  var list: Collection = create_collection();
  add(list, 1);
  add(list, 3);
  add(list, 5);
  
  // act
  insert(list, 2, 1);
  insert(list, 4, 3);
  insert(list, 0, 0);
  insert(list, 6, 6);
  
  // assert
  assert_equals(this + "[size]", 7, list.size);
  assert_equals(this + "[content]", {0, 1, 2, 3, 4, 5, 6}, to_array(list));
}

fun list_delete() {
  // arrange
  var list: Collection = unref default_list;
  
  // act
  delete(list, 0);
  delete(list, 4);
  delete(list, 1);
  
  // assert
  assert_equals(this + "[size]", 3, list.size);
  assert_equals(this + "[content]", {2, 4, 5}, to_array(list));
}

fun list_get_start() {
  // arrange
  
  // act
  var val: int = get(default_list, 0);
  
  // assert
  assert_equals(this, 1, val);
}

fun list_get_middle() {
  // arrange
  
  // act
  var val: int = get(default_list, 2);
  
  // assert
  assert_equals(this, 3, val);
}

fun list_get_end() {
  // arrange
  
  // act
  var val: int = get(default_list, 5);
  
  // assert
  assert_equals(this, 6, val);
}

fun list_test_suite() {
  list_add();
  list_add_position();
  list_add_position_with_existent();
  list_delete();
  list_get_start();
  list_get_middle();
  list_get_end();
}
