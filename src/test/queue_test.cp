// MIT License
// Copyright (c) 2023 Carlos Eduardo de Borba Machado

using cp.std.testing;
using cp.std.collections.queue;

as namespace cp;

var default_queue: Collection = create_collection();
enqueue(default_queue, 1);
enqueue(default_queue, 2);
enqueue(default_queue, 3);
enqueue(default_queue, 4);
enqueue(default_queue, 5);
enqueue(default_queue, 6);

fun queue_enqueue() {
  // arrange
  var queue: Collection = create_collection();
  
  // act
  enqueue(queue, 1);
  enqueue(queue, 2);
  enqueue(queue, 3);
  
  // assert
  assert_equals(this + "[size]", 3, queue.size);
  assert_equals(this + "[content]", {1, 2, 3}, to_array(queue));
}

fun queue_dequeue() {
  // arrange
  var queue: Collection = unref default_queue;
  
  // act
  dequeue(queue);
  dequeue(queue);
  dequeue(queue);
  
  // assert
  assert_equals(this + "[size]", 3, queue.size);
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
  // queue_dequeue();
  // queue_front();
  // queue_back();
}
