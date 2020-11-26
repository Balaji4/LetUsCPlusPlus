#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
class slist
{
slist *link;
int info;

public: slist()
	  {
	  link=NULL;
	  }
	slist* getnode()
       {
	return (new  slist);
       }
       slist* insertf(slist*);
       slist* deletef(slist*);
       void display(slist*);
};
typedef slist*  node;

node slist::insertf(node first)
{
node temp;
int i;
temp=getnode();
cout<<"\n Enter item to be inserted \n";
cin>>i;
temp->info=i;
temp->link=first;
//first=temp;
return temp;
}

node slist::deletef(node first)
{
node temp;
temp=first;
if(temp==NULL)
{
cout<<"\n List empty cannot delete item\n";
return NULL;
}
first=first->link;
cout<<"\n Item deleted="<<temp->info;
delete(temp);
return first;
}

void slist::display(node first)
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
temp=temp->link;
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