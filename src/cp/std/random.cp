// random standard lib
// MIT License
// Copyright (c) 2024 Carlos Eduardo de Borba Machado

namespace cp;

using cp.std.math;

const RAND_MAX = 4294967295;

var _next: int = 1;

fun randomize(seed: int) {
	_next = seed;
}

fun randomize(seed: float) {
	randomize(int(seed));
}

fun _rand(): int {
	_next = (_next * 1103515245 + 12345) % RAND_MAX;
	return _next;
}

fun randf(): float {
	return normalize(float(_rand()), 0.0, 1.0);
}

fun randf_range(from: float, to: float): float {
	return from + _rand() * (to - from) / RAND_MAX;
}

fun randi(): int {
	return int(_rand());
}

fun randi_range(from: int, to: int): int {
	return int(randf_range(float(from), float(to)));
}
