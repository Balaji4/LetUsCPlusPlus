#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
void bsort(int [],int);
void main()
{
int a[4000],n,i,j,temp,small;
clock_t start,end;
clrscr();
randomize();
l:n=rand()%4000;
if(n<=1)
{
goto l;
}
for(i=0;i<n;i++)
{
a[i]=rand()%100;
}
/*printf("\n Randomized Array before sort \n");
for(i=0;i<n;i++)
{
printf(" %d",a[i]);
} */
start=clock();
bsort(a,n);
end=clock();
/*printf("\n Array after sort \n");
for(i=0;i<n;i++)
{
printf(" %d",a[i]);
}  */

printf("\ntime required to sort %d elements=%lf",n,(end-start)/CLK_TCK);
getch();
}

void bsort(int b[],int n)
{
	for(int i=1;i<n;i++)
	{
	 for(int j=1;j<=n-i;j++)
	 {
		if(b[j-1]>b[j])
		{
	       int temp=b[j-1];
		b[j-1]=b[j];
		b[j]=temp;
		}
	 }
	}
}