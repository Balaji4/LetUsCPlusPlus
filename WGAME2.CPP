
#include <dos.h>
#include <graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<dos.h>
int posX, posY, posKlik;
struct user
{
char name[15];
int pt;
};
union REGS in, out;
void detect ()
{
	while (!kbhit () )
	{
		int x,y;
		in.x.ax = 3;
		int86 (0X33,&in,&out);
		if (out.x.bx == 1)
		{
			x = out.x.cx;
			y = out.x.dx;
			printf ("\nLeft || X - %d  Y - %d", x, y);
		}
		delay (200); // Otherwise due to quick computer response 100s of words will get print
	}
}
int  fn();
void level();
void level1();
void level2();
void level3();
void grade(struct user r[]);
void read_mouse(void)
{
   asm{
      mov ax,3h
      int 33h
      mov posX,cx // posX posisi X Mouse
      mov posY,dx // posY posisi Y Mouse
      mov posKlik,bx // posKlik keadaan Mouse, saat diklik atau tidak, dan tombol mana yang diklik
   }
}
void show_mouse(void)
{
   asm{
      mov ax,1h
      int 33h
   }
}

void set_mouse(void)
{
   asm{
      mov ax,4h
      mov cx,0
      mov dx,479
      int 33h
   }
}



int i,j,k,r,ch,ct;
char p[10][12]={"class\0","book\0","factory\0","time\0","work\0" ,"electronics\0","data\0","numbers\0","sports\0","machine\0"};
char a[12],hold[12],q[5][12];

void main()
{
     struct user s[5]={"\0",0};
    int m=0,z;
    char check,pa;
conti:   clrscr();
	 randomize();
       textcolor(m+1);
    textbackground(m);

   printf("\t\tMAIN MENU\n");
   printf("\t1:Launch Game\n\t2:Game level\n\t3:Best Grade\n\t4:Exit");

_setcursortype(_NOCURSOR);
show_mouse();
set_mouse();
read_mouse();
gotoxy(posX,posY);
	detect ();
   ch=getch();
   switch(ch)
   {
   case '1':if(z==5)
	    {
	    z=0;
	    }
	    printf("\n enter your name:");
	    scanf("%s",&s[z].name);
	    s[z].pt=fn();
	    z++;
	    goto conti;
	    break;
   case '2':level();
	    goto conti;
	     break;
   case '3':grade(s);
	    break;
   case '4':exit(0);
	  break;
   default:exit(1);

   }
   /*
   switch(ch)
   {
 /*  case '1':if(z==5)
	    {
	    z=0;
	    }
	    printf("\n enter your name:");
	    scanf("%s",&s[z].name);
	    s[z].pt=fn();
	    z++;
	    goto conti;
	    break;
   case '2':level();
	    goto conti;
	     break;
   case '3':grade(s);
	    break;
   case '4':exit(0);
	  break;
   default:exit(1);

   }
   */
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

 int  fn()
  {
  int pt;
  char pa;
   clrscr();
   printf("five random strings are\n\n");
   for(i=0; i<5; i++)
   {

	 k=rand()%10;
	 strcpy(q[i],p[k]);
       printf("%s\n",q[i]);

    }
    delay(3000);
    clrscr();
    printf("\n find out the missing string\n");
    for(i=0,j=3; i<4,j>=0; i++,j--)
   {
       printf("%s\n",q[j]);
    }
    strcpy(a,q[i]);
   scanf("%s",hold);
   r=strcmpi(a,hold);
   if(r==0)
   {
   printf("\n You win %c",r+1);
   pt++;
    printf("\n1:Play Again \n2:Goto main menu\n");
	    pa=getch();
	    if(pa=='1')
	    {
	    pt+=fn();
	    }

   }
   else
   {
   printf("\n You lose");
   delay(1000);
  }
   return pt;
  }


void grade(struct user r[])
{
int i;
printf("\n Best Grades\n");
for(i=0;i<5;i++)
{
printf("\n %d:%s%d",(i+1),r[i].name,r[i].pt);
}

}


void level()
{
char l;
clrscr();
printf("1:Level 1\n2:Level 2\n3:Level 3\n");
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
}

void level2()
{
}

void level3()
{
}

/*void checkmousepos()
{

}       */



