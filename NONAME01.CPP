//brute force approach for major element in an array
#include<stdio.h>
#include<conio.h>
void main()
{
int a[10],i,n,count[10];
printf("\n Size of array ?\n");
scanf("%d",&n);
printf("\n Enter %d elements \n");
 for(i=0;i<n;++i)
 scanf("%d",&a[i]);
 for(i=0;i<n;i++)
 {
 for(j=i+1;j<n;j++)
 {
 if(a[i]==a[j])
 count[i]++;
 else count[i]=1;
 }
 }
printf("\n counts\n");
 for(i=0;i<n;i++)
 {
  printf(" %d",count[i]);
  }
}
