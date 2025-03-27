#include <bits/stdc++.h>
using namespace std;

typedef struct PAIR {
  int a, b;
  bool operator<(const PAIR &p) {
    if (p.a == a) return b < p.b;
    else return a > p.a;
  }
} pr;

int main(void) {
  int n;
  long long x = 0;
  cin >> n;
  vector<pr> prs(n);
  for (int i = 0; i < n; i++) cin >> prs[i].a >> prs[i].b;

  sort(prs.begin(), prs.end());
  for (int i = 0; i < n; i++) {
    // cout << prs[i].a << " " << prs[i].b << endl;
    for (int j = i + 1; j < n; j++) {
      if (prs[i].b < prs[j].b) x += prs[i].a + prs[j].a;
    }
  }
  cout << x << endl;
  return 0;
}