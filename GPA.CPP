#include<iostream.h>
#include<conio.h>

class student
{
private:
char name[20],sg[8],lg[4];
int sub,lab;
float sgpa,credits;

public:
void getdata();
void calc();
void display();
};

 void subcalc(float &total1,float pt,char s[],int size);

void student::getdata()
{
int i;
cout<<"\n Enter your name\n";
cin>>name;
cout<<"\nHow many subjects?\n";
cin>>sub;
cout<<"\nHow many labs?\n";
cin>>lab;
cout<<"\nCredits=";
cin>>credits;
cout<<"\n Enter grades of your "<<sub<<" subjects\n";

 for(i=0;i<sub;i++)
 cin>>sg[i];

  cout<<"\n Enter grades of your "<<lab<<" subjects\n";

  for(i=0;i<lab;i++)
   cin>>lg[i];
}

void student::calc()
{

float total=0;
subcalc(total,4,sg,sub);
subcalc(total,1.5,lg,lab);
  sgpa=total/credits;
}

void student::display()
{
cout<<"\n SGPA="<<sgpa;
}

void main()
{
student s;
clrscr();
s.getdata();
s.calc();
s.display();
getch();
}

 void subcalc(float &total1,float pt,char s[],int size)
  {
   int i;
   for(i=0;i<size;i++)
   {
    switch(s[i])
    {
	case 's'|'S':total1+=10*pt;
	     break;

	case 'a'|'A':total1+=9*pt;
	     break;

	case 'b'|'B':total1+=8*pt;
	     break;

	case 'c'|'C':total1+=7*pt;
	     break;

	case 'd'|'D':total1+=6*pt;
	     break;

	case 'e'|'E':total1+=5*pt;
	     break;
	case 'f'|'F':total1+=0;
	     break;
	}
    }
   }