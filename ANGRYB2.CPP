#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
char   getkey()
{
union REGS i,o;
while(!kbhit())
;
i.h.ah=0;
int86(22,&i,&o);
return(o.h.ah);
}

char bird=1,ch;
int br=10,bc=20;
int strn=0;
void map();
void up();
void down();
void right();
void left();
void thrw();
void othbird();
void chkhit(int);
void main()
{
//char ch;
clrscr();
_setcursortype(_NOCURSOR);
textbackground(BLACK);
textcolor(WHITE);
map();
gotoxy(bc,br);
printf("%c",bird);
while(1)
{
ch=getkey();
switch(ch)
{
case 'H':up();//printf("UP key\n");
	 break;
case 'P':down();//printf("Down key\n");
	 break;
case 'M':thrw();//right();//printf("RIGHT key\n");
	 break;
case 'K':left();//printf("Left key\n");
	 break;
//case 'p':thrw();
default:exit(0);//printf("not working \n");
}
}
}




void map()
{
gotoxy(19,10);
printf("(");
gotoxy(21,10);
printf(")");
gotoxy(20,11);
printf("%c",157);
othbird();
}

void up()
{
}
void down()
{
}
void left()
{

   if(bc==20)
   {

   clrscr();
    map();
   bc=18;
   }
   else
   {
   bc--;
   if(bc<=2)
   {
   return;
   }
   else
   {
   clrscr();
 map();
    for(int i=bc+1;i<19;i++)
    {
    gotoxy(i,br);
    printf("_");
    strn++;
    }
   }
   }

 gotoxy(bc,br);
 printf("%c",bird);
}
void right()
{
}

void thrw()
{
clrscr();
map();
 for(int i=bc;i<80;i++)
 {
// clrscr();
// map();
 gotoxy(i,br);
 printf("%c",bird);
 delay(10);
 clrscr();
 map();
 chkhit(i);
 }
 }

void othbird()
{
for(int i=9;i<=20;i++)
{
gotoxy(78,i);
printf("%c",2);
}
}

void chkhit(int i)
{
if(i==78)
{
delay(200);
clrscr();
getch();
exit(0);
}
}
