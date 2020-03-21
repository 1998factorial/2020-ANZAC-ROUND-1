#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

int dist2(int x1, int y1, int x2, int y2) {
  int dx = x1-x2;
  int dy = y1-y2;
  return dx*dx + dy*dy;
}

int main() {
  int x, y, x1, y1, x2, y2;
  cin >> x >> y >> x1 >> y1 >> x2 >> y2;
  int answer2 = 1000000000;
  if (x >= x1 && x <= x2) {
    // check against horizontal line
    answer2 = min(answer2, (y-y1)*(y-y1));
    answer2 = min(answer2, (y-y2)*(y-y2));
  }
  if (y >= y1 && y <= y2) {
    // check against vertical line
    answer2 = min(answer2, (x-x1)*(x-x1));
    answer2 = min(answer2, (x-x2)*(x-x2));
  }
  answer2 = min(answer2, dist2(x, y, x1, y1));
  answer2 = min(answer2, dist2(x, y, x1, y2));
  answer2 = min(answer2, dist2(x, y, x2, y1));
  answer2 = min(answer2, dist2(x, y, x2, y2));
  double answer = sqrt((double) answer2);
  printf("%.3lf\n", answer);
}
