#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &adj, vector<bool> &v, int x) {
  stack<int> s;
  s.push(x);
  while (!s.empty()) {
    int y = s.top(); s.pop();
    if (v[y]) continue;
    for (int z : adj[y]) {
      s.push(z);
    }
    v[y] = true;
  }
}

int main(void) {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  vector<bool> v(n, false);
  vector<int> c;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a - 1].push_back(b - 1);
    adj[b - 1].push_back(a - 1);
  }
  for (int i = 0; i < n; i++) {
    if (!v[i]) {
      c.push_back(i);
      dfs(adj, v, i);
    }
  }
  cout << c.size() - 1 << endl;
  for (int i = 1; i < c.size(); i++) cout << c[i - 1] + 1 << " " << c[i] + 1 << endl;
}