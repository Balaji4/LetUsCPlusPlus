#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<ctype.h>
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
void up();
void down();
void right();
void left();
void pfile(int,int);
char   getkey()
{
union REGS i,o;
//while(!kbhit())
//;
i.h.ah=0;
int86(22,&i,&o);

return(o.h.ah);
}
char ch;
int cc=10,cr=1;
fstream ofile;
char mob[10],p[500];
int i;
void main()
{


int r,c;
clrscr();
ofile.open("customer.txt",ios::in|ios::out);
/*cout<<"Mobile no:[ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]";
r=1;c=12;
for(i=0;i<10;i++)
{
gotoxy(c,r);
mob[i]=getche();
c+=3;
} */
i=0;
ofile.seekg(0);//ios::beg)

pfile(0,393);
//ofile.close();
//ofile.seekp(ios::beg);
gotoxy(8,1);
while(1)
{
ch=getch();
// ch=getkey();
 if(isalnum(ch)&&(ch!='H')&&ch!='P'&&ch!='M'&&ch!='K')
 {
 ch=char(ch);
 printf("%c",ch);
 }
 else
 {
  ch=getkey();
  switch(ch)
  {
  case 'H':up();//printf("UP key\n");

	 break;
  case 'P':down();//printf("Down key\n");
	 //if(cr==25);
	// {// ofile.seekp(80);
	// cr=1;
	// pfile(80,393);
	 //}
	 break;
  case 'M':right();//printf("RIGHT key\n");
	 break;
  case 'K':left();//printf("Left key\n");
	 break;
  case ';':exit(1);
//  default:exit(1);//printf("not working \n");
  }
  }
 }
}

void up()
{
cr--;
gotoxy(cc,cr);
}

void down()
{
cr++;
if(cr>=25)
{
pfile(393,786);
return;
}
else if(cr>=50)
{
pfile(786,1179);
return;
}
gotoxy(cc,cr);
}

void right()
{
cc++;
if(cc>=80)
cc=80;
gotoxy(cc,cr);
}

void left()
{
cc--;
if(cc<1)
cc=1;
gotoxy(cc,cr);
}


void pfile(int s,int t)
{
int i;
ofile.seekp(s);
while(ofile.tellp()!=t&&!ofile.eof())
{
//ofile.seekp(ios::cur);
ofile.get(p[i]);
//if(p[i]=='\n');
//cout<<endl;
cout<<p[i];
i++;

}
}