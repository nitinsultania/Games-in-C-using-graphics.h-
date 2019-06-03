/*
This Game Is The Chess
It Is Two Player Game
It Is Made By
Lakhan, Nitin and Ram
*/
#include<graphics.h>
#include<dos.h>
#include<conio.h>
#include<_null.h>
#include"DATA.H"
#include"DRAW.H"
#include"MOUSE.H"
#include"PLAY.H"
#include"EVENT.H"
void main()
{
	clrscr();
	putch('W');delay(200);
	putch('E');delay(200);
	putch('L');delay(200);
	putch('C');delay(200);
	putch('O');delay(200);
	putch('M');delay(200);
	putch('E');delay(200);
	putch(' ');delay(200);
	putch('T');delay(200);
	putch('O');delay(200);
	putch(' ');delay(200);
	putch('T');delay(200);
	putch('H');delay(200);
	putch('E');delay(200);
	putch(' ');delay(200);
	putch('G');delay(200);
	putch('A');delay(200);
	putch('M');delay(200);
	putch('E');delay(200);
	putch(' ');delay(200);
	putch('O');delay(200);
	putch('F');delay(200);
	putch(' ');delay(200);
	putch('C');delay(200);
	putch('H');delay(200);
	putch('E');delay(200);
	putch('S');delay(200);
	putch('S');delay(200);
	sleep(2);
	clrscr();
	int gdriver=DETECT,gmode;
	initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
	E.initialize();
	int col=15;
	int con;
	con=E.playgame(col);
	while(con==1)
	{
		col=15-col;
		con=E.playgame(col);
	}
	cleardevice();
	closegraph();
	putch('T');delay(200);
	putch('H');delay(200);
	putch('A');delay(200);
	putch('N');delay(200);
	putch('K');delay(200);
	putch(' ');delay(200);
	putch('Y');delay(200);
	putch('O');delay(200);
	putch('U');delay(200);
	clrscr();
	sleep(2);
}
