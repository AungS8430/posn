#include <bits/stdc++.h>
using namespace std;
int falling(vector<vector<char>> &grid, int x, int y, int pos_y) {
  bool matched = false;
  if (y == -1) return pos_y;
  if (y == pos_y) matched = true;
  if (grid[y][x] != '-' && grid[y][x] != '#') {
    while (y + 1 < grid.size() && grid[y + 1][x] == '-') {
      grid[y + 1][x] = grid[y][x];
      grid[y][x] = '-';
      y++;
      if (matched) pos_y++;
    }
  }
  pos_y = falling(grid, x, y - 1, pos_y);
  return pos_y;
}
int check(vector<vector<char>> &grid, int x, int y, int m, int n) {
  int i = 0;
  if (grid[y][x] != '#' && grid[y][x] != '-') {
    if (x > 0) if (grid[y][x] == grid[y][x - 1]) {
      grid[y][x - 1] = '-';
      falling(grid, x - 1, m - 2, 0);
      i++;
    }
    if (x < n - 1) if (grid[y][x] == grid[y][x+1]) {
      grid[y][x + 1] = '-';
      falling(grid, x + 1, m - 2, 0);
      i++;
    }
    if (y > 0) if (grid[y][x] == grid[y - 1][x]) {
      grid[y - 1][x] = '-';
      falling(grid, x, m - 2, 0);
      i++;
    }
    if (y < m - 1) if (grid[y][x] == grid[y + 1][x]) {
      grid[y + 1][x] = '-';
      y = falling(grid, x, m - 2, y);
      i++;
    }
  }
  if (i > 0) {
    grid[y][x] = '-';
    i++;
  }
  falling(grid, x, m - 2, 0);
  return i;
}
int main(void) {
  int m, n, k, score = 0;
  cin >> m >> n;
  vector<vector<char>> grid(m, vector<char> (n));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j];
    }
  }
  cin >> k;
  pair<pair<int, int>, char> cmd;
  for (int i = 0; i < k; i++) {
    cin >> cmd.first.first >> cmd.first.second >> cmd.second;
    if (grid[cmd.first.first][cmd.first.second] == '-' || grid[cmd.first.first][cmd.first.second] == '#') score--;
    else {
      switch (cmd.second) {
        case 'L':
          if (cmd.first.second > 0) {
            if (grid[cmd.first.first][cmd.first.second - 1] == '-') {
              grid[cmd.first.first][cmd.first.second - 1] = grid[cmd.first.first][cmd.first.second];
              grid[cmd.first.first][cmd.first.second] = '-';
              falling(grid, cmd.first.second, m - 2, 0);
              int k = falling(grid, cmd.first.second - 1, m - 2, cmd.first.first);
              score += check(grid, cmd.first.second - 1, k, m, n);
            } else score--;
          } else score--;
          break;
        case 'R':
          if (cmd.first.second < n - 1) {
            if (grid[cmd.first.first][cmd.first.second + 1] == '-') {
              grid[cmd.first.first][cmd.first.second + 1] = grid[cmd.first.first][cmd.first.second];
              grid[cmd.first.first][cmd.first.second] = '-';
              falling(grid, cmd.first.second, m - 2, 0);
              int k = falling(grid, cmd.first.second + 1, m - 2, cmd.first.first);
              score += check(grid, cmd.first.second + 1, k, m, n);
            } else score--;
          } else score--;
          break;
      }
    }
  }
  cout << score * 5 << endl;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cout << grid[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}