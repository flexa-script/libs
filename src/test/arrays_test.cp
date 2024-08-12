// MIT License
// Copyright (c) 2023 Carlos Eduardo de Borba Machado

using cp.std.testing;
using cp.std.arrays;

as namespace cp;

fun calc_arr_size() {
  // arrange
  var arr = {1, 2, 3, 4, 5, 6};
  
  // act
  var res: int = size(arr);
  
  // assert
  assert_equals(this, 6, res);
}

fun contains() {
  // arrange
  var val = 3;
  var arr = {1, 2, 3, 4, 5, 6};
  
  // act
  var res: bool = contains(arr, val);
  
  // assert
  assert_true(this, res);
}

fun contains_start() {
  // arrange
  var val = 1;
  var arr = {1, 2, 3, 4, 5, 6};
  
  // act
  var res: bool = contains(arr, val);
  
  // assert
  assert_true(this, res);
}

fun contains_end() {
  // arrange
  var val = 6;
  var arr = {1, 2, 3, 4, 5, 6};
  
  // act
  var res: bool = contains(arr, val);
  
  // assert
  assert_true(this, res);
}

fun not_contains() {
  // arrange
  var val = 10;
  var arr = {1, 2, 3, 4, 5, 6};
  
  // act
  var res: bool = contains(arr, val);
  
  // assert
  assert_false(this, res);
}

fun contains_ref() {
  // arrange
  var val = 3;
  var arr = {1, 2, val, 4, 5, 6};
  
  // act
  var res: bool = contains_ref(arr, ref val);
  
  // assert
  assert_true(this, res);
}

fun contains_start_ref() {
  // arrange
  var val = 1;
  var arr = {val, 2, 3, 4, 5, 6};
  
  // act
  var res: bool = contains_ref(arr, ref val);
  
  // assert
  assert_true(this, res);
}

fun contains_end_ref() {
  // arrange
  var val = 6;
  var arr = {1, 2, 3, 4, 5, val};
  
  // act
  var res: bool = contains_ref(arr, ref val);
  
  // assert
  assert_true(this, res);
}

fun not_contains_ref() {
  // arrange
  var arr = {1, 2, 3, 4, 5, 6};
  
  // act
  var res: bool = contains_ref(arr, ref 10);
  
  // assert
  assert_false(this, res);
}

fun not_contains_start_ref() {
  // arrange
  var arr = {1, 2, 3, 4, 5, 6};
  
  // act
  var res: bool = contains_ref(arr, ref 1);
  
  // assert
  assert_true(this, res);
}

fun not_contains_end_ref() {
  // arrange
  var arr = {1, 2, 3, 4, 5, 6};
  
  // act
  var res: bool = contains_ref(arr, ref 6);
  
  // assert
  assert_true(this, res);
}

fun arrays_test_suite() {
  calc_arr_size();
  contains();
  contains_start();
  contains_end();
  not_contains();
  contains_ref();
  contains_start_ref();
  contains_end_ref();
  not_contains_start_ref();
  not_contains_end_ref();
  not_contains_ref();
}
