#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(void) {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<pair<ll, int>>> adj(n);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a - 1].push_back({c, b - 1});
  }

  vector<ll> ans;

  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
  pq.push({0, 0});

  vector<int> visit_count(n, 0);

  while (!pq.empty() && ans.size() < k) {
    auto [ct, cn] = pq.top(); pq.pop();

    visit_count[cn]++;
    if (cn == n - 1) ans.push_back(ct);

    if (visit_count[cn] <= k) {
      for (auto [nt, nn] : adj[cn]) {
        pq.push({ct + nt, nn});
      }
    }
  }

  for (ll t : ans) cout << t << " ";
  return 0;
}