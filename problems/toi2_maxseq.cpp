#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n;
  cin >> n;
  int a[n], b[n], s;
  pair<int, int> max = {0, 0};
  for (int i = 0; i < n; i++) cin >> a[i];
  b[0] = a[0];
  max.first = a[0];
  for (int i = 1; i < n; i++) {
    if (b[i - 1] >= 0) {
      b[i] = b[i - 1] + a[i];
    }
    else {
      b[i] = a[i];
    }
    if (b[i] > max.first) {
      max = {b[i], i};
    }
  }
  if (b[max.second] <= 0) {
    cout << "Empty sequence";
    return 0;
  } else {
    for (s = max.second; b[s] >= 0; s--);
    s++;
    for (int i = s; i <= max.second; i++) cout << a[i] << " ";
    cout << endl << max.first;
  }
  return 0;
}
