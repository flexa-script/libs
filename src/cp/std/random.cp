// testing standard lib

// MIT License
// Copyright (c) 2023 Carlos Eduardo de Borba Machado

using math;

namespace random;


const RAND_MAX = 4294967295;
const _RAND_MAX2 = 2 * 4294967295;

var _next: int = 1;

def randomize(seed: int) {
	_next = _seed;
}

def randomize(seed: float) {
	randomize(int(seed));
}

def _rand(): float {
    _next = _next * 1103515245 + 12345;
    return (_next / _RAND_MAX2) % RAND_MAX;
}

def randi(): int {
	return int(_rand());
}

def randi_range(from: int, to: int): int {
	return int(randf_range(from, to));
}

def randf(): float {
	return math::normalize(_rand(), 0, 1);
}

def randf_range(from: float, to: float): float {
	return from + _rand() * (to - from) / RAND_MAX;
}
