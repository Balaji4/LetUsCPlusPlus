#include<stdio.h>
#include<conio.h>

int valid(int [],int);
void sort(int b[],int n)
{
int i,j,temp;
	for(i=1;i<n;i++)
	{
	 for(j=1;j<=n-i;j++)
	 {
		if(b[j-1]>b[j])
		{
		temp=b[j-1];
		b[j-1]=b[j];
		b[j]=temp;
		}
	 }
	}
}
int nq(int n,int start,int rw,int dir)
{
int i,c=start,j,r=rw,k,a[10],flag=0;
clrscr();
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
if(j!=c)
{
gotoxy(2*j+5,r+5);
printf("X");
}
}
gotoxy(2*c+5,r+5);
printf("%d",i);
gotoxy(5,15+i);
printf("r=%d,c=%d",r,c);
a[i-1]=c;
//r++;
r+=dir;
//r=r%n+1;
/*if(r==n)
{
if(c+2>n)
{
//c=0;
c+=n-c;
}
else {
c+=2;
}
}
else */ if(r==((n+1)/2+1))
{
if(c-3<1)
{
c=n+c-3;
}
/*else if(c+3>n)
 {
 c+=n-c+3;
 }     */
else c-=3;
}
else
{
c+=2;
}
if(c>n)
c=c-n;
if(c==0) c=1;
}
flag=valid(a,n);
if(flag==1)
{
printf("\n for this starting column the solution does not exist");
return -1;
}
sort(a,n);
for(j=1;j<=n;j++)
{
if(a[j-1]==a[j])
{
printf("\n for this starting column the solution does not exist");
return -1;
}
}
return c;
}
int valid(int a[],int n)
{
int i,j;
for(i=1;i<n;i++)
{
if(a[i]==a[i-1]||a[i]==a[i-1]+1||a[i]==a[i-1]-1)
{
return 1;
}
}
return 0;
}

void main()
{
int n,i,b[10];
clrscr();
printf("\n enter n\n");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
b[i-1]=nq(n,i,1,1);
getch();
clrscr();
}
/*for(i=1;i<=n;i++)
{
if(b[i-1]==-1)
continue;
else
nq(n,b[i-1],n,-1);
} */

getch();
}

