#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>
#define size 5

int F(char sym)
{
 switch(sym)
 {
 case '+':
 case '-':return 2;
 case '*':
 case '/':return 4;
 case '^':
 case '$':return 5;
 case '(':return 0;
 case '#':return -1;
 default :return 8;
 }
}
int G(char sym)
{
 switch(sym)
 {
 case '+':
 case '-':return 1;
 case '*':
 case '/':return 3;
 case '^':
 case '$':return 6;
 case '(':return 9;
 case ')':return 0;
 default :return 7;
 }
}
void inftopos(char inf[],char pos[])
{
int top,i,j;
char s[30],sym;
top=-1;
s[++top]='#';
j=0;
for(i=0;i<strlen(inf);i++)
 {
 sym=inf[i];
 while(F(s[top])>G(sym))
 {
 pos[j]=s[top--];
 j++;
 }
 if(F(s[top])!=G(sym))
 s[++top]=sym;
 else top--;
 }
 while(s[top]!='#')
 {
 pos[j++]=s[top--];
 }
 pos[j]='\0';
}

double comp(char sym,double op1,double op2)
{
 switch(sym)
 {
 case '+':return op1+op2;

 case '-':return op1-op2;

 case '*':return op1*op2;

 case '/':return op1/op2;

 case '$':
 case '^':return pow(op1,op2);

 }
}

void main()
{
int ch;
clrscr();
char inf[20],pos[20];
double res=0;
double s[20],op1,op2;
int top,i;
char sym;
top=-1;
printf("\nenter an infix expression\n");
scanf("%s",inf);
inftopos(inf,pos);
printf("postfix expression is\n");
printf("%s",pos);
//res=eval(inf);

 for(i=0;i<strlen(pos);i++)
 {
 sym=pos[i];
 if(isdigit(sym))
 s[++top]=sym-'0';
 else
 {
 op2=s[top--];
 op1=s[top--];
 res=comp(sym,op1,op2);
 s[++top]=res;
 }
 }
 res=s[top--];
printf("\nresult=%lf",res);
getch();
}
