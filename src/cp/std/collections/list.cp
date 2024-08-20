// list standard lib
// MIT License
// Copyright (c) 2024 Carlos Eduardo de Borba Machado

namespace cp;

using cp.std.collections.collection;

struct List {
    var collection: Collection;
};

fun create_list(): List {
    return List{collection=create_collection()};
}

fun add(list: List, value: any) {
    _default_add(list.collection, value);
}

fun insert(list: List, value: any, index: int) {
    var collection = list.collection;

    if (index > collection.size) {
        throw "invalid access position";
    }

    if (index == collection.size) {
        _default_add(collection, value);
        return;
    }

    if (index == 0) {
        var new_node = Node{value=value, next=collection.first};
        new_node.next.prev = new_node;
        collection.first = new_node;
    } else {
        var prev_node;
        var curr_node = collection.first;

        for (var i = 0; i < index - 1; i++) {
            prev_node = curr_node;
            curr_node = curr_node.next;
        }

        var new_node = Node{value=value, next=curr_node.next};
        curr_node.next.prev = new_node;
        curr_node.next = new_node;
    }
    collection.size++;
}

fun remove(list: List) {
    _default_remove(list.collection);
}

fun delete(list: List, index: int) {
    var collection = list.collection;

    if (index >= collection.size) {
        throw "invalid access position";
    }

    if (index == 0) {
        collection.first = collection.first.next;
    } else {
        var curr_node = collection.first;

        for (var i = 0; i < index; i++) {
            curr_node = curr_node.next;
        }

        var prev_node = curr_node.prev;
        var next_node = curr_node.next;
        prev_node.next = next_node;
        if (next_node != null) {
            next_node.prev = prev_node;
        }
    }
    collection.size--;
}

fun get(list: List, index: int): any {
    var collection = list.collection;

    if (index >= collection.size) {
        return null;
    }

    var node = collection.first;

    for (var i = 0; i < index; i++) {
        node = node.next;
    }

    return node.value;
}

fun exists(list: List, value: any, comparator: function = null) {
    return exists(list.collection, value, comparator);
}

fun size(list: List): int {
    return list.collection.size;
}

fun to_array(list: List): any[] {
    return to_array(list.collection);
}

fun copy(list: List): List {
    return List{collection=copy(list.collection)};
}
