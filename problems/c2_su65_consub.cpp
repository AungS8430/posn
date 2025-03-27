#include <bits/stdc++.h>
#include <sstream>
using namespace std;

int main(void) {
  map<int, bool> arr;
  vector<int> curr_seq, max_seq;
  int x, n = 0, max_end = 0;
  string input;
  getline(cin, input);
  string substring;
  stringstream ss(input);
  while (ss >> substring) {
    try {
      x = stoi(substring);
      arr[x] = true;
    } catch (exception &e) {
      break;
    }
  }
  for (map<int, bool>::iterator i = arr.begin(); i != arr.end(); i++) {
    if (curr_seq.empty() || curr_seq.back() + 1 == i->first) {
      curr_seq.push_back(i->first);
    } else if (curr_seq.back() + 1 != i->first) {
      if (curr_seq.size() > max_seq.size()) {
        max_seq = curr_seq;
      }
      curr_seq.clear();
      curr_seq.push_back(i->first);
    }
  }
  if (curr_seq.size() > max_seq.size()) max_seq = curr_seq;
  for (int x : max_seq) cout << x << " ";
  return 0;
}