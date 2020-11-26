#include<stdio.h>
#include<iostream.h>
#include<conio.h>
struct node
{
int a;
struct node *l;
};
typedef struct node * NODE;

NODE getnode()
{
return (new node);
}
NODE insert(int x,NODE fi)
{
 NODE t;
t= getnode();
t->a=x;
t->l=fi;
return t;
}
NODE insertion(NODE f)
{
NODE m=NULL;
m=f->l;
NODE x,x1,x2;
while(m!=NULL)
{
int t=m->a;

x2=f;
x1=NULL;
x1=x2;
x2=x2->l;
x=x1;
while(x!=f || x==f && t<x->a)
{

x->l->a=x->a;
x->l->a=t;
x2=f;
while(x2->l!=x1)
{
b=x2;
x2=x2->l;
}
x=b;
}
}
return x;
}
void display(NODE f)
{
NODE tmp;
if(f==NULL)
{
printf("List is empty\n");
return ;
}
printf("\n Contents of linked list are\n");
tmp=f;
while(tmp!=NULL)
{
printf("%d->",tmp->a);
tmp=tmp->l;
}
printf("\n");
}



void main()
{
NODE f=NULL;
NODE temp;
temp=f;
int n,x;
clrscr();
printf("Enter the No. of elements\n");
scanf("%d",&n);
printf("Enter the elements\n");
for(int i=0;i<n;i++)
{
scanf("%d",&x);
temp=insert(x,temp);
}
f=insertion(temp);
display(f);

getch();
}

