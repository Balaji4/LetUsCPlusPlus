#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>

class string
{
char *name;
int len;
public:string()
       {
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
       }

	void free();
};




void  string::free()
       {

	delete name;
       }

void main()
{
char *str;
string name1;
clrscr();
cout<<"\n Enter string 1\n";
cin>>str;
name1=string(str);
cout<<"\n Given string is\n";
name1.display();
name1.free();
getch();
}

