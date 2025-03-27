#include <bits/stdc++.h>
using namespace std;

int main(void) {
  map<int, map<int, int>> adj = {
      {1, {{2, 6}, {3, 5}, {4, 5}}},
      {2, {{5, -1}}},
      {3, {{2, -2}, {5, 1}}},
      {4, {{3, -2}, {6, -1}}},
      {5, {{7, 3}}},
      {6, {{7, 3}}},
      {7, {}}
  };
  for (pair<int, map<int, int>> node : adj) {
    cout << node.first << " -> ";
    for (pair<int, int> dest : node.second) cout << dest.first << "(" << dest.second << ") ";
    cout << endl;
  }
  return 0;
}