#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<string.h>
#include<fstream.h>


//function prototypes
void main();
void newgame();
void about();
void exit();
void scorecard();
void statistics();
void mouse();
void hidemouse();
void mouseclick();
void intialize();
void draw();
void music(int n);
void drawmain();
void shield();
void removebox(int i);
void message(int n);
void checkwon();

//global variables
union REGS in,out;
struct block
{
	int x1;
	int x2;
	int y1;
	int y2;
	int col;
	int yes;
}b[60];
int blockbroken=0,chancelost=0,score;
struct statistic
 {
 int matchno;
 int scores;
 };
int abc=0,abcd=0;

void main()
{
	int gdriver=DETECT,gmode;
	initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
	cleardevice();
	intialize();
	drawmain();
	draw();
	//main functioning
	int area;
	char *p1,*p2;
	area=imagesize(205,393,225,413);
	p1=(char *)malloc(area);
	area=imagesize(165,415,265,425);
	p2=(char *)malloc(area);
	getimage(205,393,225,413,p1);
	getimage(165,415,265,425,p2);
	int dx=2,dy=-2;
	union REGS aa,bb;
	int start=0,opx,opy,obx,oby;
	int bx=205,by=393;
	int px=165,py=415;
	int chance=0;
	if(abcd==0)
	 {
	 mouse();
	 mouseclick();
	 }
	abcd=0;
	setcolor(15);
	setfillstyle(1,0);
	bar(416,331,589,439);
	settextstyle(DEFAULT_FONT,0,2);
	outtextxy(463,365,"HEY!!");
	outtextxy(442,390,"WELCOME");
	music(2);
	setfillstyle(1,0);
	bar(416,331,589,439);
	settextstyle(DEFAULT_FONT,0,1);
	outtextxy(430,340,"I AM BOUNCY.NICE");
	outtextxy(430,355,"TO MEET YOU.CAN");
	outtextxy(430,370,"YOU PLEASE HELP ME");
	outtextxy(430,385,"TO BREAK THE BLOCK.");
	outtextxy(430,400,"MR PADDLE WILL HELP");
	outtextxy(430,415,"YOU... :)");
	delay(4000);
	setfillstyle(1,0);
	bar(416,331,589,439);
	settextstyle(DEFAULT_FONT,0,1);
	outtextxy(430,350,"PRESS ARROW KEYS");
	outtextxy(430,365,"TO MOVE THE PADDLE.");
	outtextxy(430,380,"PRESS UPPER ARROW");
	outtextxy(430,395,"KEY TO START.");
	outtextxy(430,410,"BEST OF LUCK!");
jump:while(1)
	{
		if(start==1)
		{
			obx=bx;
			oby=by;
			bx=bx+dx;
			by=by+dy;
			//check left touch or hit
			if(bx<=26)
			{
				music(4);
				dx=-dx;
				bx=26;
			}
			//check right touch or hit
			if(bx>=384)
			{
				music(4);
				dx=-dx;
				bx=384;
			}
			//check bottom touch or hit
			int m;
			if(dx<0)
				m=-1;
			else
				m=1;
			if(by>393)
			{
				if((bx>=px-15&&bx<=px+10)||(bx>=px+70&&bx<=px+95))
				{
					music(5);
					by=393;
					dy=-dy;
					dx=m*4;
				}
				else if((bx>=px+10&&bx<=px+30)||(bx>=px+50&&bx<=px+70))
				{
					music(5);
					by=393;
					dy=-dy;
					dx=m*3;
				}
				else if(bx>=px+30&&bx<=px+50)
				{
					music(5);
					by=393;
					dy=-dy;
					dx=m*2;
				}
				else
				{
					putimage(obx,oby,p1,OR_PUT);
					putimage(obx,oby,p1,XOR_PUT);
					putimage(bx,by,p1,XOR_PUT);
					delay(25);
					chance++;
					chancelost++;
					music(2);
					message(6);
					for(int i=0;i<14;i++)
					{
						obx=bx;
						oby=by;
						bx=bx+dx;
						by=by+dy;
						if(bx<=26)
						 {
						 dx=-dx;
						 bx=26;
						 }
						if(bx>=384)
						 {
						 dx=-dx;
						 bx=384;
						 }
						putimage(obx,oby,p1,OR_PUT);
						putimage(obx,oby,p1,XOR_PUT);
						putimage(bx,by,p1,XOR_PUT);
						delay(25);
					}
					putimage(bx,by,p1,XOR_PUT);
					delay(1000);
					if(chance<3)
					{
						setfillstyle(1,0);
						bar(26,380,404,440);
						start=0;
						bx=205;
						by=393;
						px=165;
						py=415;
						putimage(bx,by,p1,XOR_PUT);
						putimage(px,py,p2,XOR_PUT);
						goto jump;
					}
					else
						checkwon();
				}
			}
			//check top touch or hit
			if(by<=56)
			{
				sound(4);
				dy=-dy;
				by=56;
			}
			if(by<230)
			{
				for(int i=0;i<60;i++)
				{
					if((b[i].y1<=(by+20))&&(b[i].y2>=(by+20))&&(b[i].x1<=(bx+10)&&b[i].x2>=(bx+10))&&(b[i].yes==1)&&dy==2)
					{
						dy=-dy;
						removebox(i);
					}
					else if((b[i].y1<=(by+10)&&b[i].y2>=(by+10))&&(b[i].x1<=bx&&b[i].x2>=bx)&&(b[i].yes==1)&&dx<0)
					{
						dx=-dx;
						removebox(i);
					}
					else if((b[i].y1<=(by+10))&&(b[i].y2>=(by+10))&&(b[i].x1<=(bx+20)&&b[i].x2>=(bx+20))&&(b[i].yes==1)&&dx>0)
					{
						dx=-dx;
						removebox(i);
					}
					else if((b[i].y1<=by)&&(b[i].y2>=by)&&(b[i].x1<=(bx+10)&&b[i].x2>=(bx+10))&&(b[i].yes==1)&&dy==-2)
					{
						dy=-dy;
						removebox(i);
					}
					else if((b[i].y1<=(by+5))&&(b[i].y2>=(by+5))&&(b[i].x1<=(bx+18)&&b[i].x2>=(bx+18))&&(b[i].yes==1))
					{
						dy=-dy;
						removebox(i);
					}
					else if((b[i].y1<=(by+2))&&(b[i].y2>=(by+2))&&(b[i].x1<=(bx+15)&&b[i].x2>=(bx+15))&&(b[i].yes==1))
					{
						dy=-dy;
						removebox(i);
					}
					else if((b[i].y1<=(by+2))&&(b[i].y2>=(by+2))&&(b[i].x1<=(bx+5)&&b[i].x2>=(bx+5))&&(b[i].yes==1))
					{
						dy=-dy;
						removebox(i);
					}
					else if((b[i].y1<=(by+5))&&(b[i].y2>=(by+5))&&(b[i].x1<=(bx+2)&&b[i].x2>=(bx+2))&&(b[i].yes==1))
					{
						dy=-dy;
						removebox(i);
					}
					else if((b[i].y1<=(by+15))&&(b[i].y2>=(by+15))&&(b[i].x1<=(bx+2)&&b[i].x2>=(bx+2))&&(b[i].yes==1))
					{
						dy=-dy;
						removebox(i);
					}
					else if((b[i].y1<=(by+18))&&(b[i].y2>=(by+18))&&(b[i].x1<=(bx+5)&&b[i].x2>=(bx+5))&&(b[i].yes==1))
					{
						dy=-dy;
						removebox(i);
					}
					else if((b[i].y1<=(by+18))&&(b[i].y2>=(by+18))&&(b[i].x1<=(bx+15)&&b[i].x2>=(bx+15))&&(b[i].yes==1))
					{
						dy=-dy;
						removebox(i);
					}
					else if((b[i].y1<=(by+15))&&(b[i].y2>=(by+15))&&(b[i].x1<=(bx+18)&&b[i].x2>=(bx+18))&&(b[i].yes==1))
					{
						dy=-dy;
						removebox(i);
					}
				}
			}
			putimage (obx,oby,p1,OR_PUT);
			putimage(obx,oby,p1,XOR_PUT);
			putimage(bx,by,p1,XOR_PUT);
			delay(25);
		}
		if(by>390&&start==1)
			continue;
		//move the paddle
		if(kbhit())
		{
			opx=px;
			opy=py;
			obx=bx;
			oby=by;
			aa.h.ah=0;
			int86(22,&aa,&bb);
			if(bb.h.ah==1)
			{
				mouse();
				mouseclick();
			}
			if(bb.h.ah==75&&px>27)
			{
				px=px-3;
				if(start==0)
					bx=bx-3;
			}
			if(bb.h.ah==77&&px<302)
			{
				px=px+3;
				if(start==0)
					bx=bx+3;
			}
			if(bb.h.ah==72)
				start=1;
			if(start==0)
			{
				putimage (obx,oby,p1,OR_PUT);
				putimage(obx,oby,p1,XOR_PUT);
				putimage(bx,by,p1,XOR_PUT);
			}
			putimage (opx,opy,p2,OR_PUT);
			putimage(opx,opy,p2,XOR_PUT);
			putimage(px,py,p2,XOR_PUT);
		}
	checkwon();
	}
}

//functions
void checkwon()
 {
 ofstream f("stats.dat",ios::binary|ios::out|ios::app);
 if(chancelost==3)
 {
 statistic ob;
 ob.matchno=1;
 score=100*blockbroken-500*chancelost;
 ob.scores=score;
 f.write((char *)&ob,sizeof(ob));
 f.close();
 scorecard();
 abc=1;
 mouse();
 mouseclick();
 }
 for(int i=0;i<60;i++)
  if(b[i].yes==1)
   return;
 statistic ob;
 ob.matchno=1;
 score=100*blockbroken-500*chancelost;
 ob.scores=score;
 f.write((char *)&ob,sizeof(ob));
 f.close();
 scorecard();
 abc=1;
 mouse();
 mouseclick();
 }

void message(int n)
 {
 switch(n)
  {
  case 0:setfillstyle(1,0);
	 bar(416,331,589,439);
	 settextstyle(DEFAULT_FONT,0,1);
	 outtextxy(430,350,"AT ANY POINT OF");
	 outtextxy(430,365,"TIME IN THE GAME");
	 outtextxy(430,380,"PRESS ESC TO PAUSE.");
	 outtextxy(430,395,"ENJOY!");
	 break;
  case 1:setfillstyle(1,0);
	 bar(416,331,589,439);
	 settextstyle(DEFAULT_FONT,0,2);
	 outtextxy(460,370,"GOOD");
	 outtextxy(454,395,"GOING!");
	 break;
  case 2:setfillstyle(1,0);
	 bar(416,331,589,439);
	 settextstyle(DEFAULT_FONT,0,2);
	 outtextxy(460,380,"NICE");
	 break;
  case 3:setfillstyle(1,0);
	 bar(416,331,589,439);
	 settextstyle(DEFAULT_FONT,0,2);
	 outtextxy(425,380,"EXCELLENT!");
	 break;
  case 4:setfillstyle(1,0);
	 bar(416,331,589,439);
	 settextstyle(DEFAULT_FONT,0,2);
	 outtextxy(420,380,"ENJOYING??");
	 break;
  case 5:setfillstyle(1,0);
	 bar(416,331,589,439);
	 settextstyle(DEFAULT_FONT,0,2);
	 outtextxy(420,360,"NEW LEVELS");
	 outtextxy(420,380,"COMING UP");
	 outtextxy(420,400,"SOON...:)");
	 break;
  case 6:setfillstyle(1,0);
	 bar(416,331,589,439);
	 settextstyle(DEFAULT_FONT,0,2);
	 outtextxy(480,370,"BE");
	 outtextxy(440,395,"CAREFUL!");
	 break;
  }
 }

void newgame()
{
	chancelost=0;
	blockbroken=0;
	hidemouse();
	abcd=1;
	main();
}

void about()
{
    hidemouse();
	setfillstyle(1,0);
	bar(26,56,404,444);
	setcolor(15);
	settextstyle(TRIPLEX_FONT,0,3);
	outtextxy(180,60,"ABOUT");
	settextstyle(DEFAULT_FONT,0,1);
	outtextxy(40,110,"BLOCK BREAKER IS A SINGLE PLAYER GAME.IN");
	outtextxy(40,125,"THIS GAME THERE ARE MANY BLOCKS,A PADDLE AND");
	outtextxy(40,140,"A BALL.YOU HAVE TO BREAK ALL THE BLOCKS USING");
	outtextxy(40,155,"THE BALL.DONT LET THE BALL FALL DOWN.YOU CAN");
	outtextxy(40,170,"MOVE THE PADDLE USING THE ARROW KEYS.AT ANY");
	outtextxy(40,185,"TIME OF THE GAME YOU CAN PAUSE IT USING THE");
	outtextxy(40,200,"ESC KEY.TO LET THE GAME START USE THE UPPER");
	outtextxy(40,215,"ARROW KEY.EVERY TIME THE BALL FALLS YOU WILL");
	outtextxy(40,230,"LOSE 500 POINTS AND EVERY TIME YOU BREAK THE");
	outtextxy(40,245,"BLOCK YOU GET 100 POINTS.YOU GET THREE BALLS.");
	outtextxy(40,260,"HOPE YOU ALL ENJOY THE GAME.");
	outtextxy(40,290,"THE GAME IS DESIGNED IN SIMPLE C");
	outtextxy(40,305,"LANGUAGE WITH SOME OF THE SYNTAX OF");
	outtextxy(40,320,"C++.");
	outtextxy(40,335,"DESIGNERS:-NITIN SULTANIA");
	outtextxy(40,350,"           RAM NAD");
	outtextxy(40,365,"           LAKHAN NAD");
	outtextxy(40,380,"AND SPECIAL THANKS TO MANORANJAN SIR");
	outtextxy(40,395,"FOR BEING THE PART OF THE PROJECT.");
	outtextxy(40,410,"              THANK YOU            ");
	abc=1;
	mouse();
	mouseclick();
}

void exit()
{
	exit(0);
}

void scorecard()
{
	setcolor(15);
	setfillstyle(1,0);
	bar(416,331,589,439);
	hidemouse();
	score=100*blockbroken-500*chancelost;
	settextstyle(DEFAULT_FONT,0,2);
	outtextxy(435,340,"SCORECARD");
	settextstyle(DEFAULT_FONT,0,1);
	outtextxy(430,365,"BLOCK BROKEN:-");
	outtextxy(430,380,"CHANCE LOST:-");
	outtextxy(430,395,"SCORE:-");
	char *sc=new char[5];
	char *bb=new char[3];
	char *bl=new char[2];
	itoa(score,sc,10);
	itoa(blockbroken,bb,10);
	itoa(chancelost,bl,10);
	outtextxy(540,380,bl);
	outtextxy(490,395,sc);
	outtextxy(545,365,bb);
	if(score==6000)
	outtextxy(430,420,"UNBEATABLE!!");
	else if(score>5500)
	outtextxy(430,420,"BRAVO!!");
	else if(score>5000)
	outtextxy(430,420,"EXCELLENT!!");
	else if(score>4000)
	outtextxy(430,420,"GOOD!!");
	else if(score>3000)
	outtextxy(430,420,"KEEP GOING!!");
	else
	outtextxy(430,420,"PUSH UP!!");
	abc=1;
	mouse();
	mouseclick();
}

void statistics()
{
 hidemouse();
 int matchplayed=0,score5000=0,score4000=0,score3000=0;
 ifstream f("stats.dat",ios::binary|ios::in);
 statistic ob;
 while(f.read((char*)&ob,sizeof(ob)))
  {
  if(ob.matchno==1)
   matchplayed++;
  if(ob.scores>5000)
   score5000++;
  else if(ob.scores>4000)
   score4000++;
  else
   score3000++;
  }
  f.close();
  setcolor(15);
	setfillstyle(1,0);
	bar(416,331,589,439);
	hidemouse();
	settextstyle(DEFAULT_FONT,0,2);
	outtextxy(425,340,"STATISTICS");
	settextstyle(DEFAULT_FONT,0,1);
	outtextxy(430,365,"MATCH PLAYED:-");
	outtextxy(430,380,"SCORE>5000:-");
	outtextxy(430,395,"SCORE>4000:-");
	outtextxy(430,410,"SCOTE<4000:-");
	char *mp=new char[5];
	char *s5=new char[3];
	char *s4=new char[3];
	char *s3=new char[3];
	itoa(matchplayed,mp,10);
	itoa(score5000,s5,10);
	itoa(score4000,s4,10);
	itoa(score3000,s3,10);
	outtextxy(545,365,mp);
	outtextxy(540,380,s5);
	outtextxy(540,395,s4);
	outtextxy(540,410,s3);
	abc=1;
	mouse();
	mouseclick();
}

void mouse()
{
	in.x.ax=1;
	int86(51,&in,&out);
	in.x.ax=4;
	in.x.cx=550;
	in.x.dx=370;
	int86(51,&in,&out);
	in.x.ax=7;
	in.x.cx=410;
	in.x.dx=595;
	int86(51,&in,&out);
	in.x.ax=8;
	in.x.cx=55;
	in.x.dx=445;
	int86(51,&in,&out);
}

void hidemouse()
{
	in.x.ax=1;
	int86(51,&in,&out);
	in.x.ax=2;
	int86(51,&in,&out);
}

void mouseclick()
{
	int n=0,x1,y1;
	while(n==0)
	{
		in.x.ax=3;
		int86(51,&in,&out);
		n=out.x.bx;
		x1=out.x.cx;
		y1=out.x.dx;
		if(n!=1)
		{
			n=0;
		}
		else
		{
			delay(300);
			if(x1>415&&x1<590&&y1>60&&y1<100)
			{
				about();
				mouse();
			}
			if(x1>415&&x1<590&&y1>105&&y1<145)
				exit();
			if(x1>415&&x1<590&&y1>150&&y1<190)
				newgame();
			if(x1>415&&x1<590&&y1>195&&y1<235)
			{
				hidemouse();
				if(chancelost==3)
				 newgame();
				if(abc==1)
				 {
				 abc=0;
				 newgame();
				 }
				else
				return;
			}
			if(x1>415&&x1<590&&y1>240&&y1<280)
				scorecard();
			if(x1>415&&x1<590&&y1>285&&y1<325)
				statistics();
		}
		n=0;
    }
}

void intialize()
{
	int i,c=1;
	for(i=0;i<60;i++)
	{
		if(i%6==0 && i!=0)
			c++;
		if(c==1||c==4||c==7||c==10)
		{
			if(c==1)
			{
				b[i].x1=40;
				b[i].x2=80;
			}
			else if(c==4)
			{
				b[i].x1=143;
				b[i].x2=183;
			}
			else if(c==7)
			{
				b[i].x1=246;
				b[i].x2=286;
			}
			else if(c==10)
			{
				b[i].x1=349;
				b[i].x2=389;
			}
			b[i].y1=70+25*(i%6);
			b[i].y2=70+25*((i%6)+1);
			b[i].col=8;
		}
		if(c==2||c==5||c==8)
		{
			if(c==2)
			{
				b[i].x1=81;
				b[i].x2=101;
			}
			else if(c==5)
			{
				b[i].x1=184;
				b[i].x2=204;
			}
			else if(c==8)
			{
				b[i].x1=287;
				b[i].x2=307;
			}
			b[i].y1=70+25*(i%6);
			b[i].y2=70+25*((i%6)+1);
			b[i].col=9;
		}
		if(c==3||c==6||c==9)
		{
			if(c==3)
			{
				b[i].x1=102;
				b[i].x2=142;
			}
			else if(c==6)
			{
				b[i].x1=205;
				b[i].x2=245;
			}
			else if(c==9)
			{
				b[i].x1=308;
				b[i].x2=348;
			}
			b[i].y1=70+25*(i%6);
			b[i].y2=70+25*((i%6)+1);
			b[i].col=11;
		}
	}
	for(i=0;i<60;i++)
		b[i].yes=1;
}

void draw()
{
	for(int i=0;i<60;i++)
	{
		if(b[i].yes==1)
		{
			setfillstyle(1,b[i].col);
			bar(b[i].x1,b[i].y1,b[i].x2,b[i].y2);
			setcolor(0);
			rectangle(b[i].x1,b[i].y1,b[i].x2,b[i].y2);
		}
	}
}

void music(int type)
{
	float octave[7]={130.8,146.83,164.81,174.61,196,220,246.94};
	int n,i;
	randomize();
	switch(type)
	{
		case 1:for(i=0;i<7;i++)
			{
				sound(octave[i]*8);
				delay(10);
			}
			nosound();
			break;
		case 2:for(i=0;i<15;i++)
			{
				n=random(7);
				sound(octave[n]*4);
				delay(100);
			}
			nosound();
			break;
		case 3:while(!kbhit())
			{
				n=random(7);
				sound(octave[n]*4);
				delay(100);
			}
			nosound();
			break;
		case 4:for(i=4;i>=0;i--)
			{
				sound(octave[i]*4);
				delay(8);
			}
			nosound();
			break;
		case 5:sound(octave[6]*2);
		delay(20);
		nosound();
			break;
	}
}


void drawmain()
{
	cleardevice();
	settextstyle(TRIPLEX_FONT,0,4);
	outtextxy(180,10,"BLOCK BREAKER");
	//outer boundary
	rectangle(20,50,600,450);
	//inner boundaries
	rectangle(25,55,405,445);
	rectangle(410,55,595,445);
	//functional boxes
	settextstyle(TRIPLEX_FONT,0,2);
	rectangle(415,60,590,100);
	outtextxy(465,70,"ABOUT");
	rectangle(415,105,590,145);
	outtextxy(475,115,"EXIT");
	rectangle(415,150,590,190);
	outtextxy(450,160,"NEW GAME");
	rectangle(415,195,590,235);
	outtextxy(450,205,"CONTINUE");
	rectangle(415,240,590,280);
	outtextxy(450,250,"SCORECARD");
	rectangle(415,285,590,325);
	outtextxy(450,295,"STATISTICS");
	rectangle(415,330,590,440);
	settextstyle(DEFAULT_FONT,0,1);
	outtextxy(240,460,"c ALL RIGHTS RESERVED");
	circle(243,463,6);
	setcolor(8);
	setfillstyle(1,7);
	bar(165,415,265,425);
	setfillstyle(1,14);
	bar(165,415,185,425);
	bar(245,415,265,425);
	rectangle(165,415,265,425);
	circle(215,403,10);
	setfillstyle(1,4);
	floodfill(215,403,8);
}

void shield()
{
	setcolor(15);
	line(40,430,390,430);
}

void removebox(int i)
{
    randomize();
    if(i%2==0)
     message(random(6));
    music(1);
    setfillstyle(1,0);
    bar(b[i].x1,b[i].y1,b[i].x2,b[i].y2+1);
    b[i].yes=0;
	blockbroken++;
}


