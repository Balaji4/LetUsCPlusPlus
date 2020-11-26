#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<fstream.h>


char lookup[32][10]={"struct","int","float","double","long","char"};
char *symtab=new char[10000];
int pass1(char p[]);
main()
{
char *p,ch;
p=new char[1000];
clrscr();
cout<<"Enter the structure `DELIM\n\n";
scanf("%[^`]s",p);
pass1(p);

for(int i=0;p[i]!='\0';)
cout<<p[i++];


getch();
}

int pass1(char p[])
{
int flag=1,flb=0;
for(int i=0;i<strlen(p);i++)
 {
  if(isalnum(p[i])||p[i]=='{'||p[i]=='}'||p[i]==';'||p[i]=='_'||p[i]==' '||p[i]=='\n'||p[i]=='*')
  {
  if(p[i]=='{')
  flb++;
  if(p[i]=='}')
  flb--;
  flag=1;
  continue;
  }
  else
  {
  cout<<"\nUnidentified symbol '"<<p[i]<<"'"<<"\n";
  flag=0;
  break;
  }
  }
if(flb>0)
cout<<"\n"<<flb<<" extra '{' \n";
else if(flb)
cout<<flb<<" extra '}' \n";
else if(!flag) return 0;
else return 1;
 
}

