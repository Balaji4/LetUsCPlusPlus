#include<iostream.h>
#include<conio.h>
int big(int a[]);
void main()
{
enum candidate{candidate1=1,candidate2,candidate3,candidate4,candidate5};
int sp=0,*p,i,n,count[5]={0,0,0,0,0},winner;
clrscr();
cout<<"\n Enter  the number of votes \n";
cin>>n;
p=new int[n];
cout<<"\n To vote,enter 1 for 1st candidate 2 for 2nd candidate & so on\n";
cout<<"enter the votes one by one \n";
for(i=0;i<n;i++)
{
cin>>p[i];
}
 for(i=0;i<n;i++)
 {
  switch(p[i])
  {
   case candidate1:count[0]++;
		break;
   case candidate2:count[1]++;
		break;
   case candidate3:count[2]++;
		break;
   case candidate4:count[3]++;
		break;
   case candidate5:count[4]++;
		break;
   default:sp++;
  }
 }

cout<<"\n vote count for respective candidates are\n";
for(i=0;i<5;i++)
{
cout<<"\n votes for candidate"<<(i+1)<<"="<<count[i];
}
cout<<"\n Number of spoiled votes="<<sp;
if(sp==n)
{
cout<<"\n No candidate is winner\n";
}
else
{
winner=big(count);
cout<<"\n Winner is candidate "<<winner;
}
delete []p;
getch();
}

int big(int a[])
{
int b,large=1;
b=a[0];
for(int i=1;i<5;i++)
{
 if(a[i]>b)
 {
 b=a[i];
 large=i+1;
 }
}
return (large);
}
