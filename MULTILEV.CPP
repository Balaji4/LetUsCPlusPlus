#include<iostream.h>
#include<conio.h>
class student
{
protected:
int rollnum;
public:
void getnum(int a);
void putnum();
};

void student::getnum(int a)
{
rollnum=a;
}

void student::putnum()
{
cout<<"\n Roll Number:"<<rollnum<<endl;
}

class test:public student
{
protected:
float sub1,sub2;
public: void getmarks(float,float);
void putmarks();
};

void test::getmarks(float x,float y)
{
sub1=x;
sub2=y;
}

void test::putmarks()
{
cout<<"\n Marks in sub1="<<sub1;
cout<<"\n Marks in sub2="<<sub2;
}

class result:public test
{
float total;
public:void display();
};

void result::display()
{
total=sub1+sub2;
putnum();
putmarks();
cout<<"\n Total ="<<total<<"\n";
}

void main()
{
result student1;
int r;
float m1,m2;
clrscr();
cout<<"\n Enter student's roll no.\n";
cin>>r;
student1.getnum(r);
cout<<"\n Enter marks in two subjects \n";
cin>>m1>>m2;
student1.getmarks(m1,m2);
student1.display();
getch();
}