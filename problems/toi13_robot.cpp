#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false); cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<string> grid(n);
  vector<vector<int>> dst(n, vector<int>(m, INT_MAX));
  queue<pair<int, int>> q;
  vector<vector<bool>> v(n, vector<bool>(m, false));
  for (int i = 0; i < n; i++) {
    cin >> grid[i];
    for (int j = 0; j < grid[i].length(); j++) {
      if (grid[i][j] == 'X') {
        q.push({i, j});
        dst[i][j] = 0;
        v[i][j] = true;
      }
    }
  };

  int l = 0, c = 0;

  while (!q.empty()) {
    auto [row, col] = q.front(); q.pop();
    if (row > 0) {
      if (grid[row - 1][col] != 'W' && !v[row - 1][col]) {
        dst[row - 1][col] = dst[row][col] + 1;
        v[row - 1][col] = true;
        q.push({row - 1, col});
      }
    }
    if (row < n - 1) {
      if (grid[row + 1][col] != 'W' && !v[row + 1][col]) {
        dst[row + 1][col] = dst[row][col] + 1;
        v[row + 1][col] = true;
        q.push({row + 1, col});
      }
    }
    if (col > 0) {
      if (grid[row][col - 1] != 'W' && !v[row][col - 1]) {
        dst[row][col - 1] = dst[row][col] + 1;
        v[row][col - 1] = true;
        q.push({row, col - 1});
      }
    }
    if (col < m - 1) {
      if (grid[row][col + 1] != 'W' && !v[row][col + 1]) {
        dst[row][col + 1] = dst[row][col] + 1;
        v[row][col + 1] = true;
        q.push({row, col + 1});
      }
    }

    if (grid[row][col] == 'A') {
      l += dst[row][col] * 2;
      c++;
    }
  }

  cout << c << " " << l;
  return 0;
}