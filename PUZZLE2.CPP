#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
class blocks
{
int left,right,top,bottom;

int nr,nc;
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
       void link();
blocks *lt,*rt,*tp,*bt;
int flag,num;
};
void up();
void down();
void right();
void left();
char   getkey()
{
union REGS i,o;
while(!kbhit())
;
i.h.ah=0;
int86(22,&i,&o);
return(o.h.ah);
}

void linkinit();
blocks b[9];
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


linkinit();
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
linkinit();
for(int i=0;i<=8;i++)
{
b[i].num=i+1;
b[i].draw();
}
b[8].flag=1;
while(1)
{
char ch=getkey();
switch(ch)
{
case 'H':down();
	 break;
case 'P':up();
	 break;
case 'M':left();
	 break;
case 'K':right();
	 break;
default: getch();
closegraph();
	 exit(0);
}

for( i=0;i<=8;i++)
{
b[i].draw();
}
}
}
void up()
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

  return;
  }
  else if(b[i].flag==1&&b[i].tp==NULL)
  {
  return;
  }
 }
}

void down()
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

  return;
  }
  else if(b[i].flag==1&&b[i].bt==NULL)
  {
  return;
  }
 }
}
void right()
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

  return;
  }
 else if(b[i].flag==1&&b[i].rt==NULL)
  {
  return;
  }
 }
}
void left()
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

  return;
  }
 else if(b[i].flag==1&&b[i].lt==NULL)
       {
       return;
       }
 }

}

void linkinit()
{
for(int i=0;i<=8;i++)
{
b[i].flag=0;
}
b[8].flag=1;

b[0].lt=NULL;
b[0].rt=&b[1];
b[0].tp=NULL;
b[0].bt=&b[3];
b[1].lt=&b[0];
b[1].rt=&b[2];
b[1].tp=NULL;
b[1].bt=&b[4];
b[2].lt=&b[1];
b[2].rt=NULL;
b[2].tp=NULL;
b[2].bt=&b[5];
b[3].lt=NULL;
b[3].rt=&b[4];
b[3].tp=&b[0];
b[3].bt=&b[6];
b[4].lt=&b[3];
b[4].rt=&b[5];
b[4].tp=&b[1];
b[4].bt=&b[7];
b[5].lt=&b[4];
b[5].rt=NULL;
b[5].tp=&b[2];
b[5].bt=&b[8];
b[6].lt=NULL;
b[6].rt=&b[7];
b[6].tp=&b[3];
b[6].bt=NULL;
b[7].lt=&b[6];
b[7].rt=&b[8];
b[7].tp=&b[4];
b[7].bt=NULL;
b[8].lt=&b[7];
b[8].rt=NULL;
b[8].tp=&b[5];
b[8].bt=NULL;
}


void blocks::draw()
{
rectangle(left,top,right,bottom);
setcolor(BLACK);
moveto(left+10,top+10);
outtext("1");
moveto(left+10,top+10);
outtext("2");
moveto(left+10,top+10);
outtext("3");
moveto(left+10,top+10);
outtext("4");
moveto(left+10,top+10);
outtext("5");
moveto(left+10,top+10);
outtext("6");
moveto(left+10,top+10);
outtext("7");
moveto(left+10,top+10);
outtext("8");
moveto(left+10,top+10);
outtext("9");
setcolor(WHITE);
moveto(left+10,top+10);
switch(num)
{
case 1:outtext("1");
	break;
case 2:outtext("2");
	break;
case 3:outtext("3");
	break;

case 4:outtext("4");
	break;
case 5:outtext("5");
	break;
case 6:outtext("6");
	break;
case 7:outtext("7");
	break;
case 8:outtext("8");
	break;
case 9://outtext("9");
	break;
default:outtext("0");
}

}