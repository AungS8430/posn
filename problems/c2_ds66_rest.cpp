#include <bits/stdc++.h>
#include <sstream>
using namespace std;

typedef struct VISITOR {
  string name;
  int time;
  bool operator<(VISITOR &v) {
    if (v.time == time) return strcmp(name.c_str(), v.name.c_str()) < 0;
    else return time < v.time;
  }
} visitor;

int main(void) {
  int n, k;
  string temp;
  cin >> n >> k;
  vector<visitor> v;
  cin.ignore();
  for (int i = 0; i < n; i++) {
    getline(cin, temp);
    stringstream ss(temp);
    string name;
    string stops;
    int count = 0;
    ss >> name;
    while (ss >> stops) {
      count++;
      if (stoi(stops) == k) {
        visitor c;
        c.name = name;
        c.time = count;
        v.push_back(c);
        break;
      }
    }
  }
  if (v.begin() == v.end()) {
    cout << -1;
    return 0;
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < min(3, (int)v.size()); i++) {
    cout << v[i].name << " ";
  }
  return 0;
}
