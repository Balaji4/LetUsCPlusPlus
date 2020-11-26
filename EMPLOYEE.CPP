#include<iostream.h>
#include<conio.h>
#include<iomanip.h>
class emp
{
private:
	int empno;
	char name[15];
	float basic,da,total,it,ns;
public:
       void getdata(int);
       void calc();
       void display();
};

void emp::getdata(int j)
{
cout<<"\n enter name,emp number,basic salary of employee "<<(j+1)<<endl;
cin>>name>>empno>>basic;
}

void emp::calc()
{
da=0.52*basic;
total=da+basic;
it=0.30*total;
ns=basic+da-it;
}

void emp::display()
{
cout<<name<<"\t\t\t"<<empno<<"\t\t\t"<<ns;
}


void main()
{
int n;
emp *p;
clrscr();
cout<<"\n How many employees?\n";
cin>>n;
p=new emp[n];
cout<<"\n Enter the details of "<<n<<" employee\n";
for(int i=0;i<n;i++)
{
p[i].getdata(i);
}
for(i=0;i<n;i++)
{
p[i].calc();
}
cout<<"Details of employees\n";
cout<<"NAME\t\t\tEMP NO.\t\t\tNET SALARY\n";
for(i=0;i<n;i++)
{
cout<<"\n";
p[i].display();
}
getch();
delete []p;
}
