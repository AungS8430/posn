#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>> &adj, vector<int> &v, stack<int> &s, int x) {
  v[x] = 1;
  for (int y : adj[x]) {
    if (v[y] == 0) dfs(adj, v, s, y);
    else if (v[y] == 1) {
      cout << "IMPOSSIBLE";
      exit(0);
    }
  }
  s.push(x);
  v[x] = 2;
  return true;
}

vector<int> toposort(vector<vector<int>> &adj) {
  stack<int> s;
  vector<int> v(adj.size(), 0);
  vector<int> res;
  for (int i = 0; i < adj.size(); i++) {
    if (v[i] == 0) dfs(adj, v, s, i);
    else if (v[i] == 1) {
      cout << "IMPOSSIBLE";
      exit(0);
    }
  }
  while (!s.empty()) {
    res.push_back(s.top());
    s.pop();
  }
  return res;
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

  for (int x : sorted) cout << x + 1 << " ";
  return 0;
}