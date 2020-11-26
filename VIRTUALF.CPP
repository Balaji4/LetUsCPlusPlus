#include<iostream.h>
#include<conio.h>

class base
{
public:
void display()
{
cout<<"\n Display Base \n";
}

virtual void show()
{
cout<<"\n Show Base \n";
}
};

class derived:public base
{
public:
void display()
{
cout<<"\n Display derived \n";
}
void show()
{
cout<<"\n Show Derived \n";
}
};

void main()
{
base b;
derived d;
base *bp;
clrscr();
cout<<"\n Base ptr points to base\n";
bp=&b;
bp->display();
bp->show();
cout<<"\n Base ptr points to derived\n";
bp=&d;
bp->display();
bp->show();
getch();
}