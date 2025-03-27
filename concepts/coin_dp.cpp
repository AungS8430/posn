#include <bits/stdc++.h>
#include <climits>
using namespace std;

int coins[] = {1, 2, 4};

int main(void) {
  int n;
  cin >> n;
  int value[n + 1];
  int first[n + 1];
  value[0] = 0;
  for (int i = 1; i <= n; i++) {
    value[i] = INT_MAX;
    for (int c : coins) {
      if (i - c >= 0 && value[i - c] != INT_MAX) {
        value[i] = min(value[i], value[i - c] + 1);
        first[i] = c;
      }
    }
  }
  cout << value[n] << endl;
  int remaining = n;
  while (remaining > 0) {
    cout << first[remaining] << " ";
    remaining -= first[remaining];
  }
  return 0;
}
