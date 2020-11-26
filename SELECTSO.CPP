#include<stdio.h>
#include<conio.h>
void main()
{
  int a[10],n,i,j,min,t;
  clrscr();
  printf("Enter the number of elements \n");
  scanf("%d",&n);
  printf("Enter the elements to be sorted\n");
  for(i=0;i<n;i++)
  scanf("%d",&a[i]);
  //sorting begins
  for(i=0;i<n-1;i++)
  {
   min=i;
   for(j=i+1;j<n;j++)
   {
    if(a[j]<a[min])
    min=j;
    }
    t=a[i];
    a[i]=a[min];
    a[min]=t;
    }
    printf("The sorted elements are\n");
    for(i=0;i<n;i++)
    printf("%d ",a[i]);
    getch();
    }


