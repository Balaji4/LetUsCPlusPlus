#include<stdio.h>
#include<conio.h>
#include<iostream.h>
class knap
{
int n,m,v[10][10],p[10],w[10];
public:void read();
       void opt();
       void write();
};
void knap::read()
{
cout<<"Enter the number of objects"<<endl;
cin>>n;
cout<<"Enter the weights of the objectd"<<endl;
for(int i=1;i<=n;i++)
cin>>w[i];
cout<<"enter the profits of the objects"<<endl;
for( i=1;i<=n;i++)
cin>>p[i];
cout<<"enter the capacity of knapsack"<<endl;
cin>>m;
}

void knap::write()
{
int i,j,x[10];
cout<<"output is"<<endl;
for(i=0;i<=n;i++)
{
 for(j=0;j<=m;j++)
 {
  cout<<" "<<v[i][j];
 }
 cout<<endl;
}
cout<<"optimal solution is"<<v[n][m]<<endl;
for(i=0;i<n;i++)
{
x[i]=0;
}
i=n;
j=m;
while(i!=0&&j!=0)
{
if(v[i][j]!=v[i-1][j])
 {
 x[i]=1;
 j=j-w[i];
 }
 i=i-1;
 }
 for(i=1;i<=n;i++)
 {
 cout<<"X["<<i<<"]";
 }
 cout<<"=";

 for(i=1;i<=n;i++)
 {
 cout<<" "<<x[i]<<" ";
 }
}
 int max(int a,int b)
 {
 return a>b?a:b;
 }
 void knap::opt()
 {
 for(int i=0;i<=n;i++)
 {
  for(int j=0;j<=m;j++)
  {
  if(i==0||j==0)
   v[i][j]=0;
   else if(j<w[i])
   v[i][j]=v[i-1][j];
   else
   v[i][j]=max(v[i-1][j],v[i-1][j-w[i]]+p[i]);
   }}}


 void main()
{
knap a;
clrscr();
a.read();
a.opt();
a.write();
getch();
}