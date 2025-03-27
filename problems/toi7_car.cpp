#include <bits/stdc++.h>
using namespace std;

vector<int> dfs(vector<vector<int>> &road, int row, int col, int m, int t) {
  if (row == t) return {-1};
  vector<int> actions;
  vector<int> temp;
  //cout << "row: " << row << ", col: " << col << endl;
  if (col > 0 && road[row][col - 1] == 0) {
    temp = dfs(road, row + 1, col - 1, m, t);
    if (temp.size() != 0) {
      actions = temp;
      actions.insert(actions.begin(), 1);
    }
    temp.clear();
  }
  if (col < m - 1 && road[row][col + 1] == 0) {
    temp = dfs(road, row + 1, col + 1, m, t);
    if (temp.size() != 0) {
      actions = temp;
      actions.insert(actions.begin(), 2);
    }
    temp.clear();
  }
  if (road[row][col] == 0) {
    temp = dfs(road, row + 1, col, m, t);
    if (temp.size() != 0) {
      actions = temp;
      actions.insert(actions.begin(), 3);
    }
    temp.clear();
  }
  return actions;
}

int main(void) {
  ios::sync_with_stdio(false); cin.tie(0);
  int m, n, t, x;
  cin >> m >> n >> t;
  vector<vector<int>> road(t, vector<int> (m));
  for (int i = 0; i < t; i++) {
    for (int j = 0; j < m; j++) cin >> road[i][j];
  }
  vector<int> actions = dfs(road, 0, n - 1, m, t);
  actions.pop_back();
  for (int a : actions) cout << a << endl;
  return 0;
}