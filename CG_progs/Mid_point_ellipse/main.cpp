#include <graphics.h> 
#include<iostream>
#include<dos.h>
#include<math.h>
using namespace std; 


void make_ellipse(int rx, int ry, int xc, int yc){
	
	int x = 0, y = ry;
	
	// region1
	
	float p0 = (ry*ry) - (rx*rx*ry) + (rx*rx*0.25);
	
	while(2*ry*ry*x < 2*rx*rx*y){
		
		putpixel(xc+x, yc+y, 3);
		putpixel(xc-x, yc+y, 3);
		putpixel(xc+x, yc-y, 3);
		putpixel(xc-x, yc-y, 3);
		delay(10);
		
		if(p0<0){
			x++;
			p0 = p0 + (ry*ry)*(2*x + 1);
		}
		else{
			x++;
			y--;
			p0 = p0 + (ry*ry)*(2*x + 1) - (rx*rx)*(2*y);
		}
	}
	
	// region 2
	
	float p1 = (ry*ry)*(x+0.5)*(x+0.5) + (rx*rx)*(y-1)*(y-1) - (rx*rx*ry*ry);
	
	while(y>=0){
		
		putpixel(xc+x, yc+y, 3);
		putpixel(xc-x, yc+y, 3);
		putpixel(xc+x, yc-y, 3);
		putpixel(xc-x, yc-y, 3);
		delay(10);
		
		if(p1>0){
			y--;
			p1 = p1 - (rx*rx)*(2*y - 1);
		}
		else{
			y--; 
			x++;
			p1 = p1 - (rx*rx)*(2*y - 1) + (ry*ry)*(2*x);
		}
	}
}


main() 
{ 
	int gd=DETECT, gm;
	
	initgraph(&gd, &gm, "");
	
	make_ellipse(100, 150, 500, 500); 
	
	getch();
	closegraph();

} 


