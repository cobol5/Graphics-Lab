
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include<dos.h>

int pend[2] = {320, 300};

int main(void)
{ int gdriver = DETECT, gmode, errorcode;
   initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");
   while(!kbhit()){

	while(pend[1]>200){
	cleardevice();
	circle(pend[0], pend[1], 25);
	floodfill(pend[0], pend[1], getmaxcolor());  line(320, 0, pend[0], pend[1]);
	pend[0]-=5;
	pend[1]-=3;
	delay(100);
	}while(pend[1]!=300){
	cleardevice();
	circle(pend[0], pend[1], 25);
	floodfill(pend[0], pend[1], getmaxcolor()); line(320, 0, pend[0], pend[1]);
	pend[0]+=5;
	pend[1]+=3;
	delay(100);
	}
	while(pend[1]>200){
	cleardevice();
	circle(pend[0], pend[1], 25);
	floodfill(pend[0], pend[1], getmaxcolor()); line(320, 0, pend[0], pend[1]);
	pend[0]+=5;
	pend[1]-=3;
	delay(100);
	}
	while(pend[1]!=300){
	cleardevice();
	circle(pend[0], pend[1], 25);
	floodfill(pend[0], pend[1], getmaxcolor());  line(320, 0, pend[0], pend[1]);
	pend[0]-=5;
	pend[1]+=3;
	delay(100);
	}
   }
   closegraph();
   return 0;
}
