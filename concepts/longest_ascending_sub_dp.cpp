#include <bits/stdc++.h>
using namespace std;

int arr[] = {6, 2, 5, 1, 7, 4, 8, 3};

int main(void) {
  int n;
  cin >> n;
  int length[n];
  for (int i = 0; i <= n; i++) {
    length[i] = 1;
    for (int j = 0; j < i; j++) {
      if (arr[j] < arr[i]) length[i] = max(length[i], length[j] + 1);
    }
  }
  cout << length[n];
  return 0;
}
