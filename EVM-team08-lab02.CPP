#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#include <string.h>

void scroll (int x1, int y1, int x2, int y2)
{
    void *buf;
    buf = malloc ((x2 - x1) * (y2 - y1 - 1) * 2);
    gettext(0, 1, x2 - x1, y2 - y1, buf);
    puttext(0, 0, x2 - x1, y2 - y1 - 1, buf);
}

int main()
{
    int x1, y1, x2, y2, i, j, k, T, S;

    char colours[16][20];

    strcpy(colours[0], "BLACK");
    strcpy(colours[1], "BLUE");
    strcpy(colours[2], "GREEN");
    strcpy(colours[3], "CYAN");
    strcpy(colours[4], "RED");
    strcpy(colours[5], "MAGENTA");
    strcpy(colours[6], "BROWN");
    strcpy(colours[7], "LIGHTGRAY");
    strcpy(colours[8], "DARKGRAY");
    strcpy(colours[9], "LIGHTBLUE");
    strcpy(colours[10], "LIGHTGREEN");
    strcpy(colours[11], "LIGHTCYAN");
    strcpy(colours[12], "LIGHTRED");
    strcpy(colours[13], "LIGHTMAGENTA");
    strcpy(colours[14], "YELLOW");
    strcpy(colours[15], "WHITE");

    union REGS r;
    x1 = 25;
    y1 = 8;
    x2 = 55;
    y2 = 18;
    T = 200;
    S = 2;

    textbackground(BLACK);
    clrscr();

    window(x1, y1, x2, y2);

    textbackground(BLUE);
	clrscr();
    for (i = 0; i < 8; i++)
    {
	textbackground(BLACK + i);
		clrscr();
	gotoxy(1, S + 1 + i * 8 + j);
	for (j = 0; j < 16; j++)
	{
		textcolor(BLACK + j);
		cprintf("%s %s\n\r", colours[i], colours[j]);
	    for (k = 0; k < S; k++)
	    {
		    cprintf("\n\r");
	    }
		delay(T);
	}
    }

    getch();
    return 0;
}
