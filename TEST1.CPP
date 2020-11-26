#include<stdio.h>
#include<string.h>
void main()
{
char *p,*q,*r=NULL;
int i=0,j=0,k=0;
clrscr();
printf("Enter two strings\n");
scanf("%s %s",p,q);
for(i=0;i<strlen(p);i++)
{
for(j=0;j<strlen(q);j++)
{
if(p[i]==q[j])
{
  r[k]=p[i];
  k++;
  }
}
}
printf("The deleted characters\n");
printf("%s",r);
getch();
}



