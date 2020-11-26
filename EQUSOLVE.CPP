#include<iostream.h>
#include<conio.h>
#include<ctype.h>
double fnvalue(char [],double);
double solve(char []);
void main()
{
double pt,res;
char exp[80];
clrscr();
cout<<"enter an expression\n";
cin>>exp;
cout<<"\n enter the point at which expression is to be solved\n";
cin>>pt;
res=fnvalue(exp,pt);
cout<<"\n Result="<<res;
getch();
}

double fnvalue(char ex[],double p)
{
int i=0;
char temp[80];
while(ex!=0)
{
if(isalpha(ex[i]))
temp[i]=p;
else temp[i]=ex[i];
}
return(solve(temp));
}


double solve(char t[])
{
return 1;
}