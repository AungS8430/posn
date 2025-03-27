#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int i, n = 5, p[5] = {0, 1, 2, 3, 4};
  int x = 3, y = 4; //People that can't be seated together
  int k = 2; //Minimum distance between them;
  do {
    if (distance(find(p, p + n, x), find(p, p + n, y)) > k) {
      for (int i = 0; i < n; i++) cout << p[i] << " ";
      cout << endl;
    }
  } while(next_permutation(p, p + n));
  return 0;
}