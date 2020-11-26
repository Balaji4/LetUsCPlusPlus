#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
double power(double m,int n=2);
double power(int m,int n=2);
void main()
{
double m,res;
int n,ch;
clrscr();
cout<<"\nMENU \n\n";
cout<<"1:power function with only base element (in int) as argument\n";
cout<<"2:power function with base element(in int) and exponent as argument\n";
cout<<"3:power function with only base element (in double) as argument\n";
cout<<"4:power function with base element(in double) and exponent as argument\n";
cout<<"5:Exit\n";
cout<<"\n enter your choice \n";
cin>>ch;
switch(ch)
{
case 1:cout<<"\n enter the base element\n";
       cin>>m;
       m=(int)m;
       res=power(m);
       break;
case 2:cout<<"\n enter the base element and exponent\n";
       cin>>m>>n;
       m=(int)m;
       res=power(m,n);
       break;
case 3:cout<<"\n enter the base element\n";
       cin>>m;
       res=power(m);
       break;
case 4:cout<<"\n enter the base element and exponent\n";
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
double power(int m,int n)
{
return pow(m,n);
}
