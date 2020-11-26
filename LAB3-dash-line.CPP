#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>

void LINE(int x0, int y0, int x1, int y1, int c)
{
	int x=x0,y=y0;
	double dy=y1-y0;
	double dx=x1-x0;
	int incre=2*dy;
	int incrne=2*(dy-dx);
	int d=2*dy-dx;
	while(x<x1)
	{
		putpixel(x,ceil(y),c);
		if(d<=0)
		{
			d+=incre;
			x++;

		}
		else
		{
			d+=incrne;
			x++;
			y++;
		}
	}
}
int main()
{
	int a,b,gd=DETECT,gm;
	int x[5],y[5],i,j;
	initgraph(&gd,&gm,"L:");
	printf("Enter x and y \n");
	for(i=0;i<2;i++)
		scanf("%d%d",&x[i],&y[i]);
	cleardevice();
	for(i=x[0];i<=x[1];i+=2)
	{
		a=i+2;
		b=i+2;
		LINE(a-2,b-2,a,b,WHITE);
		i+=4;
	}
	getch();
	closegraph();
	return 0;
}