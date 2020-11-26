#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#define minrow 2
#define maxrow 10
#define mincol 7
#define maxcol 17
#define msg { printf(" WON"); getch(); exit(0); }
#define msgu { gotoxy(25,25); textcolor(RED); cprintf("YOU");}
#define msgc { gotoxy(25,25); textcolor(RED); cprintf("COMPUTER");}
void table();
void accept(char);
void update(int,int);
void compaccept();
void win(char);
int  check(int,int);
int row1(char b);
int row2(char b);
int row3(char b);
int col1(char b);
int col2(char b);
int col3(char b);
int dia1(char b);
int dia2(char b);
int row=2,col=7,pos,both[3][3]={0,0,0,0,0,0,0,0,0};
int comp[3][3]={0,0,0,0,0,0,0,0,0};
int user[3][3]={0,0,0,0,0,0,0,0,0};

int bc=0,cc=0,uc=0,ini,inj;

void main()
{
table();
char dir;
int or,oc;
gotoxy(col,row);
while(1)
{
while(!kbhit)
;
dir=getch();
switch(dir)
{
case 'w': or=row;
	  row-=4;
	  if(row<minrow||row>maxrow)
	  {
	   row=or;
	   break;
	  }
	   gotoxy(col,row);
	   break;
case 'd':oc=col;
	 col+=5;
	 if(col<mincol||col>maxcol)
	  {
	   col=oc;
	   break;
	  }
       gotoxy(col,row);
       break;
case 'x':or=row;
	 row+=4;
	 if(row<minrow||row>maxrow)
	  {
	   row=or;
	   break;
	  }
	 gotoxy(col,row);
       break;
case 'a':oc=col;
	 col-=5;
	 if(col<mincol||col>maxcol)
	  {
	   col=oc;
	   break;
	  }
	 gotoxy(col,row);
       break;
case '0':accept(dir);
	 break;
case 'l':exit(0);

}

}

}

void accept(char d)         //to accept user's entry in matrix
{

 if(check(row,col)==1)     //if valid position then fill user's entry
 {

  gotoxy(col,row);
  printf("%c",d);
  update(row,col);     //update user's entry in main matrix
  user[ini][inj]=1;   //update user's entry in user's matrix
  bc++;              //main count++
  uc++;             //user's count++
  win('u');     //check if user has won the match
  if(bc==9)     //if 9 entries in main table
  {             //then simply wait for a key to press & exit
   getch();
   exit(0);
  }
  compaccept();     //else allow comp to play
  gotoxy(col,row);  //revert back to user's last entry position
 }

}

void update(int r,int c)    //update matrix entry of both comp & user
{
 if(r==2&&c==7)      //[0][0] in main matrix
 {
 both[0][0]=1;
 ini=inj=0;          //index i=0,index j=0
 }
else
 if(r==2&&c==12)   //[0][1] in main matrix
 {
 both[0][1]=1;
 ini=0;           //index i=0
 inj=1;          //index j=1
 }
else
 if(r==2&&c==17)    //[0][2] in main matrix
 {
 both[0][2]=1;
 ini=0;        //index i=0
 inj=2;        // index j=2
 }
else
 if(r==6&&c==7)   //[1][0] in main matrix
 {
  both[1][0]=1;
  ini=1;         //index i=1
  inj=0;         //index j=0
 }
else
 if(r==6&&c==12)   //[1][1] in main matrix
 {
 both[1][1]=1;
 ini=inj=1;       // index i=j=1
 }
else
 if(r==6&&c==17)    //[1][2] in main matrix
 {
 both[1][2]=1;
 ini=1;          // index i=1
 inj=2;          // index j=2
 }
else
 if(r==10&&c==7)  // [2][0] in main matrix
 {
 both[2][0]=1;
 ini=2;        //index i=2
 inj=0;         // index j=0
 }
else
 if(r==10&&c==12) // [2][1] in main matrix
 {
 both[2][1]=1;
 ini=2;          // index i=2
 inj=1;          // index j=1
 }
else
 if(r==10&&c==17)   //[2][2] in main matrix
 {
 both[2][2]=1;
 ini=inj=2;     // index i=j=2
 }
}



int check(int r,int c)
{
if(r==2&&c==7&&both[0][0]==0) //if [0][0] is empty in main matrix
{return 1; }
else
 if(r==2&&c==12&&both[0][1]==0) //[0][1]  is empty
{return 1;   }
else
 if(r==2&&c==17&&both[0][2]==0)  //[0][2] is empty
{return 1;}
else
 if(r==6&&c==7&&both[1][0]==0)  //[1][0] is empty
{return 1;  }
else
 if(r==6&&c==12&&both[1][1]==0)  //[1][1] is empty
{return 1; }
else
 if(r==6&&c==17&&both[1][2]==0)   //[1][2] is empty
{return 1;   }
else
 if(r==10&&c==7&&both[2][0]==0)   //[2][0] is empty
{return 1; }
else
 if(r==10&&c==12&&both[2][1]==0)  //[2][1] is empty
{return 1;   }
else
 if(r==10&&c==17&&both[2][2]==0)  //[2][2] is empty
{return 1;   }
else return 0;
}





void table()  // to create 3x3 table
{
int c=5,i,j;
char ch=179;   //char verticle line
clrscr();
for(i=1;i<4;i++)
{

for(j=1;j<12;j++)
{
gotoxy(c,j);
if(j%4==0&&c<=15)
{
printf("-----\n");
continue;
}
if(i==2||i==3)
printf("%c",ch);
}
c+=5;
}
}

void win(char b)    // to check who won
{
int i,j;
int *p;
if(b=='u')        //if b==u check for user
{
 p=&user[0][0];
}
else
{
 p=&comp[0][0];    // else check for comp
}


if((*(p+0*3+0)==1)&&(*(p+0*3+1)==1)&&(*(p+0*3+2)==1)) //1st row=000 or xxx
  {
  if(b=='u')               //if user
  msgu                    //display user won
  else msgc              //else comp won
  msg                    //macro for 'won' and exit
  }
else if((*(p+1*3+0))==1&&(*(p+1*3+1))==1&&(*(p+1*3+2))==1) //2nd row=000 or xxx
  {
  if(b=='u')
  msgu
  else msgc
  msg}
else if((*(p+2*3+0))==1&&(*(p+2*3+1))==1&&(*(p+2*3+2))==1) //3rd row=000 or xxx
  {if(b=='u')
  msgu
  else msgc
  msg}
else if((*(p+0*3+0))==1&&(*(p+1*3+0))==1&&(*(p+2*3+0))==1)  //1st col=000 or xxx
  {
  if(b=='u')
  msgu
  else msgc
  msg}
else if((*(p+0*3+1))==1&&(*(p+1*3+1))==1&&(*(p+2*3+1))==1) //2nd col=000 or xxx
  {if(b=='u')
  msgu
  else msgc
  msg}
else if((*(p+0*3+2)==1)&&(*(p+1*3+2)==1)&&(*(p+2*3+2)==1))  //3rd col=000 or xxx
  {
  if(b=='u')
  msgu
  else msgc
  msg}
else if((*(p+0*3+0))==1&&(*(p+1*3+1))==1&&(*(p+2*3+2)==1))  //diagonal \
  {
  if(b=='u')
  msgu
  else msgc
  msg}
else if(*(p+0*3+2)==1&&(*(p+1*3+1))==1&&(*(p+2*3+0))==1)    // diagonal /
 {
 if(b=='u')
  msgu
  else msgc
 msg}
}

void compaccept()
{
int r,c;

if(row1('c')==1)  // if comp's 1st row is near to win
{
return;
}
else if(row2('c')==1) // if comp's 2nd row is near to win
      {
      return;
      }
else if(row3('c')==1) //if comp's 3rd row is near to win
      {
      return;
      }
else if(col1('c')==1) // if comp's 1st col is near to win
     {
     return;
     }
else if(col2('c')==1) // if comp's 2nd col is near to win
     {
     return;
     }
else if(col3('c')==1) // if comp's 3rd col is near to win
     {
     return;
     }
else if(dia1('c')==1) // if comp's diagonal \ is near to win
     {
     return;
     }
else if(dia2('c')==1) // if comp's diagonal /is near to win
     {
     return;
     }
else if(row1('u')==1)  // if user's 1st row is near to win
{
return;
}
else if(row2('u')==1)  // if user's 2nd row is near to win
      {
      return;
      }
else if(row3('u')==1)  // if user's 3rd row is near to win
      {
      return;
      }
else if(col1('u')==1)  // if user's 1st col is near to win
     {
     return;
     }
else if(col2('u')==1)  // if user's 2nd col is near to win
     {
     return;
     }
else if(col3('u')==1)  // if user's 3rd col is near to win
     {
     return;
     }
else if(dia1('u')==1)  // if user's diagonal / is near to win
     {
     return;
     }
else if(dia2('u')==1)  // if user's diagonal \ is near to win
     {
     return;
     }

else                //else generate randomly row n col
{
l:r=rand()%11;
c=rand()%18;

  if(check(r,c)==1)  //check if matrix position is valid
  {

   gotoxy(c,r);
   printf("x");
    bc++;
    cc++;
     update(r,c);
    comp[ini][inj]=1;
   win('c');
   return;

  }
else goto l;           // if not valid then again goto l to generate row n col
}
}


int row1(char b)    //row 1 for comp n user which is near to fill
{

int *p;
if(b=='u')   //to check user's row1 if he's near to win
{
 p=&user[0][0];
}
else
{
 p=&comp[0][0];      //else comp's row1
}

if(((*(p+0*3+0))==1)&&((*(p+0*3+1))==1))    //[0][0]&[0][1]
 {
  if(check(2,17)==1)
  {
   gotoxy(17,2);
   printf("x");
    bc++;
    cc++;
     update(2,17);
    comp[ini][inj]=1;
   win('c');
   return 1;
  }
}

else if(((*(p+0*3+0))==1)&&((*(p+0*3+2))==1))  //[0][0]&&[0][2]
     {
	if(check(2,12)==1)
	  {
	   gotoxy(12,2);
	   printf("x");
	    bc++;
	    cc++;
	     update(2,12);
	    comp[ini][inj]=1;
	   win('c');
	   return 1;
	  }
    }
else if(((*(p+0*3+1))==1)&&((*(p+0*3+2))==1))   //[0][1]&[0][2]
     {
	  if(check(2,7)==1)
	  {
	   gotoxy(7,2);
	   printf("x");
	    bc++;
	    cc++;
	     update(2,7);
	    comp[ini][inj]=1;
	   win('c');
	   return 1;
	  }
    }

return 0;


}

int row2(char b) //row2 of comp or user is near to win
{
int *p;
if(b=='u')   //to check user's row2 if he's near to win
{
 p=&user[0][0];
}
else
{
 p=&comp[0][0];      //else comp's row2
}
if(((*(p+1*3+0))==1)&&((*(p+1*3+1))==1))  //[1][0]&[1][1]
 {
  if(check(6,17)==1)
  {
   gotoxy(17,6);
   printf("x");
    bc++;
    cc++;
     update(6,17);
    comp[ini][inj]=1;
   win('c');
   return 1;
  }
}

else if(((*(p+1*3+0))==1)&&((*(p+1*3+2))==1))  //[1][0]&[1][2]
     {
	if(check(6,12)==1)
	  {
	   gotoxy(12,6);
	   printf("x");
	    bc++;
	    cc++;
	     update(6,12);
	    comp[ini][inj]=1;
	   win('c');
	   return 1;
	  }
    }
else if(((*(p+1*3+1))==1)&&((*(p+1*3+2))==1))     //[1][1]&[1][2]
     {
	  if(check(6,7)==1)
	  {
	   gotoxy(7,6);
	   printf("x");
	    bc++;
	    cc++;
	     update(6,7);
	    comp[ini][inj]=1;
	   win('c');
	   return 1;
	  }
    }

return 0;


}

int row3(char b)   //row3 of user or comp is near to win
{
int *p;
if(b=='u')   //to check user's row3 if he's near to win
{
 p=&user[0][0];
}
else
{
 p=&comp[0][0];      //else comp's row3
}
if(((*(p+2*3+0))==1)&&((*(p+2*3+1))==1))  //[2][0]&[2][1]
 {
  if(check(10,17)==1)
  {
   gotoxy(17,10);
   printf("x");
    bc++;
    cc++;
     update(10,17);
    comp[ini][inj]=1;
   win('c');
   return 1;
  }
}

else if(((*(p+2*3+0))==1)&&((*(p+2*3+2))==1)) //[2][0]&[2][2]
     {
	if(check(10,12)==1)
	  {
	   gotoxy(12,10);
	   printf("x");
	    bc++;
	    cc++;
	     update(10,12);
	    comp[ini][inj]=1;
	   win('c');
	   return 1;
	  }
    }
else if(((*(p+2*3+1))==1)&&((*(p+2*3+2))==1)) //[2][1]& [2][2]
     {
	  if(check(10,7)==1)
	  {
	   gotoxy(7,10);
	   printf("x");
	    bc++;
	    cc++;
	     update(10,7);
	    comp[ini][inj]=1;
	   win('c');
	   return 1;
	  }
    }

return 0;


}

int col1(char b)  //to check if user or comp's 1st col is near to win
{

int *p;
if(b=='u')   //to check user's col1 if he's near to win
{
 p=&user[0][0];
}
else
{
 p=&comp[0][0];      //else comp's col1
}
if(((*(p+0*3+0))==1)&&((*(p+1*3+0))==1)) //[0][1] &[1][0]
 {
  if(check(10,7)==1)
  {
   gotoxy(7,10);
   printf("x");
    bc++;
    cc++;
     update(10,7);
    comp[ini][inj]=1;
   win('c');
   return 1;
  }
}

else if(((*(p+0*3+0))==1)&&((*(p+2*3+0))==1))   //[0][0]&[2][0]
     {
	if(check(6,12)==1)
	  {
	   gotoxy(12,6);
	   printf("x");
	    bc++;
	    cc++;
	     update(6,12);
	    comp[ini][inj]=1;
	   win('c');
	   return 1;
	  }
    }
else if(((*(p+1*3+0))==1)&&((*(p+2*3+0))==1))  //[1][0]&[2][0]
     {
	  if(check(2,7)==1)
	  {
	   gotoxy(7,2);
	   printf("x");
	    bc++;
	    cc++;
	     update(2,7);
	    comp[ini][inj]=1;
	   win('c');
	   return 1;
	  }
    }

return 0;


}

int col2(char b)
{
int *p;
if(b=='u')   //to check user's col2 if he's near to win
{
 p=&user[0][0];
}
else
{
 p=&comp[0][0];      //else comp's col2
}
if(((*(p+0*3+1))==1)&&((*(p+1*3+1))==1))
 {
  if(check(10,12)==1)
  {
   gotoxy(12,10);
   printf("x");
    bc++;
    cc++;
     update(10,12);
    comp[ini][inj]=1;
   win('c');
   return 1;
  }
}

else if(((*(p+0*3+1))==1)&&((*(p+2*3+1))==1))
     {
	if(check(6,12)==1)
	  {
	   gotoxy(12,6);
	   printf("x");
	    bc++;
	    cc++;
	     update(6,12);
	    comp[ini][inj]=1;
	   win('c');
	   return 1;
	  }
    }
else if(((*(p+1*3+1))==1)&&((*(p+2*3+1))==1))
     {
	  if(check(6,7)==1)
	  {
	   gotoxy(7,6);
	   printf("x");
	    bc++;
	    cc++;
	     update(6,7);
	    comp[ini][inj]=1;
	   win('c');
	   return 1;
	  }
    }

return 0;


}

int col3(char b)
{
int *p;
if(b=='u')   //to check user's col3 if he's near to win
{
 p=&user[0][0];
}
else
{
 p=&comp[0][0];      //else comp's col3
}
if(((*(p+0*3+2))==1)&&((*(p+1*3+2))==1))
 {
  if(check(10,17)==1)
  {
   gotoxy(17,10);
   printf("x");
    bc++;
    cc++;
     update(10,17);
    comp[ini][inj]=1;
   win('c');
   return 1;
  }
}

else if(((*(p+0*3+2))==1)&&((*(p+2*3+2))==1))
     {
	if(check(6,17)==1)
	  {
	   gotoxy(17,6);
	   printf("x");
	    bc++;
	    cc++;
	     update(6,17);
	    comp[ini][inj]=1;
	   win('c');
	   return 1;
	  }
    }
else if(((*(p+1*3+2))==1)&&((*(p+2*3+2))==1))
     {
	  if(check(2,17)==1)
	  {
	   gotoxy(17,2);
	   printf("x");
	    bc++;
	    cc++;
	     update(2,17);
	    comp[ini][inj]=1;
	   win('c');
	   return 1;
	  }
    }

return 0;


}

/* col 7 12 17 row 2 6 10*/
int dia1(char b)
{
int *p;
if(b=='u')   //to check user's diagonal / if he's near to win
{
 p=&user[0][0];
}
else
{
 p=&comp[0][0];      //else comp's diagonal /
}
if(((*(p+0*3+0))==1)&&((*(p+1*3+1))==1))
 {
  if(check(10,17)==1)
  {
   gotoxy(17,10);
   printf("x");
    bc++;
    cc++;
     update(10,17);
    comp[ini][inj]=1;
   win('c');
   return 1;
  }
}

else if(((*(p+0*3+0))==1)&&((*(p+2*3+2))==1))
     {
	if(check(6,12)==1)
	  {
	   gotoxy(12,6);
	   printf("x");
	    bc++;
	    cc++;
	     update(6,12);
	    comp[ini][inj]=1;
	   win('c');
	   return 1;
	  }
    }
else if(((*(p+1*3+1))==1)&&((*(p+2*3+2))==1))
     {
	  if(check(2,7)==1)
	  {
	   gotoxy(7,2);
	   printf("x");
	    bc++;
	    cc++;
	     update(2,7);
	    comp[ini][inj]=1;
	   win('c');
	   return 1;
	  }
    }

return 0;



}

int dia2(char b)
{
int *p;
if(b=='u')   //to check user's diagonal \ if he's near to win
{
 p=&user[0][0];
}
else
{
 p=&comp[0][0];      //else comp's diagonal \
}
if(((*(p+0*3+2))==1)&&((*(p+1*3+1))==1))
 {
  if(check(10,7)==1)
  {
   gotoxy(7,10);
   printf("x");
    bc++;
    cc++;
     update(10,7);
    comp[ini][inj]=1;
   win('c');
   return 1;
  }
}

else if(((*(p+0*3+2))==1)&&((*(p+2*3+0))==1))
     {
	if(check(6,12)==1)
	  {
	   gotoxy(12,6);
	   printf("x");
	    bc++;
	    cc++;
	     update(6,12);
	    comp[ini][inj]=1;
	   win('c');
	   return 1;
	  }
    }
else if(((*(p+1*3+1))==1)&&((*(p+2*3+0))==1))
     {
	  if(check(2,17)==1)
	  {
	   gotoxy(17,2);
	   printf("x");
	    bc++;
	    cc++;
	     update(2,17);
	    comp[ini][inj]=1;
	   win('c');
	   return 1;
	  }
    }

return 0;
}

