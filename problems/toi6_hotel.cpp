#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n, t = 0;
  cin >> n;
  vector<int> dp(n + 16, INT_MAX);
  dp[0] = 0;
  for (int i = 1; i <= n + 15; i++) {
    dp[i] = min(dp[i], dp[i - 1] + 500);
    if (i >= 2) dp[i] = min(dp[i], dp[i - 2] + 800);
    if (i >= 5) dp[i] = min(dp[i], dp[i - 5] + 1500);
    if (i >= 15) dp[i] = min(dp[i], dp[i - 15] + 3000);
  }
  int min_cost = INT_MAX;
  for (int i = n; i <= n + 15; i++) {
    min_cost = min(min_cost, dp[i]);
  }
  cout << min_cost;
  return 0;
}