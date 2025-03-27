#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define qiii queue<tuple<int, int, int>>
using namespace std;

int main(void) {
  int m, n;
  cin >> m >> n;
  vvc grid(m, vc(n));
  vvb visited(m, vb(n, false));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) cin >> grid[i][j];
  }

  qiii q;
  q.push({0, 0, 1}); // Start from (0, 0) with time 1

  while (!q.empty()) {
    auto [row, col, time] = q.front();
    q.pop();

    if (visited[row][col]) {
      cout << time << endl << row + 1 << " " << col + 1 << endl;
      return 0;
    }

    visited[row][col] = true;

    // Move Right
    if ((grid[row][col] == 'B' || grid[row][col] == 'R') && col < n - 1 && !visited[row][col + 1]) {
      q.push({row, col + 1, time + 1});
    }

    // Move Down
    if ((grid[row][col] == 'B' || grid[row][col] == 'D') && row < m - 1 && !visited[row + 1][col]) {
      q.push({row + 1, col, time + 1});
    }

    // Move Left
    if (col > 0 && !visited[row][col - 1] && (grid[row][col - 1] == 'B' || grid[row][col - 1] == 'R')) {
      q.push({row, col - 1, time + 1});
    }

    // Move Up
    if (row > 0 && !visited[row - 1][col] && (grid[row - 1][col] == 'B' || grid[row - 1][col] == 'D')) {
      q.push({row - 1, col, time + 1});
    }
  }

  return 0;
}