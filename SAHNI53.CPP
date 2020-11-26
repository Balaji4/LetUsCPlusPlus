#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int count=0;
struct circdlist
{
int info;
struct circdlist *left,*right;
};

circdlist* merge(circdlist*,circdlist*,circdlist*);

circdlist* getnode()
{
circdlist *t;
t=(struct circdlist*)(malloc(sizeof(struct circdlist)));
if(t==NULL)
{
printf("Memory not available\n");
return NULL;
}
else {
return t;
}
}





circdlist* insertr(circdlist *h,int item)
{
circdlist *temp,*p,*c=h;
temp=getnode();
temp->info=item;
c=h->left;
h->left=temp;
temp->right=h;
temp->left=c;
c->right=temp;
count++;
return h;
}



circdlist* deleter(circdlist *h)
{
circdlist *temp,*c,*p;
 if(h->left==h)
 {
 printf("List is empty\n");
 return NULL;
 }
c=h->left;
 temp=c->left;
 h->left=temp;
 temp->right=h;
 printf("Item deleted =%d",c->info);
 free(c);
 count--;
 return h;



}

void display(circdlist *h)
{
circdlist *temp=h->right;
 if(h->right==h)
 {
 printf("circdlist empty, nothing to display\n");
 return;
 }

 else
  {
   printf("elements are\n");
   while(temp!=h)
   {
   printf(" %d",temp->info);
   temp=temp->right;
   }
  }

}





int main(void)
{
   struct circdlist h1,*head1=&h1;
   struct circdlist h2,*head2=&h2;
   struct circdlist h3,*head3=&h3;

   head1->right=head1->left=head1;
   head2->right=head2->left=head2;
   head3->right=head3->left=head3;
   int ch,item;
   int listch;
   clrscr();
   for(;;)
   {
   cout<<"\n1:First list\n2:Second list\n";
   cin>>listch;
   clrscr();
   printf("\nMENU\n1:INSERT \n2:DELETE\n 3:DISPLAY\n4:Merge Lists\n5:EXIT");
   printf("\nenter your choice\n");
   scanf("%d",&ch);
    if(listch==1)
    {
    switch(ch)
    {
    case 1:printf("\nenter item to be inserted in rear\n");
	   scanf("%d",&item);

	   {
	   head1=insertr(head1,item);
	   }

	   break;
    case 2:
	   {
	   head1=deleter(head1);
	   }
	   break;
    case 3:
	   display(head1);

	   break;

    case 4:head3=merge(head1,head2,head3);
	   display(head3);
	   break;
    default:
	    getch();
	   exit(0);
    }
   }
    else
    {



    switch(ch)
    {
    case 1:printf("\nenter item to be inserted in rear\n");
	   scanf("%d",&item);

	   {
	    head2=insertr(head2,item);
	   }
	   break;
    case 2:
	   head2=deleter(head2);

	   break;
    case 3:

	   {
	   display(head2);
	   }
	   break;
    case 4:head3=merge(head1,head2,head3);
	   display(head3);
	   break;
    default:
	    getch();
	   exit(0);
    }
    }



   }


}



circdlist * merge(circdlist *h1,circdlist *h2,circdlist *h3)
{
circdlist *t1,*t2,*t3;
t1=h1->right;
t2=h2->right;
while(t1!=h1&&t2!=h2)
{
h3=insertr(h3,t1->info);
h3=insertr(h3,t2->info);
t1=t1->right;
t2=t2->right;
}
if(t1==h1&&t2==h2)
{
 return h3;
 }
 else if(t1==h1)
 {
  while(t2!=h2)
  {
  h3=insertr(h3,t2->info);
  t2=t2->right;
  }
 }
 else {
   while(t1!=h1)
  {
  h3=insertr(h3,t1->info);
  t1=t1->right;
  }
 }

return h3;
}





