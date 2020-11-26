#include<stdio.h>
#include<conio.h>
#include<dos.h>
char ch=1;
int loop(int,int);
void dec(int i,int j,int lim);
void inc(int i,int j,int lim);
void main()
{

clrscr();
int i,j;

_setcursortype(_NOCURSOR);
i=loop(0,26);
j=25;
dec(i,j,1);
/*for(j=25;j>=1;j--,i++)
{
clrscr();
gotoxy(i,j);
printf("%c",ch);
delay(100);
} */

i=1;
j=51;
inc(i,j,75);
/*for(j=51,i=1;j<=79;i++,j++)
{
clrscr();
gotoxy(j,i);
printf("%c",ch);
delay(100);
}
i=loop(51,1);  */
clrscr();
i=25;
j=76;
for(;j<=79;j++,i--)
{
clrscr();
gotoxy(j,i);
printf("%c",ch);
delay(100);
}
for(;i>=1;i--,j--)
{
clrscr();
gotoxy(j,i);
printf("%c",ch);
delay(100);
}
j--;
for(;i<=25;i++,j--)
{
clrscr();
gotoxy(j,i);
printf("%c",ch);
delay(100);
}
/*gotoxy(76,25);
printf("%c %d",ch,i);
*/getch();
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

void dec(int i,int j,int lim)
{
for(;j>=lim;i++,j--)
{
clrscr();
gotoxy(i,j);
printf("%c",ch);
delay(100);
}
}

void inc(int i,int j,int lim)
{
for(;j<=lim;i++,j++)
{
clrscr();
gotoxy(j,i);
printf("%c",ch);
delay(100);
}
}