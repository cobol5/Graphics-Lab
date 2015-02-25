#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <dos.h>
#include <math.h>
 
void bezier (int x[4], int y[4]){
    int gd = DETECT, gm, i;
    double t;
    initgraph (&gd, &gm, "..\\bgi");
    cleardevice();
    for (t = 0.0; t < 1.0; t += 0.0005){
    	double xt = pow (1-t, 3) * x[0] + 3 * t * pow (1-t, 2) * x[1] +
    		    3 * pow (t, 2) * (1-t) * x[2] + pow (t, 3) * x[3];
    	double yt = pow (1-t, 3) * y[0] + 3 * t * pow (1-t, 2) * y[1] +
    		    3 * pow (t, 2) * (1-t) * y[2] + pow (t, 3) * y[3];
    	putpixel (xt, yt, WHITE);
        delay(5);
    }
    for (i=0; i<4; i++)
	   putpixel (x[i], y[i], YELLOW);
    getch();
    closegraph();
    return;
}
 
void main(){
    int x[4], y[4], i;
    printf ("\n\n\t\tEnter the x- and y-coordinates of the four control points: ");
    for (i=0; i<4; i++)
	   scanf ("%d%d", &x[i], &y[i]);
    clrscr();
    bezier (x, y);
}