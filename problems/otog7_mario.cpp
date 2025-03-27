#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> grid(n, vector<int> (m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
      if (i > 0) {
        int prev_min = grid[i - 1][j];
        if (j > 0) prev_min = min(prev_min, grid[i - 1][j - 1]);
        if (j < m - 1) prev_min = min(prev_min, grid[i - 1][j + 1]);
        grid[i][j] += prev_min;
      }
    }
  }
  cout << *min_element(grid[n - 1].begin(), grid[n - 1].end());
  return 0;
}