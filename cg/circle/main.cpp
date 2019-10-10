#include<graphics.h>
#include<iostream>
#include<dos.h>
#include<math.h>

using namespace std;

int main(){
	
	int Xc, Yc, X, Y, r, i, Po, gd=DETECT, gm;
	
	initgraph(&gd, &gm, "");
	
	cout<<"Enter the radius \t";
	cin>>r;
	cout<<"Enter the center coordinates \t";
	cin>>Xc>>Yc;
	
	X = 0;
	Y = r;
	Po = 1-r;
	
	
	do{
		
		putpixel(Xc+X, Yc+Y, 4);
		putpixel(Xc+X, Yc-Y, 4);
		putpixel(Xc-X, Yc+Y, 4);
		putpixel(Xc-X, Yc-Y, 4);
		putpixel(Xc+Y, Yc+X, 4);
		putpixel(Xc+Y, Yc-X, 4);
		putpixel(Xc-Y, Yc+X, 4);
		putpixel(Xc-Y, Yc-X, 4);
		delay(50);
		
		if(Po<0){
			X += 1;
			Po = Po + (2*X) + 1;
		}
			
		else{
			X += 1;
			Y -= 1;
			Po = Po + 2*(X-Y) + 1;
		}
		
		
	}while(X<=Y);
	
	getch();
	closegraph();
	return 0;
}
