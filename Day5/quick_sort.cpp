#include <bits/stdc++.h>
using namespace std;

void quick_sort(vector<int> &arr, int left, int right) {
  if (left < right) {
    int pivot = arr[right];
    int pos = left - 1;
    for (int i = left; i < right; i++) {
      if (arr[i] < pivot) {
        pos++;
        swap(arr[pos], arr[i]);
      }
    }
    swap(arr[pos + 1], arr[right]);
    quick_sort(arr, left, pos);
    if (pos < right) quick_sort(arr, pos + 2, right);
  };
  return;
}

int main(void) {
  vector<int> arr = {7, 6, 4, 9, 3};
  quick_sort(arr, 0, arr.size() - 1);
  for (int i : arr) {
    cout << i << " ";
  }
  return 0;
}
