#include<stdio.h>
#include<conio.h>
void mergesort(int a[],int l,int h);
void merge(int a[],int l,int m,int h);
void main()
{
int a[20],n,i,j,temp;
clrscr();
printf("\n  How many elements \n");
scanf("%d",&n);
printf("\n Enter %d elements \n",n);
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
printf("\n Array before sort \n");
for(i=0;i<n;i++)
{
printf(" %d",a[i]);
}
mergesort(a,0,n-1);
printf("\n Array after sort \n");
for(i=0;i<n;i++)
{
printf(" %d",a[i]);
}
getch();
}

void mergesort(int a[],int l,int h)
{
int m;
 if(l<h)
 {
   m=(l+h)/2;
   mergesort(a,l,m);
   mergesort(a,m+1,h);
   merge(a,l,m,h);
 }
}
void merge(int a[],int l,int m,int h)
{
 int p,i,j,k,b[20];
 p=l;
 i=l;
 j=m+1;
 while(p<=m&&j<=h)
 {
     if(a[p]<=a[j])
     {
      b[i]=a[p];
      p=p+1;
     }
       else
       {
	b[i]=a[j];
	j++;
       }
	i++;
 }
	  if(p>m)
	  {
	  for(k=j;k<=h;k++)
	   {
	    b[i]=a[k];
	    i++;
	   }
	  }
	else
	  {
	   for(k=p;k<=m;k++)
	   {
	   b[i]=a[k];
	   i++;
	   }
	  }
	  for(k=l;k<=h;k++)
	  {
	  a[k]=b[k];
	  }
	  return;
}