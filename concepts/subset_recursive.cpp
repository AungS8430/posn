#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<int> subset;

void search(int k, int n) {
  if (k == n) {
    for (int x : subset) {
      cout << x << " ";
    }
    cout << endl;
    return;
  } else {
    search(k + 1, n);
    subset.push_back(k);
    search(k + 1, n);
    subset.pop_back();
  }
}

int main(void) {
  search(0, 3);
  return 0;
}
