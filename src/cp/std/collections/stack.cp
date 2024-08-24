// stack standard lib
// MIT License
// Copyright (c) 2024 Carlos Eduardo de Borba Machado

namespace cp;

using cp.std.collections.collection;

struct Stack {
	var collection: Collection;
};

fun create_stack(): Stack {
	return Stack{collection=create_collection()};
}

fun push(stack: Stack, value: any) {
	_default_add(stack.collection, value);
}

fun pop(stack: Stack) {
	try {
		_default_remove(stack.collection);
	} catch (...) {
		throw "Tryed to pop from empty stack";
	}
}

fun peek(stack: Stack): any {
	try {
		return _default_get(stack.collection);
	} catch (...) {
		throw "Tryed to peek from empty stack";
	}
}

fun clear(stack: Stack) {
	stack = create_stack();
}

fun size(stack: Stack): int {
	return stack.collection.size;
}

fun is_empty(stack: Stack): bool {
	return stack.collection.size == 0;
}

fun to_array(stack: Stack): any[] {
	return to_array(stack.collection);
}

fun copy(stack: Stack): Stack {
	return Stack{collection=copy(stack.collection)};
}
