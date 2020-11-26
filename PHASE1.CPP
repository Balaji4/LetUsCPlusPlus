#include<iostream.h>
#include<conio.h>
#include<time.h>
#include<dos.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#define MAX 5
#define MAXI 10
int move[10];
int z=0;
int k=0;
class node
{
public:
int id;
int f;
int d[10];
int r;
char *des;
public:
node()
{
f=1;
des=(char *)malloc(10);
}
void message(node n,char *s)
{
}
};
struct dist_vect
{
int dist[MAXI];
int from[MAXI];
};
class radio
{
public:
int R;
public:
  radio()
  {
  R=100;
}
  };
node n[10];
int cp[10][10];
void newheader(radio ra);
void checkE(radio ra);
node clusterhead();
void randomised_adjmat()
{
randomize();

for(int i=0;i<MAX;i++)
for(int j=i;j<MAX;j++)
{
if(i!=j)
{
int k=rand()%100;
if(k<75)
n[i].d[j]=k;
else
n[i].d[j]=999;
}
else
n[i].d[j]=0;
}
for(i=1;i<MAX;i++)
for(j=0;j<i;j++)
{
n[i].d[j]=n[j].d[i];
}
for(i=0;i<MAX;i++)
for(j=0;j<MAX;j++)
cp[i][j]=n[i].d[j];
}

node clusterhead()
{
int l=n[0].id,j;
for(int i=0;i<MAX;i++)
{
if(n[i].id<l && n[i].f==1)
{
l=n[i].id;
j=i;
}
}
strcpy(n[j].des,"CH");
for(i=0;i<MAX;i++)
{
if(i!=j)
strcpy(n[j].des,"CM");
}
printf("Header node is:%d\n",n[j].id);
return n[j];
}

void radiosignal()
{
randomize();
for(int i=0;i<MAX;i++)
{
n[i].r=rand()%150;
}
}
void checkEN(radio ra)
{
if(z!=0)
{
for(int i=k;i>0;i--)
{
if(n[move[i]].r<ra.R && n[move[i]].f==0){

n[move[i]].f=1;
printf("the entered node is :%d\n",n[move[i]].id);
k--;
}
}
}
z=z+1;
}

void checkE(radio ra)
{
for(int i=0;i<MAX;i++)
{
if(n[i].r>ra.R && n[i].f==1)
{
move[k]=i;
k++;
n[i].f=0;
printf("the left node is :%d\n",n[i].id);
for(int j=0;j<MAX;j++)
n[i].d[j]=0;
}
}
}

void newheader(radio ra)
{
for(int i=0;i<MAX;i++)
{
if(!strcmp(n[i].des,"CH"))
{
if(n[i].r>ra.R)
{
 delay(5000);
 if(n[i].r>ra.R)
 {
 n[i].f=0;
 node H=clusterhead();
 }
}
}
}
}

void display()
{
for(int i=0;i<MAX;i++)
{
for(int j=0;j<MAX;j++)
{
 printf("%d ",n[i].d[j]);
 }
 printf("\n");
 }
 }
//void headerexchange(
//}

void dijsk(int c[][10],node head)
{
int adj[MAX][MAX],i,j,hop[10][10]={{0}},k,count;
struct dist_vect arr[10];
for(i=0;i<MAX;i++)
{
for(j=0;j<MAX;j++)
adj[i][j]=c[i][j];
}
for(i=0;i<MAX;i++)
{
for(j=0;j<MAX;j++)
{
arr[i].dist[j]=adj[i][j];
arr[i].from[j]=j;
}
}
count=0;
for(i=0;i<MAX;i++)
{
for(j=0;j<MAX;j++)
{
for(k=0;k<MAX;k++)
{
if(arr[i].dist[j]>adj[i][k]+arr[k].dist[j])
{
arr[i].dist[j]=adj[i][k]+arr[k].dist[j];
arr[i].from[j]=k;
count++;
if(count==0)hop[i][j]=1;
else hop[i][j]=count+hop[k][j];
}
}
count=0;
}
}
for(i=0;i<MAX;i++)
{
if(head.id==n[i].id)
{
printf("State value of router under %d",n[i].id);
printf("\nNode\tvia node\tdistance\tnumber of hops\n");
for(j=0;j<MAX;j++)
{
if(n[i].id==j)
printf("\n%d\t%d\t%d\n",j+1,arr[i].from[j]+1,arr[i].dist[j]);
else
printf("\n%d\t%d\t\t%d\t\t%d\n",j+1,arr[i].from[j]+1,arr[i].dist[j],hop[i][j]+1);
getch();
}
}
}
}

int main()
{
int i,j;
char chh;
radio ra;
clrscr();
//printf("Assigning ID value to nodes randomly between 1 to 10\n");
for(i=0;i<MAX;i++)
{
printf("enter id value for node i");
scanf("%d",&n[i].id);
}


while(chh!='z')
{
randomised_adjmat();
node head=clusterhead();
radiosignal();
checkEN(ra);
newheader(ra);
checkE(ra);
dijsk(cp,head);
//display(node n);
chh=getch();

}
return 0;
//dijsk();
}