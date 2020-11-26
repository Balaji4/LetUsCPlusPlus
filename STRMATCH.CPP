#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<fstream.h>
int mystr(char [],char [],int,int);
fstream t;
void main()
{

t.open("textfile.txt",ios::in||ios::nocreate||ios::beg);
char text[80],pat[80],ch;
int tsize,psize,r,count=0;
clock_t start,end;
clrscr();
randomize();
//cout<<"\nEnter a text\n";
cout<<"\nEnter a pattern to be searched\n";
gets(pat);
psize=strlen(pat);
start=clock();
while(!t.eof())
{
for(int k=0;k<80;k++)
{
t.get(ch);
text[k]=(char)ch;//t.get();
cout<<ch;
}

tsize=strlen(text);
//cout<<"randomized text is\n\n";
//cout<<text;

r=mystr(text,pat,tsize,psize);
if(r!=-1)
{
break;
}
count+=80;
/*if(r==-1)
{
cout<<"Pattern not found\n";
}
else
{
cout<<"Pattern found in position="<<(r+1);
} */
}
end=clock();
if(r==-1)
{
cout<<"\nPattern not found\n";
}
else
{
cout<<"\nPattern found in position="<<(r+1+count);
}
printf("\nTime required to execute=%lf",(end-start)/CLK_TCK);
t.close();
getch();
}

int mystr(char text[],char p[],int n,int m)
{
int i,j,k;
char ch;
//while(t.eof()==0)
//{

for(i=0;i<=(n-m);i++)
 {
   j=0;
   while(j<m&&p[j]==text[i+j])
   j=j+1;
 if(j==m)

 return i;
 }


//}

 return -1;
}

