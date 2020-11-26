#include <conio.h>

int main(void)
{
   clrscr();
   window(10,10,60,11);
   textcolor(RED);
   textbackground(BLACK);
   cprintf("This is a test\r\n");
   getch();
   return 0;
}