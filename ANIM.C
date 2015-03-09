#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<graphics.h>

int sunv=1, cloudv = 1, rainv = 0, icebergv = 0; //visibility

int icecountdown = 50, oddeven = 0, tempcounter = 0;

int shipman[][5]={ //type,x1,y1,x2,y2
		0,138,285,108,240,  //lower deck bottom
		0,108,240,433,240,  //lower deck left
		0,433,240,403,285,  //lower deck top
		0,403,285,138,285,  //lower deck right
		1,138,220,403,240,  //middle deck rect
		1,148,224,188,236,  //window
		1,198,224,238,236,  //window
		1,248,224,288,236,  //window
		1,298,224,338,236,  //window
		1,348,224,393,236,  //window
		0,145,220,145,194,  //upper deck
		0,145,194,233,194,  //upper deck
		0,233,194,250,220,  //upper deck
		2,350,201,5,0,     //man face
		0,350,206,350,220, //man body
		0,350,209,359,208, //hand 1
		0,350,209,357,206,  //hand 2
		0,355,190,357,210, //umbrella stick
		3,355,190,190,10  //umbrella arc
		};

int sea[][4]={  //horizon
		0,275,128,275,
		413,275,640,275,
		};

int cloud[][3]={ // [x,y,rad]
			300,180,10,
			490,50,10,
			130,150,15,
			620,100,12,
			500,160,10
		};

int sun[3]={500,70,20};

int iceberg[][16]={
			600,425, 623,355, 630,360, 645,380, 657,353, 674,409, 680,425, 600,425,
			750,385, 756,370, 760,330, 800,328, 829,353, 850,365, 855,385, 750,385,
			900,285, 903,240, 910,225, 925,238, 939,243, 955,265, 970,285, 900,285
		};

void draw(){
	int i,x,y,t;
	srand(time(NULL));
	//sun
	if(sunv){
		circle(sun[0],sun[1],sun[2]);
		floodfill(sun[0],sun[1],getmaxcolor());
		sun[0] -= 5;
		if(sun[0] < -5){
			sunv = 0;
			rainv = 2;
		}
	}
	//clouds
	if(cloudv){
		for(i=0;i<5;i++){
			if(cloud[i][0]<10){
				cloud[i][0] += (random(100)+600);
			}
			pieslice(cloud[i][0],cloud[i][1],0,180,cloud[i][2]);
			pieslice(cloud[i][0]-12,cloud[i][1],0,180,cloud[i][2]-5);
			pieslice(cloud[i][0]+12,cloud[i][1],0,180,cloud[i][2]-5);
			cloud[i][0] -= 10;
		}
	}
	//rain
	if(rainv){
		for(i=0;i<100;i++){
			x = random(620)+10;
			y = random(450);
			t = random(15);
			line(x,y,x+t,y-t);
		}
		icecountdown -= 1;
		if(icecountdown == 0){
			rainv = 0;
			icebergv = 1;
		}
	}
	//iceberg
	if(icebergv){
		for(i=0;i<3;i++){
		fillpoly(8,iceberg[i]);
		t = random(5)+1;
		iceberg[i][0] -= t;
		iceberg[i][2] -= t;
		iceberg[i][4] -= t;
		iceberg[i][6] -= t;
		iceberg[i][8] -= t;
		iceberg[i][10] -= t;
		iceberg[i][12] -= t;
		iceberg[i][14] -= t;

		}
	}
	//sea
	for(i=0;i<2;i++){
		line(sea[i][0], sea[i][1], sea[i][2], sea[i][3]);
	}
	for(i=0;i<30;i++){
		x = random(600);
		y = random(200)+280;
		line(x,y,x+random(100)+10,y);
	}
	for(i=0;i<17+rainv;i++){
		switch(shipman[i][0]){
		case 0: line(shipman[i][1], shipman[i][2],
				shipman[i][3], shipman[i][4]);
			if(oddeven){shipman[i][2] -= 1;shipman[i][4] -= 1;}
			else{shipman[i][2] += 1; shipman[i][4] += 1;}
			break;
		case 1: rectangle(shipman[i][1], shipman[i][2],
				shipman[i][3], shipman[i][4]);
			if(oddeven){shipman[i][2] -= 1;shipman[i][4] -= 1;}
			else{shipman[i][2] += 1; shipman[i][4] += 1;}
			break;
		case 2: circle(shipman[i][1], shipman[i][2],
				shipman[i][3]);
			if(oddeven){shipman[i][2] -= 1;}
			else{shipman[i][2] += 1;}
			break;
		case 3: pieslice(shipman[i][1], shipman[i][2],
				180-shipman[i][3], shipman[i][3], shipman[i][4]);
			if(oddeven){shipman[i][2] -= 1;}
			else{shipman[i][2] += 1;}
			break;
		}
	}
	tempcounter++;
	if(tempcounter%3==0){
		tempcounter %= 3;
		oddeven = 1 - oddeven;
	}
}
void main(){
	int gd=DETECT, gm, i, turn;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	while(!kbhit()){
		cleardevice();
		draw();
		delay(250);//random(200)+100);
		}
	getch();
	closegraph();
}