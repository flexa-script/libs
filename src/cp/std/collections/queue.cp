// queue standard lib
// MIT License
// Copyright (c) 2024 Carlos Eduardo de Borba Machado

namespace cp;

using cp.std.collections.collection;

fun enqueue(queue: Collection, value: any) {
    if (queue.first == null) {
        queue.first = Node{value=value};
        queue.last = queue.first;
        queue.size = 1;
    } else {
        var last = queue.last;
        queue.last = Node{value=value, prev=last};
        last.next = queue.last;
        queue.size++;
    }
}

fun dequeue(queue: Collection): any {
    queue.size--;
    return queue.first;
}

fun front(queue: Collection): any {
    return queue.first;
}

fun back(queue: Collection): any {
    return queue.last;
}
