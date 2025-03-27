#include <bits/stdc++.h>
using namespace std;

int state = 1;

short decode(int in) {
  switch (in) {
    case 0:
      switch (state) {
        case 1:
          state = 3;
          return 0;
          break;
        case 2:
          state = 3;
          return 1;
          break;
      }
      break;
    case 1:
      switch (state) {
        case 3:
          state = 4;
          return 0;
          break;
        case 4:
          state = 2;
          return 1;
          break;
      }
      break;
    case 10:
      switch (state) {
        case 3:
          state = 2;
          return 0;
          break;
        case 4:
          return 1;
          break;
      }
      break;
    case 11:
     switch (state) {
      case 1:
        state = 3;
        return 0;
        break;
      case 2:
        state = 0;
        return 1;
        break;
     }
     break;
  }
  return 0;
}

int main(void) {
  int n;
  vector<short> in;
  vector<short> decoded;
  string out = "";
  cin >> n;
  for (int i = 0; i < n; i++) {
    string x;
    cin >> x;
    for (char y : x) in.push_back(y - '0');
  }
  //for (int i = 0; i < in.size(); i++) cout << in[i];
  for (int i = 0; i < in.size(); i += 2) {
    decoded.push_back(decode(in[i] * 10 + in[i + 1]));
  }
  while (decoded.size() % 8 != 0) decoded.pop_back();
  for (int i = 0; i < decoded.size(); i++) cout << decoded[i];
  for (int i = 0; i < decoded.size(); i += 8) {
    int curr = 0;
    for (int j = 7; j >= 0; j--) {
      curr += decoded[i + j] * (1<<j);
    }
    out.push_back((char) curr);
  }
  cout << out;
  return 0;
}