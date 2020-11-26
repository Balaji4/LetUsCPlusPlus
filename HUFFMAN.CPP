#include<iostream.h>
#include<conio.h>
#include<string.h>
void huffalgo();
class huff
{
float freq;
char a;
public:
      void getvalue(char b,float f)
      {
      a=b;
      freq=f;
      }
   friend ostream& operator<<(ostream &,huff);
};
ostream& operator<<(ostream &out,huff temp)
{
out<<temp.a;
out<<" "<<temp.freq<<endl;
return out;
}
void main()
{
char ch;
float f;
int n=10;
clrscr();
cout<<"\n how many alphabets\n";
cin>>n;
huff *obj;
obj=new huff[n];
cout<<"\n Enter char n its frequency\n";
for(int i=0;i<n;i++)
{
cin>>ch;
cin>>f;
obj[i].getvalue(ch,f);
}
cout<<"\n Given values are \n";
for(i=0;i<n;i++)
{
cout<<obj[i];
}
huffalgo();
delete [] obj;
getch();
}

void huffalgo()
{
}