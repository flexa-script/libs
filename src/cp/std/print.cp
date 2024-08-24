// print standard lib
// MIT License
// Copyright (c) 2024 Carlos Eduardo de Borba Machado

namespace cp;

const NEW_LINE: string = "\n";

fun printls(...value: any) {
    print(NEW_LINE + string(value));
}

fun printlb(...value: any) {
    print(NEW_LINE + string(value) + NEW_LINE);
}
