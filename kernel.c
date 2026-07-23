int row = 0;
int column = 0;
int position = 0;
int old = 0;

void newline() {
	row = 1 + old;
	column = 0;
	position = row * 80 + column;
	old = row;
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
	if (column >= 79) {
		newline();
	}
	else {
		column++;
		position++;
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
	row = 0;
	column = 0;
}

void scrolling() { 
	int i = 0;
	char *p = (char *)0xB8000;
	while (i < 80) {
		*(p + i * 2) = ' ';
		*(p + i *2 + 1) = color;
		i++;
	}
	
	int r = 0;
	for (r = 160; r < 2000; r++){
		p[r-160] = p[r];
	}
}

unsigned char inb(unsigned short port) {
	unsigned char data;
	__asm__ volatile (
		"inb %1, %0"
		:"=a" (data)
		:"d" (port)
	);
	return data;
}

void keyboard() {
	if (inb(0x64) & 1) {
		word("A button was pressed! ");
	}
}

void kernel_main() {
	word("Welcome to Masons Kernel!");
	set_color(blue);
	clear_screen();
	word("clear screen works i guess, lets test automatic newlines... FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF");
	newline();
	word("This should test a manual newline");
	word("NEW KERNEL 12345");
	scrolling();
	newline();
	word("At this point the screen should have scrolled");
	newline();
	word("Time To test Buttons!!!");
	newline();
	while (1) {
		keyboard();
	}
}
// This is a test commit
