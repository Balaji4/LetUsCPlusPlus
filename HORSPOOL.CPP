#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
char *table;
void shtable(char p[],int size);
int horspool(char p[],char t[],int m,int n);
void main()
{
char pat[20],text[20];
int pl,tl,res;
clrscr();
cout<<"\n Enter a text\n";
gets(text);
cout<<"\n Enter a pattern \n";
cin>>pat;
tl=strlen(text);
pl=strlen(pat);
res=horspool(pat,text,pl,tl);
if(res==-1)
cout<<"pattern not found";
else
cout<<"pattern found in position "<<(res+1);
getch();
}

void shtable(char p[],int size)
{
int j=0;
while(j<size)
{
table[p[j]]=size;
j++;
}
for(j=0;j<=size-2;j++)
{
table[p[j]]=size-1-j;
}
}
 int horspool(char p[],char t[],int m,int n)
 {
 int i,k;
 shtable(p,m);
 i=m-1;
 while(i<=n-1)
  {
   k=0;
    while((k<=m-1)&&(p[m-1-k]==t[i-k]))
    {
    k=k+1;
    }
    if(k==m)
     return (i-m+1);
    else
     i=i+(table[t[i]]);
  }
   return -1;
 }
