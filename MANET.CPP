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
int z=0,g=0;
int k=0,h=0;
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
int R1,R2;
public:
  radio()
  {
  R1=100;
  R2=100;
}
  };
node n[10],m[10];
int cp[10][10],cp1[10][10];
void newheader();
//void checkE(radio ra);
node clusterhead(node *a);
void randomised_adjmat(node *a,int p[][10])
{
randomize();

for(int i=0;i<MAX;i++)
for(int j=i;j<MAX;j++)
{
if(i!=j)
{
int k=rand()%100;
if(k<75)
a[i].d[j]=k;
else
a[i].d[j]=999;
}
else
a[i].d[j]=0;
}
for(i=1;i<MAX;i++)
for(j=0;j<i;j++)
{
a[i].d[j]=a[j].d[i];
}
for(i=0;i<MAX;i++)
for(j=0;j<MAX;j++)
p[i][j]=a[i].d[j];
}

node clusterhead(node *a)
{
int l=a[0].id,j;
for(int i=0;i<MAX;i++)
{
if(a[i].id<l && a[i].f==1)
{
l=a[i].id;
j=i;
}
}
printf("\n\t%d\t\n",a[j].id);
strcpy(a[j].des,"CH");
for(i=0;i<MAX;i++)
{
if(i!=j)
strcpy(a[j].des,"CM");
}
printf("Header node is:%d\t %s\n",a[j].id,a[j].des);
return a[j];
}

void radiosignal(node a[])
{
randomize();
for(int i=0;i<MAX;i++)
{
a[i].r=rand()%150;
}
}

void checkEN(radio ra,node *a,int o)
{
if(o==1)
{
if(z!=0)
{
for(int i=k;i>0;i--)
{


if(a[move[i]].r<ra.R1 && a[move[i]].f==0)
{

a[move[i]].f=1;
printf("the entered node is :%d\n",a[move[i]].id);
k--;
}
}
}
z=z+1;
}

else
{
if(g!=0)
{
for(int i=h;i>0;i--)
{


if(a[move[i]].r<ra.R2 && a[move[i]].f==0)
{

a[move[i]].f=1;
printf("the entered node is :%d\n",a[move[i]].id);
h--;
}
}
}
g=g+1;
}
}




void checkE(radio ra,node *a,int s)
{
for(int i=0;i<MAX;i++)
{
if(s==1)
{
if(a[i].r>ra.R1 && a[i].f==1)
{
move[k]=i;
k++;
a[i].f=0;
printf("the left node is :%d\n",a[i].id);
for(int j=0;j<MAX;j++)
a[i].d[j]=0;
}
}
else{
if(a[i].r>ra.R2 && a[i].f==1)
{
move[h]=i;
h++;
a[i].f=0;
printf("the left node is :%d\n",a[i].id);
for(int j=0;j<MAX;j++)
a[i].d[j]=0;
}
}
}
}

void newheader(radio ra,node *a,int s)
{
for(int i=0;i<MAX;i++)
{
if(!strcmp(a[i].des,"CH"))
{
if(s==1)
{
if(a[i].r>ra.R1)
{
 delay(5000);
 if(a[i].r>ra.R1)
 {
 a[i].f=0;
 node H=clusterhead(a);
 }
}
}
else{
if(a[i].r>ra.R2)
{
 delay(5000);
 if(a[i].r>ra.R2)
 {
 a[i].f=0;
 node H=clusterhead(a);
 }
}

}
}
}
}

void display(node *a)
{
for(int i=0;i<MAX;i++)
{
for(int j=0;j<MAX;j++)
{
 printf("%d ",a[i].d[j]);
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
/*for(i=0;i<MAX;i++)
{
printf("enter id value for node i");
scanf("%d",&m[i].id);
}*/

while(chh!='z')
{
randomised_adjmat(n,cp);
//randomised_adjmat(m,cp1);
node head=clusterhead(n);
//node head1=clusterhead(m);
radiosignal(n);
//radiosignal(m);
checkEN(ra,n,1);
//checkEN(ra,m,0);
newheader(ra,n,1);
//newheader(ra,m,0);
checkE(ra,n,1);
//checkE(ra,m,0);
dijsk(cp,head);
//dijsk(cp1,head);
//display(node n);
chh=getch();

}
return 0;
//dijsk();
}