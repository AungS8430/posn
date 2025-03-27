#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n;
  cin >> n;
  long start[n], end[n], range[2] = {LONG_MAX, LONG_MIN}, total = 0, med_pos;
  for (int i = 0; i < n; i++) {
    cin >> start[i] >> end[i];
    range[0] = min(range[0], start[i]);
    range[1] = max(range[1], end[i]);
    total += end[i] - start[i];
  }
  med_pos = total / 2;
  while (range[0] < range[1]) {
    long mid = range[0] + (range[1] - range[0]) / 2;
    long pos = 0;
    for (int i = 0; i < n; i++) {
      if (start[i] <= mid) {
        pos += min(mid, end[i] - 1) - start[i] + 1;
      }
    }
    if (pos < med_pos) range[0] = mid + 1;
    else range[1] = mid;
  }
  cout << range[0] << endl;
  return 0;
}
