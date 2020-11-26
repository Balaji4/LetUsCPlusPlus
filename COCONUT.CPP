#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<dos.h>
void cup1();
void cup2();
void cup3();
void main()
{
clrscr();
gotoxy(25,24);
printf("%c",22);
gotoxy(25,25);
printf("o");
delay(1000);
clrscr();
cup1();
cup2();
cup3();
delay(1000);
clrscr();

gotoxy(25,24);
printf("%c",22);
gotoxy(25,25);
printf("o");

getch();
}

void cup1()
{
gotoxy(25,25);
printf("%c",219);
//delay(1000);
//clrscr();
}

void cup2()
{
gotoxy(22,25);
printf("%c",219);
//delay(1000);
//clrscr();
}

void cup3()
{
gotoxy(28,25);
printf("%c",219);
//delay(1000);
//clrscr();
}