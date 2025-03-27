#include <bits/stdc++.h>
using namespace std;

int main(void) {
  map<int, vector<pair<int, int>>> adj = {{1, {{2, 5}, {3, 3}, {4, 7}}}, {2, {{1, 5}, {4, 3}, {5, 2}}}, {3, {{1, 3}, {4, 1}}}, {4, {{1, 7}, {2, 3}, {3, 1}, {5, 2}}}, {5, {{2, 2}, {4, 2}}}};
  map<int, int> dst = {{1, 0}, {2, INT_MAX}, {3, INT_MAX}, {4, INT_MAX}, {5, INT_MAX}};
  queue<int> q;
  set<int> visited;
  q.push(1);
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
  cout << dst[5];
}