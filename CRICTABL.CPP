#include<iostream.h>
#include<conio.h>
#include<iomanip.h>
struct cric
{
char name[15];
float avg;
int inn;
int nt;
int run;
};
int main()
{
struct cric *p;
int n,i;
clrscr();
cout<<"\n How many players' info  ?\n";
cin>>n;
p=new struct cric [n];
for(i=0;i<n;i++)
{
cout<<"\n Enter name,runs,innings,no. of times not out of player "<<(i+1)<<endl;
cin>>(((p+i))->name);
cin>>((p+i)->run);
cin>>((p+i)->inn);
cin>>((p+i)->nt);
}

for(i=0;i<n;i++)
{
((p+i)->avg)=(float)((p+i)->run)/(((p+i)->inn)-((p+i)->nt));
}
cout<<"\nDetails of "<<n<<" players\n\n";
cout<<"NAME\t\tRUNS\t\tINNINGS\t\tTIMES NOT OUT\t\tAVERAGE\n";
for(i=0;i<n;i++)
{
cout<<endl<<setw(-8)<<((p+i)->name);
cout<<setw(14)<<((p+i)->run);
cout<<setw(16)<<((p+i)->inn);
cout<<setw(20)<<((p+i)->nt);
cout<<setw(24)<<setprecision(4)<<((p+i)->avg);
}
delete []p;
p='\0';
getch();
return 0;
}