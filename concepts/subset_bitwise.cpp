#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(void) {
  int x[] = {1, 2, 3, 4, 5};
  vector<vector<int>> subsets;
  int n = sizeof(x) / sizeof(x[0]);
  for (int b = 0; b < (1 << n); b++) {
    vector<int> temp;
    for (int i = 0; i < n; i++) {
      if (b&(1<<i)) {
        temp.push_back(x[i]);
      }
    }
    subsets.push_back(temp);
  }
  for (vector<int> y : subsets) {
    for (int z : y) {
      cout << z << " ";
    }
    cout << endl;
  }
  return 0;
}
