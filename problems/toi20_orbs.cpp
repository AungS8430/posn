#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, l, a, b, w;
  cin >> n >> l;
  cin >> a >> b;
  vector<int> tmp(n);
  for (int i = 0; i < n; i++) {
    cin >> tmp[i];
  }
  sort(tmp.begin(), tmp.end());
  multiset<int> front(tmp.begin(), tmp.begin() + a), mid(tmp.begin() + a, tmp.begin() + b - 1), back(tmp.begin() + b - 1, tmp.end());
  for (int i = 0; i < l; i++) {
    auto x = prev(front.end());
    auto y = back.begin();

    mid.insert(*y - *x);
    mid.insert((*x + *y) / 2);

    front.erase(x);
    back.erase(y);

    auto q = mid.begin();
    auto r = prev(mid.end());

    front.insert(*q); mid.erase(q);
    back.insert(*r); mid.erase(r);
  }
  for (int f : front) {
    cout << f << " ";
  }
  for (int m : mid) {
    cout << m << " ";
  }
  for (int b : back) {
    cout << b << " ";
  }
  return 0;
}
