#include <bits/stdc++.h>
#include <vector>
#include <cmath>
using namespace std;

vector<int> heap;

void insertHeap(int n);
int deleteHeap();

int main(void) {
  int n, temp;
  heap.push_back(INT_MAX);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    insertHeap(temp);
  }
  for (int i = 1; i < heap.size(); i++) {
    cout << heap[i] << " ";
  }
  cout << endl << "Removed element: " << deleteHeap() << endl;
  for (int i = 1; i < heap.size(); i++) {
    cout << heap[i] << " ";
  }
  return 0;
}

void insertHeap(int n) {
  int hole = heap.size();
  int parent = hole / 2;
  heap.push_back(INT_MAX);
  while (hole > 1 && heap[parent] > n) {
    heap[hole] = heap[parent];;
    hole = parent;
    parent = hole / 2;
  }
  heap[hole] = n;
  return;
}

int deleteHeap() {
  int first = heap[1];
  int last = heap.back();
  heap.pop_back();
  int hole = 1;
  int l, r, c;
  while (hole * 2 < heap.size()) {
    l = hole * 2;
    r = l + 1;
    c = l;
    if (r < heap.size() && heap[r] < heap[l]) {
      c = r;
    }
    if (last > heap[c]) {
      heap[hole] = heap[c];
      hole = c;
    } else {
      break;
    }
  }
  heap[hole] = last;
  return first;
}
