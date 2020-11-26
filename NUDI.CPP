#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
int midx, midy;
int radius = 5;
void ka();
void kha();
int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;

   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error code */
   }

   midx = getmaxx() / 2;
   midy = getmaxy() / 2;
   setcolor(getmaxcolor());
   ka();
//   kha();
   /* draw the circle */

   /* clean up */
   getch();
   closegraph();
   return 0;
}

void ka()
{
circle(midx, midy, radius);
   line(midx-6,midy-6,midx+6,midy-6);
   line(midx,midy-6,midx,midy-12);
   line(midx-6,midy-12,midx+6,midy-12);
   line(midx+6,midy-12,midx+6,midy-14);

}

void kha()
{
int stangle=270,endangle=90;
 circle(midx,midy-5,2);
 circle(midx,midy+5,2);
 arc(midx+1, midy, stangle, endangle,3);
 arc(midx+4, midy,250,20,5);
}