#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
int mystr(char [],char [],int,int);
void main()
{
char text[80],pat[80];
int tsize,psize,r;
clock_t start,end;
clrscr();
randomize();
//cout<<"\nEnter a text\n";
for(int i=0;i<80;i++)
{
int rc;
l:rc=rand()%124;
if((rc>=65&&rc<=91)||(rc>=97&&rc<=122))
{
text[i]=(char)rc;
}
else
{
goto l;
}
}
tsize=strlen(text);
cout<<"randomized text is\n\n";
cout<<text;
cout<<"\nEnter a pattern to be searched\n";
gets(pat);
psize=strlen(pat);
start=clock();
r=mystr(text,pat,tsize,psize);
end=clock();
if(r==-1)
{
cout<<"Pattern not found\n";
}
else
{
cout<<"Pattern found in position="<<(r+1);
}
printf("\nTime required to execute=%lf",(end-start)/CLK_TCK);
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

