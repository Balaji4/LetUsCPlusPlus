#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
int r,c,a[40];
char ch=1;
int oc=27,or=24;
int hr=24,hc=25;
int check(int);
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
for(i=21;i<=40;i++)
{
a[i]=rand()%50;
}

clrscr();
map();
while(1)
{
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
}
}

void up()
{
int i=oc,j=or,st=-1;
for(;j>(or-10);j--) //move obj up
{
gotoxy(oc,or);
printf("_");
gotoxy(oc,j);
printf("%c",ch);
delay(200);
//st=check(j);
clrscr();
map();

}
/*if(st==-1)
st=or;
else or=st;  */

for(;j<=or;j++) //down
{
st=check(j);
if(st==1)
{
map();
return;
}

gotoxy(oc,or);
printf("_");
gotoxy(oc,j);
printf("%c",ch);
delay(300);
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
for(i=0,j=21;i<20&&j<=40;i++,j++)
{
/*r=rand()%25;
c=rand()%50;   */
r=a[i];
c=a[j];
gotoxy(c,r);
printf("____");
}
}

int check(int k)
{
int i,j;
for(j=21;j<=40;j++)
{
 if(oc==a[j])
 {
   i=(j-21);
    if((a[i]<k))
   {
    return(a[i]);
   }



 }

}
return (-1);
}
