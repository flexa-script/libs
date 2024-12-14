// utils standard lib
// MIT License
// Copyright (c) 2024 Carlos Eduardo de Borba Machado

namespace cp;

fun isnumber(value: any) {
	return typeof(value) in {typeof(int), typeof(float)};
}

fun istext(values: any) {
	return typeof(value) in {typeof(string), typeof(char)};
}
