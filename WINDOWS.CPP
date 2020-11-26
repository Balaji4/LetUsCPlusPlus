#include <conio.h>

int main(void)
{
   clrscr();
   window(10,10,40,11);
   textcolor(BLACK);
   textbackground(RED);
   cprintf("This is a test\r\n");
   getch();
   return 0;
}