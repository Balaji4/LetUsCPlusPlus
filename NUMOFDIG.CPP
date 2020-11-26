#include<iostream.h>
#include<conio.h>
void main()
{
long int n;
 int r,c=0;
 clrscr();
 cout<<"\n enter a number\n";
 cin>>n;
// cout<<"\ndigits of given number are\n";
 do
 {
// r=n%10;
// cout<<"\t"<<r;
 c++;
 n=n/10;
 }while(n!=0);
 cout<<"\n number of digits="<<c;
 getch();
 }