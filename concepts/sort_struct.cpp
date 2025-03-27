#include <bits/stdc++.h>
#include <vector>
using namespace std;

typedef struct P {
	int x;
	int y;
	bool operator<(const P &p) {
		if (x != p.x) return x < p.x;
		else return y < p.y;
	}
} PData;

int main(void) {
	vector<PData> d;
	d.push_back({1, 2});
	d.push_back({2, 2});
	d.push_back({1, 1});
	sort(d.begin(), d.end());
	for (PData i : d) cout << i.x << " " << i.y << endl;
	return 0;
}