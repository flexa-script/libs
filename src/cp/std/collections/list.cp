// list standard lib
// MIT License
// Copyright (c) 2024 Carlos Eduardo de Borba Machado

namespace cp;

using cp.std.collections.collection;

fun add(list: Collection, value: any) {
    if (list.first == null) {
        list.first = Node{value=value, next=null};
        list.size = 1;
    } else {
        var prev_node: Node = Node{value=null, next=null};
        var curr_node = list.first;

        while (curr_node.next != null) {
            prev_node = curr_node;
            curr_node = curr_node.next;
        }

        curr_node.next = Node{value=value, next=null};
        list.size++;
    }
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

fun remove(list: Collection, index: int) {
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
