#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n;
  cin >> n;
  vector<string> grid(n);
  vector<vector<long long>> dp(n, vector<long long>(n, 0));
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) cin >> grid[i];
  if (grid[0][0] == '*') {
    cout << 0;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) { 
      if (grid[i][j] == '*') continue;
      if (i > 0) dp[i][j] += (dp[i - 1][j]) % 1000000007;
      if (j > 0) dp[i][j] += (dp[i][j - 1]) % 1000000007;
      // cout << dp[i][j] << "\t";
    }
    // cout << endl;
  }
  cout << dp[n - 1][n - 1] % 1000000007;
  return 0;
}