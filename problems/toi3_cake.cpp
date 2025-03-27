#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n;
  cin >> n;
  int input;
  int x = 0;
  for (int i = 0; i < n; i++) {
    cin >> input;
    x += input * 8;
    cin >> input;
    x += input * 6;
    cin >> input;
    x += input * 4;
    cin >> input;
    x += input * 2;
    cin >> input;
    x += input;
  }
  cout << ceil(x / 8.0);
  return 0;
}
