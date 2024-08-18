// collection standard lib
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

fun _default_add(collection: Collection, value: any) {
    if (collection.first == null) {
        collection.first = Node{value=value, next=null, prev=null};
        collection.last = collection.first;
        collection.size = 1;
	} else if (ref collection.first == ref collection.last) {
		var new_node = Node{value=value, prev=collection.first, next=null};
        collection.first.next = new_node;
		collection.last = new_node;
        collection.size = 2;
    } else {
		var new_node = Node{value=value, prev=collection.last, next=null};
        collection.last.next = new_node;
		collection.last = new_node;
        collection.size++;
    }
}

fun _default_get(collection: Collection): any {
    if (collection.first == null) {
        throw "Tryed to get from empty collection";
    }

    return collection.last.value;
}

fun _default_remove(collection: Collection) {
    if (collection.first == null) {
        throw "Tryed to remove from empty collection";
    }
	if(collection.size == 1){
		collection.first = null;
		collection.last = null;
	} else {
		collection.last = collection.last.prev;
		collection.last.next = null;
	}
	collection.size--;
}

fun create_collection(): Collection {
    return Collection{first=null, last=null, size=0};
}

fun clear(collection: Collection) {
    collection = create_collection();
}

fun is_empty(collection: Collection): bool {
    return collection.size == 0;
}

fun to_array(collection: Collection): any[] {
    var arr[collection.size]: any = {null};
    var curr_node = collection.first;
    for (var i = 0; i < collection.size; i++) {
        if (typeof(curr_node.value) == typeof(Collection)) {
            arr[i] = to_array(curr_node.value);
        } else {
            arr[i] = curr_node.value;
        }
        curr_node = curr_node.next;
    }
    return arr;
}

fun copy(collection: Collection): Collection {
    var copy = Collection{};
	var arr = to_array(collection);
    foreach (var v in arr) {
		_default_add(copy, v);
	}
	return copy;
}
