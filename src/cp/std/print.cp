// print standard lib
// MIT License
// Copyright (c) 2023 Carlos Eduardo de Borba Machado

namespace cp;

const NEW_LINE: string = "\n";

def println(value: any) {
    print(string(value) + NEW_LINE);
}

def printlns(value: any) {
    print(NEW_LINE + string(value));
}

def printlnb(value: any) {
    print(NEW_LINE + string(value) + NEW_LINE);
}
