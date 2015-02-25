#include<math.h>
#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#define ROUND(a) ((int)(a+0.5))

void bspline(float *arx,float *ary,float n){
 	float pux, puy, u=0.0;
 	char ch[20];
 	int j, k;

	for(j=0;j<n;j++) {
		putpixel(arx[j],ary[j],15);
		sprintf(ch, "%d :(%d,%d)",j+1,(int) arx[j],(int) ary[j]);
		outtextxy(arx[j]+5, ary[j]+10, ch);
		if(j!=n-1){
			setlinestyle(DOTTED_LINE, 1, 1);
			line((int)arx[j], (int)ary[j], (int)arx[j+1], (int)ary[j+1]);
			setlinestyle(SOLID_LINE, 1, 1);
		}
	}

	for(k=0;k<=n-3;k++){
		while(u<=1){
			pux=arx[k]*((1/6.0)*(1-u)*(1-u)*(1-u)) +
				arx[k+1]*((1/6.0)*(3*u*u*u-6*u*u+4)) +
				arx[k+2]*((1/6.0)*(-3*u*u*u+3*u*u+3*u+1)) +
				arx[k+3]*((1/6.0)*(u*u*u));

			puy=ary[k]*((1/6.0)*(1-u)*(1-u)*(1-u)) +
				ary[k+1]*((1/6.0)*(3*u*u*u-6*u*u+4)) +
				ary[k+2]*((1/6.0)*(-3*u*u*u+3*u*u+3*u+1)) +
				ary[k+3]*((1/6.0)*(u*u*u));

			putpixel(ROUND(pux),ROUND(puy),4);
			u=u+0.01;
			}
		u=0;
	}

}


void main(){
	int i, n, c=1, x, gd=DETECT, gm;
	float arrx[100], arry[100];
	textcolor(LIGHTGRAY);
	clrscr();
	initgraph(&gd,&gm,"C:\\TurboC3\\bgi");

	printf("Enter the number of control points: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)  {
		printf("Enter the coordinates of point %d: ", i+1);
		scanf("%f%f", &arrx[i], &arry[i]);
	  }

	clrscr();
	cleardevice();
	bspline(arrx,arry,n);
	
	getch();
	do{
		bspline(arrx,arry,n);
		printf("Do you wanna modify? (0/1): ");
		scanf("%d", &c);
		if(c==1){
			printf("Enter CP number: ");
			scanf("%d", &x);
			printf("Enter the coordinates of %d point: ",x);
			scanf("%f%f", &arrx[x-1], &arry[x-1]);
			bspline(arrx, arry, n);
			getch();
			clrscr();
			cleardevice();
		}
	}while(c!=0);
	closegraph();
}
