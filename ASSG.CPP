#include<iostream.h>
#include<conio.h>
#include<ctype.h>
#include<math.h>
using namespace std;
void div(double,double);
void main()
{
double x,y;
cout<<"Enter values\n";
cin>>x>>y;
try
{

if(ischar(x))
throw x;
if(ischar(y))
throw y;
}
catch(double a)
{
cout<<"wrong data type\n";
exit(0);
}
try
{
cout<<"divide by 0\n";
}
getch();
}
void div(double a,double b)
{
double c;
if(b==0)
throw b;
c=a/b;
cout<<"quotient=\n"<<c;
}

