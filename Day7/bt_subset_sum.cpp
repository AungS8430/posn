#include <bits/stdc++.h>
using namespace std;

bool check_sum(vector<int> &numbers, int target, int index, int curr_sum, vector<int> curr_subset) {
  if (curr_sum == target) {
    return true;
  }
  if (curr_sum > target || index == numbers.size()) {
    return false;
  }

  curr_subset.push_back(numbers[index]);
  if (check_sum(numbers, target, index + 1, curr_sum + numbers[index], curr_subset)) return true;

  curr_subset.pop_back();
  if (check_sum(numbers, target, index + 1, curr_sum, curr_subset)) return true;

  return false;
}

bool backtrack(vector<int> &numbers, int target) {
  vector<int> curr_subset;
  return check_sum(numbers, target, 0, 0, curr_subset);
}

int main(void) {
  vector<int> numbers = {1, 2, 3, 4, 5, 6};
  cout << (backtrack(numbers, 3) ? "Found" : "Not found");
  return 0;
}