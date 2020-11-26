#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void main()
{
int n,m,i,k,*a;
clrscr();
printf("enter the n and m\n");
scanf("%d %d",&n,&m);
k=(n/m);
randomize();
for(i=0;i<n;i++)
{
l:int s=rand()%n;
int j=0;
while(j<i)
{
if(s==a[j])
goto l;
j++;
}
if(j==i)
a[i]=s;
}
i=0;
printf("The groups are as follows\n");
int h=n%m;
while(i<(n-h))
{
printf("(");
int c=0;
while(c!=m)
{
printf("%d,",a[i]);
c++;
i++;
}
printf(")\n");
}
int p=0;
if(h!=0)
{
printf("(");
while(p<h)
{
printf("%d,",a[i]);
i++;
p++;
}
printf(")\n");
}
getch();
}






