#include<iostream.h>
#include<conio.h>
#include<time.h>
#include<dos.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#define MAX 4
#define MAXI 10
int move[10],move1[10];
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
int R;
public:
  radio()
  {
  R=100;
}
  };
node n[10],m[10];
int cp[10][10],cp1[10][10];
void newheader();
void checkE(radio ra);
node clusterhead();
void newheader1();
void checkE1(radio ra);
node clusterhead1();

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

void randomised_adjmat1()
{
randomize();

for(int i=0;i<MAX;i++)
for(int j=i;j<MAX;j++)
{
if(i!=j)
{
int h=rand()%100;
if(h<75)
m[i].d[j]=h;
else
m[i].d[j]=999;
}
else
m[i].d[j]=0;
}
for(i=1;i<MAX;i++)
for(j=0;j<i;j++)
{
m[i].d[j]=m[j].d[i];
}
for(i=0;i<MAX;i++)
for(j=0;j<MAX;j++)
cp1[i][j]=m[i].d[j];
}

node clusterhead()
{
int l=99.id,j=0;
for(int i=0;i<MAX;i++)
{
printf("%d",n[i].id);
if((n[i].id<l) && (n[i].f==1))
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

node clusterhead1()
{
int j=0;
int l=99;
for(int i=0;i<MAX;i++)
{
if(m[i].id<l && m[i].f==1)
{
l=m[i].id;
j=i;
}
}
strcpy(m[j].des,"CH");
for(i=0;i<MAX;i++)
{
if(i!=j)
strcpy(m[j].des,"CM");
}
printf("Header node is:%d\n",m[j].id);
return m[j];
}


void radiosignal()
{
randomize();
for(int i=0;i<MAX;i++)
{
n[i].r=rand()%150;
}
}

void radiosignal1()
{
randomize();
for(int i=0;i<MAX;i++)
{
m[i].r=rand()%150;
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

void checkEN1(radio ra1)
{
if(g!=0)
{
for(int i=h;i>0;i--)
{
if(m[move1[i]].r<ra1.R && m[move1[i]].f==0){

m[move1[i]].f=1;
printf("the entered node is :%d\n",m[move1[i]].id);
h--;
}
}
}
g=g+1;
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

void checkE1(radio ra1)
{
for(int i=0;i<MAX;i++)
{
if(m[i].r>ra1.R && m[i].f==1)
{
move1[h]=i;
h++;
m[i].f=0;
printf("the left node is :%d\n",m[i].id);
for(int j=0;j<MAX;j++)
m[i].d[j]=0;
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
 //delay(5000);
 
 n[i].f=0;
 node H=clusterhead();
 
}
}
}
}

void newheader1(radio ra1)
{
for(int i=0;i<MAX;i++)
{
if(!strcmp(m[i].des,"CH"))
{
if(m[i].r>ra1.R)
{
 //delay(5000);
 m[i].f=0;
 node H=clusterhead1();
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
//getch();
}
}
else if(head.id==m[i].id)
{
printf("State value of router under %d",m[i].id);
printf("\nNode\tvia node\tdistance\tnumber of hops\n");
for(j=0;j<MAX;j++)
{
if(m[i].id==j)
printf("\n%d\t%d\t%d\n",j+1,arr[i].from[j]+1,arr[i].dist[j]);
else
printf("\n%d\t%d\t\t%d\t\t%d\n",j+1,arr[i].from[j]+1,arr[i].dist[j],hop[i][j]+1);
//getch();
}
}


}
}

int main()
{
int i,j;
char chh;
radio ra,ra1;
clrscr();
//printf("Assigning ID value to nodes randomly between 1 to 10\n");
for(i=0;i<MAX;i++)
{
printf("enter id value for node i");
scanf("%d",&n[i].id);
} 

for(i=0;i<MAX;i++)
{
printf("enter id value for node i");
scanf("%d",&m[i].id);
}

while(chh!='z')
{
randomised_adjmat();
printf("\nFor first cluster head is\n");
node head=clusterhead();
radiosignal();
checkEN(ra);
checkE(ra);
newheader(ra);
getch();
printf("\nFor first cluster head its routing table is \n");
dijsk(cp,head);
getch();
printf("\nFor second cluster head is\n");
randomised_adjmat1();
node head1=clusterhead1();
radiosignal1();
checkEN1(ra1);
checkE1(ra1);
newheader1(ra1);
//printf("\nFor first cluster head is\n");
//printf("\nFor second cluster head is\n");


getch();
printf("\nFor second cluster head its routing table is \n");
dijsk(cp1,head1);
//display();
chh=getch();
}
return 0;
//dijsk();
}