#include<iostream.h>
#include<conio.h>
class graph
{
int n,a[10][10];
public: void dfs(int u,int s[]);
	   void read();
	  int connect();
};

void graph::read()
{
int i,j;
cout<<"\n enter no. of nodes \n";
cin>>n;
cout<<"\n enter cost adjacency matrix\n";
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
 {
 cin>>a[i][j];
 }
}

}

int graph::connect()
{
int i,j,flag,s[10];
for(j=0;j<n;j++)
{
for(i=0;i<n;i++)
s[i]=0;
dfs(j,s);
flag=0;
for(i=0;i<n;i++)
{
if(s[i]==0)
flag=1;
}
if(flag==0)
return 1;
}
return 0;

}

void graph::dfs(int u,int s[])
{
int v;
s[u]=1;
 for(v=0;v<n;v++)
 {
  if(a[u][v]==1&&s[v]==0)
  {
   dfs(v,s);
  }

 }

}


void main()
{
clrscr();
graph a;
a.read();
int flag=a.connect();
if(flag==1)
cout<<"\n the graph is connected\n";
else
cout<<"\n the graph is not connected\n";
getch();
}
