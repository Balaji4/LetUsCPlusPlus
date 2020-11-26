#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
void table();
void setpos();
struct position
{
int x,y;
}p[81];
void main()
{
int t;
clrscr();
setpos();
textbackground(BLACK);
table();

for(t=0;t<81;t++)
{
gotoxy(p[t].x,p[t].y);
printf("%d",t);
}
getch();
}

void table()
{
int i,j,c=4;
char ch=179;
textcolor(RED);
for(i=0;i<10;i++)   //for no. of   column line
{
for(j=2;j<22;j++)   //
{
gotoxy(c,j);

if(i==3||i==6)
{
textcolor(BLUE);
}
//textcolor(BLUE);
if(j!=2)
cprintf("%c",ch);
if(j%2==0&&c<=36)
{
if(c==3||c==7)
textcolor(RED);
else textcolor(RED);
cprintf("____\n");
//continue;
}
//cprintf("%c",ch);
}
c+=4;
}
delline();

}


void setpos()
{
p[0].x=6;  p[0].y=3;
p[1].x=10; p[1].y=3;
p[2].x=14; p[2].y=3;
p[3].x=18; p[3].y=3;
p[4].x=22; p[4].y=3;
p[5].x=26; p[5].y=3;
p[6].x=30; p[6].y=3;
p[7].x=34; p[7].y=3;
p[8].x=38; p[8].y=3;
p[9].x=6;  p[9].y=5;   //2nd row
p[10].x=10;    p[10].y=5;
p[11].x=14;   p[11].y=5;
p[12].x=18;   p[12].y=5;
p[13].x=22;   p[13].y=5;
p[14].x=26;   p[14].y=5;
p[15].x=30;   p[15].y=5;
p[16].x=34;   p[16].y=5;
p[17].x=38;   p[17].y=5;
p[18].x=6;  p[18].y=7;   //3rd row
p[19].x=10;    p[19].y=7;
p[20].x=14;   p[20].y=7;
p[21].x=18;   p[21].y=7;
p[22].x=22;   p[22].y=7;
p[23].x=26;   p[23].y=7;
p[24].x=30;   p[24].y=7;
p[25].x=34;   p[25].y=7;
p[26].x=38;   p[26].y=7;
p[27].x=6;  p[27].y=9;   //4th row
p[28].x=10;    p[28].y=9;
p[29].x=14;   p[29].y=9;
p[30].x=18;   p[30].y=9;
p[31].x=22;   p[31].y=9;
p[32].x=26;   p[32].y=9;
p[33].x=30;   p[33].y=9;
p[34].x=34;   p[34].y=9;
p[35].x=38;   p[35].y=9;
p[36].x=6;  p[36].y=11;   //5th row
p[37].x=10;    p[37].y=11;
p[38].x=14;   p[38].y=11;
p[39].x=18;   p[39].y=11;
p[40].x=22;   p[40].y=11;
p[41].x=26;   p[41].y=11;
p[42].x=30;   p[42].y=11;
p[43].x=34;   p[43].y=11;
p[44].x=38;   p[44].y=11;
p[45].x=6;  p[45].y=13;   //6th row
p[46].x=10;    p[46].y=13;
p[47].x=14;   p[47].y=13;
p[48].x=18;   p[48].y=13;
p[49].x=22;   p[49].y=13;
p[50].x=26;   p[50].y=13;
p[51].x=30;   p[51].y=13;
p[52].x=34;   p[52].y=13;
p[53].x=38;   p[53].y=13;
p[54].x=6;  p[54].y=15;   //7th row
p[55].x=10;    p[55].y=15;
p[56].x=14;   p[56].y=15;
p[57].x=18;   p[57].y=15;
p[58].x=22;   p[58].y=15;
p[59].x=26;   p[59].y=15;
p[60].x=30;   p[60].y=15;
p[61].x=34;   p[61].y=15;
p[62].x=38;   p[62].y=15;
p[63].x=6;  p[63].y=17;   //8th row
p[64].x=10;    p[64].y=17;
p[65].x=14;   p[65].y=17;
p[66].x=18;   p[66].y=17;
p[67].x=22;   p[67].y=17;
p[68].x=26;   p[68].y=17;
p[69].x=30;   p[69].y=17;
p[70].x=34;   p[70].y=17;
p[71].x=38;   p[71].y=17;
p[72].x=6;  p[72].y=19;   //9th row
p[73].x=10;    p[73].y=19;
p[74].x=14;   p[74].y=19;
p[75].x=18;   p[75].y=19;
p[76].x=22;   p[76].y=19;
p[77].x=26;   p[77].y=19;
p[78].x=30;   p[78].y=19;
p[79].x=34;   p[79].y=19;
p[80].x=38;   p[80].y=19;

}