#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(void) {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> charge(n + 1, 0);
  vector<int> points(n + 1, 0);
  // int charge[n + 1];
  // int points[n + 1];
  // memset(charge, 0, n + 1);
  // memset(points, 0, n + 1);

  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    charge[i] = charge[i - 1];
    points[i] = points[i - 1];
    if (a >= 0) {
      points[i] += a;
    } else {
      charge[i] += -a;
    }
  }

  for (int i = 0; i < m; i++) {
    int x, h;
    cin >> x >> h;

    int l = x, r = n, ans = x;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (charge[mid] - charge[x] < h) {
        ans = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    cout << points[ans] - points[x] << "\n";
  }
  return 0;
}