#include "console.h"
#include "common.h"

int cursorx = 0;
int cursory = 0;


int strlen(char* string)
{
	int i = 0;
	
	while(string[i] != 0)
	{
		i++;
	}
	
	return i;
}

void MoveCursor(int x,int y)
{
	u16int loc = y*80 + x;
	
	outb(0x3D4,14);
	outb(0x3D5,loc >> 8);
	outb(0x3D4,15);
	outb(0x3D5,loc);
	
	return;
}

void ConsolePut(char character,unsigned char color)
{
	int x = cursorx;
	int y = cursory;
	
	unsigned char* videoMemory = (unsigned char*)0xB8000;
	
	videoMemory[y*160 + x++] = character;
	videoMemory[y*160 + x++] = color;
	
	cursorx = x;
	cursory = y;

}

void ConsoleWrite(char* string,unsigned char color)
{

	unsigned char* videoMemory = (unsigned char*)0xB8000;
	int x = cursorx;
	int y = cursory;

	int i;
	for(i=0;i<strlen(string);i++)
	{	
		if(string[i] == '\n')
		{
			y++;
			x=0;
			i++;
			break;
		}

		videoMemory[y*160 + x++] = string[i];
		videoMemory[y*160 + x++] = color;
		
		if(x >= 160)
		{
			x=0;
			y++;
		}

		MoveCursor(x/2,y);
	}

	cursorx = x;
	cursory = y;
	return;
	
}

