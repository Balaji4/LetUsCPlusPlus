#include<iostream.h>
#include<conio.h>
#include<math.h>
class octal
{
int a;
public:octal()
       {}
       octal(int x);
       friend ostream & operator<<(ostream &,octal);
       friend int operator+(octal,int);
};

octal::octal(int x)
{
int r,i=0;
a=0;
while(x!=0)
{
r=x%8;
a+=r*pow(10,i);
i++;
x=x/8;
}
}

ostream & operator<<(ostream & out,octal h)
{
out<<h.a;
return out;
}

int operator+(octal h,int k)
{
int r=0,i=0,res=0;
while(h.a>0)
{
r=h.a%10;
res+=r*pow(8,i);
i++;
h.a=h.a/10;
}
return (res+k);
}

void main()
{
octal h;
int y,k,x;
clrscr();
cout<<"\n enter an integer\n";
cin>>x;
h=octal(x);
cout<<"\n its corresponding octal equivalent is ";
cout<<h;
cout<<"\n enter  an integer to be added \n";
cin>>k;
y=h+k;
cout<<" sum =";
cout<<y;
getch();
}
