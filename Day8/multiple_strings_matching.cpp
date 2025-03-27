#include <bits/stdc++.h>
using namespace std;

int main(void) {
  string source = "ababdababcabcababaababdbd", pattern = "ababd";
  for (int i = 0; i < source.length() - pattern.length(); i++) {
    bool matched = true;
    for (int j = 0; j < pattern.length(); j++) {
      if (source[i + j] != pattern[j]) {
        matched = false;
      }
    }
    if (matched) cout << i << " ";
  }
  return 0;
}