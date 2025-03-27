#include <bits/stdc++.h>
using namespace std;

void print_path(vector<int> &parents, int x, int k) {
  if (x == k) {
    return;
  } else {
    print_path(parents, parents[x], k);
    cout << parents[x] << " ";
    return;
  }
}

int main(void) {
  int n, m, k;
  cin >> n >> m;
  vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>> ());
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({b, c});
  }
  cin >> k;
  vector<int> distance(n, INT_MAX);
  distance[k] = 0;
  queue<int> q;
  set<int> visited;
  vector<int> parents(n);
  q.push(k);
  while (!q.empty()) {
    int x = q.front(); q.pop();
    if (binary_search(visited.begin(), visited.end(), x)) continue;
    for (pair<int, int> a_node : adj[x]) {
      if (distance[x] + a_node.second < distance[a_node.first] && distance[x] != INT_MAX) {
        distance[a_node.first] = distance[x] + a_node.second;
        parents[a_node.first] = x;
        q.push(a_node.first);
      }
    }
    visited.insert(x);
  };
  for (int i = 0; i < n; i++) {
    if (i != k) {
      cout << k << " -> " << i << " (";
      if (distance[i] == INT_MAX) cout << "inf) " << endl;
      else {
        cout << distance[i];
        cout << ") ";
        print_path(parents, i, k);
        cout << i << endl;
      }
    }
  }
  return 0;
}