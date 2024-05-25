// MIT License
// Copyright (c) 2023 Carlos Eduardo de Borba Machado


using tests.math_test;


def print_header(lib_name: string) {
  print("--- Tests of lib <" + lib_name + "> ---\n");
}

def print_footer() {
  print("------------------------------\n");
}

def execute_test_suite() {
  print_header("math");
  math_test();
  print_footer();
}
