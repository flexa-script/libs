// datetime core lib
// MIT License
// Copyright (c) 2024 Carlos Eduardo de Borba Machado

namespace cp;

using cp.std.collections.dictionary;

const GET = "GET";
const PUT = "PUT";
const POST = "POST";
const DELETE = "DELETE";
const PATCH = "PATCH";
const HEAD = "HEAD";
const OPTIONS = "OPTIONS";
const TRACE = "TRACE";
const CONNECT = "CONNECT";

struct HttpConfig {
	var hostname: string;
	var path: string;
	var port: int;
	var method: string;
	var headers: Dictionary;
	var parameters: Dictionary;
	var data: string;
};

struct HttpResponse {
	var headers: Dictionary;
	var status: int;
	var status_description: int;
	var data: string;
	var http_version: string;
	var raw: string;
};

fun request(config: HttpConfig): HttpResponse;
