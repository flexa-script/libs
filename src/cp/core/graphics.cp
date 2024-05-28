// graphics core lib

// MIT License
// Copyright (c) 2023 Carlos Eduardo de Borba Machado


namespace cp;

struct Color {
	var r: int;
	var g: int;
	var b: int;
};

def initialize(title: string, width: int, height: int): bool;
def clear_screen(color: Color);
def draw_pixel(x: int, y: int, color: Color);
def draw_line(x1: int, y1: int, x2: int, y2: int, color: Color);
def draw_rect(x: int, y: int, width: int, height: int, color: Color);
def fill_rect(x: int, y: int, width: int, height: int, color: Color);
def draw_circle(xc: int, yc: int, radius: int, color: Color);
def fill_circle(xc: int, yc: int, radius: int, color: Color);
def update();
def is_quit(): bool;
