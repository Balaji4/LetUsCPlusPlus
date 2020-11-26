#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
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
       string(char s[])
       {
       //count++;
       len=strlen(s);
       name=new char[len+1];
       strcpy(name,s);
       }


       void display()
       {
       cout<<name;
      // delete name;
       }
       string operator+(string &b);
       int operator<=(string &b);
	void free();
};

string string::operator+(string &b)
{
string temp;
temp.len=len+b.len;
temp.name=new char[temp.len+1];
strcpy(temp.name,name);
strcat(temp.name," ");
strcat(temp.name,b.name);
return temp;
}

int string::operator<=(string &b)
{
int r;
r=strcmp(name,b.name);
return r;
}
void  string::free()
       {

	delete name;
       }

void main()
{
char *str;
int r;
string name1,name2,res;
clrscr();
cout<<"\n Enter string 1\n";
cin>>str;
name1=string(str);
fflush(stdin);
cout<<"\n Enter string 2\n";
cin>>str;
name2=string(str);
res=name1+name2;  // res=name1.+(name2)
cout<<"\n Given strings are\n";
name1.display();
cout<<endl;
name2.display();
cout<<endl;
if(name1<=name2)
{
name1.display();
cout<<" is smaller than ";
name2.display();
}
else
{
 name2.display();
 cout<<" is smaller than ";
 name1.display();
}
cout<<"\n Concatenated string is\n";
res.display();
name1.free();
name2.free();
res.free();
getch();
}