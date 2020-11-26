#include<stdio.h>
#include<stdlib.h>

/*
1.array u maintain the list of all visited vertices
2.array prev maintains the immediate parent of each vertex
3.array tag maintains the list of all the vertices that are appended in the spanning tree
4.dist matrix maintains the CURRENT minimum distance of all the vertices from the given source 
5.vertices numbering start with 0
*/

int v,e,s,**d,infinity=999,*dist,*u,*prev,k,*tag;

/*function to find the least cost vertex among all the visited vertices*/
int minimum()
{
int min,i,index=-1;

min=999;

for(i=0;i<v;i++)
{
	if(dist[i]< min && tag[i]!=1)
	{
		min=dist[i];
		index=i;
	}
}

return(index);
}

/*recursive function to update the distance matrix*/
void dijkstra ( int p )
{
	
	int j=0,i,k,m=0,min;


	for(i=0;i<v;i++)
	{
		if(i!=p && tag[i]!=1)
		{
			if(d[p][i] < infinity)
			{
				u[i]=1;
			}
		}
	}

	for(k=0; k < v; k++)
	{
		if(u[k]==1)
		{
			if(dist[p]+d[k][p] < dist[k]) 
			{
				dist[k]=dist[p]+d[k][p];
				prev[k]=p;
			}
		}
	}

	min=minimum();

	if(min!=-1)
	{
	tag[min]=1;

	dijkstra(min);
	}
}


void print()
{
int i=0,j;
for(i=0;i<v;i++)
{	j=i;
	printf("%d<--",i+1);
	while(prev[j]!=-1)
	{	
		printf("%d<--",prev[j]+1);
		j=prev[j];
	}
	printf("=%d\n",dist[i]);
}
}

int main()
{

	int i,j,x,y;

	printf("Enter the number of vertices\n");
	scanf("%d",&v);

	u=(int*) malloc (v*sizeof(int));
	for(i=0;i<v;i++)
	u[i]=-1;


	prev=(int*) malloc (v*sizeof(int));
	for(i=0;i<v;i++)
	prev[i]=-1;


	dist=(int*) malloc (v*sizeof(int));


	tag=(int*) malloc (v*sizeof(int));
	for(i=0;i<v;i++)
	tag[i]=0;

/*adjacency matrix declaration*/
	d = (int**) malloc(v*sizeof(int*));  
		for (i = 0; i < v; i++)  
  			 d[i] = (int*) malloc(v*sizeof(int));  

    /*Initialize matrix*/
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			if(i==j)
			d[i][j]=0;
			else
			d[i][j]=999;
		}
	}
	/*Enter cost for each edge present*/	

	printf("Enter the number of edges\n");
	scanf("%d",&e);
	for(i=0;i<e;i++)
	{
		printf("Enter  edge(u,v)");
		scanf("%d %d",&x,&y);
		printf("Enter its cost\n");
		scanf("%d",&d[x-1][y-1]);
		d[y-1][x-1]=d[x-1][y-1];
	}

/*read cost adjacency matrix*//*
	printf("Enter the adjacency matrix, type 999 for infinity and 0 for d[i][i]\n");
		for(i=0;i<v;i++)
		for(j=0;j<v;j++)
			scanf("%d",&d[i][j]);
/*end read*/

/*print matrix*/
		for(i=0;i<v;i++)
		{
		for(j=0;j<v;j++)
		printf("%d\t",d[i][j]);
		printf("\n");
		}

	printf("Enter the source vertex\n");
	scanf("%d",&s);
	s=s-1;
	/*put source in the spanning tree*/
	tag[s]=1;

/*assign initial  values to vertices in the dist matrix*/
for(i=0;i<v;i++)
{
	if(i!=s)
		dist[i]=999;
	else dist[i]=0;
}

dijkstra(s);

print();
/*
for(i=0;i<v;i++)
printf("%d", dist[i]);
*/
return(0);
}

