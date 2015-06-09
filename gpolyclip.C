#include<stdio.h>
#include<graphics.h>
#define TOP 0x01;
#define BOTTOM 0x02;
#define RIGHT 0x04;
#define LEFT 0x08;
int calcode(float x,float y,float xwmin,float ywmin,float xwmax,float ywmax)
{
 int code=0;
 if(y>ywmax) code|=TOP;
 if(y<ywmin) code|=BOTTOM;
 if(x>xwmax) code|=RIGHT;
 if(x<xwmin) code|=LEFT;
 return(code);
}
void lineclip(float x0,float y0,float x1,float y1,float xwmin,float ywmin,float xwmax,float ywmax)
{
 unsigned int code0,code1,codeout;
 int accept=0,done=0;
 float x,y;
 code0=calcode(x0,y0,xwmin,ywmin,xwmax,ywmax);
 code1=calcode(x1,y1,xwmin,ywmin,xwmax,ywmax);
 do{
    if(!(code0|code1))
     { accept=1; done=1; }
    else {if(code0&code1) {done=1;}
    else {
          if(code0) codeout=code0;
               else codeout=code1;
          if(codeout&0x01)
           {
            x=x0+(x1-x0)*(ywmax-y0)/(y1-y0);
            y=ywmax;
           }
          else {if(codeout&0x02)
                {
                  x=x0+(x1-x0)*(ywmin-y0)/(y1-y0);
                  y=ywmin;
                }
                else {if(codeout&0x04)
                      {
                       y=y0+(y1-y0)*(xwmax-x0)/(x1-x0);
                       x=xwmax;
                      }
                      else {
                             y=y0+(y1-y0)*(xwmin-x0)/(x1-x0);
                             x=xwmin;
                           }}}
          if(codeout==code0)
           {
            x0=x;
            y0=y;
            code0=calcode(x0,y0,xwmin,ywmin,xwmax,ywmax);
           }
          else
           {
            x1=x;
            y1=y;
            code1=calcode(x1,y1,xwmin,ywmin,xwmax,ywmax);
           }
         }}
   }while(done==0);
 if(accept) line(x0,y0,x1,y1);
rectangle(xwmin,ywmin,xwmax,ywmax);
}
void main()
{
 float xwmin,ywmin,xwmax,ywmax;
 float *x,*y;
 int n,i;
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
 printf("\nEnter no. of vertices:");
 scanf("%d",&n);
 x=(float *)malloc(n*sizeof(float));
 y=(float *)malloc(n*sizeof(float));
 for(i=0;i<n;i++)
 {
  printf("\nVertex %d:",i+1);
  scanf("%f %f",&x[i],&y[i]);
 }
 printf("\nEnter window's top left corner:");
 scanf("%f %f",&xwmin,&ywmin);
 printf("\nEnter window's bottom right corner:");
 scanf("%f %f",&xwmax,&ywmax);
 cleardevice();
 for(i=0;i<n;i++)
 {
  line(x[i],y[i],x[(i+1)%n],y[(i+1)%n]);
 }
 rectangle(xwmin,ywmin,xwmax,ywmax);
 getch();
 cleardevice();
 rectangle(xwmin,ywmin,xwmax,ywmax);
 for(i=0;i<n;i++)
 {
  lineclip(x[i],y[i],x[(i+1)%n],y[(i+1)%n],xwmin,ywmin,xwmax,ywmax);
 }
 getch();
}
