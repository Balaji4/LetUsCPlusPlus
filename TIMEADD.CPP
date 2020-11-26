#include<iostream.h>
#include<conio.h>
class time
{
int hr;
int min;
public:
       void gettime()
       {
       cout<<"enter time in hour:minute format\n";
       cin>>hr>>min;
       }
       void display()
       {
       cout<<hr<<" hours "<<min<<" minutes\n";
       }
       void sum(time,time);
};

void time::sum(time t1,time t2)
{
min=t1.min+t2.min;
hr=min/60;
min=min%60;
hr+=t1.hr+t2.hr;
}

void main()
{
time t1,t2,t3;
clrscr();
t1.gettime();
t2.gettime();
t3.sum(t1,t2);
cout<<"T1=";
t1.display();
cout<<"T2=";
t2.display();
cout<<"T3=";
t3.display();
getch();
}
