#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#define size 5
class stack
{
int top,stk[size];
public:stack()
       {
	top=-1;
	}
	stack operator+(int);
	stack operator-();
friend ostream& operator <<(ostream &,stack );
};

stack stack::operator+(int i)
{
if(top==size-1)
{
cout<<"\n Stack overflow \n";
return *this;
}
else
{
stk[++top]=i;
return *this;
}
}
stack stack::operator-()
{
if(top==-1)
{
cout<<"\n Stack empty \n";
return *this;
}
else
{
cout<<"\n Poped element ="<<stk[top--];
return *this;
}
}

ostream& operator<<(ostream &out,stack s)
{
 if(s.top==-1)
 {
 out<<"\n stack empty,nothing to display\n";
 return out;
 }
 else
 {
 out<<"\n Contents are \n";
 for(int i=0;i<=s.top;i++)
  {
   out<<"\t"<<s.stk[i];
   }
   return out;
 }
}

void main()
{
stack s;
int ch,item;
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
  case 1:cout<<"\n enter item to be inserted \n";
	 cin>>item;
	 s=s+item;
	 break;

  case 2:s=-s;
	 break;

  case 3:cout<<s;
	 break;

  default:exit(0);
  }
 }
// getch();
}