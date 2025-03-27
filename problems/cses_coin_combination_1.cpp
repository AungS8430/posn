#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n, x;
  cin >> n >> x;
  vector<long long> coins(n);
  vector<long long> res(x + 1, 0);
  res[0] = 1;
  for (int i = 0; i < n; i++) cin >> coins[i];
  for (int i = 0; i <= x; i++) {
    for (int c : coins) {
      if (i >= c) res[i] = (res[i] + res[i - c]) % 1000000007;
    }
  }
  cout << res[x] % 1000000007;
  return 0;
}