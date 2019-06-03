class action
{
	public:
	int ppcol;
	int ppnum;
	int ppix;
	int ppfx;
	int ppiy;
	int ppfy;
	int spcol;
	int spnum;
	int spix;
	int spfx;
	int spiy;
	int spfy;
	void takeaction();
	int seevalid();
	void addaction(int pcol, int pnum, int pix, int piy, int pfx, int pfy, int scol, int snum, int six, int siy, int sfx, int sfy);
	action *next;
}A;
class highlight
{
	public:
	action *a;
	int xc;
	int yc;
	highlight *link;
};
class event
{
	public:
	action *point[16];
	int lastx;
	int lasty;
	highlight *high;
	void addstack(int n,action *p);
	void dstack(int n);
	void rstack();
	void about();
	void initialize();
	char getpromote();
	void place(int x, int y, int pcol, int pnumber);
	void removed(int x, int y);
	void contentsdraw();
	void assignboxes();
	void dohighlight(int num);
	void rhighlight();
	int ifhighlight(int x, int y);
	int check(int posx, int posy, int col);
	int playgame(int col);
	void initials();
}E;

struct box
{
int x1;
int y1;
int x2;
int y2;
int col;
int playercol;
int pnum;
}board[8][8];
class piece
{
public:
char type;
int fm;
int posx;
int posy;
void initial(char t, int x, int y);
};
void piece::initial(char t, int x, int y)
{
	type=t;
	posx=x;
	posy=y;
	fm=1;
}
struct enp
{
	int can;
	int fx;
	int fy;
	int dno;
	enp();
};
enp::enp()
{
	can=0;
}
class player
{
public:
int col;
piece pieces[16];
enp enpass;
int fmove;
void addmoves();
char gettype(int num);
void grantenpass(int num);
void enpassant(int num);
void twopawn(int num);
void cutpawn(int num);
void npawn(int num);
void castling(int num);
void nking(int num);
void nqueen(int num);
void nknight(int num);
void nrook(int num);
void nbishop(int num);
void promote(int num);
void domove(int num, int fx, int fy);
void removeit(int num);
void kplace(int &kx, int &ky);
}white,black;
player *pw = &white;
player *pb = &black;
char player::gettype(int num)
{
	return pieces[num].type;
}
void player::promote(int num)
{
	char ch=E.getpromote();
	pieces[num].type=ch;
}
void player::removeit(int num)
{
	pieces[num].type='n';
}
void player::domove(int num, int fx, int fy)
{
	enpass.can=0;
	pieces[num].fm=0;
	if(pieces[num].type!='p')
	{
		pieces[num].posx=fx;
		pieces[num].posy=fy;
	}
	else
	{
		if(col==15 && fy==7)
		{
		pieces[num].posx=fx;
		pieces[num].posy=fy;
		promote(num);
		}
		else if(col==0 && fy==0)
		{
		pieces[num].posx=fx;
		pieces[num].posy=fy;
		promote(num);
		}
		else if(pieces[num].posy-fy==-2 || pieces[num].posy-fy==2)
		{
		pieces[num].posx=fx;
		pieces[num].posy=fy;
		grantenpass(num);
		}
		else
		{
		pieces[num].posx=fx;
		pieces[num].posy=fy;
		}
	}
}
void player::grantenpass(int num)
{
	player *p;
	if(col==15)
	{
		p=pb;
	}
	else
	{
		p=pw;
	}
	p->enpass.can=1;
	p->enpass.dno=num;
	p->enpass.fx=pieces[num].posx;
	p->enpass.fy=pieces[num].posy-fmove;
}
void player::enpassant(int num)
{
	if(enpass.can==1)
	{
		if(pieces[num].posy+fmove==enpass.fy && (pieces[num].posx+1==enpass.fx ||  pieces[num].posx-1==enpass.fx))
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,enpass.fx,enpass.fy,(15-col),enpass.dno,enpass.fx,pieces[num].posy,-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
		}
	}
}
void player::twopawn(int num)
{
	if(pieces[num].fm==1)
	{
		if(board[pieces[num].posx][pieces[num].posy+fmove].playercol==10 && board[pieces[num].posx][pieces[num].posy+fmove+fmove].playercol==10)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,pieces[num].posx,(pieces[num].posy+fmove+fmove),10,-1,-1,-1,-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
		}
	}
	
}
void player::npawn(int num)
{
	if(board[pieces[num].posx][pieces[num].posy+fmove].playercol==10)
	{
		A.addaction(col,num,pieces[num].posx,pieces[num].posy,pieces[num].posx,(pieces[num].posy+fmove),10,-1,-1,-1,-1,-1);
		if(A.seevalid()==1)
		{
			E.addstack(num,&A);
		}
	}
}
void player::cutpawn(int num)
{
	if((pieces[num].posx-1)>=0)
	{
		if(board[pieces[num].posx-1][pieces[num].posy+fmove].playercol!=10 && board[pieces[num].posx-1][pieces[num].posy+fmove].playercol!=col)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,(pieces[num].posx-1),(pieces[num].posy+fmove),(15-col),(board[pieces[num].posx-1][pieces[num].posy+fmove].pnum),(pieces[num].posx-1),(pieces[num].posy+fmove),-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
		}
	}
	if((pieces[num].posx+1)<8)
	{
		if(board[pieces[num].posx+1][pieces[num].posy+fmove].playercol!=10 && board[pieces[num].posx+1][pieces[num].posy+fmove].playercol!=col)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,(pieces[num].posx+1),(pieces[num].posy+fmove),(15-col),(board[pieces[num].posx+1][pieces[num].posy+fmove].pnum),(pieces[num].posx+1),(pieces[num].posy+fmove),-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
		}
	}
}
void player::castling(int num)
{
	if(pieces[num].fm==1)
	{
		int emp7=1,emp0=1;
		int i;
		for(i=pieces[num].posx+1;i<7;i++)
		{
			if(board[i][pieces[num].posy].playercol!=10)
			{
				emp7=0;
			}
		}
		for(i=pieces[num].posx-1;i>0;i--)
		{
			if(board[i][pieces[num].posy].playercol!=10)
			{
				emp0=0;
			}
		}
		if(emp7==1)
		{
			if(E.check(pieces[num].posx+1,pieces[num].posy,col)==0 && E.check(pieces[num].posx,pieces[num].posy,col)==0)
			{
				if(E.check(pieces[num].posx+2,pieces[num].posy,col)==0)
				{
					if(board[7][pieces[num].posy].playercol==col)
					{
						if(gettype(board[7][pieces[num].posy].pnum)=='r')
						{
							if(pieces[board[7][pieces[num].posy].pnum].fm==1)
							{
								A.addaction(col,num,pieces[num].posx,pieces[num].posy,(pieces[num].posx+2),pieces[num].posy,col,(board[7][pieces[num].posy].pnum),7,pieces[num].posy,(pieces[num].posx+1),pieces[num].posy);
								if(A.seevalid()==1)
								{
									E.addstack(num,&A);
								}

							}
						}	
					}
				}
			}
		}
		if(emp0==1)
		{
			if(E.check(pieces[num].posx-1,pieces[num].posy,col)==0 && E.check(pieces[num].posx,pieces[num].posy,col)==0)
			{
				if(E.check(pieces[num].posx-2,pieces[num].posy,col)==0)
				{
					if(board[0][pieces[num].posy].playercol==col)
					{
						if(gettype(board[0][pieces[num].posy].pnum)=='r')
						{
							if(pieces[board[0][pieces[num].posy].pnum].fm==1)
							{
								A.addaction(col,num,pieces[num].posx,pieces[num].posy,(pieces[num].posx-2),pieces[num].posy,col,(board[0][pieces[num].posy].pnum),0,pieces[num].posy,(pieces[num].posx-1),pieces[num].posy);
								if(A.seevalid()==1)
								{
									E.addstack(num,&A);
								}
							}
						}
					}
				}
			}
		}
	}
}
void player::nking(int num)
{
	if((pieces[num].posx+1)<8)
	{
		if(board[pieces[num].posx+1][pieces[num].posy].playercol==10)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,(pieces[num].posx+1),(pieces[num].posy),10,-1,-1,-1,-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
		}
		else if(board[pieces[num].posx+1][pieces[num].posy].playercol!=col)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,(pieces[num].posx+1),(pieces[num].posy),(15-col),board[(pieces[num].posx+1)][(pieces[num].posy)].pnum,(pieces[num].posx+1),(pieces[num].posy),-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
		}
	}
	if((pieces[num].posy+1)<8)
	{
		if(board[pieces[num].posx][pieces[num].posy+1].playercol==10)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,(pieces[num].posx),(pieces[num].posy+1),10,-1,-1,-1,-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
		}
		else if(board[pieces[num].posx][pieces[num].posy+1].playercol!=col)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,(pieces[num].posx),(pieces[num].posy+1),(15-col),board[(pieces[num].posx)][(pieces[num].posy+1)].pnum,(pieces[num].posx),(pieces[num].posy+1),-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
		}
	}
	if((pieces[num].posx-1)>=0)
	{
		if(board[pieces[num].posx-1][pieces[num].posy].playercol==10)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,(pieces[num].posx-1),(pieces[num].posy),10,-1,-1,-1,-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
		}
		else if(board[pieces[num].posx-1][pieces[num].posy].playercol!=col)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,(pieces[num].posx-1),(pieces[num].posy),(15-col),board[(pieces[num].posx-1)][(pieces[num].posy)].pnum,(pieces[num].posx-1),(pieces[num].posy),-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
		}
	}
	if((pieces[num].posy-1)>=0)
	{
		if(board[pieces[num].posx][pieces[num].posy-1].playercol==10)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,(pieces[num].posx),(pieces[num].posy-1),10,-1,-1,-1,-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
		}
		else if(board[pieces[num].posx][pieces[num].posy-1].playercol!=col)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,(pieces[num].posx),(pieces[num].posy-1),(15-col),board[(pieces[num].posx)][(pieces[num].posy-1)].pnum,(pieces[num].posx),(pieces[num].posy-1),-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
		}
	}
	if((pieces[num].posx+1)<8 && (pieces[num].posy+1)<8)
	{
		if(board[pieces[num].posx+1][pieces[num].posy+1].playercol==10)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,(pieces[num].posx+1),(pieces[num].posy+1),10,-1,-1,-1,-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
		}
		else if(board[pieces[num].posx+1][pieces[num].posy+1].playercol!=col)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,(pieces[num].posx+1),(pieces[num].posy+1),(15-col),board[(pieces[num].posx+1)][(pieces[num].posy+1)].pnum,(pieces[num].posx+1),(pieces[num].posy+1),-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
		}
	}
	if((pieces[num].posx+1)<8 && (pieces[num].posy-1)>=0)
	{
		if(board[pieces[num].posx+1][pieces[num].posy-1].playercol==10)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,(pieces[num].posx+1),(pieces[num].posy-1),10,-1,-1,-1,-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
		}
		else if(board[pieces[num].posx+1][pieces[num].posy-1].playercol!=col)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,(pieces[num].posx+1),(pieces[num].posy-1),(15-col),board[(pieces[num].posx+1)][(pieces[num].posy-1)].pnum,(pieces[num].posx+1),(pieces[num].posy-1),-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
		}
	}
	if((pieces[num].posx-1)>=0 && (pieces[num].posy+1)<8)
	{
		if(board[pieces[num].posx-1][pieces[num].posy+1].playercol==10)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,(pieces[num].posx-1),(pieces[num].posy+1),10,-1,-1,-1,-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
		}
		else if(board[pieces[num].posx-1][pieces[num].posy+1].playercol!=col)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,(pieces[num].posx-1),(pieces[num].posy+1),(15-col),board[(pieces[num].posx-1)][(pieces[num].posy+1)].pnum,(pieces[num].posx-1),(pieces[num].posy+1),-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
		}
	}
	if((pieces[num].posx-1)>=0 && (pieces[num].posy-1)>=0)
	{
		if(board[pieces[num].posx-1][pieces[num].posy-1].playercol==10)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,(pieces[num].posx-1),(pieces[num].posy-1),10,-1,-1,-1,-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
		}
		else if(board[pieces[num].posx-1][pieces[num].posy-1].playercol!=col)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,(pieces[num].posx-1),(pieces[num].posy-1),(15-col),board[(pieces[num].posx-1)][(pieces[num].posy-1)].pnum,(pieces[num].posx-1),(pieces[num].posy-1),-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
		}
	}
}
void player::nknight(int num)
{
	if((pieces[num].posx-2)>=0 && (pieces[num].posy-1)>=0)
	{
		if(board[pieces[num].posx-2][pieces[num].posy-1].playercol==10)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,(pieces[num].posx-2),(pieces[num].posy-1),10,-1,-1,-1,-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
		}
		else if(board[pieces[num].posx-2][pieces[num].posy-1].playercol!=col)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,(pieces[num].posx-2),(pieces[num].posy-1),(15-col),board[(pieces[num].posx-2)][(pieces[num].posy-1)].pnum,(pieces[num].posx-2),(pieces[num].posy-1),-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
		}
	}
	if((pieces[num].posx-2)>=0 && (pieces[num].posy+1)<8)
	{
		if(board[pieces[num].posx-2][pieces[num].posy+1].playercol==10)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,(pieces[num].posx-2),(pieces[num].posy+1),10,-1,-1,-1,-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
		}
		else if(board[pieces[num].posx-2][pieces[num].posy+1].playercol!=col)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,(pieces[num].posx-2),(pieces[num].posy+1),(15-col),board[(pieces[num].posx-2)][(pieces[num].posy+1)].pnum,(pieces[num].posx-2),(pieces[num].posy+1),-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
		}
	}
	if((pieces[num].posx+2)<8 && (pieces[num].posy-1)>=0)
	{
		if(board[pieces[num].posx+2][pieces[num].posy-1].playercol==10)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,(pieces[num].posx+2),(pieces[num].posy-1),10,-1,-1,-1,-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
		}
		else if(board[pieces[num].posx+2][pieces[num].posy-1].playercol!=col)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,(pieces[num].posx+2),(pieces[num].posy-1),(15-col),board[(pieces[num].posx+2)][(pieces[num].posy-1)].pnum,(pieces[num].posx+2),(pieces[num].posy-1),-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
		}
	}
	if((pieces[num].posx+2)<8 && (pieces[num].posy+1)<8)
	{
		if(board[pieces[num].posx+2][pieces[num].posy+1].playercol==10)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,(pieces[num].posx+2),(pieces[num].posy+1),10,-1,-1,-1,-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
		}
		else if(board[pieces[num].posx+2][pieces[num].posy+1].playercol!=col)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,(pieces[num].posx+2),(pieces[num].posy+1),(15-col),board[(pieces[num].posx+2)][(pieces[num].posy+1)].pnum,(pieces[num].posx+2),(pieces[num].posy+1),-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
		}
	}
	if((pieces[num].posx-1)>=0 && (pieces[num].posy-2)>=0)
	{
		if(board[pieces[num].posx-1][pieces[num].posy-2].playercol==10)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,(pieces[num].posx-1),(pieces[num].posy-2),10,-1,-1,-1,-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
		}
		else if(board[pieces[num].posx-1][pieces[num].posy-2].playercol!=col)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,(pieces[num].posx-1),(pieces[num].posy-2),(15-col),board[(pieces[num].posx-1)][(pieces[num].posy-2)].pnum,(pieces[num].posx-1),(pieces[num].posy-2),-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
		}
	}
	if((pieces[num].posx+1)<8 && (pieces[num].posy-2)>=0)
	{
		if(board[pieces[num].posx+1][pieces[num].posy-2].playercol==10)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,(pieces[num].posx+1),(pieces[num].posy-2),10,-1,-1,-1,-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
		}
		else if(board[pieces[num].posx+1][pieces[num].posy-2].playercol!=col)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,(pieces[num].posx+1),(pieces[num].posy-2),(15-col),board[(pieces[num].posx+1)][(pieces[num].posy-2)].pnum,(pieces[num].posx+1),(pieces[num].posy-2),-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
		}
	}
	if((pieces[num].posx-1)>=0 && (pieces[num].posy+2)<8)
	{
		if(board[pieces[num].posx-1][pieces[num].posy+2].playercol==10)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,(pieces[num].posx-1),(pieces[num].posy+2),10,-1,-1,-1,-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
		}
		else if(board[pieces[num].posx-1][pieces[num].posy+2].playercol!=col)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,(pieces[num].posx-1),(pieces[num].posy+2),(15-col),board[(pieces[num].posx-1)][(pieces[num].posy+2)].pnum,(pieces[num].posx-1),(pieces[num].posy+2),-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
		}
	}
	if((pieces[num].posx+1)<8 && (pieces[num].posy+2)<8)
	{
		if(board[pieces[num].posx+1][pieces[num].posy+2].playercol==10)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,(pieces[num].posx+1),(pieces[num].posy+2),10,-1,-1,-1,-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
		}
		else if(board[pieces[num].posx+1][pieces[num].posy+2].playercol!=col)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,(pieces[num].posx+1),(pieces[num].posy+2),(15-col),board[(pieces[num].posx+1)][(pieces[num].posy+2)].pnum,(pieces[num].posx+1),(pieces[num].posy+2),-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
		}
	}
}
void player::nrook(int num)
{
	int x,y;
	x=pieces[num].posx+1;
	y=pieces[num].posy;
	while(x<8)
	{
		if(board[x][y].playercol==10)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,x,y,10,-1,-1,-1,-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
		}
		else if(board[x][y].playercol!=col)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,x,y,(15-col),(board[x][y].pnum),x,y,-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
			break;
		}
		else
		{
			break;
		}
		x++;
	}
	x=pieces[num].posx-1;
	y=pieces[num].posy;
	while(x>=0)
	{
		if(board[x][y].playercol==10)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,x,y,10,-1,-1,-1,-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
		}
		else if(board[x][y].playercol!=col)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,x,y,(15-col),(board[x][y].pnum),x,y,-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
			break;
		}
		else
		{
			break;
		}
		x--;
	}
	x=pieces[num].posx;
	y=pieces[num].posy+1;
	while(y<8)
	{
		if(board[x][y].playercol==10)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,x,y,10,-1,-1,-1,-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
		}
		else if(board[x][y].playercol!=col)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,x,y,(15-col),(board[x][y].pnum),x,y,-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
			break;
		}
		else
		{
			break;
		}
		y++;
	}
	x=pieces[num].posx;
	y=pieces[num].posy-1;
	while(y>=0)
	{
		if(board[x][y].playercol==10)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,x,y,10,-1,-1,-1,-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
		}
		else if(board[x][y].playercol!=col)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,x,y,(15-col),(board[x][y].pnum),x,y,-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
			break;
		}
		else
		{
			break;
		}
		y--;
	}
}
void player::nbishop(int num)
{
	int x,y;
	x=pieces[num].posx+1;
	y=pieces[num].posy+1;
	while(x<8&&y<8)
	{
		if(board[x][y].playercol==10)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,x,y,10,-1,-1,-1,-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
		}
		else if(board[x][y].playercol!=col)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,x,y,(15-col),(board[x][y].pnum),x,y,-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
			break;
		}
		else
		{
			break;
		}
		x++;
		y++;
	}
	x=pieces[num].posx-1;
	y=pieces[num].posy-1;
	while(x>=0&&y>=0)
	{
		if(board[x][y].playercol==10)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,x,y,10,-1,-1,-1,-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
		}
		else if(board[x][y].playercol!=col)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,x,y,(15-col),(board[x][y].pnum),x,y,-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
			break;
		}
		else
		{
			break;
		}
		x--;
		y--;
	}
	x=pieces[num].posx-1;
	y=pieces[num].posy+1;
	while(y<8&&x>=0)
	{
		if(board[x][y].playercol==10)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,x,y,10,-1,-1,-1,-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
		}
		else if(board[x][y].playercol!=col)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,x,y,(15-col),(board[x][y].pnum),x,y,-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
			break;
		}
		else
		{
			break;
		}
		y++;
		x--;
	}
	x=pieces[num].posx+1;
	y=pieces[num].posy-1;
	while(y>=0&&x<8)
	{
		if(board[x][y].playercol==10)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,x,y,10,-1,-1,-1,-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
		}
		else if(board[x][y].playercol!=col)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,x,y,(15-col),(board[x][y].pnum),x,y,-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
			break;
		}
		else
		{
			break;
		}
		y--;
		x++;
	}
}
void player::nqueen(int num)
{
	int x,y;
	x=pieces[num].posx+1;
	y=pieces[num].posy;
	while(x<8)
	{
		if(board[x][y].playercol==10)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,x,y,10,-1,-1,-1,-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
		}
		else if(board[x][y].playercol!=col)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,x,y,(15-col),(board[x][y].pnum),x,y,-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
			break;
		}
		else
		{
			break;
		}
		x++;
	}
	x=pieces[num].posx-1;
	y=pieces[num].posy;
	while(x>=0)
	{
		if(board[x][y].playercol==10)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,x,y,10,-1,-1,-1,-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
		}
		else if(board[x][y].playercol!=col)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,x,y,(15-col),(board[x][y].pnum),x,y,-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
			break;
		}
		else
		{
			break;
		}
		x--;
	}
	x=pieces[num].posx;
	y=pieces[num].posy+1;
	while(y<8)
	{
		if(board[x][y].playercol==10)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,x,y,10,-1,-1,-1,-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
		}
		else if(board[x][y].playercol!=col)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,x,y,(15-col),(board[x][y].pnum),x,y,-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
			break;
		}
		else
		{
			break;
		}
		y++;
	}
	x=pieces[num].posx;
	y=pieces[num].posy-1;
	while(y>=0)
	{
		if(board[x][y].playercol==10)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,x,y,10,-1,-1,-1,-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
		}
		else if(board[x][y].playercol!=col)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,x,y,(15-col),(board[x][y].pnum),x,y,-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
			break;
		}
		else
		{
			break;
		}
		y--;
	}
	x=pieces[num].posx+1;
	y=pieces[num].posy+1;
	while(x<8&&y<8)
	{
		if(board[x][y].playercol==10)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,x,y,10,-1,-1,-1,-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
		}
		else if(board[x][y].playercol!=col)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,x,y,(15-col),(board[x][y].pnum),x,y,-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
			break;
		}
		else
		{
			break;
		}
		x++;
		y++;
	}
	x=pieces[num].posx-1;
	y=pieces[num].posy-1;
	while(x>=0&&y>=0)
	{
		if(board[x][y].playercol==10)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,x,y,10,-1,-1,-1,-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
		}
		else if(board[x][y].playercol!=col)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,x,y,(15-col),(board[x][y].pnum),x,y,-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
			break;
		}
		else
		{
			break;
		}
		x--;
		y--;
	}
	x=pieces[num].posx-1;
	y=pieces[num].posy+1;
	while(y<8&&x>=0)
	{
		if(board[x][y].playercol==10)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,x,y,10,-1,-1,-1,-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
		}
		else if(board[x][y].playercol!=col)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,x,y,(15-col),(board[x][y].pnum),x,y,-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
			break;
		}
		else
		{
			break;
		}
		y++;
		x--;
	}
	x=pieces[num].posx+1;
	y=pieces[num].posy-1;
	while(y>=0&&x<8)
	{
		if(board[x][y].playercol==10)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,x,y,10,-1,-1,-1,-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
		}
		else if(board[x][y].playercol!=col)
		{
			A.addaction(col,num,pieces[num].posx,pieces[num].posy,x,y,(15-col),(board[x][y].pnum),x,y,-1,-1);
			if(A.seevalid()==1)
			{
				E.addstack(num,&A);
			}
			break;
		}
		else
		{
			break;
		}
		y--;
		x++;
	}
}
void player::addmoves()
{
	for(int i=0; i<16; i++)
	{
		if(gettype(i)=='m')
		{
			castling(i);
			nking(i);
		}
		else if(gettype(i)=='q')
		{
			nqueen(i);
		}
		else if(gettype(i)=='r')
		{
			nrook(i);
		}
		else if(gettype(i)=='b')
		{
			nbishop(i);
		}
		else if(gettype(i)=='k')
		{
			nknight(i);
		}
		else if(gettype(i)=='p')
		{
			npawn(i);
			twopawn(i);
			enpassant(i);
			cutpawn(i);
		}
		else if(gettype(i)=='n')
		{
		}
	}
}
void player::kplace(int &kx, int &ky)
{
	kx=pieces[0].posx;
	ky=pieces[0].posy;
}