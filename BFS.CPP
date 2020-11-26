#include<iostream.h>
#include<conio.h>
class reach
{
int n,s[20],a[20][20],src;
public: void bfs();
	   void read();
	   void print();
};
void reach::read()
{
cout<<"\n enter no. of nodes \n";
cin>>n;
cout<<"\n enter adjacency matrix\n";
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
 {
 cin>>a[i][j];
 }
}
cout<<"enter the source\n";
cin>>src;
}

void reach::print()
{
for(int i=0;i<n;i++)
{

 if(s[i]==0)
  cout<<" vertex "<<i<<" is not reachable\n";
  else
  cout<<" vertex "<<i<<" is reachable\n";
}
}
void reach::bfs()
{
int f,r,q[20],u,v,i;
for(i=1;i<=n;i++)
s[i]=0;
f=r=0;
q[r]=src;
s[src]=1;
while(f<=r)
{
u=q[f++];
for(v=1;v<=n;v++)
{
if(a[u][v]==1&&s[v]==0)
 {
 s[v]=1;
 q[++r]=v;
 }
}

}

}


void main()
{
clrscr();
reach a;
a.read();
a.bfs();
a.print();
getch();
}
