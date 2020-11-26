#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
void car();
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


   rectangle(0,0, getmaxx(),getmaxy());
   /* draw a rectangle */
   //rectangle(left,top,right,bottom);
   rectangle(200,0,400,getmaxy());
   /* clean up */
   car();

   getch();
   closegraph();
   return 0;
}

void car()
{
rectangle(getmaxx()/2,getmaxy()/2,getmaxx()/2+20,getmaxy()/2+20);
   arc(getmaxx()/2+10,getmaxy()/2,0,180,10);
   arc(getmaxx()/2+10,getmaxy()/2+20,180,360,10);
}