#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  vector<int> g(n, 0);
  vector<bool> v(n, false);
  
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a - 1].push_back(b - 1);
    adj[b - 1].push_back(a - 1);
  }

  for (int start = 0; start < n; start++) {
    if (!v[start]) {
      stack<int> s;
      s.push(start);
      g[start] = 1;

      while (!s.empty()) {
        int x = s.top(); s.pop();
        for (int y : adj[x]) {
          if (v[y]) {
            if (g[x] == g[y]) {
              cout << "IMPOSSIBLE";
              return 0;
            }
          } else {
            g[y] = 3 - g[x];
            s.push(y);
          }
        }
        v[x] = true;
      }
    }
  }

  for (int i = 0; i < n; i++) cout << g[i] << " ";
  return 0;
}