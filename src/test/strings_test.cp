// MIT License
// Copyright (c) 2023 Carlos Eduardo de Borba Machado

using cp.std.testing;
using cp.std.strings;

as namespace cp;

fun str_size() {
  // arrange
  var s: string = "123456";
  
  // act
  var res: int = strlen(s);
  
  // assert
  assert_equals(this, 6, res);
}

fun str_substring_start() {
  // arrange
  var s: string = "1234567890";
  
  // act
  var res: string = substr(s, 0, 5);
  
  // assert
  assert_equals(this, "12345", res);
}

fun str_substring_midle() {
  // arrange
  var s: string = "1234567890";
  
  // act
  var res: string = substr(s, 2, 7);
  
  // assert
  assert_equals(this, "34567", res);
}

fun str_substring_end() {
  // arrange
  var s: string = "1234567890";
  
  // act
  var res: string = substr(s, 5, 9);
  
  // assert
  assert_equals(this, "67890", res);
}

fun str_substring_endless() {
  // arrange
  var s: string = "1234567890";
  
  // act
  var res: string = substr(s, 5);
  
  // assert
  assert_equals(this, "67890", res);
}

fun strings_test_suite() {
  str_size();
  str_substring_start();
  str_substring_midle();
  str_substring_endless();
}
