#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n, i[] = {0, 0, 0, 0, 0};
	cin >> n;
	i[4] += n / 100;
	n %= 100;
	if (n >= 90) {
		i[2]++;
		i[4]++;
		n -= 90;
	}
	i[3] += n / 50;
	n %= 50;
	if (n >= 40) {
		i[2]++;
		i[3]++;
		n -= 40;
	}
	i[2] += n / 10;
	n %= 10;
	if (n >= 9) {
		i[0]++;
		i[2]++;
		n -= 9;
	}
	i[1] += n / 5;
	n %= 5;
	if (n >= 4) {
		i[0]++;
		i[1]++;
		n -= 4;
	}
	i[0] += n;
	for (int j : i) cout << j << " ";
	cout << endl;
	return 0;
}