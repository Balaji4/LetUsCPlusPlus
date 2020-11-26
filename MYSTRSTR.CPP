#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
int mystr(char [],char [],int,int);
void main()
{
char text[20],pat[20];
int tsize,psize,r;
clrscr();
cout<<"\nEnter a text\n";
gets(text);
tsize=strlen(text);
cout<<"\nEnter a pattern to be searched\n";
gets(pat);
psize=strlen(pat);
r=mystr(text,pat,tsize,psize);
if(r==-1)
{
cout<<"Pattern not found\n";
getch();
exit(0);
}
cout<<"Pattern found in position="<<(r+1);
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




