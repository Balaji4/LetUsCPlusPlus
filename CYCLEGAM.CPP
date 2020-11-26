#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

int row=10,col=0;
void rotate(char *p1);
void run(int);
void rotate(char *p1);
char   getkey()
{
union REGS i,o;
while(!kbhit())
;
i.h.ah=0;
int86(22,&i,&o);
return(o.h.ah);
}
void map()
{
int i;
for(i=1;i<=80;i++)
{
gotoxy(i,25);
printf("_");
}
}
void moveup()
{
int i,j;
for(i=row;i>(row-10);i--)
{
//gotoxy(col,i);
run(1);
//printf("%c",1);
delay(100);

clrscr();
//map();
}
i--;
for(;i<=row;i++)
{
//gotoxy(col,i);
run(1);
//printf("%c",1);
delay(100);
clrscr();
//map();
}
//gotoxy(col,row);
run(1);
//printf("%c",1);
}

void moveright()
{
clrscr();
//map();
col++;
if(col==80)
col=0;
//gotoxy(col,row);
run(1);
//printf("%c",1);
}

void moveleft()
{
clrscr();
map();
if(col==1)
{
return;
}
col--;
//gotoxy(col,row);
run(1);
//printf("%c",1);
}

void movedown()
{
}


void main()
{
char ch,ob;
clrscr();
_setcursortype(_NOCURSOR);
//map();
//gotoxy(col,row);
run(1);
//printf("%c",1);
while(1)
{
ch=getkey();

//printf("%c",ch);
switch(ch)
{
case 'H':moveup();
	 //printf("UP key\n");
	 break;
case 'P':movedown();//printf("Down key\n");
	 break;
case 'M':moveright();
	 //printf("RIGHT key\n");
	 break;
case 'K':moveleft();//printf("Left key\n");
	 break;
case 'l':exit(0);
default://printf("not working \n");
	exit(0);
}
}
}

//






void run(int inc)
{
char ch1=45,ch2=46,ch3=45,ch4=46;
int i=1,c=col,r=row,j;
for(c=col;c<=col+inc;c++)
{
i=1;
clrscr();
gotoxy(c,r);
printf("          %c%c%c%c",242,22,22,243);
gotoxy(c,r+1);
printf("=====%c%c----%c\n",177,16,182);
gotoxy(c,r+2);
printf("     %c     %c%c     ",92,47,92);
gotoxy(c,r+3);
//rotate(&ch1);
rotate(&ch2);
if(ch4=='|')
{
ch4='.';
}
else if(ch4=='.')
{
ch4='|';
}
printf(" %c%c%c%c  %c%c%c  %c%c%c%c\n",ch2,ch1,ch1,ch2,92,197,47,ch2,ch1,ch1,ch2);
gotoxy(c,r+4);
printf("%c    %c     %c    %c   \n",ch4,ch4,ch4,ch4);
gotoxy(c,r+5);   //r=15
printf(" %c%c%c%c       %c%c%c%c\n",ch2,95,95,ch2,ch2,95,95,ch2);
//gotoxy(c,r+6);
while(i<=80)
{
printf("-");
i++;
}
delay(100);

}

}

void rotate(char *p1)
{
if(*p1=='_'||*p1=='-')
{
*p1='.';
}
else if(*p1=='.')
{
*p1='-';
}
}