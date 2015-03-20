#include<stdio.h>
#include<graphics.h>
#include<dos.h>

int speed[6] = {0, 400, 200, 100, 50, 10}, sp=2;

int blade[3] = {0, 120, 240}, x, y;

void draw(){
	int i;
	for(i=0; i<121; i+=30)
		circle(x, y, i);

	for(i=0;i<3;i++){
		pieslice(x, y, blade[i], blade[i]+30, 110);
		if(blade[i] == 330) blade[i] = 0;
		else blade[i] += 30;
		}
}

void shift(int a, int b){
	int i, j;
	if(b>a)
	for(i=a;i<b;i++){
		for(j=0;j<3;j++){
			sp = i;
			cleardevice();
			draw();
			delay(speed[sp]);
		}
	}
	else
	for(i=a;i>b;i--){
		for(j=0;j<5;j++){
			sp = i;
			cleardevice();
			draw();
			delay(speed[sp]);
		}
	}
}

void main(){
	int gd = DETECT, gm, t;
	char c='1';
	initgraph(&gd, &gm, "..\\BGI");
	x=getmaxx()/2;
	y=getmaxy()/2;
	while(c!='0'){
		while(!kbhit()){
			cleardevice();
			draw();
			delay(speed[sp]);
		}
		c = getch();
		t = sp;
		sp = (int)c-(int)'0';
		if(sp>6||sp<0)
			sp = 2;
		shift(t, sp);
		if(c == '0') getch();
	}
}