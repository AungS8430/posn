#include <bits/stdc++.h>
using namespace std;

int main(void) {
  vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
  vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};

  int n = arr.size();
  int x = 0;
  for (int i = 0; i < n; i++) {
    int cnt = 1;
    for (int j = 0; j < n; j++) {
      if (i != j && arr[i] >= arr[j] && dep[j] >= arr[i]) cnt++;
    }
    x = max(x, cnt);
  }
  cout << x;
  return 0;
}