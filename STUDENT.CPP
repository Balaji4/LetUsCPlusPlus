#include<iostream.h>
#include<conio.h>
#include<iomanip.h>
class stud
{
private:
	int m[3],l1,l2;
	char name[15],usn[11];
	float avg;
public:
       void getdata(int);
       void calc();
       void display();
};

void stud::getdata(int j)
{
cout<<"\n enter name,usn and 3 test marks of student "<<(j+1)<<endl;
cin>>name>>usn;
 for(int i=0;i<3;i++)
 {
  cin>>m[i];
 }
}

void stud::calc()
{
if(m[0]>m[1])
{
 if(m[0]>m[2])
 {
  l1=m[0];
	if(m[1]>m[2])
	l2=m[1];
	else
	l2=m[2];
 }
 else
 {
 l1=m[2];
 l2=m[0];
 }
}
else
 if(m[1]>m[2])
 {
  l1=m[1];
  if(m[0]>m[2])
  l2=m[0];
  else
  l2=m[2];
 }
 else
 {
  l1=m[2];
  if(m[0]>m[1])
  l2=m[0];
  else
  l2=m[1];
 }
avg=(float)(l1+l2)/2;
}

void stud::display()
{
cout<<name<<"\t\t\t"<<usn<<"\t\t"<<avg;
}


void main()
{
stud p[10];
clrscr();
for(int i=0;i<10;i++)
{
p[i].getdata(i);
}
for(i=0;i<10;i++)
{
p[i].calc();
}
cout<<"Details of students\n";
cout<<"NAME\t\t\tUSN\t\t\tAVERAGE\n";
for(i=0;i<10;i++)
{
cout<<"\n";
p[i].display();
}
getch();
}
