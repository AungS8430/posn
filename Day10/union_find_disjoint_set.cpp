#include <iostream>
#include <vector>

using namespace std;

vector<int> parent, rankArray;

void initialize(int n) {
  parent.resize(n);
  rankArray.resize(n, 0);
  for (int i = 0; i < n; ++i) {
    parent[i] = i;
  }
}

int findSet(int i) {
  if (parent[i] != i) {
    parent[i] = findSet(parent[i]);
  }
  return parent[i];
}

void unionSet(int i, int j) {
  int rootI = findSet(i);
  int rootJ = findSet(j);

  if (rootI != rootJ) {
    if (rankArray[rootI] > rankArray[rootJ]) {
      parent[rootJ] = rootI;
    } else if (rankArray[rootI] < rankArray[rootJ]) {
      parent[rootI] = rootJ;
    } else {
      parent[rootJ] = rootI;
      rankArray[rootI]++;
    }
  }
}

void printParentAndRank() {
  cout << "Parent: ";
  for (int i = 0; i < parent.size(); ++i) {
    cout << parent[i] << " ";
  }
  cout << "\nRank:   ";
  for (int i = 0; i < rankArray.size(); ++i) {
    cout << rankArray[i] << " ";
  }
  cout << endl;
}

int main() {
  int n = 8;
  initialize(n);

  unionSet(0, 1);
  unionSet(2, 3);
  unionSet(4, 5);
  unionSet(6, 7);

  unionSet(0, 2); 
  unionSet(4, 6); 

  unionSet(0, 4);
  printParentAndRank();

  return 0;
}
