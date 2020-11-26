#include<iostream.h>
#include<conio.h>
int fib(int);
void main()
{
int i,n;
clrscr();
cout<<"\n How many number of fibonacci series you want?\n";
       cin>>n;
       cout<<"\n fibonacci series upto "<<n<<" numbers is as follows\n";
       for(i=1;i<=n;i++)
       {
	cout<<"\t"<<fib(i);
       }

getch();
}

int fib(int n)
{
if(n==1)
return 0;
else if(n==2)
return 1;
else return(fib(n-1)+fib(n-2));
}