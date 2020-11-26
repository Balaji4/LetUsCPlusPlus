#include<iostream.h>
#include<conio.h>

void main()
{
	int a[20],n,i;
	clrscr();
	cout<<"\nEnter a decimal number: ";
	cin>>n;
	i=0;
	while(n>0)
	{
		a[i]=n%2;
		i++;
		n=n/2;

	}
	i--;
	cout<<"\n Its equivalent binary number is\n";
	while(i>=0)
	{
		cout<<a[i];
		i--;

	}
	getch();
}


