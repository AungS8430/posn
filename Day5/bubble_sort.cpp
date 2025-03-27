#include <bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int> &arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    bool swapped = false;
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
        swapped = true;
      }
    }
    if (swapped == false) break;
  }
}

int main(void) {
  vector<int> arr = {7, 6, 4, 9, 3};
  bubble_sort(arr);
  for (int i : arr) {
    cout << i << " ";
  }
  return 0;
}
