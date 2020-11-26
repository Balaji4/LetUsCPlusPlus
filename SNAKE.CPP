#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<iomanip.h>
#include<stdio.h>
#include<stdlib.h>

struct user
{
char name[15];
int pt;
};

void mov();
int  fn();
void level();
void level1();
void level2();
void level3();
void grade(struct user r[]);


int del=200;
int c[4]={33,34,35,36},r[4]={12,12,12,12};
char ch='d',*a="****"; //"\255\255\255\1";

void main()
{
int z=0;
char choice,check;
  struct user s[5]={"\0",0};
conti: clrscr();
	 randomize();
       textcolor(LIGHTBLUE);
    textbackground(BLACK);
    _setcursortype(_NOCURSOR);
   printf("\t\tMAIN MENU\n");
   printf("\t1:Launch Game\n\t2:Game level\n\t3:Best Grade\n\t4:Exit");
   choice=getch();
   switch(choice)
   {

   case '1':printf("\n enter your name:");
	    scanf("%s",&s[z].name);
	    s[z].pt=fn();
	    z++;
	    goto conti;
	   // break;
   case '2':level();
	    goto conti;
	   //  break;
   case '3':grade(s);
	    break;
   case '4'://window(10,10,40,11);
	   // textcolor(BLUE);
	    //textbackground(BLACK);
	    clrscr();
	    printf("\n\n\n\n\t\tExit? [YES/NO]\n");
	    check=getch();
	    clrscr();
	    if(check=='n'||check=='N')
	    {
	     clrscr();
	     goto conti;
	    }
	   exit(0);
	  break;
   default:exit(1);

   }
   printf("\n Would you like to continue\n");
   check=getch();
   if(check=='y'||check=='Y')
   {
   goto conti;
   }
   else
   printf("Thank you \n");
   getch();
}


int fn()
{
while(1)
{
ch=getch();
while(!kbhit())
{
for(int i=0;i<4;i++)
{

gotoxy(c[i],r[i]);
printf("%c",a[i]);

}     //for end
delay(del);
mov();
clrscr();
}              //inner while
//ch=getch();
}                      //outer while
returnl 0;
}

void mov()
{
switch(ch)
{
case 'w':r[0]--;
	 r[1]=r[0]-1;
	 r[2]=r[0]-2;
	 r[3]=r[0]-3;
	 c[1]=c[2]=c[3]=c[0];
	 a[3]=1;
	 a[2]=254;
	 a[1]=a[0]=254;
	 break;
case 'a':c[3]--;
	 c[2]=c[3]-1;
	 c[1]=c[3]-2;
	 c[0]=c[3]-3;;
	r[1]=r[2]=r[3]=r[0];
	a[1]=a[2]=a[3]=254;
	 a[0]=1;
	break;
case 'd':c[3]++;
	c[2]=c[3]-1;
	c[1]=c[3]-2;
	c[0]=c[3]-3;
	r[1]=r[2]=r[3]=r[0];
	 a[0]=a[1]=a[2]=254;
	 a[3]=1;
	break;
case 'x':r[0]++;
	 r[1]=r[0]+1;
	 r[2]=r[0]+2;
	 r[3]=r[0]+3;
	 c[1]=c[2]=c[3]=c[0];
	a[0]=a[1]=254;
	a[2]=254;
	a[3]=1;
	break;
case 'l':exit(0);
//default:
	 //c[4]++;
	//break;
}
}



void grade(struct user r[])
{
int i;
printf("\n Best Grades\n");
for(i=0;i<5;i++)
{
printf("\n %d:%s %d",(i+1),r[i].name,r[i].pt);
}

}


void level()
{
char l;
clrscr();

printf("\t\t 1:Level 1\n2:Level 2\n3:Level 3\n");
l=getch();
 switch(l)
 {
 case 1:level1();
	break;
 case 2:level2();
	 break;
 case 3:level3();
	break;
 default:return;
 }
}

void level1()
{
del=200;
}

void level2()
{
del=100;
}

void level3()
{
del=50;
}




