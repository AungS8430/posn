#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(void) {
  int n, m;
  cin >> n >> m;
  vector<vector<pair<ll, int>>> adj(n);
  vector<vector<ll>> cst(n, vector<ll>(2, LLONG_MAX));
  priority_queue<tuple<ll, int, bool>, vector<tuple<ll, int, bool>>, greater<tuple<ll, int, bool>>> pq;
  pq.push({0, 0, false});
  cst[0][0] = cst[0][1] = 0;

  for (int i = 0; i < m; i++) {
    int a, b; ll c;
    cin >> a >> b >> c;
    adj[a - 1].push_back({c, b - 1});
  }

  while (!pq.empty()) {
    auto [c_cst, c_dest, c_coupon] = pq.top(); pq.pop();

    if (c_cst > cst[c_dest][c_coupon]) continue;

    for (auto [n_cst, n_node] : adj[c_dest]) {
      if (c_coupon && c_cst + n_cst < cst[n_node][c_coupon]) {
        cst[n_node][c_coupon] = c_cst + n_cst;
        pq.push({cst[n_node][c_coupon], n_node, c_coupon});
      } else if (!c_coupon) {
        if (c_cst + n_cst < cst[n_node][c_coupon]) {
          cst[n_node][c_coupon] = c_cst + n_cst;
          pq.push({cst[n_node][c_coupon], n_node, c_coupon});
        }
        if (c_cst + (n_cst / 2) < cst[n_node][!c_coupon]) {
          cst[n_node][!c_coupon] = c_cst + (n_cst / 2);
          pq.push({cst[n_node][!c_coupon], n_node, !c_coupon});
        }
      }
    }
  }

  cout << cst[n - 1][1];
  return 0;
}