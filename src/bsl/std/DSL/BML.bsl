// BPS standard lib
// MIT License
// Copyright (c) 2024 Carlos Eduardo de Borba Machado

namespace cp;

using cp.std.collections.dictionary;

fun bps_parse(data: string): Dictionary;
fun _bps_stringify_value(value: any): string;
fun bps_stringify(data: Dictionary): string;

fun bps_parse(data: string): Dictionary {
	return null;
}

fun _bps_stringify_value(value: any): string {
	var json: string = "";

	if (typeof(value) == "Dictionary") {
		json = bps_stringify(value);
	} else if (is_struct(value)) {
		json = bps_stringify(parse_struct(value));
	} else if (typeof(value) == typeof(string)) {
		json = '"' + string(value) + '"';
	} else if (typeof(value) == typeof(char)) {
		json = "'" + string(value) + "'";
	} else if (is_array(value)) {
		json = "[";
		foreach (var v in value) {
			json += _bps_stringify_value(v) + ",";
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

fun bps_stringify(data: Dictionary): string {
	var bps_str: string = "";
	var visited_list = create_list();
	var current_stack = create_stack();
	var current = data.root;

	while (current != null) {
		if (not exists(visited_list, current.key)) {
			push(current_stack, current);
			add(visited_list, current.key);
			bps_str += current.key + ':' + _bps_stringify_value(current.value) + ';';
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

	if (bps_str[strlen(bps_str) - 1] == ',') {
		bps_str = substr(bps_str, 0, strlen(bps_str) - 1);
	}

	return bps_str;
}
