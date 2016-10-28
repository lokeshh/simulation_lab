#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;
double dist(double x1, double y1, double x2, double y2)
{
	return sqrt( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) );
}
int main()
{
	int gd = DETECT, gm;
	double pi=3.14, t=0.01;
	double v1=30,v2=27,v3=22,v4=18.5;
	double x1,y1,x2,x3,x4,y2,y3,y4;
	double r = 2;
	x1 = 40; y1 = 180;
	x2 = 80; y2 = 100;
	x3 = 160; y3 = 95;
	x4 = 200; y4 = 150;
	double th34,th23,th12;

	initgraph(&gd,&gm,NULL);
	
	circle(x1,y1,r);
	circle(x2,y2,r);
	circle(x3,y3,r);
	circle(x4,y4,r);
	outtextxy(x1,y1-20,"A");
	outtextxy(x2,y2-20,"B");
	outtextxy(x3,y3-20,"C");
	outtextxy(x4,y4-20,"D");
	getch();
	while(true)
	{
		
		double distance = dist(x3,y3,x4,y4);
		if(distance < 0.05)
		{
			printf("C has hit down target D\n");
			break;
		}
		distance = dist(x2,y2,x3,y3);
		if(distance < 0.05)
		{
			printf("B has hit down target C\n");
			break;
		}
		distance = dist(x1,y1,x2,y2);
		if(distance < 0.05)
		{
			printf("A has hit down target B\n");
			break;
		}
		th34 = atan( (y4-y3)/(x4-x3) );
		th23 = atan( (y3-y2)/(x3-x2) );
		th12 = atan( (y2-y1)/(x2-x1) );

		//cout<<th34<<" "<<th23<<" "<<th12<<endl;
		double theta = th34;
		y4+= v4*sin(theta)*t;
		x4+= v4*cos(theta)*t;
		
		theta = th34;
		y3+= v3*sin(theta)*t;
		x3+= v3*cos(theta)*t;
		
		theta = th23;
		y2+= v2*sin(theta)*t;
		x2+= v2*cos(theta)*t;
		
		theta = th12;
		y1+= v1*sin(theta)*t;
		x1+= v1*cos(theta)*t;

		if(y4 > 460  || y1>460 || y1<0) break;
		delay(5);
		cleardevice();
		circle(x1,y1,r);
		circle(x2,y2,r);
		circle(x3,y3,r);
		circle(x4,y4,r);
		outtextxy(x1,y1-20,"A");
		outtextxy(x2,y2-20,"B");
		outtextxy(x3,y3-20,"C");
		outtextxy(x4,y4-20,"D");
		//line(x1,y1,x2,y2);
		//line(x3,y3,x2,y2);
		//line(x3,y3,x4,y4);
	}

	getch();
	closegraph();
	return 0;
}