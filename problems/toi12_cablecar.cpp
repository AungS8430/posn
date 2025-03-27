#include <bits/stdc++.h>
using namespace std;
#define vb vector<bool>
#define vi vector<int>
#define vvi vector<vi>
#define pi pair<int, int>
#define vpi vector<pi>
#define vvpi vector<vpi>
#define pqir priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>>

int main(void) {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, m, s, d, p;
  cin >> n >> m;
  vvpi adj(n);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u - 1].push_back({v - 1, w});
    adj[v - 1].push_back({u - 1, w});
  }
  cin >> s >> d >> p;
  s--; d--;
  vi mx_w(n, INT_MIN);
  mx_w[s] = INT_MAX;
  pqir pq;
  pq.push({INT_MAX, s});
  vb v(n, false);
  while (!pq.empty()) {
    auto [w, x] = pq.top(); pq.pop();
    if (!v[x]) {
      for (auto [y, yw] : adj[x]) {
        mx_w[y] = max(mx_w[y], min(mx_w[x] , yw));
        pq.push({mx_w[y], y});
      }
    }
    v[x] = true;
  }
  // for (int w : mx_w) cout << w << " ";
  cout << (p + (mx_w[d] - 1) - 1) / (mx_w[d] - 1);
  return 0;
}