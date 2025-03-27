#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  vector<bool> v(n, false);
  vector<int> p(n);
  queue<int> q;
  vector<int> d(n, INT_MAX);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a - 1].push_back(b - 1);
    adj[b - 1].push_back(a - 1);
  }

  q.push(0);
  d[0] = 1;
  while (!q.empty()) {
    int x = q.front(); q.pop();
    if (v[x]) continue;
    for (int y : adj[x]) {
      if (d[y] > d[x] + 1) {
        d[y] = d[x] + 1;
        p[y] = x;
        q.push(y);
      }
    }
    v[x] = true;
  }
  if (d[n - 1] == INT_MAX) cout << "IMPOSSIBLE";
  else {
    cout << d[n - 1] << endl;
    vector<int> path;
    int curr = n - 1;
    while (curr != 0)
    {
      path.push_back(curr);
      curr = p[curr];
    }
    reverse(path.begin(), path.end());
    cout << "1 ";
    for (int x : path) cout << x + 1 << " ";
  }
  return 0;
}