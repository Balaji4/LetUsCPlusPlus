#include<iostream.h>
#include<conio.h>
void main()
{
int i,n,*a,sum=0;
clrscr();
cout<<"How many numbers ?\n";
cin>>n;
//cout<<"\n enter "<<n<<" numbers\n";
for(i=0;i<=n;i++)
{
//cin>>a[i];
sum+=i*i;
}
cout<<"\n sum of squares of given numbers is "<<sum;
getch();
}