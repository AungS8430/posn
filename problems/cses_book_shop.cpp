#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n, x, sum = 0;
  cin >> n >> x;
  vector<pair<int, int>> books(n);
  vector<int> dp(x + 1, 0);
  for (int i = 0; i < n; i++) cin >> books[i].first;
  for (int i = 0; i < n; i++) cin >> books[i].second;
  sort(books.begin(), books.end());

  for (int i = 0; i < n; i++) {
    for (int j = x; j >= 0; j--) {
      if (books[i].first <= j) dp[j] = max(dp[j], dp[j - books[i].first] + books[i].second);
    }
  }
  cout << dp[x];
  return 0;
}