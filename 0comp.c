#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>

int n, orig[20][3], newp[20][3], trm[3][20][3], c[3], ch;
int tx[3], ty[3], r[3], tp[3], sx[3], sy[3];
int oc = 15, nc = 5;

void draw(){
	int poly[30], i, j=0, k;
	for(i=0;i<n;i++){
		for(k=0;k<3;k++){
			poly[j] = newp[i][k];
			++j;
		}
	}
	cleardevice();
	drawpoly(n, poly);
	getch();
}

void display(int x[20][3]){
	int i,j;
	for(i=0;i<n;i++){
		printf("\n");
		for(j=0;j<3;j++){
			printf("%d ", x[i][j]);
		}
	}
	printf("\n\n");
}

void setmatrix(){
	int i;
	float t;
	for(i=0; i<3; i++){
		if(tp[i] == 0){ //translation
			trm[i][0][0] = 1;
			trm[i][0][1] = 0;
			trm[i][0][2] = 0;
			trm[i][1][0] = 0;
			trm[i][1][1] = 1;
			trm[i][1][2] = 0;
			trm[i][2][0] = tx[i];
			trm[i][2][1] = ty[i];
			trm[i][2][2] = 0;
		}
		else if(tp[i] == 1){ //scaling
			trm[i][0][0] = sx[i];
			trm[i][0][1] = 0;
			trm[i][0][2] = 0;
			trm[i][1][0] = 0;
			trm[i][1][1] = sy[i];
			trm[i][1][2] = 0;
			trm[i][2][0] = 0;
			trm[i][2][1] = 0;
			trm[i][2][2] = 0;
		}
		else if(tp[i] == 2){ //rotation
			t = 3.14*r[i]/180;

			trm[i][0][0] = cos(t);
			trm[i][0][1] = -1*sin(t);
			trm[i][0][2] = 0;
			trm[i][1][0] = sin(t);
			trm[i][1][1] = cos(t);
			trm[i][1][2] = 0;
			trm[i][2][0] = 0;
			trm[i][2][1] = 0;
			trm[i][2][2] = 0;
		}
		else if(tp[i] == 3){ //reflection abt x
			trm[i][0][0] = -1;
			trm[i][0][1] = 0;
			trm[i][0][2] = 0;
			trm[i][1][0] = 0;
			trm[i][1][1] = 1;
			trm[i][1][2] = 0;
			trm[i][2][0] = 0;
			trm[i][2][1] = 0;
			trm[i][2][2] = 0;
		}
		else if(tp[i] == 4){ //reflection abt y
			trm[i][0][0] = 1;
			trm[i][0][1] = 0;
			trm[i][0][2] = 0;
			trm[i][1][0] = 0;
			trm[i][1][1] = -1;
			trm[i][1][2] = 0;
			trm[i][2][0] = 0;
			trm[i][2][1] = 0;
			trm[i][2][2] = 0;
		}
	}
}
void matrixmul(){
	int i, j, k, resmat[20][2], temp[20][3];
	clrscr();
	cleardevice();
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			resmat[i][j] = 0;
			for(k=0; k<3; k++){
				printf("%d*%d+%d (%d,%d,%d)", orig[i][k], trm[0][k][j],resmat[i][j], i,j,k);
				resmat[i][j] += orig[i][k]*trm[0][k][j];
			}
			printf(" = %d\n", resmat[i][j]);
			getch();
		}
	}
	display(orig);
	display(resmat);
	for(i=0; i<n-1; i++){
		for(j=0; j<3; j++){
			temp[i][j] = 0;
			for(k=0; k<3; k++){
				temp[i][j] += (int)resmat[i][k]*trm[1][k][j];
			}
		}
	}
       //	display(temp);
	for(i=0; i<n-1; i++){
		for(j=0; j<3; j++){
			resmat[i][j] = 0;
			for(k=0; k<3; k++){
				resmat[i][j] += (int)temp[i][k]*trm[2][k][j];
			}
		}
	}
       //	display(resmat);
	for(i=0; i<n-1; i++){
		for(j=0; j<3; j++){
		newp[i][j] = resmat[i][j];
		}
	}
}

void main(){
	int gd=DETECT, gm, i, turn;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	printf("\n\n\t\tEnter the number of sides: ");
	scanf("%d", &n);
	printf("\n\n\t\tEnter coordinates: \n");
	for(i=0; i<n; i++){
		scanf("%d %d", &orig[i][0], &orig[i][1]);
		orig[i][2] = 1;
		newp[i][0] = orig[i][0];
		newp[i][1] = orig[i][1];
		newp[i][2] = orig[i][2];
	}
	while(1){
		clrscr();
		cleardevice();
		draw();
		printf("Enter the order of transformations: ");
		printf("\n0. Translation\n1. Scaling\n2. Rotation\n3. Ref abt x\n4. Ref abt y\n\nOrder: ");
		scanf("%d%d%d", &tp[0],&tp[1],&tp[2]);
		if(tp[0] > 4) break;
		for(i=0;i<3;i++){
			switch(tp[i]){
				case 0:
					printf("Enter the translation factor: ");
					scanf("%d %d", &tx[i], &ty[i]);
					break;
				case 2:
					printf("Enter the angle of rotation: ");
					scanf("%d", &r[i]);
					break;
				case 1:
					printf("Enter the scaling factor: ");
					scanf("%d %d", &sx[i], &sy[i]);
					break;
				case 3:
				case 4:
						break;
				default:
					printf("Enter the correct choice");
				}

			}
		setmatrix();
		matrixmul();
		getch();
		draw();
		closegraph();
		}
	}
