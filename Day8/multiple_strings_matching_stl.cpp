#include <bits/stdc++.h>
using namespace std;

int main(void) {
  string source = "ababdababcabcababaababdbd", pattern = "ababd";
  for (string::iterator i = source.begin(); i < source.end() - pattern.length(); i++) {
    string::iterator it = search(i, source.end(), pattern.begin(), pattern.end());
    if (it != source.end()) {
      cout << distance(source.begin(), it) << " ";
      i = it + pattern.length() - 1;
    }
  }
  return 0;
}