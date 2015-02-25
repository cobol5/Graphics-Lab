#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<math.h>

float bez(int n,int i){
	float total;
	total=fact(n)/(fact(i));
	total=total/fact(n-i);
	return(total);
}

int fact(int n){
	int i=n,factorial=1;
	if(i==0)
	return(1);
	do{
		factorial=factorial*i;
		i--;
	}while(i>=1);
	return(factorial);
}

void main(){
	int gm, n, no, i, gdriver=DETECT ,gmode, errorcode;
	float cpx, cpy, xu=0, yu=0, u;
	static float xk[10], yk[10];
	initgraph(&gdriver, &gmode, "C:\\TurboC3\\BGI\\");
	printf("\n\n\t\tEnter the number of control points: ");
	scanf("%d",&no);
	n=no-1;
	for(i=0;i<=n;i++){
		printf("\t\tEnter the value of x%d and y%d: ",i+1, i+1);
		scanf("%f%f",&xk[i],&yk[i]);
		putpixel(xk[i],yk[i],RED);
		}
	cleardevice();
	setcolor(RED);
	cpx=xk[0];
	cpy=yk[0];
	for(i=0;i<n;i++)
		line(xk[i],yk[i],xk[i+1],yk[i+1]);
	for(u=0;u<=1;u=u+0.05){
		xu=0;
		yu=0;
		for(i=n;i>=0;i--){
			if(i!=0){
				xu=xu+xk[i]*bez(n,i)*pow(u,i)*pow((1-u),(n-i));
			}
			else{
				xu=xu+xk[i]*bez(n,i)*pow((1-u),(n-i));
			}
		}
		for(i=n;i>=0;i--){
			if(i!=0){
				yu=yu+yk[i]*bez(n,i)*pow(u,i)*pow((1-u),(n-i));
			}
			else{
				yu=yu+yk[i]*bez(n,i)*pow((1-u),(n-i));
			}
		}
		setcolor(15);
		//setlinestyle(0,0,2);
		line(cpx,cpy,xu,yu);
		delay(30);
		cpx=xu;
		cpy=yu;
	}
	getch();
	closegraph();
}


