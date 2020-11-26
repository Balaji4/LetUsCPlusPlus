#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#define PI 3.14
void circlepoints(int x1,int y1,int x,int y,int c)
{

 putpixel(x1+x,y1-y,c);
 putpixel(x1+x,y1+y,c);
 putpixel(x1+y,y1-x,c);
 putpixel(x1+y,y1+x,c);
 putpixel(x1-x,y1-y,c);
 putpixel(x1-x,y1+y,c);
 putpixel(x1-y,y1-x,c);
 putpixel(x1-y,y1+x,c);
}
void mpcircle(int x1,int y1,int r,int c)
{
 int x=0;
 int y=r;
 double d=1-r;
 int incre=3;
 int incrse=-2*r+5;
 circlepoints(x1,y1,x,y,c);
 while(y>x)
 {
  if(d<0)
  {
   d+=incre;
   incre+=2;
   incrse+=2;
  }
   else
   {
	 d+=incrse;
	 incre+=2;
	 incrse+=4;
	 y--;
   } x++;
	 circlepoints(x1,y1,x,y,c);

  }
 }
 int main()
 {
 int gd=DETECT,gm;
 int x,y,r;
 initgraph(&gd,&gm,"l:");
 printf("Enter center co-ordinates\n");
 scanf("%d%d",&x,&y);
 printf("Enter radius\n");
 scanf("%d",&r);
 cleardevice();
 mpcircle(x,y,r,WHITE);
 getch();
 closegraph();
 return 0;
 }