#include<iostream.h>
#include<conio.h>
void swap(int &,int &);
void main()
{
int m,n;
clrscr();
cout<<"Enter two numbers \n";
cin>>m>>n;
cout<<"\n Values before swapping are M="<<m<<" N="<<n;
swap(m,n);
cout<<"\n Values after swapping are M="<<m<<" N="<<n;
getch();
}

void swap(int &x,int &y)
{
int temp;
temp=x;
x=y;
y=temp;
}