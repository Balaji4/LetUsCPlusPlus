#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
void main()
{
char  org[80],enc[80],dec[80];
int i;
clrscr();
printf("\n enter a string\n");
gets(org);
strcpy(enc,org);
printf("\nmain string= %s",enc);
for(i=0;enc[i]!='\0';i++)
 {
  enc[i]=enc[i]-10;

 }
 printf("\n encription= %s",enc);
 strcpy(dec,enc);
 for(i=0;dec[i]!='\0';i++)
 {
  dec[i]=dec[i]+10;
 }
 printf("\n decription= %s",dec);
getch();
}