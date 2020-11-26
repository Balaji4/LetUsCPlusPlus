#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<ctype.h>
#define maxrow 379
#define maxcol 429
#define minrow 115
#define mincol 165
struct pos
{
int x,y;
}p[81],iv[81];
int mat[9][9]={0};
int row,col;
char dir;
void drawtable();
void setpos();
void value();
int valid();
void pf();
void markiv();
void setmat();
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
   exit(1);  /* terminate with an error code */
}


_setcursortype(_SOLIDCURSOR);
drawtable();
setpos();
value();
markiv();
row=p[0].y;
col=p[0].x;
moveto(col,row);
outtext("_");
while(1)
{
dir=getch();
if(isdigit(dir))
{
if(valid())
{
moveto(col,row);
pf();
setmat();
}
continue;
}
else  if(isalpha(dir))
{
switch(dir)
{
case 'd':if((col+33)>maxcol)
	 {
	 break;
	 }
	 else//if(getcolor()!=GREEN)
	 {
	// col+=33;
	 setcolor(BLACK);
	 outtextxy(col,row,"_");
	// }
	col+=33;
	setcolor(YELLOW);
	outtextxy(col,row,"_");
	break;
	}
case 'x':if((row+33)>maxrow)
	  {
	  break;
	  }//if(getcolor()!=GREEN)
	 else
	 {
	 setcolor(BLACK);
	 outtextxy(col,row,"_");

	 row+=33;
	setcolor(YELLOW);
	outtextxy(col,row,"_");
	break;
	}
case 'w':if((row-33)<minrow)
	  {
	  break;
	  }//if(getcolor()!=GREEN)
	 else
	 {
	 setcolor(BLACK);
	 outtextxy(col,row,"_");
	 row -=33;
	setcolor(YELLOW);
	//outtextxy(col,row,"_");
	break;
	}
case 'a':if((col-33)<mincol)
	  {
	  break;
	  }//if(getcolor()!=GREEN)
	 else
	 {
	 setcolor(BLACK);
	 outtextxy(col,row,"_");
	 col-=33;
	setcolor(YELLOW);
	outtextxy(col,row,"_");
	break;
	}
default:closegraph();
	 exit(0);
}
}
}
closegraph();

}

void drawtable()
{
int x,y;
x=600; //getmaxx();
y=500; //getmaxy();
setcolor(1);
line((x / 2-150),(y / 2 - 150),(x / 2 +150),(y / 2  -150));  //1 horiz
line((x / 2-150),(y / 2 - 117),(x / 2 +150),(y / 2  -117));  //2 horiz
line((x / 2-150),(y / 2 - 83),(x / 2 +150),(y / 2  -83));   //3
setcolor(3);
line((x / 2-150),(y / 2 - 50),(x / 2 +150),(y / 2  -50));  //4
setcolor(1);
line((x / 2-150),(y / 2 - 17),(x / 2 +150),(y / 2  -17));   //5
line((x / 2-150),(y / 2 + 17),(x / 2 +150),(y / 2  +17));     //6
setcolor(3);
line((x / 2-150),(y / 2 +50),(x / 2 +150),(y / 2  +50));  //2 horiz
setcolor(1);
line((x / 2-150),(y / 2 + 83),(x / 2 +150),(y / 2  +83));    //8
line((x / 2-150),(y / 2 + 117),(x / 2 +150),(y / 2  +117));  //9
line((x / 2-150),(y / 2 +150),(x / 2 +150),(y / 2  +150));  //2 horiz

line((x / 2-150),(y / 2 - 150),(x / 2 -150),(y / 2 + 150)); //1  ver

line((x / 2 -117),(y / 2  -150),(x / 2-117),(y / 2 + 150));  //2 verticle
line((x / 2-83),(y / 2 - 150),(x / 2 -83),(y / 2  +150));   //3
setcolor(3);
line((x / 2-50),(y / 2 - 150),(x / 2 -50),(y / 2 + 150));  //4
setcolor(1);
line((x / 2-17),(y / 2 - 150),(x / 2 -17),(y / 2  +150));   //5
line((x / 2+16),(y / 2 - 150),(x / 2 +16),(y / 2  +150));     //6
setcolor(3);
line((x / 2+50),(y / 2 - 150),(x / 2 +50),(y / 2 + 150));  //7
setcolor(1);
line((x / 2+83),(y / 2 - 150),(x / 2 +83),(y / 2  +150));    //8
line((x / 2+117),(y / 2 - 150),(x / 2 +117),(y / 2  +150));  //9
line((x / 2+150),(y / 2 - 150),(x / 2 +150),(y / 2 + 150)); //10

}

void setpos()
{
p[0].x=165; //pos1.col
p[0].y=115; //pos1.row
for(int i=1; i<81; i++)
{
if((i%9)==0)  //if pos=mul of 9 then col=165 row= prev row+33
{
p[i].x=165;
p[i].y=p[i-1].y+33;
continue;
}
else
{
p[i].x=p[i-1].x+33;  //otherwise  col=prev col+33 row= cur row
p[i].y=p[i-1].y;
}
}

}


void value()
{
setcolor(GREEN);
outtextxy(p[2].x,p[2].y,"2");   mat[2][2]=2;
outtextxy(p[4].x,p[4].y,"7");   mat[4][4]=7;
outtextxy(p[6].x,p[6].y,"3");   mat[6][6]=3;
outtextxy(p[8].x,p[8].y,"5");   mat[8][8]=5;

outtextxy(p[10].x,p[10].y,"6"); mat[10][10]=6;
outtextxy(p[11].x,p[11].y,"1"); mat[11][11]=1;
outtextxy(p[14].x,p[14].y,"4"); mat[14][14]=4;

outtextxy(p[18].x,p[18].y,"4"); mat[18][18]=4;
outtextxy(p[22].x,p[22].y,"2"); mat[22][22]=2;

outtextxy(p[27].x,p[27].y,"1"); mat[27][27]=1;
outtextxy(p[31].x,p[31].y,"8"); mat[31][31]=8;
outtextxy(p[33].x,p[33].y,"5"); mat[33][33]=5;
outtextxy(p[34].x,p[34].y,"9"); mat[34][34]=9;

outtextxy(p[36].x,p[36].y,"5"); mat[36][36]=5;
outtextxy(p[38].x,p[38].y,"3"); mat[38][38]=3;
outtextxy(p[42].x,p[42].y,"7"); mat[42][42]=7;
outtextxy(p[44].x,p[44].y,"2"); mat[44][44]=2;

outtextxy(p[46].x,p[46].y,"2"); mat[46][46]=2;
outtextxy(p[47].x,p[47].y,"9"); mat[47][47]=9;
outtextxy(p[49].x,p[49].y,"4"); mat[49][49]=4;
outtextxy(p[53].x,p[53].y,"6"); mat[53][53]=6;

outtextxy(p[58].x,p[58].y,"1"); mat[58][58]=1;
outtextxy(p[62].x,p[62].y,"3"); mat[62][62]=3;

outtextxy(p[66].x,p[66].y,"2"); mat[66][66]=2;
outtextxy(p[69].x,p[69].y,"8"); mat[69][69]=8;
outtextxy(p[70].x,p[70].y,"7"); mat[70][70]=7;

outtextxy(p[72].x,p[72].y,"3"); mat[72][72]=3;
outtextxy(p[74].x,p[74].y,"7"); mat[74][74]=7;
outtextxy(p[76].x,p[76].y,"9"); mat[76][76]=9;
outtextxy(p[78].x,p[78].y,"2"); mat[78][78]=2;

}

void markiv()
{
 for(int i=0; i<81; i++)
 {
 iv[i].x=iv[i].y=0;
 }
 iv[2].x=165+33*2; iv[2].y=115+33*0;
 iv[4].x=165+33*4; iv[4].y=115+33*0;
 iv[6].x=165+33*6; iv[6].y=115+33*0;
 iv[8].x=165+33*8; iv[8].y=115+33*0;

 iv[10].x=165+33*1; iv[10].y=115+33*1;
 iv[11].x=165+33*2; iv[11].y=115+33*1;
 iv[14].x=165+33*5; iv[14].y=115+33*1;

 iv[18].x=165+33*0; iv[18].y=115+33*2;
 iv[22].x=165+33*4; iv[22].y=115+33*2;

 iv[27].x=165+33*0; iv[27].y=115+33*3;
 iv[31].x=165+33*4; iv[31].y=115+33*3;
 iv[33].x=165+33*6; iv[33].y=115+33*3;
 iv[34].x=165+33*7; iv[34].y=115+33*3;

 iv[36].x=165+33*0; iv[36].y=115+33*4;
 iv[38].x=165+33*2; iv[38].y=115+33*4;
 iv[42].x=165+33*6; iv[42].y=115+33*4;
 iv[44].x=165+33*8; iv[44].y=115+33*4;

 iv[46].x=165+33*1; iv[46].y=115+33*5;
 iv[47].x=165+33*2; iv[47].y=115+33*5;
 iv[49].x=165+33*4; iv[49].y=115+33*5;
 iv[53].x=165+33*8; iv[53].y=115+33*5;

 iv[58].x=165+33*4; iv[58].y=115+33*6;
 iv[62].x=165+33*8; iv[62].y=115+33*6;

 iv[66].x=165+33*3; iv[66].y=115+33*7;
 iv[69].x=165+33*6; iv[69].y=115+33*7;
 iv[70].x=165+33*7; iv[70].y=115+33*7;

 iv[72].x=165+33*0; iv[72].y=115+33*8;
 iv[74].x=165+33*2; iv[74].y=115+33*8;
 iv[76].x=165+33*4; iv[76].y=115+33*8;
 iv[78].x=165+33*6; iv[78].y=115+33*8;


}




void pf()
{
switch(dir)
{
case '1':outtext("1");
	 break;
case '2':outtext("2");
	 break;
case '3':outtext("3");
	 break;
case '4':outtext("4");
	 break;
case '5':outtext("5");
	 break;
case '6':outtext("6");
	 break;
case '7':outtext("7");
	 break;
case '8':outtext("8");
	 break;
case '9':outtext("9");
	 break;
default:return;
}
}


int valid()
{
  for(int i=0; i<81; i++)
  {
  if(row==iv[i].y&&col==iv[i].x)
  {
  return 0;
  }
  }
  return 1;
}

void setmat()
{
mat[(row-115)%33][(col-165)%33]=int(dir)-'0';
//printf("%d",mat[(row-115)%33][(col-165)%33]);
}