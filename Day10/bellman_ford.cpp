#include <bits/stdc++.h>
using namespace std;

int main(void) {
  map<int, vector<pair<int, int>>> adj = {
    {1, {{2, 6}, {3, 5}, {4, 5}}},
    {2, {{5, -1}}},
    {3, {{2, -2}, {5, 1}}},
    {4, {{3, -2}, {6, -1}}},
    {5, {{7, 3}}},
    {6, {{7, 3}}},
    {7, {}}
  };
  vector<int> distance(8, INT_MAX);
  distance[1] = 0;
  for (auto [node, edges] : adj) {
    for (auto [dest, weight] : edges) {
      distance[dest] = min(distance[dest], distance[node] + (distance[node] == INT_MAX ? 0 : weight));
    }
  }
  for (int i = 1; i < 8; i++) cout << "Distance to node " << i << " : " << distance[i] << endl;
  return 0;
}