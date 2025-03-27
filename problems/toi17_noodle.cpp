#include <bits/stdc++.h>
using namespace std;

int main(void) {
  // n is amount of channels, m is amount of shops and k is amount of each shop's channel quota
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> channel(n);
  for (int i = 0; i < n; i++) cin >> channel[i];
  vector<int> sorted = channel;
  sort(sorted.begin(), sorted.end(), greater<int> ());
  int left = *min_element(channel.begin(), channel.end()), right = reduce(sorted.begin(), sorted.begin() + min(k, n), 0), mid, ans = 0;
  while (left < right) {
    mid = (left + right) / 2;
    bool possible = true;
    for (int i = 0; i < m; i++) {
      int start = (i == 0 ? 0 : (n / m) * i);
      int end = min(n - 1, (n / m) * (i + 1) - 1);

      vector<int> x;
      for (int a = start; a <= end; a++) x.push_back(channel[a]);
      sort(x.begin(), x.end());
      reverse(x.begin(), x.end());

      if (reduce(x.begin(), min(x.end(), x.begin() + k), 0) < mid) {
        possible = false;
        break;
      }
    }
    if (!possible) {
      left = mid + 1;
    } else {
      ans = mid;
      right = mid;
    }
  }
  cout << ans;
  return 0;
}