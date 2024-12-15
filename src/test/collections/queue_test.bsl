// MIT License
// Copyright (c) 2023 Carlos Eduardo de Borba Machado

using bsl.std.testing;
using bsl.std.collections.queue;

include namespace bsl;

var default_queue: Queue = create_queue();
enqueue(default_queue, 1);
enqueue(default_queue, 2);
enqueue(default_queue, 3);
enqueue(default_queue, 4);
enqueue(default_queue, 5);
enqueue(default_queue, 6);

fun queue_enqueue() {
	// arrange
	var queue: Queue = create_queue();
	
	// act
	enqueue(queue, 1);
	enqueue(queue, 2);
	enqueue(queue, 3);
	
	// assert
	assert_equals(this + "[size]", 3, size(queue));
	assert_equals(this + "[content]", {1, 2, 3}, to_array(queue));
}

fun queue_dequeue() {
	// arrange
	var queue: Queue = copy(default_queue);
	
	// act
	dequeue(queue);
	dequeue(queue);
	dequeue(queue);
	
	// assert
	assert_equals(this + "[size]", 3, size(queue));
	assert_equals(this + "[content]", {4, 5, 6}, to_array(queue));
}

fun queue_front() {
	// arrange
	
	// act
	var val: int = front(default_queue);
	
	// assert
	assert_equals(this, 1, val);
}

fun queue_back() {
	// arrange
	
	// act
	var val: int = back(default_queue);
	
	// assert
	assert_equals(this, 6, val);
}

fun queue_test_suite() {
	queue_enqueue();
	queue_dequeue();
	queue_front();
	queue_back();
}
