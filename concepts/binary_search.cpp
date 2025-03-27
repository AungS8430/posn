#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int m[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int n = sizeof(m) / sizeof(int);
	auto r = lower_bound(m, m+n, 3) - m;
	cout << r;
	return 0;
}