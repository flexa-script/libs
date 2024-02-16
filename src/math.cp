// Lib: math.cp
// Author: Carlos Machado


var E : float = 2.718281828459045;
var PI : float = 3.141592653589793;
var TAU : float = 2.0 * PI;
var DEGREES_TO_RADIANS : float = 0.017453292519943295;
var RADIANS_TO_DEGREES : float = 57.29577951308232;


def toRadians(angdeg : float) : float {
  return angdeg * DEGREES_TO_RADIANS;
}

def toDegrees(angrad : float) : float {
  return angrad * RADIANS_TO_DEGREES;
}

def clamp(val : int, min : int, max : int) : int {
  return int(clamp(float(val), float(min), float(max)));
}

def clamp(val : float, min : float, max : float) : float {
  if (val > max) {
    return max;
  }
  if (val < min) {
    return min;
  }
  return val;
}

def abs(val : int) : int {
  return int(abs(float(val)));
}

def abs(val : float) : float {
  if (val < 0) {
    return val * -1;
  }
  return val;
}

def max(a : int, b : int) : int {
  return int(max(float(a), float(b)));
}

def max(a : float, b : float) : float {
  if (a >= b) {
    return a;
  }
  return b;
}

def min(a : int, b : int) : int {
  return int(min(float(a), float(b)));
}

def min(a : float, b : float) : float {
  if (a <= b) {
    return a;
  }
  return b;
}
