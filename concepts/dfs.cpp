#include <bits/stdc++.h>
using namespace std;

int main(void) {
  map<int, vector<int>> adj = {{1, {2, 4}}, {2, {1, 3, 5}}, {3, {2, 5}}, {4, {1}}, {5, {2, 3}}};
  stack<int> s;
  set<int> visited;
  s.push(1);
  while (!s.empty()) {
    int x = s.top(); s.pop();
    if (binary_search(visited.begin(), visited.end(), x)) continue;
    else {
      cout << x << " ";
      visited.insert(x);
      for (int y : adj[x]) s.push(y);
    }
  }
  return 0;
}
