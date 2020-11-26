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

class test:virtual public student
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

class sports:public virtual student
{
protected:float score;
public:void getscore(float s)
       {
       score=s;
       }
       void putscore()
       {
       cout<<"\n Sports wt:"<<score;
       }
};
class result:public test,public sports
{
float total;
public:void display();
};

void result::display()
{
total=sub1+sub2+score;
putnum();
putmarks();
putscore();
cout<<"\n Total ="<<total<<"\n";
}

void main()
{
result student1;
int r;
float m1,m2,s;
clrscr();
cout<<"\n Enter student's roll no.\n";
cin>>r;
student1.getnum(r);
cout<<"\n Enter marks in two subjects \n";
cin>>m1>>m2;
student1.getmarks(m1,m2);
cout<<"\n Enter score in sports \n";
cin>>s;
student1.getscore(s);
student1.display();
getch();
}