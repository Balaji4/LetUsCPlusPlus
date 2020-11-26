#include<iostream.h>
#include<conio.h>
class sample
{
int a,b;
public:void getdata()
      {
      cout<<"\n enter two values \n";
      cin>>a>>b;
      }
      void display()
      {
      cout<<"\n Given two values are "<<a<<" "<<b;
      }
     operator int()
     {
     return (a+b);
     }
};

void main()
{
sample s;
int m;
clrscr();
s.getdata();
s.display();
m=int(s);
cout<<"\n sum="<<m;
getch();
}