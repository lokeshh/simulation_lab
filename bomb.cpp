#include <iostream>
#include <graphics.h>
#include <math.h>

using namespace std;

void draw_circle(float x, float y);

int main(void)
{
  float Ratio = 0.01;
  int gd = DETECT, gm;
  float Left=100, Top=100, Right=600, Bottom=400;
  initgraph(&gd,&gm,NULL);
  float x = Left, y = Bottom;
  float vx = 150;
  float vy = 100;
  float t = 0;
  float v, angle;

  cout << "Enter velocity: " << endl;
  cin >> v;
  cout << "Enter angle: " << endl;
  cin >> angle;

  vx = v * cos(angle*3.14/180);
  vy = v * sin(angle*3.14/180);

  while (y <= Bottom)
  {
    if (!(((Left <= x) && (x <= Right)) &&
        ((Top <= y) && (y <= Bottom))
       ))
      return 0;
    t++;
    cleardevice();
    rectangle(Left, Top, Right, Bottom);    
    draw_circle(x, y);
    
    x += Ratio * vx;
    y -= Ratio * (vy  - 10 * t );

    delay(50);
  }

  delay(5000);
}

void draw_circle(float x, float y)
{
  setcolor(RED);  
  float Radius = 5;
  circle(x, y, Radius);
  floodfill(x, y, RED);
  setcolor(WHITE);
}
