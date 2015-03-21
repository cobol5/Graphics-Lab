#include<stdlib.h>
#include<graphics.h>
#include<stdio.h>
#include<math.h>
#include<dos.h>

int height = 300, midx;

void bezier (int x[4], int y[4]){
	int i;
	double t, xt, yt;
	for (t = 0.0; t < 1.0; t += 0.0005){
		i = random(9) + 1;
		xt = pow (1-t, 3) * x[0] + 3 * t * pow (1-t, 2) * x[1] + 3 * pow (1-t, 1) * (t*t) * x[2] + 1 * t*t*t * x[3];
		yt = pow (1-t, 3) * y[0] + 3 * t * pow (1-t, 2) * y[1] + 3 * pow (1-t, 1) * (t*t) * y[2] + 1 * t*t*t * y[3];
		if(i%2==0)
		putpixel (xt, yt, RED);
		if(i%5==0)
		putpixel (xt, yt, YELLOW);

		}

//	for (i=0; i<6; i++)
  //		putpixel (x[i], y[i], YELLOW);
	}

void draw(){
	int x1[4], x2[4], y1[4], y2[4], i;

	x1[0] = random(6) + midx - 3;
	x1[1] = random(6) + midx - 30;
	x1[2] = random(6) + midx - 20;
	x1[3] = midx;

	x2[0] = x1[0];
	x2[1] = random(6) + midx + 30;
	x2[2] = random(6) + midx + 20;
	x2[3] = midx;

	y1[0] = height - 100;
	y1[1] = random(5) + height - 30;
	y1[2] = random(5) + height - 15;
	y1[3] = height - 7;

	y2[0] = height - 100;
	y2[1] = random(5) + height - 30;
	y2[2] = random(5) + height - 15;
	y2[3] = height - 7;

	rectangle(midx-20, height, midx+20, getmaxy());
	rectangle(midx-1, height-5, midx+1, height);

	bezier(x1, y1);
	bezier(x2, y2);
}

void main(){
	int gd=DETECT, gm, count = 0;
	initgraph(&gd, &gm, "C:\\TurboC3\\BGI");
	midx = getmaxx()/2;
	while(height<getmaxy()-3&&!(kbhit())){
		cleardevice();
		draw();
		delay(300);
		count++;
		if(count==3){
			height += 3;
			count = 0;
			}
	}
	getch();
	cleardevice();
	closegraph();
}
