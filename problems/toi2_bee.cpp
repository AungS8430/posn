#include <bits/stdc++.h>
using namespace std;

int main(void) {
  vector<int> years;
  int input;
  int max_y = 0;
  while (cin >> input) {
    if (input < 0) break;
    max_y = max(max_y, input);
    years.push_back(input);
  }
  int x[max_y + 1] = {1, 2};
  if (max_y > 2) {
    for (int i = 2; i <= max_y; i++) {
      x[i] = x[i - 1] + x[i - 2] + 1;
    }
  }
  for (int i = 0; i < years.size(); i++) cout << x[years[i]] << " " << x[years[i]] + x[years[i] - 1] + 1 << endl;
  return 0;
}
