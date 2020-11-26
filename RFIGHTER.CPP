#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<stdlib.h>
#include<ctype.h>
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
long int speed=1;
//int ospeed=500;
const int carrowlimit=24;
const char car=219;
int cc=36,cr=24;
int rr[5],rc[5];
char getkey();
void map(int j=2);
void roadline(int);
void roadmid(int i,int j);
void colorroad(int,int,int,int);
void carrun();
void carback();
void carright();
void carleft();
void carp(int f=1);
void otrcar();
void dashchk();
void mover();
void build();
void main()
{
clrscr();
char ch;
//int f=1;
randomize();
for(int l=0;l<5;l++)
{
rr[l]=rand()%25;
rc[l]=rand()%45;
 if(rc[l]<31)
 {
 rc[l]=1;
 rc[l]+=32;
 //rc[l]%=45;
 }
}
map();
gotoxy(cc,cr);
textcolor(RED);
cprintf("%c",car);
while(!kbhit)
{
 clrscr();
   carp(2);
   delay(500);
   clrscr();
   carp(1);
   delay(500);
}
while(1)
{
while(!kbhit)
{
 clrscr();
   carp(2);
   delay(500);
   clrscr();
   carp(1);
   delay(500);
}
ch=getch();
 if(!isdigit(ch))
 ch=getkey();
switch(ch)
{
case 'H':carrun();
	 //printf("UP key\n");
	 speed+=10;
	 if(speed>=1000)
	 speed=500;
	 break;
case 'P':carback();//printf("Down key\n");
	 speed-=1;
	 if(speed<=0)
	 speed=1;
	 break;
case 'M':carright();//printf("RIGHT key\n");
	 speed-=1;
	 if(speed<=0)
	 speed=1;
	 break;
case 'K':carleft();//printf("Left key\n");
	 speed-=1;
	 if(speed<=0)
	 speed=1;

	 break;
case 'l':exit(0);

default:exit(0);
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
build();
roadline(46);
colorroad(1,25,31,45);
roadmid(38,j);
otrcar();
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
textbackground(LIGHTGREEN);
textcolor(CYAN);
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

 dashchk();
}

void otrcar()
{
int ocr,occ,i;
 for(i=0;i<5;i++)
 {
  ocr=rr[i];
  occ=rc[i];
  gotoxy(occ,ocr);
  textcolor(YELLOW);
  cprintf("%c",car);
  rr[i]++;
  if(rr[i]==25)
  {
  rr[i]=1;
  rc[i]=rand()%45;
   if(rc[i]<31)
   {
   rc[i]=36;
   }

  }
 }
}

void dashchk()
{
int i,j;
for(i=0,j=0;i<5&&j<5;i++,j++)
{
 if((cr==rr[i])&&(cc==rc[i]))
 {
 mover();
 return;
 }
}
}

void mover()
{
char chg=219;
int i,j;
for(i=cr,j=cc;i<(cr+6),j<((cc+6)%46);j++)
{
clrscr();
map();
gotoxy(j,i);
textcolor(RED);
cprintf("%c",chg);
delay(300);
clrscr();
map();
gotoxy(j,i);
textcolor(BLINK);
cprintf("%c",chg);
delay(300);
}
cc++;
 for(int loop=0;loop<=5;loop++)
 {
  clrscr();
  map();
  gotoxy(j,i);
  textcolor(BLINK);
  cprintf("*");
  delay(200);
 }
}

void build()
{
char bld=178;
for(int i=1;i<=25;i+=2)
{
gotoxy(10,i);
textcolor(RED);
cprintf("%c%c",bld,175);
gotoxy(70,i);
textcolor(RED);
cprintf("%c%c",174,bld);
}

}