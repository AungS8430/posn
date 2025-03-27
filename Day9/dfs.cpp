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
  stack<int> s;
  set<int> visited;
  s.push(1);
  while (!s.empty()) {
    int x = s.top(); s.pop();
    if (binary_search(visited.begin(), visited.end(), x)) continue;
    cout << x << " ";
    visited.insert(x);
    for (pair<int, int> node : adj[x]) s.push(node.first);
  }
  return 0;
}