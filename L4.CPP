#include<iostream.h>
#include<math.h>
#include<conio.h>
void main()
{
	long int n,i,c=0,sum=0,r,x;
	clrscr();
	cout<<"\nEnter a num: ";
	cin>>n;
	x=n;
	while(x!=0)
	{
		c++;
		x=x/10;
	}
	for(i=0;i<c;i++)
	{
		r=n%10;

		sum+=r*pow(2,i);
		n=n/10;
	}
	cout<<"\n"<<sum;
	getch();
}