/*
This Is Game Of Tic Tac Toe
You Can Play Against Computer
Or Against Another Player
It Is Made By
Lakhan, Nitin and Ram
*/
#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<stdio.h>
#include<string.h>


int board[3][3]={{2,2,2},{2,2,2},{2,2,2}};
// minimax algorithm and computers chance

int board_value(int temp[3][3])
{
	int i;
	for(i=0; i<3; i++) //checking for rows
	{
		if(temp[i][0]==temp[i][1] && temp[i][1]==temp[i][2])
		{
		if(temp[i][0]==0)
				return -10;
		else if(temp[i][0]==1)
				return +10;
		}
	}
	for(i=0; i<3; i++) //checking for coloumns
	{
	    if(temp[0][i]==temp[1][i] && temp[1][i]==temp[2][i])
		{
		if(temp[0][i]==0)
				return -10;
		else if(temp[0][i]==1)
				return +10;
		}
	}
	if(board[0][0]==temp[1][1] && temp[1][1]==temp[2][2]) //checking for left diagnol
	{
	if(temp[1][1]==0)
			return -10;
		else if(temp[1][1]==1)
			return 10;
	}
	if(temp[0][2]==temp[1][1] && temp[1][1]==temp[2][0]) //checking for right diagnol
	{
	if(temp[1][1]==0)
			return -10;
		else if(temp[1][1]==1)
			return 10;
	}
	return 0;
}



int movs_left()
{
	int n=0;
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			if(board[i][j]==2)
				n++;

	return n;
}


struct node
{
	int row;
	int col;
	int score;
}ptr,pt;


int minmax(int l, int c)
{
	if(board_value(board) == 10 && l>=0)
		return board_value(board) -9 + l;
	else if(board_value(board) == -10 && l>=0)
		return board_value(board) +9 -l;
	else if(l==0 && board_value(board)==0)
		return 0;
	else
	{   int score;
	    int value;
	    int t=0;
	    for(int i=0; i<3; i++)
	    {
			for(int j=0; j<3; j++)
		    {
			    if(board[i][j]==2)
			    {
				    board[i][j]=c;
				    score=minmax(l-1,!c);
				    if(c==1)
				    {
				    if(score>value && t>0)
				    value=score;
				    if(t==0)
				    value=score;
				    }
				    if(c==0)
				    {
				    if(score<value && t>0)
				    value=score;
				    if(t==0)
				    value=score;
				    }
				    t++;
				    board[i][j]=2;
			    }
		    }
	    }
		return value;
	}
}

void mychance()
{   delay(1500);
	int c=movs_left();
	int t=0;
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			if(board[i][j]==2)
			{
				board[i][j]=1;
				pt.row=i;
				pt.col=j;
				pt.score=minmax(c-1,0);
				if(pt.score>ptr.score && t>0)
				ptr=pt;
				if(t==0)
				ptr=pt;
				t++;
				board[i][j]=2;
			}
		}
	}

	board[ptr.row][ptr.col]=1;
}


// end of minimax algorithm

//mouse functions
union REGS in,out;

int checkmouseboxj(int x)
{
	if(x>265 && x<365)
	{
		return 2;
	}
	else if(x>155 && x<255)
	{
		return 1;
	}
	else if(x>45 && x<145)
	{
		return 0;
	}
	return -1;
}



int checkmouseboxi(int y)
{
	if(y>295 && y<395)
	{
		return 2;
	}
	else if(y>185 && y<285)
	{
		return 1;
	}
	else if(y>75 && y<175)
	{
		return 0;
	}
	return -1;
}


void mouseposn(int &x,int &y,int &n)
 {
 in.x.ax=3;
 int86(51,&in,&out);
 n=out.x.bx;
 x=out.x.cx;
 y=out.x.dx;
 }

void mouse()
 {
 in.x.ax=1;
 int86(51,&in,&out);
 in.x.ax=7;
 in.x.cx=40;
 in.x.dx=370;
 int86(51,&in,&out);
 in.x.ax=8;
 in.x.cx=70;
 in.x.dx=400;
 int86(51,&in,&out);
 }

 void hidemouse()
 {
 in.x.ax=2;
 int86(51,&in,&out);
 }

//all mouse functions made

void playchance(int c) //play chance for players 
{
	mouse();
	int x,y,b=0,k=0;
	while(k==0)
	{
		mouseposn(x,y,b);
		if(b==1)
		{
			if(checkmouseboxi(x)  != -1 && checkmouseboxj(y) != -1)
			{
			if(board[checkmouseboxi(y)][checkmouseboxj(x)]==2)
			{
				board[checkmouseboxi(y)][checkmouseboxj(x)]=c;
			    k=1;
			}
			}
		}

	}
	hidemouse();
}

int copy[3][3]={{2,2,2},{2,2,2},{2,2,2}};
void draw_mark(char ch) // draw marks on screen
{
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			if(copy[i][j]!=board[i][j])
			{
			if(ch=='o')
				circle(95+j*110,125+i*110,50);
			else
		    {
				line(45+j*110,75+i*110,145+j*110,175+i*110);
				line(145+j*110,75+i*110,45+j*110,175+i*110);
			}
			copy[i][j]=board[i][j];
			}
		}
	}

}

void draw_start(char str[]) // draw game interface
{
clrscr();
int gdriver = DETECT, gmode;
initgraph (&gdriver, &gmode, "c:\\turboc3\\bgi");
cleardevice();
setcolor(8);
struct linesettingstype ls;
getlinesettings(&ls);
setlinestyle(1,0,3);
line(10,10,10,460);
line(610,10,610,460);
line(10,10,610,10);
line(10,460,610,460);
settextjustify(1,2);
settextstyle(3,0,4);
outtextxy(310,15,"TIC TAC TOE");
settextstyle(3,0,2);
outtextxy(315,45,str);
settextjustify(0,2);
setlinestyle(0,0,2);
int i;
for(i=10; i<=330; i+=10)
{
line(150,70+i-10,150,70+i);
delay(50);
}
for(i=10; i<=330; i+=10)
{
line(260,70+i-10,260,70+i);
delay(50);
}
for(i=10; i<=330; i+=10)
{
line(40+i-10,180,40+i,180);
delay(50);
}
for(i=10; i<=330; i+=10)
{
line(40+i-10,290,40+i,290);
delay(50);
}
settextjustify(1,2);
settextstyle(3,0,3);
outtextxy(490,300,"Made By:Lakhan");
outtextxy(490,320,"Nitin and Ram");
setlinestyle(ls.linestyle,ls.upattern,ls.thickness);
}

void draw_line(int w) // draw line if team wins
{   int i;
setlinestyle(2,0,3);
	if(w==1)
	for(i=10; i<=330; i+=10)
    {
    line(40+i-10,125,40+i,125);
    delay(50);
    }
	else if(w==2)
	for(i=10; i<=330; i+=10)
    {
    line(40+i-10,235,40+i,235);
    delay(50);
    }
	else if(w==3)
	for(i=10; i<=330; i+=10)
    {
    line(40+i-10,345,40+i,345);
    delay(50);
    }
	else if(w==4)
    for(i=10; i<=330; i+=10)
    {
    line(95,70+i-10,95,70+i);
    delay(50);
    }
	else if(w==5)
    for(i=10; i<=330; i+=10)
    {
    line(205,70+i-10,205,70+i);
    delay(50);
    }
	else if(w==6)
    for(i=10; i<=330; i+=10)
    {
    line(315,70+i-10,315,70+i);
    delay(50);
    }
	else if(w==7)
    for(i=10; i<=330; i+=10)
    {
    line(40+i-10,70+i-10,40+i,70+i);
    delay(50);
    }
	else
    for(i=10; i<=330; i+=10)
    {
    line(370-i+10,70+i-10,370-i,70+i);
    delay(50);
    }
}

int win() // check if a team has won
{
    int i;
	for(i=0; i<3; i++) //checking for rows
	{
		if(board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][0]!=2)
		{
	draw_line(1+i);
		if(board[i][0]==0)
				return 1;
		else if(board[i][0]==1)
				return 2;
		}
	}
	for(i=0; i<3; i++) //checking for coloumns
	{
	    if(board[0][i]==board[1][i] && board[1][i]==board[2][i] && board[0][i]!=2)
		{
	draw_line(4+i);
		if(board[0][i]==0)
				return 1;
		else if(board[0][i]==1)
				return 2;
		}	
	}
	if(board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[1][1]!=2) //checking for left diagnol
	{
        draw_line(7);
		if(board[1][1]==0)
			return 1;
		else if(board[1][1]==1)
			return 2;
	}
	if(board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[1][1]!=2) //checking for right diagnol
	{
        draw_line(8);
		if(board[1][1]==0)
			return 1;
		else if(board[1][1]==1)
			return 2;
	}
	return 0;
}	

void drawwin(int y, char name[]) // draws congratulations for winning team
{
	if(y==1)
	{
    settextstyle(3,0,4);
    outtextxy(490,80,name);
	delay(1000);
    outtextxy(490,120,"Has");
	delay(1000);
    outtextxy(490,160,"Won");
	delay(1000);
    outtextxy(490,200,"The");
	delay(1000);
    outtextxy(490,240,"Game");		
	}
	else
	{
	settextstyle(3,0,4);
    outtextxy(490,80,"The");
	delay(1000);
    outtextxy(490,120,"Game");
	delay(1000);
    outtextxy(490,160,"Has");
	delay(1000);
    outtextxy(490,200,"Drawn");
    }
}

struct gaccount
{
	int p;
	char m;
	char name1[50];
	char name2[50];
	int np;
	int nw1;
	int nw2;
	int dr;
	void store(int a, char r, char n1[50], char n2[50])
	{
		p=a;
		m=r;
		strcpy(name1,n1);
		strcpy(name2,n2);
		np=0;
		nw1=0;
		nw2=0;
		dr=0;
	}
}game;

void game_start(int p, char m, char name1[50], char name2[50]) // controls games progress
{   (game.np)++;
	int wi=0;
	if(p==2)
	{
		char head[50]="";
		strcat(head,name1);
		strcat(head," VS ");
		strcat(head,name2);
		draw_start(head);
		int c;
	    char chm[2];
		if(m=='o')
			c=0;
		else
			c=1;
		chm[c]='o';
		chm[!c]='x';
		while(movs_left()!=0 && wi==0)
		{
			playchance(c);
			draw_mark(chm[c]);
			c=!c;
			delay(1000);
			wi=win();
		}
		if(wi==1)
		{
			(game.nw1)++;
			drawwin(1,name1);
		}
		else if(wi==2)
		{
			(game.nw2)++;
			drawwin(1,name2);
		}
		else
		{
			(game.dr)++;
			drawwin(0," ");
		}
	}
	else
	{
		char head[50]="";
		strcat(head,name1);
		strcat(head," VS ");
		strcat(head,name2);
		draw_start(head);
		int c;
		char chm[2];
		if(m=='o')
			c=0;
		else
			c=1;
		chm[c]='o';
		chm[!c]='x';
		while(movs_left()!=0 && wi==0)
		{
			if(c==0)
				playchance(0);
			else
				mychance();
			draw_mark(chm[c]);
			c=!c;
			delay(100);
			wi=win();
		}
		if(wi==1)
		{
			(game.nw1)++;
			drawwin(1,name1);
		}
		else if(wi==2)
		{
			(game.nw2)++;
			drawwin(1,name2);
		}
		else
		{
			(game.dr)++;
			drawwin(0," ");
		}
	}
	delay(2000);
    cleardevice();
    closegraph();
    restorecrtmode();
	for(int a=0; a<3; a++)
		for(int b=0; b<3; b++)
			board[a][b]=copy[a][b]=2;
}

void gameplay() // starts games initialization
{
clrscr();
cout<<"Welcome To Tic Tac Toe"<<endl;
delay(1000);
cout<<"Choose One Option"<<endl;
cout<<"1. Single Player"<<endl;
cout<<"2. Double Player"<<endl;
char ch;
cin>>ch;
delay(1000);
switch(ch)
{
case '1':
    char name[50];
    cout<<"Please Enter Your Name:"<<endl;
    gets(name);
    cout<<endl;
    cout<<"Select your Mark"<<endl;
	cout<<"1. O (O will play first turn)"<<endl;
	cout<<"2. X (X will play second turn)"<<endl;
    char ch1;
    cin>>ch1;
    switch(ch1)
    {
    case '1':game.store(1,'o',name,"Computer");
	   game_start(1,'o',name,"Computer");
	   break;
    case '2':game.store(1,'x',name,"Computer");
	   game_start(1,'x',name,"Computer");
	   break;
    default:cout<<"Wrong Choice";
	      gameplay();
    }
    break;
case '2':
    char name1[50];
	char name2[50];
    cout<<"Please Enter First Player's Name:"<<endl;
    gets(name1);
	cout<<"Please Enter Second Player's Name:"<<endl;
    gets(name2);
    cout<<endl;
    cout<<"Select First Player's Mark"<<endl;
	cout<<"1. O (O will play first turn)"<<endl;
	cout<<"2. X (X will play second turn)"<<endl;
    char ch2;
    cin>>ch2;
    switch(ch2)
    {
    case '1':game.store(2,'o',name1,name2);
	   game_start(2,'o',name1,name2);
	   break;
    case '2':game.store(2,'x',name1,name2);
	   game_start(2,'x',name1,name2);
	   break;
    default:cout<<"Wrong Choice";
              gameplay();
    }    
    break;
default:cout<<"Wrong Choice";
              gameplay();
}
}

void main()
{
gameplay();
start:
cout<<game.name1<<" VS "<<game.name2<<endl;
cout<<"No. of Games Played:"<<game.np<<endl;
cout<<"No. of Games Won By "<<game.name1<<":"<<game.nw1<<endl;
cout<<"No. of Games Won By "<<game.name2<<":"<<game.nw2<<endl;
cout<<"No. of Games Drawn:"<<game.dr<<endl;
delay(1000);
cout<<"Do You Want to Play Again?"<<endl;
cout<<"Press 1 To Continue, Press Any Other Button To Exit"<<endl;
char op;
op=getche();
if(op=='1')
{
	clrscr();
	delay(1000);
	game_start(game.p,game.m,game.name1,game.name2);
	goto start;
}
else
{
	delay(1000);
}
clrscr();
delay(1000);
cout<<"T";
delay(200);
cout<<"H";
delay(200);
cout<<"A";
delay(200);
cout<<"N";
delay(200);
cout<<"K";
delay(200);
cout<<" ";
delay(200);
cout<<"Y";
delay(200);
cout<<"O";
delay(200);
cout<<"U";
cout<<endl;
delay(1000);	
}

