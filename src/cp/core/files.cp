// files core lib
// MIT License
// Copyright (c) 2024 Carlos Eduardo de Borba Machado

namespace cp;

const PATH_SEPARATOR = "/";

const MODE_READ: int = 1;
const MODE_WRITE: int = 2;
const MODE_APPEND: int = 8;
const MODE_BINARY: int = 32;

struct File {
	var path: string;
	var mode: int;
};

fun open(file: File, path: string, mode: int): bool;
fun is_open(file: File): bool;
fun read(file: File): string;
fun read_line(file: File): string;
fun write(file: File, data: string);
fun read_all_bytes(file: File): char[];
fun write_bytes(file: File, bytes[]: char);
fun close(file: File);

fun del_file(path: string): bool;
fun del_folder(path: string): bool;

fun path_exists(path: string): bool;
