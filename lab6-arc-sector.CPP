#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>
#include<dos.h>


#define PI 3.14

float startangle,endangle;
int x,y;

int Can_draw( float theta )
{
	if( theta >= startangle && theta<= endangle )
		return 1;
	return 0;
}

void Circlepoints(int x,int y,int xc,int yc)
{
	float theta;
	theta = atan( (float)y/x );
	theta = theta * (180/M_PI);

if( Can_draw(theta))
		putpixel(xc+x,yc-y,WHITE);
	if( Can_draw(360-theta))
		putpixel(xc+x,yc+y,WHITE);

if( Can_draw(90-theta))
		putpixel(xc+y,yc-x,WHITE);
	if( Can_draw(270+theta))
		putpixel(xc+y,yc+x,WHITE);

if( Can_draw(180-theta))
		putpixel(xc-x,yc-y,WHITE);
	if( Can_draw(180+theta))
		putpixel(xc-x,yc+y,WHITE);

if( Can_draw(90+theta))
		putpixel(xc-y,yc-x,WHITE);
	if( Can_draw(270-theta))
		putpixel(xc-y,yc+x,WHITE);
}

void MidPointcircle(int xc,int yc,int rad)
{
	float d = (5/4.0) - rad;
	x=0,y=rad;

	while(y>x)
	{
		if(d<0)
			d += 2*x+3;
		else
			d+=(2*x)-(2*y)+5,y--;
		x++;
		Circlepoints(x,y,xc,yc);
//		delay(90);
	}
}
void main()
{
	int gd=DETECT,gm;
	int radius,xc,yc,choice,temp;
	float xstart,ystart,xend,yend;
	initgraph(&gd,&gm,"c:/tc/bgi");
	do
	{
		clrscr();
		cleardevice();
		printf("\n Enter your choice\n");
		printf("\n 1.Draw a Circle\n 2.Draw a Sector\n 3.Draw an Arc\n 4.Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("\n Enter the center:");
				scanf("%d %d",&xc,&yc);
				printf("\n Enter the radius:");
				scanf("%d",&radius);
				cleardevice();
				startangle=0,endangle=360;
				MidPointcircle(xc,yc,radius);
				getch();
				break;

			case 2: printf("\n Enter the center:");
				scanf("%d %d",&xc,&yc);
				printf("\n Enter the radius:");
				scanf("%d",&radius);
				printf("\n Enter the startangle:");
				scanf("%f",&startangle);
				printf("\n Enter the endangle:");
				scanf("%f",&endangle);
				cleardevice();
				if(startangle>endangle)
				{
					temp=startangle;
					startangle=endangle;
					endangle=temp;
				}
				MidPointcircle(xc,yc,radius);
				xstart=xc+radius*cos(PI/180*startangle);
				ystart=yc-radius*sin(PI/180*startangle);
				xend=xc+radius*cos(PI/180*endangle);
				yend=yc-radius*sin(PI/180*endangle);
				line(xc,yc,xstart,ystart);
				line(xc,yc,xend,yend);
				getch();
				break;

			case 3: printf("\n Enter the center:");
				scanf("%d %d",&xc,&yc);
				printf("\n Enter the radius:");
				scanf("%d",&radius);
				printf("\n Enter the startangle:");
				scanf("%f",&startangle);
				printf("\n Enter the endangle:");
				scanf("%f",&endangle);
				cleardevice();
				if(startangle>endangle)
				{
					temp=startangle;
					startangle=endangle;
					endangle=temp;
				}
				MidPointcircle(xc,yc,radius);
				getch();
				break;

			   case 4:  closegraph();
		}
	}while(choice!=4);
}