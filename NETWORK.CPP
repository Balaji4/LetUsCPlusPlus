#include<graphics.h>
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
void repaint();
int min(int a,int b)
{
if(a<b)
return a;
else
return b;

}
class bluenode;
class rednode
{
int color;
enum power{low,mid,high};
int left,top,right,bottom;
public:
rednode(){}
rednode(int x1,int y1,int x2,int y2,char player[])
{
color=RED;
left=x1;
top=y1;
right=x2;
bottom=y2;
setcolor(RED);
rectangle(left,top,right,bottom);
outtextxy(left+5,top+5,player);
}
void draw(char[]);
friend void move(bluenode &,rednode &);
};
class bluenode
{
int color;
enum power{low,mid,high};
int left,top,right,bottom;
public:
bluenode(){}
bluenode(int x1,int y1,int x2,int y2,char player[])
{
color=BLUE;
left=x1;
top=y1;
right=x2;
bottom=y2;
setcolor(BLUE);
rectangle(left,top,right,bottom);
outtextxy(left+5,top+5,player);
}
void draw(char[]);
friend void move(bluenode &,rednode &);
};
class packet
{
int radius;
int x,y;
public:
packet(){}
packet(int x1,int y1)
{
setfillstyle(SOLID_FILL,2);
setcolor(WHITE);
radius=10;
x=x1;
y=y1;
fillellipse(x,y,radius,radius);
}
void pdraw();
};
 void move(bluenode &b,rednode &r)
{
int inc=rand()%100;
b.left=min(b.left+inc,getmaxx()-20);
b.top=min(b.top+inc,getmaxy()-20);
b.right=min(b.right+inc,getmaxx());
b.bottom=min(b.bottom+inc,getmaxy());
int incr=rand()%100;
r.left=min(r.left-incr,getmaxx()-20);;
r.top=min(r.top+incr,getmaxy()-20);;
r.right=min(r.right-incr,getmaxx());;
r.bottom=min(r.bottom+incr,getmaxy());;
cleardevice();
}
bluenode b1,b2;
rednode r1,r2;
packet p;

void main()
{
int gdrive=DETECT,gmode;
initgraph(&gdrive,&gmode,"");
randomize();
b1=bluenode(25,25,45,45,"b1");
b2=bluenode(25,55,45,75,"b2");
r1=rednode(405,25,425,45,"r1");
r2=rednode(405,55,425,75,"r2");
p=packet(10,10);
delay(3000);
move(b1,r1);
repaint();
getch();
closegraph();
}
void repaint()
{
b1.draw("b1");
b2.draw("b2");
r1.draw("r1");
r2.draw("r2");
p.pdraw();
}
void bluenode::draw(char player[])
{
setcolor(BLUE);
rectangle(left,top,right,bottom);
outtextxy(left+5,top+5,player);
}
void rednode::draw(char player[])
{
setcolor(RED);
rectangle(left,top,right,bottom);
outtextxy(left+5,top+5,player);
}
void packet::pdraw()
{
setfillstyle(SOLID_FILL,2);
setcolor(WHITE);
fillellipse(x,y,radius,radius);
}