#include<iostream.h>
#include<conio.h>
#include<stdio.h>
void main()
{
char *s;
int count[10]={0};
clrscr();
cout<<"\n enter a text:\n";
for(int i=0;i<10;i++)
s[i]=getch();
for(i=0;i<10;i++)
{
switch(s[i])
{
 case '1':count[1]++;
	  break;
 case '2':count[2]++;
	  break;
 case '3':count[3]++;
	  break;
 case '4':count[4]++;
	  break;
 case '5':count[5]++;
	  break;
 case '6':count[6]++;
	  break;
 case '7':count[7]++;
	  break;
 case '8':count[8]++;
	  break;
 case '9':count[9]++;
	  break;
 case '0':count[0]++;
	  break;
 }
}

puts(s);
getch();
}



