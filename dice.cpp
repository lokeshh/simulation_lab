#include <iostream>
#include <graphics.h>
#include <string>
using namespace std;
int main(void) {
  cout << "Enter n: ";
  int n; cin >> n;
  int counts[] = {0, 0, 0, 0, 0, 0};
  for (int i = 0; i < n; i++)
    counts[random()%6]++;

  int gd = DETECT, gm, x = 30;
  initgraph(&gd, &gm, NULL);
  float Left = 100, Top = 100, Right = 500, Bottom = 400;
  line(Left, Bottom, Right, Bottom);
  line(Left, Bottom, Left, Top);
  setcolor(BLUE);
  for (int i = 0; i < 6; i++) {
    rectangle(Left+(1+2*i)*x, Bottom,
      Left+(2+2*i)*x, Bottom-counts[i]);
    char* s = (char*)to_string(i+1).c_str();
    outtextxy(Left+(1.5+2*i)*x, Bottom + 10, s);
  }
  delay(5000);
}
