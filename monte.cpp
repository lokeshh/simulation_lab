// Monte Carlo Simulation
// Integration
// Life of Pie
// Dice Roll

#include <iostream>
#include <graphics.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

float RandomFloat(float a, float b) {
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}

float fx2(float x)
{
  return x * x;
}

int main(void)
{
  cout << "y = f(x^2)" << endl;
  float n = 100000000;
  float x1 = 0, x2 = 3, y1 = 0, y2 = 10, x, y;
  int count = 0;
  for (int i = 0; i < n; i++)
  {
    x = RandomFloat(x1, x2);
    y = RandomFloat(y1, y2);
    (y <= fx2(x)) ? count++ : x++ ;    
  }
  cout << "Area under curve from 0 to 3 = ";
  cout << count / n * (y2-y1) * (x2-x1) << endl;
}
