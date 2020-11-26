#include<iostream.h>
#include<conio.h>
void main()
{
int x,i,n;
float sum=1;
clrscr();
cout<<"enter the limit n\n";
cin>>n;
cout<<"\n enter x\n";
cin>>x;
cout<<"sum for the series 1+x/2+x/3+....x/n=";
for(i=2;i<=n;i++)
{
sum+=(float)x/i;
}
cout<<sum;
getch();
}