// Lib: print
// Author: Carlos Machado


def println(value : string) {
  print(value + "\n");
}

def println(value : bool) {
  print(string(value) + "\n");
}

def println(value : int) {
  print(string(value) + "\n");
}

def println(value : float) {
  print(string(value) + "\n");
}

def println(value : char) {
  print(value + "\n");
}
