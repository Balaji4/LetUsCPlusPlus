#include<stdio.h>
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
void ssort(int [],int);
void main()
{
int a[5000],n,i,j,temp,small;
clock_t start,end;
clrscr();
randomize();
n=3000;

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
ssort(a,n);
end=clock();
printf("\n Array after sort \n");
for(i=0;i<n;i++)
{
printf(" %d",a[i]);
}

printf("\ntime required to sort %d elements=%f",n,(end-start)/CLK_TCK);
getch();
}

void ssort(int b[],int n)
{
	for(int i=0;i<n-1;i++)
	{
       int small=i;
	 for(int j=i+1;j<n;j++)
	 {

		if(b[j]<b[small])
		small=j;
	 }
    int	 temp=b[small];
	b[small]=b[i];
	 b[i]=temp;
	}
}