       /*                     ANIMATED N-QUEENS                 */
       /*                       HARISH PATEL                    */
#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
#define MAX 100

char far hip[8]={0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,};

int hr[MAX],vr[MAX],n;
unsigned int size;
void *ima;
char hippy[40];

void ani_queen(int);
void move(int,int,int);

void drawx(int x,int y)
{
 int poly1[26];
 setcolor(11);

 circle(x+25,y+5,4);
 circle(x+25,y+5,3);
 circle(x+25,y+5,2);
 circle(x+25,y+5,1);

 poly1[0]=x+15;
 poly1[1]=y+10;

 poly1[2]=x+35;
 poly1[3]=y+10;

 poly1[4]=x+35;
 poly1[5]=y+15;

 poly1[6]=x+30;
 poly1[7]=y+15;

 poly1[8]=x+30;
 poly1[9]=y+35;

 poly1[10]=x+40;
 poly1[11]=y+35;

 poly1[12]=x+40;
 poly1[13]=y+40;

 poly1[14]=x+10;
 poly1[15]=y+40;

 poly1[16]=x+10;
 poly1[17]=y+35;

 poly1[18]=x+20;
 poly1[19]=y+35;

 poly1[20]=x+20;
 poly1[21]=y+15;

 poly1[22]=x+15;
 poly1[23]=y+15;

 poly1[24]=x+15;
 poly1[25]=y+10;
 setfillpattern(hip,13);
 fillpoly(12,poly1);
 }

int place(int k,int x[])
{
 int i=0;
 while(i<k)
     if(x[i]==x[k]||(abs(x[i]-x[k])==abs(i-k)))
      return(0);
     else i++;
 return(1);
}

void main()
{
 int x[10]={0},x1[10]={0},i,k=0,count=0,count1=0;
 char sent[100];
 clrscr();
 printf("\nENTER THE NUMBER OF QUEENS (MAX 7):");
 scanf("%d",&n);

  while(k>=0)
  {
   x[k]++;
   while(x[k]<=n&&!(place(k,x)))x[k]++;
   if(x[k]<=n)
      if(k==n-1)
	   count=count+1;
      else x[++k]=0;
   else k--;
   }
   if(count==0)
    {printf("No solutions present for given board");
     getch();
     exit(1);}
     k=0;
     ani_queen(n);
     while(k>=0)
     {
      x1[k]++;
      while(x1[k]<=n&&!(place(k,x1)))x1[k]++;
      if(x1[k]<=n)
      {
	move(0,x1[k],k);
	if(k==n-1){
	count1=count1+1;
	if(count1==count){
	outtextxy(10,getmaxy()-15,"THATS THE LAST SOLUTION FOLK'S:");
	getch();
	exit(1);
	 }
	else{
	 outtextxy(10,getmaxy()-15,"PRESS ENTER TO DISPLAY NEXT SOLUTION");
	 setcolor(WHITE);
	 sprintf(hippy,"THIS IS SOLUTION %d OF %d FOR %d QUEEN PROBLEM",count1,count,n);
	 outtextxy(10,10,hippy);
	 getch();
	 setcolor(BLACK);
	 outtextxy(10,getmaxy()-15,"PRESS ENTER TO DISPLAY NEXT SOLUTION");
	 outtextxy(10,10,hippy);
	 setcolor(WHITE);
	 k=k+1;
	   }
	 }
	else x1[++k]=0;
	}
      else
       {
	 x1[k]=0;
	 k--;
	 sprintf(sent,"PRESS ENTER TO BACKTRACK QUEEN IN ROW %d",k+1);
	 outtextxy(10,20,sent);
	 setcolor(BLACK);
	 getch();
	 sprintf(sent,"PRESS ENTER TO BACKTRACK QUEEN IN ROW %d",k+1);
	 outtextxy(10,20,sent);
	 setcolor(WHITE);
	 move(x1[k],0,k);
	 }
    }
    getch();
    closegraph();
 }

void ani_queen(int n)
{
 int gdriver = DETECT, gmode, errorcode;
 int x=0,poly[10];
 initgraph(&gdriver,&gmode,"");
 errorcode = graphresult();
  if (errorcode != grOk)
  {
    printf("Graphics error: %s\n", grapherrormsg(errorcode));
    printf("Press any key to halt:");
    getch();
    exit(1);
    }
   for(int i=0;x<getmaxx()-20;i++){
     x=x+50;
     hr[i]=x;}
     x=0;
   for(int j=0;x<getmaxy()-20;j++){
     x=x+50;
     vr[j]=x;}

   setcolor(RED);
   rectangle(0,0,getmaxx(),getmaxy());
   rectangle(hr[3]-3,vr[0]-3,hr[n+3]+3,vr[n]+3);
   rectangle(hr[3]-2,vr[0]-2,hr[n+3]+2,vr[n]+2);
   rectangle(hr[3]-1,vr[0]-1,hr[n+3]+1,vr[n]+1);
   setcolor(WHITE);
   int h=0;
   for(i=3;i<n+3;i=i+1)
    { h=h^1;
      for(j=h;j<n;j=j+2){
	  poly[0]=hr[i];
	  poly[1]=vr[j];

	  poly[2]=hr[i+1];
	  poly[3]=vr[j];

	  poly[4]=hr[i+1];
	  poly[5]=vr[j+1];

	  poly[6]=hr[i];
	  poly[7]=vr[j+1];

	  poly[8]=hr[i];
	  poly[9]=vr[j];
	  fillpoly(4,poly);
	  }
      }
     setcolor(RED);
     rectangle(hr[3],vr[0],hr[n+3],vr[n]);
     for(i=0;i<n;i++)
     { drawx(hr[0],vr[i]);}
     drawx(575,425);
     outtextxy(425,450,"THIS IS THE QUEEN");
   return;
 }

void move(int s,int t,int k)
{
  size=imagesize(575,425,625,475);
  ima=malloc(size);
  getimage(575,425,625,475,ima);
  if(s<t)
  {
  t=t+2;
  int q=hr[s];
   while(q<=hr[t]-1)
   {
    putimage(q,vr[k],ima,XOR_PUT);
     q=q+1;
    putimage(q,vr[k],ima,XOR_PUT);
     delay(5);
     }
   }
   if(s>t)
   {
   s=s+2;
   int q=hr[s];
   while(q>=hr[t]+1)
   {
    putimage(q,vr[k],ima,XOR_PUT);
     q=q-1;
    putimage(q,vr[k],ima,XOR_PUT);
     delay(5);
     }
   }
   free(ima);
}











