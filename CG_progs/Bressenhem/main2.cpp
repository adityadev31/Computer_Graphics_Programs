#include<iostream>
#include<graphics.h>
#include<dos.h>
#include<math.h>
using namespace std;


void lesser_m(int x0, int y0, int x1, int y1, int dx, int dy){
	
	int p0 = 2*dy - dx;
	
	while(x0!=x1 && y0!=y1){
		
		putpixel(x0, y0, WHITE);
		cout<<"("<<x0<<","<<y0<<") \n";
		
		if(p0<0){
			x0++;
			p0 = p0 + 2*dy;
		}
		else{
			x0++;
			y0++;
			p0 = p0 + 2*(dy-dx);
		}
	}
	putpixel(x0, y0, WHITE);
	cout<<"("<<x0<<","<<y0<<") \n";
}



void greater_m(int x0, int y0, int x1, int y1, int dx, int dy){
	
	int p0 = 2*dx - dy;
	
	while(x0!=x1 && y0!=y1){
		
		putpixel(x0, y0, WHITE);
		cout<<"("<<x0<<","<<y0<<") \n";
		
		if(p0<0){
			y0++;
			p0 = p0 + 2*dx;
		}
		else{
			x0++;
			y0++;
			p0 = p0 + 2*(dx-dy);
		}
	}
	putpixel(x0, y0, WHITE);
	cout<<"("<<x0<<","<<y0<<") \n";
}



main(){
	
	int x0=2, y0=4, x1=10, y1=7, dx, dy, gd=DETECT, gm;
	
	dx = x1-x0;
	dy = y1-y0;
	float m = float(dy)/float(dx);
	
	initgraph(&gd, &gm, "");
	
	(m<1) ? lesser_m(x0, y0, x1, y1, dx, dy) : greater_m(x0, y0, x1, y1, dx, dy);
	
	getch();
	closegraph();
}
