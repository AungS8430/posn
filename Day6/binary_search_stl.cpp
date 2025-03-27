#include <bits/stdc++.h>
using namespace std;

int main(void) {
  vector<int> arr = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
  vector<int> query = {16, 88};
  for (int i = 0; i < query.size(); i++) {
    cout << "Query: " << query[i] << endl << (binary_search(arr.begin(), arr.end(), query[i]) ? "Found" : "Not found") << endl << "Lower bound: ";
    cout << *lower_bound(arr.begin(), arr.end(), query[i]) << endl;
    cout << "Upper bound: ";
    cout << *upper_bound(arr.begin(), arr.end(), query[i]) << endl << endl;
  }
  return 0;
}
