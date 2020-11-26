#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<fstream.h>
char lookup[32][10]={"struct\0","int\0","float\0","double\0","long\0","char\0","\0"};
char *symtab=new char[10000];
int pass1(char p[]);
void pass2(char p[]);
int ident(char t[],int);
void clear(char t[],int);
void main()
{
char *p,ch;
p=new char[1000];
clrscr();
clear(p,1000);
cout<<"Enter the structure `DELIM\n\n";
scanf("%[^`]s",p);
int r=pass1(p);
if(r!=0)
pass2(p);
for(int i=0;p[i]!='\0';)
cout<<p[i++];


getch();
delete []p;
delete []symtab;
}

int pass1(char p[])
{
int flag=1,flb=0;
char temp[32];
for(int i=0;i<strlen(p);i++)
 {
  if(isalnum(p[i])||p[i]=='{'||p[i]=='}'||p[i]==';'||p[i]=='_'||p[i]==' '||p[i]=='\n'||p[i]=='*')
  {
    if(p[i]=='{')
     {
     flb++;
     }
     if(p[i]=='}')
     {
      flb--;
      }
  flag=1;
  continue;
  }
  else
  {
  cout<<"\nUnidentified symbol '"<<p[i]<<"'"<<"\n";
  flag=0;
  break;
  }
} //end of for
if(flb>0)
cout<<"\n"<<flb<<" extra '{' \n";
else if(flb<0)
cout<<(-flb)<<" extra '}' \n";
//else if(!flag) return 0;
   for(i=0;i<strlen(p);)
    {

       for(int j=0;p[i+j]!=' '&&p[i+j]!='{'&&(i+j)<strlen(p);j++)
       {
       temp[j]=p[i+j];
       }
       temp[j]='\0';
       i++;
       printf("\t temp=%s ",temp);
	for(int k=0;k<7;k++)
	{
	   int r=strcmp(lookup[k],temp);
	    if(r==0)
	      {
	       printf(" id1 %s",temp);
	       break;
	      }
	}
	 i+=strlen(temp);
   }
return flag;
}


void clear(char t[],int s)
{
int i;
 for(i=0;i<s;i++)
 {
  t[i]='\0';
 }
}


void pass2(char p[])
{
char temp[20];
int i=0,j=0,flag=1;
clear(temp,20);
  for(i=0,j=0;p[i]!=' '&&p[i]!='\0'&&p[i]!='{';i++,j++)
  {
  temp[j]=p[i];
  }
if(strcmp(temp,"struct")==0)
printf("struct syntax correct\n");
   else
  {
  printf("Undefinded symbol %s\n",temp);
  getch();
  exit(0);
  }
clear(temp,20);


for(;p[i]==' '&&p[i]!='\0';i++);
if(p[i]=='{')
goto l;
 for(j=0;(p[i]!='{')&&(p[i]!=' ')&&p[i]!='\0';i++,j++)
 {
  temp[j]=p[i];
 }
 if(temp[0]=='\0'&&p[i]!='{')
 {
 printf("\n not a valid identifier\n");
 }
flag=ident(temp,j);
if(flag==0)
printf("\n Invalid identifier \n");
else
printf("\n valid identifier \n");
l:getch();
free(p);
}


int ident(char t[],int s)
{
int i,flag=1;
printf(" ->%s",t);
if((isalpha(t[0]))||(t[0]=='_'))
{
flag=1;
//return 0;
}
else {
flag=0;
return flag;
}

for(i=1;t[i]!='\0';i++)
{
if(isalnum(t[i])||(t[i]=='_'))
{
flag=1;
continue;
}else
{
flag=0;
return flag;
}
}
return 1;
}


