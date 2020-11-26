#include<iostream.h>
#include<conio.h>
int w[100],p[100],v[100][100];
int max(int a,int b)
{
if(a>=b)
return a;
return b;
}
int mfk(int i,int j)
{
int a;
if(v[i][j]<0)
{
if(j<w[i])
a=mfk(i-1,j);
else
a=max(mfk(i-1,j),p[i])+mfk(i-1,j-w[i]);
v[i][j]=a;
}
return v[i][j];
}
void main()
{
int i,j,n,m,profit;
clrscr();
cout<<"enter the no f items\n";
cin>>n;
for(i=1;i<=n;i++)
{
cout<<"enter the weight f item"<<i<<endl;
cin>>w[i];
cout<<"enter the profit of item"<<i<<endl;
cin>>p[i];
}
cout<<"enter the max capacity\n";
cin>>m;
for(i=1;i<=n;i++)
{
for(j=1;j<=m;j++)
v[i][j]=-1;
}
profit=mfk(n,m);
cout<<"max pro="<<profit;
cout<<"items included are\n";
i=n;j=m;
while(i>=0 && j>=0)
{
if(v[i][j]>v[i-1][j])
{
cout<<i;
j=j-w[i];
}
i--;
}
getch();
}
