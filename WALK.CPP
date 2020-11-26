#include<stdio.h>
#include<conio.h>
#include<dos.h>
int loop(int,int);
void main()
{

clrscr();
int i,j;
char ch=1;
_setcursortype(_NOCURSOR);
i=loop(0,26);
for(j=25;j>=0;j--,i++)
{
clrscr();
gotoxy(i,j);
printf("%c",ch);
delay(100);
}


getch();
}
int loop(int m,int n)
{
int j;
char ch=1;
for(j=m;j<n;j++)
{
clrscr();
gotoxy(j,j);
printf("%c",ch);
delay(100);
}
return j-1;
}