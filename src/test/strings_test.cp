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

fun str_counts() {
  // arrange
  var s: string = "1234567890123123";
  
  // act
  var res: int = counts(s, "123");
  
  // assert
  assert_equals(this, 3, res);
}

fun str_counts_0() {
  // arrange
  var s: string = "123456780123123";
  
  // act
  var res: int = counts(s, "9");
  
  // assert
  assert_equals(this, 0, res);
}

fun str_contains_start() {
  // arrange
  var s: string = "1234567890";
  
  // act
  var res: bool = contains(s, "123");
  
  // assert
  assert_true(this, res);
}

fun str_contains_end() {
  // arrange
  var s: string = "1234567890";
  
  // act
  var res: bool = contains(s, "7890");
  
  // assert
  assert_true(this, res);
}

fun str_contains_midle() {
  // arrange
  var s: string = "1234567890";
  
  // act
  var res: bool = contains(s, "4567");
  
  // assert
  assert_true(this, res);
}

fun str_contains_all() {
  // arrange
  var s: string = "1234567890";
  
  // act
  var res: bool = contains(s, "1234567890");
  
  // assert
  assert_true(this, res);
}

fun str_not_contains() {
  // arrange
  var s: string = "1234567890";
  
  // act
  var res: bool = contains(s, "abc");
  
  // assert
  assert_false(this, res);
}

fun str_not_contains_part() {
  // arrange
  var s: string = "1234567890";
  
  // act
  var res: bool = contains(s, "1258");
  
  // assert
  assert_false(this, res);
}

fun str_starts_with() {
  // arrange
  var s: string = "1234567890";
  
  // act
  var res: bool = starts_with(s, "123");
  
  // assert
  assert_true(this, res);
}

fun str_starts_with_false() {
  // arrange
  var s: string = "1234567890";
  
  // act
  var res: bool = starts_with(s, "890");
  
  // assert
  assert_false(this, res);
}

fun str_ends_with() {
  // arrange
  var s: string = "1234567890";
  
  // act
  var res: bool = ends_with(s, "123");
  
  // assert
  assert_false(this, res);
}

fun str_ends_with_false() {
  // arrange
  var s: string = "1234567890";
  
  // act
  var res: bool = ends_with(s, "890");
  
  // assert
  assert_true(this, res);
}

fun str_join_any_ret() {
  // arrange
  
  // act
  var res: string = join("12", 34, '5', 6789f);
  
  // assert
  assert_equals(this, "123456789.000000", res);
}

fun str_join_any_ret2() {
  // arrange
  var v1: any = "12";
  var v2: any = 34;
  var v3: any = '5';
  var v4: any = 6789f;
  
  // act
  var res: string = join(v1, v2, v3, v4);
  
  // assert
  assert_equals(this, "123456789.000000", res);
}

fun str_join_type_ret() {
  // arrange
  var v1: string = "12";
  var v2: int = 34;
  var v3: char = '5';
  var v4: float = 6789;
  
  // act
  var res: string = join(v1, v2, v3, v4);
  
  // assert
  assert_equals(this, "123456789.000000", res);
}

fun str_join_any_arr() {
  // arrange
  
  // act
  var res: string = join({"12", 34, '5', 6789f});
  
  // assert
  assert_equals(this, "123456789.000000", res);
}

fun str_join_any_arr2() {
  // arrange
  var v: any = {"12", 34, '5', 6789f};
  
  // act
  var res: string = join(v);
  
  // assert
  assert_equals(this, "123456789.000000", res);
}

fun str_join_type_arr() {
  // arrange
  var v[]: string = {"12", "34", "5", "6789"};
  
  // act
  var res: string = join(v);
  
  // assert
  assert_equals(this, "123456789", res);
}

fun str_left_trim() {
  // arrange
  var v: string = "   123456789";
  
  // act
  var res: string = left_trim(v);
  
  // assert
  assert_equals(this, "123456789", res);
}

fun str_right_trim() {
  // arrange
  var v: string = "123456789   ";
  
  // act
  var res: string = right_trim(v);
  
  // assert
  assert_equals(this, "123456789", res);
}

fun str_trim() {
  // arrange
  var v: string = "   123456789   ";
  
  // act
  var res: string = trim(v);
  
  // assert
  assert_equals(this, "123456789", res);
}

fun str_split_ms() {
  // arrange
  var v: string = "123456123789123987123";
  
  // act
  var res[]: string = split(v, "123");
  
  // assert
  assert_equals(this, {"", "456", "789", "987", ""}, res);
}

fun strings_test_suite() {
  str_size();
  str_substring_start();
  str_substring_midle();
  str_substring_endless();
  str_counts();
  str_counts_0();
  str_contains_start();
  str_contains_end();
  str_contains_midle();
  str_contains_all();
  str_not_contains();
  str_not_contains_part();
  str_starts_with();
  str_starts_with_false();
  str_ends_with();
  str_ends_with_false();
  str_join_any_ret();
  str_join_any_ret2();
  str_join_type_ret();
  str_join_any_arr();
  str_join_type_arr();
  str_left_trim();
  str_right_trim();
  str_trim();
  str_split_ms();
}
