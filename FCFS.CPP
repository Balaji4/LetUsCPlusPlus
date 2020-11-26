#include<iostream.h>
#include<conio.h>
main()
{
//a - Arrival Times, b - Burst Times, g - Gantt Chart, w - Waiting Times
int n,*a,*b,*w,*g,i,m;
float awt=0;
clrscr();
	    for(i=0;i<10;i++)
	    {
			a[i]=0; b[i]=0; w[i]=0; g[i]=0;
	    }
cout<<"Enter the number of process\n";
cin>>n;
		a=new int[n],b=new int[n],g=new int[n],w=new int[n];
cout<<"Enter the burst times\n";
	    for(i=0;i<n;i++)
		cin>>b[i];
cout<<"\nEnter the arrival times\n";
	    for(i=0;i<n;i++)
		cin>>a[i];
    g[0]=a[0];
	     for(i=0;i<10;i++)
		   g[i+1]=g[i]+b[i];
	     for(i=0;i<n;i++)
	    {
			w[i]=g[i]-a[i];
			awt=awt+w[i];
	    }
     awt =awt/n;
	    cout<<"\n\tProcess\tWaiting time\n";
	    for(i=0;i<n;i++)
	    {
			cout<<"\tP"<<i<<"\t\t"<<w[i]<<"\n";
	    }
cout<<"The average waiting time is "<<awt<<"\n";
getch();
}

