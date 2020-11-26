#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;


   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "");

   /* read result of initialization */
   errorcode = graphresult();
   /* an error occurred */
   if (errorcode != grOk)
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
   }

   setcolor(getmaxcolor());


   /* draw a diagonal line */
   line(100,100 ,100 ,200 ); //1st ver
   line(200,100,200,200);   //2nd ver
   line(120,140,120,240);   //3rd ver dwn
   line(220,140,220,240);   //4th ver dwn
   line(100,100,120,140); //up cross 1 - 3
   line(200,100,220,140); //up cross 2-4
   line(100,200,120,240); //down cross 1-3
   line(200,200,220,240);//down cross 2-4
   line(100,100,200,100); //up 1-2
   line(120,140,220,140); //up 3-4
   line(100,200,200,200); //down 1-2
   line(120,240,220,240);  //down 3-4
   /* clean up */
   getch();
   closegraph();
   return 0;
}

