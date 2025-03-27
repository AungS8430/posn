#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<char, int> &a, pair<char, int> &b) {
  return a.second > b.second;
}

int get_max(string str) {
  map<char, int> chr;
  for (int i = 0; i < str.length(); i++) {
    chr[tolower(str[i])]++;
  }
  vector<pair<char, int>> chr_vec(chr.begin(), chr.end());
  sort(chr_vec.begin(), chr_vec.end(), cmp);
  int sum = 0;
  int i = 26;
  for (auto [c, x] : chr_vec) {
    //cout << c << " " << x << endl;
    sum += x * i;
    i--;
  }
  return sum;
}

int main(void) {
  int n;
  cin >> n;
  vector<int> res;
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    res.push_back(get_max(str));
  }
  for (int x : res) cout << x << endl;
  return 0;
}