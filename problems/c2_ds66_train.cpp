#include <bits/stdc++.h>
using namespace std;

int shortest_path(vector<vector<bool>> &adj, int n, bool mode) {
  queue<int> q;
  vector<bool> visited(n, false);
  vector<int> distance(n, INT_MAX);
  distance[0] = 0;
  q.push(0);
  while (!q.empty()) {
    int x = q.front(); q.pop();
    for (int i = 0; i < n; i++) {
      if (adj[x][i] == mode && !visited[i]) {
        distance[i] = min(distance[i], distance[x] + 10 * abs(x - i));
        q.push(i);
      }
    }
    visited[x] = true;
  }
  return distance[n - 1] == INT_MAX ? -1 : distance[n - 1];
}

int main(void) {
  int n, m;
  cin >> n >> m;
  vector<vector<bool>> adj(n, vector<bool> (n, false));
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a - 1][b - 1] = adj[b - 1][a - 1] = true;
  }
  int time_train = shortest_path(adj, n, true);
  int time_car = shortest_path(adj, n, false);
  if (time_train == -1 || time_car == -1) {
    cout << -1;
  } else {
    cout << max(time_train, time_car);
  }
  return 0;
}