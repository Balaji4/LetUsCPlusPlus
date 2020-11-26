#include<stdio.h>
#include<stdlib.h>
#include<time.h>

 int n,p[10],w[10],c[10],top;
  
int max(int a,int b)

    {
	 return a>b?a:b;
    }

 int knap(int i,int m)
    {
	  if(i==n) return w[i]>m?0:p[i];

      if(w[i]>m) return knap(i+1,m);

  			if(knap(i+1,m) > knap(i+1,m-w[i])+p[i])    

  			{
  				return knap(i+1,m);
  			}

  			else

  			{
  				c[top]=i;

  				top++;

  				return knap(i+1,m-w[i])+p[i];
  			}
  	  }

 int main()
  {
	int m,max_profit,i;

	clock_t start,end;

	double tt;

    printf("enter the number of the objects\n");

    scanf("%d",&n);

    printf("enter the knapsack capacity\n");

    scanf("%d",&m);

    printf("enter profit followed by weight\n");

     for(i=1;i<=n;i++)

      scanf("%d%d",&p[i],&w[i]);

		start=clock();

       max_profit=knap(1,m);

		end=clock();

	tt=(double)(end-start)/CLOCKS_PER_SEC;

	printf("time required:%f\n",tt);

       printf("max profit=%d",max_profit);

       for(i=0;i<top;i++)

   	printf("%d\t",c[i]);
  }
