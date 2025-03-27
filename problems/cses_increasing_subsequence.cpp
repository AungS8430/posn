#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n;
  cin >> n;
  vector<int> dp;
  for (int i = 0; i < n; i++) {
    long long x;
    cin >> x;
    auto pos = lower_bound(dp.begin(), dp.end(), x);
    if (pos != dp.end()) {
      *pos = x;
    } else {
      dp.push_back(x);
    }
  }
  cout << dp.size();
  return 0;
}