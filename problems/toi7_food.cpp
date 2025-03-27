#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> f, ff;
  for (int i = 1; i <= n; i++) f.push_back(i);
  ff = f;
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    ff.erase(find(ff.begin(), ff.end(), x));
  };
  for (int i = 0; i < n - m; i++) {
    sort(f.begin(), f.end());
    f.erase(find(f.begin(), f.end(), ff[i]));
    f.insert(f.begin(), ff[i]);
    do {
      for (int m : f) cout << m << " ";
      cout << endl;
    } while(next_permutation(f.begin() + 1, f.end()));
  }
  return 0;
}