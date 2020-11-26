#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
class mat
{
int a[10][10];
int m,n;
public: mat()
	{
	m=n=0;
	}
	mat(int r,int c)
	{
	m=r;
	n=c;
	}
	void read();
	int operator==(mat y);
	mat operator+(mat y);
	mat operator-(mat y);
friend ostream & operator<<(ostream &,mat);
};

void mat::read()
	{
	int i,j;
	  for(i=0;i<m;i++)
	  {
	    for(j=0;j<n;j++)
	    {
	     cin>>a[i][j];
	    }
	  }
	}

int mat::operator==(mat y)
{
if(m==y.m&&n==y.n)
return 1;

else return 0;
}

mat mat::operator+(mat y)
{
int i,j;
mat res(m,n);
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
res.a[i][j]=a[i][j]+y.a[i][j];
}
}
return res;
}

mat mat::operator-(mat y)
{
int i,j;
mat res(m,n);
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
res.a[i][j]=a[i][j]-y.a[i][j];
}
}
return res;
}


ostream& operator<<(ostream& out,mat s)
{
int i,j;
for(i=0;i<s.m;i++)
{
for(j=0;j<s.n;j++)
{
cout<<s.a[i][j]<<"\t";
}
cout<<endl;
}
return out;
}

void main()
{
int row,col;
mat x,y,sum,diff;
clrscr();
cout<<"\n enter size of matrix 1\n";
cin>>row>>col;
x=mat(row,col);
cout<<"\n enter size of matrix 2\n";
cin>>row>>col;
y=mat(row,col);
cout<<"\n enter elements of matrix 1\n";
x.read();
cout<<"\n enter elements of matrix 2\n";
y.read();
if(x==y)
{
sum=x+y;
diff=x-y;
}
else
{
cout<<"\n addition and subtraction not possible \n";
getch();
exit(0);
}

cout<<"given first matrix is \n";
cout<<x;
cout<<"given second matrix is \n";
cout<<y;
cout<<" matrix1+matrix2 = \n";
cout<<sum;
cout<<" matrix1-matrix2 = \n";
cout<<diff;
getch();
}
