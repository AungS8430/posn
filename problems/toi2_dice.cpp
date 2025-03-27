#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n;
  cin >> n;
  string cmd[n];
  vector<vector<vector<int>>> dices(n, {{0, 5, 0}, {0, 1, 0}, {3, 2, 4}, {0, 6, 0}});
  for (int i = 0; i < n; i++) {
    cin >> cmd[i];
  }
  int temp;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < cmd[i].length(); j++) {
      switch (cmd[i][j]) {
        case 'F':
          temp = dices[i][0][1];
          dices[i][0][1] = dices[i][3][1];
          dices[i][3][1] = dices[i][2][1];
          dices[i][2][1] = dices[i][1][1];
          dices[i][1][1] = temp;
          break;
        case 'B':
          temp = dices[i][3][1];
          dices[i][3][1] = dices[i][0][1];
          dices[i][0][1] = dices[i][1][1];
          dices[i][1][1] = dices[i][2][1];
          dices[i][2][1] = temp;
          break;
        case 'L':
          temp = dices[i][1][1];
          dices[i][1][1] = dices[i][2][2];
          dices[i][2][2] = dices[i][3][1];
          dices[i][3][1] = dices[i][2][0];
          dices[i][2][0] = temp;
          break;
        case 'R':
          temp = dices[i][1][1];
          dices[i][1][1] = dices[i][2][0];
          dices[i][2][0] = dices[i][3][1];
          dices[i][3][1] = dices[i][2][2];
          dices[i][2][2] = temp;
          break;
        case 'C':
          temp = dices[i][2][1];
          dices[i][2][1] = dices[i][2][2];
          dices[i][2][2] = dices[i][0][1];
          dices[i][0][1] = dices[i][2][0];
          dices[i][2][0] = temp;
          break;
        case 'D':
          temp = dices[i][2][1];
          dices[i][2][1] = dices[i][2][0];
          dices[i][2][0] = dices[i][0][1];
          dices[i][0][1] = dices[i][2][2];
          dices[i][2][2] = temp;
          break;
      }
    }
    cout << dices[i][2][1] << " ";
  }
  return 0;
}
