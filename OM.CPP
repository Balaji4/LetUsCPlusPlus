#include<conio.h>
#include<graphics.h>
void om(int x,int y,int z)
{
setcolor(z);
setlinestyle(0,0,3);
arc(x+50,y+50,5,150,45);
arc(x+50,y+50,260,25,45);
arc(x+50,y+140,250,100,45);
arc(x+50,y+140,230,100,45);
arc(x+73,y+150,310,100,55);
arc(x+130,y+30,170,20,25);
circle(x+130,y+38,10);
}
void main()
{
int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"");
 for(int s=10;s<400;s+=5)
 {
 om(s,10,15);
 om(s,10,0);
 }
  for(int t=10;t<400;t+=5)
 {
 om(400,t,15);
 om(400,t,0);
 }
  for(int d=-400;d<0;d+=5)
 {
 om(-d,400,15);
 om(-d,400,0);
 }
  for(int k=-400;k<0;k+=5)
 {
 om(10,-k,15);
 om(10,-k,0);
 }
 getch();
 closegraph();
}