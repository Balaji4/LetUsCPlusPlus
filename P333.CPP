#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
void main()
{
int n,m,i,k,a[200],v[100];
char *r[200],file[20],w;
FILE *fp;
p: clrscr();
printf("\t\tEnter the Maximum number of students n: ");
scanf("%d",&n);
printf("\t\tEnter the number of students in each group m: ");
scanf("%d",&m);
randomize();

for(i=0;i<n;i++)
{
r[i]=(char*)malloc(20*sizeof(char));
}
for(i=0;i<n;i++)
{
l:int s=rand()%n;
int j=0;
while(j<i)
{
if(s==a[j])
goto l;
j++;
}
if(j==i)
a[i]=s;
}
//for(i=0;i<n;i++)
//printf("%d\t",a[i]);
printf("\n\t\tEnter the file name: ");
scanf("%s",file);
if((fp=fopen(file,"r"))==NULL)
{
printf("Error in opening file\n");
}


int h=n%m;
for(i=0;i<n;i++)
{
fscanf(fp,"%s",r[i]);

}
i=0;
int z=0;
printf("\n\n\t\tThe groups are as follows:\n");
while(i<(n-h))
{
printf("\t\tThe group %d is: ",z+1);
delay(500);
printf("(");
int c=0;
while(c<m)

{
printf(" %s,",r[a[i]]);
c++;
i++;
}
z+=1;
printf(")\n\n");
}
int p=0;

if(h!=0)
{
delay(500);
printf("\t\tThe remaining students are as follows: \n\n\t\t");
printf("(");
while(p<h)
{
printf(" %s,",r[a[i]]);
i++;
p++;
}
printf(")\n");
}
k=n/m;
for(int y=0;y<h;y++)
{
o:int s=rand()%k;
if(s==0)
s=s+1;
int j=0;
while(j<y)
{
if(s==v[j])
goto o;
j++;
}

if(j==y)
v[y]=s;
}
if(h!=0)
{
printf("\n\t\tThe remaining members are assigned to \n");
i=i-h;
z=0;
while(z<h)
{

printf("\n\t\t%s to %d group \n",r[a[i]],v[z]);
z++;
i++;
}
}
printf("\n\t\t Do you want to continue? Press y for yes else press any key: ");
scanf("%s",&w);
if(w== 'y' || w== 'Y')
goto p;
getch();
fclose(fp);
for(i=0;i<n;i++)
free(r[i]);

}







