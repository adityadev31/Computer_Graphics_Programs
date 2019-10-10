#include<graphics.h>
#include<iostream>
#include<dos.h>
#include<math.h>

using namespace std;


void lesser_m(int x0, int y0, int dx, int dy, int steps){
	int Po = (2*dy)-dx;
	for(int i=0; i<steps; i++){
		putpixel(x0, y0, 4);
		delay(50);
		
		if(Po<0){
			x0 += 1;
			Po = Po + (2*dy);
		}
		
		else{
			x0 += 1;
			y0 += 1;
			Po = Po + 2*(dy-dx);
		}
		
	}
	
}

void greater_m(int x0, int y0, int dx, int dy, int steps){
	
	int Po = (2*dx)-dy;
	for(int i=0; i<steps; i++){
		putpixel(x0, y0, 4);
		delay(50);
		
		if(Po<0){
			y0 += 1;
			Po = Po + (2*dx);
		}
		
		else{
			x0 += 1;
			y0 += 1;
			Po = Po + 2*(dx-dy);
		}
		
	}
	
	
}


int main(){
	
	int x0, y0, x1, y1, dx, dy, steps, gd=DETECT, gm;
	
	initgraph(&gd, &gm, "");
	
	cout<<"Enter (x0,y0), (x1,y1) \t";
	cin>>x0>>y0>>x1>>y1;
	
	dx = x1-x0;
	dy = y1-y0;
	steps = abs(dx)>=abs(dy) ? abs(dx):abs(dy);
	
	if((dy/dx) < 1)
		lesser_m(x0, y0, dx, dy, steps);
		
	else
		greater_m(x0, y0, dx, dy, steps);
	
	getch();
	closegraph();
	return 0;
}
