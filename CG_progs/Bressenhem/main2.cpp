#include<graphics.h>
#include<iostream>
#include<dos.h>
#include<math.h>

using namespace std;


void lesser_m(int x0, int y0, int x1, int y1, int dx, int dy){
	
	int p0 = (2*dy)-dx;
	
	while(x0!=x1 && y0!=y1){
		
		putpixel(x0, y0, RED);
		delay(10);
		
		if(p0<1){
			x0 += 1;
			p0 = p0 + (2*dy);
		}
		else{
			x0 += 1;
			y0 += 1;
			p0 = p0 + 2*(dy-dx);
		}
	}
	putpixel(x0, y0, RED);
	
}


void greater_m(int x0, int y0, int x1, int y1, int dx, int dy){
	
	int p0 = (2*dx)-dy;
	
	while(x0!=x1 && y0!=y1){
		
		putpixel(x0, y0, RED);
		delay(10);
		
		if(p0<1){
			y0 += 1;
			p0 = p0 + (2*dx);
		}
		else{
			x0 += 1;
			y0 += 1;
			p0 = p0 + 2*(dx-dy);
		}
	}
	putpixel(x0, y0, RED);
	
}




main(){
	
	int x0=200, y0=300, x1=1000, y1=800, dx, dy;
	int gd = DETECT, gm;
	
	initgraph(&gd, &gm, "");
	
	dx = x1-x0;
	dy = y1-y0;
	
	float m = float(dy)/float(dx);
	
	(m<1)?(lesser_m(x0, y0, x1, y1, dx, dy)):(greater_m(x0, y0, x1, y1, dx, dy));
		
	getch();
	closegraph();
	
}
