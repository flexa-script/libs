// MIT License
// Copyright (c) 2023 Carlos Eduardo de Borba Machado

using cp.std.testing;
using cp.std.random;

as namespace cp;

fun rand_float_range() {
  // arrange
  var min: float = 0.1;
  var max: float = 0.8;
  
  // act
  var res: float = randf_range(min, max);
  
  // assert
  assert_between(this, min, max, res);
}

fun random_test_suite() {
  rand_float_range();
}
