#include "common.h"

void outb(u16int port,u8int value)
{
	asm volatile("outb %1,%0" : : "dN" (port), "a" (value));
}

u8int inb(u16int port)
{
	u8int retn;
	asm volatile("inb %1,%0" : "=a" (retn) : "dN" (port));
	return retn;
}


u16int inw(u16int port)
{
   u16int retn;
   asm volatile ("inw %1, %0" : "=a" (retn) : "dN" (port));
   return retn;
} 
