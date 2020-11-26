#include<iostream.h>
#include<conio.h>
class alpha
{
int x;
public://alpha(){}
 alpha(int i)
 {
 x=i;
 cout<<"\n alpha initialized \n";
 }
 void showx()
 {
 cout<<"\n X="<<x;
 }
};

class beta
{
float y;
public: //beta(){}
       beta(float j)
       {
       y=j;
       cout<<"\n beta initialized \n";
       }
       void showy()
       {
	cout<<"\n Y="<<y<<"\n";
       }
};

class gamma:public alpha,public  beta
{
int m,n;
public:
       gamma(int a,float b,int c,int d):alpha(a),beta(b)
       {
       m=c;
       n=d;
       cout<<"\n gamma initialized \n";

       }
       void showmn()
       {
	cout<<"\n M="<<m<<"\n";
	cout<<"\n N="<<n<<"\n";
       }
};

void main()
{
int a,c,d;
float b;
clrscr();
cout<<"\n Enter four values\n";
cin>>a>>b>>c>>d;
gamma g(a,b,c,d);
g.showx();
g.showy();
g.showmn();
getch();
}