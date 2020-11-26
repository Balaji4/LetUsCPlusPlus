#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
double power(double m,int n=2);
void main()
{
double m,res;
int n,ch;
clrscr();
cout<<"\nMENU \n\n";
cout<<"1:power function with only base element as argument\n";
cout<<"2:power function with base element ana exponent as argument\n";
cout<<"3:Exit\n";
cout<<"\n enter your choice \n";
cin>>ch;
switch(ch)
{
case 1:cout<<"\n enter the base element\n";
       cin>>m;
       res=power(m);
       break;
case 2:cout<<"\n enter the base element and exponent\n";
       cin>>m>>n;
       res=power(m,n);
       break;
default:exit(0);
}

cout<<"\nResult="<<res;
getch();
}

double power(double m,int n)
{
return pow(m,n);
}

