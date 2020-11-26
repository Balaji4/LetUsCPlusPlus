#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<graphics.h>
//void dda(int x1,int y1,int x2,int y2);
void swap(float *a,float *b)
{
float temp=*a;
*a=*b;
*b=temp;
}
void swap(int *a,int *b)
{
int temp=*a;
*a=*b;
*b=temp;
}
void main()
{
int gd=DETECT,gm,xs,ys,ch,n,x[10],y[10],dx,dy,xi[20],i,j,k;
float slope[10];
initgraph(&gd,&gm,"");
printf("\n enter no. of poly points\n");
	scanf("%d",&n);
	printf("\n enter coordinates of points\n");
	for(i=0;i<n;i++)
	{
	printf("\n for x%d,y%d",i,i);
	scanf("%d%d",&x[i],&y[i]);
	}
	x[n]=x[0];
	y[n]=y[0];
	cleardevice();
	for(i=0;i<n;i++)
	{
	line(x[i],y[i],x[i+1],y[1+i]);
	}
	for(i=0;i<n;i++)
	{
	 dx=x[i+1]-x[i];
	 dy=y[i+1]-y[i];
	 if(dy==0)
	 slope[i]=1.0;
	 if(dx==0)
	 slope[i]=0.0;
	 if((dy!=0)&&(dx!=0))
	 {
	 slope[i]=(float)dy/dx;
	 }
	}
	for(ys=0;ys<480;ys++) {
		k=0;
		 for(i=0;i<n;i++)
		  {
		   if(((y[i]<=ys)&&(y[i+1]>ys))||((y[i]>ys)&&(y[i+1]<=ys)))
		   {
		   xi[k]=(int)(x[i]+slope[i]*(ys-y[i]));
		   k++;
		   }
		  }
		 for(int j=0;j<k-1;j++)
			  for(i=0;i<k-1;i++)
			  {
			  if(xi[i]>xi[i+1])
				  swap(&xi[i],&x[i+1]);
			   }
		  setcolor(35);
		  for(i=0;i<k;i+=2)
			  {
			  line(xi[i],ys,xi[i+1]+1,ys);
			  getch();
				}
  }

       getch();
	closegraph();
}
/*void dda(int x1,int y1,int x2,int y2)
{
int x=x1,y=y1,incy;
int dx=abs(x2-x1);
int dy=abs(y2-y1);
int slopef=(dy>dx),i=0,j=0;
char text[11];
if(slopef)
{
swap(&x1,&y1);
swap(&x2,&y2);
swap(&dx,&dy);
}
int d=2*dy-dx,e=2*dy,ne=2*(dy-dx);
if(x2<x1)
{
swap(&x1,&x2);
swap(&y1,&y2);
}
if(y2>y1)
{
incy=1;
}
else
{
incy=-1;
}
if(slopef)
{
putpixel(y,x1,WHITE);
sprintf(text,("%d,%d"),y,x1);
outtextxy(y,x1,"*");
outtextxy(y+10,x1,text);
}
else {
putpixel(x1,y,WHITE);
sprintf(text,("%d,%d"),x1,y);
outtextxy(x1,y,"*");
outtextxy(x1+10,y,text);
}//for(x=x1;x<=x2;x++)
x1++;
while(x1<x2)
{
 if(d<=0)
 {
 d+=e;
 }
 else
 {
 d+=ne;
 y+=incy;
 }
 x1++;
 if(slopef)
{
putpixel(y,x1,WHITE);
}
else {
 putpixel(x1,y,WHITE);
 }
}
if(slopef)
{
putpixel(y,x1,WHITE);
sprintf(text,("%d,%d"),x1,y);
outtextxy(y,x1,"*");
outtextxy(y+10,x1,text);
}
else {
 putpixel(x1,y,WHITE);
 sprintf(text,("%d,%d"),x1,y);
 outtextxy(x1,y,"*");
 outtextxy(x1+10,y,text);
 }
} */
/*#define PI 3.142
float start,end;
int can(double theta)
{
if(theta>=start&&theta<=end)
return 1;
return 0;
}
void cir(int,int,int);
void cirp(int,int,int,int);
void main()//5
{
int gd=DETECT,gm;
int x,y,r,ch;
initgraph(&gd,&gm,"");
printf("\n enter x,y,r \n");
scanf("%d%d%d",&x,&y,&r);
printf("\n 1:circle\n2:arc\n3:sector");
scanf("%d",&ch);
cleardevice();
putpixel(x,y,WHITE);
switch(ch)
{
case 1:start=0;
	end=360;
	cir(x,y,r);
	break;
case 2:printf("enter start end\n");
	scanf("%f%f",&start,&end);
	if(start>end)
	{
	swap(&start,&end);
	}
	cir(x,y,r);
	break;
case 3:printf("enter start end\n");
	scanf("%f%f",&start,&end);
	if(start>end)
	{
	swap(&start,&end);
	}
	int xs,ys,xe,ye;
	xs=x+r*cos(start*PI/180);
	ys=y+r*sin(start*PI/180);
	xe=x+r*cos(end*PI/180);
	ye=y-r*sin(end*PI/180);
	line(x,y,xs,ys);
	line(x,y,xe,ye);
	cir(x,y,r);
	break;
	default:break;
	}
	getch();
closegraph();
}
void cir(int x0,int y0,int r)
{
float d=5/4-r;
float e=3,se=-2*r+5;
int y=r,x=0;
while(y>x)
{
if(d<=0)
{
d+=e;
e+=2;
se+=2;
}
else
{
d+=se;
e+=2;
se+=4;
y--;
}
x++;
cirp(x0,y0,x,y);
}

}
/*void cir(int x0,int y0,int r)  //5
{
double y1;
int x1;
for(x1=0;x1<r;x1++)
{
y1=sqrt(r*r-x1*x1);
cirp(x0,y0,x1,y1);
}
} */
/*void cirp(int x0,int y0,int x1,int y1)
{
double theta=atan((double)y1/x1);
theta=(180*theta/PI);
if(can(360-theta))
putpixel(x0+x1,y0+y1,WHITE);
if(can(theta))
putpixel(x0+x1,y0-y1,WHITE);
if(can(180-theta))
putpixel(x0-x1,y0-y1,WHITE);
if(can(180+theta))
putpixel(x0-x1,y0+y1,WHITE);
if(can(90-theta))
putpixel(x0+y1,y0-x1,WHITE);
if(can(270-theta))
putpixel(x0-y1,y0+x1,WHITE);
if(can(270+theta))
putpixel(x0+y1,y0+x1,WHITE);
if(can(90+theta))
putpixel(x0-y1,y0-x1,WHITE);
} */