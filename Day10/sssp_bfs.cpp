#include <bits/stdc++.h>
using namespace std;

int main(void) {
  map<int, vector<int>> adj = {
      {0, {1, 4}},
      {1, {0, 2, 5}},
      {2, {1, 3, 6}},
      {3, {2, 7}},
      {4, {0, 8}},
      {5, {1, 6, 10}},
      {6, {2, 5, 11}},
      {7, {3, 12}},
      {8, {4, 9}},
      {9, {8, 10}},
      {10, {5, 9, 11}},
      {11, {6, 10, 12}},
      {12, {7, 11}}
  };
  queue<int> q;
  set<int> visited;
  vector<int> distance(13, INT_MAX);
  distance[5] = 0;
  q.push(5);
  while (!q.empty()) {
    int x = q.front(); q.pop();
    if (visited.count(x)) continue;
    visited.insert(x);
    for (int node : adj[x]) {
      if (distance[node] > distance[x] + 1) q.push(node);
      distance[node] = min(distance[node], distance[x] + 1);
    }
  }
  for (int i = 0; i <= 12; i++) cout << i << " : " << distance[i] << endl;
  return 0;
}