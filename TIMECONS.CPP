#include<iostream.h>
#include<conio.h>
class time1
{
int hr;
int min;
int sec;
public:
       time1()
       {
       hr=min=sec=0;
       }
       time1(int h,int m,int s)
       {
	hr=h;
	min=m;
	sec=s;
       }
       void display()
       {
       cout<<hr<<" hours "<<min<<" minutes "<<sec<<" seconds\n";
       }
       void sum(time1,time1);
};

void time1::sum(time1 t1,time1 t2)
{
sec=t1.sec+t2.sec;
min=sec/60;
sec=sec%60;
min+=t1.min+t2.min;
hr=min/60;
min=min%60;
hr+=t1.hr+t2.hr;
if(hr>=24)
{
hr=hr%24;
}
}

void main()
{
time1 t1,t2,t3;
int h,m,s;
clrscr();
cout<<"enter time in hour:minute:second format for time 1 \n";
cin>>h>>m>>s;
t1=time1(h,m,s);
cout<<"enter time in hour:minute:second format for time 2 \n";
cin>>h>>m>>s;
t2=time1(h,m,s);

t3.sum(t1,t2);
cout<<"T1=";
t1.display();
cout<<"T2=";
t2.display();
cout<<"T3=";
t3.display();
getch();
}
