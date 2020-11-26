#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<graphics.h>
#define size 5
/*class list
{
int top,stk[size];
public:list()
       {
	top=-1;
	}
	void push();
	void pop();
	void display();
};

void list::push()
{
int i;
cout<<"\n Enter item to be inserted \n";
cin>>i;
if(top==size-1)
{
cout<<"\n Stack overflow \n";
return;
}
stk[++top]=i;
}

void list::pop()
{
if(top==-1)
{
cout<<"\n Stack empty \n";
return;
}
else
{
cout<<"\n Poped element ="<<stk[top--];
}
}

void list::display()
{
 if(top==-1)
 {
 cout<<"\n stack empty,nothing to display\n";
 return;
 }
 else
 {
 cout<<"\n Contents are \n";
 for(int i=0;i<=top;i++)
  {
   cout<<"\t"<<stk[i];
   }
 }
}

void main()
{
list s;
int ch;
clrscr();
 for(;;)
 {
  cout<<"\n\tMENU\n";
  cout<<"1:PUSH \n";
  cout<<"2:POP \n";
  cout<<"3:DISPLAY\n";
  cout<<"4:EXIT \n";
  cout<<"\n Enter your choice\n";
  cin>>ch;
  switch(ch)
  {
  case 1:s.push();
	 break;

  case 2:s.pop();
	 break;

  case 3:s.display();
	 break;

  default:exit(0);
  }
 }
 getch();
} */
int main()
{
int gdriver = DETECT, gmode, errorcode;
   int left, top, right, bottom;

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

   left = getmaxx() / 2;
   top = getmaxy() / 2 ;
   right = getmaxx() / 2 + 100;
   bottom = getmaxy() / 2 + 150;

   /* draw a rectangle */
   rectangle(left,top,right,bottom);

   /* clean up */
   getch();
   closegraph();
   return 0;
}

