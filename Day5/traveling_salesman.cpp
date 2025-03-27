#include <bits/stdc++.h>
using namespace std;

pair<vector<int>, int> tsp(vector<int> &cities, vector<vector<int>> &distance) {
  int min_distance = INT_MAX;
  vector<int> best_path;
  do {
    int current_distance = 0;
    for (int i = 0; i < cities.size() - 1; i++) {
      current_distance += distance[cities[i]][cities[i + 1]];
    }
    current_distance += distance[cities[cities.size() - 1]][cities[0]];
    if (current_distance < min_distance) best_path = cities;
    min_distance = min(min_distance, current_distance);
  } while (next_permutation(cities.begin(), cities.end()));
  return {best_path, min_distance};
}

int main(void) {
  vector<int> cities = {0, 1, 2, 3};
  vector<vector<int>> distance = {{0, 10, 15, 20}, {10, 0, 35, 25}, {15, 35, 0, 30},{20, 25, 30, 0}};
  pair<vector<int>, int> ans = tsp(cities, distance);
  vector<int> best_path = ans.first;
  int min_distance = ans.second;
  for (int x : best_path) cout << x << " -> ";
  cout << best_path[0] << endl;
  cout << min_distance;
  return 0;
}
