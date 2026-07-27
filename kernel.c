#include "terminal.h"
#include "keyboard.h"

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
