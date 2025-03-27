#include <bits/stdc++.h>
using namespace std;

int main(void) {
  vector<vector<int>> adj = {
    {0, 6, 5, 5, 0, 0, 0},
    {0, 0, 0, 0, -1, 0, 0},
    {0, -2, 0, 0, 1, 0, 0},
    {0, 0, -2, 0, 0, -1, 0},
    {0, 0, 0, 0, 0, 0, 3},
    {0, 0, 0, 0, 0, 0, 3},
    {0, 0, 0, 0, 0, 0, 0}
  };
  for (vector<int> row : adj) {
    for (int col : row) cout << col << " ";
    cout << endl;
  }
  return 0;
}