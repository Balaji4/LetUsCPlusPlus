#include<iostream.h>
#include<conio.h>
#include<fstream.h>
void main()
{
clrscr();
ofstream outfile("sample.txt");
outfile<<"hello";
outfile.close();
ifstream infile("sample.txt");
cout<<"contents of file\n";
char *s;
infile>>s;
cout<<s;
getch();
}

