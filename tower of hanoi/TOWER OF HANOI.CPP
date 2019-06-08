/*
This Program Shows Solution
To Problem Called Tower Of Hanoi
For Only Upto 10 Plates
Problem Require Minimum 2^N - 1 Moves
Solution Is Based On A Recursive Algorithm
Move N-1 Plates From Starting Stand To Temporary Stand
Move Nth Plate From Start To Final Stand
Move N-1 Plates From Temporary Stand To Final Stand
It Is Made By
Lakhan, Nitin and Ram
*/
#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>

int m;
int chance=0;
int col[10]={11,13,12,10,3,9,2,1,6,4};

struct peg
 {
 int a[10];
 int n;
 peg()
  {
  n=0;
  }
 };

void draw()
 {
 char a[5];
 itoa(chance,a,10);
 setcolor(14);
 settextstyle(TRIPLEX_FONT,0,2);
 outtextxy(260,20,"MOVES - ");
 outtextxy(360,20,a);
 rectangle(3,3,613,363);
 rectangle(5,5,611,361);
 line(102,50,102,350);
 line(112,50,112,350);
 line(302,50,302,350);
 line(312,50,312,350);
 line(502,50,502,350);
 line(512,50,512,350);
 line(102,50,112,50);
 line(302,50,312,50);
 line(502,50,512,50);
 line(5,350,610,350);
 line(5,360,610,360);
 line(5,350,5,360);
 line(610,350,610,360);
 setfillstyle(1,14);
 bar(102,50,112,350);
 bar(302,50,312,350);
 bar(502,50,512,350);
 bar(5,350,610,360);
 setcolor(14);
 settextstyle(GOTHIC_FONT,0,6);
 outtextxy(60,370,"TOWER OF HANOI");
 settextstyle(TRIPLEX_FONT,0,1);
 outtextxy(170,430,"MADE BY NITIN,RAM,LAKHAN");
 settextstyle(DEFAULT_FONT,0,1);
 outtextxy(240,460,"c ALL RIGHTS RESERVED");
 circle(243,463,6);
 }

void drawdisc(int a[10],int p,int n)
 {
 if(p==1)
  p=107;
 if(p==2)
  p=307;
 if(p==3)
  p=507;
 for(int i=0;i<n;i++)
  {
  line(p-(10*a[i]),350-(i+1)*10,p+(10*a[i]),350-(i+1)*10);
  line(p-(10*a[i]),350-(i+1)*10,p-(10*a[i]),350-i*10);
  line(p+(10*a[i]),350-(i+1)*10,p+(10*a[i]),350-i*10);
  setfillstyle(1,col[a[i]-1]);
  bar(p-(10*a[i]),350-(i+1)*10,p+(10*a[i]),350-i*10);
  }
 }

peg p1,p2,p3;

void intialize(peg &k,peg &m,int n)
 {
 m.a[m.n]=n;
 m.n++;
 k.n--;
 }

void change(int n,int a,int c)
 {
 cleardevice();
 if(a==1&&c==2)
  intialize(p1,p2,n);
 if(a==1&&c==3)
  intialize(p1,p3,n);
 if(a==2&&c==3)
  intialize(p2,p3,n);
 if(a==2&&c==1)
  intialize(p2,p1,n);
 if(a==3&&c==1)
  intialize(p3,p1,n);
 if(a==3&&c==2)
  intialize(p3,p2,n);
 chance++;
 draw();
 drawdisc(p1.a,1,p1.n);
 drawdisc(p2.a,2,p2.n);
 drawdisc(p3.a,3,p3.n);
 delay(1100-100*m);
 }

void hanoi(int n,int a,int b,int c)
 {
 if(n==0)
  return;
 hanoi(n-1,a,c,b);
 change(n,a,c);
 hanoi(n-1,b,a,c);
 }

void main()
 {
 clrscr();
 int gdriver=DETECT,gmode;
 initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
 int p=1;
 settextstyle(TRIPLEX_FONT,0,2);
 cout<<"HELLO FRIENDS"<<endl;
 cout<<"THIS A SHORT GAME NAMED AS TOWER OF HANOI"<<endl;
 cout<<"ABOUT THE GAME:"<<endl;
 cout<<"TOWER OF HANOI:MOVE ALL THE DISKS FROM THE LEFTMOST ROD TO"<<endl;
 cout<<"THE RIGHTMOST ROD.ONLY ONE DISK MAY BE MOVED AT A TIME AND"<<endl;
 cout<<"IT IS NOT POSSIBLE TO PLACE A BIGGER DISK ON TOP OF A "<<endl;
 cout<<"SMALLER DISK."<<endl;
 cout<<"THE ORIGINAL LA TOUR D'HANOI PUZZLE WAS INVENTED BY "<<endl;
 cout<<"FRANCOIS EDOUARD ANATOLE LUCAS IN 1883."<<endl;
jump:cout<<"ENTER THE NUMBER OF DISC YOU WANT TO SEE THE SOLUTION"<<endl;

 cin>>m;
 if(m>10 && m<1)
  {
  cout<<"FOR CONVINENCE ENTER THE NO BELOW 10 AND ABOVE 0"<<endl;
  goto jump;
  }

 cleardevice();
 p1.n=m;
 for(int i=m;i>0;i--)
  p1.a[m-i]=i;
 draw();
 drawdisc(p1.a,p,m);
 sleep(1);
 hanoi(m,1,2,3);
 getch();
 }
