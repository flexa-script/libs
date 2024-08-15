// list standard lib
// MIT License
// Copyright (c) 2024 Carlos Eduardo de Borba Machado

namespace cp;

using cp.std.collections.collection;

fun add(list: Collection, value: any) {
    _default_add(list, value);
}

fun insert(list: Collection, value: any, index: int) {
    if (index > list.size) {
        throw "invalid access position";
    }

    if (index == 0) {
        list.first = Node{value=value, next=list.first};
    } else {
        var prev_node;
        var curr_node = list.first;

        for (var i = 0; i < index - 1; i++) {
            prev_node = curr_node;
            curr_node = curr_node.next;
        }

        curr_node.next = Node{value=value, next=curr_node.next};
    }
    list.size++;
}

fun remove(list: Collection) {
    _default_remove(list);
}

fun delete(list: Collection, index: int) {
    if (index >= list.size) {
        throw "invalid access position";
    }

    if (index == 0) {
        list.first = list.first.next;
    } else {
        var prev_node;
        var curr_node = list.first;

        for (var i = 0; i < index; i++) {
            prev_node = curr_node;
            curr_node = curr_node.next;
        }

        prev_node.next = curr_node.next;
    }
    list.size--;
}

fun get(list: Collection, index: int): any {
    if (index >= list.size) {
        return null;
    }

    var node = list.first;

    for (var i = 0; i < index; i++) {
        node = node.next;
    }

    return node.value;
}
