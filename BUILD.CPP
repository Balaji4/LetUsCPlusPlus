#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<stdlib.h>
void createbuild(int ,int ,int ,int);
void createwindow(int,int,int,int);
void roadline(int row);
void roadmid(int row);
void main()
{
int i,j;
clrscr();
createbuild(1,10,1,10);
createwindow(2,9,2,9);
createbuild(4,10,12,22);
createwindow(3,10,14,20);
createbuild(6,10,28,32);
createwindow(7,10,29,31);
roadline(12);
roadmid(16);

roadline(20);
getch();
}





void createbuild(int ir,int fr,int ic,int fc)
{
int i,j;
for(j=ir;j<=fr;j++)
{
for(i=ic;i<=fc;i++)
{
gotoxy(i,j);
textbackground(BLACK);
textcolor(RED);
cprintf("%c",219);
}
}
}

void createwindow(int ir,int fr,int ic,int fc)
{
int r,c;
for(r=ir;r<=fr;r+=2)
{
for(c=ic;c<=fc;c+=2)
{
gotoxy(c,r);
textcolor(BLACK);
cprintf("%c",219);
}
}
}

void roadline(int i)
{
int j;
for(j=1;j<=80;j++)
{
gotoxy(j,i);
textcolor(WHITE);
cprintf("_");
}
}

void roadmid(int i)
{
int j;
for(j=1;j<=80;j+=4)
{
gotoxy(j,i);
textcolor(WHITE);
cprintf("_");
}

}