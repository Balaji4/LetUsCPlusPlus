#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#define size 5
class list
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
}