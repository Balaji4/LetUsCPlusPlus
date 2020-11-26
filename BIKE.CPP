#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int midx, midy;
   int radius = 40;

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

   /* draw the circle */
   circle(midx-200, midy+100, radius);   //tyre left
   circle(midx, midy+100, radius);       //tyre right
   line(midx-150,midy+100,midx-50,midy+100); //bottom
   line(midx-200,midy+50,midx,midy+50);  //top
   arc(midx-200,midy+100,0,180,50); //mud guard left
   arc(midx,midy+100,45,180,50);    //mud guard  right
   /* clean up */
   getch();
   closegraph();
   return 0;
}

