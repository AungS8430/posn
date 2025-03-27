#include <bits/stdc++.h>
using namespace std;

int main(void) {
  vector<pair<pair<int, int>, int>> adj = {
    {{1, 2}, 6},
    {{1, 3}, 5},
    {{1, 4}, 5},
    {{2, 5}, -1},
    {{3, 2}, -2},
    {{3, 5}, 1},
    {{4, 3}, -2},
    {{4, 6}, -1},
    {{5, 7}, 3},
    {{6, 7}, 3}
  };
  for (pair<pair<int, int>, int> edge : adj) cout << edge.first.first << " -> " << edge.first.second << " (" << edge.second << ")" << endl;
  return 0;
}