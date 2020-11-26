#include<graphics.h>
#include<stdio.h>
#include<dos.h>
#include<conio.h>
int gdriver=DETECT,gmode;
int min1=0,min2=0,max1=400,max2=580;
class block
{
int left,top,right,bottom;
public:block(){
initgraph(&gdriver,&gmode,"");
}
block(int l,int t,int r,int b)
{
left=l;
top=t;
right=r;
bottom=b;
/*rectangle(l,t,r,b);
line(l,t+20,r,b-180); //particular line
outtextxy((int)(l+r-100)/2,(int)(b+t-180)/2,"Particular(s)");
line(l,t+180,r,b-20); //total line
setcolor(RED);
outtextxy((int)(l+r-150)/2,(int)(b-20+t+200)/2,"Total=");
setcolor(WHITE);                         */
}
void moving(int,int,int,int);

void drw()
{
rectangle(left,top,right,bottom);
line(left,top+20,right,bottom-180); //particular line
outtextxy((int)(left+right-100)/2,(int)(bottom+top-180)/2,"Particular(s)");
line(left,top+180,right,bottom-20); //total line
setcolor(RED);
outtextxy((int)(left+right-150)/2,(int)(bottom-20+top+200)/2,"Total=");
setcolor(WHITE);
}
~block()
{
}
};

void block::moving(int l,int t,int r,int b)
{
rectangle(l,t,r,b);
line(l,t+20,r,b-180); //particular line
outtextxy((int)(l+r-100)/2,(int)(b+t-180)/2,"Particular(s)");
line(l,t+180,r,b-20); //total line
setcolor(RED);
outtextxy((int)(l+r-150)/2,(int)(b-20+t+200)/2,"Total=");
setcolor(WHITE);
}
block b[6];
void add(int mi1,int mi2,int mx1,int mx2,int index)
{
int i,j,k;
for(i=mx1,j=mx2;i>=mi1&&j>=mi2;i-=10,j-=10)
{
clearviewport();
for(k=index-1;k>=0;k--)
{
b[k].drw();
}
b[index].moving(i,0,j,200);
delay(100);
}
}

void main()
{
int i,j;

b[0]=block(0,0,180,200);
b[1]=block(200,0,380,200);
b[2]=block(400,0,580,200);
b[3]=block(0,220,180,420);
b[4]=block(200,220,380,420);
b[5]=block(400,220,580,420);
for(i=max1,j=max2;i>=min1&&j>=min2;i-=10,j-=10)
{
clearviewport();
b[0].moving(i,0,j,200);
delay(100);
}
getch();
min1=200;
min2=380;
add(min1,min2,max1,max2,1);
//rectangle(0,450,635,470);*/
setfillstyle(SOLID_FILL,WHITE);
bar(0,450,635,470);
setcolor(BLUE);
outtextxy(280,460,"Mcdonald Bill System");
getch();
closegraph();
}