#include<stdio.h>
#include<conio.h>
#include <dos.h>
#include <graphics.h>
int posX, posY, posKlik;
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
			printf ("\nLeft || X - %d  Y - %d", x, y);
		}
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
_setcursortype(_NOCURSOR);
show_mouse();
set_mouse();
read_mouse();
gotoxy(posX,posY);
detect ();

getche();
}



