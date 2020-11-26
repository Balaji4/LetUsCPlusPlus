#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
class blocks
{
int left,right,top,bottom;
public:blocks()
       {
	}
       blocks(int l,int t,int r,int b)
       {
       left=l;
       right=r;
       bottom=b;
       top=t;
       }
       void draw();
};

void main()
{
 /* request auto detection */
int gdriver = DETECT, gmode, errorcode;
//int left, top, right, bottom;

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
int x,y;
x=600;//getmaxx();
y=500;//getmaxy();
blocks b[9];
b[0]=blocks((x / 2-150),(y / 2 - 150),(x / 2 -52),(y / 2 - 52));
b[1]=blocks((x / 2 - 50),(y / 2 - 150),(x / 2 +48),(y / 2 -52));
b[2]=blocks((x / 2 +50),(y / 2 - 150),(x / 2 +148),(y / 2 -52));
b[3]=blocks((x / 2 - 150),(y / 2 - 50),(x / 2 -52),(y / 2 +48));
b[4]=blocks((x / 2 - 50),(y / 2 - 50),(x / 2 + 48),(y / 2 + 48));
b[5]=blocks((x / 2 +50),(y / 2 - 50),(x / 2 +148),(y / 2 +48));
b[6]=blocks((x / 2 - 150),(y / 2 +50),(x / 2 -52),(y / 2 +148));
b[7]=blocks((x / 2 - 50),(y / 2 +50),(x / 2 +48),(y / 2 +148));
b[8]=blocks((x / 2 + 50),(y / 2+50),(x / 2 + 148),(y / 2+148));
b[9]=blocks();
for(int i=0;i<=8;i++)
{
b[i].draw();
}

getch();
closegraph();
}

void blocks::draw()
{

//left = getmaxx() / 2 - 50;
//top = getmaxy() / 2 - 50;
//right = getmaxx() / 2 + 50;
//bottom = getmaxy() / 2 + 50;

/* draw a rectangle */
rectangle(left,top,right,bottom);  //5th rect
/*left=getmaxx() / 2 - 150;
top = getmaxy() / 2 - 50;
right = getmaxx() / 2 -50;
bottom = getmaxy() / 2 +50;
rectangle(left,top,right,bottom); //4th rect

left=getmaxx() / 2 +50;
top = getmaxy() / 2 - 50;
right = getmaxx() / 2 +150;
bottom = getmaxy() / 2 +50;
rectangle(left,top,right,bottom); //6th rect

left=getmaxx() / 2 - 50;
top = getmaxy() / 2 - 150;
right = getmaxx() / 2 +50;
bottom = getmaxy() / 2 -50;
rectangle(left,top,right,bottom);//2nd rect

left=getmaxx() / 2 - 50;
top = getmaxy() / 2 +50;
right = getmaxx() / 2 +50;
bottom = getmaxy() / 2 +150;
rectangle(left,top,right,bottom);//8th rect

left=getmaxx() / 2 - 150;
top = getmaxy() / 2 - 150;
right = getmaxx() / 2 -50;
bottom = getmaxy() / 2 -50;
rectangle(left,top,right,bottom);//1st rect


left=getmaxx() / 2 +50;
top = getmaxy() / 2 - 150;
right = getmaxx() / 2 +150;
bottom = getmaxy() / 2 -50;
rectangle(left,top,right,bottom); //3rd rect

left=getmaxx() / 2 - 150;
top = getmaxy() / 2 +50;
right = getmaxx() / 2 -50;
bottom = getmaxy() / 2 +150;
rectangle(left,top,right,bottom); //7th rect



/* clean up */

//getch();
//closegraph();
}