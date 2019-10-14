#include<graphics.h>
#include<iostream>
#include<dos.h>
#include<math.h>
using namespace std;

main(){
	
	float x0=200, y0=300, x1=450, y1=600;
	int gd = DETECT, gm;
	
	initgraph(&gd, &gm, "");
	
	float dx=x1-x0;
	float dy=y1-y0;
	float steps = abs(dx)>abs(dy) ? abs(dx):abs(dy);
	
	dx /= steps;
	dy /= steps;
	
	while(x0!=x1 && y0!=y1){
		putpixel(int(x0+0.5), int(y0+0.5), WHITE);
		cout<<"("<<int(x0+0.5)<<","<<int(y0+0.5)<<") \n";
		delay(10);
		
		x0 += dx;
		y0 += dy;
	}
	putpixel(int(x0+0.5), int(y0+0.5), WHITE);
	cout<<"("<<int(x0+0.5)<<","<<int(y0+0.5)<<") \n";
	
	getch();
	closegraph();
}
