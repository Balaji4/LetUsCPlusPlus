#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#define MAX 20
#include<conio.h>
enum { FALSE, TRUE };

void mid_line (int x1, int y1, int x2, int y2);
void swap (int* a, int* b);

int main (void)
{
	clrscr();
	int n;
	int i;
	int pt[MAX][2];
	char text[11];
	int gd=DETECT, gm;

	printf ("line graph\n");
	printf ("enter the number of points: ");
	scanf ("%d", &n);
	printf ("Enter the x- and y-coordinates of each point:\n");
	for (i=0; i<n; i++)
	   scanf ("%d%d", &pt[i][0], &pt[i][1]);

	initgraph (&gd, &gm, "l:");
	if (graphresult() != grOk) {
	   fprintf (stderr, "main: Unable to load graphics driver.\n");
	   exit (1);
	}

	outtextxy (pt[0][0], pt[0][1], "*");
	sprintf (text, "(%d, %d)", pt[0][0], pt[0][1]);
	outtextxy (pt[0][0]+10, pt[0][1], text);

	for (i=0; i<n-1; i++) {
	   getch();
	   mid_line (pt[i][0], pt[i][1], pt[i+1][0], pt[i+1][1]);
	   outtextxy (pt[i+1][0], pt[i+1][1], "*");
	   sprintf (text, "(%d, %d)", pt[i+1][0], pt[i+1][1]);
	   outtextxy (pt[i+1][0]+10, pt[i+1][1]+10, text);
	}
	getch();

	closegraph();
	return 0;
}

void mid_line (int x1, int y1, int x2, int y2)
{
	int dx, dy;             /* x- and y-coordinate differences. */
	int d;                  /* Decision variable. */
	int incr_y;             /* By how many pixels y should be changed. */
	int incr_e, incr_ne;    /* Store increments to move to E. or NE. */
	int slopegt1 = FALSE;   /* Flag to check if slope > 1. */

	dx = abs (x1 - x2);
	dy = abs (y1 - y2);

	/* If slope > 1, reverse the roles of the x- and y-axes. */
	if (dy > dx) {
	   swap (&x1, &y1);
	   swap (&x2, &y2);
	   swap (&dx, &dy);
	   slopegt1 = TRUE;
	}

	/* Always start from the left endpoint. */
	if (x1 > x2) {
	   swap (&x1, &x2);
	   swap (&y1, &y2);
	}

	/* If the line ascends, increment y. Else, decrement it. */
	if (y1 > y2)
	   incr_y = -1;
	else
	   incr_y = +1;

	/* These values are derived in the theory of Bresenham's algorithm.
	* Everywhere we are multiplying by 2 to avoid floating-point.
	* This won't matter, as we are interested only in the sign. */

	d = 2 * dy - dx;    /* Initially d = 2(a + b/2) = 2 * dy - dx. */

	/* The increments are obtained from the difference of the line-
	* equations at the two pixels. */
	incr_e = 2 * dy;
	incr_ne = 2 * (dy - dx);

	/* Plot the points. If d <= 0 move east, else move north-east. */
	while (x1 < x2) {
	   if (d <= 0)
		  d += incr_e;
	   else {
		  d += incr_ne;
		  y1 += incr_y;
	   }
	   x1++;

	   if (slopegt1)
		  putpixel (y1, x1, WHITE);
	   else
		  putpixel (x1, y1, WHITE);
	}
}



void swap (int *a, int *b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}




