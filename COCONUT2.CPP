#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
void arc1();
void arc2();
void arc3();
int midx, midy;
int stangle = 0, endangle = 180;
int radius = 20;
int main(void)
{
    /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;


   /* initialize graphics and local
   variables */
   initgraph(&gdriver, &gmode, "");

   /* read result of initialization */
   errorcode = graphresult();
   /* an error occurred */
   if (errorcode != grOk)
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();

      exit(1);    /* terminate with an error code */
   }

   midx = getmaxx() / 2;
   midy = getmaxy() / 2;
   setcolor(getmaxcolor());

   /* draw arc */
   arc1();
   arc2();
   arc3();

   /* clean up */
   getch();
   closegraph();
   return 0;
}

void arc1()
{
 arc(midx-50,midy,stangle,endangle,radius);

}

void arc2()
{
 arc(midx,midy, stangle, endangle, radius);


}

void arc3()
{
 arc(midx+50,midy,stangle, endangle, radius);
}