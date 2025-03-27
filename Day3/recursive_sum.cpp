#include <bits/stdc++.h>
#include <vector>
using namespace std;

int get_sum(vector<int>& x, int i) {
  if (i == x.size()) {
    return 0;
  } else {
    return x[i] + get_sum(x, i + 1);
  }
}

int main(void) {
  int input;
  vector<int> x;
  cout << "Enter numbers with other characters to end input: ";
  while (cin >> input) {
    x.push_back(input);
  }
  int y = get_sum(x, 0);
  cout << y;
  return 0;
}
