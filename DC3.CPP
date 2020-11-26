#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<fstream.h>
#include<stdio.h>
#include<dos.h>
#include<stdlib.h>
#define LEFT 92
#define RIGHT 59
#define UP 91
#define DOWN 80
char   getkey()
{
union REGS i,o;
//while(!kbhit())
//;
i.h.ah=0;
int86(22,&i,&o);
return(o.h.ah);
}
int cc=13,cr=1;

char ch;

char p1[]="Mobile No: [ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]\n\n";
char p2[]="Device Installation at:[ ]\n\n";
char p3[]="Local Address:[ ]\n\n";
char p4[]="Permanent Address:[ ]\n\n";
char p5[]="Serial No:[ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]\n\n";
char p6[]="Gender: M[ ] F[ ]\n\n";
char p7[]="Type of Connection: [ ]Individual 	[ ]Company Owned\n\n";
char p8[]="Title: [ ]Mr  [ ]Mrs  [ ]Ms\n\n";
char p9[]="3G Wireless Broadband Device /Photon(IMEI) [ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]\n\n";
char p10[]="Name: [ ][ ][ ][ ] [ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]\n\n";
char p11[]="Father's/Husband's Name: [ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]\n\n";
char p12[]="Local Address:[ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]";
char p13[]="  [ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]\n\n";
char p14[]="City/Town/Village:[ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]\n\n";
char p15[]="State:[ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]\n\n";
char p16[]="PIN Code:[ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]\n\n";
char p17[]="Landmark/Post Office:[ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]\n\n";
char p18[]="Permanent Address:[ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]\n\n";
char p19[]="[ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]\n\n";
char p20[]="City/Town/Village:[ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]\n\n";
char p21[]="District:[ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]\n\n";
char p22[]="State:[ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]\n\n";
char p23[]="PIN Code:[ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]\n\n";
char p24[]="Landmark/Post Office:[ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]\n\n";
char p25[]="Nationality:[ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]\n\n";
char p26[]="Date of Birth:[ ][ ][ ][ ][ ][ ][ ][ ]\n\n";
char p27[]="Email:[ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]\n\n";
char p28[]="If you are a Foreign National Customer,please fill Passport No.:\n\n";
char p29[]="[ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]\n\n";
char p30[]="VISA no.:[ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]\n\n";
char p31[]="Duration of stay:  [ ]Permanent	  [ ]Temporary    Period of stay from:   	       to                \n\n";
char p32[]="PAN No./Photo ID No.:[ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]\n\n";
char p33[]="Register Me for DND: [ ]	Register me for Partial DND (Refer T&C)  [ ]1  [ ]2  [ ]3  [ ]4  [ ]5  [ ]6  [ ]7\n\n";

void up();
void down();
void right();
void left();
void main()
{
clrscr();
cout<<p1;
cout<<p2;
cout<<p3;
cout<<p4;
cout<<p5;
cout<<p6;
cout<<p7;
cout<<p8;
cout<<p9;
cout<<p10;
cout<<p11;
cout<<p12;
//cout<<p13;
//cout<<p14;
//cout<<p15;
//cout<<p16;
while(1)
{
gotoxy(cc,cr);
ch=getch();
if(isalpha(ch))
{
printf("%c",ch);
}
else
{
ch=getkey();
}
switch(ch)
{
case '[':up();//printf("UP key\n");
	 break;
case 'P':down();//printf("Down key\n");
	 break;
case ';':right();//printf("RIGHT key\n");
	 break;
case '\\':left();//printf("Left key\n");
	 break;
case '9':printf("%c",ch);
	 break;
default:exit(0);//printf("not working \n");
}
}
}



void up()
{
cr--;
if(cr<1)
{
cr=1;
return;
}
gotoxy(cc,cr);
}

void down()
{
cr++;
if(cr>=25)
{
cr=25;
return;
}
else if(cr>=50)
{
return;
}
gotoxy(cc,cr);
}

void right()
{
cc+=3;
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




