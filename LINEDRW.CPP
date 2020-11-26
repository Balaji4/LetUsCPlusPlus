#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include<dos.h>
int row[10],col[10];
void drw();
void obj();
int chk(int,int ,int);
int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   char msg[80];

   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
   }
   for(int i=0;i<10;i++)
   {
   row[i]=30+rand()%400;
   col[i]=20+rand()%800;
   }
   /* move the C.P. to location (20, 30) */
   //moveto(20, 30);

   /* create and output a
      message at (20, 30) */
 //  sprintf(msg, " (%d, %d)", getx(), gety());
  // outtextxy(20, 30, msg);

   /* draw a line to (100, 100) */
  // lineto(100, 30);

   /* create and output a message at C.P. */
  // sprintf(msg, " (%d, %d)", getx(), gety());
  // outtext(msg);
   drw();
   obj();
   /* clean up */
   getch();
   closegraph();
   return 0;
}

void drw()
{
for(int i=0;i<10;i++)
{
moveto(col[i],row[i]);
lineto(col[i]+80,row[i]);
}
}

void obj()
{
int  midx = getmaxx() / 2;
int  midy = getmaxy() / 2+180;
int xradius = 10, yradius = 20;
static int rw=0;  /* loop through the fill patterns */
 // for (int i = EMPTY_FILL; i < USER_FILL; i++) {
    /* set fill pattern */
    setfillstyle(CLOSE_DOT_FILL, getmaxcolor());

    /* draw a filled ellipse */
    fillellipse(midx, midy-rw, xradius, yradius);

 // }
 char ch=getch();
 if(ch=='w')
 {
// closegraph();
 for(int j=0;j<5;j++)
 {
 rw+=50;
  cleardevice();
  drw();
 setfillstyle(CLOSE_DOT_FILL, getmaxcolor());
 fillellipse(midx,midy-rw,xradius,yradius);
 delay(300);
  if(chk(midx,midy,rw)==1)
  {
  return;
  }
 }
 for(j=0;j<5;j++)
 {
 rw-=50;
  cleardevice();
  drw();
 setfillstyle(CLOSE_DOT_FILL, getmaxcolor());
 fillellipse(midx,midy-rw,xradius,yradius);
 delay(100);
  if(chk(midx,midy,rw)==1)
  {
  return;
  }
 }

 }
  /* clean up */
 // closegraph();
 // return 0;
}

int chk(int midx,int midy,int rw)
{
for(int i=0;i<10;i++)
{
if(midx==col[i]&&midy-rw==row[i])
{
return 1;
}
else continue;
}
return 0;
}