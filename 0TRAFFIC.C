#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>

int x, y;

int 	tl[3][2] = {257, 134, 257, 154, 257, 174},
	bl[3][2] = {214, 301, 234, 301, 254, 301},
	tr[3][2] = {424, 177, 404, 177, 384, 177},
	br[3][2] = {381, 344, 381, 324, 381, 304};

int st[4][2] = {
		2, 0,
		1, 1,
		0, 2,
		1, 1
		};

int count = 0, cols[3] = {4, 14, 2};

void changesig(){
	int j = count;
	setfillstyle(1, cols[st[j][1]]);
	floodfill(tl[st[j][0]][0], tl[st[j][0]][1], getmaxcolor());
	floodfill(br[st[j][0]][0], br[st[j][0]][1], getmaxcolor());
	setfillstyle(1, cols[st[j][0]]);
	floodfill(bl[st[j][0]][0], bl[st[j][0]][1], getmaxcolor());
	floodfill(tr[st[j][0]][0], tr[st[j][0]][1], getmaxcolor());
}

void draw(){
	rectangle(-1, -1, x-50, y-50);
	rectangle(x+50, -1, 2*x+1, y-50);
	rectangle(-1, y+50, x-50, 2*y+1);
	rectangle(x+50, y+50, 2*x+1, 2*y+1);
	setfillstyle(11, 10);

	rectangle(x-72, y-117, x-52, y-52);   // top left
	circle(x-62, y-105, 9);
	circle(x-62, y-85, 9);
	circle(x-62, y-65, 9);

	rectangle(x-117, y+72, x-52, y+52);   // bottom left
	circle(x-105, y+62, 9);
	circle(x-85, y+62, 9);
	circle(x-65, y+62, 9);

	rectangle(x+117, y-72, x+52, y-52);   // top right
	circle(x+105, y-62, 9);
	circle(x+85, y-62, 9);
	circle(x+65, y-62, 9);

	rectangle(x+72, y+117, x+52, y+52);   // bottom right
	circle(x+62, y+105, 9);
	circle(x+62, y+85, 9);
	circle(x+62, y+65, 9);

	/*
	floodfill(10, 10, getmaxcolor());
	floodfill(400, 100, getmaxcolor());
	floodfill(100, 400, getmaxcolor());
	floodfill(400, 400, getmaxcolor());
				*/
	}

void main(){
	int gd=DETECT, gm, n=-1;
	initgraph(&gd, &gm, "..\\BGI");
	x = getmaxx()/2;
	y = getmaxy()/2;


	while(!kbhit()){
		cleardevice();
		draw();
		changesig();
		delay(300);
		n = ++n%5;
		if(n==0) count = ++count%4;

	}
}