#include <bits/stdc++.h>
using namespace std;

int w[] = {1, 3, 3, 5};
int sum = 12;
int n = 4;

int main(void) {
  int x;
  cin >> x;
  bool possible[n + 1];
  possible[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = sum; j >= 0; j--) {
      if (possible[j]) possible[x+w[i]] = true;
    }
  }
  cout << possible[x];
  return 0;
}
