#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>

int n, orig[20], newp[20], c1=1, c2=1, ch;
int sx,sy,xt,yt,r;
int oc = 15, nc = 5;

void draw(int original){
	cleardevice();
	if(original == 1){
		setcolor(oc);
		drawpoly(n, orig);
	}
	else{
		setcolor(nc);
		drawpoly(n, newp);
		setcolor(oc);
		drawpoly(n, orig);
		getch();
	}
	setcolor(oc);
}

void matrixmul(int r){
	float t = 3.14*r/180, mat2[2][2];
	int mat1[20][2], i, j, k, resmat[20][2];
	mat2[0][0] = cos(t);
	mat2[0][1] = -1*sin(t);
	mat2[1][0] = sin(t);
	mat2[1][1] = cos(t);
	for(i=0; i<n-1; i++){
		mat1[i][0] = orig[2*i];
		mat1[i][1] = orig[2*i+1];
	}
	for(i=0; i<n-1; i++){
		for(j=0; j<2; j++){
			resmat[i][j] = 0;
			for(k=0; k<2; k++){
				resmat[i][j] += (int)mat1[i][k]*mat2[k][j];
			}
			//resmat[i][j] = abs(resmat[i][j]);
		}
	}
	for(i=0; i<n-1; i++){
		newp[2*i] = resmat[i][0];
		newp[2*i+1] = resmat[i][1];
	}
	newp[2*(n-1)] = newp[0];
	newp[2*(n-1) + 1] = newp[1];

}

void main(){
	int gd=DETECT, gm, i;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	printf("\n\n\t\tEnter the number of sides: ");
	scanf("%d", &n);
	printf("\n\n\t\tEnter coordinates: \n");
	for(i=0; i<n; i++){
		scanf("%d %d", &orig[2*i], &orig[2*i+1]);
	}
	orig[2*n] = orig[0];
	orig[2*n+1] = orig[1];
	n++;
	while(c1!=5){
		clrscr();cleardevice();
		draw(1);
		outtextxy(0,0,"First Transformation");
		outtextxy(0,10,"1. Translation");
		outtextxy(0,20,"2. Rotation");
		outtextxy(0,30,"3. Scaling");
		outtextxy(0,40,"4. Reflection");
		outtextxy(0,50,"5. Exit");
		outtextxy(0,70,"Enter your choice: ");
		scanf("%d", &c1);
		if(c1==5)break;
		switch(c1){
			case 1:
				outtextxy(0, 10, "Enter the translation factor ");
				scanf("%d %d", &xt, &yt);
				for(i=0;i<n;i++){
					newp[2*i] = orig[2*i] + xt;
					newp[2*i+1] = orig[2*i+1] + yt;
				}
				//draw(2);
				break;
			case 2:
				outtextxy(0, 10, "Enter the angle of rotation: ");
				scanf("%d", &r);
				matrixmul(r);
				//draw(2);
				break;

			case 3:
				outtextxy(0, 10, "Enter the scaling factor: ");
				scanf("%d %d", &sx, &sy);
				for(i=0;i<n;i++){
					newp[2*i] = orig[2*i] * sx;
					newp[2*i+1] = orig[2*i+1] * sy;
				}
				//draw(2);
				break;

			case 4:
				outtextxy(0, 10, "1.X axis and 2.Y axis : ");
				scanf("%d", &ch);
				switch(ch){
					case 1:
						for(i=0;i<n;i++){
							newp[2*i] = orig[2*i];
							newp[2*i+1] = getmaxy() - orig[2*i+1];
						}
						break;

					case 2:
						for(i=0;i<n;i++){
							newp[2*i] = getmaxx() - orig[2*i];
							newp[2*i+1] = orig[2*i+1];
						}
						break;
					}
					//draw(2);
					break;
				case 5:
					break;
				default:
					printf("Enter the correct choice");
			}
		for(i=0;i<(2*n)+1;i++){
			orig[i] = newp[i];
		}
		outtextxy(0,100,"Second Transformation");
		outtextxy(0,110,"1. Translation");
		outtextxy(0,120,"2. Rotation");
		outtextxy(0,130,"3. Scaling");
		outtextxy(0,140,"4. Reflection");
		outtextxy(0,150,"5. Exit");
		outtextxy(0,170,"Enter your choice: ");
		scanf("%d", &c2);
		switch(c2){
			case 1:
				outtextxy(0, 50, "Enter the translation factor ");
				scanf("%d %d", &xt, &yt);
				for(i=0;i<n;i++){
					newp[2*i] = orig[2*i] + xt;
					newp[2*i+1] = orig[2*i+1] + yt;
				}
				//draw(2);
				break;
			case 2:
				outtextxy(0, 50, "Enter the angle of rotation: ");
				scanf("%d", &r);
				matrixmul(r);
				//draw(2);
				break;

			case 3:
				outtextxy(0, 50, "Enter the scaling factor: ");
				scanf("%d %d", &sx, &sy);
				for(i=0;i<n;i++){
					newp[2*i] = orig[2*i] * sx;
					newp[2*i+1] = orig[2*i+1] * sy;
				}
				//draw(2);
				break;

			case 4:
				outtextxy(0, 50, "1.X axis and 2.Y axis : ");
				scanf("%d", &ch);
				switch(ch){
					case 1:
						for(i=0;i<n;i++){
							newp[2*i] = orig[2*i];
							newp[2*i+1] = getmaxy() - orig[2*i+1];
						}
						break;

					case 2:
						for(i=0;i<n;i++){
							newp[2*i] = getmaxx() - orig[2*i];
							newp[2*i+1] = orig[2*i+1];
						}
						break;
					}
					//draw(2);
					break;
				case 5:
					break;
				default:
					printf("Enter the correct choice");
			}
		for(i=0;i<(2*n)+1;i++){
			orig[i] = newp[i];
		}
		draw(2);
		}
		closegraph();
	}
