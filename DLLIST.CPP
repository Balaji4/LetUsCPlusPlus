#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
class dlist
{
dlist *left,*right;
int info;

public: dlist()
	  {
	  left=right=NULL;
	  }
	dlist* getnode()
       {
	return (new  dlist);
       }
       dlist* insertf(dlist*);
       dlist* deletef(dlist*);
       void display(dlist*);
};
typedef dlist*  node;

node dlist::insertf(node first)
{
node temp;
int i;
temp=getnode();
cout<<"\n Enter item to be inserted \n";
cin>>i;
temp->info=i;
temp->left=first;
first->right=temp;
//first=temp;
return temp;
}

node dlist::deletef(node first)
{
node temp;
temp=first;
if(temp==NULL)
{
cout<<"\n List empty cannot delete item\n";
return NULL;
}
first=first->left;
first->right=NULL;
cout<<"\n Item deleted="<<temp->info;
delete(temp);
return first;
}

void dlist::display(node first)
{
node temp;
temp=first;
if(temp==NULL)
{
cout<<"\n List empty\n";
return;
}
while(temp!=NULL)
{
cout<<"\t"<<temp->info;
temp=temp->left;
}
}

void main()
{
node first=NULL;
int ch;
 clrscr();
 for(;;)
 {
  cout<<"\n\t MENU \n";
  cout<<"1:INSERT FRONT\n";
  cout<<"2:DELETE FRONT\n";
  cout<<"3:DISPLAY\n";
  cout<<"4:EXIT\n";
  cout<<"\n enter your choice \n";
  cin>>ch;
  switch(ch)
  {
  case 1:first=first->insertf(first);
	 break;

  case 2:first=first->deletef(first);
	 break;

  case 3:first->display(first);
	 break;

  default:exit(0);
  }
  }
  }