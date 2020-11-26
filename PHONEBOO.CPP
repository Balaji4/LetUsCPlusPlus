#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<dos.h>
struct user
{
char name[20];
char num[10];
int len;
}u[20];
int ct=0;
void Disp();
void Add();
void Search();
void Del()
{
}
int mystr(char [],char [],int,int);
void main()
{
char ch;
for(;;)
{
clrscr();
cout<<"\n\tMENU\n";
cout<<"1:Search Contact\n";
cout<<"2:Add New Contact\n";
cout<<"3:Display All contacts\n";
cout<<"4:Delete Contact\n";
ch=getch();
  switch(ch)
  {
	case '1':Search();
       break;
	case '2':Add();
       break;
	case '3':Disp();
	break;
	case '4':Del();
	default:exit(0);
  }
 }
}
void Search()
{
char pat[20];
int psize,r;
fflush(stdin);
cout<<"\nEnter a name to be searched\n";
gets(pat);
psize=strlen(pat);
for(int i=0;i<ct;i++)
{
r=mystr(u[i].name,pat,u[i].len,psize);
if(r==-1)
{
continue;
}
else
cout<<u[i].name<<" "<<u[i].num<<endl;
}
getch();
}
int mystr(char t[],char p[],int n,int m)
{
int i,j;
for(i=0;i<=(n-m);i++)
 {
   j=0;
   while(j<m&&p[j]==t[i+j])
   j=j+1;
 if(j==m)
 return i;
 }
 return -1;
}

void Add()
{
 if(ct==20)
 {
 cout<"Memory Full\n";
 return;
 }
fflush(stdin);
cout<<"\nEnter a name\n";
gets(u[ct].name);
u[ct].len=strlen(u[ct].name);
fflush(stdin);
cout<<"\nEnter Number\n";
cin>>u[ct].num;
ct++;
}

void Disp()
{
int i=0;
for(i=0;i<ct;i++)
{
cout<<u[i].name<<" "<<u[i].num<<endl;
}
getch();
}