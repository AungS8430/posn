#include <bits/stdc++.h>
using namespace std;

string segments[] = {" _ | ||_|", "     |  |", " _  _||_ ", " _  _| _|", "   |_|  |", " _ |_  _|", " _ |_ |_|", " _   |  |", " _ |_||_|", " _ |_| _|"};

int main(void) {
  int m, n;
  unsigned int a = 0, b = 0;
  string input;
  cin >> m >> n;
  cin.ignore();
  string segment1[m], segment2[n];
  fill_n(segment1, m, "");
  fill_n(segment2, n, "");
  for (int i = 0; i < 3; i++) {
    getline(cin, input);
    while (input.length() < m * 4 - 1) input += " ";
    for (int j = 0; j < m; j++) {
      segment1[j] += input.substr(j * 4, 3);
    }
  }
  for (int i = 0; i < 3; i++) {
    getline(cin, input);
    while (input.length() < n * 4 - 1) input += " ";
    for (int j = 0; j < n; j++) {
      segment2[j] += input.substr(j * 4, 3);
    }
  }
  for (int i = 0; i < m; i++) {
    a *= 10;
    a += distance(segments, find(segments, segments + 10, segment1[i]));

  }
  for (int i = 0; i < n; i++) {
    b *= 10;
    b += distance(segments, find(segments, segments + 10, segment2[i]));
  }
  cout << a + b;
  return 0;
}
