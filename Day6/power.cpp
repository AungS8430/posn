#include <bits/stdc++.h>
using namespace std;

int power(int base, int expo) {
  if (expo == 0) return 1;
  else if (expo % 2 == 0 && expo > 0) return power(base, expo / 2) * power(base, expo / 2);
  else if (expo % 2 != 0) return power(base, expo / 2) * power(base, expo / 2) * base;
  return 0;
}

int main(void) {
  int base, expo;
  cout << "Base: ";
  cin >> base;
  cout << "Expo: ";
  cin >> expo;
  cout << power(base, expo);
  return 0;
}
