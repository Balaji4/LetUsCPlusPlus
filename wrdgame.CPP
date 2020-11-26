#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<dos.h>
void grade()
{
}
void level()
{
}

void  fn();
  int i,j,k,r,ch;
   char p[10][12]={"class\0","book\0","factory\0","time\0","work\0" ,"electronics\0","data\0","numbers\0","sports\0","machine\0"};
   char a[12],hold[12],q[5][12];
void main()
{

   clrscr();
   randomize();
   printf("\t\tMAIN MENU\n");
   printf("\t1:Launch Game\n\t2:Game level\n\t3:Best Grade\n\t4:Exit");
   ch=getch();
   switch(ch)
   {
   case '1':fn();

   case '2':level();
	     break;
   case '3':grade();
	    break;
   case '4':exit(0);
	  break;
   default:exit(1);

   }
}

void  fn()
  {
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
   printf("\n You win");
   }
   else
   printf("\n You lose");
   getch();
  }
