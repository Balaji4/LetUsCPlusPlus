#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
int tr=24,tc=24;
int or=23,oc=26;
void move();
char   getkey()
{
union REGS i,o;
while(!kbhit())
;
i.h.ah=0;
int86(22,&i,&o);
return(o.h.ah);
}

void right()
{
tc++;
oc++;
clrscr();
gotoxy(oc,or);
printf("%c",1);
gotoxy(tc,tr);
printf("%c%c%c%c%c",219,219,219,219,219);
}
void left()
{
tc--;
oc--;
clrscr();
gotoxy(oc,or);
printf("%c",1);
gotoxy(tc,tr);
printf("%c%c%c%c%c",219,219,219,219,219);
}
void main()
{

char ch;
clrscr();
gotoxy(oc,or);
printf("%c",1);
gotoxy(tc,tr);
printf("%c%c%c%c%c",219,219,219,219,219);
while(1)
{
ch=getkey();
switch(ch)
{
case 'H':move();//printf("UP key\n");
	 break;
case 'P'://printf("Down key\n");
	 break;
case 'M':right();//printf("RIGHT key\n");
	 break;
case 'K':left();//printf("Left key\n");
	 break;
default:exit(0);//printf("not working \n");
}

}

}

void move()
{
int i,j;
for(i=oc,j=or;i>0&&j>0;i--,j--)
{
gotoxy(i,j);
printf("%c",1);
delay(200);
clrscr();
}
}

