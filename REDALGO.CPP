#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int a[10];
void sort(int a[],int b)
{
 int i,j,temp;
 for(i=0;i<b-1;i++)
 {
  for(j=0;j<b-1;j++)
  {
   if(a[j]>a[j+1])
   {
    temp=a[j];
    a[j]=a[j+1];
    a[j+1]=temp;
   }
  }
 }
}



int main()
{
 int b,i,q,p,r,e,j=0,x;
 clrscr();
 printf("enter the total number of packets to be sent to a router:\n");
 scanf("%d",&p);
 printf("enter the buffer size of the router at which RED should take place:\n");
 scanf("%d",&b);
 if(b>=10)
 {
  printf("ERROR");
 }
 else
 {
   while(j<b)
   {
    printf("\ninsert the packet priority: ");
    scanf("%d",&a[j]);
    j++;
   }
   sort(a,b);
   printf("before RED\n");
   for(i=0;i<b;i++)
   {
    printf("%d\t",a[i]);
   }
   for(i=0;i<(p-b);i++)
   {
    printf("\ninsert the packet priority: ");
    scanf("%d",&e);
    r=rand()%b;

    a[r]=e;
    sort(a,b);
    printf("\nafter RED\n");
    for(x=0;x<b;x++)
    {
     printf("%d\t",a[x]);
    }
   }
 }
 getch();
 return 0;
}
