// graphics core lib
// MIT License
// Copyright (c) 2024 Carlos Eduardo de Borba Machado

namespace cp;

struct Color {
	var r: int;
	var g: int;
	var b: int;
};

fun rgb(r: int, g: int, b: int): Color {
	return Color{r=r, g=g, b=b};
}

struct Image {
	var path: string;
	var width: int;
	var height: int;
};

fun load_image(path: string): Image;

struct Window {
	var title: string;
	var width: int;
	var height: int;
};

fun create_window(title: string, width: int, height: int): bool;
fun clear_screen(window: Window, color: Color);
fun draw_pixel(window: Window, x: int, y: int, color: Color);
fun draw_line(window: Window, x1: int, y1: int, x2: int, y2: int, color: Color);
fun draw_rect(window: Window, x: int, y: int, width: int, height: int, color: Color);
fun fill_rect(window: Window, x: int, y: int, width: int, height: int, color: Color);
fun draw_circle(window: Window, xc: int, yc: int, radius: int, color: Color);
fun fill_circle(window: Window, xc: int, yc: int, radius: int, color: Color);
fun draw_image(window: Window, image: Image, x: int, y: int);
fun update(window: Window);
fun destroy_window(window: Window);
fun is_quit(window: Window): bool;
