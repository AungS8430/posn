#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int m, o, b_max = 0, sum = 0;
  cin >> m >> o;
  vector<int> u(o, 0);
  for (int i = 0; i < o; i++) {
    cin >> u[i];
    sum += u[i];
    b_max = max(b_max, u[i]);
  }
  int left = b_max, right = sum;
  while (left < right) {
    int mid = (left + right) / 2;
    int n = 0, curr = 0;
    for (int i = 0; i < o; i++) {
      if (curr + u[i] > mid) {
        curr = 0;
        n++;
      }
      curr += u[i];
    }
    if (n < m) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  cout << left;
  return 0;
}