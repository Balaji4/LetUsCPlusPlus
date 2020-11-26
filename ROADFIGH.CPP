#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<stdlib.h>
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
const int carrowlimit=24;
const char car=219;
int cc=36,cr=24;
char  getkey();
void map(int j=1);
void roadline(int);
void roadmid(int i,int j);
void colorroad(int,int,int,int);
void carrun();
void carback();
void carright();
void carleft();
void carp(int f=1);
void main()
{
clrscr();
char ch;
int f=1;
map();
gotoxy(cc,cr);
textcolor(RED);
cprintf("%c",car);
while(1)
{
 while(!kbhit)
 {
  if(f==1)
   {
    carp();
    f=2;
    delay(100);
    clrscr();
   }
  else
  {
   carp(1);
   f=1;
   delay(1000);
   clrscr();
  }
 }
 ch=getkey();
switch(ch)
{
case 'H':carrun();
	 //printf("UP key\n");
	 break;
case 'P':carback();//printf("Down key\n");
	 break;
case 'M':carright();//printf("RIGHT key\n");
	 break;
case 'K':carleft();//printf("Left key\n");
	 break;
default:exit(0);//printf("not working \n");
}
}
}

char   getkey()
{
union REGS i,o;
while(!kbhit())
;
i.h.ah=0;
int86(22,&i,&o);
return(o.h.ah);
}

void map(int j)
{
roadline(30);

roadline(46);
colorroad(1,25,31,45);
roadmid(38,j);

}
void roadline(int i)
{
int j;
for(j=1;j<=25;j++)
{
gotoxy(i,j);
textcolor(BLACK);
cprintf("%c",179);
}
}

void roadmid(int i,int j)
{
//int j;
for(;j<=25;j+=3)
{
gotoxy(i,j);
textcolor(BLACK);
cprintf("%c",179);
}

}


void colorroad(int ir,int fr,int ic,int fc)
{
int i,j;
for(j=ir;j<=fr;j++)
{
for(i=ic;i<=fc;i++)
{
gotoxy(i,j);
textbackground(LIGHTGRAY);
textcolor(GREEN);
cprintf("%c",219);
}
}
}

void carleft()
{
 if((cc-1)==30)
 {
 carp();
 return;
 }
 else
 {
  cc--;
  carp();
 }
}
void carright()
{
 if((cc+1)==46)
 {
 carp();
 return;
 }
 else
 {
 cc++;
 carp();
 }
}

void carback()
{
 if((cr+1)==24)
 {
 return;
 }
 else
  {
   cr++;
   carp();
  }
}

void carrun()
{
 static int count=0;
 if((cr-1)==16)
 {
 count++;
 if(count%2==0)
  {
  carp(2);
  return;
  }
  else
  {
  carp();
  return;
  }
 }
 else
 {
 cr--;
  count++;
  if(count%2==0)
  {
  carp(2);
  return;
  }
  else
  {
  carp();
  return;
  }
 }
}

void carp(int f)
{
 clrscr();
 map(f);
 gotoxy(cc,cr);
 textcolor(RED);
 cprintf("%c",car);
}