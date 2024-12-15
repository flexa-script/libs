// MIT License
// Copyright (c) 2023 Carlos Eduardo de Borba Machado

using bsl.std.testing;
using bsl.std.collections.stack;

include namespace bsl;

var default_stack: Stack = create_stack();
push(default_stack, 1);
push(default_stack, 2);
push(default_stack, 3);
push(default_stack, 4);
push(default_stack, 5);
push(default_stack, 6);

fun stack_push() {
	// arrange
	var stack: Stack = create_stack();
	
	// act
	push(stack, 1);
	push(stack, 2);
	push(stack, 3);
	
	// assert
	assert_equals(this + "[size]", 3, size(stack));
	assert_equals(this + "[content]", {1, 2, 3}, to_array(stack));
}

fun stack_pop() {
	// arrange
	var stack: Stack = copy(default_stack);
	
	// act
	pop(stack);
	pop(stack);
	pop(stack);
	
	// assert
	assert_equals(this + "[size]", 3, size(stack));
	assert_equals(this + "[content]", {1, 2, 3}, to_array(stack));
}

fun stack_peek() {
	// arrange
	
	// act
	var val: int = peek(default_stack);
	
	// assert
	assert_equals(this, 6, val);
}

fun stack_test_suite() {
	stack_push();
	stack_pop();
	stack_peek();
}
