// stack standard lib
// MIT License
// Copyright (c) 2024 Carlos Eduardo de Borba Machado

namespace cp;

using cp.std.collections.collection;

fun push(stack: Collection, value: any) {
    if (stack.first == null) {
        stack.first = Node{value=value, next=null};
        stack.last = stack.first;
        stack.size = 1;
    } else {
        
        stack.size++;
    }
}

fun pop(stack: Collection): any {
    stack.size--;
    return stack.last;
}

fun peek(stack: Collection): any {
    return stack.last;
}
