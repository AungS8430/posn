#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int x[] = {4, 5, 7, 9, 2};
  int n = 5;
  int max = x[0];
  for (int i = 1; i < n; i++) {
    if (x[i] > max) max = x[i];
  }
  cout << max;
  return 0;
}
