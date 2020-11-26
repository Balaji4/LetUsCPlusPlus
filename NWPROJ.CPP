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

class node
{
int color;
enum power{low,mid,high};
int left,top,right,bottom;
public:
node(){}
node(int x1,int y1,int x2,int y2,char player[])
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

node b1,b2,b3,b4;
packet p;

void main()
{
int gdrive=DETECT,gmode;
initgraph(&gdrive,&gmode,"");
randomize();
b1=node(25,25,45,45,"b1");
b2=node(205,205,225,225,"b2");
b3=node(405,25,425,45,"b3");
b4=node(305,105,325,125,"b4");
p=packet(10,10);
line(45,35,405,35);  //b1-b3
line(45,45,205,205);
delay(3000);
repaint();
getch();
closegraph();
}
void repaint()
{
b1.draw("b1");
b2.draw("b2");
b3.draw("b3");
b4.draw("b4");
p.pdraw();
}
void node::draw(char player[])
{
setcolor(BLUE);
rectangle(left,top,right,bottom);
outtextxy(left+5,top+5,player);
}

void packet::pdraw()
{
setfillstyle(SOLID_FILL,2);
setcolor(WHITE);
fillellipse(x,y,radius,radius);
}