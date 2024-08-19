// dict standard lib
// MIT License
// Copyright (c) 2023 Carlos Eduardo de Borba Machado

// namespace cp;

// using cp.std.collections.collection;
// using cp.core.math;

// struct DictionaryNode {
//     var value: any;
//     var key: any;
//     var key_hash: int;
//     var left: Node;
//     var right: Node;
// };

// struct Dictionary {
//     var root: Node;
// };

// fun put(dict: Dictionary, key: any, value: any) {
//     var str_key = string(key);
//     var h = hash(str_key);

//     var new_node = DictionaryNode{key=key, key_hash=h, value=value, left=null, right=null};

//     if (dict.root == null) {
//         dict.root = new_node;
//     }

//     var prev = dict.root;
//     var current = dict.root;
//     var right = false;

//     while (current != null) {
//         if (unref str_key == unref current.key) {
//             current.key = new_node.key;
//             current.key_hash = new_node.key_hash;
//             current.value = new_node.value;
//         }
//         if (h > current.key_hash) {
//             prev = current;
//             current = current.right;
//             right = true;
//         } else if (h < current.key_hash) {
//             prev = current;
//             current = current.left;
//             right = false;
//         }
//     }
//     if (right) {
//         prev.right = new_node;
//     } else {
//         prev.left = new_node;
//     }
// }
