#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n, m, sr, sc, er, ec;
  cin >> n >> m;
  vector<string> grid(n);
  vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
  vector<vector<bool>> visited(n, vector<bool>(m, false));
  vector<vector<char>> step(n, vector<char>(m));
  for (int i = 0; i < n; i++) {
    cin >> grid[i];
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 'A') {
        sr = i;
        sc = j;
      } else if (grid[i][j] == 'B') {
        er = i;
        ec = j;
      }
    }
  }

  queue<pair<int, int>> q;
  q.push({sr, sc});
  dp[sr][sc] = 0;
  while (!q.empty()) {
    auto [r, c] = q.front(); q.pop();
    if (visited[r][c]) continue;
    if (r > 0 && grid[r - 1][c] != '#') {
      dp[r - 1][c] = min(dp[r - 1][c], dp[r][c] + (dp[r][c] == INT_MAX ? 0 : 1));
      if (dp[r - 1][c] == dp[r][c] + 1) step[r - 1][c] = 'U';
      q.push({r - 1, c});
    }
    if (r < n - 1 && grid[r + 1][c] != '#') {
      dp[r + 1][c] = min(dp[r + 1][c], dp[r][c] + (dp[r][c] == INT_MAX ? 0 : 1));
      if (dp[r + 1][c] == dp[r][c] + 1) step[r + 1][c] = 'D';
      q.push({r + 1, c});
    }
    if (c > 0 && grid[r][c - 1] != '#') {
      dp[r][c - 1] = min(dp[r][c - 1], dp[r][c] + (dp[r][c] == INT_MAX ? 0 : 1));
      if (dp[r][c - 1] == dp[r][c] + 1) step[r][c - 1] = 'L';
      q.push({r, c - 1});
    }
    if (c < m - 1 && grid[r][c + 1] != '#') {
      dp[r][c + 1] = min(dp[r][c + 1], dp[r][c] + (dp[r][c] == INT_MAX ? 0 : 1));
      if (dp[r][c + 1] == dp[r][c] + 1) step[r][c + 1] = 'R';
      q.push({r, c + 1});
    }
    visited[r][c] = true;
  }
  if (dp[er][ec] == INT_MAX) {
    cout << "NO";
  } else {
    cout << "YES" << endl << dp[er][ec];
    vector<char> path;
    int r = er, c = ec;
    while (r != sr || c != sc) {
      path.push_back(step[r][c]);
      if (step[r][c] == 'U') r++;
      else if (step[r][c] == 'D') r--;
      else if (step[r][c] == 'L') c++;
      else if (step[r][c] == 'R') c--;
    }
    reverse(path.begin(), path.end());
    cout << endl;
    for (char dir : path) {
      cout << dir;
    }
  }
  return 0;
}