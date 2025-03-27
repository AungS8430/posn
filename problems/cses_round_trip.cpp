#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false); cin.tie(0);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n);
  vector<bool> v(n);
  vector<int> p(n, -1);

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a - 1].push_back(b - 1);
    adj[b - 1].push_back(a - 1);
  }

  for (int i = 0; i < n; i++) {
    if (!v[i]) {
      stack<int> s;
      s.push(i);

      while (!s.empty()) {
        int x = s.top(); s.pop();
        if (v[x]) continue;
        v[x] = true;

        for (int y : adj[x]) {
          if (y == p[x]) continue;
          if (v[y]) {
            int start = y, curr = x;
            vector<int> cycle;
            while (curr != start) {
              cycle.push_back(curr);
              curr = p[curr];
            }
            cycle.push_back(start);
            reverse(cycle.begin(), cycle.end());
            cycle.push_back(start);
            cout << cycle.size() << endl;
            for (int c : cycle) cout << c + 1 << " ";
            return 0;
          } else {
            p[y] = x;
            s.push(y);
          }
        }
      }
    }
  }
  cout << "IMPOSSIBLE";
  return 0;
}