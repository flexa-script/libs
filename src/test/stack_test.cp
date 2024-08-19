// MIT License
// Copyright (c) 2023 Carlos Eduardo de Borba Machado

using cp.std.testing;
using cp.std.collections.stack;

as namespace cp;

var default_stack: Collection = create_collection();
push(default_stack, 1);
push(default_stack, 2);
push(default_stack, 3);
push(default_stack, 4);
push(default_stack, 5);
push(default_stack, 6);

fun stack_push() {
  // arrange
  var stack: Collection = create_collection();
  
  // act
  push(stack, 1);
  push(stack, 2);
  push(stack, 3);
  
  // assert
  assert_equals(this + "[size]", 3, stack.size);
  assert_equals(this + "[content]", {1, 2, 3}, to_array(stack));
}

fun stack_pop() {
  // arrange
  var stack: Collection = copy(default_stack);
  
  // act
  pop(stack);
  pop(stack);
  pop(stack);
  
  // assert
  assert_equals(this + "[size]", 3, stack.size);
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
