#include<graphics.h>
#include<iostream>
#include<dos.h>
#include<math.h>
using namespace std;

void mid_pt_circle(int xc, int yc, int r, int x0, int y0){
	
	int p0 = 1-r;
	
	while(x0<=y0){
		
		putpixel(xc+x0, yc+y0, WHITE);
		putpixel(xc-x0, yc+y0, WHITE);
		putpixel(xc+x0, yc-y0, WHITE);
		putpixel(xc-x0, yc-y0, WHITE);
		putpixel(xc+y0, yc+x0, WHITE);
		putpixel(xc-y0, yc+x0, WHITE);
		putpixel(xc+y0, yc-x0, WHITE);
		putpixel(xc-y0, yc-x0, WHITE);
		cout<<"("<<xc+x0<<","<<yc+y0<<") \n";
		
		if(p0<0){
			x0++;
			p0 = p0 + 2*x0 + 1;
		}
		else{
			x0++;
			y0--;
			p0 = p0 + 2*(x0-y0) + 1;
		}
		
	}
}


main(){
	
	int xc=0, yc=0, r=10, x0, y0, gd=DETECT, gm;
	x0 = 0;
	y0 = r;
	
	initgraph(&gd, &gm, "");
	mid_pt_circle(xc, yc, r, x0, y0);
	getch();
	closegraph()	;
}

