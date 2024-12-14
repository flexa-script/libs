// hashtable standard lib
// MIT License
// Copyright (c) 2024 Carlos Eduardo de Borba Machado

namespace cp;

using cp.std.structs;
using cp.std.arrays;
using cp.std.collections.list;

struct Hashtable {
	var used_keys: List;
	var keys[MAX_ARRAY_SIZE]: string;
	var values[MAX_ARRAY_SIZE]: any;
};

fun create_hashtable(): Hashtable {
	return Hashtable{keys={}, values={}, used_keys=create_list()};
}

fun hashtable_hash(key: string): int {
	return hash(key) % MAX_ARRAY_SIZE;
}

fun put(ht: Hashtable, key: string, value: any) {
	var h = hashtable_hash(key);
	ht.keys[h] = key;
	ht.values[h] = value;
	add(ht.used_keys, h);
}

fun delete(ht: Hashtable, key: string) {
	var h = hashtable_hash(key);
	if (ht.keys[h] == null) {
		throw "Tryed deleting non existent key";
	}
	ht.keys[h] = null;
	ht.values[h] = null;
	delete(ht.used_keys, indexof(ht.used_keys, h));
}

fun get(ht: Hashtable, key: string): any {
	var h = hashtable_hash(key);
	if (ht.keys[h] == null) {
		throw "Tryed get from non existent key";
	}
	return ht.values[h];
}

fun to_array(ht: Hashtable): any[] {
	var uk_arr = to_array(ht.used_keys);
	var uk_size = size(ht.used_keys);
	var ht_arr[uk_size] = {null};

	for (var i = 0; i < uk_size; i++) {
		ht_arr[i] = Pair{key=ht.keys[uk_arr[i]], value=ht.values[uk_arr[i]]};
	}

	return ht_arr;
}

fun clear(ht: Hashtable) {
	ht = create_hashtable();
}

fun size(ht: Hashtable) {
	return size(ht.used_keys);
}

fun copy(ht: Hashtable) {
	return Hashtable{keys=ht.keys, values=ht.values, used_keys=copy(ht.used_keys)};
}
