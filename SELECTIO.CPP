#include<stdio.h>
#include<conio.h>
void main()
{
int a[20],n,i,j,temp,small;
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
	for(i=0;i<n-1;i++)
	{
	small=i;
	 for(j=i+1;j<n;j++)
	 {

		if(a[j]<a[small])
		small=j;
	 }
	 temp=a[small];
	a[small]=a[i];
	 a[i]=temp;
	}
printf("\n Array after sort \n");
for(i=0;i<n;i++)
{
printf(" %d",a[i]);
}
getch();
}