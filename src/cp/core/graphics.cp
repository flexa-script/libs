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

const FW_DONTCARE = 0;
const FW_THIN = 100;
const FW_EXTRALIGHT = 200;
const FW_LIGHT = 300;
const FW_NORMAL = 400;
const FW_MEDIUM = 500;
const FW_SEMIBOLD = 600;
const FW_BOLD = 700;
const FW_EXTRABOLD = 800;
const FW_HEAVY = 900;

const FW_ULTRALIGHT = FW_EXTRALIGHT;
const FW_REGULAR = FW_NORMAL;
const FW_DEMIBOLD = FW_SEMIBOLD;
const FW_ULTRABOLD = FW_EXTRABOLD;
const FW_BLACK = FW_HEAVY;

struct Font {
	var size: int;
	var name: string;
	var weight: int;
	var italic: bool;
	var underline: bool;
	var strike: bool;
	var orientation: int;
};

fun create_font(size: int = 20, name: string = "Arial", weight: int = 0, italic: bool = false,
	underline: bool = false, strike: bool = false, orientation: int = 0): Font;

struct Window {
	var title: string;
	var width: int;
	var height: int;
};

fun create_window(title: string, width: int, height: int): Window;
fun clear_screen(window: Window, color: Color);
fun draw_text(window: Window, x: int, y: int, text: string, color: Color, font: Font);
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
