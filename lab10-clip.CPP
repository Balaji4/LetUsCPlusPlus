#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>

//make sure its typedef

typedef unsigned int outcode;

//check the enum syntax properly

enum {top=0x1, bottom=0x2,right=0x4,left=0x8};

outcode compo(double x,double y,double xmin,double ymin,double xmax,double ymax)
{

outcode code=0;

	if(x>xmax)
	{
	  code|=right;
	}
       else if(x<xmin)
       {
	code|=left;
       }

       if(y>ymax)
       {
	  code|=top;
       }
       else if(y<ymin)
       {
	   code|=bottom;
       }

       return code;
 }



 void cslc(double x0,double y0,double x1,double y1,double xmin,double ymin, double xmax,double ymax)
 {

 outcode o0,o1,oout;

 o0=compo(x0,y0,xmin,ymin,xmax,ymax);
 o1=compo(x1,y1,xmin,ymin,xmax,ymax);
 int accept=0,done=0;
 do
 {

  //trival
     if(!(o0|o1))
     {

     accept=1;
     done=1;
     }
     //basic elimination  trivially reject
     else if(o0 & o1)
     {
	done=1;
     }

    else
    {

       double x,y;
       oout=o0?o0:o1;

       if(oout & top)
       {
	 x=x0 + (ymax-y0) * (x1-x0)/(y1-y0);     //for x in num x0+ y's and slope
	 y=ymax;
       }

     else if(oout & bottom)
       {
	 x=x0 + (ymin-y0) * (x1-x0)/(y1-y0);
	 y=ymin;
       }


 else if(oout & right)
       {
	 x=xmax;
	 y=y0 + (xmax-x0)*(y1-y0)/(x1-x0);
       }

  else  if(oout & left)
       {
	 x=xmin;
	 y=y0 + (xmin-x0)*(y1-y0)/(x1-x0);
       }

  if(oout ==o0)
  {
  x0=x;
  y0=y;
  o0=compo(x0,y0,xmin,ymin,xmax,ymax);
 }

  else
  {
  x1=x;
  y1=y;
   o1=compo(x1,y1,xmin,ymin,xmax,ymax);

  }
  }

	}while(done==0);

	//make sure to write below stmt

	if(accept==1)
	line(x0,y0,x1,y1);


 }

     void main()
     {

     int gd=DETECT,gm,ec;

     initgraph(&gd,&gm,"c:\\tc\\bgi\\");

     ec=graphresult();
     if(ec!=grOk)  //here O is capital
     {

     cout <<"graphic error \n";
     getch();
     exit(0);
     }

     double xmin,xmax,ymin,ymax,x0[10],x1[10],y0[10],y1[10];
     int n;

     cleardevice();
     cout <<"enter the xmin ymin xmax ymax \n";
     cin >>xmin >>ymin >>xmax >>ymax;

     cout <<"\n enter the no of lines \n";
     cin >>n;

     for(int i=0;i<n;i++)
     {
     cout <<"enter xo yo x1 y1 of " <<i <<endl;
     cin >>x0[i] >>y0[i] >>x1[i] >>y1[i];
     }

    clrscr();


    rectangle(xmin,ymin,xmax,ymax);
    for(i=0;i<n;i++)
    line(x0[i],y0[i],x1[i],y1[i]);
    getch();

    cleardevice();
    rectangle(xmin,ymin,xmax,ymax);

    for(i=0;i<n;i++)
    {
    cslc(x0[i],y0[i],x1[i],y1[i],xmin,ymin,xmax,ymax);
    }

    getch();
    closegraph();
  }








