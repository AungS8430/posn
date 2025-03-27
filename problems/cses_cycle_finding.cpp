// Time limit exceeded, must use SPFA.

#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main(void) {
  int n, m;
  cin >> n >> m;
  vector<vector<pair<ll, int>>> adj(n);
  vector<ll> dst(n, LLONG_MAX);
  vector<int> prt(n, -1);
  dst[0] = 0;
  for (int i = 0; i < m; i++) {
    int a, b; ll c;
    cin >> a >> b >> c;
    adj[a - 1].push_back({c, b - 1});
  }
 
  for (int start = 0; start < n; start++) {
    if (dst[start] != LLONG_MAX) continue;
    dst[start] = 0;
    int r;
    for (int k = 0; k < n - 1; k++) {
      r = -1;
      for (int x = 0; x < n; x++) {
        for (auto [w, y] : adj[x]) {
          if (dst[x] != LLONG_MAX && dst[x] + w < dst[y]) {
            dst[y] = dst[x] + w;
            prt[y] = x;
            r = y;
          }
        }
      }
    }
  
    if (r != -1) {
      cout << "YES\n";
      for (int i = 0; i < n; i++) r = prt[r];
  
      vector<int> cycle;
      set<int> visited;
      int v = r;
      while (visited.find(v) == visited.end()) {
        visited.insert(v);
        cycle.push_back(v);
        v = prt[v];
      }
      auto it = find(cycle.begin(), cycle.end(), v);
      cycle = vector<int>(it, cycle.end());
      cycle.push_back(v);

  
      for (int c : cycle) cout << c + 1 << " ";
      return 0;
    }
  }
  cout << "NO";
  return 0;
}