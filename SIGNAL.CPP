#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include<dos.h>
class lights
{
int xradius,yradius,left,top,right,bottom,color1,color2,color3;
public: lights()
	{
	xradius=15;
	yradius=15;
	left=200;
	right=250;
	bottom=360;
	top=200;
	color1=4;
	color2=14;
	color3=2;
	}
	lights(int w,int x,int y,int z)
	{
	 xradius=15;
	 yradius=15;
	 left=w;
	 right=y;
	 bottom=z;
	 top=x;
	 color1=4;
	 color2=14;
	 color3=2;
	}
	void drawsig(int,int,int);
};
   lights l[4];

void sigexe();
int main(void)
{
  l[0]=lights(50,150,100,310);   //left
   l[1]=lights(550,150,600,310);  //right
   l[2]=lights(300,50,350,210);                         //top
   l[3]=lights(300,300,350,460);                          //bottom
   /* request autodetection */
  int gdriver = DETECT, gmode, errorcode;


  /* initialize graphics and local variables */
  initgraph(&gdriver, &gmode, "");

  /* read result of initialization */
  errorcode = graphresult();
  if (errorcode != grOk) {  /* an error occurred */
    printf("Graphics error: %s\n", grapherrormsg(errorcode));
    printf("Press any key to halt:");
    getch();
    exit(1);          /* terminate with an error code */
  }
  int j=1;
  while(j<=2)
   {
  sigexe();
   j++;
   }


    getch();

  /* clean up */
  closegraph();
  return 0;
}
void sigexe()
{


   for(int i=0;i<4;i++)
   {
   switch(i)
   {
   case 0:l[0].drawsig(0,1,0);
	  l[1].drawsig(1,0,0);
	  l[2].drawsig(1,0,0);
	  l[3].drawsig(1,0,0);
	  sleep(3);
	  l[0].drawsig(0,0,1);
	  l[1].drawsig(1,0,0);
	  l[2].drawsig(1,0,0);
	  l[3].drawsig(1,0,0);
	  sleep(5);
	  continue;
   case 1:l[0].drawsig(1,0,0);
	  l[1].drawsig(1,0,0);
	  l[2].drawsig(0,1,0);
	  l[3].drawsig(1,0,0);
	  sleep(3);
	  l[0].drawsig(1,0,0);
	  l[1].drawsig(1,0,0);
	  l[2].drawsig(0,0,1);
	  l[3].drawsig(1,0,0);
	  sleep(5);
	  continue;
   case 2:l[0].drawsig(1,0,0);
	  l[1].drawsig(0,1,0);
	  l[2].drawsig(1,0,0);
	  l[3].drawsig(1,0,0);
	  sleep(3);
	  l[0].drawsig(1,0,0);
	  l[1].drawsig(0,0,1);
	  l[2].drawsig(1,0,0);
	  l[3].drawsig(1,0,0);
	  sleep(5);
	  continue;
   case 3:l[0].drawsig(1,0,0);
	  l[1].drawsig(1,0,0);
	  l[2].drawsig(1,0,0);
	  l[3].drawsig(0,1,0);
	  sleep(3);
	  l[0].drawsig(1,0,0);
	  l[1].drawsig(1,0,0);
	  l[2].drawsig(1,0,0);
	  l[3].drawsig(0,0,1);
	  sleep(5);
	  continue;

   default:break;
   }
   }

}
void lights::drawsig(int f1,int f2,int f3)
{

     rectangle(left,top,right,bottom);
     setfillstyle(f1,color1);
     fillellipse(left+25,top+25,15,15);
     setfillstyle(f2,color2);
     fillellipse(left+25,top+80,15,15);
     setfillstyle(f3,color3);
     fillellipse(left+25,top+135,15,15);
}

