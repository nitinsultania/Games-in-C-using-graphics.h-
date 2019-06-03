int event::check(int posx, int posy, int col)
{
	player *opp;
	int x,y;
	int py,oc;
	if(col==15)
	{
		py=1;
		oc=0;
		opp=pb;
	}
	else
	{
		py=-1;
		oc=15;
		opp=pw;
	}
	//check for king
	x=posx+1;
	y=posy;
	if(x<8&&x>=0&&y<8&&y>=0)
	{
		if(board[x][y].playercol==oc && opp->gettype(board[x][y].pnum)=='m')
			return 1;
	}
	x=posx;
	y=posy+1;
	if(x<8&&x>=0&&y<8&&y>=0)
	{
		if(board[x][y].playercol==oc && opp->gettype(board[x][y].pnum)=='m')
			return 1;
	}
	x=posx;
	y=posy-1;
	if(x<8&&x>=0&&y<8&&y>=0)
	{
		if(board[x][y].playercol==oc && opp->gettype(board[x][y].pnum)=='m')
			return 1;
	}
	x=posx-1;
	y=posy;
	if(x<8&&x>=0&&y<8&&y>=0)
	{
		if(board[x][y].playercol==oc && opp->gettype(board[x][y].pnum)=='m')
			return 1;
	}
	x=posx-1;
	y=posy+1;
	if(x<8&&x>=0&&y<8&&y>=0)
	{
		if(board[x][y].playercol==oc && opp->gettype(board[x][y].pnum)=='m')
			return 1;
	}
	x=posx+1;
	y=posy-1;
	if(x<8&&x>=0&&y<8&&y>=0)
	{
		if(board[x][y].playercol==oc && opp->gettype(board[x][y].pnum)=='m')
			return 1;
	}
	x=posx-1;
	y=posy-1;
	if(x<8&&x>=0&&y<8&&y>=0)
	{
		if(board[x][y].playercol==oc && opp->gettype(board[x][y].pnum)=='m')
			return 1;
	}
	x=posx+1;
	y=posy+1;
	if(x<8&&x>=0&&y<8&&y>=0)
	{
		if(board[x][y].playercol==oc && opp->gettype(board[x][y].pnum)=='m')
			return 1;
	}
	//check for king over
	//check for pawn
	x=posx+1;
	y=posy+py;
	if(x<8&&x>=0&&y<8&&y>=0)
	{
		if(board[x][y].playercol==oc && opp->gettype(board[x][y].pnum)=='p')
			return 1;
	}
	x=posx-1;
	y=posy+py;
	if(x<8&&x>=0&&y<8&&y>=0)
	{
		if(board[x][y].playercol==oc && opp->gettype(board[x][y].pnum)=='p')
			return 1;
	}
	//check for pawn over
	//check for rook or queen
	x=posx+1;
	y=posy;
	while(x<8)
	{
		if(board[x][y].playercol!=10)
		{
			if(board[x][y].playercol==oc && (opp->gettype(board[x][y].pnum)=='r' || opp->gettype(board[x][y].pnum)=='q'))
			{
				return 1;
			}
			break;
		}
		x++;
	}
	x=posx-1;
	y=posy;
	while(x>=0)
	{
		if(board[x][y].playercol!=10)
		{
			if(board[x][y].playercol==oc && (opp->gettype(board[x][y].pnum)=='r' || opp->gettype(board[x][y].pnum)=='q'))
			{
				return 1;
			}
			break;
		}
		x--;
	}
	x=posx;
	y=posy+1;
	while(y<8)
	{
		if(board[x][y].playercol!=10)
		{
			if(board[x][y].playercol==oc && (opp->gettype(board[x][y].pnum)=='r' || opp->gettype(board[x][y].pnum)=='q'))
			{
				return 1;
			}
			break;
		}
		y++;
	}
	x=posx;
	y=posy-1;
	while(y>=0)
	{
		if(board[x][y].playercol!=10)
		{
			if(board[x][y].playercol==oc && (opp->gettype(board[x][y].pnum)=='r' || opp->gettype(board[x][y].pnum)=='q'))
			{
				return 1;
			}
			break;
		}
		y--;
	}
	//check for rook or queen over
	//check for bishop or queen
	x=posx-1;
	y=posy-1;
	while(y>=0&&x>=0)
	{
		if(board[x][y].playercol!=10)
		{
			if(board[x][y].playercol==oc && (opp->gettype(board[x][y].pnum)=='b' || opp->gettype(board[x][y].pnum)=='q'))
			{
				return 1;
			}
			break;
		}
		y--;
		x--;
	}
	x=posx+1;
	y=posy+1;
	while(y<8&&x<8)
	{
		if(board[x][y].playercol!=10)
		{
			if(board[x][y].playercol==oc && (opp->gettype(board[x][y].pnum)=='b' || opp->gettype(board[x][y].pnum)=='q'))
			{
				return 1;
			}
			break;
		}
		y++;
		x++;
	}
	x=posx+1;
	y=posy-1;
	while(y>=0&&x<8)
	{
		if(board[x][y].playercol!=10)
		{
			if(board[x][y].playercol==oc && (opp->gettype(board[x][y].pnum)=='b' || opp->gettype(board[x][y].pnum)=='q'))
			{
				return 1;
			}
			break;
		}
		y--;
		x++;
	}
	x=posx-1;
	y=posy+1;
	while(y<8&&x>=0)
	{
		if(board[x][y].playercol!=10)
		{
			if(board[x][y].playercol==oc && (opp->gettype(board[x][y].pnum)=='b' || opp->gettype(board[x][y].pnum)=='q'))
			{
				return 1;
			}
			break;
		}
		y++;
		x--;
	}
	//check for bishop or queen over
	//check for knight
	x=posx+2;
	y=posy-1;
	if(x<8&&x>=0&&y<8&&y>=0)
	{
		if(board[x][y].playercol==oc && opp->gettype(board[x][y].pnum)=='k')
			return 1;
	}
	x=posx+2;
	y=posy+1;
	if(x<8&&x>=0&&y<8&&y>=0)
	{
		if(board[x][y].playercol==oc && opp->gettype(board[x][y].pnum)=='k')
			return 1;
	}
	x=posx-2;
	y=posy-1;
	if(x<8&&x>=0&&y<8&&y>=0)
	{
		if(board[x][y].playercol==oc && opp->gettype(board[x][y].pnum)=='k')
			return 1;
	}
	x=posx-2;
	y=posy+1;
	if(x<8&&x>=0&&y<8&&y>=0)
	{
		if(board[x][y].playercol==oc && opp->gettype(board[x][y].pnum)=='k')
			return 1;
	}
	x=posx-1;
	y=posy+2;
	if(x<8&&x>=0&&y<8&&y>=0)
	{
		if(board[x][y].playercol==oc && opp->gettype(board[x][y].pnum)=='k')
			return 1;
	}
	x=posx+1;
	y=posy+2;
	if(x<8&&x>=0&&y<8&&y>=0)
	{
		if(board[x][y].playercol==oc && opp->gettype(board[x][y].pnum)=='k')
			return 1;
	}
	x=posx-1;
	y=posy-2;
	if(x<8&&x>=0&&y<8&&y>=0)
	{
		if(board[x][y].playercol==oc && opp->gettype(board[x][y].pnum)=='k')
			return 1;
	}
	x=posx+1;
	y=posy-2;
	if(x<8&&x>=0&&y<8&&y>=0)
	{
		if(board[x][y].playercol==oc && opp->gettype(board[x][y].pnum)=='k')
			return 1;
	}
	//check for knight over
	return 0;
}
void event::initials()
{
	for(int i=0; i<16; i++)
	{
		point[i]=NULL;
	}
	high = NULL;
	lastx = 45;
	lasty = 250;
}
void event::addstack(int n, action *p)
{
	action *a = new action;
	a->ppcol=p->ppcol;
	a->ppnum=p->ppnum;
	a->ppix=p->ppix;
	a->ppfx=p->ppfx;
	a->ppiy=p->ppiy;
	a->ppfy=p->ppfy;
	a->spcol=p->spcol;
	a->spnum=p->spnum;
	a->spix=p->spix;
	a->spfx=p->spfx;
	a->spiy=p->spiy;
	a->spfy=p->spfy;
	a->next=point[n];
	point[n]=a;
}
void event::dstack(int n)
{
	for(action *a = point[n];a != NULL;)
	{
		action *p=a;
		a=a->next;
		delete p;
	}
	point[n]=NULL;
}
void event::rstack()
{
	for(int i=0; i<16; i++)
	{
		dstack(i);
	}
}
void event::dohighlight(int num)
{
	action *p = point[num];
	while(p!=NULL)
	{
		highlight *h=new highlight;
		h->a=p;
		h->xc=p->ppfx;
		h->yc=p->ppfy;
		h->link=high;
		high=h;
		if(p->spcol!=10 && p->spcol!=p->ppcol)
		{
			mhighlight(p->ppfx,p->ppfy,4);
		}
		else
		{
			mhighlight(p->ppfx,p->ppfy,2);
		}
		p=p->next;
	}
}
void event::rhighlight()
{
	highlight *h = high;
	while(h!=NULL)
	{
		dehighlight(h->xc,h->yc);
		highlight *p=h;
		h=h->link;
		delete p;
	}
	high=NULL;
}
int event::ifhighlight(int x, int y)
{
	highlight *h = high;
	action *p;
	while(h!=NULL)
	{
		if(h->xc == x && h->yc == y)
		{
			p=h->a;
			rhighlight();
			p->takeaction();
			rstack();
			return 1;
		}
		h=h->link;
	}
	return 0;
}
int event::playgame(int col)
{
	player *p;
	int ischeck,movesavail=0;
	char name[6];
	if(col==15)
	{
		p=pw;
		name[0]='W';
		name[1]='h';
		name[2]='i';
		name[3]='t';
		name[4]='e';
		name[5]=NULL;
	}
	else
	{
		p=pb;
		name[0]='B';
		name[1]='l';
		name[2]='a';
		name[3]='c';
		name[4]='k';
		name[5]=NULL;
	}
	int kx,ky;
	p->kplace(kx,ky);
	ischeck=check(kx,ky,col);
	p->addmoves();
	for(int i=0; i<16; i++)
	{
		if(point[i]!=NULL)
		{
			movesavail=1;
			break;
		}
	}
	if(ischeck==1)
	{
		dispmsg("Check","",name,"Chance","");
	}
	else
	{
		dispmsg("","",name,"Chance","");
	}
	if(ischeck==1 && movesavail==0)
	{
		dispmsg("CheckMate",name,"Lost","The","Game");
		sleep(20);
		return 0;
	}
	if(ischeck==0 && movesavail==0)
	{
		dispmsg("Stalemate","The","Game","Has","Drawn");
		sleep(20);
		return 0;
	}
	int x1=0,y1=0;
	int done=0;
	while(done==0)
	{
	showmouse(lastx,lasty);
	mouselimit(45,45,600,455);
	mouseclick(x1,y1);
	lastx=x1,lasty=y1;
	if(x1>505&&y1>135&&x1<565&&y1<195)
	{
		about();
	}
	else if(x1>505&&y1>205&&x1<565&&y1<265)
	{
		rhighlight();
		rstack();
		return 0;
	}
	else if(x1>50&&x1<450&&y1>50&&y1<450)
	{
		if(board[((x1/50)-1)][(8-(y1/50))].playercol==col)
		{
			rhighlight();
			dohighlight(board[((x1/50)-1)][(8-(y1/50))].pnum);
		}
		else if(ifhighlight(((x1/50)-1),(8-(y1/50)))==1)
		{
			done = 1;
		}
		else
		{
			rhighlight();
		}
	}
	}
	return 1;
}