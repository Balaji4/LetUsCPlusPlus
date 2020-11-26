#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#define maxrow 19
#define maxcol 38
#define minrow 3
#define mincol 6
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
void suffle();
void up(int&);
void down(int&);
void right(int&);
void left(int&);
class blocks
{
int left,right,top,bottom;

public:
	 char n;
	int flag;
	blocks()
       {
       flag=0;
	}
       blocks(int l,int t,int r,int b)
       {
       left=l;
       right=r;
       bottom=b;
       top=t;
       flag=0;
       }
       void draw();

blocks *lt,*rt,*tp,*bt;
};
void setalpha();
void linkinit();
blocks b[18];
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

b[0]=blocks((x / 2-100),(y / 2 - 60),(x / 2 -58),(y / 2 - 20));
b[1]=blocks((x / 2-60),(y / 2 - 60),(x / 2 -18),(y / 2 - 20));
b[2]=blocks((x / 2 -20 ),(y / 2 -60),(x / 2 +18),(y / 2 -20));
b[3]=blocks((x / 2 +20),(y / 2 - 60),(x / 2 +58),(y / 2 -20));
b[4]=blocks((x / 2 +60),(y / 2 - 60),(x / 2 +98),(y / 2 -20));
b[5]=blocks((x / 2 +100),(y / 2 - 60),(x / 2 +138),(y / 2 -20));

b[6]=blocks((x / 2 - 100),(y / 2 - 20),(x / 2 -58),(y / 2 +20));
b[7]=blocks((x / 2 - 60),(y / 2 - 20),(x / 2 -18),(y / 2 +20));
b[8]=blocks((x / 2 - 20),(y / 2 - 20),(x / 2 + 18),(y / 2 + 20));
b[9]=blocks((x / 2 +20),(y / 2 - 20),(x / 2 +58),(y / 2 +20));
b[10]=blocks((x / 2 +60),(y / 2 - 20),(x / 2 +98),(y / 2 +20));
b[11]=blocks((x / 2 +100),(y / 2 - 20),(x / 2 +138),(y / 2 +20));

b[12]=blocks((x / 2 - 100),(y / 2 +20),(x / 2 -58),(y / 2 +60));
b[13]=blocks((x / 2 - 60),(y / 2 +20),(x / 2 -18),(y / 2 +60));
b[14]=blocks((x / 2 - 20),(y / 2 +20),(x / 2 +18),(y / 2 +60));
b[15]=blocks((x / 2 + 20),(y / 2+20),(x / 2 + 58),(y / 2+60));
b[16]=blocks((x / 2 + 60),(y / 2+20),(x / 2 + 98),(y / 2+60));
b[17]=blocks((x / 2 + 100),(y / 2+20),(x / 2 + 138),(y / 2+60));
setalpha();

for(int i=0;i<=17;i++)
{
b[i].draw();

}

getch();
closegraph();
}

void blocks::draw()
{
rectangle(left,top,right,bottom);
moveto(left+10,top+10);
switch(this->n)
{
case 'B':outtext("B");
	 break;
case 'a':outtext("a");
	 break;
case 'l':outtext("l");
	 break;
case 'j':outtext("j");
	 break;
case 'i':outtext("i");
	 break;
case 'P':outtext("P");
	 break;
case 'r':outtext("r");
	 break;
case 's':outtext("s");
	 break;
case 'd':outtext("d");
	 break;
case 'D':outtext("D");
	 break;
case 'u':outtext("u");
	 break;
case 'b':outtext("b");
	 break;
case 'e':outtext("e");
	 break;
case 'y':outtext("y");
	 break;
}


}

void setalpha()
{
b[0].n='B';
b[1].n='a';
b[2].n='l';
b[3].n='a';
b[4].n='j';
b[5].n='i';
b[6].n='P';
b[7].n='r';
b[8].n='a';
b[9].n='s';
b[10].n='a';
b[11].n='d';
b[12].n='D';
b[13].n='u';
b[14].n='b';
b[15].n='e';
b[16].n='y';
b[17].flag=1;
}

void linkinit()
{
b[0].lt=NULL;
b[0].rt=NULL;
b[0].bt=NULL;
b[0].tp=NULL;

b[1].lt=NULL;
b[1].rt=NULL;
b[1].bt=NULL;
b[1].tp=NULL;

b[0].lt=NULL;
b[0].rt=NULL;
b[0].bt=NULL;
b[0].tp=NULL;

b[0].lt=NULL;
b[0].rt=NULL;
b[0].bt=NULL;
b[0].tp=NULL;

b[0].lt=NULL;
b[0].rt=NULL;
b[0].bt=NULL;
b[0].tp=NULL;

b[0].lt=NULL;
b[0].rt=NULL;
b[0].bt=NULL;
b[0].tp=NULL;

b[0].lt=NULL;
b[0].rt=NULL;
b[0].bt=NULL;
b[0].tp=NULL;

b[0].lt=NULL;
b[0].rt=NULL;
b[0].bt=NULL;
b[0].tp=NULL;

b[0].lt=NULL;
b[0].rt=NULL;
b[0].bt=NULL;
b[0].tp=NULL;

b[0].lt=NULL;
b[0].rt=NULL;
b[0].bt=NULL;
b[0].tp=NULL;

b[0].lt=NULL;
b[0].rt=NULL;
b[0].bt=NULL;
b[0].tp=NULL;

b[0].lt=NULL;
b[0].rt=NULL;
b[0].bt=NULL;
b[0].tp=NULL;

b[0].lt=NULL;
b[0].rt=NULL;
b[0].bt=NULL;
b[0].tp=NULL;

b[0].lt=NULL;
b[0].rt=NULL;
b[0].bt=NULL;
b[0].tp=NULL;

b[0].lt=NULL;
b[0].rt=NULL;
b[0].bt=NULL;
b[0].tp=NULL;

b[0].lt=NULL;
b[0].rt=NULL;
b[0].bt=NULL;
b[0].tp=NULL;

b[0].lt=NULL;
b[0].rt=NULL;
b[0].bt=NULL;
b[0].tp=NULL;

}

void shuffle()
{
int t=0;
 randomize();
 int i,j;
 for(j=0;j<100;j++)
 {
  i=rand()%5;
  if(i>0&&i<=4)
  {
   switch(i)
   {
    case 1:up(t);
       break;
    case 2:down(t);
       break;
    case 3:left(t);
	break;
    case 4:right(t);
	break;
    default:continue;
   }
  }
 }
}








void up(int &s)
{

 for(int i=0;i<=8;i++)
 {
  if(b[i].flag==1&&b[i].tp!=NULL)
  {
   int temp=b[i].flag;
   b[i].flag=b[i-3].flag;
   b[i-3].flag=temp;
   temp=b[i].num;
   b[i].num=b[i-3].num;
   b[i-3].num=temp;
   s++;
  return;
  }
  else if(b[i].flag==1&&b[i].tp==NULL)
  {
  return;
  }
 }
}

void down(int &s)
{
for(int i=0;i<=8;i++)
 {
  if(b[i].flag==1&&b[i].bt!=NULL)
  {
   int temp=b[i].flag;
   b[i].flag=b[i+3].flag;
   b[i+3].flag=temp;
   temp=b[i].num;
   b[i].num=b[i+3].num;
   b[i+3].num=temp;
   s++;
  return;
  }
  else if(b[i].flag==1&&b[i].bt==NULL)
  {
  return;
  }
 }
}
void right(int &s)
{
for(int i=0;i<=8;i++)
 {
  if(b[i].flag==1&&b[i].rt!=NULL)
  {
   int temp=b[i].flag;
   b[i].flag=b[i+1].flag;
   b[i+1].flag=temp;
   temp=b[i].num;
   b[i].num=b[i+1].num;
   b[i+1].num=temp;
   s++;
  return;
  }
 else if(b[i].flag==1&&b[i].rt==NULL)
  {
  return;
  }
 }
}
void left(int &s)
{
for(int i=0;i<=8;i++)
 {
  if(b[i].flag==1&&b[i].lt!=NULL)
  {
   int temp=b[i].flag;
   b[i].flag=b[i-1].flag;
   b[i-1].flag=temp;
   temp=b[i].num;
   b[i].num=b[i-1].num;

   b[i-1].num=temp;
   s++;
  return;
  }
 else if(b[i].flag==1&&b[i].lt==NULL)
       {
       return;
       }
 }

}
