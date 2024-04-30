using tests.print_test;
using tests.math_test;


def printHeader(libName : string) {
  print("--- Tests of lib <" + libName + "> ---\n");
}

def printFooter() {
  print("------------------------------\n");
}

def executeTestSuite() {
  printHeader("print");
  tests.print_test.print_test();
  printFooter();
  
  printHeader("math");
  tests.math_test.math_test();
  printFooter();
}
