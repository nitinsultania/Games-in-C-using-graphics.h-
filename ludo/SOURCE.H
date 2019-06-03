struct node
{
int blue;
int red;
int yellow;
int green;
int col;
int name;
node *blink;
node *rlink;
node *ylink;
node *glink;
int x1;
int y1;
int x2;
int y2;
};

void initialize(node *ptr)
{
ptr->blue=0;
ptr->red=0;
ptr->yellow=0;
ptr->green=0;
}

void addlink(node *ptr, node *add)
{
ptr->blink=add;
ptr->glink=add;
ptr->rlink=add;
ptr->ylink=add;
}

int i;
node *home;
node *p[4];
node *bhome;
node *rhome;
node *yhome;
node *ghome;
node *pre;
node *ptr;

void nodecreate()
{
//home node creation
home=new node;
home->blink=NULL;
home->rlink=NULL;
home->glink=NULL;
home->ylink=NULL;
//end of home node creation

// general node creation starts
ptr= new node;
initialize(ptr);
p[0]=ptr;
pre=ptr;
ptr= new node;
initialize(ptr);
addlink(pre,ptr);
pre=ptr;
ptr= new node;
initialize(ptr);
bhome=ptr;
addlink(pre,ptr);
pre=ptr;
for(i=0; i<11; i++)
{
ptr= new node;
initialize(ptr);
addlink(pre,ptr);
pre=ptr;
}
p[1]=ptr;
ptr= new node;
initialize(ptr);
addlink(pre,ptr);
pre=ptr;
ptr= new node;
initialize(ptr);
rhome=ptr;
addlink(pre,ptr);
pre=ptr;
for(i=0; i<11; i++)
{
ptr= new node;
initialize(ptr);
addlink(pre,ptr);
pre=ptr;
}
p[2]=ptr;
ptr= new node;
initialize(ptr);
addlink(pre,ptr);
pre=ptr;
ptr= new node;
initialize(ptr);
ghome=ptr;
addlink(pre,ptr);
pre=ptr;
for(i=0; i<11; i++)
{
ptr= new node;
initialize(ptr);
addlink(pre,ptr);
pre=ptr;
}
p[3]=ptr;
ptr= new node;
initialize(ptr);
addlink(pre,ptr);
pre=ptr;
ptr= new node;
initialize(ptr);
yhome=ptr;
addlink(pre,ptr);
pre=ptr;
for(i=0; i<10; i++)
{
ptr= new node;
initialize(ptr);
addlink(pre,ptr);
pre=ptr;
}
addlink(pre,p[0]);
//end of general node creation
//blue home node creation
pre=p[0];
ptr=new node;
initialize(ptr);
pre->blink=ptr;
pre=ptr;
for(i=0; i<4; i++)
{
ptr=new node;
initialize(ptr);
addlink(pre,NULL);
pre->blink=ptr;
pre=ptr;
}
addlink(pre,NULL);
pre->blink=home;
//red home node creation
pre=p[1];
ptr=new node;
initialize(ptr);
pre->rlink=ptr;
pre=ptr;
for(i=0; i<4; i++)
{
ptr=new node;
initialize(ptr);
addlink(pre,NULL);
pre->rlink=ptr;
pre=ptr;
}
addlink(pre,NULL);
pre->rlink=home;
//green home node creation
pre=p[2];
ptr=new node;
initialize(ptr);
pre->glink=ptr;
pre=ptr;
for(i=0; i<4; i++)
{
ptr=new node;
initialize(ptr);
addlink(pre,NULL);
pre->glink=ptr;
pre=ptr;
}
addlink(pre,NULL);
pre->glink=home;
// yellow home node creation
pre=p[3];
ptr=new node;
initialize(ptr);
pre->ylink=ptr;
pre=ptr;
for(i=0; i<4; i++)
{
ptr=new node;
initialize(ptr);
addlink(pre,NULL);
pre->ylink=ptr;
pre=ptr;
}
addlink(pre,NULL);
pre->ylink=home;
// end of all node creations




//coordinate assigning starts
//blue path coordinates
ptr=bhome;
ptr->col=1; ptr->name=1000;
ptr->x1=319;
ptr->y1=275;
ptr->x2=340;
ptr->y2=305;
ptr=ptr->blink;
ptr->col=15; ptr->name=1001;
ptr->x1=298;
ptr->y1=275;
ptr->x2=319;
ptr->y2=305;
ptr=ptr->blink;
ptr->col=15; ptr->name=1002;
ptr->x1=277;
ptr->y1=275;
ptr->x2=298;
ptr->y2=305;
ptr=ptr->blink;
ptr->col=15; ptr->name=1003;
ptr->x1=256;
ptr->y1=275;
ptr->x2=277;
ptr->y2=305;
ptr=ptr->blink;
ptr->col=15; ptr->name=1004;
ptr->x1=235;
ptr->y1=275;
ptr->x2=256;
ptr->y2=305;
ptr=ptr->blink;
ptr->col=15; ptr->name=1005;
ptr->x1=205;
ptr->y1=305;
ptr->x2=235;
ptr->y2=326;
ptr=ptr->blink;
ptr->col=15; ptr->name=1006;
ptr->x1=205;
ptr->y1=326;
ptr->x2=235;
ptr->y2=347;
ptr=ptr->blink;
ptr->col=15; ptr->name=1007;
ptr->x1=205;
ptr->y1=347;
ptr->x2=235;
ptr->y2=368;
ptr=ptr->blink;
ptr->col=15; ptr->name=1008;
ptr->x1=205;
ptr->y1=368;
ptr->x2=235;
ptr->y2=389;
ptr=ptr->blink;
ptr->col=15; ptr->name=1009;
ptr->x1=205;
ptr->y1=389;
ptr->x2=235;
ptr->y2=410;
ptr=ptr->blink;
ptr->col=15; ptr->name=1010;
ptr->x1=205;
ptr->y1=410;
ptr->x2=235;
ptr->y2=435;
ptr=ptr->blink;
ptr->col=15; ptr->name=1011;
ptr->x1=175;
ptr->y1=410;
ptr->x2=205;
ptr->y2=435;
ptr=ptr->blink;
ptr->col=15; ptr->name=1012;
ptr->x1=145;
ptr->y1=410;
ptr->x2=175;
ptr->y2=435;
//red path coordinates
ptr=rhome;
ptr->col=4; ptr->name=2000;
ptr->x1=145;
ptr->y1=389;
ptr->x2=175;
ptr->y2=410;
ptr=ptr->rlink;
ptr->col=15; ptr->name=2001;
ptr->x1=145;
ptr->y1=368;
ptr->x2=175;
ptr->y2=389;
ptr=ptr->rlink;
ptr->col=15; ptr->name=2002;
ptr->x1=145;
ptr->y1=347;
ptr->x2=175;
ptr->y2=368;
ptr=ptr->rlink;
ptr->col=15; ptr->name=2003;
ptr->x1=145;
ptr->y1=326;
ptr->x2=175;
ptr->y2=347;
ptr=ptr->rlink;
ptr->col=15; ptr->name=2004;
ptr->x1=145;
ptr->y1=305;
ptr->x2=175;
ptr->y2=326;
ptr=ptr->rlink;
ptr->col=15; ptr->name=2005;
ptr->x1=120;
ptr->y1=275;
ptr->x2=145;
ptr->y2=305;
ptr=ptr->rlink;
ptr->col=15; ptr->name=2006;
ptr->x1=99;
ptr->y1=275;
ptr->x2=120;
ptr->y2=305;
ptr=ptr->rlink;
ptr->col=15; ptr->name=2007;
ptr->x1=78;
ptr->y1=275;
ptr->x2=99;
ptr->y2=305;
ptr=ptr->rlink;
ptr->col=15; ptr->name=2008;
ptr->x1=57;
ptr->y1=275;
ptr->x2=78;
ptr->y2=305;
ptr=ptr->rlink;
ptr->col=15; ptr->name=2009;
ptr->x1=36;
ptr->y1=275;
ptr->x2=57;
ptr->y2=305;
ptr=ptr->rlink;
ptr->col=15; ptr->name=2010;
ptr->x1=15;
ptr->y1=275;
ptr->x2=36;
ptr->y2=305;
ptr=ptr->rlink;
ptr->col=15; ptr->name=2011;
ptr->x1=15;
ptr->y1=245;
ptr->x2=36;
ptr->y2=275;
ptr=ptr->rlink;
ptr->col=15; ptr->name=2012;
ptr->x1=15;
ptr->y1=215;
ptr->x2=36;
ptr->y2=245;
//green path coordinates
ptr=ghome;
ptr->col=2; ptr->name=3000;
ptr->x1=36;
ptr->y1=215;
ptr->x2=57;
ptr->y2=245;
ptr=ptr->glink;
ptr->col=15; ptr->name=3001;
ptr->x1=57;
ptr->y1=215;
ptr->x2=78;
ptr->y2=245;
ptr=ptr->glink;
ptr->col=15; ptr->name=3002;
ptr->x1=78;
ptr->y1=215;
ptr->x2=99;
ptr->y2=245;
ptr=ptr->glink;
ptr->col=15; ptr->name=3003;
ptr->x1=99;
ptr->y1=215;
ptr->x2=120;
ptr->y2=245;
ptr=ptr->glink;
ptr->col=15; ptr->name=3004;
ptr->x1=120;
ptr->y1=215;
ptr->x2=145;
ptr->y2=245;
ptr=ptr->glink;
ptr->col=15; ptr->name=3005;
ptr->x1=145;
ptr->y1=190;
ptr->x2=175;
ptr->y2=215;
ptr=ptr->glink;
ptr->col=15; ptr->name=3006;
ptr->x1=145;
ptr->y1=169;
ptr->x2=175;
ptr->y2=190;
ptr=ptr->glink;
ptr->col=15; ptr->name=3007;
ptr->x1=145;
ptr->y1=148;
ptr->x2=175;
ptr->y2=169;
ptr=ptr->glink;
ptr->col=15; ptr->name=3008;
ptr->x1=145;
ptr->y1=127;
ptr->x2=175;
ptr->y2=148;
ptr=ptr->glink;
ptr->col=15; ptr->name=3009;
ptr->x1=145;
ptr->y1=106;
ptr->x2=175;
ptr->y2=127;
ptr=ptr->glink;
ptr->col=15; ptr->name=3010;
ptr->x1=145;
ptr->y1=85;
ptr->x2=175;
ptr->y2=106;
ptr=ptr->glink;
ptr->col=15; ptr->name=3011;
ptr->x1=175;
ptr->y1=85;
ptr->x2=205;
ptr->y2=106;
ptr=ptr->glink;
ptr->col=15; ptr->name=3012;
ptr->x1=205;
ptr->y1=85;
ptr->x2=235;
ptr->y2=106;
//yellow path coordinates
ptr=yhome;
ptr->col=14; ptr->name=4000;
ptr->x1=205;
ptr->y1=106;
ptr->x2=235;
ptr->y2=127;
ptr=ptr->ylink;
ptr->col=15; ptr->name=4001;
ptr->x1=205;
ptr->y1=127;
ptr->x2=235;
ptr->y2=148;
ptr=ptr->ylink;
ptr->col=15; ptr->name=4002;
ptr->x1=205;
ptr->y1=148;
ptr->x2=235;
ptr->y2=169;
ptr=ptr->ylink;
ptr->col=15; ptr->name=4003;
ptr->x1=205;
ptr->y1=169;
ptr->x2=235;
ptr->y2=190;
ptr=ptr->ylink;
ptr->col=15; ptr->name=4004;
ptr->x1=205;
ptr->y1=190;
ptr->x2=235;
ptr->y2=215;
ptr=ptr->ylink;
ptr->col=15; ptr->name=4005;
ptr->x1=235;
ptr->y1=215;
ptr->x2=256;
ptr->y2=245;
ptr=ptr->ylink;
ptr->col=15; ptr->name=4006;
ptr->x1=256;
ptr->y1=215;
ptr->x2=277;
ptr->y2=245;
ptr=ptr->ylink;
ptr->col=15; ptr->name=4007;
ptr->x1=277;
ptr->y1=215;
ptr->x2=298;
ptr->y2=245;
ptr=ptr->ylink;
ptr->col=15; ptr->name=4008;
ptr->x1=298;
ptr->y1=215;
ptr->x2=319;
ptr->y2=245;
ptr=ptr->ylink;
ptr->col=15; ptr->name=4009;
ptr->x1=319;
ptr->y1=215;
ptr->x2=340;
ptr->y2=245;
ptr=ptr->ylink;
ptr->col=15; ptr->name=4010;
ptr->x1=340;
ptr->y1=215;
ptr->x2=365;
ptr->y2=245;
ptr=ptr->ylink;
ptr->col=15; ptr->name=4011;
ptr->x1=340;
ptr->y1=245;
ptr->x2=365;
ptr->y2=275;
ptr=ptr->ylink;
ptr->col=15; ptr->name=4012;
ptr->x1=340;
ptr->y1=275;
ptr->x2=365;
ptr->y2=305;
//end of path coordinates
//start of home path
//blue home path
ptr=p[0];
ptr=ptr->blink;
ptr->col=1; ptr->name=5000;
ptr->x1=319;
ptr->y1=245;
ptr->x2=340;
ptr->y2=275;
ptr=ptr->blink;
ptr->col=1; ptr->name=5001;
ptr->x1=298;
ptr->y1=245;
ptr->x2=319;
ptr->y2=275;
ptr=ptr->blink;
ptr->col=1; ptr->name=5002;
ptr->x1=277;
ptr->y1=245;
ptr->x2=298;
ptr->y2=275;
ptr=ptr->blink;
ptr->col=1; ptr->name=5003;
ptr->x1=256;
ptr->y1=245;
ptr->x2=277;
ptr->y2=275;
ptr=ptr->blink;
ptr->col=1; ptr->name=5004;
ptr->x1=235;
ptr->y1=245;
ptr->x2=256;
ptr->y2=275;
//red home path
ptr=p[1];
ptr=ptr->rlink;
ptr->col=4; ptr->name=6000;
ptr->x1=175;
ptr->y1=389;
ptr->x2=205;
ptr->y2=410;
ptr=ptr->rlink;
ptr->col=4; ptr->name=6001;
ptr->x1=175;
ptr->y1=368;
ptr->x2=205;
ptr->y2=389;
ptr=ptr->rlink;
ptr->col=4; ptr->name=6002;
ptr->x1=175;
ptr->y1=347;
ptr->x2=205;
ptr->y2=368;
ptr=ptr->rlink;
ptr->col=4; ptr->name=6003;
ptr->x1=175;
ptr->y1=326;
ptr->x2=205;
ptr->y2=347;
ptr=ptr->rlink;
ptr->col=4; ptr->name=6004;
ptr->x1=175;
ptr->y1=305;
ptr->x2=205;
ptr->y2=326;
//green home path
ptr=p[2];
ptr=ptr->glink;
ptr->col=2; ptr->name=7000;
ptr->x1=36;
ptr->y1=245;
ptr->x2=57;
ptr->y2=275;
ptr=ptr->glink;
ptr->col=2; ptr->name=7001;
ptr->x1=57;
ptr->y1=245;
ptr->x2=78;
ptr->y2=275;
ptr=ptr->glink;
ptr->col=2; ptr->name=7002;
ptr->x1=78;
ptr->y1=245;
ptr->x2=99;
ptr->y2=275;
ptr=ptr->glink;
ptr->col=2; ptr->name=7003;
ptr->x1=99;
ptr->y1=245;
ptr->x2=120;
ptr->y2=275;
ptr=ptr->glink;
ptr->col=2; ptr->name=7004;
ptr->x1=120;
ptr->y1=245;
ptr->x2=145;
ptr->y2=275;
//yellow home path
ptr=p[3];
ptr=ptr->ylink;
ptr->col=14; ptr->name=8000;
ptr->x1=175;
ptr->y1=106;
ptr->x2=205;
ptr->y2=127;
ptr=ptr->ylink;
ptr->col=14; ptr->name=8001;
ptr->x1=175;
ptr->y1=127;
ptr->x2=205;
ptr->y2=148;
ptr=ptr->ylink;
ptr->col=14; ptr->name=8002;
ptr->x1=175;
ptr->y1=148;
ptr->x2=205;
ptr->y2=169;
ptr=ptr->ylink;
ptr->col=14; ptr->name=8003;
ptr->x1=175;
ptr->y1=169;
ptr->x2=205;
ptr->y2=190;
ptr=ptr->ylink;
ptr->col=14; ptr->name=8004;
ptr->x1=175;
ptr->y1=190;
ptr->x2=205;
ptr->y2=215;
//home box
ptr=home;
ptr->col=0; ptr->name=9000;
ptr->x1=150;
ptr->y1=220;
ptr->x2=230;
ptr->y2=300;
//end of coordinate assign
}


void deletenode()
{
//deleting nodes begin
pre=p[0]->blink;
for(i=0; i<5; i++)
{
ptr=pre;
pre=pre->blink;
delete ptr;
}
pre=p[1]->rlink;
for(i=0; i<5; i++)
{
ptr=pre;
pre=pre->rlink;
delete ptr;
}
pre=p[2]->glink;
for(i=0; i<5; i++)
{
ptr=pre;
pre=pre->glink;
delete ptr;
}
pre=p[3]->ylink;
for(i=0; i<5; i++)
{
ptr=pre;
pre=pre->ylink;
delete ptr;
}
// delete blue path
pre=bhome;
for(i=0; i<13; i++)
{
ptr=pre;
pre=pre->blink;
delete ptr;
}
// delete red path
pre=rhome;
for(i=0; i<13; i++)
{
ptr=pre;
pre=pre->rlink;
delete ptr;
}
//delete green path
pre=ghome;
for(i=0; i<13; i++)
{
ptr=pre;
pre=pre->glink;
delete ptr;
}
// delete yellow path
pre=yhome;
for(i=0; i<13; i++)
{
ptr=pre;
pre=pre->ylink;
delete ptr;
}
//delete home
delete home;
//deleting nodes complete
}



node *search(int name)
{
if(name==9000) //home
{
return home;
}
else if(name>=8000 && name<=8004) //yellow home path
{
i=8000;
ptr=p[3];
while(name>=i)
{
ptr=ptr->ylink;
i++;
}
return ptr;
}
else if(name>=7000 && name<=7004) //green home path
{
i=7000;
ptr=p[2];
while(name>=i)
{
ptr=ptr->glink;
i++;
}
return ptr;
}
else if(name>=6000 && name<=6004) //red home path
{
i=6000;
ptr=p[1];
while(name>=i)
{
ptr=ptr->rlink;
i++;
}
return ptr;
}
else if(name>=5000 && name<=5004) //blue home path
{
i=5000;
ptr=p[0];
while(name>=i)
{
ptr=ptr->blink;
i++;
}
return ptr;
}
else if(name>=4000 && name<=4012) //yellow path
{
i=4000;
ptr=yhome;
while(name>i)
{
ptr=ptr->ylink;
i++;
}
return ptr;
}
else if(name>=3000 && name<=3012) //green path
{
i=3000;
ptr=ghome;
while(name>i)
{
ptr=ptr->glink;
i++;
}
return ptr;
}
else if(name>=2000 && name<=2012) //red path
{
i=2000;
ptr=rhome;
while(name>i)
{
ptr=ptr->rlink;
i++;
}
return ptr;
}
else if(name>=1000 && name<=1012) //blue path
{
i=1000;
ptr=bhome;
while(name>i)
{
ptr=ptr->blink;
i++;
}
return ptr;
}
else // end of search
{}
return NULL;
}

// marks and base work starts


struct base
{
int co_x;
int co_y;
int m_pres;
int b_color;
};

struct mark
{
base *bs_link;
int cur_name;
node *cur_link;
int t_color;
int h_x;
int h_y;
};

// initialize mark
mark *blue_1;
mark *blue_2;
mark *blue_3;
mark *blue_4;
mark *red_1;
mark *red_2;
mark *red_3;
mark *red_4;
mark *green_1;
mark *green_2;
mark *green_3;
mark *green_4;
mark *yellow_1;
mark *yellow_2;
mark *yellow_3;
mark *yellow_4;
// initialize base
base *bb_1;
base *bb_2;
base *bb_3;
base *bb_4;
base *rb_1;
base *rb_2;
base *rb_3;
base *rb_4;
base *gb_1;
base *gb_2;
base *gb_3;
base *gb_4;
base *yb_1;
base *yb_2;
base *yb_3;
base *yb_4;
// initialize done

// player
struct player
{
mark *m1;
mark *m2;
mark *m3;
mark *m4;
int col;
int win;
};

player *blue;
player *green;
player *red;
player *yellow;

void createoth()
{
//base work start
bb_1=new base;
bb_2=new base;
bb_3=new base;
bb_4=new base;
rb_1=new base;
rb_2=new base;
rb_3=new base;
rb_4=new base;
gb_1=new base;
gb_2=new base;
gb_3=new base;
gb_4=new base;
yb_1=new base;
yb_2=new base;
yb_3=new base;
yb_4=new base;


// blue marks definations
blue_1=new mark;
blue_1->bs_link=bb_1;
blue_1->cur_link=NULL;
blue_1->cur_name=0;
blue_1->t_color=1;
blue_1->h_x=590;
blue_1->h_y=245;

blue_2=new mark;
blue_2->bs_link=bb_2;
blue_2->cur_link=NULL;
blue_2->cur_name=0;
blue_2->t_color=1;
blue_2->h_x=590;
blue_2->h_y=265;

blue_3=new mark;
blue_3->bs_link=bb_3;
blue_3->cur_link=NULL;
blue_3->cur_name=0;
blue_3->t_color=1;
blue_3->h_x=590;
blue_3->h_y=285;

blue_4=new mark;
blue_4->bs_link=bb_4;
blue_4->cur_link=NULL;
blue_4->cur_name=0;
blue_4->t_color=1;
blue_4->h_x=590;
blue_4->h_y=305;


// red marks definations
red_1=new mark;
red_1->bs_link=rb_1;
red_1->cur_link=NULL;
red_1->cur_name=0;
red_1->t_color=4;
red_1->h_x=420;
red_1->h_y=245;

red_2=new mark;
red_2->bs_link=rb_2;
red_2->cur_link=NULL;
red_2->cur_name=0;
red_2->t_color=4;
red_2->h_x=420;
red_2->h_y=265;

red_3=new mark;
red_3->bs_link=rb_3;
red_3->cur_link=NULL;
red_3->cur_name=0;
red_3->t_color=4;
red_3->h_x=420;
red_3->h_y=285;

red_4=new mark;
red_4->bs_link=rb_4;
red_4->cur_link=NULL;
red_4->cur_name=0;
red_4->t_color=4;
red_4->h_x=420;
red_4->h_y=305;


// green marks definations
green_1=new mark;
green_1->bs_link=gb_1;
green_1->cur_link=NULL;
green_1->cur_name=0;
green_1->t_color=2;
green_1->h_x=445;
green_1->h_y=245;

green_2=new mark;
green_2->bs_link=gb_2;
green_2->cur_link=NULL;
green_2->cur_name=0;
green_2->t_color=2;
green_2->h_x=445;
green_2->h_y=265;

green_3=new mark;
green_3->bs_link=gb_3;
green_3->cur_link=NULL;
green_3->cur_name=0;
green_3->t_color=2;
green_3->h_x=445;
green_3->h_y=285;

green_4=new mark;
green_4->bs_link=gb_4;
green_4->cur_link=NULL;
green_4->cur_name=0;
green_4->t_color=2;
green_4->h_x=445;
green_4->h_y=305;


// yellow marks definations
yellow_1=new mark;
yellow_1->bs_link=yb_1;
yellow_1->cur_link=NULL;
yellow_1->cur_name=0;
yellow_1->t_color=14;
yellow_1->h_x=565;
yellow_1->h_y=245;

yellow_2=new mark;
yellow_2->bs_link=yb_2;
yellow_2->cur_link=NULL;
yellow_2->cur_name=0;
yellow_2->t_color=14;
yellow_2->h_x=565;
yellow_2->h_y=265;

yellow_3=new mark;
yellow_3->bs_link=yb_3;
yellow_3->cur_link=NULL;
yellow_3->cur_name=0;
yellow_3->t_color=14;
yellow_3->h_x=565;
yellow_3->h_y=285;

yellow_4=new mark;
yellow_4->bs_link=yb_4;
yellow_4->cur_link=NULL;
yellow_4->cur_name=0;
yellow_4->t_color=14;
yellow_4->h_x=565;
yellow_4->h_y=305;

// marks definations done

// base definations start

// blue bases
bb_1->b_color=1;
bb_1->m_pres=1;
bb_1->co_x=325;  
bb_1->co_y=350;

bb_2->b_color=1;
bb_2->m_pres=1;
bb_2->co_x=280;
bb_2->co_y=350;

bb_3->b_color=1;
bb_3->m_pres=1;
bb_3->co_x=280;
bb_3->co_y=395;

bb_4->b_color=1;
bb_4->m_pres=1;
bb_4->co_x=325;
bb_4->co_y=395;

// red bases
rb_1->b_color=4;
rb_1->m_pres=1;
rb_1->co_x=100;
rb_1->co_y=395;

rb_2->b_color=4;
rb_2->m_pres=1;
rb_2->co_x=100;
rb_2->co_y=350;

rb_3->b_color=4;
rb_3->m_pres=1;
rb_3->co_x=55;
rb_3->co_y=350;

rb_4->b_color=4;
rb_4->m_pres=1;
rb_4->co_x=55;
rb_4->co_y=395;

// green bases
gb_1->b_color=2;
gb_1->m_pres=1;
gb_1->co_x=55;
gb_1->co_y=170;

gb_2->b_color=2;
gb_2->m_pres=2;
gb_2->co_x=100;
gb_2->co_y=170;

gb_3->b_color=2;
gb_3->m_pres=1;
gb_3->co_x=100;
gb_3->co_y=125;

gb_4->b_color=2;
gb_4->m_pres=1;
gb_4->co_x=55;
gb_4->co_y=125;

// yellow bases
yb_1->b_color=14;
yb_1->m_pres=1;
yb_1->co_x=280;
yb_1->co_y=125;

yb_2->b_color=14;
yb_2->m_pres=1;
yb_2->co_x=280;
yb_2->co_y=170;

yb_3->b_color=14;
yb_3->m_pres=1;
yb_3->co_x=325;
yb_3->co_y=170;

yb_4->b_color=14;
yb_4->m_pres=1;
yb_4->co_x=325;
yb_4->co_y=125;

// bases defination done

//player defination starts
blue = new player;
blue->m1=blue_1;
blue->m2=blue_2;
blue->m3=blue_3;
blue->m4=blue_4;
blue->col=1;
blue->win=0;

red = new player;
red->m1=red_1;
red->m2=red_2;
red->m3=red_3;
red->m4=red_4;
red->col=4;
red->win=0;

green = new player;
green->m1=green_1;
green->m2=green_2;
green->m3=green_3;
green->m4=green_4;
green->col=2;
green->win=0;

yellow = new player;
yellow->m1=yellow_1;
yellow->m2=yellow_2;
yellow->m3=yellow_3;
yellow->m4=yellow_4;
yellow->col=14;
yellow->win=0;
}


// delete marks and base
void deleteoth()
{
// delete marks
delete blue_1;
delete blue_2;
delete blue_3;
delete blue_4;
delete red_1;
delete red_2;
delete red_3;
delete red_4;
delete green_1;
delete green_2;
delete green_3;
delete green_4;
delete yellow_1;
delete yellow_2;
delete yellow_3;
delete yellow_4;
// delete base
delete bb_1;
delete bb_2;
delete bb_3;
delete bb_4;
delete rb_1;
delete rb_2;
delete rb_3;
delete rb_4;
delete gb_1;
delete gb_2;
delete gb_3;
delete gb_4;
delete yb_1;
delete yb_2;
delete yb_3;
delete yb_4;
// delete player
delete blue;
delete red;
delete green;
delete yellow;
}

int stop[8]={1000,2000,3000,4000,1008,2008,3008,4008};