#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<graphics.h>
union REGS in, out;
int r,c,a[40];
char ch=1;
int oc=27,or=24;
int hr=24,hc=25;
int posX, posY, posKlik;
void show_mouse();
void read_mouse();
void set_mouse();
void detect ();
void map();
void main()
{
char dir;
randomize();
for(int i=0;i<20;i++)
{
 a[i]=rand()%25;
}
for(i=21;i<40;i++)
{
a[i]=rand()%50;
}

clrscr();
_setcursortype(_NOCURSOR);
map();

show_mouse();
set_mouse();
read_mouse();
detect ();
gotoxy(posX,posY);
cprintf("%c",1);
clrscr();
map();

getch();
}





void map()
{
int i,j;
for(i=0,j=21;i<20&&j<40;i++,j++)
{
r=a[i];
c=a[j];
gotoxy(c,r);
printf("____");
}
}


void show_mouse(void)
{
   asm{
      mov ax,1h
      int 33h
   }
}

void set_mouse(void)
{
   asm{
      mov ax,4h
      mov cx,0
      mov dx,479
      int 33h
   }
}

void read_mouse(void)
{
   asm{
      mov ax,3h
      int 33h
      mov posX,cx
      mov posY,dx
      mov posKlik,bx
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
			gotoxy(x,y);
			printf("%c",1);
		       //	printf ("\nLeft || X - %d  Y - %d", x, y);
		}
		delay (200); // Otherwise due to quick computer response 100s of words will get print
	}
}


