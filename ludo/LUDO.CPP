/*
This Game Is Simple Game Of Ludo
It Is Four Player Game
And You Can Save Your Progress
It Is Made By
Lakhan, Nitin and Ram
*/
#include<fstream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include"SOURCE.H"
#include<process.h>
#include<stdlib.h>

int winner=0;
char chan; 

fstream save;
struct gamesave
{   
    int curname[16];
	char chance;
	int win[4];
	int nowinner;
};
gamesave gamedata={{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},'b',{0,0,0,0},0};
void loadgame()
{   
    chan=gamedata.chance;
    winner=gamedata.nowinner;
	blue->win=gamedata.win[0];
	red->win=gamedata.win[1];
	green->win=gamedata.win[2];
	yellow->win=gamedata.win[3];
	if(gamedata.curname[0]!=0)
	{
		blue_1->cur_name=gamedata.curname[0];
		blue_1->cur_link=search(gamedata.curname[0]);
		((blue_1->cur_link)->blue)++;
		(blue_1->bs_link)->m_pres=0;
	}
	if(gamedata.curname[1]!=0)
	{
		blue_2->cur_name=gamedata.curname[1];
		blue_2->cur_link=search(gamedata.curname[1]);
		((blue_2->cur_link)->blue)++;
		(blue_2->bs_link)->m_pres=0;
	}
	if(gamedata.curname[2]!=0)
	{
		blue_3->cur_name=gamedata.curname[2];
		blue_3->cur_link=search(gamedata.curname[2]);
		((blue_3->cur_link)->blue)++;
		(blue_3->bs_link)->m_pres=0;
	}
	if(gamedata.curname[3]!=0)
	{
		blue_4->cur_name=gamedata.curname[3];
		blue_4->cur_link=search(gamedata.curname[3]);
		((blue_4->cur_link)->blue)++;
		(blue_4->bs_link)->m_pres=0;
	}
	if(gamedata.curname[4]!=0)
	{
		red_1->cur_name=gamedata.curname[4];
		red_1->cur_link=search(gamedata.curname[4]);
		((red_1->cur_link)->red)++;
		(red_1->bs_link)->m_pres=0;
	}
	if(gamedata.curname[5]!=0)
	{
		red_2->cur_name=gamedata.curname[5];
		red_2->cur_link=search(gamedata.curname[5]);
		((red_2->cur_link)->red)++;
		(red_2->bs_link)->m_pres=0;
	}
	if(gamedata.curname[6]!=0)
	{
		red_3->cur_name=gamedata.curname[6];
		red_3->cur_link=search(gamedata.curname[6]);
		((red_3->cur_link)->red)++;
		(red_3->bs_link)->m_pres=0;
	}
	if(gamedata.curname[7]!=0)
	{
		red_4->cur_name=gamedata.curname[7];
		red_4->cur_link=search(gamedata.curname[7]);
		((red_4->cur_link)->red)++;
		(red_4->bs_link)->m_pres=0;
	}
	if(gamedata.curname[8]!=0)
	{
		green_1->cur_name=gamedata.curname[8];
		green_1->cur_link=search(gamedata.curname[8]);
		((green_1->cur_link)->green)++;
		(green_1->bs_link)->m_pres=0;
	}
	if(gamedata.curname[9]!=0)
	{
		green_2->cur_name=gamedata.curname[9];
		green_2->cur_link=search(gamedata.curname[9]);
		((green_2->cur_link)->green)++;
		(green_2->bs_link)->m_pres=0;
	}
	if(gamedata.curname[10]!=0)
	{
		green_3->cur_name=gamedata.curname[10];
		green_3->cur_link=search(gamedata.curname[10]);
		((green_3->cur_link)->green)++;
		(green_3->bs_link)->m_pres=0;
	}
	if(gamedata.curname[11]!=0)
	{
		green_4->cur_name=gamedata.curname[11];
		green_4->cur_link=search(gamedata.curname[11]);
		((green_4->cur_link)->green)++;
		(green_4->bs_link)->m_pres=0;
	}
	if(gamedata.curname[12]!=0)
	{
		yellow_1->cur_name=gamedata.curname[12];
		yellow_1->cur_link=search(gamedata.curname[12]);
		((yellow_1->cur_link)->yellow)++;
		(yellow_1->bs_link)->m_pres=0;
	}
	if(gamedata.curname[12]!=0)
	{
		yellow_2->cur_name=gamedata.curname[13];
		yellow_2->cur_link=search(gamedata.curname[13]);
		((yellow_2->cur_link)->yellow)++;
		(yellow_2->bs_link)->m_pres=0;
	}
	if(gamedata.curname[12]!=0)
	{
		yellow_3->cur_name=gamedata.curname[14];
		yellow_3->cur_link=search(gamedata.curname[14]);
		((yellow_3->cur_link)->yellow)++;
		(yellow_3->bs_link)->m_pres=0;
	}
	if(gamedata.curname[15]!=0)
	{
		yellow_4->cur_name=gamedata.curname[15];
		yellow_4->cur_link=search(gamedata.curname[15]);
		((yellow_4->cur_link)->yellow)++;
		(yellow_4->bs_link)->m_pres=0;
	}
}

void mouse();
void hidemouse();
void mouseclick(int &x,int &y);
void exit();
int throwdice();
void detectoptions(int x,int y);
void playchance(player *col);
void getpiceclick(player *col, int n);
void movepice(mark *pice,int n);
int seepice(mark *pice,int n);
void cutpice(node *ptr,player *col);
#include"DRAW.H"


void cutpice(node *ptr, player *col)
{
int c=0;
for(int i=0; i<8; i++)
 {
 if(ptr->name==stop[i])
 {
 return;
 }
 }
if(ptr==home)
{
	return;
}	
if(col==blue)
{}
else
{
for(;ptr->blue>0;ptr->blue--)
{
c=1;
if((blue_1->cur_link)==ptr)
{
blue_1->cur_link=NULL;
blue_1->cur_name=0;
blue_1->bs_link->m_pres=1;
drawmark(blue_1);
}
else if((blue_2->cur_link)==ptr)
{
blue_2->cur_link=NULL;
blue_2->cur_name=0;
blue_2->bs_link->m_pres=1;
drawmark(blue_2);
}
else if((blue_3->cur_link)==ptr)
{
blue_3->cur_link=NULL;
blue_3->cur_name=0;
blue_3->bs_link->m_pres=1;
drawmark(blue_3);
}
else if((blue_4->cur_link)==ptr)
{
blue_4->cur_link=NULL;
blue_4->cur_name=0;
blue_4->bs_link->m_pres=1;
drawmark(blue_4);
}
}
}
if(col==red)
{}
else
{
for(;ptr->red>0;ptr->red--)
{
c=1;
if((red_1->cur_link)==ptr)
{
red_1->cur_link=NULL;
red_1->cur_name=0;
red_1->bs_link->m_pres=1;
drawmark(red_1);
}
else if((red_2->cur_link)==ptr)
{
red_2->cur_link=NULL;
red_2->cur_name=0;
red_2->bs_link->m_pres=1;
drawmark(red_2);
}
else if((red_3->cur_link)==ptr)
{
red_3->cur_link=NULL;
red_3->cur_name=0;
red_3->bs_link->m_pres=1;
drawmark(red_3);
}
else if((red_4->cur_link)==ptr)
{
red_4->cur_link=NULL;
red_4->cur_name=0;
red_4->bs_link->m_pres=1;
drawmark(red_4);
}
}
}
if(col==green)
{}
else
{
for(;ptr->green>0;ptr->green--)
{
c=1;
if((green_1->cur_link)==ptr)
{
green_1->cur_link=NULL;
green_1->cur_name=0;
green_1->bs_link->m_pres=1;
drawmark(green_1);
}
else if((green_2->cur_link)==ptr)
{
green_2->cur_link=NULL;
green_2->cur_name=0;
green_2->bs_link->m_pres=1;
drawmark(green_2);
}
else if((green_3->cur_link)==ptr)
{
green_3->cur_link=NULL;
green_3->cur_name=0;
green_3->bs_link->m_pres=1;
drawmark(green_3);
}
else if((green_4->cur_link)==ptr)
{
green_4->cur_link=NULL;
green_4->cur_name=0;
green_4->bs_link->m_pres=1;
drawmark(green_4);
}
}
}
if(col==yellow)
{}
else
{
for(;ptr->yellow>0;ptr->yellow--)
{
c=1;
if((yellow_1->cur_link)==ptr)
{
yellow_1->cur_link=NULL;
yellow_1->cur_name=0;
yellow_1->bs_link->m_pres=1;
drawmark(yellow_1);
}
else if((yellow_2->cur_link)==ptr)
{
yellow_2->cur_link=NULL;
yellow_2->cur_name=0;
yellow_2->bs_link->m_pres=1;
drawmark(yellow_2);
}
else if((yellow_3->cur_link)==ptr)
{
yellow_3->cur_link=NULL;
yellow_3->cur_name=0;
yellow_3->bs_link->m_pres=1;
drawmark(yellow_3);
}
else if((yellow_4->cur_link)==ptr)
{
yellow_4->cur_link=NULL;
yellow_4->cur_name=0;
yellow_4->bs_link->m_pres=1;
drawmark(yellow_4);
}
}
}
if(c==1)
{
		setfillstyle(1,0);
        bar(410,355,600,420);
        setcolor(15);
        settextstyle(SANS_SERIF_FONT,0,1);
    switch(col->col)
    {
    case 1: outtextxy(415,330,"Blue's Pice Has");
            break; 
    case 2: outtextxy(415,330,"Green's Pice Has");
            break;
    case 4: outtextxy(415,330,"Red's Pice Has");
            break;
    case 14:outtextxy(415,330,"Yellow's Pice Has");
            break;
    }	 
        outtextxy(415,380,"Cut Other Pices");
        delay(1500);
		setfillstyle(1,0);
        bar(410,355,600,420);
playchance(col);
}
}


void movepice(mark *pice,int n)
{
switch(pice->t_color)
{
case 1: if(pice->cur_name==0)
        {
		pice->cur_name=1000;
		pice->cur_link=bhome;
		drawbase(pice->bs_link);
		(pice->bs_link)->m_pres=0;
		drawnode(bhome);
		(bhome->blue)++;
		drawpice();
		drawmark(pice);
		}
		else
		{
		node *ptr=pice->cur_link;
		for(int i=0; i<n; i++)
        {
        pice->cur_name=(ptr->blink)->name;
        pice->cur_link=(ptr->blink);
		((ptr->blink)->blue)++;
		(ptr->blue)--;
        drawmark(pice); 
        drawnode(ptr);
		drawpice();
		drawmark(pice);
		delay(150);
        ptr=ptr->blink;
        }
		if(ptr==home)
		{
		blue->win++;
		setfillstyle(1,0);
        bar(410,355,600,420);
        setcolor(15);
        settextstyle(SANS_SERIF_FONT,0,1);
        outtextxy(415,355,"Blue's Pice"); 
        outtextxy(415,380,"Has Reached Home");
        delay(1500);
		setfillstyle(1,0);
        bar(410,355,600,420);
		playchance(blue);
		}
		cutpice(ptr,blue);
		}
        break;
case 4: if(pice->cur_name==0)
        {
		pice->cur_name=2000;
		pice->cur_link=rhome;
		drawbase(pice->bs_link);
		(pice->bs_link)->m_pres=0;
		drawnode(rhome);
		(rhome->red)++;
		drawpice();
		drawmark(pice);
		}
		else
		{
		node *ptr=pice->cur_link;
		for(int i=0; i<n; i++)
        {
        pice->cur_name=(ptr->rlink)->name;
        pice->cur_link=(ptr->rlink);
		((ptr->rlink)->red)++;
		(ptr->red)--;
        drawmark(pice); 
        drawnode(ptr);
		drawpice();
	    drawmark(pice);
		delay(150);
        ptr=ptr->rlink;
        }
		if(ptr==home)
		{
		red->win++;
		setfillstyle(1,0);
        bar(410,355,600,420);
        setcolor(15);
        settextstyle(SANS_SERIF_FONT,0,1);
        outtextxy(415,355,"Red's Pice"); 
        outtextxy(415,380,"Has Reached Home");
        delay(1500);
		setfillstyle(1,0);
        bar(410,355,600,420);
		playchance(red);
		}
        cutpice(ptr,red);
		}
        break;
case 2: if(pice->cur_name==0)
        {
		pice->cur_name=3000;
		pice->cur_link=ghome;
		drawbase(pice->bs_link);
		(pice->bs_link)->m_pres=0;
		drawnode(ghome);
		(ghome->green)++;
		drawpice();
		drawmark(pice);
		}
		else
		{
		node *ptr=pice->cur_link;
		for(int i=0; i<n; i++)
        {
        pice->cur_name=(ptr->glink)->name;
        pice->cur_link=(ptr->glink);
		((ptr->glink)->green)++;
		(ptr->green)--;
        drawmark(pice); 
        drawnode(ptr);
		drawpice();
		drawmark(pice);
		delay(150);
        ptr=ptr->glink;
        }
		if(ptr==home)
		{
		green->win++;
		setfillstyle(1,0);
        bar(410,355,600,420);
        setcolor(15);
        settextstyle(SANS_SERIF_FONT,0,1);
        outtextxy(415,355,"Green's Pice"); 
        outtextxy(415,380,"Has Reached Home");
        delay(1500);
		setfillstyle(1,0);
        bar(410,355,600,420);
		playchance(green);
		}
		cutpice(ptr,green);
		}
        break;
case 14:if(pice->cur_name==0)
        {
		pice->cur_name=4000;
		pice->cur_link=yhome;
		drawbase(pice->bs_link);
		(pice->bs_link)->m_pres=0;
		drawnode(yhome);
		(yhome->yellow)++;
		drawpice();
		drawmark(pice);
		}
		else
		{
		node *ptr=pice->cur_link;
		for(int i=0; i<n; i++)
        {
        pice->cur_name=(ptr->ylink)->name;
        pice->cur_link=(ptr->ylink);
		((ptr->ylink)->yellow)++;
		(ptr->yellow)--;
        drawmark(pice); 
        drawnode(ptr);
		drawpice();
		drawmark(pice);		
		delay(150);
        ptr=ptr->ylink;
        }
		if(ptr==home)
		{
		yellow->win++;
		setfillstyle(1,0);
        bar(410,355,600,420);
        setcolor(15);
        settextstyle(SANS_SERIF_FONT,0,1);
        outtextxy(415,355,"Yellow's Pice"); 
        outtextxy(415,380,"Has Reached Home");
        delay(1500);
		setfillstyle(1,0);
        bar(410,355,600,420);
		playchance(yellow);
		}
		cutpice(ptr,yellow);
		}
        break;
}
}

int seepice(mark *pice, int n)
{
if(pice->cur_name==0)
{
if(n!=6)
return 0;
}
else
{
node *ptr=pice->cur_link;
for(int i=0; i<n; i++)
{
switch(pice->t_color)
{
case 1: ptr=ptr->blink;
        break;
case 2: ptr=ptr->glink;
        break;
case 4: ptr=ptr->rlink;
        break;
case 14:ptr=ptr->ylink;
        break;
}
if(ptr==NULL)
return 0;
}
}
return 1;
}


void getpiceclick(player *col, int n)
{
int x,y;
start:
setfillstyle(1,0);
bar(410,355,600,420);
setcolor(15);
settextstyle(SANS_SERIF_FONT,0,1);
outtextxy(415,355,"Select a Pice");
delay(500);
mouse();
mouseclick(x,y);
hidemouse();
if((((((col->m1)->cur_link!=NULL)||((col->m1)->cur_link!=home))&&x>((col->m1)->cur_link)->x1&&x<((col->m1)->cur_link)->x2&&y>((col->m1)->cur_link)->y1&&y<((col->m1)->cur_link)->y2) || ((col->m1)->cur_name==0&&x>((col->m1)->bs_link)->co_x-8&&x<((col->m1)->bs_link)->co_x+8&&y>((col->m1)->bs_link)->co_y-8&&y<((col->m1)->bs_link)->co_y+8)) && (seepice(col->m1,n)==1))
{
movepice(col->m1,n);
}
else if((((((col->m2)->cur_link!=NULL)||((col->m2)->cur_link!=home))&&x>((col->m2)->cur_link)->x1&&x<((col->m2)->cur_link)->x2&&y>((col->m2)->cur_link)->y1&&y<((col->m2)->cur_link)->y2) || ((col->m2)->cur_name==0&&x>((col->m2)->bs_link)->co_x-8&&x<((col->m2)->bs_link)->co_x+8&&y>((col->m2)->bs_link)->co_y-8&&y<((col->m2)->bs_link)->co_y+8)) && (seepice(col->m2,n)==1))
{
movepice(col->m2,n);
}
else if((((((col->m3)->cur_link!=NULL)||((col->m3)->cur_link!=home))&&x>((col->m3)->cur_link)->x1&&x<((col->m3)->cur_link)->x2&&y>((col->m3)->cur_link)->y1&&y<((col->m3)->cur_link)->y2) || ((col->m3)->cur_name==0&&x>((col->m3)->bs_link)->co_x-8&&x<((col->m3)->bs_link)->co_x+8&&y>((col->m3)->bs_link)->co_y-8&&y<((col->m3)->bs_link)->co_y+8)) && (seepice(col->m3,n)==1))
{
movepice(col->m3,n);
}
else if((((((col->m4)->cur_link!=NULL)||((col->m4)->cur_link!=home))&&x>((col->m4)->cur_link)->x1&&x<((col->m4)->cur_link)->x2&&y>((col->m4)->cur_link)->y1&&y<((col->m4)->cur_link)->y2) || ((col->m4)->cur_name==0&&x>((col->m4)->bs_link)->co_x-8&&x<((col->m4)->bs_link)->co_x+8&&y>((col->m4)->bs_link)->co_y-8&&y<((col->m4)->bs_link)->co_y+8)) && (seepice(col->m4,n)==1))
{
movepice(col->m4,n);
}
else
{
setfillstyle(1,0);
bar(410,355,600,420);
setcolor(15);
settextstyle(SANS_SERIF_FONT,0,1);
outtextxy(415,355,"Select a Valid"); 
outtextxy(415,380,"Movable Pice");
delay(1500);
goto start;
}
}

//mouse functions
union REGS in,out;
//working with mouse

void mouse()
 {
 in.x.ax=1;
 int86(51,&in,&out);
 in.x.ax=4;
 in.x.cx=590;
 in.x.dx=400;
 int86(51,&in,&out); 
 in.x.ax=7;
 in.x.cx=10;
 in.x.dx=615;
 int86(51,&in,&out);
 in.x.ax=8;
 in.x.cx=80;
 in.x.dx=435;
 int86(51,&in,&out);
 }
 
void hidemouse()
 {
 in.x.ax=1;
 int86(51,&in,&out);
 in.x.ax=2;
 int86(51,&in,&out);
 }
 
void mouseclick(int &x1,int &y1)
 {
 int n=0;
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
  delay(100);
  if(x1>400&&x1<610&&y1>90&&y1<175)
  {
  hidemouse();
  detectoptions(x1,y1);
  }
  else
  {
    return;
  }
  }
  }  
 }


void exit()
 {
 if(winner<3)
 {
 gamedata.chance=chan;
 gamedata.nowinner=winner;
 gamedata.win[0]=blue->win;
 gamedata.win[1]=red->win;
 gamedata.win[2]=green->win;
 gamedata.win[3]=yellow->win;
 gamedata.curname[0]=blue_1->cur_name;
 gamedata.curname[1]=blue_2->cur_name;                       
 gamedata.curname[2]=blue_3->cur_name;
 gamedata.curname[3]=blue_4->cur_name;
 gamedata.curname[4]=red_1->cur_name;
 gamedata.curname[5]=red_2->cur_name;
 gamedata.curname[6]=red_3->cur_name;
 gamedata.curname[7]=red_4->cur_name;
 gamedata.curname[8]=green_1->cur_name;
 gamedata.curname[9]=green_2->cur_name;
 gamedata.curname[10]=green_3->cur_name;
 gamedata.curname[11]=green_4->cur_name;
 gamedata.curname[12]=yellow_1->cur_name;
 gamedata.curname[13]=yellow_2->cur_name;
 gamedata.curname[14]=yellow_3->cur_name;
 gamedata.curname[15]=yellow_4->cur_name;
 save.open("ludosave.dat",ios::binary|ios::out);
 save.seekg(0,ios::beg);
 save.write((char *)&gamedata,sizeof(gamedata));
 save.clear();
 save.close();
 }
 else
 {
  gamedata.curname[0]=0;
  gamedata.curname[1]=0;
  gamedata.curname[2]=0;
  gamedata.curname[3]=0;
  gamedata.curname[4]=0;
  gamedata.curname[5]=0;
  gamedata.curname[6]=0;
  gamedata.curname[7]=0;
  gamedata.curname[8]=0;
  gamedata.curname[9]=0;
  gamedata.curname[10]=0;
  gamedata.curname[11]=0;
  gamedata.curname[12]=0;
  gamedata.curname[13]=0;
  gamedata.curname[14]=0;
  gamedata.curname[15]=0;
  gamedata.chance='b';
  gamedata.win[0]=0;
  gamedata.win[1]=0;
  gamedata.win[2]=0;
  gamedata.win[3]=0;
  gamedata.nowinner=0;
  save.open("ludosave.dat",ios::binary|ios::out);
  save.seekg(0,ios::beg);
  save.write((char *)&gamedata,sizeof(gamedata));
  save.clear();
  save.close();
 }
 deletenode();
 deleteoth();
 exit (0);
 }


int no_dice[6]={0,0,0,0,0,0};
int n=6;
int throwdice()
 {
 int i,j;
 int y=0;
 randomize();
 for(i=0;i<5;i++)
 {
  n=random(6)+1;
  drawdice(n);
  delay(350);
 }
 for(j=5; j>=0; j--)
 {
  if(no_dice[j]>=14)
  {
  y=1;
  n=j+1;
  no_dice[n-1]=-1;
  drawdice(n);
  j=-1;
  }
 }

 if(y==0)
  {
  n= random(6)+1;
  drawdice(n);
  no_dice[n-1]=-1;
  }
 for(j=0; j<6; j++)
 (no_dice[j])++;
 
 return n;//return dice output;
 }

 
 void detectoptions(int x1,int y1)
 {
 if(x1>400&&x1<610&&y1>90&&y1<130)
  about(n);
  if(x1>400&&x1<610&&y1>135&&y1<175)
  exit();
 }
 
 
 
 void playchance(player *col)
  { 
    start:
	setfillstyle(1,0);
	bar(410,325,600,420);
	setcolor(15);
    settextstyle(SANS_SERIF_FONT,0,1);
    switch(col->col)
    {
    case 1: outtextxy(415,330,"Blue's Chance");chan='b';
            break; 
    case 2: outtextxy(415,330,"Green's Chance");chan='g';
            break;
    case 4: outtextxy(415,330,"Red's Chance");chan='r';
            break;
    case 14:outtextxy(415,330,"Yellow's Chance");chan='y';
            break;
    }	
    int x=0,y=0,n;
	mouse();
    mouseclick(x,y);
	hidemouse();
	if(x>400&&x<610&&y>180&&y<220)
	{
	n=throwdice();
	}
	else
	{
	goto start;
	}
	if(seepice(col->m1,n)==0&&seepice(col->m2,n)==0&&seepice(col->m3,n)==0&&seepice(col->m4,n)==0)
	{
	setcolor(15);
	settextstyle(SANS_SERIF_FONT,0,1);
    outtextxy(415,355,"You Cannot Move"); 
	outtextxy(415,380,"Any Pice");
    delay(2000);
	setfillstyle(1,0);
	bar(410,355,600,420);
	}
	else
	{
	getpiceclick(col,n);
	if(n==6)
	{
	playchance(col);
	}
	}
	setfillstyle(1,0);
	bar(410,325,600,420);
  }


void wingame(player *col)
{   
    winner++;
    int x=0, y=0;
    setfillstyle(1,0);
	bar(410,325,600,420);
	setcolor(15);
    settextstyle(SANS_SERIF_FONT,0,1);
	if(col==blue)
	outtextxy(415,330,"Blue Has Won");
	else if(col==red)
	outtextxy(415,330,"Red Has Won");
	else if(col==green)
	outtextxy(415,330,"Green Has Won");
	else if(col==yellow)
	outtextxy(415,330,"Yellow Has Won");
	delay(2000);
    if(winner<3)
	{
    settextstyle(SANS_SERIF_FONT,0,1);
    outtextxy(415,355,"Want To Continue");
    rectangle(415,380,500,415);
	outtextxy(445,385,"YES");
	rectangle(505,380,565,415);
	outtextxy(525,385,"NO");
	reask:
	mouse();
    mouseclick(x,y);
	hidemouse();
	if(x>415&&x<500&&y>380&&y<415)
	{
	setfillstyle(1,0);
	bar(410,325,600,420);
	delay(1000);
	}
	else if(x>505&&x<565&&y>380&&y<415)
	{
	setfillstyle(1,0);
	bar(410,325,600,420);
	outtextxy(415,330,"Thank YOU");
	outtextxy(415,355,"Hope You Enjoyed");
	delay(2000);
	exit();
	}
	else
	{
	goto reask;
	}
	}
	else
	{
	setfillstyle(1,0);
	bar(410,325,600,420);
	outtextxy(415,330,"Thank YOU");
	outtextxy(415,355,"Hope You Enjoyed");
	delay(2000);
	exit();
	}
}

void main()
 {
 clrscr();
 int gdriver=DETECT,gmode;
 initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
 nodecreate();
 createoth();
  settextstyle(TRIPLEX_FONT,0,5);
  outtextxy(135,40,"WELCOME TO LUDO");
  settextstyle(SANS_SERIF_FONT,0,1);
  outtextxy(155,110,"ITS A BOARD GAME OF FOUR PLAYERS");
  outtextxy(157,130,"IN WHICH TOKENS ARE MOVED ROUND ");
  outtextxy(260,150,"THE BOARD.");
  outtextxy(155,170,"FIRST CHANCE IS FOR BLUE, SECOND");
  outtextxy(153,190,"FOR RED, THIRD FOR GREEN AND LAST");
  outtextxy(257,210,"FOR YELLOW.");
  outtextxy(155,230,"PRESS THROWDICE TO ROLL THE DICE");
  outtextxy(139,250,"YOU CAN EXIT ANYTIME BY PRESSING EXIT.");
  outtextxy(190,270,"HOPE YOU ENJOY THE GAME.");
 //mousework
 in.x.ax=1;
 int86(51,&in,&out);
 in.x.ax=4;
 in.x.cx=300;
 in.x.dx=250;
 int86(51,&in,&out); 
 in.x.ax=7;
 in.x.cx=100;
 in.x.dx=500;
 int86(51,&in,&out);
 in.x.ax=8;
 in.x.cx=100;
 in.x.dx=400;
 int86(51,&in,&out);
    settextstyle(SANS_SERIF_FONT,0,1);
    rectangle(150,310,280,350);
	outtextxy(160,315,"New Game");
	rectangle(320,310,450,350);
	outtextxy(330,315,"Load Game");
 int mn=0,x=0,y=0;
 while(mn==0)
  {
  in.x.ax=3;
  int86(51,&in,&out);
  mn=out.x.bx;
  x=out.x.cx;
  y=out.x.dx;
  delay(100);
  if(mn==1)
 {
	 if(x>320&&x<450&&y>310&&y<350)
	 {   
    save.open("ludosave.dat",ios::binary|ios::in);
    save.seekg(0,ios::beg);
    save.read((char *)&gamedata,sizeof(gamedata));
	save.clear();
    save.close();
	 }
     else if(x>150&&x<280&&y>310&&y<350)
	 {}
    else{mn=0;}
 }
  }
 in.x.ax=1;
 int86(51,&in,&out);
 in.x.ax=2;
 int86(51,&in,&out);
 //end of function
 delay(1000);
 cleardevice();
 loadgame();
 drawall();
 drawinsideludo();
 drawpice();
 drawdice(6);
	setfillstyle(1,0);
	bar(410,325,600,420);
	setcolor(15);
	settextstyle(SANS_SERIF_FONT,0,1);
	outtextxy(415,330,"Game Starts");
	outtextxy(415,355,"Best Of Luck");
	delay(3000);
	setfillstyle(1,0);
	bar(410,325,600,420);
switch(chan)
{
	case 'b':goto bluestart;
	case 'r':goto redstart;
	case 'g':goto greenstart;
	case 'y':goto yellowstart;
}
 while(winner<3)
   {
 bluestart:
 if((blue->win)<4)
 {
 playchance(blue);
 delay(1000);
 if((blue->win)==4)
 wingame(blue);
 }
 redstart:
 if((red->win)<4)
 {
 playchance(red);
 delay(1000);
 if((red->win)==4)
 wingame(red);
 }
 greenstart:
 if((green->win)<4)
 {
 playchance(green);
 delay(1000);
 if((green->win)==4)
 wingame(green);
 }
 yellowstart:
 if((yellow->win)<4)
 {
 playchance(yellow);
 delay(1000);
 if((yellow->win)==4)
 wingame(yellow);
 }
   }
   deletenode();
   deleteoth();
 }