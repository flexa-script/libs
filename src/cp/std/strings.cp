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
	if (end == null) {
		end = strlen(str);
	}
	for (var i = start; i < end; i++) {
		ss += str[i];
	}
	return ss;
}

fun contains(str: string, strc: string): bool {
  var str_size = strlen(str);
  var strc_size = strlen(strc);
  var start: int = 0;
  var end: int = strc_size;

  if (str_size < strc_size) {
    return false;
  }

	while (end <= str_size) {
		if (substr(str, start, end) == strc) {
      return true;
    }
    start++;
    end++;
	}

	return false;
}
