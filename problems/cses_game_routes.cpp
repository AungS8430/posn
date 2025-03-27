#include <bits/stdc++.h>
#define ll long long
#define mod ((ll)(1e9+7))
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
  s.push(x);
  v[x] = 2;
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
  vector<int> res;
  while (!s.empty()) {
    res.push_back(s.top());
    s.pop();
  }
  return res;
}

int main(void) {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n), r_adj(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a - 1].push_back(b - 1);
    r_adj[b - 1].push_back(a - 1);
  }
  vector<int> sorted = toposort(adj);
  vector<ll> dp(n, 0);
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    for (int x : r_adj[sorted[i]]) {
      dp[sorted[i]] = (dp[sorted[i]] + dp[x]) % mod;
    }
  }
  cout << dp[n - 1];
  return 0;
}