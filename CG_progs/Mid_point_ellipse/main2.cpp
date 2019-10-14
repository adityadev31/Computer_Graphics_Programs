#include<iostream>
#include<graphics.h>
#include<dos.h>
#include<math.h>
using namespace std;

void mid_pt_ellipse(int xc, int yc, int rx, int ry, int x0, int y0){
	
	// region 1
	float p0 = (ry*ry) + (rx*rx*0.25) - (rx*rx*ry);
	
	while((2*ry*ry*x0)<(2*rx*rx*y0)){
		
		putpixel(xc+x0, yc+y0, WHITE);
		putpixel(xc-x0, yc+y0, WHITE);
		putpixel(xc+x0, yc-y0, WHITE);
		putpixel(xc-x0, yc-y0, WHITE);
		cout<<"("<<x0<<","<<y0<<") \n";
		
		if(p0<0){
			x0++;
			p0 = p0 + (ry*ry)*(2*x0 + 1);
		}
		else{
			x0++;
			y0--;
			p0 = p0 + (ry*ry)*(2*x0 + 1) - (rx*rx)*(2*y0);
		}
	}
	
	// region 2
	
	float p1 = (ry*ry)*(x0+0.5)*(x0+0.5) + (rx*rx)*(y0-1)*(y0-1) - (rx*rx*ry*ry);
	
	while(y0>=0){
		
		putpixel(xc+x0, yc+y0, WHITE);
		putpixel(xc-x0, yc+y0, WHITE);
		putpixel(xc+x0, yc-y0, WHITE);
		putpixel(xc-x0, yc-y0, WHITE);
		cout<<"("<<x0<<","<<y0<<") \n";
		
		if(p1>0){
			y0--;
			p1 = p1 - (rx*rx)*(2*y0 - 1);
		}
		else{
			x0++;
			y0--;
			p1 = p1 - (rx*rx)*(2*y0 - 1) + (ry*ry)*(2*x0);
		}
	}
}


main(){
	
	int xc=0, yc=0, rx=8, ry=6, x0, y0, gd=DETECT, gm;
	x0=0;
	y0=ry;
	
	initgraph(&gd, &gm, "");
	mid_pt_ellipse(xc, yc, rx, ry, x0, y0);
	getch();
	closegraph();
}

