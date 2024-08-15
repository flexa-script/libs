// queue standard lib
// MIT License
// Copyright (c) 2024 Carlos Eduardo de Borba Machado

namespace cp;

using cp.std.collections.collection;

fun enqueue(queue: Collection, value: any) {
    _default_add(queue, value);
}

fun dequeue(queue: Collection) {
    
}

fun front(queue: Collection): any {
    if (first == null) {
        throw "Tryed to get from empty collection";
    }

    return queue.first;
}

fun back(queue: Collection): any {
    _default_get(stack);
}
