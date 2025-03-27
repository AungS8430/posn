#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &adj, vector<int> &v, stack<int> &s, int x) {
  v[x] = 1;
  for (int y : adj[x]) {
    if (v[y] == 0) dfs(adj, v, s, y);
    else if (v[y] == 1) {
      cout << "IMPOSSIBLE";
      exit(0);
    }
  }
  v[x] = 2;
  s.push(x);
}

vector<int> toposort(vector<vector<int>> &adj) {
  vector<int> v(adj.size(), 0);
  stack<int> s;
  for (int i = 0; i < adj.size(); i++) {
    if (v[i] == 0) dfs(adj, v, s, i);
    else if (v[i] == 1) {
      cout << "IMPOSSIBLE";
      exit(0);
    }
  }
  vector<int> ans;
  while (!s.empty()) {
    ans.push_back(s.top());
    s.pop();
  }
  return ans;
}

int main(void) {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a - 1].push_back(b - 1);
  }
  vector<int> sorted = toposort(adj);
  vector<int> dst(n, INT_MIN);
  vector<int> parent(n, -1); // To track the path
  dst[0] = 1;

  for (int x : sorted) {
    for (int y : adj[x]) {
      if (dst[x] != INT_MIN && dst[x] + 1 > dst[y]) {
        dst[y] = dst[x] + 1;
        parent[y] = x;
      }
    }
  }

  if (dst[n - 1] == INT_MIN) {
    cout << "IMPOSSIBLE";
    return 0;
  }

  cout << dst[n - 1] << endl;

  vector<int> path;
  for (int cur = n - 1; cur != -1; cur = parent[cur]) {
    path.push_back(cur + 1);
  }
  reverse(path.begin(), path.end());

  for (int node : path) {
    cout << node << " ";
  }

  return 0;
}