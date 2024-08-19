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
    if (v == cval) {
      return true;
    }
  }
  return false;
}

fun sort(arr[]: any): any[] {
  var arr_size = size(arr);
  for (var j = 0; j < arr_size; j++) {
    for (var i = 0; i < arr_size - 1; i++) {
      if (arr[i] > arr[i + 1]) {
        var aux = arr[i + 1];
        arr[i + 1] = arr[i];
        arr[i] = aux;
      }
    }
  }
  return arr;
}

fun reverse(arr[]: any): any[] {
  var arr_size = size(arr);
  var rarr[arr_size]: any = {null};
  var ri = 0;
  for (var i = arr_size - 1; i >= 0; i--) {
    rarr[ri] = arr[i];
    ri++;
  }
  return rarr;
}
