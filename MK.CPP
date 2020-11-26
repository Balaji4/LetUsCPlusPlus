#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
  char name[10],pass[10],f[10],*gm;
  char *num;
  struct node *l;
  };
  typedef struct node *NODE;
NODE getnode()
{
  NODE x;
  x=(NODE)malloc(sizeof(struct node));
  if(x==NULL)
  {
  printf("Out of memory\n");
  exit(0);
  }
  return x;
  }
NODE insert_f(char *a,char *b,char *f,char* num,char *gm, NODE x)
{
NODE t;
t=getnode();
t->num=num;
strcpy(t->name,a);
strcpy(t->f,f);
strcpy(t->gm,gm);
strcpy(t->pass,b);
t->l=x;
return t;
}

int  search(NODE first,char *gm,char *pass)
{
NODE cur;
if(first==NULL)
{
printf("Invalid gmail_id or password\n");
return 0;
}
cur=first;
while(cur!=NULL)
{
if(strcmp(gm,cur->gm)==0 && strcmp(pass,cur->pass)==0)   break;
cur=cur->l;
}
if(cur==NULL)
{
printf("The gmail_id and password is wrong\n");
return 0;
}
return 1;
}
void gmail()
{
int c;
printf("\n\n\t1->Compose mail\n2->Inbox\n3->Sentmail\n4->Outbox\n");
printf("\n\n\tEnter your choice\n\n");
scanf("%d",&c);
switch(c)
{
case 1: char *mess,*gm;
	char q;
	clrscr();
	printf("\nEnter the message you want send\n");
	scanf("%s",mess);
	printf("Enter the gmail_id of the destination\n");
	scanf("%s",gm);
	printf("Enter the [y] to send the message\n");
	scanf("%s",q);


void main()
{
clrscr();
printf("\n\t\tGMAIL SERVICE\n");
printf("\n\n\t\t1->DONT HAVE ACCOUNT SIGN UP HERE\n");
printf("\n\n\t\t2->LOGIN\n");
printf("Enter the choice\n");
int c;
NODE first=NULL;
scanf("%d",&c);
switch(c)
{
case 1: clrscr();
	char *name,*gm,*f,*pass,*pass1;
	char *num;
	printf("\n\tEnter the name\n");
	scanf("%s",name);
	printf("\n\tEnter the gmail id\n");
	scanf("%s",gm);
      l:	printf("Enter the password of min 6 to 15 characters\n");
	scanf("%s",pass);
	printf("Renter the password for confirmation\n");
	scanf("%s",pass1);

	if(strcmpi(pass,pass1)==0)
	{
	printf("Enter the name in case if you forgot your password\n");
	scanf("%s",f);
	printf("Enter the contact number\n");
      m:	scanf("%s",num);
	if(strlen(num)!=10)
	{
	printf("Plz enter the contact no. with ten digits\n");
	goto m;
	}
	first=insert_f(name,pass,f,num,gm,first);
	printf("Your gmail account is created sucessfully\n");
	  }
	else
	{
	printf("The rentered password and the former password do not match\n");
	goto l;
	}
	break;
	case 2:char *gm,*pass;
	       clrscr();
	       printf("Enter the gmail_id\n");
	       scanf("%s",gm);
	       printf("Enter the password\n");
	       scanf("%s",pass);
	      int d=search(first,gm,pass);
	      if(d==1)
	      {
	       gmail();
	       }

	default: printf("Enter the correct choice\n");
	}

getch();
}