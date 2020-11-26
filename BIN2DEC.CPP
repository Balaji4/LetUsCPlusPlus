#include<iostream.h>
#include<conio.h>
#include<math.h>
void main()
{
long int n;
int d=0,r,i;
clrscr();
cout<<"enter a binary number\n";
cin>>n;

 i=0;
 while(n!=0)
 {
 r=n%10;
 d+=r*pow(2,i);
 i++;
 n=n/10;
 }
 cout<<"\n its equivalent decimal number is "<<d;
 getch();
 }
