// testing standard lib
// MIT License
// Copyright (c) 2023 Carlos Eduardo de Borba Machado

namespace cp;

using cp.core.console;

fun assert_equals(test: string, expected: string, value: string) {
  var res: bool = expected == value;
  if (res) {
    print("PASS: <" + test + ">");
  } else {
    print("ERROR: <" + test + "> Expected '" + expected + "', got '" + value + "'");
  }
  set_console_color(BLACK, WHITE);
  print("\n");
}

fun assert_equals(test: string, expected: int, value: int) {
  assert_equals(test, string(expected), string(value));
}

fun assert_equals(test: string, expected: float, value: float) {
  assert_equals(test, string(expected), string(value));
}

fun assert_equals(test: string, expected: bool, value: bool) {
  assert_equals(test, string(expected), string(value));
}
