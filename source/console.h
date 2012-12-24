/* io functions */

#define COLOR_BLACK 		0x00
#define COLOR_BLUE 		0x01
#define COLOR_GREEN 		0x02
#define COLOR_CYAN 		0x03
#define COLOR_RED 		0x04
#define COLOR_MAGNETA 		0x05
#define COLOR_BROWN 		0x06
#define COLOR_LIGHTGRAY	 	0x07
#define COLOR_DARKGRAY 		0x08
#define COLOR_LIGHTBLUE 	0x09
#define COLOR_LIGHTGREEN 	0x0A
#define COLOR_LIGHTCYAN 	0x0B
#define COLOR_ORANGE 		0x0C
#define COLOR_PINK 		0x0D
#define COLOR_YELLOW		0x0E
#define COLOR_WHITE 		0x0F

void MoveCursor(int,int);

void ConsolePut(char,unsigned char);
void ConsoleWrite(char*,unsigned char);

