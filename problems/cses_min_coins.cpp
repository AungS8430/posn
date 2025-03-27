#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n, x;
  cin >> n >> x;
  vector<long long> coins(n);
  vector<long long> res(x + 1, LLONG_MAX);
  for (int i = 0; i < n; i++) cin >> coins[i];
  res[0] = 0;
  for (int i = 0; i <= x; i++) {
    for (int c : coins) {
      if (i >= c) res[i] = min(res[i], (res[i - c] == LLONG_MAX ? LLONG_MAX : res[i - c] + 1));
    }
  }
  cout << (res[x] == LLONG_MAX ? -1 : res[x]);
  return 0;
}