#include<iostream.h>
#include<conio.h>
#include<iomanip.h>
struct elect
{
float bill;
float unit;
char name[15];
};

void main()
{
struct elect *p;
int i,n;
float xunit;
clrscr();
cout<<"How many users\n";
cin>>n;
p=new elect [n];
for(i=0;i<n;i++)
{
cout<<"\n enter user name , units consumed for user"<<(i+1)<<endl;
cin>>((p+i)->name);
cin>>((p+i)->unit);
}

for(i=0;i<n;i++)
{
  (p+i)->bill=50;
  xunit=(p+i)->unit;
  if(xunit<=100)
  {
   (p+i)->bill+=0.6*xunit;
  }

    if(xunit>100&&xunit<=300)
    {
     xunit-=100;
     (p+i)->bill+=60;
     (p+i)->bill+=xunit*0.8;
    }
      if(xunit>300)
      {
      xunit-=300;
      (p+i)->bill+=(60+80);
      (p+i)->bill+=(0.9)*xunit;
       }
 if((p+i)->bill>300)
{
(p+i)->bill+=0.15*((p+i)->bill);
}
}
cout<<"NAME\t\tUNITS\t\tBILL\n";
for(i=0;i<n;i++)
{
cout<<endl<<(p+i)->name;
cout<<"\t\t"<<(p+i)->unit;
cout<<"\t\t"<<setprecision(4)<<(p+i)->bill;
}

delete [] p;
getch();
}