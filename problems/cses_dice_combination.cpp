#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n;
  cin >> n;
  vector<long long> dp(n + 1);
  dp = {0, 1, 2, 4, 8, 16, 32};
  for (int i = 7; i <= n; i++) {
    dp[i] = (dp[i - 6] + dp[i - 5] + dp[i - 4] + dp[i - 3] + dp[i - 2] + dp[i - 1]) % 1000000007;
  }
  cout << dp[n];
  return 0;
}