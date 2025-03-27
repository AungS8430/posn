#include <bits/stdc++.h>
#include <vector>
#include <string>
using namespace std;

int main(void) {
	int n, rows;
	cin >> n;
	rows = 0;
	vector<string> res;
	int p, q, r;
	for (int i = 0; i < n; i++) {
		cin >> p >> q >> r;
		if (p > rows) {
			for (int j = 0; j < p - rows; j++) {
				res.push_back(string(70, 'o'));
			}
			rows = p;
		}
		for (int j = q - 1; j < q + r - 1 && j < 70; j++) {
			res[p - 1][j] = 'x';
		}
	}
	for (string line : res) {
		cout << line << endl;
	}
	return 0;
}