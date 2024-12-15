// queue standard lib
// MIT License
// Copyright (c) 2024 Carlos Eduardo de Borba Machado

namespace bsl;

using bsl.std.collections.collection;

struct Queue {
	var collection: Collection;
};

fun create_queue(): Queue {
	return Queue{collection=create_collection()};
}

fun enqueue(queue: Queue, value: any) {
	_default_add(queue.collection, value);
}

fun dequeue(queue: Queue) {
	if (queue.collection.first == null) {
		throw "Tryed dequeue from empty collection";
	}

	queue.collection.first = queue.collection.first.next;
	queue.collection.size--;
}

fun front(queue: Queue): any {
	if (queue.collection.first == null) {
		throw "Tryed to get from empty collection";
	}

	return queue.collection.first.value;
}

fun back(queue: Queue): any {
	return _default_get(queue.collection);
}

fun clear(queue: Queue) {
	queue = create_queue();
}

fun size(queue: Queue): int {
	return queue.collection.size;
}

fun is_empty(queue: Queue): bool {
	return queue.collection.size == 0;
}

fun to_array(queue: Queue): any[] {
	return to_array(queue.collection);
}

fun copy(queue: Queue): Queue {
	return Queue{collection=copy(queue.collection)};
}
