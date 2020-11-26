
#include<iostream.h>
#include<conio.h>
class invent2;
class invent1
{
int code;
int item;
float price;
public:void getdata()
       {
       cout<<"\n enter code total items and price of each product \n";
       cin>>code>>item>>price;
       }
       void display()
       {
       cout<<"Code="<<code;
       cout<<"\n Items="<<item;
       cout<<"\n price="<<price;
       }
       int getcode()
       {
       return code;
       }
       int getitem()
       {
       return item;
       }
       float getprice()
       {
       return price;
       }

};

class invent2
{
int code;
float value;
public: invent2()
	{
	code=value=0;
	}
	invent2(invent1 r)
	{
	code=r.getcode();
	value=r.getitem()*r.getprice();
	}
	void display()
	{
	cout<<"\n Code="<<code;
	cout<<"\n Value ="<<value;
	}

};




void main()
{
invent1 r;
invent2 s;
clrscr();
r.getdata();
cout<<"\n Product details -invent type 1 \n";
r.display();
s=r;
cout<<"\n Total price details -invent type 2\n";
s.display();
getch();
}