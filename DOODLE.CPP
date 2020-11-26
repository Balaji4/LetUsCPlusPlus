#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
int r,c,a[40];
char ch=1;
int oc=27,or=24;
int hr=24,hc=25;
void up();
void right();
void left();
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
map();
dir=getch();
switch(dir)
{
case 'w':up();
	 break;
case 'a':left();
	 break;
case 'd':right();
	 break;
default:exit(0);
}
getch();
}

void up()
{
int i=oc,j=or;
for(;j>(or-10);j--)
{
gotoxy(oc,or);
printf("_");
gotoxy(i,j);
printf("%c",ch);
delay(200);
clrscr();
map();
}
for(;j<=or;j++)
{
gotoxy(oc,or);
printf("_");
gotoxy(i,j);
printf("%c",ch);
delay(100);
clrscr();
map();
}
map();
}

void left()
{
}

void right()
{
}

void map()
{
int i,j;
gotoxy(hc,hr);
printf("____");
gotoxy(oc,or);
printf("%c",ch);
for(i=0,j=21;i<20&&j<40;i++,j++)
{
/*r=rand()%25;
c=rand()%50;   */
r=a[i];
c=a[j];
gotoxy(c,r);
printf("____");
}
}
