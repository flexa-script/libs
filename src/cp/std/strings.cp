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

fun counts(str: string, strc: string): int {
  var str_size = strlen(str);
  var strc_size = strlen(strc);
  var start: int = 0;
  var end: int = strc_size;

  var count: int = 0;

  if (str_size < strc_size) {
    return count;
  }

	while (end <= str_size) {
		if (substr(str, start, end) == strc) {
      count++;
    }
    start++;
    end++;
	}

	return count;
}

fun starts_with(str: string, strc: string): bool {
  var str_size = strlen(str);
  var strc_size = strlen(strc);

  if (str_size < strc_size) {
    return false;
  }

  if (substr(str, 0, strc_size) == strc) {
    return true;
  }

	return false;
}

fun ends_with(str: string, strc: string): bool {
  var str_size = strlen(str);
  var strc_size = strlen(strc);

  if (str_size < strc_size) {
    return false;
  }

  if (substr(str, str_size - strc_size) == strc) {
    return true;
  }

	return false;
}

fun join(...args: any): string {
  var ss: string = "";
  foreach (var a in args) {
    ss += string(a);
  }
  return ss;
}

fun left_trim(str: string): string {
  var start = 0;
  while (str[start] == ' ') {
    start++;
  }
  return substr(str, start);
}

fun right_trim(str: string): string {
  var end = strlen(str) - 1;
  while (str[end] == ' ') {
    end--;
  }
  return substr(str, 0, end + 1);
}

fun trim(str: string): string {
  return left_trim(right_trim(str));
}

fun split(str: string, strc: string): string[] {
  var str_size = strlen(str);
  var strc_size = strlen(strc);

  if (str_size < strc_size) {
    return {};
  }

  var size: int = counts(str, strc) + 1;
  var splitted[size]: string = {""};
  var i: int = 0;
  var res_i: int = 0;
  var start: int = 0;
  var end: int = strc_size;

	while (end <= str_size) {
		if (substr(str, start, end) == strc) {
      res_i++;
      i += strc_size;
      start += strc_size;
      end += strc_size;
    } else {
      splitted[res_i] += str[i];
    }
    i++;
    start++;
    end++;
	}

  return splitted;
}
