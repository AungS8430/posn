#include <bits/stdc++.h>
using namespace std;

void selection_sort(vector<int> &arr) {
  int n = arr.size();
  for (int i = 0; i < n - 1; i++) {
    int x = i;
    for (int j = i; j < n; j++) {
      if (arr[j] < arr[x]) x = j;
    }
    if (i != x) swap(arr[i], arr[x]);
  }
  return;
}

int main(void) {
  vector<int> arr = {7, 6, 4, 9, 3};
  selection_sort(arr);
  for (int i : arr) {
    cout << i << " ";
  }
  return 0;
}
