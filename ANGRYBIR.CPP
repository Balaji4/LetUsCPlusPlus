#include<stdio.h>
#include<conio.h>
#include <dos.h>
#include <graphics.h>
int px=25,py=25;
int posX, posY, posKlik;
void bdrag();
union REGS in, out;
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
			cprintf ("\nLeft || X - %d  Y - %d", x, y);
		}
		px=x;
		py=y;
		delay (200); // Otherwise due to quick computer response 100s of words will get print
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
void main()
{
clrscr();
textbackground(BLACK);
textcolor(WHITE);
_setcursortype(_NOCURSOR);
gotoxy(px,py);
printf("%c",1);
show_mouse();
set_mouse();
read_mouse();
gotoxy(posX,posY);
detect ();
bdrag();
cprintf("%d:%d",px,py);

getche();
}

void bdrag()
{
if(px<=195&&py<=28)
{
gotoxy(px,py);
clrscr();
//detect();
printf("%c",1);
//delay(300);
//clrscr();
}
}



