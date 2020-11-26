#include<conio.h>
#include<fstream.h>
#include<iostream.h>
#include<stdlib.h>
void main()
{
fstream outfile("dcm2.jpg",ios::in|ios::out);
char *p;//[1000];
int i;
clrscr();
for(i=0;i<1000;i++)
{
outfile.get(p[i]);
cout<<p[i];
}
getch();
}