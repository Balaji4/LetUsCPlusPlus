#include<conio.h>
#include<dos.h>
#include<stdio.h>
void main()
{
clrscr();
_setcursortype(_NOCURSOR);
textbackground(BLACK);
int i;
for(i=34;i<=40;i+=1)
{
gotoxy(i,10);
textcolor(BLUE);
cprintf("_");
}
gotoxy(37,10);
textcolor(RED);
//textcolor(BLINK);
cprintf("%c",219);

gotoxy(33,11);
textcolor(BLUE);
cprintf("/_______");
gotoxy(41,11);
textcolor(BLUE);
cprintf("\\");
getch();
}