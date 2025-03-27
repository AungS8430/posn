#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> coeff(n + 1, vector<int>(n + 1));
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      if (j == 0 || i == j) coeff[i][j] = 1;
      else if (i > 0 && j > 0) coeff[i][j] = coeff[i - 1][j - 1] + coeff[i - 1][j];
      cout << coeff[i][j] << " ";
    }
    cout << endl;
  }
  cout << coeff[n][k];
  return 0;
}