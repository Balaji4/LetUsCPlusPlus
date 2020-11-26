//7. C program to demonstrate Cohen-Sutherland line-clipping algorithm.

#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#define MAX 20
#include<conio.h>

/* Outcodes. The matrix is given below:
 * 1001 | 0001 | 0101
 * -----+------+-----
 * 1000 | 0000 | 0100
 * -----+------+-----
 * 1010 | 0010 | 0110 */

enum { TOP = 0x1, BOTTOM = 0x2, RIGHT = 0x4, LEFT = 0x8 };

enum { FALSE, TRUE };
typedef unsigned int outcode;

void cohen_sutherland (double x1, double y1, double x2, double y2,
		  double xmin, double ymin, double xmax, double ymax);

outcode compute_outcode (int x, int y,
	   int xmin, int ymin, int xmax, int ymax);

int main (void)
{
	int n;
	int i, j;
	int ln[MAX][4];
	int clip[4];
	int gd = DETECT, gm;

	printf ("This program demonstrates Cohen-Sutherland algorithm.\n");
	printf ("How many lines are to be clipped? ");
	scanf ("%d", &n);

	printf ("Enter the x- and y-coordinates of the line-endpoints:\n");
	for (i=0; i<n; i++)
	   for (j=0; j<4; j++)
		  scanf ("%d", &ln[i][j]);

	printf ("Enter the x- and y-coordinates of the left-top and right-");
	printf ("bottom corners\nof the clip window:\n");
	for (i=0; i<4; i++)
	   scanf ("%d", &clip[i]);

	initgraph (&gd, &gm, "l:");
	if (graphresult() != grOk) {
	   fprintf (stderr, "main: Unable to load graphics driver.\n");
	   exit (1);
	}

	/* Initial figure. */
	rectangle (clip[0], clip[1], clip[2], clip[3]);
	for (i=0; i<n; i++)
	   line (ln[i][0], ln[i][1], ln[i][2], ln[i][3]);
	getch();

	/* Clip each line and show the new figure. */
	cleardevice();
	rectangle (clip[0], clip[1], clip[2], clip[3]);
	for (i=0; i<n; i++) {
	   cohen_sutherland (ln[i][0], ln[i][1], ln[i][2], ln[i][3],
		  clip[0], clip[1], clip[2], clip[3]);
	   getch();
	}

	closegraph();
	return 0;
}

void cohen_sutherland (double x1, double y1, double x2, double y2,
		  double xmin, double ymin, double xmax, double ymax)
{
	int accept;     /* Is line within the clip-window? */
	int done;       /* Are we done clipping external regions of the line? */
	outcode outcode1, outcode2;     /* Outcodes of the endpoints. */

	/* Initialize. */
	accept = FALSE;
	done = FALSE;

	outcode1 = compute_outcode (x1, y1, xmin, ymin, xmax, ymax);
	outcode2 = compute_outcode (x2, y2, xmin, ymin, xmax, ymax);

	do {
	   /* Line totally inside: trivially accept. */
	   if (outcode1 == 0 && outcode2 == 0) {
		  accept = TRUE;
		  done = TRUE;
	   }

	   /* Line totally outside: trivially reject */
	   else if (outcode1 & outcode2) {
		  done = TRUE;
	   }

	   /* Line partly inside. Clip the outside parts iteratively.
		* Use equations: y = y0 + m * (x - x0)
		*                x = x0 + (1/m) * (y - y0)             */
	   else {
		  double x, y;

		  /* Consider the point outside the clip-window. */
		  int outcode_ex = outcode1 ? outcode1 : outcode2;

		  /* It is above the clip-window. */
		  if (outcode_ex & TOP) {
			 x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
			 y = ymax;
		  }

		  /* It is below the clip-window. */
		  else if (outcode_ex & BOTTOM) {
			 x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
			 y = ymin;
		  }

		  /* It is to the right of the clip-window. */
		  else if (outcode_ex & RIGHT) {
			 y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
			 x = xmax;
		  }

		  /* It is to the left of the clip-window. */
		  else {
			 y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
			 x = xmin;
		  }

		  /* Clip. */
		  if (outcode_ex == outcode1) {
			 x1 = x;
			 y1 = y;
			 outcode1 = compute_outcode (x1, y1, xmin, ymin, xmax, ymax);
		  } else {
			 x2 = x;
			 y2 = y;
			 outcode2 = compute_outcode (x2, y2, xmin, ymin, xmax, ymax);
		  }
	   }
	} while (done == FALSE);

	/* If inside, draw. Else, forget it. */
	if (accept == TRUE)
	   line (x1, y1, x2, y2);
}

outcode compute_outcode (int x, int y,
	   int xmin, int ymin, int xmax, int ymax)
{
	outcode oc = 0;

	if (y > ymax)
	   oc |= TOP;
	else if (y < ymin)
	   oc |= BOTTOM;

	if (x > xmax)
	   oc |= RIGHT;
	else if (x < xmin)
	   oc |= LEFT;

	return oc;
}
