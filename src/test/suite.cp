// MIT License
// Copyright (c) 2023 Carlos Eduardo de Borba Machado

using test.math_test;
using test.random_test;

fun print_test_suite(lib_name: string, test_suite: function) {
  print("--- Tests of lib <" + lib_name + "> ---\n");
  test_suite();
  print("------------------------------\n");
}

fun execute_test_suite() {
  print_test_suite("math", math_test_suite);
  print_test_suite("random", random_test_suite);
}
