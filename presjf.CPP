#include<iostream.h>
#include<stdio.h>
#include<conio.h>
int main()
{    int n;//=4;
    float total,wait[10]={0};
    float p[10],twaiting=0,waiting=0;
    int proc;
    int stack[10];
    float burst[10],arrival[10],sburst,temp[10],top;
    clrscr();
    //top=n;
    cout<<"\n enter no. of process\n";
    cin>>n;
	  top=n;
    for(int i=0;i<n;i++)
    {
        p[i]=i;
        stack[i]=i;
	cout<<"\nenter arrival time :";
	cin>>arrival[i];
	cout<<endl<<"enter burst time:";
	cin>>burst[i];
        temp[i]=arrival[i];
	sburst=burst[i]+sburst;
    }    

  for(i=0;i<sburst;i++)
    {
        proc=stack[0];
        if(temp[proc]==i)
                    twaiting=0;
        else
                  twaiting=i-(temp[proc]);
        temp[proc]=i+1;    
   
        wait[proc]=wait[proc]+twaiting;
        waiting=waiting+(twaiting);
	 burst[proc]=burst[proc]-1;
    
	    if(burst[proc]==0)
           {
            for(int x=0;x<top-1;x++)
                            stack[x]=stack[x+1];
            top=top-1;
           }
            for(int z=0;z<top-1;z++)
            {   
		 if((burst[stack[0]]>burst[stack[z+1]]) && (arrival[stack[z+1]] <= i+1))
              {
                       int t=stack[0];
            stack[0]=stack[z+1];
            stack[z+1]=t;
              }
          }
        }

cout<<"\ntotal waiting time:"<<waiting<<endl;
cout<<"\navg waiting time="<<(float)(waiting/n);
getch();
return 0;
}