// queue standard lib
// MIT License
// Copyright (c) 2024 Carlos Eduardo de Borba Machado

namespace cp;

using cp.std.collections.collection;

fun enqueue(queue: Collection, value: any) {
    if (queue.first == null) {
        queue.first = Node{value=value, next=null};
        queue.last = queue.first;
        queue.size = 1;
    } else {
        
        queue.size++;
    }
}

fun dequeue(queue: Collection): any {
    queue.size--;
    return queue.last;
}

fun front(queue: Collection): any {
    return queue.first;
}

fun back(queue: Collection): any {
    return queue.last;
}
