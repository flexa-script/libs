// testing standard lib
// MIT License
// Copyright (c) 2024 Carlos Eduardo de Borba Machado

namespace cp;

using cp.core.console;

fun assert_equals(test: string, expected: any, value: any, comparatorx: function = null) {
  if (comparatorx != null and comparatorx(expected, value) or
      comparatorx == null and expected == value) {
    set_console_color(BLACK, LIGHT_GREEN);
    print("PASS: <" + test + ">");
  } else {
    set_console_color(BLACK, RED);
    print("ERROR: <" + test + "> Expected '", expected, "', got '", value, "'");
  }
  set_console_color(BLACK, WHITE);
  print("\n");
}

fun assert_between(test: string, min: int, max: int, value: int) {
  if (value < min) {
    set_console_color(BLACK, RED);
    print("ERROR: <" + test + "> Value '", value, "' is lesser than min '", min, "' value");
  } else if (value > max) {
    set_console_color(BLACK, RED);
    print("ERROR: <" + test + "> Value '", value, "' is greather than max '", max, "' value");
  } else {
    set_console_color(BLACK, LIGHT_GREEN);
    print("PASS: <" + test + ">");
  }
  set_console_color(BLACK, WHITE);
  print("\n");
}

fun assert_between(test: string, min: float, max: float, value: float) {
  if (value < min) {
    set_console_color(BLACK, RED);
    print("ERROR: <" + test + "> Value '", value, "' is lesser than min '", min, "' value");
  } else if (value > max) {
    set_console_color(BLACK, RED);
    print("ERROR: <" + test + "> Value '", value, "' is greather than max '", max, "' value");
  } else {
    set_console_color(BLACK, LIGHT_GREEN);
    print("PASS: <" + test + ">");
  }
  set_console_color(BLACK, WHITE);
  print("\n");
}

fun assert_true(test: string, value: bool) {
  if (value) {
    set_console_color(BLACK, LIGHT_GREEN);
    print("PASS: <" + test + ">");
  } else {
    set_console_color(BLACK, RED);
    print("ERROR: <" + test + "> Expected true value");
  }
  set_console_color(BLACK, WHITE);
  print("\n");
}

fun assert_false(test: string, value: bool) {
  if (not value) {
    set_console_color(BLACK, LIGHT_GREEN);
    print("PASS: <" + test + ">");
  } else {
    set_console_color(BLACK, RED);
    print("ERROR: <" + test + "> Expected false value");
  }
  set_console_color(BLACK, WHITE);
  print("\n");
}
