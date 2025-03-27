#include <bits/stdc++.h>
using namespace std;

void insertion_sort(deque<int> &arr) {
  int n = arr.size();
  for (int i = 1; i < n; i++) {
    int pos;
    for (pos = 0; pos <= i && arr[pos] < arr[i]; pos++);
    arr.insert(arr.begin() + pos, arr[i]);
    arr.erase(arr.begin() + i + 1);
  }
  return;
}

int main(void) {
  deque<int> arr = {7, 6, 4, 9, 3};
  insertion_sort(arr);
  for (int i : arr) {
    cout << i << " ";
  }
  return 0; 
}
