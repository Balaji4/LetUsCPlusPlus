#include<stdio.h>
#include<conio.h>
void main()
{
int i;
char a[14];
clrscr();
printf("Enter the string\n");
for(i=0;i<5;i++)
{
a[i]=getch();
printf("*");
}
printf("\n");
for(i=0;i<5;i++)
{
printf("%c",a[i]);
}
getch();
}
