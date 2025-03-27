#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
  int x[] = {0, 1, 2};
  int n = sizeof(x) / sizeof(x[0]);
  vector<vector<int>> permutations;
  vector<int> temp(x, x + n);
  do {
    for (int y : x) {
      permutations.push_back(temp);
    }
  } while(next_permutation(temp.begin(), temp.end()));
  for (vector<int> y : permutations) {
    for (int z : y) {
      cout << z << " ";
    }
    cout << endl;
  }
  return 0;
}
