// graphics core lib
// MIT License
// Copyright (c) 2023 Carlos Eduardo de Borba Machado

namespace cp;

struct Color {
	var r: int;
	var g: int;
	var b: int;
};

def rgb(r: int, g: int, b: int): Color {
	return Color{r=r, g=g, b=b};
}

struct Image {
	var path: string;
	var width: int;
	var height: int;
};

def load_image(path: string): Image;

struct Window {
	var title: string;
	var width: int;
	var height: int;
};

def create_window(title: string, width: int, height: int): bool;
def clear_screen(window: Window, color: Color);
def draw_pixel(window: Window, x: int, y: int, color: Color);
def draw_line(window: Window, x1: int, y1: int, x2: int, y2: int, color: Color);
def draw_rect(window: Window, x: int, y: int, width: int, height: int, color: Color);
def fill_rect(window: Window, x: int, y: int, width: int, height: int, color: Color);
def draw_circle(window: Window, xc: int, yc: int, radius: int, color: Color);
def fill_circle(window: Window, xc: int, yc: int, radius: int, color: Color);
def draw_image(window: Window, image: Image, x: int, y: int);
def update(window: Window);
def destroy_window(window: Window);
def is_quit(window: Window): bool;
