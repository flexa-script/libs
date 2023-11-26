def assertEquals(test : string, expected : string, value : string) {
  var res : bool = expected == value;
  if (res) {
    print("PASS: <" + test + ">");
  } else {
    print("ERROR: <" + test + "> Expected '" + expected + "', got '" + value + "'");
  }
  print("\n");
}

def assertEquals(test : string, expected : int, value : int) {
  assertEquals(test, string(expected), string(value));
}

def assertEquals(test : string, expected : float, value : float) {
  assertEquals(test, string(expected), string(value));
}

def assertEquals(test : string, expected : bool, value : bool) {
  assertEquals(test, string(expected), string(value));
}
