#include<stdio.h>
#include<conio.h>
int stmatch(char* ,char*,int,int);
void main()
{
   char a[10],b[20];
   int i,n,s,m;
   clrscr();
   printf("Enter the number of characters\n");
   scanf("%d",&n);
   printf("ENter the text\n");
   for(i=0;i<n;i++)
   {
    scanf("%c",&b[i]);
    }
    printf("Enter the number of characters\n");
    fflush(stdin);
   scanf("%d",&m);
    printf("Enter the pattern to be searched\n");
    for(i=0;i<m;i++)
    scanf("%c",&a[i]);
    s=stmatch(a,b,n,m);
    if(s!=-1)
    printf("pattern does match\n");
    else
    printf("pattern doesnt match\n");
    getch();
    }

    int stmatch(char a[],char b[],int n,int m)
    {
    int i,j;
    for(i=0;i<=n-m;i++)
    {
    j=0;
    while(j<m && a[j]==b[i+j])
    j=j+1;
    if(j==m)
    return i;
    }
    return -1;
    }
