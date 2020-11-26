#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<iomanip.h>
#include<stdio.h>
#include<stdlib.h>

void inc();
void eat();
void hit();
int pt=0;
int c[4]={33,34,35,36},r[4]={12,12,12,12};
char ch='d',*a="'254''254''254''1'";
char mouse=15;
int rm=12,cm=14;
void main()
{
int i=0;
clrscr();
_setcursortype(_NOCURSOR);
while(1)
{
while(!kbhit())
{
gotoxy(cm,rm);
printf("%c",mouse);
for(i=0;i<4;i++)
{

gotoxy(c[i],r[i]);
printf("%c",a[i]);

}
delay(300);
inc();
hit();
eat();
clrscr();
}
ch=getch();
}

}


void inc()
{
switch(ch)
{
case 'w':r[0]--;
	 r[1]=r[0]-1;
	 r[2]=r[0]-2;
	 r[3]=r[0]-3;
	 c[1]=c[2]=c[3]=c[0];
	 a[3]=1;
	 a[2]=254;
	 a[1]=a[0]=254;

	 break;
case 'a':c[3]--;
	 c[2]=c[3]-1;
	 c[1]=c[3]-2;
	 c[0]=c[3]-3;;
	r[1]=r[2]=r[3]=r[0];
	a[1]=a[2]=a[3]=254;
	 a[0]=1;
	break;
case 'd':c[3]++;
	c[2]=c[3]-1;
	c[1]=c[3]-2;
	c[0]=c[3]-3;
	r[1]=r[2]=r[3]=r[0];
	 a[0]=a[1]=a[2]=254;
	 a[3]=1;
	break;
case 'x':r[0]++;
	 r[1]=r[0]+1;
	 r[2]=r[0]+2;
	 r[3]=r[0]+3;
	 c[1]=c[2]=c[3]=c[0];
	a[0]=a[1]=254;
	a[2]=254;
	a[3]=1;
	break;
case 'l':exit(0);
//default:
	 //c[4]++;
	//break;
}
}

void eat()
{
randomize();
if(r[0]==rm&&c[0]==cm)
{
rm=rand()%25;
cm=rand()%79;
pt++;
}
}

void hit()
{
if(r[0]==3||r[0]==23||c[0]==0||c[0]==78)
{
delay(300);
clrscr();
gotoxy(20,16);
printf("Game over\n ");
printf("\t\t score=%d",pt);
delay(1000);
exit(0);
}

}