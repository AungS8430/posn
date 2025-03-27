#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  for (int y = 1234; y <= 98765 / N; y++) {
    int x = y * N;
    int tmp, used = (y < 10000);
    tmp = x; while(tmp) {
      used |= 1<<(tmp % 10);
      tmp /= 10;
    }
    tmp = y; while(tmp) {
      used |= 1<<(tmp % 10);
      tmp /= 10;
    }
    if (used == (1<<10) - 1) printf("%05d / %05d - %d\n", x, y, N);
  }
  return 0;
}