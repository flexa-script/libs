// math standard lib
// MIT License
// Copyright (c) 2023 Carlos Eduardo de Borba Machado

namespace cp;

const MAX_VALUE = 9223372036854775807; //18446744073709551615

const E: float = 2.718281828459045;
const PI: float = 3.141592653589793;
const TAU: float = 2.0 * PI;

const DEGREES_TO_RADIANS: float = 0.017453292519943295;
const RADIANS_TO_DEGREES: float = 57.29577951308232;


def to_radians(angdeg: float): float {
	return angdeg * DEGREES_TO_RADIANS;
}

def to_degrees(angrad: float): float {
	return angrad * RADIANS_TO_DEGREES;
}

def pow(x: float, n: float): float {
	//return exp(log(x) * n);

	if (int(n) == 0) {
		return 1f;
	}

	if (int(n) % 2 == 0) {
		return pow(x, n / 2) * pow(x, n / 2);
	}
	
	return x * pow(x, n / 2) * pow(x, n / 2);
}

def round(val: float): int {
	if (val < 0.0) {
        return int(val - 0.49999999999999994);
    } else {
        return int(val + 0.49999999999999994);
	}
}

def clamp(val: float, min: float, max: float): float {
	if (val > max) {
		return max;
	}
	if (val < min) {
		return min;
	}
	return val;
}

def clamp(val: int, min: int, max: int): int {
	return int(clamp(float(val), float(min), float(max)));
}

def abs(val: float): float {
	if (val < 0) {
		return val * -1.0;
	}
	return val;
}

def abs(val: int): int {
	return int(abs(float(val)));
}

def max(a: float, b: float): float {
	if (a >= b) {
		return a;
	}
	return b;
}

def max(...values: int): int {
	return 0;
}

def max(a: int, b: int): int {
	return int(max(float(a), float(b)));
}

def max(arr[]: int): int {
	if (len(arr) == 0) {
		return null;
	}
	
	var greater: int = arr[0];
	
	foreach (var val: int in arr) {
		greater = max(val, greater);
	}

	return greater;
}

def max(arr[]: float): float {
	if (len(arr) == 0) {
		return null;
	}
	
	var greater: float = arr[0];
	
	foreach (var val: float in arr) {
		greater = max(val, greater);
	}

	return greater;
}

def min(a: float, b: float): float {
	if (a <= b) {
		return a;
	}
	return b;
}

def min(a: int, b: int): int {
	return int(min(float(a), float(b)));
}

def min(arr[]: int): int {
	if (len(arr) == 0) {
		return null;
	}
	
	var lesser: int = arr[0];
	
	foreach (var val: int in arr) {
		lesser = min(val, lesser);
	}

	return lesser;
}

def min(arr[]: float): float {
	if (len(arr) == 0) {
		return null;
	}
	
	var lesser: float = arr[0];
	
	foreach (var val: float in arr) {
		lesser = min(val, lesser);
	}

	return lesser;
}

def normalize(value: float, min: float, max: float): float {
	var normalized: float = (value - min) / (max - min);
	return normalized;
}

def denormalize(normalized: float, min: float, max: float): float {
	var denormalized: float = normalized * (max - min) + min;
	return denormalized;
}

def hash(str: string) {
	var h: int = 0;
	for (var i: int = 0; i < len(str); i++) {
		h = h * 31 + int(str[i]);
	}
	return h;
}
