#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(void) {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<ll>> adj(n, vector<ll>(n, LLONG_MAX));
  vector<pair<int, int>> query;
  vector<vector<ll>> dst(n, vector<ll>(n, LLONG_MAX));
  for (int i = 0; i < n; i++) {
    adj[i][i] = 0; // Initialize self-loops to 0
  }
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a - 1][b - 1] = adj[b - 1][a - 1] = min(adj[a - 1][b - 1], (ll)c); // Handle multiple edges
  }
  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    query.push_back({a - 1, b - 1});
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) {
        dst[i][j] = adj[i][j] = 0;
      } else dst[i][j] = adj[i][j];
    }
  }

  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (dst[i][k] != LLONG_MAX && dst[k][j] != LLONG_MAX) {
          dst[i][j] = min(dst[i][j], dst[i][k] + dst[k][j]);
        }
      }
    }
  }

  for (auto [a, b] : query) {
    if (dst[a][b] == LLONG_MAX) cout << "-1 ";
    else cout << dst[a][b] << " ";
  }
  return 0;
}