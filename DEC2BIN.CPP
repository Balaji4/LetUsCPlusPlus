#include<iostream.h>
#include<conio.h>
 void reverse(int *z,int c);
void main()
{
int n,r,a[20],i,c=0;
clrscr();
cout<<"enter a decimal number\n";
cin>>n;

 i=0;
 while(n!=0)
 {
  r=n%2;
  n=n/2;
 a[i]=r;
 i++;
 c++;
 }
 reverse(a,c);
 cout<<"\n its equivalent binary number is ";
 for(i=0;i<c;i++)
 {
 cout<<a[i];
 }
 getch();
 }

 void reverse(int *z,int c)
 {
 int *q,t;
 q=z+c-1;
 while(q>z)
 {
 t=*z;
 *z=*q;
 *q=t;
 z++;
 q--;
 }
}