// JSON standard lib
// MIT License
// Copyright (c) 2024 Carlos Eduardo de Borba Machado

namespace bsl;

using bsl.std.collections.dictionary;

fun json_parse(data: string): Dictionary;
fun _json_stringify_value(value: any): string;
fun json_stringify(dict: Dictionary): string;

fun json_parse(data: string): Dictionary {
	return null;
}

fun _json_stringify_value(value: any): string {
	var json: string = "";

	if (typeof(value) == "Dictionary") {
		json = json_stringify(value);
	} else if (is_struct(value)) {
		json = json_stringify(parse_struct(value));
	} else if (typeof(value) in {typeof(string), typeof(char)}) {
		json = '"' + string(value) + '"';
	} else if (is_array(value)) {
		json = "[";
		foreach (var v in value) {
			json += _json_stringify_value(v) + ",";
		}

		if (json[strlen(json) - 1] == ',') {
			json = substr(json, 0, strlen(json) - 1);
		}

		json += "]";

	} else {
		json += string(value);
	}
	
	return json;
}

fun json_stringify(dict: Dictionary): string {
	var json: string = "{";
	var visited_list = create_list();
	var current_stack = create_stack();
	var current = dict.root;

	while (current != null) {
		if (not exists(visited_list, current.key)) {
			push(current_stack, current);
			add(visited_list, current.key);
			json += '"' + current.key + "\":" + _json_stringify_value(current.value) + ',';
		}
		if (current.left != null and not exists(visited_list, current.left.key)) {
			current = current.left;
		} else if (current.right != null and not exists(visited_list, current.right.key)) {
			current = current.right;
		} else {
			pop(current_stack);
			current = size(current_stack) > 0 ? peek(current_stack) : null;
		}
	}

	if (json[strlen(json) - 1] == ',') {
		json = substr(json, 0, strlen(json) - 1);
	}

	json += "}";

	return json;
}
