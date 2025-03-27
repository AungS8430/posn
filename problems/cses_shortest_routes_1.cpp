#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(void) {
  int n, m;
  cin >> n >> m;
  vector<vector<pair<ll, ll>>> adj(n);
  vector<ll> dst(n, LLONG_MAX);
  vector<bool> vst(n, false);
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
  q.push({0, 0});
  dst[0] = 0;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a - 1].push_back({c, b - 1});
  }

  while (!q.empty()) {
    auto [cw, cn] = q.top(); q.pop();
    if (vst[cn]) continue;
    vst[cn] = true;
    for (auto [nw, nn] : adj[cn]) {
      if (dst[cn] != LLONG_MAX && dst[cn] + nw < dst[nn]) {
        dst[nn] = dst[cn] + nw;
        q.push({dst[nn], nn});
      }
    }
  }

  for (int i = 0; i < n; i++) cout << dst[i] << " ";
  return 0;
}