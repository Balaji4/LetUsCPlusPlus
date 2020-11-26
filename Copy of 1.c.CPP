#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
void sort(int [],int);
int lsearch(int [],int,int);
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
printf("\nRandomized array elements \n");
for(i=0;i<n;i++)
{
printf(" %d",a[i]);
}
printf("\nenter key element to be searched\n");
scanf("%d",&key);
start=clock();
r=lsearch(a,n-1,key);
end=clock();
if(r==-1)
printf("\n%d not found",key);
else printf("\n%d found in position %d",key,r+1);
printf("\ntime required to execute=%ld",(end-start)/CLK_TCK);
getch();
}

int lsearch(int b[],int n,int k)
{
if(n>=0)
{
 if(k==b[n])
 {
 return n;
 }
 else
 {
 n--;
 lsearch(b,n,k);
 }
}
else return (-1);

}


