#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>
#include <dos.h>

int x[10][4], y[10][4], n = 0;

void bezier (){
    int i, j;
    double t;
    char coord[10];
    for(j=0;j<n;j++){
	    for (t=0.0;t<1.0;t+=0.001){
		double xt = pow (1-t, 3) * x[j][0] + 3 * t * pow (1-t, 2) * x[j][1] +
			    3 * pow (t, 2) * (1-t) * x[j][2] + pow (t, 3) * x[j][3];
		double yt = pow (1-t, 3) * y[j][0] + 3 * t * pow (1-t, 2) * y[j][1] +
			    3 * pow (t, 2) * (1-t) * y[j][2] + pow (t, 3) * y[j][3];
		putpixel (xt, yt, j+1);
		delay(2);
	    }
    for (i=0; i<4; i++){
		putpixel (x[j][i], y[j][i], WHITE);
		sprintf(coord, "%d. (%d,%d)", i+1, x[j][i], y[j][i]);
		setcolor(j+1);
		outtextxy(x[j][i]+10, y[j][i]-10, coord);
		setcolor(15);
		}
    delay(100);
    }
    return;
}

void main(){
    int i, p;
    int gd = DETECT, gm ;
    char ch='y';
    printf ("Enter coordinates : ");
    for (i=0; i<4; i++)
	scanf ("%d%d", &x[0][i], &y[0][i]);
    n=1;
    clrscr();
    initgraph (&gd, &gm, "C:\\TurboC3\\BGI");
    while(ch=='y'){
		bezier ();
		moveto(0,0);
		printf("Do you want to modify? (y/n) : ");
		scanf("%c", &ch);
		scanf("%c", &ch);
		if(ch=='n') break;
		for(i=0;i<4;i++){
			x[n][i] = x[n-1][i];
			y[n][i] = y[n-1][i];
			}
		printf("Enter the CP you wanna modify(1-4) : ");
		scanf("%d", &p);
		printf("Enter the new coords :\n");
		scanf("%d%d",&x[n][p-1],&y[n][p-1]);
		++n;
		clrscr();
		cleardevice();
		}
    closegraph();
}
