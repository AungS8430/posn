#include <bits/stdc++.h>
#include <vector>
#include <stack>
using namespace std;

typedef struct VERTEX {
  int id, weight;
} vertex;

int main(void) {
  int n = 5;
  vector<vector<vertex>> graph(n);
  graph[0] = {{1, 10}, {4, 12}};
  graph[1] = {{0, 10}, {2, 15}, {3, 25}, {4, 7}};
  graph[2] = {{1, 15}, {3, 20}};
  graph[3] = {{1, 25}, {2, 20}, {4, 8}};
  graph[4] = {{0, 12}, {1, 7}, {3, 8}};
  for (int i = 0; i < n; i++) {
    vector<vertex> v = graph[i];
    cout << i;
    for (vertex u : v) {
      cout << " -> " << u.id << " (" << u.weight << ")";
    }
    cout << endl;
  }
  return 0;
}
