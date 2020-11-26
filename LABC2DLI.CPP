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
       dlist* insertp(dlist*);
       dlist* deletep(dlist*);
       void display(dlist*);
};
typedef dlist*  node;

node dlist::insertp(node first)
{
node temp,prev,cur;
int i,pos;
temp=getnode();
cout<<"\n Enter item to be inserted \n";
cin>>i;
cout<<"\n Enter position \n";
cin>>pos;
temp->info=i;
temp->left=temp->right=NULL;
if(first==NULL&&pos==1)
{
return temp;
}
if(first==NULL)
{
cout<<"\n Invlid position to insert value \n";
return first;
}
if(pos==1)
{
temp->left=first;
first->right=temp;
return temp;
}
int count=1;
prev=NULL;
cur=first;
while(cur!=NULL&&count!=pos)
{
prev=cur;
cur=cur->left;
cur->right=prev;
count++;
}

if(count==pos)
{
prev->left=temp;
temp->right=prev;
temp->left=cur;
cur->right=temp;
return first;
}
return first;
}



node dlist::deletep(node first)
{
node cur,prev;
int count,pos;
cout<<"\n Enter position of node to be deleted \n";
cin>>pos;
if(first==NULL&&pos<=1)
{
cout<<"\n Invalid position to delete \n";
return NULL;
}
if(pos==1)
{
cur=first;
first=first->left;
first->right=NULL;
free(cur);
return first;
}
prev=NULL;
cur=first;
count=1;
while(cur!=NULL)
{
if(count==pos)
{
break;
}
prev=cur;
cur=cur->left;
cur->right=prev;
count++;
}
 if(count!=pos)
 {
 cout<<"\n Invalid position\n";
 return first;
 }
 prev->left=cur->left;
// prev->right=NULL;
 free(cur);
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
cout<<"\n Contents are \n";
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
  cout<<"1:INSERT NODE AT SPECIFIED POSITION \n";
  cout<<"2:DELETE A SPECIFIED NODE \n";
  cout<<"3:DISPLAY\n";
  cout<<"4:EXIT\n";
  cout<<"\n enter your choice \n";
  cin>>ch;
  switch(ch)
  {
  case 1:first=first->insertp(first);
	 break;

  case 2:first=first->deletep(first);
	 break;

  case 3:first->display(first);
	 break;

  default:exit(0);
  }
  }
  }