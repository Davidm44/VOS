#include "console.h"
#include "common.h"

extern void isr_handler(registers_t regs)
{
	if(regs.int_no == 3)
	{	
		ConsoleWrite("Interrupt: 3",COLOR_YELLOW);
	}
	return;
}
