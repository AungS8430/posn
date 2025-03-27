#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int cnt(int n) {
  if (n == 0) return 1;
  else return pow(2, n) + cnt(n - 1);
}

int main(void) {
  int n;
  cin >> n;
  cout << cnt(n - 1);
  return 0;
}
