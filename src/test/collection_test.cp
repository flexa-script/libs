// MIT License
// Copyright (c) 2023 Carlos Eduardo de Borba Machado

using cp.std.testing;
using cp.std.collections.list;

as namespace cp;

var default_collection: Collection = create_collection();
add(default_collection, 1);
add(default_collection, 2);
add(default_collection, 3);
add(default_collection, 4);
add(default_collection, 5);
add(default_collection, 6);

fun collection_is_empty() {
  // arrange
  var collection: Collection = create_collection();
  
  // act
  var res: bool = is_empty(collection);
  
  // assert
  assert_true(this, res);
}

fun collection_is_not_empty() {
  // arrange
  
  // act
  var res: bool = is_empty(default_collection);
  
  // assert
  assert_false(this, res);
}

fun collection_is_empty_removed() {
  // arrange
  var collection: Collection = unref default_collection;
  remove(collection, 0);
  remove(collection, 0);
  remove(collection, 0);
  remove(collection, 0);
  remove(collection, 0);
  remove(collection, 0);
  
  // act
  var res: bool = is_empty(collection);
  
  // assert
  assert_true(this, res);
}

fun collection_is_empty_cleared() {
  // arrange
  var collection: Collection = unref default_collection;
  clear(collection);
  
  // act
  var res: bool = is_empty(collection);
  
  // assert
  assert_true(this, res);
}

fun collection_test_suite() {
  collection_is_empty();
  collection_is_not_empty();
  collection_is_empty_removed();
  collection_is_empty_cleared();
}
