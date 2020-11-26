#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>

struct edje
{
	int x1,y1,x2,y2,flag;
};

void main()
{
	int gd=DETECT,gm,n,i,j,k;
	struct edje ed[10],temped;
	float dx,dy,m[10],x_int[10],inter_x[10];
	int x[10],y[10],ymax=0,ymin=480,yy,temp;

	printf("Enter the no of vertices in the graph : ");
	scanf("%d",&n);
	printf("Enter the vertices\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&x[i]);
		scanf("%d",&y[i]);
		if(y[i]>ymax)
			ymax=y[i];
		if(y[i]<ymin)
			ymin=y[i];
		ed[i].x1=x[i];
		ed[i].y1=y[i];
	}
	clrscr();
	initgraph(&gd,&gm,"L:");
	cleardevice();
	for(i=0;i<n-1;i++)
	{
		ed[i].x2=ed[i+1].x1;
		ed[i].y2=ed[i+1].y1;
		ed[i].flag=0;
	}
	ed[i].x2=ed[0].x1;
	ed[i].y2=ed[0].y1;
	ed[i].flag=0;
	for(i=0;i<n;i++)
	{
		if(ed[i].y1<ed[i].y2)
		{
			temp=ed[i].x1;
			ed[i].x1=ed[i].x2;
			ed[i].x2=temp;

			temp=ed[i].y1;
			ed[i].y1=ed[i].y2;
			ed[i].y2=temp;
		}
	}
	for(i=0;i<n;i++)
		line(ed[i].x1,ed[i].y1,ed[i].x2,ed[i].y2);
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(ed[j].y1<ed[j+1].y1)
			{
				temped=ed[j];
				ed[j]=ed[j+1];
				ed[j+1]=temped;
			}
			if(ed[j].y1==ed[j+1].y1)
			{
				if(ed[j].y2<ed[j+1].y2)
				{
					temped=ed[j];
					ed[j]=ed[j+1];
					ed[j+1]=temped;
				}
				if(ed[j].y2==ed[j+1].y2)
				{
					if(ed[j].x1<ed[j+1].x1)
					{
						temped=ed[j];
						ed[j]=ed[j+1];
						ed[j+1]=temped;
					}
				}
			}
		}
	}
	for(i=0;i<n;i++)
	{
		dx=ed[i].x2-ed[i].x1;
		dy=ed[i].y2-ed[i].y1;
		if(dy==0)
			m[i]=0;
		else
			m[i]=dx/dy;
		inter_x[i]=ed[i].x1;
	}
	yy=ymax;
	while(yy>ymin)
	{
		for(i=0;i<n;i++)
		{
			if(yy>ed[i].y2&&yy<=ed[i].y1)
				ed[i].flag=1;
			else
				ed[i].flag=0;
		}
		j=0;
		for(i=0;i<n;i++)
		{
			if(ed[i].flag==1)
			{
				x_int[j]=inter_x[i]+(-m[i]);
				inter_x[i]=x_int[j];
				j++;
			}
		}
		for(i=0;i<j;i++)
		{
			for(k=0;k<j-1;k++)
			{
				if(x_int[k]>x_int[k+1])
				{
					temp=x_int[k];
					x_int[k]=x_int[k+1];
					x_int[k+1]=temp;
				}
			}
		}
		for(i=0;i<j;i+=2)
			line(x_int[i],yy,x_int[i+1],yy);
		yy--;
		delay(50);
	}
	getch();
}