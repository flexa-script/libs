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

    if (index == list.size) {
        _default_add(list, value);
        return;
    }

    if (index == 0) {
        var new_node = Node{value=value, next=list.first};
        new_node.next.prev = new_node;
        list.first = new_node;
        list.size = 1;
    } else {
        var prev_node;
        var curr_node = list.first;

        for (var i = 0; i < index - 1; i++) {
            prev_node = curr_node;
            curr_node = curr_node.next;
        }

        var new_node = Node{value=value, next=curr_node.next};
        curr_node.next.prev = new_node;
        curr_node.next = new_node;
        list.size++;
    }
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
        curr_node.next.prev = prev_node;
    }
    list.size--;
}

fun get(list: Collection, index: int): any {
    if (index >= list.size) {
        return null;
    }

    var node = list.first;

    for (var i = 0; i < index; i++) {
        println("node ",node);
        node = node.next;
    }

    return node.value;
}
