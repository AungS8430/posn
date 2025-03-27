#include <bits/stdc++.h>
using namespace std;

void dfs(vector<string> &grid, int i, int j, int n, int m) {
  stack<pair<int, int>> s;
  s.push({i, j});
  while (!s.empty()) {
    auto [a, b] = s.top(); s.pop();
    grid[a][b] = '#';
    if (a > 0) if (grid[a - 1][b] == '.') s.push({a - 1, b});
    if (a < n - 1) if (grid[a + 1][b] == '.') s.push({a + 1, b});
    if (b > 0) if (grid[a][b - 1] == '.') s.push({a, b - 1});
    if (b < m - 1) if (grid[a][b + 1] == '.') s.push({a, b + 1});
  }
}

int main(void) {
  int n, m;
  cin >> n >> m;
  vector<string> grid(n);
  int rooms = 0;
  for (int i = 0; i < n; i++) cin >> grid[i];
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == '.') {
        dfs(grid, i, j, n, m);
        rooms++;
      }
    }
  }
  cout << rooms;
  return 0;
}