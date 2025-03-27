#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> get_subsets(vector<int> &numbers) {
  vector<vector<int>> subsets;
  int n = numbers.size();
  for (int i = 0; i < (1 << n); i++) {
    vector<int> subset;
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        subset.push_back(numbers[j]);
      }
    }
    subsets.push_back(subset);
  }
  return subsets;
}

int main(void) {
  vector<int> numbers = {1, 2, 3, 4, 5};
  vector<vector<int>> subsets = get_subsets(numbers);
  for (vector<int> subset : subsets) {
    for (int x : subset) {
      cout << x << " ";
    }
    cout << endl;
  }
  return 0;
}
