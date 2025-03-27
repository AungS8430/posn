#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF LLONG_MAX

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m, x, y;
  ll z;
  cin >> n >> m >> x >> y >> z;

  vector<vector<pair<int, ll>>> adj(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    ll d;
    cin >> u >> v >> d;
    adj[u].push_back({v, d});
    adj[v].push_back({u, d});
  }

  vector<ll> distance(n, INF);
  distance[x] = 0;
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
  pq.push({0, x});

  while (!pq.empty()) {
    auto [dist, u] = pq.top();
    pq.pop();

    if (dist > distance[u]) continue;

    for (auto [v, weight] : adj[u]) {
      if (distance[u] + weight < distance[v]) {
        distance[v] = distance[u] + weight;
        pq.push({distance[v], v});
      }
    }
  }

  vector<ll> r_distance(n, INF);
  r_distance[y] = 0;
  pq.push({0, y});

  while (!pq.empty()) {
    auto [dist, u] = pq.top();
    pq.pop();

    if (dist > r_distance[u]) continue;

    for (auto [v, weight] : adj[u]) {
      if (r_distance[u] + weight < r_distance[v]) {
        r_distance[v] = r_distance[u] + weight;
        pq.push({r_distance[v], v});
      }
    }
  }

  int min_dst = -1;
  for (int i = 0; i < n; i++) {
    if (distance[i] <= z) {
      if (min_dst == -1 || r_distance[i] < r_distance[min_dst]) {
        min_dst = i;
      }
    }
  }

  if (min_dst != -1) {
    cout << min_dst << " " << distance[min_dst] << " " << r_distance[min_dst] << "\n";
  } else {
    cout << y << " " << distance[y] << "\n";
  }

  return 0;
}