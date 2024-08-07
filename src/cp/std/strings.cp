// string standard lib
// MIT License
// Copyright (c) 2024 Carlos Eduardo de Borba Machado

namespace cp;

fun strlen(str: string): int {
  var count: int = 0;
  foreach (var c: char in str) {
    count++;
  }
  return count;
}

fun substr(str: string, start: int, end: int = null): string {
	var ss = "";
	if(end == null) {
		end = strlen(str);
	}
	for(var i = start; i < end; i++){
		ss += str[i];
	}
	return ss;
}
