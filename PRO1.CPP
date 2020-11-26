#include<stdio.h>
#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<string.h>
#include<stdlib.h>
#include<dos.h>
struct pro
{
char p[100];
int m,n;
float avg;
//struct pro *link;
};
void main()
{
FILE *fp,*sp,*vp;
 struct pro q[100];
char *s;
int y,u;
clrscr();
printf("Enter the no. of students\n");
scanf("%d",&y);
printf("enter the no. of students in a group\n");
scanf("%d",&u);
if((fp=fopen("sub1.cpp","r"))==NULL)
printf("The file does not exists\n");
if((sp=fopen("names.cpp","r"))==NULL)
printf("The file does not exists\n");
if((vp=fopen("sub2.cpp","r"))==NULL)
printf("The file does not exists\n");
else
{
 for(int i=0;i<y;i++)
 {
 fscanf(fp,"%d",&q[i].m);
// printf(" %d ",q[i].m);
 fscanf(sp,"%s",q[i].p);
// printf(" %s ",q[i].p);
 fscanf(vp,"%d",&q[i].n);
// printf(" %d ",q[i].n);
 q[i].avg=(float)(q[i].n+q[i].m)/2;
// printf(" %f ",q[i].avg);
 }
 }
 for(int i=0;i<y;i++)
 {
 for(int j=1;j<y-i;j++)
 {
 if(q[j-1].avg>q[j].avg)
 {
 float t=q[j-1].avg;
 q[j-1].avg=q[j].avg;
 q[j].avg=t;
 int b=q[j-1].m;
 q[j-1].m=q[j].m;
 q[j].m=b;
 int a=q[j-1].n;
 q[j-1].n=q[j].n;
 q[j].n=a;
  char *x;
 strcpy(x,q[j-1].p);
 strcpy(q[j-1].p,q[j].p);
 strcpy(q[j].p,x);
 }
 }
 }
 printf("\n\t\tName\t\tSub1\t\tSub2\t\tAvg\n");
  for(i=0;i<y;i++)
 {
   printf("\t\t%-15s\t\t%d\t\t%d\t\t%-7.2f\n",q[i].p,q[i].n,q[i].m,q[i].avg);
   delay(500);
   }


 printf("\n");
int c,z=0;
i=0;
int h=y%u;
 while(i<(y-h))
 {
   printf("\nThe group %d is: ",z+1);
   c=0;
   printf("(");
  while(c<u)
  {

    printf(" %s, ",q[i].p);
    i++;
    c++;
  }    z+=1;
     printf(")");
    }
 randomize();
int  k=y/u,v[100];
if(h>0)
{
for(int j=0;j<h;j++)
{
o:int s=rand()%k;
if(s==0)
s=s+1;
int l=0;
while(l<j)
{
if(s==v[l])
goto o;
l++;
}

if(l==j)
v[j]=s;
}
if(h!=0)
{
printf("\n\t\tThe remaining members are assigned to \n");
i=i;
z=0;
while(z<h)
{

printf("\n\t\t%s to %d group \n",q[i].p,v[z]);
z++;
i++;
}
}
}

 getch();
 }
