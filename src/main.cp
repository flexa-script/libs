// MIT License
// Copyright (c) 2023 Carlos Eduardo de Borba Machado

// using test.suite;

// execute_test_suite();

struct Node {
    var value: any;
    var next: Node;
    var prev: Node;
};

struct Collection {
    var first: Node;
    var last: Node;
    var size: int;
};

var collection = Collection{};
collection.first = Node{value=10};
println(collection);
collection.first.value *= 10;
println(collection);
collection.last = collection.first;
println(collection);
collection.first.value /= 10;
println(collection);
