// list standard lib
// MIT License
// Copyright (c) 2024 Carlos Eduardo de Borba Machado

namespace cp;

struct Node {
    var value: any;
    var next: Node;
    var prev: Node;
};

struct Collection {
    var first: Node;
    var last: Node;
    var size: int;
};

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

fun create_collection(): Collection {
    return Collection{first=null, last=null, size=0};
}

fun clear(list: Collection) {
    list = create_collection();
}

fun is_empty(list: Collection): bool {
    return list.size == 0;
}

fun to_array(list: Collection): any[] {
    var arr[list.size]: any = {null};
    var curr_node = list.first;
    for (var i = 0; i < list.size; i++) {
        if (typeof(curr_node.value) == typeof(Collection)) {
            arr[i] = to_array(curr_node.value);
        } else {
            arr[i] = curr_node.value;
        }
        curr_node = curr_node.next;
    }
    return arr;
}
