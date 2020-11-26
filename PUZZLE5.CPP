#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<time.h>
#define maxrow 19
#define maxcol 38
#define minrow 3
#define mincol 6
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
void up(int &);
void down(int &);
void right(int &);
void left(int &);
void win();
void shuffle();
void linkinit();
blocks b[9];

int rw=4;
struct menuop
{
char op[20];
int posy;
}s[4];

void mfn();
int index();
void hscore();
void gset();
void launch();
void menu();
char   getkey()
{
union REGS i,o;

i.h.ah=0;
int86(22,&i,&o);
return(o.h.ah);
}
void main()
{
char choice;
int i;
clrscr();
_setcursortype(_NOCURSOR);
strcpy(s[0].op,"1: Launch Game\0");
strcpy(s[1].op,"2: Game Settings\0");
strcpy(s[2].op,"3: High Scores\0");
strcpy(s[3].op,"4: Exit\0");

s[0].posy=4;
s[1].posy=6;
s[2].posy=8;
s[3].posy=10;

menu();
while(1)
{
//clrscr();
//menu();
choice=getkey();
switch(choice)
{
case 'H': if((rw-2)>=4)
	  {
	  textcolor(WHITE);
	  //window(15,rw,40,11);
	  gotoxy(15,rw);
	 i=index();
	 cprintf("%s",s[i].op);
	  textcolor(RED);
	  rw-=2;
	  //window(15,rw,40,11);
	    gotoxy(15,rw);
	 i=index();
	 cprintf("%s",s[i].op);
	  }
		 //printf("UP key\n");
	 break;
case 'P':if((rw+2)<=10)
	 {
	 textcolor(WHITE);
	 //window(15,rw,40,11);
	    gotoxy(15,rw);
	 i=index();
	 cprintf("%s",s[i].op);
	 textcolor(RED);
	 rw+=2;
	 //window(15,rw,40,11);
	   gotoxy(15,rw);
	 i=index();
	 cprintf("%s",s[i].op);
	 }//printf("Down key\n");
	 break;
case 'M'://printf("RIGHT key\n");
	 break;
case 'K'://printf("Left key\n");
	 break;
default:mfn();
}
}
}


int index()
{
switch(rw)
{
case 4:return 0;
case 6:return 1;
case 8:return 2;
case 10:return 3;
}
return 0;
}

void menu()
{
textbackground(BLACK);
textcolor(WHITE);
gotoxy(15,2);
cprintf("MENU\n");
for(int i=0;i<=3;i++)
{
gotoxy(15,s[i].posy);
cprintf("%s",s[i].op);
}
textcolor(RED);
gotoxy(15,rw);//window(15,rw,40,11);
cprintf("%s",s[index()].op);
}

void mfn()
{
 switch(rw)
 {
 case 4:launch();
       return;
 case 6:gset();
       return;
 case 8:hscore();
       return;
 case 10:exit(0);
 }
}

void launch()
{
clock_t start,end;
int step=0;
char ch;
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
shuffle();
for(i=0;i<=8;i++)
{
b[i].draw();
}
start=clock();
delay(1000);
end=clock();
while(1)
{
while(!kbhit())
{
end=clock();
gotoxy(4,4);
printf("Steps");
gotoxy(4,6);
printf("Time");
gotoxy(4,7);

printf("%3.0f",(end-start)/CLK_TCK);

}
 ch=getkey();

switch(ch)
{
case 'H':down(step);

	 gotoxy(4,5);
	 printf("%d",step);//win();
	 break;
case 'P':up(step);

	 gotoxy(4,5);
	 printf("%d",step);//win();
	 break;
case 'M':left(step);

	 gotoxy(4,5);
	 printf("%d",step);
	 //win();
	 break;
case 'K':right(step);

	 gotoxy(4,5);
	 printf("%d",step);
	// win();
	 break;
default: getch();
closegraph();
	 exit(0);
}

for( i=0;i<=8;i++)
{
b[i].draw();
}
win();
}
}


void hscore()
{
clrscr();//window(15,2,40,10);
gotoxy(4,4);
cprintf("1:Easy - 0");
gotoxy(4,6);
cprintf("2:Medium - 0");
gotoxy(4,8);
cprintf("3:Hard - 0\n");
getch();
clrscr();
menu();
}

void gset()
{
clrscr();//window(15,2,40,10);
gotoxy(4,4);
cprintf("1:Easy");
gotoxy(4,6);
cprintf("2:Medium");
gotoxy(4,8);
cprintf("3:Hard\n");
getch();
clrscr();
menu();
}


void win()
{
for(int i=0;i<=8;i++)
{
if(b[i].num==i+1)
{
if(i==8)
{
delay(500);
clearviewport();
outtextxy(250,250,"you win");
getch();
closegraph();
exit(0);
}
continue;
}
else return;
}
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

