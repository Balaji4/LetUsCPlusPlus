#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<math.h>

void circledraw(int,int,int,int);
void circlepoints(int,int,int,int,int);

void main()
{
	int r,c,x0,y0;
	int graphdriver=DETECT,graphmode;
	initgraph(&graphdriver,&graphmode,"L:");
	clrscr();

printf("enter centre of circle\n");
scanf("%d %d",&x0,&y0);

printf("enter the value for r\n");
scanf("%d",&r);

	outtextxy(x0,y0,".");

circledraw(x0,y0,r,5);

	getch();
}

void circledraw(int x0,int y0,int rad,int c)
 {
   int x=0;
   float y;
   int r=rad;
   for(x=0;x<r;x++)
   {
	 y=sqrt(r*r-x*x);
	 circlepoints(x0,y0,x,y,c);
  }
 }

 void circlepoints(int x0,int y0,int x,int y, int c)
  {
	putpixel(x0+x,y0+y,c);
	putpixel(x0+y,y0+x,c);
	putpixel(x0+y,y0-x,c);
	putpixel(x0+x,y0-y,c);
	putpixel(x0-x,y0-y,c);
	putpixel(x0-y,y0-x,c);
	putpixel(x0-y,y0+x,c);
	putpixel(x0-x,y0+y,c);
  }