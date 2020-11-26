#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<dos.h>
void sort(int [],int);
int bsearch(int [],int,int,int);
void main()
{
clock_t start,end;
int n,a[20],key,i,r;

randomize();
clrscr();
l:n=rand()%20;
if(n<=1)
{
goto l;
}
for(i=0;i<n;i++)
{
a[i]=rand()%100;
}
printf("\nArray before sort \n");
for(i=0;i<n;i++)
{
printf(" %d",a[i]);
}
sort(a,n);
printf("\nArray after sort \n");
for(i=0;i<n;i++)
{
printf(" %d",a[i]);
}
printf("\nenter key element to be searched\n");
scanf("%d",&key);
start=clock();
r=bsearch(a,0,n-1,key);
delay(200);
end=clock();
if(r==-1)
printf("\n%d not found",key);
else printf("\n%d found in position %d",key,r+1);
printf("\ntime required to execute=%lf",(end-start)/CLK_TCK);
getch();
}

int bsearch(int b[],int low,int high,int k)
{
int mid=(low+high)/2;
if(low<=high)
{
if(k==b[mid])
{
return mid;
}
else if(k<b[mid])
{
high=mid-1;
bsearch(b,low,mid-1,k);
}
else if(k>b[mid])
{
low=mid+1;
bsearch(b,mid+1,high,k);
}
}
else return (-1);

}


void sort(int c[],int n)
{
	for(int i=1;i<n;i++)
	{
	 for(int j=1;j<=n-i;j++)
	 {
		if(c[j-1]>c[j])
		{
	      int temp=c[j-1];
		c[j-1]=c[j];
		c[j]=temp;
		}
	 }
	}
}