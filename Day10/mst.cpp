#include <bits/stdc++.h>
using namespace std;

int main(void) {
  map<int, vector<pair<int, int>>> adj = {
    {1, {{2, 28}, {6, 10}}},
    {2, {{1, 28}, {3, 16}, {7, 14}}},
    {3, {{2, 16}, {4, 12}}},
    {4, {{3, 12}, {5, 22}, {7, 18}}},
    {5, {{4, 22}, {6, 25}, {7, 24}}},
    {6, {{1, 10}, {5, 25}}},
    {7, {{2, 14}, {4, 18}, {5, 24}}}
  };
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
  vector<int> key(8, INT_MAX);
  key[1] = 0;
  pq.push({0, 1});
  while (!pq.empty()) {
    auto [l, x] = pq.top(); pq.pop();
    for (auto [y, yl] : adj[x]) {
      if (key[y] == 0 || yl < key[y]) {
        key[y] = yl;
        pq.push({yl, y});
      }
    }
  }
  int mst_weight = 0;
  for (int i = 1; i < key.size(); i++) {
    if (key[i] != 0) {
      mst_weight += key[i];
      for (auto [y, yl] : adj[i]) {
        if (yl == key[i]) {
          cout << i << " - " << y << " : " << key[i] << endl;
          break;
        }
      }
    }
  }
  cout << "Minimum Spanning Tree Weight: " << mst_weight << endl;
}