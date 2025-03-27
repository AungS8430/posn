#include <bits/stdc++.h>
using namespace std;

int main(void) {
  map<int, vector<int>> adj = {{1, {2, 4}}, {2, {3, 5}}, {3, {2, 6}}, {4, {1}}, {5, {2, 6}}, {6, {3, 5}}};
  queue<int> q;
  set<int> visited;
  q.push(1);
  while (!q.empty()) {
    int x = q.front(); q.pop();
    if (!binary_search(visited.begin(), visited.end(), x)) {
      cout << x << " ";
      visited.insert(x);
      for (int y : adj[x]) q.push(y);
    }
  }
  return 0;
}