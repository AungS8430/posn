#include <bits/stdc++.h>
using namespace std;

int main(void) {
  map<int, vector<pair<int, int>>> adj = {{1, {{2, 5}, {3, 3}, {4, 7}}}, {2, {{1, 5}, {4, 3}, {5, 2}}}, {3, {{1, 3}, {4, 1}}}, {4, {{1, 7}, {2, 3}, {3, 1}, {5, 2}}}, {5, {{2, 2}, {4, 2}}}};
  map<int, int> dst = {{1, 0}, {2, INT_MAX}, {3, INT_MAX}, {4, INT_MAX}, {5, INT_MAX}};
  int n = 5;
  // queue<int> q;
  set<int> visited;
  for (int i = 0; i < n - 1; i++) {
    for (pair<int, vector<pair<int, int>>> node : adj) {
      for (pair<int, int> a_node : node.second) {
        //if (dst[node.first] != INT_MAX && dst[a_node.first] > dst[node.first] + dst[a_node.second]) 
        dst[a_node.first] = min(dst[a_node.first], dst[node.first] + (dst[node.first] == INT_MAX ? 0 : a_node.second));
      }
    }
  }
  cout << dst[5];
  return 0;
}