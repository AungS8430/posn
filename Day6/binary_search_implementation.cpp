#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<int> &arr, int left, int right, int x) {
  if (left > right) return -1;
  int size = right - left + 1;
  if (arr[left + (size / 2)] == x) return left + (size / 2);
  else if (arr[left + (size / 2)] < x) return binary_search(arr, left + (size / 2) + 1, right, x);
  else return binary_search(arr, left, left + (size / 2) - 1, x);
}

int main(void) {
  vector<int> arr = {4, 7, 10, 11, 16};
  cout << binary_search(arr, 0, arr.size() - 1, 11);
  return 0;
}
