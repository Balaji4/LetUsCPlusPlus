#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<stdlib.h>
#include<ctype.h>
#define maxrow 19
#define maxcol 38
#define minrow 3
#define mincol 6
void table();
void setpos();
void move();
void value1();
void play();
void grade();
void controls();
void level();
void submit();
void decidepos(int*,int*);
void decidecol(int*);
void howtoplay();
int valid(int,int);
int dup(int,int);

//void tprint();

int row=3,col=6,b[9][9],take;
struct position
{
int x,y;
}p[81];

char dir;
void main()
{
char ch;
clrscr();
textcolor(RED);
 while(1)
 {
 printf("\t\tMAIN MENU\n");
 printf("\t1:Launch Game\n\t2:Game level\n\t3:Best Grade\n\t");
 printf("4:Controls\n\t5:How to play\n\t6:Exit");
 ch=getch();
 clrscr();
 switch(ch)
 {
 case '1':play();
	  break;
 case '2':level();
	  break;
 case '3':grade();
	  break;
 case '4':controls();
	  break;
 case '5':howtoplay();
	  break;
 default:exit(0);
 }
 }
}

void play()
{
setpos();
textbackground(BLACK);
table();
value1();

gotoxy(col,row);
while(1)
{
while(!kbhit) // do nothing untill a key is pressed
{

}


dir=getch();

move();

}
}

void table()  //create sudoku table 9x9
{
int i,j,c=4;
char ch=179;
textcolor(RED);
for(i=0;i<10;i++)   //for no. of   column line
{
for(j=2;j<22;j++)   //for row
{
gotoxy(c,j);        //c for column

if(i==3||i==6)
{
textcolor(BLUE);  // for vertical blue lines
}
if(j!=2)
cprintf("%c",ch);
if(j%2==0&&c<=36)
{
textcolor(RED);
cprintf("____\n");     // for horizontal red lines

}
}
c+=4;
}
delline();
for(int cl=5;cl<=39;cl++)     //for horizontal blue lines
{
if(cl%4==0)       //if vertical red line encountered dont print blue line
{continue;}
gotoxy(cl,8);
textcolor(BLUE);
cprintf("_");

gotoxy(cl,14);
textcolor(BLUE);
cprintf("_");
}
}


void setpos()    // for each element in matrix decide its fixed position
{


p[0].x=6;     p[0].y=3;
p[1].x=10;    p[1].y=3;
p[2].x=14;    p[2].y=3;
p[3].x=18;    p[3].y=3;
p[4].x=22;    p[4].y=3;
p[5].x=26;    p[5].y=3;
p[6].x=30;    p[6].y=3;
p[7].x=34;    p[7].y=3;
p[8].x=38;    p[8].y=3;
p[9].x=6;     p[9].y=5;   //2nd row
p[10].x=10;   p[10].y=5;
p[11].x=14;   p[11].y=5;
p[12].x=18;   p[12].y=5;
p[13].x=22;   p[13].y=5;
p[14].x=26;   p[14].y=5;
p[15].x=30;   p[15].y=5;
p[16].x=34;   p[16].y=5;
p[17].x=38;   p[17].y=5;
p[18].x=6;    p[18].y=7;   //3rd row
p[19].x=10;   p[19].y=7;
p[20].x=14;   p[20].y=7;
p[21].x=18;   p[21].y=7;
p[22].x=22;   p[22].y=7;
p[23].x=26;   p[23].y=7;
p[24].x=30;   p[24].y=7;
p[25].x=34;   p[25].y=7;
p[26].x=38;   p[26].y=7;
p[27].x=6;    p[27].y=9;   //4th row
p[28].x=10;   p[28].y=9;
p[29].x=14;   p[29].y=9;
p[30].x=18;   p[30].y=9;
p[31].x=22;   p[31].y=9;
p[32].x=26;   p[32].y=9;
p[33].x=30;   p[33].y=9;
p[34].x=34;   p[34].y=9;
p[35].x=38;   p[35].y=9;
p[36].x=6;    p[36].y=11;   //5th row
p[37].x=10;   p[37].y=11;
p[38].x=14;   p[38].y=11;
p[39].x=18;   p[39].y=11;
p[40].x=22;   p[40].y=11;
p[41].x=26;   p[41].y=11;
p[42].x=30;   p[42].y=11;
p[43].x=34;   p[43].y=11;
p[44].x=38;   p[44].y=11;
p[45].x=6;    p[45].y=13;   //6th row
p[46].x=10;   p[46].y=13;
p[47].x=14;   p[47].y=13;
p[48].x=18;   p[48].y=13;
p[49].x=22;   p[49].y=13;
p[50].x=26;   p[50].y=13;
p[51].x=30;   p[51].y=13;
p[52].x=34;   p[52].y=13;
p[53].x=38;   p[53].y=13;
p[54].x=6;    p[54].y=15;   //7th row
p[55].x=10;   p[55].y=15;
p[56].x=14;   p[56].y=15;
p[57].x=18;   p[57].y=15;
p[58].x=22;   p[58].y=15;
p[59].x=26;   p[59].y=15;
p[60].x=30;   p[60].y=15;
p[61].x=34;   p[61].y=15;
p[62].x=38;   p[62].y=15;
p[63].x=6;    p[63].y=17;   //8th row
p[64].x=10;   p[64].y=17;
p[65].x=14;   p[65].y=17;
p[66].x=18;   p[66].y=17;
p[67].x=22;   p[67].y=17;
p[68].x=26;   p[68].y=17;
p[69].x=30;   p[69].y=17;
p[70].x=34;   p[70].y=17;
p[71].x=38;   p[71].y=17;
p[72].x=6;    p[72].y=19;   //9th row
p[73].x=10;   p[73].y=19;
p[74].x=14;   p[74].y=19;
p[75].x=18;   p[75].y=19;
p[76].x=22;   p[76].y=19;
p[77].x=26;   p[77].y=19;
p[78].x=30;   p[78].y=19;
p[79].x=34;   p[79].y=19;
p[80].x=38;   p[80].y=19;

}

void move()
{
int i=0,j=0,or,oc;
l:switch(dir)      // dir for direction of movement
{
case 'w':or=row;
	 row-=2;
	 if(row<minrow||row>maxrow)
	 {
	 row=or;    //restore previous row value if out of range
	 break;
	 }
	 gotoxy(col,row);
	 break;
case 'd':oc=col;
	 col+=4;
	 if(col<mincol||col>maxcol)
	 {
	 col=oc;   //restore previous column value if out of range
	 break;
	 }
	 gotoxy(col,row);
	 break;
case 'x':or=row;
	  row+=2;
	 if(row<minrow||row>maxrow)
	 {
	 row=or;  //restore previous row value if out of range
	 break;
	 }
	 gotoxy(col,row);
	 break;
case 'a':oc=col;
	 col-=4;
	 if(col<mincol||col>maxcol)
	 {
	 col=oc; //restore previous column value if out of range
	 break;
	 }
	 gotoxy(col,row);
	 break;
case 'm':submit();
case 'l':exit(0);
}
if(isdigit(dir))  // if dir represents a no. to enter in the matrix
{
if(dir!='0')
{
take=(int)dir-'0';
if(valid(col,row)==1)
{
printf("\a");
return;
//textcolor(WHITE);
}
textcolor(YELLOW);
if(dup(col,row)==1)  // if repeated
{
textcolor(MAGENTA);
printf("\a");
}
decidepos(&i,&j); // decide position of accepting the no.
b[i][j]=take;


cprintf("%c",dir);
 if(getx()<38&&gety()<19)
 {
 dir='d';     // after press a no. goto next col
 goto l;
 }
  if(getx()==39)
  {
  dir='x';   // if last column reached goto next row
  goto l;
  }
}
}
}

void value1()
{

int i,j,k;
char a[9][9]={
		   {10,10,'2',10,'7',10,'3',10,'5'},
		   {10,'6','1',10,10,'4',10,10,10},
		   {'4',10,10,10,'2',10,10,10,10},
		   {'1',10,10,10,'8',10,'5','9',10},
		   {'5',10,'3',10,10,10,'7',10,'2'},
		   {10,'2','9',10,'4',10,10,10,'6'},
		   {10,10,10,10,'1',10,10,10,'3'},
		   {10,10,10,'2',10,10,'8','7',10},
		   {'3',10,'7',10,'9',10,'2',10,10}};
       for(k=1;k<=81;k++)
       {
       for(i=0,k=1;i<9,k<=81;i++)
       {
	for(j=0;j<9;j++)
	{

	textcolor(GREEN);
	gotoxy(p[k-1].x,p[k-1].y);
	cprintf("%c",a[i][j]);        //give some fixed no.s to play
	k++;
	}
       }
      }
      for(i=0;i<9;i++)
      {
       for(j=0;j<9;j++)
       {
	if(a[i][j]!=10)
	{
	b[i][j]=(int)a[i][j]-'0';

	}
	else b[i][j]=0;
       }
      }
}


void grade()   // high scores
{
}

void controls()  // controls for how to play
{
clrscr();
gotoxy(5,5);
printf("w:move up");
gotoxy(5,6);
printf("x:move down");
gotoxy(5,7);
printf("a:move left");
gotoxy(5,8);
printf("d:move right");
gotoxy(5,9);
printf("m:to submit your play");
gotoxy(5,10);
printf("l:to exit the game");
getch();
clrscr();
gotoxy(0,0);
}

void level()   // decide level of playing
{
char l;
clrscr();
printf("LEVEL 1\nLEVEL 2\nLEVEL 3\n");
getch();
clrscr();
}

void howtoplay()
{
clrscr();
gotoxy(5,0);
printf(" Fill in the grid so that every horizontal row,\n");
printf("every vertical column and every 3x3 box contains the digits 1-9,\n");
printf("without  repeating the numbers in the same row, column or box.\n");
printf("You can't change the digits already given in the grid.\n");
printf("Every puzzle has one solution \n");
getch();
clrscr();
gotoxy(0,0);
}

int valid(int x,int y)
{
int i,j,pos;

gotoxy(23,22);
printf("x=%d y=%d take=%d",x,y,take);
gotoxy(col,row);

switch(y)  // prevent replacement of given no.s
{
case 3:
       if(x==14||x==22||x==30||x==38)
       return 1;
       break;
case 5:if(x==10||x==14||x==26)
       return 1;
       break;
case 7:if(x==6||x==22)
       return 1;
       break;
case 9:if(x==6||x==22||x==30||x==34)
       return 1;
       break;
case 11:if(x==6||x==14||x==30||x==38)
       return 1;
       break;
case 13:if(x==10||x==14||x==22||x==38)
       return 1;
       break;
case 15:if(x==22||x==38)
       return 1;
       break;
case 17:if(x==18||x==30||x==34)
       return 1;
       break;
case 19:if(x==6||x==14||x==22||x==30)
       return 1;
       break;
}

return 0;
}


int dup(int x,int y)
{
int count=1,i,j;
switch(y)   // for unique element in each row
{
case 3:
       if(take==2||take==7||take==3||take==5)
       return 1;
       break;
case 5:
       if(take==6||take==1||take==4)
       return 1;
       break;
case 7:
       if(take==4||take==2)
       return 1;
       break;
case 9:
       if(take==1||take==8||take==5||take==9)
       return 1;
       break;
case 11:
	if(take==5||take==3||take==7||take==2)
       return 1;
       break;
case 13:
	if(take==2||take==9||take==4||take==6)
       return 1;
       break;
case 15:
	if(take==1||take==3)
       return 1;
       break;
case 17:
	if(take==2||take==8||take==7)
       return 1;
       break;
case 19:
	  if(take==3||take==7||take==9||take==2)
       return 1;
       break;
}
switch(x)   //for unique element in each column
{
case 6:
       if(take==4||take==1||take==3||take==5)
       return 1;
       break;
case 10:if(take==6||take==2)
       return 1;
       break;
case 14:if(take==1||take==2||take==3||take==7||take==9)
       return 1;
       break;
case 18:if(take==2)
       return 1;
       break;
case 22:if(take==7||take==2||take==8||take==4||take==1||take==9)
       return 1;
       break;
case 26:if(take==4)
       return 1;
       break;
case 30:if(take==3||take==5||take==7||take==8||take==2)
       return 1;
       break;
case 34:if(take==9||take==7)
       return 1;
       break;
case 38:if(take==5||take==2||take==6||take==3)
       return 1;
       break;
}
if(x>=6&&x<=14)
{
if(y>=3&&y<=7)   //  1st box
count=1;
else if(y>=9&&y<=13) // 4th box
count=4;
else if(y>=15&&y<=19)  // 7th box
count=7;
}
else if(x>=18&&x<=26)
{
if(y>=3&&y<=7)          // 2nd box
count=2;
else if(y>=9&&y<=13)   // 5th box
count=5;
else if(y>=15&&y<=19)  // 8th box
count=8;
}
else if(x>=30&&x<=38)
{
if(y>=3&&y<=7)        // 3rd box
count=3;
else if(y>=9&&y<=13)  // 6th box
count=6;
else if(y>=15&&y<=19)  // 9th box
count=9;
}

     //for matrix 3x3 box comparision

 switch(count)
 {
 case 1:
	if(take==2||take==6||take==1||take==4)
	return 1;

	break;
 case 2:
		if(take==2||take==7||take==4)
		return 1;

	break;
 case 3:
	    if(take==3||take==5)
	    return 1;

	break;
 case 4:
	if(take==1||take==2||take==3||take==5||take==9)
	return 1;

	break;
 case 5:
	if(take==8||take==4)
	return 1;
	break;
 case 6:
	if(take==5||take==9||take==7||take==2||take==6)
	return 1;
	break;
 case 7:
 if(take==7||take==3)
	return 1;
	break;
 case 8:
 if(take==2||take==9||take==1)
	return 1;
	break;
 case 9:
	if(take==2||take==8||take==7||take==3)
	return 1;
	break;
}



return 0;
}

void decidepos(int *p,int *r)  // decide row column of entered no.
{
switch(row)
{
case 3:*p=0;
       decidecol(r);
       break;
case 5:*p=1;
       decidecol(r);
       break;
case 7:*p=2;
       decidecol(r);
       break;
case 9:*p=3;
       decidecol(r);
       break;
case 11:*p=4;
       decidecol(r);
       break;
case 13:*p=5;
       decidecol(r);
       break;
case 15:*p=6;
       decidecol(r);
       break;
case 17:*p=7;
       decidecol(r);
       break;
case 19:*p=8;
       decidecol(r);
       break;
}
}
void decidecol(int *q)   // decide column no. of entered integer
{
switch(col)
	{
	case 6:
	*q=0;
	break;
	case 10:*q=1;
	break;
	case 14:*q=2;
	break;
	case 18:*q=3;
	break;
	case 22:*q=4;
	break;
	case 26:*q=5;
	break;
	case 30:*q=6;
	break;
	case 34:*q=7;
	break;
	case 38:*q=8;
	break;
       }
}
void submit()
{
int flag=0,i,j;
char ans[9][9]={
		   {'9','8','2','1','7','6','3','4','5'},
		   {'7','6','1','5','3','4','9','2','8'},
		   {'4','3','5','8','2','9','6','1','7'},
		   {'1','7','6','3','8','2','5','9','4'},
		   {'5','4','3','9','6','1','7','8','2'},
		   {'8','2','9','7','4','5','1','3','6'},
		   {'2','9','8','6','1','7','4','5','3'},
		   {'6','1','4','2','5','3','8','7','9'},
		   {'3','5','7','4','9','8','2','6','1'}};


	for(i=0;i<9;i++)      // compare with answer
	{
	 for(j=0;j<9;j++)
	 {
	 if(b[i][j]!=((int)ans[i][j]-'0'))
	 {
	 flag=1;
	 break;
	 }
	}
	}
    gotoxy(25,23);
    if(flag==1)
    printf("\n YOU LOSE \n");

    else
    printf("\n YOU WIN \n");
    getch();


}