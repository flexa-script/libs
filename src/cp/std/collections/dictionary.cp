// dict standard lib
// MIT License
// Copyright (c) 2023 Carlos Eduardo de Borba Machado

namespace cp;

using cp.core.pair;
using cp.std.math;
using cp.std.collections.stack;
using cp.std.collections.list;

struct DictionaryNode {
    var value: any;
    var key: any;
    var key_hash: int;
    var left: DictionaryNode;
    var right: DictionaryNode;
};

struct Dictionary {
    var root: DictionaryNode;
    var size: int;
};

fun create_dictionary(): Dictionary {
    return Dictionary{root=null, size=0};
}

fun emplace(dict: Dictionary, key: any, value: any) {
    var str_key = string(key);
    var h = hash(str_key);

    var new_node = DictionaryNode{key=key, key_hash=h, value=value, left=null, right=null};

    if (dict.root == null) {
        dict.root = new_node;
        dict.size = 1;
        return;
    }

    var parent = dict.root;
    var current = dict.root;
    var right = false;

    while (current != null) {
        if (unref key == unref current.key) {
            current.key = new_node.key;
            current.key_hash = new_node.key_hash;
            current.value = new_node.value;
        }
        if (h > current.key_hash) {
            parent = current;
            current = current.right;
            right = true;
        } else if (h < current.key_hash) {
            parent = current;
            current = current.left;
            right = false;
        }
    }

    if (right) {
        parent.right = new_node;
    } else {
        parent.left = new_node;
    }

    dict.size++;
}

fun erase_iosd(node: DictionaryNode): DictionaryNode {
    var parent: DictionaryNode = node;
    node = node.right;
    var right_child: bool = node.left == null;

    while (node.left != null) {
        parent = node;
        node = node.left;
    }

    if (right_child) {
        parent.right = node.right;
    } else {
        parent.left = node.right;
    }

    node.right = null;
    return node;
}

fun erase_node(node: DictionaryNode): DictionaryNode {
    if (node != null) {
        if (node.left == null and node.right == null) {
            return null;
        }

        if (node.left != null and node.right != null) {
    println("here=",node,"\n");
            var ios: DictionaryNode = erase_iosd(node);
            node.value = ios.value;
            node.key = ios.key;
            node.key_hash = ios.key_hash;
        } else if (node.left != null) {
            node = node.left;
        } else {
            node = node.right;
        }
    }

    return node;
}

fun erase(dict: Dictionary, key: any) {
    if (dict.root == null) {
        throw "Tryed to erase from empty dictionary";
    }

    var h = hash(string(key));

    var side = 0;
    var parent = null;
    var current = dict.root;

    while (current != null) {
        if (unref key == unref current.key) {
            break;
        }

        parent = current;
        if (h > current.key_hash) {
            current = current.right;
            side = 1;
        } else if (h < current.key_hash) {
            current = current.left;
            side = -1;
        }
    }
    
    println("parent=",parent,"\n");
    println("current=",current,"\n");

    if (parent == null) {
        erase_node(current);
    }
    
    if (side > 0) {
    println("b parent.right=",parent.right,"\n");
        parent.right = erase_node(current);
    println("a parent.right=",parent.right,"\n");
    } else {
    println("b parent.left=",parent.left,"\n");
        parent.left = erase_node(current);
    println("a parent.left=",parent.left,"\n");
    }

    dict.size--;
}

fun clear(dict: Dictionary) {
    dict = create_dictionary();
}

fun size(dict: Dictionary): int {
    return dict.size;
}

fun is_empty(dict: Dictionary): bool {
    return dict.size == 0;
}

fun _pair_comparator(rval: Pair, lval: Pair) {
    return rval.key == lval.key;
}

fun to_array(dict: Dictionary): any[] {
    var visited_list = create_list();
    var current_stack = create_stack();
    var current = dict.root;

    while (current != null) {
        var current_pair = Pair{key=current.key, value=current.value};
        var current_left_pair = null;
        var current_right_pair = null;
        if (current.left != null) {
            current_left_pair = Pair{key=current.left.key};
        }
        if (current.right != null) {
            current_right_pair = Pair{key=current.right.key};
        }

        if (not exists(visited_list, current_pair, _pair_comparator)) {
            push(current_stack, current);
            add(visited_list, current_pair);
        }
        if (current.left != null and not exists(visited_list, current_left_pair, _pair_comparator)) {
            current = current.left;
        } else if (current.right != null and not exists(visited_list, current_right_pair, _pair_comparator)) {
            current = current.right;
        } else {
            pop(current_stack);
            current = size(current_stack) > 0 ? peek(current_stack) : null;
        }
    }

    return to_array(visited_list);
}

fun copy(dict: Dictionary): Dictionary {
    var copyd = create_dictionary();
	var arr = to_array(dict);
    foreach (var v in arr) {
		emplace(copyd, v.key, v.value);
	}
	return copyd;
}
