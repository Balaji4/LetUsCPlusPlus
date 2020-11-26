#include<conio.h>
#include<stdlib.h>
#include<iostream.h>
class DB;
class DM
{
float mtr,cm;
public:void getdata1();
       void display1();
friend DM convert1(DM,DB);
friend DB convert2(DM,DB);
};

class DB
{
float ft,inc;
public:void getdata2();
       void display2();
friend DM convert1(DM,DB);
friend DB convert2(DM,DB);
};

void DM::getdata1()
{
cout<<"\n enter the values in meter and centimeter\n";
cin>>mtr>>cm;
}

void DB::getdata2()
{
cout<<"\n enter the values in feet and inch\n";
cin>>ft>>inc;
}

void DM::display1()
{
cout<<"\n"<<mtr<<" meter "<<cm<<" centimeter\n";
}

void DB::display2()
{
cout<<"\n"<<ft<<" feet "<<inc<<" inch";
}

DM convert1(DM c1,DB c2)
{
c1.mtr+=c2.ft*.3048;
c1.cm+=c2.inc*2.54;
c1.mtr+=c1.cm/100;
c1.cm=(int)c1.cm%100;

return c1;
}

DB convert2(DM c1,DB c2)
{
c2.ft=c2.ft+c1.mtr*3.2808;
c2.inc=c2.inc+c1.cm*0.3937;
return c2;
}

void main()
{
DM c1;
DB c2;
int ch;
clrscr();
c1.getdata1();
c2.getdata2();
cout<<" Given values are \n";
c1.display1();
c2.display2();
cout<<"\n\n 1:Convert feet to meter, inch to centimeter\n";
cout<<"\n 2:Convert meter to feet, centimeter to inch\n";
cout<<"\n enter your choice\n";
cin>>ch;
switch(ch)
{
case 1:c1=convert1(c1,c2);
	break;
case 2:c2=convert2(c1,c2);
	break;
default:exit(0);
}
cout<<"\n Total sum of feet with meter and inch with centimeter are\n";
if(ch==1)
{
c1.display1();
}
else
c2.display2();
getch();
}
