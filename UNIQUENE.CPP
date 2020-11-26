#include<stdio.h>
#include<conio.h>
void main()
{
int a[20],n,i,j,temp;
clrscr();
printf("\n  How many elements \n");
scanf("%d",&n);
printf("\n Enter %d elements \n",n);
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
printf("\n Array before sort \n");
for(i=0;i<n;i++)
{
printf(" %d",a[i]);
}
	for(i=1;i<n;i++)
	{
	 for(j=1;j<=n-i;j++)
	 {
		if(a[j-1]>a[j])
		{
		temp=a[j-1];
		a[j-1]=a[j];
		a[j]=temp;
		}
	 }
	}
printf("\n Array after sort \n");
for(i=0;i<n;i++)
{
printf(" %d",a[i]);
}
for(i=0;i<n-1;i++)
{
if(a[i]==a[i+1])
{
printf(" Element %d repeated \n",a[i]);
break;
}
}
getch();
}