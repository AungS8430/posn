#include <bits/stdc++.h>
using namespace std;

int main(void) {
  vector<int> arr = {1, 2, 3, 4, 5};
  int n = 5, x = 7;
  for (int i = 0; i < (1<<n); i++) {
    int sum = 0;
    for (int j = 0; j < n; j++) {
      if (i&(1<<j)) sum += arr[j];
    }
    if (sum == 7) {
      cout << "Found";
      return 0;
    }
  }
  cout << "Not found";
  return 0;
}