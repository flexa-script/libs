// list standard lib
// MIT License
// Copyright (c) 2023 Carlos Eduardo de Borba Machado

namespace cp;

using cp.core.math;
using cp.std.collections.list;

struct Hashtable {
    var keys[MAX_VALUE]: string;
    var values[MAX_VALUE]: any;
};


def hashtable_create(): Hashtable {
    return Hashtable{keys={null}, values={null}};
}

def put(dict: Dict, key: string, value: any) {
    var h = hash(key);
    dict.keys[h] = key;
    dict.values[h] = value;
}

def delete(dict: Dict, key: string): bool {
    var h = hash(key);
    if (dict.values[h] == null) {
        return false;
    }
    dict.keys[h] = null;
    dict.values[h] = null;

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
    list = hashtable_create();
}

def to_array(dict: Dict): any[] {
    var arr[dict.order.size]: any = {null};
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
