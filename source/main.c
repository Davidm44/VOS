#include "console.h"
#include "common.h"
#include "IDT.h"

unsigned char *D = "DAVID\n";

unsigned char keymap[128] =
{
    0  , 0  , '1' , '2' , '3', '4', '5', '6', '7', '8', '9', '0', 
    '-', '=', '\b', '\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 
    'o', 'p', '[' , ']' ,'\n',   0, 'a', 's', 'd', 'f', 'g', 'h', 
    'j', 'k', 'l' , ';' ,'\'', '`',   0,'\\', 'z', 'x', 'c', 'v', 
    'b', 'n',  'm', ',', '.' , '/',   0, '*',  0 ,' ' ,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
  '-',
    0,
    0,
    0,
  '+',
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};

extern void irq_handler(registers_t regs)
{
	if(regs.int_no == 1)
	{
	
		unsigned char scancode = inb(0x60);
		ConsolePut(keymap[scancode],COLOR_WHITE);
	}	
	outb(0x20,0x20);
}

extern int kmain()
{	
	Initialize_IDT();
	
	ConsoleWrite(D,COLOR_YELLOW);

	__asm__ ("sti");

	return 0;
}

