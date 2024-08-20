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
    var left: Node;
    var right: Node;
};

struct Dictionary {
    var root: Node;
    var size: int;
};

fun put(dict: Dictionary, key: any, value: any) {
    var str_key = string(key);
    var h = hash(str_key);

    var new_node = DictionaryNode{key=key, key_hash=h, value=value, left=null, right=null};

    if (dict.root == null) {
        dict.root = new_node;
        dict.size = 1;
        return;
    }

    var prev = dict.root;
    var current = dict.root;
    var right = false;

    while (current != null) {
        if (unref str_key == unref current.key) {
            current.key = new_node.key;
            current.key_hash = new_node.key_hash;
            current.value = new_node.value;
        }
        if (h > current.key_hash) {
            prev = current;
            current = current.right;
            right = true;
        } else if (h < current.key_hash) {
            prev = current;
            current = current.left;
            right = false;
        }
    }

    if (right) {
        prev.right = new_node;
    } else {
        prev.left = new_node;
    }

    dict.size++;
}

fun _pair_comparator(rval: Pair, lval: Pair) {
    return rval.key == lval.key;
}

fun to_array(dict: Dictionary): any[] {
    var visited_list = create_list();
    var current_stack = create_stack();
    var current = dict.root;

    while (current != null) {
        if (not exists(visited_list, current, _pair_comparator)) {
            push(current_stack, current);
            add(visited_list, Pair{key=current.key, value=current.value});
        }

        if (current.left != null and not exists(visited_list, current.left, _pair_comparator)) {
            current = current.left;
        } else if (current.right and not exists(visited_list, current.right, _pair_comparator)) {
            current = current.right;
        } else {
            pop(current_stack);
            current = peek(current_stack);
        }
    }

    return to_array(visited_list);
}
