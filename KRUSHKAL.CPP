#include<stdio.h>
#include<conio.h>
#include<iostream.h>
class krush
{
public:int n;
private: int c[10][10];
public:void costadjmat();
void minspantree();
};
void krush::costadjmat()
{
int i,j,u,v;
for(i=0;i<n;i++)
{
 for(j=0;j<n;j++)
 {
 c[i][j]=999;
 }
}
for(i=0;i<n;i++)
{
 for(j=0;j<n;j++)
 {
 cin>>c[i][j];
 }
}

}


int find(int v,int p[])
{
while(p[v]!=v)
v=p[v];
return v;
}

void unionij(int i,int j,int p[])
{
if(i<j)
p[j]=i;
else
p[i]=j;
}

void krush::minspantree()
{
int count,i,p[10],min,j,u,v,k,t[10][2],sum;
count=0;
k=0;
sum=0;
for(i=0;i<n;i++)
p[i]=i;
while(count<n)
{
min=999;
 for(i=0;i<n;i++)
 {
  for(j=0;j<n;j++)
  {
   if(c[i][j]<min)
   {
   min=c[i][j];
   u=i;
   v=j;
   }
  }
 }
 if(min==999)
 break;
 i=find(u,p);
 j=find(v,p);
 if(i!=j)
 {
 t[k][0]=u;
 t[k][1]=v;
 k++;
 count++;
 sum+=min;
 unionij(i,j,p);
}
c[u][v]=c[v][u]=999;
}
if(count==n-1)
{
cout<<"cost of spanning tree="<<sum<<endl;
cout<<"spanning tree is "<<endl;
 for(k=0;k<n-1;k++)
 cout<<t[k][0]<<","<<t[k][1]<<endl;
 return;
}
cout<<"spanning tree does not exist"<<endl;
}


void main()
{
clrscr();
krush k;
cout<<"enter the number of nodes "<<endl;
cin>>k.n;

cout<<" enter the cost adj matrix\n";
k.costadjmat();
k.minspantree();
getch();
}

