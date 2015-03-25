#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<dos.h>

int len = 110;

void drawwell(){
	circle(400, 210, 10);
	rectangle(300, 300, 500, 320);
	rectangle(310, 320, 490, 400);
	rectangle(398, 200, 402, 300);
	setfillstyle(1, 15);
	floodfill(400, 210, getmaxcolor());
	floodfill(399, 250, getmaxcolor());
	setfillstyle(4, 8);
	floodfill(310, 301, getmaxcolor());
	setfillstyle(9, 6);
	floodfill(312, 322, getmaxcolor());
}
int y2;

void draw(){
	int y = 210+len;
	if(len>50){
		if(y>300){y2=y;}
		else if(y>270){y2=300;}
		else y2=y+30;
		line(410, 210, 410, y);
		line(392, 205, 290, 290);
		line(290, 290, 290, 390-len);
		rectangle(400, y, 420, y2);

		circle(250, 270, 10);
		line(250, 280, 250, 350);
		line(250, 350, 249, 400);
		line(250, 350, 253, 400);
		line(250, 290, 290, 290+random(5));
		line(250, 290, 290, 290+random(7));

		len-=3;
		}

	else {y2 = 410;
	if(y2>270){
		rectangle(y2-10, 260, y2+10, 290);
		circle(250, 270, 10);
		line(250, 280, 250, 350);
		line(250, 350, 249, 400);
		line(250, 350, 253, 400);
		line(250, 290, y2, 270);
		line(250, 290, y2, 270);
		y2-=3;
		}  }
	drawwell();
}

void main(){
	int gd=DETECT, gm;
	initgraph(&gd, &gm, "..\\BGI");
	while(!kbhit()){
		cleardevice();
		draw();
		delay(300);
	}
}