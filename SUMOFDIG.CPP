#include<iostream.h>
#include<conio.h>
void main()
{
 int r,n,sum=0;
 cout<<"\n enter a number\n";
 cin>>n;
// cout<<"\ndigits of given number are\n";
 while(n!=0)
 {
 r=n%10;
// cout<<"\t"<<r;
 sum+=r;
 n=n/10;
 }
 cout<<"\nsum of digits="<<sum;
 getch();
 }