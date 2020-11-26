#include<iostream.h>
#include<conio.h>
class complex
{
float rp,ip;
public:complex()
	{ }
       complex(float a,float b)
       {
	rp=a;
	ip=b;
       }
friend complex add(complex,complex,complex);
friend complex sub(complex,complex,complex);
friend complex mul(complex,complex,complex);
friend complex div(complex,complex,complex);
       void display();
};

complex add(complex c1,complex c2,complex res)
{
res.rp=c1.rp+c2.rp;
res.ip=c1.ip+c2.ip;
return res;
}

complex sub(complex c1,complex c2,complex res)
{

res.rp=c1.rp-c2.rp;
res.ip=c1.ip-c2.ip;
return res;
}

complex mul(complex c1,complex c2,complex res)
{
res.rp=c1.rp*c2.rp-c1.ip*c2.ip;
res.ip=c1.rp*c2.ip+c1.ip*c2.rp;
return res;
}

complex div(complex c1,complex c2,complex res)
{
res.rp=(c1.rp*c2.rp+c1.ip*c2.ip)/(c1.rp*c1.rp+c2.rp*c2.rp);
res.ip=(c2.rp*c1.ip-c1.rp*c2.ip)/(c1.rp*c1.rp+c2.rp*c2.rp);
return res;
}

void complex::display()
{
cout<<rp<<"+"<<ip<<"i";
}

void main()
{
complex c1,c2,c3,c4,c5,c6;
float a,b;
clrscr();
cout<<"\n enter real and imaginary part of operand 1\n";
cin>>a>>b;
c1=complex(a,b);
cout<<"\n enter real and imaginary part of operand 2\n";
cin>>a>>b;
c2=complex(a,b);
cout<<"\n Given complex numbers are\n";
c1.display();
cout<<endl;
c2.display();
c3=add(c1,c2,c3);
cout<<"\n Sum=";
c3.display();
c4=sub(c1,c2,c4);
cout<<"\n Difference=";
c4.display();
c5=mul(c1,c2,c5);
cout<<"\n Product=";
c5.display();
c6=div(c1,c2,c6);
cout<<"\n Quotient of c1/c2=";
c6.display();
getch();
}
