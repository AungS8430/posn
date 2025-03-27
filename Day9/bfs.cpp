#include <bits/stdc++.h>
using namespace std;

int main(void) {
  map<int, map<int, int>> adj = {
      {1, {{2, 6}, {3, 5}, {4, 5}}},
      {2, {{5, -1}}},
      {3, {{2, -2}, {5, 1}}},
      {4, {{3, -2}, {6, -1}}},
      {5, {{7, 3}}},
      {6, {{7, 3}}},
      {7, {}}
  };
  queue<int> q;
  set<int> visited;
  q.push(1);
  while (!q.empty()) {
    int x = q.front(); q.pop();
    if (binary_search(visited.begin(), visited.end(), x)) continue;
    cout << x << " ";
    visited.insert(x);
    for (pair<int, int> node : adj[x]) q.push(node.first);
  }
  return 0;
}