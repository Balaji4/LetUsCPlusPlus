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


circdlist* split1(circdlist*,circdlist*);
circdlist* split2(circdlist*,circdlist*);
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
   clrscr();
   for(;;)
   {
   printf("\nMENU\n1:INSERT \n2:DELETE\n 3:DISPLAY\n4:Split Lists\n5:EXIT");
   printf("\nenter your choice\n");
   scanf("%d",&ch);
    switch(ch)
    {
    case 1:printf("\nenter item to be inserted in rear\n");
	   scanf("%d",&item);
	   head3=insertr(head3,item);
	   break;
    case 2:
	   head3=deleter(head3);
	   break;
    case 3:
	   display(head3);

	   break;

    case 4:head1=split1(head3,head1);
	   head2=split2(head3,head2);
	   cout<<"Link List A \n";
	   display(head1);
	   cout<<"\n Link List B\n";
	   display(head2);
	   break;
    default:
	   exit(0);
    }
   }


}



circdlist* split1(circdlist *h3,circdlist *h1)
{
circdlist *t3,*t=h3;
t3=h3->right;
int c=0;
while(t3!=h3)
{
c++;
if((c%2)==0)
 {
 }
 else{
 h1=insertr(h3,t3->info);
 }
t3=t3->right;
}
h3=t;
return h1;

}


circdlist* split2(circdlist *h3,circdlist* h2)
{
circdlist *t1,*t=h3,*t3;
t3=h3->right;
int c=0;
while(t3!=h3)
{
c++;
if(c%2==0)
 {
 h2=insertr(h3,t3->info);
 }
t3=t3->right;
}
h3=t;
return h2;

}