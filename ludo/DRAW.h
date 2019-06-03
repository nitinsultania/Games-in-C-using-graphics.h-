void drawall();
void drawinsideludo();
void drawpice();
void about(int n);
void drawmark(mark *pice);
void drawdice(int n);
void drawbase(base *bs);
void drawnode(node *box);
void drawstar(int x,int y);
void drawbox(int x,int y,int col);


void about(int n)
 {
 int x1,y1;
 setfillstyle(1,0);
 bar(10,80,370,440);
 drawall();
 settextstyle(TRIPLEX_FONT,0,3);
 outtextxy(155,100,"ABOUT");
 settextstyle(DEFAULT_FONT,0,1);
 outtextxy(40,135,"LUDO IS A STRATEGY BOARD GAME FOR TWO");
 outtextxy(40,150,"TO FOUR PLAYERS,IN WHICH THE PLAYER");
 outtextxy(40,165,"RACE THEIR FOUR TOKENS FROM START TO");
 outtextxy(40,180,"FINISH ACCORDING TO ROLLS OF A SINGLE");
 outtextxy(40,195,"DIE. HOPE YOU ALL ENJOY THE GAME.");
 outtextxy(40,210,"THE GAME IS DESIGNED IN SIMPLE C");
 outtextxy(40,225,"LANGUAGE WITH SOME OF THE SYNTAX OF");
 outtextxy(40,240,"C++.");
 outtextxy(40,255,"DESIGNERS:-NITIN SULTANIA");
 outtextxy(40,270,"           RAM NAD");
 outtextxy(40,285,"           LAKHAN NAD");
 outtextxy(40,300,"AND SPECIAL THANKS TO MANORANJAN SIR");
 outtextxy(40,315,"FOR BEING THE PART OF THE PROJECT.");
 outtextxy(40,340,"              THANK YOU            ");
 rectangle(150,380,230,410);
 outtextxy(175,392,"BACK");
 jump:
 mouse();
 mouseclick(x1,y1);
 hidemouse();
 if(x1>150&&x1<230&&y1>230&&y1<410)
  {
 setfillstyle(1,0);
 bar(10,80,370,440);
 drawall();
 drawinsideludo();
 drawpice();
 drawdice(n);
  }
 else
  {goto jump;}
 }



void drawstar(int x, int y)
{
setcolor(0);
line(x-8,y-4,x,y+8);
line(x-8,y-4,x+8,y-4);
line(x+8,y-4,x,y+8);
line(x-8,y+4,x,y-8);
line(x,y-8,x+8,y+4);
line(x-8,y+4,x+8,y+4);
setfillstyle(1,0);
floodfill(x-6,y-2,0);
floodfill(x-6,y+2,0);
floodfill(x+6,y-2,0);
floodfill(x+6,y+2,0);
floodfill(x,y-6,0);
floodfill(x,y+6,0);
}


void drawbase(base *bs)
 {
 setfillstyle(1,bs->b_color);
 floodfill(bs->co_x,bs->co_y,7);
 }

void drawmark(mark *pice)
 {
	 int x=0,y=0;
	 if(pice->cur_name==0)
	 {
		x=(pice->bs_link)->co_x;
        y=(pice->bs_link)->co_y;		
	 }
	 else if(pice->cur_name==9000)
	 {
	 setfillstyle(1,pice->t_color);
	 floodfill(pice->h_x,pice->h_y,7);
	 }
	 else if((pice->cur_name>=1000 && pice->cur_name<=1012) || (pice->cur_name>=2000 && pice->cur_name<=2012) || (pice->cur_name>=3000 && pice->cur_name<=3012) || (pice->cur_name>=4000 && pice->cur_name<=4012) || (pice->cur_name>=5000 && pice->cur_name<=5004) || (pice->cur_name>=6000 && pice->cur_name<=6004) || (pice->cur_name>=7000 && pice->cur_name<=7004) || (pice->cur_name>=8000 && pice->cur_name<=8004))
	 {
		 x=( ((pice->cur_link)->x1) + ((pice->cur_link)->x2) )/2;
		 y=( ((pice->cur_link)->y1) + ((pice->cur_link)->y2) )/2;
	 }
 if(x!=0 && y!=0)
 {
 setcolor(8);
 circle(x,y,8);
 circle(x,y,4);
 setfillstyle(1,pice->t_color);
 floodfill(x+5,y+5,8);
 setfillstyle(1,15);
 floodfill(x,y,8);
 }
 }
 
void drawnode(node *box)
 {
 setfillstyle(1,box->col);
 bar(box->x1+1,box->y1+1,box->x2-1,box->y2-1);
 for(int i=0; i<8; i++)
 {
 if(box->name==stop[i])
 {
 drawstar((box->x1+box->x2)/2,(box->y1+box->y2)/2);
 }
 }
 }

void drawpice()
{
drawmark(blue_1);
drawmark(blue_2);
drawmark(blue_3);
drawmark(blue_4);
drawmark(red_1);
drawmark(red_2);
drawmark(red_3);
drawmark(red_4);
drawmark(green_1);
drawmark(green_2);
drawmark(green_3);
drawmark(green_4);
drawmark(yellow_1);
drawmark(yellow_2);
drawmark(yellow_3);
drawmark(yellow_4);
}
 
 
 void drawbox(int x,int y,int col)
 {
 setcolor(7);
 rectangle(x,y,x+125,y+125);//outer
  setfillstyle(1,col);
  floodfill(x+5,y+5,7);
 rectangle(x+15,y+15,x+110,y+110);//inner
  setfillstyle(1,15);
  floodfill(x+17,y+17,7);
 circle(x+40,y+40,12);
  setfillstyle(1,col);
  floodfill(x+40,y+40,7);
 circle(x+85,y+40,12);
  setfillstyle(1,col);
  floodfill(x+85,y+40,7);
 circle(x+40,y+85,12);
  setfillstyle(1,col);
  floodfill(x+40,y+85,7);
 circle(x+85,y+85,12);
  setfillstyle(1,col);
  floodfill(x+85,y+85,7);
 }
 
 
 
 void drawinsideludo()
 {
 int i,j;
 //home box

 rectangle(145,215,235,305);//home
  rectangle(150,220,230,300);
  line(150,220,230,300);
  line(230,220,150,300);
  setfillstyle(1,14);
  floodfill(153,222,7);
  setfillstyle(1,4);
  floodfill(200,290,7);
  setfillstyle(1,2);
  floodfill(160,270,7);
  setfillstyle(1,1);
  floodfill(220,270,7);
  setcolor(0);
  settextstyle(TRIPLEX_FONT,0,3);
  outtextxy(160,245,"HOME");
  setcolor(7);

 //smallsquares

 rectangle(145,85,235,215);//upper
  for(i=1;i<6;i++)
   line(145,85+(21*i),235,85+(21*i));
  for(i=1;i<3;i++)
   line(145+(30*i),85,145+(30*i),215);
  for(i=0;i<5;i++)
  {
   setfillstyle(1,14);
   floodfill(190,108+(22*i),7);
  }
  setfillstyle(1,14);
  floodfill(220,108,7);
  for(i=0;i<2;i++)
   for(j=1;j<7;j++)
    {
    if(i==1&&j==2)
    continue;
    setfillstyle(1,15);
    floodfill(160+(60*i),85+(20*j),7);
    }
  setfillstyle(1,15);
  floodfill(190,105,7);


 rectangle(15,215,145,305);//left
  for(i=1;i<6;i++)
   line(15+(21*i),215,15+(21*i),305);
  for(i=1;i<3;i++)
   line(15,215+(30*i),145,215+(30*i));
  for(i=1;i<6;i++)
  {
   setfillstyle(1,2);
   floodfill(15+(22*i),260,7);
  }
  setfillstyle(1,2);
  floodfill(37,230,7);
  for(i=0;i<2;i++)
   for(j=1;j<7;j++)
    {
    if(i==0&&j==2)
    continue;
    setfillstyle(1,15);
    floodfill(15+(20*j),230+(60*i),7);
    }
  setfillstyle(1,15);
  floodfill(35,260,7);


 rectangle(+235,215,365,305);//right
  for(i=1;i<6;i++)
   line(235+(21*i),215,235+(21*i),305);
  for(i=1;i<3;i++)
   line(235,215+(30*i),365,215+(30*i));
  for(i=1;i<6;i++)
  {
   setfillstyle(1,1);
   floodfill(235+(20*i),260,7);
  }
  setfillstyle(1,1);
  floodfill(335,290,7);
  for(i=0;i<2;i++)
   for(j=1;j<7;j++)
    {
    if(i==1&&j==5)
    continue;
    setfillstyle(1,15);
    floodfill(235+(20*j),230+(60*i),7);
    }
  setfillstyle(1,15);
  floodfill(355,260,7);


 rectangle(145,305,235,435);//bottom
  for(i=1;i<6;i++)
   line(145,305+(21*i),235,305+(21*i));
  for(i=1;i<3;i++)
   line(145+(30*i),305,145+(30*i),435);
  for(i=1;i<6;i++)
  {
   setfillstyle(1,4);
   floodfill(190,305+(20*i),7);
  }
  setfillstyle(1,4);
  floodfill(160,405,7);
  for(i=0;i<2;i++)
   for(j=1;j<7;j++)
    {
    if(i==0&&j==5)
    continue;
    setfillstyle(1,15);
    floodfill(160+(60*i),305+(20*j),7);
    }
  setfillstyle(1,15);
  floodfill(190,425,7);
  
 drawbox(240,310,1);//blue box
 drawbox(15,85,2);//green box
 drawbox(15,310,4);//red box
 drawbox(240,85,14);//yellow box
 
 drawstar(220,378);
  drawstar(329,290);
   drawstar(160,399);
    drawstar(67,290);
	 drawstar(46,230);
	  drawstar(160,137);
	   drawstar(220,116);
	    drawstar(308,230);

 }
 
 
 void drawdice(int n)
{
 setfillstyle(1,15);
 bar(465,235,545,315);
 switch(n)
  {
  case 1:setcolor(0);
	 circle(505,275,5);
	 setfillstyle(1,0);
	 floodfill(505,275,0);
	 break;
  case 2:setcolor(0);
	 circle(490,275,5);
	 circle(520,275,5);
	 setfillstyle(1,0);
	 floodfill(490,275,0);
	 floodfill(520,275,0);
	 break;
  case 3:setcolor(0);
	 circle(485,295,5);
	 circle(505,275,5);
	 circle(525,255,5);
	 setfillstyle(1,0);
	 floodfill(485,295,0);
	 floodfill(505,275,0);
	 floodfill(525,255,0);
	 break;
  case 4:setcolor(0);
	 circle(490,260,5);
	 circle(520,260,5);
	 circle(490,290,5);
	 circle(520,290,5);
	 setfillstyle(1,0);
	 floodfill(490,260,0);
	 floodfill(520,260,0);
	 floodfill(490,290,0);
	 floodfill(520,290,0);
	 break;
  case 5:setcolor(0);
	 circle(485,255,5);
	 circle(525,255,5);
	 circle(525,295,5);
	 circle(505,275,5);
	 circle(485,295,5);
	 setfillstyle(1,0);
	 floodfill(485,255,0);
	 floodfill(525,255,0);
	 floodfill(525,295,0);
	 floodfill(505,275,0);
	 floodfill(485,295,0);
	 break;
  case 6:setcolor(0);
	 circle(490,255,5);
	 circle(490,275,5);
	 circle(490,295,5);
	 circle(520,255,5);
	 circle(520,275,5);
	 circle(520,295,5);
	 setfillstyle(1,0);
	 floodfill(490,255,0);
	 floodfill(490,275,0);
	 floodfill(490,295,0);
	 floodfill(520,255,0);
	 floodfill(520,275,0);
	 floodfill(520,295,0);
	 break;
  }
}
 
void drawall()
 {
 setcolor(15);
 settextstyle(GOTHIC_FONT,0,6);
 outtextxy(90,10,"LETS PLAY LUDO");
 setcolor(7);

 //printingludo

 rectangle(10,80,370,440);//outer boundary ludo
 rectangle(15,85,365,435);//inner boundary ludo
  setfillstyle(1,0);
  floodfill(12,82,7);

 rectangle(390,80,620,440);//outer boundary rulebox
 rectangle(395,85,615,435);//inner boundary rulebox
 rectangle(400,90,610,130);//about box
  setfillstyle(1,15);
  floodfill(402,92,7);
  setcolor(0);
  settextstyle(TRIPLEX_FONT,0,3);
  outtextxy(467,95,"ABOUT");
  setcolor(7);
 rectangle(400,135,610,175);//exit box
  setfillstyle(1,15);
  floodfill(402,137,7);
  setcolor(0);
  settextstyle(TRIPLEX_FONT,0,3);
  outtextxy(430,140,"SAVE & EXIT");
  setcolor(7);
 rectangle(400,180,610,220);//throwdice box
  setfillstyle(1,15);
  floodfill(402,182,7);
  setcolor(0);
  settextstyle(TRIPLEX_FONT,0,3);
  outtextxy(435,185,"THROW DICE");
  setcolor(7);
 rectangle(400,225,610,430);//dice box
  rectangle(465,235,545,315);//dice
  setfillstyle(1,15);
  floodfill(467,247,7);
  setcolor(7);
  rectangle(410,235,430,315);
   setfillstyle(1,4);
   floodfill(412,237,7);
   setfillstyle(1,15);
   circle(420,245,5);
   floodfill(420,245,7);
   circle(420,265,5);
   floodfill(420,265,7);
   circle(420,285,5);
   floodfill(420,285,7);
   circle(420,305,5);
   floodfill(420,305,7);
  rectangle(435,235,455,315);
   setfillstyle(1,2);
   floodfill(437,237,7);
   setfillstyle(1,15);
   circle(445,245,5);
   floodfill(445,245,7);
   circle(445,265,5);
   floodfill(445,265,7);
   circle(445,285,5);
   floodfill(445,285,7);
   circle(445,305,5);
   floodfill(445,305,7);
  rectangle(555,235,575,315);
   setfillstyle(1,14);
   floodfill(557,237,7);
   setfillstyle(1,15);
   circle(565,245,5);
   floodfill(565,245,7);
   circle(565,265,5);
   floodfill(565,265,7);
   circle(565,285,5);
   floodfill(565,285,7);
   circle(565,305,5);
   floodfill(565,305,7);
  rectangle(580,235,600,315);
   setfillstyle(1,1);
   floodfill(582,237,7);
   setfillstyle(1,15);
   circle(590,245,5);
   floodfill(590,245,7);
   circle(590,265,5);
   floodfill(590,265,7);
   circle(590,285,5);
   floodfill(590,285,7);
   circle(590,305,5);
   floodfill(590,305,7);
  rectangle(405,320,605,425); 
 settextstyle(DEFAULT_FONT,0,1);
 outtextxy(240,460,"c ALL RIGHTS RESERVED");
 circle(243,463,6);

 }
 