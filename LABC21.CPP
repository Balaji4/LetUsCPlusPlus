#include<iostream.h>
#include<conio.h>
class sample
{
int a,b;
public:void set();
       void setp(sample &s);
friend int add(sample s);
       void display()
       {
	cout<<"A="<<a;
	cout<<endl<<"B="<<b;
       }
};

void sample::set()
{

cout<<"\n Enter two values\n";
cin>>a>>b;

}

void sample::setp(sample &s)
{
int sample::*p=&sample::a;
int sample::*q=&sample::b;
cout<<"\n Enter A and B\n";
cin>>(s.*p)>>(s.*q);
}

int add(sample s)
{

return (s.a+s.b);
}



void main()
{
sample s,*r=&s;
int sum=0;

clrscr();
cout<<"\n Setting a and b by object s\n";
s.set();
sum=add(s);
cout<<"\n Given values are\n";
s.display();
cout<<"\n sum by simple friend function\n";
cout<<"\n  Sum="<<sum;
cout<<"\n Setting a and b by pointer to data members object s\n";
s.setp(s);
cout<<"\n Given values are\n";
s.display();
sum=add(*r);
cout<<"\n sum by simple by pointer to object \n";
cout<<"\n  Sum="<<sum;
getch();
}