// YAML standard lib
// MIT License
// Copyright (c) 2024 Carlos Eduardo de Borba Machado

namespace cp;

using cp.std.collections.dictionary;
using cp.std.strings;

fun yaml_parse(data: string): Dictionary;
fun _yaml_stringify_value(value: any, level: int): string;
fun _yaml_stringify_data(data: Dictionary, level: int): string;
fun yaml_stringify(data: Dictionary): string;

fun yaml_parse(data: string): Dictionary {
	return null;
}

fun _yaml_stringify_value(value: any, level: int): string {
	var yaml: string = "";

	if (typeof(value) == "Dictionary") {
		level++;
		yaml = "\n";
		yaml += _yaml_stringify_data(value, level);
		level--;
	} else if (is_struct(value)) {
		level++;
		yaml = "\n";
		yaml += _yaml_stringify_data(parse_struct(value), level) ;
		level--;
	} else if (typeof(value) in {typeof(string), typeof(char)}) {
		yaml = " \"" + string(value) + "\"\n";
	} else if (is_array(value)) {
		level++;
		yaml = '\n';
		foreach (var v in value) {
			yaml += repeat(" ", level * 2);
			if (is_array(v)) {
				yaml += "-" + _yaml_stringify_value(v, level);
			} else {
				yaml += "-" + _yaml_stringify_value(v, level);
			}
		}
		level--;
	} else {
		yaml = ' ' + string(value) + '\n';
	}
	
	return yaml;
}

fun _yaml_stringify_data(data: Dictionary, level: int): string {
	var yaml: string = "";
	var visited_list = create_list();
	var current_stack = create_stack();
	var current = data.root;

	while (current != null) {
		if (not exists(visited_list, current.key)) {
			push(current_stack, current);
			add(visited_list, current.key);
			yaml += repeat(" ", level * 2);
			yaml += current.key + ":" + _yaml_stringify_value(current.value, level);
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

	return yaml;
}

fun yaml_stringify(data: Dictionary): string {
	return "---\n" + _yaml_stringify_data(data, 0) + "...";
}
