#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<dos.h>
int split ( int*, int, int ) ;
void quicksort ( int *, int, int ) ;
void main( )
{
int a[20],i,n;
clock_t start,end;
clrscr();
randomize();
l:n=rand()%10;
if(n<=1)
goto l;
for(i=0;i<n;i++)
{
a[i]=rand()%100;
}
printf("\n Array before sort \n");
for(i=0;i<n;i++)
{
printf(" %d",a[i]);
}
	start=clock();
	quicksort ( a, 0, n-1 ) ;
	delay(200);
	end=clock();
	printf ( "\nArray after sorting:\n") ;
	for ( i = 0; i <n; i++)
		printf ( " %d", a[i]) ;
	printf("\nTime taken to sort %d elements=%lf",n,(end-start)/CLK_TCK);
	getch();
}

void quicksort ( int a[ ], int lower, int upper )
{
	int i;
	if ( upper > lower )
	{
	i = split ( a, lower, upper ) ;
	quicksort ( a, lower, i - 1 ) ;
	quicksort ( a, i + 1, upper ) ;
	}
}

int split ( int a[ ], int lower, int upper )
{
	int i, p, q, t ;
	p = lower + 1 ;
	q = upper ;
	i = a[lower] ;
	while ( q >= p )
	{
	while ( a[p] < i )
	{
	p++ ;
	delay(1);
	}
	while ( a[q] > i )
	q-- ;
	if ( q > p )
	{
	t = a[p] ;
	a[p] = a[q] ;
	a[q] = t ;

	}
	}
	t = a[lower] ;
	a[lower] = a[q] ;
	a[q] = t ;
	return q ;
}