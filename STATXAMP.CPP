#include<iostream.h>
#include<conio.h>
class stat
{
static int a;
public:static void inc()
      {
       ++a;
      }
      void set(int x)
      {
      a=x;
      }
      void show()
      {
      cout<<"\nA="<<a;
      }
};

int stat::a;
void main()
{
stat r,s;
int x;
clrscr();
cout<<"\n Setting variable A by object s \n";
cout<<"\n Enter value for A \n";
cin>>x;
s.set(x);
cout<<"\n Value of A by object S is ";
s.show();
cout<<"\n Value of A by object R is ";
r.show();
cout<<"\n Changing A by static member function \n";
stat::inc();
cout<<"\n Now A is \n";
s.show();
cout<<"\n Changing A by object R \n";
r.inc();
cout<<"\n Now A by object R is ";
r.show();
getch();
}