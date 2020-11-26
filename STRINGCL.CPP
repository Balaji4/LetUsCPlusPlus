#include<iostream.h>
#include<conio.h>
#include<string.h>
//int count=0;
class string
{
char *name;
int len;
public:string()
       {
     //	count++;
	len=0;
	name=new char[len+1];
       }
       string(char *s)
       {
       //count++;
       len=strlen(s);
       name=new char[len+1];
       strcpy(name,s);
       }


       void display()
       {
       cout<<name<<endl;
       delete name;
       }
       void concat(string &a,string &b);
    //	~string();
};

void string::concat(string &a,string &b)
{
len=a.len+b.len;
name=new char[len+1];
strcpy(name,a.name);
strcat(name," ");
strcat(name,b.name);
}

// string::~string()
  //     {
       //cout<<"\n Destructing object:"<<count;
     //  count--;
    //	delete name;
     //  }

void main()
{
char *str;
string name1,name2,res;
clrscr();
cout<<"\n Enter string 1\n";
cin>>str;
name1=string(str);
cout<<"\n Enter string 2\n";
cin>>str;
name2=string(str);
res.concat(name1,name2);
cout<<"\n Given strings are\n";
name1.display();
name2.display();
cout<<"\n Concatenated string is\n";
res.display();
getch();
}