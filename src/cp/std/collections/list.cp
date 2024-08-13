// list standard lib
// MIT License
// Copyright (c) 2024 Carlos Eduardo de Borba Machado

namespace cp;

struct Node {
    var value: any;
    var next: Node;
};

struct List {
    var first: Node;
    var size: int;
};

fun create_list(): List {
    return List{first=null, size=0};
}

fun add(list: List, value: any) {
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

fun add(list: List, value: any, index: int) {
    if (index >= list.size) {
        throw "invalid access position";
    }

    if (index == 0) {
        list.first = Node{value=value, next=list.first};
    } else {
        var prev_node;
        var curr_node = list.first;

        for (var i = 0; i < index; i++) {
            prev_node = curr_node;
            curr_node = curr_node.next;
        }

        curr_node.next = Node{value=value, next=curr_node.next};
    }
    list.size++;
}

fun remove(list: List, index: int) {
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

fun get(list: List, index: int): any {
    if (index >= list.size) {
        return null;
    }

    var node = list.first;

    for (var i = 0; i < index; i++) {
        node = node.next;
    }

    return node.value;
}

fun clear(list: List) {
    list = create_list();
}

fun is_empty(list: List): bool {
    return list.size == 0;
}

fun to_array(list: List): any[] {
    var arr[list.size]: any = {null};
    var curr_node = list.first;
    for (var i = 0; i < list.size; i++) {
        if (typeof(curr_node.value) == typeof(List)) {
            arr[i] = to_array(curr_node.value);
        } else {
            arr[i] = curr_node.value;
        }
        curr_node = curr_node.next;
    }
    return arr;
}
