
#include<iostream.h>
#include<conio.h>
int main()
{

int n,j,temp,temp1,temp2,*p,*b,*w,i;
float awt=0;
clrscr();


cout<<"Enter the number of process\n";
cin>>n;
p=new int[n],b=new int[n],w=new int[n];
cout<<"Enter the burst times\n";
for(i=0;i<n;i++)
	    {
			cin>>b[i];
			p[i]=i;
	    }
for(i=0;i<n;i++)
	    {
			for(j=i;j<n;j++)
			{
				    if(b[i]>b[j])
				    {
						temp=b[i];
						temp1=p[i];
						b[i]=b[j];
						p[i]=p[j];
						b[j]=temp;
						p[j]=temp1;
				     }
			}
	     }
w[0]=0;
for(i=0;i<n;i++)
w[i+1]=w[i]+b[i];
for(i=0;i<n;i++)
awt=awt+w[i];

awt=awt/n;

cout<<"\n\t Process \t Waiting time\n";
for(i=0;i<n;i++)
cout<<"\t P"<<p[i]<<"\t\t "<<w[i]<<"\n";
cout<<"The average waiting time is " <<awt<<"\n";
getch();
}