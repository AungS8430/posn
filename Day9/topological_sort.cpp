#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj = {
  {1, 2},
  {2, 3},
  {3, 5},
  {4},
  {},
  {},
  {},
  {6}
};

void dfs(stack<int> &s, set<int> &v, int x) {
  for (int a : adj[x]) {
    if (!binary_search(v.begin(), v.end(), a)) dfs(s, v, a);
  }
  v.insert(x);
  s.push(x);
}

int main(void) {
  stack<int> s;
  set<int> v;
  for (int i = 0; i < 8; i++) {
    if (!binary_search(v.begin(), v.end(), i)) dfs(s, v, i);
  }

  while(!s.empty()) {
    cout << s.top() << " ";
    s.pop();
  }
  return 0;
}