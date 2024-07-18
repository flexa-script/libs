// console core lib
// MIT License
// Copyright (c) 2023 Carlos Eduardo de Borba Machado

namespace cp;

enum {
	BLACK,
	BLUE,
	GREEN,
	AQUA,
	RED,
	PURPLE,
	YELLOW,
	WHITE,
	GRAY,
	LIGHT_BLUE,
	LIGHT_GREEN,
	LIGHT_AQUA,
	LIGHT_RED,
	LIGHT_PURPLE,
	LIGHT_YELLOW,
	BRIGHT_WHITE
};

def set_console_color(background_color: int, foreground_color: int);

def set_console_cursor_position(x: int, y: int);

def set_console_font(font_name: string, font_width: int, font_height: int);
