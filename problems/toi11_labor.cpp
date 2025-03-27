#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(void) {
  ios_base::sync_with_stdio(0), cin.tie(0);
  ll m, n;
  cin >> m >> n;
  vector<int> t(m);
  for (int i = 0; i < m; i++) cin >> t[i];
  ll left = *min_element(t.begin(), t.end()), right = left * n;
  while (left < right) {
    ll mid = (left + right) / 2;
    ll count = 0;
    for (int i = 0; i < m; i++) count += mid / t[i];
    if (count < n) left = mid + 1;
    else right = mid;
  }
  cout << left;
  return 0;
}