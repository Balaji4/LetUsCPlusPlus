#include<iostream.h>
#include<fstream.h>
#include<stdlib.h>
void main()
{
fstream out("nwgraph.txt",ios::out|ios::app);
for(int i=5;i<=15;i++)
{
out<<i<<" "<<rand()%11<<endl;
}
}