#include <bits/stdc++.h>
using namespace std;

int main(void) {
  string a, b;
  cin >> a >> b;
  int n = a.length();
  vector<vector<int>> lcs(n + 1, vector<int> (n + 1, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (a[i - 1] == b[j - 1]) lcs[i][j] = lcs[i - 1][j - 1] + 1;
      else lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
    }
  }
  pair<int, int> curr = {n, n};
  string result = "";
  while (curr.first > 0 && curr.second > 0) {
    if (a[curr.first - 1] == b[curr.second - 1]) {
      result += a[curr.first - 1];
      curr.first--;
      curr.second--;
    } else if (lcs[curr.first - 1][curr.second] > lcs[curr.first][curr.second - 1]) {
      curr.first--;
    } else {
      curr.second--;
    }
  }
  reverse(result.begin(), result.end());
  cout << result << endl << lcs[n][n] << endl << (lcs[n][n] > (n + 1) / 2 ? "y" : "n");
  return 0;
}