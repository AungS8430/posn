#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll INF = -1e18;

int main(void) {
  int n, m;
  cin >> n >> m;
  vector<vector<pair<ll, int>>> adj(n);
  vector<ll> score(n, INF);
  score[0] = 0;
  for (int i = 0; i < m; i++) {
    int a, b; ll c;
    cin >> a >> b >> c;
    adj[a - 1].push_back({c, b - 1});
  }

  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n; j++) {
      if (score[j] != INF) {
        for (auto [w, x] : adj[j]) {
          score[x] = max(score[x], score[j] + w);
        }
      }
    }
  }

  vector<int> positive_cycle_nodes;
  vector<ll> final_scores = score;
  for (int i = 0; i < n; i++) {
    for (auto [w, x] : adj[i]) {
      if (score[i] != INF && score[x] < score[i] + w) {
        final_scores[x] = score[i] + w;
        positive_cycle_nodes.push_back(x);
      }
    }
  }

  if (!positive_cycle_nodes.empty()) {
    vector<bool> can_reach_end(n, false);
    queue<int> q;
    for (int node : positive_cycle_nodes) {
      q.push(node);
      can_reach_end[node] = true;
    }

    while (!q.empty()) {
      int u = q.front();
      q.pop();
      if (u == n - 1) {
        cout << -1 << endl;
        return 0;
      }
      for (auto [w, v] : adj[u]) {
        if (!can_reach_end[v]) {
          can_reach_end[v] = true;
          q.push(v);
        }
      }
    }
  }

  cout << score[n - 1];

  return 0;
}