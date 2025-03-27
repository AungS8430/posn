#include <bits/stdc++.h>
using namespace std;

int main(void) {
  long long n;
  cin >> n;
  long long curr = 3 * n - 2, x = curr % 10 + (curr + 1) % 10; 
  if (n == 3) {
    curr += 2;
    x += curr % 10;
  } else if (n == 2) {
    x = 7;
  } else if (n == 1) {
    x = 1;
  } else if (n % 2 == 0) {
    for (long long i = 1; i < ceil(n / 2.0) - 1; i++) {
      curr += 3 * (n - i * 2) + (n - (i + 1) * 2);
      x += curr % 10;
      x += (curr + 1) % 10;
    }
    curr += 5;
    x += curr % 10;
    x += (curr + 1) % 10;
  } else {
    for (long long i = 1; i < ceil(n / 2.0) - 1; i++) {
      curr += 3 * (n - i * 2) + (n - (i + 1) * 2);
      x += curr % 10;
      x += (curr + 1) % 10;
    }
    curr++;
    x += (curr + 1) % 10;
  }
  cout << x;
  return 0;
}
