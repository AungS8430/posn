#include <bits/stdc++.h>
using namespace std;

typedef struct COORD {
  int x, y;
  bool operator<(const COORD &c) {
    if (c.x == x) return y < c.y;
    else return x > c.x;
  }
} coord;

int main(void) {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n;
  cin >> n;
  vector<coord> bombs(n);
  for (int i = 0; i < n; i++) cin >> bombs[i].x >> bombs[i].y;
  sort(bombs.begin(), bombs.end());
  int mx = 0;
  for (int i = 0; i < n; i++) {
    if (bombs[i].y >= mx) {
      mx = bombs[i].y;
      cout << bombs[i].x << " " << bombs[i].y << endl;
    }
  }
  return 0;
}