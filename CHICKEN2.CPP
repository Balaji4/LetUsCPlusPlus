/* */#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<stdlib.h>
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#include <graphics.h>
union REGS in, out,i,o;
int gd=DETECT,button,x,y;
initmouse()
{
i.x.ax=0;//for initialising mouse.
int86(0x33,&i,&o);
return(o.x.ax);
}

showmouseptr()
{
i.x.ax=1; // for displaying mouse pointer.
int86(0x33,&i,&o);
}

restrictmouseptr(int x1,int y1,int x2,int y2)
{
i.x.ax=7; //to define the upper left boundry of mouse.
i.x.cx=x1;
i.x.dx=x2;
int86(0x33,&i,&o);
i.x.ax=8; //to define the bottom right boundry of mouse.
i.x.cx=y1;
i.x.dx=y2;
int86(0x33,&i,&o);
}

			getmousepos(int *button,int *x, int *y)
			{
			i.x.ax=3; //to move mouse.
			int86(0x33,&i,&o);
			*button=o.x.bx;
			*x=o.x.cx;
			*y=o.x.dx;
			}
void showmouse(void)
{
   asm{
      mov ax,1h
      int 33h
   }
}

void detect ()
{
	while (!kbhit () )
	{
		int x,y;
		in.x.ax = 3;
		int86 (0X33,&in,&out);
		if (out.x.bx == 1)
		{
			x = out.x.cx;
			y = out.x.dx;
			printf ("\nLeft || X - %d  Y - %d", x, y);
		}
		delay (200); // Otherwise due to quick computer response 100s of words will get print
	}
}
void restrict (int x1,int y1,int x2, int y2)
{
	in.x.ax = 7;
	in.x.cx = x1;
	in.x.dx = x2;
	int86 (0X33,&in,&out);
	in.x.ax = 8;
	in.x.cx = y1;
	in.x.dx = y2;
	int86 (0X33,&in,&out);
}
int cc=25,cr=25;
int sc=33,sr=3,ec=33,er=3;
char   getkey()
{
union REGS i,o;
i.h.ah=0;
int86(22,&i,&o);
return(o.h.ah);
}

char ch;

void map();
void shit();
void egg();
void container();
void left();
void right();
void main()
{
clrscr();
int i,j;
 while(!kbhit())
 {
  map();
  container();
  shit();
  egg();
   getmousepos(&button,&x,&y);
  restrictmouseptr(0,getmaxy()-20,getmaxx(),getmaxy()-15);
 }
/*  while(1)
  {
/*   while(!kbhit())

  {
  map();
  container();
  shit();
  egg();
  }*/
  /*	detect();
	showmouse();
	restrict (10,0,250,50); // Change values here to create different mouse movement space.
	detect ();
       //	hide_mouse ();
  ch=getkey();
  switch(ch)
  {
 /* case 'H':clrscr();//printf("UP key\n");
	// shit();
	// egg();
	 break;
  case 'P':clrscr();//printf("Down key\n");
	// shit();
	// egg();
	 break;
  case 'M'://clrscr();
	 right();//printf("RIGHT key\n");
	// shit();
	// egg();
	 break;
  case 'K'://clrscr();
	 left();//printf("Left key\n");
	// shit();
	// egg();
	 break;   */
 // default:exit(0);
 // }
// }  */

}

void map()
{
int i,j;
textcolor(RED);
for(j=3;j<=78;j+=10)
{
gotoxy(j,3);
cprintf("%c",1);

}

for(i=1;i<=80;i++)
{

gotoxy(i,4);
cprintf("%c",219);
}
}

void shit()
{
 if(sr>=25)
 sr=3;
 for(;sr<=25;sr++)
 {
 ls:gotoxy(sc,sr);
 textcolor(YELLOW);
 cprintf("%c",173);
 delay(100);
 clrscr();
 map();
 container();
 if(kbhit())
 {
  ch=getkey();
  if(ch=='M')
  {
  right();
  goto ls;
  }
  else  if(ch=='K')
  {
  left();
  goto ls;
  }
  else
  {
  continue;
  }
  }
 }

}

void egg()
{
if(er>=25)
er=3;

 for(;er<=25;er++)
{
le:gotoxy(ec,er);
textcolor(WHITE);
cprintf("%c",233);
delay(100);
clrscr();
map();
container();
if(kbhit())
 {
 ch=getkey();
 if(ch=='M')
 {
 right();
 goto le;
 }
 else if(ch=='K')
 {
 left();
 goto le;
 }
 else
 {
 continue;

 }
 }
}
}

void container()
{
gotoxy(cc,cr);
printf("%c-%c",16,17);
}

void left()
{
cc--;
if(cc<=1)
cc=1;
container();
}

void right()
{
cc++;
if(cc>78)
cc=78;
container();
}