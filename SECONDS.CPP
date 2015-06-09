#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<dos.h>
void main(){
	int gd=DETECT,gm;
	int midx, midy, th, x, xt, yt, y;
	float ang;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	midx = getmaxx()/2;
	midy = getmaxy()/2;
	x = xt = midx;
	y = yt = midy - 100;
	th = 0;
	while(!kbhit()){
		line(x, y, midx, midy);
		circle(midx, midy, 110);
		putpixel(midx, midy, 15);
		ang = th*3.14/180;
		x = ((double)(xt-midx)*(double)cos(ang))-((double)(yt-midy)*(double)sin(ang)) + midx;
		y = ((double)(xt-midx)*(double)sin(ang))+((double)(yt-midy)*(double)cos(ang)) + midy;
		delay(1000);
		th = (th+6)%360;
		cleardevice();
	}
	closegraph();
	}