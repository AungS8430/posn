#include <bits/stdc++.h>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct T_PAIR {
  int j;
  int k;
  bool operator<(const T_PAIR &p) const {
    if (j == p.j) return k < p.k;
    else return j < p.j;
  }
} t_pair;

t_pair add(t_pair prev, int m, int t) {
  if (prev.k + t > m) {
    prev.j++;
    prev.k = t;
  } else prev.k += t;
  return prev;
}

int main(void) {
  int m, n, x, y;
  cin >> m;
  cin >> n;
  int k[2][n];
  t_pair min_time[n + 1][n + 1];
  min_time[0][0] = {0, 0};
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < n; j++) {
      cin >> k[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    min_time[0][i] = add(min_time[0][i - 1], m, k[1][i - 1]);
    min_time[i][0] = add(min_time[i - 1][0], m, k[0][i - 1]);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      min_time[i][j] = min(add(min_time[i - 1][j], m, k[0][i - 1]), add(min_time[i][j - 1], m, k[1][j - 1]));
    }
  }
  cout << min_time[n][n].j + 1 << endl << min_time[n][n].k << endl;
  return 0;
}
