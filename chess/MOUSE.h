//mouse functions
REGS in,out;
// display mouse at specific position
void showmouse(int posx, int posy)
{
	in.x.ax=1;
	int86(51,&in,&out);
	in.x.ax=4;
	in.x.cx=posx;
	in.x.dx=posy;
	int86(51,&in,&out); 
}
// limits mouse movement
void mouselimit(int x1, int y1, int x2, int y2)
{
	in.x.ax=7;
	in.x.cx=x1;
	in.x.dx=x2;
	int86(51,&in,&out);
	in.x.ax=8;
	in.x.cx=y1;
	in.x.dx=y2;
	int86(51,&in,&out);
}
// hides mouse from screen
void hidemouse()
{
	in.x.ax=1;
	int86(51,&in,&out);
	in.x.ax=2;
	int86(51,&in,&out);
}
// wait till user clicks mouse and get coordinates
void mouseclick(int &x1, int &y1)
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
			hidemouse();
			return;
		}
	}
}