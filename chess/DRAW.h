void maindraw()
{
	settextstyle(TRIPLEX_FONT,0,4);
	setcolor(7);
	outtextxy(275,5,"CHESS");
	setcolor(15);
	rectangle(45,45,455,455);
	rectangle(470,45,600,455);
	//draw home box
	rectangle(505,135,565,195);
	setfillstyle(1,8);
	bar(507,137,563,193);
	int x1=535,y1=165;
	setcolor(0);
	rectangle(506,136,564,194);
	line(x1-15,y1,x1,y1-15);
	line(x1,y1-15,x1+15,y1);
	line(x1-15,y1,x1-15,y1+20);
	line(x1+15,y1,x1+15,y1+20);
	line(x1-15,y1+20,x1-5,y1+20);
	line(x1+15,y1+20,x1+5,y1+20);
	line(x1-5,y1+20,x1-5,y1+10);
	line(x1+5,y1+20,x1+5,y1+10);
	line(x1-5,y1+10,x1+5,y1+10);
	line(x1-18,y1,x1,y1-18);
	line(x1+18,y1,x1,y1-18);
	line(x1-22,y1-2,x1,y1-24);
	line(x1,y1-24,x1+22,y1-2);
	line(x1-22,y1-2,x1-18,y1);
	line(x1+22,y1-2,x1+18,y1);
	line(x1-15,y1-13,x1-8,y1-20);
	line(x1-15,y1-13,x1-15,y1-24);
	line(x1-8,y1-20,x1-8,y1-24);
	line(x1-8,y1-24,x1-15,y1-24);
	setcolor(15);
	//exit box
	rectangle(505,205,565,265);
	setfillstyle(1,8);
	bar(507,207,563,263);
	int x3=535,y3=235;
	setcolor(0);
	rectangle(506,206,564,264);
	line(x3+5,y3-11,x3+5,y3-20);
	line(x3+1,y3-11,x3+1,y3-16);
	line(x3+5,y3+11,x3+5,y3+20);
	line(x3+1,y3+11,x3+1,y3+16);
	line(x3+1,y3-11,x3+5,y3-11);
	line(x3+1,y3+11,x3+5,y3+11);
	line(x3+5,y3+20,x3-20,y3+20);
	line(x3+1,y3+16,x3-16,y3+16);
	line(x3+5,y3-20,x3-20,y3-20);
	line(x3+1,y3-16,x3-16,y3-16);
	line(x3-20,y3-20,x3-20,y3+20);
	line(x3-16,y3-16,x3-16,y3+16);
	line(x3-10,y3-6,x3+7,y3-6);
	line(x3-10,y3+6,x3+7,y3+6);
	line(x3-10,y3-6,x3-10,y3+6);
	line(x3+7,y3-6,x3+7,y3-12);
	line(x3+7,y3+6,x3+7,y3+12);
	line(x3+7,y3-12,x3+21,y3);
	line(x3+7,y3+12,x3+21,y3);
	setcolor(15);
	setfillstyle(1,8);
	floodfill(471,56,15);
	setfillstyle(1,7);
	floodfill(507,137,0);
	floodfill(507,207,0);
	setcolor(15);
	rectangle(475,275,595,450);
	setfillstyle(1,7);
	floodfill(476,276,15);
	setcolor(15);
	rectangle(475,50,595,130);
	setfillstyle(1,7);
	floodfill(478,51,15);
	setcolor(8);
	settextstyle(TRIPLEX_FONT,0,3);
	outtextxy(480,45,"Made By:");
	outtextxy(480,65,"Lakhan");
	outtextxy(480,85,"Nitin");
	outtextxy(480,105,"Ram");
}
void drawpiece(char type,int col, int i, int j)
{
	int x=(board[i][j].x1+board[i][j].x2)/2,y=(board[i][j].y1+board[i][j].y2)/2;
	int pcol;
	if(col==15)
		pcol=0;
	else
		pcol=15;
	switch(type)
	{
		case 'p':
		setcolor(pcol);
		ellipse(x,y-11,0,360,6,6);
		rectangle(x-7,y-5,x+7,y-1);
		line(x-5,y-1,x-9,y+15);
		line(x+5,y-1,x+9,y+15);
		rectangle(x-15,y+15,x+15,y+20);
		setfillstyle(1,col);
		floodfill(x,y-11,pcol);
		floodfill(x-5,y-4,pcol);
		floodfill(x,y+2,pcol);
		floodfill(x-14,y+16,pcol);
		break;
		case 'm':
		setcolor(pcol);
		rectangle(x-1,y-21,x+1,y-8);
		rectangle(x-6,y-17,x+6,y-15);
		line(x-10,y-8,x+10,y-8);
		line(x-10,y-8,x-3,y+1);
		line(x+10,y-8,x+3,y+1);
		line(x-3,y+1,x+3,y+1);
		line(x-3,y+1,x-10,y+15);
		line(x+3,y+1,x+10,y+15);
		rectangle(x-17,y+15,x+17,y+22);
		setfillstyle(1,col);
		floodfill(x-16,y+16,pcol);
		floodfill(x,y+10,pcol);
		floodfill(x,y-3,pcol);
		floodfill(x,y-19,pcol);
		floodfill(x,y-10,pcol);
		floodfill(x,y-16,pcol);
		floodfill(x-4,y-16,pcol);
		floodfill(x+4,y-16,pcol);
		break;
		case 'q':
		setcolor(pcol);
		ellipse(x,y-18,300,240,3,3);
		rectangle(x-7,y-2,x+7,y+1);
		line(x-3,y+1,x-9,y+15);
		line(x+3,y+1,x+9,y+15);
		ellipse(x,y-11,120,180,4,5);
		ellipse(x,y-11,0,60,4,5);
		ellipse(x+10,y-2,90,180,5,8);
		ellipse(x-10,y-2,0,90,5,8);
		ellipse(x-5,y-2,90,120,11,9);
		ellipse(x+5,y-2,60,90,11,9);
		rectangle(x-17,y+15,x+17,y+22);
		setfillstyle(1,col);
		floodfill(x-16,y+16,pcol);
		floodfill(x,y,pcol);
		floodfill(x,y-5,pcol);
		floodfill(x,y+5,pcol);
		break;
		case 'k':
		setcolor(pcol);
		line(x-10,y+10,x-10,y+15);
		line(x+10,y+10,x+10,y+15);
		line(x-10,y+10,x-7,y+8);
		line(x+10,y+10,x+7,y+8);
		line(x-12,y+8,x+12,y+8);
		line(x+12,y+8,x+10,y-7);
		line(x-12,y+8,x-14,y+6);
		line(x-14,y+6,x-3,y-3);
		line(x+10,y-7,x,y-21);
		line(x-4,y-21,x,y-21);
		line(x-4,y-21,x-4,y-19);
		line(x-4,y-19,x-8,y-17);
		line(x-8,y-17,x-14,y-10);
		line(x-14,y-10,x-12,y-5);
		line(x-12,y-5,x-10,y-5);
		line(x-10,y-5,x-7,y-8);
		line(x-7,y-8,x-3,y-3);
		rectangle(x-17,y+15,x+17,y+22);
		setfillstyle(1,col);
		floodfill(x-16,y+16,pcol);
		floodfill(x,y-12,pcol);
		floodfill(x,y+13,pcol);
		break;
		case 'r':
		setcolor(pcol);
		line(x-13,y-6,x+13,y-6);
		line(x-13,y-19,x-13,y-6);
		line(x+13,y-19,x+13,y-6);
		ellipse(x-13,y-11,0,90,7,8);
		ellipse(x,y-11,0,180,7,8);
		ellipse(x+13,y-11,90,180,7,8);
		line(x-10,y-6,x-8,y);
		line(x-8,y,x-12,y+15);
		line(x+10,y-6,x+8,y);
		line(x+8,y,x+12,y+15);
		rectangle(x-17,y+15,x+17,y+22);
		setfillstyle(1,col);
		floodfill(x,y,pcol);
		floodfill(x-16,y+16,pcol);
		floodfill(x,y-10,pcol);
		break;
		case 'b':
		setcolor(pcol);
		ellipse(x-12,y-21,270,360,12,13);
		ellipse(x+12,y-21,180,270,12,13);
		ellipse(x-12,y+2,0,90,6,10);
		ellipse(x+12,y+2,90,180,6,10);
		line(x-6,y+2,x+6,y+2);
		rectangle(x-4,y+2,x+4,y+4);
		line(x-5,y+4,x+5,y+4);
		line(x-5,y+4,x-9,y+15);
		line(x+5,y+4,x+9,y+15);
		rectangle(x-17,y+15,x+17,y+22);
		setfillstyle(1,col);
		floodfill(x-16,y+16,pcol);
		floodfill(x,y+10,pcol);
		floodfill(x,y+3,pcol);
		floodfill(x,y-10,pcol);
		break;
		default:
		break;
	}
}
void drawbox(int i, int j)
{
	int pcol;
	if(board[i][j].col==7)
		pcol=8;
	else
		pcol=7;
	setfillstyle(1,board[i][j].col);
	bar(board[i][j].x1,board[i][j].y1,board[i][j].x2,board[i][j].y2);
	setcolor(pcol);
	rectangle(board[i][j].x1,board[i][j].y1,board[i][j].x2,board[i][j].y2);
	if(board[i][j].playercol!=10)
	{
		if(board[i][j].playercol==0)
		{
			drawpiece(pb->gettype(board[i][j].pnum),0,i,j);
		}
		else
		{
			drawpiece(pw->gettype(board[i][j].pnum),15,i,j);
		}
	}
}
void mhighlight(int i, int j, int pcol)
{
	setcolor(pcol);
	rectangle(board[i][j].x1+1,board[i][j].y1+1,board[i][j].x2-1,board[i][j].y2-1);
	rectangle(board[i][j].x1+2,board[i][j].y1+2,board[i][j].x2-2,board[i][j].y2-2);
	setfillstyle(1,pcol);
	floodfill(board[i][j].x1+2,board[i][j].y1+2,pcol);
}
void dehighlight(int i, int j)
{
	setcolor(board[i][j].col);
	rectangle(board[i][j].x1+1,board[i][j].y1+1,board[i][j].x2-1,board[i][j].y2-1);
	rectangle(board[i][j].x1+2,board[i][j].y1+2,board[i][j].x2-2,board[i][j].y2-2);
	setfillstyle(1,board[i][j].col);
	floodfill(board[i][j].x1+2,board[i][j].y1+2,board[i][j].col);
}
void clearmsg()
{
	setfillstyle(1,7);
	bar(475,275,595,450);
	setcolor(15);
	rectangle(475,275,595,450);
}
void dispmsg(char s1[], char s2[], char s3[], char s4[], char s5[])
{
	clearmsg();
	setcolor(8);
	settextstyle(SANS_SERIF_FONT,0,3);
	outtextxy(485,278,"");
	outtextxy(485,278,"");
	outtextxy(485,278,"");
	outtextxy(485,278,"");
	outtextxy(485,278,"    ");
	outtextxy(485,278,"");
	outtextxy(485,288,s1);
	outtextxy(485,318,s2);
	outtextxy(485,348,s3);
	outtextxy(485,378,s4);
	outtextxy(485,408,s5);
}
void drawpromote()
{
	clearmsg();
	setcolor(8);
	settextstyle(SANS_SERIF_FONT,0,3);
	rectangle(480,313,590,343);
	rectangle(480,348,590,378);
	rectangle(480,383,590,413);
	rectangle(480,418,590,448);
	outtextxy(485,278,"");
	outtextxy(485,278,"");
	outtextxy(485,278,"");
	outtextxy(485,278,"");
	outtextxy(485,278,"    ");
	outtextxy(485,278,"");
	outtextxy(485,278,"SELECT");
	outtextxy(485,313,"QUEEN");
	outtextxy(485,348,"ROOK");
	outtextxy(485,383,"BISHOP");
	outtextxy(485,418,"KNIGHT");
}
void drawabout()
{
	setfillstyle(1,0);
	bar(45,45,455,455);
	setcolor(15);
	rectangle(45,45,455,455);
	settextstyle(DEFAULT_FONT,0,1);
	outtextxy(50,50,"Chess ia a strategy based board game. Board is 8*8.");
	outtextxy(50,70,"It is played between two plaers black and white.");
	outtextxy(50,90,"Each player has 16 pieces each having unique moves.");
	outtextxy(50,110,"8 pawns,2 rook,2 bishop,2 knight,a queen and king.");
	outtextxy(50,130,"This pieces are placed on one of the 64 squares.");
	outtextxy(50,150,"Players move their pieces starting with white.");
	outtextxy(50,170,"Player can capture opponent's piece by moving");
	outtextxy(50,190,"their piece to place occupied by opponent's piece.");
	outtextxy(50,210,"Captured piece is then removed from board.");
	outtextxy(50,230,"The Goal of game is to capture opponent's king.");
	outtextxy(50,250,"Normally a player can move only one piece.");
	outtextxy(50,270,"Castling is exception to it where two pieces move");
	outtextxy(50,290,"Apart from normal moves there are special moves.");
	outtextxy(50,310,"Catstling and en-passant are two special moves.");
	outtextxy(50,330,"There are specific rules to when can player use it.");
	outtextxy(50,350,"Pawns on reaching opposite side gets promoted.");
	outtextxy(50,370,"A player must try to capture opponent's piece.");
	settextstyle(DEFAULT_FONT,0,2);
	outtextxy(50,390,"HOPE YOU ENJOY THE GAME");
}
void redraw()
{
	setfillstyle(1,0);
	bar(45,45,455,455);
	setcolor(15);
	rectangle(45,45,455,455);
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			drawbox(i,j);
		}
	}
}