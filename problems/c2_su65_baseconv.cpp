#include <bits/stdc++.h>
using namespace std;

string result = "";

void convert(int i, int n) {
  int r = i % n;
  i /= n;
  if (r < 10) {
    result += r + '0';
  } else {
    result += r - 10 + 'A';
  }
  if (i > 0) convert(i, n);
  return;
}

int main(void) {
  int i, n;
  cin >> i >> n;
  convert(i, n);
  reverse(result.begin(), result.end());
  cout << result;
  return 0;
}