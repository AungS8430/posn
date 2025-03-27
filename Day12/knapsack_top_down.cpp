#include <bits/stdc++.h>
using namespace std;

int n, x;
vector<int> v, w;
vector<vector<int>> dp;

int knapsack(int i, int remainingWeight) {
  if (i == n || remainingWeight == 0) return 0;
  if (dp[i][remainingWeight] != -1) return dp[i][remainingWeight];

  int result = knapsack(i + 1, remainingWeight);

  if (w[i] <= remainingWeight) {
    result = max(result, knapsack(i + 1, remainingWeight - w[i]) + v[i]);
  }

  return dp[i][remainingWeight] = result;
}

int main(void) {
  cin >> n >> x;
  v.resize(n);
  w.resize(n);
  for (int i = 0; i < n; i++) cin >> v[i] >> w[i];

  dp.assign(n, vector<int>(x + 1, -1));
  cout << knapsack(0, x);
  return 0;
}