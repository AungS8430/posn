#include <bits/stdc++.h>
using namespace std;

int binomialCoeff(int n, int k, vector<vector<int>> &dp) {
  if (k == 0 || k == n) return 1;
  if (dp[n][k] != -1) return dp[n][k];
  return dp[n][k] = binomialCoeff(n - 1, k - 1, dp) + binomialCoeff(n - 1, k, dp);
}

int main(void) {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
  cout << binomialCoeff(n, k, dp);
  return 0;
}
