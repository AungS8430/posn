#include <bits/stdc++.h>
using namespace std;

void get_permutations(vector<int> &arr) {
  sort(arr.begin(), arr.end())
  do {
    for (int x : arr) cout << x << " ";
    cout << endl;
  } while(next_permutation(arr.begin(), arr.end()));
  return;
}

int main(void) {
  vector<int> arr = {1, 2, 3, 4, 6, 7};
  get_permutations(arr);
  return 0;
}
