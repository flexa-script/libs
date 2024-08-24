// MIT License
// Copyright (c) 2023 Carlos Eduardo de Borba Machado

using cp.std.testing;
using cp.std.math;

as namespace cp;

fun abs_positive() {
	// arrange
	var num: float = 6.667;
	
	// act
	var res: float = abs(num);
	
	// assert
	assert_equals("abs_positive", 6.667, res);
}

fun abs_negative() {
	// arrange
	var num: float = -6.667;
	
	// act
	var res: float = abs(num);
	
	// assert
	assert_equals("abs_negative", 6.667, res);
}

fun clamp_greater() {
	// arrange
	var num: float = 10;
	var min: float = -5;
	var max: float = 5;
	
	// act
	var res: float = clamp(num, min, max);
	
	// assert
	assert_equals("clamp_greater", 5f, res);
}

fun clamp_lower() {
	// arrange
	var num: float = -10;
	var min: float = -5;
	var max: float = 5;
	
	// act
	var res: float = clamp(num, min, max);
	
	// assert
	assert_equals("clamp_lower", -5., res);
}

fun clamp_between() {
	// arrange
	var num: float = 0;
	var min: float = -5;
	var max: float = 5;
	
	// act
	var res: float = clamp(num, min, max);
	
	// assert
	assert_equals("clamp_between", 0., res);
}

fun round_higher_low_limit() {
	// arrange
	var num: float = 1.5;
	
	// act
	var res: int = round(num);
	
	// assert
	assert_equals(this, 2, res);
}

fun round_higher_high_limit() {
	// arrange
	var num: float = 1.9;
	
	// act
	var res: int = round(num);
	
	// assert
	assert_equals(this, 2, res);
}

fun round_higher_mid_limit() {
	// arrange
	var num: float = 1.7;
	
	// act
	var res: int = round(num);
	
	// assert
	assert_equals(this, 2, res);
}

fun math_test_suite() {
	abs_positive();
	abs_negative();

	clamp_greater();
	clamp_lower();
	clamp_between();

	round_higher_low_limit();
	round_higher_high_limit();
	round_higher_mid_limit();

}
