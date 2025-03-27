#include <bits/stdc++.h>
#include <vector>
using namespace std;

int search(vector<int> x, int y, int l, int r) {
  if (l == r) {
    if (x[l] == y) return l;
    else return -1;
  } else {
    int p = (r - l + 1) / 2 + l;
    if (x[p] == y) return p;
    else if (x[p] > y) {
      return search(x, y, l, p - 1);
    } else {
      return search(x, y, p + 1, r);
    }
  }
}

int main(void) {
  int y;
  vector<int> x = {1, 2, 3, 4, 5, 6, 7, 8};
  cin >> y;
  int i = search(x, y, 0, x.size() - 1);
  cout << i;
  return 0;
}
