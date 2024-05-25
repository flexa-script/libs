// list standard lib

// MIT License
// Copyright (c) 2023 Carlos Eduardo de Borba Machado

namespace list;


struct Node {
    var value: any;
    var next: Node;
};

struct List {
    var first: Node;
    var size: int;
};


def create(): List {
    return List{first=null, size=0};
}

def init(list: List) {
    list = create();
}

def add(list: List, value: any) {
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

def remove(list: List, index: int): bool {
    if (index >= list.size) {
        return false;
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

    return true;
}

def get(list: List, index: int): any {
    if (index >= list.size) {
        return null;
    }

    var node = list.first;

    for (var i = 0; i < index; i++) {
        node = node.next;
    }

    return node.value;
}

def clear(list: List) {
    list = create();
}

def is_empty(list: List): bool {
    return list.size == 0;
}

def to_array(list: List): any[] {
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

def to_string(list: List): string {
    if (list.first == null) {
        return "[]";
    }

    var str: string = "[";
    var node = list.first;
    while (node != null) {
        str += string(node.value);
        if (node.next != null) {
            str += ",";
        }
        node = node.next;
    }
    str += "]";

    return str;
}
