#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n, m;
  cin >> n >> m;
  int grid[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
    }
  }
  vector<vector<int>> dp(n, vector<int> (m));
  for (int i = n - 1; i >= 0; i--) {
    for (int j = m - 1; j >= 0; j--) {
      if (i == m - 1 && j == n - 1) dp[i][j] = max(1, 1 - grid[i][j]);
      else if (i == n - 1) dp[i][j] = max(1, dp[i][j + 1] - grid[i][j]);
      else if (j == m - 1) dp[i][j] = max(1, dp[i + 1][j] - grid[i][j]);
      else dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - grid[i][j]);
    }
  }
  cout << dp[0][0];
  return 0;
}