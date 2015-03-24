#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>

int x, y;

int 	tl[3][2] = {257, 174, 257, 154, 257, 134},
	bl[3][2] = {214, 301, 234, 301, 254, 301},
	tr[3][2] = {424, 177, 404, 177, 384, 177},
	br[3][2] = {381, 304, 381, 324, 381, 344};

int st[4][2] = {
		2, 0,
		1, 1,
		0, 2,
		1, 1
		};

int count = 0, cols[3] = {4, 14, 2}, up[3] = {301, 351, 401},
	dn[3] = {177, 127, 77}, rt[3] = {214, 164, 114}, lt[3] = {381, 431, 481};

void clearsig(){
	int j = count;
	setfillstyle(1, BLACK);
	floodfill(tl[st[j][0]][0], tl[st[j][0]][1], getmaxcolor());
	floodfill(br[st[j][0]][0], br[st[j][0]][1], getmaxcolor());
	setfillstyle(1, BLACK);
	floodfill(bl[st[j][0]][0], bl[st[j][0]][1], getmaxcolor());
	floodfill(tr[st[j][0]][0], tr[st[j][0]][1], getmaxcolor());

}

void changesig(){
	int j = count;
	setfillstyle(1, cols[st[j][1]]);
	floodfill(tl[st[j][0]][0], tl[st[j][0]][1], getmaxcolor());
	floodfill(br[st[j][0]][0], br[st[j][0]][1], getmaxcolor());
	setfillstyle(1, cols[st[j][0]]);
	floodfill(bl[st[j][0]][0], bl[st[j][0]][1], getmaxcolor());
	floodfill(tr[st[j][0]][0], tr[st[j][0]][1], getmaxcolor());
}

void cleanroad(){
	int h[8] = {0, 190, 640, 190, 640, 290, 0, 290};
	int v[8] = {270, 0, 370, 0, 370, 480, 270, 480};
	setfillstyle(1, 0);
	setlinestyle(3,1,1);
	fillpoly(4, h);
	fillpoly(4, v);
	line(x, 0, x, 2*y+2);
	line(0, y, getmaxx(), y);
	setlinestyle(0,1,1);
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


	floodfill(10, 10, getmaxcolor());
	floodfill(400, 100, getmaxcolor());
	floodfill(100, 400, getmaxcolor());
	floodfill(400, 400, getmaxcolor());

	}

void moveupdwn(){
	int i;
	for(i=0;i<3;i++){
		rectangle(x-40, up[i], x-10, up[i]+20);
		up[i] -= 5;
		rectangle(x+10, dn[i], x+40, dn[i]-20);
		dn[i] += 5;
	}
	}

void nmoveupdwn(){
	int i;
	for(i=0;i<3;i++){
		if(up[i]<290) up[i] -= 7;
		if(dn[i]>190) dn[i] += 7;
		rectangle(x-40, up[i], x-10, up[i]+20);
		rectangle(x+10, dn[i], x+40, dn[i]-20);
	}
	}

void moveleftri8(){
	int i;
	for(i=0;i<3;i++){
		rectangle(lt[i], y-10, lt[i]+20, y-40);
		lt[i] -= 5;
		rectangle(rt[i], y+10, rt[i]-20, y+40);
		rt[i] += 5;
	}
	}

void nmoveleftri8(){
	int i;
	for(i=0;i<3;i++){
		if(lt[i]<370) lt[i] -= 7;
		if(rt[i]>270) rt[i] += 7;
		rectangle(lt[i], y-10, lt[i]+20, y-40);
		rectangle(rt[i], y+10, rt[i]-20, y+40);
	}
	}

void main(){
	int gd=DETECT, gm, n=0;
	initgraph(&gd, &gm, "..\\BGI");
	x = getmaxx()/2;
	y = getmaxy()/2;


	while(!kbhit()){
		//clearsig();
		draw();
		changesig();
		if(st[count][0]==2){
			moveupdwn();
		       //	nmoveleftri8();
		}
		else{
			nmoveupdwn();
		}
		if(st[count][1]==2){
			moveleftri8();
		       //	nmoveupdwn();
		}
		else{
			nmoveleftri8();
		}
		/*if(st[count][1]==1&&st[count][0]==1){
			nmoveupdwn();
			nmoveleftri8();
		} */
		delay(300);
		clearsig();
		cleanroad();
		n = ++n%10;
		if(n==0) count = ++count%4;

	}
}