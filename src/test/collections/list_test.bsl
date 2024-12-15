// MIT License
// Copyright (c) 2023 Carlos Eduardo de Borba Machado

using bsl.std.testing;
using bsl.std.collections.list;

include namespace bsl;

var default_list: List = create_list();
add(default_list, 1);
add(default_list, 2);
add(default_list, 3);
add(default_list, 4);
add(default_list, 5);
add(default_list, 6);

fun list_add() {
	// arrange
	var list: List = create_list();
	
	// act
	add(list, 1);
	add(list, 2);
	add(list, 3);
	
	// assert
	assert_equals(this + "[size]", 3, size(list));
	assert_equals(this + "[content]", {1, 2, 3}, to_array(list));
}

fun list_add_position() {
	// arrange
	var list: List = create_list();

	// act
	insert(list, 4, 0);
	insert(list, 5, 1);
	insert(list, 1, 0);
	insert(list, 2, 1);
	insert(list, 3, 2);
	insert(list, 6, 5);
	
	// assert
	assert_equals(this + "[size]", 6, size(list));
	assert_equals(this + "[content]", {1, 2, 3, 4, 5, 6}, to_array(list));
}

fun list_add_position_with_existent() {
	// arrange
	var list: List = create_list();
	add(list, 1);
	add(list, 3);
	add(list, 5);
	
	// act
	insert(list, 2, 1);
	insert(list, 4, 3);
	insert(list, 0, 0);
	insert(list, 6, 6);
	
	// assert
	assert_equals(this + "[size]", 7, size(list));
	assert_equals(this + "[content]", {0, 1, 2, 3, 4, 5, 6}, to_array(list));
}

fun list_delete() {
	// arrange
	var list: List = copy(default_list);
	
	// act
	delete(list, 0);
	delete(list, 4);
	delete(list, 1);
	
	// assert
	assert_equals(this + "[size]", 3, size(list));
	assert_equals(this + "[content]", {2, 4, 5}, to_array(list));
}

fun list_get_start() {
	// arrange
	
	// act
	var val: int = get(default_list, 0);
	
	// assert
	assert_equals(this, 1, val);
}

fun list_get_middle() {
	// arrange
	
	// act
	var val: int = get(default_list, 2);
	
	// assert
	assert_equals(this, 3, val);
}

fun list_get_end() {
	// arrange
	
	// act
	var val: int = get(default_list, 5);
	
	// assert
	assert_equals(this, 6, val);
}

fun list_indexof() {
	// arrange
	
	// act
	var val: int = indexof(default_list, 5);
	
	// assert
	assert_equals(this, 4, val);
}

fun list_test_suite() {
	list_add();
	list_add_position();
	list_add_position_with_existent();
	list_delete();
	list_get_start();
	list_get_middle();
	list_get_end();
	list_indexof();
}
