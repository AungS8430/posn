#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n, count = 0;
  cin >> n;
  vector<int> coins(n);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> coins[i];
    sum += coins[i];
  }
  // sort(coins.begin(), coins.end());
  vector<bool> possible(sum + 1, false);
  possible[0] = true;
  for (int c : coins) {
    for (int i = sum; i >= c; i--) {
      if (possible[i - c] && !possible[i]) {
        possible[i] = true;
        count++;
      }
    }
  }
  cout << count << endl;
  for (int i = 1; i <= sum; i++) {
    if (possible[i]) {
      cout << i << " ";
    }
  }
  return 0;
}