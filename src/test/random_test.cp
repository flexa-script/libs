// MIT License
// Copyright (c) 2023 Carlos Eduardo de Borba Machado

using cp.std.testing;
using cp.std.random;

include namespace cp;

fun rand_int_range() {
	// arrange
	var min: int = 500;
	var max: int = 600;
	
	// act
	var res: int = randi_range(min, max);
	
	// assert
	assert_between(this, min, max, res);
}

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
	rand_int_range();
	rand_float_range();
}
