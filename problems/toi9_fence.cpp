#include <bits/stdc++.h>
using namespace std;

int mainop() {
  int m, n, t;
  cin >> m >> n >> t;
  vector<vector<bool>> grid(m, vector<bool>(n, true));
  vector<vector<pair<int, int>>> dp(m, vector<pair<int, int>>(n, {1, 1}));
  int mx = 0;
  for (int i = 0; i < t; i++) {
    int r, c;
    cin >> r >> c;
    grid[r][c] = false;
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (i == 0 && j == 0) {
        if (!grid[i][j]) dp[i][j] = {0, 0};
        else dp[i][j] = {1, 1};
        continue;
      }
      if (!grid[i][j]) {
        dp[i][j] = {0, 0};
        // cout << dp[i][j].first << " " << dp[i][j].second << " "<< 0 << "\t";
        continue;
      }
      
      if (i > 0) dp[i][j].first = dp[i - 1][j].first + 1;
      if (j > 0) dp[i][j].second = dp[i][j - 1].second + 1;

      int len = min(dp[i][j].first, dp[i][j].second);
      while (len >= 0) {
        if (len == 0) break;
        bool valid = true;
        if (dp[i - len + 1][j].second < len) valid = false;
        else if (dp[i][j - len + 1].first < len) valid = false;
        if (valid) break;
        else len--;
      }
      mx = max(mx, len);
      // cout << dp[i][j].first << " " << dp[i][j].second << " "<< len << "\t";
    }
    // cout << endl;
  }

  return mx;
}

int main(void) {
  int x[2];
  x[0] = mainop();
  x[1] = mainop();

  cout << x[0] << endl << x[1];
  return 0;
}