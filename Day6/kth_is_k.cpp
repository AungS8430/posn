// t(n) = O(log n)

#include <bits/stdc++.h>
using namespace std;

int kth_is_k(vector<int> &arr, int l, int r) {
  int size = r - l + 1;
  int mid = l + size / 2;
  if (arr[mid] == mid) return mid;
  else if (arr[mid] > mid) {
    return kth_is_k(arr, l, mid - 1);
  } else {
    return kth_is_k(arr, mid + 1, r);
  }
}

int main(void) {
  vector<int> arr = {-5, -4, -3, -1, 0, 1, 2, 6, 8, 11, 13, 14, 19, 20, 24, 26, 35, 48, 49, 80, 90, 92};
  int k = kth_is_k(arr, 0, arr.size() - 1);
  cout << k << endl;
  return 0;
}
