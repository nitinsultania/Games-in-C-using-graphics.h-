void event::assignboxes()
{
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			board[i][j].playercol=10;
			board[i][j].pnum=(-1);
			board[i][j].x1=50+50*i;
			board[i][j].y1=400-50*j;
			board[i][j].x2=100+50*i;
			board[i][j].y2=450-50*j;
			if(i%2==0)
			{
				if(j%2==0)
					board[i][j].col=8;
				else
					board[i][j].col=7;	
			}
			else
			{
				if(j%2==0)
					board[i][j].col=7;
				else
					board[i][j].col=8;	
			}
		}
	}
}
void event::contentsdraw()
{
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			drawbox(i,j);
		}
	}
}
void event::place(int x, int y, int pcol, int pnumber)
{
	board[x][y].playercol=pcol;
	board[x][y].pnum=pnumber;
}
void event::removed(int x, int y)
{
	board[x][y].playercol=10;
	board[x][y].pnum=(-1);
}
char event::getpromote()
{
	char ans;
	int x1=0,y1=0;
	drawpromote();
	listenmouse:
	showmouse(535,293);
	mouselimit(475,275,595,450);
	mouseclick(x1,y1);
	if(x1>480 && x1<590 && y1>313 && y1<343)
	{
		clearmsg();
		ans='q';
	}
	else if(x1>480 && x1<590 && y1>348 && y1<378)
	{
		clearmsg();
		ans='r';
	}
	else if(x1>480 && x1<590 && y1>383 && y1<413)
	{
		clearmsg();
		ans='b';
	}
	else if(x1>480 && x1<590 && y1>418 && y1<448)
	{
		clearmsg();
		ans='k';
	}
	else
	{
		goto listenmouse;
	}
	return ans;
}
void event::initialize()
{
	assignboxes();
	// assign pieces
	int x,y,p;
	y=1;
	for(x=0,p=8;x<8;p++,x++)
	{
		place(x,y,15,p);
		pw->pieces[p].initial('p',x,y);
	}
	y=6;
	for(x=7,p=8;x>=0;p++,x--)
	{
		place(x,y,0,p);
		pb->pieces[p].initial('p',x,y);
	}
	place(4,0,15,0); // white king 0 (4,0) 
	pw->pieces[0].initial('m',4,0);
	place(4,7,0,0); // black king 0 (4,7)
	pb->pieces[0].initial('m',4,7);
	place(3,0,15,1); // white queen 1 (3,0)
	pw->pieces[1].initial('q',3,0);
	place(3,7,0,1);// black queen 1 (3,7)
	pb->pieces[1].initial('q',3,7);
	place(2,0,15,2); // white bishop 2 (2,0)
	pw->pieces[2].initial('b',2,0);
	place(1,0,15,3); // white knight 3 (1,0)
	pw->pieces[3].initial('k',1,0);
	place(0,0,15,4); // white rook 4 (0,0)
	pw->pieces[4].initial('r',0,0);
	place(5,7,0,2); // black bishop 2 (5,7)
	pb->pieces[2].initial('b',5,7);
	place(6,7,0,3); // black knight 3 (6,7)
	pb->pieces[3].initial('k',6,7);
	place(7,7,0,4); // black rook 4 (7,7)
	pb->pieces[4].initial('r',7,7);
	place(5,0,15,5); // white bishop 5 (5,0)
	pw->pieces[5].initial('b',5,0);
	place(6,0,15,6); // white knight 6 (6,0)
	pw->pieces[6].initial('k',6,0);
	place(7,0,15,7); // white rook 7 (7,0)
	pw->pieces[7].initial('r',7,0);
	place(2,7,0,5); // black bishop 5 (2,7)
	pb->pieces[5].initial('b',2,7);
	place(1,7,0,6); // black knight 6 (1,7)
	pb->pieces[6].initial('k',1,7);
	place(0,7,0,7); // black rook 7 (0,7)
	pb->pieces[7].initial('r',0,7);
	// pieces assigned
	pw->col=15;
	pb->col=0;
	pw->fmove=1;
	pb->fmove=(-1);
	initials();
	maindraw();
	contentsdraw();
}
void event::about()
{
	lastx=45;
	lasty=250;
	drawabout();
	aboutmouse:
	showmouse(600,200);
	mouselimit(470,130,600,200);
	int x1,y1;
	mouseclick(x1,y1);
	if(x1>505 && x1<565 && y1>135 && y1<195)
	{
		redraw();
		return;
	}
	else
	{
		goto aboutmouse;
	}
}
void action::takeaction()
{
	player *p;
	if(spcol==10)
	{
	}
	else
	{
		if(spcol==15)
			p=pw;
		else
			p=pb;
		E.removed(spix,spiy);
		drawbox(spix,spiy);
		if(spfx==(-1) && spfy==(-1))
		{
			p->removeit(spnum);
		}
		else
		{
			E.place(spfx,spfy,spcol,spnum);
			p->domove(spnum,spfx,spfy);
			drawbox(spfx,spfy);
		}
	}
	if(ppcol==15)
		p=pw;
	else
		p=pb;
	E.removed(ppix,ppiy);
	drawbox(ppix,ppiy);
	E.place(ppfx,ppfy,ppcol,ppnum);
	p->domove(ppnum,ppfx,ppfy);
	drawbox(ppfx,ppfy);
}
int action::seevalid()
{
	int result;
	int kx,ky;
	player *p;
	if(ppcol==15)
		p=pw;
	else
		p=pb;
	int bippcol,bippnum,bfppcol,bfppnum;
	int bispcol,bispnum,bfspcol,bfspnum;
	if(spcol==10)
	{
	}
	else
	{
		bispcol=board[spix][spiy].playercol;
		bispnum=board[spix][spiy].pnum;
		E.removed(spix,spiy);
		if(spfx==(-1) && spfy==(-1))
		{}
		else
		{
			bfspcol=board[spfx][spfy].playercol;
			bfspnum=board[spfx][spfy].pnum;
			E.place(spfx,spfy,spcol,spnum);
		}
	}
	bippcol=board[ppix][ppiy].playercol;
	bippnum=board[ppix][ppiy].pnum;
	bfppcol=board[ppfx][ppfy].playercol;
	bfppnum=board[ppfx][ppfy].pnum;
	E.removed(ppix,ppiy);
	E.place(ppfx,ppfy,ppcol,ppnum);
	if(p->gettype(ppnum)=='m')
	{
		kx=ppfx;
		ky=ppfy;
	}
	else
	{
		p->kplace(kx,ky);
	}
	if(E.check(kx,ky,p->col)==0)
		result=1;
	else
		result=0;
	board[ppix][ppiy].playercol=bippcol;
	board[ppix][ppiy].pnum=bippnum;
	board[ppfx][ppfy].playercol=bfppcol;
	board[ppfx][ppfy].pnum=bfppnum;
	if(spcol==10)
	{
	}
	else
	{
		board[spix][spiy].playercol=bispcol;
		board[spix][spiy].pnum=bispnum;
		if(spfx==(-1) && spfy==(-1))
		{}
		else
		{
			board[spfx][spfy].playercol=bfspcol;
			board[spfx][spfy].pnum=bfspnum;
		}
	}
	return result;
}
void action::addaction(int pcol, int pnum, int pix, int piy, int pfx, int pfy, int scol, int snum, int six, int siy, int sfx, int sfy)
{
	ppcol=pcol;
	ppnum=pnum;
	ppix=pix;
	ppfx=pfx;
	ppiy=piy;
	ppfy=pfy;
	spcol=scol;
	spnum=snum;
	spix=six;
	spfx=sfx;
	spiy=siy;
	spfy=sfy;
}