// arrays standard lib
// MIT License
// Copyright (c) 2024 Carlos Eduardo de Borba Machado

namespace cp;

fun size(arr[]: any): int {
  var count: int = 0;
  foreach (var v in arr) {
    count++;
  }
  return count;
}

fun contains(arr[]: any, cval: any): bool {
  foreach (var v in arr) {
    if (unref v == unref cval) {
      return true;
    }
  }
  return false;
}

fun contains_ref(arr[]: any, cval: any): bool {
  foreach (var v in arr) {
    if (ref v == ref cval) {
      return true;
    }
  }
  return false;
}
