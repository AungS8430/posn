#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<int> &arr, int left, int right) {
  if (left == right) return arr[left - 1];
  int mid = left + (right - left) / 2;
  set<int> unique;
  for (int i = left; i <= mid; i++) {
    unique.insert(arr[i]);
  }
  if (unique.size() < mid - left + 1) {
    return binary_search(arr, left, mid);
  } else {
    return binary_search(arr, mid + 1, right);
  }
}

int main(void) {
  vector<int> arr = {1, 2, 3, 4, 5, 5, 6};
  cout << binary_search(arr, 0, arr.size() - 1);
  return 0;
}