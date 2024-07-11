// MIT License
// Copyright (c) 2023 Carlos Eduardo de Borba Machado

using test.math_test;

fun print_header(lib_name: string) {
  print("--- Tests of lib <" + lib_name + "> ---\n");
}

fun print_footer() {
  print("------------------------------\n");
}

fun execute_test_suite() {
  print_header("math");
  math_test_suite();
  print_footer();
}
