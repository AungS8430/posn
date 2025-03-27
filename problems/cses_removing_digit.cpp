#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n, x;
  cin >> n;
  int i;
  for (i = 0; n > 0; i++) {
    x = n;
    priority_queue<int> units;
    while (x > 0) {
      units.push(x % 10);
      x /= 10;
    }
    // cout << units.top() << endl;
    n -= units.top(); units.pop();
  }
  cout << i;
  return 0;
}