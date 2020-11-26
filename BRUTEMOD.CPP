//brute force approach for major element in an array
#include<stdio.h>
#include<conio.h>
void main()
{
int a[10],j,i,n,index=-1,maxfreq=1,freq=1;
clrscr();

printf("\n Size of array ?\n");
scanf("%d",&n);
printf("\n Enter %d elements \n",n);
 for(i=0;i<n;++i)
 scanf("%d",&a[i]);
 for(i=0;i<n-1;i++)
 {
freq=1;
 for(j=i+1;j<n;j++)
 {
 if(a[i]==a[j])
 {
 freq++;
 index=i;
 }
 }
 if(freq>maxfreq)
 {
 maxfreq=freq;
 }
 }if(index!=-1)
  printf("\n Max count=%d element=%d",maxfreq,a[index]);
  else
  printf("\n No mode exists\n");
  getch();
}

