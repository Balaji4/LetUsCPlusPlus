#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<string.h>
int iso(char[],char[]);
int main()
{
char s1[20],s2[20];
clrscr();
printf("enter a string\n");
gets(s1);
printf("enter another string\n");
gets(s2);
int flag=iso(s1,s2);
if(flag)
 cout<<"\n isomorphic";
 else
 cout<<"\n not isomorphic";
getch();
return 0;
}
int iso(char p1[],char p2[])
{
int i,l1,l2;
l1=strlen(p1);
l2=strlen(p2);
 if(l1!=l2)
 return 0;
 int hash1[26]={0},hash2[26]={0},count1=0,count2=0;
 for(i=0;i<l1;i++)
  {
  if(!hash1[p1[i]-97])
   {
   count1++;
   hash1[p1[i]-97]=count1;
  // }
   //if(!hash2[p2[i]-97])
  // {
  // count2++;
   hash2[p2[i]-97]=count1;
   }
  }
  cout<<endl;
 for(i=0;i<l1;i++)
  {
  cout<<endl<<(i+1)<<" "<<hash1[p1[i]-97]<<" "<<hash2[p2[i]-97];
  }
  for(i=0;i<l1;i++)
  {
  if(hash1[p1[i]-97]!=hash2[p2[i]-97])
  return 0;
  }
  return 1;
 }