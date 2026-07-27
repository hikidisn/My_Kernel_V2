#include "terminal.h"

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
		word("a button was pressed, and the libaries you made work!!!");
	}
}
