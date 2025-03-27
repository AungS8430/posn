#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(void) {
  int n;
  cin >> n;
  vector<int> sales(n);
  vector<ll> bonus(n, 1000);
  for (int i = 0; i < n; i++) cin >> sales[i];
  for (int i = 1; i < n; i++) {
    if (sales[i] == sales[i - 1]) bonus[i] = bonus[i - 1];
    else if (sales[i] > sales[i - 1]) bonus[i] = bonus[i - 1] + 1000;
  }
  for (int i = n - 2; i >= 0; i--) {
    if (sales[i] == sales[i + 1]) bonus[i] = bonus[i + 1] = max(bonus[i + 1], bonus[i]);
    else if (sales[i] > sales[i + 1] && bonus[i] <= bonus[i + 1]) bonus[i] = (bonus[i + 1]) + 1000;
  }
  long long total = 0;
  for (int i = 0; i < n; i++) total += bonus[i];
  cout << total; //reduce(bonus.begin(), bonus.end(), 0);
  return 0;
}