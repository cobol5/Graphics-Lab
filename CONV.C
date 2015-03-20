#include<stdio.h>
#include<dos.h>
#include<graphics.h>

int b[][2] = {
		300, 250,
		400, 250,
		500, 250,
		600, 250,
		200, 250,
		};

int w[] = {0, 90, 180, 270};

void draw(){
	int i;
	circle(200, 275, 25);
	circle(600, 275, 25);

	for(i=0;i<4;i++){
		arc(200, 275, w[i], w[i] + 30, 20);
		arc(600, 275, w[i], w[i] + 30, 20);
		w[i] = (w[i] + 5)%360;
		}

	line(200, 300, 600, 300);
	line(200, 250, 600, 250);

	line(90, 360, 180, 360);
	line(90, 360, 70, 310);
	line(180, 360, 200, 310);

	for(i=0;i<5;i++){
		setcolor(4);
		rectangle(b[i][0],b[i][1]-50,b[i][0]+10,b[i][1]);
		setcolor(15);
		if(b[i][0] < 130){
			b[i][0]=600;
			b[i][1]=250;
			}
		else if (b[i][0]<175){
			b[i][0] -= 4;
			b[i][1] += 10;
			}
		else{
			b[i][0] -= 5;
			}
		}
}

void main(){
	int gd = DETECT, gm;
	clrscr();
	initgraph(&gd, &gm, "c:\\turboc3\\bgi");
	while(!kbhit()){
		cleardevice();
		draw();
		delay(300);
	}
	closegraph();
	}