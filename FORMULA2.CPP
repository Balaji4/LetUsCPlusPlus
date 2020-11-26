#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void main()
{
int x,y,ch=244,ch2=233;
clrscr();

printf("\n\t%c\n\t",ch);
ch=179;
printf("%c cos%c d%c = sin%c + c",ch,ch2,ch2,ch2);
ch=245;
printf("\n\t%c",ch);
x=getx();
y=gety();
x++;
y++;
gotoxy(1,1);

getch();
}