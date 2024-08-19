// queue standard lib
// MIT License
// Copyright (c) 2024 Carlos Eduardo de Borba Machado

namespace cp;

using cp.std.collections.collection;

fun enqueue(queue: Collection, value: any) {
    _default_add(queue, value);
}

fun dequeue(queue: Collection) {
    if (queue.first == null) {
        throw "Tryed dequeue from empty collection";
    }

    queue.first = queue.first.next;
    queue.size--;
}

fun front(queue: Collection): any {
    if (queue.first == null) {
        throw "Tryed to get from empty collection";
    }

    return queue.first.value;
}

fun back(queue: Collection): any {
    return _default_get(queue);
}
