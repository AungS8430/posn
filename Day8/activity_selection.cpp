#include <bits/stdc++.h>
using namespace std;

int first_end(map<int, pair<int, int>> &activities, int from) {
  int curr = -1;
  for (pair<int, pair<int, int>> x : activities) {
    if (x.second.first >= from && x.second.second < (curr == -1 ? INT_MAX : activities[curr].second)) {
      curr = x.first;
    }
  }
  return curr;
}

int main(void) {
  map<int, pair<int, int>> activities = {{1, {1, 4}}, {2, {3, 5}}, {3, {0, 6}}, {4, {5, 7}}, {5, {3, 9}}, {6, {5, 9}}, {7, {6, 10}}, {8, {8, 11}}, {9, {8, 12}}, {10, {2, 14}}, {11, {12, 16}}};
  int x = first_end(activities, 0);
  while(x != -1) {
    cout << x << " ";
    x = first_end(activities, activities[x].second);
  }
  return 0;
}