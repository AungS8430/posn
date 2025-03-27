#include <bits/stdc++.h>
using namespace std;

int main(void) {
  string source = "ababcabcabababd", pattern = "ababd";
  cout << distance(source.begin(), search(source.begin(), source.end(), pattern.begin(), pattern.end()));
  return 0;
}