int row = 0;
int column = 0;
int position = 0; //these 3 are for future, when I add support for cursor movement

void position_nv(int column,int  row) {
	column = 0;
	row = 0;
}
int position = nv_position(0,0);
void newline(int skip) {
	int skpamt = (skip * 80);
	position_nv(skpamt, 0);
}

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
int color = green;

void tracker(char x, int  y) {
	char *p = (char *)0xB8000;
	*(p + position * 2) = x;
	*(p + position * 2 + 1) = y;
	if (column >= 80) {
		newline(1);
	}
	else {
		column++;
	}
}

void word(char *message) {
	int mpos = 0;
	char k = *(message + mpos);
	while (k != '\0') {
		tracker(k, color);
		mpos++;
		k = *(message + mpos);
	}
}

void set_color(int c) {
	if (c) {
		color = c;
	}
	else {
		color = green;
	}
}

void clear_screen() {
	char *p = (char *)0xB8000;
	int i = 0;
	while (i < 2000) {
		*(p + i * 2) = ' ';
		*(p + i *2 + 1) = color;
		i++;
	}
	position = 0;
}

void kernel_main() {
	word("Welcome to Masons Kernel!");
	set_color(blue);
	clear_screen();
	word("clear screen works i guess");
}
