#include <bits/stdc++.h>
using namespace std;
 
int main(void) {
  int n, m, sr, sc;
  cin >> n >> m;
  vector<vector<int>> grid(n, vector<int>(m, INT_MAX));
  vector<vector<int>> player(n, vector<int>(m, INT_MAX));
  vector<vector<bool>> visited(n, vector<bool>(m, false));
  queue<pair<int, int>> q;
  for (int i = 0; i < n; i++) {
    string tmp;
    cin >> tmp;
    for (int j = 0; j < m; j++) {
      if (tmp[j] == 'A') {
        sr = i;
        sc = j;
      }
      if (tmp[j] == '#') grid[i][j] = INT_MIN;
      else if (tmp[j] == '.' || tmp[j] == 'A') grid[i][j] = -1;
      else {
        grid[i][j] = 0;
        q.push({i, j});
      }
    }
  }
 
  // Add monster movement by time
  while (!q.empty()) {
    auto [row, col] = q.front(); q.pop();
    if (visited[row][col]) continue;
    int current_time = grid[row][col];
    if (row > 0 && grid[row - 1][col] == -1) {
      q.push({row - 1, col});
      grid[row - 1][col] = current_time + 1;
    }
    if (row < n - 1 && grid[row + 1][col] == -1) {
      q.push({row + 1, col});
      grid[row + 1][col] = current_time + 1;
    }
    if (col > 0 && grid[row][col - 1] == -1) {
      q.push({row, col - 1});
      grid[row][col - 1] = current_time + 1;
    }
    if (col < m - 1 && grid[row][col + 1] == -1) {
      q.push({row, col + 1});
      grid[row][col + 1] = current_time + 1;
    }
    visited[row][col] = true;
  }
 
  vector<vector<bool>> walked(n, vector<bool>(m, false));
  player[sr][sc] = 0;
 
  q.push({sr, sc});
  while (!q.empty()) {
    auto [row, col] = q.front(); q.pop();
    if (walked[row][col]) continue;
    int current_time = player[row][col];
    if ((row == 0 || row == n - 1) || (col == 0 || col == m - 1)) {
      cout << "YES" << endl << current_time << endl;
      string path;
      pair<int, int> current = {row, col};
      while (current != make_pair(sr, sc)) {
        if (current.first > 0 && player[current.first - 1][current.second] == current_time - 1) {
          current = {current.first - 1, current.second};
          path.push_back('D');
        } else if (current.first < n - 1 && player[current.first + 1][current.second] == current_time - 1) {
          current = {current.first + 1, current.second};
          path.push_back('U');
        } else if (current.second > 0 && player[current.first][current.second - 1] == current_time - 1) {
          current = {current.first, current.second - 1};
          path.push_back('R');
        } else if (current.second < m - 1 && player[current.first][current.second + 1] == current_time - 1) {
          current = {current.first, current.second + 1};
          path.push_back('L');
        }
        current_time--;
      }
      reverse(path.begin(), path.end());
      for (char c : path) cout << c;
      return 0;
    }
    if (row > 0 && (current_time + 1 < grid[row - 1][col] || grid[row - 1][col] == -1) && !walked[row - 1][col]) {
      player[row - 1][col] = current_time + 1;
      q.push({row - 1, col});
    }
    if (row < n - 1 && (current_time + 1 < grid[row + 1][col] || grid[row + 1][col] == -1) && !walked[row + 1][col]) {
      player[row + 1][col] = current_time + 1;
      q.push({row + 1, col});
    }
    if (col > 0 && (current_time + 1 < grid[row][col - 1] || grid[row][col - 1] == -1) && !walked[row][col - 1]) {
      player[row][col - 1] = current_time + 1;
      q.push({row, col - 1});
    }
    if (col < m - 1 && (current_time + 1 < grid[row][col + 1] || grid[row][col + 1] == -1) && !walked[row][col + 1]) {
      player[row][col + 1] = current_time + 1;
      q.push({row, col + 1});
    }
 
    walked[row][col] = true;
    // for (int i = 0; i < n; i++) {
    //   for (int j = 0; j < m; j++) {
    //     cout << player[i][j] << "\t";
    //   }
    //   cout << endl;
    // }
  }
  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < m; j++) {
  //     cout << player[i][j] << "\t";
  //   }
  //   cout << endl;
  // }
  cout << "NO";
  return 0;
}