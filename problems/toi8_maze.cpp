#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;
int main(void) {
  int m, n, rs, cs, re, ce;
  cin >> m >> n;
  vector<vector<int>> grid(m, vector<int> (n, INT_MAX));
  queue<pair<int, int>> q;
  set<pair<int, int>> k;
  cin >> rs >> cs;
  cin >> re >> ce;
  rs--; cs--; re--; ce--;
  q.push({rs, cs});
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j];
    }
  }
  int s = 1;
  while (!q.empty()) {
    int row = q.front().first;
    int col = q.front().second;
    q.pop();
    if ((row == rs && col == cs) || (row == re && col == ce)) {
      grid[row][col] = 1;
      grid[row][col] = grid[row][col] * s;
      k.insert({row, col});
      if (row > 0) q.push({row - 1, col});
      if (row < m - 1) q.push({row + 1, col});
      if (col > 0) q.push({row, col - 1});
      if (col < n - 1) q.push({row, col + 1});
    }
    else if (grid[row][col] == 0);
    else if (k.find({row, col}) == k.end()) {
      if (k.find({row, col}) != k.end());
      int top = (row > 0 && k.find({row - 1, col}) != k.end()) ? abs(grid[row - 1][col]) : INT_MAX;
      int bottom = (row < m - 1 && k.find({row + 1, col}) != k.end()) ? abs(grid[row + 1][col]) : INT_MAX;
      int left = (col > 0 && k.find({row, col - 1}) != k.end()) ? abs(grid[row][col - 1]) : INT_MAX;
      int right = (col < n - 1 && k.find({row, col + 1}) != k.end()) ? abs(grid[row][col + 1]) : INT_MAX;
      if (top == 0) top = INT_MAX;
      if (bottom == 0) bottom = INT_MAX;
      if (left == 0) left = INT_MAX;
      if (right == 0) right = INT_MAX;
      if (row > 0) {
        q.push({row - 1, col});
      }
      if (row < m - 1) {
        q.push({row + 1, col});
      }
      if (col > 0) {
        q.push({row, col - 1});
      }
      if (col < n - 1) {
        q.push({row, col + 1});
      }
      grid[row][col] = min(min(top, bottom), min(left, right)) + 1;
      grid[row][col] = grid[row][col] * s;
      k.insert({row, col});
    } 
    if (q.empty() && s == 1) {
      s = -1;
      q.push({re, ce});
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++){
      if (grid[i][j] == 1 && (!(i == rs && j == cs) && !(i == re && j == ce))) {
        grid[i][j] = 0;
      }
    }
  }
  int paths = 0;
  int min_steps = INT_MAX;
  for (int row = 0; row < m; row++) {
    for (int col = 0; col < n; col++) {
      if (grid[row][col] == 0) {
        int s = 0;
        int e = 0;
        if (row > 0) {
          if (grid[row - 1][col] > 0) s++;
          else if (grid[row - 1][col] < 0) e++;
        }
        if (row < m - 1) {
          if (grid[row + 1][col] > 0) s++;
          else if (grid[row + 1][col] < 0) e++;
        }
        if (col > 0) {
          if (grid[row][col - 1] > 0) s++;
          else if (grid[row][col - 1] < 0) e++;
        }
        if (col < n - 1) {
          if (grid[row][col + 1] > 0) s++;
          else if (grid[row][col + 1] < 0) e++;
        }
        if (s > 0 && e > 0) {
          paths++;
          if (row > 0 && row < m - 1) if (grid[row - 1][col] != 0 && grid[row + 1][col] != 0 && grid[row - 1][col] != grid[row + 1][col] && (grid[row + 1][col] > 0 != grid[row - 1][col] > 0)) min_steps = min(min_steps, abs(grid[row - 1][col]) + abs(grid[row + 1][col]) + 1);
          if (col > 0 && col < n - 1) if (grid[row][col - 1] != 0 && grid[row][col + 1] != 0 && grid[row][col - 1] != grid[row][col + 1] && (grid[row][col + 1] > 0 != grid[row][col - 1] > 0)) min_steps = min(min_steps, abs(grid[row][col - 1]) + abs(grid[row][col + 1]) + 1);
          if (row > 0 && col < n - 1) if (grid[row - 1][col] != 0 && grid[row][col + 1] != 0 && grid[row - 1][col] != grid[row][col + 1] && (grid[row - 1][col] > 0 != grid[row][col + 1] > 0)) min_steps = min(min_steps, abs(grid[row - 1][col]) + abs(grid[row][col + 1]) + 1);
          if (col > 0 && row < m - 1) if (grid[row + 1][col] != 0 && grid[row][col - 1] != 0 && grid[row + 1][col] != grid[row][col - 1] && (grid[row + 1][col] > 0 != grid[row][col - 1] > 0)) min_steps = min(min_steps, abs(grid[row + 1][col]) + abs(grid[row][col - 1]) + 1);
          if (row > 0 && col > 0) if (grid[row - 1][col] != 0 && grid[row][col - 1] != 0 && grid[row - 1][col] != grid[row][col - 1] && (grid[row - 1][col] > 0 != grid[row][col - 1] > 0)) min_steps = min(min_steps, abs(grid[row - 1][col]) + abs(grid[row][col - 1]) + 1);
          if (row < m - 1 && col < n - 1) if (grid[row + 1][col] != 0 && grid[row][col + 1] != 0 && grid[row + 1][col] != grid[row][col + 1] && (grid[row + 1][col] > 0 != grid[row][col + 1] > 0)) min_steps = min(min_steps, abs(grid[row + 1][col]) + abs(grid[row][col + 1]) + 1);
        }
      }
    }
  }
  cout << paths << endl << min_steps;
  return 0;
}
