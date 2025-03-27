#include <bits/stdc++.h>
using namespace std;

int main(void) {
  vector<vector<pair<int, int>>> adj = {
      {{4, 1}},
      {{3, 3}, {4, 6}},
      {{0, 6}, {1, 2}, {3, 7}},
      {{4, 5}},
      {}
  };
  queue<int> q;
  set<int> visited;
  vector<int> dst(5, INT_MAX);
  dst[2] = 0;
  q.push(2);
  while (!q.empty()) {
    int x = q.front(); q.pop();
    for (pair<int, int> n_node : adj[x]) {
      if (!binary_search(visited.begin(), visited.end(), n_node.first)) {
        dst[n_node.first] = min(dst[n_node.first], dst[x] + n_node.second);
        q.push(n_node.first);
      }
    }
    visited.insert(x);
  }
  for (int i = 0; i < 5; i++) cout << i << " : " << dst[i] << endl;
  return 0;
}