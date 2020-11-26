#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
void circlepoints(int,int,int,int,int);
void mcircle(int x1,int y1,int r,int c)
{
int x=0,y=r,incre=2*x+3,incrse=2*x-2*y+5;
double d=5/4-r;
circlepoints(x1,y1,x,y,c);
while(y>x)
{
if(d<0)
{
d+=2.0*x+3.0;
}
else
{
d+=2.0*(x-y)+5;
y--;
}
x++;
circlepoints(x1,y1,x,y,c);
}
}
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
int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;

   /* initialize graphics mode */
   initgraph(&gdriver, &gmode, "l:");

   /* read result of initialization */
   errorcode = graphresult();

   if (errorcode != grOk)  /* an error occurred */
   {
	  printf("Graphics error: %s\n", grapherrormsg(errorcode));
	  printf("Press any key to halt:");
	  getch();
	  exit(1);             /* return with error code */
   }
   int x,y,r;
  printf("Enter center co-ordinates\n");
 scanf("%d%d",&x,&y);
 printf("Enter radius\n");
 scanf("%d",&r);
 cleardevice();
 mcircle(x,y,r,WHITE);
   getch();
   }