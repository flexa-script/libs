// stack standard lib
// MIT License
// Copyright (c) 2024 Carlos Eduardo de Borba Machado

namespace cp;

using cp.std.collections.collection;

fun push(stack: Collection, value: any) {
    _default_add(stack, value);
}

fun pop(stack: Collection): any {
    _default_remove(stack);
}

fun peek(stack: Collection): any {
    _default_get(stack);
}
