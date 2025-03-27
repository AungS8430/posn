#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(void) {
  int m, n, temp;
  cin >> m >> n;
  int grid[m][n], sum[m][n];
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> temp;
      grid[i][j] = temp;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i == 0 && j == 0) sum[i][j] = grid[i][j];
      else if (i == 0) sum[i][j] = sum[i][j - 1] + grid[i][j];
      else if (j == 0) sum[i][j] = sum[i - 1][j] + grid[i][j];
      else sum[i][j] = max(sum[i - 1][j], sum[i][j - 1]) + grid[i][j];
    }
  }
  cout << sum[m - 1][n - 1];
  return 0;
}
