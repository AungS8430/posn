#include <bits/stdc++.h>
using namespace std;

map<int, vector<pair<int, int>>> adj = {
  {1, {{2, 4}, {3, 2}}},
  {2, {{4, 5}, {5, 3}}},
  {3, {{5, 6}, {6, 2}}},
  {4, {{7, 4}}},
  {5, {{7, 1}}},
  {6, {{8, 3}}},
  {7, {{8, 2}}},
  {8, {}}
};

void dfs(stack<int> &s, set<int> &v, int x) {
  if (!binary_search(v.begin(), v.end(), x)) {
    for (auto [dest, weight] : adj[x]) dfs(s, v, dest);
  }
  v.insert(x);
  s.push(x);
}

int main(void) {
  stack<int> s;
  set<int> v;
  vector<int> dst(9, INT_MAX);
  for (int i = 1; i < 9; i++) {
    if (!binary_search(v.begin(), v.end(), i)) dfs(s, v, i);
  }
  dst[1] = 0;
  while (!s.empty()) {
    int x = s.top(); s.pop();
    for (auto [node, weight] : adj[x]) {
      dst[node] = min(dst[node], dst[x] + (dst[x] == INT_MAX ? 0 : weight));
    }
  }

  for (int i = 1; i < 9; i++) cout << "Distance to " << i << " : " << dst[i] << endl;
  return 0;
}