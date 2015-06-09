#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>

void main()
{
int x,y,i,c=0,gd = DETECT,gm;
detectgraph(&gd,&gm);
initgraph(&gd,&gm,"..\\bgi");
setfillstyle(1,6);
int poly[]={300,200,450,200,450,300,300,300};
fillpoly(4,poly);
setfillstyle(1,15);
line(300,230,450,230);
line(300,260,450,260);
line(300,290,450,290);

line(360,200,360,300);
line(410,200,410,300);

setfillstyle(1,6);
int poly1[]={100,100,120,100,120,300,100,300};
fillpoly(4,poly1);
int poly2[]={120,100,375,100,375,106,120,106};
fillpoly(4,poly2);

line(375,106,375,150);

setfillstyle(1,15);
fillellipse(200,160,15,15);
line(200,175,200,250);

line(200,250,190,260);
line(200,250,210,260);
line(200,190,225,175);

line(225,175,375,150);

for(i=0;i<25;i++)
{


	setfillstyle(1,LIGHTGRAY);
	fillellipse(375,160,10,10);
	setcolor(15);
	circle(375,160,10);

	setfillstyle(1,0);
	fillellipse(375,160,2,2);

	setcolor(15);
	line(385,160,385,200);


       if(i%2)
       {
	setcolor(0);
	line(375,150,375,160);
	line(367,167,375,160);
	line(383,167,375,160);
	c=1;
	}
       else
       {
	       /*	setcolor(LIGHTGRAY);
		line(375,150,375,160);
		line(367,167,375,160);
		line(383,167,375,160);
		 */
		setcolor(0);
		line(370,153,375,160);
		line(385,154,375,160);
		line(375,170,375,160);
		c=0;
	}

	delay(200);
       }



getch();
}