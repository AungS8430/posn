#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n;
  cin >> n;
  int x[n];
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  int max_subarr_x[n * 2 - 1];
  max_subarr_x[0] = x[0];
  int max_subarr = INT_MIN, curr_start = 0, max_start = 0, max_end = 0;
  for (int i = 1; i < 2 * n - 1; i++) {
    if (max_subarr_x[i - 1] + x[i % n] < x[i % n] || curr_start % n == i % n) {
      max_subarr_x[i] = x[i % n];
      curr_start = i;
    } else {
      max_subarr_x[i] = max_subarr_x[i - 1] + x[i % n];
    }
    max_subarr = max(max_subarr, max_subarr_x[i]);
  }
  cout << max_subarr;
  return 0;
}