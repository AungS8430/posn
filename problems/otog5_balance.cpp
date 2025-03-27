#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<long long> convert(long long x) {
  vector<long long> res;
  while (x > 0) {
    res.push_back(x % 3);
    x /= 3;
  }
  res.push_back(0);
  
  for (long long i = 0; i < res.size() - 1; i++) {
    if (res[i] == 2) {
      res[i] = -1;
      res[i + 1]++;
    } else if (res[i] == 3) {
      res[i] = 0;
      res[i + 1]++;
    }
  }
  reverse(res.begin(), res.end());
  return res;
}

int main() {
  long long n;
  cin >> n;
  
  vector<long long> b3 = convert(n);
  
  long long a = 0;
  long long positive_sum = 0;
  long long negative_sum = 0;
  long long power_of_3 = 1;
  
  for (long long i = b3.size() - 1; i >= 0; i--) {
    if (b3[i] != 0) {
      a++;
    }
    if (b3[i] == 1) {
      positive_sum += power_of_3;
    } else if (b3[i] == -1) {
      negative_sum += power_of_3;
    }
    power_of_3 *= 3;
  }
  
  cout << a << " " << max(positive_sum, negative_sum + n) << endl;
  
  return 0;
}