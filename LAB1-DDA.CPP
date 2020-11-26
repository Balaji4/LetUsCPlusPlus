#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
void Lined(int x0,int y0,int x1,int y1,int c);

int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;

   /* initialize graphics mode */
   initgraph(&gdriver, &gmode, "");

   /* read result of initialization */
   errorcode = graphresult();

   if (errorcode != grOk)  /* an error occurred */
   {
	  printf("Graphics error: %s\n", grapherrormsg(errorcode));
	  printf("Press any key to halt:");
	  getch();
	  exit(1);             /* return with error code */
   }

   /* draw a line */
   Lined(10,10,450,450,15);

   /* clean up */

   getch();
   closegraph();
   return 0;
}
void Lined(int x0,int y0,int x1,int y1,int c)
{
int x;
double dy=y1-y0;
double dx=x1-x0;
double y=y0;
double m=dy/dx;
for(x=x0;x<=x1;x++)
{
putpixel(x,abs(y),c);
y+=m;
}
}