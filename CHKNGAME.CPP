#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<stdlib.h>
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
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
 }
  while(1)
  {
/*   while(!kbhit())

  {
  map();
  container();
  shit();
  egg();
  }*/

  ch=getkey();
  switch(ch)
  {
  case 'H':clrscr();//printf("UP key\n");
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
	 break;
  default:exit(0);
  }
 }

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