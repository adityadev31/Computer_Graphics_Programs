#include<graphics.h>
#include<iostream>
#include<dos.h>
#include<math.h>

using namespace std;

int main(){
	
	float x0,y0,x1,y1,dx,dy,steps;
	int gd=DETECT, gm;
	
	initgraph(&gd, &gm, "");
	
	cout<<"Enter (x0,y0) , (x1,y1) \t";
	cin>>x0>>y0>>x1>>y1;
	
	dx = x1-x0;
	dy = y1-y0;
	
	steps = abs(dx)>=abs(dy) ? abs(dx):abs(dy);
	
	dx = dx/steps;
	dy = dy/steps;
	
	for(int i=0; i<=steps; i++){
		putpixel(int(x0+0.5), int(y0+0.5), 4);
		delay(50);
		x0 += dx;
		y0 += dy;
	}
	
	getch();
	closegraph();
	return 0;
}
