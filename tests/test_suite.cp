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
  print_test();
  printFooter();
  
  printHeader("math");
  math_test();
  printFooter();
}
