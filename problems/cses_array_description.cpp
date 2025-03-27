#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

int main(void) {
  int n, m;
  cin >> n >> m;
  vector<int> num(n);
  vector<vector<long long>> dp(n, vector<long long>(m));
  for (int i = 0; i < n; i++) {
    cin >> num[i];
    num[i]--;
  }
  if (num[0] == -1) {
    for (int i = 0; i < m; i++) dp[0][i] = 1;
  } else {
    dp[0][num[0]] = 1;
  }
  for (int i = 1; i < n; i++) {
    if (num[i] == -1) {
      for (int j = 0; j < m; j++) {
        if (j > 0) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
        dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
        if (j < m - 1) dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % mod;
      }
    } else {
      int j = num[i];
      if (j > 0) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
      dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
      if (j < m - 1) dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % mod;
    }
  }
  // for (auto a:dp) {
  //   for (auto b:a) cout << b <<  " ";
  //   cout << endl;
  // }
  int ans = 0;
  for (int i = 0; i < m; i++) ans = (ans + dp[n - 1][i]) % mod;
  cout << ans;
  return 0;
}