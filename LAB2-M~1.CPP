//2. Program to implement the midpoint line algorithm to generate a line of given slope and thickness.Implement the polyline command using this algorithm as a routine that displays a set of straight lines between ‘n’ input points.For n=1,the routine displays a single point.

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void swap(int *a, int *b)
{
int temp;
temp=*a;
*a=*b;
*b=temp;
}

midp(int x1, int y1, int x2, int y2)
{
int dx, dy, slope, incr, incre, incrne,d;
dx=abs(x2-x1);
dy=abs(y2-y1);
slope=(dy>dx);
if(slope)
  {
  swap(&x1, &y1);
  swap(&x2, &y2);
  swap(&dx, &dy);
  }
d=2*dy-dx;
incre=2*dy;
incrne=2*(dy-dx);
if(x2<x1)
  {
  swap(&x1, &x2);
  swap(&y1, &y2);
  }
if(y2>y1)
  incr=1;
else
 incr=-1;
if(slope)
  putpixel(y1, x1, 15);
else
  putpixel(x1, y1, 15);
while(x1<x2)
     {
	if(d<=0)
	  d+=incre;
	else
	 {
	 d+=incrne;
	 y1+=incr;
	 }
       x1++;
       if(slope)
	 putpixel(y1, x1, 15);
       else
	 putpixel(x1, y1, 15);
    }
}
void main()
{
int gd=DETECT,gm, choice, x[5], y[5], n, i;
clrscr();
printf("enter 1:line\t2:polyline:");
scanf("%d", &choice);
switch(choice)
	{
	case 1: printf("enter the start point(x1, y1):");
		scanf("%d %d", &x[0], &y[0]);
		printf("enter the end point(x2, y2)");
		scanf("%d %d", &x[1], &y[1]);
		initgraph(&gd, &gm, "");
		midp(x[0], y[0], x[1], y[1]);
		break;
	case 2: printf("enter the no of points:");
		scanf("%d", &n);
		for(i=0; i<n ;i++)
		   {
		   printf("enter the coordinates:");
		   scanf("%d %d", &x[i], &y[i]);
		   }
		   gd=DETECT;
		initgraph(&gd, &gm, "");
		  if(n==1)
		   putpixel(x[0], y[0], 15);
		  else
		    {x[n]=x[0]; y[n]=y[0];
		    for(i=0; i<n; i++)
		       midp(x[i], y[i], x[i+1], y[i+1]);
		    }
		  break;

	 default:printf("wrong choice");
	 }
getch();
closegraph();
}
