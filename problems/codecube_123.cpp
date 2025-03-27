#include <bits/stdc++.h>
using namespace std;

void mainop() {
  string s1, s2;
  cin >> s1 >> s2;
  int len = s2.size();
  while (s1.find(s2) != string::npos) {
    s1.erase(s1.find(s2), len);
  }
  if (s1.size() == 0) cout << "No COI Secret Code" << endl;
  else cout << s1 << endl;
}

int main(void) {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) mainop();
  return 0;
}