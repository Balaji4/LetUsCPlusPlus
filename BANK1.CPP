#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define minbalance 500
int n;
class bank
{
char name[15],depname[15],type[10];
double bal;
public:long int acc;
       void init(int);
       void deposit();
       void withdraw();
       void display();
       void change();
};

void bank::init(int j)
{
bal=0;

acc=j;

cout<<"\n enter user name for user for account number:"<<acc<<endl;
cin>>name;
strcpy(type,"savings");
}

void bank::deposit()
{
double amt;
cout<<"\n Enter depositor's name\n";
cin>>depname;
cout<<"\n Enter amount to be deposited\n";
cin>>amt;
if(amt<0)
{
cout<<"\n Invalid amount entered \n";
}
else
{
bal+=amt;
}
}

void bank::withdraw()
{
double a;
display();
cout<<"\n Enter amount to withdraw\n";
cin>>a;
if(a>minbalance)
{
cout<<"\n Invalid withdrawl amount\n";
return;
}
else
{
bal-=a;
display();
}
}

void bank::display()
{
cout<<"\n Name:"<<name;
cout<<"\n Account No.:"<<acc;
cout<<"\n Balance="<<bal;
}

void bank::change()
{
int r;
cout<<"\n Your present account type is "<<type;
r=strcmp(type,"savings");
if(r==0)
{
strcpy(type,"current");
}
else
strcpy(type,"savings");
cout<<"\n Changed account type is "<<type;
}

void main()
{
bank *p;
int i,ch,j,k=100;
long int acn;
char chk;
clrscr();
cout<<"\n How many user accounts\n";
cin>>n;
p=new bank[n];
for(i=0;i<n;i++)
{
p[i].init(k);
k++;
}

l1:clrscr();
cout<<"\n Enter account number \n";
cin>>acn;
for(i=0;i<n;i++)
{
 if(acn==p[i].acc)
 {
 j=i;
 break;
 }
}
if(i!=j)
{
cout<<"\n Invalid account number\n";
exit(0);
}

cout<<"\t\nMENU\n";
cout<<"1:Print balance \n";
cout<<"2:Withdraw amount \n";
cout<<"3:Deposit amount \n";
cout<<"4:Change my account type \n";
cout<<"5:Exit\n";
cout<<"\n enter your choice \n";
cin>>ch;
switch(ch)
{
case 1:p[j].display();
       break;

case 2:p[j].withdraw();
	break;

case 3:p[j].deposit();
	break;

case 4:p[j].change();
       break;

default:exit(0);
}

cout<<"\n Would you like to continue ? [y/n] ";
cin>>chk;
if(chk=='y'||chk=='Y')
{
goto l1;
}

delete [] p;
getch();
}