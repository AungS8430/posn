#include <bits/stdc++.h>
#define ll long long
using namespace std;

void dfs(vector<vector<pair<int, int>>> &adj, vector<pair<int, int>> &res, vector<bool> &v, int x) {
  if (v[x]) return;
  v[x] = true;
  for (auto [y, yw] : adj[x]) {
    if (!v[y]) {
      res.push_back({y, yw});
      dfs(adj, res, v, y);
    }
  }
}

int main(void) {
  int n;
  cin >> n;
  n++;
  vector<vector<pair<int, int>>> adj(n);
  int mn = INT_MAX;
  int sum = 0;
  for (int i = 0; i < n - 1; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({b, c});
    adj[b].push_back({a, c});
    sum += c;
    mn = min(mn, c);
  }

  vector<pair<int, int>> sorted;
  vector<bool> v(n, false);
  for (int i = 0; i < n; i++) {
    if (adj[i].size() == 1) {
      dfs(adj, sorted, v, i);
      break;
    }
  }

  int left = mn, right = sum, ans;
  while (left <= right) {
    int mid = (left + right) / 2;
    ll sum, cnt;
    sum = cnt = 0;
    for (int i = 0; i < n; i++) {
      sum += sorted[i].second;
      if (sum >= mid) {
        sum = 0;
        cnt++;
      }
    }
    if (cnt >= 3) {
      ans = mid;
      left = mid + 1;
    }
    else right = mid - 1;
  }

  cout << ans << endl;
  return 0;
}