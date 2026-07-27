#ifndef TERMINAL_H
#define TERMINAL_H

enum vga_color {
	black = 0,
	blue = 1,
	green = 2,
	cyan = 3,
	red = 4,
	purple = 5,
	brown = 6,
	gray = 7,
	dark_gray = 8,
	light_blue = 9,
	light_green = 10,
	light_cyan = 11,
	light_red = 12,
	light_purple = 13,
	yellow = 14,
	white = 15
};

void newline(void);
void tracker(char x, int y);
void word(char *message);
void set_color(int c);
void clear_screen(void);
void scrolling(void);

#endif
