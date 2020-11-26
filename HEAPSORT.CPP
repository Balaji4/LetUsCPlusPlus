#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<dos.h>
#include<stdlib.h>
void hsort(int a[],int n);
void constheap(int c[],int n);
int main()
{
int b[40],n,i,j,c,p,temp;
clock_t start,end;
clrscr();
randomize();
l:n=rand()%40;
if(n<=1)
goto l;
for(i=0;i<n;i++)
b[i]=rand()%200;
constheap(b,n);
printf("before sort array is \n");
for(i=0;i<n;i++)
printf(" %d",b[i]);
start=clock();
delay(500);
hsort(b,n);
end=clock();
printf("\nsorted array is \n");
for(i=0;i<n;i++)
printf(" %d",b[i]);
printf("\nTime taken to sort %d elements is %lf",n,(end-start)/CLK_TCK);
getch();
return 0;
}


void constheap(int d[],int n)
{
int c,p,temp;
for(int i=1;i<n;i++)
{
c=i;
do {
p=(c-1)/2;
if(d[p]<d[c])
 {
  temp=d[p];
  d[p]=d[c];
  d[c]=temp;
  }
  c=p;
 }while(c!=0);

 }
}

void hsort(int a[],int n)
{
int j,c,p,temp;
for(j=n-1;j>=0;j--)
{
  temp=a[0];
  a[0]=a[j];
  a[j]=temp;
  p=0;
  do{
  c=2*p+1;
  if((a[c]<a[c+1])&&c<j-1)
  c++;
  if(a[p]<a[c]&&c<j)
   {
    temp=a[p];
    a[p]=a[c];
    a[c]=temp;
   }
   p=c;
  }while(c<j);
}
}