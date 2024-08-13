// MIT License
// Copyright (c) 2024 Carlos Eduardo de Borba Machado

using test.math_test;
using test.random_test;
using test.strings_test;
using test.arrays_test;

fun print_test_suite(lib_name: string, test_suite: function) {
  println("--- Tests of lib <" + lib_name + "> ---");
  test_suite();
  println("------------------------------\n");
}

fun execute_test_suite() {
  print_test_suite("math", math_test_suite);
  print_test_suite("random", random_test_suite);
  print_test_suite("strings", strings_test_suite);
  print_test_suite("arrays", arrays_test_suite);
}
