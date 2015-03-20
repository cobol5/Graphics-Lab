#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<dos.h>

int n = 19, counter = 0;
float ang = 0.0;

int cframe1[][2]={
	250, 250,
	350, 250,
	300, 290,
	250, 250,
	250, 248,
	240, 248,
	240, 246,
	260, 246,
	260, 248,
	250, 248,
	247, 300,
	300, 290,
	350, 250,
	347, 248,
	330, 240,
	347, 248,
	328, 242,
	345, 248,
	354, 300
	};

int cframe[][2]={
	250, 250,
	350, 250,
	300, 290,
	250, 250,
	250, 248,
	240, 248,
	240, 246,
	260, 246,
	260, 248,
	250, 248,
	247, 300,
	300, 290,
	350, 250,
	347, 248,
	330, 240,
	347, 248,
	328, 242,
	345, 248,
	354, 300
	};

int cir[][2] = {
	2, 10,
	10, 6,
	10, 25,
	18, 25
};


void matrixmul(){
	int i, j, k, pivx = 300, pivy = 200;
	float s = sin(ang), c = cos(ang), x, y;
	for(i=0;i<n;i++){

		cframe[i][0] = cframe1[i][0] - pivx;
		cframe[i][1] = cframe1[i][1] - pivy;

		x = cframe[i][0] * c - cframe[i][1] * s;
		y = cframe[i][0] * s + cframe[i][1] * c;

		cframe[i][0] = x + pivx;
		cframe[i][1] = y + pivy;
	}

}


void draw(){
	int i,j;
	for (i=0;i<n-1;i++){
		line(cframe[i][0], cframe[i][1], cframe[i+1][0], cframe[i+1][1]);
	}
	for (i=0;i<4;i++){
		circle(cframe[cir[i][0]][0], cframe[cir[i][0]][1], cir[i][1]);
	}
	line(cframe[cir[0][0]][0], cframe[cir[0][0]][1]-cir[0][1], cframe[cir[1][0]][0], cframe[cir[1][0]][1]-cir[1][1]);
	line(cframe[cir[0][0]][0], cframe[cir[0][0]][1]+cir[0][1], cframe[cir[1][0]][0], cframe[cir[1][0]][1]+cir[1][1]);

       line(cframe[10][0], cframe[10][1], cframe[18][0], cframe[18][1]);
}

void fill(){
	int p[10] = {0,0, 0,480, 640,480, 640,0, 0,0};
	setcolor(BLACK);
	fillpoly(5,p);
	setcolor(WHITE);
}

void main(){
int gd = DETECT, gm;
initgraph(&gd, &gm, "..\\bgi");
while(!kbhit()){
//	fill();
	cleardevice();
	draw();
	delay(300);
	counter++;
	switch(counter){
	case 0: ang = 0.0; matrixmul(); break;
	case 10: ang = -2; matrixmul(); break;
	case 20: ang = 2; matrixmul(); break;
	case 30: ang = 0; counter = 0;break;
	}
	}
	closegraph();
}