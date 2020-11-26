#include<iostream.h>
#include<stdlib.h>
#include<conio.h>
class dij
{
int n,a[10][10],d[10],p[10];
public:void read();
	void print();
	void optimal(int src,int dest);
};

void dij::optimal(int src,int dest)
{
int i,j,u,v,min;
int s[10];
for(i=0;i<n;i++)
 {
 d[i]=a[src][i];
 s[i]=0;
 p[i]=src;
 }
for(i=1;i<n;i++)
 {
 min=9999;
 u=-1;
 for(j=0;j<n;j++)
 {
  if(s[j]==0)
  {
   if(d[j]<min)
   {
    min=d[j];
    u=j;
   }
  }
 }
 s[u]=1;
 if(u==dest)
 return;
 for(v=0;v<n;v++)
 {
 if(s[v]==0)
  {
  if(d[u]+a[u][v]<d[v])
  {
  d[v]=d[u]+a[u][v];
  p[v]=u;
  }
 }
}
}
}
void dij::read()
{
int i,j;
cout<<"\n Enter the no. of nodes\n";
cin>>n;
cout<<"\n Enter the cost adjacency matrix "<<endl;
for(i=0;i<n;i++)
 {
 for(j=0;j<n;j++)
 {
 cin>>a[i][j];
 }
 }
}

void dij::print()
{
for(int srce=0;srce<n;srce++)
 {
 for(int desti=0;desti<n;desti++)
 {
 optimal(srce,desti);
 if(d[desti]==9999)
 cout<<"\n "<<desti<<" is not reachable from "<<srce<<endl;
 else
 {
 cout<<"\n The shortest path is "<<endl;
 int i=desti;
 while(i!=srce)
 {
 cout<<i<<" <--";
 i=p[i];
 }
 cout<<i<<"="<<d[desti]<<endl;
 }
}
 }
 }

 void main()
 {
 dij a;
 a.read();
 a.print();
 getch();
 }