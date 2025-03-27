#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(void) {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n);
  vector<int> prt(n, -1);
  vector<int> vst(n, 0);

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a - 1].push_back(b - 1);
  }

  for (int i = 0; i < n; i++) {
    if (vst[i] == 0) {
      stack<int> s;
      s.push(i);
      vst[i] = 1; // Mark as visiting

      while (!s.empty()) {
        int x = s.top();
        bool advanced = false;

        for (int y : adj[x]) {
          if (vst[y] == 1) {
            vector<int> cycle;
            int curr = x, end = y;
            while (curr != end) {
              cycle.push_back(curr);
              curr = prt[curr];
            }
            cycle.push_back(y);
            cycle.push_back(x);
            reverse(cycle.begin(), cycle.end());
            cout << cycle.size() << endl;
            for (int c : cycle) cout << c + 1 << " ";
            return 0;
          } else if (vst[y] == 0) {
            prt[y] = x;
            vst[y] = 1;
            s.push(y);
            advanced = true;
            break;
          }
        }
        if (!advanced) {
          vst[x] = 2;
          s.pop();
        }
      }
    }
  }
  cout << "IMPOSSIBLE";
  return 0;
}