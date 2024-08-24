// hashtable standard lib
// MIT License
// Copyright (c) 2024 Carlos Eduardo de Borba Machado

namespace cp;

using cp.core.math;
using cp.std.collections.list;

struct Hashtable {
	var keys[MAX_VALUE]: string;
	var values[MAX_VALUE]: any;
};

fun hashtable_create(): Hashtable {
	return Hashtable{keys={null}, values={null}};
}

fun hashtable_hash(key: string): int {
	return hash(key) % MAX_VALUE;
}

fun put(ht: Hashtable, key: string, value: any) {
	var h = hahashtable_hashsh(key);
	ht.keys[h] = key;
	ht.values[h] = value;
}

fun delete(ht: Hashtable, key: string) {
	var h = hashtable_hash(key);
	if (ht.keys[h] == null) {
		throw "Tryed deleting non existent key";
	}
	ht.keys[h] = null;
	ht.values[h] = null;
}

fun get(ht: Hashtable, key: string): any {
	var h = hashtable_hash(key);
	if (ht.keys[h] == null) {
		throw "Tryed get from non existent key";
	}
	return ht.values[h];
}

fun clear(ht: Hashtable) {
	ht = hashtable_create();
}
