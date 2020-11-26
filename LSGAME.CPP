#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
int main(void)
{
int p[16];
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int xmax, ymax;

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
   /*setcolor(RED);
   line(100,100 ,100 ,200 ); //1st ver
   line(200,100,200,200);   //2nd ver
  */ setcolor(BLUE);
 /*  line(120,140,120,240);   //3rd ver dwn
   line(220,140,220,240);    //4th ver dwn
   line(120,140,220,140);    //down 3-4
   line(120,240,220,240);     //up 3-4  */
   p[0]=120;
   p[1]=140;
   p[2]=120;
   p[3]=240;
   p[4]=220;
   p[5]=140;
   p[6]=220;
   p[7]=240;
/*   p[8]=120;
   p[9]=140;
   p[10]=220;
   p[11]=140;
   p[12]=120;
   p[13]=240;
   p[14]=220;
   p[15]=240;*/
   fillpoly(8,p);
   setcolor(RED);
//   line(100,100,120,140); //up cross 1 - 3

 //  line(200,100,220,140); //up cross 2-4
  // line(100,200,120,240); //down cross 1-3
  // line(200,200,220,240);//down cross 2-4
 //  line(100,100,200,100); //up 1-2
  // setcolor(RED);
  // line(100,200,200,200); //down 1-2

   /* clean up */
   getch();
   closegraph();
   return 0;
}

