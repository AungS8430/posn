#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n, x;
  cin >> n >> x;
  vector<int> v(n);
  vector<int> w(n);
  for (int i = 0; i < n; i++) cin >> v[i] >> w[i];
  vector<int> dp(x + 1, INT_MIN);
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = x; j >= 0; j--) {
      if (w[i] <= j) dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    }
  }
  cout << dp[x];
  return 0;
}