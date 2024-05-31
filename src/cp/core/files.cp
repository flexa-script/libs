// files core lib
// MIT License
// Copyright (c) 2023 Carlos Eduardo de Borba Machado

namespace cp;

const PATH_SEPARATOR = "/";

const MODE_READ: int = 1;
const MODE_WRITE: int = 2;
const MODE_APPEND: int = 3;
const MODE_TEXT: int = 10;
const MODE_BINARY: int = 20;

struct File {
	var path: string;
	var mode: int;
};

def open(file: File, path: string, mode: int): bool;
def is_open(file: File): bool;
def read(file: File): string;
def read_line(file: File): string;
def write(file: File, data: string);
def read_all_bytes(file: File): char[];
def write_bytes(file: File, bytes[]: char);
def close(file: File);

def del_file(path: string): bool;
def del_folder(path: string): bool;

def path_exists(path: string): bool;
