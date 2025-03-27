#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(void) {
  int n, start = INT_MAX, end = 0;
  cin >> n;
  int x[n][3];
  vector<pair<int, int>> skyline;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> x[i][j];
    }
    if (x[i][0] < start) start = x[i][0];
    if (x[i][2] > end) end = x[i][2];
  }
  int max, prev;
  for (int i = start; i <= end; i++) {
    max = 0;
    for (int j = 0; j < n; j++) {
      if (x[j][0] <= i && x[j][2] > i) {
        if (x[j][1] > max) max = x[j][1];
      }
    }
    if (max != prev) {
      cout << i << " " << max << " ";
      prev = max;
    }
  }
  return 0;
}
