#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct circdlist
{
int info;
struct circdlist *left,*right;
};

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

circdlist* insertf(circdlist *h,int item)
{
circdlist *temp,*c,*p;
temp=getnode();
temp->info=item;
c=h->right;
h->right=temp;
temp->left=h;
temp->right=c;
c->left=temp;
return h;
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
return h;
}

circdlist* deletef(circdlist *h)
{
circdlist *temp,*c;
 if(h->right==h)
 {
  printf("List is empty\n");
  return h;
 }
 c=h->right;
 temp=c->right;
 h->right=temp;
 temp->left=h;
 printf("Item deleted =%d",c->info);
 free(c);
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
   struct circdlist *head=NULL;
   head->right=head->left=head;
   int ch,item;
   clrscr();
   for(;;)
   {
   printf("\nMENU\n1:INSERT FRONT\n2:INSERT REAR\n3:DELETE FRONT\n4:DELETE REAR\n5:DISPLAY \n6:EXIT");
   printf("\nenter your choice\n");
   scanf("%d",&ch);
    switch(ch)
    {
    case 1:printf("\nenter item to be inserted in front\n");
	   scanf("%d",&item);
	   head=insertf(head,item);
	   break;
    case 2:printf("\nenter item to be inserted in rear\n");
	   scanf("%d",&item);
	   head=insertr(head,item);
	   break;
    case 3:head=deletef(head);
	   break;
    case 4:head=deleter(head);
	   break;
    case 5:display(head);
	   break;

    default:exit(0);
    }
   }
   return 0;
}