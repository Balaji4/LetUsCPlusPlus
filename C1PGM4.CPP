#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include <iostream.h>
int a[50];
void merge(int,int,int);
void merge_sort(int low,int high)
{
 int mid;
 if(low<high)
 {
  mid=(low+high)/2;
  merge_sort(low,mid);
  merge_sort(mid+1,high);
  merge(low,mid,high);
 }
}
void merge(int low,int mid,int high)
{
 int h,i,j,b[50],k;
 h=low;
 i=low;
 j=mid+1;
 while((h<=mid)&&(j<=high))
 {
  if(a[h]<=a[j])
  {
   b[i]=a[h];
   h++;
  }
  else
  {
   b[i]=a[j];
   j++;
  }
  i++;
 }
 if(h>mid)
 {
  for(k=j;k<=high;k++)
  {
   b[i]=a[k];
   i++;
  }
 }
 else
 {
  for(k=h;k<=mid;k++)
  {
   b[i]=a[k];
   i++;
  }
 }
 for(k=low;k<=high;k++) a[k]=b[k];
}
void main()
{
clrscr();
 int n,i;
 clock_t start,end;
 randomize();
 printf("enter n\n");
 scanf("%d",&n);

/* l:num=rand()%40;
 if(num<=1)
 {
 goto l;
 }*/
 for(i=0;i<n;i++)
 {
  a[i]=rand()%1000;
 }
 start=clock();
 merge_sort(0,n);
 end=clock();
 for(i=0;i<n;i++)
 printf("%d  ",a[i]);

 printf("\nTime required to sort %d elements is=%ld",n,(end-start)/CLK_TCK);
 getch();
}





