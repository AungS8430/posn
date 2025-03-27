#include <bits/stdc++.h>
#define ll long long
#define mod ((ll)(1e9+7))
using namespace std;

int main(void) {
  int n, m;
  cin >> n >> m;
  vector<vector<pair<ll, int>>> adj(n);
  for (int i = 0; i < m ;i++) {
    int a, b; ll c;
    cin >> a >> b >> c;
    adj[a - 1].push_back({c, b - 1});
  }

  //Dijsktra
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
  vector<ll> dst(n, LLONG_MAX);
  vector<bool> vst(n, false);
  vector<int> prt(n, -1);
  vector<int> cnt(n, 0);
  vector<ll> mn(n, LLONG_MAX);
  vector<ll> mx(n, LLONG_MIN);

  dst[0] = 0;
  pq.push({0, 0});
  cnt[0] = 1;
  mn[0] = 0;
  mx[0] = 0;

  while (!pq.empty()) {
    int x = pq.top().second; pq.pop();
    if (vst[x]) continue;
    vst[x] = true;

    for (auto [w, y] : adj[x]) {
      if (dst[x] != LLONG_MAX && dst[x] + w < dst[y]) {
        cnt[y] = cnt[x];
        dst[y] = dst[x] + w;
        prt[y] = x;
        mn[y] = mn[x] + 1;
        mx[y] = mx[x] + 1;
        pq.push({dst[y], y});
      } else if (dst[x] != LLONG_MAX && dst[x] + w == dst[y]) {
        cnt[y] = (cnt[y] + cnt[x]) % mod;
        mn[y] = min(mn[y], mn[x] + 1);
        mx[y] = max(mx[y], mx[x] + 1);
      }
    }
  }

  cout << dst[n - 1] << " " << cnt[n - 1] << " " << mn[n - 1] << " " << mx[n - 1];
  return 0;
}