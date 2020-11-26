#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#define MAX 40

enum{TOP=0X1, BOTTOM=0X2, RIGHT=0X4, LEFT=0X8};
enum{FALSE,TRUE};
typedef unsigned int outcode;
outcode compute(int x,int y,int xmin,int ymin,int xmax,int ymax)
{
 outcode oc=0;
 if(y>ymax)
 oc|=TOP;
 else
 {
 if(y<ymin)
 oc|=BOTTOM;
 }
 if(x>xmax)
 oc|=RIGHT;
 else
 {
 if(x<xmin)
 oc|=LEFT;
 }
 return oc;
 }

void cs(double x1,double y1,double x2,double y2,double xmin,double ymin,double xmax,double ymax)
{
int accept;
int done;
outcode outcode1,outcode2;
accept=FALSE;
done=FALSE;
outcode1=compute(x1,y1,xmin,ymin,xmax,ymax);
outcode2=compute(x2,y2,xmin,ymin,xmax,ymax);
do
{
if(outcode1==0&&outcode2==0)
{
accept=TRUE;
done=TRUE;
}
else if(outcode1&outcode2)
{
done=TRUE;
}
else
{
double x,y;
int outcode_ex;
if(outcode1)
outcode_ex=outcode1;
else
outcode_ex=outcode2;
if(outcode_ex&TOP)
{
x=x1+(x2-x1)*(ymax-y1)/(y2-y1);
y=ymax;
}
else if(outcode_ex&BOTTOM)
{
x=x1+(x2-x1)*(ymin-y1)/(y2-y1);
y=ymin;
}
else if(outcode_ex&RIGHT)
{
y=y1+(y2-y1)*(xmax-x1)/(x2-x1);
x=xmax;
}
else
{
y=y1+(y2-y1)*(xmin-x1)/(x2-x1);
x=xmin;
}
if(outcode_ex==outcode1)
{
x1=x;
y1=y;
outcode1=compute(x1,y1,xmin,ymin,xmax,ymax);
}
else
{
x2=x;
y2=y;
outcode2=compute(x2,y2,xmin,ymin,xmax,ymax);
}
}
}
while(done==FALSE);
if(accept==TRUE)
line(x1,y1,x2,y2);
getch();
}

int main()
{
int n;
int i,j;
int ln[MAX][4];
int clip[4];
int gd=DETECT,gm;
printf("Enter the no of lines to be clipped:\n");
scanf("%d",&n);
printf("Enter the x and y co-ordinates of the line end points:\n");
for(i=0;i<n;i++)
for(j=0;j<4;j++)
scanf("%d",&ln[i][j]);
printf("Enter the x and y co-ordinates of the clip window:\n");
for(i=0;i<4;i++)
scanf("%d",&clip[i]);
initgraph(&gd,&gm,"D:\\bc\\bgi");
rectangle(clip[0],clip[1],clip[2],clip[3]);
for(i=0;i<n;i++)
line(ln[i][0],ln[i][1],ln[i][2],ln[i][3]);
getch();
cleardevice();
rectangle(clip[0],clip[1],clip[2],clip[3]);
for(i=0;i<n;i++)
{
cs(ln[i][0],ln[i][1],ln[i][2],ln[i][3],clip[0],clip[1],clip[2],clip[3]);
getch();
}
closegraph();
return 0;
}

